#include "stdafx.h"
#include "PyReportManager.h"

void CPyReportManager::Init(std::weak_ptr<WBFL::EAF::Broker> pBroker)
{
   auto broker = pBroker.lock();
   m_pReportManager = broker->GetInterface<IEAFReportManager>(IID_IEAFReportManager);
}

void CPyReportManager::Reset()
{
}

IndexType CPyReportManager::GetReportBuilderCount()
{
   return m_pReportManager.lock()->GetReportBuilderCount();
}

boost::python::list CPyReportManager::GetReportNames()
{
   USES_CONVERSION;
   boost::python::list list;
   std::vector<std::_tstring> vNames = m_pReportManager.lock()->GetReportNames();
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