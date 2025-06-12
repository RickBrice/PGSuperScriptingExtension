#pragma once
#include <AgentTools.h>

#include <IFace\Project.h>

class CPyEnvironment
{
public:
   void Init(std::weak_ptr<WBFL::EAF::Broker> pBroker);
   void Reset();

   pgsTypes::ExposureCondition GetExposureCondition() const;
   void SetExposureCondition(pgsTypes::ExposureCondition newVal);
   Float64 GetRelHumidity() const;
   void SetRelHumidity(Float64 newVal);

private:
   std::weak_ptr<IEnvironment> m_pEnvironment;
}; 
