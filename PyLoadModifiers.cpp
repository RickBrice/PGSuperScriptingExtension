#include "stdafx.h"
#include "PyLoadModifiers.h"

void CPyLoadModifiers::Init(std::weak_ptr<WBFL::EAF::Broker> pBroker)
{
   auto broker = pBroker.lock();
   m_pLoadModifiers = broker->GetInterface<ILoadModifiers>(IID_ILoadModifiers);
}

void CPyLoadModifiers::Reset()
{
}

void CPyLoadModifiers::SetDuctilityModifier(ILoadModifiers::Level level, Float64 value)
{
   m_pLoadModifiers.lock()->SetDuctilityFactor(level, value);
}

ILoadModifiers::Level CPyLoadModifiers::GetDuctilityLevel() const
{
   return m_pLoadModifiers.lock()->GetDuctilityLevel();
}

Float64 CPyLoadModifiers::GetDuctilityFactor() const
{
   return m_pLoadModifiers.lock()->GetDuctilityFactor();
}

void CPyLoadModifiers::SetImportanceModifier(ILoadModifiers::Level level, Float64 value)
{
   m_pLoadModifiers.lock()->SetImportanceFactor(level, value);
}

ILoadModifiers::Level CPyLoadModifiers::GetImportanceLevel() const
{
   return m_pLoadModifiers.lock()->GetImportanceLevel();
}

Float64 CPyLoadModifiers::GetImportanceFactor() const
{
   return m_pLoadModifiers.lock()->GetImportanceFactor();
}

void CPyLoadModifiers::SetRedundancyModifier(ILoadModifiers::Level level, Float64 value)
{
   m_pLoadModifiers.lock()->SetRedundancyFactor(level, value);
}

ILoadModifiers::Level CPyLoadModifiers::GetRedundancyLevel() const
{
   return m_pLoadModifiers.lock()->GetRedundancyLevel();
}

Float64 CPyLoadModifiers::GetRedundancyFactor() const
{
   return m_pLoadModifiers.lock()->GetRedundancyFactor();
}
