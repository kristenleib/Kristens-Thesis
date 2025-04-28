#include <TFile.h>
#include <TH1.h>
#include <TCanvas.h>
#include <iostream>
#include <TGraph.h>

void lambda_Au_Au_2sig_comparisons() {
    TFile *file2 = TFile::Open("gold_outputs_2sig_0_10.root", "READ");
    TFile *file3 = TFile::Open("gold_outputs_2sig_10_40.root", "READ");
    TFile *file4 = TFile::Open("gold_outputs_2sig_40_80.root", "READ");

    if (!file2 || file2->IsZombie()) {
        std::cerr << "Error: Cannot open file2!" << std::endl;
        return;
    }

    if (!file3 || file3->IsZombie()) {
        std::cerr << "Error: Cannot open file3!" << std::endl;
        return;
    }

    if (!file4 || file4->IsZombie()) {
        std::cerr << "Error: Cannot open file4!" << std::endl;
        return;
    }

    // 0-10% Centrality Data
    TH2F *h_cos_theta_star_0_10 = (TH2F*)file2->Get("h_cos_theta_star");
    TH2F *h_cos_theta_star2_0_10 = (TH2F*)file2->Get("h_cos_theta_star2");
    TH2F *h_cos_theta_star3_0_10 = (TH2F*)file2->Get("h_cos_theta_star3");
    TH2F *h_cos_theta_star4_0_10 = (TH2F*)file2->Get("h_cos_theta_star4");
    TH2F *h_cos_theta_star5_0_10 = (TH2F*)file2->Get("h_cos_theta_star5");
    TH2F *h_cos_theta_star6_0_10 = (TH2F*)file2->Get("h_cos_theta_star6");

    TH2F *h_outside_cos_theta_star_0_10 = (TH2F*)file2->Get("h_outside_cos_theta_star");
    TH2F *h_outside_cos_theta_star2_0_10 = (TH2F*)file2->Get("h_outside_cos_theta_star2");
    TH2F *h_outside_cos_theta_star3_0_10 = (TH2F*)file2->Get("h_outside_cos_theta_star3");
    TH2F *h_outside_cos_theta_star4_0_10 = (TH2F*)file2->Get("h_outside_cos_theta_star4");
    TH2F *h_outside_cos_theta_star5_0_10 = (TH2F*)file2->Get("h_outside_cos_theta_star5");
    TH2F *h_outside_cos_theta_star6_0_10 = (TH2F*)file2->Get("h_outside_cos_theta_star6");

    TH2F *h_ME_cos_theta_star_0_10 = (TH2F*)file2->Get("h_ME_cos_theta_star");
    TH2F *h_ME_cos_theta_star2_0_10 = (TH2F*)file2->Get("h_ME_cos_theta_star2");
    TH2F *h_ME_cos_theta_star3_0_10 = (TH2F*)file2->Get("h_ME_cos_theta_star3");
    TH2F *h_ME_cos_theta_star4_0_10 = (TH2F*)file2->Get("h_ME_cos_theta_star4");
    TH2F *h_ME_cos_theta_star5_0_10 = (TH2F*)file2->Get("h_ME_cos_theta_star5");
    TH2F *h_ME_cos_theta_star6_0_10 = (TH2F*)file2->Get("h_ME_cos_theta_star6");

    TH2F *h_outside_ME_cos_theta_star_0_10 = (TH2F*)file2->Get("h_outside_ME_cos_theta_star");
    TH2F *h_outside_ME_cos_theta_star2_0_10 = (TH2F*)file2->Get("h_outside_ME_cos_theta_star2");
    TH2F *h_outside_ME_cos_theta_star3_0_10 = (TH2F*)file2->Get("h_outside_ME_cos_theta_star3");
    TH2F *h_outside_ME_cos_theta_star4_0_10 = (TH2F*)file2->Get("h_outside_ME_cos_theta_star4");
    TH2F *h_outside_ME_cos_theta_star5_0_10 = (TH2F*)file2->Get("h_outside_ME_cos_theta_star5");
    TH2F *h_outside_ME_cos_theta_star6_0_10 = (TH2F*)file2->Get("h_outside_ME_cos_theta_star6");

    // // 10-40% Centrality Data
    TH2F *h_cos_theta_star_10_40 = (TH2F*)file3->Get("h_cos_theta_star");
    TH2F *h_cos_theta_star2_10_40 = (TH2F*)file3->Get("h_cos_theta_star2");
    TH2F *h_cos_theta_star3_10_40 = (TH2F*)file3->Get("h_cos_theta_star3");
    TH2F *h_cos_theta_star4_10_40 = (TH2F*)file3->Get("h_cos_theta_star4");
    TH2F *h_cos_theta_star5_10_40 = (TH2F*)file3->Get("h_cos_theta_star5");
    TH2F *h_cos_theta_star6_10_40 = (TH2F*)file3->Get("h_cos_theta_star6");

    TH2F *h_outside_cos_theta_star_10_40 = (TH2F*)file3->Get("h_outside_cos_theta_star");
    TH2F *h_outside_cos_theta_star2_10_40 = (TH2F*)file3->Get("h_outside_cos_theta_star2");
    TH2F *h_outside_cos_theta_star3_10_40 = (TH2F*)file3->Get("h_outside_cos_theta_star3");
    TH2F *h_outside_cos_theta_star4_10_40 = (TH2F*)file3->Get("h_outside_cos_theta_star4");
    TH2F *h_outside_cos_theta_star5_10_40 = (TH2F*)file3->Get("h_outside_cos_theta_star5");
    TH2F *h_outside_cos_theta_star6_10_40 = (TH2F*)file3->Get("h_outside_cos_theta_star6");

    TH2F *h_ME_cos_theta_star_10_40 = (TH2F*)file3->Get("h_ME_cos_theta_star");
    TH2F *h_ME_cos_theta_star2_10_40 = (TH2F*)file3->Get("h_ME_cos_theta_star2");
    TH2F *h_ME_cos_theta_star3_10_40 = (TH2F*)file3->Get("h_ME_cos_theta_star3");
    TH2F *h_ME_cos_theta_star4_10_40 = (TH2F*)file3->Get("h_ME_cos_theta_star4");
    TH2F *h_ME_cos_theta_star5_10_40 = (TH2F*)file3->Get("h_ME_cos_theta_star5");
    TH2F *h_ME_cos_theta_star6_10_40 = (TH2F*)file3->Get("h_ME_cos_theta_star6");

    TH2F *h_outside_ME_cos_theta_star_10_40 = (TH2F*)file3->Get("h_outside_ME_cos_theta_star");
    TH2F *h_outside_ME_cos_theta_star2_10_40 = (TH2F*)file3->Get("h_outside_ME_cos_theta_star2");
    TH2F *h_outside_ME_cos_theta_star3_10_40 = (TH2F*)file3->Get("h_outside_ME_cos_theta_star3");
    TH2F *h_outside_ME_cos_theta_star4_10_40 = (TH2F*)file3->Get("h_outside_ME_cos_theta_star4");
    TH2F *h_outside_ME_cos_theta_star5_10_40 = (TH2F*)file3->Get("h_outside_ME_cos_theta_star5");
    TH2F *h_outside_ME_cos_theta_star6_10_40 = (TH2F*)file3->Get("h_outside_ME_cos_theta_star6");

    // 40-80% Centrality Data
    TH2F *h_cos_theta_star_40_80 = (TH2F*)file4->Get("h_cos_theta_star");
    TH2F *h_cos_theta_star2_40_80 = (TH2F*)file4->Get("h_cos_theta_star2");
    TH2F *h_cos_theta_star3_40_80 = (TH2F*)file4->Get("h_cos_theta_star3");
    TH2F *h_cos_theta_star4_40_80 = (TH2F*)file4->Get("h_cos_theta_star4");
    TH2F *h_cos_theta_star5_40_80 = (TH2F*)file4->Get("h_cos_theta_star5");
    TH2F *h_cos_theta_star6_40_80 = (TH2F*)file4->Get("h_cos_theta_star6");

    TH2F *h_outside_cos_theta_star_40_80 = (TH2F*)file4->Get("h_outside_cos_theta_star");
    TH2F *h_outside_cos_theta_star2_40_80 = (TH2F*)file4->Get("h_outside_cos_theta_star2");
    TH2F *h_outside_cos_theta_star3_40_80 = (TH2F*)file4->Get("h_outside_cos_theta_star3");
    TH2F *h_outside_cos_theta_star4_40_80 = (TH2F*)file4->Get("h_outside_cos_theta_star4");
    TH2F *h_outside_cos_theta_star5_40_80 = (TH2F*)file4->Get("h_outside_cos_theta_star5");
    TH2F *h_outside_cos_theta_star6_40_80 = (TH2F*)file4->Get("h_outside_cos_theta_star6");

    TH2F *h_ME_cos_theta_star_40_80 = (TH2F*)file4->Get("h_ME_cos_theta_star");
    TH2F *h_ME_cos_theta_star2_40_80 = (TH2F*)file4->Get("h_ME_cos_theta_star2");
    TH2F *h_ME_cos_theta_star3_40_80 = (TH2F*)file4->Get("h_ME_cos_theta_star3");
    TH2F *h_ME_cos_theta_star4_40_80 = (TH2F*)file4->Get("h_ME_cos_theta_star4");
    TH2F *h_ME_cos_theta_star5_40_80 = (TH2F*)file4->Get("h_ME_cos_theta_star5");
    TH2F *h_ME_cos_theta_star6_40_80 = (TH2F*)file4->Get("h_ME_cos_theta_star6");

    TH2F *h_outside_ME_cos_theta_star_40_80 = (TH2F*)file4->Get("h_outside_ME_cos_theta_star");
    TH2F *h_outside_ME_cos_theta_star2_40_80 = (TH2F*)file4->Get("h_outside_ME_cos_theta_star2");
    TH2F *h_outside_ME_cos_theta_star3_40_80 = (TH2F*)file4->Get("h_outside_ME_cos_theta_star3");
    TH2F *h_outside_ME_cos_theta_star4_40_80 = (TH2F*)file4->Get("h_outside_ME_cos_theta_star4");
    TH2F *h_outside_ME_cos_theta_star5_40_80 = (TH2F*)file4->Get("h_outside_ME_cos_theta_star5");
    TH2F *h_outside_ME_cos_theta_star6_40_80 = (TH2F*)file4->Get("h_outside_ME_cos_theta_star6");


    TCanvas *c1 = new TCanvas("c1", "c1- SE Distributions (0-10% Centrality)", 1800, 900);
    c1->Divide(3,2);

    c1->cd(1);
    h_cos_theta_star3_0_10->SetStats(0);
    h_cos_theta_star3_0_10->SetMinimum(0);
    h_cos_theta_star3_0_10->SetMarkerStyle(20);
    h_cos_theta_star3_0_10->SetMarkerColor(kBlue);
    h_cos_theta_star3_0_10->SetTitle("SE #Lambda#bar{#Lambda} Pairs inside #DeltaR = 0.93 (0-10%); cos(#theta*); dN/dCos(#theta*)"); 
    h_cos_theta_star3_0_10->GetXaxis()->CenterTitle();
    h_cos_theta_star3_0_10->GetYaxis()->CenterTitle();

    h_cos_theta_star4_0_10->SetStats(0);
    h_cos_theta_star4_0_10->SetMinimum(0);
    h_cos_theta_star4_0_10->SetMarkerStyle(20);
    h_cos_theta_star4_0_10->SetMarkerColor(kRed);
    h_cos_theta_star4_0_10->SetLineColor(kRed);

    h_cos_theta_star3_0_10->Draw("PE");
    h_cos_theta_star4_0_10->Draw("PE same");

    c1->cd(2);
    h_cos_theta_star_0_10->SetStats(0);
    h_cos_theta_star_0_10->SetMinimum(0);
    h_cos_theta_star_0_10->SetMarkerStyle(20);
    h_cos_theta_star_0_10->SetMarkerColor(kBlue);
    h_cos_theta_star_0_10->SetTitle("SE #Lambda#Lambda Pairs inside #DeltaR = 0.93 (0-10%); cos(#theta*); dN/dCos(#theta*)"); 
    h_cos_theta_star_0_10->GetXaxis()->CenterTitle();
    h_cos_theta_star_0_10->GetYaxis()->CenterTitle();

    h_cos_theta_star2_0_10->SetStats(0);
    h_cos_theta_star2_0_10->SetMinimum(0);
    h_cos_theta_star2_0_10->SetMarkerStyle(20);
    h_cos_theta_star2_0_10->SetMarkerColor(kRed);
    h_cos_theta_star2_0_10->SetLineColor(kRed);

    h_cos_theta_star_0_10->Draw("PE");
    h_cos_theta_star2_0_10->Draw("PE same");

    c1->cd(3);
    h_cos_theta_star5_0_10->SetStats(0);
    h_cos_theta_star5_0_10->SetMinimum(0);
    h_cos_theta_star5_0_10->SetMarkerStyle(20);
    h_cos_theta_star5_0_10->SetMarkerColor(kBlue);
    h_cos_theta_star5_0_10->SetTitle("SE #bar{#Lambda}#bar{#Lambda} Pairs inside #DeltaR = 0.93 (0-10%); cos(#theta*); dN/dCos(#theta*)"); 
    h_cos_theta_star5_0_10->GetXaxis()->CenterTitle();
    h_cos_theta_star5_0_10->GetYaxis()->CenterTitle();

    h_cos_theta_star6_0_10->SetStats(0);
    h_cos_theta_star6_0_10->SetMinimum(0);
    h_cos_theta_star6_0_10->SetMarkerStyle(20);
    h_cos_theta_star6_0_10->SetMarkerColor(kRed);
    h_cos_theta_star6_0_10->SetLineColor(kRed);

    h_cos_theta_star5_0_10->Draw("PE"); 
    h_cos_theta_star6_0_10->Draw("PE same");

    c1->cd(4);
    h_outside_cos_theta_star3_0_10->SetStats(0);
    h_outside_cos_theta_star3_0_10->SetMinimum(0);
    h_outside_cos_theta_star3_0_10->SetMarkerStyle(20);
    h_outside_cos_theta_star3_0_10->SetMarkerColor(kBlue);
    h_outside_cos_theta_star3_0_10->SetTitle("SE #Lambda#bar{#Lambda} Pairs outside #DeltaR = 0.93 (0-10%); cos(#theta*); dN/dCos(#theta*)"); 
    h_outside_cos_theta_star3_0_10->GetXaxis()->CenterTitle();
    h_outside_cos_theta_star3_0_10->GetYaxis()->CenterTitle();

    h_outside_cos_theta_star4_0_10->SetStats(0);
    h_outside_cos_theta_star4_0_10->SetMinimum(0);
    h_outside_cos_theta_star4_0_10->SetMarkerStyle(20);
    h_outside_cos_theta_star4_0_10->SetMarkerColor(kRed);
    h_outside_cos_theta_star4_0_10->SetLineColor(kRed);

    h_outside_cos_theta_star3_0_10->Draw("PE");
    h_outside_cos_theta_star4_0_10->Draw("PE same");

    c1->cd(5);
    h_outside_cos_theta_star_0_10->SetStats(0);
    h_outside_cos_theta_star_0_10->SetMinimum(0);
    h_outside_cos_theta_star_0_10->SetMarkerStyle(20);
    h_outside_cos_theta_star_0_10->SetMarkerColor(kBlue);
    h_outside_cos_theta_star_0_10->SetTitle("SE #Lambda#Lambda Pairs outside #DeltaR = 0.93 (0-10%); cos(#theta*); dN/dCos(#theta*)"); 
    h_outside_cos_theta_star_0_10->GetXaxis()->CenterTitle();
    h_outside_cos_theta_star_0_10->GetYaxis()->CenterTitle();

    h_outside_cos_theta_star2_0_10->SetStats(0);
    h_outside_cos_theta_star2_0_10->SetMinimum(0);
    h_outside_cos_theta_star2_0_10->SetMarkerStyle(20);
    h_outside_cos_theta_star2_0_10->SetMarkerColor(kRed);
    h_outside_cos_theta_star2_0_10->SetLineColor(kRed);

    h_outside_cos_theta_star_0_10->Draw("PE");
    h_outside_cos_theta_star2_0_10->Draw("PE same");

    c1->cd(6);
    h_outside_cos_theta_star5_0_10->SetStats(0);
    h_outside_cos_theta_star5_0_10->SetMinimum(0);
    h_outside_cos_theta_star5_0_10->SetMarkerStyle(20);
    h_outside_cos_theta_star5_0_10->SetMarkerColor(kBlue);
    h_outside_cos_theta_star5_0_10->SetTitle("SE #bar{#Lambda}#bar{#Lambda} Pairs outside #DeltaR = 0.93 (0-10%); cos(#theta*); dN/dCos(#theta*)"); 
    h_outside_cos_theta_star5_0_10->GetXaxis()->CenterTitle();
    h_outside_cos_theta_star5_0_10->GetYaxis()->CenterTitle();

    h_outside_cos_theta_star6_0_10->SetStats(0);
    h_outside_cos_theta_star6_0_10->SetMinimum(0);
    h_outside_cos_theta_star6_0_10->SetMarkerStyle(20);
    h_outside_cos_theta_star6_0_10->SetMarkerColor(kRed);
    h_outside_cos_theta_star6_0_10->SetLineColor(kRed);

    h_outside_cos_theta_star5_0_10->Draw("PE");
    h_outside_cos_theta_star6_0_10->Draw("PE same");

    std::cout << "Canvas 1 Complete" << std::endl;

    TCanvas *c2 = new TCanvas("c2", "c2- SE Distributions (10-40% Centrality)", 1800, 900);
    c2->Divide(3,2);

    c2->cd(1);
    h_cos_theta_star3_10_40->SetStats(0);
    h_cos_theta_star3_10_40->SetMinimum(0);
    h_cos_theta_star3_10_40->SetMarkerStyle(20);
    h_cos_theta_star3_10_40->SetMarkerColor(kBlue);
    h_cos_theta_star3_10_40->SetTitle("SE #Lambda#bar{#Lambda} Pairs inside #DeltaR = 0.93 (10-40%); cos(#theta*); dN/dCos(#theta*)"); 
    h_cos_theta_star3_10_40->GetXaxis()->CenterTitle();
    h_cos_theta_star3_10_40->GetYaxis()->CenterTitle();

    h_cos_theta_star4_10_40->SetStats(0);
    h_cos_theta_star4_10_40->SetMinimum(0);
    h_cos_theta_star4_10_40->SetMarkerStyle(20);
    h_cos_theta_star4_10_40->SetMarkerColor(kRed);
    h_cos_theta_star4_10_40->SetLineColor(kRed);

    h_cos_theta_star3_10_40->Draw("PE");
    h_cos_theta_star4_10_40->Draw("PE same");

    c2->cd(2);
    h_cos_theta_star_10_40->SetStats(0);
    h_cos_theta_star_10_40->SetMinimum(0);
    h_cos_theta_star_10_40->SetMarkerStyle(20);
    h_cos_theta_star_10_40->SetMarkerColor(kBlue);
    h_cos_theta_star_10_40->SetTitle("SE #Lambda#Lambda Pairs inside #DeltaR = 0.93 (10-40%); cos(#theta*); dN/dCos(#theta*)"); 
    h_cos_theta_star_10_40->GetXaxis()->CenterTitle();
    h_cos_theta_star_10_40->GetYaxis()->CenterTitle();

    h_cos_theta_star2_10_40->SetStats(0);
    h_cos_theta_star2_10_40->SetMinimum(0);
    h_cos_theta_star2_10_40->SetMarkerStyle(20);
    h_cos_theta_star2_10_40->SetMarkerColor(kRed);
    h_cos_theta_star2_10_40->SetLineColor(kRed);

    h_cos_theta_star_10_40->Draw("PE");
    h_cos_theta_star2_10_40->Draw("PE same");

    c2->cd(3);
    h_cos_theta_star5_10_40->SetStats(0);
    h_cos_theta_star5_10_40->SetMinimum(0);
    h_cos_theta_star5_10_40->SetMarkerStyle(20);
    h_cos_theta_star5_10_40->SetMarkerColor(kBlue);
    h_cos_theta_star5_10_40->SetTitle("SE #bar{#Lambda}#bar{#Lambda} Pairs inside #DeltaR = 0.93 (10-40%); cos(#theta*); dN/dCos(#theta*)"); 
    h_cos_theta_star5_10_40->GetXaxis()->CenterTitle();
    h_cos_theta_star5_10_40->GetYaxis()->CenterTitle();

    h_cos_theta_star6_10_40->SetStats(0);
    h_cos_theta_star6_10_40->SetMinimum(0);
    h_cos_theta_star6_10_40->SetMarkerStyle(20);
    h_cos_theta_star6_10_40->SetMarkerColor(kRed);
    h_cos_theta_star6_10_40->SetLineColor(kRed);

    h_cos_theta_star5_10_40->Draw("PE"); 
    h_cos_theta_star6_10_40->Draw("PE same");

    c2->cd(4);
    h_outside_cos_theta_star3_10_40->SetStats(0);
    h_outside_cos_theta_star3_10_40->SetMinimum(0);
    h_outside_cos_theta_star3_10_40->SetMarkerStyle(20);
    h_outside_cos_theta_star3_10_40->SetMarkerColor(kBlue);
    h_outside_cos_theta_star3_10_40->SetTitle("SE #Lambda#bar{#Lambda} Pairs outside #DeltaR = 0.93 (10-40%); cos(#theta*); dN/dCos(#theta*)"); 
    h_outside_cos_theta_star3_10_40->GetXaxis()->CenterTitle();
    h_outside_cos_theta_star3_10_40->GetYaxis()->CenterTitle();

    h_outside_cos_theta_star4_10_40->SetStats(0);
    h_outside_cos_theta_star4_10_40->SetMinimum(0);
    h_outside_cos_theta_star4_10_40->SetMarkerStyle(20);
    h_outside_cos_theta_star4_10_40->SetMarkerColor(kRed);
    h_outside_cos_theta_star4_10_40->SetLineColor(kRed);

    h_outside_cos_theta_star3_10_40->Draw("PE");
    h_outside_cos_theta_star4_10_40->Draw("PE same");

    c2->cd(5);
    h_outside_cos_theta_star_10_40->SetStats(0);
    h_outside_cos_theta_star_10_40->SetMinimum(0);
    h_outside_cos_theta_star_10_40->SetMarkerStyle(20);
    h_outside_cos_theta_star_10_40->SetMarkerColor(kBlue);
    h_outside_cos_theta_star_10_40->SetTitle("SE #Lambda#Lambda Pairs outside #DeltaR = 0.93 (10-40%); cos(#theta*); dN/dCos(#theta*)"); 
    h_outside_cos_theta_star_10_40->GetXaxis()->CenterTitle();
    h_outside_cos_theta_star_10_40->GetYaxis()->CenterTitle();

    h_outside_cos_theta_star2_10_40->SetStats(0);
    h_outside_cos_theta_star2_10_40->SetMinimum(0);
    h_outside_cos_theta_star2_10_40->SetMarkerStyle(20);
    h_outside_cos_theta_star2_10_40->SetMarkerColor(kRed);
    h_outside_cos_theta_star2_10_40->SetLineColor(kRed);

    h_outside_cos_theta_star_10_40->Draw("PE");
    h_outside_cos_theta_star2_10_40->Draw("PE same");

    c2->cd(6);
    h_outside_cos_theta_star5_10_40->SetStats(0);
    h_outside_cos_theta_star5_10_40->SetMinimum(0);
    h_outside_cos_theta_star5_10_40->SetMarkerStyle(20);
    h_outside_cos_theta_star5_10_40->SetMarkerColor(kBlue);
    h_outside_cos_theta_star5_10_40->SetTitle("SE #bar{#Lambda}#bar{#Lambda} Pairs outside #DeltaR = 0.93 (10-40%); cos(#theta*); dN/dCos(#theta*)"); 
    h_outside_cos_theta_star5_10_40->GetXaxis()->CenterTitle();
    h_outside_cos_theta_star5_10_40->GetYaxis()->CenterTitle();

    h_outside_cos_theta_star6_10_40->SetStats(0);
    h_outside_cos_theta_star6_10_40->SetMinimum(0);
    h_outside_cos_theta_star6_10_40->SetMarkerStyle(20);
    h_outside_cos_theta_star6_10_40->SetMarkerColor(kRed);
    h_outside_cos_theta_star6_10_40->SetLineColor(kRed);

    h_outside_cos_theta_star5_10_40->Draw("PE");
    h_outside_cos_theta_star6_10_40->Draw("PE same");

    std::cout << "Canvas 2 Complete" << std::endl;

    TCanvas *c3 = new TCanvas("c3", "c3- SE Distributions (40-80% Centrality)", 1800, 900);
    c3->Divide(3,2);

    c3->cd(1);
    h_cos_theta_star3_40_80->SetStats(0);
    h_cos_theta_star3_40_80->SetMinimum(0);
    h_cos_theta_star3_40_80->SetMarkerStyle(20);
    h_cos_theta_star3_40_80->SetMarkerColor(kBlue);
    h_cos_theta_star3_40_80->SetTitle("SE #Lambda#bar{#Lambda} Pairs inside #DeltaR = 0.93 (40-80%); cos(#theta*); dN/dCos(#theta*)"); 
    h_cos_theta_star3_40_80->GetXaxis()->CenterTitle();
    h_cos_theta_star3_40_80->GetYaxis()->CenterTitle();

    h_cos_theta_star4_40_80->SetStats(0);
    h_cos_theta_star4_40_80->SetMinimum(0);
    h_cos_theta_star4_40_80->SetMarkerStyle(20);
    h_cos_theta_star4_40_80->SetMarkerColor(kRed);
    h_cos_theta_star4_40_80->SetLineColor(kRed);

    h_cos_theta_star3_40_80->Draw("PE");
    h_cos_theta_star4_40_80->Draw("PE same");

    c3->cd(2);
    h_cos_theta_star_40_80->SetStats(0);
    h_cos_theta_star_40_80->SetMinimum(0);
    h_cos_theta_star_40_80->SetMarkerStyle(20);
    h_cos_theta_star_40_80->SetMarkerColor(kBlue);
    h_cos_theta_star_40_80->SetTitle("SE #Lambda#Lambda Pairs inside #DeltaR = 0.93 (40-80%); cos(#theta*); dN/dCos(#theta*)"); 
    h_cos_theta_star_40_80->GetXaxis()->CenterTitle();
    h_cos_theta_star_40_80->GetYaxis()->CenterTitle();

    h_cos_theta_star2_40_80->SetStats(0);
    h_cos_theta_star2_40_80->SetMinimum(0);
    h_cos_theta_star2_40_80->SetMarkerStyle(20);
    h_cos_theta_star2_40_80->SetMarkerColor(kRed);
    h_cos_theta_star2_40_80->SetLineColor(kRed);

    h_cos_theta_star_40_80->Draw("PE");
    h_cos_theta_star2_40_80->Draw("PE same");

    c3->cd(3);
    h_cos_theta_star5_40_80->SetStats(0);
    h_cos_theta_star5_40_80->SetMinimum(0);
    h_cos_theta_star5_40_80->SetMarkerStyle(20);
    h_cos_theta_star5_40_80->SetMarkerColor(kBlue);
    h_cos_theta_star5_40_80->SetTitle("SE #bar{#Lambda}#bar{#Lambda} Pairs inside #DeltaR = 0.93 (40-80%); cos(#theta*); dN/dCos(#theta*)"); 
    h_cos_theta_star5_40_80->GetXaxis()->CenterTitle();
    h_cos_theta_star5_40_80->GetYaxis()->CenterTitle();

    h_cos_theta_star6_40_80->SetStats(0);
    h_cos_theta_star6_40_80->SetMinimum(0);
    h_cos_theta_star6_40_80->SetMarkerStyle(20);
    h_cos_theta_star6_40_80->SetMarkerColor(kRed);
    h_cos_theta_star6_40_80->SetLineColor(kRed);

    h_cos_theta_star5_40_80->Draw("PE"); 
    h_cos_theta_star6_40_80->Draw("PE same");

    c3->cd(4);
    h_outside_cos_theta_star3_40_80->SetStats(0);
    h_outside_cos_theta_star3_40_80->SetMinimum(0);
    h_outside_cos_theta_star3_40_80->SetMarkerStyle(20);
    h_outside_cos_theta_star3_40_80->SetMarkerColor(kBlue);
    h_outside_cos_theta_star3_40_80->SetTitle("SE #Lambda#bar{#Lambda} Pairs outside #DeltaR = 0.93 (40-80%); cos(#theta*); dN/dCos(#theta*)"); 
    h_outside_cos_theta_star3_40_80->GetXaxis()->CenterTitle();
    h_outside_cos_theta_star3_40_80->GetYaxis()->CenterTitle();

    h_outside_cos_theta_star4_40_80->SetStats(0);
    h_outside_cos_theta_star4_40_80->SetMinimum(0);
    h_outside_cos_theta_star4_40_80->SetMarkerStyle(20);
    h_outside_cos_theta_star4_40_80->SetMarkerColor(kRed);
    h_outside_cos_theta_star4_40_80->SetLineColor(kRed);

    h_outside_cos_theta_star3_40_80->Draw("PE");
    h_outside_cos_theta_star4_40_80->Draw("PE same");

    c3->cd(5);
    h_outside_cos_theta_star_40_80->SetStats(0);
    h_outside_cos_theta_star_40_80->SetMinimum(0);
    h_outside_cos_theta_star_40_80->SetMarkerStyle(20);
    h_outside_cos_theta_star_40_80->SetMarkerColor(kBlue);
    h_outside_cos_theta_star_40_80->SetTitle("SE #Lambda#Lambda Pairs outside #DeltaR = 0.93 (40-80%); cos(#theta*); dN/dCos(#theta*)"); 
    h_outside_cos_theta_star_40_80->GetXaxis()->CenterTitle();
    h_outside_cos_theta_star_40_80->GetYaxis()->CenterTitle();

    h_outside_cos_theta_star2_40_80->SetStats(0);
    h_outside_cos_theta_star2_40_80->SetMinimum(0);
    h_outside_cos_theta_star2_40_80->SetMarkerStyle(20);
    h_outside_cos_theta_star2_40_80->SetMarkerColor(kRed);
    h_outside_cos_theta_star2_40_80->SetLineColor(kRed);

    h_outside_cos_theta_star_40_80->Draw("PE");
    h_outside_cos_theta_star2_40_80->Draw("PE same");

    c3->cd(6);
    h_outside_cos_theta_star5_40_80->SetStats(0);
    h_outside_cos_theta_star5_40_80->SetMinimum(0);
    h_outside_cos_theta_star5_40_80->SetMarkerStyle(20);
    h_outside_cos_theta_star5_40_80->SetMarkerColor(kBlue);
    h_outside_cos_theta_star5_40_80->SetTitle("SE #bar{#Lambda}#bar{#Lambda} Pairs outside #DeltaR = 0.93 (40-80%); cos(#theta*); dN/dCos(#theta*)"); 
    h_outside_cos_theta_star5_40_80->GetXaxis()->CenterTitle();
    h_outside_cos_theta_star5_40_80->GetYaxis()->CenterTitle();

    h_outside_cos_theta_star6_40_80->SetStats(0);
    h_outside_cos_theta_star6_40_80->SetMinimum(0);
    h_outside_cos_theta_star6_40_80->SetMarkerStyle(20);
    h_outside_cos_theta_star6_40_80->SetMarkerColor(kRed);
    h_outside_cos_theta_star6_40_80->SetLineColor(kRed);

    h_outside_cos_theta_star5_40_80->Draw("PE");
    h_outside_cos_theta_star6_40_80->Draw("PE same");

    std::cout << "Canvas 3 Complete" << std::endl;

    cout << "   " << endl;
    cout << "** Kristen's dN/dCos(theta*) distributions with the normalization applied (0-10% Centrality Cut) **" << endl;
    cout << "   " << endl;

    double counts_cos_theta_star_0_10 = h_cos_theta_star_0_10->Integral();
    double counts_cos_theta_star2_0_10 = h_cos_theta_star2_0_10->Integral();
    double counts_cos_theta_star3_0_10 = h_cos_theta_star3_0_10->Integral();
    double counts_cos_theta_star4_0_10 = h_cos_theta_star4_0_10->Integral();
    double counts_cos_theta_star5_0_10 = h_cos_theta_star5_0_10->Integral();
    double counts_cos_theta_star6_0_10 = h_cos_theta_star6_0_10->Integral();

    cout << "Kristen's Data: Counts inside the delta_R cut" << endl;
    cout << "US-US L0-L0: " << counts_cos_theta_star_0_10 << endl;
    cout << "US-LS L0-L0: " << counts_cos_theta_star2_0_10 << endl;
    cout << "US-US L0-L0bar: " << counts_cos_theta_star3_0_10 << endl;
    cout << "US-LS L0-L0bar: " << counts_cos_theta_star4_0_10 << endl;
    cout << "US-US L0bar-L0bar: " << counts_cos_theta_star5_0_10 << endl;
    cout << "US-LS L0bar-L0bar: " << counts_cos_theta_star6_0_10 << endl;

    double counts_outside_cos_theta_star_0_10 = h_outside_cos_theta_star_0_10->Integral();
    double counts_outside_cos_theta_star2_0_10 = h_outside_cos_theta_star2_0_10->Integral();
    double counts_outside_cos_theta_star3_0_10 = h_outside_cos_theta_star3_0_10->Integral();
    double counts_outside_cos_theta_star4_0_10 = h_outside_cos_theta_star4_0_10->Integral();
    double counts_outside_cos_theta_star5_0_10 = h_outside_cos_theta_star5_0_10->Integral();
    double counts_outside_cos_theta_star6_0_10 = h_outside_cos_theta_star6_0_10->Integral();

    cout << "   " << endl;
    cout << "Kristen's Data: Counts outside the delta_R cut" << endl;
    cout << "US-US L0-L0: " << counts_outside_cos_theta_star_0_10 << endl;
    cout << "US-LS L0-L0: " << counts_outside_cos_theta_star2_0_10 << endl;
    cout << "US-US L0-L0bar: " << counts_outside_cos_theta_star3_0_10 << endl;
    cout << "US-LS L0-L0bar: " << counts_outside_cos_theta_star4_0_10 << endl;
    cout << "US-US L0bar-L0bar: " << counts_outside_cos_theta_star5_0_10 << endl;
    cout << "US-LS L0bar-L0bar: " << counts_outside_cos_theta_star6_0_10 << endl;

    cout << "   " << endl;
    cout << "** Kristen's dN/dCos(theta*) distributions with the normalization applied (10-40% Centrality Cut) **" << endl;
    cout << "   " << endl;

    double counts_cos_theta_star_10_40 = h_cos_theta_star_10_40->Integral();
    double counts_cos_theta_star2_10_40 = h_cos_theta_star2_10_40->Integral();
    double counts_cos_theta_star3_10_40 = h_cos_theta_star3_10_40->Integral();
    double counts_cos_theta_star4_10_40 = h_cos_theta_star4_10_40->Integral();
    double counts_cos_theta_star5_10_40 = h_cos_theta_star5_10_40->Integral();
    double counts_cos_theta_star6_10_40 = h_cos_theta_star6_10_40->Integral();

    cout << "Kristen's Data: Counts inside the delta_R cut" << endl;
    cout << "US-US L0-L0: " << counts_cos_theta_star_10_40 << endl;
    cout << "US-LS L0-L0: " << counts_cos_theta_star2_10_40 << endl;
    cout << "US-US L0-L0bar: " << counts_cos_theta_star3_10_40 << endl;
    cout << "US-LS L0-L0bar: " << counts_cos_theta_star4_10_40 << endl;
    cout << "US-US L0bar-L0bar: " << counts_cos_theta_star5_10_40 << endl;
    cout << "US-LS L0bar-L0bar: " << counts_cos_theta_star6_10_40 << endl;

    double counts_outside_cos_theta_star_10_40 = h_outside_cos_theta_star_10_40->Integral();
    double counts_outside_cos_theta_star2_10_40 = h_outside_cos_theta_star2_10_40->Integral();
    double counts_outside_cos_theta_star3_10_40 = h_outside_cos_theta_star3_10_40->Integral();
    double counts_outside_cos_theta_star4_10_40 = h_outside_cos_theta_star4_10_40->Integral();
    double counts_outside_cos_theta_star5_10_40 = h_outside_cos_theta_star5_10_40->Integral();
    double counts_outside_cos_theta_star6_10_40 = h_outside_cos_theta_star6_10_40->Integral();

    cout << "   " << endl;
    cout << "Kristen's Data: Counts outside the delta_R cut" << endl;
    cout << "US-US L0-L0: " << counts_outside_cos_theta_star_10_40 << endl;
    cout << "US-LS L0-L0: " << counts_outside_cos_theta_star2_10_40 << endl;
    cout << "US-US L0-L0bar: " << counts_outside_cos_theta_star3_10_40 << endl;
    cout << "US-LS L0-L0bar: " << counts_outside_cos_theta_star4_10_40 << endl;
    cout << "US-US L0bar-L0bar: " << counts_outside_cos_theta_star5_10_40 << endl;
    cout << "US-LS L0bar-L0bar: " << counts_outside_cos_theta_star6_10_40 << endl;

    cout << "   " << endl;
    cout << "** Kristen's dN/dCos(theta*) distributions with the normalization applied (40-80% Centrality Cut) **" << endl;
    cout << "   " << endl;

    double counts_cos_theta_star_40_80 = h_cos_theta_star_40_80->Integral();
    double counts_cos_theta_star2_40_80 = h_cos_theta_star2_40_80->Integral();
    double counts_cos_theta_star3_40_80 = h_cos_theta_star3_40_80->Integral();
    double counts_cos_theta_star4_40_80 = h_cos_theta_star4_40_80->Integral();
    double counts_cos_theta_star5_40_80 = h_cos_theta_star5_40_80->Integral();
    double counts_cos_theta_star6_40_80 = h_cos_theta_star6_40_80->Integral();

    cout << "Kristen's Data: Counts inside the delta_R cut" << endl;
    cout << "US-US L0-L0: " << counts_cos_theta_star_40_80 << endl;
    cout << "US-LS L0-L0: " << counts_cos_theta_star2_40_80 << endl;
    cout << "US-US L0-L0bar: " << counts_cos_theta_star3_40_80 << endl;
    cout << "US-LS L0-L0bar: " << counts_cos_theta_star4_40_80 << endl;
    cout << "US-US L0bar-L0bar: " << counts_cos_theta_star5_40_80 << endl;
    cout << "US-LS L0bar-L0bar: " << counts_cos_theta_star6_40_80 << endl;

    double counts_outside_cos_theta_star_40_80 = h_outside_cos_theta_star_40_80->Integral();
    double counts_outside_cos_theta_star2_40_80 = h_outside_cos_theta_star2_40_80->Integral();
    double counts_outside_cos_theta_star3_40_80 = h_outside_cos_theta_star3_40_80->Integral();
    double counts_outside_cos_theta_star4_40_80 = h_outside_cos_theta_star4_40_80->Integral();
    double counts_outside_cos_theta_star5_40_80 = h_outside_cos_theta_star5_40_80->Integral();
    double counts_outside_cos_theta_star6_40_80 = h_outside_cos_theta_star6_40_80->Integral();

    cout << "   " << endl;
    cout << "Kristen's Data: Counts outside the delta_R cut" << endl;
    cout << "US-US L0-L0: " << counts_outside_cos_theta_star_40_80 << endl;
    cout << "US-LS L0-L0: " << counts_outside_cos_theta_star2_40_80 << endl;
    cout << "US-US L0-L0bar: " << counts_outside_cos_theta_star3_40_80 << endl;
    cout << "US-LS L0-L0bar: " << counts_outside_cos_theta_star4_40_80 << endl;
    cout << "US-US L0bar-L0bar: " << counts_outside_cos_theta_star5_40_80 << endl;
    cout << "US-LS L0bar-L0bar: " << counts_outside_cos_theta_star6_40_80 << endl;

    TCanvas *c4 = new TCanvas("c4", "c4- ME Distributions (0-10% Centrality)", 1800, 900);
    c4->Divide(3,2);

    c4->cd(1);
    h_ME_cos_theta_star3_0_10->SetStats(0);
    h_ME_cos_theta_star3_0_10->SetMinimum(0);
    h_ME_cos_theta_star3_0_10->SetMarkerStyle(24);
    h_ME_cos_theta_star3_0_10->SetMarkerColor(kBlue);
    h_ME_cos_theta_star3_0_10->SetTitle("ME #Lambda#bar{#Lambda} Pairs Inside #DeltaR = 0.93 (0-10%); cos(#theta*); dN/dCos(#theta*)"); 
    h_ME_cos_theta_star3_0_10->GetXaxis()->CenterTitle();
    h_ME_cos_theta_star3_0_10->GetYaxis()->CenterTitle();

    h_ME_cos_theta_star4_0_10->SetStats(0);
    h_ME_cos_theta_star4_0_10->SetMinimum(0);
    h_ME_cos_theta_star4_0_10->SetMarkerStyle(24);
    h_ME_cos_theta_star4_0_10->SetMarkerColor(kRed);
    h_ME_cos_theta_star4_0_10->SetLineColor(kRed);

    h_ME_cos_theta_star3_0_10->Draw("PE");
    h_ME_cos_theta_star4_0_10->Draw("PE same");

    c4->cd(2);
    h_ME_cos_theta_star_0_10->SetStats(0);
    h_ME_cos_theta_star_0_10->SetMinimum(0);
    h_ME_cos_theta_star_0_10->SetMarkerStyle(24);
    h_ME_cos_theta_star_0_10->SetMarkerColor(kBlue);
    h_ME_cos_theta_star_0_10->SetTitle("SE #Lambda#Lambda Pairs Inside #DeltaR = 0.93 (0-10%); cos(#theta*); dN/dCos(#theta*)"); 
    h_ME_cos_theta_star_0_10->GetXaxis()->CenterTitle();
    h_ME_cos_theta_star_0_10->GetYaxis()->CenterTitle();

    h_ME_cos_theta_star2_0_10->SetStats(0);
    h_ME_cos_theta_star2_0_10->SetMinimum(0);
    h_ME_cos_theta_star2_0_10->SetMarkerStyle(24);
    h_ME_cos_theta_star2_0_10->SetMarkerColor(kRed);
    h_ME_cos_theta_star2_0_10->SetLineColor(kRed);

    h_ME_cos_theta_star_0_10->Draw("PE");
    h_ME_cos_theta_star2_0_10->Draw("PE same");

    c4->cd(3);
    h_ME_cos_theta_star5_0_10->SetStats(0);
    h_ME_cos_theta_star5_0_10->SetMinimum(0);
    h_ME_cos_theta_star5_0_10->SetMarkerStyle(24);
    h_ME_cos_theta_star5_0_10->SetMarkerColor(kBlue);
    h_ME_cos_theta_star5_0_10->SetTitle("ME #bar{#Lambda}#bar{#Lambda} Pairs Inside #DeltaR = 0.93 (0-10%); cos(#theta*); dN/dCos(#theta*)"); 
    h_ME_cos_theta_star5_0_10->GetXaxis()->CenterTitle();
    h_ME_cos_theta_star5_0_10->GetYaxis()->CenterTitle();

    h_ME_cos_theta_star6_0_10->SetStats(0);
    h_ME_cos_theta_star6_0_10->SetMinimum(0);
    h_ME_cos_theta_star6_0_10->SetMarkerStyle(24);
    h_ME_cos_theta_star6_0_10->SetMarkerColor(kRed);
    h_ME_cos_theta_star6_0_10->SetLineColor(kRed);

    h_ME_cos_theta_star5_0_10->Draw("PE");
    h_ME_cos_theta_star6_0_10->Draw("PE same");

    c4->cd(4);
    h_outside_ME_cos_theta_star3_0_10->SetStats(0);
    h_outside_ME_cos_theta_star3_0_10->SetMinimum(0);
    h_outside_ME_cos_theta_star3_0_10->SetMarkerStyle(24);
    h_outside_ME_cos_theta_star3_0_10->SetMarkerColor(kBlue);
    h_outside_ME_cos_theta_star3_0_10->SetTitle("ME #Lambda#bar{#Lambda} Pairs Outside #DeltaR = 0.93 (0-10%); cos(#theta*); dN/dCos(#theta*)"); 
    h_outside_ME_cos_theta_star3_0_10->GetXaxis()->CenterTitle();
    h_outside_ME_cos_theta_star3_0_10->GetYaxis()->CenterTitle();

    h_outside_ME_cos_theta_star4_0_10->SetStats(0);
    h_outside_ME_cos_theta_star4_0_10->SetMinimum(0);
    h_outside_ME_cos_theta_star4_0_10->SetMarkerStyle(24);
    h_outside_ME_cos_theta_star4_0_10->SetMarkerColor(kRed);
    h_outside_ME_cos_theta_star4_0_10->SetLineColor(kRed);

    h_outside_ME_cos_theta_star3_0_10->Draw("PE");
    h_outside_ME_cos_theta_star4_0_10->Draw("PE same");

    c4->cd(5);
    h_outside_ME_cos_theta_star_0_10->SetStats(0);
    h_outside_ME_cos_theta_star_0_10->SetMinimum(0);
    h_outside_ME_cos_theta_star_0_10->SetMarkerStyle(24);
    h_outside_ME_cos_theta_star_0_10->SetMarkerColor(kBlue);
    h_outside_ME_cos_theta_star_0_10->SetTitle("SE #Lambda#Lambda Pairs Outside #DeltaR = 0.93 (0-10%); cos(#theta*); dN/dCos(#theta*)"); 
    h_outside_ME_cos_theta_star_0_10->GetXaxis()->CenterTitle();
    h_outside_ME_cos_theta_star_0_10->GetYaxis()->CenterTitle();

    h_outside_ME_cos_theta_star2_0_10->SetStats(0);
    h_outside_ME_cos_theta_star2_0_10->SetMinimum(0);
    h_outside_ME_cos_theta_star2_0_10->SetMarkerStyle(24);
    h_outside_ME_cos_theta_star2_0_10->SetMarkerColor(kRed);
    h_outside_ME_cos_theta_star2_0_10->SetLineColor(kRed);

    h_outside_ME_cos_theta_star_0_10->Draw("PE");
    h_outside_ME_cos_theta_star2_0_10->Draw("PE same");

    c4->cd(6);
    h_outside_ME_cos_theta_star5_0_10->SetStats(0);
    h_outside_ME_cos_theta_star5_0_10->SetMinimum(0);
    h_outside_ME_cos_theta_star5_0_10->SetMarkerStyle(24);
    h_outside_ME_cos_theta_star5_0_10->SetMarkerColor(kBlue);
    h_outside_ME_cos_theta_star5_0_10->SetTitle("ME #bar{#Lambda}#bar{#Lambda} Pairs Outside #DeltaR = 0.93 (0-10%); cos(#theta*); dN/dCos(#theta*)"); 
    h_outside_ME_cos_theta_star5_0_10->GetXaxis()->CenterTitle();
    h_outside_ME_cos_theta_star5_0_10->GetYaxis()->CenterTitle();

    h_outside_ME_cos_theta_star6_0_10->SetStats(0);
    h_outside_ME_cos_theta_star6_0_10->SetMinimum(0);
    h_outside_ME_cos_theta_star6_0_10->SetMarkerStyle(24);
    h_outside_ME_cos_theta_star6_0_10->SetMarkerColor(kRed);
    h_outside_ME_cos_theta_star6_0_10->SetLineColor(kRed);

    h_outside_ME_cos_theta_star5_0_10->Draw("PE");
    h_outside_ME_cos_theta_star6_0_10->Draw("PE same");

    cout << "   " << endl;
    cout << "Canvas 4 Complete" << endl;

    TCanvas *c5 = new TCanvas("c5", "c5- ME Distributions (10-40% Centrality)", 1800, 900);
    c5->Divide(3,2);

    c5->cd(1);
    h_ME_cos_theta_star3_10_40->SetStats(0);
    h_ME_cos_theta_star3_10_40->SetMinimum(0);
    h_ME_cos_theta_star3_10_40->SetMarkerStyle(24);
    h_ME_cos_theta_star3_10_40->SetMarkerColor(kBlue);

    h_ME_cos_theta_star4_10_40->SetStats(0);
    h_ME_cos_theta_star4_10_40->SetMinimum(0);
    h_ME_cos_theta_star4_10_40->SetMarkerStyle(24);
    h_ME_cos_theta_star4_10_40->SetMarkerColor(kRed);
    h_ME_cos_theta_star4_10_40->SetLineColor(kRed);

    h_ME_cos_theta_star3_10_40->Draw("PE");
    h_ME_cos_theta_star4_10_40->Draw("PE same");

    c5->cd(2);
    h_ME_cos_theta_star_10_40->SetStats(0);
    h_ME_cos_theta_star_10_40->SetMinimum(0);
    h_ME_cos_theta_star_10_40->SetMarkerStyle(24);
    h_ME_cos_theta_star_10_40->SetMarkerColor(kBlue);

    h_ME_cos_theta_star2_10_40->SetStats(0);
    h_ME_cos_theta_star2_10_40->SetMinimum(0);
    h_ME_cos_theta_star2_10_40->SetMarkerStyle(24);
    h_ME_cos_theta_star2_10_40->SetMarkerColor(kRed);
    h_ME_cos_theta_star2_10_40->SetLineColor(kRed);

    h_ME_cos_theta_star_10_40->Draw("PE");
    h_ME_cos_theta_star2_10_40->Draw("PE same");

    c5->cd(3);
    h_ME_cos_theta_star5_10_40->SetStats(0);
    h_ME_cos_theta_star5_10_40->SetMinimum(0);
    h_ME_cos_theta_star5_10_40->SetMarkerStyle(24);
    h_ME_cos_theta_star5_10_40->SetMarkerColor(kBlue);

    h_ME_cos_theta_star6_10_40->SetStats(0);
    h_ME_cos_theta_star6_10_40->SetMinimum(0);
    h_ME_cos_theta_star6_10_40->SetMarkerStyle(24);
    h_ME_cos_theta_star6_10_40->SetMarkerColor(kRed);
    h_ME_cos_theta_star6_10_40->SetLineColor(kRed);

    h_ME_cos_theta_star5_10_40->Draw("PE");
    h_ME_cos_theta_star6_10_40->Draw("PE same");

    c5->cd(4);
    h_outside_ME_cos_theta_star3_10_40->SetStats(0);
    h_outside_ME_cos_theta_star3_10_40->SetMinimum(0);
    h_outside_ME_cos_theta_star3_10_40->SetMarkerStyle(24);
    h_outside_ME_cos_theta_star3_10_40->SetMarkerColor(kBlue);

    h_outside_ME_cos_theta_star4_10_40->SetStats(0);
    h_outside_ME_cos_theta_star4_10_40->SetMinimum(0);
    h_outside_ME_cos_theta_star4_10_40->SetMarkerStyle(24);
    h_outside_ME_cos_theta_star4_10_40->SetMarkerColor(kRed);
    h_outside_ME_cos_theta_star4_10_40->SetLineColor(kRed);

    h_outside_ME_cos_theta_star3_10_40->Draw("PE");
    h_outside_ME_cos_theta_star4_10_40->Draw("PE same");

    c5->cd(5);
    h_outside_ME_cos_theta_star_10_40->SetStats(0);
    h_outside_ME_cos_theta_star_10_40->SetMinimum(0);
    h_outside_ME_cos_theta_star_10_40->SetMarkerStyle(24);
    h_outside_ME_cos_theta_star_10_40->SetMarkerColor(kBlue);

    h_outside_ME_cos_theta_star2_10_40->SetStats(0);
    h_outside_ME_cos_theta_star2_10_40->SetMinimum(0);
    h_outside_ME_cos_theta_star2_10_40->SetMarkerStyle(24);
    h_outside_ME_cos_theta_star2_10_40->SetMarkerColor(kRed);
    h_outside_ME_cos_theta_star2_10_40->SetLineColor(kRed);

    h_outside_ME_cos_theta_star_10_40->Draw("PE");
    h_outside_ME_cos_theta_star2_10_40->Draw("PE same");

    c5->cd(6);
    h_outside_ME_cos_theta_star5_10_40->SetStats(0);
    h_outside_ME_cos_theta_star5_10_40->SetMinimum(0);
    h_outside_ME_cos_theta_star5_10_40->SetMarkerStyle(24);
    h_outside_ME_cos_theta_star5_10_40->SetMarkerColor(kBlue);

    h_outside_ME_cos_theta_star6_10_40->SetStats(0);
    h_outside_ME_cos_theta_star6_10_40->SetMinimum(0);
    h_outside_ME_cos_theta_star6_10_40->SetMarkerStyle(24);
    h_outside_ME_cos_theta_star6_10_40->SetMarkerColor(kRed);
    h_outside_ME_cos_theta_star6_10_40->SetLineColor(kRed);

    h_outside_ME_cos_theta_star5_10_40->Draw("PE");
    h_outside_ME_cos_theta_star6_10_40->Draw("PE same");

    cout << "   " << endl;
    cout << "Canvas 5 Complete" << endl;

    TCanvas *c6 = new TCanvas("c6", "c6- ME Distributions (40-80% Centrality)", 1800, 900);
    c6->Divide(3,2);

    c6->cd(1);
    h_ME_cos_theta_star3_40_80->SetStats(0);
    h_ME_cos_theta_star3_40_80->SetMinimum(0);
    h_ME_cos_theta_star3_40_80->SetMarkerStyle(24);
    h_ME_cos_theta_star3_40_80->SetMarkerColor(kBlue);

    h_ME_cos_theta_star4_40_80->SetStats(0);
    h_ME_cos_theta_star4_40_80->SetMinimum(0);
    h_ME_cos_theta_star4_40_80->SetMarkerStyle(24);
    h_ME_cos_theta_star4_40_80->SetMarkerColor(kRed);
    h_ME_cos_theta_star4_40_80->SetLineColor(kRed);

    h_ME_cos_theta_star3_40_80->Draw("PE");
    h_ME_cos_theta_star4_40_80->Draw("PE same");

    c6->cd(2);
    h_ME_cos_theta_star_40_80->SetStats(0);
    h_ME_cos_theta_star_40_80->SetMinimum(0);
    h_ME_cos_theta_star_40_80->SetMarkerStyle(24);
    h_ME_cos_theta_star_40_80->SetMarkerColor(kBlue);

    h_ME_cos_theta_star2_40_80->SetStats(0);
    h_ME_cos_theta_star2_40_80->SetMinimum(0);
    h_ME_cos_theta_star2_40_80->SetMarkerStyle(24);
    h_ME_cos_theta_star2_40_80->SetMarkerColor(kRed);
    h_ME_cos_theta_star2_40_80->SetLineColor(kRed);

    h_ME_cos_theta_star_40_80->Draw("PE");
    h_ME_cos_theta_star2_40_80->Draw("PE same");

    c6->cd(3);
    h_ME_cos_theta_star5_40_80->SetStats(0);
    h_ME_cos_theta_star5_40_80->SetMinimum(0);
    h_ME_cos_theta_star5_40_80->SetMarkerStyle(24);
    h_ME_cos_theta_star5_40_80->SetMarkerColor(kBlue);

    h_ME_cos_theta_star6_40_80->SetStats(0);
    h_ME_cos_theta_star6_40_80->SetMinimum(0);
    h_ME_cos_theta_star6_40_80->SetMarkerStyle(24);
    h_ME_cos_theta_star6_40_80->SetMarkerColor(kRed);
    h_ME_cos_theta_star6_40_80->SetLineColor(kRed);

    h_ME_cos_theta_star5_40_80->Draw("PE");
    h_ME_cos_theta_star6_40_80->Draw("PE same");

    c6->cd(4);
    h_outside_ME_cos_theta_star3_40_80->SetStats(0);
    h_outside_ME_cos_theta_star3_40_80->SetMinimum(0);
    h_outside_ME_cos_theta_star3_40_80->SetMarkerStyle(24);
    h_outside_ME_cos_theta_star3_40_80->SetMarkerColor(kBlue);

    h_outside_ME_cos_theta_star4_40_80->SetStats(0);
    h_outside_ME_cos_theta_star4_40_80->SetMinimum(0);
    h_outside_ME_cos_theta_star4_40_80->SetMarkerStyle(24);
    h_outside_ME_cos_theta_star4_40_80->SetMarkerColor(kRed);
    h_outside_ME_cos_theta_star4_40_80->SetLineColor(kRed);

    h_outside_ME_cos_theta_star3_40_80->Draw("PE");
    h_outside_ME_cos_theta_star4_40_80->Draw("PE same");

    c6->cd(5);
    h_outside_ME_cos_theta_star_40_80->SetStats(0);
    h_outside_ME_cos_theta_star_40_80->SetMinimum(0);
    h_outside_ME_cos_theta_star_40_80->SetMarkerStyle(24);
    h_outside_ME_cos_theta_star_40_80->SetMarkerColor(kBlue);

    h_outside_ME_cos_theta_star2_40_80->SetStats(0);
    h_outside_ME_cos_theta_star2_40_80->SetMinimum(0);
    h_outside_ME_cos_theta_star2_40_80->SetMarkerStyle(24);
    h_outside_ME_cos_theta_star2_40_80->SetMarkerColor(kRed);
    h_outside_ME_cos_theta_star2_40_80->SetLineColor(kRed);

    h_outside_ME_cos_theta_star_40_80->Draw("PE");
    h_outside_ME_cos_theta_star2_40_80->Draw("PE same");

    c6->cd(6);
    h_outside_ME_cos_theta_star5_40_80->SetStats(0);
    h_outside_ME_cos_theta_star5_40_80->SetMinimum(0);
    h_outside_ME_cos_theta_star5_40_80->SetMarkerStyle(24);
    h_outside_ME_cos_theta_star5_40_80->SetMarkerColor(kBlue);

    h_outside_ME_cos_theta_star6_40_80->SetStats(0);
    h_outside_ME_cos_theta_star6_40_80->SetMinimum(0);
    h_outside_ME_cos_theta_star6_40_80->SetMarkerStyle(24);
    h_outside_ME_cos_theta_star6_40_80->SetMarkerColor(kRed);
    h_outside_ME_cos_theta_star6_40_80->SetLineColor(kRed);

    h_outside_ME_cos_theta_star5_40_80->Draw("PE");
    h_outside_ME_cos_theta_star6_40_80->Draw("PE same");

    cout << "   " << endl;
    cout << "Canvas 6 Complete" << endl;

    cout << "   " << endl;
    cout << "** Kristen's Mixed Event dN/dCos(theta*) distributions with the normalization applied (0-10% Centrality) **" << endl;
    cout << "   " << endl;

    double counts_ME_cos_theta_star3_0_10 = h_ME_cos_theta_star3_0_10->Integral();
    double counts_ME_cos_theta_star4_0_10 = h_ME_cos_theta_star4_0_10->Integral();
    double counts_ME_cos_theta_star_0_10 = h_ME_cos_theta_star_0_10->Integral();
    double counts_ME_cos_theta_star2_0_10 = h_ME_cos_theta_star2_0_10->Integral();
    double counts_ME_cos_theta_star5_0_10 = h_ME_cos_theta_star5_0_10->Integral();
    double counts_ME_cos_theta_star6_0_10 = h_ME_cos_theta_star6_0_10->Integral();

    cout << "Counts inside the delta_R cut" << endl;
    cout << "US-US L0-L0bar: " << counts_ME_cos_theta_star3_0_10 << endl;
    cout << "US-LS L0-L0bar: " << counts_ME_cos_theta_star4_0_10 << endl;
    cout << "US-US L0-L0: " << counts_ME_cos_theta_star_0_10 << endl;
    cout << "US-LS L0-L0: " << counts_ME_cos_theta_star2_0_10 << endl;
    cout << "US-US L0bar-L0bar: " << counts_ME_cos_theta_star5_0_10 << endl;
    cout << "US-LS L0bar-L0bar: " << counts_ME_cos_theta_star6_0_10 << endl;

    double counts_outside_ME_cos_theta_star3_0_10 = h_outside_ME_cos_theta_star3_0_10->Integral();
    double counts_outside_ME_cos_theta_star4_0_10 = h_outside_ME_cos_theta_star4_0_10->Integral();
    double counts_outside_ME_cos_theta_star_0_10 = h_outside_ME_cos_theta_star_0_10->Integral();
    double counts_outside_ME_cos_theta_star2_0_10 = h_outside_ME_cos_theta_star2_0_10->Integral();
    double counts_outside_ME_cos_theta_star5_0_10 = h_outside_ME_cos_theta_star5_0_10->Integral();
    double counts_outside_ME_cos_theta_star6_0_10 = h_outside_ME_cos_theta_star6_0_10->Integral();

    cout << "   " << endl;
    cout << "Counts outside the delta_R cut" << endl;
    cout << "US-US L0-L0bar: " << counts_outside_ME_cos_theta_star3_0_10 << endl;
    cout << "US-LS L0-L0bar: " << counts_outside_ME_cos_theta_star4_0_10<< endl;
    cout << "US-US L0-L0: " << counts_outside_ME_cos_theta_star_0_10 << endl;
    cout << "US-LS L0-L0: " << counts_outside_ME_cos_theta_star2_0_10 << endl;
    cout << "US-US L0bar-L0bar: " << counts_outside_ME_cos_theta_star5_0_10 << endl;
    cout << "US-LS L0bar-L0bar: " << counts_outside_ME_cos_theta_star6_0_10 << endl;

    cout << "   " << endl;
    cout << "** Kristen's Mixed Event dN/dCos(theta*) distributions with the normalization applied (10-40% Centrality) **" << endl;
    cout << "   " << endl;

    double counts_ME_cos_theta_star3_10_40 = h_ME_cos_theta_star3_10_40->Integral();
    double counts_ME_cos_theta_star4_10_40 = h_ME_cos_theta_star4_10_40->Integral();
    double counts_ME_cos_theta_star_10_40 = h_ME_cos_theta_star_10_40->Integral();
    double counts_ME_cos_theta_star2_10_40 = h_ME_cos_theta_star2_10_40->Integral();
    double counts_ME_cos_theta_star5_10_40 = h_ME_cos_theta_star5_10_40->Integral();
    double counts_ME_cos_theta_star6_10_40 = h_ME_cos_theta_star6_10_40->Integral();

    cout << "Counts inside the delta_R cut" << endl;
    cout << "US-US L0-L0bar: " << counts_ME_cos_theta_star3_10_40 << endl;
    cout << "US-LS L0-L0bar: " << counts_ME_cos_theta_star4_10_40 << endl;
    cout << "US-US L0-L0: " << counts_ME_cos_theta_star_10_40 << endl;
    cout << "US-LS L0-L0: " << counts_ME_cos_theta_star2_10_40 << endl;
    cout << "US-US L0bar-L0bar: " << counts_ME_cos_theta_star5_10_40 << endl;
    cout << "US-LS L0bar-L0bar: " << counts_ME_cos_theta_star6_10_40 << endl;

    double counts_outside_ME_cos_theta_star3_10_40 = h_outside_ME_cos_theta_star3_10_40->Integral();
    double counts_outside_ME_cos_theta_star4_10_40 = h_outside_ME_cos_theta_star4_10_40->Integral();
    double counts_outside_ME_cos_theta_star_10_40 = h_outside_ME_cos_theta_star_10_40->Integral();
    double counts_outside_ME_cos_theta_star2_10_40 = h_outside_ME_cos_theta_star2_10_40->Integral();
    double counts_outside_ME_cos_theta_star5_10_40 = h_outside_ME_cos_theta_star5_10_40->Integral();
    double counts_outside_ME_cos_theta_star6_10_40 = h_outside_ME_cos_theta_star6_10_40->Integral();

    cout << "   " << endl;
    cout << "Counts outside the delta_R cut" << endl;
    cout << "US-US L0-L0bar: " << counts_outside_ME_cos_theta_star3_10_40 << endl;
    cout << "US-LS L0-L0bar: " << counts_outside_ME_cos_theta_star4_10_40 << endl;
    cout << "US-US L0-L0: " << counts_outside_ME_cos_theta_star_10_40 << endl;
    cout << "US-LS L0-L0: " << counts_outside_ME_cos_theta_star2_10_40 << endl;
    cout << "US-US L0bar-L0bar: " << counts_outside_ME_cos_theta_star5_10_40 << endl;
    cout << "US-LS L0bar-L0bar: " << counts_outside_ME_cos_theta_star6_10_40 << endl;

    cout << "   " << endl;
    cout << "** Kristen's Mixed Event dN/dCos(theta*) distributions with the normalization applied (40-80% Centrality) **" << endl;
    cout << "   " << endl;

    double counts_ME_cos_theta_star3_40_80 = h_ME_cos_theta_star3_40_80->Integral();
    double counts_ME_cos_theta_star4_40_80 = h_ME_cos_theta_star4_40_80->Integral();
    double counts_ME_cos_theta_star_40_80 = h_ME_cos_theta_star_40_80->Integral();
    double counts_ME_cos_theta_star2_40_80 = h_ME_cos_theta_star2_40_80->Integral();
    double counts_ME_cos_theta_star5_40_80 = h_ME_cos_theta_star5_40_80->Integral();
    double counts_ME_cos_theta_star6_40_80 = h_ME_cos_theta_star6_40_80->Integral();

    cout << "Counts inside the delta_R cut" << endl;
    cout << "US-US L0-L0bar: " << counts_ME_cos_theta_star3_40_80 << endl;
    cout << "US-LS L0-L0bar: " << counts_ME_cos_theta_star4_40_80 << endl;
    cout << "US-US L0-L0: " << counts_ME_cos_theta_star_40_80 << endl;
    cout << "US-LS L0-L0: " << counts_ME_cos_theta_star2_40_80 << endl;
    cout << "US-US L0bar-L0bar: " << counts_ME_cos_theta_star5_40_80 << endl;
    cout << "US-LS L0bar-L0bar: " << counts_ME_cos_theta_star6_40_80 << endl;

    double counts_outside_ME_cos_theta_star3_40_80 = h_outside_ME_cos_theta_star3_40_80->Integral();
    double counts_outside_ME_cos_theta_star4_40_80 = h_outside_ME_cos_theta_star4_40_80->Integral();
    double counts_outside_ME_cos_theta_star_40_80 = h_outside_ME_cos_theta_star_40_80->Integral();
    double counts_outside_ME_cos_theta_star2_40_80 = h_outside_ME_cos_theta_star2_40_80->Integral();
    double counts_outside_ME_cos_theta_star5_40_80 = h_outside_ME_cos_theta_star5_40_80->Integral();
    double counts_outside_ME_cos_theta_star6_40_80 = h_outside_ME_cos_theta_star6_40_80->Integral();

    cout << "   " << endl;
    cout << "Counts outside the delta_R cut" << endl;
    cout << "US-US L0-L0bar: " << counts_outside_ME_cos_theta_star3_40_80 << endl;
    cout << "US-LS L0-L0bar: " << counts_outside_ME_cos_theta_star4_40_80 << endl;
    cout << "US-US L0-L0: " << counts_outside_ME_cos_theta_star_40_80 << endl;
    cout << "US-LS L0-L0: " << counts_outside_ME_cos_theta_star2_40_80 << endl;
    cout << "US-US L0bar-L0bar: " << counts_outside_ME_cos_theta_star5_40_80 << endl;
    cout << "US-LS L0bar-L0bar: " << counts_outside_ME_cos_theta_star6_40_80 << endl;

    TCanvas *c7 = new TCanvas("c7", "c7- 0-10%", 1800, 900);
    c7->Divide(3,2);

    c7->cd(1);
    h_cos_theta_star3_0_10->SetStats(0);
    h_cos_theta_star3_0_10->SetMinimum(0);
    h_cos_theta_star3_0_10->SetMarkerStyle(20);
    h_cos_theta_star3_0_10->SetMarkerColor(kBlue);
    h_cos_theta_star3_0_10->SetTitle("SE and ME #Lambda#bar{#Lambda} Pairs inside #DeltaR (0-10% Centrality); cos(#theta*); dN/dCos(#theta*)"); 
    h_cos_theta_star3_0_10->GetXaxis()->CenterTitle();
    h_cos_theta_star3_0_10->GetYaxis()->CenterTitle();

    h_cos_theta_star4_0_10->SetStats(0);
    h_cos_theta_star4_0_10->SetMinimum(0);
    h_cos_theta_star4_0_10->SetMarkerStyle(20);
    h_cos_theta_star4_0_10->SetMarkerColor(kRed);
    h_cos_theta_star4_0_10->SetLineColor(kRed);

    h_ME_cos_theta_star3_0_10->SetStats(0);
    h_ME_cos_theta_star3_0_10->SetMinimum(0);
    h_ME_cos_theta_star3_0_10->SetMarkerStyle(25);
    h_ME_cos_theta_star3_0_10->SetMarkerColor(kBlue);

    h_ME_cos_theta_star4_0_10->SetStats(0);
    h_ME_cos_theta_star4_0_10->SetMinimum(0);
    h_ME_cos_theta_star4_0_10->SetMarkerStyle(25);
    h_ME_cos_theta_star4_0_10->SetMarkerColor(kRed);
    h_ME_cos_theta_star4_0_10->SetLineColor(kRed);

    h_cos_theta_star3_0_10->Draw("PE");
    h_cos_theta_star4_0_10->Draw("PE same");
    h_ME_cos_theta_star3_0_10->Draw("PE same");
    h_ME_cos_theta_star4_0_10->Draw("PE same");

    TLegend *legend_L0_L0bar_0_10 = new TLegend(0.12, 0.6, 0.4, 0.8);
    legend_L0_L0bar_0_10->SetTextSize(0.03);
    legend_L0_L0bar_0_10->SetBorderSize(0);
    legend_L0_L0bar_0_10->SetFillStyle(0);

    legend_L0_L0bar_0_10->AddEntry(h_cos_theta_star3_0_10, "US-US SE #Lambda#bar{#Lambda} Pairs", "p");
    legend_L0_L0bar_0_10->AddEntry(h_cos_theta_star4_0_10, "US-LS SE #Lambda#bar{#Lambda} Pairs", "p");
    legend_L0_L0bar_0_10->AddEntry(h_ME_cos_theta_star3_0_10, "US-US ME #Lambda#bar{#Lambda} Pairs", "p");
    legend_L0_L0bar_0_10->AddEntry(h_ME_cos_theta_star4_0_10, "US-LS ME #Lambda#bar{#Lambda} Pairs", "p");

    legend_L0_L0bar_0_10->Draw();

    c7->cd(2);
    h_cos_theta_star_0_10->SetStats(0);
    h_cos_theta_star_0_10->SetMinimum(0);
    h_cos_theta_star_0_10->SetMarkerStyle(20);
    h_cos_theta_star_0_10->SetMarkerColor(kBlue);
    h_cos_theta_star_0_10->SetTitle("SE and ME #Lambda#Lambda Pairs inside #DeltaR (0-10% Centrality); cos(#theta*); dN/dCos(#theta*)"); 
    h_cos_theta_star_0_10->GetXaxis()->CenterTitle();
    h_cos_theta_star_0_10->GetYaxis()->CenterTitle();

    h_cos_theta_star2_0_10->SetStats(0);
    h_cos_theta_star2_0_10->SetMinimum(0);
    h_cos_theta_star2_0_10->SetMarkerStyle(20);
    h_cos_theta_star2_0_10->SetMarkerColor(kRed);
    h_cos_theta_star2_0_10->SetLineColor(kRed);

    h_ME_cos_theta_star_0_10->SetStats(0);
    h_ME_cos_theta_star_0_10->SetMinimum(0);
    h_ME_cos_theta_star_0_10->SetMarkerStyle(25);
    h_ME_cos_theta_star_0_10->SetMarkerColor(kBlue);

    h_ME_cos_theta_star2_0_10->SetStats(0);
    h_ME_cos_theta_star2_0_10->SetMinimum(0);
    h_ME_cos_theta_star2_0_10->SetMarkerStyle(25);
    h_ME_cos_theta_star2_0_10->SetMarkerColor(kRed);
    h_ME_cos_theta_star2_0_10->SetLineColor(kRed);

    h_cos_theta_star_0_10->Draw("PE");
    h_cos_theta_star2_0_10->Draw("PE same");
    h_ME_cos_theta_star_0_10->Draw("PE same");
    h_ME_cos_theta_star2_0_10->Draw("PE same");

    TLegend *legend_L0_L0_0_10 = new TLegend(0.12, 0.6, 0.4, 0.8);
    legend_L0_L0_0_10->SetTextSize(0.03);
    legend_L0_L0_0_10->SetBorderSize(0);
    legend_L0_L0_0_10->SetFillStyle(0);

    legend_L0_L0_0_10->AddEntry(h_cos_theta_star_0_10, "US-US SE #Lambda#Lambda Pairs", "p");
    legend_L0_L0_0_10->AddEntry(h_cos_theta_star2_0_10, "US-LS SE #Lambda#Lambda Pairs", "p");
    legend_L0_L0_0_10->AddEntry(h_ME_cos_theta_star_0_10, "US-US ME #Lambda#Lambda Pairs", "p");
    legend_L0_L0_0_10->AddEntry(h_ME_cos_theta_star2_0_10, "US-LS ME #Lambda#Lambda Pairs", "p");

    legend_L0_L0_0_10->Draw();

    c7->cd(3);
    h_cos_theta_star5_0_10->SetStats(0);
    h_cos_theta_star5_0_10->SetMinimum(0);
    h_cos_theta_star5_0_10->SetMarkerStyle(20);
    h_cos_theta_star5_0_10->SetMarkerColor(kBlue);
    h_cos_theta_star5_0_10->SetTitle("SE and ME #bar{#Lambda}#bar{#Lambda} Pairs inside #DeltaR (0-10% Centrality); cos(#theta*); dN/dCos(#theta*)");
    h_cos_theta_star5_0_10->GetXaxis()->CenterTitle();
    h_cos_theta_star5_0_10->GetYaxis()->CenterTitle();

    h_cos_theta_star6_0_10->SetStats(0);
    h_cos_theta_star6_0_10->SetMinimum(0);
    h_cos_theta_star6_0_10->SetMarkerStyle(20);
    h_cos_theta_star6_0_10->SetMarkerColor(kRed);
    h_cos_theta_star6_0_10->SetLineColor(kRed);

    h_ME_cos_theta_star5_0_10->SetStats(0);
    h_ME_cos_theta_star5_0_10->SetMinimum(0);
    h_ME_cos_theta_star5_0_10->SetMarkerStyle(25);
    h_ME_cos_theta_star5_0_10->SetMarkerColor(kBlue);

    h_ME_cos_theta_star6_0_10->SetStats(0);
    h_ME_cos_theta_star6_0_10->SetMinimum(0);
    h_ME_cos_theta_star6_0_10->SetMarkerStyle(25);
    h_ME_cos_theta_star6_0_10->SetMarkerColor(kRed);
    h_ME_cos_theta_star6_0_10->SetLineColor(kRed);

    h_cos_theta_star5_0_10->Draw("PE"); 
    h_cos_theta_star6_0_10->Draw("PE same");
    h_ME_cos_theta_star5_0_10->Draw("PE same");
    h_ME_cos_theta_star6_0_10->Draw("PE same");

    TLegend *legend_L0bar_L0bar_0_10 = new TLegend(0.12, 0.6, 0.4, 0.8);
    legend_L0bar_L0bar_0_10->SetTextSize(0.03);
    legend_L0bar_L0bar_0_10->SetBorderSize(0);
    legend_L0bar_L0bar_0_10->SetFillStyle(0);

    legend_L0bar_L0bar_0_10->AddEntry(h_cos_theta_star5_0_10, "US-US SE #bar{#Lambda}#bar{#Lambda} Pairs", "p");
    legend_L0bar_L0bar_0_10->AddEntry(h_cos_theta_star6_0_10, "US-LS SE #bar{#Lambda}#bar{#Lambda} Pairs", "p");
    legend_L0bar_L0bar_0_10->AddEntry(h_ME_cos_theta_star5_0_10, "US-US ME #bar{#Lambda}#bar{#Lambda} Pairs", "p");
    legend_L0bar_L0bar_0_10->AddEntry(h_ME_cos_theta_star6_0_10, "US-LS ME #bar{#Lambda}#bar{#Lambda} Pairs", "p");

    legend_L0bar_L0bar_0_10->Draw();

    c7->cd(4);
    h_outside_cos_theta_star3_0_10->SetStats(0);
    h_outside_cos_theta_star3_0_10->SetMinimum(0);
    h_outside_cos_theta_star3_0_10->SetMarkerStyle(20);
    h_outside_cos_theta_star3_0_10->SetMarkerColor(kBlue);
    h_outside_cos_theta_star3_0_10->SetTitle("SE and ME #Lambda#bar{#Lambda} Pairs outside #DeltaR (0-10% Centrality); cos(#theta*); dN/dCos(#theta*)"); 
    h_outside_cos_theta_star3_0_10->GetXaxis()->CenterTitle();
    h_outside_cos_theta_star3_0_10->GetYaxis()->CenterTitle();

    h_outside_cos_theta_star4_0_10->SetStats(0);
    h_outside_cos_theta_star4_0_10->SetMinimum(0);
    h_outside_cos_theta_star4_0_10->SetMarkerStyle(20);
    h_outside_cos_theta_star4_0_10->SetMarkerColor(kRed);
    h_outside_cos_theta_star4_0_10->SetLineColor(kRed);

    h_outside_ME_cos_theta_star3_0_10->SetStats(0);
    h_outside_ME_cos_theta_star3_0_10->SetMinimum(0);
    h_outside_ME_cos_theta_star3_0_10->SetMarkerStyle(25);
    h_outside_ME_cos_theta_star3_0_10->SetMarkerColor(kBlue);

    h_outside_ME_cos_theta_star4_0_10->SetStats(0);
    h_outside_ME_cos_theta_star4_0_10->SetMinimum(0);
    h_outside_ME_cos_theta_star4_0_10->SetMarkerStyle(25);
    h_outside_ME_cos_theta_star4_0_10->SetMarkerColor(kRed);
    h_outside_ME_cos_theta_star4_0_10->SetLineColor(kRed);

    h_outside_cos_theta_star3_0_10->Draw("PE");
    h_outside_cos_theta_star4_0_10->Draw("PE same");
    h_outside_ME_cos_theta_star3_0_10->Draw("PE same");
    h_outside_ME_cos_theta_star4_0_10->Draw("PE same");

    TLegend *legend_L0_L0bar_out_0_10 = new TLegend(0.12, 0.15, 0.4, 0.35);
    legend_L0_L0bar_out_0_10->SetTextSize(0.03);
    legend_L0_L0bar_out_0_10->SetBorderSize(0);
    legend_L0_L0bar_out_0_10->SetFillStyle(0);

    legend_L0_L0bar_out_0_10->AddEntry(h_outside_cos_theta_star3_0_10, "US-US SE #Lambda#bar{#Lambda} Pairs", "p");
    legend_L0_L0bar_out_0_10->AddEntry(h_outside_cos_theta_star4_0_10, "US-LS SE #Lambda#bar{#Lambda} Pairs", "p");
    legend_L0_L0bar_out_0_10->AddEntry(h_outside_ME_cos_theta_star3_0_10, "US-US ME #Lambda#bar{#Lambda} Pairs", "p");
    legend_L0_L0bar_out_0_10->AddEntry(h_outside_ME_cos_theta_star4_0_10, "US-LS ME #Lambda#bar{#Lambda} Pairs", "p");

    legend_L0_L0bar_out_0_10->Draw();

    c7->cd(5);
    h_outside_cos_theta_star_0_10->SetStats(0);
    h_outside_cos_theta_star_0_10->SetMinimum(0);
    h_outside_cos_theta_star_0_10->SetMarkerStyle(20);
    h_outside_cos_theta_star_0_10->SetMarkerColor(kBlue);
    h_outside_cos_theta_star_0_10->SetTitle("SE and ME #Lambda#Lambda Pairs outside #DeltaR (0-10% Centrality); cos(#theta*); dN/dCos(#theta*)"); 
    h_outside_cos_theta_star_0_10->GetXaxis()->CenterTitle();
    h_outside_cos_theta_star_0_10->GetYaxis()->CenterTitle();

    h_outside_cos_theta_star2_0_10->SetStats(0);
    h_outside_cos_theta_star2_0_10->SetMinimum(0);
    h_outside_cos_theta_star2_0_10->SetMarkerStyle(20);
    h_outside_cos_theta_star2_0_10->SetMarkerColor(kRed);
    h_outside_cos_theta_star2_0_10->SetLineColor(kRed);

    h_outside_ME_cos_theta_star_0_10->SetStats(0);
    h_outside_ME_cos_theta_star_0_10->SetMinimum(0);
    h_outside_ME_cos_theta_star_0_10->SetMarkerStyle(25);
    h_outside_ME_cos_theta_star_0_10->SetMarkerColor(kBlue);

    h_outside_ME_cos_theta_star2_0_10->SetStats(0);
    h_outside_ME_cos_theta_star2_0_10->SetMinimum(0);
    h_outside_ME_cos_theta_star2_0_10->SetMarkerStyle(25);
    h_outside_ME_cos_theta_star2_0_10->SetMarkerColor(kRed);
    h_outside_ME_cos_theta_star2_0_10->SetLineColor(kRed);

    h_outside_cos_theta_star_0_10->Draw("PE");
    h_outside_cos_theta_star2_0_10->Draw("PE same");
    h_outside_ME_cos_theta_star_0_10->Draw("PE same");
    h_outside_ME_cos_theta_star2_0_10->Draw("PE same");

    TLegend *legend_L0_L0_out_0_10 = new TLegend(0.12, 0.15, 0.4, 0.35);
    legend_L0_L0_out_0_10->SetTextSize(0.03);
    legend_L0_L0_out_0_10->SetBorderSize(0);
    legend_L0_L0_out_0_10->SetFillStyle(0);

    legend_L0_L0_out_0_10->AddEntry(h_outside_cos_theta_star_0_10, "US-US SE #Lambda#Lambda Pairs", "p");
    legend_L0_L0_out_0_10->AddEntry(h_outside_cos_theta_star2_0_10, "US-LS SE #Lambda#Lambda Pairs", "p");
    legend_L0_L0_out_0_10->AddEntry(h_outside_ME_cos_theta_star_0_10, "US-US ME #Lambda#Lambda Pairs", "p");
    legend_L0_L0_out_0_10->AddEntry(h_outside_ME_cos_theta_star2_0_10, "US-LS ME #Lambda#Lambda Pairs", "p");

    legend_L0_L0_out_0_10->Draw();

    c7->cd(6);
    h_outside_cos_theta_star5_0_10->SetStats(0);
    h_outside_cos_theta_star5_0_10->SetMinimum(0);
    h_outside_cos_theta_star5_0_10->SetMarkerStyle(20);
    h_outside_cos_theta_star5_0_10->SetMarkerColor(kBlue);
    h_outside_cos_theta_star5_0_10->SetTitle("SE and ME #bar{#Lambda}#bar{#Lambda} Pairs outside #DeltaR (0-10% Centrality); cos(#theta*); dN/dCos(#theta*)"); 
    h_outside_cos_theta_star5_0_10->GetXaxis()->CenterTitle();
    h_outside_cos_theta_star5_0_10->GetYaxis()->CenterTitle();

    h_outside_cos_theta_star6_0_10->SetStats(0);
    h_outside_cos_theta_star6_0_10->SetMinimum(0);
    h_outside_cos_theta_star6_0_10->SetMarkerStyle(20);
    h_outside_cos_theta_star6_0_10->SetMarkerColor(kRed);
    h_outside_cos_theta_star6_0_10->SetLineColor(kRed);

    h_outside_ME_cos_theta_star5_0_10->SetStats(0);
    h_outside_ME_cos_theta_star5_0_10->SetMinimum(0);
    h_outside_ME_cos_theta_star5_0_10->SetMarkerStyle(25);
    h_outside_ME_cos_theta_star5_0_10->SetMarkerColor(kBlue);

    h_outside_ME_cos_theta_star6_0_10->SetStats(0);
    h_outside_ME_cos_theta_star6_0_10->SetMinimum(0);
    h_outside_ME_cos_theta_star6_0_10->SetMarkerStyle(25);
    h_outside_ME_cos_theta_star6_0_10->SetMarkerColor(kRed);
    h_outside_ME_cos_theta_star6_0_10->SetLineColor(kRed);

    h_outside_cos_theta_star5_0_10->Draw("PE");
    h_outside_cos_theta_star6_0_10->Draw("PE same");
    h_outside_ME_cos_theta_star5_0_10->Draw("PE same");
    h_outside_ME_cos_theta_star6_0_10->Draw("PE same");

    TLegend *legend_L0bar_L0bar_out_0_10 = new TLegend(0.12, 0.15, 0.4, 0.35);
    legend_L0bar_L0bar_out_0_10->SetTextSize(0.03);
    legend_L0bar_L0bar_out_0_10->SetBorderSize(0);
    legend_L0bar_L0bar_out_0_10->SetFillStyle(0);

    legend_L0bar_L0bar_out_0_10->AddEntry(h_outside_cos_theta_star5_0_10, "US-US SE #bar{#Lambda}#bar{#Lambda} Pairs", "p");
    legend_L0bar_L0bar_out_0_10->AddEntry(h_outside_cos_theta_star6_0_10, "US-LS SE #bar{#Lambda}#bar{#Lambda} Pairs", "p");
    legend_L0bar_L0bar_out_0_10->AddEntry(h_outside_ME_cos_theta_star5_0_10, "US-US ME #bar{#Lambda}#bar{#Lambda} Pairs", "p");
    legend_L0bar_L0bar_out_0_10->AddEntry(h_outside_ME_cos_theta_star6_0_10, "US-LS ME #bar{#Lambda}#bar{#Lambda} Pairs", "p");

    legend_L0bar_L0bar_out_0_10->Draw();

    cout << "Canvas 7 Complete" << endl;

    TCanvas *c8 = new TCanvas("c8", "c8- 10-40%", 1800, 900);
    c8->Divide(3,2);

    c8->cd(1);
    h_cos_theta_star3_10_40->SetStats(0);
    h_cos_theta_star3_10_40->SetMinimum(0);
    h_cos_theta_star3_10_40->SetMarkerStyle(20);
    h_cos_theta_star3_10_40->SetMarkerColor(kBlue);
    h_cos_theta_star3_10_40->SetTitle("SE and ME #Lambda#bar{#Lambda} Pairs inside #DeltaR (10-40% Centrality); cos(#theta*); dN/dCos(#theta*)"); 
    h_cos_theta_star3_10_40->GetXaxis()->CenterTitle();
    h_cos_theta_star3_10_40->GetYaxis()->CenterTitle();

    h_cos_theta_star4_10_40->SetStats(0);
    h_cos_theta_star4_10_40->SetMinimum(0);
    h_cos_theta_star4_10_40->SetMarkerStyle(20);
    h_cos_theta_star4_10_40->SetMarkerColor(kRed);
    h_cos_theta_star4_10_40->SetLineColor(kRed);

    h_ME_cos_theta_star3_10_40->SetStats(0);
    h_ME_cos_theta_star3_10_40->SetMinimum(0);
    h_ME_cos_theta_star3_10_40->SetMarkerStyle(25);
    h_ME_cos_theta_star3_10_40->SetMarkerColor(kBlue);

    h_ME_cos_theta_star4_10_40->SetStats(0);
    h_ME_cos_theta_star4_10_40->SetMinimum(0);
    h_ME_cos_theta_star4_10_40->SetMarkerStyle(25);
    h_ME_cos_theta_star4_10_40->SetMarkerColor(kRed);
    h_ME_cos_theta_star4_10_40->SetLineColor(kRed);

    h_cos_theta_star3_10_40->Draw("PE");
    h_cos_theta_star4_10_40->Draw("PE same");
    h_ME_cos_theta_star3_10_40->Draw("PE same");
    h_ME_cos_theta_star4_10_40->Draw("PE same");

    TLegend *legend_L0_L0bar_10_40 = new TLegend(0.12, 0.6, 0.4, 0.8);
    legend_L0_L0bar_10_40->SetTextSize(0.03);
    legend_L0_L0bar_10_40->SetBorderSize(0);
    legend_L0_L0bar_10_40->SetFillStyle(0);

    legend_L0_L0bar_10_40->AddEntry(h_cos_theta_star3_10_40, "US-US SE #Lambda#bar{#Lambda} Pairs", "p");
    legend_L0_L0bar_10_40->AddEntry(h_cos_theta_star4_10_40, "US-LS SE #Lambda#bar{#Lambda} Pairs", "p");
    legend_L0_L0bar_10_40->AddEntry(h_ME_cos_theta_star3_10_40, "US-US ME #Lambda#bar{#Lambda} Pairs", "p");
    legend_L0_L0bar_10_40->AddEntry(h_ME_cos_theta_star4_10_40, "US-LS ME #Lambda#bar{#Lambda} Pairs", "p");

    legend_L0_L0bar_10_40->Draw();

    c8->cd(2);
    h_cos_theta_star_10_40->SetStats(0);
    h_cos_theta_star_10_40->SetMinimum(0);
    h_cos_theta_star_10_40->SetMarkerStyle(20);
    h_cos_theta_star_10_40->SetMarkerColor(kBlue);
    h_cos_theta_star_10_40->SetTitle("SE and ME #Lambda#Lambda Pairs inside #DeltaR (10-40% Centrality); cos(#theta*); dN/dCos(#theta*)"); 
    h_cos_theta_star_10_40->GetXaxis()->CenterTitle();
    h_cos_theta_star_10_40->GetYaxis()->CenterTitle();

    h_cos_theta_star2_10_40->SetStats(0);
    h_cos_theta_star2_10_40->SetMinimum(0);
    h_cos_theta_star2_10_40->SetMarkerStyle(20);
    h_cos_theta_star2_10_40->SetMarkerColor(kRed);
    h_cos_theta_star2_10_40->SetLineColor(kRed);

    h_ME_cos_theta_star_10_40->SetStats(0);
    h_ME_cos_theta_star_10_40->SetMinimum(0);
    h_ME_cos_theta_star_10_40->SetMarkerStyle(25);
    h_ME_cos_theta_star_10_40->SetMarkerColor(kBlue);

    h_ME_cos_theta_star2_10_40->SetStats(0);
    h_ME_cos_theta_star2_10_40->SetMinimum(0);
    h_ME_cos_theta_star2_10_40->SetMarkerStyle(25);
    h_ME_cos_theta_star2_10_40->SetMarkerColor(kRed);
    h_ME_cos_theta_star2_10_40->SetLineColor(kRed);

    h_cos_theta_star_10_40->Draw("PE");
    h_cos_theta_star2_10_40->Draw("PE same");
    h_ME_cos_theta_star_10_40->Draw("PE same");
    h_ME_cos_theta_star2_10_40->Draw("PE same");

    TLegend *legend_L0_L0_10_40 = new TLegend(0.12, 0.6, 0.4, 0.8);
    legend_L0_L0_10_40->SetTextSize(0.03);
    legend_L0_L0_10_40->SetBorderSize(0);
    legend_L0_L0_10_40->SetFillStyle(0);

    legend_L0_L0_10_40->AddEntry(h_cos_theta_star_10_40, "US-US SE #Lambda#Lambda Pairs", "p");
    legend_L0_L0_10_40->AddEntry(h_cos_theta_star2_10_40, "US-LS SE #Lambda#Lambda Pairs", "p");
    legend_L0_L0_10_40->AddEntry(h_ME_cos_theta_star_10_40, "US-US ME #Lambda#Lambda Pairs", "p");
    legend_L0_L0_10_40->AddEntry(h_ME_cos_theta_star2_10_40, "US-LS ME #Lambda#Lambda Pairs", "p");

    legend_L0_L0_10_40->Draw();

    c8->cd(3);
    h_cos_theta_star5_10_40->SetStats(0);
    h_cos_theta_star5_10_40->SetMinimum(0);
    h_cos_theta_star5_10_40->SetMarkerStyle(20);
    h_cos_theta_star5_10_40->SetMarkerColor(kBlue);
    h_cos_theta_star5_10_40->SetTitle("SE and ME #bar{#Lambda}#bar{#Lambda} Pairs inside #DeltaR (10-40% Centrality); cos(#theta*); dN/dCos(#theta*)");
    h_cos_theta_star5_10_40->GetXaxis()->CenterTitle();
    h_cos_theta_star5_10_40->GetYaxis()->CenterTitle();

    h_cos_theta_star6_10_40->SetStats(0);
    h_cos_theta_star6_10_40->SetMinimum(0);
    h_cos_theta_star6_10_40->SetMarkerStyle(20);
    h_cos_theta_star6_10_40->SetMarkerColor(kRed);
    h_cos_theta_star6_10_40->SetLineColor(kRed);

    h_ME_cos_theta_star5_10_40->SetStats(0);
    h_ME_cos_theta_star5_10_40->SetMinimum(0);
    h_ME_cos_theta_star5_10_40->SetMarkerStyle(25);
    h_ME_cos_theta_star5_10_40->SetMarkerColor(kBlue);

    h_ME_cos_theta_star6_10_40->SetStats(0);
    h_ME_cos_theta_star6_10_40->SetMinimum(0);
    h_ME_cos_theta_star6_10_40->SetMarkerStyle(25);
    h_ME_cos_theta_star6_10_40->SetMarkerColor(kRed);
    h_ME_cos_theta_star6_10_40->SetLineColor(kRed);

    h_cos_theta_star5_10_40->Draw("PE"); 
    h_cos_theta_star6_10_40->Draw("PE same");
    h_ME_cos_theta_star5_10_40->Draw("PE same");
    h_ME_cos_theta_star6_10_40->Draw("PE same");

    TLegend *legend_L0bar_L0bar_10_40 = new TLegend(0.12, 0.6, 0.4, 0.8);
    legend_L0bar_L0bar_10_40->SetTextSize(0.03);
    legend_L0bar_L0bar_10_40->SetBorderSize(0);
    legend_L0bar_L0bar_10_40->SetFillStyle(0);

    legend_L0bar_L0bar_10_40->AddEntry(h_cos_theta_star5_10_40, "US-US SE #bar{#Lambda}#bar{#Lambda} Pairs", "p");
    legend_L0bar_L0bar_10_40->AddEntry(h_cos_theta_star6_10_40, "US-LS SE #bar{#Lambda}#bar{#Lambda} Pairs", "p");
    legend_L0bar_L0bar_10_40->AddEntry(h_ME_cos_theta_star5_10_40, "US-US ME #bar{#Lambda}#bar{#Lambda} Pairs", "p");
    legend_L0bar_L0bar_10_40->AddEntry(h_ME_cos_theta_star6_10_40, "US-LS ME #bar{#Lambda}#bar{#Lambda} Pairs", "p");

    legend_L0bar_L0bar_10_40->Draw();

    c8->cd(4);
    h_outside_cos_theta_star3_10_40->SetStats(0);
    h_outside_cos_theta_star3_10_40->SetMinimum(0);
    h_outside_cos_theta_star3_10_40->SetMarkerStyle(20);
    h_outside_cos_theta_star3_10_40->SetMarkerColor(kBlue);
    h_outside_cos_theta_star3_10_40->SetTitle("SE and ME #Lambda#bar{#Lambda} Pairs outside #DeltaR (10-40% Centrality); cos(#theta*); dN/dCos(#theta*)"); 
    h_outside_cos_theta_star3_10_40->GetXaxis()->CenterTitle();
    h_outside_cos_theta_star3_10_40->GetYaxis()->CenterTitle();

    h_outside_cos_theta_star4_10_40->SetStats(0);
    h_outside_cos_theta_star4_10_40->SetMinimum(0);
    h_outside_cos_theta_star4_10_40->SetMarkerStyle(20);
    h_outside_cos_theta_star4_10_40->SetMarkerColor(kRed);
    h_outside_cos_theta_star4_10_40->SetLineColor(kRed);

    h_outside_ME_cos_theta_star3_10_40->SetStats(0);
    h_outside_ME_cos_theta_star3_10_40->SetMinimum(0);
    h_outside_ME_cos_theta_star3_10_40->SetMarkerStyle(25);
    h_outside_ME_cos_theta_star3_10_40->SetMarkerColor(kBlue);

    h_outside_ME_cos_theta_star4_10_40->SetStats(0);
    h_outside_ME_cos_theta_star4_10_40->SetMinimum(0);
    h_outside_ME_cos_theta_star4_10_40->SetMarkerStyle(25);
    h_outside_ME_cos_theta_star4_10_40->SetMarkerColor(kRed);
    h_outside_ME_cos_theta_star4_10_40->SetLineColor(kRed);

    h_outside_cos_theta_star3_10_40->Draw("PE");
    h_outside_cos_theta_star4_10_40->Draw("PE same");
    h_outside_ME_cos_theta_star3_10_40->Draw("PE same");
    h_outside_ME_cos_theta_star4_10_40->Draw("PE same");

    TLegend *legend_L0_L0bar_out_10_40 = new TLegend(0.12, 0.35, 0.4, 0.55);
    legend_L0_L0bar_out_10_40->SetTextSize(0.03);
    legend_L0_L0bar_out_10_40->SetBorderSize(0);
    legend_L0_L0bar_out_10_40->SetFillStyle(0);

    legend_L0_L0bar_out_10_40->AddEntry(h_outside_cos_theta_star3_10_40, "US-US SE #Lambda#bar{#Lambda} Pairs", "p");
    legend_L0_L0bar_out_10_40->AddEntry(h_outside_cos_theta_star4_10_40, "US-LS SE #Lambda#bar{#Lambda} Pairs", "p");
    legend_L0_L0bar_out_10_40->AddEntry(h_outside_ME_cos_theta_star3_10_40, "US-US ME #Lambda#bar{#Lambda} Pairs", "p");
    legend_L0_L0bar_out_10_40->AddEntry(h_outside_ME_cos_theta_star4_10_40, "US-LS ME #Lambda#bar{#Lambda} Pairs", "p");

    legend_L0_L0bar_out_10_40->Draw();

    c8->cd(5);
    h_outside_cos_theta_star_10_40->SetStats(0);
    h_outside_cos_theta_star_10_40->SetMinimum(0);
    h_outside_cos_theta_star_10_40->SetMarkerStyle(20);
    h_outside_cos_theta_star_10_40->SetMarkerColor(kBlue);
    h_outside_cos_theta_star_10_40->SetTitle("SE and ME #Lambda#Lambda Pairs outside #DeltaR (10-40% Centrality); cos(#theta*); dN/dCos(#theta*)"); 
    h_outside_cos_theta_star_10_40->GetXaxis()->CenterTitle();
    h_outside_cos_theta_star_10_40->GetYaxis()->CenterTitle();

    h_outside_cos_theta_star2_10_40->SetStats(0);
    h_outside_cos_theta_star2_10_40->SetMinimum(0);
    h_outside_cos_theta_star2_10_40->SetMarkerStyle(20);
    h_outside_cos_theta_star2_10_40->SetMarkerColor(kRed);
    h_outside_cos_theta_star2_10_40->SetLineColor(kRed);

    h_outside_ME_cos_theta_star_10_40->SetStats(0);
    h_outside_ME_cos_theta_star_10_40->SetMinimum(0);
    h_outside_ME_cos_theta_star_10_40->SetMarkerStyle(25);
    h_outside_ME_cos_theta_star_10_40->SetMarkerColor(kBlue);

    h_outside_ME_cos_theta_star2_10_40->SetStats(0);
    h_outside_ME_cos_theta_star2_10_40->SetMinimum(0);
    h_outside_ME_cos_theta_star2_10_40->SetMarkerStyle(25);
    h_outside_ME_cos_theta_star2_10_40->SetMarkerColor(kRed);
    h_outside_ME_cos_theta_star2_10_40->SetLineColor(kRed);

    h_outside_cos_theta_star_10_40->Draw("PE");
    h_outside_cos_theta_star2_10_40->Draw("PE same");
    h_outside_ME_cos_theta_star_10_40->Draw("PE same");
    h_outside_ME_cos_theta_star2_10_40->Draw("PE same");

    TLegend *legend_L0_L0_out_10_40 = new TLegend(0.12, 0.35, 0.4, 0.55);
    legend_L0_L0_out_10_40->SetTextSize(0.03);
    legend_L0_L0_out_10_40->SetBorderSize(0);
    legend_L0_L0_out_10_40->SetFillStyle(0);

    legend_L0_L0_out_10_40->AddEntry(h_outside_cos_theta_star_10_40, "US-US SE #Lambda#Lambda Pairs", "p");
    legend_L0_L0_out_10_40->AddEntry(h_outside_cos_theta_star2_10_40, "US-LS SE #Lambda#Lambda Pairs", "p");
    legend_L0_L0_out_10_40->AddEntry(h_outside_ME_cos_theta_star_10_40, "US-US ME #Lambda#Lambda Pairs", "p");
    legend_L0_L0_out_10_40->AddEntry(h_outside_ME_cos_theta_star2_10_40, "US-LS ME #Lambda#Lambda Pairs", "p");

    legend_L0_L0_out_10_40->Draw();

    c8->cd(6);
    h_outside_cos_theta_star5_10_40->SetStats(0);
    h_outside_cos_theta_star5_10_40->SetMinimum(0);
    h_outside_cos_theta_star5_10_40->SetMarkerStyle(20);
    h_outside_cos_theta_star5_10_40->SetMarkerColor(kBlue);
    h_outside_cos_theta_star5_10_40->SetTitle("SE and ME #bar{#Lambda}#bar{#Lambda} Pairs outside #DeltaR (10-40% Centrality); cos(#theta*); dN/dCos(#theta*)"); 
    h_outside_cos_theta_star5_10_40->GetXaxis()->CenterTitle();
    h_outside_cos_theta_star5_10_40->GetYaxis()->CenterTitle();

    h_outside_cos_theta_star6_10_40->SetStats(0);
    h_outside_cos_theta_star6_10_40->SetMinimum(0);
    h_outside_cos_theta_star6_10_40->SetMarkerStyle(20);
    h_outside_cos_theta_star6_10_40->SetMarkerColor(kRed);
    h_outside_cos_theta_star6_10_40->SetLineColor(kRed);

    h_outside_ME_cos_theta_star5_10_40->SetStats(0);
    h_outside_ME_cos_theta_star5_10_40->SetMinimum(0);
    h_outside_ME_cos_theta_star5_10_40->SetMarkerStyle(25);
    h_outside_ME_cos_theta_star5_10_40->SetMarkerColor(kBlue);

    h_outside_ME_cos_theta_star6_10_40->SetStats(0);
    h_outside_ME_cos_theta_star6_10_40->SetMinimum(0);
    h_outside_ME_cos_theta_star6_10_40->SetMarkerStyle(25);
    h_outside_ME_cos_theta_star6_10_40->SetMarkerColor(kRed);
    h_outside_ME_cos_theta_star6_10_40->SetLineColor(kRed);

    h_outside_cos_theta_star5_10_40->Draw("PE");
    h_outside_cos_theta_star6_10_40->Draw("PE same");
    h_outside_ME_cos_theta_star5_10_40->Draw("PE same");
    h_outside_ME_cos_theta_star6_10_40->Draw("PE same");

    TLegend *legend_L0bar_L0bar_out_10_40 = new TLegend(0.12, 0.35, 0.4, 0.55);
    legend_L0bar_L0bar_out_10_40->SetTextSize(0.03);
    legend_L0bar_L0bar_out_10_40->SetBorderSize(0);
    legend_L0bar_L0bar_out_10_40->SetFillStyle(0);

    legend_L0bar_L0bar_out_10_40->AddEntry(h_outside_cos_theta_star5_10_40, "US-US SE #bar{#Lambda}#bar{#Lambda} Pairs", "p");
    legend_L0bar_L0bar_out_10_40->AddEntry(h_outside_cos_theta_star6_10_40, "US-LS SE #bar{#Lambda}#bar{#Lambda} Pairs", "p");
    legend_L0bar_L0bar_out_10_40->AddEntry(h_outside_ME_cos_theta_star5_10_40, "US-US ME #bar{#Lambda}#bar{#Lambda} Pairs", "p");
    legend_L0bar_L0bar_out_10_40->AddEntry(h_outside_ME_cos_theta_star6_10_40, "US-LS ME #bar{#Lambda}#bar{#Lambda} Pairs", "p");

    legend_L0bar_L0bar_out_10_40->Draw();

    cout << "Canvas 8 Complete" << endl;

    TCanvas *c9 = new TCanvas("c9", "c9- 40-80%", 1800, 900);
    c9->Divide(3,2);

    c9->cd(1);
    h_cos_theta_star3_40_80->SetStats(0);
    h_cos_theta_star3_40_80->SetMinimum(-0.25);
    h_cos_theta_star3_40_80->SetMarkerStyle(20);
    h_cos_theta_star3_40_80->SetMarkerColor(kBlue);
    h_cos_theta_star3_40_80->SetTitle("SE and ME #Lambda#bar{#Lambda} Pairs inside #DeltaR (40-80% Centrality); cos(#theta*); dN/dCos(#theta*)"); 
    h_cos_theta_star3_40_80->GetXaxis()->CenterTitle();
    h_cos_theta_star3_40_80->GetYaxis()->CenterTitle();

    h_cos_theta_star4_40_80->SetStats(0);
    h_cos_theta_star4_40_80->SetMinimum(0);
    h_cos_theta_star4_40_80->SetMarkerStyle(20);
    h_cos_theta_star4_40_80->SetMarkerColor(kRed);
    h_cos_theta_star4_40_80->SetLineColor(kRed);

    h_ME_cos_theta_star3_40_80->SetStats(0);
    h_ME_cos_theta_star3_40_80->SetMinimum(0);
    h_ME_cos_theta_star3_40_80->SetMarkerStyle(25);
    h_ME_cos_theta_star3_40_80->SetMarkerColor(kBlue);

    h_ME_cos_theta_star4_40_80->SetStats(0);
    h_ME_cos_theta_star4_40_80->SetMinimum(0);
    h_ME_cos_theta_star4_40_80->SetMarkerStyle(25);
    h_ME_cos_theta_star4_40_80->SetMarkerColor(kRed);
    h_ME_cos_theta_star4_40_80->SetLineColor(kRed);

    h_cos_theta_star3_40_80->Draw("PE");
    h_cos_theta_star4_40_80->Draw("PE same");
    h_ME_cos_theta_star3_40_80->Draw("PE same");
    h_ME_cos_theta_star4_40_80->Draw("PE same");

    TLegend *legend_L0_L0bar_40_80 = new TLegend(0.12, 0.6, 0.4, 0.8);
    legend_L0_L0bar_40_80->SetTextSize(0.03);
    legend_L0_L0bar_40_80->SetBorderSize(0);
    legend_L0_L0bar_40_80->SetFillStyle(0);

    legend_L0_L0bar_40_80->AddEntry(h_cos_theta_star3_40_80, "US-US SE #Lambda#bar{#Lambda} Pairs", "p");
    legend_L0_L0bar_40_80->AddEntry(h_cos_theta_star4_40_80, "US-LS SE #Lambda#bar{#Lambda} Pairs", "p");
    legend_L0_L0bar_40_80->AddEntry(h_ME_cos_theta_star3_40_80, "US-US ME #Lambda#bar{#Lambda} Pairs", "p");
    legend_L0_L0bar_40_80->AddEntry(h_ME_cos_theta_star4_40_80, "US-LS ME #Lambda#bar{#Lambda} Pairs", "p");

    legend_L0_L0bar_40_80->Draw();

    c9->cd(2);
    h_cos_theta_star_40_80->SetStats(0);
    h_cos_theta_star_40_80->SetMinimum(-0.25);
    h_cos_theta_star_40_80->SetMarkerStyle(20);
    h_cos_theta_star_40_80->SetMarkerColor(kBlue);
    h_cos_theta_star_40_80->SetTitle("SE and ME #Lambda#Lambda Pairs inside #DeltaR (40-80% Centrality); cos(#theta*); dN/dCos(#theta*)"); 
    h_cos_theta_star_40_80->GetXaxis()->CenterTitle();
    h_cos_theta_star_40_80->GetYaxis()->CenterTitle();

    h_cos_theta_star2_40_80->SetStats(0);
    h_cos_theta_star2_40_80->SetMinimum(0);
    h_cos_theta_star2_40_80->SetMarkerStyle(20);
    h_cos_theta_star2_40_80->SetMarkerColor(kRed);
    h_cos_theta_star2_40_80->SetLineColor(kRed);

    h_ME_cos_theta_star_40_80->SetStats(0);
    h_ME_cos_theta_star_40_80->SetMinimum(0);
    h_ME_cos_theta_star_40_80->SetMarkerStyle(25);
    h_ME_cos_theta_star_40_80->SetMarkerColor(kBlue);

    h_ME_cos_theta_star2_40_80->SetStats(0);
    h_ME_cos_theta_star2_40_80->SetMinimum(0);
    h_ME_cos_theta_star2_40_80->SetMarkerStyle(25);
    h_ME_cos_theta_star2_40_80->SetMarkerColor(kRed);
    h_ME_cos_theta_star2_40_80->SetLineColor(kRed);

    h_cos_theta_star_40_80->Draw("PE");
    h_cos_theta_star2_40_80->Draw("PE same");
    h_ME_cos_theta_star_40_80->Draw("PE same");
    h_ME_cos_theta_star2_40_80->Draw("PE same");

    TLegend *legend_L0_L0_40_80 = new TLegend(0.12, 0.6, 0.4, 0.8);
    legend_L0_L0_40_80->SetTextSize(0.03);
    legend_L0_L0_40_80->SetBorderSize(0);
    legend_L0_L0_40_80->SetFillStyle(0);

    legend_L0_L0_40_80->AddEntry(h_cos_theta_star_40_80, "US-US SE #Lambda#Lambda Pairs", "p");
    legend_L0_L0_40_80->AddEntry(h_cos_theta_star2_40_80, "US-LS SE #Lambda#Lambda Pairs", "p");
    legend_L0_L0_40_80->AddEntry(h_ME_cos_theta_star_40_80, "US-US ME #Lambda#Lambda Pairs", "p");
    legend_L0_L0_40_80->AddEntry(h_ME_cos_theta_star2_40_80, "US-LS ME #Lambda#Lambda Pairs", "p");

    legend_L0_L0_40_80->Draw();

    c9->cd(3);
    h_cos_theta_star5_40_80->SetStats(0);
    h_cos_theta_star5_40_80->SetMinimum(-0.25);
    h_cos_theta_star5_40_80->SetMarkerStyle(20);
    h_cos_theta_star5_40_80->SetMarkerColor(kBlue);
    h_cos_theta_star5_40_80->SetTitle("SE and ME #bar{#Lambda}#bar{#Lambda} Pairs inside #DeltaR (40-80% Centrality); cos(#theta*); dN/dCos(#theta*)");
    h_cos_theta_star5_40_80->GetXaxis()->CenterTitle();
    h_cos_theta_star5_40_80->GetYaxis()->CenterTitle();

    h_cos_theta_star6_40_80->SetStats(0);
    h_cos_theta_star6_40_80->SetMinimum(0);
    h_cos_theta_star6_40_80->SetMarkerStyle(20);
    h_cos_theta_star6_40_80->SetMarkerColor(kRed);
    h_cos_theta_star6_40_80->SetLineColor(kRed);

    h_ME_cos_theta_star5_40_80->SetStats(0);
    h_ME_cos_theta_star5_40_80->SetMinimum(0);
    h_ME_cos_theta_star5_40_80->SetMarkerStyle(25);
    h_ME_cos_theta_star5_40_80->SetMarkerColor(kBlue);

    h_ME_cos_theta_star6_40_80->SetStats(0);
    h_ME_cos_theta_star6_40_80->SetMinimum(0);
    h_ME_cos_theta_star6_40_80->SetMarkerStyle(25);
    h_ME_cos_theta_star6_40_80->SetMarkerColor(kRed);
    h_ME_cos_theta_star6_40_80->SetLineColor(kRed);

    h_cos_theta_star5_40_80->Draw("PE"); 
    h_cos_theta_star6_40_80->Draw("PE same");
    h_ME_cos_theta_star5_40_80->Draw("PE same");
    h_ME_cos_theta_star6_40_80->Draw("PE same");

    TLegend *legend_L0bar_L0bar_40_80 = new TLegend(0.12, 0.6, 0.4, 0.8);
    legend_L0bar_L0bar_40_80->SetTextSize(0.03);
    legend_L0bar_L0bar_40_80->SetBorderSize(0);
    legend_L0bar_L0bar_40_80->SetFillStyle(0);

    legend_L0bar_L0bar_40_80->AddEntry(h_cos_theta_star5_40_80, "US-US SE #bar{#Lambda}#bar{#Lambda} Pairs", "p");
    legend_L0bar_L0bar_40_80->AddEntry(h_cos_theta_star6_40_80, "US-LS SE #bar{#Lambda}#bar{#Lambda} Pairs", "p");
    legend_L0bar_L0bar_40_80->AddEntry(h_ME_cos_theta_star5_40_80, "US-US ME #bar{#Lambda}#bar{#Lambda} Pairs", "p");
    legend_L0bar_L0bar_40_80->AddEntry(h_ME_cos_theta_star6_40_80, "US-LS ME #bar{#Lambda}#bar{#Lambda} Pairs", "p");

    legend_L0bar_L0bar_40_80->Draw();

    c9->cd(4);
    h_outside_cos_theta_star3_40_80->SetStats(0);
    h_outside_cos_theta_star3_40_80->SetMinimum(-0.25);
    h_outside_cos_theta_star3_40_80->SetMarkerStyle(20);
    h_outside_cos_theta_star3_40_80->SetMarkerColor(kBlue);
    h_outside_cos_theta_star3_40_80->SetTitle("SE and ME #Lambda#bar{#Lambda} Pairs outside #DeltaR (40-80% Centrality); cos(#theta*); dN/dCos(#theta*)"); 
    h_outside_cos_theta_star3_40_80->GetXaxis()->CenterTitle();
    h_outside_cos_theta_star3_40_80->GetYaxis()->CenterTitle();

    h_outside_cos_theta_star4_40_80->SetStats(0);
    h_outside_cos_theta_star4_40_80->SetMinimum(0);
    h_outside_cos_theta_star4_40_80->SetMarkerStyle(20);
    h_outside_cos_theta_star4_40_80->SetMarkerColor(kRed);
    h_outside_cos_theta_star4_40_80->SetLineColor(kRed);

    h_outside_ME_cos_theta_star3_40_80->SetStats(0);
    h_outside_ME_cos_theta_star3_40_80->SetMinimum(0);
    h_outside_ME_cos_theta_star3_40_80->SetMarkerStyle(25);
    h_outside_ME_cos_theta_star3_40_80->SetMarkerColor(kBlue);

    h_outside_ME_cos_theta_star4_40_80->SetStats(0);
    h_outside_ME_cos_theta_star4_40_80->SetMinimum(0);
    h_outside_ME_cos_theta_star4_40_80->SetMarkerStyle(25);
    h_outside_ME_cos_theta_star4_40_80->SetMarkerColor(kRed);
    h_outside_ME_cos_theta_star4_40_80->SetLineColor(kRed);

    h_outside_cos_theta_star3_40_80->Draw("PE");
    h_outside_cos_theta_star4_40_80->Draw("PE same");
    h_outside_ME_cos_theta_star3_40_80->Draw("PE same");
    h_outside_ME_cos_theta_star4_40_80->Draw("PE same");

    TLegend *legend_L0_L0bar_out_40_80 = new TLegend(0.12, 0.25, 0.4, 0.45);
    legend_L0_L0bar_out_40_80->SetTextSize(0.03);
    legend_L0_L0bar_out_40_80->SetBorderSize(0);
    legend_L0_L0bar_out_40_80->SetFillStyle(0);

    legend_L0_L0bar_out_40_80->AddEntry(h_outside_cos_theta_star3_40_80, "US-US SE #Lambda#bar{#Lambda} Pairs", "p");
    legend_L0_L0bar_out_40_80->AddEntry(h_outside_cos_theta_star4_40_80, "US-LS SE #Lambda#bar{#Lambda} Pairs", "p");
    legend_L0_L0bar_out_40_80->AddEntry(h_outside_ME_cos_theta_star3_40_80, "US-US ME #Lambda#bar{#Lambda} Pairs", "p");
    legend_L0_L0bar_out_40_80->AddEntry(h_outside_ME_cos_theta_star4_40_80, "US-LS ME #Lambda#bar{#Lambda} Pairs", "p");

    legend_L0_L0bar_out_40_80->Draw();

    c9->cd(5);
    h_outside_cos_theta_star_40_80->SetStats(0);
    h_outside_cos_theta_star_40_80->SetMinimum(-0.25);
    h_outside_cos_theta_star_40_80->SetMarkerStyle(20);
    h_outside_cos_theta_star_40_80->SetMarkerColor(kBlue);
    h_outside_cos_theta_star_40_80->SetTitle("SE and ME #Lambda#Lambda Pairs outside #DeltaR (40-80% Centrality); cos(#theta*); dN/dCos(#theta*)"); 
    h_outside_cos_theta_star_40_80->GetXaxis()->CenterTitle();
    h_outside_cos_theta_star_40_80->GetYaxis()->CenterTitle();

    h_outside_cos_theta_star2_40_80->SetStats(0);
    h_outside_cos_theta_star2_40_80->SetMinimum(0);
    h_outside_cos_theta_star2_40_80->SetMarkerStyle(20);
    h_outside_cos_theta_star2_40_80->SetMarkerColor(kRed);
    h_outside_cos_theta_star2_40_80->SetLineColor(kRed);

    h_outside_ME_cos_theta_star_40_80->SetStats(0);
    h_outside_ME_cos_theta_star_40_80->SetMinimum(0);
    h_outside_ME_cos_theta_star_40_80->SetMarkerStyle(25);
    h_outside_ME_cos_theta_star_40_80->SetMarkerColor(kBlue);

    h_outside_ME_cos_theta_star2_40_80->SetStats(0);
    h_outside_ME_cos_theta_star2_40_80->SetMinimum(0);
    h_outside_ME_cos_theta_star2_40_80->SetMarkerStyle(25);
    h_outside_ME_cos_theta_star2_40_80->SetMarkerColor(kRed);
    h_outside_ME_cos_theta_star2_40_80->SetLineColor(kRed);

    h_outside_cos_theta_star_40_80->Draw("PE");
    h_outside_cos_theta_star2_40_80->Draw("PE same");
    h_outside_ME_cos_theta_star_40_80->Draw("PE same");
    h_outside_ME_cos_theta_star2_40_80->Draw("PE same");

    TLegend *legend_L0_L0_out_40_80 = new TLegend(0.12, 0.15, 0.4, 0.35);
    legend_L0_L0_out_40_80->SetTextSize(0.03);
    legend_L0_L0_out_40_80->SetBorderSize(0);
    legend_L0_L0_out_40_80->SetFillStyle(0);

    legend_L0_L0_out_40_80->AddEntry(h_outside_cos_theta_star_40_80, "US-US SE #Lambda#Lambda Pairs", "p");
    legend_L0_L0_out_40_80->AddEntry(h_outside_cos_theta_star2_40_80, "US-LS SE #Lambda#Lambda Pairs", "p");
    legend_L0_L0_out_40_80->AddEntry(h_outside_ME_cos_theta_star_40_80, "US-US ME #Lambda#Lambda Pairs", "p");
    legend_L0_L0_out_40_80->AddEntry(h_outside_ME_cos_theta_star2_40_80, "US-LS ME #Lambda#Lambda Pairs", "p");

    legend_L0_L0_out_40_80->Draw();

    c9->cd(6);
    h_outside_cos_theta_star5_40_80->SetStats(0);
    h_outside_cos_theta_star5_40_80->SetMinimum(-0.25);
    h_outside_cos_theta_star5_40_80->SetMarkerStyle(20);
    h_outside_cos_theta_star5_40_80->SetMarkerColor(kBlue);
    h_outside_cos_theta_star5_40_80->SetTitle("SE and ME #bar{#Lambda}#bar{#Lambda} Pairs outside #DeltaR (40-80% Centrality); cos(#theta*); dN/dCos(#theta*)"); 
    h_outside_cos_theta_star5_40_80->GetXaxis()->CenterTitle();
    h_outside_cos_theta_star5_40_80->GetYaxis()->CenterTitle();

    h_outside_cos_theta_star6_40_80->SetStats(0);
    h_outside_cos_theta_star6_40_80->SetMinimum(0);
    h_outside_cos_theta_star6_40_80->SetMarkerStyle(20);
    h_outside_cos_theta_star6_40_80->SetMarkerColor(kRed);
    h_outside_cos_theta_star6_40_80->SetLineColor(kRed);

    h_outside_ME_cos_theta_star5_40_80->SetStats(0);
    h_outside_ME_cos_theta_star5_40_80->SetMinimum(0);
    h_outside_ME_cos_theta_star5_40_80->SetMarkerStyle(25);
    h_outside_ME_cos_theta_star5_40_80->SetMarkerColor(kBlue);

    h_outside_ME_cos_theta_star6_40_80->SetStats(0);
    h_outside_ME_cos_theta_star6_40_80->SetMinimum(0);
    h_outside_ME_cos_theta_star6_40_80->SetMarkerStyle(25);
    h_outside_ME_cos_theta_star6_40_80->SetMarkerColor(kRed);
    h_outside_ME_cos_theta_star6_40_80->SetLineColor(kRed);

    h_outside_cos_theta_star5_40_80->Draw("PE");
    h_outside_cos_theta_star6_40_80->Draw("PE same");
    h_outside_ME_cos_theta_star5_40_80->Draw("PE same");
    h_outside_ME_cos_theta_star6_40_80->Draw("PE same");

    TLegend *legend_L0bar_L0bar_out_40_80 = new TLegend(0.12, 0.15, 0.4, 0.35);
    legend_L0bar_L0bar_out_40_80->SetTextSize(0.03);
    legend_L0bar_L0bar_out_40_80->SetBorderSize(0);
    legend_L0bar_L0bar_out_40_80->SetFillStyle(0);

    legend_L0bar_L0bar_out_40_80->AddEntry(h_outside_cos_theta_star5_40_80, "US-US SE #bar{#Lambda}#bar{#Lambda} Pairs", "p");
    legend_L0bar_L0bar_out_40_80->AddEntry(h_outside_cos_theta_star6_40_80, "US-LS SE #bar{#Lambda}#bar{#Lambda} Pairs", "p");
    legend_L0bar_L0bar_out_40_80->AddEntry(h_outside_ME_cos_theta_star5_40_80, "US-US ME #bar{#Lambda}#bar{#Lambda} Pairs", "p");
    legend_L0bar_L0bar_out_40_80->AddEntry(h_outside_ME_cos_theta_star6_40_80, "US-LS ME #bar{#Lambda}#bar{#Lambda} Pairs", "p");

    legend_L0bar_L0bar_out_0_10->Draw();

    cout << "Canvas 9 Complete" << endl;

    TCanvas *c10 = new TCanvas("c10", "c10- Centrality", 1800, 900);
    c10->Divide(3,2);

    double counts_cos_0_10 = h_cos_theta_star_0_10->Integral();
    double counts_cos2_0_10 = h_cos_theta_star2_0_10->Integral();
    double counts_cos3_0_10 = h_cos_theta_star3_0_10->Integral();
    double counts_cos4_0_10 = h_cos_theta_star4_0_10->Integral();
    double counts_cos5_0_10 = h_cos_theta_star5_0_10->Integral();
    double counts_cos6_0_10 = h_cos_theta_star6_0_10->Integral();

    cout << "   " << endl;
    cout << "Check on Kristen's Data: Counts after the normalization is applied" << endl;
    cout << "US_US L0-L0bar Pairs: " << counts_cos3_0_10 << endl;
    cout << "US_LS L0-L0bar Pairs: " << counts_cos4_0_10 << endl;
    cout << "US_US L0-L0 Pairs: " << counts_cos_0_10 << endl;
    cout << "US_LS L0-L0 Pairs: " << counts_cos2_0_10 << endl;
    cout << "US_US L0bar-L0bar Pairs: " << counts_cos5_0_10 << endl;
    cout << "US_LS L0bar-L0bar Pairs: " << counts_cos6_0_10 << endl;

    double counts_out_cos_0_10 = h_outside_cos_theta_star_0_10->Integral();
    double counts_out_cos2_0_10 = h_outside_cos_theta_star2_0_10->Integral();
    double counts_out_cos3_0_10 = h_outside_cos_theta_star3_0_10->Integral();
    double counts_out_cos4_0_10 = h_outside_cos_theta_star4_0_10->Integral();
    double counts_out_cos5_0_10 = h_outside_cos_theta_star5_0_10->Integral();
    double counts_out_cos6_0_10 = h_outside_cos_theta_star6_0_10->Integral();

    double constant_value = 0.747 * (-0.757); 
    double constant_value_2 = 0.747 * (0.747);
    double constant_value_3 = (-0.757) * (-0.757);

    double const_val_errors = (0.009) * (0.004);
    double const_val_errors_2 = (0.009) * (0.009);
    double const_val_errors_3 = (0.004) * (0.004);

    cout << "   " << endl;
    cout << "Canvas 10 Polarization Calculations" << endl;

    c10->cd(1);
    cout << "   " << endl;
    cout << "Pad 1: L0-L0bar Pairs" << endl;

    TH1D *h_correct_cos_theta_star_L0_L0bar_0_10 = (TH1D*)h_cos_theta_star3_0_10->Clone("h_correct_cos_theta_star_L0_L0bar_0_10");
    h_correct_cos_theta_star_L0_L0bar_0_10->Divide(h_ME_cos_theta_star3_0_10);

    TH1D *h_correct_cos_theta_star_L0_L0bar_2_0_10 = (TH1D*)h_cos_theta_star4_0_10->Clone("h_correct_cos_theta_star_L0_L0bar_2_0_10");
    h_correct_cos_theta_star_L0_L0bar_2_0_10->Divide(h_ME_cos_theta_star4_0_10);

    double counts_correct_cos_3_0_10 = h_correct_cos_theta_star_L0_L0bar_0_10->Integral();
    double counts_correct_cos_4_0_10 = h_correct_cos_theta_star_L0_L0bar_2_0_10->Integral();

    h_correct_cos_theta_star_L0_L0bar_0_10->Scale(1.0 / counts_correct_cos_3_0_10);
    h_correct_cos_theta_star_L0_L0bar_0_10->Scale(counts_cos3_0_10);

    h_correct_cos_theta_star_L0_L0bar_2_0_10->Scale(1.0 / counts_correct_cos_4_0_10);
    h_correct_cos_theta_star_L0_L0bar_2_0_10->Scale(counts_cos4_0_10);

    TF1 *fit_correct_cos_theta_star_L0_L0bar_0_10 = new TF1("fit_correct_cos_theta_star_L0_L0bar_0_10", "[0] * (1 + [1] * x)", -1, 1);
    fit_correct_cos_theta_star_L0_L0bar_0_10->SetParameters(1, 1);
    h_correct_cos_theta_star_L0_L0bar_0_10->Fit(fit_correct_cos_theta_star_L0_L0bar_0_10, "R");

    double A2_divided_0_10 = fit_correct_cos_theta_star_L0_L0bar_0_10->GetParameter(0);
    double B2_divided_0_10 = fit_correct_cos_theta_star_L0_L0bar_0_10->GetParameter(1);
    double B2_error_0_10 = fit_correct_cos_theta_star_L0_L0bar_0_10->GetParError(1);
    cout << "   " << endl;
    cout << "Fit Parameters: Kristen's corrected L0-L0bar Pairs (us-us):" << endl;
    cout << "A: " << A2_divided_0_10 << endl;
    cout << "B: " << B2_divided_0_10 << endl;

    double P_llbar_0_10 = B2_divided_0_10 / constant_value;
    double P_llbar_error_0_10 = B2_error_0_10 / constant_value;
    std::cout << "Polarization (L0-L0Bar): " << P_llbar_0_10 << " ± " << P_llbar_error_0_10 << std::endl; 

    TF1 *fit_correct_cos_theta_star_L0_L0bar_2_0_10 = new TF1("fit_correct_cos_theta_star_L0_L0bar_2_0_10", "[0] * (1 + [1] * x)", -1, 1);
    fit_correct_cos_theta_star_L0_L0bar_2_0_10->SetParameters(1, 1);
    h_correct_cos_theta_star_L0_L0bar_2_0_10->Fit(fit_correct_cos_theta_star_L0_L0bar_2_0_10, "R");

    double A102_divided_0_10 = fit_correct_cos_theta_star_L0_L0bar_2_0_10->GetParameter(0);
    double B102_divided_0_10 = fit_correct_cos_theta_star_L0_L0bar_2_0_10->GetParameter(1);
    cout << "Fit Parameters: Kristen's corrected L0-L0bar Pairs (us-ls):" << endl;
    cout << "A: " << A102_divided_0_10 << endl;
    cout << "B: " << B102_divided_0_10 << endl;

    h_correct_cos_theta_star_L0_L0bar_0_10->SetStats(0);
    h_correct_cos_theta_star_L0_L0bar_0_10->SetMinimum(0);
    h_correct_cos_theta_star_L0_L0bar_0_10->SetMarkerStyle(20);
    h_correct_cos_theta_star_L0_L0bar_0_10->SetMarkerColor(kBlue);
    h_correct_cos_theta_star_L0_L0bar_0_10->SetTitle("#Lambda#bar{#Lambda} Pairs Inside #DeltaR (0-10% Centrality); cos(#theta*); dN/dCos(#theta*)"); 
    h_correct_cos_theta_star_L0_L0bar_0_10->GetXaxis()->CenterTitle();
    h_correct_cos_theta_star_L0_L0bar_0_10->GetYaxis()->CenterTitle();

    h_correct_cos_theta_star_L0_L0bar_2_0_10->SetStats(0);
    h_correct_cos_theta_star_L0_L0bar_2_0_10->SetMinimum(0);
    h_correct_cos_theta_star_L0_L0bar_2_0_10->SetMarkerStyle(20);
    h_correct_cos_theta_star_L0_L0bar_2_0_10->SetMarkerColor(kRed);
    h_correct_cos_theta_star_L0_L0bar_2_0_10->SetLineColor(kRed);

    h_correct_cos_theta_star_L0_L0bar_0_10->Draw("PE");
    h_correct_cos_theta_star_L0_L0bar_2_0_10->Draw("PE same");

    TLegend *legend_correct_L0_L0bar_0_10 = new TLegend(0.12, 0.45, 0.4, 0.55);
    legend_correct_L0_L0bar_0_10->SetTextSize(0.03);
    legend_correct_L0_L0bar_0_10->SetBorderSize(0);
    legend_correct_L0_L0bar_0_10->SetFillStyle(0);

    legend_correct_L0_L0bar_0_10->AddEntry(h_correct_cos_theta_star_L0_L0bar_0_10, "US-US #Lambda#bar{#Lambda} Pairs", "p");
    legend_correct_L0_L0bar_0_10->AddEntry(h_correct_cos_theta_star_L0_L0bar_2_0_10, "US-LS #Lambda#bar{#Lambda} Pairs", "p");

    legend_correct_L0_L0bar_0_10->Draw();

    c10->cd(2);
    cout << "   " << endl;
    cout << "Pad 2: L0-L0 Pairs" << endl;
    
    TH1D *h_correct_cos_theta_star_L0_L0_0_10 = (TH1D*)h_cos_theta_star_0_10->Clone("h_correct_cos_theta_star_L0_L0_0_10");
    h_correct_cos_theta_star_L0_L0_0_10->Divide(h_ME_cos_theta_star_0_10);

    TH1D *h_correct_cos_theta_star_L0_L0_2_0_10 = (TH1D*)h_cos_theta_star2_0_10->Clone("h_correct_cos_theta_star_L0_L0_2_0_10");
    h_correct_cos_theta_star_L0_L0_2_0_10->Divide(h_ME_cos_theta_star2_0_10);

    double counts_correct_cos_0_10 = h_correct_cos_theta_star_L0_L0_0_10->Integral();
    double counts_correct_cos_2_0_10 = h_correct_cos_theta_star_L0_L0_2_0_10->Integral();

    h_correct_cos_theta_star_L0_L0_0_10->Scale(1.0 / counts_correct_cos_0_10);
    h_correct_cos_theta_star_L0_L0_0_10->Scale(counts_cos_0_10);

    h_correct_cos_theta_star_L0_L0_2_0_10->Scale(1.0 / counts_correct_cos_2_0_10);
    h_correct_cos_theta_star_L0_L0_2_0_10->Scale(counts_cos2_0_10);

    TF1 *fit_correct_cos_theta_star_L0_L0_0_10 = new TF1("fit_correct_cos_theta_star_L0_L0_0_10", "[0] * (1 + [1] * x)", -1, 1);
    fit_correct_cos_theta_star_L0_L0_0_10->SetParameters(1, 1);
    h_correct_cos_theta_star_L0_L0_0_10->Fit(fit_correct_cos_theta_star_L0_L0_0_10, "R");

    double A_divided_0_10 = fit_correct_cos_theta_star_L0_L0_0_10->GetParameter(0);
    double B_divided_0_10 = fit_correct_cos_theta_star_L0_L0_0_10->GetParameter(1);
    double B_error_0_10 = fit_correct_cos_theta_star_L0_L0_0_10->GetParameter(1);
    cout << "   " << endl;
    cout << "Fit Parameters: Kristen's corrected L0-L0 Pairs (us-us):" << endl;
    cout << "A: " << A_divided_0_10 << endl;
    cout << "B: " << B_divided_0_10 << endl;

    double P_ll_0_10 = B_divided_0_10 / constant_value_2;
    double P_ll_error_0_10 = B_error_0_10 / constant_value_2;
    cout << "Polarization (LL): " << P_ll_0_10 << " ± " << P_ll_error_0_10 << endl;

    TF1 *fit_correct_cos_theta_star_L0_L0_2_0_10 = new TF1("fit_correct_cos_theta_star_L0_L0_2_0_10", "[0] * (1 + [1] * x)", -1, 1);
    fit_correct_cos_theta_star_L0_L0_2_0_10->SetParameters(1, 1);
    h_correct_cos_theta_star_L0_L0_2_0_10->Fit(fit_correct_cos_theta_star_L0_L0_2_0_10, "R");

    double A100_divided_0_10 = fit_correct_cos_theta_star_L0_L0_2_0_10->GetParameter(0);
    double B100_divided_0_10 = fit_correct_cos_theta_star_L0_L0_2_0_10->GetParameter(1);
    cout << "Fit Parameters: Kristen's corrected L0-L0 Pairs (us-ls):" << endl;
    cout << "A: " << A100_divided_0_10 << endl;
    cout << "B: " << B100_divided_0_10 << endl;

    h_correct_cos_theta_star_L0_L0_0_10->SetStats(0);
    h_correct_cos_theta_star_L0_L0_0_10->SetMinimum(0);
    h_correct_cos_theta_star_L0_L0_0_10->SetMarkerStyle(20);
    h_correct_cos_theta_star_L0_L0_0_10->SetMarkerColor(kBlue);
    h_correct_cos_theta_star_L0_L0_0_10->SetTitle("#Lambda#Lambda Pairs Inside #DeltaR (0-10% Centrality); cos(#theta*); dN/dCos(#theta*)"); 
    h_correct_cos_theta_star_L0_L0_0_10->GetXaxis()->CenterTitle();
    h_correct_cos_theta_star_L0_L0_0_10->GetYaxis()->CenterTitle();

    h_correct_cos_theta_star_L0_L0_2_0_10->SetStats(0);
    h_correct_cos_theta_star_L0_L0_2_0_10->SetMinimum(0);
    h_correct_cos_theta_star_L0_L0_2_0_10->SetMarkerStyle(20);
    h_correct_cos_theta_star_L0_L0_2_0_10->SetMarkerColor(kRed);
    h_correct_cos_theta_star_L0_L0_2_0_10->SetLineColor(kRed);

    h_correct_cos_theta_star_L0_L0_0_10->Draw("PE");
    h_correct_cos_theta_star_L0_L0_2_0_10->Draw("PE same");

    TLegend *legend_correct_L0_L0_0_10 = new TLegend(0.12, 0.45, 0.4, 0.55);
    legend_correct_L0_L0_0_10->SetTextSize(0.03);
    legend_correct_L0_L0_0_10->SetBorderSize(0);
    legend_correct_L0_L0_0_10->SetFillStyle(0);

    legend_correct_L0_L0_0_10->AddEntry(h_correct_cos_theta_star_L0_L0_0_10, "US-US #Lambda#Lambda Pairs", "p");
    legend_correct_L0_L0_0_10->AddEntry(h_correct_cos_theta_star_L0_L0_2_0_10, "US-LS #Lambda#Lambda Pairs", "p");

    legend_correct_L0_L0_0_10->Draw();

    c10->cd(3);
    cout << "   " << endl;
    cout << "Pad 3: L0bar-L0bar Pairs" << endl;

    TH1D *h_correct_cos_theta_star_L0bar_L0bar_0_10 = (TH1D*)h_cos_theta_star5_0_10->Clone("h_correct_cos_theta_star_L0bar_L0bar_0_10");
    h_correct_cos_theta_star_L0bar_L0bar_0_10->Divide(h_ME_cos_theta_star5_0_10);

    TH1D *h_correct_cos_theta_star_L0bar_L0bar_2_0_10 = (TH1D*)h_cos_theta_star6_0_10->Clone("h_correct_cos_theta_star_L0bar_L0bar_2_0_10");
    h_correct_cos_theta_star_L0bar_L0bar_2_0_10->Divide(h_ME_cos_theta_star6_0_10);

    double counts_correct_cos_5_0_10 = h_correct_cos_theta_star_L0bar_L0bar_0_10->Integral();
    double counts_correct_cos_6_0_10 = h_correct_cos_theta_star_L0bar_L0bar_2_0_10->Integral();

    h_correct_cos_theta_star_L0bar_L0bar_0_10->Scale(1.0 / counts_correct_cos_5_0_10);
    h_correct_cos_theta_star_L0bar_L0bar_0_10->Scale(counts_cos5_0_10);

    h_correct_cos_theta_star_L0bar_L0bar_2_0_10->Scale(1.0 / counts_correct_cos_6_0_10);
    h_correct_cos_theta_star_L0bar_L0bar_2_0_10->Scale(counts_cos6_0_10);    

    TF1 *fit_correct_cos_theta_star_L0bar_L0bar_0_10 = new TF1("fit_correct_cos_theta_star_L0bar_L0bar_0_10", "[0] * (1 + [1] * x)", -1, 1);
    fit_correct_cos_theta_star_L0bar_L0bar_0_10->SetParameters(1, 1);
    h_correct_cos_theta_star_L0bar_L0bar_0_10->Fit(fit_correct_cos_theta_star_L0bar_L0bar_0_10, "R");

    double A3_divided_0_10 = fit_correct_cos_theta_star_L0bar_L0bar_0_10->GetParameter(0);
    double B3_divided_0_10 = fit_correct_cos_theta_star_L0bar_L0bar_0_10->GetParameter(1);
    double B3_error_0_10 = fit_correct_cos_theta_star_L0bar_L0bar_0_10->GetParError(1);
    cout << "   " << endl;
    cout << "Fit Parameters: Kristen's corrected L0bar-L0bar Pairs (us-us):" << endl;
    cout << "A: " << A3_divided_0_10 << endl;
    cout << "B: " << B3_divided_0_10 << endl; 

    double P_lbarlbar_0_10 = B3_divided_0_10 / constant_value_3;
    double P_lbarlbar_error_0_10 = B3_error_0_10 / constant_value_3;
    std::cout << "Polarization (LBarLBar): " << P_lbarlbar_0_10 << " ± " << P_lbarlbar_error_0_10 << std::endl;   

    TF1 *fit_correct_cos_theta_star_L0bar_L0bar_2_0_10 = new TF1("fit_correct_cos_theta_star_L0bar_L0bar_2_0_10", "[0] * (1 + [1] * x)", -1, 1);
    fit_correct_cos_theta_star_L0bar_L0bar_2_0_10->SetParameters(1, 1);
    h_correct_cos_theta_star_L0bar_L0bar_2_0_10->Fit(fit_correct_cos_theta_star_L0bar_L0bar_2_0_10, "R");

    double A103_divided_0_10 = fit_correct_cos_theta_star_L0bar_L0bar_2_0_10->GetParameter(0);
    double B103_divided_0_10 = fit_correct_cos_theta_star_L0bar_L0bar_2_0_10->GetParameter(1);
    cout << "Fit Parameters: Kristen's corrected L0bar-L0bar Pairs (us-ls):" << endl;
    cout << "A: " << A103_divided_0_10 << endl;
    cout << "B: " << B103_divided_0_10 << endl;  

    h_correct_cos_theta_star_L0bar_L0bar_0_10->SetStats(0);
    h_correct_cos_theta_star_L0bar_L0bar_0_10->SetMinimum(0);
    h_correct_cos_theta_star_L0bar_L0bar_0_10->SetMarkerStyle(20);
    h_correct_cos_theta_star_L0bar_L0bar_0_10->SetMarkerColor(kBlue);
    h_correct_cos_theta_star_L0bar_L0bar_0_10->SetTitle("#bar{#Lambda}#bar{#Lambda} Pairs Inside #DeltaR  (0-10% Centrality); cos(#theta*); dN/dCos(#theta*)"); 
    h_correct_cos_theta_star_L0bar_L0bar_0_10->GetXaxis()->CenterTitle();
    h_correct_cos_theta_star_L0bar_L0bar_0_10->GetYaxis()->CenterTitle();

    h_correct_cos_theta_star_L0bar_L0bar_2_0_10->SetStats(0);
    h_correct_cos_theta_star_L0bar_L0bar_2_0_10->SetMinimum(0);
    h_correct_cos_theta_star_L0bar_L0bar_2_0_10->SetMarkerStyle(20);
    h_correct_cos_theta_star_L0bar_L0bar_2_0_10->SetMarkerColor(kRed);
    h_correct_cos_theta_star_L0bar_L0bar_2_0_10->SetLineColor(kRed);

    h_correct_cos_theta_star_L0bar_L0bar_0_10->Draw("PE");
    h_correct_cos_theta_star_L0bar_L0bar_2_0_10->Draw("PE same");

    TLegend *legend_correct_L0bar_L0bar_0_10 = new TLegend(0.12, 0.45, 0.4, 0.55);
    legend_correct_L0bar_L0bar_0_10->SetTextSize(0.03);
    legend_correct_L0bar_L0bar_0_10->SetBorderSize(0);
    legend_correct_L0bar_L0bar_0_10->SetFillStyle(0);

    legend_correct_L0bar_L0bar_0_10->AddEntry(h_correct_cos_theta_star_L0bar_L0bar_0_10, "US-US #bar{#Lambda}#bar{#Lambda} Pairs", "p");
    legend_correct_L0bar_L0bar_0_10->AddEntry(h_correct_cos_theta_star_L0bar_L0bar_2_0_10, "US-LS #bar{#Lambda}#bar{#Lambda} Pairs", "p");

    legend_correct_L0bar_L0bar_0_10->Draw();

    c10->cd(4);
    cout << "   " << endl;
    cout << "Pad 4: L0-L0bar Pairs" << endl;

    TH1D *h_correct_outside_cos_theta_star_L0_L0bar_0_10 =(TH1D*)h_outside_cos_theta_star3_0_10->Clone("h_correct_outside_cos_theta_star_L0_L0bar_0_10");
    h_correct_outside_cos_theta_star_L0_L0bar_0_10->Divide(h_outside_ME_cos_theta_star3_0_10);

    TH1D *h_correct_outside_cos_theta_star_L0_L0bar_2_0_10 =(TH1D*)h_outside_cos_theta_star4_0_10->Clone("h_correct_outside_cos_theta_star_L0_L0bar_2_0_10");
    h_correct_outside_cos_theta_star_L0_L0bar_2_0_10->Divide(h_outside_ME_cos_theta_star4_0_10);

    double counts_correct_out_cos_3_0_10 = h_correct_outside_cos_theta_star_L0_L0bar_0_10->Integral();
    double counts_correct_out_cos_4_0_10 = h_correct_outside_cos_theta_star_L0_L0bar_2_0_10->Integral();

    h_correct_outside_cos_theta_star_L0_L0bar_0_10->Scale(1.0 / counts_correct_out_cos_3_0_10);
    h_correct_outside_cos_theta_star_L0_L0bar_0_10->Scale(counts_out_cos3_0_10);

    h_correct_outside_cos_theta_star_L0_L0bar_2_0_10->Scale(1.0 / counts_correct_out_cos_4_0_10);
    h_correct_outside_cos_theta_star_L0_L0bar_2_0_10->Scale(counts_out_cos4_0_10); 

    TF1 *fit_correct_outside_cos_theta_star_L0_L0bar_0_10 = new TF1("fit_correct_outside_cos_theta_star_L0_L0bar_0_10", "[0] * (1 + [1] * x)", -1, 1);
    fit_correct_outside_cos_theta_star_L0_L0bar_0_10->SetParameters(1, 1);
    h_correct_outside_cos_theta_star_L0_L0bar_0_10->Fit(fit_correct_outside_cos_theta_star_L0_L0bar_0_10, "R");

    double A12_divided_0_10 = fit_correct_outside_cos_theta_star_L0_L0bar_0_10->GetParameter(0);
    double B12_divided_0_10 = fit_correct_outside_cos_theta_star_L0_L0bar_0_10->GetParameter(1);
    double B12_error_0_10 = fit_correct_outside_cos_theta_star_L0_L0bar_0_10->GetParError(1);
    cout << "   " << endl;
    cout << "Fit Parameters: Kristen's corrected L0-L0bar Pairs outside #DeltaR (us-us):" << endl;
    cout << "A: " << A12_divided_0_10 << endl;
    cout << "B: " << B12_divided_0_10 << endl;

    double P_llbar_outside_0_10 = B12_divided_0_10 /= constant_value;
    double P_llbar_outside_error_0_10 = B12_error_0_10 /= constant_value;
    std::cout << "Polarization (LLBar): " << P_llbar_outside_0_10 << " ± " << P_llbar_outside_error_0_10 << std::endl;

    TF1 *fit_correct_outside_cos_theta_star_L0_L0bar_2_0_10 = new TF1("fit_correct_outside_cos_theta_star_L0_L0bar_2_0_10", "[0] * (1 + [1] * x)", -1, 1);
    fit_correct_outside_cos_theta_star_L0_L0bar_2_0_10->SetParameters(1, 1);
    h_correct_outside_cos_theta_star_L0_L0bar_2_0_10->Fit(fit_correct_outside_cos_theta_star_L0_L0bar_2_0_10, "R");

    double A112_divided_0_10 = fit_correct_outside_cos_theta_star_L0_L0bar_2_0_10->GetParameter(0);
    double B112_divided_0_10= fit_correct_outside_cos_theta_star_L0_L0bar_2_0_10->GetParameter(1);
    cout << "Fit Parameters: Kristen's corrected L0-L0bar Pairs outside #DeltaR (us-ls):" << endl;
    cout << "A: " << A112_divided_0_10 << endl;
    cout << "B: " << B112_divided_0_10 << endl;

    h_correct_outside_cos_theta_star_L0_L0bar_0_10->SetStats(0);
    h_correct_outside_cos_theta_star_L0_L0bar_0_10->SetMinimum(0);
    h_correct_outside_cos_theta_star_L0_L0bar_0_10->SetMarkerStyle(20);
    h_correct_outside_cos_theta_star_L0_L0bar_0_10->SetMarkerColor(kBlue);
    h_correct_outside_cos_theta_star_L0_L0bar_0_10->SetTitle("#Lambda#bar{#Lambda} Pairs Outside #DeltaR (0-10% Centrality); cos(#theta*); dN/dCos(#theta*)"); 
    h_correct_outside_cos_theta_star_L0_L0bar_0_10->GetXaxis()->CenterTitle();
    h_correct_outside_cos_theta_star_L0_L0bar_0_10->GetYaxis()->CenterTitle();

    h_correct_outside_cos_theta_star_L0_L0bar_2_0_10->SetStats(0);
    h_correct_outside_cos_theta_star_L0_L0bar_2_0_10->SetMinimum(0);
    h_correct_outside_cos_theta_star_L0_L0bar_2_0_10->SetMarkerStyle(20);
    h_correct_outside_cos_theta_star_L0_L0bar_2_0_10->SetMarkerColor(kRed);
    h_correct_outside_cos_theta_star_L0_L0bar_2_0_10->SetLineColor(kRed);

    h_correct_outside_cos_theta_star_L0_L0bar_0_10->Draw("PE");
    h_correct_outside_cos_theta_star_L0_L0bar_2_0_10->Draw("PE same");

    TLegend *legend_correct_out_L0_L0bar_0_10 = new TLegend(0.12, 0.25, 0.4, 0.35);
    legend_correct_out_L0_L0bar_0_10->SetTextSize(0.03);
    legend_correct_out_L0_L0bar_0_10->SetBorderSize(0);
    legend_correct_out_L0_L0bar_0_10->SetFillStyle(0);

    legend_correct_out_L0_L0bar_0_10->AddEntry(h_correct_outside_cos_theta_star_L0_L0bar_0_10, "US-US #Lambda#bar{#Lambda} Pairs", "p");
    legend_correct_out_L0_L0bar_0_10->AddEntry(h_correct_outside_cos_theta_star_L0_L0bar_2_0_10, "US-LS #Lambda#bar{#Lambda} Pairs", "p");

    legend_correct_out_L0_L0bar_0_10->Draw();

    c10->cd(5);
    cout << "   " << endl;
    cout << "Pad 5: L0-L0 Pairs" << endl;

    TH1D *h_correct_outside_cos_theta_star_L0_L0_0_10 = (TH1D*)h_outside_cos_theta_star_0_10->Clone("h_correct_outside_cos_theta_star_L0_L0_0_10");
    h_correct_outside_cos_theta_star_L0_L0_0_10->Divide(h_outside_ME_cos_theta_star_0_10);

    TH1D *h_correct_outside_cos_theta_star_L0_L0_2_0_10 = (TH1D*)h_outside_cos_theta_star2_0_10->Clone("h_correct_outside_cos_theta_star_L0_L0_2_0_10");
    h_correct_outside_cos_theta_star_L0_L0_2_0_10->Divide(h_outside_ME_cos_theta_star2_0_10);

    double counts_correct_out_cos_0_10 = h_correct_outside_cos_theta_star_L0_L0_0_10->Integral();
    double counts_correct_out_cos_2_0_10 = h_correct_outside_cos_theta_star_L0_L0_2_0_10->Integral();

    h_correct_outside_cos_theta_star_L0_L0_0_10->Scale(1.0 / counts_correct_out_cos_0_10);
    h_correct_outside_cos_theta_star_L0_L0_0_10->Scale(counts_out_cos_0_10);

    h_correct_outside_cos_theta_star_L0_L0_2_0_10->Scale(1.0 / counts_correct_out_cos_2_0_10);
    h_correct_outside_cos_theta_star_L0_L0_2_0_10->Scale(counts_out_cos2_0_10);

    TF1 *fit_correct_outside_cos_theta_star_L0_L0_0_10 = new TF1("fit_correct_outside_cos_theta_star_L0_L0_0_10", "[0] * (1 + [1] * x)", -1, 1);
    fit_correct_outside_cos_theta_star_L0_L0_0_10->SetParameters(1, 1);
    h_correct_outside_cos_theta_star_L0_L0_0_10->Fit(fit_correct_outside_cos_theta_star_L0_L0_0_10, "R");

    double A11_divided_0_10 = fit_correct_outside_cos_theta_star_L0_L0_0_10->GetParameter(0);
    double B11_divided_0_10 = fit_correct_outside_cos_theta_star_L0_L0_0_10->GetParameter(1);
    double B11_error_0_10 = fit_correct_outside_cos_theta_star_L0_L0_0_10->GetParError(1);
    cout << "   " << endl;
    cout << "Fit Parameters: Kristen's corrected L0-L0 Pairs outside #DeltaR (us-us):" << endl;
    cout << "A: " << A11_divided_0_10 << endl;
    cout << "B: " << B11_divided_0_10 << endl; 

    double P_ll_outside_0_10 = B11_divided_0_10 /= constant_value_2;
    double P_ll_outside_error_0_10 = B11_error_0_10 /= constant_value_2;
    std::cout << "Polarization (LL): " << P_ll_outside_0_10 << " ± " << P_ll_outside_error_0_10 << std::endl;

    TF1 *fit_correct_outside_cos_theta_star_L0_L0_2_0_10 = new TF1("fit_correct_outside_cos_theta_star_L0_L0_2_0_10", "[0] * (1 + [1] * x)", -1, 1);
    fit_correct_outside_cos_theta_star_L0_L0_2_0_10->SetParameters(1, 1);
    h_correct_outside_cos_theta_star_L0_L0_2_0_10->Fit(fit_correct_outside_cos_theta_star_L0_L0_2_0_10, "R");

    double A111_divided_0_10 = fit_correct_outside_cos_theta_star_L0_L0_2_0_10->GetParameter(0);
    double B111_divided_0_10 = fit_correct_outside_cos_theta_star_L0_L0_2_0_10->GetParameter(1);
    cout << "Fit Parameters: Kristen's corrected L0-L0 Pairs outside #DeltaR (us-ls):" << endl;
    cout << "A: " << A111_divided_0_10 << endl;
    cout << "B: " << B111_divided_0_10 << endl; 

    h_correct_outside_cos_theta_star_L0_L0_0_10->SetStats(0);
    h_correct_outside_cos_theta_star_L0_L0_0_10->SetMinimum(0);
    h_correct_outside_cos_theta_star_L0_L0_0_10->SetMarkerStyle(20);
    h_correct_outside_cos_theta_star_L0_L0_0_10->SetMarkerColor(kBlue);
    h_correct_outside_cos_theta_star_L0_L0_0_10->SetTitle("#Lambda#Lambda Pairs Outside #DeltaR (0-10% Centrality); cos(#theta*); dN/dCos(#theta*)"); 
    h_correct_outside_cos_theta_star_L0_L0_0_10->GetXaxis()->CenterTitle();
    h_correct_outside_cos_theta_star_L0_L0_0_10->GetYaxis()->CenterTitle();

    h_correct_outside_cos_theta_star_L0_L0_2_0_10->SetStats(0);
    h_correct_outside_cos_theta_star_L0_L0_2_0_10->SetMinimum(0);
    h_correct_outside_cos_theta_star_L0_L0_2_0_10->SetMarkerStyle(20);
    h_correct_outside_cos_theta_star_L0_L0_2_0_10->SetMarkerColor(kRed);
    h_correct_outside_cos_theta_star_L0_L0_2_0_10->SetLineColor(kRed);

    h_correct_outside_cos_theta_star_L0_L0_0_10->Draw("PE");
    h_correct_outside_cos_theta_star_L0_L0_2_0_10->Draw("PE same");

    TLegend *legend_correct_out_L0_L0_0_10 = new TLegend(0.12, 0.25, 0.4, 0.35);
    legend_correct_out_L0_L0_0_10->SetTextSize(0.03);
    legend_correct_out_L0_L0_0_10->SetBorderSize(0);
    legend_correct_out_L0_L0_0_10->SetFillStyle(0);

    legend_correct_out_L0_L0_0_10->AddEntry(h_correct_outside_cos_theta_star_L0_L0_0_10, "US-US #Lambda#Lambda Pairs", "p");
    legend_correct_out_L0_L0_0_10->AddEntry(h_correct_outside_cos_theta_star_L0_L0_2_0_10, "US-LS #Lambda#Lambda Pairs", "p");

    legend_correct_out_L0_L0_0_10->Draw();

    c10->cd(6);
    cout << "   " << endl;
    cout << "Pad 6: L0bar-L0bar Pairs" << endl;

    TH1D *h_correct_outside_cos_theta_star_L0bar_L0bar_0_10 =(TH1D*)h_outside_cos_theta_star5_0_10->Clone("h_correct_outside_cos_theta_star_L0bar_L0bar_0_10");
    h_correct_outside_cos_theta_star_L0bar_L0bar_0_10->Divide(h_outside_ME_cos_theta_star5_0_10);

    TH1D *h_correct_outside_cos_theta_star_L0bar_L0bar_2_0_10 =(TH1D*)h_outside_cos_theta_star6_0_10->Clone("h_correct_outside_cos_theta_star_L0bar_L0bar_2_0_10");
    h_correct_outside_cos_theta_star_L0bar_L0bar_2_0_10->Divide(h_outside_ME_cos_theta_star6_0_10);

    double counts_correct_out_cos_5_0_10 = h_correct_outside_cos_theta_star_L0bar_L0bar_0_10->Integral();
    double counts_correct_out_cos_6_0_10 = h_correct_outside_cos_theta_star_L0bar_L0bar_2_0_10->Integral();

    h_correct_outside_cos_theta_star_L0bar_L0bar_0_10->Scale(1.0 / counts_correct_out_cos_5_0_10);
    h_correct_outside_cos_theta_star_L0bar_L0bar_0_10->Scale(counts_out_cos5_0_10);

    h_correct_outside_cos_theta_star_L0bar_L0bar_2_0_10->Scale(1.0 / counts_correct_out_cos_6_0_10);
    h_correct_outside_cos_theta_star_L0bar_L0bar_2_0_10->Scale(counts_out_cos6_0_10);

    TF1 *fit_correct_outside_cos_theta_star_L0bar_L0bar_0_10 = new TF1("fit_correct_outside_cos_theta_star_L0bar_L0bar_0_10", "[0] * (1 + [1] * x)", -1, 1);
    fit_correct_outside_cos_theta_star_L0bar_L0bar_0_10->SetParameters(1, 1);
    h_correct_outside_cos_theta_star_L0bar_L0bar_0_10->Fit(fit_correct_outside_cos_theta_star_L0bar_L0bar_0_10, "R"); 

    double A13_divided_0_10 = fit_correct_outside_cos_theta_star_L0bar_L0bar_0_10->GetParameter(0);
    double B13_divided_0_10 = fit_correct_outside_cos_theta_star_L0bar_L0bar_0_10->GetParameter(1);
    double B13_error_0_10 = fit_correct_outside_cos_theta_star_L0bar_L0bar_0_10->GetParError(1);
    cout << "   " << endl;
    cout << "Fit Parameters: Kristen's corrected L0bar-L0bar Pairs outside #DeltaR (us-us):" << endl;
    cout << "A: " << A13_divided_0_10 << endl;
    cout << "B: " << B13_divided_0_10 << endl;

    double P_lbarlbar_outside_0_10 = B13_divided_0_10 /= constant_value_3;
    double P_lbarlbar_outside_error_0_10 = B13_error_0_10 /= constant_value_3;
    std::cout << "Polarization (LLBar): " << P_lbarlbar_outside_0_10 << " ± " << P_lbarlbar_outside_error_0_10 << std::endl;

    TF1 *fit_correct_outside_cos_theta_star_L0bar_L0bar_2_0_10 = new TF1("fit_correct_outside_cos_theta_star_L0bar_L0bar_2_0_10", "[0] * (1 + [1] * x)", -1, 1);
    fit_correct_outside_cos_theta_star_L0bar_L0bar_2_0_10->SetParameters(1, 1);
    h_correct_outside_cos_theta_star_L0bar_L0bar_2_0_10->Fit(fit_correct_outside_cos_theta_star_L0bar_L0bar_2_0_10, "R"); 

    double A113_divided_0_10 = fit_correct_outside_cos_theta_star_L0bar_L0bar_2_0_10->GetParameter(0);
    double B113_divided_0_10 = fit_correct_outside_cos_theta_star_L0bar_L0bar_2_0_10->GetParameter(1);
    cout << "Fit Parameters: Kristen's corrected L0bar-L0bar Pairs outside #DeltaR (us-ls):" << endl;
    cout << "A: " << A113_divided_0_10 << endl;
    cout << "B: " << B113_divided_0_10 << endl;

    h_correct_outside_cos_theta_star_L0bar_L0bar_0_10->SetStats(0);
    h_correct_outside_cos_theta_star_L0bar_L0bar_0_10->SetMinimum(0);
    h_correct_outside_cos_theta_star_L0bar_L0bar_0_10->SetMarkerStyle(20);
    h_correct_outside_cos_theta_star_L0bar_L0bar_0_10->SetMarkerColor(kBlue);
    h_correct_outside_cos_theta_star_L0bar_L0bar_0_10->SetTitle("#bar{#Lambda}#bar{#Lambda} Pairs Outside #DeltaR (0-10% Centrality); cos(#theta*); dN/dCos(#theta*)"); 
    h_correct_outside_cos_theta_star_L0bar_L0bar_0_10->GetXaxis()->CenterTitle();
    h_correct_outside_cos_theta_star_L0bar_L0bar_0_10->GetYaxis()->CenterTitle();

    h_correct_outside_cos_theta_star_L0bar_L0bar_2_0_10->SetStats(0);
    h_correct_outside_cos_theta_star_L0bar_L0bar_2_0_10->SetMinimum(0);
    h_correct_outside_cos_theta_star_L0bar_L0bar_2_0_10->SetMarkerStyle(20);
    h_correct_outside_cos_theta_star_L0bar_L0bar_2_0_10->SetMarkerColor(kRed);
    h_correct_outside_cos_theta_star_L0bar_L0bar_2_0_10->SetLineColor(kRed);

    h_correct_outside_cos_theta_star_L0bar_L0bar_0_10->Draw("PE");
    h_correct_outside_cos_theta_star_L0bar_L0bar_2_0_10->Draw("PE same");

    TLegend *legend_correct_out_L0bar_L0bar_0_10 = new TLegend(0.12, 0.25, 0.4, 0.35);
    legend_correct_out_L0bar_L0bar_0_10->SetTextSize(0.03);
    legend_correct_out_L0bar_L0bar_0_10->SetBorderSize(0);
    legend_correct_out_L0bar_L0bar_0_10->SetFillStyle(0);

    legend_correct_out_L0bar_L0bar_0_10->AddEntry(h_correct_outside_cos_theta_star_L0bar_L0bar_0_10, "US-US #bar{#Lambda}#bar{#Lambda} Pairs", "p");
    legend_correct_out_L0bar_L0bar_0_10->AddEntry(h_correct_outside_cos_theta_star_L0bar_L0bar_2_0_10, "US-LS #bar{#Lambda}#bar{#Lambda} Pairs", "p");

    legend_correct_out_L0bar_L0bar_0_10->Draw();

    cout << "Canvas 10 Complete" << endl;

    TCanvas *c11 = new TCanvas("c11", "c11- 10-40% Centrality", 1800, 900);
    c11->Divide(3,2);

    double counts_cos_10_40 = h_cos_theta_star_10_40->Integral();
    double counts_cos2_10_40 = h_cos_theta_star2_10_40->Integral();
    double counts_cos3_10_40 = h_cos_theta_star3_10_40->Integral();
    double counts_cos4_10_40 = h_cos_theta_star4_10_40->Integral();
    double counts_cos5_10_40 = h_cos_theta_star5_10_40->Integral();
    double counts_cos6_10_40 = h_cos_theta_star6_10_40->Integral();

    cout << "   " << endl;
    cout << "Check on Kristen's Data: Counts after the normalization is applied" << endl;
    cout << "US_US L0-L0bar Pairs: " << counts_cos3_10_40 << endl;
    cout << "US_LS L0-L0bar Pairs: " << counts_cos4_10_40 << endl;
    cout << "US_US L0-L0 Pairs: " << counts_cos_10_40 << endl;
    cout << "US_LS L0-L0 Pairs: " << counts_cos2_10_40 << endl;
    cout << "US_US L0bar-L0bar Pairs: " << counts_cos5_10_40 << endl;
    cout << "US_LS L0bar-L0bar Pairs: " << counts_cos6_10_40 << endl;

    double counts_out_cos_10_40 = h_outside_cos_theta_star_10_40->Integral();
    double counts_out_cos2_10_40 = h_outside_cos_theta_star2_10_40->Integral();
    double counts_out_cos3_10_40 = h_outside_cos_theta_star3_10_40->Integral();
    double counts_out_cos4_10_40 = h_outside_cos_theta_star4_10_40->Integral();
    double counts_out_cos5_10_40 = h_outside_cos_theta_star5_10_40->Integral();
    double counts_out_cos6_10_40 = h_outside_cos_theta_star6_10_40->Integral();

    cout << "   " << endl;
    cout << "Canvas 11 Polarization Calculations" << endl;

    c11->cd(1);
    cout << "   " << endl;
    cout << "Pad 1: L0-L0bar Pairs" << endl;

    TH1D *h_correct_cos_theta_star_L0_L0bar_10_40 = (TH1D*)h_cos_theta_star3_10_40->Clone("h_correct_cos_theta_star_L0_L0bar_10_40");
    h_correct_cos_theta_star_L0_L0bar_10_40->Divide(h_ME_cos_theta_star3_10_40);

    TH1D *h_correct_cos_theta_star_L0_L0bar_2_10_40 = (TH1D*)h_cos_theta_star4_10_40->Clone("h_correct_cos_theta_star_L0_L0bar_2_10_40");
    h_correct_cos_theta_star_L0_L0bar_2_10_40->Divide(h_ME_cos_theta_star4_10_40);

    double counts_correct_cos_3_10_40 = h_correct_cos_theta_star_L0_L0bar_10_40->Integral();
    double counts_correct_cos_4_10_40 = h_correct_cos_theta_star_L0_L0bar_2_10_40->Integral();

    h_correct_cos_theta_star_L0_L0bar_10_40->Scale(1.0 / counts_correct_cos_3_10_40);
    h_correct_cos_theta_star_L0_L0bar_10_40->Scale(counts_cos3_10_40);

    h_correct_cos_theta_star_L0_L0bar_2_10_40->Scale(1.0 / counts_correct_cos_4_10_40);
    h_correct_cos_theta_star_L0_L0bar_2_10_40->Scale(counts_cos4_10_40);

    TF1 *fit_correct_cos_theta_star_L0_L0bar_10_40 = new TF1("fit_correct_cos_theta_star_L0_L0bar_10_40", "[0] * (1 + [1] * x)", -1, 1);
    fit_correct_cos_theta_star_L0_L0bar_10_40->SetParameters(1, 1);
    h_correct_cos_theta_star_L0_L0bar_10_40->Fit(fit_correct_cos_theta_star_L0_L0bar_10_40, "R");

    double A2_divided_10_40 = fit_correct_cos_theta_star_L0_L0bar_10_40->GetParameter(0);
    double B2_divided_10_40 = fit_correct_cos_theta_star_L0_L0bar_10_40->GetParameter(1);
    double B2_error_10_40 = fit_correct_cos_theta_star_L0_L0bar_10_40->GetParError(1);
    cout << "   " << endl;
    cout << "Fit Parameters: Kristen's corrected L0-L0bar Pairs (us-us):" << endl;
    cout << "A: " << A2_divided_10_40 << endl;
    cout << "B: " << B2_divided_10_40 << endl;

    double P_llbar_10_40 = B2_divided_10_40 / constant_value;
    double P_llbar_error_10_40 = B2_error_10_40 / constant_value;
    std::cout << "Polarization (L0-L0Bar): " << P_llbar_10_40 << " ± " << P_llbar_error_10_40 << std::endl; 

    TF1 *fit_correct_cos_theta_star_L0_L0bar_2_10_40 = new TF1("fit_correct_cos_theta_star_L0_L0bar_2_10_40", "[0] * (1 + [1] * x)", -1, 1);
    fit_correct_cos_theta_star_L0_L0bar_2_10_40->SetParameters(1, 1);
    h_correct_cos_theta_star_L0_L0bar_2_10_40->Fit(fit_correct_cos_theta_star_L0_L0bar_2_10_40, "R");

    double A102_divided_10_40 = fit_correct_cos_theta_star_L0_L0bar_2_10_40->GetParameter(0);
    double B102_divided_10_40 = fit_correct_cos_theta_star_L0_L0bar_2_10_40->GetParameter(1);
    cout << "Fit Parameters: Kristen's corrected L0-L0bar Pairs (us-ls):" << endl;
    cout << "A: " << A102_divided_10_40 << endl;
    cout << "B: " << B102_divided_10_40 << endl;

    h_correct_cos_theta_star_L0_L0bar_10_40->SetStats(0);
    h_correct_cos_theta_star_L0_L0bar_10_40->SetMinimum(0);
    h_correct_cos_theta_star_L0_L0bar_10_40->SetMarkerStyle(20);
    h_correct_cos_theta_star_L0_L0bar_10_40->SetMarkerColor(kBlue);
    h_correct_cos_theta_star_L0_L0bar_10_40->SetTitle("#Lambda#bar{#Lambda} Pairs Inside #DeltaR (10-40% Centrality); cos(#theta*); dN/dCos(#theta*)"); 
    h_correct_cos_theta_star_L0_L0bar_10_40->GetXaxis()->CenterTitle();
    h_correct_cos_theta_star_L0_L0bar_10_40->GetYaxis()->CenterTitle();

    h_correct_cos_theta_star_L0_L0bar_2_10_40->SetStats(0);
    h_correct_cos_theta_star_L0_L0bar_2_10_40->SetMinimum(0);
    h_correct_cos_theta_star_L0_L0bar_2_10_40->SetMarkerStyle(20);
    h_correct_cos_theta_star_L0_L0bar_2_10_40->SetMarkerColor(kRed);
    h_correct_cos_theta_star_L0_L0bar_2_10_40->SetLineColor(kRed);

    h_correct_cos_theta_star_L0_L0bar_10_40->Draw("PE");
    h_correct_cos_theta_star_L0_L0bar_2_10_40->Draw("PE same");

    TLegend *legend_correct_L0_L0bar_10_40 = new TLegend(0.12, 0.4, 0.4, 0.5);
    legend_correct_L0_L0bar_10_40->SetTextSize(0.03);
    legend_correct_L0_L0bar_10_40->SetBorderSize(0);
    legend_correct_L0_L0bar_10_40->SetFillStyle(0);

    legend_correct_L0_L0bar_10_40->AddEntry(h_correct_cos_theta_star_L0_L0bar_10_40, "US-US #Lambda#bar{#Lambda} Pairs", "p");
    legend_correct_L0_L0bar_10_40->AddEntry(h_correct_cos_theta_star_L0_L0bar_2_10_40, "US-LS #Lambda#bar{#Lambda} Pairs", "p");

    legend_correct_L0_L0bar_10_40->Draw();

    c11->cd(2);
    cout << "   " << endl;
    cout << "Pad 2: L0-L0 Pairs" << endl;
    
    TH1D *h_correct_cos_theta_star_L0_L0_10_40 = (TH1D*)h_cos_theta_star_10_40->Clone("h_correct_cos_theta_star_L0_L0_10_40");
    h_correct_cos_theta_star_L0_L0_10_40->Divide(h_ME_cos_theta_star_10_40);

    TH1D *h_correct_cos_theta_star_L0_L0_2_10_40 = (TH1D*)h_cos_theta_star2_10_40->Clone("h_correct_cos_theta_star_L0_L0_2_10_40");
    h_correct_cos_theta_star_L0_L0_2_10_40->Divide(h_ME_cos_theta_star2_10_40);

    double counts_correct_cos_10_40 = h_correct_cos_theta_star_L0_L0_10_40->Integral();
    double counts_correct_cos_2_10_40 = h_correct_cos_theta_star_L0_L0_2_10_40->Integral();

    h_correct_cos_theta_star_L0_L0_10_40->Scale(1.0 / counts_correct_cos_10_40);
    h_correct_cos_theta_star_L0_L0_10_40->Scale(counts_cos_10_40);

    h_correct_cos_theta_star_L0_L0_2_10_40->Scale(1.0 / counts_correct_cos_2_10_40);
    h_correct_cos_theta_star_L0_L0_2_10_40->Scale(counts_cos2_10_40);

    TF1 *fit_correct_cos_theta_star_L0_L0_10_40 = new TF1("fit_correct_cos_theta_star_L0_L0_10_40", "[0] * (1 + [1] * x)", -1, 1);
    fit_correct_cos_theta_star_L0_L0_10_40->SetParameters(1, 1);
    h_correct_cos_theta_star_L0_L0_10_40->Fit(fit_correct_cos_theta_star_L0_L0_10_40, "R");

    double A_divided_10_40 = fit_correct_cos_theta_star_L0_L0_10_40->GetParameter(0);
    double B_divided_10_40 = fit_correct_cos_theta_star_L0_L0_10_40->GetParameter(1);
    double B_error_10_40 = fit_correct_cos_theta_star_L0_L0_10_40->GetParameter(1);
    cout << "   " << endl;
    cout << "Fit Parameters: Kristen's corrected L0-L0 Pairs (us-us):" << endl;
    cout << "A: " << A_divided_10_40 << endl;
    cout << "B: " << B_divided_10_40 << endl;

    double P_ll_10_40 = B_divided_10_40 / constant_value_2;
    double P_ll_error_10_40 = B_error_10_40 / constant_value_2;
    cout << "Polarization (LL): " << P_ll_10_40 << " ± " << P_ll_error_10_40 << endl;

    TF1 *fit_correct_cos_theta_star_L0_L0_2_10_40 = new TF1("fit_correct_cos_theta_star_L0_L0_2_10_40", "[0] * (1 + [1] * x)", -1, 1);
    fit_correct_cos_theta_star_L0_L0_2_10_40->SetParameters(1, 1);
    h_correct_cos_theta_star_L0_L0_2_10_40->Fit(fit_correct_cos_theta_star_L0_L0_2_10_40, "R");

    double A100_divided_10_40 = fit_correct_cos_theta_star_L0_L0_2_10_40->GetParameter(0);
    double B100_divided_10_40 = fit_correct_cos_theta_star_L0_L0_2_10_40->GetParameter(1);
    cout << "Fit Parameters: Kristen's corrected L0-L0 Pairs (us-ls):" << endl;
    cout << "A: " << A100_divided_10_40 << endl;
    cout << "B: " << B100_divided_10_40 << endl;

    h_correct_cos_theta_star_L0_L0_10_40->SetStats(0);
    h_correct_cos_theta_star_L0_L0_10_40->SetMinimum(0);
    h_correct_cos_theta_star_L0_L0_10_40->SetMarkerStyle(20);
    h_correct_cos_theta_star_L0_L0_10_40->SetMarkerColor(kBlue);
    h_correct_cos_theta_star_L0_L0_10_40->SetTitle("#Lambda#Lambda Pairs Inside #DeltaR (10-40% Centrality); cos(#theta*); dN/dCos(#theta*)"); 
    h_correct_cos_theta_star_L0_L0_10_40->GetXaxis()->CenterTitle();
    h_correct_cos_theta_star_L0_L0_10_40->GetYaxis()->CenterTitle();

    h_correct_cos_theta_star_L0_L0_2_10_40->SetStats(0);
    h_correct_cos_theta_star_L0_L0_2_10_40->SetMinimum(0);
    h_correct_cos_theta_star_L0_L0_2_10_40->SetMarkerStyle(20);
    h_correct_cos_theta_star_L0_L0_2_10_40->SetMarkerColor(kRed);
    h_correct_cos_theta_star_L0_L0_2_10_40->SetLineColor(kRed);

    h_correct_cos_theta_star_L0_L0_10_40->Draw("PE");
    h_correct_cos_theta_star_L0_L0_2_10_40->Draw("PE same");

    TLegend *legend_correct_L0_L0_10_40 = new TLegend(0.12, 0.4, 0.4, 0.5);
    legend_correct_L0_L0_10_40->SetTextSize(0.03);
    legend_correct_L0_L0_10_40->SetBorderSize(0);
    legend_correct_L0_L0_10_40->SetFillStyle(0);

    legend_correct_L0_L0_10_40->AddEntry(h_correct_cos_theta_star_L0_L0_10_40, "US-US #Lambda#Lambda Pairs", "p");
    legend_correct_L0_L0_10_40->AddEntry(h_correct_cos_theta_star_L0_L0_2_10_40, "US-LS #Lambda#Lambda Pairs", "p");

    legend_correct_L0_L0_10_40->Draw();

    c11->cd(3);
    cout << "   " << endl;
    cout << "Pad 3: L0bar-L0bar Pairs" << endl;

    TH1D *h_correct_cos_theta_star_L0bar_L0bar_10_40 = (TH1D*)h_cos_theta_star5_10_40->Clone("h_correct_cos_theta_star_L0bar_L0bar_10_40");
    h_correct_cos_theta_star_L0bar_L0bar_10_40->Divide(h_ME_cos_theta_star5_10_40);

    TH1D *h_correct_cos_theta_star_L0bar_L0bar_2_10_40 = (TH1D*)h_cos_theta_star6_10_40->Clone("h_correct_cos_theta_star_L0bar_L0bar_2_10_40");
    h_correct_cos_theta_star_L0bar_L0bar_2_10_40->Divide(h_ME_cos_theta_star6_10_40);

    double counts_correct_cos_5_10_40 = h_correct_cos_theta_star_L0bar_L0bar_10_40->Integral();
    double counts_correct_cos_6_10_40 = h_correct_cos_theta_star_L0bar_L0bar_2_10_40->Integral();

    h_correct_cos_theta_star_L0bar_L0bar_10_40->Scale(1.0 / counts_correct_cos_5_10_40);
    h_correct_cos_theta_star_L0bar_L0bar_10_40->Scale(counts_cos5_10_40);

    h_correct_cos_theta_star_L0bar_L0bar_2_10_40->Scale(1.0 / counts_correct_cos_6_10_40);
    h_correct_cos_theta_star_L0bar_L0bar_2_10_40->Scale(counts_cos6_10_40);    

    TF1 *fit_correct_cos_theta_star_L0bar_L0bar_10_40 = new TF1("fit_correct_cos_theta_star_L0bar_L0bar_10_40", "[0] * (1 + [1] * x)", -1, 1);
    fit_correct_cos_theta_star_L0bar_L0bar_10_40->SetParameters(1, 1);
    h_correct_cos_theta_star_L0bar_L0bar_10_40->Fit(fit_correct_cos_theta_star_L0bar_L0bar_10_40, "R");

    double A3_divided_10_40 = fit_correct_cos_theta_star_L0bar_L0bar_10_40->GetParameter(0);
    double B3_divided_10_40 = fit_correct_cos_theta_star_L0bar_L0bar_10_40->GetParameter(1);
    double B3_error_10_40 = fit_correct_cos_theta_star_L0bar_L0bar_10_40->GetParError(1);
    cout << "   " << endl;
    cout << "Fit Parameters: Kristen's corrected L0bar-L0bar Pairs (us-us):" << endl;
    cout << "A: " << A3_divided_10_40 << endl;
    cout << "B: " << B3_divided_10_40 << endl; 

    double P_lbarlbar_10_40 = B3_divided_10_40 / constant_value_3;
    double P_lbarlbar_error_10_40 = B3_error_10_40 / constant_value_3;
    std::cout << "Polarization (LBarLBar): " << P_lbarlbar_10_40 << " ± " << P_lbarlbar_error_10_40 << std::endl;   

    TF1 *fit_correct_cos_theta_star_L0bar_L0bar_2_10_40 = new TF1("fit_correct_cos_theta_star_L0bar_L0bar_2_10_40", "[0] * (1 + [1] * x)", -1, 1);
    fit_correct_cos_theta_star_L0bar_L0bar_2_10_40->SetParameters(1, 1);
    h_correct_cos_theta_star_L0bar_L0bar_2_10_40->Fit(fit_correct_cos_theta_star_L0bar_L0bar_2_10_40, "R");

    double A103_divided_10_40 = fit_correct_cos_theta_star_L0bar_L0bar_2_10_40->GetParameter(0);
    double B103_divided_10_40 = fit_correct_cos_theta_star_L0bar_L0bar_2_10_40->GetParameter(1);
    cout << "Fit Parameters: Kristen's corrected L0bar-L0bar Pairs (us-ls):" << endl;
    cout << "A: " << A103_divided_10_40 << endl;
    cout << "B: " << B103_divided_10_40 << endl;  

    h_correct_cos_theta_star_L0bar_L0bar_10_40->SetStats(0);
    h_correct_cos_theta_star_L0bar_L0bar_10_40->SetMinimum(0);
    h_correct_cos_theta_star_L0bar_L0bar_10_40->SetMarkerStyle(20);
    h_correct_cos_theta_star_L0bar_L0bar_10_40->SetMarkerColor(kBlue);
    h_correct_cos_theta_star_L0bar_L0bar_10_40->SetTitle("#bar{#Lambda}#bar{#Lambda} Pairs Inside #DeltaR  (10-40% Centrality); cos(#theta*); dN/dCos(#theta*)"); 
    h_correct_cos_theta_star_L0bar_L0bar_10_40->GetXaxis()->CenterTitle();
    h_correct_cos_theta_star_L0bar_L0bar_10_40->GetYaxis()->CenterTitle();

    h_correct_cos_theta_star_L0bar_L0bar_2_10_40->SetStats(0);
    h_correct_cos_theta_star_L0bar_L0bar_2_10_40->SetMinimum(0);
    h_correct_cos_theta_star_L0bar_L0bar_2_10_40->SetMarkerStyle(20);
    h_correct_cos_theta_star_L0bar_L0bar_2_10_40->SetMarkerColor(kRed);
    h_correct_cos_theta_star_L0bar_L0bar_2_10_40->SetLineColor(kRed);

    h_correct_cos_theta_star_L0bar_L0bar_10_40->Draw("PE");
    h_correct_cos_theta_star_L0bar_L0bar_2_10_40->Draw("PE same");

    TLegend *legend_correct_L0bar_L0bar_10_40 = new TLegend(0.12, 0.4, 0.4, 0.5);
    legend_correct_L0bar_L0bar_10_40->SetTextSize(0.03);
    legend_correct_L0bar_L0bar_10_40->SetBorderSize(0);
    legend_correct_L0bar_L0bar_10_40->SetFillStyle(0);

    legend_correct_L0bar_L0bar_10_40->AddEntry(h_correct_cos_theta_star_L0bar_L0bar_10_40, "US-US #bar{#Lambda}#bar{#Lambda} Pairs", "p");
    legend_correct_L0bar_L0bar_10_40->AddEntry(h_correct_cos_theta_star_L0bar_L0bar_2_10_40, "US-LS #bar{#Lambda}#bar{#Lambda} Pairs", "p");

    legend_correct_L0bar_L0bar_10_40->Draw();

    c11->cd(4);
    cout << "   " << endl;
    cout << "Pad 4: L0-L0bar Pairs" << endl;

    TH1D *h_correct_outside_cos_theta_star_L0_L0bar_10_40 =(TH1D*)h_outside_cos_theta_star3_10_40->Clone("h_correct_outside_cos_theta_star_L0_L0bar_10_40");
    h_correct_outside_cos_theta_star_L0_L0bar_10_40->Divide(h_outside_ME_cos_theta_star3_10_40);

    TH1D *h_correct_outside_cos_theta_star_L0_L0bar_2_10_40 =(TH1D*)h_outside_cos_theta_star4_10_40->Clone("h_correct_outside_cos_theta_star_L0_L0bar_2_10_40");
    h_correct_outside_cos_theta_star_L0_L0bar_2_10_40->Divide(h_outside_ME_cos_theta_star4_10_40);

    double counts_correct_out_cos_3_10_40 = h_correct_outside_cos_theta_star_L0_L0bar_10_40->Integral();
    double counts_correct_out_cos_4_10_40 = h_correct_outside_cos_theta_star_L0_L0bar_2_10_40->Integral();

    h_correct_outside_cos_theta_star_L0_L0bar_10_40->Scale(1.0 / counts_correct_out_cos_3_10_40);
    h_correct_outside_cos_theta_star_L0_L0bar_10_40->Scale(counts_out_cos3_10_40);

    h_correct_outside_cos_theta_star_L0_L0bar_2_10_40->Scale(1.0 / counts_correct_out_cos_4_10_40);
    h_correct_outside_cos_theta_star_L0_L0bar_2_10_40->Scale(counts_out_cos4_10_40); 

    TF1 *fit_correct_outside_cos_theta_star_L0_L0bar_10_40 = new TF1("fit_correct_outside_cos_theta_star_L0_L0bar_10_40", "[0] * (1 + [1] * x)", -1, 1);
    fit_correct_outside_cos_theta_star_L0_L0bar_10_40->SetParameters(1, 1);
    h_correct_outside_cos_theta_star_L0_L0bar_10_40->Fit(fit_correct_outside_cos_theta_star_L0_L0bar_10_40, "R");

    double A12_divided_10_40 = fit_correct_outside_cos_theta_star_L0_L0bar_10_40->GetParameter(0);
    double B12_divided_10_40 = fit_correct_outside_cos_theta_star_L0_L0bar_10_40->GetParameter(1);
    double B12_error_10_40 = fit_correct_outside_cos_theta_star_L0_L0bar_10_40->GetParError(1);
    cout << "   " << endl;
    cout << "Fit Parameters: Kristen's corrected L0-L0bar Pairs outside #DeltaR (us-us):" << endl;
    cout << "A: " << A12_divided_10_40 << endl;
    cout << "B: " << B12_divided_10_40 << endl;

    double P_llbar_outside_10_40 = B12_divided_10_40 /= constant_value;
    double P_llbar_outside_error_10_40 = B12_error_10_40 /= constant_value;
    std::cout << "Polarization (LLBar): " << P_llbar_outside_10_40 << " ± " << P_llbar_outside_error_10_40 << std::endl;

    TF1 *fit_correct_outside_cos_theta_star_L0_L0bar_2_10_40 = new TF1("fit_correct_outside_cos_theta_star_L0_L0bar_2_10_40", "[0] * (1 + [1] * x)", -1, 1);
    fit_correct_outside_cos_theta_star_L0_L0bar_2_10_40->SetParameters(1, 1);
    h_correct_outside_cos_theta_star_L0_L0bar_2_10_40->Fit(fit_correct_outside_cos_theta_star_L0_L0bar_2_10_40, "R");

    double A112_divided_10_40 = fit_correct_outside_cos_theta_star_L0_L0bar_2_10_40->GetParameter(0);
    double B112_divided_10_40 = fit_correct_outside_cos_theta_star_L0_L0bar_2_10_40->GetParameter(1);
    cout << "Fit Parameters: Kristen's corrected L0-L0bar Pairs outside #DeltaR (us-ls):" << endl;
    cout << "A: " << A112_divided_10_40 << endl;
    cout << "B: " << B112_divided_10_40 << endl;

    h_correct_outside_cos_theta_star_L0_L0bar_10_40->SetStats(0);
    h_correct_outside_cos_theta_star_L0_L0bar_10_40->SetMinimum(0);
    h_correct_outside_cos_theta_star_L0_L0bar_10_40->SetMarkerStyle(20);
    h_correct_outside_cos_theta_star_L0_L0bar_10_40->SetMarkerColor(kBlue);
    h_correct_outside_cos_theta_star_L0_L0bar_10_40->SetTitle("#Lambda#bar{#Lambda} Pairs Outside #DeltaR (10-40% Centrality); cos(#theta*); dN/dCos(#theta*)"); 
    h_correct_outside_cos_theta_star_L0_L0bar_10_40->GetXaxis()->CenterTitle();
    h_correct_outside_cos_theta_star_L0_L0bar_10_40->GetYaxis()->CenterTitle();

    h_correct_outside_cos_theta_star_L0_L0bar_2_10_40->SetStats(0);
    h_correct_outside_cos_theta_star_L0_L0bar_2_10_40->SetMinimum(0);
    h_correct_outside_cos_theta_star_L0_L0bar_2_10_40->SetMarkerStyle(20);
    h_correct_outside_cos_theta_star_L0_L0bar_2_10_40->SetMarkerColor(kRed);
    h_correct_outside_cos_theta_star_L0_L0bar_2_10_40->SetLineColor(kRed);

    h_correct_outside_cos_theta_star_L0_L0bar_10_40->Draw("PE");
    h_correct_outside_cos_theta_star_L0_L0bar_2_10_40->Draw("PE same");

    TLegend *legend_correct_out_L0_L0bar_10_40 = new TLegend(0.12, 0.4, 0.4, 0.5);
    legend_correct_out_L0_L0bar_10_40->SetTextSize(0.03);
    legend_correct_out_L0_L0bar_10_40->SetBorderSize(0);
    legend_correct_out_L0_L0bar_10_40->SetFillStyle(0);

    legend_correct_out_L0_L0bar_10_40->AddEntry(h_correct_outside_cos_theta_star_L0_L0bar_10_40, "US-US #Lambda#bar{#Lambda} Pairs", "p");
    legend_correct_out_L0_L0bar_10_40->AddEntry(h_correct_outside_cos_theta_star_L0_L0bar_2_10_40, "US-LS #Lambda#bar{#Lambda} Pairs", "p");

    legend_correct_out_L0_L0bar_10_40->Draw();

    c11->cd(5);
    cout << "   " << endl;
    cout << "Pad 5: L0-L0 Pairs" << endl;

    TH1D *h_correct_outside_cos_theta_star_L0_L0_10_40 = (TH1D*)h_outside_cos_theta_star_10_40->Clone("h_correct_outside_cos_theta_star_L0_L0_10_40");
    h_correct_outside_cos_theta_star_L0_L0_10_40->Divide(h_outside_ME_cos_theta_star_10_40);

    TH1D *h_correct_outside_cos_theta_star_L0_L0_2_10_40 = (TH1D*)h_outside_cos_theta_star2_10_40->Clone("h_correct_outside_cos_theta_star_L0_L0_2_10_40");
    h_correct_outside_cos_theta_star_L0_L0_2_10_40->Divide(h_outside_ME_cos_theta_star2_10_40);

    double counts_correct_out_cos_10_40 = h_correct_outside_cos_theta_star_L0_L0_10_40->Integral();
    double counts_correct_out_cos_2_10_40 = h_correct_outside_cos_theta_star_L0_L0_2_10_40->Integral();

    h_correct_outside_cos_theta_star_L0_L0_10_40->Scale(1.0 / counts_correct_out_cos_10_40);
    h_correct_outside_cos_theta_star_L0_L0_10_40->Scale(counts_out_cos_10_40);

    h_correct_outside_cos_theta_star_L0_L0_2_10_40->Scale(1.0 / counts_correct_out_cos_2_10_40);
    h_correct_outside_cos_theta_star_L0_L0_2_10_40->Scale(counts_out_cos2_10_40);

    TF1 *fit_correct_outside_cos_theta_star_L0_L0_10_40 = new TF1("fit_correct_outside_cos_theta_star_L0_L0_10_40", "[0] * (1 + [1] * x)", -1, 1);
    fit_correct_outside_cos_theta_star_L0_L0_10_40->SetParameters(1, 1);
    h_correct_outside_cos_theta_star_L0_L0_10_40->Fit(fit_correct_outside_cos_theta_star_L0_L0_10_40, "R");

    double A11_divided_10_40 = fit_correct_outside_cos_theta_star_L0_L0_10_40->GetParameter(0);
    double B11_divided_10_40 = fit_correct_outside_cos_theta_star_L0_L0_10_40->GetParameter(1);
    double B11_error_10_40 = fit_correct_outside_cos_theta_star_L0_L0_10_40->GetParError(1);
    cout << "   " << endl;
    cout << "Fit Parameters: Kristen's corrected L0-L0 Pairs outside #DeltaR (us-us):" << endl;
    cout << "A: " << A11_divided_10_40 << endl;
    cout << "B: " << B11_divided_10_40 << endl; 

    double P_ll_outside_10_40 = B11_divided_10_40 /= constant_value_2;
    double P_ll_outside_error_10_40 = B11_error_10_40 /= constant_value_2;
    std::cout << "Polarization (LL): " << P_ll_outside_10_40 << " ± " << P_ll_outside_error_10_40 << std::endl;

    TF1 *fit_correct_outside_cos_theta_star_L0_L0_2_10_40 = new TF1("fit_correct_outside_cos_theta_star_L0_L0_2_10_40", "[0] * (1 + [1] * x)", -1, 1);
    fit_correct_outside_cos_theta_star_L0_L0_2_10_40->SetParameters(1, 1);
    h_correct_outside_cos_theta_star_L0_L0_2_10_40->Fit(fit_correct_outside_cos_theta_star_L0_L0_2_10_40, "R");

    double A111_divided_10_40 = fit_correct_outside_cos_theta_star_L0_L0_2_10_40->GetParameter(0);
    double B111_divided_10_40 = fit_correct_outside_cos_theta_star_L0_L0_2_10_40->GetParameter(1);
    cout << "Fit Parameters: Kristen's corrected L0-L0 Pairs outside #DeltaR (us-ls):" << endl;
    cout << "A: " << A111_divided_10_40 << endl;
    cout << "B: " << B111_divided_10_40 << endl; 

    h_correct_outside_cos_theta_star_L0_L0_10_40->SetStats(0);
    h_correct_outside_cos_theta_star_L0_L0_10_40->SetMinimum(0);
    h_correct_outside_cos_theta_star_L0_L0_10_40->SetMarkerStyle(20);
    h_correct_outside_cos_theta_star_L0_L0_10_40->SetMarkerColor(kBlue);
    h_correct_outside_cos_theta_star_L0_L0_10_40->SetTitle("#Lambda#Lambda Pairs Outside #DeltaR (10-40% Centrality); cos(#theta*); dN/dCos(#theta*)"); 
    h_correct_outside_cos_theta_star_L0_L0_10_40->GetXaxis()->CenterTitle();
    h_correct_outside_cos_theta_star_L0_L0_10_40->GetYaxis()->CenterTitle();

    h_correct_outside_cos_theta_star_L0_L0_2_10_40->SetStats(0);
    h_correct_outside_cos_theta_star_L0_L0_2_10_40->SetMinimum(0);
    h_correct_outside_cos_theta_star_L0_L0_2_10_40->SetMarkerStyle(20);
    h_correct_outside_cos_theta_star_L0_L0_2_10_40->SetMarkerColor(kRed);
    h_correct_outside_cos_theta_star_L0_L0_2_10_40->SetLineColor(kRed);

    h_correct_outside_cos_theta_star_L0_L0_10_40->Draw("PE");
    h_correct_outside_cos_theta_star_L0_L0_2_10_40->Draw("PE same");

    TLegend *legend_correct_out_L0_L0_10_40 = new TLegend(0.12, 0.4, 0.4, 0.5);
    legend_correct_out_L0_L0_10_40->SetTextSize(0.03);
    legend_correct_out_L0_L0_10_40->SetBorderSize(0);
    legend_correct_out_L0_L0_10_40->SetFillStyle(0);

    legend_correct_out_L0_L0_10_40->AddEntry(h_correct_outside_cos_theta_star_L0_L0_10_40, "US-US #Lambda#Lambda Pairs", "p");
    legend_correct_out_L0_L0_10_40->AddEntry(h_correct_outside_cos_theta_star_L0_L0_2_10_40, "US-LS #Lambda#Lambda Pairs", "p");

    legend_correct_out_L0_L0_10_40->Draw();

    c11->cd(6);
    cout << "   " << endl;
    cout << "Pad 6: L0bar-L0bar Pairs" << endl;

    TH1D *h_correct_outside_cos_theta_star_L0bar_L0bar_10_40 =(TH1D*)h_outside_cos_theta_star5_10_40->Clone("h_correct_outside_cos_theta_star_L0bar_L0bar_10_40");
    h_correct_outside_cos_theta_star_L0bar_L0bar_10_40->Divide(h_outside_ME_cos_theta_star5_10_40);

    TH1D *h_correct_outside_cos_theta_star_L0bar_L0bar_2_10_40 =(TH1D*)h_outside_cos_theta_star6_10_40->Clone("h_correct_outside_cos_theta_star_L0bar_L0bar_2_10_40");
    h_correct_outside_cos_theta_star_L0bar_L0bar_2_10_40->Divide(h_outside_ME_cos_theta_star6_10_40);

    double counts_correct_out_cos_5_10_40 = h_correct_outside_cos_theta_star_L0bar_L0bar_10_40->Integral();
    double counts_correct_out_cos_6_10_40 = h_correct_outside_cos_theta_star_L0bar_L0bar_2_10_40->Integral();

    h_correct_outside_cos_theta_star_L0bar_L0bar_10_40->Scale(1.0 / counts_correct_out_cos_5_10_40);
    h_correct_outside_cos_theta_star_L0bar_L0bar_10_40->Scale(counts_out_cos5_10_40);

    h_correct_outside_cos_theta_star_L0bar_L0bar_2_10_40->Scale(1.0 / counts_correct_out_cos_6_10_40);
    h_correct_outside_cos_theta_star_L0bar_L0bar_2_10_40->Scale(counts_out_cos6_10_40);

    TF1 *fit_correct_outside_cos_theta_star_L0bar_L0bar_10_40 = new TF1("fit_correct_outside_cos_theta_star_L0bar_L0bar_10_40", "[0] * (1 + [1] * x)", -1, 1);
    fit_correct_outside_cos_theta_star_L0bar_L0bar_10_40->SetParameters(1, 1);
    h_correct_outside_cos_theta_star_L0bar_L0bar_10_40->Fit(fit_correct_outside_cos_theta_star_L0bar_L0bar_10_40, "R"); 

    double A13_divided_10_40 = fit_correct_outside_cos_theta_star_L0bar_L0bar_10_40->GetParameter(0);
    double B13_divided_10_40 = fit_correct_outside_cos_theta_star_L0bar_L0bar_10_40->GetParameter(1);
    double B13_error_10_40 = fit_correct_outside_cos_theta_star_L0bar_L0bar_10_40->GetParError(1);
    cout << "   " << endl;
    cout << "Fit Parameters: Kristen's corrected L0bar-L0bar Pairs outside #DeltaR (us-us):" << endl;
    cout << "A: " << A13_divided_10_40 << endl;
    cout << "B: " << B13_divided_10_40 << endl;

    double P_lbarlbar_outside_10_40 = B13_divided_10_40 /= constant_value_3;
    double P_lbarlbar_outside_error_10_40 = B13_error_10_40 /= constant_value_3;
    std::cout << "Polarization (LLBar): " << P_lbarlbar_outside_10_40 << " ± " << P_lbarlbar_outside_error_10_40 << std::endl;

    TF1 *fit_correct_outside_cos_theta_star_L0bar_L0bar_2_10_40 = new TF1("fit_correct_outside_cos_theta_star_L0bar_L0bar_2_10_40", "[0] * (1 + [1] * x)", -1, 1);
    fit_correct_outside_cos_theta_star_L0bar_L0bar_2_10_40->SetParameters(1, 1);
    h_correct_outside_cos_theta_star_L0bar_L0bar_2_10_40->Fit(fit_correct_outside_cos_theta_star_L0bar_L0bar_2_10_40, "R"); 

    double A113_divided_10_40 = fit_correct_outside_cos_theta_star_L0bar_L0bar_2_10_40->GetParameter(0);
    double B113_divided_10_40 = fit_correct_outside_cos_theta_star_L0bar_L0bar_2_10_40->GetParameter(1);
    cout << "Fit Parameters: Kristen's corrected L0bar-L0bar Pairs outside #DeltaR (us-ls):" << endl;
    cout << "A: " << A113_divided_10_40 << endl;
    cout << "B: " << B113_divided_10_40 << endl;

    h_correct_outside_cos_theta_star_L0bar_L0bar_10_40->SetStats(0);
    h_correct_outside_cos_theta_star_L0bar_L0bar_10_40->SetMinimum(0);
    h_correct_outside_cos_theta_star_L0bar_L0bar_10_40->SetMarkerStyle(20);
    h_correct_outside_cos_theta_star_L0bar_L0bar_10_40->SetMarkerColor(kBlue);
    h_correct_outside_cos_theta_star_L0bar_L0bar_10_40->SetTitle("#bar{#Lambda}#bar{#Lambda} Pairs Outside #DeltaR (10-40% Centrality); cos(#theta*); dN/dCos(#theta*)"); 
    h_correct_outside_cos_theta_star_L0bar_L0bar_10_40->GetXaxis()->CenterTitle();
    h_correct_outside_cos_theta_star_L0bar_L0bar_10_40->GetYaxis()->CenterTitle();

    h_correct_outside_cos_theta_star_L0bar_L0bar_2_10_40->SetStats(0);
    h_correct_outside_cos_theta_star_L0bar_L0bar_2_10_40->SetMinimum(0);
    h_correct_outside_cos_theta_star_L0bar_L0bar_2_10_40->SetMarkerStyle(20);
    h_correct_outside_cos_theta_star_L0bar_L0bar_2_10_40->SetMarkerColor(kRed);
    h_correct_outside_cos_theta_star_L0bar_L0bar_2_10_40->SetLineColor(kRed);

    h_correct_outside_cos_theta_star_L0bar_L0bar_10_40->Draw("PE");
    h_correct_outside_cos_theta_star_L0bar_L0bar_2_10_40->Draw("PE same");

    TLegend *legend_correct_out_L0bar_L0bar_10_40 = new TLegend(0.12, 0.4, 0.4, 0.5);
    legend_correct_out_L0bar_L0bar_10_40->SetTextSize(0.03);
    legend_correct_out_L0bar_L0bar_10_40->SetBorderSize(0);
    legend_correct_out_L0bar_L0bar_10_40->SetFillStyle(0);

    legend_correct_out_L0bar_L0bar_10_40->AddEntry(h_correct_outside_cos_theta_star_L0bar_L0bar_10_40, "US-US #bar{#Lambda}#bar{#Lambda} Pairs", "p");
    legend_correct_out_L0bar_L0bar_10_40->AddEntry(h_correct_outside_cos_theta_star_L0bar_L0bar_2_10_40, "US-LS #bar{#Lambda}#bar{#Lambda} Pairs", "p");

    legend_correct_out_L0bar_L0bar_10_40->Draw();

    cout << "Canvas 11 Complete" << endl;

    TCanvas *c12 = new TCanvas("c12", "c12- 40-80 Centrality", 1800, 900);
    c12->Divide(3,2);

    double counts_cos_40_80 = h_cos_theta_star_40_80->Integral();
    double counts_cos2_40_80 = h_cos_theta_star2_40_80->Integral();
    double counts_cos3_40_80 = h_cos_theta_star3_40_80->Integral();
    double counts_cos4_40_80 = h_cos_theta_star4_40_80->Integral();
    double counts_cos5_40_80 = h_cos_theta_star5_40_80->Integral();
    double counts_cos6_40_80 = h_cos_theta_star6_40_80->Integral();

    cout << "   " << endl;
    cout << "Check on Kristen's Data: Counts after the normalization is applied" << endl;
    cout << "US_US L0-L0bar Pairs: " << counts_cos3_40_80 << endl;
    cout << "US_LS L0-L0bar Pairs: " << counts_cos4_40_80 << endl;
    cout << "US_US L0-L0 Pairs: " << counts_cos_40_80 << endl;
    cout << "US_LS L0-L0 Pairs: " << counts_cos2_40_80 << endl;
    cout << "US_US L0bar-L0bar Pairs: " << counts_cos5_40_80 << endl;
    cout << "US_LS L0bar-L0bar Pairs: " << counts_cos6_40_80 << endl;

    double counts_out_cos_40_80 = h_outside_cos_theta_star_40_80->Integral();
    double counts_out_cos2_40_80 = h_outside_cos_theta_star2_40_80->Integral();
    double counts_out_cos3_40_80 = h_outside_cos_theta_star3_40_80->Integral();
    double counts_out_cos4_40_80 = h_outside_cos_theta_star4_40_80->Integral();
    double counts_out_cos5_40_80 = h_outside_cos_theta_star5_40_80->Integral();
    double counts_out_cos6_40_80 = h_outside_cos_theta_star6_40_80->Integral();

    cout << "   " << endl;
    cout << "Canvas 10 Polarization Calculations" << endl;

    c12->cd(1);
    cout << "   " << endl;
    cout << "Pad 1: L0-L0bar Pairs" << endl;

    TH1D *h_correct_cos_theta_star_L0_L0bar_40_80 = (TH1D*)h_cos_theta_star3_40_80->Clone("h_correct_cos_theta_star_L0_L0bar_40_80");
    h_correct_cos_theta_star_L0_L0bar_40_80->Divide(h_ME_cos_theta_star3_40_80);

    TH1D *h_correct_cos_theta_star_L0_L0bar_2_40_80 = (TH1D*)h_cos_theta_star4_40_80->Clone("h_correct_cos_theta_star_L0_L0bar_2_40_80");
    h_correct_cos_theta_star_L0_L0bar_2_40_80->Divide(h_ME_cos_theta_star4_40_80);

    double counts_correct_cos_3_40_80 = h_correct_cos_theta_star_L0_L0bar_40_80->Integral();
    double counts_correct_cos_4_40_80 = h_correct_cos_theta_star_L0_L0bar_2_40_80->Integral();

    h_correct_cos_theta_star_L0_L0bar_40_80->Scale(1.0 / counts_correct_cos_3_40_80);
    h_correct_cos_theta_star_L0_L0bar_40_80->Scale(counts_cos3_40_80);

    h_correct_cos_theta_star_L0_L0bar_2_40_80->Scale(1.0 / counts_correct_cos_4_40_80);
    h_correct_cos_theta_star_L0_L0bar_2_40_80->Scale(counts_cos4_40_80);

    TF1 *fit_correct_cos_theta_star_L0_L0bar_40_80 = new TF1("fit_correct_cos_theta_star_L0_L0bar_40_80", "[0] * (1 + [1] * x)", -1, 1);
    fit_correct_cos_theta_star_L0_L0bar_40_80->SetParameters(1, 1);
    h_correct_cos_theta_star_L0_L0bar_40_80->Fit(fit_correct_cos_theta_star_L0_L0bar_40_80, "R");

    double A2_divided_40_80 = fit_correct_cos_theta_star_L0_L0bar_40_80->GetParameter(0);
    double B2_divided_40_80 = fit_correct_cos_theta_star_L0_L0bar_40_80->GetParameter(1);
    double B2_error_40_80 = fit_correct_cos_theta_star_L0_L0bar_40_80->GetParError(1);
    cout << "   " << endl;
    cout << "Fit Parameters: Kristen's corrected L0-L0bar Pairs (us-us):" << endl;
    cout << "A: " << A2_divided_40_80 << endl;
    cout << "B: " << B2_divided_40_80 << endl;

    double P_llbar_40_80 = B2_divided_40_80 / constant_value;
    double P_llbar_error_40_80 = B2_error_40_80 / constant_value;
    std::cout << "Polarization (L0-L0Bar): " << P_llbar_40_80 << " ± " << P_llbar_error_40_80 << std::endl; 

    TF1 *fit_correct_cos_theta_star_L0_L0bar_2_40_80 = new TF1("fit_correct_cos_theta_star_L0_L0bar_2_40_80", "[0] * (1 + [1] * x)", -1, 1);
    fit_correct_cos_theta_star_L0_L0bar_2_40_80->SetParameters(1, 1);
    h_correct_cos_theta_star_L0_L0bar_2_40_80->Fit(fit_correct_cos_theta_star_L0_L0bar_2_40_80, "R");

    double A102_divided_40_80 = fit_correct_cos_theta_star_L0_L0bar_2_40_80->GetParameter(0);
    double B102_divided_40_80 = fit_correct_cos_theta_star_L0_L0bar_2_40_80->GetParameter(1);
    cout << "Fit Parameters: Kristen's corrected L0-L0bar Pairs (us-ls):" << endl;
    cout << "A: " << A102_divided_40_80 << endl;
    cout << "B: " << B102_divided_40_80 << endl;

    h_correct_cos_theta_star_L0_L0bar_40_80->SetStats(0);
    h_correct_cos_theta_star_L0_L0bar_40_80->SetMinimum(0);
    h_correct_cos_theta_star_L0_L0bar_40_80->SetMarkerStyle(20);
    h_correct_cos_theta_star_L0_L0bar_40_80->SetMarkerColor(kBlue);
    h_correct_cos_theta_star_L0_L0bar_40_80->SetTitle("#Lambda#bar{#Lambda} Pairs Inside #DeltaR (40-80% Centrality); cos(#theta*); dN/dCos(#theta*)"); 
    h_correct_cos_theta_star_L0_L0bar_40_80->GetXaxis()->CenterTitle();
    h_correct_cos_theta_star_L0_L0bar_40_80->GetYaxis()->CenterTitle();

    h_correct_cos_theta_star_L0_L0bar_2_40_80->SetStats(0);
    h_correct_cos_theta_star_L0_L0bar_2_40_80->SetMinimum(0);
    h_correct_cos_theta_star_L0_L0bar_2_40_80->SetMarkerStyle(20);
    h_correct_cos_theta_star_L0_L0bar_2_40_80->SetMarkerColor(kRed);
    h_correct_cos_theta_star_L0_L0bar_2_40_80->SetLineColor(kRed);

    h_correct_cos_theta_star_L0_L0bar_40_80->Draw("PE");
    h_correct_cos_theta_star_L0_L0bar_2_40_80->Draw("PE same");

    TLegend *legend_correct_L0_L0bar_40_80 = new TLegend(0.12, 0.25, 0.4, 0.35);
    legend_correct_L0_L0bar_40_80->SetTextSize(0.03);
    legend_correct_L0_L0bar_40_80->SetBorderSize(0);
    legend_correct_L0_L0bar_40_80->SetFillStyle(0);

    legend_correct_L0_L0bar_40_80->AddEntry(h_correct_cos_theta_star_L0_L0bar_40_80, "US-US #Lambda#bar{#Lambda} Pairs", "p");
    legend_correct_L0_L0bar_40_80->AddEntry(h_correct_cos_theta_star_L0_L0bar_2_40_80, "US-LS #Lambda#bar{#Lambda} Pairs", "p");

    legend_correct_L0_L0bar_40_80->Draw();

    c12->cd(2);
    cout << "   " << endl;
    cout << "Pad 2: L0-L0 Pairs" << endl;
    
    TH1D *h_correct_cos_theta_star_L0_L0_40_80 = (TH1D*)h_cos_theta_star_40_80->Clone("h_correct_cos_theta_star_L0_L0_40_80");
    h_correct_cos_theta_star_L0_L0_40_80->Divide(h_ME_cos_theta_star_40_80);

    TH1D *h_correct_cos_theta_star_L0_L0_2_40_80 = (TH1D*)h_cos_theta_star2_40_80->Clone("h_correct_cos_theta_star_L0_L0_2_40_80");
    h_correct_cos_theta_star_L0_L0_2_40_80->Divide(h_ME_cos_theta_star2_40_80);

    double counts_correct_cos_40_80 = h_correct_cos_theta_star_L0_L0_40_80->Integral();
    double counts_correct_cos_2_40_80 = h_correct_cos_theta_star_L0_L0_2_40_80->Integral();

    h_correct_cos_theta_star_L0_L0_40_80->Scale(1.0 / counts_correct_cos_40_80);
    h_correct_cos_theta_star_L0_L0_40_80->Scale(counts_cos_40_80);

    h_correct_cos_theta_star_L0_L0_2_40_80->Scale(1.0 / counts_correct_cos_2_40_80);
    h_correct_cos_theta_star_L0_L0_2_40_80->Scale(counts_cos2_40_80);

    TF1 *fit_correct_cos_theta_star_L0_L0_40_80 = new TF1("fit_correct_cos_theta_star_L0_L0_40_80", "[0] * (1 + [1] * x)", -1, 1);
    fit_correct_cos_theta_star_L0_L0_40_80->SetParameters(1, 1);
    h_correct_cos_theta_star_L0_L0_40_80->Fit(fit_correct_cos_theta_star_L0_L0_40_80, "R");

    double A_divided_40_80 = fit_correct_cos_theta_star_L0_L0_40_80->GetParameter(0);
    double B_divided_40_80 = fit_correct_cos_theta_star_L0_L0_40_80->GetParameter(1);
    double B_error_40_80 = fit_correct_cos_theta_star_L0_L0_40_80->GetParameter(1);
    cout << "   " << endl;
    cout << "Fit Parameters: Kristen's corrected L0-L0 Pairs (us-us):" << endl;
    cout << "A: " << A_divided_40_80 << endl;
    cout << "B: " << B_divided_40_80 << endl;

    double P_ll_40_80 = B_divided_40_80 / constant_value_2;
    double P_ll_error_40_80 = B_error_40_80 / constant_value_2;
    cout << "Polarization (LL): " << P_ll_40_80 << " ± " << P_ll_error_40_80 << endl;

    TF1 *fit_correct_cos_theta_star_L0_L0_2_40_80 = new TF1("fit_correct_cos_theta_star_L0_L0_2_40_80", "[0] * (1 + [1] * x)", -1, 1);
    fit_correct_cos_theta_star_L0_L0_2_40_80->SetParameters(1, 1);
    h_correct_cos_theta_star_L0_L0_2_40_80->Fit(fit_correct_cos_theta_star_L0_L0_2_40_80, "R");

    double A100_divided_40_80 = fit_correct_cos_theta_star_L0_L0_2_40_80->GetParameter(0);
    double B100_divided_40_80 = fit_correct_cos_theta_star_L0_L0_2_40_80->GetParameter(1);
    cout << "Fit Parameters: Kristen's corrected L0-L0 Pairs (us-ls):" << endl;
    cout << "A: " << A100_divided_40_80 << endl;
    cout << "B: " << B100_divided_40_80 << endl;

    h_correct_cos_theta_star_L0_L0_40_80->SetStats(0);
    h_correct_cos_theta_star_L0_L0_40_80->SetMinimum(0);
    h_correct_cos_theta_star_L0_L0_40_80->SetMarkerStyle(20);
    h_correct_cos_theta_star_L0_L0_40_80->SetMarkerColor(kBlue);
    h_correct_cos_theta_star_L0_L0_40_80->SetTitle("#Lambda#Lambda Pairs Inside #DeltaR (40-80% Centrality); cos(#theta*); dN/dCos(#theta*)"); 
    h_correct_cos_theta_star_L0_L0_40_80->GetXaxis()->CenterTitle();
    h_correct_cos_theta_star_L0_L0_40_80->GetYaxis()->CenterTitle();

    h_correct_cos_theta_star_L0_L0_2_40_80->SetStats(0);
    h_correct_cos_theta_star_L0_L0_2_40_80->SetMinimum(0);
    h_correct_cos_theta_star_L0_L0_2_40_80->SetMarkerStyle(20);
    h_correct_cos_theta_star_L0_L0_2_40_80->SetMarkerColor(kRed);
    h_correct_cos_theta_star_L0_L0_2_40_80->SetLineColor(kRed);

    h_correct_cos_theta_star_L0_L0_40_80->Draw("PE");
    h_correct_cos_theta_star_L0_L0_2_40_80->Draw("PE same");

    TLegend *legend_correct_L0_L0_40_80 = new TLegend(0.12, 0.25, 0.4, 0.35);
    legend_correct_L0_L0_40_80->SetTextSize(0.03);
    legend_correct_L0_L0_40_80->SetBorderSize(0);
    legend_correct_L0_L0_40_80->SetFillStyle(0);

    legend_correct_L0_L0_40_80->AddEntry(h_correct_cos_theta_star_L0_L0_40_80, "US-US #Lambda#Lambda Pairs", "p");
    legend_correct_L0_L0_40_80->AddEntry(h_correct_cos_theta_star_L0_L0_2_40_80, "US-LS #Lambda#Lambda Pairs", "p");

    legend_correct_L0_L0_40_80->Draw();

    c12->cd(3);
    cout << "   " << endl;
    cout << "Pad 3: L0bar-L0bar Pairs" << endl;

    TH1D *h_correct_cos_theta_star_L0bar_L0bar_40_80 = (TH1D*)h_cos_theta_star5_40_80->Clone("h_correct_cos_theta_star_L0bar_L0bar_40_80");
    h_correct_cos_theta_star_L0bar_L0bar_40_80->Divide(h_ME_cos_theta_star5_40_80);

    TH1D *h_correct_cos_theta_star_L0bar_L0bar_2_40_80 = (TH1D*)h_cos_theta_star6_40_80->Clone("h_correct_cos_theta_star_L0bar_L0bar_2_40_80");
    h_correct_cos_theta_star_L0bar_L0bar_2_40_80->Divide(h_ME_cos_theta_star6_40_80);

    double counts_correct_cos_5_40_80 = h_correct_cos_theta_star_L0bar_L0bar_40_80->Integral();
    double counts_correct_cos_6_40_80 = h_correct_cos_theta_star_L0bar_L0bar_2_40_80->Integral();

    h_correct_cos_theta_star_L0bar_L0bar_40_80->Scale(1.0 / counts_correct_cos_5_40_80);
    h_correct_cos_theta_star_L0bar_L0bar_40_80->Scale(counts_cos5_40_80);

    h_correct_cos_theta_star_L0bar_L0bar_2_40_80->Scale(1.0 / counts_correct_cos_6_40_80);
    h_correct_cos_theta_star_L0bar_L0bar_2_40_80->Scale(counts_cos6_40_80);    

    TF1 *fit_correct_cos_theta_star_L0bar_L0bar_40_80 = new TF1("fit_correct_cos_theta_star_L0bar_L0bar_40_80", "[0] * (1 + [1] * x)", -1, 1);
    fit_correct_cos_theta_star_L0bar_L0bar_40_80->SetParameters(1, 1);
    h_correct_cos_theta_star_L0bar_L0bar_40_80->Fit(fit_correct_cos_theta_star_L0bar_L0bar_40_80, "R");

    double A3_divided_40_80 = fit_correct_cos_theta_star_L0bar_L0bar_40_80->GetParameter(0);
    double B3_divided_40_80 = fit_correct_cos_theta_star_L0bar_L0bar_40_80->GetParameter(1);
    double B3_error_40_80 = fit_correct_cos_theta_star_L0bar_L0bar_40_80->GetParError(1);
    cout << "   " << endl;
    cout << "Fit Parameters: Kristen's corrected L0bar-L0bar Pairs (us-us):" << endl;
    cout << "A: " << A3_divided_40_80 << endl;
    cout << "B: " << B3_divided_40_80 << endl; 

    double P_lbarlbar_40_80 = B3_divided_40_80 / constant_value_3;
    double P_lbarlbar_error_40_80 = B3_error_40_80 / constant_value_3;
    std::cout << "Polarization (LBarLBar): " << P_lbarlbar_40_80 << " ± " << P_lbarlbar_error_40_80 << std::endl;   

    TF1 *fit_correct_cos_theta_star_L0bar_L0bar_2_40_80 = new TF1("fit_correct_cos_theta_star_L0bar_L0bar_2_40_80", "[0] * (1 + [1] * x)", -1, 1);
    fit_correct_cos_theta_star_L0bar_L0bar_2_40_80->SetParameters(1, 1);
    h_correct_cos_theta_star_L0bar_L0bar_2_40_80->Fit(fit_correct_cos_theta_star_L0bar_L0bar_2_40_80, "R");

    double A103_divided_40_80 = fit_correct_cos_theta_star_L0bar_L0bar_2_40_80->GetParameter(0);
    double B103_divided_40_80 = fit_correct_cos_theta_star_L0bar_L0bar_2_40_80->GetParameter(1);
    cout << "Fit Parameters: Kristen's corrected L0bar-L0bar Pairs (us-ls):" << endl;
    cout << "A: " << A103_divided_40_80 << endl;
    cout << "B: " << B103_divided_40_80 << endl;  

    h_correct_cos_theta_star_L0bar_L0bar_40_80->SetStats(0);
    h_correct_cos_theta_star_L0bar_L0bar_40_80->SetMinimum(0);
    h_correct_cos_theta_star_L0bar_L0bar_40_80->SetMarkerStyle(20);
    h_correct_cos_theta_star_L0bar_L0bar_40_80->SetMarkerColor(kBlue);
    h_correct_cos_theta_star_L0bar_L0bar_40_80->SetTitle("#bar{#Lambda}#bar{#Lambda} Pairs Inside #DeltaR  (40-80% Centrality); cos(#theta*); dN/dCos(#theta*)"); 
    h_correct_cos_theta_star_L0bar_L0bar_40_80->GetXaxis()->CenterTitle();
    h_correct_cos_theta_star_L0bar_L0bar_40_80->GetYaxis()->CenterTitle();

    h_correct_cos_theta_star_L0bar_L0bar_2_40_80->SetStats(0);
    h_correct_cos_theta_star_L0bar_L0bar_2_40_80->SetMinimum(0);
    h_correct_cos_theta_star_L0bar_L0bar_2_40_80->SetMarkerStyle(20);
    h_correct_cos_theta_star_L0bar_L0bar_2_40_80->SetMarkerColor(kRed);
    h_correct_cos_theta_star_L0bar_L0bar_2_40_80->SetLineColor(kRed);

    h_correct_cos_theta_star_L0bar_L0bar_40_80->Draw("PE");
    h_correct_cos_theta_star_L0bar_L0bar_2_40_80->Draw("PE same");

    TLegend *legend_correct_L0bar_L0bar_40_80 = new TLegend(0.12, 0.25, 0.4, 0.35);
    legend_correct_L0bar_L0bar_40_80->SetTextSize(0.03);
    legend_correct_L0bar_L0bar_40_80->SetBorderSize(0);
    legend_correct_L0bar_L0bar_40_80->SetFillStyle(0);

    legend_correct_L0bar_L0bar_40_80->AddEntry(h_correct_cos_theta_star_L0bar_L0bar_40_80, "US-US #bar{#Lambda}#bar{#Lambda} Pairs", "p");
    legend_correct_L0bar_L0bar_40_80->AddEntry(h_correct_cos_theta_star_L0bar_L0bar_2_40_80, "US-LS #bar{#Lambda}#bar{#Lambda} Pairs", "p");

    legend_correct_L0bar_L0bar_40_80->Draw();

    c12->cd(4);
    cout << "   " << endl;
    cout << "Pad 4: L0-L0bar Pairs" << endl;

    TH1D *h_correct_outside_cos_theta_star_L0_L0bar_40_80 =(TH1D*)h_outside_cos_theta_star3_40_80->Clone("h_correct_outside_cos_theta_star_L0_L0bar_40_80");
    h_correct_outside_cos_theta_star_L0_L0bar_40_80->Divide(h_outside_ME_cos_theta_star3_40_80);

    TH1D *h_correct_outside_cos_theta_star_L0_L0bar_2_40_80 =(TH1D*)h_outside_cos_theta_star4_40_80->Clone("h_correct_outside_cos_theta_star_L0_L0bar_2_40_80");
    h_correct_outside_cos_theta_star_L0_L0bar_2_40_80->Divide(h_outside_ME_cos_theta_star4_40_80);

    double counts_correct_out_cos_3_40_80 = h_correct_outside_cos_theta_star_L0_L0bar_40_80->Integral();
    double counts_correct_out_cos_4_40_80 = h_correct_outside_cos_theta_star_L0_L0bar_2_40_80->Integral();

    h_correct_outside_cos_theta_star_L0_L0bar_40_80->Scale(1.0 / counts_correct_out_cos_3_40_80);
    h_correct_outside_cos_theta_star_L0_L0bar_40_80->Scale(counts_out_cos3_40_80);

    h_correct_outside_cos_theta_star_L0_L0bar_2_40_80->Scale(1.0 / counts_correct_out_cos_4_40_80);
    h_correct_outside_cos_theta_star_L0_L0bar_2_40_80->Scale(counts_out_cos4_40_80); 

    TF1 *fit_correct_outside_cos_theta_star_L0_L0bar_40_80 = new TF1("fit_correct_outside_cos_theta_star_L0_L0bar_40_80", "[0] * (1 + [1] * x)", -1, 1);
    fit_correct_outside_cos_theta_star_L0_L0bar_40_80->SetParameters(1, 1);
    h_correct_outside_cos_theta_star_L0_L0bar_40_80->Fit(fit_correct_outside_cos_theta_star_L0_L0bar_40_80, "R");

    double A12_divided_40_80 = fit_correct_outside_cos_theta_star_L0_L0bar_40_80->GetParameter(0);
    double B12_divided_40_80 = fit_correct_outside_cos_theta_star_L0_L0bar_40_80->GetParameter(1);
    double B12_error_40_80 = fit_correct_outside_cos_theta_star_L0_L0bar_40_80->GetParError(1);
    cout << "   " << endl;
    cout << "Fit Parameters: Kristen's corrected L0-L0bar Pairs outside #DeltaR (us-us):" << endl;
    cout << "A: " << A12_divided_40_80 << endl;
    cout << "B: " << B12_divided_40_80 << endl;

    double P_llbar_outside_40_80 = B12_divided_40_80 /= constant_value;
    double P_llbar_outside_error_40_80 = B12_error_40_80 /= constant_value;
    std::cout << "Polarization (LLBar): " << P_llbar_outside_40_80 << " ± " << P_llbar_outside_error_40_80 << std::endl;

    TF1 *fit_correct_outside_cos_theta_star_L0_L0bar_2_40_80 = new TF1("fit_correct_outside_cos_theta_star_L0_L0bar_2_40_80", "[0] * (1 + [1] * x)", -1, 1);
    fit_correct_outside_cos_theta_star_L0_L0bar_2_40_80->SetParameters(1, 1);
    h_correct_outside_cos_theta_star_L0_L0bar_2_40_80->Fit(fit_correct_outside_cos_theta_star_L0_L0bar_2_40_80, "R");

    double A112_divided_40_80 = fit_correct_outside_cos_theta_star_L0_L0bar_2_40_80->GetParameter(0);
    double B112_divided_40_80 = fit_correct_outside_cos_theta_star_L0_L0bar_2_40_80->GetParameter(1);
    cout << "Fit Parameters: Kristen's corrected L0-L0bar Pairs outside #DeltaR (us-ls):" << endl;
    cout << "A: " << A112_divided_40_80 << endl;
    cout << "B: " << B112_divided_40_80 << endl;

    h_correct_outside_cos_theta_star_L0_L0bar_40_80->SetStats(0);
    h_correct_outside_cos_theta_star_L0_L0bar_40_80->SetMinimum(0);
    h_correct_outside_cos_theta_star_L0_L0bar_40_80->SetMarkerStyle(20);
    h_correct_outside_cos_theta_star_L0_L0bar_40_80->SetMarkerColor(kBlue);
    h_correct_outside_cos_theta_star_L0_L0bar_40_80->SetTitle("#Lambda#bar{#Lambda} Pairs Outside #DeltaR (40-80% Centrality); cos(#theta*); dN/dCos(#theta*)"); 
    h_correct_outside_cos_theta_star_L0_L0bar_40_80->GetXaxis()->CenterTitle();
    h_correct_outside_cos_theta_star_L0_L0bar_40_80->GetYaxis()->CenterTitle();

    h_correct_outside_cos_theta_star_L0_L0bar_2_40_80->SetStats(0);
    h_correct_outside_cos_theta_star_L0_L0bar_2_40_80->SetMinimum(0);
    h_correct_outside_cos_theta_star_L0_L0bar_2_40_80->SetMarkerStyle(20);
    h_correct_outside_cos_theta_star_L0_L0bar_2_40_80->SetMarkerColor(kRed);
    h_correct_outside_cos_theta_star_L0_L0bar_2_40_80->SetLineColor(kRed);

    h_correct_outside_cos_theta_star_L0_L0bar_40_80->Draw("PE");
    h_correct_outside_cos_theta_star_L0_L0bar_2_40_80->Draw("PE same");

    TLegend *legend_correct_out_L0_L0bar_40_80 = new TLegend(0.12, 0.2, 0.4, 0.3);
    legend_correct_out_L0_L0bar_40_80->SetTextSize(0.03);
    legend_correct_out_L0_L0bar_40_80->SetBorderSize(0);
    legend_correct_out_L0_L0bar_40_80->SetFillStyle(0);

    legend_correct_out_L0_L0bar_40_80->AddEntry(h_correct_outside_cos_theta_star_L0_L0bar_40_80, "US-US #Lambda#bar{#Lambda} Pairs", "p");
    legend_correct_out_L0_L0bar_40_80->AddEntry(h_correct_outside_cos_theta_star_L0_L0bar_2_40_80, "US-LS #Lambda#bar{#Lambda} Pairs", "p");

    legend_correct_out_L0_L0bar_40_80->Draw();

    c12->cd(5);
    cout << "   " << endl;
    cout << "Pad 5: L0-L0 Pairs" << endl;

    TH1D *h_correct_outside_cos_theta_star_L0_L0_40_80 = (TH1D*)h_outside_cos_theta_star_40_80->Clone("h_correct_outside_cos_theta_star_L0_L0_40_80");
    h_correct_outside_cos_theta_star_L0_L0_40_80->Divide(h_outside_ME_cos_theta_star_40_80);

    TH1D *h_correct_outside_cos_theta_star_L0_L0_2_40_80 = (TH1D*)h_outside_cos_theta_star2_40_80->Clone("h_correct_outside_cos_theta_star_L0_L0_2_40_80");
    h_correct_outside_cos_theta_star_L0_L0_2_40_80->Divide(h_outside_ME_cos_theta_star2_40_80);

    double counts_correct_out_cos_40_80 = h_correct_outside_cos_theta_star_L0_L0_40_80->Integral();
    double counts_correct_out_cos_2_40_80 = h_correct_outside_cos_theta_star_L0_L0_2_40_80->Integral();

    h_correct_outside_cos_theta_star_L0_L0_40_80->Scale(1.0 / counts_correct_out_cos_40_80);
    h_correct_outside_cos_theta_star_L0_L0_40_80->Scale(counts_out_cos_40_80);

    h_correct_outside_cos_theta_star_L0_L0_2_40_80->Scale(1.0 / counts_correct_out_cos_2_40_80);
    h_correct_outside_cos_theta_star_L0_L0_2_40_80->Scale(counts_out_cos2_40_80);

    TF1 *fit_correct_outside_cos_theta_star_L0_L0_40_80 = new TF1("fit_correct_outside_cos_theta_star_L0_L0_40_80", "[0] * (1 + [1] * x)", -1, 1);
    fit_correct_outside_cos_theta_star_L0_L0_40_80->SetParameters(1, 1);
    h_correct_outside_cos_theta_star_L0_L0_40_80->Fit(fit_correct_outside_cos_theta_star_L0_L0_40_80, "R");

    double A11_divided_40_80 = fit_correct_outside_cos_theta_star_L0_L0_40_80->GetParameter(0);
    double B11_divided_40_80 = fit_correct_outside_cos_theta_star_L0_L0_40_80->GetParameter(1);
    double B11_error_40_80 = fit_correct_outside_cos_theta_star_L0_L0_40_80->GetParError(1);
    cout << "   " << endl;
    cout << "Fit Parameters: Kristen's corrected L0-L0 Pairs outside #DeltaR (us-us):" << endl;
    cout << "A: " << A11_divided_40_80 << endl;
    cout << "B: " << B11_divided_40_80 << endl; 

    double P_ll_outside_40_80 = B11_divided_40_80 /= constant_value_2;
    double P_ll_outside_error_40_80 = B11_error_40_80 /= constant_value_2;
    std::cout << "Polarization (LL): " << P_ll_outside_40_80 << " ± " << P_ll_outside_error_40_80 << std::endl;

    TF1 *fit_correct_outside_cos_theta_star_L0_L0_2_40_80 = new TF1("fit_correct_outside_cos_theta_star_L0_L0_2_40_80", "[0] * (1 + [1] * x)", -1, 1);
    fit_correct_outside_cos_theta_star_L0_L0_2_40_80->SetParameters(1, 1);
    h_correct_outside_cos_theta_star_L0_L0_2_40_80->Fit(fit_correct_outside_cos_theta_star_L0_L0_2_40_80, "R");

    double A111_divided_40_80 = fit_correct_outside_cos_theta_star_L0_L0_2_40_80->GetParameter(0);
    double B111_divided_40_80 = fit_correct_outside_cos_theta_star_L0_L0_2_40_80->GetParameter(1);
    cout << "Fit Parameters: Kristen's corrected L0-L0 Pairs outside #DeltaR (us-ls):" << endl;
    cout << "A: " << A111_divided_40_80 << endl;
    cout << "B: " << B111_divided_40_80 << endl; 

    h_correct_outside_cos_theta_star_L0_L0_40_80->SetStats(0);
    h_correct_outside_cos_theta_star_L0_L0_40_80->SetMinimum(0);
    h_correct_outside_cos_theta_star_L0_L0_40_80->SetMarkerStyle(20);
    h_correct_outside_cos_theta_star_L0_L0_40_80->SetMarkerColor(kBlue);
    h_correct_outside_cos_theta_star_L0_L0_40_80->SetTitle("#Lambda#Lambda Pairs Outside #DeltaR (40-80% Centrality); cos(#theta*); dN/dCos(#theta*)"); 
    h_correct_outside_cos_theta_star_L0_L0_40_80->GetXaxis()->CenterTitle();
    h_correct_outside_cos_theta_star_L0_L0_40_80->GetYaxis()->CenterTitle();

    h_correct_outside_cos_theta_star_L0_L0_2_40_80->SetStats(0);
    h_correct_outside_cos_theta_star_L0_L0_2_40_80->SetMinimum(0);
    h_correct_outside_cos_theta_star_L0_L0_2_40_80->SetMarkerStyle(20);
    h_correct_outside_cos_theta_star_L0_L0_2_40_80->SetMarkerColor(kRed);
    h_correct_outside_cos_theta_star_L0_L0_2_40_80->SetLineColor(kRed);

    h_correct_outside_cos_theta_star_L0_L0_40_80->Draw("PE");
    h_correct_outside_cos_theta_star_L0_L0_2_40_80->Draw("PE same");

    TLegend *legend_correct_out_L0_L0_40_80 = new TLegend(0.12, 0.2, 0.4, 0.3);
    legend_correct_out_L0_L0_40_80->SetTextSize(0.03);
    legend_correct_out_L0_L0_40_80->SetBorderSize(0);
    legend_correct_out_L0_L0_40_80->SetFillStyle(0);

    legend_correct_out_L0_L0_40_80->AddEntry(h_correct_outside_cos_theta_star_L0_L0_40_80, "US-US #Lambda#Lambda Pairs", "p");
    legend_correct_out_L0_L0_40_80->AddEntry(h_correct_outside_cos_theta_star_L0_L0_2_40_80, "US-LS #Lambda#Lambda Pairs", "p");

    legend_correct_out_L0_L0_40_80->Draw();

    c12->cd(6);
    cout << "   " << endl;
    cout << "Pad 6: L0bar-L0bar Pairs" << endl;

    TH1D *h_correct_outside_cos_theta_star_L0bar_L0bar_40_80 =(TH1D*)h_outside_cos_theta_star5_40_80->Clone("h_correct_outside_cos_theta_star_L0bar_L0bar_40_80");
    h_correct_outside_cos_theta_star_L0bar_L0bar_40_80->Divide(h_outside_ME_cos_theta_star5_40_80);

    TH1D *h_correct_outside_cos_theta_star_L0bar_L0bar_2_40_80 =(TH1D*)h_outside_cos_theta_star6_40_80->Clone("h_correct_outside_cos_theta_star_L0bar_L0bar_2_40_80");
    h_correct_outside_cos_theta_star_L0bar_L0bar_2_40_80->Divide(h_outside_ME_cos_theta_star6_40_80);

    double counts_correct_out_cos_5_40_80 = h_correct_outside_cos_theta_star_L0bar_L0bar_40_80->Integral();
    double counts_correct_out_cos_6_40_80 = h_correct_outside_cos_theta_star_L0bar_L0bar_2_40_80->Integral();

    h_correct_outside_cos_theta_star_L0bar_L0bar_40_80->Scale(1.0 / counts_correct_out_cos_5_40_80);
    h_correct_outside_cos_theta_star_L0bar_L0bar_40_80->Scale(counts_out_cos5_40_80);

    h_correct_outside_cos_theta_star_L0bar_L0bar_2_40_80->Scale(1.0 / counts_correct_out_cos_6_40_80);
    h_correct_outside_cos_theta_star_L0bar_L0bar_2_40_80->Scale(counts_out_cos6_40_80);

    TF1 *fit_correct_outside_cos_theta_star_L0bar_L0bar_40_80 = new TF1("fit_correct_outside_cos_theta_star_L0bar_L0bar_40_80", "[0] * (1 + [1] * x)", -1, 1);
    fit_correct_outside_cos_theta_star_L0bar_L0bar_40_80->SetParameters(1, 1);
    h_correct_outside_cos_theta_star_L0bar_L0bar_40_80->Fit(fit_correct_outside_cos_theta_star_L0bar_L0bar_40_80, "R"); 

    double A13_divided_40_80 = fit_correct_outside_cos_theta_star_L0bar_L0bar_40_80->GetParameter(0);
    double B13_divided_40_80 = fit_correct_outside_cos_theta_star_L0bar_L0bar_40_80->GetParameter(1);
    double B13_error_40_80 = fit_correct_outside_cos_theta_star_L0bar_L0bar_40_80->GetParError(1);
    cout << "   " << endl;
    cout << "Fit Parameters: Kristen's corrected L0bar-L0bar Pairs outside #DeltaR (us-us):" << endl;
    cout << "A: " << A13_divided_40_80 << endl;
    cout << "B: " << B13_divided_40_80 << endl;

    double P_lbarlbar_outside_40_80 = B13_divided_40_80 /= constant_value_3;
    double P_lbarlbar_outside_error_40_80 = B13_error_40_80 /= constant_value_3;
    std::cout << "Polarization (LLBar): " << P_lbarlbar_outside_40_80 << " ± " << P_lbarlbar_outside_error_40_80 << std::endl;

    TF1 *fit_correct_outside_cos_theta_star_L0bar_L0bar_2_40_80 = new TF1("fit_correct_outside_cos_theta_star_L0bar_L0bar_2_40_80", "[0] * (1 + [1] * x)", -1, 1);
    fit_correct_outside_cos_theta_star_L0bar_L0bar_2_40_80->SetParameters(1, 1);
    h_correct_outside_cos_theta_star_L0bar_L0bar_2_40_80->Fit(fit_correct_outside_cos_theta_star_L0bar_L0bar_2_40_80, "R"); 

    double A113_divided_40_80 = fit_correct_outside_cos_theta_star_L0bar_L0bar_2_40_80->GetParameter(0);
    double B113_divided_40_80 = fit_correct_outside_cos_theta_star_L0bar_L0bar_2_40_80->GetParameter(1);
    cout << "Fit Parameters: Kristen's corrected L0bar-L0bar Pairs outside #DeltaR (us-ls):" << endl;
    cout << "A: " << A113_divided_40_80 << endl;
    cout << "B: " << B113_divided_40_80<< endl;

    h_correct_outside_cos_theta_star_L0bar_L0bar_40_80->SetStats(0);
    h_correct_outside_cos_theta_star_L0bar_L0bar_40_80->SetMinimum(0);
    h_correct_outside_cos_theta_star_L0bar_L0bar_40_80->SetMarkerStyle(20);
    h_correct_outside_cos_theta_star_L0bar_L0bar_40_80->SetMarkerColor(kBlue);
    h_correct_outside_cos_theta_star_L0bar_L0bar_40_80->SetTitle("#bar{#Lambda}#bar{#Lambda} Pairs Outside #DeltaR (40-80% Centrality); cos(#theta*); dN/dCos(#theta*)"); 
    h_correct_outside_cos_theta_star_L0bar_L0bar_40_80->GetXaxis()->CenterTitle();
    h_correct_outside_cos_theta_star_L0bar_L0bar_40_80->GetYaxis()->CenterTitle();

    h_correct_outside_cos_theta_star_L0bar_L0bar_2_40_80->SetStats(0);
    h_correct_outside_cos_theta_star_L0bar_L0bar_2_40_80->SetMinimum(0);
    h_correct_outside_cos_theta_star_L0bar_L0bar_2_40_80->SetMarkerStyle(20);
    h_correct_outside_cos_theta_star_L0bar_L0bar_2_40_80->SetMarkerColor(kRed);
    h_correct_outside_cos_theta_star_L0bar_L0bar_2_40_80->SetLineColor(kRed);

    h_correct_outside_cos_theta_star_L0bar_L0bar_40_80->Draw("PE");
    h_correct_outside_cos_theta_star_L0bar_L0bar_2_40_80->Draw("PE same");

    TLegend *legend_correct_out_L0bar_L0bar_40_80 = new TLegend(0.12, 0.2, 0.4, 0.3);
    legend_correct_out_L0bar_L0bar_40_80->SetTextSize(0.03);
    legend_correct_out_L0bar_L0bar_40_80->SetBorderSize(0);
    legend_correct_out_L0bar_L0bar_40_80->SetFillStyle(0);

    legend_correct_out_L0bar_L0bar_40_80->AddEntry(h_correct_outside_cos_theta_star_L0bar_L0bar_40_80, "US-US #bar{#Lambda}#bar{#Lambda} Pairs", "p");
    legend_correct_out_L0bar_L0bar_40_80->AddEntry(h_correct_outside_cos_theta_star_L0bar_L0bar_2_40_80, "US-LS #bar{#Lambda}#bar{#Lambda} Pairs", "p");

    legend_correct_out_L0bar_L0bar_40_80->Draw();

    cout << "Canvas 12 Complete" << endl;

    double counts_correct_cos_theta_star_L0_L0bar_0_10 = h_correct_cos_theta_star_L0_L0bar_0_10->Integral();
    double counts_correct_cos_theta_star_L0_L0bar_2_0_10 = h_correct_cos_theta_star_L0_L0bar_2_0_10->Integral();
    double counts_correct_cos_theta_star_L0_L0_0_10 = h_correct_cos_theta_star_L0_L0_0_10->Integral();
    double counts_correct_cos_theta_star_L0_L0_2_0_10 = h_correct_cos_theta_star_L0_L0_2_0_10->Integral();
    double counts_correct_cos_theta_star_L0bar_L0bar_0_10 = h_correct_cos_theta_star_L0bar_L0bar_0_10->Integral();
    double counts_correct_cos_theta_star_L0bar_L0bar_2_0_10 = h_correct_cos_theta_star_L0bar_L0bar_2_0_10->Integral();

    double counts_correct_outside_cos_theta_star_L0_L0bar_0_10 = h_correct_outside_cos_theta_star_L0_L0bar_0_10->Integral();
    double counts_correct_outside_cos_theta_star_L0_L0bar_2_0_10 = h_correct_outside_cos_theta_star_L0_L0bar_2_0_10->Integral();
    double counts_correct_outside_cos_theta_star_L0_L0_0_10 = h_correct_outside_cos_theta_star_L0_L0_0_10->Integral();
    double counts_correct_outside_cos_theta_star_L0_L0_2_0_10 = h_correct_outside_cos_theta_star_L0_L0_2_0_10->Integral();
    double counts_correct_outside_cos_theta_star_L0bar_L0bar_0_10 = h_correct_outside_cos_theta_star_L0bar_L0bar_0_10->Integral();
    double counts_correct_outside_cos_theta_star_L0bar_L0bar_2_0_10 = h_correct_outside_cos_theta_star_L0bar_L0bar_2_0_10->Integral();

    cout << "   " << endl;
    cout << "Kristen's Data after the ME Correction is Applied (0-10% Centrality)" << endl;
    cout << "inside #DeltaR = 0.93 cut" << endl;
    cout << "US-US L0-L0bar Pairs: " << counts_correct_cos_theta_star_L0_L0bar_0_10 << endl;
    cout << "US-LS L0-L0bar Pairs: " << counts_correct_cos_theta_star_L0_L0bar_2_0_10 << endl;
    cout << "US-US L0-L0 Pairs: " << counts_correct_cos_theta_star_L0_L0_0_10 << endl;
    cout << "US-LS L0-L0 Pairs: " << counts_correct_cos_theta_star_L0_L0_2_0_10 << endl;
    cout << "US-US L0bar-L0bar Pairs: " << counts_correct_cos_theta_star_L0bar_L0bar_0_10 << endl;
    cout << "US-LS L0bar-L0bar Pairs: " << counts_correct_cos_theta_star_L0bar_L0bar_2_0_10 << endl;
    cout << "   " << endl;
    cout << "outside #DeltaR = 0.93 cut" << endl;
    cout << "US-US L0-L0bar Pairs: " << counts_correct_outside_cos_theta_star_L0_L0bar_0_10 << endl;
    cout << "US-LS L0-L0bar Pairs: " << counts_correct_outside_cos_theta_star_L0_L0bar_2_0_10 << endl;
    cout << "US-US L0-L0 Pairs: " << counts_correct_outside_cos_theta_star_L0_L0_0_10 << endl;
    cout << "US-LS L0-L0 Pairs: " << counts_correct_outside_cos_theta_star_L0_L0_2_0_10 << endl;
    cout << "US-US L0bar-L0bar Pairs: " << counts_correct_outside_cos_theta_star_L0bar_L0bar_0_10 << endl;
    cout << "US-LS L0bar-L0bar Pairs: " << counts_correct_outside_cos_theta_star_L0bar_L0bar_2_0_10 << endl;

    double counts_correct_cos_theta_star_L0_L0bar_10_40 = h_correct_cos_theta_star_L0_L0bar_10_40->Integral();
    double counts_correct_cos_theta_star_L0_L0bar_2_10_40 = h_correct_cos_theta_star_L0_L0bar_2_10_40->Integral();
    double counts_correct_cos_theta_star_L0_L0_10_40 = h_correct_cos_theta_star_L0_L0_10_40->Integral();
    double counts_correct_cos_theta_star_L0_L0_2_10_40 = h_correct_cos_theta_star_L0_L0_2_10_40->Integral();
    double counts_correct_cos_theta_star_L0bar_L0bar_10_40 = h_correct_cos_theta_star_L0bar_L0bar_10_40->Integral();
    double counts_correct_cos_theta_star_L0bar_L0bar_2_10_40 = h_correct_cos_theta_star_L0bar_L0bar_2_10_40->Integral();

    double counts_correct_outside_cos_theta_star_L0_L0bar_10_40 = h_correct_outside_cos_theta_star_L0_L0bar_10_40->Integral();
    double counts_correct_outside_cos_theta_star_L0_L0bar_2_10_40 = h_correct_outside_cos_theta_star_L0_L0bar_2_10_40->Integral();
    double counts_correct_outside_cos_theta_star_L0_L0_10_40 = h_correct_outside_cos_theta_star_L0_L0_10_40->Integral();
    double counts_correct_outside_cos_theta_star_L0_L0_2_10_40 = h_correct_outside_cos_theta_star_L0_L0_2_10_40->Integral();
    double counts_correct_outside_cos_theta_star_L0bar_L0bar_10_40 = h_correct_outside_cos_theta_star_L0bar_L0bar_10_40->Integral();
    double counts_correct_outside_cos_theta_star_L0bar_L0bar_2_10_40 = h_correct_outside_cos_theta_star_L0bar_L0bar_2_10_40->Integral();

    cout << "   " << endl;
    cout << "Kristen's Data after the ME Correction is Applied (10-40% Centrality)" << endl;
    cout << "inside #DeltaR = 0.93 cut" << endl;
    cout << "US-US L0-L0bar Pairs: " << counts_correct_cos_theta_star_L0_L0bar_10_40 << endl;
    cout << "US-LS L0-L0bar Pairs: " << counts_correct_cos_theta_star_L0_L0bar_2_10_40 << endl;
    cout << "US-US L0-L0 Pairs: " << counts_correct_cos_theta_star_L0_L0_10_40 << endl;
    cout << "US-LS L0-L0 Pairs: " << counts_correct_cos_theta_star_L0_L0_2_10_40 << endl;
    cout << "US-US L0bar-L0bar Pairs: " << counts_correct_cos_theta_star_L0bar_L0bar_10_40 << endl;
    cout << "US-LS L0bar-L0bar Pairs: " << counts_correct_cos_theta_star_L0bar_L0bar_2_10_40 << endl;
    cout << "   " << endl;
    cout << "outside #DeltaR = 0.93 cut" << endl;
    cout << "US-US L0-L0bar Pairs: " << counts_correct_outside_cos_theta_star_L0_L0bar_10_40 << endl;
    cout << "US-LS L0-L0bar Pairs: " << counts_correct_outside_cos_theta_star_L0_L0bar_2_10_40 << endl;
    cout << "US-US L0-L0 Pairs: " << counts_correct_outside_cos_theta_star_L0_L0_10_40 << endl;
    cout << "US-LS L0-L0 Pairs: " << counts_correct_outside_cos_theta_star_L0_L0_2_10_40 << endl;
    cout << "US-US L0bar-L0bar Pairs: " << counts_correct_outside_cos_theta_star_L0bar_L0bar_10_40 << endl;
    cout << "US-LS L0bar-L0bar Pairs: " << counts_correct_outside_cos_theta_star_L0bar_L0bar_2_10_40 << endl;

    double counts_correct_cos_theta_star_L0_L0bar_40_80 = h_correct_cos_theta_star_L0_L0bar_40_80->Integral();
    double counts_correct_cos_theta_star_L0_L0bar_2_40_80 = h_correct_cos_theta_star_L0_L0bar_2_40_80->Integral();
    double counts_correct_cos_theta_star_L0_L0_40_80 = h_correct_cos_theta_star_L0_L0_40_80->Integral();
    double counts_correct_cos_theta_star_L0_L0_2_40_80 = h_correct_cos_theta_star_L0_L0_2_40_80->Integral();
    double counts_correct_cos_theta_star_L0bar_L0bar_40_80 = h_correct_cos_theta_star_L0bar_L0bar_40_80->Integral();
    double counts_correct_cos_theta_star_L0bar_L0bar_2_40_80 = h_correct_cos_theta_star_L0bar_L0bar_2_40_80->Integral();

    double counts_correct_outside_cos_theta_star_L0_L0bar_40_80 = h_correct_outside_cos_theta_star_L0_L0bar_40_80->Integral();
    double counts_correct_outside_cos_theta_star_L0_L0bar_2_40_80 = h_correct_outside_cos_theta_star_L0_L0bar_2_40_80->Integral();
    double counts_correct_outside_cos_theta_star_L0_L0_40_80 = h_correct_outside_cos_theta_star_L0_L0_40_80->Integral();
    double counts_correct_outside_cos_theta_star_L0_L0_2_40_80 = h_correct_outside_cos_theta_star_L0_L0_2_40_80->Integral();
    double counts_correct_outside_cos_theta_star_L0bar_L0bar_40_80 = h_correct_outside_cos_theta_star_L0bar_L0bar_40_80->Integral();
    double counts_correct_outside_cos_theta_star_L0bar_L0bar_2_40_80 = h_correct_outside_cos_theta_star_L0bar_L0bar_2_40_80->Integral();

    cout << "   " << endl;
    cout << "Kristen's Data after the ME Correction is Applied (40-80% Centrality)" << endl;
    cout << "inside #DeltaR = 0.93 cut" << endl;
    cout << "US-US L0-L0bar Pairs: " << counts_correct_cos_theta_star_L0_L0bar_40_80 << endl;
    cout << "US-LS L0-L0bar Pairs: " << counts_correct_cos_theta_star_L0_L0bar_2_40_80 << endl;
    cout << "US-US L0-L0 Pairs: " << counts_correct_cos_theta_star_L0_L0_40_80 << endl;
    cout << "US-LS L0-L0 Pairs: " << counts_correct_cos_theta_star_L0_L0_2_40_80 << endl;
    cout << "US-US L0bar-L0bar Pairs: " << counts_correct_cos_theta_star_L0bar_L0bar_40_80 << endl;
    cout << "US-LS L0bar-L0bar Pairs: " << counts_correct_cos_theta_star_L0bar_L0bar_2_40_80 << endl;
    cout << "   " << endl;
    cout << "outside #DeltaR = 0.93 cut" << endl;
    cout << "US-US L0-L0bar Pairs: " << counts_correct_outside_cos_theta_star_L0_L0bar_40_80 << endl;
    cout << "US-LS L0-L0bar Pairs: " << counts_correct_outside_cos_theta_star_L0_L0bar_2_40_80 << endl;
    cout << "US-US L0-L0 Pairs: " << counts_correct_outside_cos_theta_star_L0_L0_40_80 << endl;
    cout << "US-LS L0-L0 Pairs: " << counts_correct_outside_cos_theta_star_L0_L0_2_40_80 << endl;
    cout << "US-US L0bar-L0bar Pairs: " << counts_correct_outside_cos_theta_star_L0bar_L0bar_40_80 << endl;
    cout << "US-LS L0bar-L0bar Pairs: " << counts_correct_outside_cos_theta_star_L0bar_L0bar_2_40_80 << endl;

    TCanvas *c13 = new TCanvas("c13", "c13- Corrected Distributions (0-10% Centrality)", 1800, 900);
    c13->Divide(3, 2);

    c13->cd(1);
    cout << "   " << endl;
    cout << "Canvas 7, Pad 1" << endl;

    TH1D *h_corrected_cos_theta_star_L0_L0bar_0_10 = new TH1D(*h_correct_cos_theta_star_L0_L0bar_0_10);
    h_corrected_cos_theta_star_L0_L0bar_0_10->Add(h_correct_cos_theta_star_L0_L0bar_2_0_10, -1.0);

    cout << "   " << endl;
    cout << "Fit Parameters: Kristen's Data after ME correction and background subtraction" << endl;
    TF1 *fit_corrected_cos_theta_star_L0_L0bar_0_10 = new TF1("fit_corrected_cos_theta_star_L0_L0bar", "[0] * (1 + [1] * x)", -1, 1);
    fit_corrected_cos_theta_star_L0_L0bar_0_10->SetParameters(1, 1);
    fit_corrected_cos_theta_star_L0_L0bar_0_10->SetLineColor(kBlue);
    h_corrected_cos_theta_star_L0_L0bar_0_10->Fit(fit_corrected_cos_theta_star_L0_L0bar_0_10, "R");

    double A22_divided_0_10 = fit_corrected_cos_theta_star_L0_L0bar_0_10->GetParameter(0);
    double B22_divided_0_10 = fit_corrected_cos_theta_star_L0_L0bar_0_10->GetParameter(1);
    double B22_error_0_10 = fit_corrected_cos_theta_star_L0_L0bar_0_10->GetParError(1);
    cout << "Fit Parameters: Kristen's corrected L0-L0bar Pairs inside #DeltaR (After Background Subtraction):" << endl;
    cout << "A: " << A22_divided_0_10 << endl;
    cout << "B: " << B22_divided_0_10 << endl;

    double P_corrected_llbar_0_10 = B22_divided_0_10 / constant_value;
    double P_corrected_llbar_error_0_10 = B22_error_0_10 / constant_value;
    std::cout << "Polarization (L0-L0Bar): " << P_corrected_llbar_0_10 << " ± " << P_corrected_llbar_error_0_10 << std::endl;

    h_corrected_cos_theta_star_L0_L0bar_0_10->SetStats(0);
    h_corrected_cos_theta_star_L0_L0bar_0_10->SetMinimum(0);
    h_corrected_cos_theta_star_L0_L0bar_0_10->SetMarkerStyle(20);
    h_corrected_cos_theta_star_L0_L0bar_0_10->SetMarkerColor(kBlue);
    h_corrected_cos_theta_star_L0_L0bar_0_10->SetTitle("#Lambda#bar{#Lambda} Pairs Inside #DeltaR (0-10% Centrality); cos(#theta*); dN/dCos(#theta*)"); 
    h_corrected_cos_theta_star_L0_L0bar_0_10->GetXaxis()->CenterTitle();
    h_corrected_cos_theta_star_L0_L0bar_0_10->GetYaxis()->CenterTitle();
    h_corrected_cos_theta_star_L0_L0bar_0_10->Draw("PE");

    TLegend *legend_corrected_L0_L0bar_0_10 = new TLegend(0.15, 0.2, 0.4, 0.3);
    legend_corrected_L0_L0bar_0_10->SetBorderSize(1);    
    legend_corrected_L0_L0bar_0_10->SetTextSize(0.03);   
    legend_corrected_L0_L0bar_0_10->SetBorderSize(0);
    legend_corrected_L0_L0bar_0_10->SetFillStyle(0); 
    legend_corrected_L0_L0bar_0_10->AddEntry(h_corrected_cos_theta_star_L0_L0bar_0_10, "#Lambda#bar{#Lambda} Pairs", "p");
    legend_corrected_L0_L0bar_0_10->AddEntry(fit_corrected_cos_theta_star_L0_L0bar_0_10, "fit");
    legend_corrected_L0_L0bar_0_10->Draw();

    c13->cd(2);
    cout << "   " << endl;
    cout << "Canvas 7, Pad 2" << endl;

    TH1D *h_corrected_cos_theta_star_L0_L0_0_10 = new TH1D(*h_correct_cos_theta_star_L0_L0_0_10);
    h_corrected_cos_theta_star_L0_L0_0_10->Add(h_correct_cos_theta_star_L0_L0_2_0_10, -1.0);

    cout << "   " << endl;
    cout << "Fit Parameters: Kristen's Data after ME correction and background subtraction" << endl;
    TF1 *fit_corrected_cos_theta_star_L0_L0_0_10 = new TF1("fit_corrected_cos_theta_star_L0_L0_0_10", "[0] * (1 + [1] * x)", -1, 1);
    fit_corrected_cos_theta_star_L0_L0_0_10->SetParameters(1, 1);
    fit_corrected_cos_theta_star_L0_L0_0_10->SetLineColor(kBlue);
    h_corrected_cos_theta_star_L0_L0_0_10->Fit(fit_corrected_cos_theta_star_L0_L0_0_10, "R");

    double A21_divided_0_10 = fit_corrected_cos_theta_star_L0_L0_0_10->GetParameter(0);
    double B21_divided_0_10 = fit_corrected_cos_theta_star_L0_L0_0_10->GetParameter(1);
    double B21_error_0_10 = fit_corrected_cos_theta_star_L0_L0_0_10->GetParError(1);
    cout << "Fit Parameters: Kristen's corrected L0-L0 Pairs inside #DeltaR (After Background Subtraction):" << endl;
    cout << "A: " << A21_divided_0_10 << endl;
    cout << "B: " << B21_divided_0_10 << endl;

    double P_corrected_ll_0_10 = B21_divided_0_10 / constant_value_2;
    double P_corrected_ll_error_0_10 = B21_error_0_10 / constant_value_2;
    std::cout << "Polarization (L0-L0Bar): " << P_corrected_ll_0_10 << " ± " << P_corrected_ll_error_0_10 << std::endl; 

    h_corrected_cos_theta_star_L0_L0_0_10->SetStats(0);
    h_corrected_cos_theta_star_L0_L0_0_10->SetMinimum(0);
    h_corrected_cos_theta_star_L0_L0_0_10->SetMarkerStyle(20);
    h_corrected_cos_theta_star_L0_L0_0_10->SetMarkerColor(kBlue);
    h_corrected_cos_theta_star_L0_L0_0_10->SetTitle("#Lambda#Lambda Pairs Inside #DeltaR (0-10% Centrality); cos(#theta*); dN/dCos(#theta*)"); 
    h_corrected_cos_theta_star_L0_L0_0_10->GetXaxis()->CenterTitle();
    h_corrected_cos_theta_star_L0_L0_0_10->GetYaxis()->CenterTitle();
    h_corrected_cos_theta_star_L0_L0_0_10->Draw("PE");

    TLegend *legend_corrected_L0_L0_0_10 = new TLegend(0.15, 0.2, 0.4, 0.3);
    legend_corrected_L0_L0_0_10->SetBorderSize(1);    
    legend_corrected_L0_L0_0_10->SetTextSize(0.03);   
    legend_corrected_L0_L0_0_10->SetBorderSize(0);
    legend_corrected_L0_L0_0_10->SetFillStyle(0); 
    legend_corrected_L0_L0_0_10->AddEntry(h_corrected_cos_theta_star_L0_L0_0_10, "#Lambda#Lambda Pairs", "p");
    legend_corrected_L0_L0_0_10->AddEntry(fit_corrected_cos_theta_star_L0_L0_0_10, "fit");
    legend_corrected_L0_L0_0_10->Draw();

    c13->cd(3);
    cout << "   " << endl;
    cout << "Canvas 7, Pad 3" << endl;

    TH1D *h_corrected_cos_theta_star_L0bar_L0bar_0_10 = new TH1D(*h_correct_cos_theta_star_L0bar_L0bar_0_10);
    h_corrected_cos_theta_star_L0bar_L0bar_0_10->Add(h_correct_cos_theta_star_L0bar_L0bar_2_0_10, -1.0);

    cout << "   " << endl;
    cout << "Fit Parameters: Kristen's Data after ME correction and background subtraction" << endl;
    TF1 *fit_corrected_cos_theta_star_L0bar_L0bar_0_10 = new TF1("fit_corrected_cos_theta_star_L0bar_L0bar_0_10", "[0] * (1 + [1] * x)", -1, 1);
    fit_corrected_cos_theta_star_L0bar_L0bar_0_10->SetParameters(1, 1);
    fit_corrected_cos_theta_star_L0bar_L0bar_0_10->SetLineColor(kBlue);
    h_corrected_cos_theta_star_L0bar_L0bar_0_10->Fit(fit_corrected_cos_theta_star_L0bar_L0bar_0_10, "R");

    double A23_divided_0_10 = fit_corrected_cos_theta_star_L0bar_L0bar_0_10->GetParameter(0);
    double B23_divided_0_10 = fit_corrected_cos_theta_star_L0bar_L0bar_0_10->GetParameter(1);
    double B23_error_0_10 = fit_corrected_cos_theta_star_L0bar_L0bar_0_10->GetParError(1);
    cout << "Fit Parameters: Kristen's corrected L0bar-L0bar Pairs inside #DeltaR (After Background Subtraction):" << endl;
    cout << "A: " << A23_divided_0_10 << endl;
    cout << "B: " << B23_divided_0_10 << endl;

    double P_corrected_lbarlbar_0_10 = B23_divided_0_10 / constant_value_3;
    double P_corrected_lbarlbar_error_0_10 = B23_error_0_10 / constant_value_3;
    std::cout << "Polarization (L0-L0Bar): " << P_corrected_lbarlbar_0_10 << " ± " << P_corrected_lbarlbar_error_0_10 << std::endl;

    h_corrected_cos_theta_star_L0bar_L0bar_0_10->SetStats(0);
    h_corrected_cos_theta_star_L0bar_L0bar_0_10->SetMinimum(0);
    h_corrected_cos_theta_star_L0bar_L0bar_0_10->SetMarkerStyle(20);
    h_corrected_cos_theta_star_L0bar_L0bar_0_10->SetMarkerColor(kBlue);
    h_corrected_cos_theta_star_L0bar_L0bar_0_10->SetTitle("#bar{#Lambda}#bar{#Lambda} Pairs Inside #DeltaR (0-10% Centrality); cos(#theta*); dN/dCos(#theta*)"); 
    h_corrected_cos_theta_star_L0bar_L0bar_0_10->GetXaxis()->CenterTitle();
    h_corrected_cos_theta_star_L0bar_L0bar_0_10->GetYaxis()->CenterTitle();
    h_corrected_cos_theta_star_L0bar_L0bar_0_10->Draw("PE");

    TLegend *legend_corrected_L0bar_L0bar_0_10 = new TLegend(0.15, 0.2, 0.4, 0.3);
    legend_corrected_L0bar_L0bar_0_10->SetBorderSize(1);    
    legend_corrected_L0bar_L0bar_0_10->SetTextSize(0.03);   
    legend_corrected_L0bar_L0bar_0_10->SetBorderSize(0);
    legend_corrected_L0bar_L0bar_0_10->SetFillStyle(0); 
    legend_corrected_L0bar_L0bar_0_10->AddEntry(h_corrected_cos_theta_star_L0bar_L0bar_0_10, "#bar{#Lambda}#bar{#Lambda} pairs", "p");
    legend_corrected_L0bar_L0bar_0_10->AddEntry(fit_corrected_cos_theta_star_L0bar_L0bar_0_10, "fit");
    legend_corrected_L0bar_L0bar_0_10->Draw();

    c13->cd(4);
    cout << "   " << endl;
    cout << "Canvas 7, Pad 4" << endl;

    TH1D *h_corrected_outside_cos_theta_star_L0_L0bar_0_10 = new TH1D(*h_correct_outside_cos_theta_star_L0_L0bar_0_10);
    h_corrected_outside_cos_theta_star_L0_L0bar_0_10->Add(h_correct_outside_cos_theta_star_L0_L0bar_2_0_10, -1.0);

    cout << "   " << endl;
    cout << "Fit Parameters: Kristen's Data after ME correction and background subtraction" << endl;
    TF1 *fit_corrected_outside_cos_theta_star_L0_L0bar_0_10 = new TF1("fit_corrected_outside_cos_theta_star_L0_L0bar_0_10", "[0] * (1 + [1] * x)", -1, 1);
    fit_corrected_outside_cos_theta_star_L0_L0bar_0_10->SetParameters(1, 1);
    fit_corrected_outside_cos_theta_star_L0_L0bar_0_10->SetLineColor(kBlue);
    h_corrected_outside_cos_theta_star_L0_L0bar_0_10->Fit(fit_corrected_outside_cos_theta_star_L0_L0bar_0_10, "R");

    double A32_divided_0_10 = fit_corrected_outside_cos_theta_star_L0_L0bar_0_10->GetParameter(0);
    double B32_divided_0_10 = fit_corrected_outside_cos_theta_star_L0_L0bar_0_10->GetParameter(1);
    double B32_error_0_10 = fit_corrected_outside_cos_theta_star_L0_L0bar_0_10->GetParError(1);
    cout << "Fit Parameters: Kristen's corrected L0-L0bar Pairs outside #DeltaR (After Background Subtraction):" << endl;
    cout << "A: " << A32_divided_0_10 << endl;
    cout << "B: " << B32_divided_0_10 << endl;

    double P_corrected_outside_llbar_0_10 = B32_divided_0_10 / constant_value;
    double P_corrected_outside_llbar_error_0_10 = B32_error_0_10 / constant_value;
    std::cout << "Polarization (L0-L0Bar): " << P_corrected_outside_llbar_0_10 << " ± " << P_corrected_outside_llbar_error_0_10 << std::endl;

    h_corrected_outside_cos_theta_star_L0_L0bar_0_10->SetStats(0);
    h_corrected_outside_cos_theta_star_L0_L0bar_0_10->SetMinimum(0);
    h_corrected_outside_cos_theta_star_L0_L0bar_0_10->SetMarkerStyle(20);
    h_corrected_outside_cos_theta_star_L0_L0bar_0_10->SetMarkerColor(kBlue);
    h_corrected_outside_cos_theta_star_L0_L0bar_0_10->SetTitle("#Lambda#bar{#Lambda} Pairs outside #DeltaR (0-10% Centrality); cos(#theta*); dN/dCos(#theta*)"); 
    h_corrected_outside_cos_theta_star_L0_L0bar_0_10->GetXaxis()->CenterTitle();
    h_corrected_outside_cos_theta_star_L0_L0bar_0_10->GetYaxis()->CenterTitle();
    h_corrected_outside_cos_theta_star_L0_L0bar_0_10->Draw("PE");

    TLegend *legend_corrected_outside_L0_L0bar_0_10 = new TLegend(0.15, 0.2, 0.4, 0.3);
    legend_corrected_outside_L0_L0bar_0_10->SetBorderSize(1);    
    legend_corrected_outside_L0_L0bar_0_10->SetTextSize(0.03);   
    legend_corrected_outside_L0_L0bar_0_10->SetBorderSize(0);
    legend_corrected_outside_L0_L0bar_0_10->SetFillStyle(0); 
    legend_corrected_outside_L0_L0bar_0_10->AddEntry(h_corrected_cos_theta_star_L0_L0bar_0_10, "#Lambda#bar{#Lambda} pairs", "p");
    legend_corrected_outside_L0_L0bar_0_10->AddEntry(fit_corrected_cos_theta_star_L0_L0bar_0_10, "fit");
    legend_corrected_outside_L0_L0bar_0_10->Draw();

    c13->cd(5);
    cout << "   " << endl;
    cout << "Canvas 7, Pad 5" << endl;

    TH1D *h_corrected_outside_cos_theta_star_L0_L0_0_10 = new TH1D(*h_correct_outside_cos_theta_star_L0_L0_0_10);
    h_corrected_outside_cos_theta_star_L0_L0_0_10->Add(h_correct_outside_cos_theta_star_L0_L0_2_0_10, -1.0);

    cout << "   " << endl;
    cout << "Fit Parameters: Kristen's Data after ME correction and background subtraction" << endl;
    TF1 *fit_corrected_outside_cos_theta_star_L0_L0_0_10 = new TF1("fit_corrected_outside_cos_theta_star_L0_L0_0_10", "[0] * (1 + [1] * x)", -1, 1);
    fit_corrected_outside_cos_theta_star_L0_L0_0_10->SetParameters(1, 1);
    fit_corrected_outside_cos_theta_star_L0_L0_0_10->SetLineColor(kBlue);
    h_corrected_outside_cos_theta_star_L0_L0_0_10->Fit(fit_corrected_outside_cos_theta_star_L0_L0_0_10, "R");

    double A31_divided_0_10 = fit_corrected_outside_cos_theta_star_L0_L0_0_10->GetParameter(0);
    double B31_divided_0_10 = fit_corrected_outside_cos_theta_star_L0_L0_0_10->GetParameter(1);
    double B31_error_0_10 = fit_corrected_outside_cos_theta_star_L0_L0_0_10->GetParError(1);
    cout << "Fit Parameters: Kristen's corrected L0-L0 Pairs outside #DeltaR (After Background Subtraction):" << endl;
    cout << "A: " << A31_divided_0_10 << endl;
    cout << "B: " << B31_divided_0_10 << endl;

    double P_corrected_outside_ll_0_10 = B31_divided_0_10 / constant_value_2;
    double P_corrected_outside_ll_error_0_10 = B31_error_0_10 / constant_value_2;
    std::cout << "Polarization (L0-L0Bar): " << P_corrected_outside_ll_0_10 << " ± " << P_corrected_outside_ll_error_0_10 << std::endl; 

    h_corrected_outside_cos_theta_star_L0_L0_0_10->SetStats(0);
    h_corrected_outside_cos_theta_star_L0_L0_0_10->SetMinimum(0);
    h_corrected_outside_cos_theta_star_L0_L0_0_10->SetMarkerStyle(20);
    h_corrected_outside_cos_theta_star_L0_L0_0_10->SetMarkerColor(kBlue);
    h_corrected_outside_cos_theta_star_L0_L0_0_10->SetTitle("#Lambda#Lambda Pairs outside #DeltaR (0-10% Centrality); cos(#theta*); dN/dCos(#theta*)"); 
    h_corrected_outside_cos_theta_star_L0_L0_0_10->GetXaxis()->CenterTitle();
    h_corrected_outside_cos_theta_star_L0_L0_0_10->GetYaxis()->CenterTitle();
    h_corrected_outside_cos_theta_star_L0_L0_0_10->Draw("PE");

    TLegend *legend_corrected_outside_L0_L0_0_10 = new TLegend(0.15, 0.2, 0.4, 0.3);
    legend_corrected_outside_L0_L0_0_10->SetBorderSize(1);    
    legend_corrected_outside_L0_L0_0_10->SetTextSize(0.03);   
    legend_corrected_outside_L0_L0_0_10->SetBorderSize(0);
    legend_corrected_outside_L0_L0_0_10->SetFillStyle(0); 
    legend_corrected_outside_L0_L0_0_10->AddEntry(h_corrected_cos_theta_star_L0_L0_0_10, "#Lambda#Lambda pairs", "p");
    legend_corrected_outside_L0_L0_0_10->AddEntry(fit_corrected_cos_theta_star_L0_L0_0_10, "fit");
    legend_corrected_outside_L0_L0_0_10->Draw();

    c13->cd(6);
    cout << "   " << endl;
    cout << "Canvas 7, Pad 6" << endl;

    TH1D *h_corrected_outside_cos_theta_star_L0bar_L0bar_0_10 = new TH1D(*h_correct_outside_cos_theta_star_L0bar_L0bar_0_10);
    h_corrected_outside_cos_theta_star_L0bar_L0bar_0_10->Add(h_correct_outside_cos_theta_star_L0bar_L0bar_2_0_10, -1.0);

    cout << "   " << endl;
    cout << "Fit Parameters: Kristen's Data after ME correction and background subtraction" << endl;
    TF1 *fit_corrected_outside_cos_theta_star_L0bar_L0bar_0_10 = new TF1("fit_corrected_outside_cos_theta_star_L0bar_L0bar_0_10", "[0] * (1 + [1] * x)", -1, 1);
    fit_corrected_outside_cos_theta_star_L0bar_L0bar_0_10->SetParameters(1, 1);
    fit_corrected_outside_cos_theta_star_L0bar_L0bar_0_10->SetLineColor(kBlue);
    h_corrected_outside_cos_theta_star_L0bar_L0bar_0_10->Fit(fit_corrected_outside_cos_theta_star_L0bar_L0bar_0_10, "R");

    double A33_divided_0_10 = fit_corrected_outside_cos_theta_star_L0bar_L0bar_0_10->GetParameter(0);
    double B33_divided_0_10 = fit_corrected_outside_cos_theta_star_L0bar_L0bar_0_10->GetParameter(1);
    double B33_error_0_10 = fit_corrected_outside_cos_theta_star_L0bar_L0bar_0_10->GetParError(1);
    cout << "Fit Parameters: Kristen's corrected L0bar-L0bar Pairs outside #DeltaR (After Background Subtraction):" << endl;
    cout << "A: " << A33_divided_0_10 << endl;
    cout << "B: " << B33_divided_0_10 << endl;

    double P_corrected_outside_lbarlbar_0_10 = B33_divided_0_10 / constant_value_3;
    double P_corrected_outside_lbarlbar_error_0_10 = B33_error_0_10 / constant_value_3;
    std::cout << "Polarization (L0-L0Bar): " << P_corrected_outside_lbarlbar_0_10 << " ± " << P_corrected_outside_lbarlbar_error_0_10 << std::endl;

    h_corrected_outside_cos_theta_star_L0bar_L0bar_0_10->SetStats(0);
    h_corrected_outside_cos_theta_star_L0bar_L0bar_0_10->SetMinimum(0);
    h_corrected_outside_cos_theta_star_L0bar_L0bar_0_10->SetMarkerStyle(20);
    h_corrected_outside_cos_theta_star_L0bar_L0bar_0_10->SetMarkerColor(kBlue);
    h_corrected_outside_cos_theta_star_L0bar_L0bar_0_10->SetTitle("#bar{#Lambda}#bar{#Lambda} Pairs outside #DeltaR (0-10% Centrality); cos(#theta*); dN/dCos(#theta*)"); 
    h_corrected_outside_cos_theta_star_L0bar_L0bar_0_10->GetXaxis()->CenterTitle();
    h_corrected_outside_cos_theta_star_L0bar_L0bar_0_10->GetYaxis()->CenterTitle();
    h_corrected_outside_cos_theta_star_L0bar_L0bar_0_10->Draw("PE");

    TLegend *legend_corrected_outside_L0bar_L0bar_0_10 = new TLegend(0.15, 0.2, 0.4, 0.3);
    legend_corrected_outside_L0bar_L0bar_0_10->SetBorderSize(1);    
    legend_corrected_outside_L0bar_L0bar_0_10->SetTextSize(0.03);   
    legend_corrected_outside_L0bar_L0bar_0_10->SetBorderSize(0);
    legend_corrected_outside_L0bar_L0bar_0_10->SetFillStyle(0); 
    legend_corrected_outside_L0bar_L0bar_0_10->AddEntry(h_corrected_cos_theta_star_L0bar_L0bar_0_10, "#bar{#Lambda}#bar{#Lambda} pairs", "p");
    legend_corrected_outside_L0bar_L0bar_0_10->AddEntry(fit_corrected_cos_theta_star_L0bar_L0bar_0_10, "fit");
    legend_corrected_outside_L0bar_L0bar_0_10->Draw();

    cout << "Canvas 13 Complete" << endl;

    TCanvas *c14 = new TCanvas("c14", "c14- Corrected Distributions (10-40% Centrality)", 1800, 900);
    c14->Divide(3, 2);

    c14->cd(1);
    cout << "   " << endl;
    cout << "Canvas 7, Pad 1" << endl;

    TH1D *h_corrected_cos_theta_star_L0_L0bar_10_40 = new TH1D(*h_correct_cos_theta_star_L0_L0bar_10_40);
    h_corrected_cos_theta_star_L0_L0bar_10_40->Add(h_correct_cos_theta_star_L0_L0bar_2_10_40, -1.0);

    cout << "   " << endl;
    cout << "Fit Parameters: Kristen's Data after ME correction and background subtraction" << endl;
    TF1 *fit_corrected_cos_theta_star_L0_L0bar_10_40 = new TF1("fit_corrected_cos_theta_star_L0_L0bar_10_40", "[0] * (1 + [1] * x)", -1, 1);
    fit_corrected_cos_theta_star_L0_L0bar_10_40->SetParameters(1, 1);
    fit_corrected_cos_theta_star_L0_L0bar_10_40->SetLineColor(kBlue);
    h_corrected_cos_theta_star_L0_L0bar_10_40->Fit(fit_corrected_cos_theta_star_L0_L0bar_10_40, "R");

    double A22_divided_10_40 = fit_corrected_cos_theta_star_L0_L0bar_10_40->GetParameter(0);
    double B22_divided_10_40 = fit_corrected_cos_theta_star_L0_L0bar_10_40->GetParameter(1);
    double B22_error_10_40 = fit_corrected_cos_theta_star_L0_L0bar_10_40->GetParError(1);
    cout << "Fit Parameters: Kristen's corrected L0-L0bar Pairs inside #DeltaR (After Background Subtraction):" << endl;
    cout << "A: " << A22_divided_10_40 << endl;
    cout << "B: " << B22_divided_10_40 << endl;

    double P_corrected_llbar_10_40 = B22_divided_10_40 / constant_value;
    double P_corrected_llbar_error_10_40 = B22_error_10_40 / constant_value;
    std::cout << "Polarization (L0-L0Bar): " << P_corrected_llbar_10_40 << " ± " << P_corrected_llbar_error_10_40 << std::endl;

    h_corrected_cos_theta_star_L0_L0bar_10_40->SetStats(0);
    h_corrected_cos_theta_star_L0_L0bar_10_40->SetMinimum(0);
    h_corrected_cos_theta_star_L0_L0bar_10_40->SetMarkerStyle(20);
    h_corrected_cos_theta_star_L0_L0bar_10_40->SetMarkerColor(kBlue);
    h_corrected_cos_theta_star_L0_L0bar_10_40->SetTitle("#Lambda#bar{#Lambda} Pairs Inside #DeltaR (10-40 Centrality); cos(#theta*); dN/dCos(#theta*)"); 
    h_corrected_cos_theta_star_L0_L0bar_10_40->GetXaxis()->CenterTitle();
    h_corrected_cos_theta_star_L0_L0bar_10_40->GetYaxis()->CenterTitle();
    h_corrected_cos_theta_star_L0_L0bar_10_40->Draw("PE");

    TLegend *legend_corrected_L0_L0bar_10_40 = new TLegend(0.15, 0.2, 0.4, 0.3);
    legend_corrected_L0_L0bar_10_40->SetBorderSize(1);    
    legend_corrected_L0_L0bar_10_40->SetTextSize(0.03);   
    legend_corrected_L0_L0bar_10_40->SetBorderSize(0);
    legend_corrected_L0_L0bar_10_40->SetFillStyle(0); 
    legend_corrected_L0_L0bar_10_40->AddEntry(h_corrected_cos_theta_star_L0_L0bar_10_40, "#Lambda#bar{#Lambda} Pairs", "p");
    legend_corrected_L0_L0bar_10_40->AddEntry(fit_corrected_cos_theta_star_L0_L0bar_10_40, "fit");
    legend_corrected_L0_L0bar_10_40->Draw();

    c14->cd(2);
    cout << "   " << endl;
    cout << "Canvas 7, Pad 2" << endl;

    TH1D *h_corrected_cos_theta_star_L0_L0_10_40 = new TH1D(*h_correct_cos_theta_star_L0_L0_10_40);
    h_corrected_cos_theta_star_L0_L0_10_40->Add(h_correct_cos_theta_star_L0_L0_2_10_40, -1.0);

    cout << "   " << endl;
    cout << "Fit Parameters: Kristen's Data after ME correction and background subtraction" << endl;
    TF1 *fit_corrected_cos_theta_star_L0_L0_10_40 = new TF1("fit_corrected_cos_theta_star_L0_L0_10_40", "[0] * (1 + [1] * x)", -1, 1);
    fit_corrected_cos_theta_star_L0_L0_10_40->SetParameters(1, 1);
    fit_corrected_cos_theta_star_L0_L0_10_40->SetLineColor(kBlue);
    h_corrected_cos_theta_star_L0_L0_10_40->Fit(fit_corrected_cos_theta_star_L0_L0_10_40, "R");

    double A21_divided_10_40 = fit_corrected_cos_theta_star_L0_L0_10_40->GetParameter(0);
    double B21_divided_10_40 = fit_corrected_cos_theta_star_L0_L0_10_40->GetParameter(1);
    double B21_error_10_40 = fit_corrected_cos_theta_star_L0_L0_10_40->GetParError(1);
    cout << "Fit Parameters: Kristen's corrected L0-L0 Pairs inside #DeltaR (After Background Subtraction):" << endl;
    cout << "A: " << A21_divided_10_40 << endl;
    cout << "B: " << B21_divided_10_40 << endl;

    double P_corrected_ll_10_40 = B21_divided_10_40 / constant_value_2;
    double P_corrected_ll_error_10_40 = B21_error_10_40 / constant_value_2;
    std::cout << "Polarization (L0-L0Bar): " << P_corrected_ll_10_40 << " ± " << P_corrected_ll_error_10_40 << std::endl; 

    h_corrected_cos_theta_star_L0_L0_10_40->SetStats(0);
    h_corrected_cos_theta_star_L0_L0_10_40->SetMinimum(0);
    h_corrected_cos_theta_star_L0_L0_10_40->SetMarkerStyle(20);
    h_corrected_cos_theta_star_L0_L0_10_40->SetMarkerColor(kBlue);
    h_corrected_cos_theta_star_L0_L0_10_40->SetTitle("#Lambda#Lambda Pairs Inside #DeltaR (10-40% Centrality); cos(#theta*); dN/dCos(#theta*)"); 
    h_corrected_cos_theta_star_L0_L0_10_40->GetXaxis()->CenterTitle();
    h_corrected_cos_theta_star_L0_L0_10_40->GetYaxis()->CenterTitle();
    h_corrected_cos_theta_star_L0_L0_10_40->Draw("PE");

    TLegend *legend_corrected_L0_L0_10_40 = new TLegend(0.15, 0.2, 0.4, 0.3);
    legend_corrected_L0_L0_10_40->SetBorderSize(1);    
    legend_corrected_L0_L0_10_40->SetTextSize(0.03);   
    legend_corrected_L0_L0_10_40->SetBorderSize(0);
    legend_corrected_L0_L0_10_40->SetFillStyle(0); 
    legend_corrected_L0_L0_10_40->AddEntry(h_corrected_cos_theta_star_L0_L0_10_40, "#Lambda#Lambda Pairs", "p");
    legend_corrected_L0_L0_10_40->AddEntry(fit_corrected_cos_theta_star_L0_L0_10_40, "fit");
    legend_corrected_L0_L0_10_40->Draw();

    c14->cd(3);
    cout << "   " << endl;
    cout << "Canvas 7, Pad 3" << endl;

    TH1D *h_corrected_cos_theta_star_L0bar_L0bar_10_40 = new TH1D(*h_correct_cos_theta_star_L0bar_L0bar_10_40);
    h_corrected_cos_theta_star_L0bar_L0bar_10_40->Add(h_correct_cos_theta_star_L0bar_L0bar_2_10_40, -1.0);

    cout << "   " << endl;
    cout << "Fit Parameters: Kristen's Data after ME correction and background subtraction" << endl;
    TF1 *fit_corrected_cos_theta_star_L0bar_L0bar_10_40 = new TF1("fit_corrected_cos_theta_star_L0bar_L0bar_10_40", "[0] * (1 + [1] * x)", -1, 1);
    fit_corrected_cos_theta_star_L0bar_L0bar_10_40->SetParameters(1, 1);
    fit_corrected_cos_theta_star_L0bar_L0bar_10_40->SetLineColor(kBlue);
    h_corrected_cos_theta_star_L0bar_L0bar_10_40->Fit(fit_corrected_cos_theta_star_L0bar_L0bar_10_40, "R");

    double A23_divided_10_40 = fit_corrected_cos_theta_star_L0bar_L0bar_10_40->GetParameter(0);
    double B23_divided_10_40 = fit_corrected_cos_theta_star_L0bar_L0bar_10_40->GetParameter(1);
    double B23_error_10_40 = fit_corrected_cos_theta_star_L0bar_L0bar_10_40->GetParError(1);
    cout << "Fit Parameters: Kristen's corrected L0bar-L0bar Pairs inside #DeltaR (After Background Subtraction):" << endl;
    cout << "A: " << A23_divided_10_40 << endl;
    cout << "B: " << B23_divided_10_40 << endl;

    double P_corrected_lbarlbar_10_40 = B23_divided_10_40 / constant_value_3;
    double P_corrected_lbarlbar_error_10_40 = B23_error_10_40 / constant_value_3;
    std::cout << "Polarization (L0-L0Bar): " << P_corrected_lbarlbar_10_40 << " ± " << P_corrected_lbarlbar_error_10_40 << std::endl;

    h_corrected_cos_theta_star_L0bar_L0bar_10_40->SetStats(0);
    h_corrected_cos_theta_star_L0bar_L0bar_10_40->SetMinimum(0);
    h_corrected_cos_theta_star_L0bar_L0bar_10_40->SetMarkerStyle(20);
    h_corrected_cos_theta_star_L0bar_L0bar_10_40->SetMarkerColor(kBlue);
    h_corrected_cos_theta_star_L0bar_L0bar_10_40->SetTitle("#bar{#Lambda}#bar{#Lambda} Pairs Inside #DeltaR (10-40% Centrality); cos(#theta*); dN/dCos(#theta*)"); 
    h_corrected_cos_theta_star_L0bar_L0bar_10_40->GetXaxis()->CenterTitle();
    h_corrected_cos_theta_star_L0bar_L0bar_10_40->GetYaxis()->CenterTitle();
    h_corrected_cos_theta_star_L0bar_L0bar_10_40->Draw("PE");

    TLegend *legend_corrected_L0bar_L0bar_10_40 = new TLegend(0.15, 0.2, 0.4, 0.3);
    legend_corrected_L0bar_L0bar_10_40->SetBorderSize(1);    
    legend_corrected_L0bar_L0bar_10_40->SetTextSize(0.03);   
    legend_corrected_L0bar_L0bar_10_40->SetBorderSize(0);
    legend_corrected_L0bar_L0bar_10_40->SetFillStyle(0); 
    legend_corrected_L0bar_L0bar_10_40->AddEntry(h_corrected_cos_theta_star_L0bar_L0bar_10_40, "#bar{#Lambda}#bar{#Lambda} pairs", "p");
    legend_corrected_L0bar_L0bar_10_40->AddEntry(fit_corrected_cos_theta_star_L0bar_L0bar_10_40, "fit");
    legend_corrected_L0bar_L0bar_10_40->Draw();

    c14->cd(4);
    cout << "   " << endl;
    cout << "Canvas 7, Pad 4" << endl;

    TH1D *h_corrected_outside_cos_theta_star_L0_L0bar_10_40 = new TH1D(*h_correct_outside_cos_theta_star_L0_L0bar_10_40);
    h_corrected_outside_cos_theta_star_L0_L0bar_10_40->Add(h_correct_outside_cos_theta_star_L0_L0bar_2_10_40, -1.0);

    cout << "   " << endl;
    cout << "Fit Parameters: Kristen's Data after ME correction and background subtraction" << endl;
    TF1 *fit_corrected_outside_cos_theta_star_L0_L0bar_10_40 = new TF1("fit_corrected_outside_cos_theta_star_L0_L0bar_10_40", "[0] * (1 + [1] * x)", -1, 1);
    fit_corrected_outside_cos_theta_star_L0_L0bar_10_40->SetParameters(1, 1);
    fit_corrected_outside_cos_theta_star_L0_L0bar_10_40->SetLineColor(kBlue);
    h_corrected_outside_cos_theta_star_L0_L0bar_10_40->Fit(fit_corrected_outside_cos_theta_star_L0_L0bar_10_40, "R");

    double A32_divided_10_40 = fit_corrected_outside_cos_theta_star_L0_L0bar_10_40->GetParameter(0);
    double B32_divided_10_40 = fit_corrected_outside_cos_theta_star_L0_L0bar_10_40->GetParameter(1);
    double B32_error_10_40 = fit_corrected_outside_cos_theta_star_L0_L0bar_10_40->GetParError(1);
    cout << "Fit Parameters: Kristen's corrected L0-L0bar Pairs outside #DeltaR (After Background Subtraction):" << endl;
    cout << "A: " << A32_divided_10_40 << endl;
    cout << "B: " << B32_divided_10_40 << endl;

    double P_corrected_outside_llbar_10_40 = B32_divided_10_40 / constant_value;
    double P_corrected_outside_llbar_error_10_40 = B32_error_10_40 / constant_value;
    std::cout << "Polarization (L0-L0Bar): " << P_corrected_outside_llbar_10_40 << " ± " << P_corrected_outside_llbar_error_10_40 << std::endl;

    h_corrected_outside_cos_theta_star_L0_L0bar_10_40->SetStats(0);
    h_corrected_outside_cos_theta_star_L0_L0bar_10_40->SetMinimum(0);
    h_corrected_outside_cos_theta_star_L0_L0bar_10_40->SetMarkerStyle(20);
    h_corrected_outside_cos_theta_star_L0_L0bar_10_40->SetMarkerColor(kBlue);
    h_corrected_outside_cos_theta_star_L0_L0bar_10_40->SetTitle("#Lambda#bar{#Lambda} Pairs outside #DeltaR (10-40% Centrality); cos(#theta*); dN/dCos(#theta*)"); 
    h_corrected_outside_cos_theta_star_L0_L0bar_10_40->GetXaxis()->CenterTitle();
    h_corrected_outside_cos_theta_star_L0_L0bar_10_40->GetYaxis()->CenterTitle();
    h_corrected_outside_cos_theta_star_L0_L0bar_10_40->Draw("PE");

    TLegend *legend_corrected_outside_L0_L0bar_10_40 = new TLegend(0.15, 0.2, 0.4, 0.3);
    legend_corrected_outside_L0_L0bar_10_40->SetBorderSize(1);    
    legend_corrected_outside_L0_L0bar_10_40->SetTextSize(0.03);   
    legend_corrected_outside_L0_L0bar_10_40->SetBorderSize(0);
    legend_corrected_outside_L0_L0bar_10_40->SetFillStyle(0); 
    legend_corrected_outside_L0_L0bar_10_40->AddEntry(h_corrected_cos_theta_star_L0_L0bar_10_40, "#Lambda#bar{#Lambda} pairs", "p");
    legend_corrected_outside_L0_L0bar_10_40->AddEntry(fit_corrected_cos_theta_star_L0_L0bar_10_40, "fit");
    legend_corrected_outside_L0_L0bar_10_40->Draw();

    c14->cd(5);
    cout << "   " << endl;
    cout << "Canvas 7, Pad 5" << endl;

    TH1D *h_corrected_outside_cos_theta_star_L0_L0_10_40 = new TH1D(*h_correct_outside_cos_theta_star_L0_L0_10_40);
    h_corrected_outside_cos_theta_star_L0_L0_10_40->Add(h_correct_outside_cos_theta_star_L0_L0_2_10_40, -1.0);

    cout << "   " << endl;
    cout << "Fit Parameters: Kristen's Data after ME correction and background subtraction" << endl;
    TF1 *fit_corrected_outside_cos_theta_star_L0_L0_10_40 = new TF1("fit_corrected_outside_cos_theta_star_L0_L0_10_40", "[0] * (1 + [1] * x)", -1, 1);
    fit_corrected_outside_cos_theta_star_L0_L0_10_40->SetParameters(1, 1);
    fit_corrected_outside_cos_theta_star_L0_L0_10_40->SetLineColor(kBlue);
    h_corrected_outside_cos_theta_star_L0_L0_10_40->Fit(fit_corrected_outside_cos_theta_star_L0_L0_10_40, "R");

    double A31_divided_10_40 = fit_corrected_outside_cos_theta_star_L0_L0_10_40->GetParameter(0);
    double B31_divided_10_40 = fit_corrected_outside_cos_theta_star_L0_L0_10_40->GetParameter(1);
    double B31_error_10_40 = fit_corrected_outside_cos_theta_star_L0_L0_10_40->GetParError(1);
    cout << "Fit Parameters: Kristen's corrected L0-L0 Pairs outside #DeltaR (After Background Subtraction):" << endl;
    cout << "A: " << A31_divided_10_40 << endl;
    cout << "B: " << B31_divided_10_40 << endl;

    double P_corrected_outside_ll_10_40 = B31_divided_10_40 / constant_value_2;
    double P_corrected_outside_ll_error_10_40 = B31_error_10_40 / constant_value_2;
    std::cout << "Polarization (L0-L0Bar): " << P_corrected_outside_ll_10_40 << " ± " << P_corrected_outside_ll_error_10_40 << std::endl; 

    h_corrected_outside_cos_theta_star_L0_L0_10_40->SetStats(0);
    h_corrected_outside_cos_theta_star_L0_L0_10_40->SetMinimum(0);
    h_corrected_outside_cos_theta_star_L0_L0_10_40->SetMarkerStyle(20);
    h_corrected_outside_cos_theta_star_L0_L0_10_40->SetMarkerColor(kBlue);
    h_corrected_outside_cos_theta_star_L0_L0_10_40->SetTitle("#Lambda#Lambda Pairs outside #DeltaR (10-40% Centrality); cos(#theta*); dN/dCos(#theta*)"); 
    h_corrected_outside_cos_theta_star_L0_L0_10_40->GetXaxis()->CenterTitle();
    h_corrected_outside_cos_theta_star_L0_L0_10_40->GetYaxis()->CenterTitle();
    h_corrected_outside_cos_theta_star_L0_L0_10_40->Draw("PE");

    TLegend *legend_corrected_outside_L0_L0_10_40 = new TLegend(0.15, 0.2, 0.4, 0.3);
    legend_corrected_outside_L0_L0_10_40->SetBorderSize(1);    
    legend_corrected_outside_L0_L0_10_40->SetTextSize(0.03);   
    legend_corrected_outside_L0_L0_10_40->SetBorderSize(0);
    legend_corrected_outside_L0_L0_10_40->SetFillStyle(0); 
    legend_corrected_outside_L0_L0_10_40->AddEntry(h_corrected_cos_theta_star_L0_L0_10_40, "#Lambda#Lambda pairs", "p");
    legend_corrected_outside_L0_L0_10_40->AddEntry(fit_corrected_cos_theta_star_L0_L0_10_40, "fit");
    legend_corrected_outside_L0_L0_10_40->Draw();

    c14->cd(6);
    cout << "   " << endl;
    cout << "Canvas 7, Pad 6" << endl;

    TH1D *h_corrected_outside_cos_theta_star_L0bar_L0bar_10_40 = new TH1D(*h_correct_outside_cos_theta_star_L0bar_L0bar_10_40);
    h_corrected_outside_cos_theta_star_L0bar_L0bar_10_40->Add(h_correct_outside_cos_theta_star_L0bar_L0bar_2_10_40, -1.0);

    cout << "   " << endl;
    cout << "Fit Parameters: Kristen's Data after ME correction and background subtraction" << endl;
    TF1 *fit_corrected_outside_cos_theta_star_L0bar_L0bar_10_40 = new TF1("fit_corrected_outside_cos_theta_star_L0bar_L0bar_10_40", "[0] * (1 + [1] * x)", -1, 1);
    fit_corrected_outside_cos_theta_star_L0bar_L0bar_10_40->SetParameters(1, 1);
    fit_corrected_outside_cos_theta_star_L0bar_L0bar_10_40->SetLineColor(kBlue);
    h_corrected_outside_cos_theta_star_L0bar_L0bar_10_40->Fit(fit_corrected_outside_cos_theta_star_L0bar_L0bar_10_40, "R");

    double A33_divided_10_40 = fit_corrected_outside_cos_theta_star_L0bar_L0bar_10_40->GetParameter(0);
    double B33_divided_10_40 = fit_corrected_outside_cos_theta_star_L0bar_L0bar_10_40->GetParameter(1);
    double B33_error_10_40 = fit_corrected_outside_cos_theta_star_L0bar_L0bar_10_40->GetParError(1);
    cout << "Fit Parameters: Kristen's corrected L0bar-L0bar Pairs outside #DeltaR (After Background Subtraction):" << endl;
    cout << "A: " << A33_divided_10_40 << endl;
    cout << "B: " << B33_divided_10_40 << endl;

    double P_corrected_outside_lbarlbar_10_40 = B33_divided_10_40 / constant_value_3;
    double P_corrected_outside_lbarlbar_error_10_40 = B33_error_10_40 / constant_value_3;
    std::cout << "Polarization (L0-L0Bar): " << P_corrected_outside_lbarlbar_10_40 << " ± " << P_corrected_outside_lbarlbar_error_10_40 << std::endl;

    h_corrected_outside_cos_theta_star_L0bar_L0bar_10_40->SetStats(0);
    h_corrected_outside_cos_theta_star_L0bar_L0bar_10_40->SetMinimum(0);
    h_corrected_outside_cos_theta_star_L0bar_L0bar_10_40->SetMarkerStyle(20);
    h_corrected_outside_cos_theta_star_L0bar_L0bar_10_40->SetMarkerColor(kBlue);
    h_corrected_outside_cos_theta_star_L0bar_L0bar_10_40->SetTitle("#bar{#Lambda}#bar{#Lambda} Pairs outside #DeltaR (10-40% Centrality); cos(#theta*); dN/dCos(#theta*)"); 
    h_corrected_outside_cos_theta_star_L0bar_L0bar_10_40->GetXaxis()->CenterTitle();
    h_corrected_outside_cos_theta_star_L0bar_L0bar_10_40->GetYaxis()->CenterTitle();
    h_corrected_outside_cos_theta_star_L0bar_L0bar_10_40->Draw("PE");

    TLegend *legend_corrected_outside_L0bar_L0bar_10_40 = new TLegend(0.15, 0.2, 0.4, 0.3);
    legend_corrected_outside_L0bar_L0bar_10_40->SetBorderSize(1);    
    legend_corrected_outside_L0bar_L0bar_10_40->SetTextSize(0.03);   
    legend_corrected_outside_L0bar_L0bar_10_40->SetBorderSize(0);
    legend_corrected_outside_L0bar_L0bar_10_40->SetFillStyle(0); 
    legend_corrected_outside_L0bar_L0bar_10_40->AddEntry(h_corrected_cos_theta_star_L0bar_L0bar_10_40, "#bar{#Lambda}#bar{#Lambda} pairs", "p");
    legend_corrected_outside_L0bar_L0bar_10_40->AddEntry(fit_corrected_cos_theta_star_L0bar_L0bar_10_40, "fit");
    legend_corrected_outside_L0bar_L0bar_10_40->Draw();

    TCanvas *c15 = new TCanvas("c15", "c15- Corrected Distributions (40-80% Centrality)", 1800, 900);
    c15->Divide(3, 2);

    c15->cd(1);
    cout << "   " << endl;
    cout << "Canvas 7, Pad 1" << endl;

    TH1D *h_corrected_cos_theta_star_L0_L0bar_40_80 = new TH1D(*h_correct_cos_theta_star_L0_L0bar_40_80);
    h_corrected_cos_theta_star_L0_L0bar_40_80->Add(h_correct_cos_theta_star_L0_L0bar_2_40_80, -1.0);

    cout << "   " << endl;
    cout << "Fit Parameters: Kristen's Data after ME correction and background subtraction" << endl;
    TF1 *fit_corrected_cos_theta_star_L0_L0bar_40_80 = new TF1("fit_corrected_cos_theta_star_L0_L0bar_40_80", "[0] * (1 + [1] * x)", -1, 1);
    fit_corrected_cos_theta_star_L0_L0bar_40_80->SetParameters(1, 1);
    fit_corrected_cos_theta_star_L0_L0bar_40_80->SetLineColor(kBlue);
    h_corrected_cos_theta_star_L0_L0bar_40_80->Fit(fit_corrected_cos_theta_star_L0_L0bar_40_80, "R");

    double A22_divided_40_80 = fit_corrected_cos_theta_star_L0_L0bar_40_80->GetParameter(0);
    double B22_divided_40_80 = fit_corrected_cos_theta_star_L0_L0bar_40_80->GetParameter(1);
    double B22_error_40_80 = fit_corrected_cos_theta_star_L0_L0bar_40_80->GetParError(1);
    cout << "Fit Parameters: Kristen's corrected L0-L0bar Pairs inside #DeltaR (After Background Subtraction):" << endl;
    cout << "A: " << A22_divided_40_80 << endl;
    cout << "B: " << B22_divided_40_80 << endl;

    double P_corrected_llbar_40_80 = B22_divided_40_80 / constant_value;
    double P_corrected_llbar_error_40_80 = B22_error_40_80 / constant_value;
    std::cout << "Polarization (L0-L0Bar): " << P_corrected_llbar_40_80 << " ± " << P_corrected_llbar_error_40_80 << std::endl;

    h_corrected_cos_theta_star_L0_L0bar_40_80->SetStats(0);
    h_corrected_cos_theta_star_L0_L0bar_40_80->SetMinimum(0);
    h_corrected_cos_theta_star_L0_L0bar_40_80->SetMarkerStyle(20);
    h_corrected_cos_theta_star_L0_L0bar_40_80->SetMarkerColor(kBlue);
    h_corrected_cos_theta_star_L0_L0bar_40_80->SetTitle("#Lambda#bar{#Lambda} Pairs Inside #DeltaR (40-80% Centrality); cos(#theta*); dN/dCos(#theta*)"); 
    h_corrected_cos_theta_star_L0_L0bar_40_80->GetXaxis()->CenterTitle();
    h_corrected_cos_theta_star_L0_L0bar_40_80->GetYaxis()->CenterTitle();
    h_corrected_cos_theta_star_L0_L0bar_40_80->Draw("PE");

    TLegend *legend_corrected_L0_L0bar_40_80 = new TLegend(0.15, 0.2, 0.4, 0.3);
    legend_corrected_L0_L0bar_40_80->SetBorderSize(1);    
    legend_corrected_L0_L0bar_40_80->SetTextSize(0.03);   
    legend_corrected_L0_L0bar_40_80->SetBorderSize(0);
    legend_corrected_L0_L0bar_40_80->SetFillStyle(0); 
    legend_corrected_L0_L0bar_40_80->AddEntry(h_corrected_cos_theta_star_L0_L0bar_40_80, "#Lambda#bar{#Lambda} Pairs", "p");
    legend_corrected_L0_L0bar_40_80->AddEntry(fit_corrected_cos_theta_star_L0_L0bar_40_80, "fit");
    legend_corrected_L0_L0bar_40_80->Draw();

    c15->cd(2);
    cout << "   " << endl;
    cout << "Canvas 7, Pad 2" << endl;

    TH1D *h_corrected_cos_theta_star_L0_L0_40_80 = new TH1D(*h_correct_cos_theta_star_L0_L0_40_80);
    h_corrected_cos_theta_star_L0_L0_40_80->Add(h_correct_cos_theta_star_L0_L0_2_40_80, -1.0);

    cout << "   " << endl;
    cout << "Fit Parameters: Kristen's Data after ME correction and background subtraction" << endl;
    TF1 *fit_corrected_cos_theta_star_L0_L0_40_80 = new TF1("fit_corrected_cos_theta_star_L0_L0_40_80", "[0] * (1 + [1] * x)", -1, 1);
    fit_corrected_cos_theta_star_L0_L0_40_80->SetParameters(1, 1);
    fit_corrected_cos_theta_star_L0_L0_40_80->SetLineColor(kBlue);
    h_corrected_cos_theta_star_L0_L0_40_80->Fit(fit_corrected_cos_theta_star_L0_L0_40_80, "R");

    double A21_divided_40_80 = fit_corrected_cos_theta_star_L0_L0_40_80->GetParameter(0);
    double B21_divided_40_80 = fit_corrected_cos_theta_star_L0_L0_40_80->GetParameter(1);
    double B21_error_40_80 = fit_corrected_cos_theta_star_L0_L0_40_80->GetParError(1);
    cout << "Fit Parameters: Kristen's corrected L0-L0 Pairs inside #DeltaR (After Background Subtraction):" << endl;
    cout << "A: " << A21_divided_40_80 << endl;
    cout << "B: " << B21_divided_40_80 << endl;

    double P_corrected_ll_40_80 = B21_divided_40_80 / constant_value_2;
    double P_corrected_ll_error_40_80 = B21_error_40_80 / constant_value_2;
    std::cout << "Polarization (L0-L0Bar): " << P_corrected_ll_40_80 << " ± " << P_corrected_ll_error_40_80 << std::endl; 

    h_corrected_cos_theta_star_L0_L0_40_80->SetStats(0);
    h_corrected_cos_theta_star_L0_L0_40_80->SetMinimum(0);
    h_corrected_cos_theta_star_L0_L0_40_80->SetMarkerStyle(20);
    h_corrected_cos_theta_star_L0_L0_40_80->SetMarkerColor(kBlue);
    h_corrected_cos_theta_star_L0_L0_40_80->SetTitle("#Lambda#Lambda Pairs Inside #DeltaR (40-80% Centrality); cos(#theta*); dN/dCos(#theta*)"); 
    h_corrected_cos_theta_star_L0_L0_40_80->GetXaxis()->CenterTitle();
    h_corrected_cos_theta_star_L0_L0_40_80->GetYaxis()->CenterTitle();
    h_corrected_cos_theta_star_L0_L0_40_80->Draw("PE");

    TLegend *legend_corrected_L0_L0_40_80 = new TLegend(0.15, 0.2, 0.4, 0.3);
    legend_corrected_L0_L0_40_80->SetBorderSize(1);    
    legend_corrected_L0_L0_40_80->SetTextSize(0.03);   
    legend_corrected_L0_L0_40_80->SetBorderSize(0);
    legend_corrected_L0_L0_40_80->SetFillStyle(0); 
    legend_corrected_L0_L0_40_80->AddEntry(h_corrected_cos_theta_star_L0_L0_40_80, "#Lambda#Lambda Pairs", "p");
    legend_corrected_L0_L0_40_80->AddEntry(fit_corrected_cos_theta_star_L0_L0_40_80, "fit");
    legend_corrected_L0_L0_40_80->Draw();

    c15->cd(3);
    cout << "   " << endl;
    cout << "Canvas 7, Pad 3" << endl;

    TH1D *h_corrected_cos_theta_star_L0bar_L0bar_40_80 = new TH1D(*h_correct_cos_theta_star_L0bar_L0bar_40_80);
    h_corrected_cos_theta_star_L0bar_L0bar_40_80->Add(h_correct_cos_theta_star_L0bar_L0bar_2_40_80, -1.0);

    cout << "   " << endl;
    cout << "Fit Parameters: Kristen's Data after ME correction and background subtraction" << endl;
    TF1 *fit_corrected_cos_theta_star_L0bar_L0bar_40_80 = new TF1("fit_corrected_cos_theta_star_L0bar_L0bar_40_80", "[0] * (1 + [1] * x)", -1, 1);
    fit_corrected_cos_theta_star_L0bar_L0bar_40_80->SetParameters(1, 1);
    fit_corrected_cos_theta_star_L0bar_L0bar_40_80->SetLineColor(kBlue);
    h_corrected_cos_theta_star_L0bar_L0bar_40_80->Fit(fit_corrected_cos_theta_star_L0bar_L0bar_40_80, "R");

    double A23_divided_40_80 = fit_corrected_cos_theta_star_L0bar_L0bar_40_80->GetParameter(0);
    double B23_divided_40_80 = fit_corrected_cos_theta_star_L0bar_L0bar_40_80->GetParameter(1);
    double B23_error_40_80 = fit_corrected_cos_theta_star_L0bar_L0bar_40_80->GetParError(1);
    cout << "Fit Parameters: Kristen's corrected L0bar-L0bar Pairs inside #DeltaR (After Background Subtraction):" << endl;
    cout << "A: " << A23_divided_40_80 << endl;
    cout << "B: " << B23_divided_40_80 << endl;

    double P_corrected_lbarlbar_40_80 = B23_divided_40_80 / constant_value_3;
    double P_corrected_lbarlbar_error_40_80 = B23_error_40_80 / constant_value_3;
    std::cout << "Polarization (L0-L0Bar): " << P_corrected_lbarlbar_40_80 << " ± " << P_corrected_lbarlbar_error_40_80 << std::endl;

    h_corrected_cos_theta_star_L0bar_L0bar_40_80->SetStats(0);
    h_corrected_cos_theta_star_L0bar_L0bar_40_80->SetMinimum(0);
    h_corrected_cos_theta_star_L0bar_L0bar_40_80->SetMarkerStyle(20);
    h_corrected_cos_theta_star_L0bar_L0bar_40_80->SetMarkerColor(kBlue);
    h_corrected_cos_theta_star_L0bar_L0bar_40_80->SetTitle("#bar{#Lambda}#bar{#Lambda} Pairs Inside #DeltaR (40-80% Centrality); cos(#theta*); dN/dCos(#theta*)"); 
    h_corrected_cos_theta_star_L0bar_L0bar_40_80->GetXaxis()->CenterTitle();
    h_corrected_cos_theta_star_L0bar_L0bar_40_80->GetYaxis()->CenterTitle();
    h_corrected_cos_theta_star_L0bar_L0bar_40_80->Draw("PE");

    TLegend *legend_corrected_L0bar_L0bar_40_80 = new TLegend(0.15, 0.2, 0.4, 0.3);
    legend_corrected_L0bar_L0bar_40_80->SetBorderSize(1);    
    legend_corrected_L0bar_L0bar_40_80->SetTextSize(0.03);   
    legend_corrected_L0bar_L0bar_40_80->SetBorderSize(0);
    legend_corrected_L0bar_L0bar_40_80->SetFillStyle(0); 
    legend_corrected_L0bar_L0bar_40_80->AddEntry(h_corrected_cos_theta_star_L0bar_L0bar_40_80, "#bar{#Lambda}#bar{#Lambda} pairs", "p");
    legend_corrected_L0bar_L0bar_40_80->AddEntry(fit_corrected_cos_theta_star_L0bar_L0bar_40_80, "Kristen's dN/dCos(theta*): Fit");
    legend_corrected_L0bar_L0bar_40_80->Draw();

    c15->cd(4);
    cout << "   " << endl;
    cout << "Canvas 7, Pad 4" << endl;

    TH1D *h_corrected_outside_cos_theta_star_L0_L0bar_40_80 = new TH1D(*h_correct_outside_cos_theta_star_L0_L0bar_40_80);
    h_corrected_outside_cos_theta_star_L0_L0bar_40_80->Add(h_correct_outside_cos_theta_star_L0_L0bar_2_40_80, -1.0);

    cout << "   " << endl;
    cout << "Fit Parameters: Kristen's Data after ME correction and background subtraction" << endl;
    TF1 *fit_corrected_outside_cos_theta_star_L0_L0bar_40_80 = new TF1("fit_corrected_outside_cos_theta_star_L0_L0bar_40_80", "[0] * (1 + [1] * x)", -1, 1);
    fit_corrected_outside_cos_theta_star_L0_L0bar_40_80->SetParameters(1, 1);
    fit_corrected_outside_cos_theta_star_L0_L0bar_40_80->SetLineColor(kBlue);
    h_corrected_outside_cos_theta_star_L0_L0bar_40_80->Fit(fit_corrected_outside_cos_theta_star_L0_L0bar_40_80, "R");

    double A32_divided_40_80 = fit_corrected_outside_cos_theta_star_L0_L0bar_40_80->GetParameter(0);
    double B32_divided_40_80 = fit_corrected_outside_cos_theta_star_L0_L0bar_40_80->GetParameter(1);
    double B32_error_40_80 = fit_corrected_outside_cos_theta_star_L0_L0bar_40_80->GetParError(1);
    cout << "Fit Parameters: Kristen's corrected L0-L0bar Pairs outside #DeltaR (After Background Subtraction):" << endl;
    cout << "A: " << A32_divided_40_80 << endl;
    cout << "B: " << B32_divided_40_80 << endl;

    double P_corrected_outside_llbar_40_80 = B32_divided_40_80 / constant_value;
    double P_corrected_outside_llbar_error_40_80 = B32_error_40_80 / constant_value;
    std::cout << "Polarization (L0-L0Bar): " << P_corrected_outside_llbar_40_80 << " ± " << P_corrected_outside_llbar_error_40_80 << std::endl;

    h_corrected_outside_cos_theta_star_L0_L0bar_40_80->SetStats(0);
    h_corrected_outside_cos_theta_star_L0_L0bar_40_80->SetMinimum(0);
    h_corrected_outside_cos_theta_star_L0_L0bar_40_80->SetMarkerStyle(20);
    h_corrected_outside_cos_theta_star_L0_L0bar_40_80->SetMarkerColor(kBlue);
    h_corrected_outside_cos_theta_star_L0_L0bar_40_80->SetTitle("#Lambda#bar{#Lambda} Pairs outside #DeltaR (40-80% Centrality); cos(#theta*); dN/dCos(#theta*)"); 
    h_corrected_outside_cos_theta_star_L0_L0bar_40_80->GetXaxis()->CenterTitle();
    h_corrected_outside_cos_theta_star_L0_L0bar_40_80->GetYaxis()->CenterTitle();
    h_corrected_outside_cos_theta_star_L0_L0bar_40_80->Draw("PE");

    TLegend *legend_correct_outside_L0_L0bar_40_80 = new TLegend(0.15, 0.2, 0.4, 0.3);
    legend_correct_outside_L0_L0bar_40_80->SetBorderSize(1);    
    legend_correct_outside_L0_L0bar_40_80->SetTextSize(0.03);   
    legend_correct_outside_L0_L0bar_40_80->SetBorderSize(0);
    legend_correct_outside_L0_L0bar_40_80->SetFillStyle(0); 
    legend_correct_outside_L0_L0bar_40_80->AddEntry(h_corrected_cos_theta_star_L0_L0bar_40_80, "#Lambda#bar{#Lambda} pairs", "p");
    legend_correct_outside_L0_L0bar_40_80->AddEntry(fit_corrected_cos_theta_star_L0_L0bar_40_80, "fit");
    legend_correct_outside_L0_L0bar_40_80->Draw();

    c15->cd(5);
    cout << "   " << endl;
    cout << "Canvas 7, Pad 5" << endl;

    TH1D *h_corrected_outside_cos_theta_star_L0_L0_40_80 = new TH1D(*h_correct_outside_cos_theta_star_L0_L0_40_80);
    h_corrected_outside_cos_theta_star_L0_L0_40_80->Add(h_correct_outside_cos_theta_star_L0_L0_2_40_80, -1.0);

    cout << "   " << endl;
    cout << "Fit Parameters: Kristen's Data after ME correction and background subtraction" << endl;
    TF1 *fit_corrected_outside_cos_theta_star_L0_L0_40_80 = new TF1("fit_corrected_outside_cos_theta_star_L0_L0_40_80", "[0] * (1 + [1] * x)", -1, 1);
    fit_corrected_outside_cos_theta_star_L0_L0_40_80->SetParameters(1, 1);
    fit_corrected_outside_cos_theta_star_L0_L0_40_80->SetLineColor(kBlue);
    h_corrected_outside_cos_theta_star_L0_L0_40_80->Fit(fit_corrected_outside_cos_theta_star_L0_L0_40_80, "R");

    double A31_divided_40_80 = fit_corrected_outside_cos_theta_star_L0_L0_40_80->GetParameter(0);
    double B31_divided_40_80 = fit_corrected_outside_cos_theta_star_L0_L0_40_80->GetParameter(1);
    double B31_error_40_80 = fit_corrected_outside_cos_theta_star_L0_L0_40_80->GetParError(1);
    cout << "Fit Parameters: Kristen's corrected L0-L0 Pairs outside #DeltaR (After Background Subtraction):" << endl;
    cout << "A: " << A31_divided_40_80 << endl;
    cout << "B: " << B31_divided_40_80 << endl;

    double P_corrected_outside_ll_40_80 = B31_divided_40_80 / constant_value_2;
    double P_corrected_outside_ll_error_40_80 = B31_error_40_80 / constant_value_2;
    std::cout << "Polarization (L0-L0Bar): " << P_corrected_outside_ll_40_80 << " ± " << P_corrected_outside_ll_error_40_80 << std::endl; 

    h_corrected_outside_cos_theta_star_L0_L0_40_80->SetStats(0);
    h_corrected_outside_cos_theta_star_L0_L0_40_80->SetMinimum(0);
    h_corrected_outside_cos_theta_star_L0_L0_40_80->SetMarkerStyle(20);
    h_corrected_outside_cos_theta_star_L0_L0_40_80->SetMarkerColor(kBlue);
    h_corrected_outside_cos_theta_star_L0_L0_40_80->SetTitle("#Lambda#Lambda Pairs outside #DeltaR (40-80% Centrality); cos(#theta*); dN/dCos(#theta*)"); 
    h_corrected_outside_cos_theta_star_L0_L0_40_80->GetXaxis()->CenterTitle();
    h_corrected_outside_cos_theta_star_L0_L0_40_80->GetYaxis()->CenterTitle();
    h_corrected_outside_cos_theta_star_L0_L0_40_80->Draw("PE");

    TLegend *legend_corrected_outside_L0_L0_40_80 = new TLegend(0.15, 0.2, 0.4, 0.3);
    legend_corrected_outside_L0_L0_40_80->SetBorderSize(1);    
    legend_corrected_outside_L0_L0_40_80->SetTextSize(0.03);   
    legend_corrected_outside_L0_L0_40_80->SetBorderSize(0);
    legend_corrected_outside_L0_L0_40_80->SetFillStyle(0); 
    legend_corrected_outside_L0_L0_40_80->AddEntry(h_corrected_cos_theta_star_L0_L0_40_80, "#Lambda#Lambda pairs", "p");
    legend_corrected_outside_L0_L0_40_80->AddEntry(fit_corrected_cos_theta_star_L0_L0_40_80, "fit");
    legend_corrected_outside_L0_L0_40_80->Draw();

    c15->cd(6);
    cout << "   " << endl;
    cout << "Canvas 7, Pad 6" << endl;

    TH1D *h_corrected_outside_cos_theta_star_L0bar_L0bar_40_80 = new TH1D(*h_correct_outside_cos_theta_star_L0bar_L0bar_40_80);
    h_corrected_outside_cos_theta_star_L0bar_L0bar_40_80->Add(h_correct_outside_cos_theta_star_L0bar_L0bar_2_40_80, -1.0);

    cout << "   " << endl;
    cout << "Fit Parameters: Kristen's Data after ME correction and background subtraction" << endl;
    TF1 *fit_corrected_outside_cos_theta_star_L0bar_L0bar_40_80 = new TF1("fit_corrected_outside_cos_theta_star_L0bar_L0bar_40_80", "[0] * (1 + [1] * x)", -1, 1);
    fit_corrected_outside_cos_theta_star_L0bar_L0bar_40_80->SetParameters(1, 1);
    fit_corrected_outside_cos_theta_star_L0bar_L0bar_40_80->SetLineColor(kBlue);
    h_corrected_outside_cos_theta_star_L0bar_L0bar_40_80->Fit(fit_corrected_outside_cos_theta_star_L0bar_L0bar_40_80, "R");

    double A33_divided_40_80 = fit_corrected_outside_cos_theta_star_L0bar_L0bar_40_80->GetParameter(0);
    double B33_divided_40_80 = fit_corrected_outside_cos_theta_star_L0bar_L0bar_40_80->GetParameter(1);
    double B33_error_40_80 = fit_corrected_outside_cos_theta_star_L0bar_L0bar_40_80->GetParError(1);
    cout << "Fit Parameters: Kristen's corrected L0bar-L0bar Pairs outside #DeltaR (After Background Subtraction):" << endl;
    cout << "A: " << A33_divided_40_80 << endl;
    cout << "B: " << B33_divided_40_80 << endl;

    double P_corrected_outside_lbarlbar_40_80 = B33_divided_40_80 / constant_value_3;
    double P_corrected_outside_lbarlbar_error_40_80 = B33_error_40_80 / constant_value_3;
    std::cout << "Polarization (L0-L0Bar): " << P_corrected_outside_lbarlbar_40_80 << " ± " << P_corrected_outside_lbarlbar_error_40_80 << std::endl;

    h_corrected_outside_cos_theta_star_L0bar_L0bar_40_80->SetStats(0);
    h_corrected_outside_cos_theta_star_L0bar_L0bar_40_80->SetMinimum(0);
    h_corrected_outside_cos_theta_star_L0bar_L0bar_40_80->SetMarkerStyle(20);
    h_corrected_outside_cos_theta_star_L0bar_L0bar_40_80->SetMarkerColor(kBlue);
    h_corrected_outside_cos_theta_star_L0bar_L0bar_40_80->SetTitle("#bar{#Lambda}#bar{#Lambda} Pairs outside #DeltaR (40-80% Centrality); cos(#theta*); dN/dCos(#theta*)"); 
    h_corrected_outside_cos_theta_star_L0bar_L0bar_40_80->GetXaxis()->CenterTitle();
    h_corrected_outside_cos_theta_star_L0bar_L0bar_40_80->GetYaxis()->CenterTitle();
    h_corrected_outside_cos_theta_star_L0bar_L0bar_40_80->Draw("PE");

    TLegend *legend_corrected_outside_L0bar_L0bar_40_80 = new TLegend(0.15, 0.2, 0.4, 0.3);
    legend_corrected_outside_L0bar_L0bar_40_80->SetBorderSize(1);    
    legend_corrected_outside_L0bar_L0bar_40_80->SetTextSize(0.03);   
    legend_corrected_outside_L0bar_L0bar_40_80->SetBorderSize(0);
    legend_corrected_outside_L0bar_L0bar_40_80->SetFillStyle(0); 
    legend_corrected_outside_L0bar_L0bar_40_80->AddEntry(h_corrected_cos_theta_star_L0bar_L0bar_40_80, "#bar{#Lambda}#bar{#Lambda} pairs", "p");
    legend_corrected_outside_L0bar_L0bar_40_80->AddEntry(fit_corrected_cos_theta_star_L0bar_L0bar_40_80, "fit");
    legend_corrected_outside_L0bar_L0bar_40_80->Draw();

    TCanvas *c16 = new TCanvas("c16", "c16- #Lambda Polarization (0-10% Centrality)", 1800, 900);
    c16->Divide(2,2);

    double x_min3 = -0.6;
    double x_max3 = 0.3;

    double x_min4 = -0.25;
    double x_max4 = 0.2;

    c16->cd(1);
    double xValues_0_10[3] = {P_corrected_llbar_0_10, P_corrected_ll_0_10, P_corrected_lbarlbar_0_10}; 
    double yValues_0_10[3] = {1, 2, 3};

    double xErrors_0_10[3] = {P_corrected_llbar_error_0_10, P_corrected_ll_error_0_10, P_corrected_lbarlbar_error_0_10}; 
    double yErrors_0_10[3] = {0, 0, 0};

    TGraphErrors *graph_0_10 = new TGraphErrors(3, xValues_0_10, yValues_0_10, xErrors_0_10, yErrors_0_10);

    graph_0_10->SetTitle("Polarization inside #DeltaR = 0.93 (0-10% Centrality)");
    graph_0_10->SetMarkerStyle(20);
    graph_0_10->SetMarkerSize(1.5);
    graph_0_10->SetMarkerColor(kBlue);
    graph_0_10->SetLineColor(kBlue);
    graph_0_10->GetXaxis()->SetLimits(x_min3, x_max3);
    graph_0_10->GetYaxis()->SetLimits(0.5, 3.5);  // Adjust limits to fit labels properly
    graph_0_10->GetYaxis()->SetNdivisions(3);
    graph_0_10->GetYaxis()->SetLabelSize(0);
    graph_0_10->Draw("APLE");

    TLatex latex_0_10;
    latex_0_10.SetTextSize(0.04);
    latex_0_10.SetTextAlign(32);  // Right-align
    latex_0_10.DrawLatex(x_min3 - 0.0025, 1, "#Lambda^{0}#bar{#Lambda}^{0}");
    latex_0_10.DrawLatex(x_min3 - 0.0025, 2, "#Lambda^{0}#Lambda^{0}");
    latex_0_10.DrawLatex(x_min3 - 0.0025, 3, "#bar{#Lambda}^{0}#bar{#Lambda}^{0}");

    TLine *line_0_10 = new TLine(0, 0.9, 0, 3.1);
    line_0_10->SetLineColor(kRed);
    line_0_10->SetLineStyle(2);   
    line_0_10->SetLineWidth(2);   
    line_0_10->Draw();

    c16->cd(2);
    double xValues_2_0_10[3] = {P_corrected_outside_llbar_0_10, P_corrected_outside_ll_0_10, P_corrected_outside_lbarlbar_0_10}; 
    double yValues_2_0_10[3] = {1, 2, 3};

    double xErrors_2_0_10[3] = {P_corrected_outside_llbar_error_0_10, P_corrected_outside_ll_error_0_10, P_corrected_outside_lbarlbar_error_0_10}; 
    double yErrors_2_0_10[3] = {0, 0, 0};

    TGraphErrors *graph_2_0_10 = new TGraphErrors(3, xValues_2_0_10, yValues_2_0_10, xErrors_2_0_10, yErrors_2_0_10);

    graph_2_0_10->SetTitle("Polarization outside #DeltaR = 0.93 (0-10% Centrality)");
    graph_2_0_10->SetMarkerStyle(20);
    graph_2_0_10->SetMarkerSize(1.5);
    graph_2_0_10->SetMarkerColor(kBlue);
    graph_2_0_10->SetLineColor(kBlue);
    graph_2_0_10->GetXaxis()->SetLimits(x_min4, x_max4);
    graph_2_0_10->GetYaxis()->SetLimits(0.5, 3.5);  // Adjust limits to fit labels properly
    graph_2_0_10->GetYaxis()->SetNdivisions(3);
    graph_2_0_10->GetYaxis()->SetLabelSize(0);
    graph_2_0_10->Draw("APLE");

    TLatex latex2_0_10;
    latex2_0_10.SetTextSize(0.04);
    latex2_0_10.SetTextAlign(32);  // Right-align
    latex2_0_10.DrawLatex(x_min4 - 0.0025, 1, "#Lambda^{0}#bar{#Lambda}^{0}");
    latex2_0_10.DrawLatex(x_min4 - 0.0025, 2, "#Lambda^{0}#Lambda^{0}");
    latex2_0_10.DrawLatex(x_min4 - 0.0025, 3, "#bar{#Lambda}^{0}#bar{#Lambda}^{0}");

    TLine *line2_0_10 = new TLine(0, 0.9, 0, 3.1);
    line2_0_10->SetLineColor(kRed);
    line2_0_10->SetLineStyle(2);   
    line2_0_10->SetLineWidth(2);   
    line2_0_10->Draw();

    TCanvas *c17 = new TCanvas("c17", "c17- #Lambda Polarization (10-40% Centrality)", 1800, 900);
    c17->Divide(2,2);

    double x_min5 = -0.3;
    double x_max5 = 0.1;

    double x_min6 = -0.1;
    double x_max6 = 0.1;

    c17->cd(1);
    double xValues_10_40[3] = {P_corrected_llbar_10_40, P_corrected_ll_10_40, P_corrected_lbarlbar_10_40}; 
    double yValues_10_40[3] = {1, 2, 3};

    double xErrors_10_40[3] = {P_corrected_llbar_error_10_40, P_corrected_ll_error_10_40, P_corrected_lbarlbar_error_10_40}; 
    double yErrors_10_40[3] = {0, 0, 0};

    TGraphErrors *graph_10_40 = new TGraphErrors(3, xValues_10_40, yValues_10_40, xErrors_10_40, yErrors_10_40);

    graph_10_40->SetTitle("Polarization inside #DeltaR = 0.93 (10-40% Centrality)");
    graph_10_40->SetMarkerStyle(20);
    graph_10_40->SetMarkerSize(1.5);
    graph_10_40->SetMarkerColor(kBlue);
    graph_10_40->SetLineColor(kBlue);
    graph_10_40->GetXaxis()->SetLimits(x_min5, x_max5);
    graph_10_40->GetYaxis()->SetLimits(0.5, 3.5);  // Adjust limits to fit labels properly
    graph_10_40->GetYaxis()->SetNdivisions(3);
    graph_10_40->GetYaxis()->SetLabelSize(0);
    graph_10_40->Draw("APLE");

    TLatex latex_10_40;
    latex_10_40.SetTextSize(0.04);
    latex_10_40.SetTextAlign(32);  // Right-align
    latex_10_40.DrawLatex(x_min5 - 0.0025, 1, "#Lambda^{0}#bar{#Lambda}^{0}");
    latex_10_40.DrawLatex(x_min5 - 0.0025, 2, "#Lambda^{0}#Lambda^{0}");
    latex_10_40.DrawLatex(x_min5 - 0.0025, 3, "#bar{#Lambda}^{0}#bar{#Lambda}^{0}");

    TLine *line_10_40 = new TLine(0, 0.9, 0, 3.1);
    line_10_40->SetLineColor(kRed);
    line_10_40->SetLineStyle(2);   
    line_10_40->SetLineWidth(2);   
    line_10_40->Draw();

    c17->cd(2);
    double xValues_2_10_40[3] = {P_corrected_outside_llbar_10_40, P_corrected_outside_ll_10_40, P_corrected_outside_lbarlbar_10_40}; 
    double yValues_2_10_40[3] = {1, 2, 3};

    double xErrors_2_10_40[3] = {P_corrected_outside_llbar_error_10_40, P_corrected_outside_ll_error_10_40, P_corrected_outside_lbarlbar_error_10_40}; 
    double yErrors_2_10_40[3] = {0, 0, 0};

    TGraphErrors *graph_2_10_40 = new TGraphErrors(3, xValues_2_10_40, yValues_2_10_40, xErrors_2_10_40, yErrors_2_10_40);

    graph_2_10_40->SetTitle("Polarization outside #DeltaR = 0.93 (10-40% Centrality)");
    graph_2_10_40->SetMarkerStyle(20);
    graph_2_10_40->SetMarkerSize(1.5);
    graph_2_10_40->SetMarkerColor(kBlue);
    graph_2_10_40->SetLineColor(kBlue);
    graph_2_10_40->GetXaxis()->SetLimits(x_min6, x_max6);
    graph_2_10_40->GetYaxis()->SetLimits(0.5, 3.5);  // Adjust limits to fit labels properly
    graph_2_10_40->GetYaxis()->SetNdivisions(3);
    graph_2_10_40->GetYaxis()->SetLabelSize(0);
    graph_2_10_40->Draw("APLE");

    TLatex latex2_10_40;
    latex2_10_40.SetTextSize(0.04);
    latex2_10_40.SetTextAlign(32);  // Right-align
    latex2_10_40.DrawLatex(x_min6 - 0.0025, 1, "#Lambda^{0}#bar{#Lambda}^{0}");
    latex2_10_40.DrawLatex(x_min6 - 0.0025, 2, "#Lambda^{0}#Lambda^{0}");
    latex2_10_40.DrawLatex(x_min6 - 0.0025, 3, "#bar{#Lambda}^{0}#bar{#Lambda}^{0}");

    TLine *line2_10_40 = new TLine(0, 0.9, 0, 3.1);
    line2_10_40->SetLineColor(kRed);
    line2_10_40->SetLineStyle(2);   
    line2_10_40->SetLineWidth(2);   
    line2_10_40->Draw();

    TCanvas *c18 = new TCanvas("c18", "c18- #Lambda Polarization (40-80% Centrality)", 1800, 900);
    c18->Divide(2,2);

    double x_min7 = -0.4;
    double x_max7 = 0.2;

    double x_min8 = -0.21;
    double x_max8 = 0.2;

    c18->cd(1);
    double xValues_40_80[3] = {P_corrected_llbar_40_80, P_corrected_ll_40_80, P_corrected_lbarlbar_40_80}; 
    double yValues_40_80[3] = {1, 2, 3};

    double xErrors_40_80[3] = {P_corrected_llbar_error_40_80, P_corrected_ll_error_40_80, P_corrected_lbarlbar_error_40_80}; 
    double yErrors_40_80[3] = {0, 0, 0};

    TGraphErrors *graph_40_80 = new TGraphErrors(3, xValues_40_80, yValues_40_80, xErrors_40_80, yErrors_40_80);

    graph_40_80->SetTitle("Polarization inside #DeltaR = 0.93 (40-80% Centrality)");
    graph_40_80->SetMarkerStyle(20);
    graph_40_80->SetMarkerSize(1.5);
    graph_40_80->SetMarkerColor(kBlue);
    graph_40_80->SetLineColor(kBlue);
    graph_40_80->GetXaxis()->SetLimits(x_min7, x_max7);
    graph_40_80->GetYaxis()->SetLimits(0.5, 3.5);  // Adjust limits to fit labels properly
    graph_40_80->GetYaxis()->SetNdivisions(3);
    graph_40_80->GetYaxis()->SetLabelSize(0);
    graph_40_80->Draw("APLE");

    TLatex latex_40_80;
    latex_40_80.SetTextSize(0.04);
    latex_40_80.SetTextAlign(32);  // Right-align
    latex_40_80.DrawLatex(x_min7 - 0.0025, 1, "#Lambda^{0}#bar{#Lambda}^{0}");
    latex_40_80.DrawLatex(x_min7 - 0.0025, 2, "#Lambda^{0}#Lambda^{0}");
    latex_40_80.DrawLatex(x_min7 - 0.0025, 3, "#bar{#Lambda}^{0}#bar{#Lambda}^{0}");

    TLine *line_40_80 = new TLine(0, 0.9, 0, 3.1);
    line_40_80->SetLineColor(kRed);
    line_40_80->SetLineStyle(2);   
    line_40_80->SetLineWidth(2);   
    line_40_80->Draw();

    c18->cd(2);
    double xValues_2_40_80[3] = {P_corrected_outside_llbar_40_80, P_corrected_outside_ll_40_80, P_corrected_outside_lbarlbar_40_80}; 
    double yValues_2_40_80[3] = {1, 2, 3};

    double xErrors_2_40_80[3] = {P_corrected_outside_llbar_error_40_80, P_corrected_outside_ll_error_40_80, P_corrected_outside_lbarlbar_error_40_80}; 
    double yErrors_2_40_80[3] = {0, 0, 0};

    TGraphErrors *graph_2_40_80 = new TGraphErrors(3, xValues_2_40_80, yValues_2_40_80, xErrors_2_40_80, yErrors_2_40_80);

    graph_2_40_80->SetTitle("Polarization outside #DeltaR = 0.93 (40-80% Centrality)");
    graph_2_40_80->SetMarkerStyle(20);
    graph_2_40_80->SetMarkerSize(1.5);
    graph_2_40_80->SetMarkerColor(kBlue);
    graph_2_40_80->SetLineColor(kBlue);
    graph_2_40_80->GetXaxis()->SetLimits(x_min8, x_max8);
    graph_2_40_80->GetYaxis()->SetLimits(0.5, 3.5);  // Adjust limits to fit labels properly
    graph_2_40_80->GetYaxis()->SetNdivisions(3);
    graph_2_40_80->GetYaxis()->SetLabelSize(0);
    graph_2_40_80->Draw("APLE");

    TLatex latex2_40_80;
    latex2_40_80.SetTextSize(0.04);
    latex2_40_80.SetTextAlign(32);  // Right-align
    latex2_40_80.DrawLatex(x_min8 - 0.0025, 1, "#Lambda^{0}#bar{#Lambda}^{0}");
    latex2_40_80.DrawLatex(x_min8 - 0.0025, 2, "#Lambda^{0}#Lambda^{0}");
    latex2_40_80.DrawLatex(x_min8 - 0.0025, 3, "#bar{#Lambda}^{0}#bar{#Lambda}^{0}");

    TLine *line2_40_80 = new TLine(0, 0.9, 0, 3.1);
    line2_40_80->SetLineColor(kRed);
    line2_40_80->SetLineStyle(2);   
    line2_40_80->SetLineWidth(2);   
    line2_40_80->Draw();

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
    c11->Update();
    c12->Update();
    c13->Update();
    c14->Update();
    c15->Update();
    c16->Update();
    c17->Update();
    c18->Update();

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
    c11->WaitPrimitive();
    c12->WaitPrimitive();
    c13->WaitPrimitive();
    c14->WaitPrimitive();
    c15->WaitPrimitive();
    c16->WaitPrimitive();
    c17->WaitPrimitive();
    c18->WaitPrimitive();
}