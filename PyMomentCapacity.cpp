#include "stdafx.h"
#include "PyMomentCapacity.h"

void CPyMomentCapacity::Init(std::weak_ptr<WBFL::EAF::Broker> pBroker)
{
   auto broker = pBroker.lock();
   m_pMomentCapacity = broker->GetInterface<IMomentCapacity>(IID_IMomentCapacity);
}

void CPyMomentCapacity::Reset()
{
}

const MINMOMENTCAPDETAILS& CPyMomentCapacity::GetMinMomentCapacityDetails(IntervalIndexType intervalIdx, const pgsPointOfInterest& poi, bool bPositiveMoment)
{
   return *(m_pMomentCapacity.lock()->GetMinMomentCapacityDetails(intervalIdx, poi, bPositiveMoment));
}
