#pragma once
#include <AgentTools.h>

#include <IFace\Project.h>

class CPyLimits
{
public:
   void Init(std::weak_ptr<WBFL::EAF::Broker> pBroker);
   void Reset();

   Float64 GetMaxSlabFc(pgsTypes::ConcreteType concType) const;
   Float64 GetMaxSegmentFci(pgsTypes::ConcreteType concType) const;
   Float64 GetMaxSegmentFc(pgsTypes::ConcreteType concType) const;
   Float64 GetMaxClosureFci(pgsTypes::ConcreteType concType) const;
   Float64 GetMaxClosureFc(pgsTypes::ConcreteType concType) const;
   Float64 GetMaxConcreteUnitWeight(pgsTypes::ConcreteType concType) const;
   Float64 GetMaxConcreteAggSize(pgsTypes::ConcreteType concType) const;

private:
   std::weak_ptr<ILimits> m_pLimits;
}; 
