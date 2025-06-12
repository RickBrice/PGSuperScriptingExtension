#include "stdafx.h"
#include "PyEnvironment.h"

void CPyEnvironment::Init(std::weak_ptr<WBFL::EAF::Broker> pBroker)
{
   auto broker = pBroker.lock();
   m_pEnvironment = broker->GetInterface<IEnvironment>(IID_IEnvironment);
}

void CPyEnvironment::Reset()
{
}

pgsTypes::ExposureCondition CPyEnvironment::GetExposureCondition() const
{
   return m_pEnvironment.lock()->GetExposureCondition();
}

void CPyEnvironment::SetExposureCondition(pgsTypes::ExposureCondition newVal)
{
   m_pEnvironment.lock()->SetExposureCondition(newVal);
}

Float64 CPyEnvironment::GetRelHumidity() const
{
   return m_pEnvironment.lock()->GetRelHumidity();
}

void CPyEnvironment::SetRelHumidity(Float64 newVal)
{
   m_pEnvironment.lock()->SetRelHumidity(newVal);
}
