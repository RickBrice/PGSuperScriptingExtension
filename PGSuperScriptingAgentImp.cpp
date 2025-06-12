
#include "stdafx.h"
#include "PGSuperScriptingAgentImp.h"
#include "CLSID.h"

#include "PyEditorFrame.h"
#include "PyEditorView.h"

#include <Python.h>
#include "ScintillaDocView.h"
#include "dllmain.h" // for CExtensionApp

#include "ScriptingCommandLineInfo.h"
#include <EAF\EAFApp.h>

#include "PyScriptEngine.h"

#include "GILManager.h"

BEGIN_MESSAGE_MAP(CMyCmdTarget, CCmdTarget)
   ON_COMMAND(ID_MACROS, OnMacros)
   //ON_COMMAND(ID_INTERACTIVE, OnInteractive)
   ON_COMMAND(IDC_SHOWCONSOLE, OnShowConsole)
   ON_UPDATE_COMMAND_UI(IDC_SHOWCONSOLE, OnUpdateShowConsole)
   //   ON_COMMAND(ID_NEW_SCRIPT, OnNewScript)
//   ON_COMMAND(ID_OPEN_SCRIPT, OnOpenScript)
//   ON_COMMAND(ID_RUN_SCRIPT,OnRunScript)
END_MESSAGE_MAP()

void CMyCmdTarget::Init(CPGSuperScriptingAgent* pAgent)
{
   m_pMyAgent = pAgent;
}

void CMyCmdTarget::Reset()
{
   m_pMyAgent = nullptr;

   if (m_MacroDlg.GetSafeHwnd() != nullptr)
   {
      m_MacroDlg.ShowWindow(SW_HIDE);
   }
}

void CMyCmdTarget::OnMacros()
{
   if (m_MacroDlg.GetSafeHwnd() == nullptr)
   {
      AFX_MANAGE_STATE(AfxGetStaticModuleState());
      m_MacroDlg.Create(IDD_MACROS);
      m_MacroDlg.SetScriptEngine(&m_pMyAgent->ScriptEngine);
   }
   m_MacroDlg.ShowWindow(SW_SHOW);
   m_MacroDlg.SetForegroundWindow();
}

#include <thread>
void InteractivePython()
{
   NppPythonScript::GILLock lock;
   AllocConsole();

   {
      CPyIORedirector ioredirect;

      PyRun_SimpleString("import code");
      PyRun_SimpleString("ic = code.InteractiveConsole()");
      PyRun_SimpleString("ic.interact()");
   }

   FreeConsole();
}
#include "GILManager.h"
void CMyCmdTarget::OnInteractive()
{
   //InteractivePython();
   NppPythonScript::GILRelease release;
   std::thread t(InteractivePython);
   t.join();
}

void CMyCmdTarget::OnShowConsole()
{
   EAFGetMainFrame()->ShowControlBar(&(m_pMyAgent->m_Console),!m_pMyAgent->m_Console.IsVisible(),FALSE);
}

void CMyCmdTarget::OnUpdateShowConsole(CCmdUI *pCmdUI)
{
   if (m_pMyAgent->m_Console.IsVisible())
   {
      pCmdUI->SetText(_T("Hide Console"));
   }
   else
   {
      pCmdUI->SetText(_T("Show Console"));
   }
}

/////////////////////////////////////////////////////////////
// CPGSuperScriptingAgent

CPGSuperScriptingAgent::CPGSuperScriptingAgent()
{
   m_MyCommandTarget.Init(this);

   m_ScriptDocument.m_bAutoDelete = FALSE;
   m_pView = nullptr;
}

void CPGSuperScriptingAgent::RegisterViews()
{
   //GET_IFACE(IEAFViewRegistrar,pViewRegistrar);
   //m_SourceEditorViewKey = pViewRegistrar->RegisterView(IDR_MENU,this,RUNTIME_CLASS(CPyEditorFrame),RUNTIME_CLASS(CPyEditorView));
}

void CPGSuperScriptingAgent::UnregisterViews()
{
   //GET_IFACE(IEAFViewRegistrar,pViewRegistrar);
   //pViewRegistrar->RemoveView(m_SourceEditorViewKey);
}

