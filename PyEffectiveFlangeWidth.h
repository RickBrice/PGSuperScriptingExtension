#pragma once
#include <AgentTools.h>

#include <IFace\Project.h>

class CPyEffectiveFlangeWidth
{
public:
   void Init(std::weak_ptr<WBFL::EAF::Broker> pBroker);
   void Reset();

   bool GetIgnoreEffectiveFlangeWidthLimits() const;
   void SetIgnoreEffectiveFlangeWidthLimits(bool bIgnore);

private:
   std::weak_ptr<IEffectiveFlangeWidth> m_pEffectiveFlangeWidth;
}; 
