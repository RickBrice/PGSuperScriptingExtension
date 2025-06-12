#pragma once
#include <AgentTools.h>

#include <IFace\Project.h>

class CPyLoadModifiers
{
public:
   void Init(std::weak_ptr<WBFL::EAF::Broker> pBroker);
   void Reset();

   void SetDuctilityModifier(ILoadModifiers::Level level, Float64 value);
   Float64 GetDuctilityFactor() const;
   ILoadModifiers::Level GetDuctilityLevel() const;

   void SetImportanceModifier(ILoadModifiers::Level level, Float64 value);
   Float64 GetImportanceFactor() const;
   ILoadModifiers::Level GetImportanceLevel() const;

   void SetRedundancyModifier(ILoadModifiers::Level level, Float64 value);
   Float64 GetRedundancyFactor() const;
   ILoadModifiers::Level GetRedundancyLevel() const;

private:
   std::weak_ptr<ILoadModifiers> m_pLoadModifiers;
}; 
