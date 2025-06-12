#include "stdafx.h"
#include "PyProjectProperties.h"

void CPyProjectProperties::Init(std::weak_ptr<WBFL::EAF::Broker> pBroker)
{
   auto broker = pBroker.lock();
   m_pProjectProperties = broker->GetInterface<IProjectProperties>(IID_IProjectProperties);
}

void CPyProjectProperties::Reset()
{
}

std::string CPyProjectProperties::GetBridgeName() const
{
   USES_CONVERSION;
   return T2A(m_pProjectProperties.lock()->GetBridgeName());
}

void CPyProjectProperties::SetBridgeName(LPCSTR strName)
{
   USES_CONVERSION;
   m_pProjectProperties.lock()->SetBridgeName(A2T(strName));
}

std::string CPyProjectProperties::GetBridgeID() const
{
   USES_CONVERSION;
   return T2A(m_pProjectProperties.lock()->GetBridgeID());
}

void CPyProjectProperties::SetBridgeID(LPCSTR strID)
{
   USES_CONVERSION;
   m_pProjectProperties.lock()->SetBridgeID(A2T(strID));
}

std::string CPyProjectProperties::GetJobNumber() const
{
   USES_CONVERSION;
   return T2A(m_pProjectProperties.lock()->GetJobNumber());
}

void CPyProjectProperties::SetJobNumber(LPCSTR strJobNumber)
{
   USES_CONVERSION;
   m_pProjectProperties.lock()->SetJobNumber(A2T(strJobNumber));
}

std::string CPyProjectProperties::GetEngineer() const
{
   USES_CONVERSION;
   return T2A(m_pProjectProperties.lock()->GetEngineer());
}

void CPyProjectProperties::SetEngineer(LPCSTR strEngineer)
{
   USES_CONVERSION;
   m_pProjectProperties.lock()->SetEngineer(A2T(strEngineer));
}

std::string CPyProjectProperties::GetCompany() const
{
   USES_CONVERSION;
   return T2A(m_pProjectProperties.lock()->GetCompany());
}

void CPyProjectProperties::SetCompany(LPCSTR strCompany)
{
   USES_CONVERSION;
   m_pProjectProperties.lock()->SetCompany(A2T(strCompany));
}

std::string CPyProjectProperties::GetComments() const
{
   USES_CONVERSION;
   return T2A(m_pProjectProperties.lock()->GetComments());
}

void CPyProjectProperties::SetComments(LPCSTR strComments)
{
   USES_CONVERSION;
   m_pProjectProperties.lock()->SetComments(A2T(strComments));
}