void CPGSuperScriptingAgent::CreateMenus()
{
   AFX_MANAGE_STATE(AfxGetStaticModuleState());

   GET_IFACE(IEAFMainMenu,pMainMenu);
   auto pMenu = pMainMenu->GetMainMenu();

   INT nMenus = pMenu->GetMenuItemCount();
   if ( nMenus == 0 )
      return;

   m_pMyMenu = pMenu->CreatePopupMenu(nMenus-1,_T("Macros")); // put the menu before the last menu (Help)
   auto callback = std::dynamic_pointer_cast<WBFL::EAF::ICommandCallback>(shared_from_this());
   m_pMyMenu->LoadMenu(IDR_MENU,callback);
}

void CPGSuperScriptingAgent::RemoveMenus()
{
   GET_IFACE(IEAFMainMenu,pMainMenu);
   auto pMenu = pMainMenu->GetMainMenu();
   pMenu->DestroyMenu(m_pMyMenu);
}

void CPGSuperScriptingAgent::CreateToolBar()
{
   AFX_MANAGE_STATE(AfxGetStaticModuleState());
   GET_IFACE(IEAFToolbars,pToolBars);
   m_ToolBarID = pToolBars->CreateToolBar(_T("Scripting"));
   auto pToolBar = pToolBars->GetToolBar(m_ToolBarID);
   auto callback = std::dynamic_pointer_cast<WBFL::EAF::ICommandCallback>(shared_from_this());
   pToolBar->LoadToolBar(IDR_TOOLBAR,callback);

   //GET_IFACE(IEditByUI,pEditUI);
   //UINT stdID = pEditUI->GetStdToolBarID();
   //CEAFToolBar* pStdToolBar = pToolBars->GetToolBar(stdID);
   //UINT cmdID = ID_COMMAND1;
   //pStdToolBar->InsertButton(-1,cmdID,-1,_T("Extension Command"),this);
}

void CPGSuperScriptingAgent::RemoveToolBar()
{
   GET_IFACE(IEAFToolbars,pToolBars);
   pToolBars->DestroyToolBar(m_ToolBarID);

   //GET_IFACE(IEditByUI,pEditUI);
   //UINT stdID = pEditUI->GetStdToolBarID();
   //CEAFToolBar* pStdToolBar = pToolBars->GetToolBar(stdID);
   //pStdToolBar->RemoveButtons(this);
}

/////////////////////////////////////////////////////////////////////////
// IAgentEx

bool CPGSuperScriptingAgent::RegisterInterfaces()
{
   EAF_AGENT_REGISTER_INTERFACES;
   REGISTER_INTERFACE(IScripting);

   return true;
}

bool CPGSuperScriptingAgent::Init()
{
   EAF_AGENT_INIT;

   AFX_MANAGE_STATE(AfxGetStaticModuleState());
   VERIFY(m_bmpMenu.LoadBitmap(IDB_LOGO));

   // this is where the python wrappers need to init the broker and interfaces
   CExtensionApp* pApp = (CExtensionApp*)AfxGetApp();
   pApp->m_pyPGSuper.Init(m_pBroker);

   return true;
}

CLSID CPGSuperScriptingAgent::GetCLSID() const
{
   return CLSID_PGSuperScriptingAgent;
}

bool CPGSuperScriptingAgent::Reset()
{
   EAF_AGENT_RESET;

   AFX_MANAGE_STATE(AfxGetStaticModuleState());
   CExtensionApp* pApp = (CExtensionApp*)AfxGetApp();
   pApp->m_pyPGSuper.Reset();

   m_bmpMenu.DeleteObject();

   m_MyCommandTarget.Reset();

   return true;
}

bool CPGSuperScriptingAgent::ShutDown()
{
   EAF_AGENT_SHUTDOWN;
   return true;
}


