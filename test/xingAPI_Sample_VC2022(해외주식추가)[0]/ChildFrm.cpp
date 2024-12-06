// ChildFrm.cpp : implementation of the CChildFrame class
//

#include "stdafx.h"
#include "XingAPI_Sample.h"

#include "ChildFrm.h"

// �ֽ�
#include "Dlg_t1101.h"				// �ֽ����簡ȣ����ȸ
#include "Dlg_t1301.h"				// �ֽĽð��뺰ü����ȸ
#include "Dlg_t1305.h"				// �Ⱓ���ְ�
#include "Dlg_t1452.h"				// �ŷ�������
#include "Dlg_t8411.h"				// �ֽ�íƮ(ƽ/nƽ)

#include "Dlg_H1_.h"
#include "Dlg_H2_.h"
#include "Dlg_h3_ELW.h"
#include "Dlg_h2_ELW.h"

#include "Dlg_CSPAT00600.h"			// ���������ֹ�
#include "Dlg_CSPAT00700.h"			// ���������ֹ�
#include "Dlg_CSPAT00800.h"			// ��������ֹ�

#include "Dlg_SC0.h"				// �ֽ��ֹ�����
#include "Dlg_SC1.h"				// �ֽ��ֹ�ü��
#include "Dlg_SC2.h"				// �ֽ��ֹ�����
#include "Dlg_SC3.h"				// �ֽ��ֹ����
#include "Dlg_SC4.h"				// �ֽ��ֹ��ź�

#include "Dlg_CSPAQ03700.h"			// �������� �ֹ�ü�᳻�� ��ȸ
#include "Dlg_CSPAQ02300.h"			// �������� �ܰ��� ��ȸ
#include "Dlg_CSPAQ02200.h"			// �������� ������/�ֹ����ɱݾ�/���� ��ȸ
#include "Dlg_CSPBQ00200.h"			// �������� ���űݷ��� �ֹ����ɼ��� ��ȸ

// �����ɼ�
#include "Dlg_FC0.h"				// ����ü��

#include "Dlg_CFOAT00100.h"			// �����ɼ� �����ֹ�
#include "Dlg_CFOAT00200.h"			// �����ɼ� �����ֹ�
#include "Dlg_CFOAT00300.h"			// �����ɼ� ����ֹ�
#include "Dlg_C01.h"				// �����ɼ� �ֹ�ü��
#include "Dlg_H01.h"				// �����ɼ� �������

#include "Dlg_CFOAQ00600.h"			// �����ɼ� �����ֹ�ü�᳻�� ��ȸ
#include "Dlg_CFOFQ02400.h"			// �����ɼ� �̰���������Ȳ

// CME �߰�����
#include "Dlg_CCEAT00100.h"			// CME �߰����� �����ֹ�
#include "Dlg_CCEAT00200.h"			// CME �߰����� �����ֹ�
#include "Dlg_CCEAT00300.h"			// CME �߰����� ����ֹ�

// EUREX �߰��ɼ�
#include "Dlg_CEXAT11100.h"			// EUREX �߰��ɼ� �����ֹ�
#include "Dlg_CEXAT11200.h"			// EUREX �߰��ɼ� �����ֹ�
#include "Dlg_CEXAT11300.h"			// EUREX �߰��ɼ� ����ֹ�

// �ֽļ���
#include "Dlg_JC0.h"

// �ؿ��ֽ�
#include "Dlg_g3101.h"				// �ؿ��ֽ����簡��ȸ
#include "Dlg_g3202.h"				// �ؿ��ֽ���ƮNTICK��ȸ
#include "Dlg_GSC.h"				// �ؿ��ֽ� ü��
#include "Dlg_GSH.h"				// �ؿ��ֽ� ȣ��
#include "Dlg_COSAT00301.h"			// �̱��ֽ��ֹ�
#include "Dlg_COSAT00311.h"			// �̱��ֽ������ֹ�
#include "Dlg_COSAQ00102.h"			// �ؿ��ֽ� ü�᳻�� ��ȸ
#include "Dlg_COSOQ00201.h"			// �ؿ��ֽ� �ܰ��� ��ȸ
#include "Dlg_AS0.h"				// �ؿ��ֽ��ֹ�����(�̱�)
#include "Dlg_AS1.h"				// �ؿ��ֽ��ֹ�ü��(�̱�)
#include "Dlg_AS2.h"				// �ؿ��ֽ��ֹ�����(�̱�)
#include "Dlg_AS3.h"				// �ؿ��ֽ��ֹ����(�̱�)
#include "Dlg_AS4.h"				// �ؿ��ֽ��ֹ��ź�(�̱�)

