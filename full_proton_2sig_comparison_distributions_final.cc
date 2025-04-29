#include <TFile.h>
#include <TH1.h>
#include <TCanvas.h>
#include <iostream>
#include <TGraph.h>

void full_proton_2sig_comparison_distributions() {
    TFile *LLbarOutFile_2sig = TFile::Open("ProdPlane_Lambda_ana_cuts_2sig.Root", "READ");
    TFile *file2 = TFile::Open("proton_output_2sig.root", "READ");

     if (!LLbarOutFile_2sig || LLbarOutFile_2sig->IsZombie()) {
        std::cerr << "Error: Cannot open LLbarOutFile!" << std::endl;
        return;
    }

    if (!file2 || file2->IsZombie()) {
        std::cerr << "Error: Cannot open file2!" << std::endl;
        return;
    }

    // Jan's Data
    TH2F *L0_L0bar_cos_theta_star_vs_delta_R_US_hist = (TH2F*)LLbarOutFile_2sig->Get("L0_L0bar_cos_theta_star_vs_delta_R_US_hist");
    TH2F *L0_L0bar_cos_theta_star_vs_delta_R_US_LS_hist = (TH2F*)LLbarOutFile_2sig->Get("L0_L0bar_cos_theta_star_vs_delta_R_US_LS_hist");

    TH2F *L0_L0_cos_theta_star_vs_delta_R_US_hist = (TH2F*)LLbarOutFile_2sig->Get("L0_L0_cos_theta_star_vs_delta_R_US_hist");
    TH2F *L0_L0_cos_theta_star_vs_delta_R_US_LS_hist = (TH2F*)LLbarOutFile_2sig->Get("L0_L0_cos_theta_star_vs_delta_R_US_LS_hist");

    TH2F *L0bar_L0bar_cos_theta_star_vs_delta_R_US_hist = (TH2F*)LLbarOutFile_2sig->Get("L0bar_L0bar_cos_theta_star_vs_delta_R_US_hist");
    TH2F *L0bar_L0bar_cos_theta_star_vs_delta_R_US_LS_hist = (TH2F*)LLbarOutFile_2sig->Get("L0bar_L0bar_cos_theta_star_vs_delta_R_US_LS_hist");

    // mixed events
    TH2F *L0_L0bar_cos_theta_star_vs_delta_R_US_ME_hist = (TH2F*)LLbarOutFile_2sig->Get("L0_L0bar_cos_theta_star_vs_delta_R_US_ME_hist");
    TH2F *L0_L0bar_cos_theta_star_vs_delta_R_US_LS_ME_hist = (TH2F*)LLbarOutFile_2sig->Get("L0_L0bar_cos_theta_star_vs_delta_R_US_LS_ME_hist");

    TH2F *L0_L0_cos_theta_star_vs_delta_R_US_ME_hist = (TH2F*)LLbarOutFile_2sig->Get("L0_L0_cos_theta_star_vs_delta_R_US_ME_hist");
    TH2F *L0_L0_cos_theta_star_vs_delta_R_US_LS_ME_hist = (TH2F*)LLbarOutFile_2sig->Get("L0_L0_cos_theta_star_vs_delta_R_US_LS_ME_hist");

    TH2F *L0bar_L0bar_cos_theta_star_vs_delta_R_US_ME_hist = (TH2F*)LLbarOutFile_2sig->Get("L0bar_L0bar_cos_theta_star_vs_delta_R_US_ME_hist");
    TH2F *L0bar_L0bar_cos_theta_star_vs_delta_R_US_LS_ME_hist = (TH2F*)LLbarOutFile_2sig->Get("L0bar_L0bar_cos_theta_star_vs_delta_R_US_LS_ME_hist");

    // My data
    TH2F *h_cos_theta_star = (TH2F*)file2->Get("h_cos_theta_star");
    TH2F *h_cos_theta_star2 = (TH2F*)file2->Get("h_cos_theta_star2");
    TH2F *h_cos_theta_star3 = (TH2F*)file2->Get("h_cos_theta_star3");
    TH2F *h_cos_theta_star4 = (TH2F*)file2->Get("h_cos_theta_star4");
    TH2F *h_cos_theta_star5 = (TH2F*)file2->Get("h_cos_theta_star5");
    TH2F *h_cos_theta_star6 = (TH2F*)file2->Get("h_cos_theta_star6");

    TH2F *h_outside_cos_theta_star = (TH2F*)file2->Get("h_outside_cos_theta_star");
    TH2F *h_outside_cos_theta_star2 = (TH2F*)file2->Get("h_outside_cos_theta_star2");
    TH2F *h_outside_cos_theta_star3 = (TH2F*)file2->Get("h_outside_cos_theta_star3");
    TH2F *h_outside_cos_theta_star4 = (TH2F*)file2->Get("h_outside_cos_theta_star4");
    TH2F *h_outside_cos_theta_star5 = (TH2F*)file2->Get("h_outside_cos_theta_star5");
    TH2F *h_outside_cos_theta_star6 = (TH2F*)file2->Get("h_outside_cos_theta_star6");

    TH2F *h_ME_cos_theta_star = (TH2F*)file2->Get("h_ME_cos_theta_star");
    TH2F *h_ME_cos_theta_star2 = (TH2F*)file2->Get("h_ME_cos_theta_star2");
    TH2F *h_ME_cos_theta_star3 = (TH2F*)file2->Get("h_ME_cos_theta_star3");
    TH2F *h_ME_cos_theta_star4 = (TH2F*)file2->Get("h_ME_cos_theta_star4");
    TH2F *h_ME_cos_theta_star5 = (TH2F*)file2->Get("h_ME_cos_theta_star5");
    TH2F *h_ME_cos_theta_star6 = (TH2F*)file2->Get("h_ME_cos_theta_star6");

    TH2F *h_outside_ME_cos_theta_star = (TH2F*)file2->Get("h_outside_ME_cos_theta_star");
    TH2F *h_outside_ME_cos_theta_star2 = (TH2F*)file2->Get("h_outside_ME_cos_theta_star2");
    TH2F *h_outside_ME_cos_theta_star3 = (TH2F*)file2->Get("h_outside_ME_cos_theta_star3");
    TH2F *h_outside_ME_cos_theta_star4 = (TH2F*)file2->Get("h_outside_ME_cos_theta_star4");
    TH2F *h_outside_ME_cos_theta_star5 = (TH2F*)file2->Get("h_outside_ME_cos_theta_star5");
    TH2F *h_outside_ME_cos_theta_star6 = (TH2F*)file2->Get("h_outside_ME_cos_theta_star6");

    TCanvas *c1 = new TCanvas("c1", "Canvas 1", 1800, 900);
    c1->Divide(3,2);

    c1->cd(1);
    TH1D *projX_LLbar_1 = L0_L0bar_cos_theta_star_vs_delta_R_US_hist->ProjectionX("projX_LLbar_1", 1, 1);
    projX_LLbar_1->SetStats(0);
    projX_LLbar_1->SetMinimum(0);
    projX_LLbar_1->SetMarkerStyle(20);
    projX_LLbar_1->SetMarkerColor(kBlue);
    projX_LLbar_1->SetTitle("L0_L0bar_cos_theta_star_vs_delta_R_US_hist; cos(#theta*); dN/dCos(#theta*)");
    projX_LLbar_1->GetXaxis()->CenterTitle();
    projX_LLbar_1->GetYaxis()->CenterTitle();

    // Project X-axis for Y-bin 2
    TH1D *projX_LLbar_2 = L0_L0bar_cos_theta_star_vs_delta_R_US_LS_hist->ProjectionX("projX_LLbar_2", 1, 1);
    projX_LLbar_2->SetStats(0);
    projX_LLbar_2->SetMinimum(0);
    projX_LLbar_2->SetMarkerStyle(21);
    projX_LLbar_2->SetMarkerColor(kRed);

    // Draw both on the same pad
    projX_LLbar_1->Draw("PE");
    projX_LLbar_2->Draw("PE same");

    c1->cd(2);
    TH1D *projX_LL_1 = L0_L0_cos_theta_star_vs_delta_R_US_hist->ProjectionX("projX_LL_1", 1, 1);
    projX_LL_1->SetStats(0);
    projX_LL_1->SetMinimum(0);
    projX_LL_1->SetMarkerStyle(20);
    projX_LL_1->SetMarkerColor(kBlue);
    projX_LL_1->SetTitle("L0_L0bar_cos_theta_star_vs_delta_R_US_hist; cos(#theta*); dN/dCos(#theta*)");
    projX_LL_1->GetXaxis()->CenterTitle();
    projX_LL_1->GetYaxis()->CenterTitle();

    // Project X-axis for Y-bin 2
    TH1D *projX_LL_2 = L0_L0_cos_theta_star_vs_delta_R_US_LS_hist->ProjectionX("projX_LL_2", 1, 1);
    projX_LL_2->SetStats(0);
    projX_LL_2->SetMinimum(0);
    projX_LL_2->SetMarkerStyle(21);
    projX_LL_2->SetMarkerColor(kRed);

    // Draw both on the same pad
    projX_LL_1->Draw("PE");
    projX_LL_2->Draw("PE same");

    c1->cd(3);
    TH1D *projX_LbarLbar_1 = L0bar_L0bar_cos_theta_star_vs_delta_R_US_hist->ProjectionX("projX_LbarLbar_1", 1, 1);
    projX_LbarLbar_1->SetStats(0);
    projX_LbarLbar_1->SetMinimum(0);
    projX_LbarLbar_1->SetMarkerStyle(20);
    projX_LbarLbar_1->SetMarkerColor(kBlue);
    projX_LbarLbar_1->SetTitle("L0bar_L0bar_cos_theta_star_vs_delta_R_US_hist; cos(#theta*); dN/dCos(#theta*)");
    projX_LbarLbar_1->GetXaxis()->CenterTitle();
    projX_LbarLbar_1->GetYaxis()->CenterTitle();

    // Project X-axis for Y-bin 2
    TH1D *projX_LbarLbar_2 = L0bar_L0bar_cos_theta_star_vs_delta_R_US_LS_hist->ProjectionX("projX_LbarLbar_2", 1, 1);
    projX_LbarLbar_2->SetStats(0);
    projX_LbarLbar_2->SetMinimum(0);
    projX_LbarLbar_2->SetMarkerStyle(21);
    projX_LbarLbar_2->SetMarkerColor(kRed);

    // Draw both on the same pad
    projX_LbarLbar_1->Draw("PE");
    projX_LbarLbar_2->Draw("PE same");

    c1->cd(4);
    TH1D *projX_LLbar_3 = L0_L0bar_cos_theta_star_vs_delta_R_US_hist->ProjectionX("projX_LLbar_3", 2, 2);
    projX_LLbar_3->SetStats(0);
    projX_LLbar_3->SetMinimum(0); // Ensure the Y-axis starts from 0
    projX_LLbar_3->SetMarkerStyle(20);
    projX_LLbar_3->SetMarkerColor(kBlue);
    projX_LLbar_3->SetTitle("L0_L0bar_cos_theta_star_vs_delta_R_hist; cos(#theta*); dN/dCos(#theta*)");
    projX_LLbar_3->GetXaxis()->CenterTitle();
    projX_LLbar_3->GetYaxis()->CenterTitle();

    TH1D *projX_LLbar_4 = L0_L0bar_cos_theta_star_vs_delta_R_US_LS_hist->ProjectionX("projX_LLbar_4", 2, 2);
    projX_LLbar_4->SetStats(0);
    projX_LLbar_4->SetMinimum(0); // Ensure the Y-axis starts from 0
    projX_LLbar_4->SetMarkerStyle(21);
    projX_LLbar_4->SetMarkerColor(kRed);

    // Draw both on the same pad
    projX_LLbar_3->Draw("PE");
    projX_LLbar_4->Draw("PE same");

    c1->cd(5);
    TH1D *projX_LL_3 = L0_L0_cos_theta_star_vs_delta_R_US_hist->ProjectionX("projX_LL_3", 2, 2);
    projX_LL_3->SetStats(0);
    projX_LL_3->SetMinimum(0); // Ensure the Y-axis starts from 0
    projX_LL_3->SetMarkerStyle(20);
    projX_LL_3->SetMarkerColor(kBlue);
    projX_LL_3->SetTitle("L0_L0bar_cos_theta_star_vs_delta_R_hist; cos(#theta*); dN/dCos(#theta*)");
    projX_LL_3->GetXaxis()->CenterTitle();
    projX_LL_3->GetYaxis()->CenterTitle();

    TH1D *projX_LL_4 = L0_L0_cos_theta_star_vs_delta_R_US_LS_hist->ProjectionX("projX_LL_4", 2, 2);
    projX_LL_4->SetStats(0);
    projX_LL_4->SetMinimum(0); // Ensure the Y-axis starts from 0
    projX_LL_4->SetMarkerStyle(21);
    projX_LL_4->SetMarkerColor(kRed);

    // Draw both on the same pad
    projX_LL_3->Draw("PE");
    projX_LL_4->Draw("PE same");

    double counts_projX_LL_4 = projX_LL_4->Integral();
    cout << projX_LL_4 << endl;

    c1->cd(6);
    TH1D *projX_LbarLbar_3 = L0bar_L0bar_cos_theta_star_vs_delta_R_US_hist->ProjectionX("projX_LbarLbar_3", 2, 2);
    projX_LbarLbar_3->SetStats(0);
    projX_LbarLbar_3->SetMinimum(0); // Ensure the Y-axis starts from 0
    projX_LbarLbar_3->SetMarkerStyle(20);
    projX_LbarLbar_3->SetMarkerColor(kBlue);
    projX_LbarLbar_3->SetTitle("L0bar_L0bar_cos_theta_star_vs_delta_R_US_hist; cos(#theta*); dN/dCos(#theta*)");
    projX_LbarLbar_3->GetXaxis()->CenterTitle();
    projX_LbarLbar_3->GetYaxis()->CenterTitle();

    TH1D *projX_LbarLbar_4 = L0bar_L0bar_cos_theta_star_vs_delta_R_US_LS_hist->ProjectionX("projX_LbarLbar_4", 2, 2);
    projX_LbarLbar_4->SetStats(0);
    projX_LbarLbar_4->SetMinimum(0); // Ensure the Y-axis starts from 0
    projX_LbarLbar_4->SetMarkerStyle(21);
    projX_LbarLbar_4->SetMarkerColor(kRed);

    // Draw both on the same pad
    projX_LbarLbar_3->Draw("PE");
    projX_LbarLbar_4->Draw("PE same");

    cout << "canvas 1 compete" << endl;

    double Inside_US_US_L0_L0bar = projX_LLbar_1->Integral();
    double Inside_US_LS_L0_L0bar = projX_LLbar_2->Integral();
    double Inside_US_US_L0_L0 = projX_LL_1->Integral();
    double Inside_US_LS_L0_L0 = projX_LL_2->Integral();
    double Inside_US_US_L0bar_L0bar = projX_LbarLbar_1->Integral();
    double Inside_US_LS_L0bar_L0bar = projX_LbarLbar_2->Integral();

    cout << "   " << endl;
    cout << "** Jan's SE dN/dCos(theta*) distributions without the normalization applied **" << endl;
    cout << "   " << endl;
    cout << "Counts US_US L0_L0bar inside Delta_R: " << Inside_US_US_L0_L0bar << endl;
    cout << "Counts US_LS L0_L0bar inside Delta_R: " << Inside_US_LS_L0_L0bar << endl;
    cout << "Counts US_US L0_L0 inside Delta_R: " << Inside_US_US_L0_L0 << endl;
    cout << "Counts US_LS L0_L0 inside Delta_R: " << Inside_US_LS_L0_L0 << endl;
    cout << "Counts US_US L0bar_L0bar inside Delta_R: " << Inside_US_US_L0bar_L0bar << endl;
    cout << "Counts US_LS L0bar_L0bar inside Delta_R: " << Inside_US_LS_L0bar_L0bar << endl;

    double Outside_US_US_L0_L0bar = projX_LLbar_3->Integral();
    double Outside_US_LS_L0_L0bar = projX_LLbar_4->Integral();
    double Outside_US_US_L0_L0 = projX_LL_3->Integral();
    double Outside_US_LS_L0_L0 = projX_LL_4->Integral();
    double Outside_US_US_L0bar_L0bar = projX_LbarLbar_3->Integral();
    double Outside_US_LS_L0bar_L0bar = projX_LbarLbar_4->Integral();

    cout << "   " << endl;
    cout << "Counts US_US L0_L0bar Outside Delta_R: " << Outside_US_US_L0_L0bar << endl;
    cout << "Counts US_LS L0_L0bar Outside Delta_R: " << Outside_US_LS_L0_L0bar << endl;
    cout << "Counts US_US L0_L0 Outside Delta_R: " << Outside_US_US_L0_L0 << endl;
    cout << "Counts US_LS L0_L0 Outside Delta_R: " << Outside_US_LS_L0_L0 << endl;
    cout << "Counts US_US L0bar_L0bar Outside Delta_R: " << Outside_US_US_L0bar_L0bar << endl;
    cout << "Counts US_LS L0bar_L0bar Outside Delta_R: " << Outside_US_LS_L0bar_L0bar << endl;
    cout << "   " << endl;

    TCanvas *c2 = new TCanvas("c2", "Canvas 2", 1800, 900);
    c2->Divide(3,2);

    c2->cd(1);
    TH1D *projX_ME_LLbar_1 = L0_L0bar_cos_theta_star_vs_delta_R_US_ME_hist->ProjectionX("projX_ME_LLbar_1", 1, 1);
    projX_ME_LLbar_1->SetStats(0);
    projX_ME_LLbar_1->SetMinimum(0);
    projX_ME_LLbar_1->SetMarkerStyle(20);
    projX_ME_LLbar_1->SetMarkerColor(kBlue);
    projX_ME_LLbar_1->SetTitle("L0_L0bar_cos_theta_star_vs_delta_R_US_ME_hist; cos(#theta*); dN/dCos(#theta*)");
    projX_ME_LLbar_1->GetXaxis()->CenterTitle();
    projX_ME_LLbar_1->GetYaxis()->CenterTitle();

    // Project X-axis for Y-bin 2
    TH1D *projX_ME_LLbar_2 = L0_L0bar_cos_theta_star_vs_delta_R_US_LS_ME_hist->ProjectionX("projX_ME_LLbar_2", 1, 1);
    projX_ME_LLbar_2->SetStats(0);
    projX_ME_LLbar_2->SetMinimum(0);
    projX_ME_LLbar_2->SetMarkerStyle(21);
    projX_ME_LLbar_2->SetMarkerColor(kRed);

    // Draw both on the same pad
    projX_ME_LLbar_1->Draw("PE");
    projX_ME_LLbar_2->Draw("PE same");

    c2->cd(2);
    TH1D *projX_ME_LL_1 = L0_L0_cos_theta_star_vs_delta_R_US_ME_hist->ProjectionX("projX_ME_LL_1", 1, 1);
    projX_ME_LL_1->SetStats(0);
    projX_ME_LL_1->SetMinimum(0);
    projX_ME_LL_1->SetMarkerStyle(20);
    projX_ME_LL_1->SetMarkerColor(kBlue);
    projX_ME_LL_1->SetTitle("L0_L0_cos_theta_star_vs_delta_R_US_ME_hist; cos(#theta*); dN/dCos(#theta*)");
    projX_ME_LL_1->GetXaxis()->CenterTitle();
    projX_ME_LL_1->GetYaxis()->CenterTitle();

    // Project X-axis for Y-bin 2
    TH1D *projX_ME_LL_2 = L0_L0_cos_theta_star_vs_delta_R_US_LS_ME_hist->ProjectionX("projX_ME_LL_2", 1, 1);
    projX_ME_LL_2->SetStats(0);
    projX_ME_LL_2->SetMinimum(0);
    projX_ME_LL_2->SetMarkerStyle(21);
    projX_ME_LL_2->SetMarkerColor(kRed);

    // Draw both on the same pad
    projX_ME_LL_1->Draw("PE");
    projX_ME_LL_2->Draw("PE same");

    c2->cd(3);
    TH1D *projX_ME_LbarLbar_1 = L0bar_L0bar_cos_theta_star_vs_delta_R_US_ME_hist->ProjectionX("projX_ME_LbarLbar_1", 1, 1);
    projX_ME_LbarLbar_1->SetStats(0);
    projX_ME_LbarLbar_1->SetMinimum(0);
    projX_ME_LbarLbar_1->SetMarkerStyle(20);
    projX_ME_LbarLbar_1->SetMarkerColor(kBlue);
    projX_ME_LbarLbar_1->SetTitle("L0bar_L0bar_cos_theta_star_vs_delta_R_US_ME_hist; cos(#theta*); dN/dCos(#theta*)");
    projX_ME_LbarLbar_1->GetXaxis()->CenterTitle();
    projX_ME_LbarLbar_1->GetYaxis()->CenterTitle();

    // Project X-axis for Y-bin 2
    TH1D *projX_ME_LbarLbar_2 = L0bar_L0bar_cos_theta_star_vs_delta_R_US_LS_ME_hist->ProjectionX("projX_ME_LbarLbar_2", 1, 1);
    projX_ME_LbarLbar_2->SetStats(0);
    projX_ME_LbarLbar_2->SetMinimum(0);
    projX_ME_LbarLbar_2->SetMarkerStyle(21);
    projX_ME_LbarLbar_2->SetMarkerColor(kRed);

    // Draw both on the same pad
    projX_ME_LbarLbar_1->Draw("PE");
    projX_ME_LbarLbar_2->Draw("PE same");

    c2->cd(4);
    TH1D *projX_ME_LLbar_3 = L0_L0bar_cos_theta_star_vs_delta_R_US_ME_hist->ProjectionX("projX_ME_LLbar_3", 2, 2);
    projX_ME_LLbar_3->SetStats(0);
    projX_ME_LLbar_3->SetMinimum(0); // Ensure the Y-axis starts from 0
    projX_ME_LLbar_3->SetMarkerStyle(20);
    projX_ME_LLbar_3->SetMarkerColor(kBlue);
    projX_ME_LLbar_3->SetTitle("L0_L0bar_cos_theta_star_vs_delta_R_US_ME_hist; cos(#theta*); dN/dCos(#theta*)");
    projX_ME_LLbar_3->GetXaxis()->CenterTitle();
    projX_ME_LLbar_3->GetYaxis()->CenterTitle();

    TH1D *projX_ME_LLbar_4 = L0_L0bar_cos_theta_star_vs_delta_R_US_LS_ME_hist->ProjectionX("projX_ME_LLbar_4", 2, 2);
    projX_LLbar_4->SetStats(0);
    projX_LLbar_4->SetMinimum(0); // Ensure the Y-axis starts from 0
    projX_LLbar_4->SetMarkerStyle(20);
    projX_LLbar_4->SetMarkerColor(kRed);

    // Draw both on the same pad
    projX_LLbar_3->Draw("PE");
    projX_LLbar_4->Draw("PE same");

    c2->cd(5);
    TH1D *projX_ME_LL_3 = L0_L0_cos_theta_star_vs_delta_R_US_ME_hist->ProjectionX("projX_ME_LL_3", 2, 2);
    projX_ME_LL_3->SetStats(0);
    projX_ME_LL_3->SetMinimum(0); // Ensure the Y-axis starts from 0
    projX_ME_LL_3->SetMarkerStyle(20);
    projX_ME_LL_3->SetMarkerColor(kBlue);
    projX_ME_LL_3->SetTitle("L0_L0_cos_theta_star_vs_delta_R_US_ME_hist; cos(#theta*); dN/dCos(#theta*)");
    projX_ME_LL_3->GetXaxis()->CenterTitle();
    projX_ME_LL_3->GetYaxis()->CenterTitle();

    TH1D *projX_ME_LL_4 = L0_L0_cos_theta_star_vs_delta_R_US_LS_ME_hist->ProjectionX("projX_ME_LL_4", 2, 2);
    projX_ME_LL_4->SetStats(0);
    projX_ME_LL_4->SetMinimum(0);
    projX_ME_LL_4->SetMarkerStyle(20);
    projX_ME_LL_4->SetMarkerColor(kRed);

    // Draw both on the same pad
    projX_ME_LL_3->Draw("PE");
    projX_ME_LL_4->Draw("PE same");

    c2->cd(6);
    TH1D *projX_ME_LbarLbar_3 = L0bar_L0bar_cos_theta_star_vs_delta_R_US_ME_hist->ProjectionX("projX_ME_LbarLbar_3", 2, 2);
    projX_ME_LbarLbar_3->SetStats(0);
    projX_ME_LbarLbar_3->SetMinimum(0); // Ensure the Y-axis starts from 0
    projX_ME_LbarLbar_3->SetMarkerStyle(20);
    projX_ME_LbarLbar_3->SetMarkerColor(kBlue);
    projX_ME_LbarLbar_3->SetTitle("L0bar_L0bar_cos_theta_star_vs_delta_R_ME_US_hist; cos(#theta*); dN/dCos(#theta*)");
    projX_ME_LbarLbar_3->GetXaxis()->CenterTitle();
    projX_ME_LbarLbar_3->GetYaxis()->CenterTitle();

    TH1D *projX_ME_LbarLbar_4 = L0bar_L0bar_cos_theta_star_vs_delta_R_US_LS_ME_hist->ProjectionX("projX_ME_LbarLbar_4", 2, 2);
    projX_ME_LbarLbar_4->SetStats(0);
    projX_ME_LbarLbar_4->SetMinimum(0); // Ensure the Y-axis starts from 0
    projX_ME_LbarLbar_4->SetMarkerStyle(20);
    projX_ME_LbarLbar_4->SetMarkerColor(kRed);

    // Draw both on the same pad
    projX_ME_LbarLbar_3->Draw("PE");
    projX_ME_LbarLbar_4->Draw("PE same");

    cout << "canvas 2 compete" << endl;

    double Inside_US_US_ME_L0_L0bar = projX_ME_LLbar_1->Integral();
    double Inside_US_LS_ME_L0_L0bar = projX_ME_LLbar_2->Integral();
    double Inside_US_US_ME_L0_L0 = projX_ME_LL_1->Integral();
    double Inside_US_LS_ME_L0_L0 = projX_ME_LL_2->Integral();
    double Inside_US_US_ME_L0bar_L0bar = projX_ME_LbarLbar_1->Integral();
    double Inside_US_LS_ME_L0bar_L0bar = projX_ME_LbarLbar_2->Integral();

    cout << "   " << endl;
    cout << "** Jan's ME dN/dCos(theta*) distributions without the normalization applied **" << endl;
    cout << "   " << endl;
    cout << "Counts US_US L0_L0bar inside Delta_R: " << Inside_US_US_ME_L0_L0bar << endl;
    cout << "Counts US_LS L0_L0bar inside Delta_R: " << Inside_US_LS_ME_L0_L0bar << endl;
    cout << "Counts US_US L0_L0 inside Delta_R: " << Inside_US_US_ME_L0_L0 << endl;
    cout << "Counts US_LS L0_L0 inside Delta_R: " << Inside_US_LS_ME_L0_L0 << endl;
    cout << "Counts US_US L0bar_L0bar inside Delta_R: " << Inside_US_US_ME_L0bar_L0bar << endl;
    cout << "Counts US_LS L0bar_L0bar inside Delta_R: " << Inside_US_LS_ME_L0bar_L0bar << endl;

    double Outside_US_US_ME_L0_L0bar = projX_ME_LLbar_3->Integral();
    double Outside_US_LS_ME_L0_L0bar = projX_ME_LLbar_4->Integral();
    double Outside_US_US_ME_L0_L0 = projX_ME_LL_3->Integral();
    double Outside_US_LS_ME_L0_L0 = projX_ME_LL_4->Integral();
    double Outside_US_US_ME_L0bar_L0bar = projX_ME_LbarLbar_3->Integral();
    double Outside_US_LS_ME_L0bar_L0bar = projX_ME_LbarLbar_4->Integral();

    cout << "   " << endl;
    cout << "Counts US_US L0_L0bar Outside Delta_R: " << Outside_US_US_ME_L0_L0bar << endl;
    cout << "Counts US_LS L0_L0bar Outside Delta_R: " << Outside_US_LS_ME_L0_L0bar << endl;
    cout << "Counts US_US L0_L0 Outside Delta_R: " << Outside_US_US_ME_L0_L0 << endl;
    cout << "Counts US_LS L0_L0 Outside Delta_R: " << Outside_US_LS_ME_L0_L0 << endl;
    cout << "Counts US_US L0bar_L0bar Outside Delta_R: " << Outside_US_US_ME_L0bar_L0bar << endl;
    cout << "Counts US_LS L0bar_L0bar Outside Delta_R: " << Outside_US_LS_ME_L0bar_L0bar << endl;
    cout << "   " << endl; 

    TCanvas *c3 = new TCanvas("c3", "Canvas 3", 1800, 900);
    c3->Divide(3,2);

    c3->cd(1);
    TH1D *h1_L0_L0bar_cos_theta_star_US_US = (TH1D*)projX_LLbar_1->Clone("h1_L0_L0bar_cos_theta_star_US_US");
    TH1D *h1_L0_L0bar_cos_theta_star_US_LS = (TH1D*)projX_LLbar_2->Clone("h1_L0_L0bar_cos_theta_star_US_LS");  

    h1_L0_L0bar_cos_theta_star_US_US->Scale(1.0/h1_L0_L0bar_cos_theta_star_US_US->GetXaxis()->GetBinWidth(1));
    h1_L0_L0bar_cos_theta_star_US_LS->Scale(1.0/h1_L0_L0bar_cos_theta_star_US_LS->GetXaxis()->GetBinWidth(1));

    h1_L0_L0bar_cos_theta_star_US_US->Scale(1.0/1000);
    h1_L0_L0bar_cos_theta_star_US_LS->Scale(1.0/1000);

    h1_L0_L0bar_cos_theta_star_US_US->SetStats(0);
    h1_L0_L0bar_cos_theta_star_US_US->SetMinimum(0);
    h1_L0_L0bar_cos_theta_star_US_US->SetMarkerStyle(25);
    h1_L0_L0bar_cos_theta_star_US_US->SetMarkerColor(kBlue);
    h1_L0_L0bar_cos_theta_star_US_US->SetTitle("SE L0-L0bar Pairs inside #DeltaR=0.93; cos(#theta*); dN/dCos(#theta*)"); 
    h1_L0_L0bar_cos_theta_star_US_US->GetXaxis()->CenterTitle();
    h1_L0_L0bar_cos_theta_star_US_US->GetYaxis()->CenterTitle();

    h_cos_theta_star3->SetStats(0);
    h_cos_theta_star3->SetMinimum(0);
    h_cos_theta_star3->SetMarkerStyle(20);
    h_cos_theta_star3->SetMarkerColor(kBlue);

    h1_L0_L0bar_cos_theta_star_US_LS->SetStats(0);
    h1_L0_L0bar_cos_theta_star_US_LS->SetMinimum(0);
    h1_L0_L0bar_cos_theta_star_US_LS->SetMarkerStyle(25);
    h1_L0_L0bar_cos_theta_star_US_LS->SetMarkerColor(kRed);
    h1_L0_L0bar_cos_theta_star_US_LS->SetLineColor(kRed);

    h_cos_theta_star4->SetStats(0);
    h_cos_theta_star4->SetMinimum(0);
    h_cos_theta_star4->SetMarkerStyle(20);
    h_cos_theta_star4->SetMarkerColor(kRed);
    h_cos_theta_star4->SetLineColor(kRed);

    h1_L0_L0bar_cos_theta_star_US_US->Draw("PE"); 
    h1_L0_L0bar_cos_theta_star_US_LS->Draw("PE same");
    h_cos_theta_star3->Draw("PE same");
    h_cos_theta_star4->Draw("PE same");

    c3->cd(2);
    TH1D *h1_L0_L0_cos_theta_star_US_US = (TH1D*)projX_LL_1->Clone("h1_L0_L0_cos_theta_star_US_US");
    TH1D *h1_L0_L0_cos_theta_star_US_LS = (TH1D*)projX_LL_2->Clone("h1_L0_L0_cos_theta_star_US_LS");  

    h1_L0_L0_cos_theta_star_US_US->Scale(1.0/h1_L0_L0_cos_theta_star_US_US->GetXaxis()->GetBinWidth(1));
    h1_L0_L0_cos_theta_star_US_LS->Scale(1.0/h1_L0_L0_cos_theta_star_US_LS->GetXaxis()->GetBinWidth(1));

    h1_L0_L0_cos_theta_star_US_US->Scale(1.0/1000);
    h1_L0_L0_cos_theta_star_US_LS->Scale(1.0/1000);

    h1_L0_L0_cos_theta_star_US_US->SetStats(0);
    h1_L0_L0_cos_theta_star_US_US->SetMinimum(0);
    h1_L0_L0_cos_theta_star_US_US->SetMarkerStyle(25);
    h1_L0_L0_cos_theta_star_US_US->SetMarkerColor(kBlue);
    h1_L0_L0_cos_theta_star_US_US->SetTitle("SE L0-L0 Pairs inside #DeltaR; cos(#theta*); dN/dCos(#theta*)"); 
    h1_L0_L0_cos_theta_star_US_US->GetXaxis()->CenterTitle();
    h1_L0_L0_cos_theta_star_US_US->GetYaxis()->CenterTitle();

    h_cos_theta_star->SetStats(0);
    h_cos_theta_star->SetMinimum(0);
    h_cos_theta_star->SetMarkerStyle(20);
    h_cos_theta_star->SetMarkerColor(kBlue);

    h1_L0_L0_cos_theta_star_US_LS->SetStats(0);
    h1_L0_L0_cos_theta_star_US_LS->SetMinimum(0);
    h1_L0_L0_cos_theta_star_US_LS->SetMarkerStyle(25);
    h1_L0_L0_cos_theta_star_US_LS->SetMarkerColor(kRed);
    h1_L0_L0_cos_theta_star_US_LS->SetLineColor(kRed);

    h_cos_theta_star2->SetStats(0);
    h_cos_theta_star2->SetMinimum(0);
    h_cos_theta_star2->SetMarkerStyle(20);
    h_cos_theta_star2->SetMarkerColor(kRed);
    h_cos_theta_star2->SetLineColor(kRed);

    h1_L0_L0_cos_theta_star_US_US->Draw("PE"); 
    h1_L0_L0_cos_theta_star_US_LS->Draw("PE same");
    h_cos_theta_star->Draw("PE same");
    h_cos_theta_star2->Draw("PE same");

    c3->cd(3);
    TH1D *h1_L0bar_L0bar_cos_theta_star_US_US = (TH1D*)projX_LbarLbar_1->Clone("h1_L0bar_L0bar_cos_theta_star_US_US");
    TH1D *h1_L0bar_L0bar_cos_theta_star_US_LS = (TH1D*)projX_LbarLbar_2->Clone("h1_L0bar_L0bar_cos_theta_star_US_LS");  

    h1_L0bar_L0bar_cos_theta_star_US_US->Scale(1.0/h1_L0bar_L0bar_cos_theta_star_US_US->GetXaxis()->GetBinWidth(1));
    h1_L0bar_L0bar_cos_theta_star_US_LS->Scale(1.0/h1_L0bar_L0bar_cos_theta_star_US_LS->GetXaxis()->GetBinWidth(1));

    h1_L0bar_L0bar_cos_theta_star_US_US->Scale(1.0/1000);
    h1_L0bar_L0bar_cos_theta_star_US_LS->Scale(1.0/1000);

    h1_L0bar_L0bar_cos_theta_star_US_US->SetStats(0);
    h1_L0bar_L0bar_cos_theta_star_US_US->SetMinimum(0);
    h1_L0bar_L0bar_cos_theta_star_US_US->SetMarkerStyle(25);
    h1_L0bar_L0bar_cos_theta_star_US_US->SetMarkerColor(kBlue);
    h1_L0bar_L0bar_cos_theta_star_US_US->SetTitle("SE L0bar- L0bar Pairs inside #DeltaR; cos(#theta*); dN/dCos(#theta*)"); 
    h1_L0bar_L0bar_cos_theta_star_US_US->GetXaxis()->CenterTitle();
    h1_L0bar_L0bar_cos_theta_star_US_US->GetYaxis()->CenterTitle();

    h1_L0bar_L0bar_cos_theta_star_US_LS->SetStats(0);
    h1_L0bar_L0bar_cos_theta_star_US_LS->SetMinimum(0);
    h1_L0bar_L0bar_cos_theta_star_US_LS->SetMarkerStyle(25);
    h1_L0bar_L0bar_cos_theta_star_US_LS->SetMarkerColor(kRed);
    h1_L0bar_L0bar_cos_theta_star_US_LS->SetLineColor(kRed);

    h_cos_theta_star5->SetStats(0);
    h_cos_theta_star5->SetMinimum(0);
    h_cos_theta_star5->SetMarkerStyle(20);
    h_cos_theta_star5->SetMarkerColor(kBlue);

    h_cos_theta_star6->SetStats(0);
    h_cos_theta_star6->SetMinimum(0);
    h_cos_theta_star6->SetMarkerStyle(20);
    h_cos_theta_star6->SetMarkerColor(kRed);
    h_cos_theta_star6->SetLineColor(kRed);

    h1_L0bar_L0bar_cos_theta_star_US_US->Draw("PE"); 
    h1_L0bar_L0bar_cos_theta_star_US_LS->Draw("PE same");
    h_cos_theta_star5->Draw("PE same"); 
    h_cos_theta_star6->Draw("PE same");

    c3->cd(4);
    TH1D *h1_L0_L0bar_outside_cos_theta_star_US_US = (TH1D*)projX_LLbar_3->Clone("h1_L0_L0bar_outside_cos_theta_star_US_US");
    TH1D *h1_L0_L0bar_outside_cos_theta_star_US_LS = (TH1D*)projX_LLbar_4->Clone("h1_L0_L0bar_outside_cos_theta_star_US_LS");  

    h1_L0_L0bar_outside_cos_theta_star_US_US->Scale(1.0/h1_L0_L0bar_outside_cos_theta_star_US_US->GetXaxis()->GetBinWidth(1));
    h1_L0_L0bar_outside_cos_theta_star_US_LS->Scale(1.0/h1_L0_L0bar_outside_cos_theta_star_US_LS->GetXaxis()->GetBinWidth(1));

    h1_L0_L0bar_outside_cos_theta_star_US_US->Scale(1.0/1000);
    h1_L0_L0bar_outside_cos_theta_star_US_LS->Scale(1.0/1000);

    h1_L0_L0bar_outside_cos_theta_star_US_US->SetStats(0);
    h1_L0_L0bar_outside_cos_theta_star_US_US->SetMinimum(0);
    h1_L0_L0bar_outside_cos_theta_star_US_US->SetMarkerStyle(25);
    h1_L0_L0bar_outside_cos_theta_star_US_US->SetMarkerColor(kBlue);
    h1_L0_L0bar_outside_cos_theta_star_US_US->SetTitle("SE L0-L0bar Pairs outside #DeltaR; cos(#theta*); dN/dCos(#theta*)"); 
    h1_L0_L0bar_outside_cos_theta_star_US_US->GetXaxis()->CenterTitle();
    h1_L0_L0bar_outside_cos_theta_star_US_US->GetYaxis()->CenterTitle();

    h1_L0_L0bar_outside_cos_theta_star_US_LS->SetStats(0);
    h1_L0_L0bar_outside_cos_theta_star_US_LS->SetMinimum(0);
    h1_L0_L0bar_outside_cos_theta_star_US_LS->SetMarkerStyle(25);
    h1_L0_L0bar_outside_cos_theta_star_US_LS->SetMarkerColor(kRed);
    h1_L0_L0bar_outside_cos_theta_star_US_LS->SetLineColor(kRed);

    h_outside_cos_theta_star3->SetStats(0);
    h_outside_cos_theta_star3->SetMinimum(0);
    h_outside_cos_theta_star3->SetMarkerStyle(20);
    h_outside_cos_theta_star3->SetMarkerColor(kBlue);

    h_outside_cos_theta_star4->SetStats(0);
    h_outside_cos_theta_star4->SetMinimum(0);
    h_outside_cos_theta_star4->SetMarkerStyle(20);
    h_outside_cos_theta_star4->SetMarkerColor(kRed);
    h_outside_cos_theta_star4->SetLineColor(kRed);

    h1_L0_L0bar_outside_cos_theta_star_US_US->Draw("PE"); 
    h1_L0_L0bar_outside_cos_theta_star_US_LS->Draw("PE same");
    h_outside_cos_theta_star3->Draw("PE same");
    h_outside_cos_theta_star4->Draw("PE same");

    c3->cd(5);
    TH1D *h1_L0_L0_outside_cos_theta_star_US_US = (TH1D*)projX_LL_3->Clone("h1_L0_L0_outside_cos_theta_star_US_US");
    TH1D *h1_L0_L0_outside_cos_theta_star_US_LS = (TH1D*)projX_LL_4->Clone("h1_L0_L0_outside_cos_theta_star_US_LS");  

    h1_L0_L0_outside_cos_theta_star_US_US->Scale(1.0/h1_L0_L0_outside_cos_theta_star_US_US->GetXaxis()->GetBinWidth(1));
    h1_L0_L0_outside_cos_theta_star_US_LS->Scale(1.0/h1_L0_L0_outside_cos_theta_star_US_LS->GetXaxis()->GetBinWidth(1));

    h1_L0_L0_outside_cos_theta_star_US_US->Scale(1.0/1000);
    h1_L0_L0_outside_cos_theta_star_US_LS->Scale(1.0/1000);

    h1_L0_L0_outside_cos_theta_star_US_US->SetStats(0);
    h1_L0_L0_outside_cos_theta_star_US_US->SetMinimum(0);
    h1_L0_L0_outside_cos_theta_star_US_US->SetMarkerStyle(25);
    h1_L0_L0_outside_cos_theta_star_US_US->SetMarkerColor(kBlue);
    h1_L0_L0_outside_cos_theta_star_US_US->SetTitle("SE L0-L0 Pairs outside #DeltaR; cos(#theta*); dN/dCos(#theta*)"); 
    h1_L0_L0_outside_cos_theta_star_US_US->GetXaxis()->CenterTitle();
    h1_L0_L0_outside_cos_theta_star_US_US->GetYaxis()->CenterTitle();

    h1_L0_L0_outside_cos_theta_star_US_LS->SetStats(0);
    h1_L0_L0_outside_cos_theta_star_US_LS->SetMinimum(0);
    h1_L0_L0_outside_cos_theta_star_US_LS->SetMarkerStyle(25);
    h1_L0_L0_outside_cos_theta_star_US_LS->SetMarkerColor(kRed);
    h1_L0_L0_outside_cos_theta_star_US_LS->SetLineColor(kRed);

    h_outside_cos_theta_star->SetStats(0);
    h_outside_cos_theta_star->SetMinimum(0);
    h_outside_cos_theta_star->SetMarkerStyle(20);
    h_outside_cos_theta_star->SetMarkerColor(kBlue);

    h_outside_cos_theta_star2->SetStats(0);
    h_outside_cos_theta_star2->SetMinimum(0);
    h_outside_cos_theta_star2->SetMarkerStyle(20);
    h_outside_cos_theta_star2->SetMarkerColor(kRed);
    h_outside_cos_theta_star2->SetLineColor(kRed);

    h1_L0_L0_outside_cos_theta_star_US_US->Draw("PE"); 
    h1_L0_L0_outside_cos_theta_star_US_LS->Draw("PE same");
    h_outside_cos_theta_star->Draw("PE same");
    h_outside_cos_theta_star2->Draw("PE same");

    c3->cd(6);
    TH1D *h1_L0bar_L0bar_outside_cos_theta_star_US_US = (TH1D*)projX_LbarLbar_3->Clone("h1_L0bar_L0bar_outside_cos_theta_star_US_US");
    TH1D *h1_L0bar_L0bar_outside_cos_theta_star_US_LS = (TH1D*)projX_LbarLbar_4->Clone("h1_L0bar_L0bar_outside_cos_theta_star_US_LS");  

    h1_L0bar_L0bar_outside_cos_theta_star_US_US->Scale(1.0/h1_L0bar_L0bar_outside_cos_theta_star_US_US->GetXaxis()->GetBinWidth(1));
    h1_L0bar_L0bar_outside_cos_theta_star_US_LS->Scale(1.0/h1_L0bar_L0bar_outside_cos_theta_star_US_LS->GetXaxis()->GetBinWidth(1));

    h1_L0bar_L0bar_outside_cos_theta_star_US_US->Scale(1.0/1000);
    h1_L0bar_L0bar_outside_cos_theta_star_US_LS->Scale(1.0/1000);

    h1_L0bar_L0bar_outside_cos_theta_star_US_US->SetStats(0);
    h1_L0bar_L0bar_outside_cos_theta_star_US_US->SetMinimum(0);
    h1_L0bar_L0bar_outside_cos_theta_star_US_US->SetMarkerStyle(25);
    h1_L0bar_L0bar_outside_cos_theta_star_US_US->SetMarkerColor(kBlue);
    h1_L0bar_L0bar_outside_cos_theta_star_US_US->SetTitle("SE L0bar-L0bar Pairs outside #DeltaR; cos(#theta*); dN/dCos(#theta*)"); 
    h1_L0bar_L0bar_outside_cos_theta_star_US_US->GetXaxis()->CenterTitle();
    h1_L0bar_L0bar_outside_cos_theta_star_US_US->GetYaxis()->CenterTitle();

    h1_L0bar_L0bar_outside_cos_theta_star_US_LS->SetStats(0);
    h1_L0bar_L0bar_outside_cos_theta_star_US_LS->SetMinimum(0);
    h1_L0bar_L0bar_outside_cos_theta_star_US_LS->SetMarkerStyle(25);
    h1_L0bar_L0bar_outside_cos_theta_star_US_LS->SetMarkerColor(kRed);
    h1_L0bar_L0bar_outside_cos_theta_star_US_LS->SetLineColor(kRed);

    h_outside_cos_theta_star5->SetStats(0);
    h_outside_cos_theta_star5->SetMinimum(0);
    h_outside_cos_theta_star5->SetMarkerStyle(20);
    h_outside_cos_theta_star5->SetMarkerColor(kBlue);

    h_outside_cos_theta_star6->SetStats(0);
    h_outside_cos_theta_star6->SetMinimum(0);
    h_outside_cos_theta_star6->SetMarkerStyle(20);
    h_outside_cos_theta_star6->SetMarkerColor(kRed);
    h_outside_cos_theta_star6->SetLineColor(kRed);

    h1_L0bar_L0bar_outside_cos_theta_star_US_US->Draw("PE"); 
    h1_L0bar_L0bar_outside_cos_theta_star_US_LS->Draw("PE same");
    h_outside_cos_theta_star5->Draw("PE same");
    h_outside_cos_theta_star6->Draw("PE same");

    std::cout << "Canvas 3 Complete" << std::endl;

    double Counts_SE_US_US_L0_L0bar = h1_L0_L0bar_cos_theta_star_US_US->Integral();
    double Counts_SE_US_LS_L0_L0bar = h1_L0_L0bar_cos_theta_star_US_LS->Integral();
    double Counts_SE_US_US_L0_L0 = h1_L0_L0_cos_theta_star_US_US->Integral();
    double Counts_SE_US_LS_L0_L0 = h1_L0_L0_cos_theta_star_US_LS->Integral();
    double Counts_SE_US_US_L0bar_L0bar = h1_L0bar_L0bar_cos_theta_star_US_US->Integral();
    double Counts_SE_US_LS_L0bar_L0bar = h1_L0bar_L0bar_cos_theta_star_US_LS->Integral();

    cout << "   " << endl;
    cout << "** Jan's dN/dCos(theta*) distributions with the normalization applied **" << endl;
    cout << "   " << endl;
    cout << "Counts inside the Delta_R Cut" << endl;
    cout << "US-US L0-L0bar: " << Counts_SE_US_US_L0_L0bar << endl;
    cout << "US-LS L0-L0bar: " << Counts_SE_US_LS_L0_L0bar << endl;
    cout << "US-US L0-L0: " << Counts_SE_US_US_L0_L0 << endl;
    cout << "US-LS L0-L0: " << Counts_SE_US_LS_L0_L0 << endl;
    cout << "US-US L0bar-L0bar: " << Counts_SE_US_US_L0bar_L0bar << endl;
    cout << "US-LS L0bar-L0bar: " << Counts_SE_US_LS_L0bar_L0bar << endl;

    double Counts_outside_SE_US_US_L0_L0bar = h1_L0_L0bar_outside_cos_theta_star_US_US->Integral();
    double Counts_outside_SE_US_LS_L0_L0bar = h1_L0_L0bar_outside_cos_theta_star_US_LS->Integral();
    double Counts_outside_SE_US_US_L0_L0 = h1_L0_L0_outside_cos_theta_star_US_US->Integral();
    double Counts_outside_SE_US_LS_L0_L0 = h1_L0_L0_outside_cos_theta_star_US_LS->Integral();
    double Counts_outside_SE_US_US_L0bar_L0bar = h1_L0bar_L0bar_outside_cos_theta_star_US_US->Integral();
    double Counts_outside_SE_US_LS_L0bar_L0bar = h1_L0bar_L0bar_outside_cos_theta_star_US_LS->Integral();

    cout << "   " << endl;
    cout << "Counts outside the Delta_R Cut" << endl;
    cout << "US-US L0-L0bar: " << Counts_outside_SE_US_US_L0_L0bar << endl;
    cout << "US-LS L0-L0bar: " << Counts_outside_SE_US_LS_L0_L0bar << endl;
    cout << "US-US L0-L0: " << Counts_outside_SE_US_US_L0_L0 << endl;
    cout << "US-LS L0-L0: " << Counts_outside_SE_US_LS_L0_L0 << endl;
    cout << "US-US L0bar-L0bar: " << Counts_outside_SE_US_US_L0bar_L0bar << endl;
    cout << "US-LS L0bar-L0bar: " << Counts_outside_SE_US_LS_L0bar_L0bar << endl;

    cout << "   " << endl;
    cout << "** Kristen's dN/dCos(theta*) distributions with the normalization applied **" << endl;
    cout << "   " << endl;

    double counts_cos_theta_star3 = h_cos_theta_star3->Integral();
    double counts_cos_theta_star4 = h_cos_theta_star4->Integral();
    double counts_cos_theta_star = h_cos_theta_star->Integral();
    double counts_cos_theta_star2 = h_cos_theta_star2->Integral();
    double counts_cos_theta_star5 = h_cos_theta_star5->Integral();
    double counts_cos_theta_star6 = h_cos_theta_star6->Integral();

    cout << "Kristen's Data: Counts inside the delta_R cut" << endl;
    cout << "US-US L0-L0bar: " << counts_cos_theta_star3 << endl;
    cout << "US-LS L0-L0bar: " << counts_cos_theta_star4 << endl;
    cout << "US-US L0-L0: " << counts_cos_theta_star << endl;
    cout << "US-LS L0-L0: " << counts_cos_theta_star2 << endl;
    cout << "US-US L0bar-L0bar: " << counts_cos_theta_star5 << endl;
    cout << "US-LS L0bar-L0bar: " << counts_cos_theta_star6 << endl;

    double counts_outside_cos_theta_star3 = h_outside_cos_theta_star3->Integral();
    double counts_outside_cos_theta_star4 = h_outside_cos_theta_star4->Integral();
    double counts_outside_cos_theta_star = h_outside_cos_theta_star->Integral();
    double counts_outside_cos_theta_star2 = h_outside_cos_theta_star2->Integral();
    double counts_outside_cos_theta_star5 = h_outside_cos_theta_star5->Integral();
    double counts_outside_cos_theta_star6 = h_outside_cos_theta_star6->Integral();

    cout << "   " << endl;
    cout << "Kristen's Data: Counts outside the delta_R cut" << endl;
    cout << "US-US L0-L0bar: " << counts_outside_cos_theta_star3 << endl;
    cout << "US-LS L0-L0bar: " << counts_outside_cos_theta_star4 << endl;
    cout << "US-US L0-L0: " << counts_outside_cos_theta_star << endl;
    cout << "US-LS L0-L0: " << counts_outside_cos_theta_star2 << endl;
    cout << "US-US L0bar-L0bar: " << counts_outside_cos_theta_star5 << endl;
    cout << "US-LS L0bar-L0bar: " << counts_outside_cos_theta_star6 << endl;

    TCanvas *c4 = new TCanvas("c4", "Canvas 4", 1800, 900);
    c4->Divide(3,2);

    c4->cd(1);
    TH1D *h1_L0_L0bar_ME_cos_theta_star_US_US = (TH1D*)projX_ME_LLbar_1->Clone("h1_L0_L0bar_ME_cos_theta_star_US_US");
    TH1D *h1_L0_L0bar_ME_cos_theta_star_US_LS = (TH1D*)projX_ME_LLbar_2->Clone("h1_L0_L0bar_ME_cos_theta_star_US_LS");  

    h1_L0_L0bar_ME_cos_theta_star_US_US->Scale(1.0/h1_L0_L0bar_ME_cos_theta_star_US_US->GetXaxis()->GetBinWidth(1));
    h1_L0_L0bar_ME_cos_theta_star_US_LS->Scale(1.0/h1_L0_L0bar_ME_cos_theta_star_US_LS->GetXaxis()->GetBinWidth(1));

    h1_L0_L0bar_ME_cos_theta_star_US_US->Scale(1.0/1000);
    h1_L0_L0bar_ME_cos_theta_star_US_LS->Scale(1.0/1000);

    double Counts_ME_US_US_L0_L0bar = h1_L0_L0bar_ME_cos_theta_star_US_US->Integral();
    double Counts_ME_US_LS_L0_L0bar = h1_L0_L0bar_ME_cos_theta_star_US_LS->Integral();

    h1_L0_L0bar_ME_cos_theta_star_US_US->Scale(Counts_SE_US_US_L0_L0bar/Counts_ME_US_US_L0_L0bar);
    h1_L0_L0bar_ME_cos_theta_star_US_LS->Scale(Counts_SE_US_LS_L0_L0bar/Counts_ME_US_LS_L0_L0bar);

    h1_L0_L0bar_ME_cos_theta_star_US_US->SetStats(0);
    h1_L0_L0bar_ME_cos_theta_star_US_US->SetMinimum(0);
    h1_L0_L0bar_ME_cos_theta_star_US_US->SetMarkerStyle(26);
    h1_L0_L0bar_ME_cos_theta_star_US_US->SetMarkerColor(kBlue);
    h1_L0_L0bar_ME_cos_theta_star_US_US->SetTitle("ME L0-L0bar Pairs inside #DeltaR; cos(#theta*); dN/dCos(#theta*)"); 
    h1_L0_L0bar_ME_cos_theta_star_US_US->GetXaxis()->CenterTitle();
    h1_L0_L0bar_ME_cos_theta_star_US_US->GetYaxis()->CenterTitle();

    h1_L0_L0bar_ME_cos_theta_star_US_LS->SetStats(0);
    h1_L0_L0bar_ME_cos_theta_star_US_LS->SetMinimum(0);
    h1_L0_L0bar_ME_cos_theta_star_US_LS->SetMarkerStyle(26);
    h1_L0_L0bar_ME_cos_theta_star_US_LS->SetMarkerColor(kRed);
    h1_L0_L0bar_ME_cos_theta_star_US_LS->SetLineColor(kRed);

    h_ME_cos_theta_star3->SetStats(0);
    h_ME_cos_theta_star3->SetMinimum(0);
    h_ME_cos_theta_star3->SetMarkerStyle(22);
    h_ME_cos_theta_star3->SetMarkerColor(kBlue);

    h_ME_cos_theta_star4->SetStats(0);
    h_ME_cos_theta_star4->SetMinimum(0);
    h_ME_cos_theta_star4->SetMarkerStyle(22);
    h_ME_cos_theta_star4->SetMarkerColor(kRed);
    h_ME_cos_theta_star4->SetLineColor(kRed);

    h1_L0_L0bar_ME_cos_theta_star_US_US->Draw("PE"); 
    h1_L0_L0bar_ME_cos_theta_star_US_LS->Draw("PE same");
    h_ME_cos_theta_star3->Draw("PE same");
    h_ME_cos_theta_star4->Draw("PE same");

    c4->cd(2);
    TH1D *h1_L0_L0_ME_cos_theta_star_US_US = (TH1D*)projX_ME_LL_1->Clone("h1_L0_L0_ME_cos_theta_star_US_US");
    TH1D *h1_L0_L0_ME_cos_theta_star_US_LS = (TH1D*)projX_ME_LL_2->Clone("h1_L0_L0_ME_cos_theta_star_US_LS");  

    h1_L0_L0_ME_cos_theta_star_US_US->Scale(1.0/h1_L0_L0_ME_cos_theta_star_US_US->GetXaxis()->GetBinWidth(1));
    h1_L0_L0_ME_cos_theta_star_US_LS->Scale(1.0/h1_L0_L0_ME_cos_theta_star_US_LS->GetXaxis()->GetBinWidth(1));

    h1_L0_L0_ME_cos_theta_star_US_US->Scale(1.0/1000);
    h1_L0_L0_ME_cos_theta_star_US_LS->Scale(1.0/1000);

    double Counts_ME_US_US_L0_L0 = h1_L0_L0_ME_cos_theta_star_US_US->Integral();
    double Counts_ME_US_LS_L0_L0 = h1_L0_L0_ME_cos_theta_star_US_LS->Integral();

    h1_L0_L0_ME_cos_theta_star_US_US->Scale(Counts_SE_US_US_L0_L0/Counts_ME_US_US_L0_L0);
    h1_L0_L0_ME_cos_theta_star_US_LS->Scale(Counts_SE_US_LS_L0_L0/Counts_ME_US_LS_L0_L0);

    h1_L0_L0_ME_cos_theta_star_US_US->SetStats(0);
    h1_L0_L0_ME_cos_theta_star_US_US->SetMinimum(0);
    h1_L0_L0_ME_cos_theta_star_US_US->SetMarkerStyle(26);
    h1_L0_L0_ME_cos_theta_star_US_US->SetMarkerColor(kBlue);
    h1_L0_L0_ME_cos_theta_star_US_US->SetTitle("ME L0-L0 Pairs inside #DeltaR; cos(#theta*); dN/dCos(#theta*)"); 
    h1_L0_L0_ME_cos_theta_star_US_US->GetXaxis()->CenterTitle();
    h1_L0_L0_ME_cos_theta_star_US_US->GetYaxis()->CenterTitle();

    h1_L0_L0_ME_cos_theta_star_US_LS->SetStats(0);
    h1_L0_L0_ME_cos_theta_star_US_LS->SetMinimum(0);
    h1_L0_L0_ME_cos_theta_star_US_LS->SetMarkerStyle(26);
    h1_L0_L0_ME_cos_theta_star_US_LS->SetMarkerColor(kRed);
    h1_L0_L0_ME_cos_theta_star_US_LS->SetLineColor(kRed);

    h_ME_cos_theta_star->SetStats(0);
    h_ME_cos_theta_star->SetMinimum(0);
    h_ME_cos_theta_star->SetMarkerStyle(22);
    h_ME_cos_theta_star->SetMarkerColor(kBlue);

    h_ME_cos_theta_star2->SetStats(0);
    h_ME_cos_theta_star2->SetMinimum(0);
    h_ME_cos_theta_star2->SetMarkerStyle(22);
    h_ME_cos_theta_star2->SetMarkerColor(kRed);
    h_ME_cos_theta_star2->SetLineColor(kRed);

    h1_L0_L0_ME_cos_theta_star_US_US->Draw("PE"); 
    h1_L0_L0_ME_cos_theta_star_US_LS->Draw("PE same");
    h_ME_cos_theta_star->Draw("PE same");
    h_ME_cos_theta_star2->Draw("PE same");

    c4->cd(3);
    TH1D *h1_L0bar_L0bar_ME_cos_theta_star_US_US = (TH1D*)projX_ME_LbarLbar_1->Clone("h1_L0bar_L0bar_ME_cos_theta_star_US_US");
    TH1D *h1_L0bar_L0bar_ME_cos_theta_star_US_LS = (TH1D*)projX_ME_LbarLbar_2->Clone("h1_L0bar_L0bar_ME_cos_theta_star_US_LS");  

    h1_L0bar_L0bar_ME_cos_theta_star_US_US->Scale(1.0/h1_L0bar_L0bar_ME_cos_theta_star_US_US->GetXaxis()->GetBinWidth(1));
    h1_L0bar_L0bar_ME_cos_theta_star_US_LS->Scale(1.0/h1_L0bar_L0bar_ME_cos_theta_star_US_LS->GetXaxis()->GetBinWidth(1));

    h1_L0bar_L0bar_ME_cos_theta_star_US_US->Scale(1.0/1000);
    h1_L0bar_L0bar_ME_cos_theta_star_US_LS->Scale(1.0/1000);

    double Counts_ME_US_US_L0bar_L0bar = h1_L0bar_L0bar_ME_cos_theta_star_US_US->Integral();
    double Counts_ME_US_LS_L0bar_L0bar = h1_L0bar_L0bar_ME_cos_theta_star_US_LS->Integral();

    h1_L0bar_L0bar_ME_cos_theta_star_US_US->Scale(Counts_SE_US_US_L0bar_L0bar/Counts_ME_US_US_L0bar_L0bar);
    h1_L0bar_L0bar_ME_cos_theta_star_US_LS->Scale(Counts_SE_US_LS_L0bar_L0bar/Counts_ME_US_LS_L0bar_L0bar);

    h1_L0bar_L0bar_ME_cos_theta_star_US_US->SetStats(0);
    h1_L0bar_L0bar_ME_cos_theta_star_US_US->SetMinimum(0);
    h1_L0bar_L0bar_ME_cos_theta_star_US_US->SetMarkerStyle(26);
    h1_L0bar_L0bar_ME_cos_theta_star_US_US->SetMarkerColor(kBlue);
    h1_L0bar_L0bar_ME_cos_theta_star_US_US->SetTitle("ME L0bar- L0bar Pairs inside #DeltaR; cos(#theta*); dN/dCos(#theta*)"); 
    h1_L0bar_L0bar_ME_cos_theta_star_US_US->GetXaxis()->CenterTitle();
    h1_L0bar_L0bar_ME_cos_theta_star_US_US->GetYaxis()->CenterTitle();

    h1_L0bar_L0bar_ME_cos_theta_star_US_LS->SetStats(0);
    h1_L0bar_L0bar_ME_cos_theta_star_US_LS->SetMinimum(0);
    h1_L0bar_L0bar_ME_cos_theta_star_US_LS->SetMarkerStyle(26);
    h1_L0bar_L0bar_ME_cos_theta_star_US_LS->SetMarkerColor(kRed);
    h1_L0bar_L0bar_ME_cos_theta_star_US_LS->SetLineColor(kRed);

    h_ME_cos_theta_star5->SetStats(0);
    h_ME_cos_theta_star5->SetMinimum(0);
    h_ME_cos_theta_star5->SetMarkerStyle(22);
    h_ME_cos_theta_star5->SetMarkerColor(kBlue);

    h_ME_cos_theta_star6->SetStats(0);
    h_ME_cos_theta_star6->SetMinimum(0);
    h_ME_cos_theta_star6->SetMarkerStyle(22);
    h_ME_cos_theta_star6->SetMarkerColor(kRed);
    h_ME_cos_theta_star6->SetLineColor(kRed);

    h1_L0bar_L0bar_ME_cos_theta_star_US_US->Draw("PE"); 
    h1_L0bar_L0bar_ME_cos_theta_star_US_LS->Draw("PE same");
    h_ME_cos_theta_star5->Draw("PE same");
    h_ME_cos_theta_star6->Draw("PE same");

    c4->cd(4);
    TH1D *h1_L0_L0bar_outside_ME_cos_theta_star_US_US = (TH1D*)projX_ME_LLbar_3->Clone("h1_L0_L0bar_outside_ME_cos_theta_star_US_US");
    TH1D *h1_L0_L0bar_outside_ME_cos_theta_star_US_LS = (TH1D*)projX_ME_LLbar_4->Clone("h1_L0_L0bar_outside_ME_cos_theta_star_US_LS");  

    h1_L0_L0bar_outside_ME_cos_theta_star_US_US->Scale(1.0/h1_L0_L0bar_outside_ME_cos_theta_star_US_US->GetXaxis()->GetBinWidth(1));
    h1_L0_L0bar_outside_ME_cos_theta_star_US_LS->Scale(1.0/h1_L0_L0bar_outside_ME_cos_theta_star_US_LS->GetXaxis()->GetBinWidth(1));

    h1_L0_L0bar_outside_ME_cos_theta_star_US_US->Scale(1.0/1000);
    h1_L0_L0bar_outside_ME_cos_theta_star_US_LS->Scale(1.0/1000);

    double Counts_outside_ME_US_US_L0_L0bar = h1_L0_L0bar_outside_ME_cos_theta_star_US_US->Integral();
    double Counts_outside_ME_US_LS_L0_L0bar = h1_L0_L0bar_outside_ME_cos_theta_star_US_LS->Integral();

    h1_L0_L0bar_outside_ME_cos_theta_star_US_US->Scale(Counts_outside_SE_US_US_L0_L0bar/Counts_outside_ME_US_US_L0_L0bar);
    h1_L0_L0bar_outside_ME_cos_theta_star_US_LS->Scale(Counts_outside_SE_US_LS_L0_L0bar/Counts_outside_ME_US_LS_L0_L0bar);

    h1_L0_L0bar_outside_ME_cos_theta_star_US_US->SetStats(0);
    h1_L0_L0bar_outside_ME_cos_theta_star_US_US->SetMinimum(0);
    h1_L0_L0bar_outside_ME_cos_theta_star_US_US->SetMarkerStyle(26);
    h1_L0_L0bar_outside_ME_cos_theta_star_US_US->SetMarkerColor(kBlue);
    h1_L0_L0bar_outside_ME_cos_theta_star_US_US->SetTitle("ME L0-L0bar Pairs Outside #DeltaR; cos(#theta*); dN/dCos(#theta*)"); 
    h1_L0_L0bar_outside_ME_cos_theta_star_US_US->GetXaxis()->CenterTitle();
    h1_L0_L0bar_outside_ME_cos_theta_star_US_US->GetYaxis()->CenterTitle();

    h1_L0_L0bar_outside_ME_cos_theta_star_US_LS->SetStats(0);
    h1_L0_L0bar_outside_ME_cos_theta_star_US_LS->SetMinimum(0);
    h1_L0_L0bar_outside_ME_cos_theta_star_US_LS->SetMarkerStyle(26);
    h1_L0_L0bar_outside_ME_cos_theta_star_US_LS->SetMarkerColor(kRed);
    h1_L0_L0bar_outside_ME_cos_theta_star_US_LS->SetLineColor(kRed);

    h_outside_ME_cos_theta_star3->SetStats(0);
    h_outside_ME_cos_theta_star3->SetMinimum(0);
    h_outside_ME_cos_theta_star3->SetMarkerStyle(22);
    h_outside_ME_cos_theta_star3->SetMarkerColor(kBlue);

    h_outside_ME_cos_theta_star4->SetStats(0);
    h_outside_ME_cos_theta_star4->SetMinimum(0);
    h_outside_ME_cos_theta_star4->SetMarkerStyle(22);
    h_outside_ME_cos_theta_star4->SetMarkerColor(kRed);
    h_outside_ME_cos_theta_star4->SetLineColor(kRed);

    h1_L0_L0bar_outside_ME_cos_theta_star_US_US->Draw("PE"); 
    h1_L0_L0bar_outside_ME_cos_theta_star_US_LS->Draw("PE same");
    h_outside_ME_cos_theta_star3->Draw("PE same");
    h_outside_ME_cos_theta_star4->Draw("PE same");

    c4->cd(5);
    TH1D *h1_L0_L0_outside_ME_cos_theta_star_US_US = (TH1D*)projX_ME_LL_3->Clone("h1_L0_L0_outside_ME_cos_theta_star_US_US");
    TH1D *h1_L0_L0_outside_ME_cos_theta_star_US_LS = (TH1D*)projX_ME_LL_4->Clone("h1_L0_L0_outside_ME_cos_theta_star_US_LS");  

    h1_L0_L0_outside_ME_cos_theta_star_US_US->Scale(1.0/h1_L0_L0_outside_ME_cos_theta_star_US_US->GetXaxis()->GetBinWidth(1));
    h1_L0_L0_outside_ME_cos_theta_star_US_LS->Scale(1.0/h1_L0_L0_outside_ME_cos_theta_star_US_LS->GetXaxis()->GetBinWidth(1));

    h1_L0_L0_outside_ME_cos_theta_star_US_US->Scale(1.0/1000);
    h1_L0_L0_outside_ME_cos_theta_star_US_LS->Scale(1.0/1000);

    double Counts_outside_ME_US_US_L0_L0 = h1_L0_L0_outside_ME_cos_theta_star_US_US->Integral();
    double Counts_outside_ME_US_LS_L0_L0 = h1_L0_L0_outside_ME_cos_theta_star_US_LS->Integral();

    h1_L0_L0_outside_ME_cos_theta_star_US_US->Scale(Counts_outside_SE_US_US_L0_L0/Counts_outside_ME_US_US_L0_L0);
    h1_L0_L0_outside_ME_cos_theta_star_US_LS->Scale(Counts_outside_SE_US_LS_L0_L0/Counts_outside_ME_US_LS_L0_L0);

    h1_L0_L0_outside_ME_cos_theta_star_US_US->SetStats(0);
    h1_L0_L0_outside_ME_cos_theta_star_US_US->SetMinimum(0);
    h1_L0_L0_outside_ME_cos_theta_star_US_US->SetMarkerStyle(26);
    h1_L0_L0_outside_ME_cos_theta_star_US_US->SetMarkerColor(kBlue);
    h1_L0_L0_outside_ME_cos_theta_star_US_US->SetTitle("ME L0-L0 Pairs Outside #DeltaR; cos(#theta*); dN/dCos(#theta*)"); 
    h1_L0_L0_outside_ME_cos_theta_star_US_US->GetXaxis()->CenterTitle();
    h1_L0_L0_outside_ME_cos_theta_star_US_US->GetYaxis()->CenterTitle();

    h1_L0_L0_outside_ME_cos_theta_star_US_LS->SetStats(0);
    h1_L0_L0_outside_ME_cos_theta_star_US_LS->SetMinimum(0);
    h1_L0_L0_outside_ME_cos_theta_star_US_LS->SetMarkerStyle(26);
    h1_L0_L0_outside_ME_cos_theta_star_US_LS->SetMarkerColor(kRed);
    h1_L0_L0_outside_ME_cos_theta_star_US_LS->SetLineColor(kRed);

    h_outside_ME_cos_theta_star->SetStats(0);
    h_outside_ME_cos_theta_star->SetMinimum(0);
    h_outside_ME_cos_theta_star->SetMarkerStyle(22);
    h_outside_ME_cos_theta_star->SetMarkerColor(kBlue);

    h_outside_ME_cos_theta_star2->SetStats(0);
    h_outside_ME_cos_theta_star2->SetMinimum(0);
    h_outside_ME_cos_theta_star2->SetMarkerStyle(22);
    h_outside_ME_cos_theta_star2->SetMarkerColor(kRed);
    h_outside_ME_cos_theta_star2->SetLineColor(kRed);

    h1_L0_L0_outside_ME_cos_theta_star_US_US->Draw("PE"); 
    h1_L0_L0_outside_ME_cos_theta_star_US_LS->Draw("PE same");
    h_outside_ME_cos_theta_star->Draw("PE same");
    h_outside_ME_cos_theta_star2->Draw("PE same");

    c4->cd(6);
    TH1D *h1_L0bar_L0bar_outside_ME_cos_theta_star_US_US = (TH1D*)projX_ME_LbarLbar_3->Clone("h1_L0bar_L0bar_outside_ME_cos_theta_star_US_US");
    TH1D *h1_L0bar_L0bar_outside_ME_cos_theta_star_US_LS = (TH1D*)projX_ME_LbarLbar_4->Clone("h1_L0bar_L0bar_outside_ME_cos_theta_star_US_LS");  

    h1_L0bar_L0bar_outside_ME_cos_theta_star_US_US->Scale(1.0/h1_L0bar_L0bar_outside_ME_cos_theta_star_US_US->GetXaxis()->GetBinWidth(1));
    h1_L0bar_L0bar_outside_ME_cos_theta_star_US_LS->Scale(1.0/h1_L0bar_L0bar_outside_ME_cos_theta_star_US_LS->GetXaxis()->GetBinWidth(1));

    h1_L0bar_L0bar_outside_ME_cos_theta_star_US_US->Scale(1.0/1000);
    h1_L0bar_L0bar_outside_ME_cos_theta_star_US_LS->Scale(1.0/1000);

    double Counts_outside_ME_US_US_L0bar_L0bar = h1_L0bar_L0bar_outside_ME_cos_theta_star_US_US->Integral();
    double Counts_outside_ME_US_LS_L0bar_L0bar = h1_L0bar_L0bar_outside_ME_cos_theta_star_US_LS->Integral();

    h1_L0bar_L0bar_outside_ME_cos_theta_star_US_US->Scale(Counts_outside_SE_US_US_L0bar_L0bar/Counts_outside_ME_US_US_L0bar_L0bar);
    h1_L0bar_L0bar_outside_ME_cos_theta_star_US_LS->Scale(Counts_outside_SE_US_LS_L0bar_L0bar/Counts_outside_ME_US_LS_L0bar_L0bar);

    h1_L0bar_L0bar_outside_ME_cos_theta_star_US_US->SetStats(0);
    h1_L0bar_L0bar_outside_ME_cos_theta_star_US_US->SetMinimum(0);
    h1_L0bar_L0bar_outside_ME_cos_theta_star_US_US->SetMarkerStyle(26);
    h1_L0bar_L0bar_outside_ME_cos_theta_star_US_US->SetMarkerColor(kBlue);
    h1_L0bar_L0bar_outside_ME_cos_theta_star_US_US->SetTitle("ME L0bar-L0bar Pairs Outside #DeltaR; cos(#theta*); dN/dCos(#theta*)"); 
    h1_L0bar_L0bar_outside_ME_cos_theta_star_US_US->GetXaxis()->CenterTitle();
    h1_L0bar_L0bar_outside_ME_cos_theta_star_US_US->GetYaxis()->CenterTitle();

    h1_L0bar_L0bar_outside_ME_cos_theta_star_US_LS->SetStats(0);
    h1_L0bar_L0bar_outside_ME_cos_theta_star_US_LS->SetMinimum(0);
    h1_L0bar_L0bar_outside_ME_cos_theta_star_US_LS->SetMarkerStyle(26);
    h1_L0bar_L0bar_outside_ME_cos_theta_star_US_LS->SetMarkerColor(kRed);
    h1_L0bar_L0bar_outside_ME_cos_theta_star_US_LS->SetLineColor(kRed);

    h_outside_ME_cos_theta_star5->SetStats(0);
    h_outside_ME_cos_theta_star5->SetMinimum(0);
    h_outside_ME_cos_theta_star5->SetMarkerStyle(22);
    h_outside_ME_cos_theta_star5->SetMarkerColor(kBlue);

    h_outside_ME_cos_theta_star6->SetStats(0);
    h_outside_ME_cos_theta_star6->SetMinimum(0);
    h_outside_ME_cos_theta_star6->SetMarkerStyle(22);
    h_outside_ME_cos_theta_star6->SetMarkerColor(kRed);
    h_outside_ME_cos_theta_star6->SetLineColor(kRed);

    h1_L0bar_L0bar_outside_ME_cos_theta_star_US_US->Draw("PE"); 
    h1_L0bar_L0bar_outside_ME_cos_theta_star_US_LS->Draw("PE same");
    h_outside_ME_cos_theta_star5->Draw("PE same");
    h_outside_ME_cos_theta_star6->Draw("PE same");

    cout << "   " << endl;
    cout << "Canvas 4 Complete" << endl;

    cout << "   " << endl;
    cout << "** Jan's Mixed Event dN/dCos(theta*) distributions with the normalization applied **" << endl;
    cout << "Counts inside the Delta_R Cut" << endl;
    cout << "US-US L0-L0bar: " << Counts_ME_US_US_L0_L0bar << endl;
    cout << "US-LS L0-L0bar: " << Counts_ME_US_LS_L0_L0bar << endl;
    cout << "US-US L0-L0: " << Counts_ME_US_US_L0_L0 << endl;
    cout << "US-LS L0-L0: " << Counts_ME_US_LS_L0_L0 << endl;
    cout << "US-US L0bar-L0bar: " << Counts_ME_US_US_L0bar_L0bar << endl;
    cout << "US-LS L0bar-L0bar: " << Counts_ME_US_LS_L0bar_L0bar << endl;

    cout << "   " << endl;
    cout << "Counts outside the Delta_R Cut" << endl;
    cout << "US-US L0-L0bar: " << Counts_outside_ME_US_US_L0_L0bar << endl;
    cout << "US-LS L0-L0bar: " << Counts_outside_ME_US_LS_L0_L0bar << endl;
    cout << "US-US L0-L0: " << Counts_outside_ME_US_US_L0_L0 << endl;
    cout << "US-LS L0-L0: " << Counts_outside_ME_US_LS_L0_L0 << endl;
    cout << "US-US L0bar-L0bar: " << Counts_outside_ME_US_US_L0bar_L0bar << endl;
    cout << "US-LS L0bar-L0bar: " << Counts_outside_ME_US_LS_L0bar_L0bar << endl;

    cout << "   " << endl;
    cout << "** Kristen's Mixed Event dN/dCos(theta*) distributions with the normalization applied **" << endl;
    cout << "   " << endl;

    double counts_ME_cos_theta_star3 = h_ME_cos_theta_star3->Integral();
    double counts_ME_cos_theta_star4 = h_ME_cos_theta_star4->Integral();
    double counts_ME_cos_theta_star = h_ME_cos_theta_star->Integral();
    double counts_ME_cos_theta_star2 = h_ME_cos_theta_star2->Integral();
    double counts_ME_cos_theta_star5 = h_ME_cos_theta_star5->Integral();
    double counts_ME_cos_theta_star6 = h_ME_cos_theta_star6->Integral();

    cout << "Counts inside the delta_R cut" << endl;
    cout << "US-US L0-L0bar: " << counts_ME_cos_theta_star3 << endl;
    cout << "US-LS L0-L0bar: " << counts_ME_cos_theta_star4 << endl;
    cout << "US-US L0-L0: " << counts_ME_cos_theta_star << endl;
    cout << "US-LS L0-L0: " << counts_ME_cos_theta_star2 << endl;
    cout << "US-US L0bar-L0bar: " << counts_ME_cos_theta_star5 << endl;
    cout << "US-LS L0bar-L0bar: " << counts_ME_cos_theta_star6 << endl;

    double counts_outside_ME_cos_theta_star3 = h_outside_ME_cos_theta_star3->Integral();
    double counts_outside_ME_cos_theta_star4 = h_outside_ME_cos_theta_star4->Integral();
    double counts_outside_ME_cos_theta_star = h_outside_ME_cos_theta_star->Integral();
    double counts_outside_ME_cos_theta_star2 = h_outside_ME_cos_theta_star2->Integral();
    double counts_outside_ME_cos_theta_star5 = h_outside_ME_cos_theta_star5->Integral();
    double counts_outside_ME_cos_theta_star6 = h_outside_ME_cos_theta_star6->Integral();

    cout << "   " << endl;
    cout << "Counts outside the delta_R cut" << endl;
    cout << "US-US L0-L0bar: " << counts_outside_ME_cos_theta_star3 << endl;
    cout << "US-LS L0-L0bar: " << counts_outside_ME_cos_theta_star4 << endl;
    cout << "US-US L0-L0: " << counts_outside_ME_cos_theta_star << endl;
    cout << "US-LS L0-L0: " << counts_outside_ME_cos_theta_star2 << endl;
    cout << "US-US L0bar-L0bar: " << counts_outside_ME_cos_theta_star5 << endl;
    cout << "US-LS L0bar-L0bar: " << counts_outside_ME_cos_theta_star6 << endl;

    TCanvas *c5 = new TCanvas("c5", "Canvas 5", 1800, 900);
    c5->Divide(3,2);

    c5->cd(1);
    TH1D* h_ME_cos_theta_star3_clone = (TH1D*)h_ME_cos_theta_star3->Clone("h_ME_cos_theta_star3_clone");
    TH1D* h_ME_cos_theta_star4_clone = (TH1D*)h_ME_cos_theta_star4->Clone("h_ME_cos_theta_star4_clone");    

    h_cos_theta_star3->SetStats(0);
    h_cos_theta_star3->SetMinimum(0);
    h_cos_theta_star3->SetMarkerStyle(20);
    h_cos_theta_star3->SetMarkerColor(kBlue);
    h_cos_theta_star3->SetTitle("SE and ME #Lambda#bar{#Lambda} Pairs inside #DeltaR; cos(#theta*); dN/dCos(#theta*)"); 
    h_cos_theta_star3->GetXaxis()->CenterTitle();
    h_cos_theta_star3->GetYaxis()->CenterTitle();

    h_cos_theta_star4->SetStats(0);
    h_cos_theta_star4->SetMinimum(0);
    h_cos_theta_star4->SetMarkerStyle(20);
    h_cos_theta_star4->SetMarkerColor(kRed);
    h_cos_theta_star4->SetLineColor(kRed);

    h_ME_cos_theta_star3_clone->SetStats(0);
    h_ME_cos_theta_star3_clone->SetMinimum(0);
    h_ME_cos_theta_star3_clone->SetMarkerStyle(25);
    h_ME_cos_theta_star3_clone->SetMarkerColor(kBlue);

    h_ME_cos_theta_star4_clone->SetStats(0);
    h_ME_cos_theta_star4_clone->SetMinimum(0);
    h_ME_cos_theta_star4_clone->SetMarkerStyle(25);
    h_ME_cos_theta_star4_clone->SetMarkerColor(kRed);
    h_ME_cos_theta_star4_clone->SetLineColor(kRed);

    h_cos_theta_star3->Draw("PE");
    h_cos_theta_star4->Draw("PE same");
    h_ME_cos_theta_star3_clone->Draw("PE same");
    h_ME_cos_theta_star4_clone->Draw("PE same");

    c5->cd(2);
    TH1D* h_ME_cos_theta_star_clone = (TH1D*)h_ME_cos_theta_star->Clone("h_ME_cos_theta_star_clone");
    TH1D* h_ME_cos_theta_star2_clone = (TH1D*)h_ME_cos_theta_star2->Clone("h_ME_cos_theta_star2_clone");    

    h_cos_theta_star->SetStats(0);
    h_cos_theta_star->SetMinimum(0);
    h_cos_theta_star->SetMarkerStyle(20);
    h_cos_theta_star->SetMarkerColor(kBlue);
    h_cos_theta_star->SetTitle("SE and ME #Lambda#Lambda Pairs inside #DeltaR; cos(#theta*); dN/dCos(#theta*)"); 
    h_cos_theta_star->GetXaxis()->CenterTitle();
    h_cos_theta_star->GetYaxis()->CenterTitle();

    h_cos_theta_star2->SetStats(0);
    h_cos_theta_star2->SetMinimum(0);
    h_cos_theta_star2->SetMarkerStyle(20);
    h_cos_theta_star2->SetMarkerColor(kRed);
    h_cos_theta_star2->SetLineColor(kRed);

    h_ME_cos_theta_star_clone->SetStats(0);
    h_ME_cos_theta_star_clone->SetMinimum(0);
    h_ME_cos_theta_star_clone->SetMarkerStyle(25);
    h_ME_cos_theta_star_clone->SetMarkerColor(kBlue);

    h_ME_cos_theta_star2_clone->SetStats(0);
    h_ME_cos_theta_star2_clone->SetMinimum(0);
    h_ME_cos_theta_star2_clone->SetMarkerStyle(25);
    h_ME_cos_theta_star2_clone->SetMarkerColor(kRed);
    h_ME_cos_theta_star2_clone->SetLineColor(kRed);

    h_cos_theta_star->Draw("PE");
    h_cos_theta_star2->Draw("PE same");
    h_ME_cos_theta_star_clone->Draw("PE same");
    h_ME_cos_theta_star2_clone->Draw("PE same");

    c5->cd(3);
    TH1D* h_ME_cos_theta_star5_clone = (TH1D*)h_ME_cos_theta_star5->Clone("h_ME_cos_theta_star5_clone");
    TH1D* h_ME_cos_theta_star6_clone = (TH1D*)h_ME_cos_theta_star6->Clone("h_ME_cos_theta_star6_clone");

    h_cos_theta_star5->SetStats(0);
    h_cos_theta_star5->SetMinimum(0);
    h_cos_theta_star5->SetMarkerStyle(20);
    h_cos_theta_star5->SetMarkerColor(kBlue);
    h_cos_theta_star5->SetTitle("SE and ME #bar{#Lambda}#bar{#Lambda} Pairs inside #DeltaR; cos(#theta*); dN/dCos(#theta*)"); 
    h_cos_theta_star5->GetXaxis()->CenterTitle();
    h_cos_theta_star5->GetYaxis()->CenterTitle();

    h_cos_theta_star6->SetStats(0);
    h_cos_theta_star6->SetMinimum(0);
    h_cos_theta_star6->SetMarkerStyle(20);
    h_cos_theta_star6->SetMarkerColor(kRed);
    h_cos_theta_star6->SetLineColor(kRed);

    h_ME_cos_theta_star5_clone->SetStats(0);
    h_ME_cos_theta_star5_clone->SetMinimum(0);
    h_ME_cos_theta_star5_clone->SetMarkerStyle(25);
    h_ME_cos_theta_star5_clone->SetMarkerColor(kBlue);

    h_ME_cos_theta_star6_clone->SetStats(0);
    h_ME_cos_theta_star6_clone->SetMinimum(0);
    h_ME_cos_theta_star6_clone->SetMarkerStyle(25);
    h_ME_cos_theta_star6_clone->SetMarkerColor(kRed);
    h_ME_cos_theta_star6_clone->SetLineColor(kRed);

    h_cos_theta_star5->Draw("PE"); 
    h_cos_theta_star6->Draw("PE same");
    h_ME_cos_theta_star5_clone->Draw("PE same");
    h_ME_cos_theta_star6_clone->Draw("PE same");

    c5->cd(4);
    TH1D* h_outside_ME_cos_theta_star3_clone = (TH1D*)h_outside_ME_cos_theta_star3->Clone("h_outside_ME_cos_theta_star3_clone");
    TH1D* h_outside_ME_cos_theta_star4_clone = (TH1D*)h_outside_ME_cos_theta_star4->Clone("h_outside_ME_cos_theta_star4_clone");    

    h_outside_cos_theta_star3->SetStats(0);
    h_outside_cos_theta_star3->SetMinimum(0);
    h_outside_cos_theta_star3->SetMarkerStyle(20);
    h_outside_cos_theta_star3->SetMarkerColor(kBlue);
    h_outside_cos_theta_star3->SetTitle("SE and ME #Lambda#bar{#Lambda} Pairs outside #DeltaR; cos(#theta*); dN/dCos(#theta*)"); 
    h_outside_cos_theta_star3->GetXaxis()->CenterTitle();
    h_outside_cos_theta_star3->GetYaxis()->CenterTitle();

    h_outside_cos_theta_star4->SetStats(0);
    h_outside_cos_theta_star4->SetMinimum(0);
    h_outside_cos_theta_star4->SetMarkerStyle(20);
    h_outside_cos_theta_star4->SetMarkerColor(kRed);
    h_outside_cos_theta_star4->SetLineColor(kRed);

    h_outside_ME_cos_theta_star3_clone->SetStats(0);
    h_outside_ME_cos_theta_star3_clone->SetMinimum(0);
    h_outside_ME_cos_theta_star3_clone->SetMarkerStyle(25);
    h_outside_ME_cos_theta_star3_clone->SetMarkerColor(kBlue);

    h_outside_ME_cos_theta_star4->SetStats(0);
    h_outside_ME_cos_theta_star4->SetMinimum(0);
    h_outside_ME_cos_theta_star4->SetMarkerStyle(25);
    h_outside_ME_cos_theta_star4->SetMarkerColor(kRed);
    h_outside_ME_cos_theta_star4->SetLineColor(kRed);

    h_outside_cos_theta_star3->Draw("PE");
    h_outside_cos_theta_star4->Draw("PE same");
    h_outside_ME_cos_theta_star3_clone->Draw("PE same");
    h_outside_ME_cos_theta_star4_clone->Draw("PE same");

    c5->cd(5);
    TH1D* h_outside_ME_cos_theta_star_clone = (TH1D*)h_outside_ME_cos_theta_star->Clone("h_outside_ME_cos_theta_star_clone");
    TH1D* h_outside_ME_cos_theta_star2_clone = (TH1D*)h_outside_ME_cos_theta_star2->Clone("h_outside_ME_cos_theta_star2_clone");

    h_outside_cos_theta_star->SetStats(0);
    h_outside_cos_theta_star->SetMinimum(0);
    h_outside_cos_theta_star->SetMarkerStyle(20);
    h_outside_cos_theta_star->SetMarkerColor(kBlue);
    h_outside_cos_theta_star->SetTitle("SE and ME #Lambda#Lambda Pairs outside #DeltaR; cos(#theta*); dN/dCos(#theta*)"); 
    h_outside_cos_theta_star->GetXaxis()->CenterTitle();
    h_outside_cos_theta_star->GetYaxis()->CenterTitle();

    h_outside_cos_theta_star2->SetStats(0);
    h_outside_cos_theta_star2->SetMinimum(0);
    h_outside_cos_theta_star2->SetMarkerStyle(20);
    h_outside_cos_theta_star2->SetMarkerColor(kRed);
    h_outside_cos_theta_star2->SetLineColor(kRed);

    h_outside_ME_cos_theta_star_clone->SetStats(0);
    h_outside_ME_cos_theta_star_clone->SetMinimum(0);
    h_outside_ME_cos_theta_star_clone->SetMarkerStyle(25);
    h_outside_ME_cos_theta_star_clone->SetMarkerColor(kBlue);

    h_outside_ME_cos_theta_star2_clone->SetStats(0);
    h_outside_ME_cos_theta_star2_clone->SetMinimum(0);
    h_outside_ME_cos_theta_star2_clone->SetMarkerStyle(25);
    h_outside_ME_cos_theta_star2_clone->SetMarkerColor(kRed);
    h_outside_ME_cos_theta_star2_clone->SetLineColor(kRed);

    h_outside_cos_theta_star->Draw("PE");
    h_outside_cos_theta_star2->Draw("PE same");
    h_outside_ME_cos_theta_star_clone->Draw("PE same");
    h_outside_ME_cos_theta_star2_clone->Draw("PE same");

    c5->cd(6);
    TH1D* h_outside_ME_cos_theta_star5_clone = (TH1D*)h_outside_ME_cos_theta_star5->Clone("h_outside_ME_cos_theta_star5_clone");
    TH1D* h_outside_ME_cos_theta_star6_clone = (TH1D*)h_outside_ME_cos_theta_star6->Clone("h_outside_ME_cos_theta_star6_clone");

    h_outside_cos_theta_star5->SetStats(0);
    h_outside_cos_theta_star5->SetMinimum(0);
    h_outside_cos_theta_star5->SetMarkerStyle(20);
    h_outside_cos_theta_star5->SetMarkerColor(kBlue);
    h_outside_cos_theta_star5->SetTitle("SE and ME #bar{#Lambda}#bar{#Lambda} Pairs outside #DeltaR; cos(#theta*); dN/dCos(#theta*)"); 
    h_outside_cos_theta_star5->GetXaxis()->CenterTitle();
    h_outside_cos_theta_star5->GetYaxis()->CenterTitle();

    h_outside_cos_theta_star6->SetStats(0);
    h_outside_cos_theta_star6->SetMinimum(0);
    h_outside_cos_theta_star6->SetMarkerStyle(20);
    h_outside_cos_theta_star6->SetMarkerColor(kRed);
    h_outside_cos_theta_star6->SetLineColor(kRed);

    h_outside_ME_cos_theta_star5_clone->SetStats(0);
    h_outside_ME_cos_theta_star5_clone->SetMinimum(0);
    h_outside_ME_cos_theta_star5_clone->SetMarkerStyle(25);
    h_outside_ME_cos_theta_star5_clone->SetMarkerColor(kBlue);

    h_outside_ME_cos_theta_star6_clone->SetStats(0);
    h_outside_ME_cos_theta_star6_clone->SetMinimum(0);
    h_outside_ME_cos_theta_star6_clone->SetMarkerStyle(25);
    h_outside_ME_cos_theta_star6_clone->SetMarkerColor(kRed);
    h_outside_ME_cos_theta_star6_clone->SetLineColor(kRed);

    h_outside_cos_theta_star5->Draw("PE");
    h_outside_cos_theta_star6->Draw("PE same");
    h_outside_ME_cos_theta_star5_clone->Draw("PE same");
    h_outside_ME_cos_theta_star6_clone->Draw("PE same");

    cout << "Canvas 5 Complete" << endl;

    TCanvas *c6 = new TCanvas("c6", "Canvas 6", 1800, 900);
    c6->Divide(3,2);

    double counts_cos_jan = h1_L0_L0_cos_theta_star_US_US->Integral();
    double counts_cos2_jan = h1_L0_L0_cos_theta_star_US_LS->Integral();
    double counts_cos3_jan = h1_L0_L0bar_cos_theta_star_US_US->Integral();
    double counts_cos4_jan = h1_L0_L0bar_cos_theta_star_US_LS->Integral();
    double counts_cos5_jan = h1_L0bar_L0bar_cos_theta_star_US_US->Integral();
    double counts_cos6_jan = h1_L0bar_L0bar_cos_theta_star_US_LS->Integral();

    cout << "   " << endl;
    cout << "Check on Jan's Data: Counts after the normalization is applied" << endl;
    cout << "US_US L0-L0bar Pairs: " << counts_cos3_jan << endl;
    cout << "US_LS L0-L0bar Pairs: " << counts_cos4_jan << endl;
    cout << "US_US L0-L0 Pairs: " << counts_cos_jan << endl;
    cout << "US_LS L0-L0 Pairs: " << counts_cos2_jan << endl;
    cout << "US_US L0bar-L0bar Pairs: " << counts_cos5_jan << endl;
    cout << "US_LS L0bar-L0bar Pairs: " << counts_cos6_jan << endl;

    double counts_out_cos_jan = h1_L0_L0_outside_cos_theta_star_US_US->Integral();
    double counts_out_cos2_jan = h1_L0_L0_outside_cos_theta_star_US_LS->Integral();
    double counts_out_cos3_jan = h1_L0_L0bar_outside_cos_theta_star_US_US->Integral();
    double counts_out_cos4_jan = h1_L0_L0bar_outside_cos_theta_star_US_LS->Integral();
    double counts_out_cos5_jan = h1_L0bar_L0bar_outside_cos_theta_star_US_US->Integral();
    double counts_out_cos6_jan = h1_L0bar_L0bar_outside_cos_theta_star_US_LS->Integral();

    double counts_cos = h_cos_theta_star->Integral();
    double counts_cos2 = h_cos_theta_star2->Integral();
    double counts_cos3 = h_cos_theta_star3->Integral();
    double counts_cos4 = h_cos_theta_star4->Integral();
    double counts_cos5 = h_cos_theta_star5->Integral();
    double counts_cos6 = h_cos_theta_star6->Integral();

    cout << "   " << endl;
    cout << "Check on Kristen's Data: Counts after the normalization is applied" << endl;
    cout << "US_US L0-L0bar Pairs: " << counts_cos3 << endl;
    cout << "US_LS L0-L0bar Pairs: " << counts_cos4 << endl;
    cout << "US_US L0-L0 Pairs: " << counts_cos << endl;
    cout << "US_LS L0-L0 Pairs: " << counts_cos2 << endl;
    cout << "US_US L0bar-L0bar Pairs: " << counts_cos5 << endl;
    cout << "US_LS L0bar-L0bar Pairs: " << counts_cos6 << endl;

    double counts_out_cos = h_outside_cos_theta_star->Integral();
    double counts_out_cos2 = h_outside_cos_theta_star2->Integral();
    double counts_out_cos3 = h_outside_cos_theta_star3->Integral();
    double counts_out_cos4 = h_outside_cos_theta_star4->Integral();
    double counts_out_cos5 = h_outside_cos_theta_star5->Integral();
    double counts_out_cos6 = h_outside_cos_theta_star6->Integral();

    // double counts_ME_cos_jan = h1_L0_L0_ME_cos_theta_star_US_US->Integral();
    // double counts_ME_cos2_jan = h1_L0_L0_ME_cos_theta_star_US_LS->Integral();
    // double counts_ME_cos3_jan = h1_L0_L0bar_ME_cos_theta_star_US_US->Integral();
    // double counts_ME_cos4_jan = h1_L0_L0bar_ME_cos_theta_star_US_LS->Integral();
    // double counts_ME_cos5_jan = h1_L0bar_L0bar_ME_cos_theta_star_US_US->Integral();
    // double counts_ME_cos6_jan = h1_L0bar_L0bar_ME_cos_theta_star_US_LS->Integral();

    double constant_value = 0.747 * (-0.757); 
    double constant_value_3 = 0.747 * (0.747);
    double constant_value_2 = (-0.757) * (-0.757);

    double const_val_errors = (0.009) * (0.004);
    double const_val_errors_3 = (0.009) * (0.009);
    double const_val_errors_2 = (0.004) * (0.004);

    cout << "   " << endl;
    cout << "Canvas 6 Polarization Calculations" << endl;

    c6->cd(1);
    cout << "   " << endl;
    cout << "Pad 1: L0-L0bar Pairs" << endl;

    TH1D *h_correct_L0_L0bar = (TH1D*)h1_L0_L0bar_cos_theta_star_US_US->Clone("h_correct_L0_L0bar");  
    h_correct_L0_L0bar->Divide(h1_L0_L0bar_ME_cos_theta_star_US_US);  

    TH1D *h_correct_L0_L0bar_2 = (TH1D*)h1_L0_L0bar_cos_theta_star_US_LS->Clone("h_correct_L0_L0bar_2");  
    h_correct_L0_L0bar_2->Divide(h1_L0_L0bar_ME_cos_theta_star_US_LS); 

    double counts_correct_cos_3_jan = h_correct_L0_L0bar->Integral();
    double counts_correct_cos_4_jan = h_correct_L0_L0bar->Integral();

    h_correct_L0_L0bar->Scale(1.0 / counts_correct_cos_3_jan);
    h_correct_L0_L0bar->Scale(counts_cos3_jan);

    h_correct_L0_L0bar_2->Scale(1.0 / counts_correct_cos_4_jan);
    h_correct_L0_L0bar_2->Scale(counts_cos4_jan);

    TF1 *fit_correct_L0_L0bar = new TF1("fit_correct_L0_L0bar", "[0] * (1 + [1] * x)", -1, 1);
    fit_correct_L0_L0bar->SetParameters(1, 1);
    h_correct_L0_L0bar->Fit(fit_correct_L0_L0bar, "RQN");

    double A2_divided_jan = fit_correct_L0_L0bar->GetParameter(0);
    double B2_divided_jan = fit_correct_L0_L0bar->GetParameter(1);
    double B2_error_jan = fit_correct_L0_L0bar->GetParError(1);
    cout << "   " << endl;
    cout << "Fit Parameters: Jan's corrected L0-L0bar Pairs (us-us):" << endl;
    cout << "A: " << A2_divided_jan << endl;
    cout << "B: " << B2_divided_jan << endl;

    double P_llbar_jan = B2_divided_jan / constant_value;
    double P_llbar_error_jan = B2_error_jan / constant_value;
    std::cout << "Polarization (L0-L0Bar): " << P_llbar_jan << " ± " << P_llbar_error_jan << std::endl; 

    TH1D *h_correct_cos_theta_star_L0_L0bar = (TH1D*)h_cos_theta_star3->Clone("h_correct_cos_theta_star_L0_L0bar");
    h_correct_cos_theta_star_L0_L0bar->Divide(h_ME_cos_theta_star3);

    TH1D *h_correct_cos_theta_star_L0_L0bar_2 = (TH1D*)h_cos_theta_star4->Clone("h_correct_cos_theta_star_L0_L0bar_2");
    h_correct_cos_theta_star_L0_L0bar_2->Divide(h_ME_cos_theta_star4);

    double counts_correct_cos_3 = h_correct_cos_theta_star_L0_L0bar->Integral();
    double counts_correct_cos_4 = h_correct_cos_theta_star_L0_L0bar_2->Integral();

    h_correct_cos_theta_star_L0_L0bar->Scale(1.0 / counts_correct_cos_3);
    h_correct_cos_theta_star_L0_L0bar->Scale(counts_cos3);

    h_correct_cos_theta_star_L0_L0bar_2->Scale(1.0 / counts_correct_cos_4);
    h_correct_cos_theta_star_L0_L0bar_2->Scale(counts_cos4);

    TF1 *fit_correct_cos_theta_star_L0_L0bar = new TF1("fit_correct_cos_theta_star_L0_L0bar", "[0] * (1 + [1] * x)", -1, 1);
    fit_correct_cos_theta_star_L0_L0bar->SetParameters(1, 1);
    h_correct_cos_theta_star_L0_L0bar->Fit(fit_correct_cos_theta_star_L0_L0bar, "RQN");

    double A2_divided = fit_correct_cos_theta_star_L0_L0bar->GetParameter(0);
    double B2_divided = fit_correct_cos_theta_star_L0_L0bar->GetParameter(1);
    double B2_error = fit_correct_cos_theta_star_L0_L0bar->GetParError(1);
    cout << "   " << endl;
    cout << "Fit Parameters: Kristen's corrected L0-L0bar Pairs (us-us):" << endl;
    cout << "A: " << A2_divided << endl;
    cout << "B: " << B2_divided << endl;

    double P_llbar = B2_divided / constant_value;
    double P_llbar_error = B2_error / constant_value;
    std::cout << "Polarization (L0-L0Bar): " << P_llbar << " ± " << P_llbar_error << std::endl; 

    h_correct_L0_L0bar->SetStats(0);
    h_correct_L0_L0bar->SetMinimum(0);
    h_correct_L0_L0bar->SetMarkerStyle(25);
    h_correct_L0_L0bar->SetMarkerColor(kBlue);
    h_correct_L0_L0bar->SetTitle("L0-L0bar Pairs Inside #DeltaR; cos(#theta*); dN/dCos(#theta*)"); 
    h_correct_L0_L0bar->GetXaxis()->CenterTitle();
    h_correct_L0_L0bar->GetYaxis()->CenterTitle();

    h_correct_L0_L0bar_2->SetStats(0);
    h_correct_L0_L0bar_2->SetMinimum(0);
    h_correct_L0_L0bar_2->SetMarkerStyle(25);
    h_correct_L0_L0bar_2->SetMarkerColor(kRed);
    h_correct_L0_L0bar_2->SetLineColor(kRed);

    h_correct_cos_theta_star_L0_L0bar->SetStats(0);
    h_correct_cos_theta_star_L0_L0bar->SetMinimum(0);
    h_correct_cos_theta_star_L0_L0bar->SetMarkerStyle(20);
    h_correct_cos_theta_star_L0_L0bar->SetMarkerColor(kBlue);

    h_correct_cos_theta_star_L0_L0bar_2->SetStats(0);
    h_correct_cos_theta_star_L0_L0bar_2->SetMinimum(0);
    h_correct_cos_theta_star_L0_L0bar_2->SetMarkerStyle(20);
    h_correct_cos_theta_star_L0_L0bar_2->SetMarkerColor(kRed);
    h_correct_cos_theta_star_L0_L0bar_2->SetLineColor(kRed);

    h_correct_L0_L0bar->Draw("PE");
    h_correct_L0_L0bar_2->Draw("PE same");
    h_correct_cos_theta_star_L0_L0bar->Draw("PE same");
    h_correct_cos_theta_star_L0_L0bar_2->Draw("PE same");

    c6->cd(2);
    cout << "   " << endl;
    cout << "Pad 2: L0-L0 Pairs" << endl;
    
    TH1D *h_correct_L0_L0 = (TH1D*)h1_L0_L0_cos_theta_star_US_US->Clone("h_correct_L0_L0");
    h_correct_L0_L0->Divide(h1_L0_L0_ME_cos_theta_star_US_US);

    TH1D *h_correct_L0_L0_2 = (TH1D*)h1_L0_L0_cos_theta_star_US_LS->Clone("h_correct_L0_L0_2");
    h_correct_L0_L0_2->Divide(h1_L0_L0_ME_cos_theta_star_US_LS);

    double counts_correct_cos_jan = h_correct_L0_L0->Integral();
    double counts_correct_cos_2_jan = h_correct_L0_L0_2->Integral();

    h_correct_L0_L0->Scale(1.0 / counts_correct_cos_jan);
    h_correct_L0_L0->Scale(counts_cos_jan);

    h_correct_L0_L0_2->Scale(1.0 / counts_correct_cos_2_jan);
    h_correct_L0_L0_2->Scale(counts_cos2_jan);

    TF1 *fit_correct_L0_L0 = new TF1("fit_correct_L0_L0", "[0] * (1 + [1] * x)", -1, 1);
    fit_correct_L0_L0->SetParameters(1, 1);
    h_correct_L0_L0->Fit(fit_correct_L0_L0, "RQN");

    double A_divided_jan = fit_correct_L0_L0->GetParameter(0);
    double B_divided_jan = fit_correct_L0_L0->GetParameter(1);
    double B_error_jan = fit_correct_L0_L0->GetParError(1);
    cout << "   " << endl;
    cout << "Fit Parameters: Jan's corrected L0-L0 Pairs (us-us):" << endl;
    cout << "A: " << A_divided_jan << endl;
    cout << "B: " << B_divided_jan << endl;

    double P_ll_jan = B_divided_jan / constant_value_2;
    double P_ll_error_jan = B_error_jan / constant_value_2;
    std::cout << "Polarization (LL): " << P_ll_jan << " ± " << P_ll_error_jan << std::endl;

    TH1D *h_correct_cos_theta_star_L0_L0 = (TH1D*)h_cos_theta_star->Clone("h_correct_cos_theta_star_L0_L0");
    h_correct_cos_theta_star_L0_L0->Divide(h_ME_cos_theta_star);

    TH1D *h_correct_cos_theta_star_L0_L0_2 = (TH1D*)h_cos_theta_star2->Clone("h_correct_cos_theta_star_L0_L0_2");
    h_correct_cos_theta_star_L0_L0_2->Divide(h_ME_cos_theta_star2);

    double counts_correct_cos = h_correct_cos_theta_star_L0_L0->Integral();
    double counts_correct_cos_2 = h_correct_cos_theta_star_L0_L0_2->Integral();

    h_correct_cos_theta_star_L0_L0->Scale(1.0 / counts_correct_cos);
    h_correct_cos_theta_star_L0_L0->Scale(counts_cos);

    h_correct_cos_theta_star_L0_L0_2->Scale(1.0 / counts_correct_cos_2);
    h_correct_cos_theta_star_L0_L0_2->Scale(counts_cos2);

    TF1 *fit_correct_cos_theta_star_L0_L0 = new TF1("fit_correct_cos_theta_star_L0_L0", "[0] * (1 + [1] * x)", -1, 1);
    fit_correct_cos_theta_star_L0_L0->SetParameters(1, 1);
    h_correct_cos_theta_star_L0_L0->Fit(fit_correct_cos_theta_star_L0_L0, "RQN");

    double A_divided = fit_correct_cos_theta_star_L0_L0->GetParameter(0);
    double B_divided = fit_correct_cos_theta_star_L0_L0->GetParameter(1);
    double B_error = fit_correct_cos_theta_star_L0_L0->GetParameter(1);
    cout << "   " << endl;
    cout << "Fit Parameters: Kristen's corrected L0-L0 Pairs (us-us):" << endl;
    cout << "A: " << A_divided << endl;
    cout << "B: " << B_divided << endl;

    double P_ll = B_divided / constant_value_2;
    double P_ll_error = B_error / constant_value_2;
    cout << "Polarization (LL): " << P_ll << " ± " << P_ll_error << endl;

    h_correct_L0_L0->SetStats(0);
    h_correct_L0_L0->SetMinimum(0);
    h_correct_L0_L0->SetMarkerStyle(25);
    h_correct_L0_L0->SetMarkerColor(kBlue);
    h_correct_L0_L0->SetTitle("L0-L0 Pairs Inside #DeltaR; cos(#theta*); dN/dCos(#theta*)"); 
    h_correct_L0_L0->GetXaxis()->CenterTitle();
    h_correct_L0_L0->GetYaxis()->CenterTitle();

    h_correct_L0_L0_2->SetStats(0);
    h_correct_L0_L0_2->SetMinimum(0);
    h_correct_L0_L0_2->SetMarkerStyle(25);
    h_correct_L0_L0_2->SetMarkerColor(kRed);
    h_correct_L0_L0_2->SetLineColor(kRed);

    h_correct_cos_theta_star_L0_L0->SetStats(0);
    h_correct_cos_theta_star_L0_L0->SetMinimum(0);
    h_correct_cos_theta_star_L0_L0->SetMarkerStyle(20);
    h_correct_cos_theta_star_L0_L0->SetMarkerColor(kBlue);

    h_correct_cos_theta_star_L0_L0_2->SetStats(0);
    h_correct_cos_theta_star_L0_L0_2->SetMinimum(0);
    h_correct_cos_theta_star_L0_L0_2->SetMarkerStyle(20);
    h_correct_cos_theta_star_L0_L0_2->SetMarkerColor(kRed);
    h_correct_cos_theta_star_L0_L0_2->SetLineColor(kRed);

    h_correct_L0_L0->Draw("PE");
    h_correct_L0_L0_2->Draw("PE same");
    h_correct_cos_theta_star_L0_L0->Draw("PE same");
    h_correct_cos_theta_star_L0_L0_2->Draw("PE same");

    c6->cd(3);
    cout << "   " << endl;
    cout << "Pad 3: L0bar-L0bar Pairs" << endl;

    TH1D *h_correct_L0bar_L0bar = (TH1D*)h1_L0bar_L0bar_cos_theta_star_US_US->Clone("h_correct_L0bar_L0bar");  
    h_correct_L0bar_L0bar->Divide(h1_L0bar_L0bar_ME_cos_theta_star_US_US);  

    TH1D *h_correct_L0bar_L0bar_2 = (TH1D*)h1_L0bar_L0bar_cos_theta_star_US_LS->Clone("h_correct_L0bar_L0bar_2");  
    h_correct_L0bar_L0bar_2->Divide(h1_L0bar_L0bar_ME_cos_theta_star_US_LS);

    double counts_correct_cos_5_jan = h_correct_L0bar_L0bar->Integral();
    double counts_correct_cos_6_jan = h_correct_L0bar_L0bar_2->Integral();

    h_correct_L0bar_L0bar->Scale(1.0 / counts_correct_cos_5_jan);
    h_correct_L0bar_L0bar->Scale(counts_cos5_jan);

    h_correct_L0bar_L0bar_2->Scale(1.0 / counts_correct_cos_6_jan);
    h_correct_L0bar_L0bar_2->Scale(counts_cos6_jan);

    TF1 *fit_correct_L0bar_L0bar = new TF1("fit_correct_L0bar_L0bar", "[0] * (1 + [1] * x)", -1, 1);
    fit_correct_L0bar_L0bar->SetParameters(1, 1);
    h_correct_L0bar_L0bar->Fit(fit_correct_L0bar_L0bar, "RQN");

    double A3_divided_jan = fit_correct_L0bar_L0bar->GetParameter(0);
    double B3_divided_jan = fit_correct_L0bar_L0bar->GetParameter(1);
    double B3_error_jan = fit_correct_L0bar_L0bar->GetParError(1);
    cout << "   " << endl;
    cout << "Fit Parameters: Jan's corrected L0bar-L0bar Pairs (us-us):" << endl;
    cout << "A: " << A3_divided_jan << endl;
    cout << "B: " << B3_divided_jan << endl; 

    double P_lbarlbar_jan = B3_divided_jan / constant_value_3;
    double P_lbarlbar_error_jan = B3_error_jan / constant_value_3;
    std::cout << "Polarization (LBarLBar): " << P_lbarlbar_jan << " ± " << P_lbarlbar_error_jan << std::endl;

    TH1D *h_correct_cos_theta_star_L0bar_L0bar = (TH1D*)h_cos_theta_star5->Clone("h_correct_cos_theta_star_L0bar_L0bar");
    h_correct_cos_theta_star_L0bar_L0bar->Divide(h_ME_cos_theta_star5);

    TH1D *h_correct_cos_theta_star_L0bar_L0bar_2 = (TH1D*)h_cos_theta_star6->Clone("h_correct_cos_theta_star_L0bar_L0bar_2");
    h_correct_cos_theta_star_L0bar_L0bar_2->Divide(h_ME_cos_theta_star6);

    double counts_correct_cos_5 = h_correct_cos_theta_star_L0bar_L0bar->Integral();
    double counts_correct_cos_6 = h_correct_cos_theta_star_L0bar_L0bar_2->Integral();

    h_correct_cos_theta_star_L0bar_L0bar->Scale(1.0 / counts_correct_cos_5);
    h_correct_cos_theta_star_L0bar_L0bar->Scale(counts_cos5);

    h_correct_cos_theta_star_L0bar_L0bar_2->Scale(1.0 / counts_correct_cos_6);
    h_correct_cos_theta_star_L0bar_L0bar_2->Scale(counts_cos6);    

    TF1 *fit_correct_cos_theta_star_L0bar_L0bar = new TF1("fit_correct_cos_theta_star_L0bar_L0bar", "[0] * (1 + [1] * x)", -1, 1);
    fit_correct_cos_theta_star_L0bar_L0bar->SetParameters(1, 1);
    h_correct_cos_theta_star_L0_L0bar->Fit(fit_correct_cos_theta_star_L0bar_L0bar, "RQN");

    double A3_divided = fit_correct_cos_theta_star_L0bar_L0bar->GetParameter(0);
    double B3_divided = fit_correct_cos_theta_star_L0bar_L0bar->GetParameter(1);
    double B3_error = fit_correct_cos_theta_star_L0bar_L0bar->GetParError(1);
    cout << "   " << endl;
    cout << "Fit Parameters: Kristen's corrected L0bar-L0bar Pairs (us-us):" << endl;
    cout << "A: " << A3_divided << endl;
    cout << "B: " << B3_divided << endl; 

    double P_lbarlbar = B3_divided / constant_value_3;
    double P_lbarlbar_error = B3_error / constant_value_3;
    std::cout << "Polarization (LBarLBar): " << P_lbarlbar << " ± " << P_lbarlbar_error << std::endl;    

    h_correct_L0bar_L0bar->SetStats(0);
    h_correct_L0bar_L0bar->SetMinimum(0);
    h_correct_L0bar_L0bar->SetMarkerStyle(25);
    h_correct_L0bar_L0bar->SetMarkerColor(kBlue);
    h_correct_L0bar_L0bar->SetTitle("L0bar-L0bar Pairs Inside #DeltaR; cos(#theta*); dN/dCos(#theta*)"); 
    h_correct_L0bar_L0bar->GetXaxis()->CenterTitle();
    h_correct_L0bar_L0bar->GetYaxis()->CenterTitle();

    h_correct_L0bar_L0bar_2->SetStats(0);
    h_correct_L0bar_L0bar_2->SetMinimum(0);
    h_correct_L0bar_L0bar_2->SetMarkerStyle(25);
    h_correct_L0bar_L0bar_2->SetMarkerColor(kRed);
    h_correct_L0bar_L0bar_2->SetLineColor(kRed);

    h_correct_cos_theta_star_L0bar_L0bar->SetStats(0);
    h_correct_cos_theta_star_L0bar_L0bar->SetMinimum(0);
    h_correct_cos_theta_star_L0bar_L0bar->SetMarkerStyle(20);
    h_correct_cos_theta_star_L0bar_L0bar->SetMarkerColor(kBlue);

    h_correct_cos_theta_star_L0bar_L0bar_2->SetStats(0);
    h_correct_cos_theta_star_L0bar_L0bar_2->SetMinimum(0);
    h_correct_cos_theta_star_L0bar_L0bar_2->SetMarkerStyle(20);
    h_correct_cos_theta_star_L0bar_L0bar_2->SetMarkerColor(kRed);
    h_correct_cos_theta_star_L0bar_L0bar_2->SetLineColor(kRed);

    h_correct_L0bar_L0bar->Draw("PE");
    h_correct_L0bar_L0bar_2->Draw("PE same");
    h_correct_cos_theta_star_L0bar_L0bar->Draw("PE same");
    h_correct_cos_theta_star_L0bar_L0bar_2->Draw("PE same");

    c6->cd(4);
    cout << "   " << endl;
    cout << "Pad 4: L0-L0bar Pairs" << endl;

    TH1D *h_correct_outside_L0_L0bar = (TH1D*)h1_L0_L0bar_outside_cos_theta_star_US_US->Clone("h_correct_outside_L0_L0bar");  
    h_correct_outside_L0_L0bar->Divide(h1_L0_L0bar_outside_ME_cos_theta_star_US_US);  

    TH1D *h_correct_outside_L0_L0bar_2 = (TH1D*)h1_L0_L0bar_outside_cos_theta_star_US_LS->Clone("h_correct_outside_L0_L0bar_2");  
    h_correct_outside_L0_L0bar_2->Divide(h1_L0_L0bar_outside_ME_cos_theta_star_US_LS); 

    double counts_correct_out_cos_3_jan = h_correct_outside_L0_L0bar->Integral();
    double counts_correct_out_cos_4_jan = h_correct_outside_L0_L0bar_2->Integral();

    h_correct_outside_L0_L0bar->Scale(1.0 / counts_correct_out_cos_3_jan);
    h_correct_outside_L0_L0bar->Scale(counts_out_cos3_jan);

    h_correct_outside_L0_L0bar_2->Scale(1.0 / counts_correct_out_cos_4_jan);
    h_correct_outside_L0_L0bar_2->Scale(counts_out_cos4_jan); 

    TF1 *fit_correct_outside_L0_L0bar = new TF1("fit_correct_outside_L0_L0bar", "[0] * (1 + [1] * x)", -1, 1);
    fit_correct_outside_L0_L0bar->SetParameters(1, 1);
    h_correct_outside_L0_L0bar->Fit(fit_correct_outside_L0_L0bar, "RQN");

    double A12_divided_jan = fit_correct_outside_L0_L0bar->GetParameter(0);
    double B12_divided_jan = fit_correct_outside_L0_L0bar->GetParameter(1);
    double B12_error_jan = fit_correct_outside_L0_L0bar->GetParError(1);
    cout << "   " << endl;
    cout << "Fit Parameters: Jan's corrected L0-L0bar Pairs outside #DeltaR (us-us):" << endl;
    cout << "A: " << A12_divided_jan << endl;
    cout << "B: " << B12_divided_jan << endl;

    double P_llbar_outside_jan = B12_divided_jan /= constant_value;
    double P_llbar_outside_error_jan = B12_error_jan /= constant_value;
    std::cout << "Polarization (LLBar): " << P_llbar_outside_jan << " ± " << P_llbar_outside_error_jan << std::endl;

    TH1D *h_correct_outside_cos_theta_star_L0_L0bar =(TH1D*)h_outside_cos_theta_star3->Clone("h_correct_outside_cos_theta_star_L0_L0bar");
    h_correct_outside_cos_theta_star_L0_L0bar->Divide(h_outside_ME_cos_theta_star3);

    TH1D *h_correct_outside_cos_theta_star_L0_L0bar_2 =(TH1D*)h_outside_cos_theta_star4->Clone("h_correct_outside_cos_theta_star_L0_L0bar_2");
    h_correct_outside_cos_theta_star_L0_L0bar_2->Divide(h_outside_ME_cos_theta_star4);

    double counts_correct_out_cos_3 = h_correct_outside_cos_theta_star_L0_L0bar->Integral();
    double counts_correct_out_cos_4 = h_correct_outside_cos_theta_star_L0_L0bar_2->Integral();

    h_correct_outside_cos_theta_star_L0_L0bar->Scale(1.0 / counts_correct_out_cos_3);
    h_correct_outside_cos_theta_star_L0_L0bar->Scale(counts_out_cos3);

    h_correct_outside_cos_theta_star_L0_L0bar_2->Scale(1.0 / counts_correct_out_cos_4);
    h_correct_outside_cos_theta_star_L0_L0bar_2->Scale(counts_out_cos4); 

    TF1 *fit_correct_outside_cos_theta_star_L0_L0bar = new TF1("fit_correct_outside_cos_theta_star_L0_L0bar", "[0] * (1 + [1] * x)", -1, 1);
    fit_correct_outside_cos_theta_star_L0_L0bar->SetParameters(1, 1);
    h_correct_outside_cos_theta_star_L0_L0bar->Fit(fit_correct_outside_cos_theta_star_L0_L0bar, "RQN");

    double A12_divided = fit_correct_outside_cos_theta_star_L0_L0bar->GetParameter(0);
    double B12_divided = fit_correct_outside_cos_theta_star_L0_L0bar->GetParameter(1);
    double B12_error = fit_correct_outside_cos_theta_star_L0_L0bar->GetParError(1);
    cout << "   " << endl;
    cout << "Fit Parameters: Kristen's corrected L0-L0bar Pairs outside #DeltaR (us-us):" << endl;
    cout << "A: " << A12_divided << endl;
    cout << "B: " << B12_divided << endl;

    double P_llbar_outside = B12_divided /= constant_value;
    double P_llbar_outside_error = B12_error /= constant_value;
    std::cout << "Polarization (LLBar): " << P_llbar_outside << " ± " << P_llbar_outside_error << std::endl;

    h_correct_outside_L0_L0bar->SetStats(0);
    h_correct_outside_L0_L0bar->SetMinimum(0);
    h_correct_outside_L0_L0bar->SetMarkerStyle(25);
    h_correct_outside_L0_L0bar->SetMarkerColor(kBlue);
    h_correct_outside_L0_L0bar->SetTitle("L0-L0bar Pairs Outside #DeltaR; cos(#theta*); dN/dCos(#theta*)"); 
    h_correct_outside_L0_L0bar->GetXaxis()->CenterTitle();
    h_correct_outside_L0_L0bar->GetYaxis()->CenterTitle();

    h_correct_outside_L0_L0bar_2->SetStats(0);
    h_correct_outside_L0_L0bar_2->SetMinimum(0);
    h_correct_outside_L0_L0bar_2->SetMarkerStyle(25);
    h_correct_outside_L0_L0bar_2->SetMarkerColor(kRed);
    h_correct_outside_L0_L0bar_2->SetLineColor(kRed);

    h_correct_outside_cos_theta_star_L0_L0bar->SetStats(0);
    h_correct_outside_cos_theta_star_L0_L0bar->SetMinimum(0);
    h_correct_outside_cos_theta_star_L0_L0bar->SetMarkerStyle(20);
    h_correct_outside_cos_theta_star_L0_L0bar->SetMarkerColor(kBlue);

    h_correct_outside_cos_theta_star_L0_L0bar_2->SetStats(0);
    h_correct_outside_cos_theta_star_L0_L0bar_2->SetMinimum(0);
    h_correct_outside_cos_theta_star_L0_L0bar_2->SetMarkerStyle(20);
    h_correct_outside_cos_theta_star_L0_L0bar_2->SetMarkerColor(kRed);
    h_correct_outside_cos_theta_star_L0_L0bar_2->SetLineColor(kRed);

    h_correct_outside_L0_L0bar->Draw("PE");
    h_correct_outside_L0_L0bar_2->Draw("PE same");
    h_correct_outside_cos_theta_star_L0_L0bar->Draw("PE same");
    h_correct_outside_cos_theta_star_L0_L0bar_2->Draw("PE same");

    c6->cd(5);
    cout << "   " << endl;
    cout << "Pad 5: L0-L0 Pairs" << endl;

    TH1D *h_correct_outside_L0_L0 = (TH1D*)h1_L0_L0_outside_cos_theta_star_US_US->Clone("h_correct_outside_L0_L0");  
    h_correct_outside_L0_L0->Divide(h1_L0_L0_outside_ME_cos_theta_star_US_US);  

    TH1D *h_correct_outside_L0_L0_2 = (TH1D*)h1_L0_L0_outside_cos_theta_star_US_LS->Clone("h_correct_outside_L0_L0_2");  
    h_correct_outside_L0_L0_2->Divide(h1_L0_L0_outside_ME_cos_theta_star_US_LS); 

    double counts_correct_out_cos_jan = h_correct_outside_L0_L0->Integral();
    double counts_correct_out_cos_2_jan = h_correct_outside_L0_L0_2->Integral();

    h_correct_outside_L0_L0->Scale(1.0 / counts_correct_out_cos_jan);
    h_correct_outside_L0_L0->Scale(counts_out_cos);

    h_correct_outside_L0_L0_2->Scale(1.0 / counts_correct_out_cos_2_jan);
    h_correct_outside_L0_L0_2->Scale(counts_out_cos2);

    TF1 *fit_correct_outside_L0_L0 = new TF1("fit_correct_outside_L0_L0", "[0] * (1 + [1] * x)", -1, 1);
    fit_correct_outside_L0_L0->SetParameters(1, 1);
    h_correct_outside_L0_L0->Fit(fit_correct_outside_L0_L0, "RQN");

    double A11_divided_jan = fit_correct_outside_L0_L0->GetParameter(0);
    double B11_divided_jan = fit_correct_outside_L0_L0->GetParameter(1);
    double B11_error_jan = fit_correct_outside_L0_L0->GetParError(1);
    cout << "   " << endl;
    cout << "Fit Parameters: Jan's corrected L0-L0 Pairs outside #DeltaR (us-us):" << endl;
    cout << "A: " << A11_divided_jan << endl;
    cout << "B: " << B11_divided_jan << endl; 

    double P_ll_outside_jan = B11_divided_jan /= constant_value_2;
    double P_ll_outside_error_jan = B11_error_jan /= constant_value_2;
    std::cout << "Polarization (LL): " << P_ll_outside_jan << " ± " << P_ll_outside_error_jan << std::endl;

    TH1D *h_correct_outside_cos_theta_star_L0_L0 = (TH1D*)h_outside_cos_theta_star->Clone("h_correct_outside_cos_theta_star_L0_L0");
    h_correct_outside_cos_theta_star_L0_L0->Divide(h_outside_ME_cos_theta_star);

    TH1D *h_correct_outside_cos_theta_star_L0_L0_2 = (TH1D*)h_outside_cos_theta_star2->Clone("h_correct_outside_cos_theta_star_L0_L0_2");
    h_correct_outside_cos_theta_star_L0_L0_2->Divide(h_outside_ME_cos_theta_star2);

    double counts_correct_out_cos = h_correct_outside_cos_theta_star_L0_L0->Integral();
    double counts_correct_out_cos_2 = h_correct_outside_cos_theta_star_L0_L0_2->Integral();

    h_correct_outside_cos_theta_star_L0_L0->Scale(1.0 / counts_correct_out_cos);
    h_correct_outside_cos_theta_star_L0_L0->Scale(counts_out_cos);

    h_correct_outside_cos_theta_star_L0_L0_2->Scale(1.0 / counts_correct_out_cos_2);
    h_correct_outside_cos_theta_star_L0_L0_2->Scale(counts_out_cos2);

    TF1 *fit_correct_outside_cos_theta_star_L0_L0 = new TF1("fit_correct_outside_cos_theta_star_L0_L0", "[0] * (1 + [1] * x)", -1, 1);
    fit_correct_outside_cos_theta_star_L0_L0->SetParameters(1, 1);
    h_correct_outside_cos_theta_star_L0_L0->Fit(fit_correct_outside_cos_theta_star_L0_L0, "RQN");

    double A11_divided = fit_correct_outside_cos_theta_star_L0_L0->GetParameter(0);
    double B11_divided = fit_correct_outside_cos_theta_star_L0_L0->GetParameter(1);
    double B11_error = fit_correct_outside_cos_theta_star_L0_L0->GetParError(1);
    cout << "   " << endl;
    cout << "Fit Parameters: Kristen's corrected L0-L0 Pairs outside #DeltaR (us-us):" << endl;
    cout << "A: " << A11_divided << endl;
    cout << "B: " << B11_divided << endl; 

    double P_ll_outside = B11_divided /= constant_value_2;
    double P_ll_outside_error = B11_error /= constant_value_2;
    std::cout << "Polarization (LL): " << P_ll_outside << " ± " << P_ll_outside_error << std::endl;

    h_correct_outside_L0_L0->SetStats(0);
    h_correct_outside_L0_L0->SetMinimum(0);
    h_correct_outside_L0_L0->SetMarkerStyle(25);
    h_correct_outside_L0_L0->SetMarkerColor(kBlue);
    h_correct_outside_L0_L0->SetTitle("L0-L0 Pairs Outside #DeltaR; cos(#theta*); dN/dCos(#theta*)"); 
    h_correct_outside_L0_L0->GetXaxis()->CenterTitle();
    h_correct_outside_L0_L0->GetYaxis()->CenterTitle();

    h_correct_outside_L0_L0_2->SetStats(0);
    h_correct_outside_L0_L0_2->SetMinimum(0);
    h_correct_outside_L0_L0_2->SetMarkerStyle(25);
    h_correct_outside_L0_L0_2->SetMarkerColor(kRed);
    h_correct_outside_L0_L0_2->SetLineColor(kRed);

    h_correct_outside_cos_theta_star_L0_L0->SetStats(0);
    h_correct_outside_cos_theta_star_L0_L0->SetMinimum(0);
    h_correct_outside_cos_theta_star_L0_L0->SetMarkerStyle(20);
    h_correct_outside_cos_theta_star_L0_L0->SetMarkerColor(kBlue);

    h_correct_outside_cos_theta_star_L0_L0_2->SetStats(0);
    h_correct_outside_cos_theta_star_L0_L0_2->SetMinimum(0);
    h_correct_outside_cos_theta_star_L0_L0_2->SetMarkerStyle(20);
    h_correct_outside_cos_theta_star_L0_L0_2->SetMarkerColor(kRed);
    h_correct_outside_cos_theta_star_L0_L0_2->SetLineColor(kRed);

    h_correct_outside_L0_L0->Draw("PE");
    h_correct_outside_L0_L0_2->Draw("PE same");
    h_correct_outside_cos_theta_star_L0_L0->Draw("PE same");
    h_correct_outside_cos_theta_star_L0_L0_2->Draw("PE same");

    c6->cd(6);
    cout << "   " << endl;
    cout << "Pad 6: L0bar-L0bar Pairs" << endl;

    TH1D *h_correct_outside_L0bar_L0bar = (TH1D*)h1_L0bar_L0bar_outside_cos_theta_star_US_US->Clone("h_correct_outside_L0bar_L0bar");  
    h_correct_outside_L0bar_L0bar->Divide(h1_L0bar_L0bar_outside_ME_cos_theta_star_US_US);  

    TH1D *h_correct_outside_L0bar_L0bar_2 = (TH1D*)h1_L0bar_L0bar_outside_cos_theta_star_US_LS->Clone("h_correct_outside_L0bar_L0bar_2");  
    h_correct_outside_L0bar_L0bar_2->Divide(h1_L0bar_L0bar_outside_ME_cos_theta_star_US_LS); 

    double counts_correct_out_cos_5_jan = h_correct_outside_L0bar_L0bar->Integral();
    double counts_correct_out_cos_6_jan = h_correct_outside_L0bar_L0bar_2->Integral();

    h_correct_outside_L0bar_L0bar->Scale(1.0 / counts_correct_out_cos_5_jan);
    h_correct_outside_L0bar_L0bar->Scale(counts_out_cos5_jan);

    h_correct_outside_L0bar_L0bar_2->Scale(1.0 / counts_correct_out_cos_6_jan);
    h_correct_outside_L0bar_L0bar_2->Scale(counts_out_cos6_jan);

    TF1 *fit_correct_outside_L0bar_L0bar = new TF1("fit_correct_outside_L0bar_L0bar", "[0] * (1 + [1] * x)", -1, 1);
    fit_correct_outside_L0bar_L0bar->SetParameters(1, 1);
    h_correct_outside_L0bar_L0bar->Fit(fit_correct_outside_L0bar_L0bar, "RQN");

    double A13_divided_jan = fit_correct_outside_L0bar_L0bar->GetParameter(0);
    double B13_divided_jan = fit_correct_outside_L0bar_L0bar->GetParameter(1);
    double B13_error_jan = fit_correct_outside_L0bar_L0bar->GetParError(1);
    cout << "   " << endl;
    cout << "Fit Parameters: Jan's corrected L0bar-L0bar Pairs outside #DeltaR (us-us):" << endl;
    cout << "A: " << A13_divided_jan << endl;
    cout << "B: " << B13_divided_jan << endl; 

    double P_lbarlbar_outside_jan = B13_divided_jan /= constant_value_3;
    double P_lbarlbar_outside_error_jan = B13_error_jan /= constant_value_3;
    std::cout << "Polarization (LBarLBar): " << P_lbarlbar_outside_jan << " ± " << P_lbarlbar_outside_error_jan << std::endl;

    TH1D *h_correct_outside_cos_theta_star_L0bar_L0bar =(TH1D*)h_outside_cos_theta_star5->Clone("h_correct_outside_cos_theta_star_L0bar_L0bar");
    h_correct_outside_cos_theta_star_L0bar_L0bar->Divide(h_outside_ME_cos_theta_star5);

    TH1D *h_correct_outside_cos_theta_star_L0bar_L0bar_2 =(TH1D*)h_outside_cos_theta_star6->Clone("h_correct_outside_cos_theta_star_L0bar_L0bar_2");
    h_correct_outside_cos_theta_star_L0bar_L0bar_2->Divide(h_outside_ME_cos_theta_star6);

    double counts_correct_out_cos_5 = h_correct_outside_cos_theta_star_L0bar_L0bar->Integral();
    double counts_correct_out_cos_6 = h_correct_outside_cos_theta_star_L0bar_L0bar_2->Integral();

    h_correct_outside_cos_theta_star_L0bar_L0bar->Scale(1.0 / counts_correct_out_cos_5);
    h_correct_outside_cos_theta_star_L0bar_L0bar->Scale(counts_out_cos5);

    h_correct_outside_cos_theta_star_L0bar_L0bar_2->Scale(1.0 / counts_correct_out_cos_6);
    h_correct_outside_cos_theta_star_L0bar_L0bar_2->Scale(counts_out_cos6);

    TF1 *fit_correct_outside_cos_theta_star_L0bar_L0bar = new TF1("fit_correct_outside_cos_theta_star_L0bar_L0bar", "[0] * (1 + [1] * x)", -1, 1);
    fit_correct_outside_cos_theta_star_L0bar_L0bar->SetParameters(1, 1);
    h_correct_outside_cos_theta_star_L0bar_L0bar->Fit(fit_correct_outside_cos_theta_star_L0bar_L0bar, "RQN"); 

    double A13_divided = fit_correct_outside_cos_theta_star_L0bar_L0bar->GetParameter(0);
    double B13_divided = fit_correct_outside_cos_theta_star_L0bar_L0bar->GetParameter(1);
    double B13_error = fit_correct_outside_cos_theta_star_L0bar_L0bar->GetParError(1);
    cout << "   " << endl;
    cout << "Fit Parameters: Kristen's corrected L0bar-L0bar Pairs outside #DeltaR (us-us):" << endl;
    cout << "A: " << A13_divided << endl;
    cout << "B: " << B13_divided << endl;

    double P_lbarlbar_outside = B13_divided /= constant_value_3;
    double P_lbarlbar_outside_error = B13_error /= constant_value_3;
    std::cout << "Polarization (LLBar): " << P_lbarlbar_outside << " ± " << P_lbarlbar_outside_error << std::endl;

    h_correct_outside_L0bar_L0bar->SetStats(0);
    h_correct_outside_L0bar_L0bar->SetMinimum(0);
    h_correct_outside_L0bar_L0bar->SetMarkerStyle(25);
    h_correct_outside_L0bar_L0bar->SetMarkerColor(kBlue);
    h_correct_outside_L0bar_L0bar->SetTitle("L0bar-L0bar Pairs Outside #DeltaR; cos(#theta*); dN/dCos(#theta*)"); 
    h_correct_outside_L0bar_L0bar->GetXaxis()->CenterTitle();
    h_correct_outside_L0bar_L0bar->GetYaxis()->CenterTitle();

    h_correct_outside_L0bar_L0bar_2->SetStats(0);
    h_correct_outside_L0bar_L0bar_2->SetMinimum(0);
    h_correct_outside_L0bar_L0bar_2->SetMarkerStyle(25);
    h_correct_outside_L0bar_L0bar_2->SetMarkerColor(kRed);
    h_correct_outside_L0bar_L0bar_2->SetLineColor(kRed);

    h_correct_outside_cos_theta_star_L0bar_L0bar->SetStats(0);
    h_correct_outside_cos_theta_star_L0bar_L0bar->SetMinimum(0);
    h_correct_outside_cos_theta_star_L0bar_L0bar->SetMarkerStyle(20);
    h_correct_outside_cos_theta_star_L0bar_L0bar->SetMarkerColor(kBlue);

    h_correct_outside_cos_theta_star_L0bar_L0bar_2->SetStats(0);
    h_correct_outside_cos_theta_star_L0bar_L0bar_2->SetMinimum(0);
    h_correct_outside_cos_theta_star_L0bar_L0bar_2->SetMarkerStyle(20);
    h_correct_outside_cos_theta_star_L0bar_L0bar_2->SetMarkerColor(kRed);
    h_correct_outside_cos_theta_star_L0bar_L0bar_2->SetLineColor(kRed);

    h_correct_outside_L0bar_L0bar->Draw("PE");
    h_correct_outside_L0bar_L0bar_2->Draw("PE same");
    h_correct_outside_cos_theta_star_L0bar_L0bar->Draw("PE same");
    h_correct_outside_cos_theta_star_L0bar_L0bar_2->Draw("PE same");

    double counts_correct_L0_L0 = h_correct_L0_L0->Integral();
    double counts_correct_L0_L0_2 = h_correct_L0_L0_2->Integral();
    double counts_correct_L0_L0bar = h_correct_L0_L0bar->Integral();
    double counts_correct_L0_L0bar_2 = h_correct_L0_L0bar_2->Integral();
    double counts_correct_L0bar_L0bar = h_correct_L0bar_L0bar->Integral();
    double counts_correct_L0bar_L0bar_2 = h_correct_L0bar_L0bar_2->Integral();

    double counts_correct_outside_L0_L0 = h_correct_outside_L0_L0->Integral();
    double counts_correct_outside_L0_L0_2 = h_correct_outside_L0_L0_2->Integral();
    double counts_correct_outside_L0_L0bar = h_correct_outside_L0_L0bar->Integral();
    double counts_correct_outside_L0_L0bar_2 = h_correct_outside_L0_L0bar_2->Integral();
    double counts_correct_outside_L0bar_L0bar = h_correct_outside_L0bar_L0bar->Integral();
    double counts_correct_outside_L0bar_L0bar_2 = h_correct_outside_L0bar_L0bar_2->Integral();

    cout << "   " << endl;
    cout << "Jan's Data after the ME Correction is Applied" << endl;
    cout << "inside #DeltaR = 0.93 cut" << endl;
    cout << "US-US L0-L0bar Pairs: " << counts_correct_L0_L0bar << endl;
    cout << "US-LS L0-L0bar Pairs: " << counts_correct_L0_L0bar_2 << endl;
    cout << "US-US L0-L0 Pairs: " << counts_correct_L0_L0 << endl;
    cout << "US-LS L0-L0 Pairs: " << counts_correct_L0_L0_2 << endl;
    cout << "US-US L0bar-L0bar Pairs: " << counts_correct_L0bar_L0bar << endl;
    cout << "US-LS L0bar-L0bar Pairs: " << counts_correct_L0bar_L0bar_2 << endl;
    cout << "   " << endl;
    cout << "outside #DeltaR = 0.93 cut" << endl;
    cout << "US-US L0-L0bar Pairs: " << counts_correct_outside_L0_L0bar << endl;
    cout << "US-LS L0-L0bar Pairs: " << counts_correct_outside_L0_L0bar_2 << endl;
    cout << "US-US L0-L0 Pairs: " << counts_correct_outside_L0_L0 << endl;
    cout << "US-LS L0-L0 Pairs: " << counts_correct_outside_L0_L0_2 << endl;
    cout << "US-US L0bar-L0bar Pairs: " << counts_correct_outside_L0bar_L0bar << endl;
    cout << "US-LS L0bar-L0bar Pairs: " << counts_correct_outside_L0bar_L0bar_2 << endl;

    double counts_correct_cos_theta_star_L0_L0bar = h_correct_cos_theta_star_L0_L0bar->Integral();
    double counts_correct_cos_theta_star_L0_L0bar_2 = h_correct_cos_theta_star_L0_L0bar_2->Integral();
    double counts_correct_cos_theta_star_L0_L0 = h_correct_cos_theta_star_L0_L0->Integral();
    double counts_correct_cos_theta_star_L0_L0_2 = h_correct_cos_theta_star_L0_L0_2->Integral();
    double counts_correct_cos_theta_star_L0bar_L0bar = h_correct_cos_theta_star_L0bar_L0bar->Integral();
    double counts_correct_cos_theta_star_L0bar_L0bar_2 = h_correct_cos_theta_star_L0bar_L0bar_2->Integral();

    double counts_correct_outside_cos_theta_star_L0_L0bar = h_correct_outside_cos_theta_star_L0_L0bar->Integral();
    double counts_correct_outside_cos_theta_star_L0_L0bar_2 = h_correct_outside_cos_theta_star_L0_L0bar_2->Integral();
    double counts_correct_outside_cos_theta_star_L0_L0 = h_correct_outside_cos_theta_star_L0_L0->Integral();
    double counts_correct_outside_cos_theta_star_L0_L0_2 = h_correct_outside_cos_theta_star_L0_L0_2->Integral();
    double counts_correct_outside_cos_theta_star_L0bar_L0bar = h_correct_outside_cos_theta_star_L0bar_L0bar->Integral();
    double counts_correct_outside_cos_theta_star_L0bar_L0bar_2 = h_correct_outside_cos_theta_star_L0bar_L0bar_2->Integral();

    cout << "   " << endl;
    cout << "Kristen's Data after the ME Correction is Applied" << endl;
    cout << "inside #DeltaR = 0.93 cut" << endl;
    cout << "US-US L0-L0bar Pairs: " << counts_correct_cos_theta_star_L0_L0bar << endl;
    cout << "US-LS L0-L0bar Pairs: " << counts_correct_cos_theta_star_L0_L0bar_2 << endl;
    cout << "US-US L0-L0 Pairs: " << counts_correct_cos_theta_star_L0_L0 << endl;
    cout << "US-LS L0-L0 Pairs: " << counts_correct_cos_theta_star_L0_L0_2 << endl;
    cout << "US-US L0bar-L0bar Pairs: " << counts_correct_cos_theta_star_L0bar_L0bar << endl;
    cout << "US-LS L0bar-L0bar Pairs: " << counts_correct_cos_theta_star_L0bar_L0bar_2 << endl;
    cout << "   " << endl;
    cout << "outside #DeltaR = 0.93 cut" << endl;
    cout << "US-US L0-L0bar Pairs: " << counts_correct_outside_cos_theta_star_L0_L0bar << endl;
    cout << "US-LS L0-L0bar Pairs: " << counts_correct_outside_cos_theta_star_L0_L0bar_2 << endl;
    cout << "US-US L0-L0 Pairs: " << counts_correct_outside_cos_theta_star_L0_L0 << endl;
    cout << "US-LS L0-L0 Pairs: " << counts_correct_outside_cos_theta_star_L0_L0_2 << endl;
    cout << "US-US L0bar-L0bar Pairs: " << counts_correct_outside_cos_theta_star_L0bar_L0bar << endl;
    cout << "US-LS L0bar-L0bar Pairs: " << counts_correct_outside_cos_theta_star_L0bar_L0bar_2 << endl;

    TCanvas *c7 = new TCanvas("c7", "Canvas 7", 1800, 900);
    c7->Divide(3, 2);

    c7->cd(1);
    cout << "   " << endl;
    cout << "Canvas 7, Pad 1" << endl;

    TH1D *h_corrected_L0_L0bar = new TH1D(*h_correct_L0_L0bar);
    h_corrected_L0_L0bar->Add(h_correct_L0_L0bar_2, -1.0);

    cout << "   " << endl;
    cout << "Fit Parameters: Jan's Data after ME correction and background subtraction" << endl;
    TF1 *fit_corrected_L0_L0bar = new TF1("fit_corrected_L0_L0bar", "[0] * (1 + [1] * x)", -1, 1);
    fit_corrected_L0_L0bar->SetParameters(1, 1);
    h_corrected_L0_L0bar->Fit(fit_corrected_L0_L0bar, "R");

    double A22_divided_jan = fit_corrected_L0_L0bar->GetParameter(0);
    double B22_divided_jan = fit_corrected_L0_L0bar->GetParameter(1);
    double B22_error_jan = fit_corrected_L0_L0bar->GetParError(1);
    cout << "Fit Parameters: Jan's corrected L0-L0bar Pairs inside #DeltaR (After Background Subtraction):" << endl;
    cout << "A: " << A22_divided_jan << endl;
    cout << "B: " << B22_divided_jan << endl;

    double P_corrected_llbar_jan = B22_divided_jan / constant_value;
    double P_corrected_llbar_error_jan = B22_error_jan / constant_value;
    std::cout << "Polarization (L0-L0Bar): " << P_corrected_llbar_jan << " ± " << P_corrected_llbar_error_jan << std::endl;

    TH1D *h_corrected_cos_theta_star_L0_L0bar = new TH1D(*h_correct_cos_theta_star_L0_L0bar);
    h_corrected_cos_theta_star_L0_L0bar->Add(h_correct_cos_theta_star_L0_L0bar_2, -1.0);

    cout << "   " << endl;
    cout << "Fit Parameters: Kristen's Data after ME correction and background subtraction" << endl;
    TF1 *fit_corrected_cos_theta_star_L0_L0bar = new TF1("fit_corrected_cos_theta_star_L0_L0bar", "[0] * (1 + [1] * x)", -1, 1);
    fit_corrected_cos_theta_star_L0_L0bar->SetParameters(1, 1);
    fit_corrected_cos_theta_star_L0_L0bar->SetLineColor(kBlue);
    h_corrected_cos_theta_star_L0_L0bar->Fit(fit_corrected_cos_theta_star_L0_L0bar, "R");

    double A22_divided = fit_corrected_cos_theta_star_L0_L0bar->GetParameter(0);
    double B22_divided = fit_corrected_cos_theta_star_L0_L0bar->GetParameter(1);
    double B22_error = fit_corrected_cos_theta_star_L0_L0bar->GetParError(1);
    cout << "Fit Parameters: Kristen's corrected L0-L0bar Pairs inside #DeltaR (After Background Subtraction):" << endl;
    cout << "A: " << A22_divided << endl;
    cout << "B: " << B22_divided << endl;

    double P_corrected_llbar = B22_divided / constant_value;
    double P_corrected_llbar_error = B22_error / constant_value;
    std::cout << "Polarization (L0-L0Bar): " << P_corrected_llbar << " ± " << P_corrected_llbar_error << std::endl;

    h_corrected_L0_L0bar->SetStats(0);
    h_corrected_L0_L0bar->SetMinimum(0);
    h_corrected_L0_L0bar->SetMarkerStyle(22);
    h_corrected_L0_L0bar->SetMarkerColor(kRed);
    h_corrected_L0_L0bar->SetLineColor(kRed);
    h_corrected_L0_L0bar->SetTitle("Corrected #Lambda#bar{#Lambda} Pairs Inside #DeltaR; cos(#theta*); dN/dCos(#theta*)"); 
    h_corrected_L0_L0bar->GetXaxis()->CenterTitle();
    h_corrected_L0_L0bar->GetYaxis()->CenterTitle();
    // h_corrected_L0_L0bar->Draw("PE");

    h_corrected_cos_theta_star_L0_L0bar->SetStats(0);
    h_corrected_cos_theta_star_L0_L0bar->SetMinimum(0);
    h_corrected_cos_theta_star_L0_L0bar->SetMarkerStyle(20);
    h_corrected_cos_theta_star_L0_L0bar->SetMarkerColor(kBlue);
    fit_corrected_cos_theta_star_L0_L0bar->SetLineColor(kBlue);
    h_corrected_cos_theta_star_L0_L0bar->Draw("same");

    TLegend *legend_correct_1 = new TLegend(0.15, 0.15, 0.4, 0.3);
    legend_correct_1->SetBorderSize(1);    
    legend_correct_1->SetTextSize(0.03);   
    legend_correct_1->SetBorderSize(0);
    legend_correct_1->SetFillStyle(0); 
    // legend_correct_1->AddEntry(h_corrected_L0_L0bar, "Jan's dN/dCos(theta*): After Background Subtraction", "p");
    // legend_correct_1->AddEntry(fit_corrected_L0_L0bar, "Jan's dN/dCos(theta*): Fit");
    legend_correct_1->AddEntry(h_corrected_cos_theta_star_L0_L0bar, "#Lambda#bar{#Lambda}", "p");
    legend_correct_1->AddEntry(fit_corrected_cos_theta_star_L0_L0bar, "Fit");
    legend_correct_1->Draw();

    c7->cd(2);
    cout << "   " << endl;
    cout << "Canvas 7, Pad 2" << endl;

    TH1D *h_corrected_L0_L0 = new TH1D(*h_correct_L0_L0);
    h_corrected_L0_L0->Add(h_correct_L0_L0_2, -1.0);

    cout << "   " << endl;
    cout << "Fit Parameters: Jan's Data after ME correction and background subtraction" << endl;
    TF1 *fit_corrected_L0_L0 = new TF1("fit_corrected_L0_L0", "[0] * (1 + [1] * x)", -1, 1);
    fit_corrected_L0_L0->SetParameters(1, 1);
    h_corrected_L0_L0->Fit(fit_corrected_L0_L0, "R");

    double A21_divided_jan = fit_corrected_L0_L0->GetParameter(0);
    double B21_divided_jan = fit_corrected_L0_L0->GetParameter(1);
    double B21_error_jan = fit_corrected_L0_L0->GetParError(1);
    cout << "Fit Parameters: Jan's corrected L0-L0 Pairs inside #DeltaR (After Background Subtraction):" << endl;
    cout << "A: " << A21_divided_jan << endl;
    cout << "B: " << B21_divided_jan << endl;

    double P_corrected_ll_jan = B21_divided_jan / constant_value_2;
    double P_corrected_ll_error_jan = B21_error_jan / constant_value_2;
    std::cout << "Polarization (L0-L0Bar): " << P_corrected_ll_jan << " ± " << P_corrected_ll_error_jan << std::endl; 

    TH1D *h_corrected_cos_theta_star_L0_L0 = new TH1D(*h_correct_cos_theta_star_L0_L0);
    h_corrected_cos_theta_star_L0_L0->Add(h_correct_cos_theta_star_L0_L0_2, -1.0);

    cout << "   " << endl;
    cout << "Fit Parameters: Kristen's Data after ME correction and background subtraction" << endl;
    TF1 *fit_corrected_cos_theta_star_L0_L0 = new TF1("fit_corrected_cos_theta_star_L0_L0", "[0] * (1 + [1] * x)", -1, 1);
    fit_corrected_cos_theta_star_L0_L0->SetParameters(1, 1);
    fit_corrected_cos_theta_star_L0_L0->SetLineColor(kBlue);
    h_corrected_cos_theta_star_L0_L0->Fit(fit_corrected_cos_theta_star_L0_L0, "R");

    double A21_divided = fit_corrected_cos_theta_star_L0_L0->GetParameter(0);
    double B21_divided = fit_corrected_cos_theta_star_L0_L0->GetParameter(1);
    double B21_error = fit_corrected_cos_theta_star_L0_L0->GetParError(1);
    cout << "Fit Parameters: Kristen's corrected L0-L0 Pairs inside #DeltaR (After Background Subtraction):" << endl;
    cout << "A: " << A21_divided << endl;
    cout << "B: " << B21_divided << endl;

    double P_corrected_ll = B21_divided / constant_value_2;
    double P_corrected_ll_error = B21_error / constant_value_2;
    std::cout << "Polarization (L0-L0Bar): " << P_corrected_ll << " ± " << P_corrected_ll_error << std::endl; 

    h_corrected_L0_L0->SetStats(0);
    h_corrected_L0_L0->SetMinimum(0);
    h_corrected_L0_L0->SetMarkerStyle(22);
    h_corrected_L0_L0->SetMarkerColor(kRed);
    h_corrected_L0_L0->SetLineColor(kRed);
    h_corrected_L0_L0->SetTitle("Corrected #Lambda#Lambda Pairs Inside #DeltaR; cos(#theta*); dN/dCos(#theta*)"); 
    h_corrected_L0_L0->GetXaxis()->CenterTitle();
    h_corrected_L0_L0->GetYaxis()->CenterTitle();
    // h_corrected_L0_L0->Draw("PE");

    h_corrected_cos_theta_star_L0_L0->SetStats(0);
    h_corrected_cos_theta_star_L0_L0->SetMinimum(0);
    h_corrected_cos_theta_star_L0_L0->SetMarkerStyle(20);
    h_corrected_cos_theta_star_L0_L0->SetMarkerColor(kBlue);
    fit_corrected_cos_theta_star_L0_L0->SetLineColor(kBlue);
    h_corrected_cos_theta_star_L0_L0->Draw("same");

    TLegend *legend_correct_2 = new TLegend(0.15, 0.15, 0.4, 0.3);
    legend_correct_2->SetBorderSize(1);    
    legend_correct_2->SetTextSize(0.03);   
    legend_correct_2->SetBorderSize(0);
    legend_correct_2->SetFillStyle(0); 
    // legend_correct_2->AddEntry(h_corrected_L0_L0, "Jan's dN/dCos(theta*): After Background Subtraction", "p");
    // legend_correct_2->AddEntry(fit_corrected_L0_L0, "Jan's dN/dCos(theta*): Fit");
    legend_correct_2->AddEntry(h_corrected_cos_theta_star_L0_L0, "#Lambda#Lambda", "p");
    legend_correct_2->AddEntry(fit_corrected_cos_theta_star_L0_L0, "Fit");
    legend_correct_2->Draw();

    c7->cd(3);
    cout << "   " << endl;
    cout << "Canvas 7, Pad 3" << endl;

    TH1D *h_corrected_L0bar_L0bar = new TH1D(*h_correct_L0bar_L0bar);
    h_corrected_L0bar_L0bar->Add(h_correct_L0bar_L0bar_2, -1.0);

    cout << "   " << endl;
    cout << "Fit Parameters: Jan's Data after ME correction and background subtraction" << endl;
    TF1 *fit_corrected_L0bar_L0bar = new TF1("fit_corrected_L0bar_L0bar", "[0] * (1 + [1] * x)", -1, 1);
    fit_corrected_L0bar_L0bar->SetParameters(1, 1);
    h_corrected_L0bar_L0bar->Fit(fit_corrected_L0bar_L0bar, "R");

    double A23_divided_jan = fit_corrected_L0bar_L0bar->GetParameter(0);
    double B23_divided_jan = fit_corrected_L0bar_L0bar->GetParameter(1);
    double B23_error_jan = fit_corrected_L0bar_L0bar->GetParError(1);
    cout << "Fit Parameters: Jans's corrected L0bar-L0bar Pairs inside #DeltaR (After Background Subtraction):" << endl;
    cout << "A: " << A23_divided_jan << endl;
    cout << "B: " << B23_divided_jan << endl;

    double P_corrected_lbarlbar_jan = B23_divided_jan / constant_value_3;
    double P_corrected_lbarlbar_error_jan = B23_error_jan / constant_value_3;
    std::cout << "Polarization (L0-L0Bar): " << P_corrected_lbarlbar_jan << " ± " << P_corrected_lbarlbar_error_jan << std::endl; 

    TH1D *h_corrected_cos_theta_star_L0bar_L0bar = new TH1D(*h_correct_cos_theta_star_L0bar_L0bar);
    h_corrected_cos_theta_star_L0bar_L0bar->Add(h_correct_cos_theta_star_L0bar_L0bar_2, -1.0);

    cout << "   " << endl;
    cout << "Fit Parameters: Kristen's Data after ME correction and background subtraction" << endl;
    TF1 *fit_corrected_cos_theta_star_L0bar_L0bar = new TF1("fit_corrected_cos_theta_star_L0bar_L0bar", "[0] * (1 + [1] * x)", -1, 1);
    fit_corrected_cos_theta_star_L0bar_L0bar->SetParameters(1, 1);
    fit_corrected_cos_theta_star_L0bar_L0bar->SetLineColor(kBlue);
    h_corrected_cos_theta_star_L0bar_L0bar->Fit(fit_corrected_cos_theta_star_L0bar_L0bar, "R");

    // TF1 *fit_corrected_cos_theta_star_L0bar_L0bar = new TF1("fit_corrected_cos_theta_star_L0bar_L0bar", "[0] * (1 + [1] * x)", -1, 1);
    // fit_corrected_cos_theta_star_L0bar_L0bar->SetParameters(1, 1);
    // fit_corrected_cos_theta_star_L0bar_L0bar->SetLineColor(kBlue);
    // h_corrected_cos_theta_star_L0bar_L0bar->Fit(fit_corrected_cos_theta_star_L0_L0bar, "R");

    double A23_divided = fit_corrected_cos_theta_star_L0bar_L0bar->GetParameter(0);
    double B23_divided = fit_corrected_cos_theta_star_L0bar_L0bar->GetParameter(1);
    double B23_error = fit_corrected_cos_theta_star_L0bar_L0bar->GetParError(1);
    cout << "Fit Parameters: Kristen's corrected L0bar-L0bar Pairs inside #DeltaR (After Background Subtraction):" << endl;
    cout << "A: " << A23_divided << endl;
    cout << "B: " << B23_divided << endl;

    double P_corrected_lbarlbar = B23_divided / constant_value_3;
    double P_corrected_lbarlbar_error = B23_error / constant_value_3;
    std::cout << "Polarization (L0-L0Bar): " << P_corrected_lbarlbar << " ± " << P_corrected_lbarlbar_error << std::endl;

    h_corrected_L0bar_L0bar->SetStats(0);
    h_corrected_L0bar_L0bar->SetMinimum(0);
    h_corrected_L0bar_L0bar->SetMarkerStyle(22);
    h_corrected_L0bar_L0bar->SetMarkerColor(kRed);
    h_corrected_L0bar_L0bar->SetLineColor(kRed);
    h_corrected_L0bar_L0bar->SetTitle("Corrected #bar{#Lambda}#bar{#Lambda} Pairs Inside #DeltaR; cos(#theta*); dN/dCos(#theta*)"); 
    h_corrected_L0bar_L0bar->GetXaxis()->CenterTitle();
    h_corrected_L0bar_L0bar->GetYaxis()->CenterTitle();
    // h_corrected_L0bar_L0bar->Draw("PE");

    h_corrected_cos_theta_star_L0bar_L0bar->SetStats(0);
    h_corrected_cos_theta_star_L0bar_L0bar->SetMinimum(0);
    h_corrected_cos_theta_star_L0bar_L0bar->SetMarkerStyle(20);
    h_corrected_cos_theta_star_L0bar_L0bar->SetMarkerColor(kBlue);
    fit_corrected_cos_theta_star_L0bar_L0bar->SetLineColor(kBlue);
    h_corrected_cos_theta_star_L0bar_L0bar->Draw("same");

    TLegend *legend_correct_3 = new TLegend(0.15, 0.15, 0.4, 0.3);
    legend_correct_3->SetBorderSize(1);    
    legend_correct_3->SetTextSize(0.03);   
    legend_correct_3->SetBorderSize(0);
    legend_correct_3->SetFillStyle(0); 
    // legend_correct_3->AddEntry(h_corrected_L0bar_L0bar, "Jan's dN/dCos(theta*): After Background Subtraction", "p");
    // legend_correct_3->AddEntry(fit_corrected_L0bar_L0bar, "Jan's dN/dCos(theta*): Fit");
    legend_correct_3->AddEntry(h_corrected_cos_theta_star_L0bar_L0bar, "#bar{#Lambda}#bar{#Lambda}", "p");
    legend_correct_3->AddEntry(fit_corrected_cos_theta_star_L0bar_L0bar, "Fit");
    legend_correct_3->Draw();

    c7->cd(4);
    cout << "   " << endl;
    cout << "Canvas 7, Pad 4" << endl;

    TH1D *h_corrected_outside_L0_L0bar = new TH1D(*h_correct_outside_L0_L0bar);
    h_corrected_outside_L0_L0bar->Add(h_correct_outside_L0_L0bar_2, -1.0);

    cout << "   " << endl;
    cout << "Fit Parameters: Jan's Data after ME correction and background subtraction" << endl;
    TF1 *fit_corrected_outside_L0_L0bar = new TF1("fit_corrected_outside_L0_L0bar", "[0] * (1 + [1] * x)", -1, 1);
    fit_corrected_outside_L0_L0bar->SetParameters(1, 1);
    h_corrected_outside_L0_L0bar->Fit(fit_corrected_outside_L0_L0bar, "R");

    // TF1 *fit_corrected_outside_L0_L0bar = new TF1("fit_corrected_outside_L0_L0bar", "[0] * (1 + [1] * x)", -1, 1);
    // fit_corrected_outside_L0_L0bar->SetParameters(1, 1);
    // h_corrected_outside_L0_L0bar->Fit(fit_corrected_L0_L0bar, "R");

    double A32_divided_jan = fit_corrected_outside_L0_L0bar->GetParameter(0);
    double B32_divided_jan = fit_corrected_outside_L0_L0bar->GetParameter(1);
    double B32_error_jan = fit_corrected_outside_L0_L0bar->GetParError(1);
    cout << "Fit Parameters: Jans's corrected L0-L0bar Pairs outside #DeltaR (After Background Subtraction):" << endl;
    cout << "A: " << A32_divided_jan << endl;
    cout << "B: " << B32_divided_jan << endl;

    double P_corrected_outside_llbar_jan = B32_divided_jan / constant_value;
    double P_corrected_outside_llbar_error_jan = B32_error_jan / constant_value;
    std::cout << "Polarization (L0-L0Bar): " << P_corrected_outside_llbar_jan << " ± " << P_corrected_outside_llbar_error_jan << std::endl;

    TH1D *h_corrected_outside_cos_theta_star_L0_L0bar = new TH1D(*h_correct_outside_cos_theta_star_L0_L0bar);
    h_corrected_outside_cos_theta_star_L0_L0bar->Add(h_correct_outside_cos_theta_star_L0_L0bar_2, -1.0);

    cout << "   " << endl;
    cout << "Fit Parameters: Kristen's Data after ME correction and background subtraction" << endl;
    TF1 *fit_corrected_outside_cos_theta_star_L0_L0bar = new TF1("fit_corrected_outside_cos_theta_star_L0_L0bar", "[0] * (1 + [1] * x)", -1, 1);
    fit_corrected_outside_cos_theta_star_L0_L0bar->SetParameters(1, 1);
    fit_corrected_outside_cos_theta_star_L0_L0bar->SetLineColor(kBlue);
    h_corrected_outside_cos_theta_star_L0_L0bar->Fit(fit_corrected_outside_cos_theta_star_L0_L0bar, "R");

    double A32_divided = fit_corrected_outside_cos_theta_star_L0_L0bar->GetParameter(0);
    double B32_divided = fit_corrected_outside_cos_theta_star_L0_L0bar->GetParameter(1);
    double B32_error = fit_corrected_outside_cos_theta_star_L0_L0bar->GetParError(1);
    cout << "Fit Parameters: Kristen's corrected L0-L0bar Pairs outside #DeltaR (After Background Subtraction):" << endl;
    cout << "A: " << A32_divided << endl;
    cout << "B: " << B32_divided << endl;

    double P_corrected_outside_llbar = B32_divided / constant_value;
    double P_corrected_outside_llbar_error = B32_error / constant_value;
    std::cout << "Polarization (L0-L0Bar): " << P_corrected_outside_llbar << " ± " << P_corrected_outside_llbar_error << std::endl;

    h_corrected_outside_L0_L0bar->SetStats(0);
    h_corrected_outside_L0_L0bar->SetMinimum(0);
    h_corrected_outside_L0_L0bar->SetMarkerStyle(22);
    h_corrected_outside_L0_L0bar->SetMarkerColor(kRed);
    h_corrected_outside_L0_L0bar->SetLineColor(kRed);
    h_corrected_outside_L0_L0bar->SetTitle("Corrected #Lambda#bar{#Lambda} Pairs outside #DeltaR; cos(#theta*); dN/dCos(#theta*)"); 
    h_corrected_outside_L0_L0bar->GetXaxis()->CenterTitle();
    h_corrected_outside_L0_L0bar->GetYaxis()->CenterTitle();
    // h_corrected_outside_L0_L0bar->Draw("PE");

    h_corrected_outside_cos_theta_star_L0_L0bar->SetStats(0);
    h_corrected_outside_cos_theta_star_L0_L0bar->SetMinimum(0);
    h_corrected_outside_cos_theta_star_L0_L0bar->SetMarkerStyle(20);
    h_corrected_outside_cos_theta_star_L0_L0bar->SetMarkerColor(kBlue);
    fit_corrected_cos_theta_star_L0_L0bar->SetLineColor(kBlue);
    h_corrected_outside_cos_theta_star_L0_L0bar->Draw("same");

    TLegend *legend_correct_4 = new TLegend(0.15, 0.15, 0.4, 0.3);
    legend_correct_4->SetBorderSize(1);    
    legend_correct_4->SetTextSize(0.03);   
    legend_correct_4->SetBorderSize(0);
    legend_correct_4->SetFillStyle(0); 
    // legend_correct_4->AddEntry(h_corrected_L0_L0bar, "Jan's dN/dCos(theta*): After Background Subtraction", "p");
    // legend_correct_4->AddEntry(fit_corrected_L0_L0bar, "Jan's dN/dCos(theta*): Fit");
    legend_correct_4->AddEntry(h_corrected_cos_theta_star_L0_L0bar, "#Lambda#bar{#Lambda}", "p");
    legend_correct_4->AddEntry(fit_corrected_cos_theta_star_L0_L0bar, "Fit");
    legend_correct_4->Draw();

    c7->cd(5);
    cout << "   " << endl;
    cout << "Canvas 7, Pad 5" << endl;

    TH1D *h_corrected_outside_L0_L0 = new TH1D(*h_correct_outside_L0_L0);
    h_corrected_outside_L0_L0->Add(h_correct_outside_L0_L0_2, -1.0);

    cout << "   " << endl;
    cout << "Fit Parameters: Jan's Data after ME correction and background subtraction" << endl;
    TF1 *fit_corrected_outside_L0_L0 = new TF1("fit_corrected_outside_L0_L0", "[0] * (1 + [1] * x)", -1, 1);
    fit_corrected_outside_L0_L0->SetParameters(1, 1);
    h_corrected_outside_L0_L0->Fit(fit_corrected_outside_L0_L0, "R");

    double A31_divided_jan = fit_corrected_outside_L0_L0->GetParameter(0);
    double B31_divided_jan = fit_corrected_outside_L0_L0->GetParameter(1);
    double B31_error_jan = fit_corrected_outside_L0_L0->GetParError(1);
    cout << "Fit Parameters: Jans's corrected L0-L0 Pairs outside #DeltaR (After Background Subtraction):" << endl;
    cout << "A: " << A31_divided_jan << endl;
    cout << "B: " << B31_divided_jan << endl;

    double P_corrected_outside_ll_jan = B31_divided_jan / constant_value_2;
    double P_corrected_outside_ll_error_jan = B31_error_jan / constant_value_2;
    std::cout << "Polarization (L0-L0Bar): " << P_corrected_outside_ll_jan << " ± " << P_corrected_outside_ll_error_jan << std::endl; 

    TH1D *h_corrected_outside_cos_theta_star_L0_L0 = new TH1D(*h_correct_outside_cos_theta_star_L0_L0);
    h_corrected_outside_cos_theta_star_L0_L0->Add(h_correct_outside_cos_theta_star_L0_L0_2, -1.0);

    cout << "   " << endl;
    cout << "Fit Parameters: Kristen's Data after ME correction and background subtraction" << endl;
    TF1 *fit_corrected_outside_cos_theta_star_L0_L0 = new TF1("fit_corrected_outside_cos_theta_star_L0_L0", "[0] * (1 + [1] * x)", -1, 1);
    fit_corrected_outside_cos_theta_star_L0_L0->SetParameters(1, 1);
    fit_corrected_outside_cos_theta_star_L0_L0->SetLineColor(kBlue);
    h_corrected_outside_cos_theta_star_L0_L0->Fit(fit_corrected_outside_cos_theta_star_L0_L0, "R");

    double A31_divided = fit_corrected_outside_cos_theta_star_L0_L0->GetParameter(0);
    double B31_divided = fit_corrected_outside_cos_theta_star_L0_L0->GetParameter(1);
    double B31_error = fit_corrected_outside_cos_theta_star_L0_L0->GetParError(1);
    cout << "Fit Parameters: Kristen's corrected L0-L0 Pairs outside #DeltaR (After Background Subtraction):" << endl;
    cout << "A: " << A31_divided << endl;
    cout << "B: " << B31_divided << endl;

    double P_corrected_outside_ll = B31_divided / constant_value_2;
    double P_corrected_outside_ll_error = B31_error / constant_value_2;
    std::cout << "Polarization (L0-L0Bar): " << P_corrected_outside_ll << " ± " << P_corrected_outside_ll_error << std::endl; 

    h_corrected_outside_L0_L0->SetStats(0);
    h_corrected_outside_L0_L0->SetMinimum(0);
    h_corrected_outside_L0_L0->SetMarkerStyle(22);
    h_corrected_outside_L0_L0->SetMarkerColor(kRed);
    h_corrected_outside_L0_L0->SetLineColor(kRed);
    h_corrected_outside_L0_L0->SetTitle("Corrected #Lambda#Lambda Pairs outside #DeltaR; cos(#theta*); dN/dCos(#theta*)"); 
    h_corrected_outside_L0_L0->GetXaxis()->CenterTitle();
    h_corrected_outside_L0_L0->GetYaxis()->CenterTitle();
    // h_corrected_outside_L0_L0->Draw("PE");

    h_corrected_outside_cos_theta_star_L0_L0->SetStats(0);
    h_corrected_outside_cos_theta_star_L0_L0->SetMinimum(0);
    h_corrected_outside_cos_theta_star_L0_L0->SetMarkerStyle(20);
    h_corrected_outside_cos_theta_star_L0_L0->SetMarkerColor(kBlue);
    fit_corrected_outside_cos_theta_star_L0_L0->SetLineColor(kBlue);
    h_corrected_outside_cos_theta_star_L0_L0->Draw("same");

    TLegend *legend_correct_5 = new TLegend(0.15, 0.15, 0.4, 0.3);
    legend_correct_5->SetBorderSize(1);    
    legend_correct_5->SetTextSize(0.03);   
    legend_correct_5->SetBorderSize(0);
    legend_correct_5->SetFillStyle(0); 
    // legend_correct_5->AddEntry(h_corrected_L0_L0, "Jan's dN/dCos(theta*): After Background Subtraction", "p");
    // legend_correct_5->AddEntry(fit_corrected_L0_L0, "Jan's dN/dCos(theta*): Fit");
    legend_correct_5->AddEntry(h_corrected_cos_theta_star_L0_L0, "#Lambda#Lambda", "p");
    legend_correct_5->AddEntry(fit_corrected_cos_theta_star_L0_L0, "Fit");
    legend_correct_5->Draw();

    c7->cd(6);
    cout << "   " << endl;
    cout << "Canvas 7, Pad 6" << endl;

    TH1D *h_corrected_outside_L0bar_L0bar = new TH1D(*h_correct_outside_L0bar_L0bar);
    h_corrected_outside_L0bar_L0bar->Add(h_correct_outside_L0bar_L0bar_2, -1.0);

    cout << "   " << endl;
    cout << "Fit Parameters: Jan's Data after ME correction and background subtraction" << endl;
    TF1 *fit_corrected_outside_L0bar_L0bar = new TF1("fit_corrected_outside_L0bar_L0bar", "[0] * (1 + [1] * x)", -1, 1);
    fit_corrected_outside_L0bar_L0bar->SetParameters(1, 1);
    h_corrected_outside_L0bar_L0bar->Fit(fit_corrected_outside_L0bar_L0bar, "R");

    double A33_divided_jan = fit_corrected_outside_L0bar_L0bar->GetParameter(0);
    double B33_divided_jan = fit_corrected_outside_L0bar_L0bar->GetParameter(1);
    double B33_error_jan = fit_corrected_outside_L0bar_L0bar->GetParError(1);
    cout << "Fit Parameters: Jans's corrected L0bar-L0bar Pairs outside #DeltaR (After Background Subtraction):" << endl;
    cout << "A: " << A33_divided_jan << endl;
    cout << "B: " << B33_divided_jan << endl;

    double P_corrected_outside_lbarlbar_jan = B33_divided_jan / constant_value_3;
    double P_corrected_outside_lbarlbar_error_jan = B33_error_jan / constant_value_3;
    std::cout << "Polarization (L0-L0Bar): " << P_corrected_outside_lbarlbar_jan << " ± " << P_corrected_outside_lbarlbar_error_jan << std::endl; 

    TH1D *h_corrected_outside_cos_theta_star_L0bar_L0bar = new TH1D(*h_correct_outside_cos_theta_star_L0bar_L0bar);
    h_corrected_outside_cos_theta_star_L0bar_L0bar->Add(h_correct_outside_cos_theta_star_L0bar_L0bar_2, -1.0);

    cout << "   " << endl;
    cout << "Fit Parameters: Kristen's Data after ME correction and background subtraction" << endl;
    TF1 *fit_corrected_outside_cos_theta_star_L0bar_L0bar = new TF1("fit_corrected_outside_cos_theta_star_L0bar_L0bar", "[0] * (1 + [1] * x)", -1, 1);
    fit_corrected_outside_cos_theta_star_L0bar_L0bar->SetParameters(1, 1);
    fit_corrected_outside_cos_theta_star_L0bar_L0bar->SetLineColor(kBlue);
    h_corrected_outside_cos_theta_star_L0bar_L0bar->Fit(fit_corrected_outside_cos_theta_star_L0bar_L0bar, "R");

    // TF1 *fit_corrected_outside_cos_theta_star_L0bar_L0bar = new TF1("fit_corrected_outside_cos_theta_star_L0bar_L0bar", "[0] * (1 + [1] * x)", -1, 1);
    // fit_corrected_outside_cos_theta_star_L0bar_L0bar->SetParameters(1, 1);
    // fit_corrected_outside_cos_theta_star_L0bar_L0bar->SetLineColor(kBlue);
    // h_corrected_outside_cos_theta_star_L0bar_L0bar->Fit(fit_corrected_outside_cos_theta_star_L0_L0bar, "R");

    double A33_divided = fit_corrected_outside_cos_theta_star_L0bar_L0bar->GetParameter(0);
    double B33_divided = fit_corrected_outside_cos_theta_star_L0bar_L0bar->GetParameter(1);
    double B33_error = fit_corrected_outside_cos_theta_star_L0bar_L0bar->GetParError(1);
    cout << "Fit Parameters: Kristen's corrected L0bar-L0bar Pairs outside #DeltaR (After Background Subtraction):" << endl;
    cout << "A: " << A33_divided << endl;
    cout << "B: " << B33_divided << endl;

    double P_corrected_outside_lbarlbar = B33_divided / constant_value_3;
    double P_corrected_outside_lbarlbar_error = B33_error / constant_value_3;
    std::cout << "Polarization (L0-L0Bar): " << P_corrected_outside_lbarlbar << " ± " << P_corrected_outside_lbarlbar_error << std::endl;

    h_corrected_outside_L0bar_L0bar->SetStats(0);
    h_corrected_outside_L0bar_L0bar->SetMinimum(0);
    h_corrected_outside_L0bar_L0bar->SetMarkerStyle(22);
    h_corrected_outside_L0bar_L0bar->SetMarkerColor(kRed);
    h_corrected_outside_L0bar_L0bar->SetLineColor(kRed);
    h_corrected_outside_L0bar_L0bar->SetTitle("Corrected #bar{#Lambda}#bar{#Lambda} Pairs outside #DeltaR; cos(#theta*); dN/dCos(#theta*)"); 
    h_corrected_outside_L0bar_L0bar->GetXaxis()->CenterTitle();
    h_corrected_outside_L0bar_L0bar->GetYaxis()->CenterTitle();
    // h_corrected_outside_L0bar_L0bar->Draw("PE");

    h_corrected_outside_cos_theta_star_L0bar_L0bar->SetStats(0);
    h_corrected_outside_cos_theta_star_L0bar_L0bar->SetMinimum(0);
    h_corrected_outside_cos_theta_star_L0bar_L0bar->SetMarkerStyle(20);
    h_corrected_outside_cos_theta_star_L0bar_L0bar->SetMarkerColor(kBlue);
    fit_corrected_cos_theta_star_L0bar_L0bar->SetLineColor(kBlue);
    h_corrected_outside_cos_theta_star_L0bar_L0bar->Draw("same");

    TLegend *legend_correct_6 = new TLegend(0.15, 0.15, 0.4, 0.3);
    legend_correct_6->SetBorderSize(1);    
    legend_correct_6->SetTextSize(0.03);   
    legend_correct_6->SetBorderSize(0);
    legend_correct_6->SetFillStyle(0); 
    // legend_correct_6->AddEntry(h_corrected_L0bar_L0bar, "Jan's dN/dCos(theta*): After Background Subtraction", "p");
    // legend_correct_6->AddEntry(fit_corrected_L0bar_L0bar, "Jan's dN/dCos(theta*): Fit");
    legend_correct_6->AddEntry(h_corrected_cos_theta_star_L0bar_L0bar, "#bar{#Lambda}#bar{#Lambda}", "p");
    legend_correct_6->AddEntry(fit_corrected_cos_theta_star_L0bar_L0bar, "Fit");
    legend_correct_6->Draw();

    TCanvas *c8 = new TCanvas("c8", "Canvas 8", 1800, 900);
    c8->Divide(2,1);

    double x_min3 = -0.65;
    double x_max3 = 0.3;

    double x_min4 = -0.2;
    double x_max4 = 0.2;

    c8->cd(1);
    double xValues_3[3] = {P_corrected_llbar_jan, P_corrected_ll_jan, P_corrected_lbarlbar_jan}; 
    double yValues_3[3] = {1, 2, 3};  // Arbitrary x-values for visualization

    double xErrors_3[3] = {P_corrected_llbar_error_jan, P_corrected_ll_error_jan, P_corrected_lbarlbar_error_jan}; 
    double yErrors_3[3] = {0, 0, 0};

    double xValues_13[3] = {P_corrected_llbar, P_corrected_ll, P_corrected_lbarlbar}; 
    double yValues_13[3] = {1, 2, 3};  // Arbitrary x-values for visualization

    double xErrors_13[3] = {P_corrected_llbar_error, P_corrected_ll_error, P_corrected_lbarlbar_error}; 
    double yErrors_13[3] = {0, 0, 0};

    TGraphErrors *graph3 = new TGraphErrors(3, xValues_3, yValues_3, xErrors_3, yErrors_3);
    TGraphErrors *graph13 = new TGraphErrors(3, xValues_13, yValues_13, xErrors_13, yErrors_13);

    graph3->SetTitle("Polarization inside #DeltaR = 0.93 (w/ background subtraction)");
    graph3->SetMarkerStyle(21);
    graph3->SetMarkerSize(1.5);
    graph3->SetMarkerColor(kRed);
    graph3->SetLineColor(kRed);
    graph3->GetXaxis()->SetLimits(x_min3, x_max3);
    graph3->Draw("APLE");

    graph13->SetTitle("Polarization inside #DeltaR = 0.93");
    graph13->SetMarkerStyle(20);
    graph13->SetMarkerSize(1.5);
    graph13->SetMarkerColor(kBlue);
    graph13->SetLineColor(kBlue);
    // graph13->GetXaxis()->SetLimits(x_min3, x_max3);
    // graph13->GetYaxis()->SetLimits(0.5, 3.5);  // Adjust limits to fit labels properly
    // graph13->GetYaxis()->SetNdivisions(3);
    // graph13->GetYaxis()->SetLabelSize(0);
    graph13->Draw("PLE same");

    // TLatex latex;
    // latex.SetTextSize(0.04);
    // latex.SetTextAlign(32);  // Right-align
    // latex.DrawLatex(x_min3 - 0.0025, 1, "#Lambda^{0}#bar{#Lambda}^{0}");
    // latex.DrawLatex(x_min3 - 0.0025, 2, "#Lambda^{0}#Lambda^{0}");
    // latex.DrawLatex(x_min3 - 0.0025, 3, "#bar{#Lambda}^{0}#bar{#Lambda}^{0}");

    // TLine *line = new TLine(0, 0.9, 0, 3.15); 
    // line->SetLineStyle(2); // Dashed line
    // line->SetLineColor(kRed);
    // line->SetLineWidth(2);
    // line->Draw();

    TLegend *legend3 = new TLegend(0.15, 0.35, 0.4, 0.25);
    legend3->SetBorderSize(1);    
    legend3->SetTextSize(0.02);   
    legend3->SetBorderSize(0);
    legend3->SetFillStyle(0); 
    legend3->AddEntry(graph3, "Jan's Polarization: After Background Subtraction", "p");
    legend3->AddEntry(graph13, "Kristen's Polarization: After Background Subtraction", "p");
    legend3->Draw();

    c8->cd(2);
    double xValues_33[3] = {P_corrected_outside_llbar_jan, P_corrected_outside_ll_jan, P_corrected_outside_lbarlbar_jan}; 
    double yValues_33[3] = {1, 2, 3};  // Arbitrary x-values for visualization

    double xErrors_33[3] = {P_corrected_outside_llbar_error_jan, P_corrected_outside_ll_error_jan, P_corrected_outside_lbarlbar_error_jan}; 
    double yErrors_33[3] = {0, 0, 0};

    double xValues_23[3] = {P_corrected_outside_llbar, P_corrected_outside_ll, P_corrected_outside_lbarlbar}; 
    double yValues_23[3] = {1, 2, 3};  // Arbitrary x-values for visualization

    double xErrors_23[3] = {P_corrected_outside_llbar_error, P_corrected_outside_ll_error, P_corrected_outside_lbarlbar_error}; 
    double yErrors_23[3] = {0, 0, 0};

    TGraphErrors *graph23 = new TGraphErrors(3, xValues_33, yValues_33, xErrors_33, yErrors_33);
    TGraphErrors *graph25 = new TGraphErrors(3, xValues_23, yValues_23, xErrors_23, yErrors_23);

    graph23->SetTitle("Polarization outside #DeltaR = 0.93 (w/ background subtraction)");
    graph23->SetMarkerStyle(21);
    graph23->SetMarkerSize(1.5);
    graph23->SetMarkerColor(kRed);
    graph23->SetLineColor(kRed);
    graph23->GetXaxis()->SetLimits(x_min4, x_max4);
    graph23->Draw("APLE");

    graph25->SetTitle("Polarization outside #DeltaR = 0.93");
    graph25->SetMarkerStyle(20);
    graph25->SetMarkerSize(1.5);
    graph25->SetMarkerColor(kBlue);
    graph25->SetLineColor(kBlue);
    // graph25->GetXaxis()->SetLimits(x_min4, x_max4);
    // graph25->GetYaxis()->SetLimits(0.5, 3.5);  // Adjust limits to fit labels properly
    // graph25->GetYaxis()->SetNdivisions(3);
    // graph25->GetYaxis()->SetLabelSize(0);
    graph25->Draw("PLE same");

    // TLatex latex2;
    // latex2.SetTextSize(0.04);
    // latex2.SetTextAlign(32);  // Right-align
    // latex2.DrawLatex(x_min4 - 0.0025, 1, "#Lambda^{0}#bar{#Lambda}^{0}");
    // latex2.DrawLatex(x_min4 - 0.0025, 2, "#Lambda^{0}#Lambda^{0}");
    // latex2.DrawLatex(x_min4 - 0.0025, 3, "#bar{#Lambda}^{0}#bar{#Lambda}^{0}");

    // TLine *line2 = new TLine(0, 0.9, 0, 3.15); 
    // line2->SetLineStyle(2); // Dashed line
    // line2->SetLineColor(kRed);
    // line2->SetLineWidth(2);
    // line2->Draw();

    TLegend *legend4 = new TLegend(0.15, 0.35, 0.4, 0.25);
    legend4->SetBorderSize(1);        
    legend4->SetTextSize(0.03);   
    legend4->SetBorderSize(0);
    legend4->SetFillStyle(0); 
    legend4->AddEntry(graph23, "Jan's Polarization: After Background Subtraction", "p");
    legend4->AddEntry(graph25, "Kristen's Polarization: After Background Subtraction", "p");
    legend4->Draw();

    TCanvas *c9 = new TCanvas("c9", "Canvas 9", 1800, 900);
    c9->Divide(3,2);

    c9->cd(1);
    h_cos_theta_star3->SetStats(0);
    h_cos_theta_star3->SetMinimum(0);
    h_cos_theta_star3->SetMaximum(9);
    h_cos_theta_star3->SetMarkerStyle(20);
    h_cos_theta_star3->SetMarkerColor(kBlue);
    h_cos_theta_star3->SetTitle("SE and ME #Lambda#bar{#Lambda} Pairs inside #DeltaR=0.93; cos(#theta*); dN/dCos(#theta*)"); 
    // h_cos_theta_star3->SetTitle("SE #Lambda#bar{#Lambda} Pairs inside #DeltaR=0.93; cos(#theta*); dN/dCos(#theta*)"); 
    h_cos_theta_star3->GetXaxis()->CenterTitle();
    h_cos_theta_star3->GetYaxis()->CenterTitle();

    h_cos_theta_star4->SetStats(0);
    h_cos_theta_star4->SetMinimum(0);
    h_cos_theta_star4->SetMarkerStyle(20);
    h_cos_theta_star4->SetMarkerColor(kRed);
    h_cos_theta_star4->SetLineColor(kRed);

    h_ME_cos_theta_star3_clone->SetStats(0);
    h_ME_cos_theta_star3_clone->SetMinimum(0);
    h_ME_cos_theta_star3_clone->SetMarkerStyle(25);
    h_ME_cos_theta_star3_clone->SetMarkerColor(kBlue);

    h_ME_cos_theta_star4_clone->SetStats(0);
    h_ME_cos_theta_star4_clone->SetMinimum(0);
    h_ME_cos_theta_star4_clone->SetMarkerStyle(25);
    h_ME_cos_theta_star4_clone->SetMarkerColor(kRed);
    h_ME_cos_theta_star4_clone->SetLineColor(kRed);

    h_cos_theta_star3->Draw("PE");
    h_cos_theta_star4->Draw("PE same");
    h_ME_cos_theta_star3_clone->Draw("PE same");
    h_ME_cos_theta_star4_clone->Draw("PE same");

    TLegend *legend_2 = new TLegend(0.12, 0.25, 0.4, 0.45);
    legend_2->SetTextSize(0.03);
    legend_2->SetBorderSize(0);
    legend_2->SetFillStyle(0); // Transparent background

    legend_2->AddEntry(h_cos_theta_star3, "US-US SE #Lambda-#bar{#Lambda} Pairs", "p");
    legend_2->AddEntry(h_cos_theta_star4, "US-LS SE #Lambda-#bar{#Lambda} Pairs", "p");
    legend_2->AddEntry(h_ME_cos_theta_star3_clone, "US-US ME #Lambda-#bar{#Lambda} Pairs", "p");
    legend_2->AddEntry(h_ME_cos_theta_star4_clone, "US-US SE #Lambda-#bar{#Lambda} Pairs", "p");

    legend_2->Draw();

    c9->cd(2);
    h_outside_cos_theta_star3->SetStats(0);
    h_outside_cos_theta_star3->SetMinimum(0);
    h_outside_cos_theta_star3->SetMarkerStyle(20);
    h_outside_cos_theta_star3->SetMarkerColor(kBlue);
    // h_outside_cos_theta_star3->SetMaximum(10);
    h_outside_cos_theta_star3->SetTitle("SE and ME #Lambda#bar{#Lambda} Pairs outside #DeltaR=0.93; cos(#theta*); dN/dCos(#theta*)"); 
    h_outside_cos_theta_star3->GetXaxis()->CenterTitle();
    h_outside_cos_theta_star3->GetYaxis()->CenterTitle();

    h_outside_cos_theta_star4->SetStats(0);
    h_outside_cos_theta_star4->SetMinimum(0);
    h_outside_cos_theta_star4->SetMarkerStyle(20);
    h_outside_cos_theta_star4->SetMarkerColor(kRed);
    h_outside_cos_theta_star4->SetLineColor(kRed);

    h_outside_ME_cos_theta_star3_clone->SetStats(0);
    h_outside_ME_cos_theta_star3_clone->SetMinimum(0);
    h_outside_ME_cos_theta_star3_clone->SetMarkerStyle(25);
    h_outside_ME_cos_theta_star3_clone->SetMarkerColor(kBlue);

    h_outside_ME_cos_theta_star4_clone->SetStats(0);
    h_outside_ME_cos_theta_star4_clone->SetMinimum(0);
    h_outside_ME_cos_theta_star4_clone->SetMarkerStyle(25);
    h_outside_ME_cos_theta_star4_clone->SetMarkerColor(kRed);
    h_outside_ME_cos_theta_star4_clone->SetLineColor(kRed);

    h_outside_cos_theta_star3->Draw("PE same");
    h_outside_cos_theta_star4->Draw("PE same");
    h_outside_ME_cos_theta_star3_clone->Draw("PE same");
    h_outside_ME_cos_theta_star4_clone->Draw("PE same");

    TLegend *legend_5 = new TLegend(0.12, 0.45, 0.4, 0.65);
    legend_5->SetTextSize(0.03);
    legend_5->SetBorderSize(0);
    legend_5->SetFillStyle(0); // Transparent background

    legend_5->AddEntry(h_outside_cos_theta_star3, "US-US SE #Lambda-#bar{#Lambda} Pairs", "p");
    legend_5->AddEntry(h_outside_cos_theta_star4, "US-LS SE #Lambda-#bar{#Lambda} Pairs", "p");
    legend_5->AddEntry(h_outside_ME_cos_theta_star3_clone, "US-US ME #Lambda-#bar{#Lambda} Pairs", "p");
    legend_5->AddEntry(h_outside_ME_cos_theta_star4_clone, "US-US SE #Lambda-#bar{#Lambda} Pairs", "p");

    legend_5->Draw();

    c9->cd(4);
    h_correct_cos_theta_star_L0_L0bar->SetStats(0);
    h_correct_cos_theta_star_L0_L0bar->SetMinimum(0);
    h_correct_cos_theta_star_L0_L0bar->SetMarkerStyle(20);
    h_correct_cos_theta_star_L0_L0bar->SetMarkerColor(kBlue);
    h_correct_cos_theta_star_L0_L0bar->SetTitle("#Lambda#bar{#Lambda} Pairs inside #DeltaR=0.93; cos(#theta*); dN/dCos(#theta*)"); 
    h_correct_cos_theta_star_L0_L0bar->GetXaxis()->CenterTitle();
    h_correct_cos_theta_star_L0_L0bar->GetYaxis()->CenterTitle();

    h_correct_cos_theta_star_L0_L0bar_2->SetStats(0);
    h_correct_cos_theta_star_L0_L0bar_2->SetMinimum(0);
    h_correct_cos_theta_star_L0_L0bar_2->SetMarkerStyle(20);
    h_correct_cos_theta_star_L0_L0bar_2->SetMarkerColor(kRed);
    h_correct_cos_theta_star_L0_L0bar_2->SetLineColor(kRed);

    h_correct_cos_theta_star_L0_L0bar->Draw("PE");
    h_correct_cos_theta_star_L0_L0bar_2->Draw("PE same");

    TLegend *legend_6 = new TLegend(0.12, 0.45, 0.4, 0.55);
    legend_6->SetTextSize(0.03);
    legend_6->SetBorderSize(0);
    legend_6->SetFillStyle(0); // Transparent background

    legend_6->AddEntry(h_correct_cos_theta_star_L0_L0bar, "US-US SE #Lambda-#bar{#Lambda} Pairs", "p");
    legend_6->AddEntry(h_correct_cos_theta_star_L0_L0bar_2, "US-LS SE #Lambda-#bar{#Lambda} Pairs", "p");

    legend_6->Draw();

    c9->cd(5);
    h_correct_outside_cos_theta_star_L0_L0bar->SetStats(0);
    h_correct_outside_cos_theta_star_L0_L0bar->SetMinimum(0);
    h_correct_outside_cos_theta_star_L0_L0bar->SetMarkerStyle(20);
    h_correct_outside_cos_theta_star_L0_L0bar->SetMarkerColor(kBlue);
    h_correct_outside_cos_theta_star_L0_L0bar->SetTitle("#Lambda#bar{#Lambda} Pairs outside #DeltaR=0.93; cos(#theta*); dN/dCos(#theta*)"); 
    h_correct_outside_cos_theta_star_L0_L0bar->GetXaxis()->CenterTitle();
    h_correct_outside_cos_theta_star_L0_L0bar->GetYaxis()->CenterTitle();

    h_correct_outside_cos_theta_star_L0_L0bar_2->SetStats(0);
    h_correct_outside_cos_theta_star_L0_L0bar_2->SetMinimum(0);
    h_correct_outside_cos_theta_star_L0_L0bar_2->SetMarkerStyle(20);
    h_correct_outside_cos_theta_star_L0_L0bar_2->SetMarkerColor(kRed);
    h_correct_outside_cos_theta_star_L0_L0bar_2->SetLineColor(kRed);

    h_correct_outside_cos_theta_star_L0_L0bar->Draw("PE");
    h_correct_outside_cos_theta_star_L0_L0bar_2->Draw("PE same");

    TLegend *legend_7 = new TLegend(0.12, 0.45, 0.4, 0.55);
    legend_7->SetTextSize(0.03);
    legend_7->SetBorderSize(0);
    legend_7->SetFillStyle(0); // Transparent background

    legend_7->AddEntry(h_correct_outside_cos_theta_star_L0_L0bar, "US-US SE #Lambda-#bar{#Lambda} Pairs", "p");
    legend_7->AddEntry(h_correct_outside_cos_theta_star_L0_L0bar_2, "US-LS SE #Lambda-#bar{#Lambda} Pairs", "p");
    legend_7->Draw();

    TCanvas *c10 = new TCanvas("c10", "Canvas 10", 1800, 900);
    c10->Divide(3,2);

    c10->cd(1);
    h_corrected_cos_theta_star_L0_L0bar->SetStats(0);
    h_corrected_cos_theta_star_L0_L0bar->SetMinimum(0);
    h_corrected_cos_theta_star_L0_L0bar->SetMarkerStyle(20);
    h_corrected_cos_theta_star_L0_L0bar->SetMarkerColor(kBlue);
    // fit_corrected_cos_theta_star_L0_L0bar->SetLineColor(kRed);
    h_corrected_cos_theta_star_L0_L0bar->SetTitle("Corrected #Lambda#bar{#Lambda} Pairs inside #DeltaR=0.93; cos(#theta*); dN/dCos(#theta*)"); 
    h_corrected_cos_theta_star_L0_L0bar->GetXaxis()->CenterTitle();
    h_corrected_cos_theta_star_L0_L0bar->GetYaxis()->CenterTitle();
    h_corrected_cos_theta_star_L0_L0bar->Draw("PE");

    fit_corrected_cos_theta_star_L0_L0bar->SetLineColor(kRed);
    fit_corrected_cos_theta_star_L0_L0bar->Draw("same");

    TLegend *legend_correct_12 = new TLegend(0.15, 0.3, 0.4, 0.4);
    legend_correct_12->SetBorderSize(1);    
    legend_correct_12->SetTextSize(0.03);   
    legend_correct_12->SetBorderSize(0);
    legend_correct_12->SetFillStyle(0); 
    legend_correct_12->AddEntry(h_corrected_cos_theta_star_L0_L0bar, "#Lambda#bar{#Lambda}", "p");
    legend_correct_12->AddEntry(fit_corrected_cos_theta_star_L0_L0bar, "Fit");
    legend_correct_12->Draw();

    c10->cd(2);
    h_corrected_outside_cos_theta_star_L0_L0bar->SetStats(0);
    h_corrected_outside_cos_theta_star_L0_L0bar->SetMinimum(0);
    h_corrected_outside_cos_theta_star_L0_L0bar->SetMarkerStyle(20);
    h_corrected_outside_cos_theta_star_L0_L0bar->SetMarkerColor(kBlue);
    h_corrected_outside_cos_theta_star_L0_L0bar->SetTitle("Corrected #Lambda#bar{#Lambda} Pairs outside #DeltaR=0.93; cos(#theta*); dN/dCos(#theta*)"); 
    h_corrected_outside_cos_theta_star_L0_L0bar->GetXaxis()->CenterTitle();
    h_corrected_outside_cos_theta_star_L0_L0bar->GetYaxis()->CenterTitle();
    h_corrected_outside_cos_theta_star_L0_L0bar->Draw("PE");

    fit_corrected_outside_cos_theta_star_L0_L0bar->SetLineColor(kRed);
    fit_corrected_outside_cos_theta_star_L0_L0bar->Draw("same");

    TLegend *legend_correct_14 = new TLegend(0.15, 0.3, 0.4, 0.4);
    legend_correct_14->SetBorderSize(1);    
    legend_correct_14->SetTextSize(0.03);   
    legend_correct_14->SetBorderSize(0);
    legend_correct_14->SetFillStyle(0); 
    legend_correct_14->AddEntry(h_corrected_outside_cos_theta_star_L0_L0bar, "#Lambda#bar{#Lambda}", "p");
    legend_correct_14->AddEntry(fit_corrected_outside_cos_theta_star_L0_L0bar, "Fit");
    legend_correct_14->Draw();

    c1->Update(); 
    c2->Update(); 
    c3->Update(); 
    c4->Update();
    c5->Update();
    c6->Update();
    c7->Update();
    c8->Update();
    c9->Update();
    c10->Update();

    c1->WaitPrimitive(); 
    c2->WaitPrimitive(); 
    c3->WaitPrimitive(); 
    c4->WaitPrimitive();
    c5->WaitPrimitive();
    c6->WaitPrimitive();
    c7->WaitPrimitive();
    c8->WaitPrimitive();
    c9->WaitPrimitive();
    c10->WaitPrimitive();
}