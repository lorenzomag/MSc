#include <Math/Vector4D.h>
#include "../../include/pch.h"
#include "TF1.h"
#include "TApplication.h"
#include "TRint.h"
#include "TCanvas.h"
#include "TRootCanvas.h"
#include "ROOT/TSeq.hxx"
#include "TLine.h"
#include "TLatex.h"
#include "TROOT.h"
#include "TLegend.h"
#include "TFrame.h"
#include "../../include/lhcbStyle.h"

#define USE_PDG_MASS 0
#define USE_MASS12 1
#define Lc_cuts 1
#define Lc_pi_cuts 0
#define ASYNCHRONOUS 0
#define DEBUG 0

int Lc_cut_min = 2270;
int Lc_cut_max = 2310;
int Lc_pi_cut_min = 2450;
int Lc_pi_cut_max = 2460;

enum inputs
{
    MC,
    WS1,
    WS2,
    SIG
};
const TString enum_str[4] = {"Simulation", "WS1", "WS2", "Signal"};

bool Lc_cut = false;
bool Lc_pi_cut = false;

const int kRefresh = 100;

void padRefresh(TPad *pad, int flag);
TCanvas *resonant_state_analysis(const inputs kInput);

int main(int argc, char **argv)
{
    TApplication app("app", &argc, argv);
#if ASYNCHRONOUS
    ROOT::EnableThreadSafety();

    std::vector<std::future<TCanvas *>> futures;
    TRootCanvas *root_canvas;

    for (inputs input_type : {MC, WS1, WS2, SIG})
    {
        futures.push_back(std::async(resonant_state_analysis, input_type));
    }

    for (int future_n : ROOT::TSeqU(futures.size()))
    {
        root_canvas = (TRootCanvas *)futures[future_n].get()->GetCanvasImp();
        root_canvas->Connect("CloseWindow()", "TApplication", gApplication, "Terminate()");
    }

#else  // NOT ASYNCHRONOUS
    TCanvas *canv;
    TRootCanvas *root_canvas;

    for (inputs input_type : {MC, WS1, WS2, SIG})
    {
        canv = resonant_state_analysis(input_type);
        root_canvas = ((TRootCanvas *)canv->GetCanvasImp());
        root_canvas->Connect("CloseWindow()", "TApplication", gApplication, "Terminate()");
    }
#endif // ASYNCHRONOUS
    app.Run();
}