// �����ں�
#include "Dlg_t1601.h"				// �����ں�����
#include "Dlg_t1602.h"				// �ð��뺰 �����ڸŸ�����

#include "Dlg_BMT.h"
#include "Dlg_BM_.h"

// ��Ÿ
#include "Dlg_t9942.h"				// API�� ELW ��������ȸ
#include "Dlg_t9943.h"				// API�� �������� ��������ȸ
#include "Dlg_g3190.h"				// API�� �ؿ��ֽ� ��������ȸ

static TR_WINDOW_TABLE s_tblTrWindow[] = 
{
	//---------------------------------------------------------------------------------------------
	// �ֽ�/ELW �ü�
	{ "�ֽ�/ELW" , "�ü�", "��ȸTR",   "t1101"     , RUNTIME_CLASS(CDlg_t1101     ), IDD_t1101     , "�ֽ����簡ȣ����ȸ(t1101)" },
 	{ "�ֽ�/ELW" , "�ü�", "��ȸTR",   "t1301"     , RUNTIME_CLASS(CDlg_t1301     ), IDD_t1301     , "�ֽĽð��뺰ü����ȸ(t1301)" },
 	{ "�ֽ�/ELW" , "�ü�", "��ȸTR",   "t1305"     , RUNTIME_CLASS(CDlg_t1305     ), IDD_t1305     , "�Ⱓ���ְ�(t1305)" },
 	{ "�ֽ�/ELW" , "�ü�", "��ȸTR",   "t1452"     , RUNTIME_CLASS(CDlg_t1452     ), IDD_t1452     , "�ŷ�������(t1452)" },
 	{ "�ֽ�/ELW" , "�ü�", "��ȸTR",   "t8411"     , RUNTIME_CLASS(CDlg_t8411     ), IDD_t8411     , "�ֽ�íƮ(ƽ/nƽ)(t8411)" },

	{ "�ֽ�/ELW" , "�ü�", "�ǽð�TR", "H1_"       , RUNTIME_CLASS(CDlg_H1_       ), IDD_H1_       , "KOSPI ȣ���ܷ�" },
	{ "�ֽ�/ELW" , "�ü�", "�ǽð�TR", "H2_"       , RUNTIME_CLASS(CDlg_H2_       ), IDD_H2_       , "KOSPI �ð���ȣ���ܷ�" },
	{ "�ֽ�/ELW" , "�ü�", "�ǽð�TR", "h3_"       , RUNTIME_CLASS(CDlg_h3_ELW    ), IDD_h3_ELW    , "ELW ȣ���ܷ�" },
	{ "�ֽ�/ELW" , "�ü�", "�ǽð�TR", "h2_"       , RUNTIME_CLASS(CDlg_h2_ELW    ), IDD_h2_ELW    , "ELW �ð���ȣ���ܷ�" },
	//---------------------------------------------------------------------------------------------

	//---------------------------------------------------------------------------------------------
	// �ֽ�/ELW �ֹ�
	{ "�ֽ�/ELW" , "�ֹ�", "��ȸTR",   "CSPAT00600", RUNTIME_CLASS(CDlg_CSPAT00600), IDD_CSPAT00600, "���������ֹ�(CSPAT00600)" },
	{ "�ֽ�/ELW" , "�ֹ�", "��ȸTR",   "CSPAT00700", RUNTIME_CLASS(CDlg_CSPAT00700), IDD_CSPAT00700, "���������ֹ�(CSPAT00700)" },
 	{ "�ֽ�/ELW" , "�ֹ�", "��ȸTR",   "CSPAT00800", RUNTIME_CLASS(CDlg_CSPAT00800), IDD_CSPAT00800, "��������ֹ�(CSPAT00800)" },
	
	{ "�ֽ�/ELW" , "�ֹ�", "�ǽð�TR", "SC0"       , RUNTIME_CLASS(CDlg_SC0       ), IDD_SC0       , "�ֽ��ֹ�����" },
	{ "�ֽ�/ELW" , "�ֹ�", "�ǽð�TR", "SC1"       , RUNTIME_CLASS(CDlg_SC1       ), IDD_SC1       , "�ֽ��ֹ�ü��" },
	{ "�ֽ�/ELW" , "�ֹ�", "�ǽð�TR", "SC2"       , RUNTIME_CLASS(CDlg_SC2       ), IDD_SC2       , "�ֽ��ֹ�����" },
	{ "�ֽ�/ELW" , "�ֹ�", "�ǽð�TR", "SC3"       , RUNTIME_CLASS(CDlg_SC3       ), IDD_SC3       , "�ֽ��ֹ����" },
	{ "�ֽ�/ELW" , "�ֹ�", "�ǽð�TR", "SC4"       , RUNTIME_CLASS(CDlg_SC4       ), IDD_SC4       , "�ֽ��ֹ��ź�" },
	//---------------------------------------------------------------------------------------------

	//---------------------------------------------------------------------------------------------
	// �ֽ�/ELW ����
	{ "�ֽ�/ELW" , "����", "��ȸTR"  , "CSPAQ13700", RUNTIME_CLASS(CDlg_CSPAQ03700), IDD_CSPAQ03700, "�������� �ֹ�ü�᳻�� ��ȸ" },
	{ "�ֽ�/ELW" , "����", "��ȸTR"  , "CSPAQ12300", RUNTIME_CLASS(CDlg_CSPAQ02300), IDD_CSPAQ02300, "�������� �ܰ��� ��ȸ" },
	{ "�ֽ�/ELW" , "����", "��ȸTR"  , "CSPAQ12200", RUNTIME_CLASS(CDlg_CSPAQ02200), IDD_CSPAQ02200, "�������� ������/�ֹ����ɱݾ�/���� ��ȸ" },
	{ "�ֽ�/ELW" , "����", "��ȸTR"  , "CSPBQ00200", RUNTIME_CLASS(CDlg_CSPBQ00200), IDD_CSPBQ00200, "�������� ���űݷ��� �ֹ����ɼ��� ��ȸ" },
	//---------------------------------------------------------------------------------------------

	//---------------------------------------------------------------------------------------------
	// ����/�ɼ� �ü�
	{ "����/�ɼ�", "�ü�", "�ǽð�TR", "FC0"       , RUNTIME_CLASS(CDlg_FC0       ), IDD_FC0       , "����ü��" },
	
	//---------------------------------------------------------------------------------------------
	// ����/�ɼ� �ֹ�
	{ "����/�ɼ�", "�ֹ�", "��ȸTR"  , "CFOAT00100", RUNTIME_CLASS(CDlg_CFOAT00100), IDD_CFOAT00100, "�����ɼ� �����ֹ�" },
	{ "����/�ɼ�", "�ֹ�", "��ȸTR"  , "CFOAT00200", RUNTIME_CLASS(CDlg_CFOAT00200), IDD_CFOAT00200, "�����ɼ� �����ֹ�" },
	{ "����/�ɼ�", "�ֹ�", "��ȸTR"  , "CFOAT00300", RUNTIME_CLASS(CDlg_CFOAT00300), IDD_CFOAT00300, "�����ɼ� ����ֹ�" },
	{ "����/�ɼ�", "�ֹ�", "�ǽð�TR", "C01",		 RUNTIME_CLASS(CDlg_C01),		 IDD_C01,	     "�����ɼ� �ֹ�ü��" },
	{ "����/�ɼ�", "�ֹ�", "�ǽð�TR", "H01",		 RUNTIME_CLASS(CDlg_H01),		 IDD_H01,	     "�����ɼ� �������" },
	//---------------------------------------------------------------------------------------------
	
	//---------------------------------------------------------------------------------------------
	// ����/�ɼ� ����
	{ "����/�ɼ�", "����", "��ȸTR"  , "CFOAQ00600", RUNTIME_CLASS(CDlg_CFOAQ00600), IDD_CFOAQ00600, "�����ɼ� �����ֹ�ü�᳻�� ��ȸ" },
	{ "����/�ɼ�", "����", "��ȸTR"  , "CFOFQ02400", RUNTIME_CLASS(CDlg_CFOFQ02400), IDD_CFOFQ02400, "�����ɼ� �̰���������Ȳ" },
	//---------------------------------------------------------------------------------------------
	
	//---------------------------------------------------------------------------------------------
	// CME �߰����� �ֹ�
	{ "CME �߰�����", "�ֹ�", "��ȸTR"  , "CCEAT00100", RUNTIME_CLASS(CDlg_CCEAT00100), IDD_CCEAT00100, "CME �߰����� �����ֹ�" },
	{ "CME �߰�����", "�ֹ�", "��ȸTR"  , "CCEAT00200", RUNTIME_CLASS(CDlg_CCEAT00200), IDD_CCEAT00200, "CME �߰����� �����ֹ�" },
	{ "CME �߰�����", "�ֹ�", "��ȸTR"  , "CCEAT00300", RUNTIME_CLASS(CDlg_CCEAT00300), IDD_CCEAT00300, "CME �߰����� ����ֹ�" },
	//---------------------------------------------------------------------------------------------
	
	//---------------------------------------------------------------------------------------------
	// EUREX �߰��ɼ� �ֹ�
	{ "EUREX �߰��ɼ�", "�ֹ�", "��ȸTR"  , "CEXAT11100", RUNTIME_CLASS(CDlg_CEXAT11100), IDD_CEXAT11100, "EUREX �߰��ɼ� �����ֹ�" },
	{ "EUREX �߰��ɼ�", "�ֹ�", "��ȸTR"  , "CEXAT11200", RUNTIME_CLASS(CDlg_CEXAT11200), IDD_CEXAT11200, "EUREX �߰��ɼ� �����ֹ�" },
	{ "EUREX �߰��ɼ�", "�ֹ�", "��ȸTR"  , "CEXAT11300", RUNTIME_CLASS(CDlg_CEXAT11300), IDD_CEXAT11300, "EUREX �߰��ɼ� ����ֹ�" },
	//---------------------------------------------------------------------------------------------

	//---------------------------------------------------------------------------------------------
	// �ֽļ��� �ü�
	{ "�ֽļ���" , "�ü�", "�ǽð�TR", "JC0"       , RUNTIME_CLASS(CDlg_JC0       ), IDD_JC0       , "����ü��" },
	//---------------------------------------------------------------------------------------------
	
	//---------------------------------------------------------------------------------------------
	// ���� �ü�
	//---------------------------------------------------------------------------------------------
	
	//---------------------------------------------------------------------------------------------
	// ������
	{ "������", "", "��ȸTR", "t1601", RUNTIME_CLASS(CDlg_t1601), IDD_t1601, "�����ں�����" },
	{ "������", "", "��ȸTR", "t1602", RUNTIME_CLASS(CDlg_t1602), IDD_t1602, "�ð��뺰 �����ڸŸ�����" },

	{ "������", "", "�ǽð�TR", "BMT"  , RUNTIME_CLASS(CDlg_BMT), IDD_BMT, "�ð��뺰 �����ڸŸ�����" },
	{ "������", "", "�ǽð�TR", "BM_"  , RUNTIME_CLASS(CDlg_BM_), IDD_BM_, "�����ں� �����ں� �Ÿ���Ȳ" },
	//---------------------------------------------------------------------------------------------

	//---------------------------------------------------------------------------------------------
	// ���α׷�
	//---------------------------------------------------------------------------------------------

	//---------------------------------------------------------------------------------------------
	// ��������
	//---------------------------------------------------------------------------------------------

	//---------------------------------------------------------------------------------------------
	// ��Ʈ
	//---------------------------------------------------------------------------------------------

	//---------------------------------------------------------------------------------------------
	// �ؿ��ֽ�

	//---------------------------------------------------------------------------------------------
	{ "�ؿ��ֽ�" , "�ü�", "��ȸTR",   "g3101"     , RUNTIME_CLASS(CDlg_g3101     ), IDD_g3101     , "�ؿ��ֽ� ���簡 ȣ����ȸ(g3101)" },
	{ "�ؿ��ֽ�" , "�ü�", "��ȸTR",   "g3202"     , RUNTIME_CLASS(CDlg_g3202     ), IDD_g3202     , "�ؿ��ֽ� ��ƮNTICK ��ȸ(g3202)" },
	{ "�ؿ��ֽ�", "�ֹ�", "��ȸTR"  , "COSAT00301", RUNTIME_CLASS(CDlg_COSAT00301), IDD_COSAT00301, "�̱��ֽ��ֹ�" },
	{ "�ؿ��ֽ�", "�ֹ�", "��ȸTR"  , "COSAT00311", RUNTIME_CLASS(CDlg_COSAT00311), IDD_COSAT00311, "�̱��ֽ������ֹ�" },
	{ "�ؿ��ֽ�" , "����", "��ȸTR"  , "COSAQ00102", RUNTIME_CLASS(CDlg_COSAQ00102), IDD_COSAQ00102, "�ؿ��ֽ� �ֹ�ü�᳻�� ��ȸ" },
	{ "�ؿ��ֽ�" , "����", "��ȸTR"  , "COSOQ00201", RUNTIME_CLASS(CDlg_COSOQ00201), IDD_COSOQ00201, "�ؿ��ֽ� �ܰ��� ��ȸ" },
	{ "�ؿ��ֽ�", "", "�ǽð�TR", "GSC", RUNTIME_CLASS(CDlg_GSC), IDD_GSC, "�ؿ��ֽ� ü��(GSC)" },
	{ "�ؿ��ֽ�", "", "�ǽð�TR", "GSH", RUNTIME_CLASS(CDlg_GSH), IDD_GSH, "�ؿ��ֽ� ȣ��(GSH)" },
	{ "�ؿ��ֽ�" , "", "�ǽð�TR", "AS0", RUNTIME_CLASS(CDlg_AS0), IDD_AS0, "�ؿ��ֽ��ֹ�����(�̱�)" },
	{ "�ؿ��ֽ�" , "", "�ǽð�TR", "AS1", RUNTIME_CLASS(CDlg_AS1), IDD_AS1, "�ؿ��ֽ��ֹ�ü��(�̱�)" },
	{ "�ؿ��ֽ�" , "", "�ǽð�TR", "AS2", RUNTIME_CLASS(CDlg_AS2), IDD_AS2, "�ؿ��ֽ��ֹ�����(�̱�)" },
	{ "�ؿ��ֽ�" , "", "�ǽð�TR", "AS3", RUNTIME_CLASS(CDlg_AS3), IDD_AS3, "�ؿ��ֽ��ֹ����(�̱�)" },
	{ "�ؿ��ֽ�" , "", "�ǽð�TR", "AS4", RUNTIME_CLASS(CDlg_AS4), IDD_AS4, "�ؿ��ֽ��ֹ��ź�(�̱�)" },
	//---------------------------------------------------------------------------------------------
	// ��Ÿ
	{ "��Ÿ", "", "��ȸTR", "t9942", RUNTIME_CLASS(CDlg_t9942), IDD_t9942, "ELW��������ȸAPI��(t9942)" },
	{ "��Ÿ", "", "��ȸTR", "t9943", RUNTIME_CLASS(CDlg_t9943), IDD_t9943, "����������������ȸAPI��(t9943)" },
	{ "��Ÿ", "", "��ȸTR", "g3190", RUNTIME_CLASS(CDlg_g3190), IDD_g3190, "�ؿ��ֽĸ�������ȸ(g3190)" },
	//---------------------------------------------------------------------------------------------
};

