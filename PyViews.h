#pragma once
#include <AgentTools.h>

#include <IFace\Views.h>

#include "PyBridgeModelView.h"
#include "PyGirderModelView.h"
#include "PyLoadsView.h"

class CPyViews
{
public:
   void Init(std::weak_ptr<WBFL::EAF::Broker> pBroker);
   void Reset();

   CPyBridgeModelView CreateBridgeModelView();
   CPyGirderModelView CreateGirderView();
   CPyLoadsView CreateLoadsView();
   void CreateLibraryEditorView();
   void CreateGraphView(IndexType idx);
   CPyViewControllerBase* CreateGraphViewByName(LPCSTR strName);
   void CreateReport(IndexType idx,bool bPrompt);

private:
   std::weak_ptr<WBFL::EAF::Broker> m_pBroker; // weak reference
   inline std::shared_ptr<WBFL::EAF::Broker> GetBroker() { return m_pBroker.lock(); }
   std::weak_ptr<IViews> m_pViews;

   CPyViewControllerBase* CreateGraphContollerWrapper(IEAFViewController* pController) const;
};
