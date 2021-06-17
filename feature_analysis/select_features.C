#include "select_features.h"

json select_features(feat_source option)
{
    json j_db;
    if (option == feat_source::from_file)
    {

        std::ifstream inFile;
        std::string inFileName = "user_settings.json";
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
            {"nCandidate", false},
            {"totCandidates", false},
            {"EventInSequence", false},
            {"runNumber", true},
            {"eventNumber", true},
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
            {"nMuonTracks", false}};

        for (auto particle_name : particle_list)
        {

            j_db["particles"][particle_name]["include"] = true;
            j_db["particles"][particle_name]["features"] = {
                {"_ENDVERTEX_X", false},
                {"_ENDVERTEX_Y", false},
                {"_ENDVERTEX_Z", false},
                {"_ENDVERTEX_XERR", false},
                {"_ENDVERTEX_YERR", false},
                {"_ENDVERTEX_ZERR", false},
                {"_ENDVERTEX_CHI2", true},
                {"_ENDVERTEX_NDOF", false},
                {"_ENDVERTEX_COV_", false},
                {"_OWNPV_X", false},
                {"_OWNPV_Y", false},
                {"_OWNPV_Z", false},
                {"_OWNPV_XERR", false},
                {"_OWNPV_YERR", false},
                {"_OWNPV_ZERR", false},
                {"_OWNPV_CHI2", true},
                {"_OWNPV_NDOF", false},
                {"_OWNPV_COV_", false},
                {"_IP_OWNPV", false},
                {"_IPCHI2_OWNPV", false},
                {"_FD_OWNPV", false},
                {"_FDCHI2_OWNPV", false},
                {"_DIRA_OWNPV", false},
                {"_P", true},
                {"_PT", true},
                {"_PE", false},
                {"_PX", false},
                {"_PY", false},
                {"_PZ", true},
                {"_MM", true},
                {"_MMERR", false},
                {"_M", true},
                {"_BKGCAT", false},
                {"_falseID", false},
                {"_MC_MOTHER_ID", false},
                {"_MC_MOTHER_KEY", false},
                {"_MC_GD_MOTHER_ID", false},
                {"_MC_GD_MOTHER_KEY", false},
                {"_MC_GD_GD_MOTHER_ID", false},
                {"_MC_GD_GD_MOTHER_KEY", false},
                {"_falseP_E", false},
                {"_falseP_X", false},
                {"_falseP_Y", false},
                {"_falseP_Z", false},
                {"_falsePT", false},
                {"_falseORIGINVERTEX_X", false},
                {"_falseORIGINVERTEX_Y", false},
                {"_falseORIGINVERTEX_Z", false},
                {"_falseENDVERTEX_X", false},
                {"_falseENDVERTEX_Y", false},
                {"_falseENDVERTEX_Z", false},
                {"_falseISSTABLE", false},
                {"_falseTAU", false},
                {"_ID", true},
                {"_TAU", true},
                {"_TAUERR", true},
                {"_TAUCHI2", true},
                {"_CHI2NDOF_DTF_Lc", false},
                {"_CHI2NDOF_DTF_Lc_PV", false},
                {"_CHI2NDOF_DTF_PV", false},
                {"_Dau3_M_DTF_Lc_PV", false},
                {"_Dau3_PE_DTF_Lc_PV", false},
                {"_Dau3_PT_DTF_Lc_PV", false},
                {"_Dau3_PX_DTF_Lc_PV", false},
                {"_Dau3_PY_DTF_Lc_PV", false},
                {"_Dau3_PZ_DTF_Lc_PV", false},
                {"_Dau3_P_DTF_Lc_PV", false},
                {"_M_DTF_Lc", false},
                {"_M_DTF_PV", false},
                {"_ORIVX_X", true},
                {"_ORIVX_Y", true},
                {"_ORIVX_Z", true},
                {"_ORIVX_XERR", true},
                {"_ORIVX_YERR", true},
                {"_ORIVX_ZERR", true},
                {"_ORIVX_CHI2", true},
                {"_ORIVX_NDOF", true},
                {"_ORIVX_COV_", true},
                {"_FD_ORIVX", false},
                {"_FDCHI2_ORIVX", false},
                {"_DIRA_ORIVX", false},
                {"_BPVVDCHI2", false},
                {"_DOCA12", false},
                {"_DOCA13", false},
                {"_DOCA23", false},
                {"_DOCACHI2MAX", false},
                {"_DOCAMAX", false},
                {"_DOCAMIN", false},
                {"_ETA", true},
                {"_M12_DTF_Lc_PV", false},
                {"_M13_DTF_Lc_PV", false},
                {"_M23_DTF_Lc_PV", false},
                {"_Y", false},
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
                {"_PIDe", false},
                {"_PIDmu", false},
                {"_PIDK", false},
                {"_PIDp", false},
                {"_PIDd", false},
                {"_ProbNNe", true},
                {"_ProbNNk", true},
                {"_ProbNNp", true},
                {"_ProbNNpi", true},
                {"_ProbNNmu", true},
                {"_ProbNNd", true},
                {"_ProbNNghost", true},
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
                {"_TRACK_Likelihood", false}};
        }
        // std::cout
        //     << std::setw(4) << j_db << std::endl;

        // for (auto i : j_db["particles"].items())
        // {
        //     std::cout << i.key() << std::endl;
        // }

        std::ofstream myfile;
        myfile.open("default_settings.json");
        myfile << std::setw(4) << j_db;
        myfile.close();
    }
    return j_db;
}