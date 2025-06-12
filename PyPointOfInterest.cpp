#include "stdafx.h"
#include "PyPointOfInterest.h"

void CPyPointOfInterest::Init(std::weak_ptr<WBFL::EAF::Broker> pBroker)
{
   auto broker = pBroker.lock();
   m_pPoi = broker->GetInterface<IPointOfInterest>(IID_IPointOfInterest);
}

void CPyPointOfInterest::Reset()
{
}

std::vector<pgsPointOfInterest> CPyPointOfInterest::GetPointsOfInterest(const CSegmentKey& segmentKey) const
{
   PoiList poiList;
   m_pPoi.lock()->GetPointsOfInterest(segmentKey, &poiList);
   std::vector<pgsPointOfInterest> vPoi;
   MakePoiVector(poiList, &vPoi);
   return vPoi;
}

std::vector<pgsPointOfInterest> CPyPointOfInterest::GetSpanPointsOfInterest(const CSpanKey& spanKey) const
{
   PoiList poiList;
   m_pPoi.lock()->GetPointsOfInterest(spanKey, &poiList);
   std::vector<pgsPointOfInterest> vPoi;
   MakePoiVector(poiList, &vPoi);
   return vPoi;
}
