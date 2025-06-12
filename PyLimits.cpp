#include "stdafx.h"
#include "PyLimits.h"

void CPyLimits::Init(std::weak_ptr<WBFL::EAF::Broker> pBroker)
{
   auto broker = pBroker.lock();
   m_pLimits = broker->GetInterface<ILimits>(IID_ILimits);
}

void CPyLimits::Reset()
{
}

Float64 CPyLimits::GetMaxSlabFc(pgsTypes::ConcreteType concType) const
{
   return m_pLimits.lock()->GetMaxSlabFc(concType);
}

Float64 CPyLimits::GetMaxSegmentFci(pgsTypes::ConcreteType concType) const
{
   return m_pLimits.lock()->GetMaxSegmentFci(concType);
}

Float64 CPyLimits::GetMaxSegmentFc(pgsTypes::ConcreteType concType) const
{
   return m_pLimits.lock()->GetMaxSegmentFc(concType);
}

Float64 CPyLimits::GetMaxClosureFci(pgsTypes::ConcreteType concType) const
{
   return m_pLimits.lock()->GetMaxClosureFci(concType);
}

Float64 CPyLimits::GetMaxClosureFc(pgsTypes::ConcreteType concType) const
{
   return m_pLimits.lock()->GetMaxClosureFc(concType);
}

Float64 CPyLimits::GetMaxConcreteUnitWeight(pgsTypes::ConcreteType concType) const
{
   return m_pLimits.lock()->GetMaxConcreteUnitWeight(concType);
}

Float64 CPyLimits::GetMaxConcreteAggSize(pgsTypes::ConcreteType concType) const
{
   return m_pLimits.lock()->GetMaxConcreteAggSize(concType);
}