TCanvas *resonant_state_analysis(const inputs kInput = MC)
{
    // ROOT::EnableImplicitMT(8);
    // set_lhcb_style();
    gStyle->SetOptStat("e"); // show only nent -e
    gStyle->SetStatBorderSize(0);
    gStyle->SetLegendBorderSize(0);
    gStyle->SetStatFontSize(0.05);
    gStyle->SetStatX(0.9);
    gStyle->SetStatY(0.89);
    gStyle->SetStatW(0.15);
    gStyle->SetStatH(0.1);
    std::cout << "Started plotting for " << enum_str[kInput] << " dataset.\n";
    TCanvas *c1;
    if (kInput == inputs::MC)
        c1 = new TCanvas("MonteCarlo", "MonteCarlo", 200, 10, 600, 900);
    if (kInput == inputs::WS1)
        c1 = new TCanvas("WS1", "WS1", 200, 10, 600, 900);
    if (kInput == inputs::WS2)
        c1 = new TCanvas("WS2", "WS2", 200, 10, 600, 900);
    if (kInput == inputs::SIG)
        c1 = new TCanvas("Signal (data)", "Signal (data)", 200, 10, 600, 900);

#if USE_PDG_MASS
    ROOT::Math::PxPyPzMVector Lc;
    ROOT::Math::PxPyPzMVector pi;
    ROOT::Math::PxPyPzMVector Lc_pi;
#else
    ROOT::Math::PxPyPzEVector Lc;
    ROOT::Math::PxPyPzEVector pi;
    ROOT::Math::PxPyPzEVector Lc_pi;
#endif

    TFile *in;
    TString filename;
    switch (kInput)
    {
    case inputs::MC:
        filename = getenv("CURRENT_MC_DATASET");
        in = new TFile(filename);
        break;
    case inputs::WS1:
        filename = getenv("CURRENT_WS1_DATASET");
        in = new TFile(filename);
        break;
    case inputs::WS2:
        filename = getenv("CURRENT_WS2_DATASET");
        in = new TFile(filename);
        break;
    case inputs::SIG:
        filename = getenv("CURRENT_SIG_DATASET");
        in = new TFile(filename);
        break;
    }
    TString friend_filename = (TString)"friend_" + filename;
    TFile *friend_file = new TFile(friend_filename);

    if (!in->IsOpen())
    {
        std::cerr << "[WARNING] Filename " << filename << " for " << enum_str[kInput] << " dataset not found.\n";
        return nullptr;
    }

    TH1D *hpx[3];

#if Lc_cuts
    TString title_hist_0 = (TString) "Mass of #Lambda_{c}^{+} (Cuts applied: " + Lc_cut_min + (TString) " MeV < M(#Lambda_{c}^{+}) < " + Lc_cut_max + (TString) " MeV);Mass (MeV);Counts";
#else
    TString title_hist_0 = "Mass of #Lambda_{c}^{+};Mass (MeV);Counts";
#endif // Lc_cuts
#if Lc_pi_cuts
    TString title_hist_1 = (TString) "Invariant mass of (#Lambda_{c}^{+} + #pi^{+}) (Cuts applied: " + Lc_pi_cut_min + (TString) " MeV < M(#Sigma) - M(#Lambda_{c}_reco) + M(#Lambda_{c}_lit)  < " + Lc_pi_cut_max + (TString) " MeV);Mass (MeV);Counts";
#else
    TString title_hist_1 = "Invariant mass of (#Lambda_{c}^{+} + #pi^{+});Mass (MeV);Counts";
#endif // Lc_pi_cuts
    TString title_hist_2 = "Invariant mass of (#Lambda_{c}^{+} + #pi^{+}) "
                           "- Reconstructed mass of #Lambda_{c}^{+} "
                           "+ Literature mass of #Lambda_{c}^{+};Mass (MeV);Counts";
    hpx[0] = new TH1D("Lc Mass", title_hist_0, 500, 0, 0);
    hpx[1] = new TH1D("LcPi Mass", title_hist_1, 500, 0, 0);
    hpx[2] = new TH1D("LcPi diff", title_hist_2,
                      500, 0, 0);

    c1->Divide(1, 3);

    auto t = (TTree *)in->Get("DecayTree");

    double Lc_PX;
    double Lc_PY;
    double Lc_PZ;
    double Lc_PE;
    double pi_PX;
    double pi_PY;
    double pi_PZ;
    double pi_PE;
    int Xicst_TRUEID;

    if (kInput == MC)
    {
        t->SetBranchAddress("Xicst_TRUEID", &Xicst_TRUEID);
    }
    t->SetBranchAddress("Lc_PX", &Lc_PX);
    t->SetBranchAddress("Lc_PY", &Lc_PY);
    t->SetBranchAddress("Lc_PZ", &Lc_PZ);
    t->SetBranchAddress("Lc_PE", &Lc_PE);
    t->SetBranchAddress("pibach_PX", &pi_PX);
    t->SetBranchAddress("pibach_PY", &pi_PY);
    t->SetBranchAddress("pibach_PZ", &pi_PZ);
    t->SetBranchAddress("pibach_PE", &pi_PE);

#if DEBUG
    int n_entries = 10000;
#else
    int n_entries = t->GetEntries();
#endif
    for (int i = 0; i < n_entries; i++)
    {
        Xicst_TRUEID = -999;
        t->GetEntry(i);

        if ((abs(Xicst_TRUEID) == 4214 && kInput == MC) || kInput != MC)
        {
            Lc.SetPx(Lc_PX);
            Lc.SetPy(Lc_PY);
            Lc.SetPz(Lc_PZ);
#if USE_PDG_MASS
            Lc.SetM(2286.46);
#else
            Lc.SetE(Lc_PE);
#endif

            pi.SetPx(pi_PX);
            pi.SetPy(pi_PY);
            pi.SetPz(pi_PZ);
#if USE_PDG_MASS
            pi.SetM(139.57);
#else
            pi.SetE(pi_PE);
#endif

            auto Lc_M = Lc.M();
            Lc_pi = Lc + pi;
            auto Lc_pi_M = Lc_pi.M();
            auto Lc_pi_M_hiRes = Lc_pi_M - Lc_M + 2286.46;

#if Lc_pi_cuts
            if (Lc_pi_cut_min < Lc_pi_M_hiRes && Lc_pi_M_hiRes < Lc_pi_cut_max)
#endif
            {
#if Lc_cuts
                if (Lc_cut_min < Lc_M && Lc_M < Lc_cut_max)
#endif
                {
                    hpx[0]->Fill(Lc_M);
                    hpx[1]->Fill(Lc_pi_M);
                    hpx[2]->Fill(Lc_pi_M_hiRes);
                }
            }
        }
    }

    TLine *Lc_cut_line_min;
    TLine *Lc_cut_line_max;
    TLine *Lc_pi_cut_line_min;
    TLine *Lc_pi_cut_line_max;

    for (Int_t j = 1; j <= 3; j++)
    {

        c1->cd(j);
        std::cout << "Started plot " << j << " for " << enum_str[kInput] << " dataset\n";
        hpx[j - 1]->Draw();
        // auto lhcbName = get_lhcb_name();
        // lhcbName->Draw();
        padRefresh(c1);

        auto max = c1->GetPad(j)->GetFrame()->GetY2();

#if !Lc_cuts
        if (j == 1)
        {
            Lc_cut_line_min = new TLine(Lc_cut_min, 0, Lc_cut_min, max);
            Lc_cut_line_max = new TLine(Lc_cut_max, 0, Lc_cut_max, max);
            Lc_cut_line_min->SetLineColor(30);
            Lc_cut_line_max->SetLineColor(30);
            Lc_cut_line_min->Draw("SAME");
            Lc_cut_line_max->Draw("SAME");
        }
#endif // !Lc_cuts
#if !Lc_pi_cuts
        if (j == 2 || j == 3)
        {
            Lc_pi_cut_line_min = new TLine(Lc_pi_cut_min, 0, Lc_pi_cut_min, max);
            Lc_pi_cut_line_max = new TLine(Lc_pi_cut_max, 0, Lc_pi_cut_max, max);
            Lc_pi_cut_line_min->SetLineColor(46);
            Lc_pi_cut_line_max->SetLineColor(46);
            Lc_pi_cut_line_min->Draw("SAME");
            Lc_pi_cut_line_max->Draw("SAME");
        }
#endif // !Lc_pi_cuts
    }
    c1->cd(2);
    TLegend *legend = new TLegend(0.65, 0.6, 0.9, 0.8);
    legend->AddEntry(hpx[0], "Mass Distribution", "lf");
    TString legend_entry_string = (TString)"for " + enum_str[kInput];
    legend->AddEntry((TObject *)0, legend_entry_string, "");
#if !Lc_cuts
    legend->AddEntry(Lc_cut_line_min, "#Lambda_{c}^{+} Cuts", "lf");
#endif // Lc_cuts
#if !Lc_pi_cuts
    legend->AddEntry(Lc_pi_cut_line_min, "#Lambda_{c}^{+}#pi^{+} Cuts", "lf");
#endif // Lc_pi_cuts
    legend->Draw();
    padRefresh(c1);

    TString figures_dir = "figures/";
    TString canvas_title = figures_dir + enum_str[kInput];
#if Lc_cuts
    canvas_title += "_LcCuts";
#endif
#if Lc_pi_cuts
    canvas_title += "_LcPiCuts";
#endif
    canvas_title += ".png";

    c1->Print(canvas_title);

    return c1;
}

void padRefresh(TPad *pad, int flag = 0)
{
    if (!pad)
        return;
    pad->Modified();
    pad->Update();
    TList *tl = pad->GetListOfPrimitives();
    if (!tl)
        return;
    TListIter next(tl);
    TObject *to;
    while ((to = next()))
    {
        if (to->InheritsFrom(TPad::Class()))
            padRefresh((TPad *)to, 1);
    }
    if (flag)
        return;
    gSystem->ProcessEvents();
}