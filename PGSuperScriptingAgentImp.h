///////////////////////////////////////////////////////////////////////
// ExtensionAgentExample - Extension Agent Example Project for PGSuper
// Copyright © 1999-2017  Washington State Department of Transportation
//                        Bridge and Structures Office
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the Alternate Route Open Source License as 
// published by the Washington State Department of Transportation, 
// Bridge and Structures Office.
//
// This program is distributed in the hope that it will be useful, but 
// distribution is AS IS, WITHOUT ANY WARRANTY; without even the implied 
// warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See 
// the Alternate Route Open Source License for more details.
//
// You should have received a copy of the Alternate Route Open Source 
// License along with this program; if not, write to the Washington 
// State Department of Transportation, Bridge and Structures Office, 
// P.O. Box  47340, Olympia, WA 98503, USA or e-mail 
// Bridge_Support@wsdot.wa.gov
///////////////////////////////////////////////////////////////////////

// ExampleExtensionAgent.h : Declaration of the CExampleExtensionAgent

#pragma once
#include "resource.h"       // main symbols
#include <EAF\EAFUIIntegration.h>
#include <EAF/Agent.h>
#include <EAF/Menu.h>

#include "Scripting.h"
#include "MacroDlg.h"

#include "Console.h"

#include "PyEditorDoc.h"
#include "PyEditorFrame.h"
#include "PyEditorView.h"

#include "PyScriptEngine.h"

class CPGSuperScriptingAgent;
class CScintillaCtrl;

class CMyCmdTarget : public CCmdTarget
{
public:
   CMyCmdTarget() { m_pMyAgent = nullptr; };

   void Init(CPGSuperScriptingAgent* pAgent);
   void Reset();

   afx_msg void OnMacros();
   afx_msg void OnInteractive();
   afx_msg void OnShowConsole();
   afx_msg void OnUpdateShowConsole(CCmdUI *pCmdUI);

   CPGSuperScriptingAgent* m_pMyAgent;

   CMacroDlg m_MacroDlg;

   DECLARE_MESSAGE_MAP()
};


// CExtensionAgent

class CPGSuperScriptingAgent : public WBFL::EAF::Agent,
   public WBFL::EAF::ICommandCallback,
   public WBFL::EAF::IAgentUIIntegration,
   public IEAFProcessCommandLine, // we add some command line options for launching scripts
   public IScripting
{
public:
   CPGSuperScriptingAgent();

   CMyCmdTarget m_MyCommandTarget;

   DWORD m_dwExtendUICookie;

   CBitmap m_bmpMenu;

   std::shared_ptr<WBFL::EAF::Menu> m_pMyMenu;
   void CreateMenus();
   void RemoveMenus();

   UINT m_ToolBarID;
   void CreateToolBar();
   void RemoveToolBar();

   void RegisterViews();
   void UnregisterViews();

   CConsole m_Console;
   CPyScriptEngine ScriptEngine;

   void EditScript(LPCTSTR lpszScriptFile);

// Agent
public:
   std::_tstring GetName() const override { return _T("PGSuperScriptingAgent"); }
   bool RegisterInterfaces() override;
   bool Init() override;
   bool Reset() override;
   bool ShutDown() override;
   CLSID GetCLSID() const override;

// IAgentUIIntegration
public:
   bool IntegrateWithUI(bool bIntegrate) override;

// IEAFCommandCallback
public:
   BOOL OnCommandMessage(UINT nID, int nCode, void* pExtra, AFX_CMDHANDLERINFO* pHandlerInfo) override;
   BOOL GetStatusBarMessageString(UINT nID, CString& rMessage) const override;
   BOOL GetToolTipMessageString(UINT nID, CString& rMessage) const override;

// IEAFProcessCommandLine
public:
   virtual BOOL ProcessCommandLineOptions(CEAFCommandLineInfo& cmdInfo) override;

// IScripting
public:
   virtual LPCTSTR GetScriptFolder() const override;
   virtual std::vector<CString> GetScriptNames() const override;
   virtual std::vector<CString> GetScriptFiles() const override;
   virtual CString GetScriptFile(LPCTSTR lpszScriptName) const override;

private:
   EAF_DECLARE_AGENT_DATA;
   void RegisterUIExtensions();
   void UnregisterUIExtensions();

   // the script editor view is not a view of the PGSuper document
   //long m_SourceEditorViewKey;
   //void CreateScriptEditorView();

   CPyEditorDoc m_ScriptDocument;
   CPyEditorFrame* m_pFrame;
   CPyEditorView* m_pView;
};

//OBJECT_ENTRY_AUTO(CLSID_PGSuperScriptingAgent, CPGSuperScriptingAgent)
