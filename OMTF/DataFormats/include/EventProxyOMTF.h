#ifndef EVENTPROXYOMTF_h
#define EVENTPROXYOMTF_h

#include <string>
#include <typeinfo>
#include <vector>
#include "boost/shared_ptr.hpp"

#include "EventProxyBase.h"
#include "EventObj.h"
#include "GenObjColl.h"
#include "L1ObjColl.h"

#include "TBranch.h"


   class EventProxyOMTF: public EventProxyBase{

   public:

      EventProxyOMTF();
      virtual ~EventProxyOMTF();

      void init(std::vector<std::string> const& iFileNames);

      virtual EventProxyBase* clone() const;

     const EventObj  *getEventId() const {return myEvent;};

     const GenObjColl *getGenObjColl() const {return myGenObjColl;};

     const L1ObjColl  *getL1ObjColl() const { return myL1ObjColl;};

   private:
     
      // Declaration of leaf types
      EventObj       *myEvent;
      GenObjColl     *myGenObjColl;
      L1ObjColl      *myL1ObjColl;

};
#endif
