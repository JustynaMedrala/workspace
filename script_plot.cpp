void script_plot()
{
   TFile *f = TFile::Open("mc.cat.evt.root");
   if (!f) {
      std::cout << "cannot open file" << std::endl;
      return -1;
   }
   TDirectoryFile *mydirectory = f->Get<TDirectoryFile>("EventCategorizer subtask 0 stats");
   TH1D *hist_All_energy, *hist_All_time;
   TH1D *hist_2Gamma_energy, *hist_2Gamma_time;
   TH1D *hist_3Gamma_energy, *hist_3Gamma_time;
   TH1D *hist_Prompt_energy, *hist_Prompt_time;
   TH1D *hist_Scattered_energy, *hist_Scattered_time;
   TH2D *hist_ScatterAngle_PrimaryTOT, *hist_ScatterAngle_PrimaryTOT_before_cut;
   TH2D *hist_ScatterAngle_ScatterTOT, *hist_ScatterAngle_ScatterTOT_before_cut;

   mydirectory->GetObject("All_energy", hist_All_energy);
   mydirectory->GetObject("All_time", hist_All_time);
   mydirectory->GetObject("2Gamma_energy", hist_2Gamma_energy);
   mydirectory->GetObject("2Gamma_time", hist_2Gamma_time);
   mydirectory->GetObject("3Gamma_energy", hist_3Gamma_energy);
   mydirectory->GetObject("3Gamma_time", hist_3Gamma_time);
   mydirectory->GetObject("Prompt_energy", hist_Prompt_energy);
   mydirectory->GetObject("Prompt_time", hist_Prompt_time);
   mydirectory->GetObject("Scattered_energy", hist_Scattered_energy);
   mydirectory->GetObject("Scattered_time", hist_Scattered_time);
   mydirectory->GetObject("ScatterAngle_PrimaryTOT", hist_ScatterAngle_PrimaryTOT);
   mydirectory->GetObject("ScatterAngle_ScatterTOT", hist_ScatterAngle_ScatterTOT);
   mydirectory->GetObject("ScatterAngle_PrimaryTOT_before_cut", hist_ScatterAngle_PrimaryTOT_before_cut);
   mydirectory->GetObject("ScatterAngle_ScatterTOT_before_cut", hist_ScatterAngle_ScatterTOT_before_cut);


   if (!hist_ScatterAngle_PrimaryTOT && !hist_ScatterAngle_ScatterTOT) {
      std::cout << " doesn't contain histogram" << std::endl;
      return -2;
   }
   TCanvas c;
   hist_All_energy->Draw();
   c.SaveAs("All_energy.png");
   hist_All_time->Draw();
   c.SaveAs("All_time.png");
   hist_2Gamma_energy->Draw();
   c.SaveAs("2Gamma_energy.png");
   hist_2Gamma_time->Draw();
   c.SaveAs("2Gamma_time.png");
   hist_3Gamma_energy->Draw();
   c.SaveAs("3Gamma_energy.png");
   hist_3Gamma_time->Draw();
   c.SaveAs("3Gamma_time.png");
   hist_Prompt_energy->Draw();
   c.SaveAs("Prompt_energy.png");
   hist_Prompt_time->Draw();
   c.SaveAs("Prompt_time.png");
   hist_Scattered_energy->Draw();
   c.SaveAs("Scattered_energy.png");
   hist_Scattered_time->Draw();
   c.SaveAs("Scattered_time.png");
   hist_ScatterAngle_PrimaryTOT->Draw();
   c.SaveAs("Primary.png");   
   //hist_ScatterAngle_PrimaryTOT_before_cut->Draw();
   //c.SaveAs("Primary_before_cut.png");
   hist_ScatterAngle_ScatterTOT->Draw();
   c.SaveAs("Scatter.png");
   //hist_ScatterAngle_ScatterTOT_before_cut->Draw();
   //c.SaveAs("Scatter_before_cut.png");
}

