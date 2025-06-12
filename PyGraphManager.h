#pragma once

#include <EAF/EAFGraphManager.h>
#include <AgentTools.h>
class CPyGraphManager
{
public:
   void Init(std::weak_ptr<WBFL::EAF::Broker> pBroker);
   void Reset();

   IndexType GetGraphBuilderCount();
   boost::python::list GetGraphNames();

private:
   std::weak_ptr<IEAFGraphManager> m_pGraphManager;
};