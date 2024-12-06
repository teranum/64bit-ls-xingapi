// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "XingAPI_Sample.h"

#include "MainFrm.h"
#include "ChildFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMainFrame

IMPLEMENT_DYNAMIC(CMainFrame, CMDIFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CMDIFrameWnd)
	//{{AFX_MSG_MAP(CMainFrame)
	ON_WM_CREATE()
	ON_WM_CLOSE()
	//}}AFX_MSG_MAP
	ON_MESSAGE( WMU_SHOW_TR, OnShowTR )
	ON_MESSAGE( WM_USER + XM_DISCONNECT, OnDisconnect )
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMainFrame construction/destruction

CMainFrame::CMainFrame()
{
	// TODO: add member initialization code here
	
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CMDIFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	if( !m_wndTRBar.Create( "", this, 2000, WS_CHILD | WS_VISIBLE | CBRS_LEFT ) )
	{
		TRACE( "Failed to create tr bar\n" );
		return -1;		// fail to create
	}	
	EnableDocking(CBRS_ALIGN_ANY);

	//-----------------------------------------------------------------------------------------
	// X-ing API 초기화
	//-----------------------------------------------------------------------------------------

	// 설치된 XingAPI의 경로를 얻어온다.
#ifdef _WIN64
	LPCTSTR szClassPath = "WOW6432Node\\CLSID\\{7FEF321C-6BFD-413C-AA80-541A275434A1}\\InprocServer32";
#else
	LPCTSTR szClassPath = "CLSID\\{7FEF321C-6BFD-413C-AA80-541A275434A1}\\InprocServer32";
#endif // _WIN64
	HKEY hKey;
	CString szXingFolder;
	if (RegOpenKeyEx(HKEY_CLASSES_ROOT, szClassPath, 0, KEY_READ, &hKey) == ERROR_SUCCESS)
	{
		char szPath[MAX_PATH];
		DWORD dwType = REG_SZ;
		DWORD dwSize = MAX_PATH;
		if (RegQueryValueEx(hKey, "", NULL, &dwType, (LPBYTE)szPath, &dwSize) == ERROR_SUCCESS)
		{
			szXingFolder = szPath;
			int nFind = szXingFolder.ReverseFind('\\');
			if (nFind > 0)
			{
				szXingFolder = szXingFolder.Left(nFind);
			}
		}
		RegCloseKey(hKey);
	}

	if (szXingFolder.GetLength() == 0)
	{
		MessageBox("XingAPI 가 설치되어 있지 않습니다.");
		return -1;
	}
	
	if( g_iXingAPI.Init(szXingFolder) == FALSE )
	{
		MessageBox("DLL을 Load 할 수 없습니다.");
		return -1;
	}
	//-----------------------------------------------------------------------------------------
	return 0;
}

void CMainFrame::OnClose() 
{
	// Logout 한다
	//		굳이 응답을 받을 필요는 없다.
	//		Login을 하지 않은 상태에서 Logout을 하면 FALSE가 Return 되므로 Login 여부를 체크하지 않아도 된다.
	g_iXingAPI.Logout( GetSafeHwnd() );
	g_iXingAPI.Disconnect();	
	
	CMDIFrameWnd::OnClose();
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CMDIFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CMainFrame diagnostics

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CMDIFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CMDIFrameWnd::Dump(dc);
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMainFrame message handlers


LRESULT CMainFrame::OnShowTR( WPARAM wParam, LPARAM lParam )
{
	LPCTSTR pszTR = (LPCTSTR)wParam;
	TRACE( "Show Window : %s\n", pszTR );
	
	CChildFrame* pWnd = (CChildFrame*)CreateNewChild( RUNTIME_CLASS(CChildFrame), IDR_XINGAPTYPE, NULL, NULL );
	pWnd->SetTR( pszTR );

	return 0L;
}

//--------------------------------------------------------------------------------------
// 서버연결 종료
//--------------------------------------------------------------------------------------
LRESULT CMainFrame::OnDisconnect( WPARAM wParam, LPARAM lParam )
{
	MessageBox( "서버와의 연결이 종료되었습니다.", "통신에러", MB_ICONSTOP );
	return 0L;
}
