#include "stdafx.h"
#include "PyViews.h"

#include "PyStabilityGraphViewController.h"
#include "PyEffectivePrestressGraphViewController.h"
#include "PyConcretePropertiesGraphViewController.h"
#include "PyDeflectionHistoryGraphViewController.h"
#include "PyStressHistoryGraphViewController.h"
#include "PyAnalysisResultsGraphViewController.h"
#include "PySegmentAnalysisResultsGraphViewController.h"
#include "PyGirderPropertiesGraphViewController.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////

void CPyViews::Init(std::weak_ptr<WBFL::EAF::Broker> pBroker)
{
   m_pBroker = pBroker;
   m_pViews = GetBroker()->GetInterface<IViews>(IID_IViews); // can't use GET_IFACE because it will create a local variable that goes out of scope
}

void CPyViews::Reset()
{
}

CPyBridgeModelView CPyViews::CreateBridgeModelView()
{
   CComPtr<IBridgeModelViewController> controller;
   m_pViews.lock()->CreateBridgeModelView(&controller);

   GET_IFACE2(GetBroker(),ISelection, pSelection);
   CPyBridgeModelView view;
   view.Init(controller, pSelection);
   return view;
}

CPyGirderModelView CPyViews::CreateGirderView()
{
   CComPtr<IGirderModelViewController> controller;
   m_pViews.lock()->CreateGirderView(CGirderKey(ALL_GROUPS, 0), &controller);

   CPyGirderModelView view;
   view.Init(controller);
   return view;
}

CPyLoadsView CPyViews::CreateLoadsView()
{
   CComPtr<ILoadsViewController> controller;
   m_pViews.lock()->CreateLoadsView(&controller);

   CPyLoadsView view;
   view.Init(controller);
   return view;
}

void CPyViews::CreateLibraryEditorView()
{
   m_pViews.lock()->CreateLibraryEditorView();
}

void CPyViews::CreateGraphView(IndexType idx)
{
   m_pViews.lock()->CreateGraphView(idx);
}

CPyViewControllerBase* CPyViews::CreateGraphViewByName(LPCSTR strName)
{
   USES_CONVERSION;
   CComPtr<IEAFViewController> controller;
   m_pViews.lock()->CreateGraphView(A2T(strName), &controller);

   return CreateGraphContollerWrapper(controller);
}

void CPyViews::CreateReport(IndexType idx,bool bPrompt)
{
   m_pViews.lock()->CreateReportView(idx, bPrompt);
}

CPyViewControllerBase* CPyViews::CreateGraphContollerWrapper(IEAFViewController* pController) const
{
   CComQIPtr<IStabilityGraphViewController> stabilityGraphController(pController);
   CComQIPtr<IEffectivePrestressGraphViewController> effectivePrestressGraphController(pController);
   CComQIPtr<IConcretePropertiesGraphViewController> concretePropertiesController(pController);
   CComQIPtr<IDeflectionHistoryGraphViewController> deflectionHistoryController(pController);
   CComQIPtr<IStressHistoryGraphViewController> stressHistoryController(pController);
   CComQIPtr<IAnalysisResultsGraphViewController> analysisResultsController(pController);
   CComQIPtr<ISegmentAnalysisResultsGraphViewController> segmentAnalysisResultsController(pController);
   CComQIPtr<IGirderPropertiesGraphViewController> girderPropertiesController(pController);

   if (stabilityGraphController)
   {
      auto controller = std::make_unique<CPyStabilityGraphViewController>();
      controller->Init(stabilityGraphController);
      return controller.release();
   }
   else if (effectivePrestressGraphController)
   {
      auto controller = std::make_unique<CPyEffectivePrestressGraphViewController>();
      controller->Init(effectivePrestressGraphController);
      return controller.release();
   }
   else if (concretePropertiesController)
   {
      auto controller = std::make_unique<CPyConcretePropertiesGraphViewController>();
      controller->Init(concretePropertiesController);
      return controller.release();
   }
   else if (deflectionHistoryController)
   {
      auto controller = std::make_unique<CPyDeflectionHistoryGraphViewController>();
      controller->Init(deflectionHistoryController);
      return controller.release();
   }
   else if (stressHistoryController)
   {
      auto controller = std::make_unique<CPyStressHistoryGraphViewController>();
      controller->Init(stressHistoryController);
      return controller.release();
   }
   else if (analysisResultsController)
   {
      auto controller = std::make_unique<CPyAnalysisResultsGraphViewController>();
      controller->Init(analysisResultsController);
      return controller.release();
   }
   else if (segmentAnalysisResultsController)
   {
      auto controller = std::make_unique<CPySegmentAnalysisResultsGraphViewController>();
      controller->Init(segmentAnalysisResultsController);
      return controller.release();
   }
   else if (girderPropertiesController)
   {
      auto controller = std::make_unique<CPyGirderPropertiesGraphViewController>();
      controller->Init(girderPropertiesController);
      return controller.release();
   }
   else
   {
      ATLASSERT(false); // should never get here... is there a new type of graph controller?
      PyErr_SetString(PyExc_NameError, "Graph controller not available");
      PyErr_Print();
      return nullptr;
   }
}