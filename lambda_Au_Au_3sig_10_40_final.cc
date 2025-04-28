#include <TLorentzVector.h>
#include <TChain.h>
#include <TTree.h>
#include <TH1F.h>
#include <TH2F.h>
#include <TH1D.h>
#include <TCanvas.h>
#include <iostream>
#include <vector>
#include <TStyle.h>
#include <cmath>
#include <TRatioPlot.h>

using namespace std;

// Function to compute the invariant mass of two particles
double invariantMass(const TLorentzVector &p1, const TLorentzVector &p2) {
    TLorentzVector p = p1 + p2;
    return p.M();
}

void lambda_Au_Au_3sig_10_40() {

    // Create a TChain
    TChain *ntp_Lambda = new TChain("ntp_Lambda");

    // Add ROOT files to the TChain
    ntp_Lambda->Add("gold_output_1.root");
    ntp_Lambda->Add("gold_output_2.root");
    ntp_Lambda->Add("gold_output_3.root");
    ntp_Lambda->Add("gold_output_4.root");

    // Check if the TChain has been successfully created and files added
    if (ntp_Lambda->GetEntries() == 0) {
        cerr << "Error: Could not retrieve entries from TChain 'ntp_Lambda'." << endl;
        return;
    }

    // Variables for tree branches
    float p1_pt, p1_eta, p1_phi;
    float p2_pt, p2_eta, p2_phi;
    Int_t pair_charge, p1_ch;
    Int_t p1_InEventID, p2_InEventID;
    Int_t eventId, prevEventID = -1;
    float p1_dca, p2_dca, pair_DCAdaughters, pair_decayL, pair_theta;
    float mcentrality, mreweight;

    // Set branch addresses
    ntp_Lambda->SetBranchAddress("p1_pt", &p1_pt);
    ntp_Lambda->SetBranchAddress("p1_eta", &p1_eta);
    ntp_Lambda->SetBranchAddress("p1_phi", &p1_phi);
    ntp_Lambda->SetBranchAddress("p2_pt", &p2_pt);
    ntp_Lambda->SetBranchAddress("p2_eta", &p2_eta);
    ntp_Lambda->SetBranchAddress("p2_phi", &p2_phi);
    ntp_Lambda->SetBranchAddress("pair_charge", &pair_charge);
    ntp_Lambda->SetBranchAddress("p1_ch", &p1_ch);
    ntp_Lambda->SetBranchAddress("p1_InEventID", &p1_InEventID);
    ntp_Lambda->SetBranchAddress("p2_InEventID", &p2_InEventID);
    ntp_Lambda->SetBranchAddress("eventId", &eventId);
    ntp_Lambda->SetBranchAddress("p1_dca", &p1_dca);
    ntp_Lambda->SetBranchAddress("p2_dca", &p2_dca);
    ntp_Lambda->SetBranchAddress("pair_DCAdaughters", &pair_DCAdaughters);
    ntp_Lambda->SetBranchAddress("pair_decayL", &pair_decayL);
    ntp_Lambda->SetBranchAddress("pair_theta", &pair_theta);
    ntp_Lambda->SetBranchAddress("mcentrality", &mcentrality);
    ntp_Lambda->SetBranchAddress("mreweight", &mreweight);

    TFile *outFile_gold_3sig = new TFile("gold_outputs_3sig_10_40.root", "Recreate");

    // Constants for particle masses
    const float mass_p1 = 0.938272;  // Proton mass
    const float mass_p2 = 0.139570;  // Pion mass 

    // Oringal Vectors
    vector<TLorentzVector> lambda_ls;
    vector<TLorentzVector> proton_ls;
    vector<int> proton_id_lambda_ls;
    vector<int> pion_id_lambda_ls;

    vector<TLorentzVector> lambda_us;
    vector<TLorentzVector> proton_us;
    vector<int> proton_id_lambda_us;
    vector<int> pion_id_lambda_us;

    vector<TLorentzVector> lambda_bar_ls;
    vector<TLorentzVector> anti_proton_ls;
    vector<int> anti_proton_id_lambda_bar_ls;
    vector<int> anti_pion_id_lambda_bar_ls;

    vector<TLorentzVector> lambda_bar_us;
    vector<TLorentzVector> anti_proton_us;
    vector<int> anti_proton_id_lambda_bar_us;
    vector<int> anti_pion_id_lambda_bar_us;

    // Original Four Momenta Vectors
    vector<TLorentzVector> fourmoment_Lus_Lus;
    vector<TLorentzVector> fourmoment_proton_us_1;
    vector<TLorentzVector> fourmoment_proton_us_2;
    vector<TLorentzVector> fourmoment_lambda_us_1;
    vector<TLorentzVector> fourmoment_lambda_us_2;
    vector<double> weight_vector_1;

    vector<TLorentzVector> fourmoment_Lus_Lls;
    vector<TLorentzVector> fourmoment_proton_us3;
    vector<TLorentzVector> fourmoment_proton_ls3;
    vector<TLorentzVector> fourmoment_lambda_us3;
    vector<TLorentzVector> fourmoment_lambda_ls3;
    vector<double> weight_vector_2;

    vector<TLorentzVector> fourmoment_Lus_LBarus;
    vector<TLorentzVector> fourmoment_proton_us4;
    vector<TLorentzVector> fourmoment_anti_proton_us4;
    vector<TLorentzVector> fourmoment_lambda_us4;
    vector<TLorentzVector> fourmoment_lambda_bar_us4;
    vector<double> weight_vector_3;

    vector<TLorentzVector> fourmoment_Lus_LBarls;
    vector<TLorentzVector> fourmoment_proton_us5;
    vector<TLorentzVector> fourmoment_anti_proton_ls5;
    vector<TLorentzVector> fourmoment_lambda_us5;
    vector<TLorentzVector> fourmoment_lambda_bar_ls5;
    vector<double> weight_vector_4;

    vector<TLorentzVector> fourmoment_Lls_LBarus;
    vector<TLorentzVector> fourmoment_proton_ls6;
    vector<TLorentzVector> fourmoment_anti_proton_us6;
    vector<TLorentzVector> fourmoment_lambda_ls6;
    vector<TLorentzVector> fourmoment_lambda_bar_us6;
    vector<double> weight_vector_5;

    vector<TLorentzVector> fourmoment_LBarus_LBarus;
    vector<TLorentzVector> fourmoment_anti_proton_us_1;
    vector<TLorentzVector> fourmoment_anti_proton_us_2;
    vector<TLorentzVector> fourmoment_lambda_bar_us_1;
    vector<TLorentzVector> fourmoment_lambda_bar_us_2;
    vector<double> weight_vector_6;

    vector<TLorentzVector> fourmoment_LBarus_LBarls;
    vector<TLorentzVector> fourmoment_anti_proton_us7;
    vector<TLorentzVector> fourmoment_anti_proton_ls7;
    vector<TLorentzVector> fourmoment_lambda_bar_us7;
    vector<TLorentzVector> fourmoment_lambda_bar_ls7;
    vector<double> weight_vector_7;

    // Single Lambda and Lambda Bar Vectors
    vector<TLorentzVector> single_lambda_us;
    vector<TLorentzVector> single_proton_us;

    vector<TLorentzVector> single_lambda_ls;
    vector<TLorentzVector> single_proton_ls;

    vector<TLorentzVector> single_lambda_bar_us;
    vector<TLorentzVector> single_anti_proton_us;

    vector<TLorentzVector> single_lambda_bar_ls;
    vector<TLorentzVector> single_anti_proton_ls;

    // Single Event Pair Vectors
    vector<TLorentzVector> same_event_lambda_us_1;
    vector<TLorentzVector> same_event_proton_us_1;
    vector<TLorentzVector> same_event_lambda_us_2;
    vector<TLorentzVector> same_event_proton_us_2;
    vector<double> same_event_weight_vector_1;

    vector<TLorentzVector> same_event_lambda_us_3;
    vector<TLorentzVector> same_event_proton_us_3;
    vector<TLorentzVector> same_event_lambda_ls_3;
    vector<TLorentzVector> same_event_proton_ls_3;
    vector<double> same_event_weight_vector_2;

    vector<TLorentzVector> same_event_lambda_us_4;
    vector<TLorentzVector> same_event_proton_us_4;
    vector<TLorentzVector> same_event_lambda_bar_us_4;
    vector<TLorentzVector> same_event_anti_proton_us_4;
    vector<double> same_event_weight_vector_3;

    vector<TLorentzVector> same_event_lambda_us_5;
    vector<TLorentzVector> same_event_proton_us_5;
    vector<TLorentzVector> same_event_lambda_bar_ls_5;
    vector<TLorentzVector> same_event_anti_proton_ls_5;
    vector<double> same_event_weight_vector_4;

    vector<TLorentzVector> same_event_lambda_ls_5;
    vector<TLorentzVector> same_event_proton_ls_5;
    vector<TLorentzVector> same_event_lambda_bar_us_5;
    vector<TLorentzVector> same_event_anti_proton_us_5;
    vector<double> same_event_weight_vector_5;

    vector<TLorentzVector> same_event_lambda_bar_us_1;
    vector<TLorentzVector> same_event_anti_proton_us_1;
    vector<TLorentzVector> same_event_lambda_bar_us_2;
    vector<TLorentzVector> same_event_anti_proton_us_2;
    vector<double> same_event_weight_vector_6;

    vector<TLorentzVector> same_event_lambda_bar_us_6;
    vector<TLorentzVector> same_event_anti_proton_us_6;
    vector<TLorentzVector> same_event_lambda_bar_ls_6;
    vector<TLorentzVector> same_event_anti_proton_ls_6;
    vector<double> same_event_weight_vector_7;

    // Four Momenta Vectors for Mixed Events
    vector<TLorentzVector> fourmoment_ME_proton_us_1;
    vector<TLorentzVector> fourmoment_ME_proton_us_2;
    vector<TLorentzVector> fourmoment_ME_lambda_us_1;
    vector<TLorentzVector> fourmoment_ME_lambda_us_2;
    vector<double> ME_weight_vector_1;

    vector<TLorentzVector> fourmoment_ME_proton_us_3;
    vector<TLorentzVector> fourmoment_ME_proton_ls_3;
    vector<TLorentzVector> fourmoment_ME_lambda_us_3;
    vector<TLorentzVector> fourmoment_ME_lambda_ls_3;
    vector<double> ME_weight_vector_2;

    vector<TLorentzVector> fourmoment_ME_proton_us_4;
    vector<TLorentzVector> fourmoment_ME_anti_proton_us_4;
    vector<TLorentzVector> fourmoment_ME_lambda_us_4;
    vector<TLorentzVector> fourmoment_ME_lambda_bar_us_4;
    vector<double> ME_weight_vector_3;

    vector<TLorentzVector> fourmoment_ME_proton_us_5;
    vector<TLorentzVector> fourmoment_ME_anti_proton_ls_5;
    vector<TLorentzVector> fourmoment_ME_lambda_us_5;
    vector<TLorentzVector> fourmoment_ME_lambda_bar_ls_5;
    vector<double> ME_weight_vector_4;

    vector<TLorentzVector> fourmoment_ME_proton_ls_5;
    vector<TLorentzVector> fourmoment_ME_anti_proton_us_5;
    vector<TLorentzVector> fourmoment_ME_lambda_ls_5;
    vector<TLorentzVector> fourmoment_ME_lambda_bar_us_5;
    vector<double> ME_weight_vector_5;

    vector<TLorentzVector> fourmoment_ME_anti_proton_us_1;
    vector<TLorentzVector> fourmoment_ME_anti_proton_us_2;
    vector<TLorentzVector> fourmoment_ME_lambda_bar_us_1;
    vector<TLorentzVector> fourmoment_ME_lambda_bar_us_2;
    vector<double> ME_weight_vector_6;

    vector<TLorentzVector> fourmoment_ME_anti_proton_us_6;
    vector<TLorentzVector> fourmoment_ME_anti_proton_ls_6;
    vector<TLorentzVector> fourmoment_ME_lambda_bar_us_6;
    vector<TLorentzVector> fourmoment_ME_lambda_bar_ls_6;
    vector<double> ME_weight_vector_7;

    vector<float> counts_successfull_ME_US_US_LL;
    vector<float> counts_successfull_ME_US_LS_LL;
    vector<float> counts_successfull_ME_US_US_LLBar;
    vector<float> counts_successfull_ME_US_LS_LLBar;
    vector<float> counts_successfull_ME_LS_US_LLBar;
    vector<float> counts_successfull_ME_US_US_LBarLBar;
    vector<float> counts_successfull_ME_US_LS_LBarLBar;

    vector<float> needsbettername;
    vector<float> needsbettername2;
    vector<float> needsbettername3;
    vector<float> needsbettername4;
    vector<float> needsbettername5;
    vector<float> needsbettername6;
    vector<float> needsbettername7;

    // 2d Invariant Mass Histograms before Cuts
    TH2F *h2_lambda_us_lambda_us = new TH2F("h2_lambda_us_lambda_us", "Unlike Sign Lambda - Unlike Sign Lambda (Includes Background)", 180, 1.0, 1.2, 180, 1.0, 1.2);
    TH2F *h2_lambda_us_lambda_ls = new TH2F("h2_lambda_us_lambda_ls", "Unlike Sign Lambda - Like Sign Lambda (Background)", 180, 1.0, 1.2, 180, 1.0, 1.2);
    TH2F *h2_lambda_us_lambda_bar_us = new TH2F("h2_lambda_us_lambda_bar_us", "Unlike Sign Lambda - Unlike Sign Lambda Bar (Includes Background)", 180, 1.0, 1.2, 180, 1.0, 1.2);
    TH2F *h2_lambda_us_lambda_bar_ls = new TH2F("h2_lambda_us_lambda_bar_ls", "Unlike Sign Lambda - Like Sign Lambda Bar (Background)", 180, 1.0, 1.2, 180, 1.0, 1.2);
    TH2F *h2_lambda_bar_us_lambda_bar_us = new TH2F("h2_lambda_bar_us_lambda_bar_us", "Unlike Sign Lambda Bar - Unlike Sign Lambda Bar (Includes Background)", 180, 1.0, 1.2, 180, 1.0, 1.2);
    TH2F *h2_lambda_bar_us_lambda_bar_ls = new TH2F("h2_lambda_bar_us_lambda_ls", "Unlike Sign Lambda Bar - Like Sign Lambda Bar (Background)", 180, 1.0, 1.2, 180, 1.0, 1.2);

    TH2F *h2_no_cuts_L0_L0_p1pt_p2pt_US_US = new TH2F("h2_no_cuts_L0_L0_p1pt_p2pt_US_US", "p1_pt vs p2_pt", 50, 0, 5, 50, 0, 5);
    TH2F *h2_no_cuts_L0_L0_p1eta_p2eta_US_US = new TH2F("h2_no_cuts_L0_L0_p1eta_p2eta_US_US", "p1_eta vs p2_eta", 50, -1.5, 1.5, 50, -1.5, 1.5);
    TH2F *h2_no_cuts_L0_L0_p1phi_p2phi_US_US = new TH2F("h2_no_cuts_L0_L0_p1phi_p2phi_US_US", "p1_phi vs p2_phi", 50, -3, 3, 50, -3, 3);

    TH2F *h2_no_cuts_L0_L0_p1pt_p2pt_US_LS = new TH2F("h2_no_cuts_L0_L0_p1pt_p2pt_US_LS", "p1_pt vs p2_pt", 50, 0, 5, 50, 0, 5);
    TH2F *h2_no_cuts_L0_L0_p1eta_p2eta_US_LS = new TH2F("h2_no_cuts_L0_L0_p1eta_p2eta_US_LS", "p1_eta vs p2_eta", 50, -1.5, 1.5, 50, -1.5, 1.5);
    TH2F *h2_no_cuts_L0_L0_p1phi_p2phi_US_LS = new TH2F("h2_no_cuts_L0_L0_p1phi_p2phi_US_LS", "p1_phi vs p2_phi", 50, -3.5, 3.5, 50, -3.5, 3.5);

    TH2F *h2_no_cuts_L0_L0bar_p1pt_p2pt_US_US = new TH2F("h2_no_cuts_L0_L0bar_p1pt_p2pt_US_US", "p1_pt vs p2_pt", 50, 0, 5, 50, 0, 5);
    TH2F *h2_no_cuts_L0_L0bar_p1eta_p2eta_US_US = new TH2F("h2_no_cuts_L0_L0bar_p1eta_p2eta_US_US", "p1_eta vs p2_eta", 50, -1.5, 1.5, 50, -1.5, 1.5);
    TH2F *h2_no_cuts_L0_L0bar_p1phi_p2phi_US_US = new TH2F("h2_no_cuts_L0_L0bar_p1phi_p2phi_US_US", "p1_phi vs p2_phi", 50, -3.5, 3.5, 50, -3.5, 3.5);

    TH2F *h2_no_cuts_L0_L0bar_p1pt_p2pt_US_LS = new TH2F("h2_no_cuts_L0_L0bar_p1pt_p2pt_US_LS", "p1_pt vs p2_pt", 50, 0, 5, 50, 0, 5);
    TH2F *h2_no_cuts_L0_L0bar_p1eta_p2eta_US_LS = new TH2F("h2_no_cuts_L0_L0bar_p1eta_p2eta_US_LS", "p1_eta vs p2_eta", 50, -1.5, 1.5, 50, -1.5, 1.5);
    TH2F *h2_no_cuts_L0_L0bar_p1phi_p2phi_US_LS = new TH2F("h2_p1phi_p2phi_4", "p1_phi vs p2_phi", 50, -3.5, 3.5, 50, -3.5, 3.5);

    TH2F *h2_no_cuts_L0bar_L0bar_p1pt_p2pt_US_US = new TH2F("h2_no_cuts_L0bar_L0bar_p1pt_p2pt_US_US", "p1_pt vs p2_pt", 50, 0, 5, 50, 0, 5);
    TH2F *h2_no_cuts_L0bar_L0bar_p1eta_p2eta_US_US = new TH2F("h2_no_cuts_L0bar_L0bar_p1eta_p2eta_US_US", "p1_eta vs p2_eta", 50, -1.5, 1.5, 50, -1.5, 1.5);
    TH2F *h2_no_cuts_L0bar_L0bar_p1phi_p2phi_US_US = new TH2F("h2_no_cuts_L0bar_L0bar_p1phi_p2phi_US_US", "p1_phi vs p2_phi", 50, -3.5, 3.5, 50, -3.5, 3.5);

    TH2F *h2_no_cuts_L0bar_L0bar_p1pt_p2pt_US_LS = new TH2F("h2_no_cuts_L0bar_L0bar_p1pt_p2pt_US_LS", "p1_pt vs p2_pt", 50, 0, 5, 50, 0, 5);
    TH2F *h2_no_cuts_L0bar_L0bar_p1eta_p2eta_US_LS = new TH2F("h2_no_cuts_L0bar_L0bar_p1eta_p2eta_US_LS", "p1_eta vs p2_eta", 50, -1.5, 1.5, 50, -1.5, 1.5);
    TH2F *h2_no_cuts_L0bar_L0bar_p1phi_p2phi_US_LS = new TH2F("h2_no_cuts_L0bar_L0bar_p1phi_p2phi_US_LS", "p1_phi vs p2_phi", 50, -3.5, 3.5, 50, -3.5, 3.5);
    
    // Invariant Mass Histograms- Check Pre-Cuts
    TH2F *h2_no_cut_invMass_lambda_us_lambda_us = new TH2F("h2_no_cut_invMass_lambda_us_lambda_us", "Unlike Sign Lambda - Unlike Sign Lambda (test)", 180, 1.0, 1.2, 180, 1.0, 1.2);
    TH2F *h2_no_cut_invMass_lambda_us_lambda_ls = new TH2F("h2_no_cut_invMass_lambda_us_lambda_ls", "Unlike Sign Lambda - Like Sign Lambda (test2)", 180, 1.0, 1.2, 180, 1.0, 1.2);
    TH2F *h2_no_cut_invMass_lambda_us_lambda_bar_us = new TH2F("h2_no_cut_invMass_lambda_us_lambda_bar_us", "Unlike Sign Lambda - Unlike Sign Lambda Bar (test)", 180, 1.0, 1.2, 180, 1.0, 1.2);
    TH2F *h2_no_cut_invMass_lambda_us_lambda_bar_ls = new TH2F("h2_no_cut_invMass_lambda_us_lambda_bar_ls", "Unlike Sign Lambda - Like Sign Lambda Bar (test2)", 180, 1.0, 1.2, 180, 1.0, 1.2);
    TH2F *h2_no_cut_invMass_lambda_bar_us_lambda_bar_us = new TH2F("h2_no_cut_invMass_lambda_bar_us_lambda_bar_us", "Unlike Sign Lambda Bar - Unlike Sign Lambda Bar (test)", 180, 1.0, 1.2, 180, 1.0, 1.2);
    TH2F *h2_no_cut_invMass_lambda_bar_us_lambda_bar_ls = new TH2F("h2_no_cut_invMass_lambda_bar_us_lambda_bar_ls", "Unlike Sign Lambda Bar - Like Sign Lambda Bar (test2)", 180, 1.0, 1.2, 180, 1.0, 1.2);

    TH2F *h2_no_cut_check_L0_L0_p1pt_p2pt_US_US = new TH2F("h2_no_cut_check_L0_L0_p1pt_p2pt_US_US", "p1_pt vs p2_pt", 50, 0, 5, 50, 0, 5);
    TH2F *h2_no_cut_check_L0_L0_p1eta_p2eta_US_US = new TH2F("h2_no_cut_check_L0_L0_p1eta_p2eta_US_US", "p1_eta vs p2_eta", 50, -1.5, 1.5, 50, -1.5, 1.5);
    TH2F *h2_no_cut_check_L0_L0_p1phi_p2phi_US_US = new TH2F("h2_no_cut_check_L0_L0_p1phi_p2phi_US_US", "p1_phi vs p2_phi", 50, -3, 3, 50, -3, 3);

    TH2F *h2_no_cut_check_L0_L0_p1pt_p2pt_US_LS = new TH2F("h2_no_cut_check_L0_L0_p1pt_p2pt_US_LS", "p1_pt vs p2_pt", 50, 0, 5, 50, 0, 5);
    TH2F *h2_no_cut_check_L0_L0_p1eta_p2eta_US_LS = new TH2F("h2_no_cut_check_L0_L0_p1eta_p2eta_US_LS", "p1_eta vs p2_eta", 50, -1.5, 1.5, 50, -1.5, 1.5);
    TH2F *h2_no_cut_check_L0_L0_p1phi_p2phi_US_LS = new TH2F("h2_no_cut_check_L0_L0_p1phi_p2phi_US_LS", "p1_phi vs p2_phi", 50, -3.5, 3.5, 50, -3.5, 3.5);

    TH2F *h2_no_cut_check_L0_L0bar_p1pt_p2pt_US_US = new TH2F("h2_no_cut_check_L0_L0bar_p1pt_p2pt_US_US", "p1_pt vs p2_pt", 50, 0, 5, 50, 0, 5);
    TH2F *h2_no_cut_check_L0_L0bar_p1eta_p2eta_US_US = new TH2F("h2_no_cut_check_L0_L0bar_p1eta_p2eta_US_US", "p1_eta vs p2_eta", 50, -1.5, 1.5, 50, -1.5, 1.5);
    TH2F *h2_no_cut_check_L0_L0bar_p1phi_p2phi_US_US = new TH2F("h2_no_cut_check_L0_L0bar_p1phi_p2phi_US_US", "p1_phi vs p2_phi", 50, -3, 3, 50, -3, 3);

    TH2F *h2_no_cut_check_L0_L0bar_p1pt_p2pt_US_LS = new TH2F("h2_no_cut_check_L0_L0bar_p1pt_p2pt_US_LS", "p1_pt vs p2_pt", 50, 0, 5, 50, 0, 5);
    TH2F *h2_no_cut_check_L0_L0bar_p1eta_p2eta_US_LS = new TH2F("h2_no_cut_check_L0_L0bar_p1eta_p2eta_US_LS", "p1_eta vs p2_eta", 50, -1.5, 1.5, 50, -1.5, 1.5);
    TH2F *h2_no_cut_check_L0_L0bar_p1phi_p2phi_US_LS = new TH2F("h2_no_cut_check_L0_L0bar_p1phi_p2phi_US_LS", "p1_phi vs p2_phi", 50, -3.5, 3.5, 50, -3.5, 3.5);

    TH2F *h2_no_cut_check_L0bar_L0bar_p1pt_p2pt_US_US = new TH2F("h2_no_cut_check_L0bar_L0bar_p1pt_p2pt_US_US", "p1_pt vs p2_pt", 50, 0, 5, 50, 0, 5);
    TH2F *h2_no_cut_check_L0bar_L0bar_p1eta_p2eta_US_US = new TH2F("h2_no_cut_check_L0bar_L0bar_p1eta_p2eta_US_US", "p1_eta vs p2_eta", 50, -1.5, 1.5, 50, -1.5, 1.5);
    TH2F *h2_no_cut_check_L0bar_L0bar_p1phi_p2phi_US_US = new TH2F("h2_no_cut_check_L0bar_L0bar_p1phi_p2phi_US_US", "p1_phi vs p2_phi", 50, -3, 3, 50, -3, 3);

    TH2F *h2_no_cut_check_L0bar_L0bar_p1pt_p2pt_US_LS = new TH2F("h2_no_cut_check_L0bar_L0bar_p1pt_p2pt_US_LS", "p1_pt vs p2_pt", 50, 0, 5, 50, 0, 5);
    TH2F *h2_no_cut_check_L0bar_L0bar_p1eta_p2eta_US_LS = new TH2F("h2_no_cut_check_L0bar_L0bar_p1eta_p2eta_US_LS", "p1_eta vs p2_eta", 50, -1.5, 1.5, 50, -1.5, 1.5);
    TH2F *h2_no_cut_check_L0bar_L0bar_p1phi_p2phi_US_LS = new TH2F("h2_no_cut_check_L0bar_L0bar_p1phi_p2phi_US_LS", "p1_phi vs p2_phi", 50, -3.5, 3.5, 50, -3.5, 3.5);

    // Invariant Mass Histograms after Cuts
    TH2F *h2_invMass_lambda_us_lambda_us = new TH2F("h2_invMass_lambda_us_lambda_us", "Unlike Sign Lambda - Unlike Sign Lambda (test)", 180, 1.0, 1.2, 180, 1.0, 1.2);
    TH2F *h2_invMass_lambda_us_lambda_ls = new TH2F("h2_invMass_lambda_us_lambda_ls", "Unlike Sign Lambda - Like Sign Lambda (test2)", 180, 1.0, 1.2, 180, 1.0, 1.2);
    TH2F *h2_invMass_lambda_us_lambda_bar_us = new TH2F("h2_invMass_lambda_us_lambda_bar_us", "Unlike Sign Lambda - Unlike Sign Lambda Bar (test)", 180, 1.0, 1.2, 180, 1.0, 1.2);
    TH2F *h2_invMass_lambda_us_lambda_bar_ls = new TH2F("h2_invMass_lambda_us_lambda_bar_ls", "Unlike Sign Lambda - Like Sign Lambda Bar (test2)", 180, 1.0, 1.2, 180, 1.0, 1.2);
    TH2F *h2_invMass_lambda_bar_us_lambda_bar_us = new TH2F("h2_invMass_lambda_bar_us_lambda_bar_us", "Unlike Sign Lambda Bar - Unlike Sign Lambda Bar (test)", 180, 1.0, 1.2, 180, 1.0, 1.2);
    TH2F *h2_invMass_lambda_bar_us_lambda_bar_ls = new TH2F("h2_invMass_lambda_bar_us_lambda_bar_ls", "Unlike Sign Lambda Bar - Like Sign Lambda Bar (test2)", 180, 1.0, 1.2, 180, 1.0, 1.2);

    TH2F *h2_invMass_outside_lambda_us_lambda_us = new TH2F("h2_invMass_outside_lambda_us_lambda_us", "Unlike Sign Lambda - Unlike Sign Lambda (test)", 180, 1.0, 1.2, 180, 1.0, 1.2);
    TH2F *h2_invMass_outside_lambda_us_lambda_ls = new TH2F("h2_invMass_outside_lambda_us_lambda_ls", "Unlike Sign Lambda - Like Sign Lambda (test2)", 180, 1.0, 1.2, 180, 1.0, 1.2);
    TH2F *h2_invMass_outside_lambda_us_lambda_bar_us = new TH2F("h2_invMass_outside_lambda_us_lambda_bar_us", "Unlike Sign Lambda - Unlike Sign Lambda Bar (test)", 180, 1.0, 1.2, 180, 1.0, 1.2);
    TH2F *h2_invMass_outside_lambda_us_lambda_bar_ls = new TH2F("h2_invMass_outside_lambda_us_lambda_bar_ls", "Unlike Sign Lambda - Like Sign Lambda Bar (test2)", 180, 1.0, 1.2, 180, 1.0, 1.2);
    TH2F *h2_invMass_outside_lambda_bar_us_lambda_bar_us = new TH2F("h2_invMass_outside_lambda_bar_us_lambda_bar_us", "Unlike Sign Lambda Bar - Unlike Sign Lambda Bar (test)", 180, 1.0, 1.2, 180, 1.0, 1.2);
    TH2F *h2_invMass_outside_lambda_bar_us_lambda_bar_ls = new TH2F("h2_invMass_outside_lambda_bar_us_lambda_bar_ls", "Unlike Sign Lambda Bar - Like Sign Lambda Bar (test2)", 180, 1.0, 1.2, 180, 1.0, 1.2);

    TH2F *h2_cut_L0_L0_p1pt_p2pt_US_US = new TH2F("h2_cut_L0_L0_p1pt_p2pt_US_US", "p1_pt vs p2_pt", 50, 0, 5, 50, 0, 5);
    TH2F *h2_cut_L0_L0_p1eta_p2eta_US_US = new TH2F("h2_cut_L0_L0_p1eta_p2eta_US_US", "p1_eta vs p2_eta", 50, -1.5, 1.5, 50, -1.5, 1.5);
    TH2F *h2_cut_L0_L0_p1phi_p2phi_US_US = new TH2F("h2_cut_L0_L0_p1phi_p2phi_US_US", "p1_phi vs p2_phi", 50, -3, 3, 50, -3, 3);

    TH2F *h2_cut_L0_L0_p1pt_p2pt_US_LS = new TH2F("h2_cut_L0_L0_p1pt_p2pt_US_LS", "p1_pt vs p2_pt", 50, 0, 5, 50, 0, 5);
    TH2F *h2_cut_L0_L0_p1eta_p2eta_US_LS = new TH2F("h2_cut_L0_L0_p1eta_p2eta_US_LS", "p1_eta vs p2_eta", 50, -1.5, 1.5, 50, -1.5, 1.5);
    TH2F *h2_cut_L0_L0_p1phi_p2phi_US_LS = new TH2F("h2_cut_L0_L0_p1phi_p2phi_US_LS", "p1_phi vs p2_phi", 50, -3.5, 3.5, 50, -3.5, 3.5);

    TH2F *h2_cut_L0_L0bar_p1pt_p2pt_US_US = new TH2F("h2_cut_L0_L0bar_p1pt_p2pt_US_US", "p1_pt vs p2_pt", 50, 0, 5, 50, 0, 5);
    TH2F *h2_cut_L0_L0bar_p1eta_p2eta_US_US = new TH2F("h2_cut_L0_L0bar_p1eta_p2eta_US_US", "p1_eta vs p2_eta", 50, -1.5, 1.5, 50, -1.5, 1.5);
    TH2F *h2_cut_L0_L0bar_p1phi_p2phi_US_US = new TH2F("h2_cut_L0_L0bar_p1phi_p2phi_US_US", "p1_phi vs p2_phi", 50, -3, 3, 50, -3, 3);

    TH2F *h2_cut_L0_L0bar_p1pt_p2pt_US_LS = new TH2F("h2_cut_L0_L0bar_p1pt_p2pt_US_LS", "p1_pt vs p2_pt", 50, 0, 5, 50, 0, 5);
    TH2F *h2_cut_L0_L0bar_p1eta_p2eta_US_LS = new TH2F("h2_cut_L0_L0bar_p1eta_p2eta_US_LS", "p1_eta vs p2_eta", 50, -1.5, 1.5, 50, -1.5, 1.5);
    TH2F *h2_cut_L0_L0bar_p1phi_p2phi_US_LS = new TH2F("h2_cut_L0_L0bar_p1phi_p2phi_US_LS", "p1_phi vs p2_phi", 50, -3.5, 3.5, 50, -3.5, 3.5);

    TH2F *h2_cut_L0bar_L0bar_p1pt_p2pt_US_US = new TH2F("h2_cut_L0bar_L0bar_p1pt_p2pt_US_US", "p1_pt vs p2_pt", 50, 0, 5, 50, 0, 5);
    TH2F *h2_cut_L0bar_L0bar_p1eta_p2eta_US_US = new TH2F("h2_cut_L0bar_L0bar_p1eta_p2eta_US_US", "p1_eta vs p2_eta", 50, -1.5, 1.5, 50, -1.5, 1.5);
    TH2F *h2_cut_L0bar_L0bar_p1phi_p2phi_US_US = new TH2F("h2_cut_L0bar_L0bar_p1phi_p2phi_US_US", "p1_phi vs p2_phi", 50, -3, 3, 50, -3, 3);

    TH2F *h2_cut_L0bar_L0bar_p1pt_p2pt_US_LS = new TH2F("h2_cut_L0bar_L0bar_p1pt_p2pt_US_LS", "p1_pt vs p2_pt", 50, 0, 5, 50, 0, 5);
    TH2F *h2_cut_L0bar_L0bar_p1eta_p2eta_US_LS = new TH2F("h2_cut_L0bar_L0bar_p1eta_p2eta_US_LS", "p1_eta vs p2_eta", 50, -1.5, 1.5, 50, -1.5, 1.5);
    TH2F *h2_cut_L0bar_L0bar_p1phi_p2phi_US_LS = new TH2F("h2_cut_L0bar_L0bar_p1phi_p2phi_US_LS", "p1_phi vs p2_phi", 50, -3.5, 3.5, 50, -3.5, 3.5);

    TH2F *h2_cut_outside_L0_L0_p1pt_p2pt_US_US = new TH2F("h2_cut_outside_L0_L0_p1pt_p2pt_US_US", "p1_pt vs p2_pt", 50, 0, 5, 50, 0, 5);
    TH2F *h2_cut_outside_L0_L0_p1eta_p2eta_US_US = new TH2F("h2_cut_outside_L0_L0_p1eta_p2eta_US_US", "p1_eta vs p2_eta", 50, -1.5, 1.5, 50, -1.5, 1.5);
    TH2F *h2_cut_outside_L0_L0_p1phi_p2phi_US_US = new TH2F("h2_cut_outside_L0_L0_p1phi_p2phi_US_US", "p1_phi vs p2_phi", 50, -3, 3, 50, -3, 3);

    TH2F *h2_cut_outside_L0_L0_p1pt_p2pt_US_LS = new TH2F("h2_cut_outside_L0_L0_p1pt_p2pt_US_LS", "p1_pt vs p2_pt", 50, 0, 5, 50, 0, 5);
    TH2F *h2_cut_outside_L0_L0_p1eta_p2eta_US_LS = new TH2F("h2_cut_outside_L0_L0_p1eta_p2eta_US_LS", "p1_eta vs p2_eta", 50, -1.5, 1.5, 50, -1.5, 1.5);
    TH2F *h2_cut_outside_L0_L0_p1phi_p2phi_US_LS = new TH2F("h2_cut_outside_L0_L0_p1phi_p2phi_US_LS", "p1_phi vs p2_phi", 50, -3.5, 3.5, 50, -3.5, 3.5);

    TH2F *h2_cut_outside_L0_L0bar_p1pt_p2pt_US_US = new TH2F("h2_cut_outside_L0_L0bar_p1pt_p2pt_US_US", "p1_pt vs p2_pt", 50, 0, 5, 50, 0, 5);
    TH2F *h2_cut_outside_L0_L0bar_p1eta_p2eta_US_US = new TH2F("h2_cut_outside_L0_L0bar_p1eta_p2eta_US_US", "p1_eta vs p2_eta", 50, -1.5, 1.5, 50, -1.5, 1.5);
    TH2F *h2_cut_outside_L0_L0bar_p1phi_p2phi_US_US = new TH2F("h2_cut_outside_L0_L0bar_p1phi_p2phi_US_US", "p1_phi vs p2_phi", 50, -3, 3, 50, -3, 3);

    TH2F *h2_cut_outside_L0_L0bar_p1pt_p2pt_US_LS = new TH2F("h2_cut_outside_L0_L0bar_p1pt_p2pt_US_LS", "p1_pt vs p2_pt", 50, 0, 5, 50, 0, 5);
    TH2F *h2_cut_outside_L0_L0bar_p1eta_p2eta_US_LS = new TH2F("h2_cut_outside_L0_L0bar_p1eta_p2eta_US_LS", "p1_eta vs p2_eta", 50, -1.5, 1.5, 50, -1.5, 1.5);
    TH2F *h2_cut_outside_L0_L0bar_p1phi_p2phi_US_LS = new TH2F("h2_cut_outside_L0_L0bar_p1phi_p2phi_US_LS", "p1_phi vs p2_phi", 50, -3.5, 3.5, 50, -3.5, 3.5);

    TH2F *h2_cut_outside_L0bar_L0bar_p1pt_p2pt_US_US = new TH2F("h2_cut_outside_L0bar_L0bar_p1pt_p2pt_US_US", "p1_pt vs p2_pt", 50, 0, 5, 50, 0, 5);
    TH2F *h2_cut_outside_L0bar_L0bar_p1eta_p2eta_US_US = new TH2F("h2_cut_outside_L0bar_L0bar_p1eta_p2eta_US_US", "p1_eta vs p2_eta", 50, -1.5, 1.5, 50, -1.5, 1.5);
    TH2F *h2_cut_outside_L0bar_L0bar_p1phi_p2phi_US_US = new TH2F("h2_cut_outside_L0bar_L0bar_p1phi_p2phi_US_US", "p1_phi vs p2_phi", 50, -3, 3, 50, -3, 3);

    TH2F *h2_cut_outside_L0bar_L0bar_p1pt_p2pt_US_LS = new TH2F("h2_cut_outside_L0bar_L0bar_p1pt_p2pt_US_LS", "p1_pt vs p2_pt", 50, 0, 5, 50, 0, 5);
    TH2F *h2_cut_outside_L0bar_L0bar_p1eta_p2eta_US_LS = new TH2F("h2_cut_outside_L0bar_L0bar_p1eta_p2eta_US_LS", "p1_eta vs p2_eta", 50, -1.5, 1.5, 50, -1.5, 1.5);
    TH2F *h2_cut_outside_L0bar_L0bar_p1phi_p2phi_US_LS = new TH2F("h2_cut_outside_L0bar_L0bar_p1phi_p2phi_US_LS", "p1_phi vs p2_phi", 50, -3.5, 3.5, 50, -3.5, 3.5);

    // Histograms for the Angluar Distribution (Cos(theta*))
    TH1D *h_outside_cos_theta_star = new TH1D("h_outside_cos_theta_star", "Angular Distribution for Unlike Sign Lambda - Unlike Sign Lambda (cos_theta_star*)", 10, -1, 1);
    TH1D *h_outside_cos_theta_star2 = new TH1D("h_outside_cos_theta_star2", "Angular Distribution for Unlike Sign Lambda - Like Sign Lambda (cos_theta_star*)", 10, -1, 1);
    TH1D *h_outside_cos_theta_star3 = new TH1D("h_outside_cos_theta_star3", "Angular Distribution for Unlike Sign Lambda - Unlike Sign Lambda Bar (cos_theta_star*)", 10, -1, 1);
    TH1D *h_outside_cos_theta_star4 = new TH1D("h_outside_cos_theta_star4", "Angular Distribution for Unlike Sign Lambda - Like Sign Lambda Bar (cos_theta_star*)", 10, -1, 1);
    TH1D *h_outside_cos_theta_star5 = new TH1D("h_outside_cos_theta_star5", "Angular Distribution for Unlike Sign Lambda Bar - Unlike Sign Lambda Bar (cos_theta_star*)", 10, -1, 1);
    TH1D *h_outside_cos_theta_star6 = new TH1D("h_outside_cos_theta_star6", "Angular Distribution for Unlike Sign Lambda Bar - Like Sign Lambda Bar (cos_theta_star*)", 10, -1, 1);

    // Histograms for the Angluar Distribution (Cos(theta*))
    TH1D *h_cos_theta_star = new TH1D("h_cos_theta_star", "Angular Distribution for Unlike Sign Lambda - Unlike Sign Lambda (cos_theta_star*)", 10, -1, 1);
    TH1D *h_cos_theta_star2 = new TH1D("h_cos_theta_star2", "Angular Distribution for Unlike Sign Lambda - Like Sign Lambda (cos_theta_star*)", 10, -1, 1);
    TH1D *h_cos_theta_star3 = new TH1D("h_cos_theta_star3", "Angular Distribution for Unlike Sign Lambda - Unlike Sign Lambda Bar (cos_theta_star*)", 10, -1, 1);
    TH1D *h_cos_theta_star4 = new TH1D("h_cos_theta_star4", "Angular Distribution for Unlike Sign Lambda - Like Sign Lambda Bar (cos_theta_star*)", 10, -1, 1);
    TH1D *h_cos_theta_star5 = new TH1D("h_cos_theta_star5", "Angular Distribution for Unlike Sign Lambda Bar - Unlike Sign Lambda Bar (cos_theta_star*)", 10, -1, 1);
    TH1D *h_cos_theta_star6 = new TH1D("h_cos_theta_star6", "Angular Distribution for Unlike Sign Lambda Bar - Like Sign Lambda Bar (cos_theta_star*)", 10, -1, 1);

    // Define histograms for Delta R distributions
    TH1D *h_delta_R_US_US_ll = new TH1D("h_delta_R_US_US_ll", "Delta R Distribution for US-US Lambda - Lambda Pairs", 50, 0, 5);
    TH1D *h_delta_R_US_LS_ll = new TH1D("h_delta_R_US_LS_ll", "Delta R Distribution for US-LS Lambda - Lambda Pairs", 50, 0, 5);
    TH1D *h_delta_R_US_US_llbar = new TH1D("h_delta_R_US_US_llbar", "Delta R Distribution for US-US Lambda - Lambda Bar Pairs", 50, 0, 5);
    TH1D *h_delta_R_US_LS_llbar = new TH1D("h_delta_R_US_LS_llbar", "Delta R Distribution for US-LS Lambda - Lambda Bar Pairs", 50, 0, 5);
    TH1D *h_delta_R_US_US_lbarlbar = new TH1D("h_delta_R_US_US_lbarlbar", "Delta R Distribution for US-US Lambda Bar - Lambda Bar Pairs", 50, 0, 5);
    TH1D *h_delta_R_US_LS_lbarlbar = new TH1D("h_delta_R_US_LS_lbarlbar", "Delta R Distribution for US-LS Lambda Bar - Lambda Bar Pairs", 50, 0, 5);

    // Histograms for Delta Phi Distributions
    TH1D *h_delta_phi_US_US_ll = new TH1D("h_delta_phi_US_US_ll", "Delta Phi for US-US Lambda - Lambda Pairs", 50, 0, TMath::Pi());
    TH1D *h_delta_phi_US_LS_ll = new TH1D("h_delta_phi_US_LS_ll", "Delta Phi for US-LS Lambda - Lambda Pairs", 50, 0, TMath::Pi());
    TH1D *h_delta_phi_US_US_llbar = new TH1D("h_delta_phi_US_US_llbar", "Delta Phi for US-US Lambda - Lambda Bar Pairs", 50, 0, TMath::Pi());
    TH1D *h_delta_phi_US_LS_llbar = new TH1D("h_delta_phi_US_LS_llbar", "Delta Phi for US-LS Lambda - Lambda Bar Pairs", 50, 0, TMath::Pi());
    TH1D *h_delta_phi_US_US_lbarlbar = new TH1D("h_delta_phi_US_US_lbarlbar", "Delta Phi for US-US Lambda Bar - Lambda Bar Pairs", 50, 0, TMath::Pi());
    TH1D *h_delta_phi_US_LS_lbarlbar = new TH1D("h_delta_phi_US_LS_lbarlbar", "Delta Phi for US-LS Lambda Bar - Lambda Bar Pairs", 50, 0, TMath::Pi());

    // Restricted Histograms for ME Pairs
    TH2F *h2_SE_lambda_us_lambda_us = new TH2F("h2_SE_lambda_us_lambda_us", "test", 180, 1.0, 1.2, 180, 1.0, 1.2);
    TH2F *h2_SE_lambda_us_lambda_ls = new TH2F("h2_SE_lambda_us_lambda_ls", "test", 180, 1.0, 1.2, 180, 1.0, 1.2);
    TH2F *h2_SE_lambda_us_lambda_bar_us = new TH2F("h2_SE_lambda_us_lambda_bar_us", "test", 180, 1.0, 1.2, 180, 1.0, 1.2);
    TH2F *h2_SE_lambda_us_lambda_bar_ls = new TH2F("h2_SE_lambda_us_lambda_bar_ls", "test", 180, 1.0, 1.2, 180, 1.0, 1.2);
    TH2F *h2_SE_lambda_bar_us_lambda_bar_us = new TH2F("h2_SE_lambda_bar_us_lambda_bar_us", "test", 180, 1.0, 1.2, 180, 1.0, 1.2);
    TH2F *h2_SE_lambda_bar_us_lambda_bar_ls = new TH2F("h2_SE_lambda_bar_us_lambda_bar_ls", "test", 180, 1.0, 1.2, 180, 1.0, 1.2);

    TH2F *h2_restricted_L0_L0_p1pt_p2pt_US_US = new TH2F("h2_restricted_L0_L0_p1pt_p2pt_US_US", "p1pt vs p2pt", 50, 0, 5, 50, 0, 5);
    TH2F *h2_restricted_L0_L0_p1eta_p2eta_US_US = new TH2F("h2_restricted_L0_L0_p1eta_p2eta_US_US", "p1eta vs p2eta", 50, -1.5, 1.5, 50, -1.5, 1.5);
    TH2F *h2_restricted_L0_L0_p1phi_p2phi_US_US = new TH2F("h2_restricted_L0_L0_p1phi_p2phi_US_US", "p1phi vs p2phi", 50, -3, 3, 50, -3, 3);

    TH2F *h2_restricted_L0_L0_p1pt_p2pt_US_LS = new TH2F("h2_restricted_L0_L0_p1pt_p2pt_US_LS", "p1pt vs p2pt", 50, 0, 5, 50, 0, 5);
    TH2F *h2_restricted_L0_L0_p1eta_p2eta_US_LS = new TH2F("h2_restricted_L0_L0_p1eta_p2eta_US_LS", "p1eta vs p2eta", 50, -1.5, 1.5, 50, -1.5, 1.5);
    TH2F *h2_restricted_L0_L0_p1phi_p2phi_US_LS = new TH2F("h2_restricted_L0_L0_p1phi_p2phi_US_LS", "p1phi vs p2phi", 50, -3, 3, 50, -3, 3);

    TH2F *h2_restricted_L0_L0bar_p1pt_p2pt_US_US = new TH2F("h2_restricted_L0_L0bar_p1pt_p2pt_US_US", "p1pt vs p2pt", 50, 0, 5, 50, 0, 5);
    TH2F *h2_restricted_L0_L0bar_p1eta_p2eta_US_US = new TH2F("h2_restricted_L0_L0bar_p1eta_p2eta_US_US", "p1eta vs p2eta", 50, -1.5, 1.5, 50, -1.5, 1.5);
    TH2F *h2_restricted_L0_L0bar_p1phi_p2phi_US_US = new TH2F("h2_restricted_L0_L0bar_p1phi_p2phi_US_US", "p1phi vs p2phi", 50, -3, 3, 50, -3, 3);

    TH2F *h2_restricted_L0_L0bar_p1pt_p2pt_US_LS = new TH2F("h2_restricted_L0_L0bar_p1pt_p2pt_US_LS", "p1pt vs p2pt", 50, 0, 5, 50, 0, 5);
    TH2F *h2_restricted_L0_L0bar_p1eta_p2eta_US_LS = new TH2F("h2_restricted_L0_L0bar_p1eta_p2eta_US_LS", "p1eta vs p2eta", 50, -1.5, 1.5, 50, -1.5, 1.5);
    TH2F *h2_restricted_L0_L0bar_p1phi_p2phi_US_LS = new TH2F("h2_restricted_L0_L0bar_p1phi_p2phi_US_LS", "p1phi vs p2phi", 50, -3, 3, 50, -3, 3);

    TH2F *h2_restricted_L0bar_L0bar_p1pt_p2pt_US_US = new TH2F("h2_restricted_L0bar_L0bar_p1pt_p2pt_US_US", "p1pt vs p2pt", 50, 0, 5, 50, 0, 5);
    TH2F *h2_restricted_L0bar_L0bar_p1eta_p2eta_US_US = new TH2F("h2_restricted_L0bar_L0bar_p1eta_p2eta_US_US", "p1eta vs p2eta", 50, -1.5, 1.5, 50, -1.5, 1.5);
    TH2F *h2_restricted_L0bar_L0bar_p1phi_p2phi_US_US = new TH2F("h2_restricted_L0bar_L0bar_p1phi_p2phi_US_US", "p1phi vs p2phi", 50, -3, 3, 50, -3, 3);

    TH2F *h2_restricted_L0bar_L0bar_p1pt_p2pt_US_LS = new TH2F("h2_restricted_L0bar_L0bar_p1pt_p2pt_US_LS", "p1pt vs p2pt", 50, 0, 5, 50, 0, 5);
    TH2F *h2_restricted_L0bar_L0bar_p1eta_p2eta_US_LS = new TH2F("h2_restricted_L0bar_L0bar_p1eta_p2eta_US_LS", "p1eta vs p2eta", 50, -1.5, 1.5, 50, -1.5, 1.5);
    TH2F *h2_restricted_L0bar_L0bar_p1phi_p2phi_US_LS = new TH2F("h2_restricted_L0bar_L0bar_p1phi_p2phi_US_LS", "p1phi vs p2phi", 50, -3, 3, 50, -3, 3);

    // Mixed Event Histograms
    TH2F *mixed_event_SE_lambda_us_S_lambda_us = new TH2F("mixed_event_SE_lambda_us_S_lambda_us", "test", 180, 1.0, 1.2, 180, 1.0, 1.2);
    TH2F *mixed_event_SE_lambda_us_S_lambda_ls = new TH2F("mixed_event_SE_lambda_us_S_lambda_ls", "test", 180, 1.0, 1.2, 180, 1.0, 1.2);
    TH2F *mixed_event_SE_lambda_us_S_lambda_bar_us = new TH2F("mixed_event_SE_lambda_us_S_lambda_bar_us", "test", 180, 1.0, 1.2, 180, 1.0, 1.2);
    TH2F *mixed_event_SE_lambda_us_S_lambda_bar_ls = new TH2F("mixed_event_SE_lambda_us_S_lambda_bar_ls", "test", 180, 1.0, 1.2, 180, 1.0, 1.2);
    TH2F *mixed_event_SE_lambda_bar_us_S_lambda_bar_us = new TH2F("mixed_event_SE_lambda_bar_us_S_lambda_bar_us", "test", 180, 1.0, 1.2, 180, 1.0, 1.2);
    TH2F *mixed_event_SE_lambda_bar_us_S_lambda_bar_ls = new TH2F("mixed_event_SE_lambda_bar_us_S_lambda_bar_ls", "test", 180, 1.0, 1.2, 180, 1.0, 1.2);

    TH2F *h2_no_cuts_ME_L0_L0_p1pt_p2pt_US_US = new TH2F("h2_no_cuts_ME_L0_L0_p1pt_p2pt_US_US", "p1_pt vs p2_pt", 50, 0, 5, 50, 0, 5);
    TH2F *h2_no_cuts_ME_L0_L0_p1eta_p2eta_US_US = new TH2F("h2_no_cuts_ME_L0_L0_p1eta_p2eta_US_US", "p1_eta vs p2_eta", 50, -1.5, 1.5, 50, -1.5, 1.5);
    TH2F *h2_no_cuts_ME_L0_L0_p1phi_p2phi_US_US = new TH2F("h2_no_cuts_ME_L0_L0_p1phi_p2phi_US_US", "p1_phi vs p2_phi", 50, -3, 3, 50, -3, 3);

    TH2F *h2_no_cuts_ME_L0_L0_p1pt_p2pt_US_LS = new TH2F("h2_no_cuts_ME_L0_L0_p1pt_p2pt_US_LS", "p1_pt vs p2_pt", 50, 0, 5, 50, 0, 5);
    TH2F *h2_no_cuts_ME_L0_L0_p1eta_p2eta_US_LS = new TH2F("h2_no_cuts_ME_L0_L0_p1eta_p2eta_US_LS", "p1_eta vs p2_eta", 50, -1.5, 1.5, 50, -1.5, 1.5);
    TH2F *h2_no_cuts_ME_L0_L0_p1phi_p2phi_US_LS = new TH2F("h2_no_cuts_ME_L0_L0_p1phi_p2phi_US_LS", "p1_phi vs p2_phi", 50, -3.5, 3.5, 50, -3.5, 3.5);

    TH2F *h2_no_cuts_ME_L0_L0bar_p1pt_p2pt_US_US = new TH2F("h2_no_cuts_ME_L0_L0bar_p1pt_p2pt_US_US", "p1_pt vs p2_pt", 50, 0, 5, 50, 0, 5);
    TH2F *h2_no_cuts_ME_L0_L0bar_p1eta_p2eta_US_US = new TH2F("h2_no_cuts_ME_L0_L0bar_p1eta_p2eta_US_US", "p1_eta vs p2_eta", 50, -1.5, 1.5, 50, -1.5, 1.5);
    TH2F *h2_no_cuts_ME_L0_L0bar_p1phi_p2phi_US_US = new TH2F("h2_no_cuts_ME_L0_L0bar_p1phi_p2phi_US_US", "p1_phi vs p2_phi", 50, -3.5, 3.5, 50, -3.5, 3.5);

    TH2F *h2_no_cuts_ME_L0_L0bar_p1pt_p2pt_US_LS = new TH2F("h2_no_cuts_ME_L0_L0bar_p1pt_p2pt_US_LS", "p1_pt vs p2_pt", 50, 0, 5, 50, 0, 5);
    TH2F *h2_no_cuts_ME_L0_L0bar_p1eta_p2eta_US_LS = new TH2F("h2_no_cuts_ME_L0_L0bar_p1eta_p2eta_US_LS", "p1_eta vs p2_eta", 50, -1.5, 1.5, 50, -1.5, 1.5);
    TH2F *h2_no_cuts_ME_L0_L0bar_p1phi_p2phi_US_LS = new TH2F("h2_no_cuts_ME_L0_L0bar_p1phi_p2phi_US_LS", "p1_phi vs p2_phi", 50, -3.5, 3.5, 50, -3.5, 3.5);

    TH2F *h2_no_cuts_ME_L0bar_L0bar_p1pt_p2pt_US_US = new TH2F("h2_no_cuts_ME_L0bar_L0bar_p1pt_p2pt_US_US", "p1_pt vs p2_pt", 50, 0, 5, 50, 0, 5);
    TH2F *h2_no_cuts_ME_L0bar_L0bar_p1eta_p2eta_US_US = new TH2F("h2_no_cuts_ME_L0bar_L0bar_p1eta_p2eta_US_US", "p1_eta vs p2_eta", 50, -1.5, 1.5, 50, -1.5, 1.5);
    TH2F *h2_no_cuts_ME_L0bar_L0bar_p1phi_p2phi_US_US = new TH2F("h2_no_cuts_ME_L0bar_L0bar_p1phi_p2phi_US_US", "p1_phi vs p2_phi", 50, -3.5, 3.5, 50, -3.5, 3.5);

    TH2F *h2_no_cuts_ME_L0bar_L0bar_p1pt_p2pt_US_LS = new TH2F("h2_no_cuts_ME_L0bar_L0bar_p1pt_p2pt_US_LS", "p1_pt vs p2_pt", 50, 0, 5, 50, 0, 5);
    TH2F *h2_no_cuts_ME_L0bar_L0bar_p1eta_p2eta_US_LS = new TH2F("h2_no_cuts_ME_L0bar_L0bar_p1eta_p2eta_US_LS", "p1_eta vs p2_eta", 50, -1.5, 1.5, 50, -1.5, 1.5);
    TH2F *h2_no_cuts_ME_L0bar_L0bar_p1phi_p2phi_US_LS = new TH2F("h2_no_cuts_ME_L0bar_L0bar_p1phi_p2phi_US_LS", "p1_phi vs p2_phi", 50, -3.5, 3.5, 50, -3.5, 3.5);

    // Mixed Event Invariant Mass Histograms- Check Pre-Cuts
    TH2F *h2_no_cut_invMass_ME_lambda_us_lambda_us = new TH2F("h2_no_cut_invMass_ME_lambda_us_lambda_us", "Unlike Sign Lambda - Unlike Sign Lambda (test)", 180, 1.0, 1.2, 180, 1.0, 1.2);
    TH2F *h2_no_cut_invMass_ME_lambda_us_lambda_ls = new TH2F("h2_no_cut_invMass_ME_lambda_us_lambda_ls", "Unlike Sign Lambda - Like Sign Lambda (test2)", 180, 1.0, 1.2, 180, 1.0, 1.2);
    TH2F *h2_no_cut_invMass_ME_lambda_us_lambda_bar_us = new TH2F("h2_no_cut_invMass_ME_lambda_us_lambda_bar_us", "Unlike Sign Lambda - Unlike Sign Lambda Bar (test)", 180, 1.0, 1.2, 180, 1.0, 1.2);
    TH2F *h2_no_cut_invMass_ME_lambda_us_lambda_bar_ls = new TH2F("h2_no_cut_invMass_ME_lambda_us_lambda_bar_ls", "Unlike Sign Lambda - Like Sign Lambda Bar (test2)", 180, 1.0, 1.2, 180, 1.0, 1.2);
    TH2F *h2_no_cut_invMass_ME_lambda_bar_us_lambda_bar_us = new TH2F("h2_no_cut_invMass_ME_lambda_bar_us_lambda_bar_us", "Unlike Sign Lambda Bar - Unlike Sign Lambda Bar (test)", 180, 1.0, 1.2, 180, 1.0, 1.2);
    TH2F *h2_no_cut_invMass_ME_lambda_bar_us_lambda_bar_ls = new TH2F("h2_no_cut_invMass_ME_lambda_bar_us_lambda_bar_ls", "Unlike Sign Lambda Bar - Like Sign Lambda Bar (test2)", 180, 1.0, 1.2, 180, 1.0, 1.2);

    TH2F *h2_no_cut_check_ME_L0_L0_p1pt_p2pt_US_US = new TH2F("h2_no_cut_check_ME_L0_L0_p1pt_p2pt_US_US", "p1_pt vs p2_pt", 50, 0, 5, 50, 0, 5);
    TH2F *h2_no_cut_check_ME_L0_L0_p1eta_p2eta_US_US = new TH2F("h2_no_cut_check_ME_L0_L0_p1eta_p2eta_US_US", "p1_eta vs p2_eta", 50, -1.5, 1.5, 50, -1.5, 1.5);
    TH2F *h2_no_cut_check_ME_L0_L0_p1phi_p2phi_US_US = new TH2F("h2_no_cut_check_ME_L0_L0_p1phi_p2phi_US_US", "p1_phi vs p2_phi", 50, -3, 3, 50, -3, 3);

    TH2F *h2_no_cut_check_ME_L0_L0_p1pt_p2pt_US_LS = new TH2F("h2_no_cut_check_ME_L0_L0_p1pt_p2pt_US_LS", "p1_pt vs p2_pt", 50, 0, 5, 50, 0, 5);
    TH2F *h2_no_cut_check_ME_L0_L0_p1eta_p2eta_US_LS = new TH2F("h2_no_cut_check_ME_L0_L0_p1eta_p2eta_US_LS", "p1_eta vs p2_eta", 50, -1.5, 1.5, 50, -1.5, 1.5);
    TH2F *h2_no_cut_check_ME_L0_L0_p1phi_p2phi_US_LS = new TH2F("h2_no_cut_check_ME_L0_L0_p1phi_p2phi_US_LS", "p1_phi vs p2_phi", 50, -3.5, 3.5, 50, -3.5, 3.5);

    TH2F *h2_no_cut_check_ME_L0_L0bar_p1pt_p2pt_US_US = new TH2F("h2_no_cut_check_ME_L0_L0bar_p1pt_p2pt_US_US", "p1_pt vs p2_pt", 50, 0, 5, 50, 0, 5);
    TH2F *h2_no_cut_check_ME_L0_L0bar_p1eta_p2eta_US_US = new TH2F("h2_no_cut_check_ME_L0_L0bar_p1eta_p2eta_US_US", "p1_eta vs p2_eta", 50, -1.5, 1.5, 50, -1.5, 1.5);
    TH2F *h2_no_cut_check_ME_L0_L0bar_p1phi_p2phi_US_US = new TH2F("h2_no_cut_check_ME_L0_L0bar_p1phi_p2phi_US_US", "p1_phi vs p2_phi", 50, -3, 3, 50, -3, 3);

    TH2F *h2_no_cut_check_ME_L0_L0bar_p1pt_p2pt_US_LS = new TH2F("h2_no_cut_check_ME_L0_L0bar_p1pt_p2pt_US_LS", "p1_pt vs p2_pt", 50, 0, 5, 50, 0, 5);
    TH2F *h2_no_cut_check_ME_L0_L0bar_p1eta_p2eta_US_LS = new TH2F("h2_no_cut_check_ME_L0_L0bar_p1eta_p2eta_US_LS", "p1_eta vs p2_eta", 50, -1.5, 1.5, 50, -1.5, 1.5);
    TH2F *h2_no_cut_check_ME_L0_L0bar_p1phi_p2phi_US_LS = new TH2F("h2_no_cut_check_ME_L0_L0bar_p1phi_p2phi_US_LS", "p1_phi vs p2_phi", 50, -3.5, 3.5, 50, -3.5, 3.5);

    TH2F *h2_no_cut_check_ME_L0bar_L0bar_p1pt_p2pt_US_US = new TH2F("h2_no_cut_check_ME_L0bar_L0bar_p1pt_p2pt_US_US", "p1_pt vs p2_pt", 50, 0, 5, 50, 0, 5);
    TH2F *h2_no_cut_check_ME_L0bar_L0bar_p1eta_p2eta_US_US = new TH2F("h2_no_cut_check_ME_L0bar_L0bar_p1eta_p2eta_US_US", "p1_eta vs p2_eta", 50, -1.5, 1.5, 50, -1.5, 1.5);
    TH2F *h2_no_cut_check_ME_L0bar_L0bar_p1phi_p2phi_US_US = new TH2F("h2_no_cut_check_ME_L0bar_L0bar_p1phi_p2phi_US_US", "p1_phi vs p2_phi", 50, -3, 3, 50, -3, 3);

    TH2F *h2_no_cut_check_ME_L0bar_L0bar_p1pt_p2pt_US_LS = new TH2F("h2_no_cut_check_ME_L0bar_L0bar_p1pt_p2pt_US_LS", "p1_pt vs p2_pt", 50, 0, 5, 50, 0, 5);
    TH2F *h2_no_cut_check_ME_L0bar_L0bar_p1eta_p2eta_US_LS = new TH2F("h2_no_cut_check_ME_L0bar_L0bar_p1eta_p2eta_US_LS", "p1_eta vs p2_eta", 50, -1.5, 1.5, 50, -1.5, 1.5);
    TH2F *h2_no_cut_check_ME_L0bar_L0bar_p1phi_p2phi_US_LS = new TH2F("h2_no_cut_check_ME_L0bar_L0bar_p1phi_p2phi_US_LS", "p1_phi vs p2_phi", 50, -3.5, 3.5, 50, -3.5, 3.5);

    // Mixed Event Invariant Mass Histograms after Cuts
    TH2F *h2_invMass_ME_lambda_us_lambda_us = new TH2F("h2_invMass_ME_lambda_us_lambda_us", "ME Unlike Sign Lambda - Unlike Sign Lambda (test)", 180, 1.0, 1.2, 180, 1.0, 1.2);
    TH2F *h2_invMass_ME_lambda_us_lambda_ls = new TH2F("h2_invMass_ME_lambda_us_lambda_ls", "ME Unlike Sign Lambda - Like Sign Lambda (test2)", 180, 1.0, 1.2, 180, 1.0, 1.2);
    TH2F *h2_invMass_ME_lambda_us_lambda_bar_us = new TH2F("h2_invMass_ME_lambda_us_lambda_bar_us", "ME Unlike Sign Lambda - Unlike Sign Lambda Bar (test)", 180, 1.0, 1.2, 180, 1.0, 1.2);
    TH2F *h2_invMass_ME_lambda_us_lambda_bar_ls = new TH2F("h2_invMass_ME_lambda_us_lambda_bar_ls", "ME Unlike Sign Lambda - Like Sign Lambda Bar (test2)", 180, 1.0, 1.2, 180, 1.0, 1.2);
    TH2F *h2_invMass_ME_lambda_bar_us_lambda_bar_us = new TH2F("h2_invMass_ME_lambda_bar_us_lambda_bar_us", "ME Unlike Sign Lambda Bar - Unlike Sign Lambda Bar (test)", 180, 1.0, 1.2, 180, 1.0, 1.2);
    TH2F *h2_invMass_ME_lambda_bar_us_lambda_bar_ls = new TH2F("h2_invMass_ME_lambda_bar_us_lambda_bar_ls", "ME Unlike Sign Lambda Bar - Like Sign Lambda Bar (test2)", 180, 1.0, 1.2, 180, 1.0, 1.2);

    TH2F *h2_invMass_outside_ME_lambda_us_lambda_us = new TH2F("h2_invMass_outside_ME_lambda_us_lambda_us", "ME Unlike Sign Lambda - Unlike Sign Lambda (test)", 180, 1.0, 1.2, 180, 1.0, 1.2);
    TH2F *h2_invMass_outside_ME_lambda_us_lambda_ls = new TH2F("h2_invMass_ME_outside_lambda_us_lambda_ls", "ME Unlike Sign Lambda - Like Sign Lambda (test2)", 180, 1.0, 1.2, 180, 1.0, 1.2);
    TH2F *h2_invMass_outside_ME_lambda_us_lambda_bar_us = new TH2F("h2_invMass_outside_ME_lambda_us_lambda_bar_us", "ME Unlike Sign Lambda - Unlike Sign Lambda Bar (test)", 180, 1.0, 1.2, 180, 1.0, 1.2);
    TH2F *h2_invMass_outside_ME_lambda_us_lambda_bar_ls = new TH2F("h2_invMass_outside_ME_lambda_us_lambda_bar_ls", "ME Unlike Sign Lambda - Like Sign Lambda Bar (test2)", 180, 1.0, 1.2, 180, 1.0, 1.2);
    TH2F *h2_invMass_outside_ME_lambda_bar_us_lambda_bar_us = new TH2F("h2_invMass_outside_ME_lambda_bar_us_lambda_bar_us", "ME Unlike Sign Lambda Bar - Unlike Sign Lambda Bar (test)", 180, 1.0, 1.2, 180, 1.0, 1.2);
    TH2F *h2_invMass_outside_ME_lambda_bar_us_lambda_bar_ls = new TH2F("h2_invMass_outside_ME_lambda_bar_us_lambda_bar_ls", "ME Unlike Sign Lambda Bar - Like Sign Lambda Bar (test2)", 180, 1.0, 1.2, 180, 1.0, 1.2);

    TH2F *h2_cut_ME_L0_L0_p1pt_p2pt_US_US = new TH2F("h2_cut_ME_L0_L0_p1pt_p2pt_US_US", "p1_pt vs p2_pt", 50, 0, 5, 50, 0, 5);
    TH2F *h2_cut_ME_L0_L0_p1eta_p2eta_US_US = new TH2F("h2_cut_ME_L0_L0_p1eta_p2eta_US_US", "p1_eta vs p2_eta", 50, -1.5, 1.5, 50, -1.5, 1.5);
    TH2F *h2_cut_ME_L0_L0_p1phi_p2phi_US_US = new TH2F("h2_cut_ME_L0_L0_p1phi_p2phi_US_US", "p1_phi vs p2_phi", 50, -3, 3, 50, -3, 3);

    TH2F *h2_cut_ME_L0_L0_p1pt_p2pt_US_LS = new TH2F("h2_cut_ME_L0_L0_p1pt_p2pt_US_LS", "p1_pt vs p2_pt", 50, 0, 5, 50, 0, 5);
    TH2F *h2_cut_ME_L0_L0_p1eta_p2eta_US_LS = new TH2F("h2_cut_ME_L0_L0_p1eta_p2eta_US_LS", "p1_eta vs p2_eta", 50, -1.5, 1.5, 50, -1.5, 1.5);
    TH2F *h2_cut_ME_L0_L0_p1phi_p2phi_US_LS = new TH2F("h2_cut_ME_L0_L0_p1phi_p2phi_US_LS", "p1_phi vs p2_phi", 50, -3.5, 3.5, 50, -3.5, 3.5);

    TH2F *h2_cut_ME_L0_L0bar_p1pt_p2pt_US_US = new TH2F("h2_cut_ME_L0_L0bar_p1pt_p2pt_US_US", "p1_pt vs p2_pt", 50, 0, 5, 50, 0, 5);
    TH2F *h2_cut_ME_L0_L0bar_p1eta_p2eta_US_US = new TH2F("h2_cut_ME_L0_L0bar_p1eta_p2eta_US_US", "p1_eta vs p2_eta", 50, -1.5, 1.5, 50, -1.5, 1.5);
    TH2F *h2_cut_ME_L0_L0bar_p1phi_p2phi_US_US = new TH2F("h2_cut_ME_L0_L0bar_p1phi_p2phi_US_US", "p1_phi vs p2_phi", 50, -3, 3, 50, -3, 3);

    TH2F *h2_cut_ME_L0_L0bar_p1pt_p2pt_US_LS = new TH2F("h2_cut_ME_L0_L0bar_p1pt_p2pt_US_LS", "p1_pt vs p2_pt", 50, 0, 5, 50, 0, 5);
    TH2F *h2_cut_ME_L0_L0bar_p1eta_p2eta_US_LS = new TH2F("h2_cut_ME_L0_L0bar_p1eta_p2eta_US_LS", "p1_eta vs p2_eta", 50, -1.5, 1.5, 50, -1.5, 1.5);
    TH2F *h2_cut_ME_L0_L0bar_p1phi_p2phi_US_LS = new TH2F("h2_cut_ME_L0_L0bar_p1phi_p2phi_US_LS", "p1_phi vs p2_phi", 50, -3.5, 3.5, 50, -3.5, 3.5);

    TH2F *h2_cut_ME_L0bar_L0bar_p1pt_p2pt_US_US = new TH2F("h2_cut_ME_L0bar_L0bar_p1pt_p2pt_US_US", "p1_pt vs p2_pt", 50, 0, 5, 50, 0, 5);
    TH2F *h2_cut_ME_L0bar_L0bar_p1eta_p2eta_US_US = new TH2F("h2_cut_ME_L0bar_L0bar_p1eta_p2eta_US_US", "p1_eta vs p2_eta", 50, -1.5, 1.5, 50, -1.5, 1.5);
    TH2F *h2_cut_ME_L0bar_L0bar_p1phi_p2phi_US_US = new TH2F("h2_cut_ME_L0bar_L0bar_p1phi_p2phi_US_US", "p1_phi vs p2_phi", 50, -3, 3, 50, -3, 3);

    TH2F *h2_cut_ME_L0bar_L0bar_p1pt_p2pt_US_LS = new TH2F("h2_cut_ME_L0bar_L0bar_p1pt_p2pt_US_LS", "p1_pt vs p2_pt", 50, 0, 5, 50, 0, 5);
    TH2F *h2_cut_ME_L0bar_L0bar_p1eta_p2eta_US_LS = new TH2F("h2_cut_ME_L0bar_L0bar_p1eta_p2eta_US_LS", "p1_eta vs p2_eta", 50, -1.5, 1.5, 50, -1.5, 1.5);
    TH2F *h2_cut_ME_L0bar_L0bar_p1phi_p2phi_US_LS = new TH2F("h2_cut_ME_L0bar_L0bar_p1phi_p2phi_US_LS", "p1_phi vs p2_phi", 50, -3.5, 3.5, 50, -3.5, 3.5);

    TH2F *h2_cut_outside_ME_L0_L0_p1pt_p2pt_US_US = new TH2F("h2_cut_outside_ME_L0_L0_p1pt_p2pt_US_US", "p1_pt vs p2_pt", 50, 0, 5, 50, 0, 5);
    TH2F *h2_cut_outside_ME_L0_L0_p1eta_p2eta_US_US = new TH2F("h2_cut_outside_ME_L0_L0_p1eta_p2eta_US_US", "p1_eta vs p2_eta", 50, -1.5, 1.5, 50, -1.5, 1.5);
    TH2F *h2_cut_outside_ME_L0_L0_p1phi_p2phi_US_US = new TH2F("h2_cut_outside_ME_L0_L0_p1phi_p2phi_US_US", "p1_phi vs p2_phi", 50, -3, 3, 50, -3, 3);

    TH2F *h2_cut_outside_ME_L0_L0_p1pt_p2pt_US_LS = new TH2F("h2_cut_outside_ME_L0_L0_p1pt_p2pt_US_LS", "p1_pt vs p2_pt", 50, 0, 5, 50, 0, 5);
    TH2F *h2_cut_outside_ME_L0_L0_p1eta_p2eta_US_LS = new TH2F("h2_cut_outside_ME_L0_L0_p1eta_p2eta_US_LS", "p1_eta vs p2_eta", 50, -1.5, 1.5, 50, -1.5, 1.5);
    TH2F *h2_cut_outside_ME_L0_L0_p1phi_p2phi_US_LS = new TH2F("h2_cut_outside_ME_L0_L0_p1phi_p2phi_US_LS", "p1_phi vs p2_phi", 50, -3.5, 3.5, 50, -3.5, 3.5);

    TH2F *h2_cut_outside_ME_L0_L0bar_p1pt_p2pt_US_US = new TH2F("h2_cut_outside_ME_L0_L0bar_p1pt_p2pt_US_US", "p1_pt vs p2_pt", 50, 0, 5, 50, 0, 5);
    TH2F *h2_cut_outside_ME_L0_L0bar_p1eta_p2eta_US_US = new TH2F("h2_cut_outside_ME_L0_L0bar_p1eta_p2eta_US_US", "p1_eta vs p2_eta", 50, -1.5, 1.5, 50, -1.5, 1.5);
    TH2F *h2_cut_outside_ME_L0_L0bar_p1phi_p2phi_US_US = new TH2F("h2_cut_outside_ME_L0_L0bar_p1phi_p2phi_US_US", "p1_phi vs p2_phi", 50, -3, 3, 50, -3, 3);

    TH2F *h2_cut_outside_ME_L0_L0bar_p1pt_p2pt_US_LS = new TH2F("h2_cut_outside_ME_L0_L0bar_p1pt_p2pt_US_LS", "p1_pt vs p2_pt", 50, 0, 5, 50, 0, 5);
    TH2F *h2_cut_outside_ME_L0_L0bar_p1eta_p2eta_US_LS = new TH2F("h2_cut_outside_ME_L0_L0bar_p1eta_p2eta_US_LS", "p1_eta vs p2_eta", 50, -1.5, 1.5, 50, -1.5, 1.5);
    TH2F *h2_cut_outside_ME_L0_L0bar_p1phi_p2phi_US_LS = new TH2F("h2_cut_outside_ME_L0_L0bar_p1phi_p2phi_US_LS", "p1_phi vs p2_phi", 50, -3.5, 3.5, 50, -3.5, 3.5);

    TH2F *h2_cut_outside_ME_L0bar_L0bar_p1pt_p2pt_US_US = new TH2F("h2_cut_outside_ME_L0bar_L0bar_p1pt_p2pt_US_US", "p1_pt vs p2_pt", 50, 0, 5, 50, 0, 5);
    TH2F *h2_cut_outside_ME_L0bar_L0bar_p1eta_p2eta_US_US = new TH2F("h2_cut_outside_ME_L0bar_L0bar_p1eta_p2eta_US_US", "p1_eta vs p2_eta", 50, -1.5, 1.5, 50, -1.5, 1.5);
    TH2F *h2_cut_outside_ME_L0bar_L0bar_p1phi_p2phi_US_US = new TH2F("h2_cut_outside_ME_L0bar_L0bar_p1phi_p2phi_US_US", "p1_phi vs p2_phi", 50, -3, 3, 50, -3, 3);

    TH2F *h2_cut_outside_ME_L0bar_L0bar_p1pt_p2pt_US_LS = new TH2F("h2_cut_outside_ME_L0bar_L0bar_p1pt_p2pt_US_LS", "p1_pt vs p2_pt", 50, 0, 5, 50, 0, 5);
    TH2F *h2_cut_outside_ME_L0bar_L0bar_p1eta_p2eta_US_LS = new TH2F("h2_cut_outside_ME_L0bar_L0bar_p1eta_p2eta_US_LS", "p1_eta vs p2_eta", 50, -1.5, 1.5, 50, -1.5, 1.5);
    TH2F *h2_cut_outside_ME_L0bar_L0bar_p1phi_p2phi_US_LS = new TH2F("h2_cut_outside_ME_L0bar_L0bar_p1phi_p2phi_US_LS", "p1_phi vs p2_phi", 50, -3.5, 3.5, 50, -3.5, 3.5);

    // Mixed Event Histograms for the Angluar Distribution (Cos(theta*))
    TH1D *h_ME_cos_theta_star = new TH1D("h_ME_cos_theta_star", "ME Angular Distribution for Unlike Sign Lambda - Unlike Sign Lambda (cos_theta_star*)", 10, -1, 1);
    TH1D *h_ME_cos_theta_star2 = new TH1D("h_ME_cos_theta_star2", "ME Angular Distribution for Unlike Sign Lambda - Like Sign Lambda (cos_theta_star*)", 10, -1, 1);
    TH1D *h_ME_cos_theta_star3 = new TH1D("h_ME_cos_theta_star3", "ME Angular Distribution for Unlike Sign Lambda - Unlike Sign Lambda Bar (cos_theta_star*)", 10, -1, 1);
    TH1D *h_ME_cos_theta_star4 = new TH1D("h_ME_cos_theta_star4", "ME Angular Distribution for Unlike Sign Lambda - Like Sign Lambda Bar (cos_theta_star*)", 10, -1, 1);
    TH1D *h_ME_cos_theta_star5 = new TH1D("h_ME_cos_theta_star5", "ME Angular Distribution for Unlike Sign Lambda Bar - Unlike Sign Lambda Bar (cos_theta_star*)", 10, -1, 1);
    TH1D *h_ME_cos_theta_star6 = new TH1D("h_ME_cos_theta_star6", "ME Angular Distribution for Unlike Sign Lambda Bar - Like Sign Lambda Bar (cos_theta_star*)", 10, -1, 1);

    TH1D *h_outside_ME_cos_theta_star = new TH1D("h_outside_ME_cos_theta_star", "ME Angular Distribution for Unlike Sign Lambda - Unlike Sign Lambda (cos_theta_star*)", 10, -1, 1);
    TH1D *h_outside_ME_cos_theta_star2 = new TH1D("h_outside_ME_cos_theta_star2", "ME Angular Distribution for Unlike Sign Lambda - Like Sign Lambda (cos_theta_star*)", 10, -1, 1);
    TH1D *h_outside_ME_cos_theta_star3 = new TH1D("h_outside_ME_cos_theta_star3", "ME Angular Distribution for Unlike Sign Lambda - Unlike Sign Lambda Bar (cos_theta_star*)", 10, -1, 1);
    TH1D *h_outside_ME_cos_theta_star4 = new TH1D("h_outside_ME_cos_theta_star4", "ME Angular Distribution for Unlike Sign Lambda - Like Sign Lambda Bar (cos_theta_star*)", 10, -1, 1);
    TH1D *h_outside_ME_cos_theta_star5 = new TH1D("h_outside_ME_cos_theta_star5", "ME Angular Distribution for Unlike Sign Lambda Bar - Unlike Sign Lambda Bar (cos_theta_star*)", 10, -1, 1);
    TH1D *h_outside_ME_cos_theta_star6 = new TH1D("h_outside_ME_cos_theta_star6", "ME Angular Distribution for Unlike Sign Lambda Bar - Like Sign Lambda Bar (cos_theta_star*)", 10, -1, 1);

    // Define histograms for Mixed Event Delta R distributions
    TH1D *h_delta_R_ME_US_US_ll = new TH1D("h_delta_R_ME_US_US_ll", "ME Delta R Distribution for US-US Lambda - Lambda Pairs", 50, 0, 5);
    TH1D *h_delta_R_ME_US_LS_ll = new TH1D("h_delta_R_ME_US_LS_ll", "ME Delta R Distribution for US-LS Lambda - Lambda Pairs", 50, 0, 5);
    TH1D *h_delta_R_ME_US_US_llbar = new TH1D("h_delta_R_ME_US_US_llbar", "ME Delta R Distribution for US-US Lambda - Lambda Bar Pairs", 50, 0, 5);
    TH1D *h_delta_R_ME_US_LS_llbar = new TH1D("h_delta_R_ME_US_LS_llbar", "ME Delta R Distribution for US-LS Lambda - Lambda Bar Pairs", 50, 0, 5);
    TH1D *h_delta_R_ME_US_US_lbarlbar = new TH1D("h_delta_R_ME_US_US_lbarlbar", "ME Delta R Distribution for US-US Lambda Bar - Lambda Bar Pairs", 50, 0, 5);
    TH1D *h_delta_R_ME_US_LS_lbarlbar = new TH1D("h_delta_R_ME_US_LS_lbarlbar", "ME Delta R Distribution for US-LS Lambda Bar - Lambda Bar Pairs", 50, 0, 5);

    // Histograms for Mixed Event Delta Phi Distributions
    TH1D *h_delta_phi_ME_US_US_ll = new TH1D("h_delta_phi_ME_US_US_ll", "ME Delta Phi for US-US Lambda - Lambda Pairs", 50, 0, TMath::Pi());
    TH1D *h_delta_phi_ME_US_LS_ll = new TH1D("h_delta_phi_ME_US_LS_ll", "ME Delta Phi for US-LS Lambda - Lambda Pairs", 50, 0, TMath::Pi());
    TH1D *h_delta_phi_ME_US_US_llbar = new TH1D("h_delta_phi_ME_US_US_llbar", "ME Delta Phi for US-US Lambda - Lambda Bar Pairs", 50, 0, TMath::Pi());
    TH1D *h_delta_phi_ME_US_LS_llbar = new TH1D("h_delta_phi_ME_US_LS_llbar", "ME Delta Phi for US-LS Lambda - Lambda Bar Pairs", 50, 0, TMath::Pi());
    TH1D *h_delta_phi_ME_US_US_lbarlbar = new TH1D("h_delta_phi_ME_US_US_lbarlbar", "ME Delta Phi for US-US Lambda Bar - Lambda Bar Pairs", 50, 0, TMath::Pi());
    TH1D *h_delta_phi_ME_US_LS_lbarlbar = new TH1D("h_delta_phi_ME_US_LS_lbarlbar", "ME Delta Phi for US-LS Lambda Bar - Lambda Bar Pairs", 50, 0, TMath::Pi());

    // Main for loop that Fills the Vector Pairs
    int iter_1 = 0;
    int iter_2 = 0;
    int iter_3 = 0;
    int iter_4 = 0;

    const int nEntries = ntp_Lambda->GetEntries();

    std::cout << "  " << std::endl;
    std::cout << "Total number of Entries going into the loop: " << nEntries << std::endl;
    std::cout << "  " << std::endl;

    // Initialize counter
    int total_events = 0;
    int passed_events = 0;
    int events_cut = 0;

    for (int i = 0; i < nEntries; ++i){
        ntp_Lambda->GetEntry(i);
        total_events++;

        if (p1_dca < 0.1) {
            continue;
        }
        if (p2_dca < 0.3) {
            continue;
        }
        if (pair_DCAdaughters > 1.0) {
            continue;
        }
        if (pair_decayL < 2) {
            continue;
        }
        if (cos(pair_theta) < 0.996) {
            continue;
        }

        // Skip pairing if p1_InEventID equals p2_InEventID
        if (p1_InEventID == p2_InEventID)
            continue;

        // Fill TLorentzVector with current event particles
        TLorentzVector p1, p2;
        p1.SetPtEtaPhiM(p1_pt, p1_eta, p1_phi, mass_p1);
        p2.SetPtEtaPhiM(p2_pt, p2_eta, p2_phi, mass_p2);

        TLorentzVector fourmomentum = p1 + p2;

        // Pairing the Lambdas and Lambda Bars
        if (eventId != prevEventID && prevEventID != -1){

            if (mcentrality >= 4 && mcentrality <= 6) {
                for (size_t j = 0; j < lambda_us.size(); ++j) {
                    for (size_t k = j + 1; k < lambda_us.size(); ++k) {
                        if (proton_id_lambda_us[j] == proton_id_lambda_us[k] || pion_id_lambda_us[j] == pion_id_lambda_us[k])
                            continue;

                        h2_lambda_us_lambda_us->Fill(lambda_us[j].M(), lambda_us[k].M(), mreweight);

                        h2_no_cuts_L0_L0_p1pt_p2pt_US_US->Fill(proton_us[j].Pt(), proton_us[k].Pt(), mreweight);
                        h2_no_cuts_L0_L0_p1eta_p2eta_US_US->Fill(proton_us[j].Eta(), proton_us[k].Eta(), mreweight);
                        h2_no_cuts_L0_L0_p1phi_p2phi_US_US->Fill(proton_us[j].Phi(), proton_us[k].Phi(), mreweight);

                        fourmoment_lambda_us_1.push_back(lambda_us[j]);
                        fourmoment_lambda_us_2.push_back(lambda_us[k]);
                        fourmoment_proton_us_1.push_back(proton_us[j]);
                        fourmoment_proton_us_2.push_back(proton_us[k]);

                        weight_vector_1.push_back(mreweight);
                    }

                    for (size_t k = 0; k < lambda_ls.size(); ++k) {
                        if (proton_id_lambda_us[j] == proton_id_lambda_ls[k] || pion_id_lambda_us[j] == pion_id_lambda_ls[k])
                            continue;

                        if (iter_1 % 2 == 0){
                            h2_lambda_us_lambda_ls->Fill(lambda_us[j].M(), lambda_ls[k].M(), mreweight);
                        } else {
                            h2_lambda_us_lambda_ls->Fill(lambda_ls[k].M(), lambda_us[j].M(), mreweight);
                        }

                        h2_no_cuts_L0_L0_p1pt_p2pt_US_LS->Fill(proton_us[j].Pt(), proton_ls[k].Pt(), mreweight);
                        h2_no_cuts_L0_L0_p1eta_p2eta_US_LS->Fill(proton_us[j].Eta(), proton_ls[k].Eta(), mreweight);
                        h2_no_cuts_L0_L0_p1phi_p2phi_US_LS->Fill(proton_us[j].Phi(), proton_ls[k].Phi(), mreweight);

                        fourmoment_lambda_us3.push_back(lambda_us[j]);
                        fourmoment_lambda_ls3.push_back(lambda_ls[k]);
                        fourmoment_proton_us3.push_back(proton_us[j]);
                        fourmoment_proton_ls3.push_back(proton_ls[k]);

                        weight_vector_2.push_back(mreweight);

                        iter_1++; // increase the value by 1
                    }
                }

                for (size_t j = 0; j < lambda_us.size(); ++j) {
                    for (size_t k = 0; k < lambda_bar_us.size(); ++k) {
                        if (proton_id_lambda_us[j] == anti_proton_id_lambda_bar_us[k] || pion_id_lambda_us[j] == anti_pion_id_lambda_bar_us[k])
                            continue;

                        h2_lambda_us_lambda_bar_us->Fill(lambda_us[j].M(), lambda_bar_us[k].M(), mreweight);

                        h2_no_cuts_L0_L0bar_p1pt_p2pt_US_US->Fill(proton_us[j].Pt(), anti_proton_us[k].Pt(), mreweight);
                        h2_no_cuts_L0_L0bar_p1eta_p2eta_US_US->Fill(proton_us[j].Eta(), anti_proton_us[k].Eta(), mreweight);
                        h2_no_cuts_L0_L0bar_p1phi_p2phi_US_US->Fill(proton_us[j].Phi(), anti_proton_us[k].Phi(), mreweight);

                        fourmoment_lambda_us4.push_back(lambda_us[j]);
                        fourmoment_lambda_bar_us4.push_back(lambda_bar_us[k]);
                        fourmoment_proton_us4.push_back(proton_us[j]);
                        fourmoment_anti_proton_us4.push_back(anti_proton_us[k]);

                        weight_vector_3.push_back(mreweight);
                    }

                    for (size_t k = 0; k < lambda_bar_ls.size(); ++k){
                        if (proton_id_lambda_us[j] == anti_proton_id_lambda_bar_ls[k] || pion_id_lambda_us[j] == anti_pion_id_lambda_bar_ls[k])
                            continue;

                        h2_lambda_us_lambda_bar_ls->Fill(lambda_us[j].M(), lambda_bar_ls[k].M(), mreweight);

                        h2_no_cuts_L0_L0bar_p1pt_p2pt_US_LS->Fill(proton_us[j].Pt(), anti_proton_ls[k].Pt(), mreweight);
                        h2_no_cuts_L0_L0bar_p1eta_p2eta_US_LS->Fill(proton_us[j].Eta(), anti_proton_ls[k].Eta(), mreweight);
                        h2_no_cuts_L0_L0bar_p1phi_p2phi_US_LS->Fill(proton_us[j].Phi(), anti_proton_ls[k].Phi(), mreweight);

                        fourmoment_lambda_us5.push_back(lambda_us[j]);
                        fourmoment_lambda_bar_ls5.push_back(lambda_bar_ls[k]);
                        fourmoment_proton_us5.push_back(proton_us[j]);
                        fourmoment_anti_proton_ls5.push_back(anti_proton_ls[k]);

                        weight_vector_4.push_back(mreweight);
                    }
                }

                for (size_t j = 0; j < lambda_ls.size(); ++j){
                    for (size_t k = 0; k < lambda_bar_us.size(); ++k){
                        if (proton_id_lambda_ls[j] == anti_proton_id_lambda_bar_us[k] || pion_id_lambda_ls[j] == anti_pion_id_lambda_bar_us[k])
                            continue;

                        h2_lambda_us_lambda_bar_ls->Fill(lambda_ls[j].M(), lambda_bar_us[k].M(), mreweight);

                        h2_no_cuts_L0_L0bar_p1pt_p2pt_US_LS->Fill(proton_ls[j].Pt(), anti_proton_us[k].Pt(), mreweight);
                        h2_no_cuts_L0_L0bar_p1eta_p2eta_US_LS->Fill(proton_ls[j].Eta(), anti_proton_us[k].Eta(), mreweight);
                        h2_no_cuts_L0_L0bar_p1phi_p2phi_US_LS->Fill(proton_ls[j].Phi(), anti_proton_us[k].Phi(), mreweight);

                        fourmoment_lambda_ls6.push_back(lambda_ls[j]);
                        fourmoment_lambda_bar_us6.push_back(lambda_bar_us[k]);
                        fourmoment_proton_ls6.push_back(proton_ls[j]);
                        fourmoment_anti_proton_us6.push_back(anti_proton_us[k]);

                        weight_vector_5.push_back(mreweight);
                    }
                }

                for (size_t j = 0; j < lambda_bar_us.size(); ++j){
                    for (size_t k = j + 1; k < lambda_bar_us.size(); ++k) {
                        if (anti_proton_id_lambda_bar_us[j] == anti_proton_id_lambda_bar_us[k] || anti_pion_id_lambda_bar_us[j] == anti_pion_id_lambda_bar_us[k])
                            continue;

                        h2_lambda_bar_us_lambda_bar_us->Fill(lambda_bar_us[j].M(), lambda_bar_us[k].M(), mreweight);

                        h2_no_cuts_L0bar_L0bar_p1pt_p2pt_US_US->Fill(anti_proton_us[j].Pt(), anti_proton_us[k].Pt(), mreweight);
                        h2_no_cuts_L0bar_L0bar_p1eta_p2eta_US_US->Fill(anti_proton_us[j].Eta(), anti_proton_us[k].Eta(), mreweight);
                        h2_no_cuts_L0bar_L0bar_p1phi_p2phi_US_US->Fill(anti_proton_us[j].Phi(), anti_proton_us[k].Phi(), mreweight);

                        fourmoment_lambda_bar_us_1.push_back(lambda_bar_us[j]);
                        fourmoment_lambda_bar_us_2.push_back(lambda_bar_us[k]);
                        fourmoment_anti_proton_us_1.push_back(anti_proton_us[j]);
                        fourmoment_anti_proton_us_2.push_back(anti_proton_us[k]);

                        weight_vector_6.push_back(mreweight);
                    }

                    for (size_t k = 0; k < lambda_bar_ls.size(); ++k) {
                        if (anti_proton_id_lambda_bar_us[j] == anti_proton_id_lambda_bar_ls[k] || anti_pion_id_lambda_bar_us[j] == anti_pion_id_lambda_bar_ls[k])
                            continue;

                        if (iter_2 % 2 == 0){
                            h2_lambda_bar_us_lambda_bar_ls->Fill(lambda_bar_us[j].M(), lambda_bar_ls[k].M(), mreweight);
                        } else{
                            h2_lambda_bar_us_lambda_bar_ls->Fill(lambda_bar_ls[k].M(), lambda_bar_us[k].M(), mreweight);
                        }

                        h2_no_cuts_L0bar_L0bar_p1pt_p2pt_US_LS->Fill(anti_proton_us[j].Pt(), anti_proton_ls[k].Pt(), mreweight);
                        h2_no_cuts_L0bar_L0bar_p1eta_p2eta_US_LS->Fill(anti_proton_us[j].Eta(), anti_proton_ls[k].Eta(), mreweight);
                        h2_no_cuts_L0bar_L0bar_p1phi_p2phi_US_LS->Fill(anti_proton_us[j].Phi(), anti_proton_ls[k].Phi(), mreweight);

                        fourmoment_lambda_bar_us7.push_back(lambda_bar_us[j]);
                        fourmoment_lambda_bar_ls7.push_back(lambda_bar_ls[k]);
                        fourmoment_anti_proton_us7.push_back(anti_proton_us[j]);
                        fourmoment_anti_proton_ls7.push_back(anti_proton_ls[k]);

                        weight_vector_7.push_back(mreweight);

                        iter_2++;
                    }
                }

                // Pull out the single US Lambdas and US Lambda Bars
                uint single_vector_size = 2e5;
                uint vector_size = 2e5;

                // uint single_vector_size = 1e5;
                // uint vector_size = 1e5;

                // uint single_vector_size = 3e4;
                // uint vector_size = 1e4;

                if (lambda_us.size() == 1 && lambda_bar_us.size() == 0 && single_lambda_us.size() < single_vector_size){
                    single_lambda_us.push_back(lambda_us[0]);
                    single_proton_us.push_back(proton_us[0]);
                } else if (lambda_us.size() == 0 && lambda_bar_us.size() == 1 && single_lambda_bar_us.size() < single_vector_size) {
                    single_lambda_bar_us.push_back(lambda_bar_us[0]);
                    single_anti_proton_us.push_back(anti_proton_us[0]);
                }

                if (lambda_ls.size() == 1 && lambda_bar_ls.size() == 0 && single_lambda_ls.size() < single_vector_size){
                    single_lambda_ls.push_back(lambda_ls[0]);
                    single_proton_ls.push_back(proton_ls[0]);
                } else if (lambda_ls.size() == 0 && lambda_bar_ls.size() == 1 && single_lambda_bar_ls.size() < single_vector_size) {
                    single_lambda_bar_ls.push_back(lambda_bar_ls[0]);
                    single_anti_proton_ls.push_back(anti_proton_ls[0]);
                }

                // Same Event Pairs
                // "!=" is the c++ equivalent of "≠"

                if (lambda_us.size() > 0 && lambda_bar_us.size() > 0 && same_event_lambda_us_4.size() < vector_size) {
                    if (proton_id_lambda_us[0] != anti_proton_id_lambda_bar_us[0] && pion_id_lambda_us[0] != anti_pion_id_lambda_bar_us[0]) {

                        h2_SE_lambda_us_lambda_bar_us->Fill(lambda_us[0].M(), lambda_bar_us[0].M(), mreweight);

                        h2_restricted_L0_L0bar_p1pt_p2pt_US_US->Fill(proton_us[0].Pt(), anti_proton_us[0].Pt(), mreweight);
                        h2_restricted_L0_L0bar_p1eta_p2eta_US_US->Fill(proton_us[0].Eta(), anti_proton_us[0].Eta(), mreweight);
                        h2_restricted_L0_L0bar_p1phi_p2phi_US_US->Fill(proton_us[0].Phi(), anti_proton_us[0].Phi(), mreweight);

                        same_event_lambda_us_4.push_back(lambda_us[0]);
                        same_event_lambda_bar_us_4.push_back(lambda_bar_us[0]);
                        same_event_proton_us_4.push_back(proton_us[0]);
                        same_event_anti_proton_us_4.push_back(anti_proton_us[0]);

                        same_event_weight_vector_3.push_back(mreweight);
                    }
                }

                if (lambda_us.size() > 0 && lambda_bar_ls.size() > 0 && same_event_lambda_us_5.size() < vector_size) {
                    if (proton_id_lambda_us[0] != anti_proton_id_lambda_bar_ls[0] && pion_id_lambda_us[0] != anti_pion_id_lambda_bar_ls[0]) {

                        h2_SE_lambda_us_lambda_bar_ls->Fill(lambda_us[0].M(), lambda_bar_ls[0].M(), mreweight);

                        h2_restricted_L0_L0bar_p1pt_p2pt_US_LS->Fill(proton_us[0].Pt(), anti_proton_ls[0].Pt(), mreweight);
                        h2_restricted_L0_L0bar_p1eta_p2eta_US_LS->Fill(proton_us[0].Eta(), anti_proton_ls[0].Eta(), mreweight);
                        h2_restricted_L0_L0bar_p1phi_p2phi_US_LS->Fill(proton_us[0].Phi(), anti_proton_ls[0].Phi(), mreweight);

                        same_event_lambda_us_5.push_back(lambda_us[0]);
                        same_event_lambda_bar_ls_5.push_back(lambda_bar_ls[0]);
                        same_event_proton_us_5.push_back(proton_us[0]);
                        same_event_anti_proton_ls_5.push_back(anti_proton_ls[0]);

                        same_event_weight_vector_4.push_back(mreweight);
                    }
                }

                if (lambda_ls.size() > 0 && lambda_bar_us.size() > 0 && same_event_lambda_ls_5.size() < vector_size) {
                    if (proton_id_lambda_ls[0] != anti_proton_id_lambda_bar_us[0] && pion_id_lambda_ls[0] != anti_pion_id_lambda_bar_us[0]) {

                        h2_SE_lambda_us_lambda_bar_ls->Fill(lambda_ls[0].M(), lambda_bar_us[0].M(), mreweight);

                        h2_restricted_L0_L0bar_p1pt_p2pt_US_LS->Fill(anti_proton_ls[0].Pt(), proton_us[0].Pt());
                        h2_restricted_L0_L0bar_p1eta_p2eta_US_LS->Fill(anti_proton_ls[0].Eta(), proton_us[0].Eta());
                        h2_restricted_L0_L0bar_p1phi_p2phi_US_LS->Fill(anti_proton_ls[0].Phi(), proton_us[0].Phi());

                        same_event_lambda_ls_5.push_back(lambda_ls[0]);
                        same_event_lambda_bar_us_5.push_back(lambda_bar_us[0]);
                        same_event_proton_ls_5.push_back(proton_ls[0]);
                        same_event_anti_proton_us_5.push_back(anti_proton_us[0]);

                        same_event_weight_vector_5.push_back(mreweight);
                    }
                }

                if (lambda_us.size() > 1 && same_event_lambda_us_1.size() < vector_size) {
                    if (proton_id_lambda_us[0] != proton_id_lambda_us[1] && pion_id_lambda_us[0] != pion_id_lambda_us[1]) {

                        h2_SE_lambda_us_lambda_us->Fill(lambda_us[0].M(), lambda_us[1].M(), mreweight);

                        h2_restricted_L0_L0_p1pt_p2pt_US_US->Fill(proton_us[0].Pt(), proton_us[1].Pt());
                        h2_restricted_L0_L0_p1eta_p2eta_US_US->Fill(proton_us[0].Eta(), proton_us[1].Eta());
                        h2_restricted_L0_L0_p1phi_p2phi_US_US->Fill(proton_us[0].Phi(), proton_us[1].Phi());

                        same_event_lambda_us_1.push_back(lambda_us[0]);
                        same_event_lambda_us_2.push_back(lambda_us[1]);
                        same_event_proton_us_1.push_back(proton_us[0]);
                        same_event_proton_us_2.push_back(proton_us[1]);

                        same_event_weight_vector_1.push_back(mreweight);
                    }
                }

                if (lambda_us.size() > 0 && lambda_ls.size() > 0 && same_event_lambda_us_3.size() < vector_size) {
                    if (proton_id_lambda_us[0] != proton_id_lambda_ls[0] && pion_id_lambda_us[0] != pion_id_lambda_ls[0]) {

                        if (iter_3 % 2 == 0) {
                            h2_SE_lambda_us_lambda_ls->Fill(lambda_us[0].M(), lambda_ls[0].M(), mreweight);
                        } else {
                            h2_SE_lambda_us_lambda_ls->Fill(lambda_ls[0].M(), lambda_us[0].M(), mreweight);
                        }

                        iter_3++;

                        h2_restricted_L0_L0_p1pt_p2pt_US_LS->Fill(proton_us[0].Pt(), proton_ls[0].Pt());
                        h2_restricted_L0_L0_p1eta_p2eta_US_LS->Fill(proton_us[0].Eta(), proton_ls[0].Eta());
                        h2_restricted_L0_L0_p1phi_p2phi_US_LS->Fill(proton_us[0].Phi(), proton_ls[0].Phi());

                        same_event_lambda_us_3.push_back(lambda_us[0]);
                        same_event_lambda_ls_3.push_back(lambda_ls[0]);
                        same_event_proton_us_3.push_back(proton_us[0]);
                        same_event_proton_ls_3.push_back(proton_ls[0]);

                        same_event_weight_vector_2.push_back(mreweight);
                    }
                }

                if (lambda_bar_us.size() > 1 && same_event_lambda_bar_us_1.size() < vector_size) {
                    if (anti_proton_id_lambda_bar_us[0] != anti_proton_id_lambda_bar_us[1] && anti_pion_id_lambda_bar_us[0] != anti_pion_id_lambda_bar_us[1]) {

                        h2_SE_lambda_bar_us_lambda_bar_us->Fill(lambda_bar_us[0].M(), lambda_bar_us[1].M(), mreweight);

                        h2_restricted_L0bar_L0bar_p1pt_p2pt_US_US->Fill(anti_proton_us[0].Pt(), anti_proton_us[1].Pt());
                        h2_restricted_L0bar_L0bar_p1eta_p2eta_US_US->Fill(anti_proton_us[0].Eta(), anti_proton_us[1].Eta());
                        h2_restricted_L0bar_L0bar_p1phi_p2phi_US_US->Fill(anti_proton_us[0].Phi(), anti_proton_us[1].Phi());

                        same_event_lambda_bar_us_1.push_back(lambda_bar_us[0]);
                        same_event_lambda_bar_us_2.push_back(lambda_bar_us[1]);
                        same_event_anti_proton_us_1.push_back(anti_proton_us[0]);
                        same_event_anti_proton_us_2.push_back(anti_proton_us[1]);

                        same_event_weight_vector_6.push_back(mreweight);
                    }
                }

                if (lambda_bar_us.size() > 0 && lambda_bar_ls.size() > 0 && same_event_lambda_bar_us_6.size() < vector_size) {
                    if (anti_proton_id_lambda_bar_us[0] != anti_proton_id_lambda_bar_ls[0] && anti_pion_id_lambda_bar_us[0] != anti_pion_id_lambda_bar_ls[0]) {

                        if (iter_4 % 2 == 0) {
                            h2_SE_lambda_bar_us_lambda_bar_ls->Fill(lambda_bar_us[0].M(), lambda_bar_ls[0].M(), mreweight);
                        } else {
                            h2_SE_lambda_bar_us_lambda_bar_ls->Fill(lambda_bar_ls[0].M(), lambda_bar_us[0].M(), mreweight);
                        }

                        iter_4++;

                        h2_restricted_L0bar_L0bar_p1pt_p2pt_US_LS->Fill(anti_proton_us[0].Pt(), anti_proton_ls[0].Pt());
                        h2_restricted_L0bar_L0bar_p1eta_p2eta_US_LS->Fill(anti_proton_us[0].Eta(), anti_proton_ls[0].Eta());
                        h2_restricted_L0bar_L0bar_p1phi_p2phi_US_LS->Fill(anti_proton_us[0].Phi(), anti_proton_ls[0].Phi());

                        same_event_lambda_bar_us_6.push_back(lambda_bar_us[0]);
                        same_event_lambda_bar_ls_6.push_back(lambda_bar_ls[0]);
                        same_event_anti_proton_us_6.push_back(anti_proton_us[0]);
                        same_event_anti_proton_ls_6.push_back(anti_proton_ls[0]);

                        same_event_weight_vector_7.push_back(mreweight);
                    }
                }

            } else {
                continue;
            }

            lambda_us.clear();
            proton_us.clear();
            proton_id_lambda_us.clear();
            pion_id_lambda_us.clear();

            lambda_ls.clear();
            proton_ls.clear();
            proton_id_lambda_ls.clear();
            pion_id_lambda_ls.clear();

            lambda_bar_us.clear();
            anti_proton_us.clear();
            anti_proton_id_lambda_bar_us.clear();
            anti_pion_id_lambda_bar_us.clear();

            lambda_bar_ls.clear();
            anti_proton_ls.clear();
            anti_proton_id_lambda_bar_ls.clear();
            anti_pion_id_lambda_bar_ls.clear();
        }

        // passed_events++;

        // Pair charge check
        if (pair_charge == 0) {
            // Un-like sign pairs
            if (p1_ch > 0 && fourmomentum.Pt() > 0.5 && fourmomentum.Pt() < 5. && fabs(fourmomentum.Rapidity() < 1 ) ) {
                // Lambda pair
                lambda_us.push_back(fourmomentum);
                proton_us.push_back(p1);
                proton_id_lambda_us.push_back(p1_InEventID);
                pion_id_lambda_us.push_back(p2_InEventID);

            } else if (p1_ch < 0 && fourmomentum.Pt() > 0.5 && fourmomentum.Pt() < 5. && fabs(fourmomentum.Rapidity() < 1 ) ) {
                // Lambda Bar pair
                lambda_bar_us.push_back(fourmomentum);
                anti_proton_us.push_back(p1);
                anti_proton_id_lambda_bar_us.push_back(p1_InEventID);
                anti_pion_id_lambda_bar_us.push_back(p2_InEventID);
            }
        } else {
            // Like-sign pairs
            if (p1_ch > 0 && fourmomentum.Pt() > 0.5 && fourmomentum.Pt() < 5. && fabs(fourmomentum.Rapidity() < 1 ) ) {
                // Lambda pair
                lambda_ls.push_back(fourmomentum);
                proton_ls.push_back(p1);
                proton_id_lambda_ls.push_back(p1_InEventID);
                pion_id_lambda_ls.push_back(p2_InEventID);

            } else if (p1_ch < 0 && fourmomentum.Pt() > 0.5 && fourmomentum.Pt() < 5. && fabs(fourmomentum.Rapidity() < 1 ) ) {
                // Lambda-bar pair
                lambda_bar_ls.push_back(fourmomentum);
                anti_proton_ls.push_back(p1);
                anti_proton_id_lambda_bar_ls.push_back(p1_InEventID);
                anti_pion_id_lambda_bar_ls.push_back(p2_InEventID);
            }
        }

        prevEventID = eventId;
    }

    cout << "Total events: " << total_events << endl;

    double Counts_SE_US_US_LL = h2_lambda_us_lambda_us->Integral();
    double Counts_SE_US_LS_LL = h2_lambda_us_lambda_ls->Integral();
    double Counts_SE_US_US_LLBar = h2_lambda_us_lambda_bar_us->Integral();
    double Counts_SE_US_LS_LLBar = h2_lambda_us_lambda_bar_ls->Integral();
    double Counts_SE_US_US_LBarLBar = h2_lambda_bar_us_lambda_bar_us->Integral();
    double Counts_SE_US_LS_LBarLBar = h2_lambda_bar_us_lambda_bar_ls->Integral();

    std::cout << "  " << std::endl;
    std::cout << "**Single Event Pairs (before cuts)**" << std::endl;
    std::cout << "US Lambda - US Lambda Pair: " << Counts_SE_US_US_LL << std::endl;
    std::cout << "US Lambda - LS Lambda Pair: " << Counts_SE_US_LS_LL << std::endl;
    std::cout << "US Lambda - US Lambda Bar Pair: " << Counts_SE_US_US_LLBar << std::endl;
    std::cout << "US Lambda - LS Lambda Bar Pair: " << Counts_SE_US_LS_LLBar << std::endl;
    std::cout << "US Lambda Bar - US Lambda Bar Pair: " << Counts_SE_US_US_LBarLBar << std::endl;
    std::cout << "US Lambda Bar - LS Lambda Bar Pair: " << Counts_SE_US_LS_LBarLBar << std::endl;

    gStyle->SetPalette(kPastel);
    gStyle->SetOptStat(10);

    std::unique_ptr<TCanvas> c1(new TCanvas("c1", "c1- Invariant Mass w/ Background, No Cuts", 1800, 900));
    c1->Divide(3, 1);

    double minX = 1.08;
    double maxX = 1.15;
    double minY = 1.08;
    double maxY = 1.15;

    c1->cd(1);
    int binMinX = h2_lambda_us_lambda_bar_us->GetXaxis()->FindBin(minX);
    int binMaxX = h2_lambda_us_lambda_bar_us->GetXaxis()->FindBin(maxX);
    int binMinY = h2_lambda_us_lambda_bar_us->GetYaxis()->FindBin(minY);
    int binMaxY = h2_lambda_us_lambda_bar_us->GetYaxis()->FindBin(maxY);

    h2_lambda_us_lambda_bar_us->GetXaxis()->SetRange(binMinX, binMaxX);
    h2_lambda_us_lambda_bar_us->GetYaxis()->SetRange(binMinY, binMaxY);
    h2_lambda_us_lambda_bar_us->Draw("SURF2");
    h2_lambda_us_lambda_bar_us->SetTitle("Inv. Mass for #Lambda#bar{#Lambda} Pair");
    h2_lambda_us_lambda_bar_ls->Draw("same");

    c1->cd(2);
    binMinX = h2_lambda_us_lambda_us->GetXaxis()->FindBin(minX);
    binMaxX = h2_lambda_us_lambda_us->GetXaxis()->FindBin(maxX);
    binMinY = h2_lambda_us_lambda_us->GetYaxis()->FindBin(minY);
    binMaxY = h2_lambda_us_lambda_us->GetYaxis()->FindBin(maxY);

    h2_lambda_us_lambda_us->GetXaxis()->SetRange(binMinX, binMaxX);
    h2_lambda_us_lambda_us->GetYaxis()->SetRange(binMinY, binMaxY);
    h2_lambda_us_lambda_us->Draw("SURF2");
    h2_lambda_us_lambda_us->SetTitle("Inv. Mass for #Lambda#Lambda Pair");
    h2_lambda_us_lambda_ls->Draw("same");

    c1->cd(3);
    binMinX = h2_lambda_bar_us_lambda_bar_us->GetXaxis()->FindBin(minX);
    binMaxX = h2_lambda_bar_us_lambda_bar_us->GetXaxis()->FindBin(maxX);
    binMinY = h2_lambda_bar_us_lambda_bar_us->GetYaxis()->FindBin(minY);
    binMaxY = h2_lambda_bar_us_lambda_bar_us->GetYaxis()->FindBin(maxY);

    h2_lambda_bar_us_lambda_bar_us->GetXaxis()->SetRange(binMinX, binMaxX);
    h2_lambda_bar_us_lambda_bar_us->GetYaxis()->SetRange(binMinY, binMaxY);
    h2_lambda_bar_us_lambda_bar_us->Draw("SURF2");
    h2_lambda_bar_us_lambda_bar_us->SetTitle("Inv. Mass for #bar{#Lambda}#bar{#Lambda} Pair");
    h2_lambda_bar_us_lambda_bar_ls->Draw("same");

    std::cout << "Canvas 1 Complete" << std::endl;

    double minX_3 = 1.13;
    double maxX_3 = 1.14;
    double minY_3 = 1.11;
    double maxY_3 = 1.12;

    int binMinX_3 = h2_lambda_us_lambda_bar_us->GetXaxis()->FindBin(minX_3);
    int binMaxX_3 = h2_lambda_us_lambda_bar_us->GetXaxis()->FindBin(maxX_3);
    int binMinY_3 = h2_lambda_us_lambda_bar_us->GetYaxis()->FindBin(minY_3);
    int binMaxY_3 = h2_lambda_us_lambda_bar_us->GetYaxis()->FindBin(maxY_3);

    double ridge_L0_L0bar_us_us = h2_lambda_us_lambda_bar_us->Integral(binMinX_3, binMaxX_3, binMinY_3, binMaxY_3);

    binMinX_3 = h2_lambda_us_lambda_bar_ls->GetXaxis()->FindBin(minX_3);
    binMaxX_3 = h2_lambda_us_lambda_bar_ls->GetXaxis()->FindBin(maxX_3);
    binMinY_3 = h2_lambda_us_lambda_bar_ls->GetYaxis()->FindBin(minY_3);
    binMaxY_3 = h2_lambda_us_lambda_bar_ls->GetYaxis()->FindBin(maxY_3);

    double ridge_L0_L0bar_us_ls = h2_lambda_us_lambda_bar_ls->Integral(binMinX_3, binMaxX_3, binMinY_3, binMaxY_3);

    binMinX_3 = h2_lambda_us_lambda_us->GetXaxis()->FindBin(minX_3);
    binMaxX_3 = h2_lambda_us_lambda_us->GetXaxis()->FindBin(maxX_3);
    binMinY_3 = h2_lambda_us_lambda_us->GetYaxis()->FindBin(minY_3);
    binMaxY_3 = h2_lambda_us_lambda_us->GetYaxis()->FindBin(maxY_3);

    double ridge_L0_L0_us_us = h2_lambda_us_lambda_us->Integral(binMinX_3, binMaxX_3, binMinY_3, binMaxY_3);

    binMinX_3 = h2_lambda_us_lambda_ls->GetXaxis()->FindBin(minX_3);
    binMaxX_3 = h2_lambda_us_lambda_ls->GetXaxis()->FindBin(maxX_3);
    binMinY_3 = h2_lambda_us_lambda_ls->GetYaxis()->FindBin(minY_3);
    binMaxY_3 = h2_lambda_us_lambda_ls->GetYaxis()->FindBin(maxY_3);

    double ridge_L0_L0_us_ls = h2_lambda_us_lambda_ls->Integral(binMinX_3, binMaxX_3, binMinY_3, binMaxY_3);

    binMinX_3 = h2_lambda_bar_us_lambda_bar_us->GetXaxis()->FindBin(minX_3);
    binMaxX_3 = h2_lambda_bar_us_lambda_bar_us->GetXaxis()->FindBin(maxX_3);
    binMinY_3 = h2_lambda_bar_us_lambda_bar_us->GetYaxis()->FindBin(minY_3);
    binMaxY_3 = h2_lambda_bar_us_lambda_bar_us->GetYaxis()->FindBin(maxY_3);

    double ridge_L0bar_L0bar_us_us = h2_lambda_bar_us_lambda_bar_us->Integral(binMinX_3, binMaxX_3, binMinY_3, binMaxY_3);

    binMinX_3 = h2_lambda_bar_us_lambda_bar_ls->GetXaxis()->FindBin(minX_3);
    binMaxX_3 = h2_lambda_bar_us_lambda_bar_ls->GetXaxis()->FindBin(maxX_3);
    binMinY_3 = h2_lambda_bar_us_lambda_bar_ls->GetYaxis()->FindBin(minY_3);
    binMaxY_3 = h2_lambda_bar_us_lambda_bar_ls->GetYaxis()->FindBin(maxY_3);

    double ridge_L0bar_L0bar_us_ls = h2_lambda_bar_us_lambda_bar_ls->Integral(binMinX_3, binMaxX_3, binMinY_3, binMaxY_3);

    cout << "   " << endl;
    cout << "counts in us_us L0_L0bar ridge: " << ridge_L0_L0bar_us_us << endl;
    cout << "counts in us_ls L0_L0bar ridge: " << ridge_L0_L0bar_us_ls << endl;
    cout << "counts in us_us L0_L0 ridge: " << ridge_L0_L0_us_us << endl;
    cout << "counts in us_ls L0_L0 ridge: " << ridge_L0_L0_us_ls << endl;
    cout << "counts in us_us L0bar_L0bar ridge: " << ridge_L0bar_L0bar_us_us << endl;
    cout << "counts in us_ls L0bar_L0bar ridge: " << ridge_L0bar_L0bar_us_ls << endl;
    cout << "   " << endl;

    // Background subtractions (US-LS is being subtracted from US-US) for Invariant Mass Distributions
    TH2F *h2_LLBar_Signal = new TH2F(*h2_lambda_us_lambda_bar_us);
    h2_LLBar_Signal->Add(h2_lambda_us_lambda_bar_ls, -1.0);

    TH2F *h2_LL_Signal = new TH2F(*h2_lambda_us_lambda_us);
    h2_LL_Signal->Add(h2_lambda_us_lambda_ls, -1.0);

    TH2F *h2_LBarLBar_Signal = new TH2F(*h2_lambda_bar_us_lambda_bar_us);
    h2_LBarLBar_Signal->Add(h2_lambda_bar_us_lambda_bar_ls, -1.0);

    std::unique_ptr<TCanvas> c2(new TCanvas("c2", "c2- Invariant Mass w/o Background, No Cuts", 1800, 900));
    c2->Divide(3, 2);

    double minX_2 = 1.11;
    double maxX_2 = 1.12;
    double minY_2 = 1.11;
    double maxY_2 = 1.12;

    c2->cd(1);
    int binMinX_2 = h2_LLBar_Signal->GetXaxis()->FindBin(minX_2);
    int binMaxX_2 = h2_LLBar_Signal->GetXaxis()->FindBin(maxX_2);
    int binMinY_2 = h2_LLBar_Signal->GetYaxis()->FindBin(minY_2);
    int binMaxY_2 = h2_LLBar_Signal->GetYaxis()->FindBin(maxY_2);

    h2_LLBar_Signal->GetXaxis()->SetRange(binMinX_2, binMaxX_2);
    h2_LLBar_Signal->GetYaxis()->SetRange(binMinY_2, binMaxY_2);
    h2_LLBar_Signal->Draw("SURF2");
    h2_LLBar_Signal->SetTitle("Inv. Mass for #Lambda#bar{#Lambda} Pair (Peak Region)");

    TF2 *gaus2D_LLBar = new TF2("gaus2D_LLBar", "[0]*TMath::Gaus(x,[1],[2])*TMath::Gaus(y,[3],[4])", minX_2, maxX_2, minY_2, maxY_2);
    gaus2D_LLBar->SetParameters(360.198, 1.11573, 0.00137157, 1.11574, 0.00139988);
    h2_LLBar_Signal->Fit("gaus2D_LLBar", "0", "");

    std::cout << "  " << std::endl;
    int fitStatus1 = h2_LLBar_Signal->Fit("gaus2D_LLBar", "0");
    if (fitStatus1 == 0) {
        std::cout << "Fit converged successfully." << std::endl;

        // Print out the mean and sigma values from the fit
        double meanX = gaus2D_LLBar->GetParameter(1);
        double sigmaX = gaus2D_LLBar->GetParameter(2);
        double meanY = gaus2D_LLBar->GetParameter(3);
        double sigmaY = gaus2D_LLBar->GetParameter(4);

        std::cout << "Mean X: " << meanX << std::endl;
        std::cout << "Sigma X: " << sigmaX << std::endl;
        std::cout << "Mean Y: " << meanY << std::endl;
        std::cout << "Sigma Y: " << sigmaY << std::endl;

    } else {
        std::cout << "Fit did not converge. Status code: " << fitStatus1 << std::endl;
    }
    std::cout << "  " << std::endl;

    c2->cd(4);
    gaus2D_LLBar->Draw("SURF2");
    gaus2D_LLBar->SetTitle("Gaussian fit for #Lambda#bar{#Lambda} Pairs");

    c2->cd(2);
    binMinX_2 = h2_LL_Signal->GetXaxis()->FindBin(minX_2);
    binMaxX_2 = h2_LL_Signal->GetXaxis()->FindBin(maxX_2);
    binMinY_2 = h2_LL_Signal->GetYaxis()->FindBin(minY_2);
    binMaxY_2 = h2_LL_Signal->GetYaxis()->FindBin(maxY_2);

    h2_LL_Signal->GetXaxis()->SetRange(binMinX_2, binMaxX_2);
    h2_LL_Signal->GetYaxis()->SetRange(binMinY_2, binMaxY_2);
    h2_LL_Signal->Draw("SURF2");
    h2_LL_Signal->SetTitle("Inv. Mass for #Lambda#Lambda Pair (Peak Region)");

    TF2 *gaus2D_LL = new TF2("gaus2D_LL", "[0]*TMath::Gaus(x,[1],[2])*TMath::Gaus(y,[3],[4])", minX_2, maxX_2, minY_2, maxY_2);
    gaus2D_LL->SetParameters(190.681, 1.11571, 0.001478, 1.11571, 0.001369);
    h2_LL_Signal->Fit("gaus2D_LL", "0", "");

    std::cout << "  " << std::endl;
    int fitStatus = h2_LL_Signal->Fit("gaus2D_LL", "0");
    if (fitStatus == 0) {
        std::cout << "Fit converged successfully." << std::endl;

        // Print out the mean and sigma values from the fit
        double meanX = gaus2D_LL->GetParameter(1);
        double sigmaX = std::fabs(gaus2D_LL->GetParameter(2));
        double meanY = gaus2D_LL->GetParameter(3);
        double sigmaY = std::fabs(gaus2D_LL->GetParameter(4));

        std::cout << "Mean X: " << meanX << std::endl;
        std::cout << "Sigma X: " << sigmaX << std::endl;
        std::cout << "Mean Y: " << meanY << std::endl;
        std::cout << "Sigma Y: " << sigmaY << std::endl;

    } else {
        std::cout << "Fit did not converge. Status code: " << fitStatus << std::endl;
    }
    std::cout << "  " << std::endl;

    c2->cd(5);
    gaus2D_LL->Draw("SURF2");
    gaus2D_LL->SetTitle("Gaussian fit for #Lambda#Lambda Pairs");

    c2->cd(3);
    binMinX_2 = h2_LBarLBar_Signal->GetXaxis()->FindBin(minX_2);
    binMaxX_2 = h2_LBarLBar_Signal->GetXaxis()->FindBin(maxX_2);
    binMinY_2 = h2_LBarLBar_Signal->GetYaxis()->FindBin(minY_2);
    binMaxY_2 = h2_LBarLBar_Signal->GetYaxis()->FindBin(maxY_2);

    h2_LBarLBar_Signal->GetXaxis()->SetRange(binMinX_2, binMaxX_2);
    h2_LBarLBar_Signal->GetYaxis()->SetRange(binMinY_2, binMaxY_2);
    h2_LBarLBar_Signal->Draw("SURF2");
    h2_LBarLBar_Signal->SetTitle("Inv. Mass for #bar{#Lambda}#bar{#Lambda} Pair (Peak Region)");

    TF2 *gaus2D_LBarLBar = new TF2("gaus2D_LBarLBar", "[0]*TMath::Gaus(x,[1],[2])*TMath::Gaus(y,[3],[4])", minX_2, maxX_2, minY_2, maxY_2);
    gaus2D_LBarLBar->SetParameters(146.732, 1.11578, 0.00143841, 1.11565, 0.00123124);
    h2_LBarLBar_Signal->Fit("gaus2D_LBarLBar", "0", "");

    std::cout << "  " << std::endl;
    int fitStatus2 = h2_LBarLBar_Signal->Fit("gaus2D_LBarLBar", "0");
    if (fitStatus2 == 0) {
        std::cout << "Fit converged successfully." << std::endl;

        // Print out the mean and sigma values from the fit
        double meanX = gaus2D_LBarLBar->GetParameter(1);
        double sigmaX = gaus2D_LBarLBar->GetParameter(2);
        double meanY = gaus2D_LBarLBar->GetParameter(3);
        double sigmaY = gaus2D_LBarLBar->GetParameter(4);

        std::cout << "Mean X: " << meanX << std::endl;
        std::cout << "Sigma X: " << sigmaX << std::endl;
        std::cout << "Mean Y: " << meanY << std::endl;
        std::cout << "Sigma Y: " << sigmaY << std::endl;

    } else {
        std::cout << "Fit did not converge. Status code: " << fitStatus2 << std::endl;
    }
    std::cout << "  " << std::endl;

    c2->cd(6);
    gaus2D_LBarLBar->Draw("SURF2");
    gaus2D_LBarLBar->SetTitle("Gaussian fit for #bar{#Lambda}#bar{#Lambda} Pairs");

    double counts_no_cuts_L0_L0_signal = h2_LL_Signal->Integral();
    double counts_no_cuts_L0_L0bar_signal = h2_LLBar_Signal->Integral();
    double counts_no_cuts_L0bar_L0bar_signal = h2_LBarLBar_Signal->Integral();

    cout << "   " << endl;
    cout << "Counts in h2_LL_Signal: " << counts_no_cuts_L0_L0_signal << endl;
    cout << "Counts in h2_LLBar_Signal: " << counts_no_cuts_L0_L0bar_signal << endl;
    cout << "Counts in h2_LBarLBar_Signal: " << counts_no_cuts_L0bar_L0bar_signal << endl;

    cout << "   " << endl;
    std::cout << "Canvas 2 Complete" << std::endl;

    // Canvas 4: QA Plots for L0_L0bar Inv. Mass Distributions, No Cuts Applied
    std::unique_ptr<TCanvas> c3(new TCanvas("c3", "c3- QA Distributions L0_L0bar Inv. Mass Plots", 1800, 900));
    c3->Divide(3, 2);

    c3->cd(1);
    h2_no_cuts_L0_L0bar_p1pt_p2pt_US_US->Draw("COLZ"); 
    h2_no_cuts_L0_L0bar_p1pt_p2pt_US_US->SetTitle("Pt- US-US #Lambda#bar{#Lambda} Pairs (no cuts)"); 
    h2_no_cuts_L0_L0bar_p1pt_p2pt_US_US->GetXaxis()->SetTitle("p1_pt [GeV/c]");
    h2_no_cuts_L0_L0bar_p1pt_p2pt_US_US->GetXaxis()->CenterTitle(true);
    h2_no_cuts_L0_L0bar_p1pt_p2pt_US_US->GetYaxis()->SetTitle("p2_pt [GeV/c]");
    h2_no_cuts_L0_L0bar_p1pt_p2pt_US_US->GetYaxis()->CenterTitle(true);

    c3->cd(2);
    h2_no_cuts_L0_L0bar_p1eta_p2eta_US_US->Draw("COLZ");
    h2_no_cuts_L0_L0bar_p1eta_p2eta_US_US->SetTitle("Eta- US-US #Lambda#bar{#Lambda} Pairs (no cuts)");
    h2_no_cuts_L0_L0bar_p1eta_p2eta_US_US->GetXaxis()->SetTitle("p1_eta");
    h2_no_cuts_L0_L0bar_p1eta_p2eta_US_US->GetXaxis()->CenterTitle(true);
    h2_no_cuts_L0_L0bar_p1eta_p2eta_US_US->GetYaxis()->SetTitle("p2_eta");
    h2_no_cuts_L0_L0bar_p1eta_p2eta_US_US->GetYaxis()->CenterTitle(true);

    c3->cd(3);
    h2_no_cuts_L0_L0bar_p1phi_p2phi_US_US->Draw("COLZ");
    h2_no_cuts_L0_L0bar_p1phi_p2phi_US_US->SetTitle("Phi- US-US #Lambda#bar{#Lambda} Pairs (no cuts)");
    h2_no_cuts_L0_L0bar_p1phi_p2phi_US_US->GetXaxis()->SetTitle("p1_phi");
    h2_no_cuts_L0_L0bar_p1phi_p2phi_US_US->GetXaxis()->CenterTitle(true);
    h2_no_cuts_L0_L0bar_p1phi_p2phi_US_US->GetYaxis()->SetTitle("p2_phi");
    h2_no_cuts_L0_L0bar_p1phi_p2phi_US_US->GetYaxis()->CenterTitle(true);

    c3->cd(4);
    h2_no_cuts_L0_L0bar_p1pt_p2pt_US_LS->Draw("COLZ"); 
    h2_no_cuts_L0_L0bar_p1pt_p2pt_US_LS->SetTitle("Pt- US-LS #Lambda#bar{#Lambda} Pairs (no cuts)"); 
    h2_no_cuts_L0_L0bar_p1pt_p2pt_US_LS->GetXaxis()->SetTitle("p1_pt [GeV/c]");
    h2_no_cuts_L0_L0bar_p1pt_p2pt_US_LS->GetXaxis()->CenterTitle(true);
    h2_no_cuts_L0_L0bar_p1pt_p2pt_US_LS->GetYaxis()->SetTitle("p2_pt [GeV/c]");
    h2_no_cuts_L0_L0bar_p1pt_p2pt_US_LS->GetYaxis()->CenterTitle(true);

    c3->cd(5);
    h2_no_cuts_L0_L0bar_p1eta_p2eta_US_LS->Draw("COLZ");
    h2_no_cuts_L0_L0bar_p1eta_p2eta_US_LS->SetTitle("Eta- US-LS #Lambda#bar{#Lambda} Pairs (no cuts)");
    h2_no_cuts_L0_L0bar_p1eta_p2eta_US_LS->GetXaxis()->SetTitle("p1_eta");
    h2_no_cuts_L0_L0bar_p1eta_p2eta_US_LS->GetXaxis()->CenterTitle(true);
    h2_no_cuts_L0_L0bar_p1eta_p2eta_US_LS->GetYaxis()->SetTitle("p2_eta");
    h2_no_cuts_L0_L0bar_p1eta_p2eta_US_LS->GetYaxis()->CenterTitle(true);

    c3->cd(6);
    h2_no_cuts_L0_L0bar_p1phi_p2phi_US_LS->Draw("COLZ");
    h2_no_cuts_L0_L0bar_p1phi_p2phi_US_LS->SetTitle("Phi- US-LS #Lambda#bar{#Lambda} Pairs (no cuts)");
    h2_no_cuts_L0_L0bar_p1phi_p2phi_US_LS->GetXaxis()->SetTitle("p1_phi");
    h2_no_cuts_L0_L0bar_p1phi_p2phi_US_LS->GetXaxis()->CenterTitle(true);
    h2_no_cuts_L0_L0bar_p1phi_p2phi_US_LS->GetYaxis()->SetTitle("p2_phi");
    h2_no_cuts_L0_L0bar_p1phi_p2phi_US_LS->GetYaxis()->CenterTitle(true);

    std::cout << "Canvas 3 Complete" << std::endl;

    // Canvas 3: QA Plots for L0_L0 Pairs, No Cuts Applied
    std::unique_ptr<TCanvas> c4(new TCanvas("c4", "c4- QA Distributions L0_L0 Inv. Mass Plots", 1800, 900));
    c4->Divide(3, 2);

    c4->cd(1);
    h2_no_cuts_L0_L0_p1pt_p2pt_US_US->Draw("COLZ"); 
    h2_no_cuts_L0_L0_p1pt_p2pt_US_US->SetTitle("Pt- US-US #Lambda#Lambda Pairs (no cuts)"); 
    h2_no_cuts_L0_L0_p1pt_p2pt_US_US->GetXaxis()->SetTitle("p1_pt [GeV/c]");
    h2_no_cuts_L0_L0_p1pt_p2pt_US_US->GetXaxis()->CenterTitle(true);
    h2_no_cuts_L0_L0_p1pt_p2pt_US_US->GetYaxis()->SetTitle("p2_pt [GeV/c]");
    h2_no_cuts_L0_L0_p1pt_p2pt_US_US->GetYaxis()->CenterTitle(true);

    c4->cd(2);
    h2_no_cuts_L0_L0_p1eta_p2eta_US_US->Draw("COLZ");
    h2_no_cuts_L0_L0_p1eta_p2eta_US_US->SetTitle("Eta- US-US #Lambda#Lambda Pairs (no cuts)");
    h2_no_cuts_L0_L0_p1eta_p2eta_US_US->GetXaxis()->SetTitle("p1_eta");
    h2_no_cuts_L0_L0_p1eta_p2eta_US_US->GetXaxis()->CenterTitle(true);
    h2_no_cuts_L0_L0_p1eta_p2eta_US_US->GetYaxis()->SetTitle("p2_eta");
    h2_no_cuts_L0_L0_p1eta_p2eta_US_US->GetYaxis()->CenterTitle(true);

    c4->cd(3);
    h2_no_cuts_L0_L0_p1phi_p2phi_US_US->Draw("COLZ");
    h2_no_cuts_L0_L0_p1phi_p2phi_US_US->SetTitle("Phi- US-US #Lambda#Lambda Pairs (no cuts)");
    h2_no_cuts_L0_L0_p1phi_p2phi_US_US->GetXaxis()->SetTitle("p1_phi");
    h2_no_cuts_L0_L0_p1phi_p2phi_US_US->GetXaxis()->CenterTitle(true);
    h2_no_cuts_L0_L0_p1phi_p2phi_US_US->GetYaxis()->SetTitle("p2_phi");
    h2_no_cuts_L0_L0_p1phi_p2phi_US_US->GetYaxis()->CenterTitle(true);

    c4->cd(4);
    h2_no_cuts_L0_L0_p1pt_p2pt_US_LS->Draw("COLZ"); 
    h2_no_cuts_L0_L0_p1pt_p2pt_US_LS->SetTitle("Pt- US-LS #Lambda#Lambda Pairs (no cuts)"); 
    h2_no_cuts_L0_L0_p1pt_p2pt_US_LS->GetXaxis()->SetTitle("p1_pt [GeV/c]");
    h2_no_cuts_L0_L0_p1pt_p2pt_US_LS->GetXaxis()->CenterTitle(true);
    h2_no_cuts_L0_L0_p1pt_p2pt_US_LS->GetYaxis()->SetTitle("p2_pt [GeV/c]");
    h2_no_cuts_L0_L0_p1pt_p2pt_US_LS->GetYaxis()->CenterTitle(true);

    c4->cd(5);
    h2_no_cuts_L0_L0_p1eta_p2eta_US_LS->Draw("COLZ");
    h2_no_cuts_L0_L0_p1eta_p2eta_US_LS->SetTitle("Eta- US-LS #Lambda#Lambda Pairs (no cuts)");
    h2_no_cuts_L0_L0_p1eta_p2eta_US_LS->GetXaxis()->SetTitle("p1_eta");
    h2_no_cuts_L0_L0_p1eta_p2eta_US_LS->GetXaxis()->CenterTitle(true);
    h2_no_cuts_L0_L0_p1eta_p2eta_US_LS->GetYaxis()->SetTitle("p2_eta");
    h2_no_cuts_L0_L0_p1eta_p2eta_US_LS->GetYaxis()->CenterTitle(true);

    c4->cd(6);
    h2_no_cuts_L0_L0_p1phi_p2phi_US_LS->Draw("COLZ");
    h2_no_cuts_L0_L0_p1phi_p2phi_US_LS->SetTitle("Phi- US-LS #Lambda#Lambda Pairs (no cuts)");
    h2_no_cuts_L0_L0_p1phi_p2phi_US_LS->GetXaxis()->SetTitle("p1_phi");
    h2_no_cuts_L0_L0_p1phi_p2phi_US_LS->GetXaxis()->CenterTitle(true);
    h2_no_cuts_L0_L0_p1phi_p2phi_US_LS->GetYaxis()->SetTitle("p2_phi");
    h2_no_cuts_L0_L0_p1phi_p2phi_US_LS->GetYaxis()->CenterTitle(true);

    std::cout << "Canvas 4 Complete" << std::endl;

    // Canvas 4: QA Plots for L0_L0bar Inv. Mass Distributions, No Cuts Applied
    std::unique_ptr<TCanvas> c5(new TCanvas("c5", "c5- QA Distributions L0bar_L0bar Inv. Mass Plots", 1800, 900));
    c5->Divide(3, 2);

    c5->cd(1);
    h2_no_cuts_L0bar_L0bar_p1pt_p2pt_US_US->Draw("COLZ"); 
    h2_no_cuts_L0bar_L0bar_p1pt_p2pt_US_US->SetTitle("Pt- US-US #bar{#Lambda}#bar{#Lambda} Pairs (no cuts)"); 
    h2_no_cuts_L0bar_L0bar_p1pt_p2pt_US_US->GetXaxis()->SetTitle("p1_pt [GeV/c]");
    h2_no_cuts_L0bar_L0bar_p1pt_p2pt_US_US->GetXaxis()->CenterTitle(true);
    h2_no_cuts_L0bar_L0bar_p1pt_p2pt_US_US->GetYaxis()->SetTitle("p2_pt [GeV/c]");
    h2_no_cuts_L0bar_L0bar_p1pt_p2pt_US_US->GetYaxis()->CenterTitle(true);

    c5->cd(2);
    h2_no_cuts_L0bar_L0bar_p1eta_p2eta_US_US->Draw("COLZ");
    h2_no_cuts_L0bar_L0bar_p1eta_p2eta_US_US->SetTitle("Eta- US-US #bar{#Lambda}#bar{#Lambda} Pairs (no cuts)");
    h2_no_cuts_L0bar_L0bar_p1eta_p2eta_US_US->GetXaxis()->SetTitle("p1_eta");
    h2_no_cuts_L0bar_L0bar_p1eta_p2eta_US_US->GetXaxis()->CenterTitle(true);
    h2_no_cuts_L0bar_L0bar_p1eta_p2eta_US_US->GetYaxis()->SetTitle("p2_eta");
    h2_no_cuts_L0bar_L0bar_p1eta_p2eta_US_US->GetYaxis()->CenterTitle(true);

    c5->cd(3);
    h2_no_cuts_L0bar_L0bar_p1phi_p2phi_US_US->Draw("COLZ");
    h2_no_cuts_L0bar_L0bar_p1phi_p2phi_US_US->SetTitle("Phi- US-US #bar{#Lambda}#bar{#Lambda} Pairs (no cuts)");
    h2_no_cuts_L0bar_L0bar_p1phi_p2phi_US_US->GetXaxis()->SetTitle("p1_phi");
    h2_no_cuts_L0bar_L0bar_p1phi_p2phi_US_US->GetXaxis()->CenterTitle(true);
    h2_no_cuts_L0bar_L0bar_p1phi_p2phi_US_US->GetYaxis()->SetTitle("p2_phi");
    h2_no_cuts_L0bar_L0bar_p1phi_p2phi_US_US->GetYaxis()->CenterTitle(true);

    c5->cd(4);
    h2_no_cuts_L0bar_L0bar_p1pt_p2pt_US_LS->Draw("COLZ"); 
    h2_no_cuts_L0bar_L0bar_p1pt_p2pt_US_LS->SetTitle("Pt- US-LS #bar{#Lambda}#bar{#Lambda} Pairs (no cuts)"); 
    h2_no_cuts_L0bar_L0bar_p1pt_p2pt_US_LS->GetXaxis()->SetTitle("p1_pt [GeV/c]");
    h2_no_cuts_L0bar_L0bar_p1pt_p2pt_US_LS->GetXaxis()->CenterTitle(true);
    h2_no_cuts_L0bar_L0bar_p1pt_p2pt_US_LS->GetYaxis()->SetTitle("p2_pt [GeV/c]");
    h2_no_cuts_L0bar_L0bar_p1pt_p2pt_US_LS->GetYaxis()->CenterTitle(true);

    c5->cd(5);
    h2_no_cuts_L0bar_L0bar_p1eta_p2eta_US_LS->Draw("COLZ");
    h2_no_cuts_L0bar_L0bar_p1eta_p2eta_US_LS->SetTitle("Eta- US-LS #bar{#Lambda}#bar{#Lambda} Pairs (no cuts)");
    h2_no_cuts_L0bar_L0bar_p1eta_p2eta_US_LS->GetXaxis()->SetTitle("p1_eta");
    h2_no_cuts_L0bar_L0bar_p1eta_p2eta_US_LS->GetXaxis()->CenterTitle(true);
    h2_no_cuts_L0bar_L0bar_p1eta_p2eta_US_LS->GetYaxis()->SetTitle("p2_eta");
    h2_no_cuts_L0bar_L0bar_p1eta_p2eta_US_LS->GetYaxis()->CenterTitle(true);

    c5->cd(6);
    h2_no_cuts_L0bar_L0bar_p1phi_p2phi_US_LS->Draw("COLZ");
    h2_no_cuts_L0bar_L0bar_p1phi_p2phi_US_LS->SetTitle("Phi- US-LS #bar{#Lambda}#bar{#Lambda} Pairs (no cuts)");
    h2_no_cuts_L0bar_L0bar_p1phi_p2phi_US_LS->GetXaxis()->SetTitle("p1_phi");
    h2_no_cuts_L0bar_L0bar_p1phi_p2phi_US_LS->GetXaxis()->CenterTitle(true);
    h2_no_cuts_L0bar_L0bar_p1phi_p2phi_US_LS->GetYaxis()->SetTitle("p2_phi");
    h2_no_cuts_L0bar_L0bar_p1phi_p2phi_US_LS->GetYaxis()->CenterTitle(true);

    std::cout << "Canvas 5 Complete" << std::endl;

    // Canvas 3: Invariant Mass Projections of the x axis and y axis
    std::unique_ptr<TCanvas> c6(new TCanvas("c6", "c6- 2D Inv. Mass Projections (x-axis projections)", 1800, 900));
    c6->Divide(3, 2);

    c6->cd(1);
    TH1D *projX_LLBar = h2_LLBar_Signal->ProjectionX("projX_LLBar", binMinX_2, binMaxX_2);
    projX_LLBar->GetXaxis()->SetRange(binMinX_2, binMaxX_2);

    int MeanX_LLBar = h2_LLBar_Signal->GetXaxis()->FindBin(gaus2D_LLBar->GetParameter(3));
    TH1D *meanX_LLBar = h2_LLBar_Signal->ProjectionX("meanX_LLBar", MeanX_LLBar, MeanX_LLBar);
    meanX_LLBar->SetLineColor(kViolet-2);
    meanX_LLBar->SetLineWidth(3);
    meanX_LLBar->SetTitle("X-axis Projection: Inv. Mass #Lambda#bar{#Lambda}");
    meanX_LLBar->GetXaxis()->SetTitle("Inv. Mass");
    meanX_LLBar->GetXaxis()->CenterTitle(true);
    meanX_LLBar->GetYaxis()->SetTitle("Counts");
    meanX_LLBar->GetYaxis()->CenterTitle(true);
    // meanX_LLBar->SetMaximum(4000);
    meanX_LLBar->Draw("");

    TF12 *proj_gausX_LLBar = new TF12("proj_gausX_LLBar", gaus2D_LLBar, gaus2D_LLBar->GetParameter(3), "x");
    proj_gausX_LLBar->SetLineColor(kRed+1);
    proj_gausX_LLBar->SetLineWidth(3);
    proj_gausX_LLBar->Draw("same");

    c6->cd(2);
    TH1D *projX_LL = h2_LL_Signal->ProjectionX("projX_LL", binMinX_2, binMaxX_2);
    projX_LL->GetXaxis()->SetRange(binMinX_2, binMaxX_2);

    int MeanX_LL = h2_LL_Signal->GetXaxis()->FindBin(gaus2D_LL->GetParameter(3));
    TH1D *meanX_LL = h2_LL_Signal->ProjectionX("meanX_LL", MeanX_LL, MeanX_LL);
    meanX_LL->SetLineColor(kViolet-2);
    meanX_LL->SetLineWidth(3);
    meanX_LL->SetTitle("X-axis Projection: Inv. Mass #Lambda#Lambda");
    meanX_LL->GetXaxis()->SetTitle("Inv. Mass");
    meanX_LL->GetXaxis()->CenterTitle(true);
    meanX_LL->GetYaxis()->SetTitle("Counts");
    meanX_LL->GetYaxis()->CenterTitle(true);
    meanX_LL->SetMaximum(4700);
    meanX_LL->Draw("");

    TF12 *proj_gausX_LL = new TF12("proj_gausX_LL", gaus2D_LL, gaus2D_LL->GetParameter(3), "x");
    proj_gausX_LL->SetLineColor(kRed+1);
    proj_gausX_LL->SetLineWidth(3);
    proj_gausX_LL->Draw("same");

    c6->cd(3);
    TH1D *projX_LBarLBar = h2_LBarLBar_Signal->ProjectionX("projX_LBarLBar", binMinX_2, binMaxX_2);
    projX_LBarLBar->GetXaxis()->SetRange(binMinX_2, binMaxX_2);

    int MeanX_LBarLBar = h2_LBarLBar_Signal->GetXaxis()->FindBin(gaus2D_LBarLBar->GetParameter(3));
    TH1D *meanX_LBarLBar = h2_LBarLBar_Signal->ProjectionX("meanX_LBarLBar", MeanX_LBarLBar, MeanX_LBarLBar);
    meanX_LBarLBar->SetLineColor(kViolet-2);
    meanX_LBarLBar->SetLineWidth(3);
    meanX_LBarLBar->SetTitle("X-axis Projection: Inv. Mass #bar{#Lambda}#bar{#Lambda}");
    meanX_LBarLBar->GetXaxis()->SetTitle("Inv. Mass");
    meanX_LBarLBar->GetXaxis()->CenterTitle(true);
    meanX_LBarLBar->GetYaxis()->SetTitle("Counts");
    meanX_LBarLBar->GetYaxis()->CenterTitle(true);
    // meanX_LBarLBar->SetMaximum(1600);
    meanX_LBarLBar->Draw("");

    TF12 *proj_gausX_LBarLBar = new TF12("proj_gausX_LBarLBar", gaus2D_LBarLBar, gaus2D_LBarLBar->GetParameter(3), "x");
    proj_gausX_LBarLBar->SetLineColor(kRed+1);
    proj_gausX_LBarLBar->SetLineWidth(3);
    proj_gausX_LBarLBar->Draw("same");

    c6->cd(4);
    TH1D *projY_LLBar = h2_LLBar_Signal->ProjectionY("projY_LLBar", binMinY_2, binMaxY_2);
    projY_LLBar->GetYaxis()->SetRange(binMinY_2, binMaxY_2);
    
    int MeanY_LLBar = h2_LLBar_Signal->GetYaxis()->FindBin(gaus2D_LLBar->GetParameter(1));
    TH1D *meanY_LLBar = h2_LLBar_Signal->ProjectionY("meanY_LLBar", MeanY_LLBar, MeanY_LLBar);
    meanY_LLBar->SetLineColor(kViolet-2);
    meanY_LLBar->SetLineWidth(3);
    meanY_LLBar->SetTitle("Y-axis Projection: Inv. Mass #Lambda#bar{#Lambda}");
    meanY_LLBar->GetXaxis()->SetTitle("Inv. Mass");
    meanY_LLBar->GetXaxis()->CenterTitle(true);
    meanY_LLBar->GetYaxis()->SetTitle("Counts");
    meanY_LLBar->GetYaxis()->CenterTitle(true);
    // meanY_LLBar->SetMaximum(4000);
    meanY_LLBar->Draw("");

    TF12 *proj_gausY_LLBar = new TF12("proj_gausY_LLBar", gaus2D_LLBar, gaus2D_LLBar->GetParameter(1), "y");
    proj_gausY_LLBar->SetLineColor(kRed+1);
    proj_gausY_LLBar->SetLineWidth(3);
    proj_gausY_LLBar->Draw("same");

    c6->cd(5);
    TH1D *projY_LL = h2_LL_Signal->ProjectionY("projY_LL", binMinY_2, binMaxY_2);
    projY_LL->GetYaxis()->SetRange(binMinY_2, binMaxY_2);

    int MeanY_LL = h2_LL_Signal->GetYaxis()->FindBin(gaus2D_LL->GetParameter(1));
    TH1D *meanY_LL = h2_LL_Signal->ProjectionY("meanY_LL", MeanY_LL, MeanY_LL);
    meanY_LL->SetLineColor(kViolet-2);
    meanY_LL->SetLineWidth(3);
    meanY_LL->SetTitle("Y-axis Projection: Inv. Mass #Lambda#Lambda");
    meanY_LL->GetXaxis()->SetTitle("Inv. Mass");
    meanY_LL->GetXaxis()->CenterTitle(true);
    meanY_LL->GetYaxis()->SetTitle("Counts");
    meanY_LL->GetYaxis()->CenterTitle(true);
    meanY_LL->SetMaximum(4700);
    meanY_LL->Draw("");

    TF12 *proj_gausY_LL = new TF12("proj_gausY_LL", gaus2D_LL, gaus2D_LL->GetParameter(1), "y");
    proj_gausY_LL->SetLineColor(kRed+1);
    proj_gausY_LL->SetLineWidth(3);
    proj_gausY_LL->Draw("same");

    c6->cd(6);
    TH1D *projY_LBarLBar = h2_LBarLBar_Signal->ProjectionY("projY_LBarLBar", binMinY_2, binMaxY_2);
    projY_LBarLBar->GetYaxis()->SetRange(binMinY_2, binMaxY_2);

    int MeanY_LBarLBar = h2_LBarLBar_Signal->GetYaxis()->FindBin(gaus2D_LBarLBar->GetParameter(1));
    TH1D *meanY_LBarLBar = h2_LBarLBar_Signal->ProjectionY("meanY_LBarLBar", MeanY_LBarLBar, MeanY_LBarLBar);
    meanY_LBarLBar->SetLineColor(kViolet-2);
    meanY_LBarLBar->SetLineWidth(3);
    meanY_LBarLBar->SetTitle("Y-axis Projection: Inv. Mass #bar{#Lambda}#bar{#Lambda}");
    meanY_LBarLBar->GetXaxis()->SetTitle("Inv. Mass");
    meanY_LBarLBar->GetXaxis()->CenterTitle(true);
    meanY_LBarLBar->GetYaxis()->SetTitle("Counts");
    meanY_LBarLBar->GetYaxis()->CenterTitle(true);
    // meanY_LBarLBar->SetMaximum(1600);
    meanY_LBarLBar->Draw("");

    TF12 *proj_gausY_LBarLBar = new TF12("proj_gausY_LBarLBar", gaus2D_LBarLBar, gaus2D_LBarLBar->GetParameter(1), "y");
    proj_gausY_LBarLBar->SetLineColor(kRed+1);
    proj_gausY_LBarLBar->SetLineWidth(3);
    proj_gausY_LBarLBar->Draw("same");

    std::cout << "Canvas 6 Complete" << std::endl;

    std::unique_ptr<TCanvas> c7(new TCanvas("c7", "canvas 7", 1800, 900));
    c7->Divide(3, 1);

    c7->cd(1);
    binMinX = h2_SE_lambda_us_lambda_bar_us->GetXaxis()->FindBin(minX);
    binMaxX = h2_SE_lambda_us_lambda_bar_us->GetXaxis()->FindBin(maxX);
    binMinY = h2_SE_lambda_us_lambda_bar_us->GetYaxis()->FindBin(minY);
    binMaxY = h2_SE_lambda_us_lambda_bar_us->GetYaxis()->FindBin(maxY);

    h2_SE_lambda_us_lambda_bar_us->GetXaxis()->SetRange(binMinX, binMaxX);
    h2_SE_lambda_us_lambda_bar_us->GetYaxis()->SetRange(binMinY, binMaxY);
    h2_SE_lambda_us_lambda_bar_us->Draw("SURF2");
    h2_SE_lambda_us_lambda_bar_us->SetTitle("Inv. Mass for #Lambda#bar{#Lambda} Pairs (restricted vectors)");
    h2_SE_lambda_us_lambda_bar_ls->Draw("same");

    c7->cd(2);
    binMinX = h2_SE_lambda_us_lambda_us->GetXaxis()->FindBin(minX);
    binMaxX = h2_SE_lambda_us_lambda_us->GetXaxis()->FindBin(maxX);
    binMinY = h2_SE_lambda_us_lambda_us->GetYaxis()->FindBin(minY);
    binMaxY = h2_SE_lambda_us_lambda_us->GetYaxis()->FindBin(maxY);

    h2_SE_lambda_us_lambda_us->GetXaxis()->SetRange(binMinX, binMaxX);
    h2_SE_lambda_us_lambda_us->GetYaxis()->SetRange(binMinY, binMaxY);
    h2_SE_lambda_us_lambda_us->Draw("SURF2");
    h2_SE_lambda_us_lambda_us->SetTitle("Inv. Mass for #Lambda#Lambda Pairs (restricted vectors)");
    h2_SE_lambda_us_lambda_ls->Draw("same");

    c7->cd(3);
    binMinX = h2_SE_lambda_bar_us_lambda_bar_us->GetXaxis()->FindBin(minX);
    binMaxX = h2_SE_lambda_bar_us_lambda_bar_us->GetXaxis()->FindBin(maxX);
    binMinY = h2_SE_lambda_bar_us_lambda_bar_us->GetYaxis()->FindBin(minY);
    binMaxY = h2_SE_lambda_bar_us_lambda_bar_us->GetYaxis()->FindBin(maxY);

    h2_SE_lambda_bar_us_lambda_bar_us->GetXaxis()->SetRange(binMinX, binMaxX);
    h2_SE_lambda_bar_us_lambda_bar_us->GetYaxis()->SetRange(binMinY, binMaxY);
    h2_SE_lambda_bar_us_lambda_bar_us->Draw("SURF2");
    h2_SE_lambda_bar_us_lambda_bar_us->SetTitle("Inv. Mass for #bar{#Lambda}#bar{#Lambda} Pairs (Singal + Background, restricted vectors)");
    h2_SE_lambda_bar_us_lambda_bar_ls->Draw("same");

    std::unique_ptr<TCanvas> c8(new TCanvas("c8", "canvas 8", 1800, 900));
    c8->Divide(3, 2);

    c8->cd(1);
    h2_restricted_L0_L0bar_p1pt_p2pt_US_US->Draw("COLZ");
    h2_restricted_L0_L0bar_p1pt_p2pt_US_US->SetTitle("Pt- US_US #Lambda#bar{#Lambda} Pairs (restricted vectors)");
    h2_restricted_L0_L0bar_p1pt_p2pt_US_US->GetXaxis()->SetTitle("p1_pT");
    h2_restricted_L0_L0bar_p1pt_p2pt_US_US->GetXaxis()->CenterTitle(true);
    h2_restricted_L0_L0bar_p1pt_p2pt_US_US->GetYaxis()->SetTitle("p2_pT");
    h2_restricted_L0_L0bar_p1pt_p2pt_US_US->GetYaxis()->CenterTitle(true);
    
    c8->cd(2);
    h2_restricted_L0_L0bar_p1eta_p2eta_US_US->Draw("COLZ");
    h2_restricted_L0_L0bar_p1eta_p2eta_US_US->SetTitle("Eta- US_US #Lambda#bar{#Lambda} Pairs (restricted vectors)");
    h2_restricted_L0_L0bar_p1eta_p2eta_US_US->GetXaxis()->SetTitle("p1_eta");
    h2_restricted_L0_L0bar_p1eta_p2eta_US_US->GetXaxis()->CenterTitle(true);
    h2_restricted_L0_L0bar_p1eta_p2eta_US_US->GetYaxis()->SetTitle("p2_eta");
    h2_restricted_L0_L0bar_p1eta_p2eta_US_US->GetYaxis()->CenterTitle(true);

    c8->cd(3);
    h2_restricted_L0_L0bar_p1phi_p2phi_US_US->Draw("COLZ");
    h2_restricted_L0_L0bar_p1phi_p2phi_US_US->SetTitle("Phi- US_US #Lambda#bar{#Lambda} Pairs (restricted vectors)");
    h2_restricted_L0_L0bar_p1phi_p2phi_US_US->GetXaxis()->SetTitle("p1_phi");
    h2_restricted_L0_L0bar_p1phi_p2phi_US_US->GetXaxis()->CenterTitle(true);
    h2_restricted_L0_L0bar_p1phi_p2phi_US_US->GetYaxis()->SetTitle("p2_phi");
    h2_restricted_L0_L0bar_p1phi_p2phi_US_US->GetYaxis()->CenterTitle(true);

    c8->cd(4);
    h2_restricted_L0_L0bar_p1pt_p2pt_US_LS->Draw("COLZ");
    h2_restricted_L0_L0bar_p1pt_p2pt_US_LS->SetTitle("Pt- US_LS #Lambda#bar{#Lambda} Pairs (restricted vectors)");
    h2_restricted_L0_L0bar_p1pt_p2pt_US_LS->GetXaxis()->SetTitle("p1_pT");
    h2_restricted_L0_L0bar_p1pt_p2pt_US_LS->GetXaxis()->CenterTitle(true);
    h2_restricted_L0_L0bar_p1pt_p2pt_US_LS->GetYaxis()->SetTitle("p2_pT");
    h2_restricted_L0_L0bar_p1pt_p2pt_US_LS->GetYaxis()->CenterTitle(true);
    
    c8->cd(5);
    h2_restricted_L0_L0bar_p1eta_p2eta_US_LS->Draw("COLZ");
    h2_restricted_L0_L0bar_p1eta_p2eta_US_LS->SetTitle("Eta- US_LS #Lambda#bar{#Lambda} Pairs (restricted vectors)");
    h2_restricted_L0_L0bar_p1eta_p2eta_US_LS->GetXaxis()->SetTitle("p1_eta");
    h2_restricted_L0_L0bar_p1eta_p2eta_US_LS->GetXaxis()->CenterTitle(true);
    h2_restricted_L0_L0bar_p1eta_p2eta_US_LS->GetYaxis()->SetTitle("p2_eta");
    h2_restricted_L0_L0bar_p1eta_p2eta_US_LS->GetYaxis()->CenterTitle(true);

    c8->cd(6);
    h2_restricted_L0_L0bar_p1phi_p2phi_US_LS->Draw("COLZ");
    h2_restricted_L0_L0bar_p1phi_p2phi_US_LS->SetTitle("Phi- US_LS #Lambda#bar{#Lambda} Pairs (restricted vectors)");
    h2_restricted_L0_L0bar_p1phi_p2phi_US_LS->GetXaxis()->SetTitle("p1_phi");
    h2_restricted_L0_L0bar_p1phi_p2phi_US_LS->GetXaxis()->CenterTitle(true);
    h2_restricted_L0_L0bar_p1phi_p2phi_US_LS->GetYaxis()->SetTitle("p2_phi");
    h2_restricted_L0_L0bar_p1phi_p2phi_US_LS->GetYaxis()->CenterTitle(true);

    std::cout << "Canvas 8 Complete" << std::endl;

    std::unique_ptr<TCanvas> c9(new TCanvas("c9", "canvas 9", 1800, 900));
    c9->Divide(3, 2);

    c9->cd(1);
    h2_restricted_L0_L0_p1pt_p2pt_US_US->Draw("COLZ");
    h2_restricted_L0_L0_p1pt_p2pt_US_US->SetTitle("Pt- US_US #Lambda#Lambda Pairs (restricted vectors)");
    h2_restricted_L0_L0_p1pt_p2pt_US_US->GetXaxis()->SetTitle("p1_pT");
    h2_restricted_L0_L0_p1pt_p2pt_US_US->GetXaxis()->CenterTitle(true);
    h2_restricted_L0_L0_p1pt_p2pt_US_US->GetYaxis()->SetTitle("p2_pT");
    h2_restricted_L0_L0_p1pt_p2pt_US_US->GetYaxis()->CenterTitle(true);

    c9->cd(2);
    h2_restricted_L0_L0_p1eta_p2eta_US_US->Draw("COLZ");
    h2_restricted_L0_L0_p1eta_p2eta_US_US->SetTitle("Eta- US_US #Lambda#Lambda Pairs (restricted vectors)");
    h2_restricted_L0_L0_p1eta_p2eta_US_US->GetXaxis()->SetTitle("p1_eta");
    h2_restricted_L0_L0_p1eta_p2eta_US_US->GetXaxis()->CenterTitle(true);
    h2_restricted_L0_L0_p1eta_p2eta_US_US->GetYaxis()->SetTitle("p2_eta");
    h2_restricted_L0_L0_p1eta_p2eta_US_US->GetYaxis()->CenterTitle(true);

    c9->cd(3);
    h2_restricted_L0_L0_p1phi_p2phi_US_US->Draw("COLZ");
    h2_restricted_L0_L0_p1phi_p2phi_US_US->SetTitle("Phi- US_US #Lambda#Lambda Pairs (restricted vectors)");
    h2_restricted_L0_L0_p1phi_p2phi_US_US->GetXaxis()->SetTitle("p1_phi");
    h2_restricted_L0_L0_p1phi_p2phi_US_US->GetXaxis()->CenterTitle(true);
    h2_restricted_L0_L0_p1phi_p2phi_US_US->GetYaxis()->SetTitle("p2_phi");
    h2_restricted_L0_L0_p1phi_p2phi_US_US->GetYaxis()->CenterTitle(true);

    c9->cd(4);
    h2_restricted_L0_L0_p1pt_p2pt_US_LS->Draw("COLZ");
    h2_restricted_L0_L0_p1pt_p2pt_US_LS->SetTitle("Pt- US_LS #Lambda#Lambda Pairs (restricted vectors)");
    h2_restricted_L0_L0_p1pt_p2pt_US_LS->GetXaxis()->SetTitle("p1_pT");
    h2_restricted_L0_L0_p1pt_p2pt_US_LS->GetXaxis()->CenterTitle(true);
    h2_restricted_L0_L0_p1pt_p2pt_US_LS->GetYaxis()->SetTitle("p2_pT");
    h2_restricted_L0_L0_p1pt_p2pt_US_LS->GetYaxis()->CenterTitle(true);

    c9->cd(5);
    h2_restricted_L0_L0_p1eta_p2eta_US_LS->Draw("COLZ");
    h2_restricted_L0_L0_p1eta_p2eta_US_LS->SetTitle("Eta- US_LS #Lambda#Lambda Pairs (restricted vectors)");
    h2_restricted_L0_L0_p1eta_p2eta_US_LS->GetXaxis()->SetTitle("p1_eta");
    h2_restricted_L0_L0_p1eta_p2eta_US_LS->GetXaxis()->CenterTitle(true);
    h2_restricted_L0_L0_p1eta_p2eta_US_LS->GetYaxis()->SetTitle("p2_eta");
    h2_restricted_L0_L0_p1eta_p2eta_US_LS->GetYaxis()->CenterTitle(true);

    c9->cd(6);
    h2_restricted_L0_L0_p1phi_p2phi_US_LS->Draw("COLZ");
    h2_restricted_L0_L0_p1phi_p2phi_US_LS->SetTitle("Phi- US_LS #Lambda#Lambda Pairs (restricted vectors)");
    h2_restricted_L0_L0_p1phi_p2phi_US_LS->GetXaxis()->SetTitle("p1_phi");
    h2_restricted_L0_L0_p1phi_p2phi_US_LS->GetXaxis()->CenterTitle(true);
    h2_restricted_L0_L0_p1phi_p2phi_US_LS->GetYaxis()->SetTitle("p2_phi");
    h2_restricted_L0_L0_p1phi_p2phi_US_LS->GetYaxis()->CenterTitle(true);

    std::cout << "Canvas 9 Complete" << std::endl;

    std::unique_ptr<TCanvas> c10(new TCanvas("c10", "canvas 10", 1800, 900));
    c10->Divide(3, 2);

    c10->cd(1);
    h2_restricted_L0bar_L0bar_p1pt_p2pt_US_US->Draw("COLZ");
    h2_restricted_L0bar_L0bar_p1pt_p2pt_US_US->SetTitle("Pt- US_US #bar{#Lambda}#bar{#Lambda} Pairs (restricted vectors)");
    h2_restricted_L0bar_L0bar_p1pt_p2pt_US_US->GetXaxis()->SetTitle("p1_pT");
    h2_restricted_L0bar_L0bar_p1pt_p2pt_US_US->GetXaxis()->CenterTitle(true);
    h2_restricted_L0bar_L0bar_p1pt_p2pt_US_US->GetYaxis()->SetTitle("p2_pT");
    h2_restricted_L0bar_L0bar_p1pt_p2pt_US_US->GetYaxis()->CenterTitle(true);
    
    c10->cd(2);
    h2_restricted_L0bar_L0bar_p1eta_p2eta_US_US->Draw("COLZ");
    h2_restricted_L0bar_L0bar_p1eta_p2eta_US_US->SetTitle("Eta- US_US #bar{#Lambda}#bar{#Lambda} Pairs (restricted vectors)");
    h2_restricted_L0bar_L0bar_p1eta_p2eta_US_US->GetXaxis()->SetTitle("p1_eta");
    h2_restricted_L0bar_L0bar_p1eta_p2eta_US_US->GetXaxis()->CenterTitle(true);
    h2_restricted_L0bar_L0bar_p1eta_p2eta_US_US->GetYaxis()->SetTitle("p2_eta");
    h2_restricted_L0bar_L0bar_p1eta_p2eta_US_US->GetYaxis()->CenterTitle(true);

    c10->cd(3);
    h2_restricted_L0bar_L0bar_p1phi_p2phi_US_US->Draw("COLZ");
    h2_restricted_L0bar_L0bar_p1phi_p2phi_US_US->SetTitle("Phi- US_US #bar{#Lambda}#bar{#Lambda} Pairs (restricted vectors)");
    h2_restricted_L0bar_L0bar_p1phi_p2phi_US_US->GetXaxis()->SetTitle("p1_phi");
    h2_restricted_L0bar_L0bar_p1phi_p2phi_US_US->GetXaxis()->CenterTitle(true);
    h2_restricted_L0bar_L0bar_p1phi_p2phi_US_US->GetYaxis()->SetTitle("p2_phi");
    h2_restricted_L0bar_L0bar_p1phi_p2phi_US_US->GetYaxis()->CenterTitle(true);

    c10->cd(4);
    h2_restricted_L0bar_L0bar_p1pt_p2pt_US_LS->Draw("COLZ");
    h2_restricted_L0bar_L0bar_p1pt_p2pt_US_LS->SetTitle("Pt- US_LS #bar{#Lambda}#bar{#Lambda} Pairs (restricted vectors)");
    h2_restricted_L0bar_L0bar_p1pt_p2pt_US_LS->GetXaxis()->SetTitle("p1_pT");
    h2_restricted_L0bar_L0bar_p1pt_p2pt_US_LS->GetXaxis()->CenterTitle(true);
    h2_restricted_L0bar_L0bar_p1pt_p2pt_US_LS->GetYaxis()->SetTitle("p2_pT");
    h2_restricted_L0bar_L0bar_p1pt_p2pt_US_LS->GetYaxis()->CenterTitle(true);
    
    c10->cd(5);
    h2_restricted_L0bar_L0bar_p1eta_p2eta_US_LS->Draw("COLZ");
    h2_restricted_L0bar_L0bar_p1eta_p2eta_US_LS->SetTitle("Eta- US_LS #bar{#Lambda}#bar{#Lambda} Pairs (restricted vectors)");
    h2_restricted_L0_L0_p1pt_p2pt_US_US->GetXaxis()->SetTitle("p1_eta");
    h2_restricted_L0_L0_p1pt_p2pt_US_US->GetXaxis()->CenterTitle(true);
    h2_restricted_L0_L0_p1pt_p2pt_US_US->GetYaxis()->SetTitle("p2_eta");
    h2_restricted_L0_L0_p1pt_p2pt_US_US->GetYaxis()->CenterTitle(true);

    c10->cd(6);
    h2_restricted_L0bar_L0bar_p1phi_p2phi_US_LS->Draw("COLZ");
    h2_restricted_L0bar_L0bar_p1phi_p2phi_US_LS->SetTitle("Phi- US_LS #bar{#Lambda}#bar{#Lambda} Pairs (restricted vectors)");
    h2_restricted_L0bar_L0bar_p1phi_p2phi_US_LS->GetXaxis()->SetTitle("p1_phi");
    h2_restricted_L0bar_L0bar_p1phi_p2phi_US_LS->GetXaxis()->CenterTitle(true);
    h2_restricted_L0bar_L0bar_p1phi_p2phi_US_LS->GetYaxis()->SetTitle("p2_phi");
    h2_restricted_L0bar_L0bar_p1phi_p2phi_US_LS->GetYaxis()->CenterTitle(true);

    std::cout << "Canvas 10 Complete" << std::endl;

    std::unique_ptr<TCanvas> c11(new TCanvas("c11", "canvas 11", 1800, 900));
    c11->Divide(3, 1);

    TH2F *h2_restricted_LL_Signal = new TH2F(*h2_SE_lambda_us_lambda_us);
    h2_restricted_LL_Signal->Add(h2_SE_lambda_us_lambda_ls, -1.0);

    TH2F *h2_restricted_LLBar_Signal = new TH2F(*h2_SE_lambda_us_lambda_bar_us);
    h2_restricted_LLBar_Signal->Add(h2_SE_lambda_us_lambda_bar_ls, -1.0);

    TH2F *h2_restricted_LBarLBar_Signal = new TH2F(*h2_SE_lambda_bar_us_lambda_bar_us);
    h2_restricted_LBarLBar_Signal->Add(h2_SE_lambda_bar_us_lambda_bar_ls, -1.0);

    c11->cd(1);
    binMinX_2 = h2_restricted_LLBar_Signal->GetXaxis()->FindBin(minX_2);
    binMaxX_2 = h2_restricted_LLBar_Signal->GetXaxis()->FindBin(maxX_2);
    binMinY_2 = h2_restricted_LLBar_Signal->GetYaxis()->FindBin(minY_2);
    binMaxY_2 = h2_restricted_LLBar_Signal->GetYaxis()->FindBin(maxY_2);

    h2_restricted_LLBar_Signal->GetXaxis()->SetRange(binMinX_2, binMaxX_2);
    h2_restricted_LLBar_Signal->GetYaxis()->SetRange(binMinY_2, binMaxY_2);
    h2_restricted_LLBar_Signal->Draw("SURF2");
    h2_restricted_LLBar_Signal->SetTitle("#Lambda#bar{#Lambda} Inv. Mass Peak (restricted vectors)");

    c11->cd(2);
    binMinX_2 = h2_restricted_LL_Signal->GetXaxis()->FindBin(minX_2);
    binMaxX_2 = h2_restricted_LL_Signal->GetXaxis()->FindBin(maxX_2);
    binMinY_2 = h2_restricted_LL_Signal->GetYaxis()->FindBin(minY_2);
    binMaxY_2 = h2_restricted_LL_Signal->GetYaxis()->FindBin(maxY_2);

    h2_restricted_LL_Signal->GetXaxis()->SetRange(binMinX_2, binMaxX_2);
    h2_restricted_LL_Signal->GetYaxis()->SetRange(binMinY_2, binMaxY_2);
    h2_restricted_LL_Signal->Draw("SURF2");
    h2_restricted_LL_Signal->SetTitle("#Lambda#Lambda Inv. Mass Peak (restricted vectors)");

    c11->cd(3);
    binMinX_2 = h2_restricted_LBarLBar_Signal->GetXaxis()->FindBin(minX_2);
    binMaxX_2 = h2_restricted_LBarLBar_Signal->GetXaxis()->FindBin(maxX_2);
    binMinY_2 = h2_restricted_LBarLBar_Signal->GetYaxis()->FindBin(minY_2);
    binMaxY_2 = h2_restricted_LBarLBar_Signal->GetYaxis()->FindBin(maxY_2);

    h2_restricted_LBarLBar_Signal->GetXaxis()->SetRange(binMinX_2, binMaxX_2);
    h2_restricted_LBarLBar_Signal->GetYaxis()->SetRange(binMinY_2, binMaxY_2);
    h2_restricted_LBarLBar_Signal->Draw("SURF2");
    h2_restricted_LBarLBar_Signal->SetTitle("#bar{#Lambda}#bar{#Lambda} Inv. Mass Peak (restricted vectors)");

    std::cout << "Canvas 11 Complete" << std::endl;

    // ± 3 sigma check and polarization calculations for Lambda - Lambda Bar Pairs
    double meanX_LLBar_2 = gaus2D_LLBar->GetParameter(1);
    double sigmaX_LLBar_2 = std::fabs(gaus2D_LLBar->GetParameter(2));
    double meanY_LLBar_2 = gaus2D_LLBar->GetParameter(3);
    double sigmaY_LLBar_2 = std::fabs(gaus2D_LLBar->GetParameter(4));

    double minX_range_LLBar_2 = meanX_LLBar_2 - 3.0 * sigmaX_LLBar_2;
    double maxX_range_LLBar_2 = meanX_LLBar_2 + 3.0 * sigmaX_LLBar_2;
    double minY_range_LLBar_2 = meanY_LLBar_2 - 3.0 * sigmaY_LLBar_2;
    double maxY_range_LLBar_2 = meanY_LLBar_2 + 3.0 * sigmaY_LLBar_2;

    for (size_t i = 0; i < fourmoment_lambda_us4.size(); ++i){
        double invariantMass_lambda_us_4 = fourmoment_lambda_us4[i].M();
        double invariantMass_lambda_bar_us_4 = fourmoment_lambda_bar_us4[i].M();
        double centrality_weight_3 = weight_vector_3[i];

        h2_no_cut_invMass_lambda_us_lambda_bar_us->Fill(invariantMass_lambda_us_4, invariantMass_lambda_bar_us_4, centrality_weight_3);

        h2_no_cut_check_L0_L0bar_p1pt_p2pt_US_US->Fill(fourmoment_proton_us4[i].Pt(), fourmoment_anti_proton_us4[i].Pt(), centrality_weight_3);
        h2_no_cut_check_L0_L0bar_p1eta_p2eta_US_US->Fill(fourmoment_proton_us4[i].Eta(), fourmoment_anti_proton_us4[i].Eta(), centrality_weight_3);
        h2_no_cut_check_L0_L0bar_p1phi_p2phi_US_US->Fill(fourmoment_proton_us4[i].Phi(), fourmoment_anti_proton_us4[i].Phi(), centrality_weight_3);

        if (invariantMass_lambda_us_4 >= minX_range_LLBar_2 && invariantMass_lambda_us_4 <= maxX_range_LLBar_2 &&
            invariantMass_lambda_bar_us_4 >= minY_range_LLBar_2 && invariantMass_lambda_bar_us_4 <= maxY_range_LLBar_2) {

            double delta_y = std::fabs(fourmoment_lambda_us4[i].Rapidity() - fourmoment_lambda_bar_us4[i].Rapidity());
            double delta_phi = std::fabs(fourmoment_lambda_us4[i].Phi() - fourmoment_lambda_bar_us4[i].Phi());

            if (delta_phi > M_PI) delta_phi = 2 * M_PI - delta_phi;
            
            double delta_R = sqrt(delta_y * delta_y + delta_phi * delta_phi);

            h_delta_R_US_US_llbar->Fill(delta_R, centrality_weight_3);
            h_delta_phi_US_US_llbar->Fill(delta_phi, centrality_weight_3);

            double delta_R_Threshold = 0.93;
            if (delta_R > delta_R_Threshold){
                h2_invMass_outside_lambda_us_lambda_bar_us->Fill(invariantMass_lambda_us_4, invariantMass_lambda_bar_us_4, centrality_weight_3);

                h2_cut_outside_L0_L0bar_p1pt_p2pt_US_US->Fill(fourmoment_proton_us4[i].Pt(), fourmoment_anti_proton_us4[i].Pt(), centrality_weight_3);
                h2_cut_outside_L0_L0bar_p1eta_p2eta_US_US->Fill(fourmoment_proton_us4[i].Eta(), fourmoment_anti_proton_us4[i].Eta(), centrality_weight_3);
                h2_cut_outside_L0_L0bar_p1phi_p2phi_US_US->Fill(fourmoment_proton_us4[i].Phi(), fourmoment_anti_proton_us4[i].Phi(), centrality_weight_3);

                fourmoment_proton_us4[i].Boost(-fourmoment_lambda_us4[i].BoostVector());
                fourmoment_anti_proton_us4[i].Boost(-fourmoment_lambda_bar_us4[i].BoostVector());
                double outside_theta_star3 = fourmoment_proton_us4[i].Angle(fourmoment_anti_proton_us4[i].Vect());
                double outside_cos_theta_star3 = cos(outside_theta_star3);

                h_outside_cos_theta_star3->Fill(outside_cos_theta_star3, centrality_weight_3);

            } else{
                h2_invMass_lambda_us_lambda_bar_us->Fill(invariantMass_lambda_us_4, invariantMass_lambda_bar_us_4, centrality_weight_3);

                h2_cut_L0_L0bar_p1pt_p2pt_US_US->Fill(fourmoment_proton_us4[i].Pt(), fourmoment_anti_proton_us4[i].Pt(), centrality_weight_3);
                h2_cut_L0_L0bar_p1eta_p2eta_US_US->Fill(fourmoment_proton_us4[i].Eta(), fourmoment_anti_proton_us4[i].Eta(), centrality_weight_3);
                h2_cut_L0_L0bar_p1phi_p2phi_US_US->Fill(fourmoment_proton_us4[i].Phi(), fourmoment_anti_proton_us4[i].Phi(), centrality_weight_3);

                fourmoment_proton_us4[i].Boost(-fourmoment_lambda_us4[i].BoostVector());
                fourmoment_anti_proton_us4[i].Boost(-fourmoment_lambda_bar_us4[i].BoostVector());
                double theta_star3 = fourmoment_proton_us4[i].Angle(fourmoment_anti_proton_us4[i].Vect());
                double cos_theta_star3 = cos(theta_star3);

                h_cos_theta_star3->Fill(cos_theta_star3, centrality_weight_3);
            }

        } else {
            continue;
        }
    }
    
    // for loop for lambda_us - lambda_bar_ls
    for (size_t i = 0; i < fourmoment_lambda_us5.size(); ++i){
        double invariantMass_lambda_us_5 = fourmoment_lambda_us5[i].M();
        double invariantMass_lambda_bar_ls_5 = fourmoment_lambda_bar_ls5[i].M();
        double centrality_weight_4 = weight_vector_4[i];

        h2_no_cut_invMass_lambda_us_lambda_bar_ls->Fill(invariantMass_lambda_us_5, invariantMass_lambda_bar_ls_5, centrality_weight_4);

        h2_no_cut_check_L0_L0bar_p1pt_p2pt_US_LS->Fill(fourmoment_proton_us5[i].Pt(), fourmoment_anti_proton_ls5[i].Pt(), centrality_weight_4);
        h2_no_cut_check_L0_L0bar_p1eta_p2eta_US_LS->Fill(fourmoment_proton_us5[i].Eta(), fourmoment_anti_proton_ls5[i].Eta(), centrality_weight_4);
        h2_no_cut_check_L0_L0bar_p1phi_p2phi_US_LS->Fill(fourmoment_proton_us5[i].Phi(), fourmoment_anti_proton_ls5[i].Phi(), centrality_weight_4);

        if (invariantMass_lambda_us_5 >= minX_range_LLBar_2 && invariantMass_lambda_us_5 <= maxX_range_LLBar_2 &&
            invariantMass_lambda_bar_ls_5 >= minY_range_LLBar_2 && invariantMass_lambda_bar_ls_5 <= maxY_range_LLBar_2) {

            double delta_y = std::fabs(fourmoment_lambda_us5[i].Rapidity() - fourmoment_lambda_bar_ls5[i].Rapidity());
            double delta_phi = std::fabs(fourmoment_lambda_us5[i].Phi() - fourmoment_lambda_bar_ls5[i].Phi());

            if (delta_phi > M_PI) delta_phi = 2 * M_PI - delta_phi;
            
            double delta_R = sqrt(delta_y * delta_y + delta_phi * delta_phi);

            h_delta_R_US_LS_llbar->Fill(delta_R, centrality_weight_4);
            h_delta_phi_US_LS_llbar->Fill(delta_phi, centrality_weight_4);

            double delta_R_Threshold = 0.93;
            if (delta_R > delta_R_Threshold){
                h2_invMass_outside_lambda_us_lambda_bar_ls->Fill(invariantMass_lambda_us_5, invariantMass_lambda_bar_ls_5, centrality_weight_4);

                h2_cut_outside_L0_L0bar_p1pt_p2pt_US_LS->Fill(fourmoment_proton_us5[i].Pt(), fourmoment_anti_proton_ls5[i].Pt(), centrality_weight_4);
                h2_cut_outside_L0_L0bar_p1eta_p2eta_US_LS->Fill(fourmoment_proton_us5[i].Eta(), fourmoment_anti_proton_ls5[i].Eta(), centrality_weight_4);
                h2_cut_outside_L0_L0bar_p1phi_p2phi_US_LS->Fill(fourmoment_proton_us5[i].Phi(), fourmoment_anti_proton_ls5[i].Phi(), centrality_weight_4);
                
                fourmoment_proton_us5[i].Boost(-fourmoment_lambda_us5[i].BoostVector());
                fourmoment_anti_proton_ls5[i].Boost(-fourmoment_lambda_bar_ls5[i].BoostVector());
                double outside_theta_star4 = fourmoment_proton_us5[i].Angle(fourmoment_anti_proton_ls5[i].Vect());
                double outside_cos_theta_star4 = cos(outside_theta_star4);

                h_outside_cos_theta_star4->Fill(outside_cos_theta_star4, centrality_weight_4);

            } else{
                h2_invMass_lambda_us_lambda_bar_ls->Fill(invariantMass_lambda_us_5, invariantMass_lambda_bar_ls_5, centrality_weight_4);

                h2_cut_L0_L0bar_p1pt_p2pt_US_LS->Fill(fourmoment_proton_us5[i].Pt(), fourmoment_anti_proton_ls5[i].Pt(), centrality_weight_4);
                h2_cut_L0_L0bar_p1eta_p2eta_US_LS->Fill(fourmoment_proton_us5[i].Eta(), fourmoment_anti_proton_ls5[i].Eta(), centrality_weight_4);
                h2_cut_L0_L0bar_p1phi_p2phi_US_LS->Fill(fourmoment_proton_us5[i].Phi(), fourmoment_anti_proton_ls5[i].Phi(), centrality_weight_4);

                fourmoment_proton_us5[i].Boost(-fourmoment_lambda_us5[i].BoostVector());
                fourmoment_anti_proton_ls5[i].Boost(-fourmoment_lambda_bar_ls5[i].BoostVector());
                double theta_star4 = fourmoment_proton_us5[i].Angle(fourmoment_anti_proton_ls5[i].Vect());
                double cos_theta_star4 = cos(theta_star4);

                h_cos_theta_star4->Fill(cos_theta_star4, centrality_weight_4);
            }

        } else {
            continue;
        }
    }
    
    // for loop for lambda_ls - lambda_bar_us
    for (size_t i = 0; i < fourmoment_lambda_ls6.size(); ++i){
        double invariantMass_lambda_ls_6 = fourmoment_lambda_ls6[i].M();
        double invariantMass_lambda_bar_us_6 = fourmoment_lambda_bar_us6[i].M();
        double centrality_weight_5 = weight_vector_5[i];

        h2_no_cut_invMass_lambda_us_lambda_bar_ls->Fill(invariantMass_lambda_ls_6, invariantMass_lambda_bar_us_6, centrality_weight_5);

        h2_no_cut_check_L0_L0bar_p1pt_p2pt_US_LS->Fill(fourmoment_proton_ls6[i].Pt(), fourmoment_anti_proton_us6[i].Pt(), centrality_weight_5);
        h2_no_cut_check_L0_L0bar_p1eta_p2eta_US_LS->Fill(fourmoment_proton_ls6[i].Eta(), fourmoment_anti_proton_us6[i].Eta(), centrality_weight_5);
        h2_no_cut_check_L0_L0bar_p1phi_p2phi_US_LS->Fill(fourmoment_proton_ls6[i].Phi(), fourmoment_anti_proton_us6[i].Phi(), centrality_weight_5);

        if (invariantMass_lambda_ls_6 >= minX_range_LLBar_2 && invariantMass_lambda_ls_6 <= maxX_range_LLBar_2 &&
            invariantMass_lambda_bar_us_6 >= minY_range_LLBar_2 && invariantMass_lambda_bar_us_6 <= maxY_range_LLBar_2){

            double delta_y = std::fabs(fourmoment_lambda_ls6[i].Rapidity() - fourmoment_lambda_bar_us6[i].Rapidity());
            double delta_phi = std::fabs(fourmoment_lambda_ls6[i].Phi() - fourmoment_lambda_bar_us6[i].Phi());

            if (delta_phi > M_PI) delta_phi = 2 * M_PI - delta_phi;
            
            double delta_R = sqrt(delta_y * delta_y + delta_phi * delta_phi);

            h_delta_R_US_LS_llbar->Fill(delta_R, centrality_weight_5);
            h_delta_phi_US_LS_llbar->Fill(delta_phi, centrality_weight_5);

            double delta_R_Threshold = 0.93;
            if (delta_R > delta_R_Threshold){
                h2_invMass_outside_lambda_us_lambda_bar_ls->Fill(invariantMass_lambda_ls_6, invariantMass_lambda_bar_us_6, centrality_weight_5);

                h2_cut_outside_L0_L0bar_p1pt_p2pt_US_LS->Fill(fourmoment_proton_ls6[i].Pt(), fourmoment_anti_proton_us6[i].Pt(), centrality_weight_5);
                h2_cut_outside_L0_L0bar_p1eta_p2eta_US_LS->Fill(fourmoment_proton_ls6[i].Eta(), fourmoment_anti_proton_us6[i].Eta(), centrality_weight_5);
                h2_cut_outside_L0_L0bar_p1phi_p2phi_US_LS->Fill(fourmoment_proton_ls6[i].Phi(), fourmoment_anti_proton_us6[i].Phi(), centrality_weight_5);

                fourmoment_proton_ls6[i].Boost(-fourmoment_lambda_ls6[i].BoostVector());
                fourmoment_anti_proton_us6[i].Boost(-fourmoment_lambda_bar_us6[i].BoostVector());
                double outside_theta_star4 = fourmoment_proton_ls6[i].Angle(fourmoment_anti_proton_us6[i].Vect());
                double outside_cos_theta_star4 = cos(outside_theta_star4);

                h_outside_cos_theta_star4->Fill(outside_cos_theta_star4, centrality_weight_5);

            } else{
                h2_invMass_lambda_us_lambda_bar_ls->Fill(invariantMass_lambda_ls_6, invariantMass_lambda_bar_us_6, centrality_weight_5);

                h2_cut_L0_L0bar_p1pt_p2pt_US_LS->Fill(fourmoment_proton_ls6[i].Pt(), fourmoment_anti_proton_us6[i].Pt(), centrality_weight_5);
                h2_cut_L0_L0bar_p1eta_p2eta_US_LS->Fill(fourmoment_proton_ls6[i].Eta(), fourmoment_anti_proton_us6[i].Eta(), centrality_weight_5);
                h2_cut_L0_L0bar_p1phi_p2phi_US_LS->Fill(fourmoment_proton_ls6[i].Phi(), fourmoment_anti_proton_us6[i].Phi(), centrality_weight_5);

                fourmoment_proton_ls6[i].Boost(-fourmoment_lambda_ls6[i].BoostVector());
                fourmoment_anti_proton_us6[i].Boost(-fourmoment_lambda_bar_us6[i].BoostVector());
                double theta_star4 = fourmoment_proton_ls6[i].Angle(fourmoment_anti_proton_us6[i].Vect());
                double cos_theta_star4 = cos(theta_star4);

                h_cos_theta_star4->Fill(cos_theta_star4, centrality_weight_5);
            }
        } else {
            continue;
        }
    }

    // ± 3 sigma check and polarization calculations for Lambda - Lambda Pairs
    double meanX_LL_2 = gaus2D_LL->GetParameter(1);
    double sigmaX_LL_2 = std::fabs(gaus2D_LL->GetParameter(2));
    double meanY_LL_2 = gaus2D_LL->GetParameter(3);
    double sigmaY_LL_2 = std::fabs(gaus2D_LL->GetParameter(4));

    double minX_range_LL_2 = meanX_LL_2 - 3.0 * sigmaX_LL_2;
    double maxX_range_LL_2 = meanX_LL_2 + 3.0 * sigmaX_LL_2;
    double minY_range_LL_2 = meanY_LL_2 - 3.0 * sigmaY_LL_2;
    double maxY_range_LL_2 = meanY_LL_2 + 3.0 * sigmaY_LL_2;

    for (size_t i = 0; i < fourmoment_lambda_us_1.size(); ++i) {
        double invariantMass_lambda_us_1 = fourmoment_lambda_us_1[i].M();
        double invariantMass_lambda_us_2 = fourmoment_lambda_us_2[i].M();
        double centrality_weight_1 = weight_vector_1[i];

        h2_no_cut_invMass_lambda_us_lambda_us->Fill(invariantMass_lambda_us_1, invariantMass_lambda_us_2, centrality_weight_1);

        h2_no_cut_check_L0_L0_p1pt_p2pt_US_US->Fill(fourmoment_proton_us_1[i].Pt(), fourmoment_proton_us_2[i].Pt(), centrality_weight_1);
        h2_no_cut_check_L0_L0_p1eta_p2eta_US_US->Fill(fourmoment_proton_us_1[i].Eta(), fourmoment_proton_us_2[i].Eta(), centrality_weight_1);
        h2_no_cut_check_L0_L0_p1phi_p2phi_US_US->Fill(fourmoment_proton_us_1[i].Phi(), fourmoment_proton_us_2[i].Phi(), centrality_weight_1);

        // Check if invariant mass values are within 3 sigma range
        if (invariantMass_lambda_us_1 >= minX_range_LL_2 && invariantMass_lambda_us_1 <= maxX_range_LL_2 &&
            invariantMass_lambda_us_2 >= minY_range_LL_2 && invariantMass_lambda_us_2 <= maxY_range_LL_2) {

            double delta_y = std::fabs(fourmoment_lambda_us_1[i].Rapidity() - fourmoment_lambda_us_2[i].Rapidity());
            double delta_phi = std::fabs(fourmoment_lambda_us_1[i].Phi() - fourmoment_lambda_us_2[i].Phi());
            if (delta_phi > M_PI) delta_phi = 2 * M_PI - delta_phi;
            
            double delta_R = sqrt(delta_y * delta_y + delta_phi * delta_phi);

            h_delta_R_US_US_ll->Fill(delta_R, centrality_weight_1);
            h_delta_phi_US_US_ll->Fill(delta_phi, centrality_weight_1);

            double delta_R_Threshold = 0.93;
            if (delta_R > delta_R_Threshold){
                h2_invMass_outside_lambda_us_lambda_us->Fill(invariantMass_lambda_us_1, invariantMass_lambda_us_2, centrality_weight_1);

                h2_cut_outside_L0_L0_p1pt_p2pt_US_US->Fill(fourmoment_proton_us_1[i].Pt(), fourmoment_proton_us_2[i].Pt(), centrality_weight_1);
                h2_cut_outside_L0_L0_p1eta_p2eta_US_US->Fill(fourmoment_proton_us_1[i].Eta(), fourmoment_proton_us_2[i].Eta(), centrality_weight_1);
                h2_cut_outside_L0_L0_p1phi_p2phi_US_US->Fill(fourmoment_proton_us_1[i].Phi(), fourmoment_proton_us_2[i].Phi(), centrality_weight_1);

                fourmoment_proton_us_1[i].Boost(-fourmoment_lambda_us_1[i].BoostVector());
                fourmoment_proton_us_2[i].Boost(-fourmoment_lambda_us_2[i].BoostVector());
                double outside_theta_star = fourmoment_proton_us_1[i].Angle(fourmoment_proton_us_2[i].Vect());
                double outside_cos_theta_star = cos(outside_theta_star);

                h_outside_cos_theta_star->Fill(outside_cos_theta_star, centrality_weight_1);

            } else {
                h2_invMass_lambda_us_lambda_us->Fill(invariantMass_lambda_us_1, invariantMass_lambda_us_2, centrality_weight_1);

                h2_cut_L0_L0_p1pt_p2pt_US_US->Fill(fourmoment_proton_us_1[i].Pt(), fourmoment_proton_us_2[i].Pt(), centrality_weight_1);
                h2_cut_L0_L0_p1eta_p2eta_US_US->Fill(fourmoment_proton_us_1[i].Eta(), fourmoment_proton_us_2[i].Eta(), centrality_weight_1);
                h2_cut_L0_L0_p1phi_p2phi_US_US->Fill(fourmoment_proton_us_1[i].Phi(), fourmoment_proton_us_2[i].Phi(), centrality_weight_1);

                fourmoment_proton_us_1[i].Boost(-fourmoment_lambda_us_1[i].BoostVector());
                fourmoment_proton_us_2[i].Boost(-fourmoment_lambda_us_2[i].BoostVector());
                double theta_star = fourmoment_proton_us_1[i].Angle(fourmoment_proton_us_2[i].Vect());
                double cos_theta_star = cos(theta_star);

                h_cos_theta_star->Fill(cos_theta_star, centrality_weight_1);
            }

        } else {
            continue; // Skip if outside 3 sigma range
        }
    }

    // for loop for lambda_us - lambda_ls
    for (size_t i = 0; i < fourmoment_lambda_us3.size(); ++i){
        double invariantMass_lambda_us_3 = fourmoment_lambda_us3[i].M();
        double invariantMass_lambda_ls_3 = fourmoment_lambda_ls3[i].M();
        double centrality_weight_2 = weight_vector_2[i];

        h2_no_cut_invMass_lambda_us_lambda_ls->Fill(invariantMass_lambda_us_3, invariantMass_lambda_ls_3, centrality_weight_2);

        h2_no_cut_check_L0_L0_p1pt_p2pt_US_LS->Fill(fourmoment_proton_us3[i].Pt(), fourmoment_proton_ls3[i].Pt(), centrality_weight_2);
        h2_no_cut_check_L0_L0_p1eta_p2eta_US_LS->Fill(fourmoment_proton_us3[i].Eta(), fourmoment_proton_ls3[i].Eta(), centrality_weight_2);
        h2_no_cut_check_L0_L0_p1phi_p2phi_US_LS->Fill(fourmoment_proton_us3[i].Phi(), fourmoment_proton_ls3[i].Phi(), centrality_weight_2);

        if (invariantMass_lambda_us_3 >= minX_range_LL_2 && invariantMass_lambda_us_3 <= maxX_range_LL_2 &&
            invariantMass_lambda_ls_3 >= minY_range_LL_2 && invariantMass_lambda_ls_3 <= maxY_range_LL_2) {

            double delta_y = std::fabs(fourmoment_lambda_us3[i].Rapidity() - fourmoment_lambda_ls3[i].Rapidity());
            double delta_phi = std::fabs(fourmoment_lambda_us3[i].Phi() - fourmoment_lambda_ls3[i].Phi());

            if (delta_phi > M_PI) delta_phi = 2 * M_PI - delta_phi;
            
            double delta_R = sqrt(delta_y * delta_y + delta_phi * delta_phi);

            h_delta_R_US_LS_ll->Fill(delta_R, centrality_weight_2);
            h_delta_phi_US_LS_ll->Fill(delta_phi, centrality_weight_2);

            double delta_R_Threshold = 0.93;
            if (delta_R > delta_R_Threshold){
                h2_invMass_outside_lambda_us_lambda_ls->Fill(invariantMass_lambda_us_3, invariantMass_lambda_ls_3, centrality_weight_2);

                h2_cut_outside_L0_L0_p1pt_p2pt_US_LS->Fill(fourmoment_proton_us3[i].Pt(), fourmoment_proton_ls3[i].Pt(), centrality_weight_2);
                h2_cut_outside_L0_L0_p1eta_p2eta_US_LS->Fill(fourmoment_proton_us3[i].Eta(), fourmoment_proton_ls3[i].Eta(), centrality_weight_2);
                h2_cut_outside_L0_L0_p1phi_p2phi_US_LS->Fill(fourmoment_proton_us3[i].Phi(), fourmoment_proton_ls3[i].Phi(), centrality_weight_2);

                fourmoment_proton_us3[i].Boost(-fourmoment_lambda_us3[i].BoostVector());
                fourmoment_proton_ls3[i].Boost(-fourmoment_lambda_ls3[i].BoostVector());
                double outside_theta_star2 = fourmoment_proton_us3[i].Angle(fourmoment_proton_ls3[i].Vect());
                double outside_cos_theta_star2 = cos(outside_theta_star2);

                h_outside_cos_theta_star2->Fill(outside_cos_theta_star2, centrality_weight_2);

            } else{
                h2_invMass_lambda_us_lambda_ls->Fill(invariantMass_lambda_us_3, invariantMass_lambda_ls_3, centrality_weight_2);

                h2_cut_L0_L0_p1pt_p2pt_US_LS->Fill(fourmoment_proton_us3[i].Pt(), fourmoment_proton_ls3[i].Pt(), centrality_weight_2);
                h2_cut_L0_L0_p1eta_p2eta_US_LS->Fill(fourmoment_proton_us3[i].Eta(), fourmoment_proton_ls3[i].Eta(), centrality_weight_2);
                h2_cut_L0_L0_p1phi_p2phi_US_LS->Fill(fourmoment_proton_us3[i].Phi(), fourmoment_proton_ls3[i].Phi(), centrality_weight_2);

                fourmoment_proton_us3[i].Boost(-fourmoment_lambda_us3[i].BoostVector());
                fourmoment_proton_ls3[i].Boost(-fourmoment_lambda_ls3[i].BoostVector());
                double theta_star2 = fourmoment_proton_us3[i].Angle(fourmoment_proton_ls3[i].Vect());
                double cos_theta_star2 = cos(theta_star2);

                h_cos_theta_star2->Fill(cos_theta_star2, centrality_weight_2);
            }

        } else {
            continue;
        }
    }

    // ± 3-sigma cut for L0bar-L0bar Pairs
    double meanX_LBarLBar_2 = gaus2D_LBarLBar->GetParameter(1);
    double sigmaX_LBarLBar_2 = fabs(gaus2D_LBarLBar->GetParameter(2));
    double meanY_LBarLBar_2 = gaus2D_LBarLBar->GetParameter(3);
    double sigmaY_LBarLBar_2 = fabs(gaus2D_LBarLBar->GetParameter(4));

    double minX_range_LBarLBar_2 = meanX_LBarLBar_2 - 3.0 * sigmaX_LBarLBar_2;
    double maxX_range_LBarLBar_2 = meanX_LBarLBar_2 + 3.0 * sigmaX_LBarLBar_2;
    double minY_range_LBarLBar_2 = meanY_LBarLBar_2 - 3.0 * sigmaY_LBarLBar_2;
    double maxY_range_LBarLBar_2 = meanY_LBarLBar_2 + 3.0 * sigmaY_LBarLBar_2;

    for (size_t i=0; i < fourmoment_lambda_bar_us_1.size(); ++i) {
        double invariantMass_lambda_bar_us_1 = fourmoment_lambda_bar_us_1[i].M();
        double invariantMass_lambda_bar_us_2 = fourmoment_lambda_bar_us_2[i].M();
        double centrality_weight_6 = weight_vector_6[i];

        h2_no_cut_invMass_lambda_bar_us_lambda_bar_us->Fill(invariantMass_lambda_bar_us_1, invariantMass_lambda_bar_us_2, centrality_weight_6);

        h2_no_cut_check_L0bar_L0bar_p1pt_p2pt_US_US->Fill(fourmoment_anti_proton_us_1[i].Pt(), fourmoment_anti_proton_us_2[i].Pt(), centrality_weight_6);
        h2_no_cut_check_L0bar_L0bar_p1eta_p2eta_US_US->Fill(fourmoment_anti_proton_us_1[i].Eta(), fourmoment_anti_proton_us_2[i].Eta(), centrality_weight_6);
        h2_no_cut_check_L0bar_L0bar_p1phi_p2phi_US_US->Fill(fourmoment_anti_proton_us_1[i].Phi(), fourmoment_anti_proton_us_2[i].Phi(), centrality_weight_6);

        if (invariantMass_lambda_bar_us_1 >= minX_range_LBarLBar_2 && invariantMass_lambda_bar_us_1 <= maxX_range_LBarLBar_2 &&
            invariantMass_lambda_bar_us_2 >= minY_range_LBarLBar_2 && invariantMass_lambda_bar_us_2 <= maxY_range_LBarLBar_2) {

            double delta_y = std::fabs(fourmoment_lambda_bar_us_1[i].Rapidity() - fourmoment_lambda_bar_us_2[i].Rapidity());
            double delta_phi = std::fabs(fourmoment_lambda_bar_us_1[i].Phi() - fourmoment_lambda_bar_us_2[i].Phi());
            if (delta_phi > M_PI) delta_phi = 2 * M_PI - delta_phi;

            double delta_R = sqrt(delta_y * delta_y + delta_phi * delta_phi);

            h_delta_R_US_US_lbarlbar->Fill(delta_R, centrality_weight_6);
            h_delta_phi_US_US_lbarlbar->Fill(delta_phi, centrality_weight_6);

            double delta_R_Threshold = 0.93;
            if (delta_R > delta_R_Threshold) {
                h2_invMass_outside_lambda_bar_us_lambda_bar_us->Fill(invariantMass_lambda_bar_us_1, invariantMass_lambda_bar_us_2, centrality_weight_6);

                h2_cut_outside_L0bar_L0bar_p1pt_p2pt_US_US->Fill(fourmoment_anti_proton_us_1[i].Pt(), fourmoment_anti_proton_us_2[i].Pt(), centrality_weight_6);
                h2_cut_outside_L0bar_L0bar_p1eta_p2eta_US_US->Fill(fourmoment_anti_proton_us_1[i].Eta(), fourmoment_anti_proton_us_2[i].Eta(), centrality_weight_6);
                h2_cut_outside_L0bar_L0bar_p1phi_p2phi_US_US->Fill(fourmoment_anti_proton_us_1[i].Phi(), fourmoment_anti_proton_us_2[i].Phi(), centrality_weight_6);

                fourmoment_anti_proton_us_1[i].Boost(-fourmoment_lambda_bar_us_1[i].BoostVector());
                fourmoment_anti_proton_us_2[i].Boost(-fourmoment_lambda_bar_us_2[i].BoostVector());
                double outisde_theta_star5 = fourmoment_anti_proton_us_1[i].Angle(fourmoment_anti_proton_us_2[i].Vect());
                double outside_cos_theta_star5 = cos(outisde_theta_star5);

                h_outside_cos_theta_star5->Fill(outside_cos_theta_star5, centrality_weight_6);
            } else{
                h2_invMass_lambda_bar_us_lambda_bar_us->Fill(invariantMass_lambda_bar_us_1, invariantMass_lambda_bar_us_2, centrality_weight_6);

                h2_cut_L0bar_L0bar_p1pt_p2pt_US_US->Fill(fourmoment_anti_proton_us_1[i].Pt(), fourmoment_anti_proton_us_2[i].Pt(), centrality_weight_6);
                h2_cut_L0bar_L0bar_p1eta_p2eta_US_US->Fill(fourmoment_anti_proton_us_1[i].Eta(), fourmoment_anti_proton_us_2[i].Eta(), centrality_weight_6);
                h2_cut_L0bar_L0bar_p1phi_p2phi_US_US->Fill(fourmoment_anti_proton_us_1[i].Phi(), fourmoment_anti_proton_us_2[i].Phi(), centrality_weight_6);

                fourmoment_anti_proton_us_1[i].Boost(-fourmoment_lambda_bar_us_1[i].BoostVector());
                fourmoment_anti_proton_us_2[i].Boost(-fourmoment_lambda_bar_us_2[i].BoostVector());
                double theta_star5 = fourmoment_anti_proton_us_1[i].Angle(fourmoment_anti_proton_us_2[i].Vect());
                double cos_theta_star5 = cos(theta_star5);

                h_cos_theta_star5->Fill(cos_theta_star5, centrality_weight_6);
            }
        } else{
            continue;
        }
    }

    for (size_t i = 0; i < fourmoment_lambda_bar_us7.size(); ++i) {
        double invariantMass_lambda_bar_us_7 = fourmoment_lambda_bar_us7[i].M();
        double invariantMass_lambda_bar_ls_7 = fourmoment_lambda_bar_ls7[i].M();
        double centrality_weight_7 = weight_vector_7[i];

        h2_no_cut_invMass_lambda_bar_us_lambda_bar_ls->Fill(invariantMass_lambda_bar_us_7, invariantMass_lambda_bar_ls_7, centrality_weight_7);

        h2_no_cut_check_L0bar_L0bar_p1pt_p2pt_US_LS->Fill(fourmoment_anti_proton_us7[i].Pt(), fourmoment_anti_proton_ls7[i].Pt(), centrality_weight_7);
        h2_no_cut_check_L0bar_L0bar_p1eta_p2eta_US_LS->Fill(fourmoment_anti_proton_us7[i].Eta(), fourmoment_anti_proton_ls7[i].Eta(), centrality_weight_7);
        h2_no_cut_check_L0bar_L0bar_p1phi_p2phi_US_LS->Fill(fourmoment_anti_proton_us7[i].Phi(), fourmoment_anti_proton_ls7[i].Phi(), centrality_weight_7);

        if (invariantMass_lambda_bar_us_7 >= minX_range_LBarLBar_2 && invariantMass_lambda_bar_us_7 <= maxX_range_LBarLBar_2 &&
            invariantMass_lambda_bar_ls_7 >= minY_range_LBarLBar_2 && invariantMass_lambda_bar_ls_7 <= maxY_range_LBarLBar_2) {

            double delta_y = std::fabs(fourmoment_anti_proton_us7[i].Rapidity() - fourmoment_anti_proton_ls7[i].Rapidity());
            double delta_phi = std::fabs(fourmoment_anti_proton_us7[i].Phi() - fourmoment_anti_proton_ls7[i].Phi());
            if (delta_phi > M_PI) delta_phi = 2 * M_PI - delta_phi;

            double delta_R = sqrt(delta_y * delta_y + delta_phi * delta_phi);

            h_delta_R_US_LS_lbarlbar->Fill(delta_R, centrality_weight_7);
            h_delta_phi_US_LS_lbarlbar->Fill(delta_phi, centrality_weight_7);

            double delta_R_Threshold = 0.93; 
            if (delta_R > delta_R_Threshold){
                h2_invMass_outside_lambda_bar_us_lambda_bar_ls->Fill(invariantMass_lambda_bar_us_7, invariantMass_lambda_bar_ls_7, centrality_weight_7);

                h2_cut_outside_L0bar_L0bar_p1pt_p2pt_US_LS->Fill(fourmoment_anti_proton_us7[i].Pt(), fourmoment_anti_proton_ls7[i].Pt(), centrality_weight_7);
                h2_cut_outside_L0bar_L0bar_p1eta_p2eta_US_LS->Fill(fourmoment_anti_proton_us7[i].Eta(), fourmoment_anti_proton_ls7[i].Eta(), centrality_weight_7);
                h2_cut_outside_L0bar_L0bar_p1phi_p2phi_US_LS->Fill(fourmoment_anti_proton_us7[i].Phi(), fourmoment_anti_proton_ls7[i].Phi(), centrality_weight_7);

                fourmoment_anti_proton_us7[i].Boost(-fourmoment_lambda_bar_us7[i].BoostVector());
                fourmoment_anti_proton_ls7[i].Boost(-fourmoment_lambda_bar_ls7[i].BoostVector());
                double outside_theta_star6 = fourmoment_anti_proton_us7[i].Angle(fourmoment_anti_proton_ls7[i].Vect());
                double outside_cos_theta_star6 = cos(outside_theta_star6);

                h_outside_cos_theta_star6->Fill(outside_cos_theta_star6, centrality_weight_7);
            } else{
                h2_invMass_lambda_bar_us_lambda_bar_ls->Fill(invariantMass_lambda_bar_us_7, invariantMass_lambda_bar_ls_7, centrality_weight_7);

                h2_cut_L0bar_L0bar_p1pt_p2pt_US_LS->Fill(fourmoment_anti_proton_us7[i].Pt(), fourmoment_anti_proton_ls7[i].Pt(), centrality_weight_7);
                h2_cut_L0bar_L0bar_p1eta_p2eta_US_LS->Fill(fourmoment_anti_proton_us7[i].Eta(), fourmoment_anti_proton_ls7[i].Eta(), centrality_weight_7);
                h2_cut_L0bar_L0bar_p1phi_p2phi_US_LS->Fill(fourmoment_anti_proton_us7[i].Phi(), fourmoment_anti_proton_ls7[i].Phi(), centrality_weight_7);

                fourmoment_anti_proton_us7[i].Boost(-fourmoment_lambda_bar_us7[i].BoostVector());
                fourmoment_anti_proton_ls7[i].Boost(-fourmoment_lambda_bar_ls7[i].BoostVector());
                double theta_star6 = fourmoment_anti_proton_us7[i].Angle(fourmoment_anti_proton_ls7[i].Vect());
                double cos_theta_star6 = cos(theta_star6);

                h_cos_theta_star6->Fill(cos_theta_star6, centrality_weight_7);
            }
        } else{
            continue;
        }
    }

    passed_events++;
    cout << "Events Passed: " << passed_events << endl;

    double counts_no_cut_check_L0_L0bar_US_US = h2_no_cut_invMass_lambda_us_lambda_bar_us->Integral();
    double counts_no_cut_check_L0_L0bar_US_LS = h2_no_cut_invMass_lambda_us_lambda_bar_ls->Integral();
    double counts_no_cut_check_L0_L0_US_US = h2_no_cut_invMass_lambda_us_lambda_us->Integral();
    double counts_no_cut_check_L0_L0_US_LS = h2_no_cut_invMass_lambda_us_lambda_ls->Integral();
    double counts_no_cut_check_L0bar_L0bar_US_US = h2_no_cut_invMass_lambda_bar_us_lambda_bar_us->Integral();
    double counts_no_cut_check_L0bar_L0bar_US_LS = h2_no_cut_invMass_lambda_bar_us_lambda_bar_ls->Integral();

    cout << "   " << endl;
    cout << "Invariant Mass- No Cuts, After Pushing Back into Vectors" << endl;
    cout << "Counts US-US L0-L0bar Inv. Mass (no cuts): " << counts_no_cut_check_L0_L0bar_US_US << endl;
    cout << "Counts US-LS L0-L0bar Inv. Mass (no cuts): " << counts_no_cut_check_L0_L0bar_US_LS << endl;
    cout << "Counts US-US L0-L0 Inv. Mass (no cuts): " << counts_no_cut_check_L0_L0_US_US << endl;
    cout << "Counts US-LS L0-L0 Inv. Mass (no cuts): " << counts_no_cut_check_L0_L0_US_LS << endl;
    cout << "Counts US-US L0bar-L0bar Inv. Mass (no cuts): " << counts_no_cut_check_L0bar_L0bar_US_US << endl;
    cout << "Counts US-LS L0bar-L0bar Inv. Mass (no cuts): " << counts_no_cut_check_L0bar_L0bar_US_LS << endl;

    cout << "   " << endl;
    cout << "   " << endl;
    cout << " Cuts Applied " << endl;

    double counts_cut_outside_L0_L0bar_US_US = h2_invMass_outside_lambda_us_lambda_bar_us->Integral();
    double counts_cut_outside_L0_L0bar_US_LS = h2_invMass_outside_lambda_us_lambda_bar_ls->Integral();
    double counts_cut_outside_L0_L0_US_US = h2_invMass_outside_lambda_us_lambda_us->Integral();
    double counts_cut_outside_L0_L0_US_LS = h2_invMass_outside_lambda_us_lambda_ls->Integral();
    double counts_cut_outside_L0bar_L0bar_US_US = h2_invMass_outside_lambda_bar_us_lambda_bar_us->Integral();
    double counts_cut_outside_L0bar_L0bar_US_LS = h2_invMass_outside_lambda_bar_us_lambda_bar_ls->Integral();

    cout << "   " << endl;
    cout << "** Invariant Mass- Outside #DeltaR **" << endl; 
    cout << "Counts US-US L0-L0bar Inv. Mass Outside #DeltaR: " << counts_cut_outside_L0_L0bar_US_US << endl;
    cout << "Counts US-LS L0-L0bar Inv. Mass Outside #DeltaR: " << counts_cut_outside_L0_L0bar_US_LS << endl;
    cout << "Counts US-US L0-L0 Inv. Mass Outside #DeltaR: " << counts_cut_outside_L0_L0_US_US << endl;
    cout << "Counts US-LS L0-L0 Inv. Mass Outside #DeltaR: " << counts_cut_outside_L0_L0_US_LS << endl;
    cout << "Counts US-US L0bar-L0bar Inv. Mass Outside #DeltaR: " << counts_cut_outside_L0bar_L0bar_US_US << endl;
    cout << "Counts US-LS L0bar-L0bar Inv. Mass Outside #DeltaR: " << counts_cut_outside_L0bar_L0bar_US_LS << endl;

    double counts_cut_inside_L0_L0bar_US_US = h2_invMass_lambda_us_lambda_bar_us->Integral();
    double counts_cut_inside_L0_L0bar_US_LS = h2_invMass_lambda_us_lambda_bar_ls->Integral();
    double counts_cut_inside_L0_L0_US_US = h2_invMass_lambda_us_lambda_us->Integral();
    double counts_cut_inside_L0_L0_US_LS = h2_invMass_lambda_us_lambda_ls->Integral();
    double counts_cut_inside_L0bar_L0bar_US_US = h2_invMass_lambda_bar_us_lambda_bar_us->Integral();
    double counts_cut_inside_L0bar_L0bar_US_LS = h2_invMass_lambda_bar_us_lambda_bar_ls->Integral();

    cout << "   " << endl;
    cout << "** Invariant Mass- Inside #DeltaR **" << endl; 
    cout << "Counts US-US L0-L0bar Inv. Mass Inside #DeltaR: " << counts_cut_inside_L0_L0bar_US_US << endl;
    cout << "Counts US-LS L0-L0bar Inv. Mass Inside #DeltaR: " << counts_cut_inside_L0_L0bar_US_LS << endl;
    cout << "Counts US-US L0-L0 Inv. Mass Inside #DeltaR: " << counts_cut_inside_L0_L0_US_US << endl;
    cout << "Counts US-LS L0-L0 Inv. Mass Inside #DeltaR: " << counts_cut_inside_L0_L0_US_LS << endl;
    cout << "Counts US-US L0bar-L0bar Inv. Mass Inside #DeltaR: " << counts_cut_inside_L0bar_L0bar_US_US << endl;
    cout << "Counts US-LS L0bar-L0bar Inv. Mass Inside #DeltaR: " << counts_cut_inside_L0bar_L0bar_US_LS << endl;

    std::unique_ptr<TCanvas> c12(new TCanvas("c12", "c12- Invariant Mass w/ Background, No Cuts (check)", 1800, 900));
    c12->Divide(3, 1);

    c12->cd(1);
    binMinX = h2_no_cut_invMass_lambda_us_lambda_bar_us->GetXaxis()->FindBin(minX);
    binMaxX = h2_no_cut_invMass_lambda_us_lambda_bar_us->GetXaxis()->FindBin(maxX);
    binMinY = h2_no_cut_invMass_lambda_us_lambda_bar_us->GetYaxis()->FindBin(minY);
    binMaxY = h2_no_cut_invMass_lambda_us_lambda_bar_us->GetYaxis()->FindBin(maxY);

    h2_no_cut_invMass_lambda_us_lambda_bar_us->GetXaxis()->SetRange(binMinX, binMaxX);
    h2_no_cut_invMass_lambda_us_lambda_bar_us->GetYaxis()->SetRange(binMinY, binMaxY);
    h2_no_cut_invMass_lambda_us_lambda_bar_us->Draw("SURF2");
    h2_no_cut_invMass_lambda_us_lambda_bar_us->SetTitle("Inv. Mass for #Lambda#bar{#Lambda} Pair (Check on The SE Pairs)");
    h2_no_cut_invMass_lambda_us_lambda_bar_ls->Draw("same");

    c12->cd(2);
    binMinX = h2_no_cut_invMass_lambda_us_lambda_us->GetXaxis()->FindBin(minX);
    binMaxX = h2_no_cut_invMass_lambda_us_lambda_us->GetXaxis()->FindBin(maxX);
    binMinY = h2_no_cut_invMass_lambda_us_lambda_us->GetYaxis()->FindBin(minY);
    binMaxY = h2_no_cut_invMass_lambda_us_lambda_us->GetYaxis()->FindBin(maxY);

    h2_no_cut_invMass_lambda_us_lambda_us->GetXaxis()->SetRange(binMinX, binMaxX);
    h2_no_cut_invMass_lambda_us_lambda_us->GetYaxis()->SetRange(binMinY, binMaxY);
    h2_no_cut_invMass_lambda_us_lambda_us->Draw("SURF2");
    h2_no_cut_invMass_lambda_us_lambda_us->SetTitle("Inv. Mass for #Lambda#Lambda Pair (Check on The SE Pairs)");
    h2_no_cut_invMass_lambda_us_lambda_ls->Draw("same");

    c12->cd(3);
    binMinX = h2_no_cut_invMass_lambda_bar_us_lambda_bar_us->GetXaxis()->FindBin(minX);
    binMaxX = h2_no_cut_invMass_lambda_bar_us_lambda_bar_us->GetXaxis()->FindBin(maxX);
    binMinY = h2_no_cut_invMass_lambda_bar_us_lambda_bar_us->GetYaxis()->FindBin(minY);
    binMaxY = h2_no_cut_invMass_lambda_bar_us_lambda_bar_us->GetYaxis()->FindBin(maxY);

    h2_no_cut_invMass_lambda_bar_us_lambda_bar_us->GetXaxis()->SetRange(binMinX, binMaxX);
    h2_no_cut_invMass_lambda_bar_us_lambda_bar_us->GetYaxis()->SetRange(binMinY, binMaxY);
    h2_no_cut_invMass_lambda_bar_us_lambda_bar_us->Draw("SURF2");
    h2_no_cut_invMass_lambda_bar_us_lambda_bar_us->SetTitle("Inv. Mass for #bar{#Lambda}#bar{#Lambda} Pair (Check on The SE Pairs)");
    h2_no_cut_invMass_lambda_bar_us_lambda_bar_ls->Draw("same");

    std::cout << "Canvas 12 Complete" << std::endl;

    std::unique_ptr<TCanvas> c13(new TCanvas("c13", "c13- Delta_R Histograms", 1800, 900));
    c13->Divide(3, 2);

    c13->cd(1);
    h_delta_R_US_US_llbar->Draw();
    h_delta_R_US_US_llbar->SetLineColor(kBlue);
    h_delta_R_US_US_llbar->SetTitle("#DeltaR for #Lambda#bar{#Lambda} Pairs");
    h_delta_R_US_LS_llbar->SetLineColor(kRed);
    h_delta_R_US_LS_llbar->Draw("same");

    TLegend *legend_delR_L0_L0bar = new TLegend(0.6, 0.7, 0.8, 0.8);
    legend_delR_L0_L0bar->SetTextSize(0.04);
    legend_delR_L0_L0bar->SetBorderSize(0);
    legend_delR_L0_L0bar->SetFillStyle(0); // Transparent background

    legend_delR_L0_L0bar->AddEntry(h_delta_R_US_US_llbar, "US-US #DeltaR", "lep");
    legend_delR_L0_L0bar->AddEntry(h_delta_R_US_LS_llbar, "US-LS #DeltaR", "lep");
    legend_delR_L0_L0bar->Draw();

    c13->cd(2);
    h_delta_R_US_US_ll->Draw();
    h_delta_R_US_US_ll->SetLineColor(kBlue);
    h_delta_R_US_US_ll->SetTitle("#DeltaR for #Lambda#Lambda Pairs");
    h_delta_R_US_LS_ll->Draw("same");
    h_delta_R_US_LS_ll->SetLineColor(kRed);

    TLegend *legend_delR_L0_L0 = new TLegend(0.6, 0.7, 0.8, 0.8);
    legend_delR_L0_L0->SetTextSize(0.04);
    legend_delR_L0_L0->SetBorderSize(0);
    legend_delR_L0_L0->SetFillStyle(0); // Transparent background

    legend_delR_L0_L0->AddEntry(h_delta_R_US_US_ll, "US-US #DeltaR", "lep");
    legend_delR_L0_L0->AddEntry(h_delta_R_US_LS_ll, "US-LS #DeltaR", "lep");
    legend_delR_L0_L0->Draw();

    c13->cd(3);
    h_delta_R_US_US_lbarlbar->Draw();
    h_delta_R_US_US_lbarlbar->SetLineColor(kBlue);
    h_delta_R_US_US_lbarlbar->SetTitle("#DeltaR for #bar{#Lambda}#bar{#Lambda} Pairs");
    h_delta_R_US_LS_lbarlbar->Draw("same");
    h_delta_R_US_LS_lbarlbar->SetLineColor(kRed);

    TLegend *legend_delR_L0bar_L0bar = new TLegend(0.6, 0.7, 0.8, 0.8);
    legend_delR_L0bar_L0bar->SetTextSize(0.04);
    legend_delR_L0bar_L0bar->SetBorderSize(0);
    legend_delR_L0bar_L0bar->SetFillStyle(0); // Transparent background

    legend_delR_L0bar_L0bar->AddEntry(h_delta_R_US_US_lbarlbar, "US-US #DeltaR", "lep");
    legend_delR_L0bar_L0bar->AddEntry(h_delta_R_US_LS_lbarlbar, "US-LS #DeltaR", "lep");
    legend_delR_L0bar_L0bar->Draw();

    c13->cd(4);
    h_delta_phi_US_US_llbar->SetMinimum(0);
    h_delta_phi_US_US_llbar->Draw();
    h_delta_phi_US_US_llbar->SetLineColor(kBlue);
    h_delta_phi_US_US_llbar->SetTitle("#Delta#phi for #Lambda#bar{#Lambda} Pairs");
    h_delta_phi_US_LS_llbar->Draw("same");
    h_delta_phi_US_LS_llbar->SetLineColor(kRed);

    TLegend *legend_delphi_L0_L0bar = new TLegend(0.65, 0.2, 0.85, 0.3);
    legend_delphi_L0_L0bar->SetTextSize(0.04);
    legend_delphi_L0_L0bar->SetBorderSize(0);
    legend_delphi_L0_L0bar->SetFillStyle(0); // Transparent background

    legend_delphi_L0_L0bar->AddEntry(h_delta_phi_US_US_llbar, "US-US #Delta#phi", "lep");
    legend_delphi_L0_L0bar->AddEntry(h_delta_phi_US_LS_llbar, "US-LS #Delta#phi", "lep");
    legend_delphi_L0_L0bar->Draw();

    c13->cd(5);
    h_delta_phi_US_US_ll->SetMinimum(0);
    h_delta_phi_US_US_ll->Draw();
    h_delta_phi_US_US_ll->SetLineColor(kBlue);
    h_delta_phi_US_US_ll->SetTitle("#Delta#phi for #Lambda#Lambda Pairs");
    h_delta_phi_US_LS_ll->Draw("same");
    h_delta_phi_US_LS_ll->SetLineColor(kRed);

    TLegend *legend_delphi_L0_L0 = new TLegend(0.65, 0.2, 0.85, 0.3);
    legend_delphi_L0_L0->SetTextSize(0.04);
    legend_delphi_L0_L0->SetBorderSize(0);
    legend_delphi_L0_L0->SetFillStyle(0); // Transparent background

    legend_delphi_L0_L0->AddEntry(h_delta_phi_US_US_ll, "US-US #Delta#phi", "lep");
    legend_delphi_L0_L0->AddEntry(h_delta_phi_US_LS_ll, "US-LS #Delta#phi", "lep");
    legend_delphi_L0_L0->Draw();

    c13->cd(6);
    h_delta_phi_US_US_lbarlbar->SetMinimum(0);
    h_delta_phi_US_US_lbarlbar->Draw();
    h_delta_phi_US_US_lbarlbar->SetLineColor(kBlue);
    h_delta_phi_US_US_lbarlbar->SetTitle("#Delta#phi for #bar{#Lambda}#bar{#Lambda} Pairs");
    h_delta_phi_US_LS_lbarlbar->Draw("same");
    h_delta_phi_US_LS_lbarlbar->SetLineColor(kRed);

    TLegend *legend_delphi_L0bar_L0bar = new TLegend(0.65, 0.2, 0.85, 0.3);
    legend_delphi_L0bar_L0bar->SetTextSize(0.04);
    legend_delphi_L0bar_L0bar->SetBorderSize(0);
    legend_delphi_L0bar_L0bar->SetFillStyle(0); // Transparent background

    legend_delphi_L0bar_L0bar->AddEntry(h_delta_phi_US_US_lbarlbar, "US-US #Delta#phi", "lep");
    legend_delphi_L0bar_L0bar->AddEntry(h_delta_phi_US_LS_lbarlbar, "US-LS #Delta#phi", "lep");
    legend_delphi_L0bar_L0bar->Draw();

    std::cout << "Canvas 13 Complete" << std::endl;

    double SE_outside_cos_theta_star3 = h_outside_cos_theta_star3->Integral();
    double SE_outside_cos_theta_star4 = h_outside_cos_theta_star4->Integral();
    double SE_outside_cos_theta_star = h_outside_cos_theta_star->Integral();
    double SE_outside_cos_theta_star2 = h_outside_cos_theta_star2->Integral();
    double SE_outside_cos_theta_star5 = h_outside_cos_theta_star5->Integral();
    double SE_outside_cos_theta_star6 = h_outside_cos_theta_star6->Integral();

    std::cout << "  " << std::endl;
    std::cout << "Counts in h_outside_cos_theta_star3: " << SE_outside_cos_theta_star3 << std::endl;
    std::cout << "Counts in h_outside_cos_theta_star4: " << SE_outside_cos_theta_star4 << std::endl;
    std::cout << "Counts in h_outside_cos_theta_star: " << SE_outside_cos_theta_star << std::endl;
    std::cout << "Counts in h_outside_cos_theta_star2: " << SE_outside_cos_theta_star2 << std::endl;
    std::cout << "Counts in h_outside_cos_theta_star5: " << SE_outside_cos_theta_star5 << std::endl;
    std::cout << "Counts in h_outside_cos_theta_star6: " << SE_outside_cos_theta_star6 << std::endl;
    std::cout << "  " << std::endl;

    double SE_cos_theta_star3 = h_cos_theta_star3->Integral();
    double SE_cos_theta_star4 = h_cos_theta_star4->Integral();
    double SE_cos_theta_star = h_cos_theta_star->Integral();
    double SE_cos_theta_star2 = h_cos_theta_star2->Integral();
    double SE_cos_theta_star5 = h_cos_theta_star5->Integral();
    double SE_cos_theta_star6 = h_cos_theta_star6->Integral();

    std::cout << "  " << std::endl;
    std::cout << "Counts in h_cos_theta_star3: " << SE_cos_theta_star3 << std::endl;
    std::cout << "Counts in h_cos_theta_star4: " << SE_cos_theta_star4 << std::endl;
    std::cout << "Counts in h_cos_theta_star: " << SE_cos_theta_star << std::endl;
    std::cout << "Counts in h_cos_theta_star2: " << SE_cos_theta_star2 << std::endl;
    std::cout << "Counts in h_cos_theta_star5: " << SE_cos_theta_star5 << std::endl;
    std::cout << "Counts in h_cos_theta_star6: " << SE_cos_theta_star6 << std::endl;
    std::cout << "  " << std::endl;

    std::unique_ptr<TCanvas> c14(new TCanvas("c14", "Canvas 14", 1800, 900));
    c14->Divide(3, 2);

    c14->cd(1);
    h2_no_cut_check_L0_L0bar_p1pt_p2pt_US_US->Draw("COLZ");
    h2_no_cut_check_L0_L0bar_p1pt_p2pt_US_US->SetTitle("Pt- US-US #Lambda#bar{#Lambda} Pairs (no cut check)");
    h2_no_cut_check_L0_L0bar_p1pt_p2pt_US_US->GetXaxis()->SetTitle("p1_pt [GeV/c]");
    h2_no_cut_check_L0_L0bar_p1pt_p2pt_US_US->GetXaxis()->CenterTitle(true);
    h2_no_cut_check_L0_L0bar_p1pt_p2pt_US_US->GetYaxis()->SetTitle("p2_pt [GeV/c]");
    h2_no_cut_check_L0_L0bar_p1pt_p2pt_US_US->GetYaxis()->CenterTitle(true);

    c14->cd(2);
    h2_no_cut_check_L0_L0bar_p1eta_p2eta_US_US->Draw("COLZ");
    h2_no_cut_check_L0_L0bar_p1eta_p2eta_US_US->SetTitle("Eta- US-US #Lambda#bar{#Lambda} paris (no cut check)");
    h2_no_cut_check_L0_L0bar_p1eta_p2eta_US_US->GetXaxis()->SetTitle("p1_eta");
    h2_no_cut_check_L0_L0bar_p1eta_p2eta_US_US->GetXaxis()->CenterTitle(true);
    h2_no_cut_check_L0_L0bar_p1eta_p2eta_US_US->GetYaxis()->SetTitle("p2_eta");
    h2_no_cut_check_L0_L0bar_p1eta_p2eta_US_US->GetYaxis()->CenterTitle(true);

    c14->cd(3);
    h2_no_cut_check_L0_L0bar_p1phi_p2phi_US_US->Draw("COLZ");
    h2_no_cut_check_L0_L0bar_p1phi_p2phi_US_US->SetTitle("Phi- US-US #Lambda#bar{#Lambda} pairs (no cut check)");
    h2_no_cut_check_L0_L0bar_p1phi_p2phi_US_US->GetXaxis()->SetTitle("p1_phi");
    h2_no_cut_check_L0_L0bar_p1phi_p2phi_US_US->GetXaxis()->CenterTitle(true);
    h2_no_cut_check_L0_L0bar_p1phi_p2phi_US_US->GetYaxis()->SetTitle("p2_phi");
    h2_no_cut_check_L0_L0bar_p1phi_p2phi_US_US->GetYaxis()->CenterTitle(true);

    c14->cd(4);
    h2_no_cut_check_L0_L0bar_p1pt_p2pt_US_LS->Draw("COLZ");
    h2_no_cut_check_L0_L0bar_p1pt_p2pt_US_LS->SetTitle("Pt- US-LS #Lambda#bar{#Lambda} Pairs (no cut check)");
    h2_no_cut_check_L0_L0bar_p1pt_p2pt_US_LS->GetXaxis()->SetTitle("p1_pt [GeV/c]");
    h2_no_cut_check_L0_L0bar_p1pt_p2pt_US_LS->GetXaxis()->CenterTitle(true);
    h2_no_cut_check_L0_L0bar_p1pt_p2pt_US_LS->GetYaxis()->SetTitle("p2_pt [GeV/c]");
    h2_no_cut_check_L0_L0bar_p1pt_p2pt_US_LS->GetYaxis()->CenterTitle(true);

    c14->cd(5);
    h2_no_cut_check_L0_L0bar_p1eta_p2eta_US_LS->Draw("COLZ");
    h2_no_cut_check_L0_L0bar_p1eta_p2eta_US_LS->SetTitle("Eta- US-LS #Lambda#bar{#Lambda} paris (no cut check)");
    h2_no_cut_check_L0_L0bar_p1eta_p2eta_US_LS->GetXaxis()->SetTitle("p1_eta");
    h2_no_cut_check_L0_L0bar_p1eta_p2eta_US_LS->GetXaxis()->CenterTitle(true);
    h2_no_cut_check_L0_L0bar_p1eta_p2eta_US_LS->GetYaxis()->SetTitle("p2_eta");
    h2_no_cut_check_L0_L0bar_p1eta_p2eta_US_LS->GetYaxis()->CenterTitle(true);

    c14->cd(6);
    h2_no_cut_check_L0_L0bar_p1phi_p2phi_US_LS->Draw("COLZ");
    h2_no_cut_check_L0_L0bar_p1phi_p2phi_US_LS->SetTitle("Phi- US-LS #Lambda#bar{#Lambda} pairs (no cut check)");
    h2_no_cut_check_L0_L0bar_p1phi_p2phi_US_LS->GetXaxis()->SetTitle("p1_phi");
    h2_no_cut_check_L0_L0bar_p1phi_p2phi_US_LS->GetXaxis()->CenterTitle(true);
    h2_no_cut_check_L0_L0bar_p1phi_p2phi_US_LS->GetYaxis()->SetTitle("p2_phi");
    h2_no_cut_check_L0_L0bar_p1phi_p2phi_US_LS->GetYaxis()->CenterTitle(true);

    std::cout << "Canvas 14 Complete" << std::endl;

    std::unique_ptr<TCanvas> c15(new TCanvas("c15", "Canvas 15", 1800, 900));
    c15->Divide(3, 2);

    c15->cd(1);
    h2_no_cut_check_L0_L0_p1pt_p2pt_US_US->Draw("COLZ");
    h2_no_cut_check_L0_L0_p1pt_p2pt_US_US->SetTitle("Pt- US-US #Lambda#Lambda Pairs (no cut check)");
    h2_no_cut_check_L0_L0_p1pt_p2pt_US_US->GetXaxis()->SetTitle("p1_pt [GeV/c]");
    h2_no_cut_check_L0_L0_p1pt_p2pt_US_US->GetXaxis()->CenterTitle(true);
    h2_no_cut_check_L0_L0_p1pt_p2pt_US_US->GetYaxis()->SetTitle("p2_pt [GeV/c]");
    h2_no_cut_check_L0_L0_p1pt_p2pt_US_US->GetYaxis()->CenterTitle(true);

    c15->cd(2);
    h2_no_cut_check_L0_L0_p1eta_p2eta_US_US->Draw("COLZ");
    h2_no_cut_check_L0_L0_p1eta_p2eta_US_US->SetTitle("Eta- US-US #Lambda#Lambda Pairs (no cut check)");
    h2_no_cut_check_L0_L0_p1eta_p2eta_US_US->GetXaxis()->SetTitle("p1_eta");
    h2_no_cut_check_L0_L0_p1eta_p2eta_US_US->GetXaxis()->CenterTitle(true);
    h2_no_cut_check_L0_L0_p1eta_p2eta_US_US->GetYaxis()->SetTitle("p2_eta");
    h2_no_cut_check_L0_L0_p1eta_p2eta_US_US->GetYaxis()->CenterTitle(true);

    c15->cd(3);
    h2_no_cut_check_L0_L0_p1phi_p2phi_US_US->Draw("COLZ");
    h2_no_cut_check_L0_L0_p1phi_p2phi_US_US->SetTitle("Phi- US-US #Lambda#Lambda Pairs (no cut check)");
    h2_no_cut_check_L0_L0_p1phi_p2phi_US_US->GetXaxis()->SetTitle("p1_phi");
    h2_no_cut_check_L0_L0_p1phi_p2phi_US_US->GetXaxis()->CenterTitle(true);
    h2_no_cut_check_L0_L0_p1phi_p2phi_US_US->GetYaxis()->SetTitle("p2_phi");
    h2_no_cut_check_L0_L0_p1phi_p2phi_US_US->GetYaxis()->CenterTitle(true);

    c15->cd(4);
    h2_no_cut_check_L0_L0_p1pt_p2pt_US_LS->Draw("COLZ");
    h2_no_cut_check_L0_L0_p1pt_p2pt_US_LS->SetTitle("Pt- US-LS #Lambda#Lambda Pairs (no cut check)");
    h2_no_cut_check_L0_L0_p1pt_p2pt_US_LS->GetXaxis()->SetTitle("p1_pt [GeV/c]");
    h2_no_cut_check_L0_L0_p1pt_p2pt_US_LS->GetXaxis()->CenterTitle(true);
    h2_no_cut_check_L0_L0_p1pt_p2pt_US_LS->GetYaxis()->SetTitle("p2_pt [GeV/c]");
    h2_no_cut_check_L0_L0_p1pt_p2pt_US_LS->GetYaxis()->CenterTitle(true);

    c15->cd(5);
    h2_no_cut_check_L0_L0_p1eta_p2eta_US_LS->Draw("COLZ");
    h2_no_cut_check_L0_L0_p1eta_p2eta_US_LS->SetTitle("Eta- US-LS #Lambda#Lambda Pairs (no cut check)");
    h2_no_cut_check_L0_L0_p1eta_p2eta_US_LS->GetXaxis()->SetTitle("p1_eta");
    h2_no_cut_check_L0_L0_p1eta_p2eta_US_LS->GetXaxis()->CenterTitle(true);
    h2_no_cut_check_L0_L0_p1eta_p2eta_US_LS->GetYaxis()->SetTitle("p2_eta");
    h2_no_cut_check_L0_L0_p1eta_p2eta_US_LS->GetYaxis()->CenterTitle(true);

    c15->cd(6);
    h2_no_cut_check_L0_L0_p1phi_p2phi_US_LS->Draw("COLZ");
    h2_no_cut_check_L0_L0_p1phi_p2phi_US_LS->SetTitle("Phi- US-LS #Lambda#Lambda Pairs (no cut check)");
    h2_no_cut_check_L0_L0_p1phi_p2phi_US_LS->GetXaxis()->SetTitle("p1_phi");
    h2_no_cut_check_L0_L0_p1phi_p2phi_US_LS->GetXaxis()->CenterTitle(true);
    h2_no_cut_check_L0_L0_p1phi_p2phi_US_LS->GetYaxis()->SetTitle("p2_phi");
    h2_no_cut_check_L0_L0_p1phi_p2phi_US_LS->GetYaxis()->CenterTitle(true);

    std::cout << "Canvas 15 Complete" << std::endl;

    std::unique_ptr<TCanvas> c16(new TCanvas("c16", "Canvas 16", 1800, 900));
    c16->Divide(3, 2);

    c16->cd(1);
    h2_no_cut_check_L0bar_L0bar_p1pt_p2pt_US_US->Draw("COLZ");
    h2_no_cut_check_L0bar_L0bar_p1pt_p2pt_US_US->SetTitle("Pt- US-US #bar{#Lambda}#bar{#Lambda} Pairs (no cut check)");
    h2_no_cut_check_L0bar_L0bar_p1pt_p2pt_US_US->GetXaxis()->SetTitle("p1_pt [GeV/c]");
    h2_no_cut_check_L0bar_L0bar_p1pt_p2pt_US_US->GetXaxis()->CenterTitle(true);
    h2_no_cut_check_L0bar_L0bar_p1pt_p2pt_US_US->GetYaxis()->SetTitle("p2_pt [GeV/c]");
    h2_no_cut_check_L0bar_L0bar_p1pt_p2pt_US_US->GetYaxis()->CenterTitle(true);

    c16->cd(2);
    h2_no_cut_check_L0bar_L0bar_p1eta_p2eta_US_US->Draw("COLZ");
    h2_no_cut_check_L0bar_L0bar_p1eta_p2eta_US_US->SetTitle("Eta- US-US #bar{#Lambda}#bar{#Lambda} paris (no cut check)");
    h2_no_cut_check_L0bar_L0bar_p1eta_p2eta_US_US->GetXaxis()->SetTitle("p1_eta");
    h2_no_cut_check_L0bar_L0bar_p1eta_p2eta_US_US->GetXaxis()->CenterTitle(true);
    h2_no_cut_check_L0bar_L0bar_p1eta_p2eta_US_US->GetYaxis()->SetTitle("p2_eta");
    h2_no_cut_check_L0bar_L0bar_p1eta_p2eta_US_US->GetYaxis()->CenterTitle(true);

    c16->cd(3);
    h2_no_cut_check_L0bar_L0bar_p1phi_p2phi_US_US->Draw("COLZ");
    h2_no_cut_check_L0bar_L0bar_p1phi_p2phi_US_US->SetTitle("Phi- US-US #bar{#Lambda}#bar{#Lambda} pairs (no cut check)");
    h2_no_cut_check_L0bar_L0bar_p1phi_p2phi_US_US->GetXaxis()->SetTitle("p1_phi");
    h2_no_cut_check_L0bar_L0bar_p1phi_p2phi_US_US->GetXaxis()->CenterTitle(true);
    h2_no_cut_check_L0bar_L0bar_p1phi_p2phi_US_US->GetYaxis()->SetTitle("p2_phi");
    h2_no_cut_check_L0bar_L0bar_p1phi_p2phi_US_US->GetYaxis()->CenterTitle(true);

    c16->cd(4);
    h2_no_cut_check_L0bar_L0bar_p1pt_p2pt_US_LS->Draw("COLZ");
    h2_no_cut_check_L0bar_L0bar_p1pt_p2pt_US_LS->SetTitle("Pt- US-LS #bar{#Lambda}#bar{#Lambda} Pairs (no cut check)");
    h2_no_cut_check_L0bar_L0bar_p1pt_p2pt_US_LS->GetXaxis()->SetTitle("p1_pt [GeV/c]");
    h2_no_cut_check_L0bar_L0bar_p1pt_p2pt_US_LS->GetXaxis()->CenterTitle(true);
    h2_no_cut_check_L0bar_L0bar_p1pt_p2pt_US_LS->GetYaxis()->SetTitle("p2_pt [GeV/c]");
    h2_no_cut_check_L0bar_L0bar_p1pt_p2pt_US_LS->GetYaxis()->CenterTitle(true);

    c16->cd(5);
    h2_no_cut_check_L0bar_L0bar_p1eta_p2eta_US_LS->Draw("COLZ");
    h2_no_cut_check_L0bar_L0bar_p1eta_p2eta_US_LS->SetTitle("Eta- US-LS #bar{#Lambda}#bar{#Lambda} paris (no cut check)");
    h2_no_cut_check_L0bar_L0bar_p1eta_p2eta_US_LS->GetXaxis()->SetTitle("p1_eta");
    h2_no_cut_check_L0bar_L0bar_p1eta_p2eta_US_LS->GetXaxis()->CenterTitle(true);
    h2_no_cut_check_L0bar_L0bar_p1eta_p2eta_US_LS->GetYaxis()->SetTitle("p2_eta");
    h2_no_cut_check_L0bar_L0bar_p1eta_p2eta_US_LS->GetYaxis()->CenterTitle(true);

    c16->cd(6);
    h2_no_cut_check_L0bar_L0bar_p1phi_p2phi_US_LS->Draw("COLZ");
    h2_no_cut_check_L0bar_L0bar_p1phi_p2phi_US_LS->SetTitle("Phi- US-LS #bar{#Lambda}#bar{#Lambda} pairs (no cut check)");
    h2_no_cut_check_L0bar_L0bar_p1phi_p2phi_US_LS->GetXaxis()->SetTitle("p1_phi");
    h2_no_cut_check_L0bar_L0bar_p1phi_p2phi_US_LS->GetXaxis()->CenterTitle(true);
    h2_no_cut_check_L0bar_L0bar_p1phi_p2phi_US_LS->GetYaxis()->SetTitle("p2_phi");
    h2_no_cut_check_L0bar_L0bar_p1phi_p2phi_US_LS->GetYaxis()->CenterTitle(true);

    std::cout << "Canvas 16 Complete" << std::endl;

    h_cos_theta_star3->Scale(1.0/h_cos_theta_star3->GetXaxis()->GetBinWidth(1));
    h_cos_theta_star4->Scale(1.0/h_cos_theta_star4->GetXaxis()->GetBinWidth(1));
    h_cos_theta_star->Scale(1.0/h_cos_theta_star->GetXaxis()->GetBinWidth(1));
    h_cos_theta_star2->Scale(1.0/h_cos_theta_star2->GetXaxis()->GetBinWidth(1));
    h_cos_theta_star5->Scale(1.0/h_cos_theta_star5->GetXaxis()->GetBinWidth(1));
    h_cos_theta_star6->Scale(1.0/h_cos_theta_star6->GetXaxis()->GetBinWidth(1));

    h_cos_theta_star3->Scale(1.0/1000);
    h_cos_theta_star4->Scale(1.0/1000);
    h_cos_theta_star->Scale(1.0/1000);
    h_cos_theta_star2->Scale(1.0/1000);
    h_cos_theta_star5->Scale(1.0/1000);
    h_cos_theta_star6->Scale(1.0/1000);

    h_outside_cos_theta_star3->Scale(1.0/h_outside_cos_theta_star3->GetXaxis()->GetBinWidth(1));
    h_outside_cos_theta_star4->Scale(1.0/h_outside_cos_theta_star4->GetXaxis()->GetBinWidth(1));
    h_outside_cos_theta_star->Scale(1.0/h_outside_cos_theta_star->GetXaxis()->GetBinWidth(1));
    h_outside_cos_theta_star2->Scale(1.0/h_outside_cos_theta_star2->GetXaxis()->GetBinWidth(1));
    h_outside_cos_theta_star5->Scale(1.0/h_outside_cos_theta_star5->GetXaxis()->GetBinWidth(1));
    h_outside_cos_theta_star6->Scale(1.0/h_outside_cos_theta_star6->GetXaxis()->GetBinWidth(1));

    h_cos_theta_star2->Scale(ridge_L0_L0_us_us/ ridge_L0_L0_us_ls);
    h_cos_theta_star4->Scale(ridge_L0_L0bar_us_us/ ridge_L0_L0bar_us_ls);
    h_cos_theta_star6->Scale(ridge_L0bar_L0bar_us_us/ ridge_L0bar_L0bar_us_ls);

    h_outside_cos_theta_star3->Scale(1.0/1000);
    h_outside_cos_theta_star4->Scale(1.0/1000);
    h_outside_cos_theta_star->Scale(1.0/1000);
    h_outside_cos_theta_star2->Scale(1.0/1000);
    h_outside_cos_theta_star5->Scale(1.0/1000);
    h_outside_cos_theta_star6->Scale(1.0/1000);

    double constant_value_L0_L0bar = 0.747 * (-0.757);
    double constant_value_L0_L0 = 0.747 * (0.747);
    double constant_value_L0bar_L0bar = (-0.757) * (-0.757);

    std::unique_ptr<TCanvas> c17(new TCanvas("c17", "Canvas 17", 1800, 900));
    c17->Divide(3, 2);

    c17->cd(1);
    h_cos_theta_star3->SetMinimum(0);
    h_cos_theta_star3->SetMarkerStyle(20);
    h_cos_theta_star3->SetMarkerColor(kBlue);
    h_cos_theta_star3->Draw("PE"); // Draw with error bars
    h_cos_theta_star3->SetTitle("Lambda - Lambda Bar Angular Correlation");
    h_cos_theta_star4->SetMarkerStyle(20);
    h_cos_theta_star4->SetLineColor(kRed);
    h_cos_theta_star4->SetMarkerColor(kRed);
    h_cos_theta_star4->Draw("same PE"); // Draw with error bars

    TF1 *fit_cos_theta_star13 = new TF1("fit_cos_theta_star13", "[0] * (1 + [1] * x)", -1, 1);
    fit_cos_theta_star13->SetParameters(1, 1);
    h_cos_theta_star3->Fit(fit_cos_theta_star13, "R0");

    double A3_signle_events = fit_cos_theta_star13->GetParameter(0);
    double B3_signle_events = fit_cos_theta_star13->GetParameter(1);
    cout << "Fit Parameters for Corrected Lambda - Lambda M_Inv Distribution:" << endl;
    cout << "A US-US LLBar Pairs: " << A3_signle_events << endl;
    cout << "B US-US LLBar Pairs: " << B3_signle_events << endl;

    TF1 *fit_cos_theta_star14 = new TF1("fit_cos_theta_star14", "[0] * (1 + [1] * x)", -1, 1);
    fit_cos_theta_star14->SetParameters(1, 1);
    h_cos_theta_star4->Fit(fit_cos_theta_star14, "R0");

    double A4_signle_events = fit_cos_theta_star14->GetParameter(0);
    double B4_signle_events = fit_cos_theta_star14->GetParameter(1);
    cout << "Fit Parameters for Corrected Lambda - Lambda M_Inv Distribution:" << endl;
    cout << "A US-LS LLBar Pairs: " << A4_signle_events << endl;
    cout << "B US-LS LLBar Pairs: " << B4_signle_events << endl;

    double P_ll_3 = B3_signle_events /= constant_value_L0_L0bar;
    std::cout << "Polarization (US-US LLbar): " << P_ll_3 << std::endl;

    double P_ll_4 = B4_signle_events /= constant_value_L0_L0bar;
    std::cout << "Polarization (US-LS LLbar): " << P_ll_4 << std::endl;

    fit_cos_theta_star13->Draw("same");
    fit_cos_theta_star13->SetLineColor(kBlack);
    fit_cos_theta_star14->Draw("same");
    fit_cos_theta_star14->SetLineColor(kBlack);

    c17->cd(2);
    h_cos_theta_star->SetMinimum(0);
    h_cos_theta_star->SetMarkerStyle(20);
    h_cos_theta_star->SetMarkerColor(kBlue);
    h_cos_theta_star->Draw("PE");
    h_cos_theta_star->SetTitle("Lambda - Lambda Angular Correlation");
    h_cos_theta_star2->SetLineColor(kRed);
    h_cos_theta_star2->SetMarkerStyle(20);
    h_cos_theta_star2->SetMarkerColor(kRed);
    h_cos_theta_star2->Draw("same PE");

    TF1 *fit_cos_theta_star11 = new TF1("fit_cos_theta_star11", "[0] * (1 + [1] * x)", -1, 1);
    fit_cos_theta_star11->SetParameters(1, 1);
    h_cos_theta_star->Fit(fit_cos_theta_star11, "R0");

    double A1_signle_events = fit_cos_theta_star11->GetParameter(0);
    double B1_signle_events = fit_cos_theta_star11->GetParameter(1);
    cout << "Fit Parameters for Corrected Lambda - Lambda M_Inv Distribution:" << endl;
    cout << "A US-US LL Pairs: " << A1_signle_events << endl;
    cout << "B US-US LL Pairs: " << B1_signle_events << endl;

    TF1 *fit_cos_theta_star12 = new TF1("fit_cos_theta_star12", "[0] * (1 + [1] * x)", -1, 1);
    fit_cos_theta_star12->SetParameters(1, 1);
    h_cos_theta_star2->Fit(fit_cos_theta_star12, "R0");

    double A2_signle_events = fit_cos_theta_star12->GetParameter(0);
    double B2_signle_events = fit_cos_theta_star12->GetParameter(1);
    cout << "Fit Parameters for Corrected Lambda - Lambda M_Inv Distribution:" << endl;
    cout << "A US-LS LL Pairs: " << A2_signle_events << endl;
    cout << "B US-LS LL Pairs: " << B2_signle_events << endl;

    double P_ll_1 = B1_signle_events /= constant_value_L0_L0;
    std::cout << "Polarization (US-US LL): " << P_ll_1 << std::endl;

    double P_ll_2 = B2_signle_events /= constant_value_L0_L0;
    std::cout << "Polarization (US-LS LL): " << P_ll_2 << std::endl;

    fit_cos_theta_star11->Draw("same");
    fit_cos_theta_star11->SetLineColor(kBlack);
    fit_cos_theta_star12->Draw("same");
    fit_cos_theta_star12->SetLineColor(kBlack);

    c17->cd(3);
    h_cos_theta_star5->SetMinimum(0);
    h_cos_theta_star5->SetMarkerStyle(20);
    h_cos_theta_star5->SetMarkerColor(kBlue);
    h_cos_theta_star5->Draw("PE"); // Draw with error bars
    h_cos_theta_star5->SetTitle("Lambda Bar - Lambda Bar Angular Correlation");
    h_cos_theta_star6->SetLineColor(kRed);
    h_cos_theta_star6->SetMarkerStyle(20);
    h_cos_theta_star6->SetMarkerColor(kRed);
    h_cos_theta_star6->Draw("same PE"); // Draw with error bars

    TF1 *fit_cos_theta_star15 = new TF1("fit_cos_theta_star15", "[0] * (1 + [1] * x)", -1, 1);
    fit_cos_theta_star15->SetParameters(1, 1);
    h_cos_theta_star5->Fit(fit_cos_theta_star15, "R0");

    double A5_signle_events = fit_cos_theta_star15->GetParameter(0);
    double B5_signle_events = fit_cos_theta_star15->GetParameter(1);
    cout << "Fit Parameters for Corrected Lambda - Lambda M_Inv Distribution:" << endl;
    cout << "A US-US LBarLBar Pairs: " << A5_signle_events << endl;
    cout << "B US-US LBarLBar Pairs: " << B5_signle_events << endl;

    TF1 *fit_cos_theta_star16 = new TF1("fit_cos_theta_star16", "[0] * (1 + [1] * x)", -1, 1);
    fit_cos_theta_star16->SetParameters(1, 1);
    h_cos_theta_star6->Fit(fit_cos_theta_star16, "R0");

    double A6_signle_events = fit_cos_theta_star16->GetParameter(0);
    double B6_signle_events = fit_cos_theta_star16->GetParameter(1);
    cout << "Fit Parameters for Corrected Lambda - Lambda M_Inv Distribution:" << endl;
    cout << "A US-LS LBarLBar Pairs: " << A6_signle_events << endl;
    cout << "B US-LS LBarLBar Pairs: " << B6_signle_events << endl;

    double P_ll_5 = B5_signle_events /= constant_value_L0bar_L0bar;
    std::cout << "Polarization (US-US LbarLbar): " << P_ll_5 << std::endl;

    double P_ll_6 = B6_signle_events /= constant_value_L0bar_L0bar;
    std::cout << "Polarization (US-LS LbarLbar): " << P_ll_6 << std::endl;

    fit_cos_theta_star15->Draw("same");
    fit_cos_theta_star15->SetLineColor(kBlack);
    fit_cos_theta_star16->Draw("same");
    fit_cos_theta_star16->SetLineColor(kBlack);

    c17->cd(4);
    h_outside_cos_theta_star3->SetMinimum(0);
    h_outside_cos_theta_star3->SetMarkerStyle(20);
    h_outside_cos_theta_star3->SetMarkerColor(kBlue);
    h_outside_cos_theta_star3->Draw("PE");
    h_outside_cos_theta_star3->SetTitle("Lambda - Lambda Angular Correlation");
    h_outside_cos_theta_star4->SetLineColor(kRed);
    h_outside_cos_theta_star4->SetMarkerStyle(20);
    h_outside_cos_theta_star4->SetMarkerColor(kRed);
    h_outside_cos_theta_star4->Draw("same PE");

    c17->cd(5);
    h_outside_cos_theta_star->SetMinimum(0);
    h_outside_cos_theta_star->SetMarkerStyle(20);
    h_outside_cos_theta_star->SetMarkerColor(kBlue);
    h_outside_cos_theta_star->Draw("PE");
    h_outside_cos_theta_star->SetTitle("Lambda - Lambda Angular Correlation");
    h_outside_cos_theta_star2->SetLineColor(kRed);
    h_outside_cos_theta_star2->SetMarkerStyle(20);
    h_outside_cos_theta_star2->SetMarkerColor(kRed);
    h_outside_cos_theta_star2->Draw("same PE");

    c17->cd(6);
    h_outside_cos_theta_star5->SetMinimum(0);
    h_outside_cos_theta_star5->SetMarkerStyle(20);
    h_outside_cos_theta_star5->SetMarkerColor(kBlue);
    h_outside_cos_theta_star5->Draw("PE");
    h_outside_cos_theta_star5->SetTitle("Lambda - Lambda Angular Correlation");
    h_outside_cos_theta_star6->SetLineColor(kRed);
    h_outside_cos_theta_star6->SetMarkerStyle(20);
    h_outside_cos_theta_star6->SetMarkerColor(kRed);
    h_outside_cos_theta_star6->Draw("same PE");

    std::cout << "canvas 17 complete" << std::endl;

    std::unique_ptr<TCanvas> c18(new TCanvas("c18", "Canvas 18", 1800, 900));
    c18->Divide(3, 2);

    c18->cd(1);
    h2_cut_L0_L0bar_p1pt_p2pt_US_US->Draw("COLZ");
    h2_cut_L0_L0bar_p1pt_p2pt_US_US->SetTitle("Pt- US-US #Lambda#bar{#Lambda} Pairs inside #DeltaR = 0.93");
    h2_cut_L0_L0bar_p1pt_p2pt_US_US->GetXaxis()->SetTitle("p1_pt [GeV/c]");
    h2_cut_L0_L0bar_p1pt_p2pt_US_US->GetXaxis()->CenterTitle(true);
    h2_cut_L0_L0bar_p1pt_p2pt_US_US->GetYaxis()->SetTitle("p2_pt [GeV/c]");
    h2_cut_L0_L0bar_p1pt_p2pt_US_US->GetYaxis()->CenterTitle(true);

    c18->cd(2);
    h2_cut_L0_L0bar_p1eta_p2eta_US_US->Draw("COLZ");
    h2_cut_L0_L0bar_p1eta_p2eta_US_US->SetTitle("Eta- US-US #Lambda#bar{#Lambda} inside #DeltaR = 0.93");
    h2_cut_L0_L0bar_p1eta_p2eta_US_US->GetXaxis()->SetTitle("p1_eta");
    h2_cut_L0_L0bar_p1eta_p2eta_US_US->GetXaxis()->CenterTitle(true);
    h2_cut_L0_L0bar_p1eta_p2eta_US_US->GetYaxis()->SetTitle("p2_eta");
    h2_cut_L0_L0bar_p1eta_p2eta_US_US->GetYaxis()->CenterTitle(true);

    c18->cd(3);
    h2_cut_L0_L0bar_p1phi_p2phi_US_US->Draw("COLZ");
    h2_cut_L0_L0bar_p1phi_p2phi_US_US->SetTitle("Phi- US-US #Lambda#bar{#Lambda} inside #DeltaR = 0.93");
    h2_cut_L0_L0bar_p1phi_p2phi_US_US->GetXaxis()->SetTitle("p1_phi");
    h2_cut_L0_L0bar_p1phi_p2phi_US_US->GetXaxis()->CenterTitle(true);
    h2_cut_L0_L0bar_p1phi_p2phi_US_US->GetYaxis()->SetTitle("p2_phi");
    h2_cut_L0_L0bar_p1phi_p2phi_US_US->GetYaxis()->CenterTitle(true);

    c18->cd(4);
    h2_cut_L0_L0bar_p1pt_p2pt_US_LS->Draw("COLZ");
    h2_cut_L0_L0bar_p1pt_p2pt_US_LS->SetTitle("Pt- US-LS #Lambda#bar{#Lambda} Pairs inside #DeltaR = 0.93");
    h2_cut_L0_L0bar_p1pt_p2pt_US_LS->GetXaxis()->SetTitle("p1_pt [GeV/c]");
    h2_cut_L0_L0bar_p1pt_p2pt_US_LS->GetXaxis()->CenterTitle(true);
    h2_cut_L0_L0bar_p1pt_p2pt_US_LS->GetYaxis()->SetTitle("p2_pt [GeV/c]");
    h2_cut_L0_L0bar_p1pt_p2pt_US_LS->GetYaxis()->CenterTitle(true);

    c18->cd(5);
    h2_cut_L0_L0bar_p1eta_p2eta_US_LS->Draw("COLZ");
    h2_cut_L0_L0bar_p1eta_p2eta_US_LS->SetTitle("Eta- US-LS #Lambda#bar{#Lambda} inside #DeltaR = 0.93");
    h2_cut_L0_L0bar_p1eta_p2eta_US_LS->GetXaxis()->SetTitle("p1_eta");
    h2_cut_L0_L0bar_p1eta_p2eta_US_LS->GetXaxis()->CenterTitle(true);
    h2_cut_L0_L0bar_p1eta_p2eta_US_LS->GetYaxis()->SetTitle("p2_eta");
    h2_cut_L0_L0bar_p1eta_p2eta_US_LS->GetYaxis()->CenterTitle(true);

    c18->cd(6);
    h2_cut_L0_L0bar_p1phi_p2phi_US_LS->Draw("COLZ");
    h2_cut_L0_L0bar_p1phi_p2phi_US_LS->SetTitle("Phi- US-LS #Lambda#bar{#Lambda} inside #DeltaR = 0.93");
    h2_cut_L0_L0bar_p1phi_p2phi_US_LS->GetXaxis()->SetTitle("p1_phi");
    h2_cut_L0_L0bar_p1phi_p2phi_US_LS->GetXaxis()->CenterTitle(true);
    h2_cut_L0_L0bar_p1phi_p2phi_US_LS->GetYaxis()->SetTitle("p2_phi");
    h2_cut_L0_L0bar_p1phi_p2phi_US_LS->GetYaxis()->CenterTitle(true);

    std::cout << "canvas 18 complete" << std::endl;

    std::unique_ptr<TCanvas> c19(new TCanvas("c19", "Canvas 19", 1800, 900));
    c19->Divide(3, 2);

    c19->cd(1);
    h2_cut_L0_L0_p1pt_p2pt_US_US->Draw("COLZ");
    h2_cut_L0_L0_p1pt_p2pt_US_US->SetTitle("Pt- US-US #Lambda#Lambda Pairs inside #DeltaR = 0.93");
    h2_cut_L0_L0_p1pt_p2pt_US_US->GetXaxis()->SetTitle("p1_pt [GeV/c]");
    h2_cut_L0_L0_p1pt_p2pt_US_US->GetXaxis()->CenterTitle(true);
    h2_cut_L0_L0_p1pt_p2pt_US_US->GetYaxis()->SetTitle("p2_pt [GeV/c]");
    h2_cut_L0_L0_p1pt_p2pt_US_US->GetYaxis()->CenterTitle(true);

    c19->cd(2);
    h2_cut_L0_L0_p1eta_p2eta_US_US->Draw("COLZ");
    h2_cut_L0_L0_p1eta_p2eta_US_US->SetTitle("Eta- US-US #Lambda#Lambda inside #DeltaR = 0.93");
    h2_cut_L0_L0_p1eta_p2eta_US_US->GetXaxis()->SetTitle("p1_eta");
    h2_cut_L0_L0_p1eta_p2eta_US_US->GetXaxis()->CenterTitle(true);
    h2_cut_L0_L0_p1eta_p2eta_US_US->GetYaxis()->SetTitle("p2_eta");
    h2_cut_L0_L0_p1eta_p2eta_US_US->GetYaxis()->CenterTitle(true);

    c19->cd(3);
    h2_cut_L0_L0_p1phi_p2phi_US_US->Draw("COLZ");
    h2_cut_L0_L0_p1phi_p2phi_US_US->SetTitle("Phi- US-US #Lambda#Lambda inside #DeltaR = 0.93");
    h2_cut_L0_L0_p1phi_p2phi_US_US->GetXaxis()->SetTitle("p1_phi");
    h2_cut_L0_L0_p1phi_p2phi_US_US->GetXaxis()->CenterTitle(true);
    h2_cut_L0_L0_p1phi_p2phi_US_US->GetYaxis()->SetTitle("p2_phi");
    h2_cut_L0_L0_p1phi_p2phi_US_US->GetYaxis()->CenterTitle(true);

    c19->cd(4);
    h2_cut_L0_L0_p1pt_p2pt_US_LS->Draw("COLZ");
    h2_cut_L0_L0_p1pt_p2pt_US_LS->SetTitle("Pt- US-LS #Lambda#Lambda Pairs inside #DeltaR = 0.93");
    h2_cut_L0_L0_p1pt_p2pt_US_LS->GetXaxis()->SetTitle("p1_pt [GeV/c]");
    h2_cut_L0_L0_p1pt_p2pt_US_LS->GetXaxis()->CenterTitle(true);
    h2_cut_L0_L0_p1pt_p2pt_US_LS->GetYaxis()->SetTitle("p2_pt [GeV/c]");
    h2_cut_L0_L0_p1pt_p2pt_US_LS->GetYaxis()->CenterTitle(true);

    c19->cd(5);
    h2_cut_L0_L0_p1eta_p2eta_US_LS->Draw("COLZ");
    h2_cut_L0_L0_p1eta_p2eta_US_LS->SetTitle("Eta- US-LS #Lambda#Lambda inside #DeltaR = 0.93");
    h2_cut_L0_L0_p1eta_p2eta_US_LS->GetXaxis()->SetTitle("p1_eta");
    h2_cut_L0_L0_p1eta_p2eta_US_LS->GetXaxis()->CenterTitle(true);
    h2_cut_L0_L0_p1eta_p2eta_US_LS->GetYaxis()->SetTitle("p2_eta");
    h2_cut_L0_L0_p1eta_p2eta_US_LS->GetYaxis()->CenterTitle(true);

    c19->cd(6);
    h2_cut_L0_L0_p1phi_p2phi_US_LS->Draw("COLZ");
    h2_cut_L0_L0_p1phi_p2phi_US_LS->SetTitle("Phi- US-LS #Lambda#Lambda inside #DeltaR = 0.93");
    h2_cut_L0_L0_p1phi_p2phi_US_LS->GetXaxis()->SetTitle("p1_phi");
    h2_cut_L0_L0_p1phi_p2phi_US_LS->GetXaxis()->CenterTitle(true);
    h2_cut_L0_L0_p1phi_p2phi_US_LS->GetYaxis()->SetTitle("p2_phi");
    h2_cut_L0_L0_p1phi_p2phi_US_LS->GetYaxis()->CenterTitle(true);

    std::cout << "canvas 19 complete" << std::endl;

    std::unique_ptr<TCanvas> c20(new TCanvas("c20", "Canvas 20", 1800, 900));
    c20->Divide(3, 2);

    c20->cd(1);
    h2_cut_L0bar_L0bar_p1pt_p2pt_US_US->Draw("COLZ");
    h2_cut_L0bar_L0bar_p1pt_p2pt_US_US->SetTitle("Pt- US-US #bar{#Lambda}#bar{#Lambda} Pairs inside #DeltaR = 0.93");
    h2_cut_L0bar_L0bar_p1pt_p2pt_US_US->GetXaxis()->SetTitle("p1_pt [GeV/c]");
    h2_cut_L0bar_L0bar_p1pt_p2pt_US_US->GetXaxis()->CenterTitle(true);
    h2_cut_L0bar_L0bar_p1pt_p2pt_US_US->GetYaxis()->SetTitle("p2_pt [GeV/c]");
    h2_cut_L0bar_L0bar_p1pt_p2pt_US_US->GetYaxis()->CenterTitle(true);

    c20->cd(2);
    h2_cut_L0bar_L0bar_p1eta_p2eta_US_US->Draw("COLZ");
    h2_cut_L0bar_L0bar_p1eta_p2eta_US_US->SetTitle("Eta- US-US #bar{#Lambda}#bar{#Lambda} inside #DeltaR = 0.93");
    h2_cut_L0bar_L0bar_p1eta_p2eta_US_US->GetXaxis()->SetTitle("p1_eta");
    h2_cut_L0bar_L0bar_p1eta_p2eta_US_US->GetXaxis()->CenterTitle(true);
    h2_cut_L0bar_L0bar_p1eta_p2eta_US_US->GetYaxis()->SetTitle("p2_eta");
    h2_cut_L0bar_L0bar_p1eta_p2eta_US_US->GetYaxis()->CenterTitle(true);

    c20->cd(3);
    h2_cut_L0bar_L0bar_p1phi_p2phi_US_US->Draw("COLZ");
    h2_cut_L0bar_L0bar_p1phi_p2phi_US_US->SetTitle("Phi- US-US #bar{#Lambda}#bar{#Lambda} inside #DeltaR = 0.93");
    h2_cut_L0bar_L0bar_p1phi_p2phi_US_US->GetXaxis()->SetTitle("p1_phi");
    h2_cut_L0bar_L0bar_p1phi_p2phi_US_US->GetXaxis()->CenterTitle(true);
    h2_cut_L0bar_L0bar_p1phi_p2phi_US_US->GetYaxis()->SetTitle("p2_phi");
    h2_cut_L0bar_L0bar_p1phi_p2phi_US_US->GetYaxis()->CenterTitle(true);

    c20->cd(4);
    h2_cut_L0bar_L0bar_p1pt_p2pt_US_LS->Draw("COLZ");
    h2_cut_L0bar_L0bar_p1pt_p2pt_US_LS->SetTitle("Pt- US-LS #bar{#Lambda}#bar{#Lambda} Pairs inside #DeltaR = 0.93");
    h2_cut_L0bar_L0bar_p1pt_p2pt_US_LS->GetXaxis()->SetTitle("p1_pt [GeV/c]");
    h2_cut_L0bar_L0bar_p1pt_p2pt_US_LS->GetXaxis()->CenterTitle(true);
    h2_cut_L0bar_L0bar_p1pt_p2pt_US_LS->GetYaxis()->SetTitle("p2_pt [GeV/c]");
    h2_cut_L0bar_L0bar_p1pt_p2pt_US_LS->GetYaxis()->CenterTitle(true);

    c20->cd(5);
    h2_cut_L0bar_L0bar_p1eta_p2eta_US_LS->Draw("COLZ");
    h2_cut_L0bar_L0bar_p1eta_p2eta_US_LS->SetTitle("Eta- US-LS #bar{#Lambda}#bar{#Lambda} inside #DeltaR = 0.93");
    h2_cut_L0bar_L0bar_p1eta_p2eta_US_LS->GetXaxis()->SetTitle("p1_eta");
    h2_cut_L0bar_L0bar_p1eta_p2eta_US_LS->GetXaxis()->CenterTitle(true);
    h2_cut_L0bar_L0bar_p1eta_p2eta_US_LS->GetYaxis()->SetTitle("p2_eta");
    h2_cut_L0bar_L0bar_p1eta_p2eta_US_LS->GetYaxis()->CenterTitle(true);

    c20->cd(6);
    h2_cut_L0bar_L0bar_p1phi_p2phi_US_LS->Draw("COLZ");
    h2_cut_L0bar_L0bar_p1phi_p2phi_US_LS->SetTitle("Phi- US-LS #bar{#Lambda}#bar{#Lambda} inside #DeltaR = 0.93");
    h2_cut_L0bar_L0bar_p1phi_p2phi_US_LS->GetXaxis()->SetTitle("p1_phi");
    h2_cut_L0bar_L0bar_p1phi_p2phi_US_LS->GetXaxis()->CenterTitle(true);
    h2_cut_L0bar_L0bar_p1phi_p2phi_US_LS->GetYaxis()->SetTitle("p2_phi");
    h2_cut_L0bar_L0bar_p1phi_p2phi_US_LS->GetYaxis()->CenterTitle(true);

    std::cout << "canvas 20 complete" << std::endl;

    std::unique_ptr<TCanvas> c21(new TCanvas("c21", "Canvas 21", 1800, 900));
    c21->Divide(3, 2);

    c21->cd(1);
    h2_cut_outside_L0_L0bar_p1pt_p2pt_US_US->Draw("COLZ");
    h2_cut_outside_L0_L0bar_p1pt_p2pt_US_US->SetTitle("Pt- US-US #Lambda#bar{#Lambda} Pairs outside #DeltaR = 0.93");
    h2_cut_outside_L0_L0bar_p1pt_p2pt_US_US->GetXaxis()->SetTitle("p1_pt [GeV/c]");
    h2_cut_outside_L0_L0bar_p1pt_p2pt_US_US->GetXaxis()->CenterTitle(true);
    h2_cut_outside_L0_L0bar_p1pt_p2pt_US_US->GetYaxis()->SetTitle("p2_pt [GeV/c]");
    h2_cut_outside_L0_L0bar_p1pt_p2pt_US_US->GetYaxis()->CenterTitle(true);

    c21->cd(2);
    h2_cut_outside_L0_L0bar_p1eta_p2eta_US_US->Draw("COLZ");
    h2_cut_outside_L0_L0bar_p1eta_p2eta_US_US->SetTitle("Eta- US-US #Lambda#bar{#Lambda} outside #DeltaR = 0.93");
    h2_cut_outside_L0_L0bar_p1eta_p2eta_US_US->GetXaxis()->SetTitle("p1_eta");
    h2_cut_outside_L0_L0bar_p1eta_p2eta_US_US->GetXaxis()->CenterTitle(true);
    h2_cut_outside_L0_L0bar_p1eta_p2eta_US_US->GetYaxis()->SetTitle("p2_eta");
    h2_cut_outside_L0_L0bar_p1eta_p2eta_US_US->GetYaxis()->CenterTitle(true);

    c21->cd(3);
    h2_cut_outside_L0_L0bar_p1phi_p2phi_US_US->Draw("COLZ");
    h2_cut_outside_L0_L0bar_p1phi_p2phi_US_US->SetTitle("Phi- US-US #Lambda#bar{#Lambda} outside #DeltaR = 0.93");
    h2_cut_outside_L0_L0bar_p1phi_p2phi_US_US->GetXaxis()->SetTitle("p1_phi");
    h2_cut_outside_L0_L0bar_p1phi_p2phi_US_US->GetXaxis()->CenterTitle(true);
    h2_cut_outside_L0_L0bar_p1phi_p2phi_US_US->GetYaxis()->SetTitle("p2_phi");
    h2_cut_outside_L0_L0bar_p1phi_p2phi_US_US->GetYaxis()->CenterTitle(true);

    c21->cd(4);
    h2_cut_outside_L0_L0bar_p1pt_p2pt_US_LS->Draw("COLZ");
    h2_cut_outside_L0_L0bar_p1pt_p2pt_US_LS->SetTitle("Pt- US-LS #Lambda#bar{#Lambda} Pairs outside #DeltaR = 0.93");
    h2_cut_outside_L0_L0bar_p1pt_p2pt_US_LS->GetXaxis()->SetTitle("p1_pt [GeV/c]");
    h2_cut_outside_L0_L0bar_p1pt_p2pt_US_LS->GetXaxis()->CenterTitle(true);
    h2_cut_outside_L0_L0bar_p1pt_p2pt_US_LS->GetYaxis()->SetTitle("p2_pt [GeV/c]");
    h2_cut_outside_L0_L0bar_p1pt_p2pt_US_LS->GetYaxis()->CenterTitle(true);

    c21->cd(5);
    h2_cut_outside_L0_L0bar_p1eta_p2eta_US_LS->Draw("COLZ");
    h2_cut_outside_L0_L0bar_p1eta_p2eta_US_LS->SetTitle("Eta- US-LS #Lambda#bar{#Lambda} outside #DeltaR = 0.93");
    h2_cut_outside_L0_L0bar_p1eta_p2eta_US_LS->GetXaxis()->SetTitle("p1_eta");
    h2_cut_outside_L0_L0bar_p1eta_p2eta_US_LS->GetXaxis()->CenterTitle(true);
    h2_cut_outside_L0_L0bar_p1eta_p2eta_US_LS->GetYaxis()->SetTitle("p2_eta");
    h2_cut_outside_L0_L0bar_p1eta_p2eta_US_LS->GetYaxis()->CenterTitle(true);

    c21->cd(6);
    h2_cut_outside_L0_L0bar_p1phi_p2phi_US_LS->Draw("COLZ");
    h2_cut_outside_L0_L0bar_p1phi_p2phi_US_LS->SetTitle("Phi- US-LS #Lambda#bar{#Lambda} outside #DeltaR = 0.93");
    h2_cut_outside_L0_L0bar_p1phi_p2phi_US_LS->GetXaxis()->SetTitle("p1_phi");
    h2_cut_outside_L0_L0bar_p1phi_p2phi_US_LS->GetXaxis()->CenterTitle(true);
    h2_cut_outside_L0_L0bar_p1phi_p2phi_US_LS->GetYaxis()->SetTitle("p2_phi");
    h2_cut_outside_L0_L0bar_p1phi_p2phi_US_LS->GetYaxis()->CenterTitle(true);

    std::cout << "canvas 21 complete" << std::endl;

    std::unique_ptr<TCanvas> c22(new TCanvas("c22", "Canvas 22", 1800, 900));
    c22->Divide(3, 2);

    c22->cd(1);
    h2_cut_outside_L0_L0_p1pt_p2pt_US_US->Draw("COLZ");
    h2_cut_outside_L0_L0_p1pt_p2pt_US_US->SetTitle("Pt- US-US #Lambda#Lambda Pairs outside #DeltaR = 0.93");
    h2_cut_outside_L0_L0_p1pt_p2pt_US_US->GetXaxis()->SetTitle("p1_pt [GeV/c]");
    h2_cut_outside_L0_L0_p1pt_p2pt_US_US->GetXaxis()->CenterTitle(true);
    h2_cut_outside_L0_L0_p1pt_p2pt_US_US->GetYaxis()->SetTitle("p2_pt [GeV/c]");
    h2_cut_outside_L0_L0_p1pt_p2pt_US_US->GetYaxis()->CenterTitle(true);

    c22->cd(2);
    h2_cut_outside_L0_L0_p1eta_p2eta_US_US->Draw("COLZ");
    h2_cut_outside_L0_L0_p1eta_p2eta_US_US->SetTitle("Eta- US-US #Lambda#Lambda outside #DeltaR = 0.93");
    h2_cut_outside_L0_L0_p1eta_p2eta_US_US->GetXaxis()->SetTitle("p1_eta");
    h2_cut_outside_L0_L0_p1eta_p2eta_US_US->GetXaxis()->CenterTitle(true);
    h2_cut_outside_L0_L0_p1eta_p2eta_US_US->GetYaxis()->SetTitle("p2_eta");
    h2_cut_outside_L0_L0_p1eta_p2eta_US_US->GetYaxis()->CenterTitle(true);

    c22->cd(3);
    h2_cut_outside_L0_L0_p1phi_p2phi_US_US->Draw("COLZ");
    h2_cut_outside_L0_L0_p1phi_p2phi_US_US->SetTitle("Phi- US-US #Lambda#Lambda outside #DeltaR = 0.93");
    h2_cut_outside_L0_L0_p1phi_p2phi_US_US->GetXaxis()->SetTitle("p1_phi");
    h2_cut_outside_L0_L0_p1phi_p2phi_US_US->GetXaxis()->CenterTitle(true);
    h2_cut_outside_L0_L0_p1phi_p2phi_US_US->GetYaxis()->SetTitle("p2_phi");
    h2_cut_outside_L0_L0_p1phi_p2phi_US_US->GetYaxis()->CenterTitle(true);

    c22->cd(4);
    h2_cut_outside_L0_L0_p1pt_p2pt_US_LS->Draw("COLZ");
    h2_cut_outside_L0_L0_p1pt_p2pt_US_LS->SetTitle("Pt- US-LS #Lambda#Lambda Pairs outside #DeltaR = 0.93");
    h2_cut_outside_L0_L0_p1pt_p2pt_US_LS->GetXaxis()->SetTitle("p1_pt [GeV/c]");
    h2_cut_outside_L0_L0_p1pt_p2pt_US_LS->GetXaxis()->CenterTitle(true);
    h2_cut_outside_L0_L0_p1pt_p2pt_US_LS->GetYaxis()->SetTitle("p2_pt [GeV/c]");
    h2_cut_outside_L0_L0_p1pt_p2pt_US_LS->GetYaxis()->CenterTitle(true);

    c22->cd(5);
    h2_cut_outside_L0_L0_p1eta_p2eta_US_LS->Draw("COLZ");
    h2_cut_outside_L0_L0_p1eta_p2eta_US_LS->SetTitle("Eta- US-LS #Lambda#Lambda outside #DeltaR = 0.93");
    h2_cut_outside_L0_L0_p1eta_p2eta_US_LS->GetXaxis()->SetTitle("p1_eta");
    h2_cut_outside_L0_L0_p1eta_p2eta_US_LS->GetXaxis()->CenterTitle(true);
    h2_cut_outside_L0_L0_p1eta_p2eta_US_LS->GetYaxis()->SetTitle("p2_eta");
    h2_cut_outside_L0_L0_p1eta_p2eta_US_LS->GetYaxis()->CenterTitle(true);

    c22->cd(6);
    h2_cut_outside_L0_L0_p1phi_p2phi_US_LS->Draw("COLZ");
    h2_cut_outside_L0_L0_p1phi_p2phi_US_LS->SetTitle("Phi- US-LS #Lambda#Lambda outside #DeltaR = 0.93");
    h2_cut_outside_L0_L0_p1phi_p2phi_US_LS->GetXaxis()->SetTitle("p1_phi");
    h2_cut_outside_L0_L0_p1phi_p2phi_US_LS->GetXaxis()->CenterTitle(true);
    h2_cut_outside_L0_L0_p1phi_p2phi_US_LS->GetYaxis()->SetTitle("p2_phi");
    h2_cut_outside_L0_L0_p1phi_p2phi_US_LS->GetYaxis()->CenterTitle(true);

    std::cout << "canvas 22 complete" << std::endl;

    std::unique_ptr<TCanvas> c23(new TCanvas("c23", "Canvas 23", 1800, 900));
    c23->Divide(3, 2);

    c23->cd(1);
    h2_cut_outside_L0bar_L0bar_p1pt_p2pt_US_US->Draw("COLZ");
    h2_cut_outside_L0bar_L0bar_p1pt_p2pt_US_US->SetTitle("Pt- US-US #bar{#Lambda}#bar{#Lambda} Pairs outside #DeltaR = 0.93");
    h2_cut_outside_L0bar_L0bar_p1pt_p2pt_US_US->GetXaxis()->SetTitle("p1_pt [GeV/c]");
    h2_cut_outside_L0bar_L0bar_p1pt_p2pt_US_US->GetXaxis()->CenterTitle(true);
    h2_cut_outside_L0bar_L0bar_p1pt_p2pt_US_US->GetYaxis()->SetTitle("p2_pt [GeV/c]");
    h2_cut_outside_L0bar_L0bar_p1pt_p2pt_US_US->GetYaxis()->CenterTitle(true);

    c23->cd(2);
    h2_cut_outside_L0bar_L0bar_p1eta_p2eta_US_US->Draw("COLZ");
    h2_cut_outside_L0bar_L0bar_p1eta_p2eta_US_US->SetTitle("Eta- US-US #bar{#Lambda}#bar{#Lambda} outside #DeltaR = 0.93");
    h2_cut_outside_L0bar_L0bar_p1eta_p2eta_US_US->GetXaxis()->SetTitle("p1_eta");
    h2_cut_outside_L0bar_L0bar_p1eta_p2eta_US_US->GetXaxis()->CenterTitle(true);
    h2_cut_outside_L0bar_L0bar_p1eta_p2eta_US_US->GetYaxis()->SetTitle("p2_eta");
    h2_cut_outside_L0bar_L0bar_p1eta_p2eta_US_US->GetYaxis()->CenterTitle(true);

    c23->cd(3);
    h2_cut_outside_L0bar_L0bar_p1phi_p2phi_US_US->Draw("COLZ");
    h2_cut_outside_L0bar_L0bar_p1phi_p2phi_US_US->SetTitle("Phi- US-US #bar{#Lambda}#bar{#Lambda} outside #DeltaR = 0.93");
    h2_cut_outside_L0bar_L0bar_p1phi_p2phi_US_US->GetXaxis()->SetTitle("p1_phi");
    h2_cut_outside_L0bar_L0bar_p1phi_p2phi_US_US->GetXaxis()->CenterTitle(true);
    h2_cut_outside_L0bar_L0bar_p1phi_p2phi_US_US->GetYaxis()->SetTitle("p2_phi");
    h2_cut_outside_L0bar_L0bar_p1phi_p2phi_US_US->GetYaxis()->CenterTitle(true);

    c23->cd(4);
    h2_cut_outside_L0bar_L0bar_p1pt_p2pt_US_LS->Draw("COLZ");
    h2_cut_outside_L0bar_L0bar_p1pt_p2pt_US_LS->SetTitle("Pt- US-LS #bar{#Lambda}#bar{#Lambda} Pairs outside #DeltaR = 0.93");
    h2_cut_outside_L0bar_L0bar_p1pt_p2pt_US_LS->GetXaxis()->SetTitle("p1_pt [GeV/c]");
    h2_cut_outside_L0bar_L0bar_p1pt_p2pt_US_LS->GetXaxis()->CenterTitle(true);
    h2_cut_outside_L0bar_L0bar_p1pt_p2pt_US_LS->GetYaxis()->SetTitle("p2_pt [GeV/c]");
    h2_cut_outside_L0bar_L0bar_p1pt_p2pt_US_LS->GetYaxis()->CenterTitle(true);

    c23->cd(5);
    h2_cut_outside_L0bar_L0bar_p1eta_p2eta_US_LS->Draw("COLZ");
    h2_cut_outside_L0bar_L0bar_p1eta_p2eta_US_LS->SetTitle("Eta- US-LS #bar{#Lambda}#bar{#Lambda} outside #DeltaR = 0.93");
    h2_cut_outside_L0bar_L0bar_p1eta_p2eta_US_LS->GetXaxis()->SetTitle("p1_eta");
    h2_cut_outside_L0bar_L0bar_p1eta_p2eta_US_LS->GetXaxis()->CenterTitle(true);
    h2_cut_outside_L0bar_L0bar_p1eta_p2eta_US_LS->GetYaxis()->SetTitle("p2_eta");
    h2_cut_outside_L0bar_L0bar_p1eta_p2eta_US_LS->GetYaxis()->CenterTitle(true);

    c23->cd(6);
    h2_cut_outside_L0bar_L0bar_p1phi_p2phi_US_LS->Draw("COLZ");
    h2_cut_outside_L0bar_L0bar_p1phi_p2phi_US_LS->SetTitle("Phi- US-LS #bar{#Lambda}#bar{#Lambda} outside #DeltaR = 0.93");
    h2_cut_outside_L0bar_L0bar_p1phi_p2phi_US_LS->GetXaxis()->SetTitle("p1_phi");
    h2_cut_outside_L0bar_L0bar_p1phi_p2phi_US_LS->GetXaxis()->CenterTitle(true);
    h2_cut_outside_L0bar_L0bar_p1phi_p2phi_US_LS->GetYaxis()->SetTitle("p2_phi");
    h2_cut_outside_L0bar_L0bar_p1phi_p2phi_US_LS->GetYaxis()->CenterTitle(true);

    std::cout << "canvas 23 complete" << std::endl;

    std::unique_ptr<TCanvas> c24(new TCanvas("c24", "Canvas 24", 1800, 900));
    c24->Divide(3, 2);

    TH2F *h2_recombined_L0_L0bar_p1pt_p2pt_US_US = new TH2F(*h2_cut_L0_L0bar_p1pt_p2pt_US_US);
    h2_recombined_L0_L0bar_p1pt_p2pt_US_US->Add(h2_cut_outside_L0_L0bar_p1pt_p2pt_US_US, 1.0);

    TH2F *h2_recombined_L0_L0bar_p1eta_p2eta_US_US = new TH2F(*h2_cut_L0_L0bar_p1eta_p2eta_US_US);
    h2_recombined_L0_L0bar_p1eta_p2eta_US_US->Add(h2_cut_outside_L0_L0bar_p1eta_p2eta_US_US, 1.0);

    TH2F *h2_recombined_L0_L0bar_p1phi_p2phi_US_US = new TH2F(*h2_cut_L0_L0bar_p1phi_p2phi_US_US);
    h2_recombined_L0_L0bar_p1phi_p2phi_US_US->Add(h2_cut_outside_L0_L0bar_p1phi_p2phi_US_US, 1.0);

    TH2F *h2_recombined_L0_L0bar_p1pt_p2pt_US_LS = new TH2F(*h2_cut_L0_L0bar_p1pt_p2pt_US_LS);
    h2_recombined_L0_L0bar_p1pt_p2pt_US_LS->Add(h2_cut_outside_L0_L0bar_p1pt_p2pt_US_LS, 1.0);

    TH2F *h2_recombined_L0_L0bar_p1eta_p2eta_US_LS = new TH2F(*h2_cut_L0_L0bar_p1eta_p2eta_US_LS);
    h2_recombined_L0_L0bar_p1eta_p2eta_US_LS->Add(h2_cut_outside_L0_L0bar_p1eta_p2eta_US_LS, 1.0);

    TH2F *h2_recombined_L0_L0bar_p1phi_p2phi_US_LS = new TH2F(*h2_cut_L0_L0bar_p1phi_p2phi_US_LS);
    h2_recombined_L0_L0bar_p1phi_p2phi_US_LS->Add(h2_cut_outside_L0_L0bar_p1phi_p2phi_US_LS, 1.0);

    c24->cd(1);
    h2_recombined_L0_L0bar_p1pt_p2pt_US_US->Draw("COLZ");
    h2_recombined_L0_L0bar_p1pt_p2pt_US_US->SetTitle("Pt- US-US #Lambda#bar{#Lambda} Pairs inside and outside #DeltaR = 0.93");
    h2_recombined_L0_L0bar_p1pt_p2pt_US_US->GetXaxis()->SetTitle("p1_pt [GeV/c]");
    h2_recombined_L0_L0bar_p1pt_p2pt_US_US->GetXaxis()->CenterTitle(true);
    h2_recombined_L0_L0bar_p1pt_p2pt_US_US->GetYaxis()->SetTitle("p2_pt [GeV/c]");
    h2_recombined_L0_L0bar_p1pt_p2pt_US_US->GetYaxis()->CenterTitle(true);

    c24->cd(2);
    h2_recombined_L0_L0bar_p1eta_p2eta_US_US->Draw("COLZ");
    h2_recombined_L0_L0bar_p1eta_p2eta_US_US->SetTitle("Eta- US-US #Lambda#bar{#Lambda} Pairs inside and outside #DeltaR = 0.93");
    h2_recombined_L0_L0bar_p1eta_p2eta_US_US->GetXaxis()->SetTitle("p1_eta");
    h2_recombined_L0_L0bar_p1eta_p2eta_US_US->GetXaxis()->CenterTitle(true);
    h2_recombined_L0_L0bar_p1eta_p2eta_US_US->GetYaxis()->SetTitle("p2_eta");
    h2_recombined_L0_L0bar_p1eta_p2eta_US_US->GetXaxis()->CenterTitle(true);

    c24->cd(3);
    h2_recombined_L0_L0bar_p1phi_p2phi_US_US->Draw("COLZ");
    h2_recombined_L0_L0bar_p1phi_p2phi_US_US->SetTitle("Phi- US-US #Lambda#bar{#Lambda} Pairs inside and outside #DeltaR = 0.93");
    h2_recombined_L0_L0bar_p1phi_p2phi_US_US->GetXaxis()->SetTitle("p1_phi");
    h2_recombined_L0_L0bar_p1phi_p2phi_US_US->GetXaxis()->CenterTitle(true);
    h2_recombined_L0_L0bar_p1phi_p2phi_US_US->GetYaxis()->SetTitle("p2_phi");
    h2_recombined_L0_L0bar_p1phi_p2phi_US_US->GetXaxis()->CenterTitle(true);

    c24->cd(4);
    h2_recombined_L0_L0bar_p1pt_p2pt_US_LS->Draw("COLZ");
    h2_recombined_L0_L0bar_p1pt_p2pt_US_LS->SetTitle("Pt- US-LS #Lambda#bar{#Lambda} Pairs inside and outside #DeltaR = 0.93");
    h2_recombined_L0_L0bar_p1pt_p2pt_US_LS->GetXaxis()->SetTitle("p1_pt [GeV/c]");
    h2_recombined_L0_L0bar_p1pt_p2pt_US_LS->GetXaxis()->CenterTitle(true);
    h2_recombined_L0_L0bar_p1pt_p2pt_US_LS->GetYaxis()->SetTitle("p2_pt [GeV/c]");
    h2_recombined_L0_L0bar_p1pt_p2pt_US_LS->GetXaxis()->CenterTitle(true);

    c24->cd(5);
    h2_recombined_L0_L0bar_p1eta_p2eta_US_LS->Draw("COLZ");
    h2_recombined_L0_L0bar_p1eta_p2eta_US_LS->SetTitle("Eta- US-US #Lambda#bar{#Lambda} Pairs inside and outside #DeltaR = 0.93");
    h2_recombined_L0_L0bar_p1eta_p2eta_US_LS->GetXaxis()->SetTitle("p1_eta");
    h2_recombined_L0_L0bar_p1eta_p2eta_US_LS->GetXaxis()->CenterTitle(true);
    h2_recombined_L0_L0bar_p1eta_p2eta_US_LS->GetYaxis()->SetTitle("p2_eta");
    h2_recombined_L0_L0bar_p1eta_p2eta_US_LS->GetXaxis()->CenterTitle(true);

    c24->cd(6);
    h2_recombined_L0_L0bar_p1phi_p2phi_US_LS->Draw("COLZ");
    h2_recombined_L0_L0bar_p1phi_p2phi_US_LS->SetTitle("Phi- US-US #Lambda#bar{#Lambda} Pairs inside and outside #DeltaR = 0.93");
    h2_recombined_L0_L0bar_p1phi_p2phi_US_LS->GetXaxis()->SetTitle("p1_phi");
    h2_recombined_L0_L0bar_p1phi_p2phi_US_LS->GetXaxis()->CenterTitle(true);
    h2_recombined_L0_L0bar_p1phi_p2phi_US_LS->GetYaxis()->SetTitle("p2_phi");
    h2_recombined_L0_L0bar_p1phi_p2phi_US_LS->GetXaxis()->CenterTitle(true);

    std::cout << "Canvas 24 Complete" << std::endl;

    std::unique_ptr<TCanvas> c25(new TCanvas("c25", "Canvas 25", 1800, 900));
    c25->Divide(3, 2);

    TH2F *h2_recombined_L0_L0_p1pt_p2pt_US_US = new TH2F(*h2_cut_L0_L0_p1pt_p2pt_US_US);
    h2_recombined_L0_L0_p1pt_p2pt_US_US->Add(h2_cut_outside_L0_L0_p1pt_p2pt_US_US, 1.0);

    TH2F *h2_recombined_L0_L0_p1eta_p2eta_US_US = new TH2F(*h2_cut_L0_L0_p1eta_p2eta_US_US);
    h2_recombined_L0_L0_p1eta_p2eta_US_US->Add(h2_cut_outside_L0_L0_p1eta_p2eta_US_US, 1.0);

    TH2F *h2_recombined_L0_L0_p1phi_p2phi_US_US = new TH2F(*h2_cut_L0_L0_p1phi_p2phi_US_US);
    h2_recombined_L0_L0_p1phi_p2phi_US_US->Add(h2_cut_outside_L0_L0_p1phi_p2phi_US_US, 1.0);

    TH2F *h2_recombined_L0_L0_p1pt_p2pt_US_LS = new TH2F(*h2_cut_L0_L0_p1pt_p2pt_US_LS);
    h2_recombined_L0_L0_p1pt_p2pt_US_LS->Add(h2_cut_outside_L0_L0_p1pt_p2pt_US_LS, 1.0);

    TH2F *h2_recombined_L0_L0_p1eta_p2eta_US_LS = new TH2F(*h2_cut_L0_L0_p1eta_p2eta_US_LS);
    h2_recombined_L0_L0_p1eta_p2eta_US_LS->Add(h2_cut_outside_L0_L0_p1eta_p2eta_US_LS, 1.0);

    TH2F *h2_recombined_L0_L0_p1phi_p2phi_US_LS = new TH2F(*h2_cut_L0_L0_p1phi_p2phi_US_LS);
    h2_recombined_L0_L0_p1phi_p2phi_US_LS->Add(h2_cut_outside_L0_L0_p1phi_p2phi_US_LS, 1.0);

    c25->cd(1);
    h2_recombined_L0_L0_p1pt_p2pt_US_US->Draw("COLZ");
    h2_recombined_L0_L0_p1pt_p2pt_US_US->SetTitle("Pt- US-US #Lambda#Lambda Pairs inside and outside #DeltaR = 0.93");
    h2_recombined_L0_L0_p1pt_p2pt_US_US->GetXaxis()->SetTitle("p1_pt [GeV/c]");
    h2_recombined_L0_L0_p1pt_p2pt_US_US->GetXaxis()->CenterTitle(true);
    h2_recombined_L0_L0_p1pt_p2pt_US_US->GetYaxis()->SetTitle("p2_pt [GeV/c]");
    h2_recombined_L0_L0_p1pt_p2pt_US_US->GetYaxis()->CenterTitle(true);

    c25->cd(2);
    h2_recombined_L0_L0_p1eta_p2eta_US_US->Draw("COLZ");
    h2_recombined_L0_L0_p1eta_p2eta_US_US->SetTitle("Eta- US-US #Lambda#Lambda Pairs inside and outside #DeltaR = 0.93");
    h2_recombined_L0_L0_p1eta_p2eta_US_US->GetXaxis()->SetTitle("p1_eta");
    h2_recombined_L0_L0_p1eta_p2eta_US_US->GetXaxis()->CenterTitle(true);
    h2_recombined_L0_L0_p1eta_p2eta_US_US->GetYaxis()->SetTitle("p2_eta");
    h2_recombined_L0_L0_p1eta_p2eta_US_US->GetYaxis()->CenterTitle(true);

    c25->cd(3);
    h2_recombined_L0_L0_p1phi_p2phi_US_US->Draw("COLZ");
    h2_recombined_L0_L0_p1phi_p2phi_US_US->SetTitle("Phi- US-US #Lambda#Lambda Pairs inside and outside #DeltaR = 0.93");
    h2_recombined_L0_L0_p1phi_p2phi_US_US->GetXaxis()->SetTitle("p1_phi");
    h2_recombined_L0_L0_p1phi_p2phi_US_US->GetXaxis()->CenterTitle(true);
    h2_recombined_L0_L0_p1phi_p2phi_US_US->GetYaxis()->SetTitle("p2_phi");
    h2_recombined_L0_L0_p1phi_p2phi_US_US->GetYaxis()->CenterTitle(true);

    c25->cd(4);
    h2_recombined_L0_L0_p1pt_p2pt_US_LS->Draw("COLZ");
    h2_recombined_L0_L0_p1pt_p2pt_US_LS->SetTitle("Pt- US-LS #Lambda#Lambda Pairs inside and outside #DeltaR = 0.93");
    h2_recombined_L0_L0_p1pt_p2pt_US_LS->GetXaxis()->SetTitle("p1_pt [GeV/c]");
    h2_recombined_L0_L0_p1pt_p2pt_US_LS->GetXaxis()->CenterTitle(true);
    h2_recombined_L0_L0_p1pt_p2pt_US_LS->GetYaxis()->SetTitle("p2_pt [GeV/c]");
    h2_recombined_L0_L0_p1pt_p2pt_US_LS->GetYaxis()->CenterTitle(true);

    c25->cd(5);
    h2_recombined_L0_L0_p1eta_p2eta_US_LS->Draw("COLZ");
    h2_recombined_L0_L0_p1eta_p2eta_US_LS->SetTitle("Eta- US-US #Lambda#Lambda Pairs inside and outside #DeltaR = 0.93");
    h2_recombined_L0_L0_p1eta_p2eta_US_LS->GetXaxis()->SetTitle("p1_eta");
    h2_recombined_L0_L0_p1eta_p2eta_US_LS->GetXaxis()->CenterTitle(true);
    h2_recombined_L0_L0_p1eta_p2eta_US_LS->GetYaxis()->SetTitle("p2_eta");
    h2_recombined_L0_L0_p1eta_p2eta_US_LS->GetYaxis()->CenterTitle(true);

    c25->cd(6);
    h2_recombined_L0_L0_p1phi_p2phi_US_LS->Draw("COLZ");
    h2_recombined_L0_L0_p1phi_p2phi_US_LS->SetTitle("Phi- US-US #Lambda#Lambda Pairs inside and outside #DeltaR = 0.93");
    h2_recombined_L0_L0_p1phi_p2phi_US_LS->GetXaxis()->SetTitle("p1_phi");
    h2_recombined_L0_L0_p1phi_p2phi_US_LS->GetXaxis()->CenterTitle(true);
    h2_recombined_L0_L0_p1phi_p2phi_US_LS->GetYaxis()->SetTitle("p2_phi");
    h2_recombined_L0_L0_p1phi_p2phi_US_LS->GetYaxis()->CenterTitle(true);

    std::cout << "Canvas 25 Complete" << std::endl;

    std::unique_ptr<TCanvas> c26(new TCanvas("c26", "Canvas 26", 1800, 900));
    c26->Divide(3, 2);

    TH2F *h2_recombined_L0bar_L0bar_p1pt_p2pt_US_US = new TH2F(*h2_cut_L0bar_L0bar_p1pt_p2pt_US_US);
    h2_recombined_L0bar_L0bar_p1pt_p2pt_US_US->Add(h2_cut_outside_L0bar_L0bar_p1pt_p2pt_US_US, 1.0);

    TH2F *h2_recombined_L0bar_L0bar_p1eta_p2eta_US_US = new TH2F(*h2_cut_L0bar_L0bar_p1eta_p2eta_US_US);
    h2_recombined_L0bar_L0bar_p1eta_p2eta_US_US->Add(h2_cut_outside_L0bar_L0bar_p1eta_p2eta_US_US, 1.0);

    TH2F *h2_recombined_L0bar_L0bar_p1phi_p2phi_US_US = new TH2F(*h2_cut_L0bar_L0bar_p1phi_p2phi_US_US);
    h2_recombined_L0bar_L0bar_p1phi_p2phi_US_US->Add(h2_cut_outside_L0bar_L0bar_p1phi_p2phi_US_US, 1.0);

    TH2F *h2_recombined_L0bar_L0bar_p1pt_p2pt_US_LS = new TH2F(*h2_cut_L0bar_L0bar_p1pt_p2pt_US_LS);
    h2_recombined_L0bar_L0bar_p1pt_p2pt_US_LS->Add(h2_cut_outside_L0bar_L0bar_p1pt_p2pt_US_LS, 1.0);

    TH2F *h2_recombined_L0bar_L0bar_p1eta_p2eta_US_LS = new TH2F(*h2_cut_L0bar_L0bar_p1eta_p2eta_US_LS);
    h2_recombined_L0bar_L0bar_p1eta_p2eta_US_LS->Add(h2_cut_outside_L0bar_L0bar_p1eta_p2eta_US_LS, 1.0);

    TH2F *h2_recombined_L0bar_L0bar_p1phi_p2phi_US_LS = new TH2F(*h2_cut_L0bar_L0bar_p1phi_p2phi_US_LS);
    h2_recombined_L0bar_L0bar_p1phi_p2phi_US_LS->Add(h2_cut_outside_L0bar_L0bar_p1phi_p2phi_US_LS, 1.0);

    c26->cd(1);
    h2_recombined_L0bar_L0bar_p1pt_p2pt_US_US->Draw("COLZ");
    h2_recombined_L0bar_L0bar_p1pt_p2pt_US_US->SetTitle("Pt- US-US #bar{#Lambda}#bar{#Lambda} Pairs inside and outside #DeltaR = 0.93");
    h2_recombined_L0bar_L0bar_p1pt_p2pt_US_US->GetXaxis()->SetTitle("p1_pt [GeV/c]");
    h2_recombined_L0bar_L0bar_p1pt_p2pt_US_US->GetXaxis()->CenterTitle(true);
    h2_recombined_L0bar_L0bar_p1pt_p2pt_US_US->GetYaxis()->SetTitle("p2_pt [GeV/c]");
    h2_recombined_L0bar_L0bar_p1pt_p2pt_US_US->GetYaxis()->CenterTitle(true);

    c26->cd(2);
    h2_recombined_L0bar_L0bar_p1eta_p2eta_US_US->Draw("COLZ");
    h2_recombined_L0bar_L0bar_p1eta_p2eta_US_US->SetTitle("Eta- US-US #bar{#Lambda}#bar{#Lambda} Pairs inside and outside #DeltaR = 0.93");
    h2_recombined_L0bar_L0bar_p1eta_p2eta_US_US->GetXaxis()->SetTitle("p1_eta");
    h2_recombined_L0bar_L0bar_p1eta_p2eta_US_US->GetXaxis()->CenterTitle(true);
    h2_recombined_L0bar_L0bar_p1eta_p2eta_US_US->GetYaxis()->SetTitle("p2_eta");
    h2_recombined_L0bar_L0bar_p1eta_p2eta_US_US->GetYaxis()->CenterTitle(true);

    c26->cd(3);
    h2_recombined_L0bar_L0bar_p1phi_p2phi_US_US->Draw("COLZ");
    h2_recombined_L0bar_L0bar_p1phi_p2phi_US_US->SetTitle("Phi- US-US #bar{#Lambda}#bar{#Lambda} Pairs inside and outside #DeltaR = 0.93");
    h2_recombined_L0bar_L0bar_p1phi_p2phi_US_US->GetXaxis()->SetTitle("p1_phi");
    h2_recombined_L0bar_L0bar_p1phi_p2phi_US_US->GetXaxis()->CenterTitle(true);
    h2_recombined_L0bar_L0bar_p1phi_p2phi_US_US->GetYaxis()->SetTitle("p2_phi");
    h2_recombined_L0bar_L0bar_p1phi_p2phi_US_US->GetYaxis()->CenterTitle(true);

    c26->cd(4);
    h2_recombined_L0bar_L0bar_p1pt_p2pt_US_LS->Draw("COLZ");
    h2_recombined_L0bar_L0bar_p1pt_p2pt_US_LS->SetTitle("Pt- US-LS #bar{#Lambda}#bar{#Lambda} Pairs inside and outside #DeltaR = 0.93");
    h2_recombined_L0bar_L0bar_p1pt_p2pt_US_LS->GetXaxis()->SetTitle("p1_pt [GeV/c]");
    h2_recombined_L0bar_L0bar_p1pt_p2pt_US_LS->GetXaxis()->CenterTitle(true);
    h2_recombined_L0bar_L0bar_p1pt_p2pt_US_LS->GetYaxis()->SetTitle("p2_pt [GeV/c]");
    h2_recombined_L0bar_L0bar_p1pt_p2pt_US_LS->GetYaxis()->CenterTitle(true);

    c26->cd(5);
    h2_recombined_L0bar_L0bar_p1eta_p2eta_US_LS->Draw("COLZ");
    h2_recombined_L0bar_L0bar_p1eta_p2eta_US_LS->SetTitle("Eta- US-US #bar{#Lambda}#bar{#Lambda} Pairs inside and outside #DeltaR = 0.93");
    h2_recombined_L0bar_L0bar_p1eta_p2eta_US_LS->GetXaxis()->SetTitle("p1_eta");
    h2_recombined_L0bar_L0bar_p1eta_p2eta_US_LS->GetXaxis()->CenterTitle(true);
    h2_recombined_L0bar_L0bar_p1eta_p2eta_US_LS->GetYaxis()->SetTitle("p2_eta");
    h2_recombined_L0bar_L0bar_p1eta_p2eta_US_LS->GetYaxis()->CenterTitle(true);

    c26->cd(6);
    h2_recombined_L0bar_L0bar_p1phi_p2phi_US_LS->Draw("COLZ");
    h2_recombined_L0bar_L0bar_p1phi_p2phi_US_LS->SetTitle("Phi- US-US #bar{#Lambda}#bar{#Lambda} Pairs inside and outside #DeltaR = 0.93");
    h2_recombined_L0bar_L0bar_p1phi_p2phi_US_LS->GetXaxis()->SetTitle("p1_phi");
    h2_recombined_L0bar_L0bar_p1phi_p2phi_US_LS->GetXaxis()->CenterTitle(true);
    h2_recombined_L0bar_L0bar_p1phi_p2phi_US_LS->GetYaxis()->SetTitle("p2_phi");
    h2_recombined_L0bar_L0bar_p1phi_p2phi_US_LS->GetYaxis()->CenterTitle(true);

    std::cout << "Canvas 26 Complete" << std::endl;
    
    // Kinematic Veriables for Cuts
    double pt_restrict = 0.1;
    double phi_restrict = 0.1;
    double eta_restrict = 0.1;

    // do a typo check for the mixed event kinematic distributions
    for (size_t j=0; j < same_event_lambda_us_1.size(); ++j) {

        float successfull_ME_US_US_LL = 0;

        for (size_t k=0; k < single_lambda_us.size(); ++k){

            if (std::fabs(same_event_lambda_us_2[j].Pt() - single_lambda_us[k].Pt()) > pt_restrict)
                continue;
            if (std::fabs(same_event_lambda_us_2[j].Eta() - single_lambda_us[k].Eta()) > eta_restrict)
                continue;
            if (std::fabs(same_event_lambda_us_2[j].Phi() - single_lambda_us[k].Phi()) > phi_restrict)
                continue;

            if (same_event_lambda_us_1[j].M() >= minX_range_LL_2 && same_event_lambda_us_1[j].M() <= maxX_range_LL_2 &&
                same_event_lambda_us_2[j].M() >= minY_range_LL_2 && same_event_lambda_us_2[j].M() <= maxY_range_LL_2 &&
                single_lambda_us[k].M() >= minY_range_LL_2 && single_lambda_us[k].M() <= maxY_range_LL_2){

                successfull_ME_US_US_LL++;
            }
        }

        if (successfull_ME_US_US_LL != 0) {
            counts_successfull_ME_US_US_LL.push_back(1.0 / successfull_ME_US_US_LL);
        } else{
            counts_successfull_ME_US_US_LL.push_back(0.0);
        }
    }

    // Lambda - Lambda ME Pairs
    for (size_t j = 0; j < same_event_lambda_us_1.size(); ++j) {
        for (size_t k = 0; k < single_lambda_us.size(); ++k) {
            if (std::fabs(same_event_lambda_us_2[j].Pt() - single_lambda_us[k].Pt()) > pt_restrict)
                continue;
            if (std::fabs(same_event_lambda_us_2[j].Phi() - single_lambda_us[k].Phi()) > phi_restrict)
                continue;
            if (std::fabs(same_event_lambda_us_2[j].Eta() - single_lambda_us[k].Eta()) > eta_restrict)
                continue;

            mixed_event_SE_lambda_us_S_lambda_us->Fill(same_event_lambda_us_1[j].M(), single_lambda_us[k].M(), mreweight);

            h2_no_cuts_ME_L0_L0_p1pt_p2pt_US_US->Fill(same_event_proton_us_1[j].Pt(), single_proton_us[k].Pt(), mreweight);
            h2_no_cuts_ME_L0_L0_p1eta_p2eta_US_US->Fill(same_event_proton_us_1[j].Eta(), single_proton_us[k].Eta(), mreweight);
            h2_no_cuts_ME_L0_L0_p1phi_p2phi_US_US->Fill(same_event_proton_us_1[j].Phi(), single_proton_us[k].Phi(), mreweight);

            if (same_event_lambda_us_1[j].M() >= minX_range_LL_2 && same_event_lambda_us_1[j].M() <= maxX_range_LL_2 &&
                same_event_lambda_us_2[j].M() >= minY_range_LL_2 && same_event_lambda_us_2[j].M() <= maxY_range_LL_2 &&
                single_lambda_us[k].M() >= minY_range_LL_2 && single_lambda_us[k].M() <= maxY_range_LL_2){

                fourmoment_ME_lambda_us_1.push_back(same_event_lambda_us_1[j]);
                fourmoment_ME_lambda_us_2.push_back(single_lambda_us[k]);
                fourmoment_ME_proton_us_1.push_back(same_event_proton_us_1[j]);
                fourmoment_ME_proton_us_2.push_back(single_proton_us[k]);

                ME_weight_vector_1.push_back(mreweight);

                needsbettername.push_back(counts_successfull_ME_US_US_LL[j]);
            }
        }
    }

    std::cout << "SE US Lambda - Single US Lambda Complete" << std::endl;

    int iter_5 = 0;

    for (size_t j = 0; j < same_event_lambda_us_3.size(); ++j) {

        float successfull_ME_US_LS_LL = 0;

        for (size_t k = 0; k < single_lambda_ls.size(); ++k) {
            if (std::fabs(same_event_lambda_ls_3[j].Pt() - single_lambda_ls[k].Pt()) > pt_restrict)
                continue;
            if (std::fabs(same_event_lambda_ls_3[j].Phi() - single_lambda_ls[k].Phi()) > phi_restrict)
                continue;
            if (std::fabs(same_event_lambda_ls_3[j].Eta() - single_lambda_ls[k].Eta()) > eta_restrict)
                continue;

            if (same_event_lambda_us_3[j].M() >= minX_range_LL_2 && same_event_lambda_us_3[j].M() <= maxX_range_LL_2 &&
                same_event_lambda_ls_3[j].M() >= minY_range_LL_2 && same_event_lambda_ls_3[j].M() <= maxY_range_LL_2 &&
                single_lambda_ls[k].M() >= minY_range_LL_2 && single_lambda_ls[k].M() <= maxY_range_LL_2){

                successfull_ME_US_LS_LL++;
            }
        }

        if (successfull_ME_US_LS_LL != 0) {
            counts_successfull_ME_US_LS_LL.push_back(1.0 / successfull_ME_US_LS_LL);
        } else {
            counts_successfull_ME_US_LS_LL.push_back(0.0);
        }
    } 

    for (size_t j = 0; j < same_event_lambda_us_3.size(); ++j) {
        for (size_t k = 0; k < single_lambda_ls.size(); ++k) {       
            if (std::fabs(same_event_lambda_ls_3[j].Pt() - single_lambda_ls[k].Pt()) > pt_restrict)
                continue;
            if (std::fabs(same_event_lambda_ls_3[j].Phi() - single_lambda_ls[k].Phi()) > phi_restrict)
                continue;
            if (std::fabs(same_event_lambda_ls_3[j].Eta() - single_lambda_ls[k].Eta()) > eta_restrict)
                continue;


            if (iter_5 % 2 == 0) {
                mixed_event_SE_lambda_us_S_lambda_ls->Fill(same_event_lambda_us_3[j].M(), single_lambda_ls[k].M(), mreweight);
            } else {
                mixed_event_SE_lambda_us_S_lambda_ls->Fill(single_lambda_ls[k].M(), same_event_lambda_us_3[j].M(), mreweight);
            }

            iter_5++;

            h2_no_cuts_ME_L0_L0_p1pt_p2pt_US_LS->Fill(same_event_proton_us_3[j].Pt(), single_proton_ls[k].Pt(), mreweight);
            h2_no_cuts_ME_L0_L0_p1eta_p2eta_US_LS->Fill(same_event_proton_us_3[j].Eta(), single_proton_ls[k].Eta(), mreweight);
            h2_no_cuts_ME_L0_L0_p1phi_p2phi_US_LS->Fill(same_event_proton_us_3[j].Phi(), single_proton_ls[k].Phi(), mreweight);

           if (same_event_lambda_us_3[j].M() >= minX_range_LL_2 && same_event_lambda_us_3[j].M() <= maxX_range_LL_2 &&
                same_event_lambda_ls_3[j].M() >= minY_range_LL_2 && same_event_lambda_ls_3[j].M() <= maxY_range_LL_2 &&
                single_lambda_ls[k].M() >= minY_range_LL_2 && single_lambda_ls[k].M() <= maxY_range_LL_2){

                fourmoment_ME_lambda_us_3.push_back(same_event_lambda_us_3[j]);
                fourmoment_ME_lambda_ls_3.push_back(single_lambda_ls[k]);
                fourmoment_ME_proton_us_3.push_back(same_event_proton_us_3[j]);
                fourmoment_ME_proton_ls_3.push_back(single_proton_ls[k]);

                ME_weight_vector_2.push_back(mreweight);

                needsbettername2.push_back(counts_successfull_ME_US_LS_LL[j]);
            }
        }
    }

    std::cout << "SE US Lambda - Single LS Lambda Complete" << std::endl;

    for (size_t j = 0; j < same_event_lambda_us_4.size(); ++j) {

        float successfull_ME_US_US_LLBar = 0;

        for (size_t k = 0; k < single_lambda_bar_us.size(); ++k){
            if (std::fabs(same_event_lambda_bar_us_4[j].Pt() - single_lambda_bar_us[k].Pt()) > pt_restrict)
                continue;
            if (std::fabs(same_event_lambda_bar_us_4[j].Phi() - single_lambda_bar_us[k].Phi()) > phi_restrict)
                continue;
            if (std::fabs(same_event_lambda_bar_us_4[j].Eta() - single_lambda_bar_us[k].Eta()) > eta_restrict)
                continue;

            if (same_event_lambda_us_4[j].M() >= minX_range_LLBar_2 && same_event_lambda_us_4[j].M() <= maxX_range_LLBar_2 &&
                same_event_lambda_bar_us_4[j].M() >= minY_range_LLBar_2 && same_event_lambda_bar_us_4[j].M() <= maxY_range_LLBar_2 &&
                single_lambda_bar_us[k].M() >= minY_range_LLBar_2 && single_lambda_bar_us[k].M() <= maxY_range_LLBar_2){

                successfull_ME_US_US_LLBar++;
            }
        }

        // counts_successfull_ME_US_US_LLBar.push_back(1.0 / successfull_ME_US_US_LLBar);

        if (successfull_ME_US_US_LLBar != 0) {
            counts_successfull_ME_US_US_LLBar.push_back(1.0 / successfull_ME_US_US_LLBar);
        } else {
            counts_successfull_ME_US_US_LLBar.push_back(0.0);
        }
    }

    for (size_t j = 0; j < same_event_lambda_us_4.size(); ++j) {
        for (size_t k = 0; k < single_lambda_bar_us.size(); ++k){
            if (std::fabs(same_event_lambda_bar_us_4[j].Pt() - single_lambda_bar_us[k].Pt()) > pt_restrict)
                continue;
            if (std::fabs(same_event_lambda_bar_us_4[j].Phi() - single_lambda_bar_us[k].Phi()) > phi_restrict)
                continue;
            if (std::fabs(same_event_lambda_bar_us_4[j].Eta() - single_lambda_bar_us[k].Eta()) > eta_restrict)
                continue;

            mixed_event_SE_lambda_us_S_lambda_bar_us->Fill(same_event_lambda_us_4[j].M(), single_lambda_bar_us[k].M(), mreweight);

            h2_no_cuts_ME_L0_L0bar_p1pt_p2pt_US_US->Fill(same_event_proton_us_4[j].Pt(), single_anti_proton_us[k].Pt(), mreweight);
            h2_no_cuts_ME_L0_L0bar_p1eta_p2eta_US_US->Fill(same_event_proton_us_4[j].Eta(), single_anti_proton_us[k].Eta(), mreweight);
            h2_no_cuts_ME_L0_L0bar_p1phi_p2phi_US_US->Fill(same_event_proton_us_4[j].Phi(), single_anti_proton_us[k].Phi(), mreweight);

            if (same_event_lambda_us_4[j].M() >= minX_range_LLBar_2 && same_event_lambda_us_4[j].M() <= maxX_range_LLBar_2 &&
                same_event_lambda_bar_us_4[j].M() >= minY_range_LLBar_2 && same_event_lambda_bar_us_4[j].M() <= maxY_range_LLBar_2 &&
                single_lambda_bar_us[k].M() >= minY_range_LLBar_2 && single_lambda_bar_us[k].M() <= maxY_range_LLBar_2){

                fourmoment_ME_lambda_us_4.push_back(same_event_lambda_us_4[j]);
                fourmoment_ME_lambda_bar_us_4.push_back(single_lambda_bar_us[k]);
                fourmoment_ME_proton_us_4.push_back(same_event_proton_us_4[j]);
                fourmoment_ME_anti_proton_us_4.push_back(single_anti_proton_us[k]);

                ME_weight_vector_3.push_back(mreweight);

                needsbettername3.push_back(counts_successfull_ME_US_US_LLBar[j]);
            }
        }
    }

    std::cout << "SE US Lambda - Single US Lambda Bar Complete" << std::endl;

    for (size_t j = 0; j < same_event_lambda_us_5.size(); ++j) {

        float successfull_ME_US_LS_LLBar = 0;

        for (size_t k = 0; k < single_lambda_bar_ls.size(); ++k) {
            if (std::fabs(same_event_lambda_bar_ls_5[j].Pt() - single_lambda_bar_ls[k].Pt()) > pt_restrict)
                continue;
            if (std::fabs(same_event_lambda_bar_ls_5[j].Phi() - single_lambda_bar_ls[k].Phi()) > phi_restrict)
                continue;
            if (std::fabs(same_event_lambda_bar_ls_5[j].Eta() - single_lambda_bar_ls[k].Eta()) > eta_restrict)
                continue;

            if (same_event_lambda_us_5[j].M() >= minX_range_LLBar_2 && same_event_lambda_us_5[j].M() <= maxX_range_LLBar_2 &&
                same_event_lambda_bar_ls_5[j].M() >= minY_range_LLBar_2 && same_event_lambda_bar_ls_5[j].M() <= maxX_range_LLBar_2 &&
                single_lambda_bar_ls[k].M() >= minY_range_LLBar_2 && single_lambda_bar_ls[k].M() <= maxY_range_LLBar_2){

                successfull_ME_US_LS_LLBar++;
            }
        }

        if (successfull_ME_US_LS_LLBar != 0) {
            counts_successfull_ME_US_LS_LLBar.push_back(1.0 / successfull_ME_US_LS_LLBar);
        } else {
            counts_successfull_ME_US_LS_LLBar.push_back(0.0);
        }
    }

    for (size_t j = 0; j < same_event_lambda_us_5.size(); ++j) {
        for (size_t k = 0; k < single_lambda_bar_ls.size(); ++k) {
            if (std::fabs(same_event_lambda_bar_ls_5[j].Pt() - single_lambda_bar_ls[k].Pt()) > pt_restrict)
                continue;
            if (std::fabs(same_event_lambda_bar_ls_5[j].Phi() - single_lambda_bar_ls[k].Phi()) > phi_restrict)
                continue;
            if (std::fabs(same_event_lambda_bar_ls_5[j].Eta() - single_lambda_bar_ls[k].Eta()) > eta_restrict)
                continue;

            mixed_event_SE_lambda_us_S_lambda_bar_ls->Fill(same_event_lambda_us_5[j].M(), single_lambda_bar_ls[k].M(), mreweight);

            h2_no_cuts_ME_L0_L0bar_p1pt_p2pt_US_LS->Fill(same_event_proton_us_5[j].Pt(), single_anti_proton_ls[k].Pt(), mreweight);
            h2_no_cuts_ME_L0_L0bar_p1eta_p2eta_US_LS->Fill(same_event_proton_us_5[j].Eta(), single_anti_proton_ls[k].Eta(), mreweight);
            h2_no_cuts_ME_L0_L0bar_p1phi_p2phi_US_LS->Fill(same_event_proton_us_5[j].Phi(), single_anti_proton_ls[k].Phi(), mreweight);

            if (same_event_lambda_us_5[j].M() >= minX_range_LLBar_2 && same_event_lambda_us_5[j].M() <= maxX_range_LLBar_2 &&
                same_event_lambda_bar_ls_5[j].M() >= minY_range_LLBar_2 && same_event_lambda_bar_ls_5[j].M() <= maxX_range_LLBar_2 &&
                single_lambda_bar_ls[k].M() >= minY_range_LLBar_2 && single_lambda_bar_ls[k].M() <= maxY_range_LLBar_2){

                fourmoment_ME_lambda_us_5.push_back(same_event_lambda_us_5[j]);
                fourmoment_ME_lambda_bar_ls_5.push_back(single_lambda_bar_ls[k]);
                fourmoment_ME_proton_us_5.push_back(same_event_proton_us_5[j]);
                fourmoment_ME_anti_proton_ls_5.push_back(single_anti_proton_ls[k]);

                ME_weight_vector_4.push_back(mreweight);

                needsbettername4.push_back(counts_successfull_ME_US_LS_LLBar[j]);
            }
        }
    }

    std::cout << "SE US Lambda - Single LS Lambda Bar Complete" << std::endl;

    for (size_t j = 0; j < same_event_lambda_ls_5.size(); ++j) {

        float successfull_ME_LS_US_LLBar = 0;

        for (size_t k = 0; k < single_lambda_bar_us.size(); ++k) {
            if (std::fabs(same_event_lambda_bar_us_5[j].Pt() - single_lambda_bar_us[k].Pt()) > pt_restrict)
                continue;
            if (std::fabs(same_event_lambda_bar_us_5[j].Phi() - single_lambda_bar_us[k].Phi()) > phi_restrict)
                continue;
            if (std::fabs(same_event_lambda_bar_us_5[j].Eta() - single_lambda_bar_us[k].Eta()) > eta_restrict)
                continue;

            if (same_event_lambda_ls_5[j].M() >= minX_range_LLBar_2 && same_event_lambda_ls_5[j].M() <= maxX_range_LLBar_2 &&
                same_event_lambda_bar_us_5[j].M() >= minY_range_LLBar_2 && same_event_lambda_bar_us_5[j].M() <= maxY_range_LLBar_2 &&
                single_lambda_bar_us[k].M() >= minY_range_LLBar_2 && single_lambda_bar_us[k].M() <= maxY_range_LLBar_2){

                successfull_ME_LS_US_LLBar++;
            }
        }

        // counts_successfull_ME_LS_US_LLBar.push_back(1.0 / successfull_ME_LS_US_LLBar);

        if (successfull_ME_LS_US_LLBar != 0) {
            counts_successfull_ME_LS_US_LLBar.push_back(1.0 / successfull_ME_LS_US_LLBar);
        } else {
            counts_successfull_ME_LS_US_LLBar.push_back(0.0);
        }
    }

    for (size_t j = 0; j < same_event_lambda_ls_5.size(); ++j) {
        for (size_t k = 0; k < single_lambda_bar_us.size(); ++k) {
            if (std::fabs(same_event_lambda_bar_us_5[j].Pt() - single_lambda_bar_us[k].Pt()) > pt_restrict)
                continue;
            if (std::fabs(same_event_lambda_bar_us_5[j].Phi() - single_lambda_bar_us[k].Phi()) > phi_restrict)
                continue;
            if (std::fabs(same_event_lambda_bar_us_5[j].Eta() - single_lambda_bar_us[k].Eta()) > eta_restrict)
                continue;

            mixed_event_SE_lambda_us_S_lambda_bar_ls->Fill(same_event_lambda_ls_5[j].M(), single_lambda_bar_us[k].M(), mreweight);

            h2_no_cuts_ME_L0_L0bar_p1pt_p2pt_US_LS->Fill(same_event_proton_ls_5[j].Pt(), single_anti_proton_us[k].Pt(), mreweight);
            h2_no_cuts_ME_L0_L0bar_p1eta_p2eta_US_LS->Fill(same_event_proton_ls_5[j].Eta(), single_anti_proton_us[k].Eta(), mreweight);
            h2_no_cuts_ME_L0_L0bar_p1phi_p2phi_US_LS->Fill(same_event_proton_ls_5[j].Phi(), single_anti_proton_us[k].Phi(), mreweight);

            if (same_event_lambda_ls_5[j].M() >= minX_range_LLBar_2 && same_event_lambda_ls_5[j].M() <= maxX_range_LLBar_2 &&
                same_event_lambda_bar_us_5[j].M() >= minY_range_LLBar_2 && same_event_lambda_bar_us_5[j].M() <= maxY_range_LLBar_2 &&
                single_lambda_bar_us[k].M() >= minY_range_LLBar_2 && single_lambda_bar_us[k].M() <= maxY_range_LLBar_2){

                fourmoment_ME_lambda_ls_5.push_back(same_event_lambda_ls_5[j]);
                fourmoment_ME_lambda_bar_us_5.push_back(single_lambda_bar_us[k]);
                fourmoment_ME_proton_ls_5.push_back(same_event_proton_ls_5[j]);
                fourmoment_ME_anti_proton_us_5.push_back(single_proton_us[j]);

                ME_weight_vector_5.push_back(mreweight);

                needsbettername5.push_back(counts_successfull_ME_LS_US_LLBar[j]);

            }
        }
    }

    std::cout << "SE LS Lambda - Single US Lambda Bar Complete" << std::endl;

    for (size_t j = 0; j < same_event_lambda_bar_us_1.size(); ++j) {

        float successfull_ME_US_US_LBarLBar = 0;

        for (size_t k = 0; k < single_lambda_bar_us.size(); ++k) {
            if (std::fabs(same_event_lambda_bar_us_2[j].Pt() - single_lambda_bar_us[k].Pt()) > pt_restrict)
                continue;
            if (std::fabs(same_event_lambda_bar_us_2[j].Phi() - single_lambda_bar_us[k].Phi()) > phi_restrict)
                continue;
            if (std::fabs(same_event_lambda_bar_us_2[j].Eta() - single_lambda_bar_us[k].Eta()) > eta_restrict)
                continue;

            if (same_event_lambda_bar_us_1[j].M() >= minX_range_LBarLBar_2 && same_event_lambda_bar_us_1[j].M() <= maxX_range_LBarLBar_2 &&
                same_event_lambda_bar_us_2[j].M() >= minY_range_LBarLBar_2 && same_event_lambda_bar_us_2[j].M() <= maxY_range_LBarLBar_2 &&
                single_lambda_bar_us[k].M() >= minY_range_LBarLBar_2 && single_lambda_bar_us[k].M() <= maxY_range_LBarLBar_2){

                successfull_ME_US_US_LBarLBar++;
            }
        }

        if (successfull_ME_US_US_LBarLBar != 0) {
            counts_successfull_ME_US_US_LBarLBar.push_back(1.0 / successfull_ME_US_US_LBarLBar);
        } else {
            counts_successfull_ME_US_US_LBarLBar.push_back(0.0);
        }
    }

    for (size_t j = 0; j < same_event_lambda_bar_us_1.size(); ++j) {
        for (size_t k = 0; k < single_lambda_bar_us.size(); ++k) {
            if (std::fabs(same_event_lambda_bar_us_2[j].Pt() - single_lambda_bar_us[k].Pt()) > pt_restrict)
                continue;
            if (std::fabs(same_event_lambda_bar_us_2[j].Phi() - single_lambda_bar_us[k].Phi()) > phi_restrict)
                continue;
            if (std::fabs(same_event_lambda_bar_us_2[j].Eta() - single_lambda_bar_us[k].Eta()) > eta_restrict)
                continue;

            mixed_event_SE_lambda_bar_us_S_lambda_bar_us->Fill(same_event_lambda_bar_us_1[j].M(), single_lambda_bar_us[k].M(), mreweight);

            h2_no_cuts_ME_L0bar_L0bar_p1pt_p2pt_US_US->Fill(same_event_anti_proton_us_1[j].Pt(), single_anti_proton_us[k].Pt(), mreweight);
            h2_no_cuts_ME_L0bar_L0bar_p1eta_p2eta_US_US->Fill(same_event_anti_proton_us_1[j].Eta(), single_anti_proton_us[k].Eta(), mreweight);
            h2_no_cuts_ME_L0bar_L0bar_p1phi_p2phi_US_US->Fill(same_event_anti_proton_us_1[j].Phi(), single_anti_proton_us[k].Phi(), mreweight);

            if (same_event_lambda_bar_us_1[j].M() >= minX_range_LBarLBar_2 && same_event_lambda_bar_us_1[j].M() <= maxX_range_LBarLBar_2 &&
                same_event_lambda_bar_us_2[j].M() >= minY_range_LBarLBar_2 && same_event_lambda_bar_us_2[j].M() <= maxY_range_LBarLBar_2 &&
                single_lambda_bar_us[k].M() >= minY_range_LBarLBar_2 && single_lambda_bar_us[k].M() <= maxY_range_LBarLBar_2){

                fourmoment_ME_lambda_bar_us_1.push_back(same_event_lambda_bar_us_1[j]);
                fourmoment_ME_lambda_bar_us_2.push_back(single_lambda_bar_us[k]);
                fourmoment_ME_anti_proton_us_1.push_back(same_event_anti_proton_us_1[j]);
                fourmoment_ME_anti_proton_us_2.push_back(single_anti_proton_us[k]);

                ME_weight_vector_6.push_back(mreweight);

                needsbettername6.push_back(counts_successfull_ME_US_US_LBarLBar[j]);
            }
        }
    }

    std::cout << "SE US Lambda Bar - Single US Lambda Bar Complete" << std::endl;

    for (size_t j = 0; j < same_event_lambda_bar_us_6.size(); ++j) {

        float successfull_ME_US_LS_LBarLBar = 0;

        for (size_t k = 0; k < single_lambda_bar_ls.size(); ++k) {
            if (std::fabs(same_event_lambda_bar_ls_6[j].Pt() - single_lambda_bar_ls[k].Pt()) > pt_restrict)
                continue;
            if (std::fabs(same_event_lambda_bar_ls_6[j].Phi() - single_lambda_bar_ls[k].Phi()) > phi_restrict)
                continue;
            if (std::fabs(same_event_lambda_bar_ls_6[j].Eta() - single_lambda_bar_ls[k].Eta()) > eta_restrict)
                continue;

            if (same_event_lambda_bar_us_6[j].M() >= minX_range_LBarLBar_2 && same_event_lambda_bar_us_6[j].M() <= maxX_range_LBarLBar_2 &&
                same_event_lambda_bar_ls_6[j].M() >= minY_range_LBarLBar_2 && same_event_lambda_bar_ls_6[j].M() <= maxY_range_LBarLBar_2 &&
                single_lambda_bar_ls[k].M() >= minY_range_LBarLBar_2 && single_lambda_bar_ls[k].M() <= maxY_range_LBarLBar_2){

                successfull_ME_US_LS_LBarLBar++; 
            }
        }

        // counts_successfull_ME_US_LS_LBarLBar.push_back(1.0 / successfull_ME_US_LS_LBarLBar);

        if (successfull_ME_US_LS_LBarLBar != 0) {
            counts_successfull_ME_US_LS_LBarLBar.push_back(1.0 / successfull_ME_US_LS_LBarLBar);
        } else {
            counts_successfull_ME_US_LS_LBarLBar.push_back(0.0);
        }
    }

    int iter_6 = 0;

    for (size_t j = 0; j < same_event_lambda_bar_us_6.size(); ++j) {
        for (size_t k = 0; k < single_lambda_bar_ls.size(); ++k) {
            if (std::fabs(same_event_lambda_bar_ls_6[j].Pt() - single_lambda_bar_ls[k].Pt()) > pt_restrict)
                continue;
            if (std::fabs(same_event_lambda_bar_ls_6[j].Phi() - single_lambda_bar_ls[k].Phi()) > phi_restrict)
                continue;
            if (std::fabs(same_event_lambda_bar_ls_6[j].Eta() - single_lambda_bar_ls[k].Eta()) > eta_restrict)
                continue;

            if (iter_6 % 2 == 0) {
                mixed_event_SE_lambda_bar_us_S_lambda_bar_ls->Fill(same_event_lambda_bar_us_6[j].M(), single_lambda_bar_ls[k].M(), mreweight);
            } else {
                mixed_event_SE_lambda_bar_us_S_lambda_bar_ls->Fill(single_lambda_bar_ls[k].M(), same_event_lambda_bar_us_6[j].M(), mreweight);
            }

            iter_6++;

            h2_no_cuts_ME_L0bar_L0bar_p1pt_p2pt_US_LS->Fill(same_event_anti_proton_us_6[j].Pt(), single_anti_proton_ls[k].Pt(), mreweight);
            h2_no_cuts_ME_L0bar_L0bar_p1eta_p2eta_US_LS->Fill(same_event_anti_proton_us_6[j].Eta(), single_anti_proton_ls[k].Eta(), mreweight);
            h2_no_cuts_ME_L0bar_L0bar_p1phi_p2phi_US_LS->Fill(same_event_anti_proton_us_6[j].Phi(), single_anti_proton_ls[k].Phi(), mreweight);

            if (same_event_lambda_bar_us_6[j].M() >= minX_range_LBarLBar_2 && same_event_lambda_bar_us_6[j].M() <= maxX_range_LBarLBar_2 &&
                same_event_lambda_bar_ls_6[j].M() >= minY_range_LBarLBar_2 && same_event_lambda_bar_ls_6[j].M() <= maxY_range_LBarLBar_2 &&
                single_lambda_bar_ls[k].M() >= minY_range_LBarLBar_2 && single_lambda_bar_ls[k].M() <= maxY_range_LBarLBar_2){

                fourmoment_ME_lambda_bar_us_6.push_back(same_event_lambda_bar_us_6[j]);
                fourmoment_ME_lambda_bar_ls_6.push_back(single_lambda_bar_ls[k]);
                fourmoment_ME_anti_proton_us_6.push_back(same_event_anti_proton_us_6[j]);
                fourmoment_ME_anti_proton_ls_6.push_back(single_anti_proton_ls[k]);

                ME_weight_vector_7.push_back(mreweight);

                needsbettername7.push_back(counts_successfull_ME_US_LS_LBarLBar[j]);
            }
        }
    }

    std::cout << "SE US Lambda Bar - Single LS Lambda Bar Complete" << std::endl;

    std::cout << "Mixed Event Pairings Complete" << std::endl;

    double Counts_ME_US_US_LLBar = mixed_event_SE_lambda_us_S_lambda_bar_us->Integral();
    double Counts_ME_US_LS_LLBar = mixed_event_SE_lambda_us_S_lambda_bar_ls->Integral();
    double Counts_ME_US_US_LL = mixed_event_SE_lambda_us_S_lambda_us->Integral();
    double Counts_ME_US_LS_LL = mixed_event_SE_lambda_us_S_lambda_ls->Integral();
    double Counts_ME_US_US_LBarLBar = mixed_event_SE_lambda_bar_us_S_lambda_bar_us->Integral();
    double Counts_ME_US_LS_LBarLBar = mixed_event_SE_lambda_bar_us_S_lambda_bar_ls->Integral();

    std::cout << "  " << std::endl;
    std::cout << "**Mixed Event Pairs (before cuts)**" << std::endl;
    std::cout << "US Lambda - US Lambda Bar Pair: " << Counts_ME_US_US_LLBar << std::endl;
    std::cout << "US Lambda - LS Lambda Bar Pair: " << Counts_ME_US_LS_LLBar << std::endl;
    std::cout << "US Lambda - US Lambda Pair: " << Counts_ME_US_US_LL << std::endl;
    std::cout << "US Lambda - LS Lambda Pair: " << Counts_ME_US_LS_LL << std::endl;
    std::cout << "US Lambda Bar - US Lambda Bar Pair: " << Counts_ME_US_US_LBarLBar << std::endl;
    std::cout << "US Lambda Bar - LS Lambda Bar Pair: " << Counts_ME_US_LS_LBarLBar << std::endl;

    std::unique_ptr<TCanvas> c27(new TCanvas("c27", "Canvas 27", 1800, 900));
    c27->Divide(3, 1);

    c27->cd(1);
    binMinX = mixed_event_SE_lambda_us_S_lambda_bar_us->GetXaxis()->FindBin(minX);
    binMaxX = mixed_event_SE_lambda_us_S_lambda_bar_us->GetXaxis()->FindBin(maxX);
    binMinY = mixed_event_SE_lambda_us_S_lambda_bar_us->GetYaxis()->FindBin(minY);
    binMaxY = mixed_event_SE_lambda_us_S_lambda_bar_us->GetYaxis()->FindBin(maxY);

    mixed_event_SE_lambda_us_S_lambda_bar_us->GetXaxis()->SetRange(binMinX, binMaxX);
    mixed_event_SE_lambda_us_S_lambda_bar_us->GetYaxis()->SetRange(binMinY, binMaxY);
    mixed_event_SE_lambda_us_S_lambda_bar_us->Draw("SURF2");
    mixed_event_SE_lambda_us_S_lambda_bar_us->SetTitle("Inv. Mass for ME #Lambda#bar{#Lambda} Pair");
    mixed_event_SE_lambda_us_S_lambda_bar_ls->Draw("same");

    c27->cd(2);
    binMinX = mixed_event_SE_lambda_us_S_lambda_us->GetXaxis()->FindBin(minX);
    binMaxX = mixed_event_SE_lambda_us_S_lambda_us->GetXaxis()->FindBin(maxX);
    binMinY = mixed_event_SE_lambda_us_S_lambda_us->GetYaxis()->FindBin(minY);
    binMaxY = mixed_event_SE_lambda_us_S_lambda_us->GetYaxis()->FindBin(maxY);

    mixed_event_SE_lambda_us_S_lambda_us->GetXaxis()->SetRange(binMinX, binMaxX);
    mixed_event_SE_lambda_us_S_lambda_us->GetYaxis()->SetRange(binMinY, binMaxY);
    mixed_event_SE_lambda_us_S_lambda_us->Draw("SURF2");
    mixed_event_SE_lambda_us_S_lambda_us->SetTitle("Inv. Mass for ME #Lambda#Lambda Pair");
    mixed_event_SE_lambda_us_S_lambda_ls->Draw("same");

    c27->cd(3);
    binMinX = mixed_event_SE_lambda_bar_us_S_lambda_bar_us->GetXaxis()->FindBin(minX);
    binMaxX = mixed_event_SE_lambda_bar_us_S_lambda_bar_us->GetXaxis()->FindBin(maxX);
    binMinY = mixed_event_SE_lambda_bar_us_S_lambda_bar_us->GetYaxis()->FindBin(minY);
    binMaxY = mixed_event_SE_lambda_bar_us_S_lambda_bar_us->GetYaxis()->FindBin(maxY);

    mixed_event_SE_lambda_bar_us_S_lambda_bar_us->GetXaxis()->SetRange(binMinX, binMaxX);
    mixed_event_SE_lambda_bar_us_S_lambda_bar_us->GetYaxis()->SetRange(binMinY, binMaxY);
    mixed_event_SE_lambda_bar_us_S_lambda_bar_us->Draw("SURF2");
    mixed_event_SE_lambda_bar_us_S_lambda_bar_us->SetTitle("Inv. Mass for ME #bar{#Lambda}#bar{#Lambda} Pair");
    mixed_event_SE_lambda_bar_us_S_lambda_bar_ls->Draw("same");

    std::cout << "Canvas 27 Complete" << std::endl;

    std::unique_ptr<TCanvas> c28(new TCanvas("c28", "Canvas 28", 1800, 900));
    c28->Divide(3, 2);

    c28->cd(1);
    h2_no_cuts_ME_L0_L0bar_p1pt_p2pt_US_US->Draw("COLZ"); 
    h2_no_cuts_ME_L0_L0bar_p1pt_p2pt_US_US->SetTitle("Pt- US-US ME #Lambda#bar{#Lambda} Pairs (no cuts)"); 
    h2_no_cuts_ME_L0_L0bar_p1pt_p2pt_US_US->GetXaxis()->SetTitle("p1_pt [GeV/c]");
    h2_no_cuts_ME_L0_L0bar_p1pt_p2pt_US_US->GetXaxis()->CenterTitle(true);
    h2_no_cuts_ME_L0_L0bar_p1pt_p2pt_US_US->GetYaxis()->SetTitle("p2_pt [GeV/c]");
    h2_no_cuts_ME_L0_L0bar_p1pt_p2pt_US_US->GetYaxis()->CenterTitle(true);

    c28->cd(2);
    h2_no_cuts_ME_L0_L0bar_p1eta_p2eta_US_US->Draw("COLZ");
    h2_no_cuts_ME_L0_L0bar_p1eta_p2eta_US_US->SetTitle("Eta- US-US ME #Lambda#bar{#Lambda} Pairs (no cuts)");
    h2_no_cuts_ME_L0_L0bar_p1eta_p2eta_US_US->GetXaxis()->SetTitle("p1_eta");
    h2_no_cuts_ME_L0_L0bar_p1eta_p2eta_US_US->GetXaxis()->CenterTitle(true);
    h2_no_cuts_ME_L0_L0bar_p1eta_p2eta_US_US->GetYaxis()->SetTitle("p2_eta");
    h2_no_cuts_ME_L0_L0bar_p1eta_p2eta_US_US->GetYaxis()->CenterTitle(true);

    c28->cd(3);
    h2_no_cuts_ME_L0_L0bar_p1phi_p2phi_US_US->Draw("COLZ");
    h2_no_cuts_ME_L0_L0bar_p1phi_p2phi_US_US->SetTitle("Phi- US-US ME #Lambda#bar{#Lambda} Pairs (no cuts)");
    h2_no_cuts_ME_L0_L0bar_p1phi_p2phi_US_US->GetXaxis()->SetTitle("p1_phi");
    h2_no_cuts_ME_L0_L0bar_p1phi_p2phi_US_US->GetXaxis()->CenterTitle(true);
    h2_no_cuts_ME_L0_L0bar_p1phi_p2phi_US_US->GetYaxis()->SetTitle("p2_phi");
    h2_no_cuts_ME_L0_L0bar_p1phi_p2phi_US_US->GetYaxis()->CenterTitle(true);

    c28->cd(4);
    h2_no_cuts_ME_L0_L0bar_p1pt_p2pt_US_LS->Draw("COLZ"); 
    h2_no_cuts_ME_L0_L0bar_p1pt_p2pt_US_LS->SetTitle("Pt- US-LS ME #Lambda#bar{#Lambda} Pairs (no cuts)"); 
    h2_no_cuts_ME_L0_L0bar_p1pt_p2pt_US_LS->GetXaxis()->SetTitle("p1_pt [GeV/c]");
    h2_no_cuts_ME_L0_L0bar_p1pt_p2pt_US_LS->GetXaxis()->CenterTitle(true);
    h2_no_cuts_ME_L0_L0bar_p1pt_p2pt_US_LS->GetYaxis()->SetTitle("p2_pt [GeV/c]");
    h2_no_cuts_ME_L0_L0bar_p1pt_p2pt_US_LS->GetYaxis()->CenterTitle(true);

    c28->cd(5);
    h2_no_cuts_ME_L0_L0bar_p1eta_p2eta_US_LS->Draw("COLZ");
    h2_no_cuts_ME_L0_L0bar_p1eta_p2eta_US_LS->SetTitle("Eta- US-LS ME #Lambda#bar{#Lambda} Pairs (no cuts)");
    h2_no_cuts_ME_L0_L0bar_p1eta_p2eta_US_LS->GetXaxis()->SetTitle("p1_eta");
    h2_no_cuts_ME_L0_L0bar_p1eta_p2eta_US_LS->GetXaxis()->CenterTitle(true);
    h2_no_cuts_ME_L0_L0bar_p1eta_p2eta_US_LS->GetYaxis()->SetTitle("p2_eta");
    h2_no_cuts_ME_L0_L0bar_p1eta_p2eta_US_LS->GetYaxis()->CenterTitle(true);

    c28->cd(6);
    h2_no_cuts_ME_L0_L0bar_p1phi_p2phi_US_LS->Draw("COLZ");
    h2_no_cuts_ME_L0_L0bar_p1phi_p2phi_US_LS->SetTitle("Phi- US-LS ME #Lambda#bar{#Lambda} Pairs (no cuts)");
    h2_no_cuts_ME_L0_L0bar_p1phi_p2phi_US_LS->GetXaxis()->SetTitle("p1_phi");
    h2_no_cuts_ME_L0_L0bar_p1phi_p2phi_US_LS->GetXaxis()->CenterTitle(true);
    h2_no_cuts_ME_L0_L0bar_p1phi_p2phi_US_LS->GetYaxis()->SetTitle("p2_phi");
    h2_no_cuts_ME_L0_L0bar_p1phi_p2phi_US_LS->GetYaxis()->CenterTitle(true);

    std::cout << "Canvas 28 Complete" << std::endl;

    std::unique_ptr<TCanvas> c29(new TCanvas("c29", "Canvas 29", 1800, 900));
    c29->Divide(3, 2);

    c29->cd(1);
    h2_no_cuts_ME_L0_L0_p1pt_p2pt_US_US->Draw("COLZ"); 
    h2_no_cuts_ME_L0_L0_p1pt_p2pt_US_US->SetTitle("Pt- US-US ME #Lambda#Lambda Pairs (no cuts)"); 
    h2_no_cuts_ME_L0_L0_p1pt_p2pt_US_US->GetXaxis()->SetTitle("p1_pt [GeV/c]");
    h2_no_cuts_ME_L0_L0_p1pt_p2pt_US_US->GetXaxis()->CenterTitle(true);
    h2_no_cuts_ME_L0_L0_p1pt_p2pt_US_US->GetYaxis()->SetTitle("p2_pt [GeV/c]");
    h2_no_cuts_ME_L0_L0_p1pt_p2pt_US_US->GetYaxis()->CenterTitle(true);

    c29->cd(2);
    h2_no_cuts_ME_L0_L0_p1eta_p2eta_US_US->Draw("COLZ");
    h2_no_cuts_ME_L0_L0_p1eta_p2eta_US_US->SetTitle("Eta- US-US ME #Lambda#Lambda Pairs (no cuts)");
    h2_no_cuts_ME_L0_L0_p1eta_p2eta_US_US->GetXaxis()->SetTitle("p1_eta");
    h2_no_cuts_ME_L0_L0_p1eta_p2eta_US_US->GetXaxis()->CenterTitle(true);
    h2_no_cuts_ME_L0_L0_p1eta_p2eta_US_US->GetYaxis()->SetTitle("p2_eta");
    h2_no_cuts_ME_L0_L0_p1eta_p2eta_US_US->GetYaxis()->CenterTitle(true);

    c29->cd(3);
    h2_no_cuts_ME_L0_L0_p1phi_p2phi_US_US->Draw("COLZ");
    h2_no_cuts_ME_L0_L0_p1phi_p2phi_US_US->SetTitle("Phi- US-US ME #Lambda#Lambda Pairs (no cuts)");
    h2_no_cuts_ME_L0_L0_p1phi_p2phi_US_US->GetXaxis()->SetTitle("p1_phi");
    h2_no_cuts_ME_L0_L0_p1phi_p2phi_US_US->GetXaxis()->CenterTitle(true);
    h2_no_cuts_ME_L0_L0_p1phi_p2phi_US_US->GetYaxis()->SetTitle("p2_phi");
    h2_no_cuts_ME_L0_L0_p1phi_p2phi_US_US->GetYaxis()->CenterTitle(true);

    c29->cd(4);
    h2_no_cuts_ME_L0_L0_p1pt_p2pt_US_LS->Draw("COLZ"); 
    h2_no_cuts_ME_L0_L0_p1pt_p2pt_US_LS->SetTitle("Pt- US-LS ME #Lambda#Lambda Pairs (no cuts)"); 
    h2_no_cuts_ME_L0_L0_p1pt_p2pt_US_LS->GetXaxis()->SetTitle("p1_pt [GeV/c]");
    h2_no_cuts_ME_L0_L0_p1pt_p2pt_US_LS->GetXaxis()->CenterTitle(true);
    h2_no_cuts_ME_L0_L0_p1pt_p2pt_US_LS->GetYaxis()->SetTitle("p2_pt [GeV/c]");
    h2_no_cuts_ME_L0_L0_p1pt_p2pt_US_LS->GetYaxis()->CenterTitle(true);

    c29->cd(5);
    h2_no_cuts_ME_L0_L0_p1eta_p2eta_US_LS->Draw("COLZ");
    h2_no_cuts_ME_L0_L0_p1eta_p2eta_US_LS->SetTitle("Eta- US-LS ME #Lambda#Lambda Pairs (no cuts)");
    h2_no_cuts_ME_L0_L0_p1eta_p2eta_US_LS->GetXaxis()->SetTitle("p1_eta");
    h2_no_cuts_ME_L0_L0_p1eta_p2eta_US_LS->GetXaxis()->CenterTitle(true);
    h2_no_cuts_ME_L0_L0_p1eta_p2eta_US_LS->GetYaxis()->SetTitle("p2_eta");
    h2_no_cuts_ME_L0_L0_p1eta_p2eta_US_LS->GetYaxis()->CenterTitle(true);

    c29->cd(6);
    h2_no_cuts_ME_L0_L0_p1phi_p2phi_US_LS->Draw("COLZ");
    h2_no_cuts_ME_L0_L0_p1phi_p2phi_US_LS->SetTitle("Phi- US-LS ME #Lambda#Lambda Pairs (no cuts)");
    h2_no_cuts_ME_L0_L0_p1phi_p2phi_US_LS->GetXaxis()->SetTitle("p1_phi");
    h2_no_cuts_ME_L0_L0_p1phi_p2phi_US_LS->GetXaxis()->CenterTitle(true);
    h2_no_cuts_ME_L0_L0_p1phi_p2phi_US_LS->GetYaxis()->SetTitle("p2_phi");
    h2_no_cuts_ME_L0_L0_p1phi_p2phi_US_LS->GetYaxis()->CenterTitle(true);

    std::cout << "Canvas 29 Complete" << std::endl;

    std::unique_ptr<TCanvas> c30(new TCanvas("c30", "Canvas 30", 1800, 900));
    c30->Divide(3, 2);

    c30->cd(1);
    h2_no_cuts_ME_L0bar_L0bar_p1pt_p2pt_US_US->Draw("COLZ"); 
    h2_no_cuts_ME_L0bar_L0bar_p1pt_p2pt_US_US->SetTitle("Pt- US-US ME #bar{#Lambda}#bar{#Lambda} Pairs (no cuts)"); 
    h2_no_cuts_ME_L0bar_L0bar_p1pt_p2pt_US_US->GetXaxis()->SetTitle("p1_pt [GeV/c]");
    h2_no_cuts_ME_L0bar_L0bar_p1pt_p2pt_US_US->GetXaxis()->CenterTitle(true);
    h2_no_cuts_ME_L0bar_L0bar_p1pt_p2pt_US_US->GetYaxis()->SetTitle("p2_pt [GeV/c]");
    h2_no_cuts_ME_L0bar_L0bar_p1pt_p2pt_US_US->GetYaxis()->CenterTitle(true);

    c30->cd(2);
    h2_no_cuts_ME_L0bar_L0bar_p1eta_p2eta_US_US->Draw("COLZ");
    h2_no_cuts_ME_L0bar_L0bar_p1eta_p2eta_US_US->SetTitle("Eta- US-US ME #bar{#Lambda}#bar{#Lambda} Pairs (no cuts)");
    h2_no_cuts_ME_L0bar_L0bar_p1eta_p2eta_US_US->GetXaxis()->SetTitle("p1_eta");
    h2_no_cuts_ME_L0bar_L0bar_p1eta_p2eta_US_US->GetXaxis()->CenterTitle(true);
    h2_no_cuts_ME_L0bar_L0bar_p1eta_p2eta_US_US->GetYaxis()->SetTitle("p2_eta");
    h2_no_cuts_ME_L0bar_L0bar_p1eta_p2eta_US_US->GetYaxis()->CenterTitle(true);

    c30->cd(3);
    h2_no_cuts_ME_L0bar_L0bar_p1phi_p2phi_US_US->Draw("COLZ");
    h2_no_cuts_ME_L0bar_L0bar_p1phi_p2phi_US_US->SetTitle("Phi- US-US ME #bar{#Lambda}#bar{#Lambda} Pairs (no cuts)");
    h2_no_cuts_ME_L0bar_L0bar_p1phi_p2phi_US_US->GetXaxis()->SetTitle("p1_phi");
    h2_no_cuts_ME_L0bar_L0bar_p1phi_p2phi_US_US->GetXaxis()->CenterTitle(true);
    h2_no_cuts_ME_L0bar_L0bar_p1phi_p2phi_US_US->GetYaxis()->SetTitle("p2_phi");
    h2_no_cuts_ME_L0bar_L0bar_p1phi_p2phi_US_US->GetYaxis()->CenterTitle(true);

    c30->cd(4);
    h2_no_cuts_ME_L0bar_L0bar_p1pt_p2pt_US_LS->Draw("COLZ"); 
    h2_no_cuts_ME_L0bar_L0bar_p1pt_p2pt_US_LS->SetTitle("Pt- US-LS ME #bar{#Lambda}#bar{#Lambda} Pairs (no cuts)"); 
    h2_no_cuts_ME_L0bar_L0bar_p1pt_p2pt_US_LS->GetXaxis()->SetTitle("p1_pt [GeV/c]");
    h2_no_cuts_ME_L0bar_L0bar_p1pt_p2pt_US_LS->GetXaxis()->CenterTitle(true);
    h2_no_cuts_ME_L0bar_L0bar_p1pt_p2pt_US_LS->GetYaxis()->SetTitle("p2_pt [GeV/c]");
    h2_no_cuts_ME_L0bar_L0bar_p1pt_p2pt_US_LS->GetYaxis()->CenterTitle(true);

    c30->cd(5);
    h2_no_cuts_ME_L0bar_L0bar_p1eta_p2eta_US_LS->Draw("COLZ");
    h2_no_cuts_ME_L0bar_L0bar_p1eta_p2eta_US_LS->SetTitle("Eta- US-LS ME #bar{#Lambda}#bar{#Lambda} Pairs (no cuts)");
    h2_no_cuts_ME_L0bar_L0bar_p1eta_p2eta_US_LS->GetXaxis()->SetTitle("p1_eta");
    h2_no_cuts_ME_L0bar_L0bar_p1eta_p2eta_US_LS->GetXaxis()->CenterTitle(true);
    h2_no_cuts_ME_L0bar_L0bar_p1eta_p2eta_US_LS->GetYaxis()->SetTitle("p2_eta");
    h2_no_cuts_ME_L0bar_L0bar_p1eta_p2eta_US_LS->GetYaxis()->CenterTitle(true);

    c30->cd(6);
    h2_no_cuts_ME_L0bar_L0bar_p1phi_p2phi_US_LS->Draw("COLZ");
    h2_no_cuts_ME_L0bar_L0bar_p1phi_p2phi_US_LS->SetTitle("Phi- US-LS ME #bar{#Lambda}#bar{#Lambda} Pairs (no cuts)");
    h2_no_cuts_ME_L0bar_L0bar_p1phi_p2phi_US_LS->GetXaxis()->SetTitle("p1_phi");
    h2_no_cuts_ME_L0bar_L0bar_p1phi_p2phi_US_LS->GetXaxis()->CenterTitle(true);
    h2_no_cuts_ME_L0bar_L0bar_p1phi_p2phi_US_LS->GetYaxis()->SetTitle("p2_phi");
    h2_no_cuts_ME_L0bar_L0bar_p1phi_p2phi_US_LS->GetYaxis()->CenterTitle(true);

    std::cout << "Canvas 30 Complete" << std::endl;

    // Background subtractions for the Invariant Mass of the Mixed Events
    TH2F *h2_LLBar_Signal_ME = new TH2F(*mixed_event_SE_lambda_us_S_lambda_bar_us);
    h2_LLBar_Signal_ME->Add(mixed_event_SE_lambda_us_S_lambda_bar_ls, -1.0);

    TH2F *h2_LL_Signal_ME = new TH2F(*mixed_event_SE_lambda_us_S_lambda_us);
    h2_LL_Signal_ME->Add(mixed_event_SE_lambda_us_S_lambda_ls, -1.0);

    TH2F *h2_LBarLBar_Signal_ME = new TH2F(*mixed_event_SE_lambda_bar_us_S_lambda_bar_us);
    h2_LBarLBar_Signal_ME->Add(mixed_event_SE_lambda_bar_us_S_lambda_bar_ls, -1.0);

    // Canvas 6: Invariant Mass Distribution and Gaussian Fit for Mixed Event Pairs
    std::unique_ptr<TCanvas> c31(new TCanvas("c31", "Canvas 31", 1800, 900));
    c31->Divide(3, 1);

    c31->cd(1);
    binMinX_2 = h2_LLBar_Signal_ME->GetXaxis()->FindBin(minX_2);
    binMaxX_2 = h2_LLBar_Signal_ME->GetXaxis()->FindBin(maxX_2);
    binMinY_2 = h2_LLBar_Signal_ME->GetYaxis()->FindBin(minY_2);
    binMaxY_2 = h2_LLBar_Signal_ME->GetYaxis()->FindBin(maxY_2);

    h2_LLBar_Signal_ME->GetXaxis()->SetRange(binMinX_2, binMaxX_2);
    h2_LLBar_Signal_ME->GetYaxis()->SetRange(binMinY_2, binMaxY_2);
    h2_LLBar_Signal_ME->Draw("SURF2");
    h2_LLBar_Signal_ME->SetTitle("ME #Lambda#bar{#Lambda} Pair Inv. Mass Peak");

    c31->cd(2);
    binMinX_2 = h2_LL_Signal_ME->GetXaxis()->FindBin(minX_2);
    binMaxX_2 = h2_LL_Signal_ME->GetXaxis()->FindBin(maxX_2);
    binMinY_2 = h2_LL_Signal_ME->GetYaxis()->FindBin(minY_2);
    binMaxY_2 = h2_LL_Signal_ME->GetYaxis()->FindBin(maxY_2);

    h2_LL_Signal_ME->GetXaxis()->SetRange(binMinX_2, binMaxX_2);
    h2_LL_Signal_ME->GetYaxis()->SetRange(binMinY_2, binMaxY_2);
    h2_LL_Signal_ME->Draw("SURF2");
    h2_LL_Signal_ME->SetTitle("ME #Lambda#Lambda Pair Inv. Mass Peak");

    c31->cd(3);
    binMinX_2 = h2_LBarLBar_Signal_ME->GetXaxis()->FindBin(minX_2);
    binMaxX_2 = h2_LBarLBar_Signal_ME->GetXaxis()->FindBin(maxX_2);
    binMinY_2 = h2_LBarLBar_Signal_ME->GetYaxis()->FindBin(minY_2);
    binMaxY_2 = h2_LBarLBar_Signal_ME->GetYaxis()->FindBin(maxY_2);

    h2_LBarLBar_Signal_ME->GetXaxis()->SetRange(binMinX_2, binMaxX_2);
    h2_LBarLBar_Signal_ME->GetYaxis()->SetRange(binMinY_2, binMaxY_2);
    h2_LBarLBar_Signal_ME->Draw("SURF2");
    h2_LBarLBar_Signal_ME->SetTitle("ME #bar{#Lambda}#bar{#Lambda} Pair Inv. Mass Peak");

    std::cout << "Canvas 31 Complete" << std::endl;

    h_ME_cos_theta_star3->Sumw2();
    h_ME_cos_theta_star4->Sumw2();
    h_ME_cos_theta_star->Sumw2();
    h_ME_cos_theta_star2->Sumw2();
    h_ME_cos_theta_star5->Sumw2();
    h_ME_cos_theta_star6->Sumw2();

    for (size_t i = 0; i < fourmoment_ME_lambda_us_4.size(); ++i){
        double weight_3 = needsbettername3[i];
        double ME_centrality_weight_3 = ME_weight_vector_3[i];

        h2_no_cut_invMass_ME_lambda_us_lambda_bar_us->Fill(fourmoment_ME_lambda_us_4[i].M(), fourmoment_ME_lambda_bar_us_4[i].M(), weight_3 * ME_centrality_weight_3);

        h2_no_cut_check_ME_L0_L0bar_p1pt_p2pt_US_US->Fill(fourmoment_ME_proton_us_4[i].Pt(), fourmoment_ME_anti_proton_us_4[i].Pt(), weight_3 * ME_centrality_weight_3);
        h2_no_cut_check_ME_L0_L0bar_p1eta_p2eta_US_US->Fill(fourmoment_ME_proton_us_4[i].Eta(), fourmoment_ME_anti_proton_us_4[i].Eta(), weight_3 * ME_centrality_weight_3);
        h2_no_cut_check_ME_L0_L0bar_p1phi_p2phi_US_US->Fill(fourmoment_ME_proton_us_4[i].Phi(), fourmoment_ME_anti_proton_us_4[i].Phi(), weight_3 * ME_centrality_weight_3);

        double delta_y = std::fabs(fourmoment_ME_lambda_us_4[i].Rapidity() - fourmoment_ME_lambda_bar_us_4[i].Rapidity());
        double delta_phi = std::fabs(fourmoment_ME_lambda_us_4[i].Phi() - fourmoment_ME_lambda_bar_us_4[i].Phi());

        if (delta_phi > M_PI) delta_phi = 2 * M_PI - delta_phi;
        
        double delta_R = sqrt(delta_y * delta_y + delta_phi * delta_phi);

        h_delta_R_ME_US_US_llbar->Fill(delta_R, weight_3 * ME_centrality_weight_3);
        h_delta_phi_ME_US_US_llbar->Fill(delta_phi, weight_3 * ME_centrality_weight_3);

        double delta_R_Threshold = 0.93;
        if (delta_R > delta_R_Threshold){
            h2_invMass_outside_ME_lambda_us_lambda_bar_us->Fill(fourmoment_ME_lambda_us_4[i].M(), fourmoment_ME_lambda_bar_us_4[i].M(), weight_3 * ME_centrality_weight_3);

            h2_cut_outside_ME_L0_L0bar_p1pt_p2pt_US_US->Fill(fourmoment_ME_proton_us_4[i].Pt(), fourmoment_ME_anti_proton_us_4[i].Pt(), weight_3 * ME_centrality_weight_3);
            h2_cut_outside_ME_L0_L0bar_p1eta_p2eta_US_US->Fill(fourmoment_ME_proton_us_4[i].Eta(), fourmoment_ME_anti_proton_us_4[i].Eta(), weight_3 * ME_centrality_weight_3);
            h2_cut_outside_ME_L0_L0bar_p1phi_p2phi_US_US->Fill(fourmoment_ME_proton_us_4[i].Phi(), fourmoment_ME_anti_proton_us_4[i].Phi(), weight_3 * ME_centrality_weight_3);

            fourmoment_ME_proton_us_4[i].Boost(-fourmoment_ME_lambda_us_4[i].BoostVector());
            fourmoment_ME_anti_proton_us_4[i].Boost(-fourmoment_ME_lambda_bar_us_4[i].BoostVector());
            double outside_ME_theta_star3 = fourmoment_ME_proton_us_4[i].Angle(fourmoment_ME_anti_proton_us_4[i].Vect());
            double outside_ME_cos_theta_star3 = cos(outside_ME_theta_star3);

            h_outside_ME_cos_theta_star3->Fill(outside_ME_cos_theta_star3, weight_3 * ME_centrality_weight_3); 
        } else{
            h2_invMass_ME_lambda_us_lambda_bar_us->Fill(fourmoment_ME_lambda_us_4[i].M(), fourmoment_ME_lambda_bar_us_4[i].M(), weight_3 * ME_centrality_weight_3);

            h2_cut_ME_L0_L0bar_p1pt_p2pt_US_US->Fill(fourmoment_ME_proton_us_4[i].Pt(), fourmoment_ME_anti_proton_us_4[i].Pt(), weight_3 * ME_centrality_weight_3);
            h2_cut_ME_L0_L0bar_p1eta_p2eta_US_US->Fill(fourmoment_ME_proton_us_4[i].Eta(), fourmoment_ME_anti_proton_us_4[i].Eta(), weight_3 * ME_centrality_weight_3);
            h2_cut_ME_L0_L0bar_p1phi_p2phi_US_US->Fill(fourmoment_ME_proton_us_4[i].Phi(), fourmoment_ME_anti_proton_us_4[i].Phi(), weight_3 * ME_centrality_weight_3);

            fourmoment_ME_proton_us_4[i].Boost(-fourmoment_ME_lambda_us_4[i].BoostVector());
            fourmoment_ME_anti_proton_us_4[i].Boost(-fourmoment_ME_lambda_bar_us_4[i].BoostVector());
            double ME_theta_star3 = fourmoment_ME_proton_us_4[i].Angle(fourmoment_ME_anti_proton_us_4[i].Vect());
            double ME_cos_theta_star3 = cos(ME_theta_star3);

            h_ME_cos_theta_star3->Fill(ME_cos_theta_star3, weight_3 * ME_centrality_weight_3);
        }
    }

    for (size_t i = 0; i < fourmoment_ME_lambda_us_5.size(); ++i) {
        double weight_4 = needsbettername4[i];
        double ME_centrality_weight_4 = ME_weight_vector_4[i];

        h2_no_cut_invMass_ME_lambda_us_lambda_bar_ls->Fill(fourmoment_ME_lambda_us_5[i].M(), fourmoment_ME_lambda_bar_ls_5[i].M(), weight_4 * ME_centrality_weight_4);

        h2_no_cut_check_ME_L0_L0bar_p1pt_p2pt_US_LS->Fill(fourmoment_ME_proton_us_5[i].Pt(), fourmoment_ME_anti_proton_ls_5[i].Pt(), weight_4 * ME_centrality_weight_4);
        h2_no_cut_check_ME_L0_L0bar_p1eta_p2eta_US_LS->Fill(fourmoment_ME_proton_us_5[i].Eta(), fourmoment_ME_anti_proton_ls_5[i].Eta(), weight_4 * ME_centrality_weight_4);
        h2_no_cut_check_ME_L0_L0bar_p1phi_p2phi_US_LS->Fill(fourmoment_ME_proton_ls_5[i].Phi(), fourmoment_ME_anti_proton_ls_5[i].Phi(), weight_4 * ME_centrality_weight_4);

        double delta_y = std::fabs(fourmoment_ME_lambda_us_5[i].Rapidity() - fourmoment_ME_lambda_bar_ls_5[i].Rapidity());
        double delta_phi = std::fabs(fourmoment_ME_lambda_us_5[i].Phi() - fourmoment_ME_lambda_bar_ls_5[i].Phi());

        if (delta_phi > M_PI) delta_phi = 2 * M_PI - delta_phi;
        
        double delta_R = sqrt(delta_y * delta_y + delta_phi * delta_phi);

        h_delta_R_ME_US_LS_llbar->Fill(delta_R, weight_4 * ME_centrality_weight_4);
        h_delta_phi_ME_US_LS_llbar->Fill(delta_phi, weight_4 * ME_centrality_weight_4);

        double delta_R_Threshold = 0.93;
        if (delta_R > delta_R_Threshold){
            h2_invMass_outside_ME_lambda_us_lambda_bar_ls->Fill(fourmoment_ME_lambda_us_5[i].M(), fourmoment_ME_lambda_bar_ls_5[i].M(), weight_4 * ME_centrality_weight_4);

            h2_cut_outside_ME_L0_L0bar_p1pt_p2pt_US_LS->Fill(fourmoment_ME_proton_us_5[i].Pt(), fourmoment_ME_anti_proton_ls_5[i].Pt(), weight_4 * ME_centrality_weight_4);
            h2_cut_outside_ME_L0_L0bar_p1eta_p2eta_US_LS->Fill(fourmoment_ME_proton_us_5[i].Eta(), fourmoment_ME_anti_proton_ls_5[i].Eta(), weight_4 * ME_centrality_weight_4);
            h2_cut_outside_ME_L0_L0bar_p1phi_p2phi_US_LS->Fill(fourmoment_ME_proton_ls_5[i].Phi(), fourmoment_ME_anti_proton_ls_5[i].Phi(), weight_4 * ME_centrality_weight_4);

            fourmoment_ME_proton_us_5[i].Boost(-fourmoment_ME_lambda_us_5[i].BoostVector());
            fourmoment_ME_anti_proton_ls_5[i].Boost(-fourmoment_ME_lambda_bar_ls_5[i].BoostVector());
            double outside_ME_theta_star4 = fourmoment_ME_proton_us_5[i].Angle(fourmoment_ME_anti_proton_ls_5[i].Vect());
            double outside_ME_cos_theta_star4 = cos(outside_ME_theta_star4);

            h_outside_ME_cos_theta_star4->Fill(outside_ME_cos_theta_star4, weight_4 * ME_centrality_weight_4);
        } else{
            h2_invMass_ME_lambda_us_lambda_bar_ls->Fill(fourmoment_ME_lambda_us_5[i].M(), fourmoment_ME_lambda_bar_ls_5[i].M(), weight_4 * ME_centrality_weight_4);

            h2_cut_ME_L0_L0bar_p1pt_p2pt_US_LS->Fill(fourmoment_ME_proton_us_5[i].Pt(), fourmoment_ME_anti_proton_ls_5[i].Pt(), weight_4 * ME_centrality_weight_4);
            h2_cut_ME_L0_L0bar_p1eta_p2eta_US_LS->Fill(fourmoment_ME_proton_us_5[i].Eta(), fourmoment_ME_anti_proton_ls_5[i].Eta(), weight_4 * ME_centrality_weight_4);
            h2_cut_ME_L0_L0bar_p1phi_p2phi_US_LS->Fill(fourmoment_ME_proton_ls_5[i].Phi(), fourmoment_ME_anti_proton_ls_5[i].Phi(), weight_4 * ME_centrality_weight_4);

            fourmoment_ME_proton_us_5[i].Boost(-fourmoment_ME_lambda_us_5[i].BoostVector());
            fourmoment_ME_anti_proton_ls_5[i].Boost(-fourmoment_ME_lambda_bar_ls_5[i].BoostVector());
            double ME_theta_star4 = fourmoment_ME_proton_us_5[i].Angle(fourmoment_ME_anti_proton_ls_5[i].Vect());
            double ME_cos_theta_star4 = cos(ME_theta_star4);

            h_ME_cos_theta_star4->Fill(ME_cos_theta_star4, weight_4 * ME_centrality_weight_4);
        }
    }

    for (size_t i = 0; i < fourmoment_ME_lambda_ls_5.size(); ++i) {
        double weight_5 = needsbettername5[i];
        double ME_centrality_weight_5 = ME_weight_vector_5[i];

        h2_no_cut_invMass_ME_lambda_us_lambda_bar_ls->Fill(fourmoment_ME_lambda_ls_5[i].M(), fourmoment_ME_lambda_bar_us_5[i].M(), weight_5 * ME_centrality_weight_5);

        h2_no_cut_check_ME_L0_L0bar_p1pt_p2pt_US_LS->Fill(fourmoment_ME_proton_ls_5[i].Pt(), fourmoment_ME_anti_proton_us_5[i].Pt(), weight_5 * ME_centrality_weight_5);
        h2_no_cut_check_ME_L0_L0bar_p1eta_p2eta_US_LS->Fill(fourmoment_ME_proton_ls_5[i].Eta(), fourmoment_ME_anti_proton_us_5[i].Eta(), weight_5 * ME_centrality_weight_5);
        h2_no_cut_check_ME_L0_L0bar_p1phi_p2phi_US_LS->Fill(fourmoment_ME_proton_ls_5[i].Phi(), fourmoment_ME_anti_proton_us_5[i].Phi(), weight_5 * ME_centrality_weight_5);

        double delta_y = std::fabs(fourmoment_ME_lambda_ls_5[i].Rapidity() - fourmoment_ME_lambda_bar_us_5[i].Rapidity());
        double delta_phi = std::fabs(fourmoment_ME_lambda_ls_5[i].Phi() - fourmoment_ME_lambda_bar_us_5[i].Phi());

        if (delta_phi > M_PI) delta_phi = 2 * M_PI - delta_phi;
        
        double delta_R = sqrt(delta_y * delta_y + delta_phi * delta_phi);

        h_delta_R_ME_US_LS_llbar->Fill(delta_R, weight_5 * ME_centrality_weight_5);
        h_delta_phi_ME_US_LS_llbar->Fill(delta_phi, weight_5 * ME_centrality_weight_5);

        double delta_R_Threshold = 0.93;
        if (delta_R > delta_R_Threshold){
            h2_invMass_outside_ME_lambda_us_lambda_bar_ls->Fill(fourmoment_ME_lambda_ls_5[i].M(), fourmoment_ME_lambda_bar_us_5[i].M(), weight_5 * ME_centrality_weight_5);

            h2_cut_outside_ME_L0_L0bar_p1pt_p2pt_US_LS->Fill(fourmoment_ME_proton_ls_5[i].Pt(), fourmoment_ME_anti_proton_us_5[i].Pt(), weight_5 * ME_centrality_weight_5);
            h2_cut_outside_ME_L0_L0bar_p1eta_p2eta_US_LS->Fill(fourmoment_ME_proton_ls_5[i].Eta(), fourmoment_ME_anti_proton_us_5[i].Eta(), weight_5 * ME_centrality_weight_5);
            h2_cut_outside_ME_L0_L0bar_p1phi_p2phi_US_LS->Fill(fourmoment_ME_proton_ls_5[i].Phi(), fourmoment_ME_anti_proton_us_5[i].Phi(), weight_5 * ME_centrality_weight_5);

            fourmoment_ME_proton_ls_5[i].Boost(-fourmoment_ME_lambda_ls_5[i].BoostVector());
            fourmoment_ME_anti_proton_us_5[i].Boost(-fourmoment_ME_lambda_bar_us_5[i].BoostVector());
            double outside_ME_theta_star4 = fourmoment_ME_proton_ls_5[i].Angle(fourmoment_ME_anti_proton_us_5[i].Vect());
            double outside_ME_cos_theta_star4 = cos(outside_ME_theta_star4);

            h_outside_ME_cos_theta_star4->Fill(outside_ME_cos_theta_star4, weight_5 * ME_centrality_weight_5);           
        } else{
            h2_invMass_ME_lambda_us_lambda_bar_ls->Fill(fourmoment_ME_lambda_ls_5[i].M(), fourmoment_ME_lambda_bar_us_5[i].M(), weight_5 * ME_centrality_weight_5);

            h2_cut_outside_ME_L0_L0bar_p1pt_p2pt_US_LS->Fill(fourmoment_ME_proton_ls_5[i].Pt(), fourmoment_ME_anti_proton_us_5[i].Pt(), weight_5 * ME_centrality_weight_5);
            h2_cut_outside_ME_L0_L0bar_p1eta_p2eta_US_LS->Fill(fourmoment_ME_proton_ls_5[i].Eta(), fourmoment_ME_anti_proton_us_5[i].Eta(), weight_5 * ME_centrality_weight_5);
            h2_cut_outside_ME_L0_L0bar_p1phi_p2phi_US_LS->Fill(fourmoment_ME_proton_ls_5[i].Phi(), fourmoment_ME_anti_proton_us_5[i].Phi(), weight_5 * ME_centrality_weight_5);

            fourmoment_ME_proton_ls_5[i].Boost(-fourmoment_ME_lambda_ls_5[i].BoostVector());
            fourmoment_ME_anti_proton_us_5[i].Boost(-fourmoment_ME_lambda_bar_us_5[i].BoostVector());
            double ME_theta_star4 = fourmoment_ME_proton_ls_5[i].Angle(fourmoment_ME_anti_proton_us_5[i].Vect());
            double ME_cos_theta_star4 = cos(ME_theta_star4);

            h_ME_cos_theta_star4->Fill(ME_cos_theta_star4, weight_5 * ME_centrality_weight_5);
        }
    }

    for (size_t i = 0; i < fourmoment_ME_lambda_us_1.size(); ++i) {
        double weight_1 = needsbettername[i];
        double ME_centrality_weight_1 = ME_weight_vector_1[i];

        h2_no_cut_invMass_ME_lambda_us_lambda_us->Fill(fourmoment_ME_lambda_us_1[i].M(), fourmoment_ME_lambda_us_2[i].M(), weight_1 * ME_centrality_weight_1);

        h2_no_cut_check_ME_L0_L0_p1pt_p2pt_US_US->Fill(fourmoment_ME_proton_us_1[i].Pt(), fourmoment_ME_proton_us_2[i].Pt(), weight_1 * ME_centrality_weight_1);
        h2_no_cut_check_ME_L0_L0_p1eta_p2eta_US_US->Fill(fourmoment_ME_proton_us_1[i].Eta(), fourmoment_ME_proton_us_2[i].Eta(), weight_1 * ME_centrality_weight_1);
        h2_no_cut_check_ME_L0_L0_p1phi_p2phi_US_US->Fill(fourmoment_ME_proton_us_1[i].Phi(), fourmoment_ME_proton_us_2[i].Phi(), weight_1 * ME_centrality_weight_1);

        double delta_y = std::fabs(fourmoment_ME_lambda_us_1[i].Rapidity() - fourmoment_ME_lambda_us_2[i].Rapidity());
        double delta_phi = std::fabs(fourmoment_ME_lambda_us_1[i].Phi() - fourmoment_ME_lambda_us_2[i].Phi());
        if (delta_phi > M_PI) delta_phi = 2 * M_PI - delta_phi;
            
        double delta_R = sqrt(delta_y * delta_y + delta_phi * delta_phi);

        h_delta_R_ME_US_US_ll->Fill(delta_R, weight_1 * ME_centrality_weight_1);
        h_delta_phi_ME_US_US_ll->Fill(delta_phi, weight_1 * ME_centrality_weight_1);

        double delta_R_Threshold = 0.93;
        if (delta_R > delta_R_Threshold){
            h2_invMass_outside_ME_lambda_us_lambda_us->Fill(fourmoment_ME_lambda_us_1[i].M(), fourmoment_ME_lambda_us_2[i].M(), weight_1 * ME_centrality_weight_1);

            h2_cut_outside_ME_L0_L0_p1pt_p2pt_US_US->Fill(fourmoment_ME_anti_proton_us_1[i].Pt(), fourmoment_ME_anti_proton_us_2[i].Pt(), weight_1 * ME_centrality_weight_1);
            h2_cut_outside_ME_L0_L0_p1eta_p2eta_US_US->Fill(fourmoment_ME_anti_proton_us_1[i].Eta(), fourmoment_ME_anti_proton_us_2[i].Eta(), weight_1 * ME_centrality_weight_1);
            h2_cut_outside_ME_L0_L0_p1phi_p2phi_US_US->Fill(fourmoment_ME_anti_proton_us_1[i].Phi(), fourmoment_ME_anti_proton_us_2[i].Phi(), weight_1 * ME_centrality_weight_1);

            fourmoment_ME_proton_us_1[i].Boost(-fourmoment_ME_lambda_us_1[i].BoostVector());
            fourmoment_ME_proton_us_2[i].Boost(-fourmoment_ME_lambda_us_2[i].BoostVector());
            double outside_ME_theta_star = fourmoment_ME_proton_us_1[i].Angle(fourmoment_ME_proton_us_2[i].Vect());
            double outside_ME_cos_theta_star = cos(outside_ME_theta_star);

            h_outside_ME_cos_theta_star->Fill(outside_ME_cos_theta_star, weight_1 * ME_centrality_weight_1);
        } else{
            h2_invMass_ME_lambda_us_lambda_us->Fill(fourmoment_ME_lambda_us_1[i].M(), fourmoment_ME_lambda_us_2[i].M(), weight_1 * ME_centrality_weight_1);

            h2_cut_ME_L0_L0_p1pt_p2pt_US_US->Fill(fourmoment_ME_anti_proton_us_1[i].Pt(), fourmoment_ME_anti_proton_us_2[i].Pt(), weight_1 * ME_centrality_weight_1);
            h2_cut_ME_L0_L0_p1eta_p2eta_US_US->Fill(fourmoment_ME_anti_proton_us_1[i].Eta(), fourmoment_ME_anti_proton_us_2[i].Eta(), weight_1 * ME_centrality_weight_1);
            h2_cut_ME_L0_L0_p1phi_p2phi_US_US->Fill(fourmoment_ME_anti_proton_us_1[i].Phi(), fourmoment_ME_anti_proton_us_2[i].Phi(), weight_1 * ME_centrality_weight_1);

            fourmoment_ME_proton_us_1[i].Boost(-fourmoment_ME_lambda_us_1[i].BoostVector());
            fourmoment_ME_proton_us_2[i].Boost(-fourmoment_ME_lambda_us_2[i].BoostVector());
            double ME_theta_star = fourmoment_ME_proton_us_1[i].Angle(fourmoment_ME_proton_us_2[i].Vect());
            double ME_cos_theta_star = cos(ME_theta_star);

            h_ME_cos_theta_star->Fill(ME_cos_theta_star, weight_1 * ME_centrality_weight_1);
        }
    }

    for (size_t i = 0; i < fourmoment_ME_lambda_us_3.size(); ++i){
        double weight_2 = needsbettername2[i];
        double ME_centrality_weight_2 = ME_weight_vector_2[i];

        h2_no_cut_invMass_ME_lambda_us_lambda_ls->Fill(fourmoment_ME_lambda_us_3[i].M(), fourmoment_ME_lambda_ls_3[i].M(), weight_2 * ME_centrality_weight_2);

        h2_no_cut_check_ME_L0_L0_p1pt_p2pt_US_LS->Fill(fourmoment_ME_proton_us_3[i].Pt(), fourmoment_ME_proton_ls_3[i].Pt(), weight_2 * ME_centrality_weight_2);
        h2_no_cut_check_ME_L0_L0_p1eta_p2eta_US_LS->Fill(fourmoment_ME_proton_us_3[i].Eta(), fourmoment_ME_proton_ls_3[i].Eta(), weight_2 * ME_centrality_weight_2);
        h2_no_cut_check_ME_L0_L0_p1phi_p2phi_US_LS->Fill(fourmoment_ME_proton_us_3[i].Phi(), fourmoment_ME_proton_ls_3[i].Phi(), weight_2 * ME_centrality_weight_2);

        double delta_y = std::fabs(fourmoment_ME_lambda_us_3[i].Rapidity() - fourmoment_ME_lambda_ls_3[i].Rapidity());
        double delta_phi = std::fabs(fourmoment_ME_lambda_us_3[i].Phi() - fourmoment_ME_lambda_ls_3[i].Phi());

        if (delta_phi > M_PI) delta_phi = 2 * M_PI - delta_phi;
        
        double delta_R = sqrt(delta_y * delta_y + delta_phi * delta_phi);

        h_delta_R_ME_US_LS_ll->Fill(delta_R, weight_2 * ME_centrality_weight_2);
        h_delta_phi_ME_US_LS_ll->Fill(delta_phi, weight_2 * ME_centrality_weight_2);

        double delta_R_Threshold = 0.93;
        if (delta_R > delta_R_Threshold){
            h2_invMass_outside_ME_lambda_us_lambda_ls->Fill(fourmoment_ME_lambda_us_3[i].M(), fourmoment_ME_lambda_ls_3[i].M(), weight_2 * ME_centrality_weight_2);

            h2_cut_outside_ME_L0_L0_p1pt_p2pt_US_LS->Fill(fourmoment_ME_proton_us_3[i].Pt(), fourmoment_ME_proton_ls_3[i].Pt(), weight_2 * ME_centrality_weight_2);
            h2_cut_outside_ME_L0_L0_p1eta_p2eta_US_LS->Fill(fourmoment_ME_proton_us_3[i].Eta(), fourmoment_ME_proton_ls_3[i].Eta(), weight_2 * ME_centrality_weight_2);
            h2_cut_outside_ME_L0_L0_p1phi_p2phi_US_LS->Fill(fourmoment_ME_proton_us_3[i].Phi(), fourmoment_ME_proton_ls_3[i].Phi(), weight_2 * ME_centrality_weight_2);
       
            fourmoment_ME_proton_us_3[i].Boost(-fourmoment_ME_lambda_us_3[i].BoostVector());
            fourmoment_ME_proton_ls_3[i].Boost(-fourmoment_ME_lambda_ls_3[i].BoostVector());
            double outside_ME_theta_star2 = fourmoment_ME_proton_us_3[i].Angle(fourmoment_ME_proton_ls_3[i].Vect());
            double outside_ME_cos_theta_star2 = cos(outside_ME_theta_star2);

            h_outside_ME_cos_theta_star2->Fill(outside_ME_cos_theta_star2, weight_2 * ME_centrality_weight_2);
        } else{
            h2_invMass_ME_lambda_us_lambda_ls->Fill(fourmoment_ME_lambda_us_3[i].M(), fourmoment_ME_lambda_ls_3[i].M(), weight_2 * ME_centrality_weight_2);

            h2_cut_ME_L0_L0_p1pt_p2pt_US_LS->Fill(fourmoment_ME_proton_us_3[i].Pt(), fourmoment_ME_proton_ls_3[i].Pt(), weight_2 * ME_centrality_weight_2);
            h2_cut_ME_L0_L0_p1eta_p2eta_US_LS->Fill(fourmoment_ME_proton_us_3[i].Eta(), fourmoment_ME_proton_ls_3[i].Eta(), weight_2 * ME_centrality_weight_2);
            h2_cut_ME_L0_L0_p1phi_p2phi_US_LS->Fill(fourmoment_ME_proton_us_3[i].Phi(), fourmoment_ME_proton_ls_3[i].Phi(), weight_2 * ME_centrality_weight_2);
       
            fourmoment_ME_proton_us_3[i].Boost(-fourmoment_ME_lambda_us_3[i].BoostVector());
            fourmoment_ME_proton_ls_3[i].Boost(-fourmoment_ME_lambda_ls_3[i].BoostVector());
            double ME_theta_star2 = fourmoment_ME_proton_us_3[i].Angle(fourmoment_ME_proton_ls_3[i].Vect());
            double ME_cos_theta_star2 = cos(ME_theta_star2);

            h_ME_cos_theta_star2->Fill(ME_cos_theta_star2, weight_2 * ME_centrality_weight_2);
        }
    }

    for (size_t i = 0; i < fourmoment_ME_lambda_bar_us_1.size(); ++i) {
        double weight_6 = needsbettername6[i];
        double ME_centrality_weight_6 = ME_weight_vector_6[i];

        h2_no_cut_invMass_ME_lambda_bar_us_lambda_bar_us->Fill(fourmoment_ME_lambda_bar_us_1[i].M(), fourmoment_ME_lambda_bar_us_2[i].M(), weight_6 * ME_centrality_weight_6);

        h2_no_cut_check_ME_L0bar_L0bar_p1pt_p2pt_US_US->Fill(fourmoment_ME_anti_proton_us_1[i].Pt(), fourmoment_ME_anti_proton_us_2[i].Pt(), weight_6 * ME_centrality_weight_6);
        h2_no_cut_check_ME_L0bar_L0bar_p1eta_p2eta_US_US->Fill(fourmoment_ME_anti_proton_us_1[i].Eta(), fourmoment_ME_anti_proton_us_2[i].Eta(), weight_6 * ME_centrality_weight_6);
        h2_no_cut_check_ME_L0bar_L0bar_p1phi_p2phi_US_US->Fill(fourmoment_ME_anti_proton_us_1[i].Phi(), fourmoment_ME_anti_proton_us_2[i].Phi(), weight_6 * ME_centrality_weight_6);

        double delta_y = std::fabs(fourmoment_ME_lambda_bar_us_1[i].Rapidity() - fourmoment_ME_lambda_bar_us_2[i].Rapidity());
        double delta_phi = std::fabs(fourmoment_ME_lambda_bar_us_1[i].Phi() - fourmoment_ME_lambda_bar_us_2[i].Phi());

        if (delta_phi > M_PI) delta_phi = 2 * M_PI - delta_phi;
        
        double delta_R = sqrt(delta_y * delta_y + delta_phi * delta_phi);

        h_delta_R_ME_US_US_lbarlbar->Fill(delta_R, weight_6 * ME_centrality_weight_6);
        h_delta_phi_ME_US_US_lbarlbar->Fill(delta_phi, weight_6 * ME_centrality_weight_6);

        double delta_R_Threshold = 0.93;
        if (delta_R > delta_R_Threshold){
            h2_invMass_outside_ME_lambda_bar_us_lambda_bar_us->Fill(fourmoment_ME_lambda_bar_us_1[i].M(), fourmoment_ME_lambda_bar_us_2[i].M(), weight_6 * ME_centrality_weight_6);

            h2_cut_outside_ME_L0bar_L0bar_p1pt_p2pt_US_US->Fill(fourmoment_ME_anti_proton_us_1[i].Pt(), fourmoment_ME_anti_proton_us_2[i].Pt(), weight_6 * ME_centrality_weight_6);
            h2_cut_outside_ME_L0bar_L0bar_p1eta_p2eta_US_US->Fill(fourmoment_ME_anti_proton_us_1[i].Eta(), fourmoment_ME_anti_proton_us_2[i].Eta(), weight_6 * ME_centrality_weight_6);
            h2_cut_outside_ME_L0bar_L0bar_p1phi_p2phi_US_US->Fill(fourmoment_ME_anti_proton_us_1[i].Phi(), fourmoment_ME_anti_proton_us_2[i].Phi(), weight_6 * ME_centrality_weight_6);

            fourmoment_ME_anti_proton_us_1[i].Boost(-fourmoment_ME_lambda_bar_us_1[i].BoostVector());
            fourmoment_ME_anti_proton_us_2[i].Boost(-fourmoment_ME_lambda_bar_us_2[i].BoostVector());
            double outside_ME_theta_star5 = fourmoment_ME_anti_proton_us_1[i].Angle(fourmoment_ME_anti_proton_us_2[i].Vect());
            double outside_ME_cos_theta_star5 = cos(outside_ME_theta_star5);

            h_outside_ME_cos_theta_star5->Fill(outside_ME_cos_theta_star5, weight_6 * ME_centrality_weight_6);
        } else{
            h2_invMass_ME_lambda_bar_us_lambda_bar_us->Fill(fourmoment_ME_lambda_bar_us_1[i].M(), fourmoment_ME_lambda_bar_us_2[i].M(), weight_6 * ME_centrality_weight_6);

            h2_cut_ME_L0bar_L0bar_p1pt_p2pt_US_US->Fill(fourmoment_ME_anti_proton_us_1[i].Pt(), fourmoment_ME_anti_proton_us_2[i].Pt(), weight_6 * ME_centrality_weight_6);
            h2_cut_ME_L0bar_L0bar_p1eta_p2eta_US_US->Fill(fourmoment_ME_anti_proton_us_1[i].Eta(), fourmoment_ME_anti_proton_us_2[i].Eta(), weight_6 * ME_centrality_weight_6);
            h2_cut_ME_L0bar_L0bar_p1phi_p2phi_US_US->Fill(fourmoment_ME_anti_proton_us_1[i].Phi(), fourmoment_ME_anti_proton_us_2[i].Phi(), weight_6 * ME_centrality_weight_6);

            fourmoment_ME_anti_proton_us_1[i].Boost(-fourmoment_ME_lambda_bar_us_1[i].BoostVector());
            fourmoment_ME_anti_proton_us_2[i].Boost(-fourmoment_ME_lambda_bar_us_2[i].BoostVector());
            double ME_theta_star5 = fourmoment_ME_anti_proton_us_1[i].Angle(fourmoment_ME_anti_proton_us_2[i].Vect());
            double ME_cos_theta_star5 = cos(ME_theta_star5);

            h_ME_cos_theta_star5->Fill(ME_cos_theta_star5, weight_6 * ME_centrality_weight_6);
        }
    }

    for (size_t i = 0; i < fourmoment_ME_lambda_bar_us_6.size(); ++i) {
        double weight_7 = needsbettername7[i];
        double ME_centrality_weight_7 = ME_weight_vector_7[i];

        h2_no_cut_invMass_ME_lambda_bar_us_lambda_bar_ls->Fill(fourmoment_ME_lambda_bar_us_6[i].M(), fourmoment_ME_lambda_bar_ls_6[i].M(), weight_7 * ME_centrality_weight_7);

        h2_no_cut_check_ME_L0bar_L0bar_p1pt_p2pt_US_LS->Fill(fourmoment_ME_anti_proton_us_6[i].Pt(), fourmoment_ME_anti_proton_ls_6[i].Pt(), weight_7 * ME_centrality_weight_7);
        h2_no_cut_check_ME_L0bar_L0bar_p1eta_p2eta_US_LS->Fill(fourmoment_ME_anti_proton_us_6[i].Eta(), fourmoment_ME_anti_proton_ls_6[i].Eta(), weight_7 * ME_centrality_weight_7);
        h2_no_cut_check_ME_L0bar_L0bar_p1phi_p2phi_US_LS->Fill(fourmoment_ME_anti_proton_us_6[i].Phi(), fourmoment_ME_anti_proton_ls_6[i].Phi(), weight_7 * ME_centrality_weight_7);

        double delta_y = std::fabs(fourmoment_ME_lambda_bar_us_6[i].Rapidity() - fourmoment_ME_lambda_bar_us_6[i].Rapidity());
        double delta_phi = std::fabs(fourmoment_ME_lambda_bar_us_6[i].Phi() - fourmoment_ME_lambda_bar_ls_6[i].Phi());

        if (delta_phi > M_PI) delta_phi = 2 * M_PI - delta_phi;
        
        double delta_R = sqrt(delta_y * delta_y + delta_phi * delta_phi);

        h_delta_R_ME_US_LS_lbarlbar->Fill(delta_R, weight_7 * ME_centrality_weight_7);
        h_delta_phi_ME_US_LS_lbarlbar->Fill(delta_phi, weight_7 * ME_centrality_weight_7);

        double delta_R_Threshold = 0.93;
        if (delta_R > delta_R_Threshold){
            h2_invMass_outside_ME_lambda_bar_us_lambda_bar_ls->Fill(fourmoment_ME_lambda_bar_us_6[i].M(), fourmoment_ME_lambda_bar_ls_6[i].M(), weight_7 * ME_centrality_weight_7);

            h2_cut_outside_ME_L0bar_L0bar_p1pt_p2pt_US_LS->Fill(fourmoment_ME_anti_proton_us_6[i].Pt(), fourmoment_ME_anti_proton_ls_6[i].Pt(), weight_7 * ME_centrality_weight_7);
            h2_cut_outside_ME_L0bar_L0bar_p1eta_p2eta_US_LS->Fill(fourmoment_ME_anti_proton_us_6[i].Eta(), fourmoment_ME_anti_proton_ls_6[i].Eta(), weight_7 * ME_centrality_weight_7);
            h2_cut_outside_ME_L0bar_L0bar_p1phi_p2phi_US_LS->Fill(fourmoment_ME_anti_proton_us_6[i].Phi(), fourmoment_ME_anti_proton_ls_6[i].Phi(), weight_7 * ME_centrality_weight_7);

            fourmoment_ME_anti_proton_us_6[i].Boost(-fourmoment_ME_lambda_bar_us_6[i].BoostVector());
            fourmoment_ME_anti_proton_ls_6[i].Boost(-fourmoment_ME_lambda_bar_ls_6[i].BoostVector());
            double outside_ME_theta_star6 = fourmoment_ME_anti_proton_us_6[i].Angle(fourmoment_ME_anti_proton_ls_6[i].Vect());
            double outside_ME_cos_theta_star6 = cos(outside_ME_theta_star6);

            h_outside_ME_cos_theta_star6->Fill(outside_ME_cos_theta_star6, weight_7 * ME_centrality_weight_7);
        } else{
            h2_invMass_ME_lambda_bar_us_lambda_bar_ls->Fill(fourmoment_ME_lambda_bar_us_6[i].M(), fourmoment_ME_lambda_bar_ls_6[i].M(), weight_7 * ME_centrality_weight_7);

            h2_cut_ME_L0bar_L0bar_p1pt_p2pt_US_LS->Fill(fourmoment_ME_anti_proton_us_6[i].Pt(), fourmoment_ME_anti_proton_ls_6[i].Pt(), weight_7 * ME_centrality_weight_7);
            h2_cut_ME_L0bar_L0bar_p1eta_p2eta_US_LS->Fill(fourmoment_ME_anti_proton_us_6[i].Eta(), fourmoment_ME_anti_proton_ls_6[i].Eta(), weight_7 * ME_centrality_weight_7);
            h2_cut_ME_L0bar_L0bar_p1phi_p2phi_US_LS->Fill(fourmoment_ME_anti_proton_us_6[i].Phi(), fourmoment_ME_anti_proton_ls_6[i].Phi(), weight_7 * ME_centrality_weight_7);

            fourmoment_ME_anti_proton_us_6[i].Boost(-fourmoment_ME_lambda_bar_us_6[i].BoostVector());
            fourmoment_ME_anti_proton_ls_6[i].Boost(-fourmoment_ME_lambda_bar_ls_6[i].BoostVector());
            double ME_theta_star6 = fourmoment_ME_anti_proton_us_6[i].Angle(fourmoment_ME_anti_proton_ls_6[i].Vect());
            double ME_cos_theta_star6 = cos(ME_theta_star6);

            h_ME_cos_theta_star6->Fill(ME_cos_theta_star6, weight_7 * ME_centrality_weight_7); 
        }
    }

    cout << "Mixed Event dN/dCos(theta*) Calculations Complete :)" << endl;

    double outside_counts_Minv_ME_signal_llbar = h2_invMass_outside_ME_lambda_us_lambda_bar_us->Integral();
    double outside_counts_Minv_ME_background_llbar = h2_invMass_outside_ME_lambda_us_lambda_bar_ls->Integral();
    double outside_counts_Minv_ME_signal_ll = h2_invMass_outside_ME_lambda_us_lambda_us->Integral();
    double outside_counts_Minv_ME_background_ll = h2_invMass_outside_ME_lambda_us_lambda_ls->Integral();
    double outside_counts_Minv_ME_signal_lbarlbar = h2_invMass_outside_ME_lambda_bar_us_lambda_bar_us->Integral();
    double outside_counts_Minv_ME_background_lbarlbar = h2_invMass_outside_ME_lambda_bar_us_lambda_bar_ls->Integral();

    std::cout << "  " << std::endl;
    std::cout << "**Mixed Event Pairs (after cuts)**" << std::endl;
    std::cout << "US Lambda - US Lambda Bar Pair: " << outside_counts_Minv_ME_signal_llbar << std::endl;
    std::cout << "US Lambda - LS Lambda Bar Pair: " << outside_counts_Minv_ME_background_llbar << std::endl;
    std::cout << "US Lambda - US Lambda Pair: " << outside_counts_Minv_ME_signal_ll << std::endl;
    std::cout << "US Lambda - LS Lambda Pair: " << outside_counts_Minv_ME_background_ll << std::endl;
    std::cout << "US Lambda Bar - US Lambda Bar Pair: " << outside_counts_Minv_ME_signal_lbarlbar << std::endl;
    std::cout << "US Lambda Bar - LS Lambda Bar Pair: " << outside_counts_Minv_ME_background_lbarlbar << std::endl;
    std::cout << "  " << std::endl;

    double counts_Minv_ME_signal_llbar = h2_invMass_ME_lambda_us_lambda_bar_us->Integral();
    double counts_Minv_ME_background_llbar = h2_invMass_ME_lambda_us_lambda_bar_ls->Integral();
    double counts_Minv_ME_signal_ll = h2_invMass_ME_lambda_us_lambda_us->Integral();
    double counts_Minv_ME_background_ll = h2_invMass_ME_lambda_us_lambda_ls->Integral();
    double counts_Minv_ME_signal_lbarlbar = h2_invMass_ME_lambda_bar_us_lambda_bar_us->Integral();
    double counts_Minv_ME_background_lbarlbar = h2_invMass_ME_lambda_bar_us_lambda_bar_ls->Integral();

    std::cout << "  " << std::endl;
    std::cout << "**Mixed Event Pairs (after cuts)**" << std::endl;
    std::cout << "US Lambda - US Lambda Bar Pair: " << counts_Minv_ME_signal_llbar << std::endl;
    std::cout << "US Lambda - LS Lambda Bar Pair: " << counts_Minv_ME_background_llbar << std::endl;
    std::cout << "US Lambda - US Lambda Pair: " << counts_Minv_ME_signal_ll << std::endl;
    std::cout << "US Lambda - LS Lambda Pair: " << counts_Minv_ME_background_ll << std::endl;
    std::cout << "US Lambda Bar - US Lambda Bar Pair: " << counts_Minv_ME_signal_lbarlbar << std::endl;
    std::cout << "US Lambda Bar - LS Lambda Bar Pair: " << counts_Minv_ME_background_lbarlbar << std::endl;
    std::cout << "  " << std::endl;

    double minX_ME_2 = 1.11;
    double maxX_ME_2 = 1.12;
    double minY_ME_2 = 1.11;
    double maxY_ME_2 = 1.12;
    
    std::unique_ptr<TCanvas> c32(new TCanvas("c32", "Canvas 32", 1800, 900));
    c32->Divide(3, 1);

    // Lambda - Lambda Bar Signal 
    TH2F *h2_invMass_ME_LLBar_Signal = new TH2F(*h2_invMass_ME_lambda_us_lambda_bar_us);
    h2_invMass_ME_LLBar_Signal->Add(h2_invMass_ME_lambda_us_lambda_bar_ls, -1.0);

    c32->cd(1);
    int binMinX_ME_2 = h2_invMass_ME_LLBar_Signal->GetXaxis()->FindBin(minX_ME_2);
    int binMaxX_ME_2 = h2_invMass_ME_LLBar_Signal->GetXaxis()->FindBin(maxX_ME_2);
    int binMinY_ME_2 = h2_invMass_ME_LLBar_Signal->GetYaxis()->FindBin(minY_ME_2);
    int binMaxY_ME_2 = h2_invMass_ME_LLBar_Signal->GetYaxis()->FindBin(maxY_ME_2);

    h2_invMass_ME_LLBar_Signal->GetXaxis()->SetRange(binMinX_ME_2, binMaxX_ME_2);
    h2_invMass_ME_LLBar_Signal->GetYaxis()->SetRange(binMinY_ME_2, binMaxY_ME_2);
    h2_invMass_ME_LLBar_Signal->Draw("SURF2");
    h2_invMass_ME_LLBar_Signal->SetTitle("ME #Lambda#bar{#Lambda} Pair Inv. Mass Peak (check on ME pairs)");

    // Lambda - Lambda Signal
    TH2F *h2_invMass_ME_LL_Signal = new TH2F(*h2_invMass_ME_lambda_us_lambda_us);
    h2_invMass_ME_LL_Signal->Add(h2_invMass_ME_lambda_us_lambda_ls, -1.0);

    c32->cd(2);
    binMinX_ME_2 = h2_invMass_ME_LL_Signal->GetXaxis()->FindBin(minX_ME_2);
    binMaxX_ME_2 = h2_invMass_ME_LL_Signal->GetXaxis()->FindBin(maxX_ME_2);
    binMinY_ME_2 = h2_invMass_ME_LL_Signal->GetYaxis()->FindBin(minY_ME_2);
    binMaxY_ME_2 = h2_invMass_ME_LL_Signal->GetYaxis()->FindBin(maxY_ME_2);

    h2_invMass_ME_LL_Signal->GetXaxis()->SetRange(binMinX_ME_2, binMaxX_ME_2);
    h2_invMass_ME_LL_Signal->GetYaxis()->SetRange(binMinY_ME_2, binMaxY_ME_2);
    h2_invMass_ME_LL_Signal->Draw("SURF2");
    h2_invMass_ME_LL_Signal->SetTitle("ME #Lambda#Lambda Pair Inv. Mass Peak (check on ME pairs)");

    // Lambda Bar - Lambda Bar Signal
    TH2F *h2_invMass_ME_LBarLBar_Signal = new TH2F(*h2_invMass_ME_lambda_bar_us_lambda_bar_us);
    h2_invMass_ME_LBarLBar_Signal->Add(h2_invMass_ME_lambda_bar_us_lambda_bar_ls, -1.0);

    c32->cd(3);
    binMinX_ME_2 = h2_invMass_ME_LBarLBar_Signal->GetXaxis()->FindBin(minX_ME_2);
    binMaxX_ME_2 = h2_invMass_ME_LBarLBar_Signal->GetXaxis()->FindBin(maxX_ME_2);
    binMinY_ME_2 = h2_invMass_ME_LBarLBar_Signal->GetYaxis()->FindBin(minY_ME_2);
    binMaxY_ME_2 = h2_invMass_ME_LBarLBar_Signal->GetYaxis()->FindBin(maxY_ME_2);

    h2_invMass_ME_LBarLBar_Signal->GetXaxis()->SetRange(binMinX_ME_2, binMaxX_ME_2);
    h2_invMass_ME_LBarLBar_Signal->GetYaxis()->SetRange(binMinY_ME_2, binMaxY_ME_2);
    h2_invMass_ME_LBarLBar_Signal->Draw("SURF2");
    h2_invMass_ME_LBarLBar_Signal->SetTitle("ME #bar{#Lambda}#bar{#Lambda} Pair Inv. Mass Peak (check on ME pairs)");

    std::cout << "Canvas 32 Complete" << std::endl;

    std::unique_ptr<TCanvas> c33(new TCanvas("c33", "Canvas 33", 1800, 900));
    c33->Divide(3, 2);

    c33->cd(1);
    h2_no_cut_check_ME_L0_L0bar_p1pt_p2pt_US_US->Draw("COLZ");
    h2_no_cut_check_ME_L0_L0bar_p1pt_p2pt_US_US->SetTitle("Pt- US-US ME #Lambda#bar{#Lambda} Pairs (no cuts, check)");
    h2_no_cut_check_ME_L0_L0bar_p1pt_p2pt_US_US->GetXaxis()->SetTitle("p1_pt [GeV/c]");
    h2_no_cut_check_ME_L0_L0bar_p1pt_p2pt_US_US->GetXaxis()->CenterTitle(true);
    h2_no_cut_check_ME_L0_L0bar_p1pt_p2pt_US_US->GetYaxis()->SetTitle("p2_pt [GeV/c]");
    h2_no_cut_check_ME_L0_L0bar_p1pt_p2pt_US_US->GetYaxis()->CenterTitle(true);

    c33->cd(2);
    h2_no_cut_check_ME_L0_L0bar_p1eta_p2eta_US_US->Draw("COLZ");
    h2_no_cut_check_ME_L0_L0bar_p1eta_p2eta_US_US->SetTitle("Eta- US-US ME #Lambda#bar{#Lambda} Pairs (no cuts, check)");
    h2_no_cut_check_ME_L0_L0bar_p1eta_p2eta_US_US->GetXaxis()->SetTitle("p1_eta");
    h2_no_cut_check_ME_L0_L0bar_p1eta_p2eta_US_US->GetXaxis()->CenterTitle(true);
    h2_no_cut_check_ME_L0_L0bar_p1eta_p2eta_US_US->GetYaxis()->SetTitle("p2_eta");
    h2_no_cut_check_ME_L0_L0bar_p1eta_p2eta_US_US->GetYaxis()->CenterTitle(true);

    c33->cd(3);
    h2_no_cut_check_ME_L0_L0bar_p1phi_p2phi_US_US->Draw("COLZ");
    h2_no_cut_check_ME_L0_L0bar_p1phi_p2phi_US_US->SetTitle("Phi- US-US ME #Lambda#bar{#Lambda} Pairs (no cuts, check)");
    h2_no_cut_check_ME_L0_L0bar_p1phi_p2phi_US_US->GetXaxis()->SetTitle("p1_phi");
    h2_no_cut_check_ME_L0_L0bar_p1phi_p2phi_US_US->GetXaxis()->CenterTitle(true);
    h2_no_cut_check_ME_L0_L0bar_p1phi_p2phi_US_US->GetYaxis()->SetTitle("p2_phi");
    h2_no_cut_check_ME_L0_L0bar_p1phi_p2phi_US_US->GetYaxis()->CenterTitle(true);

    c33->cd(4);
    h2_no_cut_check_ME_L0_L0bar_p1pt_p2pt_US_LS->Draw("COLZ");
    h2_no_cut_check_ME_L0_L0bar_p1pt_p2pt_US_LS->SetTitle("Pt- US-LS ME #Lambda#bar{#Lambda} Pairs (no cuts, check)");
    h2_no_cut_check_ME_L0_L0bar_p1pt_p2pt_US_LS->GetXaxis()->SetTitle("p1_pt [GeV/c]");
    h2_no_cut_check_ME_L0_L0bar_p1pt_p2pt_US_LS->GetXaxis()->CenterTitle(true);
    h2_no_cut_check_ME_L0_L0bar_p1pt_p2pt_US_LS->GetYaxis()->SetTitle("p2_pt [GeV/c]");
    h2_no_cut_check_ME_L0_L0bar_p1pt_p2pt_US_LS->GetYaxis()->CenterTitle(true);

    c33->cd(5);
    h2_no_cut_check_ME_L0_L0bar_p1eta_p2eta_US_LS->Draw("COLZ");
    h2_no_cut_check_ME_L0_L0bar_p1eta_p2eta_US_LS->SetTitle("Eta- US-LS ME #Lambda#bar{#Lambda} Pairs (no cuts, check)");
    h2_no_cut_check_ME_L0_L0bar_p1eta_p2eta_US_LS->GetXaxis()->SetTitle("p1_eta");
    h2_no_cut_check_ME_L0_L0bar_p1eta_p2eta_US_LS->GetXaxis()->CenterTitle(true);
    h2_no_cut_check_ME_L0_L0bar_p1eta_p2eta_US_LS->GetYaxis()->SetTitle("p2_eta");
    h2_no_cut_check_ME_L0_L0bar_p1eta_p2eta_US_LS->GetYaxis()->CenterTitle(true);

    c33->cd(6);
    h2_no_cut_check_ME_L0_L0bar_p1phi_p2phi_US_LS->Draw("COLZ");
    h2_no_cut_check_ME_L0_L0bar_p1phi_p2phi_US_LS->SetTitle("Phi- US-LS ME #Lambda#bar{#Lambda} Pairs (no cuts, check)");
    h2_no_cut_check_ME_L0_L0bar_p1phi_p2phi_US_LS->GetXaxis()->SetTitle("p1_phi");
    h2_no_cut_check_ME_L0_L0bar_p1phi_p2phi_US_LS->GetXaxis()->CenterTitle(true);
    h2_no_cut_check_ME_L0_L0bar_p1phi_p2phi_US_LS->GetYaxis()->SetTitle("p2_phi");
    h2_no_cut_check_ME_L0_L0bar_p1phi_p2phi_US_LS->GetXaxis()->CenterTitle(true);

    std::cout << "Canvas 33 Complete" << std::endl;

    std::unique_ptr<TCanvas> c34(new TCanvas("c34", "Canvas 34", 1800, 900));
    c34->Divide(3, 2);

    c34->cd(1);
    h2_no_cut_check_ME_L0_L0_p1pt_p2pt_US_US->Draw("COLZ");
    h2_no_cut_check_ME_L0_L0_p1pt_p2pt_US_US->SetTitle("Pt- US-US ME #Lambda#Lambda Pairs (no cuts, check)");
    h2_no_cut_check_ME_L0_L0_p1pt_p2pt_US_US->GetXaxis()->SetTitle("p1_pt [GeV/c]");
    h2_no_cut_check_ME_L0_L0_p1pt_p2pt_US_US->GetXaxis()->CenterTitle(true);
    h2_no_cut_check_ME_L0_L0_p1pt_p2pt_US_US->GetYaxis()->SetTitle("p2_pt [GeV/c]");
    h2_no_cut_check_ME_L0_L0_p1pt_p2pt_US_US->GetYaxis()->CenterTitle(true);

    c34->cd(2);
    h2_no_cut_check_ME_L0_L0_p1eta_p2eta_US_US->Draw("COLZ");
    h2_no_cut_check_ME_L0_L0_p1eta_p2eta_US_US->SetTitle("Eta- US-US ME #Lambda#Lambda Pairs (no cuts, check)");
    h2_no_cut_check_ME_L0_L0_p1eta_p2eta_US_US->GetXaxis()->SetTitle("p1_eta");
    h2_no_cut_check_ME_L0_L0_p1eta_p2eta_US_US->GetXaxis()->CenterTitle(true);
    h2_no_cut_check_ME_L0_L0_p1eta_p2eta_US_US->GetYaxis()->SetTitle("p2_eta");
    h2_no_cut_check_ME_L0_L0_p1eta_p2eta_US_US->GetYaxis()->CenterTitle(true);

    c34->cd(3);
    h2_no_cut_check_ME_L0_L0_p1phi_p2phi_US_US->Draw("COLZ");
    h2_no_cut_check_ME_L0_L0_p1phi_p2phi_US_US->SetTitle("Phi- US-US ME #Lambda#Lambda Pairs (no cuts, check)");
    h2_no_cut_check_ME_L0_L0_p1phi_p2phi_US_US->GetXaxis()->SetTitle("p1_phi");
    h2_no_cut_check_ME_L0_L0_p1phi_p2phi_US_US->GetXaxis()->CenterTitle(true);
    h2_no_cut_check_ME_L0_L0_p1phi_p2phi_US_US->GetYaxis()->SetTitle("p2_phi");
    h2_no_cut_check_ME_L0_L0_p1phi_p2phi_US_US->GetYaxis()->CenterTitle(true);

    c34->cd(4);
    h2_no_cut_check_ME_L0_L0_p1pt_p2pt_US_LS->Draw("COLZ");
    h2_no_cut_check_ME_L0_L0_p1pt_p2pt_US_LS->SetTitle("Pt- US-LS ME #Lambda#Lambda Pairs (no cuts, check)");
    h2_no_cut_check_ME_L0_L0_p1pt_p2pt_US_LS->GetXaxis()->SetTitle("p1_pt [GeV/c]");
    h2_no_cut_check_ME_L0_L0_p1pt_p2pt_US_LS->GetXaxis()->CenterTitle(true);
    h2_no_cut_check_ME_L0_L0_p1pt_p2pt_US_LS->GetYaxis()->SetTitle("p2_pt [GeV/c]");
    h2_no_cut_check_ME_L0_L0_p1pt_p2pt_US_LS->GetYaxis()->CenterTitle(true);

    c34->cd(5);
    h2_no_cut_check_ME_L0_L0_p1eta_p2eta_US_LS->Draw("COLZ");
    h2_no_cut_check_ME_L0_L0_p1eta_p2eta_US_LS->SetTitle("Eta- US-LS ME #Lambda#Lambda Pairs (no cuts, check)");
    h2_no_cut_check_ME_L0_L0_p1eta_p2eta_US_LS->GetXaxis()->SetTitle("p1_eta");
    h2_no_cut_check_ME_L0_L0_p1eta_p2eta_US_LS->GetXaxis()->CenterTitle(true);
    h2_no_cut_check_ME_L0_L0_p1eta_p2eta_US_LS->GetYaxis()->SetTitle("p2_eta");
    h2_no_cut_check_ME_L0_L0_p1eta_p2eta_US_LS->GetYaxis()->CenterTitle(true);

    c34->cd(6);
    h2_no_cut_check_ME_L0_L0_p1phi_p2phi_US_LS->Draw("COLZ");
    h2_no_cut_check_ME_L0_L0_p1phi_p2phi_US_LS->SetTitle("Phi- US-LS ME #Lambda#Lambda Pairs (no cuts, check)");
    h2_no_cut_check_ME_L0_L0_p1phi_p2phi_US_LS->GetXaxis()->SetTitle("p1_phi");
    h2_no_cut_check_ME_L0_L0_p1phi_p2phi_US_LS->GetXaxis()->CenterTitle(true);
    h2_no_cut_check_ME_L0_L0_p1phi_p2phi_US_LS->GetYaxis()->SetTitle("p2_phi");
    h2_no_cut_check_ME_L0_L0_p1phi_p2phi_US_LS->GetYaxis()->CenterTitle(true);

    std::cout << "Canvas 34 Complete" << std::endl;

    std::unique_ptr<TCanvas> c35(new TCanvas("c35", "Canvas 35", 1800, 900));
    c35->Divide(3, 2);

    c35->cd(1);
    h2_no_cut_check_ME_L0bar_L0bar_p1pt_p2pt_US_US->Draw("COLZ");
    h2_no_cut_check_ME_L0bar_L0bar_p1pt_p2pt_US_US->SetTitle("Pt- US-US ME #bar{#Lambda}#bar{#Lambda} Pairs (no cuts, check)");
    h2_no_cut_check_ME_L0bar_L0bar_p1pt_p2pt_US_US->GetXaxis()->SetTitle("p1_pt [GeV/c]");
    h2_no_cut_check_ME_L0bar_L0bar_p1pt_p2pt_US_US->GetXaxis()->CenterTitle(true);
    h2_no_cut_check_ME_L0bar_L0bar_p1pt_p2pt_US_US->GetYaxis()->SetTitle("p2_pt [GeV/c]");
    h2_no_cut_check_ME_L0bar_L0bar_p1pt_p2pt_US_US->GetXaxis()->CenterTitle(true);

    c35->cd(2);
    h2_no_cut_check_ME_L0bar_L0bar_p1eta_p2eta_US_US->Draw("COLZ");
    h2_no_cut_check_ME_L0bar_L0bar_p1eta_p2eta_US_US->SetTitle("Eta- US-US ME #bar{#Lambda}#bar{#Lambda} Pairs (no cuts, check)");
    h2_no_cut_check_ME_L0bar_L0bar_p1eta_p2eta_US_US->GetXaxis()->SetTitle("p1_eta");
    h2_no_cut_check_ME_L0bar_L0bar_p1eta_p2eta_US_US->GetXaxis()->CenterTitle(true);
    h2_no_cut_check_ME_L0bar_L0bar_p1eta_p2eta_US_US->GetYaxis()->SetTitle("p2_eta");
    h2_no_cut_check_ME_L0bar_L0bar_p1eta_p2eta_US_US->GetXaxis()->CenterTitle(true);

    c35->cd(3);
    h2_no_cut_check_ME_L0bar_L0bar_p1phi_p2phi_US_US->Draw("COLZ");
    h2_no_cut_check_ME_L0bar_L0bar_p1phi_p2phi_US_US->SetTitle("Phi- US-US ME #bar{#Lambda}#bar{#Lambda} Pairs (no cuts, check)");
    h2_no_cut_check_ME_L0bar_L0bar_p1phi_p2phi_US_US->GetXaxis()->SetTitle("p1_phi");
    h2_no_cut_check_ME_L0bar_L0bar_p1phi_p2phi_US_US->GetXaxis()->CenterTitle(true);
    h2_no_cut_check_ME_L0bar_L0bar_p1phi_p2phi_US_US->GetYaxis()->SetTitle("p2_phi");
    h2_no_cut_check_ME_L0bar_L0bar_p1phi_p2phi_US_US->GetXaxis()->CenterTitle(true);

    c35->cd(4);
    h2_no_cut_check_ME_L0bar_L0bar_p1pt_p2pt_US_LS->Draw("COLZ");
    h2_no_cut_check_ME_L0bar_L0bar_p1pt_p2pt_US_LS->SetTitle("Pt- US-LS ME #bar{#Lambda}#bar{#Lambda} Pairs (no cuts, check)");
    h2_no_cut_check_ME_L0bar_L0bar_p1pt_p2pt_US_LS->GetXaxis()->SetTitle("p1_pt [GeV/c]");
    h2_no_cut_check_ME_L0bar_L0bar_p1pt_p2pt_US_LS->GetXaxis()->CenterTitle(true);
    h2_no_cut_check_ME_L0bar_L0bar_p1pt_p2pt_US_LS->GetYaxis()->SetTitle("p2_pt [GeV/c]");
    h2_no_cut_check_ME_L0bar_L0bar_p1pt_p2pt_US_LS->GetXaxis()->CenterTitle(true);

    c35->cd(5);
    h2_no_cut_check_ME_L0bar_L0bar_p1eta_p2eta_US_LS->Draw("COLZ");
    h2_no_cut_check_ME_L0bar_L0bar_p1eta_p2eta_US_LS->SetTitle("Eta- US-LS ME #bar{#Lambda}#bar{#Lambda} Pairs (no cuts, check)");
    h2_no_cut_check_ME_L0bar_L0bar_p1eta_p2eta_US_LS->GetXaxis()->SetTitle("p1_eta");
    h2_no_cut_check_ME_L0bar_L0bar_p1eta_p2eta_US_LS->GetXaxis()->CenterTitle(true);
    h2_no_cut_check_ME_L0bar_L0bar_p1eta_p2eta_US_LS->GetYaxis()->SetTitle("p2_eta");
    h2_no_cut_check_ME_L0bar_L0bar_p1eta_p2eta_US_LS->GetXaxis()->CenterTitle(true);

    c35->cd(6);
    h2_no_cut_check_ME_L0bar_L0bar_p1phi_p2phi_US_LS->Draw("COLZ");
    h2_no_cut_check_ME_L0bar_L0bar_p1phi_p2phi_US_LS->SetTitle("Phi- US-LS ME #bar{#Lambda}#bar{#Lambda} Pairs (no cuts, check)");
    h2_no_cut_check_ME_L0bar_L0bar_p1phi_p2phi_US_LS->GetXaxis()->SetTitle("p1_phi");
    h2_no_cut_check_ME_L0bar_L0bar_p1phi_p2phi_US_LS->GetXaxis()->CenterTitle(true);
    h2_no_cut_check_ME_L0bar_L0bar_p1phi_p2phi_US_LS->GetYaxis()->SetTitle("p2_phi");
    h2_no_cut_check_ME_L0bar_L0bar_p1phi_p2phi_US_LS->GetXaxis()->CenterTitle(true);

    std::cout << "Canvas 35 Complete" << std::endl;

    std::unique_ptr<TCanvas> c36(new TCanvas("c36", "Canvas 36", 1800, 900));
    c36->Divide(3, 2);

    c36->cd(1);
    h_delta_R_ME_US_US_llbar->Draw();
    h_delta_R_ME_US_US_llbar->SetLineColor(kBlue);
    h_delta_R_ME_US_US_llbar->SetTitle("#DeltaR Distribution for #Lambda#bar{#Lambda} Pairs");
    h_delta_R_ME_US_LS_llbar->Draw("same");
    h_delta_R_ME_US_LS_llbar->SetLineColor(kRed);

    TLegend *legend_ME_delR_L0_L0bar = new TLegend(0.6, 0.7, 0.8, 0.8);
    legend_ME_delR_L0_L0bar->SetTextSize(0.04);
    legend_ME_delR_L0_L0bar->SetBorderSize(0);
    legend_ME_delR_L0_L0bar->SetFillStyle(0); // Transparent background

    legend_ME_delR_L0_L0bar->AddEntry(h_delta_R_ME_US_US_llbar, "US-US #DeltaR", "lep");
    legend_ME_delR_L0_L0bar->AddEntry(h_delta_R_ME_US_LS_llbar, "US-LS #DeltaR", "lep");
    legend_ME_delR_L0_L0bar->Draw();

    c36->cd(2);
    h_delta_R_ME_US_US_ll->Draw();
    h_delta_R_ME_US_US_ll->SetLineColor(kBlue);
    h_delta_R_ME_US_US_ll->SetTitle("#DeltaR Distribution for #Lambda#Lambda Pairs");
    h_delta_R_ME_US_LS_ll->Draw("same");
    h_delta_R_ME_US_LS_ll->SetLineColor(kRed);

    TLegend *legend_ME_delR_L0_L0 = new TLegend(0.6, 0.7, 0.8, 0.8);
    legend_ME_delR_L0_L0->SetTextSize(0.04);
    legend_ME_delR_L0_L0->SetBorderSize(0);
    legend_ME_delR_L0_L0->SetFillStyle(0); // Transparent background

    legend_ME_delR_L0_L0->AddEntry(h_delta_R_ME_US_US_ll, "US-US #DeltaR", "lep");
    legend_ME_delR_L0_L0->AddEntry(h_delta_R_ME_US_LS_ll, "US-LS #DeltaR", "lep");
    legend_ME_delR_L0_L0->Draw();

    c36->cd(3);
    h_delta_R_ME_US_US_lbarlbar->Draw();
    h_delta_R_ME_US_US_lbarlbar->SetLineColor(kBlue);
    h_delta_R_ME_US_US_lbarlbar->SetTitle("#DeltaR Distribution for #bar{#Lambda}#bar{#Lambda} Pairs");
    h_delta_R_ME_US_LS_lbarlbar->Draw("same");
    h_delta_R_ME_US_LS_lbarlbar->SetLineColor(kRed);

    TLegend *legend_ME_delR_L0bar_L0bar = new TLegend(0.6, 0.7, 0.8, 0.8);
    legend_ME_delR_L0bar_L0bar->SetTextSize(0.04);
    legend_ME_delR_L0bar_L0bar->SetBorderSize(0);
    legend_ME_delR_L0bar_L0bar->SetFillStyle(0); // Transparent background

    legend_ME_delR_L0bar_L0bar->AddEntry(h_delta_R_ME_US_US_lbarlbar, "US-US #DeltaR", "lep");
    legend_ME_delR_L0bar_L0bar->AddEntry(h_delta_R_ME_US_LS_lbarlbar, "US-LS #DeltaR", "lep");
    legend_ME_delR_L0bar_L0bar->Draw();

    c36->cd(4);
    h_delta_phi_ME_US_US_llbar->SetMinimum(0);
    h_delta_phi_ME_US_US_llbar->Draw();
    h_delta_phi_ME_US_US_llbar->SetLineColor(kBlue);
    h_delta_phi_ME_US_US_llbar->SetTitle("#Delta#phi Distribution for #Lambda#bar{#Lambda} Pairs");
    h_delta_phi_ME_US_LS_llbar->Draw("same");
    h_delta_phi_ME_US_LS_llbar->SetLineColor(kRed);

    TLegend *legend_ME_delphi_L0_L0bar = new TLegend(0.6, 0.7, 0.8, 0.8);
    legend_ME_delphi_L0_L0bar->SetTextSize(0.04);
    legend_ME_delphi_L0_L0bar->SetBorderSize(0);
    legend_ME_delphi_L0_L0bar->SetFillStyle(0); // Transparent background

    legend_ME_delphi_L0_L0bar->AddEntry(h_delta_phi_ME_US_US_llbar, "US-US #Delta#phi", "lep");
    legend_ME_delphi_L0_L0bar->AddEntry(h_delta_phi_ME_US_LS_llbar, "US-LS #Delta#phi", "lep");
    legend_ME_delphi_L0_L0bar->Draw();

    c36->cd(5);
    h_delta_phi_ME_US_US_ll->SetMinimum(0);
    h_delta_phi_ME_US_US_ll->Draw();
    h_delta_phi_ME_US_US_ll->SetLineColor(kBlue);
    h_delta_phi_ME_US_US_ll->SetTitle("#Delta#phi Distribution for #Lambda#Lambda Pairs");
    h_delta_phi_ME_US_LS_ll->Draw("same");
    h_delta_phi_ME_US_LS_ll->SetLineColor(kRed);

    TLegend *legend_ME_delphi_L0_L0 = new TLegend(0.6, 0.7, 0.8, 0.8);
    legend_ME_delphi_L0_L0->SetTextSize(0.04);
    legend_ME_delphi_L0_L0->SetBorderSize(0);
    legend_ME_delphi_L0_L0->SetFillStyle(0); // Transparent background

    legend_ME_delphi_L0_L0->AddEntry(h_delta_phi_ME_US_US_ll, "US-US #Delta#phi", "lep");
    legend_ME_delphi_L0_L0->AddEntry(h_delta_phi_ME_US_LS_ll, "US-LS #Delta#phi", "lep");
    legend_ME_delphi_L0_L0->Draw();

    c36->cd(6);
    h_delta_phi_ME_US_US_lbarlbar->SetMinimum(0);
    h_delta_phi_ME_US_US_lbarlbar->Draw();
    h_delta_phi_ME_US_US_lbarlbar->SetLineColor(kBlue);
    h_delta_phi_ME_US_US_lbarlbar->SetTitle("#Delta#phi Distributions for #bar{#Lambda}#bar{#Lambda} Pairs");
    h_delta_phi_ME_US_LS_lbarlbar->Draw("same");
    h_delta_phi_ME_US_LS_lbarlbar->SetLineColor(kRed);

    TLegend *legend_ME_delphi_L0bar_L0bar = new TLegend(0.6, 0.7, 0.8, 0.8);
    legend_ME_delphi_L0bar_L0bar->SetTextSize(0.04);
    legend_ME_delphi_L0bar_L0bar->SetBorderSize(0);
    legend_ME_delphi_L0bar_L0bar->SetFillStyle(0); // Transparent background

    legend_ME_delphi_L0bar_L0bar->AddEntry(h_delta_phi_ME_US_US_lbarlbar, "US-US #Delta#phi", "lep");
    legend_ME_delphi_L0bar_L0bar->AddEntry(h_delta_phi_ME_US_LS_lbarlbar, "US-LS #Delta#phi", "lep");
    legend_ME_delphi_L0bar_L0bar->Draw();

    std::cout << "Canvas 36 Complete" << std::endl;

    double outside_ME_cos_theta_star3 = h_outside_ME_cos_theta_star3->Integral();
    double outside_ME_cos_theta_star4 = h_outside_ME_cos_theta_star4->Integral();
    double outside_ME_cos_theta_star = h_outside_ME_cos_theta_star->Integral();
    double outside_ME_cos_theta_star2 = h_outside_ME_cos_theta_star2->Integral();
    double outside_ME_cos_theta_star5 = h_outside_ME_cos_theta_star5->Integral();
    double outside_ME_cos_theta_star6 = h_outside_ME_cos_theta_star6->Integral();  

    std::cout << "  " << std::endl;
    std::cout << "Counts in h_outside_ME_cos_theta_star3: " << outside_ME_cos_theta_star3 << std::endl;
    std::cout << "Counts in h_outside_ME_cos_theta_star4: " << outside_ME_cos_theta_star4 << std::endl;
    std::cout << "Counts in h_outside_ME_cos_theta_star: " << outside_ME_cos_theta_star << std::endl;
    std::cout << "Counts in h_outside_ME_cos_theta_star2: " << outside_ME_cos_theta_star2 << std::endl;
    std::cout << "Counts in h_outside_ME_cos_theta_star5: " << outside_ME_cos_theta_star5 << std::endl;
    std::cout << "Counts in h_outside_ME_cos_theta_star6: " << outside_ME_cos_theta_star6 << std::endl;
    std::cout << "  " << std::endl;

    double ME_cos_theta_star3 = h_ME_cos_theta_star3->Integral();
    double ME_cos_theta_star4 = h_ME_cos_theta_star4->Integral();
    double ME_cos_theta_star = h_ME_cos_theta_star->Integral();
    double ME_cos_theta_star2 = h_ME_cos_theta_star2->Integral();
    double ME_cos_theta_star5 = h_ME_cos_theta_star5->Integral();
    double ME_cos_theta_star6 = h_ME_cos_theta_star6->Integral();  

    std::cout << "  " << std::endl;
    std::cout << "Counts in h_ME_cos_theta_star3: " << ME_cos_theta_star3 << std::endl;
    std::cout << "Counts in h_ME_cos_theta_star4: " << ME_cos_theta_star4 << std::endl;
    std::cout << "Counts in h_ME_cos_theta_star: " << ME_cos_theta_star << std::endl;
    std::cout << "Counts in h_ME_cos_theta_star2: " << ME_cos_theta_star2 << std::endl;
    std::cout << "Counts in h_ME_cos_theta_star5: " << ME_cos_theta_star5 << std::endl;
    std::cout << "Counts in h_ME_cos_theta_star6: " << ME_cos_theta_star6 << std::endl;
    std::cout << "  " << std::endl;

    h_outside_ME_cos_theta_star3->Scale(1.0/h_outside_ME_cos_theta_star3->GetXaxis()->GetBinWidth(1));
    h_outside_ME_cos_theta_star4->Scale(1.0/h_outside_ME_cos_theta_star4->GetXaxis()->GetBinWidth(1));
    h_outside_ME_cos_theta_star->Scale(1.0/h_outside_ME_cos_theta_star->GetXaxis()->GetBinWidth(1));
    h_outside_ME_cos_theta_star2->Scale(1.0/h_outside_ME_cos_theta_star2->GetXaxis()->GetBinWidth(1));
    h_outside_ME_cos_theta_star5->Scale(1.0/h_outside_ME_cos_theta_star5->GetXaxis()->GetBinWidth(1));
    h_outside_ME_cos_theta_star6->Scale(1.0/h_outside_ME_cos_theta_star6->GetXaxis()->GetBinWidth(1));

    h_outside_ME_cos_theta_star3->Scale(1.0/1000);
    h_outside_ME_cos_theta_star4->Scale(1.0/1000);
    h_outside_ME_cos_theta_star->Scale(1.0/1000);
    h_outside_ME_cos_theta_star2->Scale(1.0/1000);
    h_outside_ME_cos_theta_star5->Scale(1.0/1000);
    h_outside_ME_cos_theta_star6->Scale(1.0/1000);

    h_ME_cos_theta_star3->Scale(1.0/h_ME_cos_theta_star3->GetXaxis()->GetBinWidth(1));
    h_ME_cos_theta_star4->Scale(1.0/h_ME_cos_theta_star4->GetXaxis()->GetBinWidth(1));
    h_ME_cos_theta_star->Scale(1.0/h_ME_cos_theta_star->GetXaxis()->GetBinWidth(1));
    h_ME_cos_theta_star2->Scale(1.0/h_ME_cos_theta_star2->GetXaxis()->GetBinWidth(1));
    h_ME_cos_theta_star5->Scale(1.0/h_ME_cos_theta_star5->GetXaxis()->GetBinWidth(1));
    h_ME_cos_theta_star6->Scale(1.0/h_ME_cos_theta_star6->GetXaxis()->GetBinWidth(1));

    h_ME_cos_theta_star3->Scale(1.0/1000);
    h_ME_cos_theta_star4->Scale(1.0/1000);
    h_ME_cos_theta_star->Scale(1.0/1000);
    h_ME_cos_theta_star2->Scale(1.0/1000);
    h_ME_cos_theta_star5->Scale(1.0/1000);
    h_ME_cos_theta_star6->Scale(1.0/1000);

    h_ME_cos_theta_star3->Scale(SE_cos_theta_star3/ME_cos_theta_star3);
    h_ME_cos_theta_star4->Scale(SE_cos_theta_star4/ME_cos_theta_star4);
    h_ME_cos_theta_star->Scale(SE_cos_theta_star/ME_cos_theta_star);
    h_ME_cos_theta_star2->Scale(SE_cos_theta_star2/ME_cos_theta_star2);
    h_ME_cos_theta_star5->Scale(SE_cos_theta_star5/ME_cos_theta_star5);
    h_ME_cos_theta_star6->Scale(SE_cos_theta_star6/ME_cos_theta_star6);

    h_outside_ME_cos_theta_star3->Scale(SE_outside_cos_theta_star3/outside_ME_cos_theta_star3);
    h_outside_ME_cos_theta_star4->Scale(SE_outside_cos_theta_star4/outside_ME_cos_theta_star4);
    h_outside_ME_cos_theta_star->Scale(SE_outside_cos_theta_star/outside_ME_cos_theta_star);
    h_outside_ME_cos_theta_star2->Scale(SE_outside_cos_theta_star2/outside_ME_cos_theta_star2);
    h_outside_ME_cos_theta_star5->Scale(SE_outside_cos_theta_star5/outside_ME_cos_theta_star5);
    h_outside_ME_cos_theta_star6->Scale(SE_outside_cos_theta_star6/outside_ME_cos_theta_star6);

    std::unique_ptr<TCanvas> c37(new TCanvas("c37", "Canvas 37", 1800, 900));
    c37->Divide(3, 2);

    c37->cd(1);
    h_ME_cos_theta_star3->SetMinimum(0);
    h_ME_cos_theta_star3->SetMarkerStyle(20);
    h_ME_cos_theta_star3->SetMarkerColor(kBlue);
    h_ME_cos_theta_star3->Draw("PE"); // Draw with error bars
    h_ME_cos_theta_star3->SetTitle("#Lambda#bar{#Lambda} Angular Correlation inside #DeltaR = 0.93");
    h_ME_cos_theta_star3->GetXaxis()->SetTitle("cos(#theta*)");
    h_ME_cos_theta_star3->GetXaxis()->CenterTitle(true);
    h_ME_cos_theta_star3->GetYaxis()->SetTitle("dN/dCos(#theta*)");
    h_ME_cos_theta_star3->GetYaxis()->CenterTitle(true);

    h_ME_cos_theta_star4->SetMarkerStyle(20);
    h_ME_cos_theta_star4->SetLineColor(kRed);
    h_ME_cos_theta_star4->SetMarkerColor(kRed);
    h_ME_cos_theta_star4->Draw("same PE"); // Draw with error bars

    c37->cd(2);
    h_ME_cos_theta_star->SetMinimum(0);
    h_ME_cos_theta_star->SetMarkerStyle(20);
    h_ME_cos_theta_star->SetMarkerColor(kBlue);
    h_ME_cos_theta_star->Draw("PE");
    h_ME_cos_theta_star->SetTitle("#Lambda#Lambda Angular Correlation inside #DeltaR = 0.93");
    h_ME_cos_theta_star->GetXaxis()->SetTitle("cos(#theta*)");
    h_ME_cos_theta_star->GetXaxis()->CenterTitle(true);
    h_ME_cos_theta_star->GetYaxis()->SetTitle("dN/dCos(#theta*)");
    h_ME_cos_theta_star->GetYaxis()->CenterTitle(true);

    h_ME_cos_theta_star2->SetLineColor(kRed);
    h_ME_cos_theta_star2->SetMarkerStyle(20);
    h_ME_cos_theta_star2->SetMarkerColor(kRed);
    h_ME_cos_theta_star2->Draw("same PE");

    c37->cd(3);
    h_ME_cos_theta_star5->SetMinimum(0);
    h_ME_cos_theta_star5->SetMarkerStyle(20);
    h_ME_cos_theta_star5->SetMarkerColor(kBlue);
    h_ME_cos_theta_star5->Draw("PE"); // Draw with error bars
    h_ME_cos_theta_star5->SetTitle("#bar{#Lambda}#bar{#Lambda} Angular Correlation inside #DeltaR = 0.93");
    h_ME_cos_theta_star5->GetXaxis()->SetTitle("cos(#theta*)");
    h_ME_cos_theta_star5->GetXaxis()->CenterTitle(true);
    h_ME_cos_theta_star5->GetYaxis()->SetTitle("dN/dCos(#theta*)");
    h_ME_cos_theta_star5->GetYaxis()->CenterTitle(true);

    h_ME_cos_theta_star6->SetLineColor(kRed);
    h_ME_cos_theta_star6->SetMarkerStyle(20);
    h_ME_cos_theta_star6->SetMarkerColor(kRed);
    h_ME_cos_theta_star6->Draw("same PE"); // Draw with error bars

    c37->cd(4);
    h_outside_ME_cos_theta_star3->SetMinimum(0);
    h_outside_ME_cos_theta_star3->SetMarkerStyle(20);
    h_outside_ME_cos_theta_star3->SetMarkerColor(kBlue);
    h_outside_ME_cos_theta_star3->Draw("PE"); // Draw with error bars
    h_outside_ME_cos_theta_star3->SetTitle("#Lambda#bar{#Lambda} Angular Correlation outside #DeltaR = 0.93");
    h_outside_ME_cos_theta_star3->GetXaxis()->SetTitle("cos(#theta*)");
    h_outside_ME_cos_theta_star3->GetXaxis()->CenterTitle(true);
    h_outside_ME_cos_theta_star3->GetYaxis()->SetTitle("dN/dCos(#theta*)");
    h_outside_ME_cos_theta_star3->GetYaxis()->CenterTitle(true);

    h_outside_ME_cos_theta_star4->SetMarkerStyle(20);
    h_outside_ME_cos_theta_star4->SetLineColor(kRed);
    h_outside_ME_cos_theta_star4->SetMarkerColor(kRed);
    h_outside_ME_cos_theta_star4->Draw("same PE"); // Draw with error bars

    c37->cd(5);
    h_outside_ME_cos_theta_star->SetMinimum(0);
    h_outside_ME_cos_theta_star->SetMarkerStyle(20);
    h_outside_ME_cos_theta_star->SetMarkerColor(kBlue);
    h_outside_ME_cos_theta_star->Draw("PE");
    h_outside_ME_cos_theta_star->SetTitle("#Lambda#Lambda Angular Correlation outside #DeltaR = 0.93");
    h_outside_ME_cos_theta_star->GetXaxis()->SetTitle("cos(#theta*)");
    h_outside_ME_cos_theta_star->GetXaxis()->CenterTitle(true);
    h_outside_ME_cos_theta_star->GetYaxis()->SetTitle("dN/dCos(#theta*)");
    h_outside_ME_cos_theta_star->GetYaxis()->CenterTitle(true);

    h_outside_ME_cos_theta_star2->SetLineColor(kRed);
    h_outside_ME_cos_theta_star2->SetMarkerStyle(20);
    h_outside_ME_cos_theta_star2->SetMarkerColor(kRed);
    h_outside_ME_cos_theta_star2->Draw("same PE");

    c37->cd(6);
    h_outside_ME_cos_theta_star5->SetMinimum(0);
    h_outside_ME_cos_theta_star5->SetMarkerStyle(20);
    h_outside_ME_cos_theta_star5->SetMarkerColor(kBlue);
    h_outside_ME_cos_theta_star5->Draw("PE"); // Draw with error bars
    h_outside_ME_cos_theta_star5->SetTitle("#bar{#Lambda}#bar{#Lambda} Angular Correlation outside #DeltaR = 0.93");
    h_outside_ME_cos_theta_star5->GetXaxis()->SetTitle("cos(#theta*)");
    h_outside_ME_cos_theta_star5->GetXaxis()->CenterTitle(true);
    h_outside_ME_cos_theta_star5->GetYaxis()->SetTitle("dN/dCos(#theta*)");
    h_outside_ME_cos_theta_star5->GetYaxis()->CenterTitle(true);

    h_outside_ME_cos_theta_star6->SetLineColor(kRed);
    h_outside_ME_cos_theta_star6->SetMarkerStyle(20);
    h_outside_ME_cos_theta_star6->SetMarkerColor(kRed);
    h_outside_ME_cos_theta_star6->Draw("same PE"); // Draw with error bars

    std::cout << "Canvas 37 Complete" << std::endl;

    std::unique_ptr<TCanvas> c38(new TCanvas("c38", "Canvas 38", 1800, 900));
    c38->Divide(3, 2);

    c38->cd(1);
    h_cos_theta_star3->SetMinimum(0);
    h_cos_theta_star3->SetMarkerStyle(20);
    h_cos_theta_star3->SetMarkerColor(kBlue);
    h_cos_theta_star3->Draw("PE"); // Draw with error bars
    h_cos_theta_star3->SetTitle("#Lambda#bar{#Lambda} Angular Correlation inside #DeltaR = 0.93");

    h_cos_theta_star4->SetMarkerStyle(20);
    h_cos_theta_star4->SetLineColor(kRed);
    h_cos_theta_star4->SetMarkerColor(kRed);
    h_cos_theta_star4->Draw("same PE"); // Draw with error bars

    h_cos_theta_star3->GetXaxis()->SetTitle("Cos(#theta*)");
    h_cos_theta_star3->GetXaxis()->CenterTitle();
    h_cos_theta_star3->GetYaxis()->SetTitle("dN/dCos(#theta*)");
    h_cos_theta_star3->GetYaxis()->CenterTitle();

    h_ME_cos_theta_star3->SetMinimum(0);
    h_ME_cos_theta_star3->SetMarkerStyle(24);
    h_ME_cos_theta_star3->SetMarkerColor(kBlue);
    h_ME_cos_theta_star3->Draw("same PE"); // Draw with error bars
    
    h_ME_cos_theta_star4->SetMarkerStyle(24);
    h_ME_cos_theta_star4->SetLineColor(kRed);
    h_ME_cos_theta_star4->SetMarkerColor(kRed);
    h_ME_cos_theta_star4->Draw("same PE"); // Draw with error bars

    TLegend *legend_2 = new TLegend(0.12, 0.65, 0.35, 0.9);
    legend_2->SetTextSize(0.03);
    legend_2->SetBorderSize(0);
    legend_2->SetFillStyle(0); // Transparent background

    legend_2->AddEntry(h_cos_theta_star3, "US-US SE #Lambda-#bar{#Lambda} Pairs", "p");
    legend_2->AddEntry(h_cos_theta_star4, "US-LS SE #Lambda-#bar{#Lambda} Pairs", "p");
    legend_2->AddEntry(h_ME_cos_theta_star3, "US-US ME #Lambda-#bar{#Lambda} Pairs", "p");
    legend_2->AddEntry(h_ME_cos_theta_star4, "US-US SE #Lambda-#bar{#Lambda} Pairs", "p");

    legend_2->Draw();

    c38->cd(2);
    h_cos_theta_star->SetMinimum(0);
    h_cos_theta_star->SetMarkerStyle(20);
    h_cos_theta_star->SetMarkerColor(kBlue);
    h_cos_theta_star->Draw("PE");
    h_cos_theta_star->SetTitle("#Lambda#Lambda Angular Correlation inside #DeltaR = 0.93");

    h_cos_theta_star2->SetLineColor(kRed);
    h_cos_theta_star2->SetMarkerStyle(20);
    h_cos_theta_star2->SetMarkerColor(kRed);
    h_cos_theta_star2->Draw("same PE");

    h_cos_theta_star->GetXaxis()->SetTitle("Cos(#theta*)");
    h_cos_theta_star->GetXaxis()->CenterTitle();
    h_cos_theta_star->GetYaxis()->SetTitle("dN/dCos(#theta*)");
    h_cos_theta_star->GetYaxis()->CenterTitle();

    h_ME_cos_theta_star->SetMinimum(0);
    h_ME_cos_theta_star->SetMarkerStyle(24);
    h_ME_cos_theta_star->SetMarkerColor(kBlue);
    h_ME_cos_theta_star->Draw("same PE");
    
    h_ME_cos_theta_star2->SetLineColor(kRed);
    h_ME_cos_theta_star2->SetMarkerStyle(24);
    h_ME_cos_theta_star2->SetMarkerColor(kRed);
    h_ME_cos_theta_star2->Draw("same PE");

    TLegend *legend = new TLegend(0.12, 0.65, 0.35, 0.9);
    legend->SetTextSize(0.03);
    legend->SetBorderSize(0);
    legend->SetFillStyle(0); // Transparent background

    legend->AddEntry(h_cos_theta_star, "US-US SE #Lambda-#Lambda Pairs", "p");
    legend->AddEntry(h_cos_theta_star2, "US-LS SE #Lambda-#Lambda Pairs", "p");
    legend->AddEntry(h_ME_cos_theta_star, "US-US ME #Lambda-#Lambda Pairs)", "p");
    legend->AddEntry(h_ME_cos_theta_star2, "US-LS ME #Lambda-#Lambda Pairs", "p");

    legend->Draw();

    c38->cd(3);
    h_cos_theta_star5->SetMinimum(0);
    h_cos_theta_star5->SetMarkerStyle(20);
    h_cos_theta_star5->SetMarkerColor(kBlue);
    h_cos_theta_star5->Draw("PE"); // Draw with error bars
    h_cos_theta_star5->SetTitle("#bar{#Lambda}#bar{#Lambda} Angular Correlation inside #DeltaR = 0.93");

    h_cos_theta_star6->SetLineColor(kRed);
    h_cos_theta_star6->SetMarkerStyle(20);
    h_cos_theta_star6->SetMarkerColor(kRed);
    h_cos_theta_star6->Draw("same PE"); // Draw with error bars

    h_cos_theta_star5->GetXaxis()->SetTitle("Cos(#theta*)");
    h_cos_theta_star5->GetXaxis()->CenterTitle();
    h_cos_theta_star5->GetYaxis()->SetTitle("dN/dCos(#theta*)");
    h_cos_theta_star5->GetYaxis()->CenterTitle();

    h_ME_cos_theta_star5->SetMinimum(0);
    h_ME_cos_theta_star5->SetMarkerStyle(24);
    h_ME_cos_theta_star5->SetMarkerColor(kBlue);
    h_ME_cos_theta_star5->Draw("same PE"); // Draw with error bars
    
    h_ME_cos_theta_star6->SetLineColor(kRed);
    h_ME_cos_theta_star6->SetMarkerStyle(24);
    h_ME_cos_theta_star6->SetMarkerColor(kRed);
    h_ME_cos_theta_star6->Draw("same PE"); // Draw with error bars

    TLegend *legend_3 = new TLegend(0.12, 0.65, 0.35, 0.9);
    legend_3->SetTextSize(0.03);
    legend_3->SetBorderSize(0);
    legend_3->SetFillStyle(0); // Transparent background

    legend_3->AddEntry(h_cos_theta_star5, "US-US SE #bar{#Lambda}-#bar{#Lambda} Pairs", "p");
    legend_3->AddEntry(h_cos_theta_star6, "US-LS SE #bar{#Lambda}-#bar{#Lambda} Pairs", "p");
    legend_3->AddEntry(h_ME_cos_theta_star5, "US-US ME #bar{#Lambda}-#bar{#Lambda} Pairs", "p");
    legend_3->AddEntry(h_ME_cos_theta_star6, "US-LS ME #bar{#Lambda}-#bar{#Lambda} Pairs", "p");

    legend_3->Draw();

    c38->cd(4);
    h_outside_cos_theta_star3->SetMinimum(0);
    h_outside_cos_theta_star3->SetMarkerStyle(20);
    h_outside_cos_theta_star3->SetMarkerColor(kBlue);
    h_outside_cos_theta_star3->Draw("PE"); // Draw with error bars
    h_outside_cos_theta_star3->SetTitle("#Lambda#bar{#Lambda} Angular Correlation outside #DeltaR = 0.93");

    h_outside_cos_theta_star4->SetMarkerStyle(20);
    h_outside_cos_theta_star4->SetLineColor(kRed);
    h_outside_cos_theta_star4->SetMarkerColor(kRed);
    h_outside_cos_theta_star4->Draw("same PE"); // Draw with error bars

    h_outside_cos_theta_star3->GetXaxis()->SetTitle("Cos(#theta*)");
    h_outside_cos_theta_star3->GetXaxis()->CenterTitle();
    h_outside_cos_theta_star3->GetYaxis()->SetTitle("dN/dCos(#theta*)");
    h_outside_cos_theta_star3->GetYaxis()->CenterTitle();

    h_outside_ME_cos_theta_star3->SetMinimum(0);
    h_outside_ME_cos_theta_star3->SetMarkerStyle(24);
    h_outside_ME_cos_theta_star3->SetMarkerColor(kBlue);
    h_outside_ME_cos_theta_star3->Draw("same PE"); // Draw with error bars
    
    h_outside_ME_cos_theta_star4->SetMarkerStyle(24);
    h_outside_ME_cos_theta_star4->SetLineColor(kRed);
    h_outside_ME_cos_theta_star4->SetMarkerColor(kRed);
    h_outside_ME_cos_theta_star4->Draw("same PE"); // Draw with error bars

    TLegend *legend_5 = new TLegend(0.12, 0.3, 0.4, 0.6);
    legend_5->SetTextSize(0.03);
    legend_5->SetBorderSize(0);
    legend_5->SetFillStyle(0); // Transparent background

    legend_5->AddEntry(h_outside_cos_theta_star3, "US-US SE #Lambda-#bar{#Lambda} Pairs", "p");
    legend_5->AddEntry(h_outside_cos_theta_star4, "US-LS SE #Lambda-#bar{#Lambda} Pairs", "p");
    legend_5->AddEntry(h_outside_ME_cos_theta_star3, "US-US ME #Lambda-#bar{#Lambda} Pairs", "p");
    legend_5->AddEntry(h_outside_ME_cos_theta_star4, "US-US SE #Lambda-#bar{#Lambda} Pairs", "p");

    legend_5->Draw();

    c38->cd(5);
    h_outside_cos_theta_star->SetMinimum(0);
    h_outside_cos_theta_star->SetMarkerStyle(20);
    h_outside_cos_theta_star->SetMarkerColor(kBlue);
    h_outside_cos_theta_star->Draw("PE");
    h_outside_cos_theta_star->SetTitle("#Lambda#Lambda Angular Correlation outside #DeltaR = 0.93");

    h_outside_cos_theta_star2->SetLineColor(kRed);
    h_outside_cos_theta_star2->SetMarkerStyle(20);
    h_outside_cos_theta_star2->SetMarkerColor(kRed);
    h_outside_cos_theta_star2->Draw("same PE");

    h_outside_cos_theta_star->GetXaxis()->SetTitle("Cos(#theta*)");
    h_outside_cos_theta_star->GetXaxis()->CenterTitle();
    h_outside_cos_theta_star->GetYaxis()->SetTitle("dN/dCos(#theta*)");
    h_outside_cos_theta_star->GetYaxis()->CenterTitle();

    h_outside_ME_cos_theta_star->SetMinimum(0);
    h_outside_ME_cos_theta_star->SetMarkerStyle(24);
    h_outside_ME_cos_theta_star->SetMarkerColor(kBlue);
    h_outside_ME_cos_theta_star->Draw("same PE");
    
    h_outside_ME_cos_theta_star2->SetLineColor(kRed);
    h_outside_ME_cos_theta_star2->SetMarkerStyle(24);
    h_outside_ME_cos_theta_star2->SetMarkerColor(kRed);
    h_outside_ME_cos_theta_star2->Draw("same PE");

    TLegend *legend_4 = new TLegend(0.12, 0.4, 0.4, 0.6);
    legend_4->SetTextSize(0.03);
    legend_4->SetBorderSize(0);
    legend_4->SetFillStyle(0); // Transparent background

    legend_4->AddEntry(h_outside_cos_theta_star, "US-US SE #Lambda-#Lambda Pairs", "p");
    legend_4->AddEntry(h_outside_cos_theta_star2, "US-LS SE #Lambda-#Lambda Pairs", "p");
    legend_4->AddEntry(h_outside_ME_cos_theta_star, "US-US ME #Lambda-#Lambda Pairs)", "p");
    legend_4->AddEntry(h_outside_ME_cos_theta_star2, "US-LS ME #Lambda-#Lambda Pairs", "p");

    legend_4->Draw();

    c38->cd(6);
    h_outside_cos_theta_star5->SetMinimum(0);
    h_outside_cos_theta_star5->SetMarkerStyle(20);
    h_outside_cos_theta_star5->SetMarkerColor(kBlue);
    h_outside_cos_theta_star5->Draw("PE"); // Draw with error bars
    h_outside_cos_theta_star5->SetTitle("#bar{#Lambda}#bar{#Lambda} Angular Correlation outside #DeltaR = 0.93");

    h_outside_cos_theta_star6->SetLineColor(kRed);
    h_outside_cos_theta_star6->SetMarkerStyle(20);
    h_outside_cos_theta_star6->SetMarkerColor(kRed);
    h_outside_cos_theta_star6->Draw("same PE"); // Draw with error bars

    h_outside_cos_theta_star5->GetXaxis()->SetTitle("Cos(#theta*)");
    h_outside_cos_theta_star5->GetXaxis()->CenterTitle();
    h_outside_cos_theta_star5->GetYaxis()->SetTitle("dN/dCos(#theta*)");
    h_outside_cos_theta_star5->GetYaxis()->CenterTitle();

    h_outside_ME_cos_theta_star5->SetMinimum(0);
    h_outside_ME_cos_theta_star5->SetMarkerStyle(24);
    h_outside_ME_cos_theta_star5->SetMarkerColor(kBlue);
    h_outside_ME_cos_theta_star5->Draw("same PE"); // Draw with error bars
    
    h_outside_ME_cos_theta_star6->SetLineColor(kRed);
    h_outside_ME_cos_theta_star6->SetMarkerStyle(24);
    h_outside_ME_cos_theta_star6->SetMarkerColor(kRed);
    h_outside_ME_cos_theta_star6->Draw("same PE"); // Draw with error bars

    TLegend *legend_6 = new TLegend(0.12, 0.3, 0.4, 0.6);
    legend_6->SetTextSize(0.03);
    legend_6->SetBorderSize(0);
    legend_6->SetFillStyle(0); // Transparent background

    legend_6->AddEntry(h_outside_cos_theta_star5, "US-US SE #bar{#Lambda}-#bar{#Lambda} Pairs", "p");
    legend_6->AddEntry(h_outside_cos_theta_star6, "US-LS SE #bar{#Lambda}-#bar{#Lambda} Pairs", "p");
    legend_6->AddEntry(h_outside_ME_cos_theta_star5, "US-US ME #bar{#Lambda}-#bar{#Lambda} Pairs", "p");
    legend_6->AddEntry(h_outside_ME_cos_theta_star6, "US-LS ME #bar{#Lambda}-#bar{#Lambda} Pairs", "p");

    legend_6->Draw();

    std::cout << "Canvas 38 Complete" << std::endl;

    std::unique_ptr<TCanvas> c39(new TCanvas("c39", "Canvas 39", 1800, 900));
    c39->Divide(3, 2);

    c39->cd(1);
    h2_cut_ME_L0_L0bar_p1pt_p2pt_US_US->Draw("COLZ");
    h2_cut_ME_L0_L0bar_p1pt_p2pt_US_US->SetTitle("Pt- US-US ME #Lambda#bar{#Lambda} Pairs inside #DeltaR = 0.93");
    h2_cut_ME_L0_L0bar_p1pt_p2pt_US_US->GetXaxis()->SetTitle("p1_pt [GeV/c]");
    h2_cut_ME_L0_L0bar_p1pt_p2pt_US_US->GetXaxis()->CenterTitle();
    h2_cut_ME_L0_L0bar_p1pt_p2pt_US_US->GetYaxis()->SetTitle("p2_pt [GeV/c]");
    h2_cut_ME_L0_L0bar_p1pt_p2pt_US_US->GetYaxis()->CenterTitle();

    c39->cd(2);
    h2_cut_ME_L0_L0bar_p1eta_p2eta_US_US->Draw("COLZ");
    h2_cut_ME_L0_L0bar_p1eta_p2eta_US_US->SetTitle("Eta- US-US ME #Lambda#bar{#Lambda} Pairs inside #DeltaR = 0.93");
    h2_cut_ME_L0_L0bar_p1eta_p2eta_US_US->GetXaxis()->SetTitle("p1_eta");
    h2_cut_ME_L0_L0bar_p1eta_p2eta_US_US->GetXaxis()->CenterTitle();
    h2_cut_ME_L0_L0bar_p1eta_p2eta_US_US->GetYaxis()->SetTitle("p2_eta");
    h2_cut_ME_L0_L0bar_p1eta_p2eta_US_US->GetYaxis()->CenterTitle();

    c39->cd(3);
    h2_cut_ME_L0_L0bar_p1phi_p2phi_US_LS->Draw("COLZ");
    h2_cut_ME_L0_L0bar_p1phi_p2phi_US_LS->SetTitle("Phi- US-US ME #Lambda#bar{#Lambda} Pairs inside #DeltaR = 0.93");
    h2_cut_ME_L0_L0bar_p1phi_p2phi_US_LS->GetXaxis()->SetTitle("p1_phi");
    h2_cut_ME_L0_L0bar_p1phi_p2phi_US_LS->GetXaxis()->CenterTitle();
    h2_cut_ME_L0_L0bar_p1phi_p2phi_US_LS->GetYaxis()->SetTitle("p2_phi");
    h2_cut_ME_L0_L0bar_p1phi_p2phi_US_LS->GetYaxis()->CenterTitle();

    c39->cd(4);
    h2_cut_ME_L0_L0bar_p1pt_p2pt_US_LS->Draw("COLZ");
    h2_cut_ME_L0_L0bar_p1pt_p2pt_US_LS->SetTitle("Pt- US-LS ME #Lambda#bar{#Lambda} Pairs inside #DeltaR = 0.93");
    h2_cut_ME_L0_L0bar_p1pt_p2pt_US_LS->GetXaxis()->SetTitle("p1_pt [GeV/c]");
    h2_cut_ME_L0_L0bar_p1pt_p2pt_US_LS->GetXaxis()->CenterTitle();
    h2_cut_ME_L0_L0bar_p1pt_p2pt_US_LS->GetYaxis()->SetTitle("p2_pt [GeV/c]");
    h2_cut_ME_L0_L0bar_p1pt_p2pt_US_LS->GetYaxis()->CenterTitle();

    c39->cd(5);
    h2_cut_ME_L0_L0bar_p1eta_p2eta_US_LS->Draw("COLZ");
    h2_cut_ME_L0_L0bar_p1eta_p2eta_US_LS->SetTitle("Eta- US-LS ME #Lambda#bar{#Lambda} Pairs inside #DeltaR = 0.93");
    h2_cut_ME_L0_L0bar_p1eta_p2eta_US_LS->GetXaxis()->SetTitle("p1_eta");
    h2_cut_ME_L0_L0bar_p1eta_p2eta_US_LS->GetXaxis()->CenterTitle();
    h2_cut_ME_L0_L0bar_p1eta_p2eta_US_LS->GetYaxis()->SetTitle("p2_eta");
    h2_cut_ME_L0_L0bar_p1eta_p2eta_US_LS->GetYaxis()->CenterTitle();

    c39->cd(6);
    h2_cut_ME_L0_L0bar_p1phi_p2phi_US_LS->Draw("COLZ");
    h2_cut_ME_L0_L0bar_p1phi_p2phi_US_LS->SetTitle("Phi- US-LS ME #Lambda#bar{#Lambda} Pairs inside #DeltaR = 0.93");
    h2_cut_ME_L0_L0bar_p1phi_p2phi_US_LS->GetXaxis()->SetTitle("p1_phi");
    h2_cut_ME_L0_L0bar_p1phi_p2phi_US_LS->GetXaxis()->CenterTitle();
    h2_cut_ME_L0_L0bar_p1phi_p2phi_US_LS->GetYaxis()->SetTitle("p2_phi");
    h2_cut_ME_L0_L0bar_p1phi_p2phi_US_LS->GetYaxis()->CenterTitle();

    std::cout << "Canvas 39 Complete" << std::endl;

    std::unique_ptr<TCanvas> c40(new TCanvas("c40", "Canvas 40", 1800, 900));
    c40->Divide(3, 2);

    c40->cd(1);
    h2_cut_ME_L0_L0_p1pt_p2pt_US_US->Draw("COLZ");
    h2_cut_ME_L0_L0_p1pt_p2pt_US_US->SetTitle("Pt- US-US ME #Lambda#Lambda Pairs inside #DeltaR = 0.93");
    h2_cut_ME_L0_L0_p1pt_p2pt_US_US->GetXaxis()->SetTitle("p1_pt [GeV/c]");
    h2_cut_ME_L0_L0_p1pt_p2pt_US_US->GetXaxis()->CenterTitle();
    h2_cut_ME_L0_L0_p1pt_p2pt_US_US->GetYaxis()->SetTitle("p2_pt [GeV/c]");
    h2_cut_ME_L0_L0_p1pt_p2pt_US_US->GetYaxis()->CenterTitle();

    c40->cd(2);
    h2_cut_ME_L0_L0_p1eta_p2eta_US_US->Draw("COLZ");
    h2_cut_ME_L0_L0_p1eta_p2eta_US_US->SetTitle("Eta- US-US ME #Lambda#Lambda Pairs inside #DeltaR = 0.93");
    h2_cut_ME_L0_L0_p1eta_p2eta_US_US->GetXaxis()->SetTitle("p1_eta");
    h2_cut_ME_L0_L0_p1eta_p2eta_US_US->GetXaxis()->CenterTitle();
    h2_cut_ME_L0_L0_p1eta_p2eta_US_US->GetYaxis()->SetTitle("p2_eta");
    h2_cut_ME_L0_L0_p1eta_p2eta_US_US->GetYaxis()->CenterTitle();

    c40->cd(3);
    h2_cut_ME_L0_L0_p1phi_p2phi_US_US->Draw("COLZ");
    h2_cut_ME_L0_L0_p1phi_p2phi_US_US->SetTitle("Phi- US-US ME #Lambda#Lambda Pairs inside #DeltaR = 0.93");
    h2_cut_ME_L0_L0_p1phi_p2phi_US_US->GetXaxis()->SetTitle("p1_phi");
    h2_cut_ME_L0_L0_p1phi_p2phi_US_US->GetXaxis()->CenterTitle();
    h2_cut_ME_L0_L0_p1phi_p2phi_US_US->GetYaxis()->SetTitle("p2_phi");
    h2_cut_ME_L0_L0_p1phi_p2phi_US_US->GetYaxis()->CenterTitle();

    c40->cd(4);
    h2_cut_ME_L0_L0_p1pt_p2pt_US_LS->Draw("COLZ");
    h2_cut_ME_L0_L0_p1pt_p2pt_US_LS->SetTitle("Pt- US-LS ME #Lambda#Lambda Pairs inside #DeltaR = 0.93");
    h2_cut_ME_L0_L0_p1pt_p2pt_US_LS->GetXaxis()->SetTitle("p1_pt [GeV/c]");
    h2_cut_ME_L0_L0_p1pt_p2pt_US_LS->GetXaxis()->CenterTitle();
    h2_cut_ME_L0_L0_p1pt_p2pt_US_LS->GetYaxis()->SetTitle("p2_pt [GeV/c]");
    h2_cut_ME_L0_L0_p1pt_p2pt_US_LS->GetYaxis()->CenterTitle();

    c40->cd(5);
    h2_cut_ME_L0_L0_p1eta_p2eta_US_LS->Draw("COLZ");
    h2_cut_ME_L0_L0_p1eta_p2eta_US_LS->SetTitle("Eta- US-LS ME #Lambda#Lambda Pairs inside #DeltaR = 0.93");
    h2_cut_ME_L0_L0_p1eta_p2eta_US_LS->GetXaxis()->SetTitle("p1_eta");
    h2_cut_ME_L0_L0_p1eta_p2eta_US_LS->GetXaxis()->CenterTitle();
    h2_cut_ME_L0_L0_p1eta_p2eta_US_LS->GetYaxis()->SetTitle("p2_eta");
    h2_cut_ME_L0_L0_p1eta_p2eta_US_LS->GetYaxis()->CenterTitle();

    c40->cd(6);
    h2_cut_ME_L0_L0_p1phi_p2phi_US_LS->Draw("COLZ");
    h2_cut_ME_L0_L0_p1phi_p2phi_US_LS->SetTitle("Phi- US-LS ME #Lambda#Lambda Pairs inside #DeltaR = 0.93");
    h2_cut_ME_L0_L0_p1phi_p2phi_US_LS->GetXaxis()->SetTitle("p1_phi");
    h2_cut_ME_L0_L0_p1phi_p2phi_US_LS->GetXaxis()->CenterTitle();
    h2_cut_ME_L0_L0_p1phi_p2phi_US_LS->GetYaxis()->SetTitle("p2_phi");
    h2_cut_ME_L0_L0_p1phi_p2phi_US_LS->GetYaxis()->CenterTitle();

    std::cout << "Canvas 40 Complete" << std::endl; 

    std::unique_ptr<TCanvas> c41(new TCanvas("c41", "Canvas 41", 1800, 900));
    c41->Divide(3, 2);

    c41->cd(1);
    h2_cut_ME_L0bar_L0bar_p1pt_p2pt_US_US->Draw("COLZ");
    h2_cut_ME_L0bar_L0bar_p1pt_p2pt_US_US->SetTitle("Pt- US-US ME #bar{#Lambda}#bar{#Lambda} Pairs inside #DeltaR = 0.93");
    h2_cut_ME_L0bar_L0bar_p1pt_p2pt_US_US->GetXaxis()->SetTitle("p1_pt [GeV/c]");
    h2_cut_ME_L0bar_L0bar_p1pt_p2pt_US_US->GetXaxis()->CenterTitle();
    h2_cut_ME_L0bar_L0bar_p1pt_p2pt_US_US->GetYaxis()->SetTitle("p2_pt [GeV/c]");
    h2_cut_ME_L0bar_L0bar_p1pt_p2pt_US_US->GetYaxis()->CenterTitle();

    c41->cd(2);
    h2_cut_ME_L0bar_L0bar_p1eta_p2eta_US_US->Draw("COLZ");
    h2_cut_ME_L0bar_L0bar_p1eta_p2eta_US_US->SetTitle("Eta- US-US ME #bar{#Lambda}#bar{#Lambda} Pairs inside #DeltaR = 0.93");
    h2_cut_ME_L0bar_L0bar_p1eta_p2eta_US_US->GetXaxis()->SetTitle("p1_eta");
    h2_cut_ME_L0bar_L0bar_p1eta_p2eta_US_US->GetXaxis()->CenterTitle();
    h2_cut_ME_L0bar_L0bar_p1eta_p2eta_US_US->GetYaxis()->SetTitle("p2_eta");
    h2_cut_ME_L0bar_L0bar_p1eta_p2eta_US_US->GetYaxis()->CenterTitle();

    c41->cd(3);
    h2_cut_ME_L0bar_L0bar_p1phi_p2phi_US_US->Draw("COLZ");
    h2_cut_ME_L0bar_L0bar_p1phi_p2phi_US_US->SetTitle("Phi- US-US #bar{#Lambda}#bar{#Lambda} Pairs inside #DeltaR = 0.93");
    h2_cut_ME_L0bar_L0bar_p1phi_p2phi_US_US->GetXaxis()->SetTitle("p1_phi");
    h2_cut_ME_L0bar_L0bar_p1phi_p2phi_US_US->GetXaxis()->CenterTitle();
    h2_cut_ME_L0bar_L0bar_p1phi_p2phi_US_US->GetYaxis()->SetTitle("p2_phi");
    h2_cut_ME_L0bar_L0bar_p1phi_p2phi_US_US->GetYaxis()->CenterTitle();

    c41->cd(4);
    h2_cut_ME_L0bar_L0bar_p1pt_p2pt_US_LS->Draw("COLZ");
    h2_cut_ME_L0bar_L0bar_p1pt_p2pt_US_LS->SetTitle("Pt- US-LS ME #bar{#Lambda}#bar{#Lambda} Pairs inside #DeltaR = 0.93");
    h2_cut_ME_L0bar_L0bar_p1pt_p2pt_US_LS->GetXaxis()->SetTitle("p1_pt [GeV/c]");
    h2_cut_ME_L0bar_L0bar_p1pt_p2pt_US_LS->GetXaxis()->CenterTitle();
    h2_cut_ME_L0bar_L0bar_p1pt_p2pt_US_LS->GetYaxis()->SetTitle("p2_pt [GeV/c]");
    h2_cut_ME_L0bar_L0bar_p1pt_p2pt_US_LS->GetYaxis()->CenterTitle();

    c41->cd(5);
    h2_cut_ME_L0bar_L0bar_p1eta_p2eta_US_LS->Draw("COLZ");
    h2_cut_ME_L0bar_L0bar_p1eta_p2eta_US_LS->SetTitle("Eta- US-LS ME #bar{#Lambda}#bar{#Lambda} Pairs inside #DeltaR = 0.93");
    h2_cut_ME_L0bar_L0bar_p1eta_p2eta_US_LS->GetXaxis()->SetTitle("p1_eta");
    h2_cut_ME_L0bar_L0bar_p1eta_p2eta_US_LS->GetXaxis()->CenterTitle();
    h2_cut_ME_L0bar_L0bar_p1eta_p2eta_US_LS->GetYaxis()->SetTitle("p2_eta");
    h2_cut_ME_L0bar_L0bar_p1eta_p2eta_US_LS->GetYaxis()->CenterTitle();

    c41->cd(6);
    h2_cut_ME_L0bar_L0bar_p1phi_p2phi_US_LS->Draw("COLZ");
    h2_cut_ME_L0bar_L0bar_p1phi_p2phi_US_LS->SetTitle("Phi- US-LS ME #bar{#Lambda}#bar{#Lambda} Pairs inside #DeltaR = 0.93");
    h2_cut_ME_L0bar_L0bar_p1phi_p2phi_US_LS->GetXaxis()->SetTitle("p1_phi");
    h2_cut_ME_L0bar_L0bar_p1phi_p2phi_US_LS->GetXaxis()->CenterTitle();
    h2_cut_ME_L0bar_L0bar_p1phi_p2phi_US_LS->GetYaxis()->SetTitle("p2_phi");
    h2_cut_ME_L0bar_L0bar_p1phi_p2phi_US_LS->GetYaxis()->CenterTitle();

    std::cout << "Canvas 41 Complete" << std::endl;

    std::unique_ptr<TCanvas> c42(new TCanvas("c42", "Canvas 42", 1800, 900));
    c42->Divide(3, 2);

    c42->cd(1);
    h2_cut_outside_ME_L0_L0bar_p1pt_p2pt_US_US->Draw("COLZ");
    h2_cut_outside_ME_L0_L0bar_p1pt_p2pt_US_US->SetTitle("Pt- US-US ME #Lambda#bar{#Lambda} Pairs outside #DeltaR = 0.93");
    h2_cut_outside_ME_L0_L0bar_p1pt_p2pt_US_US->GetXaxis()->SetTitle("p1_pt [GeV/c]");
    h2_cut_outside_ME_L0_L0bar_p1pt_p2pt_US_US->GetYaxis()->SetTitle("p2_pt [GeV/c]");

    c42->cd(2);
    h2_cut_outside_ME_L0_L0bar_p1eta_p2eta_US_US->Draw("COLZ");
    h2_cut_outside_ME_L0_L0bar_p1eta_p2eta_US_US->SetTitle("Eta- US-US ME #Lambda#bar{#Lambda} Pairs outside #DeltaR = 0.93");
    h2_cut_outside_ME_L0_L0bar_p1eta_p2eta_US_US->GetXaxis()->SetTitle("p1_eta");
    h2_cut_outside_ME_L0_L0bar_p1eta_p2eta_US_US->GetYaxis()->SetTitle("p2_eta");

    c42->cd(3);
    h2_cut_outside_ME_L0_L0bar_p1phi_p2phi_US_LS->Draw("COLZ");
    h2_cut_outside_ME_L0_L0bar_p1phi_p2phi_US_LS->SetTitle("Phi- US-US ME #Lambda#bar{#Lambda} Pairs outside #DeltaR = 0.93");
    h2_cut_outside_ME_L0_L0bar_p1phi_p2phi_US_LS->GetXaxis()->SetTitle("p1_phi");
    h2_cut_outside_ME_L0_L0bar_p1phi_p2phi_US_LS->GetYaxis()->SetTitle("p2_phi");

    c42->cd(4);
    h2_cut_outside_ME_L0_L0bar_p1pt_p2pt_US_LS->Draw("COLZ");
    h2_cut_outside_ME_L0_L0bar_p1pt_p2pt_US_LS->SetTitle("Pt- US-LS ME #Lambda#bar{#Lambda} Pairs outside #DeltaR = 0.93");
    h2_cut_outside_ME_L0_L0bar_p1pt_p2pt_US_LS->GetXaxis()->SetTitle("p1_pt [GeV/c]");
    h2_cut_outside_ME_L0_L0bar_p1pt_p2pt_US_LS->GetYaxis()->SetTitle("p2_pt [GeV/c]");

    c42->cd(5);
    h2_cut_outside_ME_L0_L0bar_p1eta_p2eta_US_LS->Draw("COLZ");
    h2_cut_outside_ME_L0_L0bar_p1eta_p2eta_US_LS->SetTitle("Eta- US-LS ME #Lambda#bar{#Lambda} Pairs outside #DeltaR = 0.93");
    h2_cut_outside_ME_L0_L0bar_p1eta_p2eta_US_LS->GetXaxis()->SetTitle("p1_eta");
    h2_cut_outside_ME_L0_L0bar_p1eta_p2eta_US_LS->GetYaxis()->SetTitle("p2_eta");

    c42->cd(6);
    h2_cut_outside_ME_L0_L0bar_p1phi_p2phi_US_LS->Draw("COLZ");
    h2_cut_outside_ME_L0_L0bar_p1phi_p2phi_US_LS->SetTitle("Phi- US-LS ME #Lambda#bar{#Lambda} Pairs outside #DeltaR = 0.93");
    h2_cut_outside_ME_L0_L0bar_p1phi_p2phi_US_LS->GetXaxis()->SetTitle("p1_phi");
    h2_cut_outside_ME_L0_L0bar_p1phi_p2phi_US_LS->GetYaxis()->SetTitle("p2_phi");

    std::cout << "Canvas 42 Complete" << std::endl;

    std::unique_ptr<TCanvas> c43(new TCanvas("c43", "Canvas 43", 1800, 900));
    c43->Divide(3, 2);

    c43->cd(1);
    h2_cut_outside_ME_L0_L0_p1pt_p2pt_US_US->Draw("COLZ");
    h2_cut_outside_ME_L0_L0_p1pt_p2pt_US_US->SetTitle("Pt- US-US ME #Lambda#Lambda Pairs outside #DeltaR = 0.93");
    h2_cut_outside_ME_L0_L0_p1pt_p2pt_US_US->GetXaxis()->SetTitle("p1_pt [GeV/c]");
    h2_cut_outside_ME_L0_L0_p1pt_p2pt_US_US->GetXaxis()->CenterTitle();
    h2_cut_outside_ME_L0_L0_p1pt_p2pt_US_US->GetYaxis()->SetTitle("p2_pt [GeV/c]");
    h2_cut_outside_ME_L0_L0_p1pt_p2pt_US_US->GetYaxis()->CenterTitle();

    c43->cd(2);
    h2_cut_outside_ME_L0_L0_p1eta_p2eta_US_US->Draw("COLZ");
    h2_cut_outside_ME_L0_L0_p1eta_p2eta_US_US->SetTitle("Eta- US-US ME #Lambda#Lambda Pairs outside #DeltaR = 0.93");
    h2_cut_outside_ME_L0_L0_p1eta_p2eta_US_US->GetXaxis()->SetTitle("p1_eta");
    h2_cut_outside_ME_L0_L0_p1eta_p2eta_US_US->GetXaxis()->CenterTitle();
    h2_cut_outside_ME_L0_L0_p1eta_p2eta_US_US->GetYaxis()->SetTitle("p2_eta");
    h2_cut_outside_ME_L0_L0_p1eta_p2eta_US_US->GetYaxis()->CenterTitle();

    c43->cd(3);
    h2_cut_outside_ME_L0_L0_p1phi_p2phi_US_US->Draw("COLZ");
    h2_cut_outside_ME_L0_L0_p1phi_p2phi_US_US->SetTitle("Phi- US-US ME #Lambda#Lambda Pairs outside #DeltaR = 0.93");
    h2_cut_outside_ME_L0_L0_p1phi_p2phi_US_US->GetXaxis()->SetTitle("p1_phi");
    h2_cut_outside_ME_L0_L0_p1phi_p2phi_US_US->GetXaxis()->CenterTitle();
    h2_cut_outside_ME_L0_L0_p1phi_p2phi_US_US->GetYaxis()->SetTitle("p2_phi");
    h2_cut_outside_ME_L0_L0_p1phi_p2phi_US_US->GetYaxis()->CenterTitle();

    c43->cd(4);
    h2_cut_outside_ME_L0_L0_p1pt_p2pt_US_LS->Draw("COLZ");
    h2_cut_outside_ME_L0_L0_p1pt_p2pt_US_LS->SetTitle("Pt- US-LS ME #Lambda#Lambda Pairs outside #DeltaR = 0.93");
    h2_cut_outside_ME_L0_L0_p1pt_p2pt_US_LS->GetXaxis()->SetTitle("p1_pt [GeV/c]");
    h2_cut_outside_ME_L0_L0_p1pt_p2pt_US_LS->GetXaxis()->CenterTitle();
    h2_cut_outside_ME_L0_L0_p1pt_p2pt_US_LS->GetYaxis()->SetTitle("p2_pt [GeV/c]");
    h2_cut_outside_ME_L0_L0_p1pt_p2pt_US_LS->GetYaxis()->CenterTitle();

    c43->cd(5);
    h2_cut_outside_ME_L0_L0_p1eta_p2eta_US_LS->Draw("COLZ");
    h2_cut_outside_ME_L0_L0_p1eta_p2eta_US_LS->SetTitle("Eta- US-LS ME #Lambda#Lambda Pairs outside #DeltaR = 0.93");
    h2_cut_outside_ME_L0_L0_p1eta_p2eta_US_LS->GetXaxis()->SetTitle("p1_eta");
    h2_cut_outside_ME_L0_L0_p1eta_p2eta_US_LS->GetXaxis()->CenterTitle();
    h2_cut_outside_ME_L0_L0_p1eta_p2eta_US_LS->GetYaxis()->SetTitle("p2_eta");
    h2_cut_outside_ME_L0_L0_p1eta_p2eta_US_LS->GetYaxis()->CenterTitle();

    c43->cd(6);
    h2_cut_outside_ME_L0_L0_p1phi_p2phi_US_LS->Draw("COLZ");
    h2_cut_outside_ME_L0_L0_p1phi_p2phi_US_LS->SetTitle("Phi- US-LS ME #Lambda#Lambda Pairs outside #DeltaR = 0.93");
    h2_cut_outside_ME_L0_L0_p1phi_p2phi_US_LS->GetXaxis()->SetTitle("p1_phi");
    h2_cut_outside_ME_L0_L0_p1phi_p2phi_US_LS->GetXaxis()->CenterTitle();
    h2_cut_outside_ME_L0_L0_p1phi_p2phi_US_LS->GetYaxis()->SetTitle("p2_phi");
    h2_cut_outside_ME_L0_L0_p1phi_p2phi_US_LS->GetYaxis()->CenterTitle();

    std::cout << "Canvas 43 Complete" << std::endl; 

    std::unique_ptr<TCanvas> c44(new TCanvas("c44", "Canvas 44", 1800, 900));
    c44->Divide(3, 2);

    c44->cd(1);
    h2_cut_outside_ME_L0bar_L0bar_p1pt_p2pt_US_US->Draw("COLZ");
    h2_cut_outside_ME_L0bar_L0bar_p1pt_p2pt_US_US->SetTitle("Pt- US-US ME #bar{#Lambda}#bar{#Lambda} Pairs outside #DeltaR = 0.93");
    h2_cut_outside_ME_L0bar_L0bar_p1pt_p2pt_US_US->GetXaxis()->SetTitle("p1_pt [GeV/c]");
    h2_cut_outside_ME_L0bar_L0bar_p1pt_p2pt_US_US->GetXaxis()->CenterTitle();
    h2_cut_outside_ME_L0bar_L0bar_p1pt_p2pt_US_US->GetYaxis()->SetTitle("p2_pt [GeV/c]");
    h2_cut_outside_ME_L0bar_L0bar_p1pt_p2pt_US_US->GetYaxis()->CenterTitle();

    c44->cd(2);
    h2_cut_outside_ME_L0bar_L0bar_p1eta_p2eta_US_US->Draw("COLZ");
    h2_cut_outside_ME_L0bar_L0bar_p1eta_p2eta_US_US->SetTitle("Eta- US-US ME #bar{#Lambda}#bar{#Lambda} Pairs outside #DeltaR = 0.93");
    h2_cut_outside_ME_L0bar_L0bar_p1eta_p2eta_US_US->GetXaxis()->SetTitle("p1_eta");
    h2_cut_outside_ME_L0bar_L0bar_p1eta_p2eta_US_US->GetXaxis()->CenterTitle();
    h2_cut_outside_ME_L0bar_L0bar_p1eta_p2eta_US_US->GetYaxis()->SetTitle("p2_eta");
    h2_cut_outside_ME_L0bar_L0bar_p1eta_p2eta_US_US->GetYaxis()->CenterTitle();

    c44->cd(3);
    h2_cut_outside_ME_L0bar_L0bar_p1phi_p2phi_US_US->Draw("COLZ");
    h2_cut_outside_ME_L0bar_L0bar_p1phi_p2phi_US_US->SetTitle("Phi- US-US ME #bar{#Lambda}#bar{#Lambda} Pairs outside #DeltaR = 0.93");
    h2_cut_outside_ME_L0bar_L0bar_p1phi_p2phi_US_US->GetXaxis()->SetTitle("p1_phi");
    h2_cut_outside_ME_L0bar_L0bar_p1phi_p2phi_US_US->GetXaxis()->CenterTitle();
    h2_cut_outside_ME_L0bar_L0bar_p1phi_p2phi_US_US->GetYaxis()->SetTitle("p2_phi");
    h2_cut_outside_ME_L0bar_L0bar_p1phi_p2phi_US_US->GetYaxis()->CenterTitle();

    c44->cd(4);
    h2_cut_outside_ME_L0bar_L0bar_p1pt_p2pt_US_LS->Draw("COLZ");
    h2_cut_outside_ME_L0bar_L0bar_p1pt_p2pt_US_LS->SetTitle("Pt- US-LS ME #bar{#Lambda}#bar{#Lambda} Pairs outside #DeltaR = 0.93");
    h2_cut_outside_ME_L0bar_L0bar_p1pt_p2pt_US_LS->GetXaxis()->SetTitle("p1_pt [GeV/c]");
    h2_cut_outside_ME_L0bar_L0bar_p1pt_p2pt_US_LS->GetXaxis()->CenterTitle();
    h2_cut_outside_ME_L0bar_L0bar_p1pt_p2pt_US_LS->GetYaxis()->SetTitle("p2_pt [GeV/c]");
    h2_cut_outside_ME_L0bar_L0bar_p1pt_p2pt_US_LS->GetYaxis()->CenterTitle();

    c44->cd(5);
    h2_cut_outside_ME_L0bar_L0bar_p1eta_p2eta_US_LS->Draw("COLZ");
    h2_cut_outside_ME_L0bar_L0bar_p1eta_p2eta_US_LS->SetTitle("Eta- US-LS ME #bar{#Lambda}#bar{#Lambda} Pairs outside #DeltaR = 0.93");
    h2_cut_outside_ME_L0bar_L0bar_p1eta_p2eta_US_LS->GetXaxis()->SetTitle("p1_eta");
    h2_cut_outside_ME_L0bar_L0bar_p1eta_p2eta_US_LS->GetXaxis()->CenterTitle();
    h2_cut_outside_ME_L0bar_L0bar_p1eta_p2eta_US_LS->GetYaxis()->SetTitle("p2_eta");
    h2_cut_outside_ME_L0bar_L0bar_p1eta_p2eta_US_LS->GetYaxis()->CenterTitle();

    c44->cd(6);
    h2_cut_outside_ME_L0bar_L0bar_p1phi_p2phi_US_LS->Draw("COLZ");
    h2_cut_outside_ME_L0bar_L0bar_p1phi_p2phi_US_LS->SetTitle("Phi- US-LS ME #bar{#Lambda}#bar{#Lambda} Pairs outside #DeltaR = 0.93");
    h2_cut_outside_ME_L0bar_L0bar_p1phi_p2phi_US_LS->GetXaxis()->SetTitle("p1_phi");
    h2_cut_outside_ME_L0bar_L0bar_p1phi_p2phi_US_LS->GetXaxis()->CenterTitle();
    h2_cut_outside_ME_L0bar_L0bar_p1phi_p2phi_US_LS->GetYaxis()->SetTitle("p2_phi");
    h2_cut_outside_ME_L0bar_L0bar_p1phi_p2phi_US_LS->GetYaxis()->CenterTitle();

    std::cout << "Canvas 44 Complete" << std::endl;

    std::unique_ptr<TCanvas> c45(new TCanvas("c45", "Canvas 45", 1800, 900));
    c45->Divide(3, 2);

    TH2F *h2_recombined_ME_L0_L0bar_p1pt_p2pt_US_US = new TH2F(*h2_cut_ME_L0_L0bar_p1pt_p2pt_US_US);
    h2_recombined_ME_L0_L0bar_p1pt_p2pt_US_US->Add(h2_cut_outside_ME_L0_L0bar_p1pt_p2pt_US_US, 1.0);

    TH2F *h2_recombined_ME_L0_L0bar_p1eta_p2eta_US_US = new TH2F(*h2_cut_ME_L0_L0bar_p1eta_p2eta_US_US);
    h2_recombined_ME_L0_L0bar_p1eta_p2eta_US_US->Add(h2_cut_outside_ME_L0_L0bar_p1eta_p2eta_US_US, 1.0);

    TH2F *h2_recombined_ME_L0_L0bar_p1phi_p2phi_US_US = new TH2F(*h2_cut_ME_L0_L0bar_p1phi_p2phi_US_US);
    h2_recombined_ME_L0_L0bar_p1phi_p2phi_US_US->Add(h2_cut_outside_ME_L0_L0bar_p1phi_p2phi_US_US, 1.0);

    TH2F *h2_recombined_ME_L0_L0bar_p1pt_p2pt_US_LS = new TH2F(*h2_cut_ME_L0_L0bar_p1pt_p2pt_US_LS);
    h2_recombined_ME_L0_L0bar_p1pt_p2pt_US_LS->Add(h2_cut_outside_ME_L0_L0bar_p1pt_p2pt_US_LS, 1.0);

    TH2F *h2_recombined_ME_L0_L0bar_p1eta_p2eta_US_LS = new TH2F(*h2_cut_ME_L0_L0bar_p1eta_p2eta_US_LS);
    h2_recombined_ME_L0_L0bar_p1eta_p2eta_US_LS->Add(h2_cut_outside_ME_L0_L0bar_p1eta_p2eta_US_LS, 1.0);

    TH2F *h2_recombined_ME_L0_L0bar_p1phi_p2phi_US_LS = new TH2F(*h2_cut_ME_L0_L0bar_p1phi_p2phi_US_LS);
    h2_recombined_ME_L0_L0bar_p1phi_p2phi_US_LS->Add(h2_cut_outside_ME_L0_L0bar_p1phi_p2phi_US_LS, 1.0);

    c45->cd(1);
    h2_recombined_ME_L0_L0bar_p1pt_p2pt_US_US->Draw("COLZ");
    h2_recombined_ME_L0_L0bar_p1pt_p2pt_US_US->SetTitle("Pt- US-US ME #Lambda#bar{#Lambda} Pairs inside and outside #DeltaR = 0.93");
    h2_recombined_ME_L0_L0bar_p1pt_p2pt_US_US->GetXaxis()->SetTitle("p1_pt [GeV/c]");
    h2_recombined_ME_L0_L0bar_p1pt_p2pt_US_US->GetXaxis()->CenterTitle();
    h2_recombined_ME_L0_L0bar_p1pt_p2pt_US_US->GetYaxis()->SetTitle("p2_pt [GeV/c]");
    h2_recombined_ME_L0_L0bar_p1pt_p2pt_US_US->GetYaxis()->CenterTitle();

    c45->cd(2);
    h2_recombined_ME_L0_L0bar_p1eta_p2eta_US_US->Draw("COLZ");
    h2_recombined_ME_L0_L0bar_p1eta_p2eta_US_US->SetTitle("Eta- US-US ME #Lambda#bar{#Lambda} Pairs inside and outside #DeltaR = 0.93");
    h2_recombined_ME_L0_L0bar_p1eta_p2eta_US_US->GetXaxis()->SetTitle("p1_eta");
    h2_recombined_ME_L0_L0bar_p1eta_p2eta_US_US->GetXaxis()->CenterTitle();
    h2_recombined_ME_L0_L0bar_p1eta_p2eta_US_US->GetYaxis()->SetTitle("p2_eta");
    h2_recombined_ME_L0_L0bar_p1eta_p2eta_US_US->GetYaxis()->CenterTitle();

    c45->cd(3);
    h2_recombined_ME_L0_L0bar_p1phi_p2phi_US_US->Draw("COLZ");
    h2_recombined_ME_L0_L0bar_p1phi_p2phi_US_US->SetTitle("Phi- US-US ME #Lambda#bar{#Lambda} Pairs inside and outside #DeltaR = 0.93");
    h2_recombined_ME_L0_L0bar_p1phi_p2phi_US_US->GetXaxis()->SetTitle("p1_phi");
    h2_recombined_ME_L0_L0bar_p1phi_p2phi_US_US->GetXaxis()->CenterTitle();
    h2_recombined_ME_L0_L0bar_p1phi_p2phi_US_US->GetYaxis()->SetTitle("p2_phi");
    h2_recombined_ME_L0_L0bar_p1phi_p2phi_US_US->GetYaxis()->CenterTitle();

    c45->cd(4);
    h2_recombined_ME_L0_L0bar_p1pt_p2pt_US_LS->Draw("COLZ");
    h2_recombined_ME_L0_L0bar_p1pt_p2pt_US_LS->SetTitle("Pt- US-LS ME #Lambda#bar{#Lambda} Pairs inside and outside #DeltaR = 0.93");
    h2_recombined_ME_L0_L0bar_p1pt_p2pt_US_LS->GetXaxis()->SetTitle("p1_pt [GeV/c]");
    h2_recombined_ME_L0_L0bar_p1pt_p2pt_US_LS->GetXaxis()->CenterTitle();
    h2_recombined_ME_L0_L0bar_p1pt_p2pt_US_LS->GetYaxis()->SetTitle("p2_pt [GeV/c]");
    h2_recombined_ME_L0_L0bar_p1pt_p2pt_US_LS->GetYaxis()->CenterTitle();

    c45->cd(5);
    h2_recombined_ME_L0_L0bar_p1eta_p2eta_US_LS->Draw("COLZ");
    h2_recombined_ME_L0_L0bar_p1eta_p2eta_US_LS->SetTitle("Eta- US-LS ME #Lambda#bar{#Lambda} Pairs inside and outside #DeltaR = 0.93");
    h2_recombined_ME_L0_L0bar_p1eta_p2eta_US_LS->GetXaxis()->SetTitle("p1_eta");
    h2_recombined_ME_L0_L0bar_p1eta_p2eta_US_LS->GetXaxis()->CenterTitle();
    h2_recombined_ME_L0_L0bar_p1eta_p2eta_US_LS->GetYaxis()->SetTitle("p2_eta");
    h2_recombined_ME_L0_L0bar_p1eta_p2eta_US_LS->GetYaxis()->CenterTitle();

    c45->cd(6);
    h2_recombined_ME_L0_L0bar_p1phi_p2phi_US_LS->Draw("COLZ");
    h2_recombined_ME_L0_L0bar_p1phi_p2phi_US_LS->SetTitle("Phi- US-LS ME #Lambda#bar{#Lambda} Pairs inside and outside #DeltaR = 0.93");
    h2_recombined_ME_L0_L0bar_p1phi_p2phi_US_LS->GetXaxis()->SetTitle("p1_phi");
    h2_recombined_ME_L0_L0bar_p1phi_p2phi_US_LS->GetXaxis()->CenterTitle();
    h2_recombined_ME_L0_L0bar_p1phi_p2phi_US_LS->GetYaxis()->SetTitle("p2_phi");
    h2_recombined_ME_L0_L0bar_p1phi_p2phi_US_LS->GetYaxis()->CenterTitle();

    std::cout << "Canvas 45 Complete" << std::endl;

    std::unique_ptr<TCanvas> c46(new TCanvas("c46", "Canvas 46", 1800, 900));
    c46->Divide(3, 2);

    TH2F *h2_recombined_ME_L0_L0_p1pt_p2pt_US_US = new TH2F(*h2_cut_ME_L0_L0_p1pt_p2pt_US_US);
    h2_recombined_ME_L0_L0_p1pt_p2pt_US_US->Add(h2_cut_outside_ME_L0_L0_p1pt_p2pt_US_US, 1.0);

    TH2F *h2_recombined_ME_L0_L0_p1eta_p2eta_US_US = new TH2F(*h2_cut_ME_L0_L0_p1eta_p2eta_US_US);
    h2_recombined_ME_L0_L0_p1eta_p2eta_US_US->Add(h2_cut_outside_ME_L0_L0_p1eta_p2eta_US_US, 1.0);

    TH2F *h2_recombined_ME_L0_L0_p1phi_p2phi_US_US = new TH2F(*h2_cut_ME_L0_L0_p1phi_p2phi_US_US);
    h2_recombined_ME_L0_L0_p1phi_p2phi_US_US->Add(h2_cut_outside_ME_L0_L0_p1phi_p2phi_US_US, 1.0);

    TH2F *h2_recombined_ME_L0_L0_p1pt_p2pt_US_LS = new TH2F(*h2_cut_ME_L0_L0_p1pt_p2pt_US_LS);
    h2_recombined_ME_L0_L0_p1pt_p2pt_US_LS->Add(h2_cut_outside_ME_L0_L0_p1pt_p2pt_US_LS, 1.0);

    TH2F *h2_recombined_ME_L0_L0_p1eta_p2eta_US_LS = new TH2F(*h2_cut_ME_L0_L0_p1eta_p2eta_US_LS);
    h2_recombined_ME_L0_L0_p1eta_p2eta_US_LS->Add(h2_cut_outside_ME_L0_L0_p1eta_p2eta_US_LS, 1.0);

    TH2F *h2_recombined_ME_L0_L0_p1phi_p2phi_US_LS = new TH2F(*h2_cut_ME_L0_L0_p1phi_p2phi_US_LS);
    h2_recombined_ME_L0_L0_p1phi_p2phi_US_LS->Add(h2_cut_outside_ME_L0_L0_p1phi_p2phi_US_LS, 1.0);

    c46->cd(1);
    h2_recombined_ME_L0_L0_p1pt_p2pt_US_US->Draw("COLZ");
    h2_recombined_ME_L0_L0_p1pt_p2pt_US_US->SetTitle("Pt- US-US ME #Lambda#Lambda Pairs inside and outside #DeltaR = 0.93");
    h2_recombined_ME_L0_L0_p1pt_p2pt_US_US->GetXaxis()->SetTitle("p1_pt [GeV/c]");
    h2_recombined_ME_L0_L0_p1pt_p2pt_US_US->GetXaxis()->CenterTitle();
    h2_recombined_ME_L0_L0_p1pt_p2pt_US_US->GetYaxis()->SetTitle("p2_pt [GeV/c]");
    h2_recombined_ME_L0_L0_p1pt_p2pt_US_US->GetYaxis()->CenterTitle();

    c46->cd(2);
    h2_recombined_ME_L0_L0_p1eta_p2eta_US_US->Draw("COLZ");
    h2_recombined_ME_L0_L0_p1eta_p2eta_US_US->SetTitle("Eta- US-US ME #Lambda#Lambda Pairs inside and outside #DeltaR = 0.93");
    h2_recombined_ME_L0_L0_p1eta_p2eta_US_US->GetXaxis()->SetTitle("p1_eta");
    h2_recombined_ME_L0_L0_p1eta_p2eta_US_US->GetXaxis()->CenterTitle();
    h2_recombined_ME_L0_L0_p1eta_p2eta_US_US->GetYaxis()->SetTitle("p2_eta");
    h2_recombined_ME_L0_L0_p1eta_p2eta_US_US->GetYaxis()->CenterTitle();

    c46->cd(3);
    h2_recombined_ME_L0_L0_p1phi_p2phi_US_US->Draw("COLZ");
    h2_recombined_ME_L0_L0_p1phi_p2phi_US_US->SetTitle("Phi- US-US ME #Lambda#Lambda Pairs inside and outside #DeltaR = 0.93");
    h2_recombined_ME_L0_L0_p1phi_p2phi_US_US->GetXaxis()->SetTitle("p1_phi");
    h2_recombined_ME_L0_L0_p1phi_p2phi_US_US->GetXaxis()->CenterTitle();
    h2_recombined_ME_L0_L0_p1phi_p2phi_US_US->GetYaxis()->SetTitle("p2_phi");
    h2_recombined_ME_L0_L0_p1phi_p2phi_US_US->GetYaxis()->CenterTitle();

    c46->cd(4);
    h2_recombined_ME_L0_L0_p1pt_p2pt_US_LS->Draw("COLZ");
    h2_recombined_ME_L0_L0_p1pt_p2pt_US_LS->SetTitle("Pt- US-LS ME #Lambda#Lambda Pairs inside and outside #DeltaR = 0.93");
    h2_recombined_ME_L0_L0_p1pt_p2pt_US_LS->GetXaxis()->SetTitle("p1_pt [GeV/c]");
    h2_recombined_ME_L0_L0_p1pt_p2pt_US_LS->GetXaxis()->CenterTitle();
    h2_recombined_ME_L0_L0_p1pt_p2pt_US_LS->GetYaxis()->SetTitle("p2_pt [GeV/c]");
    h2_recombined_ME_L0_L0_p1pt_p2pt_US_LS->GetYaxis()->CenterTitle();

    c46->cd(5);
    h2_recombined_ME_L0_L0_p1eta_p2eta_US_LS->Draw("COLZ");
    h2_recombined_ME_L0_L0_p1eta_p2eta_US_LS->SetTitle("Eta- US-LS ME #Lambda#Lambda Pairs inside and outside #DeltaR = 0.93");
    h2_recombined_ME_L0_L0_p1eta_p2eta_US_LS->GetXaxis()->SetTitle("p1_eta");
    h2_recombined_ME_L0_L0_p1eta_p2eta_US_LS->GetXaxis()->CenterTitle();
    h2_recombined_ME_L0_L0_p1eta_p2eta_US_LS->GetYaxis()->SetTitle("p2_eta");
    h2_recombined_ME_L0_L0_p1eta_p2eta_US_LS->GetYaxis()->CenterTitle();

    c46->cd(6);
    h2_recombined_ME_L0_L0_p1phi_p2phi_US_LS->Draw("COLZ");
    h2_recombined_ME_L0_L0_p1phi_p2phi_US_LS->SetTitle("Phi- US-LS ME #Lambda#Lambda Pairs inside and outside #DeltaR = 0.93");
    h2_recombined_ME_L0_L0_p1phi_p2phi_US_LS->GetXaxis()->SetTitle("p1_phi");
    h2_recombined_ME_L0_L0_p1phi_p2phi_US_LS->GetXaxis()->CenterTitle();
    h2_recombined_ME_L0_L0_p1phi_p2phi_US_LS->GetYaxis()->SetTitle("p2_phi");
    h2_recombined_ME_L0_L0_p1phi_p2phi_US_LS->GetYaxis()->CenterTitle();

    std::cout << "Canvas 46 Complete" << std::endl;

    std::unique_ptr<TCanvas> c47(new TCanvas("c47", "Canvas 47", 1800, 900));
    c47->Divide(3, 2);

    TH2F *h2_recombined_ME_L0bar_L0bar_p1pt_p2pt_US_US = new TH2F(*h2_cut_ME_L0bar_L0bar_p1pt_p2pt_US_US);
    h2_recombined_ME_L0bar_L0bar_p1pt_p2pt_US_US->Add(h2_cut_outside_ME_L0bar_L0bar_p1pt_p2pt_US_US, 1.0);

    TH2F *h2_recombined_ME_L0bar_L0bar_p1eta_p2eta_US_US = new TH2F(*h2_cut_ME_L0bar_L0bar_p1eta_p2eta_US_US);
    h2_recombined_ME_L0bar_L0bar_p1eta_p2eta_US_US->Add(h2_cut_outside_ME_L0bar_L0bar_p1eta_p2eta_US_US, 1.0);

    TH2F *h2_recombined_ME_L0bar_L0bar_p1phi_p2phi_US_US = new TH2F(*h2_cut_ME_L0bar_L0bar_p1phi_p2phi_US_US);
    h2_recombined_ME_L0bar_L0bar_p1phi_p2phi_US_US->Add(h2_cut_outside_ME_L0bar_L0bar_p1phi_p2phi_US_US, 1.0);

    TH2F *h2_recombined_ME_L0bar_L0bar_p1pt_p2pt_US_LS = new TH2F(*h2_cut_ME_L0bar_L0bar_p1pt_p2pt_US_LS);
    h2_recombined_ME_L0bar_L0bar_p1pt_p2pt_US_LS->Add(h2_cut_outside_ME_L0bar_L0bar_p1pt_p2pt_US_LS, 1.0);

    TH2F *h2_recombined_ME_L0bar_L0bar_p1eta_p2eta_US_LS = new TH2F(*h2_cut_ME_L0bar_L0bar_p1eta_p2eta_US_LS);
    h2_recombined_ME_L0bar_L0bar_p1eta_p2eta_US_LS->Add(h2_cut_outside_ME_L0bar_L0bar_p1eta_p2eta_US_LS, 1.0);

    TH2F *h2_recombined_ME_L0bar_L0bar_p1phi_p2phi_US_LS = new TH2F(*h2_cut_ME_L0bar_L0bar_p1phi_p2phi_US_LS);
    h2_recombined_ME_L0bar_L0bar_p1phi_p2phi_US_LS->Add(h2_cut_outside_ME_L0bar_L0bar_p1phi_p2phi_US_LS, 1.0);

    c47->cd(1);
    h2_recombined_ME_L0bar_L0bar_p1pt_p2pt_US_US->Draw("COLZ");
    h2_recombined_ME_L0bar_L0bar_p1pt_p2pt_US_US->SetTitle("Pt- US-US ME #bar{#Lambda}#bar{#Lambda} Pairs inside and outside #DeltaR = 0.93");
    h2_recombined_ME_L0bar_L0bar_p1pt_p2pt_US_US->GetXaxis()->SetTitle("p1_pt [GeV/c]");
    h2_recombined_ME_L0bar_L0bar_p1pt_p2pt_US_US->GetXaxis()->CenterTitle();
    h2_recombined_ME_L0bar_L0bar_p1pt_p2pt_US_US->GetYaxis()->SetTitle("p2_pt [GeV/c]");
    h2_recombined_ME_L0bar_L0bar_p1pt_p2pt_US_US->GetYaxis()->CenterTitle();

    c47->cd(2);
    h2_recombined_ME_L0bar_L0bar_p1eta_p2eta_US_US->Draw("COLZ");
    h2_recombined_ME_L0bar_L0bar_p1eta_p2eta_US_US->SetTitle("Eta- US-US ME #bar{#Lambda}#bar{#Lambda} Pairs inside and outside #DeltaR = 0.93");
    h2_recombined_ME_L0bar_L0bar_p1eta_p2eta_US_US->GetXaxis()->SetTitle("p1_eta");
    h2_recombined_ME_L0bar_L0bar_p1eta_p2eta_US_US->GetXaxis()->CenterTitle();
    h2_recombined_ME_L0bar_L0bar_p1eta_p2eta_US_US->GetYaxis()->SetTitle("p2_eta");
    h2_recombined_ME_L0bar_L0bar_p1eta_p2eta_US_US->GetYaxis()->CenterTitle();

    c47->cd(3);
    h2_recombined_ME_L0bar_L0bar_p1phi_p2phi_US_US->Draw("COLZ");
    h2_recombined_ME_L0bar_L0bar_p1phi_p2phi_US_US->SetTitle("Phi- US-US ME #bar{#Lambda}#bar{#Lambda} Pairs inside and outside #DeltaR = 0.93");
    h2_recombined_ME_L0bar_L0bar_p1phi_p2phi_US_US->GetXaxis()->SetTitle("p1_phi");
    h2_recombined_ME_L0bar_L0bar_p1phi_p2phi_US_US->GetXaxis()->CenterTitle();
    h2_recombined_ME_L0bar_L0bar_p1phi_p2phi_US_US->GetYaxis()->SetTitle("p2_phi");
    h2_recombined_ME_L0bar_L0bar_p1phi_p2phi_US_US->GetYaxis()->CenterTitle();


    c47->cd(4);
    h2_recombined_ME_L0bar_L0bar_p1pt_p2pt_US_LS->Draw("COLZ");
    h2_recombined_ME_L0bar_L0bar_p1pt_p2pt_US_LS->SetTitle("Pt- US-LS ME #bar{#Lambda}#bar{#Lambda} Pairs inside and outside #DeltaR = 0.93");
    h2_recombined_ME_L0bar_L0bar_p1pt_p2pt_US_LS->GetXaxis()->SetTitle("p1_pt [GeV/c]");
    h2_recombined_ME_L0bar_L0bar_p1pt_p2pt_US_LS->GetXaxis()->CenterTitle();
    h2_recombined_ME_L0bar_L0bar_p1pt_p2pt_US_LS->GetYaxis()->SetTitle("p2_pt [GeV/c]");
    h2_recombined_ME_L0bar_L0bar_p1pt_p2pt_US_LS->GetYaxis()->CenterTitle();

    c47->cd(5);
    h2_recombined_ME_L0bar_L0bar_p1eta_p2eta_US_LS->Draw("COLZ");
    h2_recombined_ME_L0bar_L0bar_p1eta_p2eta_US_LS->SetTitle("Eta- US-LS ME #bar{#Lambda}#bar{#Lambda} Pairs inside and outside #DeltaR = 0.93");
    h2_recombined_ME_L0bar_L0bar_p1eta_p2eta_US_LS->GetXaxis()->SetTitle("p1_eta");
    h2_recombined_ME_L0bar_L0bar_p1eta_p2eta_US_LS->GetXaxis()->CenterTitle();
    h2_recombined_ME_L0bar_L0bar_p1eta_p2eta_US_LS->GetYaxis()->SetTitle("p2_eta");
    h2_recombined_ME_L0bar_L0bar_p1eta_p2eta_US_LS->GetYaxis()->CenterTitle();

    c47->cd(6);
    h2_recombined_ME_L0bar_L0bar_p1phi_p2phi_US_LS->Draw("COLZ");
    h2_recombined_ME_L0bar_L0bar_p1phi_p2phi_US_LS->SetTitle("Phi- US-LS ME #bar{#Lambda}#bar{#Lambda} Pairs inside and outside #DeltaR = 0.93");
    h2_recombined_ME_L0bar_L0bar_p1phi_p2phi_US_LS->GetXaxis()->SetTitle("p1_phi");
    h2_recombined_ME_L0bar_L0bar_p1phi_p2phi_US_LS->GetXaxis()->CenterTitle();
    h2_recombined_ME_L0bar_L0bar_p1phi_p2phi_US_LS->GetYaxis()->SetTitle("p2_phi");
    h2_recombined_ME_L0bar_L0bar_p1phi_p2phi_US_LS->GetYaxis()->CenterTitle();

    std::cout << "Canvas 47 Complete" << std::endl;

    outFile_gold_3sig->cd();

    c1->Write();
    c2->Write();
    c3->Write();
    c4->Write();
    c5->Write();
    c6->Write();
    c7->Write();
    c8->Write();
    c9->Write();
    c10->Write();
    c11->Write();
    c12->Write();
    c13->Write();
    c14->Write();
    c15->Write();
    c16->Write();
    c17->Write();
    c18->Write();
    c19->Write();
    c20->Write();
    c21->Write();
    c22->Write();
    c23->Write();
    c24->Write();
    c25->Write();
    c26->Write();
    c27->Write();
    c28->Write();
    c29->Write();
    c30->Write();
    c31->Write();
    c32->Write();
    c33->Write();
    c34->Write();
    c35->Write();
    c36->Write();
    c37->Write();
    c38->Write();
    c39->Write();
    c40->Write();
    c41->Write();
    c42->Write();
    c43->Write();
    c44->Write();
    c45->Write();
    c46->Write();
    c47->Write();

    // Step 3: Close the file
    outFile_gold_3sig->Write();
    outFile_gold_3sig->Close();

    // c1->Update();
    // c2->Update();
    // c3->Update();
    // c4->Update();
    // c5->Update();
    // c6->Update();
    // c7->Update();
    // c8->Update();
    // c9->Update();
    // c10->Update();
    // c11->Update();
    // c12->Update();
    // c13->Update();
    // c14->Update();
    // c15->Update();
    // c16->Update();
    // c17->Update();
    // c18->Update();
    // c19->Update();
    // c20->Update();
    // c21->Update();
    // c22->Update();
    // c23->Update();
    // c24->Update();
    // c25->Update();
    // c26->Update();

    // c1->WaitPrimitive();
    // c2->WaitPrimitive();
    // c3->WaitPrimitive();
    // c4->WaitPrimitive();
    // c5->WaitPrimitive();
    // c6->WaitPrimitive();
    // c7->WaitPrimitive();
    // c8->WaitPrimitive();
    // c9->WaitPrimitive();
    // c10->WaitPrimitive();
    // c11->WaitPrimitive();
    // c12->WaitPrimitive();
    // c13->WaitPrimitive();
    // c14->WaitPrimitive();
    // c15->WaitPrimitive();
    // c16->WaitPrimitive();
    // c17->WaitPrimitive();
    // c18->WaitPrimitive();
    // c19->WaitPrimitive();
    // c20->WaitPrimitive();
    // c21->WaitPrimitive();
    // c22->WaitPrimitive();
    // c23->WaitPrimitive();
    // c24->WaitPrimitive();
    // c25->WaitPrimitive();
    // c26->WaitPrimitive();

    std::cout << "Analysis Complete" << std::endl;
}