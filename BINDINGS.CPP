#include "stdafx.h"
#include "bindings.h"

void CPyPGSuper::Init(std::weak_ptr<WBFL::EAF::Broker> pBroker)
{
   auto broker = pBroker.lock();
   m_pVersionInfo = broker->GetInterface<IVersionInfo>(IID_IVersionInfo);

   m_Properties.Init(pBroker);
   m_Environment.Init(pBroker);
   m_Roadway.Init(pBroker);

   m_Views.Init(pBroker);
   m_GraphManager.Init(pBroker);
   m_ReportManager.Init(pBroker);

   m_LoadModifiers.Init(pBroker);

   m_Bridge.Init(pBroker);
   m_PointOfInterest.Init(pBroker);

   m_Limits.Init(pBroker);

   m_EffectiveFlangeWidth.Init(pBroker);

   m_LossParameters.Init(pBroker);

   m_MomentCapacity.Init(pBroker);
}

void CPyPGSuper::Reset()
{
   m_Properties.Reset();
   m_Environment.Reset();
   m_Roadway.Reset();
   m_Limits.Reset();

   m_Views.Reset();
   m_GraphManager.Reset();
   m_ReportManager.Reset();

   m_LoadModifiers.Reset();

   m_Bridge.Reset();
   m_PointOfInterest.Reset();

   m_EffectiveFlangeWidth.Reset();

   m_LossParameters.Reset();

   m_MomentCapacity.Reset();
}

std::string CPyPGSuper::GetVersionString() const
{
   USES_CONVERSION;
   return T2A(m_pVersionInfo.lock()->GetVersionString(false));
}

std::string CPyPGSuper::GetVersionStringWithBuildNumber() const
{
   USES_CONVERSION;
   return T2A(m_pVersionInfo.lock()->GetVersionString(true));
}

std::string CPyPGSuper::GetVersion() const
{
   USES_CONVERSION;
   return T2A(m_pVersionInfo.lock()->GetVersion(false));
}

std::string CPyPGSuper::GetVersionWithBuildNumber() const
{
   USES_CONVERSION;
   return T2A(m_pVersionInfo.lock()->GetVersion(true));
}

CPyProjectProperties CPyPGSuper::Properties()
{
   return m_Properties;
}

CPyEnvironment CPyPGSuper::Environment()
{
   return m_Environment;
}

CPyRoadway CPyPGSuper::Roadway()
{
   return m_Roadway;
}

CPyViews CPyPGSuper::Views()
{
   return m_Views;
}

CPyGraphManager CPyPGSuper::Graphs()
{
   return m_GraphManager;
}

CPyReportManager CPyPGSuper::Reports()
{
   return m_ReportManager;
}

CPyLoadModifiers CPyPGSuper::LoadModifiers()
{
   return m_LoadModifiers;
}

CPyBridge CPyPGSuper::Bridge()
{
   return m_Bridge;
}

CPyPointOfInterest CPyPGSuper::PointOfInterest()
{
   return m_PointOfInterest;
}

CPyLimits CPyPGSuper::Limits()
{
   return m_Limits;
}

CPyEffectiveFlangeWidth CPyPGSuper::EffectiveFlangeWidth()
{
   return m_EffectiveFlangeWidth;
}

CPyLossParameters CPyPGSuper::LossParameters()
{
   return m_LossParameters;
}

CPyMomentCapacity CPyPGSuper::MomentCapacity()
{
   return m_MomentCapacity;
}
