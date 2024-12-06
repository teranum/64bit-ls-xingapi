// Dlg_g3101.cpp : implementation file
//

#include "stdafx.h"
#include "XingAPI_Sample.h"
#include "Dlg_g3101.h"

#include "./Packet/g3101.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlg_g3101 dialog

IMPLEMENT_DYNCREATE(CDlg_g3101, CDialog)

// CDlg_g3101::CDlg_g3101(CWnd* pParent /*=NULL*/)
// : CDialog(CDlg_g3101::IDD, pParent)
CDlg_g3101::CDlg_g3101()
{
	//{{AFX_DATA_INIT(CDlg_g3101)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CDlg_g3101::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlg_g3101)
	//}}AFX_DATA_MAP
	DDX_Control(pDX, IDC_OUTBLOCK, m_ctrlOutBlock);
}


BEGIN_MESSAGE_MAP(CDlg_g3101, CDialog)
	//{{AFX_MSG_MAP(CDlg_g3101)
	//}}AFX_MSG_MAP
	ON_BN_CLICKED( IDC_BUTTON_REQUEST,		  OnButtonRequest	  )
	ON_MESSAGE	 ( WM_USER + XM_RECEIVE_DATA, OnXMReceiveData	  )
	ON_MESSAGE	 ( WM_USER + XM_TIMEOUT_DATA, OnXMTimeoutData	  )
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlg_g3101 message handlers

BOOL CDlg_g3101::OnInitDialog() 
{
	CDialog::OnInitDialog();

	InitCtrls();
	
	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}

void CDlg_g3101::OnButtonRequest() 
{
	RequestData();
}


//--------------------------------------------------------------------------------------
// ��Ʈ�� �ʱ�ȭ
//--------------------------------------------------------------------------------------
void CDlg_g3101::InitCtrls()
{
	m_ctrlOutBlock.InsertColumn( 0, "�ʵ��", LVCFMT_LEFT, 150 );
	m_ctrlOutBlock.InsertColumn( 1, "������", LVCFMT_LEFT, 200 );

	// List Control�� OutBlock �ʵ���� �־��ش�.
	m_ctrlOutBlock.InsertItem(  0, "��������     " );
	m_ctrlOutBlock.InsertItem(  1, "KEY�����ڵ�  " );
	m_ctrlOutBlock.InsertItem(  2, "�ŷ����ڵ�   " );
	m_ctrlOutBlock.InsertItem(  3, "�ŷ���ID     " );
	m_ctrlOutBlock.InsertItem(  4, "�ŷ�����     " );
	m_ctrlOutBlock.InsertItem(  5, "�Ÿű���     " );
	m_ctrlOutBlock.InsertItem(  6, "�����ڵ�     " );
	m_ctrlOutBlock.InsertItem(  7, "�ѱ������   " );
	m_ctrlOutBlock.InsertItem(  8, "�����ѱ۸�   " );
	m_ctrlOutBlock.InsertItem(  9, "�Ҽ����ڸ��� " );
	m_ctrlOutBlock.InsertItem( 10, "��ȯ�ڵ�     " );
	m_ctrlOutBlock.InsertItem( 11, "���簡       " );
	m_ctrlOutBlock.InsertItem( 12, "���ϴ�񱸺� " );
	m_ctrlOutBlock.InsertItem( 13, "���ϴ��     " );
	m_ctrlOutBlock.InsertItem( 14, "�����       " );
	m_ctrlOutBlock.InsertItem( 15, "�ŷ���       " );
	m_ctrlOutBlock.InsertItem( 16, "�ŷ����     " );
	m_ctrlOutBlock.InsertItem( 17, "52���ְ�   " );
	m_ctrlOutBlock.InsertItem( 18, "52��������   " );
	m_ctrlOutBlock.InsertItem( 19, "���Ѱ�       " );
	m_ctrlOutBlock.InsertItem( 20, "���Ѱ�       " );
	m_ctrlOutBlock.InsertItem( 21, "�ð�         " );
	m_ctrlOutBlock.InsertItem( 22, "����         " );
	m_ctrlOutBlock.InsertItem( 23, "��         " );
	m_ctrlOutBlock.InsertItem( 24, "PER          " );
	m_ctrlOutBlock.InsertItem( 25, "EPS         " );
}

