// Dlg_t9941.cpp : implementation file
//

#include "stdafx.h"
#include "XingAPI_Sample.h"
#include "Dlg_t9941.h"

#include "./Packet/t9941.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlg_t9941 dialog

IMPLEMENT_DYNCREATE(CDlg_t9941, CDialog)


CDlg_t9941::CDlg_t9941(CWnd* pParent /*=NULL*/)
	: CDialog(CDlg_t9941::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlg_t9941)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CDlg_t9941::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlg_t9941)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
	DDX_Control(pDX, IDC_OUTBLOCK, m_ctrlOutBlock);
}


BEGIN_MESSAGE_MAP(CDlg_t9941, CDialog)
	//{{AFX_MSG_MAP(CDlg_t9941)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
	ON_BN_CLICKED( IDC_BUTTON_REQUEST,		  OnButtonRequest	  )
	ON_MESSAGE	 ( WM_USER + XM_RECEIVE_DATA, OnXMReceiveData	  )
	ON_MESSAGE	 ( WM_USER + XM_TIMEOUT_DATA, OnXMTimeoutData	  )
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlg_t9941 message handlers

BOOL CDlg_t9941::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	InitCtrls();
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CDlg_t9941::OnButtonRequest() 
{
	RequestData( FALSE );
}

//--------------------------------------------------------------------------------------
// ��Ʈ�� �ʱ�ȭ
//--------------------------------------------------------------------------------------
void CDlg_t9941::InitCtrls()
{
	//-------------------------------------------------------------------------
	// InBlock : �⺻�� ����
	
	((CComboBox*)GetDlgItem( IDC_INBLOCK_GUBUN ))->SetCurSel( 0 );	// ����

	//-----------------------------------------------------------
	// OutBlock
	m_ctrlOutBlock.InsertColumn( 0, "�����",   LVCFMT_LEFT,   150 );
	m_ctrlOutBlock.InsertColumn( 1, "�����ڵ�", LVCFMT_CENTER,  60 );
	m_ctrlOutBlock.InsertColumn( 2, "Ȯ���ڵ�", LVCFMT_CENTER, 100 );
}

//--------------------------------------------------------------------------------------
// ������ ��ȸ
//--------------------------------------------------------------------------------------
void CDlg_t9941::RequestData( BOOL bNext )
{
	//-----------------------------------------------------------
	// �ֽĸ�������ȸAPI��(t9941) ( block,headtype=A )
	t9941InBlock	pckInBlock;

	TCHAR			szTrNo[]	= "t9941";
	char			szNextKey[]	= "";

	//-----------------------------------------------------------
	// ������ ���
	CString str_gubun		; GetDlgItemText( IDC_INBLOCK_GUBUN	  , str_gubun		);		// ����

	// ComboBox���� �����°��� ������ �ڿ� ������ �پ����� �� �����Ƿ� ������ �����Ѵ�.
	if( str_gubun.GetLength() > sizeof( pckInBlock.gubun ) ) str_gubun = str_gubun.Left( sizeof( pckInBlock.gubun ) );
	
	//-----------------------------------------------------------
	// ������ �ʱ�ȭ
	FillMemory( &pckInBlock, sizeof( pckInBlock ), ' ' );
	
	//-----------------------------------------------------------
	// ������ �Է�
	SetPacketData( pckInBlock.gubun		 , sizeof( pckInBlock.gubun		 ), str_gubun		, DATA_TYPE_STRING );	// ����
	
	//-----------------------------------------------------------
	// ������ ����
	int nRqID = g_iXingAPI.Request( 
		GetSafeHwnd(),				// �����͸� ���� ������, XM_RECEIVE_DATA ���� �´�.
		szTrNo,						// TR ��ȣ
		&pckInBlock,				// InBlock ������
		sizeof( pckInBlock ),		// InBlock ������ ũ��
		bNext,						// ������ȸ ���� : ������ȸ�� ��쿡 �����Ѵ�.
		szNextKey,					// ������ȸ Key : //		Header Type�� B �� ��쿣 ���� ��ȸ�� ���� Next Key�� �־��ش�.
		30							// Timeout(��) : �ش� �ð�(��)���� �����Ͱ� ���� ������ Timeout�� �߻��Ѵ�. XM_TIMEOUT_DATA �޽����� �߻��Ѵ�.
	);

	if( bNext == FALSE )
	{
		m_ctrlOutBlock.DeleteAllItems();
	}

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
LRESULT CDlg_t9941::OnXMReceiveData( WPARAM wParam, LPARAM lParam )
{
	//-------------------------------------------------------------------------------------
	// Data�� ����
	if( wParam == REQUEST_DATA )
	{
		LPRECV_PACKET pRpData = (LPRECV_PACKET)lParam;

		int nDataLength = pRpData->nDataLength;

		LPt9941OutBlock pOutBlock = (LPt9941OutBlock)pRpData->lpData;

		// OutBlock ó��
		int nOutBlockCount = nDataLength / sizeof( t9941OutBlock );
		for( int i=0; i<nOutBlockCount; i++ )
		{
			m_ctrlOutBlock.InsertItem( i, "" );
			m_ctrlOutBlock.SetItemText( i,  0, GetDispData( pOutBlock[i].hname  , sizeof( pOutBlock[i].hname   ), DATA_TYPE_STRING ) );		// �����
			m_ctrlOutBlock.SetItemText( i,  1, GetDispData( pOutBlock[i].shcode , sizeof( pOutBlock[i].shcode  ), DATA_TYPE_STRING ) );		// �����ڵ�
			m_ctrlOutBlock.SetItemText( i,  2, GetDispData( pOutBlock[i].expcode, sizeof( pOutBlock[i].expcode ), DATA_TYPE_STRING ) );		// Ȯ���ڵ�
		}
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
LRESULT CDlg_t9941::OnXMTimeoutData( WPARAM wParam, LPARAM lParam )
{
	g_iXingAPI.ReleaseRequestData( (int)lParam );

	return 0L;
}