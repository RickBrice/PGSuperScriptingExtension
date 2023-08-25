#pragma once

#include <IFace\Project.h>

class CPyEnvironment
{
public:
   void Init(IBroker* pBroker);
   void Reset();

   pgsTypes::ExposureCondition GetExposureCondition() const;
   void SetExposureCondition(pgsTypes::ExposureCondition newVal);
   Float64 GetRelHumidity() const;
   void SetRelHumidity(Float64 newVal);

private:
   CComPtr<IEnvironment> m_pEnvironment;
}; 
