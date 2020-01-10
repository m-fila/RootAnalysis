#include "EventProxyELI.h"

#include "TSystem.h"

#include <iostream>

EventProxyELI::EventProxyELI(){}
/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////
EventProxyELI::~EventProxyELI(){}
/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////
EventProxyBase* EventProxyELI::clone() const{

  return new EventProxyELI();

}
//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
void EventProxyELI::init(std::vector<std::string> const& iFileNames){

  treeName_ = "HTauTauTree";

  EventProxyBase::init(iFileNames);
  //fChain->SetMakeClass(0);

  event = 0;
  pairs = 0;
  jets = 0;
  genLeptons = 0;

  fChain->SetBranchAddress("ELIEvent.",&event);
  fChain->SetBranchAddress("ELIPairCollection",&pairs);
  fChain->SetBranchAddress("ELIJetCollection",&jets);
  fChain->SetBranchAddress("ELIGenLeptonCollection",&genLeptons);

  fChain->SetBranchStatus("*",0);
  fChain->SetBranchStatus("ELIEvent*",1);
  fChain->SetBranchStatus("ELIPairCollection*",1);
  fChain->SetBranchStatus("ELIJetCollection*",1);
  fChain->SetBranchStatus("ELIGenLeptonCollection*",1);
  //fChain->SetBranchStatus("ELILeptonCollection*",1);


}
/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////
void  EventProxyELI::enableBranches(){

  fChain->SetBranchStatus("*",1);

}
/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////
void  EventProxyELI::disableBranches(){

  fChain->SetBranchStatus("*",0);

}
/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////
void  EventProxyELI::clear(){

  if(event) event->clear();
  if(pairs) pairs->clear();
  if(jets) jets->clear();
  if(genLeptons) genLeptons->clear();

}
/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////
