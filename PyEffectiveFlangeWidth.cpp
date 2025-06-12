#include "stdafx.h"
#include "PyEffectiveFlangeWidth.h"

void CPyEffectiveFlangeWidth::Init(std::weak_ptr<WBFL::EAF::Broker> pBroker)
{
   auto broker = pBroker.lock();
   m_pEffectiveFlangeWidth = broker->GetInterface<IEffectiveFlangeWidth>(IID_IEffectiveFlangeWidth);
}

void CPyEffectiveFlangeWidth::Reset()
{
}

bool CPyEffectiveFlangeWidth::GetIgnoreEffectiveFlangeWidthLimits() const
{
   return m_pEffectiveFlangeWidth.lock()->IgnoreEffectiveFlangeWidthLimits();
}

void CPyEffectiveFlangeWidth::SetIgnoreEffectiveFlangeWidthLimits(bool bIgnore)
{
   m_pEffectiveFlangeWidth.lock()->IgnoreEffectiveFlangeWidthLimits(bIgnore);
}
