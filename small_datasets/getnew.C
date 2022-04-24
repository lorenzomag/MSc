void getnew(std::string filename)
{
    auto f = new TFile(filename.c_str());
    auto bigt = f->Get<TTree>("DecayTree");

    auto n_evts = 150000;

    TFile outf("small_WS3.root","RECREATE");
    auto smallt = bigt->CloneTree(n_evts);

    smallt->Write();
    outf.Close();

}