int GetTRWindowTableCount()
{
	return sizeof( s_tblTrWindow ) / sizeof( TR_WINDOW_TABLE );
}

LPTR_WINDOW_TABLE GetTRWindowTableData()
{
	return s_tblTrWindow;
}

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CChildFrame

IMPLEMENT_DYNCREATE(CChildFrame, CMDIChildWnd)

BEGIN_MESSAGE_MAP(CChildFrame, CMDIChildWnd)
	//{{AFX_MSG_MAP(CChildFrame)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code !
		ON_COMMAND(ID_FILE_CLOSE, OnFileClose)
		ON_WM_SETFOCUS()
		ON_WM_CREATE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CChildFrame construction/destruction

CChildFrame::CChildFrame()
{
	// TODO: add member initialization code here
	
}

CChildFrame::~CChildFrame()
{
}

BOOL CChildFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	if( !CMDIChildWnd::PreCreateWindow(cs) )
		return FALSE;

	cs.dwExStyle &= ~WS_EX_CLIENTEDGE;
	cs.lpszClass = AfxRegisterWndClass(0);

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CChildFrame diagnostics

#ifdef _DEBUG
void CChildFrame::AssertValid() const
{
	CMDIChildWnd::AssertValid();
}

void CChildFrame::Dump(CDumpContext& dc) const
{
	CMDIChildWnd::Dump(dc);
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CChildFrame message handlers
void CChildFrame::OnFileClose() 
{
	// To close the frame, just send a WM_CLOSE, which is the equivalent
	// choosing close from the system menu.

	SendMessage(WM_CLOSE);
}

int CChildFrame::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CMDIChildWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// create a view to occupy the client area of the frame
	if (!m_wndView.Create(NULL, NULL, AFX_WS_DEFAULT_VIEW, 
		CRect(0, 0, 0, 0), this, AFX_IDW_PANE_FIRST, NULL))
	{
		TRACE0("Failed to create view window\n");
		return -1;
	}

	return 0;
}

