#include "stdafx.h"
#include "PyRoadway.h"

void CPyRoadway::Init(std::weak_ptr<WBFL::EAF::Broker> pBroker)
{
   auto broker = pBroker.lock();
   m_pAlignment = broker->GetInterface<IRoadwayData>(IID_IRoadwayData);
}

void CPyRoadway::Reset()
{
}

void CPyRoadway::SetAlignmentData(const AlignmentData2& data)
{
   m_pAlignment.lock()->SetAlignmentData2(data);
}

AlignmentData2 CPyRoadway::GetAlignmentData() const
{
   return m_pAlignment.lock()->GetAlignmentData2();
}

void CPyRoadway::SetProfileData(const ProfileData2& data)
{
   m_pAlignment.lock()->SetProfileData2(data);
}

ProfileData2 CPyRoadway::GetProfileData() const
{
   return m_pAlignment.lock()->GetProfileData2();
}

void CPyRoadway::SetRoadwaySectionData(const RoadwaySectionData& data)
{
   m_pAlignment.lock()->SetRoadwaySectionData(data);
}

RoadwaySectionData CPyRoadway::GetRoadwaySectionData() const
{
   return m_pAlignment.lock()->GetRoadwaySectionData();
}