////////////////////////////////////////////////////////////////////
// IAgentUIIntegration
bool CPGSuperScriptingAgent::IntegrateWithUI(bool bIntegrate)
{
   if ( bIntegrate )
   {
      CreateMenus();
      CreateToolBar();
      RegisterViews();

      {
         AFX_MANAGE_STATE(AfxGetStaticModuleState());
         m_Console.Create(EAFGetMainFrame(), IDD_CONSOLE, CBRS_SIZE_DYNAMIC | CBRS_FLOATING, AFX_IDW_CONTROLBAR_LAST + 10);
      }
      m_Console.EnableDocking(CBRS_ALIGN_ANY);
      EAFGetMainFrame()->FloatControlBar(&m_Console,CPoint(500,500),0);
      m_Console.SetWindowText(_T("Python"));
   }
   else
   {
      RemoveMenus();
      RemoveToolBar();
      UnregisterViews();
   }

   return true;
}

/////////////////////////////////////////////////////////////////////////////
// IEAFCommandCallback
BOOL CPGSuperScriptingAgent::OnCommandMessage(UINT nID,int nCode,void* pExtra,AFX_CMDHANDLERINFO* pHandlerInfo)
{
   return m_MyCommandTarget.OnCmdMsg(nID,nCode,pExtra,pHandlerInfo);
}

BOOL CPGSuperScriptingAgent::GetStatusBarMessageString(UINT nID, CString& rMessage) const
{
   AFX_MANAGE_STATE(AfxGetStaticModuleState());

   // load appropriate string
	if ( rMessage.LoadString(nID) )
	{
		// first newline terminates actual string
      rMessage.Replace('\n','\0');
	}
	else
	{
		// not found
		TRACE1("Warning (CPGSuperScriptingAgent): no message line prompt for ID 0x%04X.\n", nID);
	}

   return TRUE;
}

BOOL CPGSuperScriptingAgent::GetToolTipMessageString(UINT nID, CString& rMessage) const
{
   AFX_MANAGE_STATE(AfxGetStaticModuleState());
   CString string;
   // load appropriate string
	if ( string.LoadString(nID) )
	{
		// tip is after first newline 
      int pos = string.Find('\n');
      if ( 0 < pos )
         rMessage = string.Mid(pos+1);
	}
	else
	{
		// not found
		TRACE1("Warning (CPGSuperScriptingAgent): no tool tip for ID 0x%04X.\n", nID);
	}

   return TRUE;
}

////////////////////////////////////////////////////////////////////
// IEAFProcessCommandLine
BOOL CPGSuperScriptingAgent::ProcessCommandLineOptions(CEAFCommandLineInfo& cmdInfo)
{
   CScriptingCommandLineInfo ci;
   EAFGetApp()->ParseCommandLine(ci);
   cmdInfo = ci;
   if (ci.m_bRunScript)
   {
      //ScriptEngine.Run(ci.m_StartupScript);
      return TRUE;
   }
   return FALSE;
}

////////////////////////////////////////////////////////////////////
// IScripting
LPCTSTR CPGSuperScriptingAgent::GetScriptFolder() const
{
   AFX_MANAGE_STATE(AfxGetStaticModuleState());
   CExtensionApp* pApp = (CExtensionApp*)AfxGetApp();
   return pApp->GetScriptPath();
}

std::vector<CString> CPGSuperScriptingAgent::GetScriptNames() const
{
   AFX_MANAGE_STATE(AfxGetStaticModuleState());
   CExtensionApp* pApp = (CExtensionApp*)AfxGetApp();
   CString strSearch;
   strSearch.Format(_T("%s\\*.py"), pApp->GetScriptPath());
   CFileFind find;

   std::vector<CString> vScripts;
   BOOL bWorking = find.FindFile(strSearch);
   while (bWorking)
   {
      bWorking = find.FindNextFile();
      CString strFileTitle = find.GetFileTitle();
      vScripts.push_back(strFileTitle);
   }

   return vScripts;
}

