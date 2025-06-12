#pragma once
#include <AgentTools.h>

#include <IFace\MomentCapacity.h>

class CPyMomentCapacity
{
public:
   void Init(std::weak_ptr<WBFL::EAF::Broker> pBroker);
   void Reset();

   const MINMOMENTCAPDETAILS& GetMinMomentCapacityDetails(IntervalIndexType intervalIdx, const pgsPointOfInterest& poi, bool bPositiveMoment);

private:
   std::weak_ptr<IMomentCapacity> m_pMomentCapacity;
}; 