void CChildFrame::OnSetFocus(CWnd* pOldWnd) 
{
	CMDIChildWnd::OnSetFocus(pOldWnd);

	m_wndView.SetFocus();
}

BOOL CChildFrame::OnCmdMsg(UINT nID, int nCode, void* pExtra, AFX_CMDHANDLERINFO* pHandlerInfo) 
{
	// let the view have first crack at the command
	if (m_wndView.OnCmdMsg(nID, nCode, pExtra, pHandlerInfo))
		return TRUE;
	
	// otherwise, do default handling
	return CMDIChildWnd::OnCmdMsg(nID, nCode, pExtra, pHandlerInfo);
}

BOOL CChildFrame::SetTR( LPCTSTR pszTrCode )
{
	int nCount = sizeof( s_tblTrWindow ) / sizeof( TR_WINDOW_TABLE );
	for( int i=0; i<nCount; i++ )
	{
		if( strcmp( s_tblTrWindow[i].szTrCode, pszTrCode ) == 0 )
		{
			char szTitle[256] = { 0 };
			sprintf_s( szTitle, "[%s] %s", s_tblTrWindow[i].szTrCode, s_tblTrWindow[i].szDesc );
			SetWindowText( szTitle  );
			CDocument* pDocument = GetActiveDocument();
			if( pDocument )
			{
				pDocument->SetTitle( szTitle );
			}
			else
			{
				m_strTitle = szTitle;
			}
			m_wndView.SetTR( s_tblTrWindow[i].pRuntimeClass, s_tblTrWindow[i].uDlgID );
			return TRUE;
		}
	}

	CString strMsg;
	strMsg.Format( "%s �� Sample�� ã�� �� �����ϴ�.", pszTrCode );
	
	MessageBox( strMsg, "����", MB_ICONSTOP );

	SendMessage( WM_CLOSE );
	
	return FALSE;
}