//--------------------------------------------------------------------------------------
// ������ ��ȸ
//--------------------------------------------------------------------------------------
void CDlg_g3101::RequestData( BOOL bNext )
{
	//-----------------------------------------------------------
	// �ֽ����簡ȣ����ȸ(g3101) ( attr,block,headtype=A )
	g3101InBlock	pckInBlock;

	TCHAR			szTrNo[]	= "g3101";
	char			szNextKey[]	= "";

	//-----------------------------------------------------------
	// ������ �ʱ�ȭ
	FillMemory( &pckInBlock, sizeof( pckInBlock ), ' ' );

	//-----------------------------------------------------------
	// ������ �Է�
	SetPacketData( pckInBlock.delaygb  , sizeof( pckInBlock.delaygb   ), this, IDC_INBLOCK_DELAYGB  , DATA_TYPE_STRING );	// ��������
	SetPacketData( pckInBlock.keysymbol, sizeof( pckInBlock.keysymbol ), this, IDC_INBLOCK_KEYSYMBOL, DATA_TYPE_STRING );	// KEY�����ڵ�
	SetPacketData( pckInBlock.exchcd   , sizeof( pckInBlock.exchcd    ), this, IDC_INBLOCK_EXCHCD   , DATA_TYPE_STRING );	// �ŷ����ڵ�    
	SetPacketData( pckInBlock.symbol   , sizeof( pckInBlock.symbol    ), this, IDC_INBLOCK_SYMBOL   , DATA_TYPE_STRING );	// �����ڵ�    

	//-----------------------------------------------------------
	// ������ ����
	int nRqID = g_iXingAPI.Request( 
		GetSafeHwnd(),				// �����͸� ���� ������, XM_RECEIVE_DATA ���� �´�.
		szTrNo,						// TR ��ȣ
		&pckInBlock,				// InBlock ������
		sizeof( pckInBlock ),		// InBlock ������ ũ��
		bNext,						// ������ȸ ���� : ������ȸ�� ��쿡 �����Ѵ�.
		szNextKey,					// ������ȸ Key : Header Type�� B �� ��쿣 ���� ��ȸ�� ���� Next Key�� �־��ش�.
		30							// Timeout(��) : �ش� �ð�(��)���� �����Ͱ� ���� ������ Timeout�� �߻��Ѵ�. XM_TIMEOUT_DATA �޽����� �߻��Ѵ�.
	);

	//-----------------------------------------------------------
	// Request ID�� 0���� ���� ��쿡�� �����̴�.
	if( nRqID < 0 )
	{
		MessageBox( "��ȸ����", "����", MB_ICONSTOP );
	}
}

