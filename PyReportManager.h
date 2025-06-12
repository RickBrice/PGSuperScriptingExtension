#pragma once
#include <AgentTools.h>

#include <EAF/EAFReportManager.h>

class CPyReportManager
{
public:
   void Init(std::weak_ptr<WBFL::EAF::Broker> pBroker);
   void Reset();

   IndexType GetReportBuilderCount();
   boost::python::list GetReportNames();

private:
   std::weak_ptr<IEAFReportManager> m_pReportManager;
};