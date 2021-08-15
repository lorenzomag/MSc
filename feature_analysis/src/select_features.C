#include "pch.h"
#include <algorithm>
#include "select_features.h"

std::vector<TString> include_particles = {
    "Xicst",
    "Lc",
    "pibach",
    "Kbach"};

json select_features(feat_source option)
{
    json j_db;
    if (option == feat_source::from_file)
    {

        std::ifstream inFile;
        std::string inFileName = "/home/loren/MSc/feature_analysis/user_settings.json";
        inFile.open(inFileName);
        if (inFile.is_open())
        {
            try
            {
                inFile >> j_db;
            }
            catch (nlohmann::detail::parse_error)
            {
                std::cerr << "[WARNING] Input file \"" << inFileName << "\" was not a properly setup json file;" << std::endl
                          << "[WARNING] Using \"default_settings.json\" instead." << std::endl;
                option = feat_source::default_values;
            }
        }
        else
        {
            std::cerr << "[WARNING] Input file \"" << inFileName << "\" not found" << std::endl
                      << "[WARNING] Using \"default_settings.json\" instead." << std::endl;
            option = feat_source::default_values;
        }
    }

    if (option == feat_source::default_values)
    {

        std::string particle_list[] = {
            "Lc",
            "Km",
            "p",
            "pip",
            "Kbach",
            "pibach",
            "Xicst"};
        j_db["global"] = {
// BEGIN LIST OF GLOBAL FEATURES
			{"nCandidate", false},
			{"totCandidates", false},
			{"EventInSequence", false},
			{"runNumber", false},
			{"eventNumber", false},
			{"BCID", false},
			{"BCType", false},
			{"OdinTCK", false},
			{"L0DUTCK", false},
			{"HLT1TCK", false},
			{"HLT2TCK", false},
			{"GpsTime", false},
			{"Polarity", false},
			{"nPV", false},
			{"PVX", false},
			{"PVY", false},
			{"PVZ", false},
			{"PVXERR", false},
			{"PVYERR", false},
			{"PVZERR", false},
			{"PVCHI2", false},
			{"PVNDOF", false},
			{"PVNTRACKS", false},
			{"nPVs", false},
			{"nTracks", false},
			{"nLongTracks", false},
			{"nDownstreamTracks", false},
			{"nUpstreamTracks", false},
			{"nVeloTracks", false},
			{"nTTracks", false},
			{"nBackTracks", false},
			{"nRich1Hits", false},
			{"nRich2Hits", false},
			{"nVeloClusters", false},
			{"nITClusters", false},
			{"nTTClusters", false},
			{"nOTClusters", false},
			{"nSPDHits", false},
			{"nMuonCoordsS0", false},
			{"nMuonCoordsS1", false},
			{"nMuonCoordsS2", false},
			{"nMuonCoordsS3", false},
			{"nMuonCoordsS4", false},
			{"nMuonTracks", false},
			{"Lc_bdtg", false},
// END LIST OF GLOBAL FEATURES
        };

        for (auto particle_name : particle_list)
        {
            if (std::find(include_particles.begin(), include_particles.end(), particle_name) != include_particles.end())
                j_db["particles"][particle_name]["include"] = true;
            else
                j_db["particles"][particle_name]["include"] = false;

            j_db["particles"][particle_name]["features"] = {
// BEGIN LIST OF PARTICLE FEATURES
			{"_ENDVERTEX_X", false},
			{"_ENDVERTEX_Y", false},
			{"_ENDVERTEX_Z", false},
			{"_MC12TuneV2_ProbNNe", false},
			{"_MC12TuneV2_ProbNNmu", false},
			{"_MC12TuneV2_ProbNNpi", false},
			{"_MC12TuneV2_ProbNNk", false},
			{"_MC12TuneV2_ProbNNp", false},
			{"_MC12TuneV2_ProbNNghost", false},
			{"_MC12TuneV3_ProbNNe", false},
			{"_MC12TuneV3_ProbNNmu", false},
			{"_MC12TuneV3_ProbNNpi", false},
			{"_MC12TuneV3_ProbNNk", false},
			{"_MC12TuneV3_ProbNNp", false},
			{"_MC12TuneV3_ProbNNghost", false},
			{"_MC12TuneV4_ProbNNe", false},
			{"_MC12TuneV4_ProbNNmu", false},
			{"_MC12TuneV4_ProbNNpi", false},
			{"_MC12TuneV4_ProbNNk", false},
			{"_MC12TuneV4_ProbNNp", false},
			{"_MC12TuneV4_ProbNNghost", false},
			{"_MC15TuneV1_ProbNNe", false},
			{"_MC15TuneV1_ProbNNmu", false},
			{"_MC15TuneV1_ProbNNpi", false},
			{"_MC15TuneV1_ProbNNk", false},
			{"_MC15TuneV1_ProbNNp", false},
			{"_MC15TuneV1_ProbNNghost", false},
			{"_OWNPV_X", false},
			{"_OWNPV_Y", false},
			{"_OWNPV_Z", false},
			{"_OWNPV_XERR", false},
			{"_OWNPV_YERR", false},
			{"_OWNPV_ZERR", false},
			{"_OWNPV_CHI2", false},
			{"_OWNPV_NDOF", false},
			{"_OWNPV_COV_[3][3]", false},
			{"_IP_OWNPV", false},
			{"_IPCHI2_OWNPV", false},
			{"_ORIVX_X", false},
			{"_ORIVX_Y", false},
			{"_ORIVX_Z", false},
			{"_ORIVX_XERR", false},
			{"_ORIVX_YERR", false},
			{"_ORIVX_ZERR", false},
			{"_ORIVX_CHI2", false},
			{"_ORIVX_NDOF", false},
			{"_ORIVX_COV_[3][3]", false},
			{"_P", false},
			{"_PT", false},
			{"_PE", false},
			{"_PX", false},
			{"_PY", false},
			{"_PZ", false},
			{"_M", false},
			{"_TRUEID", false},
			{"_MC_MOTHER_ID", false},
			{"_MC_MOTHER_KEY", false},
			{"_MC_GD_MOTHER_ID", false},
			{"_MC_GD_MOTHER_KEY", false},
			{"_MC_GD_GD_MOTHER_ID", false},
			{"_MC_GD_GD_MOTHER_KEY", false},
			{"_TRUEP_E", false},
			{"_TRUEP_X", false},
			{"_TRUEP_Y", false},
			{"_TRUEP_Z", false},
			{"_TRUEPT", false},
			{"_TRUEORIGINVERTEX_X", false},
			{"_TRUEORIGINVERTEX_Y", false},
			{"_TRUEORIGINVERTEX_Z", false},
			{"_TRUEENDVERTEX_X", false},
			{"_TRUEENDVERTEX_Y", false},
			{"_TRUEENDVERTEX_Z", false},
			{"_TRUEISSTABLE", false},
			{"_TRUETAU", false},
			{"_ID", false},
			{"_PIDe", false},
			{"_PIDmu", false},
			{"_PIDK", false},
			{"_PIDp", false},
			{"_PIDd", false},
			{"_ProbNNe", false},
			{"_ProbNNk", false},
			{"_ProbNNp", false},
			{"_ProbNNpi", false},
			{"_ProbNNmu", false},
			{"_ProbNNd", false},
			{"_ProbNNghost", false},
			{"_hasMuon", false},
			{"_isMuon", false},
			{"_hasRich", false},
			{"_UsedRichAerogel", false},
			{"_UsedRich1Gas", false},
			{"_UsedRich2Gas", false},
			{"_RichAboveElThres", false},
			{"_RichAboveMuThres", false},
			{"_RichAbovePiThres", false},
			{"_RichAboveKaThres", false},
			{"_RichAbovePrThres", false},
			{"_hasCalo", false},
			{"_TRACK_Type", false},
			{"_TRACK_Key", false},
			{"_TRACK_CHI2NDOF", false},
			{"_TRACK_PCHI2", false},
			{"_TRACK_MatchCHI2", false},
			{"_TRACK_GhostProb", false},
			{"_TRACK_CloneDist", false},
			{"_TRACK_Likelihood", false},
			{"_ENDVERTEX_XERR", false},
			{"_ENDVERTEX_YERR", false},
			{"_ENDVERTEX_ZERR", false},
			{"_ENDVERTEX_CHI2", false},
			{"_ENDVERTEX_NDOF", false},
			{"_ENDVERTEX_COV_", false},
			{"_OWNPV_COV_", false},
			{"_FD_OWNPV", false},
			{"_FDCHI2_OWNPV", false},
			{"_DIRA_OWNPV", false},
			{"_MM", false},
			{"_MMERR", false},
			{"_DTF_LcPDG_DTF_CHI2", false},
			{"_DTF_LcPDG_DTF_NDOF", false},
			{"_DTF_LcPDG_Lc_M", false},
			{"_DTF_LcPDG_Lc_PT", false},
			{"_DTF_LcPDG_M", false},
			{"_DTF_LcPDG_M12", false},
			{"_DTF_LcPDG_PT", false},
			{"_DTF_PV_DTF_CHI2", false},
			{"_DTF_PV_DTF_NDOF", false},
			{"_DTF_PV_Lc_M", false},
			{"_DTF_PV_Lc_PT", false},
			{"_DTF_PV_M", false},
			{"_DTF_PV_M12", false},
			{"_DTF_PV_PT", false},
			{"_DTF_PV_LcPDG_DTF_CHI2", false},
			{"_DTF_PV_LcPDG_DTF_NDOF", false},
			{"_DTF_PV_LcPDG_Lc_M", false},
			{"_DTF_PV_LcPDG_Lc_PT", false},
			{"_DTF_PV_LcPDG_M", false},
			{"_DTF_PV_LcPDG_M12", false},
			{"_DTF_PV_LcPDG_PT", false},
			{"_BPVIPCHI2", false},
			{"_BPVVDCHI2", false},
			{"_DOCA12", false},
			{"_DOCA13", false},
			{"_DOCA23", false},
			{"_DOCACHI2MAX", false},
			{"_DOCAMAX", false},
			{"_DOCAMIN", false},
			{"_ETA", false},
			{"_M12", false},
			{"_M13", false},
			{"_M23", false},
			{"_SUM_PT", false},
			{"_Y", false},
			{"_ORIVX_COV_", false},
			{"_FD_ORIVX", false},
			{"_FDCHI2_ORIVX", false},
			{"_DIRA_ORIVX", false},
			{"_ENDVERTEX_COV_[3][3]", false},
			{"_BKGCAT", false},
// END LIST OF PARTICLE FEATURES
            };
        }
        std::ofstream myfile;
        myfile.open("default_settings.json");
        myfile << std::setw(4) << j_db;
        myfile.close();
    }
    return j_db;
}
