#pragma once
#include <AgentTools.h>

#include <IFace\Project.h>

class CPyRoadway
{
public:
   void Init(std::weak_ptr<WBFL::EAF::Broker> pBroker);
   void Reset();

   void SetAlignmentData(const AlignmentData2& data);
   AlignmentData2 GetAlignmentData() const;

   void SetProfileData(const ProfileData2& data);
   ProfileData2 GetProfileData() const;

   void SetRoadwaySectionData(const RoadwaySectionData& data);
   RoadwaySectionData GetRoadwaySectionData() const;

private:
   std::weak_ptr<IRoadwayData> m_pAlignment;
}; 
