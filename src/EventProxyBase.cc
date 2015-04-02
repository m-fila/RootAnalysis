#include "EventProxyBase.h"

//
EventProxyBase::EventProxyBase():
  fileNames_(), treeName_(""), eventIndex_(0), accumulatedSize_(0){

	std::cout<<__func__<<std::endl;

}

void EventProxyBase::init(std::vector<std::string> const& iFileNames){

  fChain = boost::shared_ptr<TChain>(new TChain(treeName_.c_str()));

  for (auto it= iFileNames.begin(), itEnd = iFileNames.end();it!=itEnd; ++it) {
	  fChain->Add(it->c_str(),-1);
  }

  //fChain->Print();
  accumulatedSize_ = fChain->GetEntries();
  Int_t cachesize = 10000000; //10 MBytes
  fChain->SetCacheSize(cachesize);
  fChain->AddBranchToCache("*",kTRUE);
  //fChain->SetParallelUnzip(kTRUE);

  fChain->SetBranchStatus("*",0);

}

EventProxyBase::~EventProxyBase(){}

//
// member functions
//

EventProxyBase const&
EventProxyBase::operator++(){

	fChain->GetEntry(eventIndex_++);

   return *this;
}

void EventProxyBase::skip(int n) 
{
  eventIndex_+= n;
  fChain->GetEntry(eventIndex_);
}

/** Go to the very first Event*/

EventProxyBase const&
EventProxyBase::toBegin()
{

	fChain->GetEntry(0);
	eventIndex_ = 0;
    return *this;
}


bool
EventProxyBase::atEnd() const{

  return eventIndex_>=accumulatedSize_;
}
