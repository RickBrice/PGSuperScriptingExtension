#pragma once
#include <AgentTools.h>

#include <IFace\PointOfInterest.h>

class CPyPointOfInterest
{
public:
   void Init(std::weak_ptr<WBFL::EAF::Broker> pBroker);
   void Reset();

   std::vector<pgsPointOfInterest> GetPointsOfInterest(const CSegmentKey& segmentKey) const;
   std::vector<pgsPointOfInterest> GetSpanPointsOfInterest(const CSpanKey& spanKey) const;

private:
   std::weak_ptr<IPointOfInterest> m_pPoi;
}; 