//--------------------------------------------------------------------------------------
// �����͸� ����
//--------------------------------------------------------------------------------------
LRESULT CDlg_g3101::OnXMReceiveData( WPARAM wParam, LPARAM lParam )
{
	//-------------------------------------------------------------------------------------
	// Data�� ����
	if( wParam == REQUEST_DATA )
	{
		LPRECV_PACKET pRpData = (LPRECV_PACKET)lParam;

		LPg3101OutBlock pOutBlock = (LPg3101OutBlock)pRpData->lpData;

		m_ctrlOutBlock.SetItemText(  0, 1, GetDispData( pOutBlock->delaygb    , sizeof( pOutBlock->delaygb       ), DATA_TYPE_STRING ) );
		m_ctrlOutBlock.SetItemText(  1, 1, GetDispData( pOutBlock->keysymbol , sizeof( pOutBlock->keysymbol      ), DATA_TYPE_STRING ) );
		m_ctrlOutBlock.SetItemText(  2, 1, GetDispData( pOutBlock->exchcd    , sizeof( pOutBlock->exchcd         ), DATA_TYPE_STRING ) );
		m_ctrlOutBlock.SetItemText(  3, 1, GetDispData( pOutBlock->exchange  , sizeof( pOutBlock->exchange       ), DATA_TYPE_STRING ) );
		m_ctrlOutBlock.SetItemText(  4, 1, GetDispData( pOutBlock->suspend   , sizeof( pOutBlock->suspend        ), DATA_TYPE_STRING ) );
		m_ctrlOutBlock.SetItemText(  5, 1, GetDispData( pOutBlock->sellonly  , sizeof( pOutBlock->sellonly       ), DATA_TYPE_STRING ) );
		m_ctrlOutBlock.SetItemText(  6, 1, GetDispData( pOutBlock->symbol    , sizeof( pOutBlock->symbol         ), DATA_TYPE_STRING ) );
		m_ctrlOutBlock.SetItemText(  7, 1, GetDispData( pOutBlock->korname   , sizeof( pOutBlock->korname        ), DATA_TYPE_STRING ) );
		m_ctrlOutBlock.SetItemText(  8, 1, GetDispData( pOutBlock->induname  , sizeof( pOutBlock->induname       ), DATA_TYPE_STRING ) );
		m_ctrlOutBlock.SetItemText(  9, 1, GetDispData( pOutBlock->floatpoint, sizeof( pOutBlock->floatpoint     ), DATA_TYPE_STRING ) );
		m_ctrlOutBlock.SetItemText( 10, 1, GetDispData( pOutBlock->currency  , sizeof( pOutBlock->currency       ), DATA_TYPE_STRING ) );
		m_ctrlOutBlock.SetItemText( 11, 1, GetDispData( pOutBlock->price     , sizeof( pOutBlock->price          ), DATA_TYPE_DOT, 6 ) );
		m_ctrlOutBlock.SetItemText( 12, 1, GetDispData( pOutBlock->sign      , sizeof( pOutBlock->sign           ), DATA_TYPE_STRING ) );
		m_ctrlOutBlock.SetItemText( 13, 1, GetDispData( pOutBlock->diff      , sizeof( pOutBlock->diff           ), DATA_TYPE_DOT, 6 ) );
		m_ctrlOutBlock.SetItemText( 14, 1, GetDispData( pOutBlock->rate      , sizeof( pOutBlock->rate           ), DATA_TYPE_FLOAT, 2 ) );
		m_ctrlOutBlock.SetItemText( 15, 1, GetDispData( pOutBlock->volume    , sizeof( pOutBlock->volume         ), DATA_TYPE_LONG   ) );
		m_ctrlOutBlock.SetItemText( 16, 1, GetDispData( pOutBlock->amount    , sizeof( pOutBlock->amount         ), DATA_TYPE_LONG   ) );
		m_ctrlOutBlock.SetItemText( 17, 1, GetDispData( pOutBlock->high52p   , sizeof( pOutBlock->high52p        ), DATA_TYPE_DOT, 6   ) );
		m_ctrlOutBlock.SetItemText( 18, 1, GetDispData( pOutBlock->low52p    , sizeof( pOutBlock->low52p         ), DATA_TYPE_DOT, 6   ) );
		m_ctrlOutBlock.SetItemText( 19, 1, GetDispData( pOutBlock->uplimit   , sizeof( pOutBlock->uplimit        ), DATA_TYPE_DOT, 6   ) );
		m_ctrlOutBlock.SetItemText( 20, 1, GetDispData( pOutBlock->dnlimit   , sizeof( pOutBlock->dnlimit        ), DATA_TYPE_DOT, 6   ) );
		m_ctrlOutBlock.SetItemText( 21, 1, GetDispData( pOutBlock->open      , sizeof( pOutBlock->open           ), DATA_TYPE_DOT, 6   ) );
		m_ctrlOutBlock.SetItemText( 22, 1, GetDispData( pOutBlock->high      , sizeof( pOutBlock->high           ), DATA_TYPE_DOT, 6   ) );
		m_ctrlOutBlock.SetItemText( 23, 1, GetDispData( pOutBlock->low       , sizeof( pOutBlock->low            ), DATA_TYPE_DOT, 6   ) );
		m_ctrlOutBlock.SetItemText( 24, 1, GetDispData( pOutBlock->perv      , sizeof( pOutBlock->perv           ), DATA_TYPE_DOT, 2   ) );
		m_ctrlOutBlock.SetItemText( 25, 1, GetDispData( pOutBlock->epsv      , sizeof( pOutBlock->epsv           ), DATA_TYPE_DOT, 2   ) );
	}
	
	//-------------------------------------------------------------------------------------
	// �޽����� ����
	else if( wParam == MESSAGE_DATA )
	{
		LPMSG_PACKET pMsg = (LPMSG_PACKET)lParam;

		CString strMsg( (char*)pMsg->lpszMessageData, pMsg->nMsgLength );
		GetParent()->SendMessage( WMU_SET_MESSAGE, (WPARAM)pMsg->szMsgCode, (LPARAM)(LPCTSTR)strMsg );		
		
		g_iXingAPI.ReleaseMessageData( lParam );
	}
	
	//-------------------------------------------------------------------------------------
	// System Error�� ����
	else if( wParam == SYSTEM_ERROR_DATA )
	{
		LPMSG_PACKET pMsg = (LPMSG_PACKET)lParam;
		
		CString strMsg( (char*)pMsg->lpszMessageData, pMsg->nMsgLength );
		GetParent()->SendMessage( WMU_SET_MESSAGE, (WPARAM)pMsg->szMsgCode, (LPARAM)(LPCTSTR)strMsg );		

		g_iXingAPI.ReleaseMessageData( lParam );
	}

	//-------------------------------------------------------------------------------------
	// Release Data�� ����
	else if( wParam == RELEASE_DATA )
	{
		g_iXingAPI.ReleaseRequestData( (int)lParam );
	}

	return 0L;
}

//--------------------------------------------------------------------------------------
// Timeout �߻�
//--------------------------------------------------------------------------------------
LRESULT CDlg_g3101::OnXMTimeoutData( WPARAM wParam, LPARAM lParam )
{
	g_iXingAPI.ReleaseRequestData( (int)lParam );

	return 0L;
}