#include "stdafx.h"
#include "PyGraphManager.h"

void CPyGraphManager::Init(std::weak_ptr<WBFL::EAF::Broker> pBroker)
{
   auto broker = pBroker.lock();
   m_pGraphManager = broker->GetInterface<IEAFGraphManager>(IID_IEAFGraphManager);
}

void CPyGraphManager::Reset()
{
}

IndexType CPyGraphManager::GetGraphBuilderCount()
{
   return m_pGraphManager.lock()->GetGraphBuilderCount();
}

boost::python::list CPyGraphManager::GetGraphNames()
{
   USES_CONVERSION;
   boost::python::list list;
   std::vector<std::_tstring> vNames = m_pGraphManager.lock()->GetGraphNames();
   for (const auto& name : vNames)
   {
#if defined _UNICODE
      boost::python::handle<> handle(PyUnicode_FromWideChar(name.c_str(),-1));
#else
      boost::python::handle<> handle(PyUnicode_FromString(T2A(name.c_str())));
#endif
      list.append(boost::python::object(handle));
   }

   return list;
}
