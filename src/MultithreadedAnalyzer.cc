#include"MultithreadedAnalyzer.h"


  void  MultithreadedAnalyzer::initialize(TFileDirectory& aDir, pat::strbitset* aSelections){
	TH2F * hist = new TH2F(), *another_hist = (TH2F*)hist->Clone();
	delete hist;
	delete another_hist;
	
       finalHistos = new OTFHistograms(&aDir,selectionFlavours_);
       int size = AnalysisHistograms::container.size();
       for(int i = 0; i < threads;++i)
	 analyzers[i]->initialize(aDir, aSelections);
       int size1 = AnalysisHistograms::container.size();
       copy(AnalysisHistograms::container.begin() + size,AnalysisHistograms::container.begin() +size1,
		 back_inserter(histograms));
 }
  bool MultithreadedAnalyzer::analyze(const EventProxyBase& iEvent){
      int thread = omp_get_thread_num();
      analyzers[thread]->analyze(iEvent);
 }
 void MultithreadedAnalyzer::piece2DHistogramsTogether(){
     vector<map<string,TH2F*>*> maps;
     for(int i =0; i < threads;++i){
       maps.push_back( histograms[i]->getMy2DHistogramsAdress());
     }
     finalHistos->pieceHistogramsTogether2D(maps);
     
   }
  void MultithreadedAnalyzer::piece1DHistogramsTogether(){
     vector<map<string,TH1F*>*> maps;
     for(int i =0; i < threads;++i){
       maps.push_back( histograms[i]->getMy1DHistogramsAdress());
     }
     finalHistos->pieceHistogramsTogether1D(maps);
     
   }
     void MultithreadedAnalyzer::piece3DHistogramsTogether(){
     vector<map<string,TH3F*>*> maps;
     for(int i =0; i < threads;++i){
       maps.push_back( histograms[i]->getMy3DHistogramsAdress());
     }
     finalHistos->pieceHistogramsTogether3D(maps);
     
   }
 void MultithreadedAnalyzer::finalize(){
      piece1DHistogramsTogether();
      piece2DHistogramsTogether();
      piece3DHistogramsTogether();
      finalHistos->finalizeHistograms(); 
      
    }
void MultithreadedAnalyzer::addBranch(TTree* tree){
}
void MultithreadedAnalyzer::clear(){
}
MultithreadedAnalyzer::~MultithreadedAnalyzer(){
}
void MultithreadedAnalyzer::addCutHistos(TList* aList){
}
MultithreadedAnalyzer::MultithreadedAnalyzer(const string& aName, int threadnum) : Analyzer(aName){
     threads = threadnum;
      for(int i = 0; i < threads;++i) analyzers.push_back(new OTFAnalyzer(aName));
};