std::vector<CString> CPGSuperScriptingAgent::GetScriptFiles() const
{
   AFX_MANAGE_STATE(AfxGetStaticModuleState());
   CExtensionApp* pApp = (CExtensionApp*)AfxGetApp();
   CString strSearch;
   strSearch.Format(_T("%s\\*.py"), pApp->GetScriptPath());
   CFileFind find;

   std::vector<CString> vScriptFiles;
   BOOL bWorking = find.FindFile(strSearch);
   while (bWorking)
   {
      bWorking = find.FindNextFile();
      CString strFilePath = find.GetFilePath();
      vScriptFiles.push_back(strFilePath);
   }

   return vScriptFiles;
}

CString CPGSuperScriptingAgent::GetScriptFile(LPCTSTR lpszScriptName) const
{
   AFX_MANAGE_STATE(AfxGetStaticModuleState());
   CExtensionApp* pApp = (CExtensionApp*)AfxGetApp();
   CString strScriptPath;
   strScriptPath.Format(_T("%s\\%s.py"), pApp->GetScriptPath(), lpszScriptName);
   return strScriptPath;
}

////////////////////////////////////////////////////////////////////
void CPGSuperScriptingAgent::EditScript(LPCTSTR lpszScriptFile)
{
   // this seems to be working
   // command routing is an issue
   // may need to have a seperate Main Frame window for the script editor
   // this would actually be good... that way we can use the script debugger
   // would be best if the editor/debugger was in its own thread?
   CExtensionApp* pApp;
   {
      AFX_MANAGE_STATE(AfxGetStaticModuleState());
      pApp = (CExtensionApp*)AfxGetApp();
   }

   if (lpszScriptFile == nullptr)
   {
      pApp->m_pDocManager->OnFileNew();

      CFrameWnd* pFrame = ((CFrameWnd*)AfxGetMainWnd())->GetActiveFrame();
      ATLASSERT(pFrame->IsKindOf(RUNTIME_CLASS(CPyEditorFrame)));
      CPyEditorView* pView = (CPyEditorView*)(pFrame->GetActiveView());
      if (pView && pView->IsKindOf(RUNTIME_CLASS(CPyEditorView)))
      {
         CScintillaCtrl& ctrl = pView->GetCtrl();

         CString strScriptStarter("#PGSuper Python Script\n\nimport BridgeLink\npgsuper = BridgeLink.GetPGSuper()\n\n# Add script code below\n");
         ctrl.AddText(strScriptStarter.GetLength(), strScriptStarter.GetBuffer());
      }
   }
   else
   {
      pApp->m_pDocManager->OpenDocumentFile(lpszScriptFile);
   }

   //CCreateContext context;
   //context.m_pCurrentFrame = nullptr;
   //context.m_pCurrentDoc = &m_ScriptDocument;
   //context.m_pNewViewClass = RUNTIME_CLASS(CPyEditorView);
   //context.m_pNewDocTemplate = nullptr;

   //m_pFrame = static_cast<CPyEditorFrame*>(RUNTIME_CLASS(CPyEditorFrame)->CreateObject());
   //if (!m_pFrame->LoadFrame(IDR_PYEDITOR, WS_OVERLAPPEDWINDOW | FWS_ADDTOTITLE, EAFGetMainFrame(), &context))
   //{
   //   ATLASSERT(false);
   //}

   //ASSERT_KINDOF(CMDIChildWnd, m_pFrame);

   //m_pView = static_cast<CPyEditorView*>(context.m_pNewViewClass->CreateObject());
   //if (m_pView == nullptr)
   //{
   //   ATLASSERT(false);
   //   //return -1;
   //}
   //if (!m_pView->Create(nullptr, nullptr, WS_CHILD | WS_VISIBLE, CRect(0, 0, 0, 0), m_pFrame, 2, &context))
   //{
   //   ATLASSERT(false);
   //   //return -1;
   //}
   //ATLASSERT(m_pView != nullptr);

   //m_pFrame->ActivateFrame();
   //m_pFrame->RecalcLayout();

   //CString strFileName;
   //if (GetScriptFile(strFileName))
   //{
   //   CFile file;
   //   file.Open(strFileName, CFile::modeRead);
   //   CArchive ar(&file, CArchive::load);

   //   m_ScriptDocument.Serialize(ar);

   //   ar.Close();
   //   file.Close();
   //}

}
