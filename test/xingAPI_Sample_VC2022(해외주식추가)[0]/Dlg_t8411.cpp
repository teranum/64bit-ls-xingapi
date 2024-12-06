// Dlg_t8411.cpp : implementation file
//

#include "stdafx.h"
#include "XingAPI_Sample.h"
#include "Dlg_t8411.h"

#include "./Packet/t8411.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlg_t8411 dialog

IMPLEMENT_DYNCREATE(CDlg_t8411, CDialog)

CDlg_t8411::CDlg_t8411(CWnd* pParent /*=NULL*/)
	: CDialog(CDlg_t8411::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlg_t8411)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CDlg_t8411::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlg_t8411)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
	DDX_Control(pDX, IDC_OUTBLOCK, m_ctrlOutBlock);
	DDX_Control(pDX, IDC_OUTBLOCK1, m_ctrlOutBlock1);
}


BEGIN_MESSAGE_MAP(CDlg_t8411, CDialog)
	//{{AFX_MSG_MAP(CDlg_t8411)
	//}}AFX_MSG_MAP
	ON_BN_CLICKED( IDC_BUTTON_REQUEST,		  OnButtonRequest	  )
	ON_BN_CLICKED( IDC_BUTTON_REQUEST_NEXT,	  OnButtonRequestNext )
	ON_MESSAGE	 ( WM_USER + XM_RECEIVE_DATA, OnXMReceiveData	  )
	ON_MESSAGE	 ( WM_USER + XM_TIMEOUT_DATA, OnXMTimeoutData	  )
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlg_t8411 message handlers

BOOL CDlg_t8411::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	m_bCompress = FALSE;
	
	InitCtrls();
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CDlg_t8411::OnButtonRequest() 
{
	RequestData( FALSE );
}

void CDlg_t8411::OnButtonRequestNext() 
{
	RequestData( TRUE );	
}

//--------------------------------------------------------------------------------------
// ��Ʈ�� �ʱ�ȭ
//--------------------------------------------------------------------------------------
void CDlg_t8411::InitCtrls()
{
	//-----------------------------------------------------------
	// OutBlock
	m_ctrlOutBlock.InsertColumn( 0, "�����ڵ�",		LVCFMT_LEFT, 50 );
	m_ctrlOutBlock.InsertColumn( 1, "���Ͻð�",		LVCFMT_RIGHT, 50 );
	m_ctrlOutBlock.InsertColumn( 2, "���ϰ�",		LVCFMT_RIGHT, 50 );
	m_ctrlOutBlock.InsertColumn( 3, "��������",		LVCFMT_RIGHT, 50 );
	m_ctrlOutBlock.InsertColumn( 4, "��������",		LVCFMT_RIGHT, 50 );
	m_ctrlOutBlock.InsertColumn( 5, "���ϰŷ���",	LVCFMT_RIGHT, 50 );
	m_ctrlOutBlock.InsertColumn( 6, "���Ͻð�",		LVCFMT_RIGHT, 50 );
	m_ctrlOutBlock.InsertColumn( 7, "���ϰ�",		LVCFMT_RIGHT, 50 );
	m_ctrlOutBlock.InsertColumn( 8, "��������",		LVCFMT_RIGHT, 50 );
	m_ctrlOutBlock.InsertColumn( 9, "��������",		LVCFMT_RIGHT, 50 );
	m_ctrlOutBlock.InsertColumn( 10, "���Ѱ�",		LVCFMT_RIGHT, 50 );
	m_ctrlOutBlock.InsertColumn( 11, "���Ѱ�",		LVCFMT_RIGHT, 50 );
	m_ctrlOutBlock.InsertColumn( 12, "��������",	LVCFMT_LEFT,  50 );
	m_ctrlOutBlock.InsertColumn( 13, "���ӽð�",	LVCFMT_RIGHT, 50 );
	m_ctrlOutBlock.InsertColumn( 14, "����۽ð�",	LVCFMT_RIGHT, 50 );
	m_ctrlOutBlock.InsertColumn( 15, "������ð�",	LVCFMT_RIGHT, 50 );
	m_ctrlOutBlock.InsertColumn( 16, "����ȣ��ó���ð�", LVCFMT_RIGHT, 50 );
	m_ctrlOutBlock.InsertColumn( 17, "���ڵ�ī��Ʈ", LVCFMT_RIGHT, 50 );

	//-----------------------------------------------------------
	// OutBlock1
	m_ctrlOutBlock1.InsertColumn(  0, "��¥",		LVCFMT_LEFT  , 50 );
	m_ctrlOutBlock1.InsertColumn(  1, "�ð�",		LVCFMT_RIGHT , 50 );
	m_ctrlOutBlock1.InsertColumn(  2, "�ð�",		LVCFMT_RIGHT , 50 );
	m_ctrlOutBlock1.InsertColumn(  3, "��",		LVCFMT_RIGHT , 50 );
	m_ctrlOutBlock1.InsertColumn(  4, "����",		LVCFMT_RIGHT , 50 );
	m_ctrlOutBlock1.InsertColumn(  5, "����",		LVCFMT_RIGHT , 50 );
	m_ctrlOutBlock1.InsertColumn(  6, "�ŷ���",		LVCFMT_RIGHT , 50 );
	m_ctrlOutBlock1.InsertColumn(  7, "��������",	LVCFMT_RIGHT , 50 );
	m_ctrlOutBlock1.InsertColumn(  8, "��������",	LVCFMT_RIGHT , 50 );
	m_ctrlOutBlock1.InsertColumn(  9, "�����ְ��ݿ��Ѹ�", LVCFMT_RIGHT , 50 );
}

//--------------------------------------------------------------------------------------
// ������ ��ȸ
//--------------------------------------------------------------------------------------
void CDlg_t8411::RequestData( BOOL bNext )
{
	//-----------------------------------------------------------
	// �ֽ����簡ȣ����ȸ(t1101) ( attr,block,headtype=A )
	t8411InBlock	pckInBlock;

	TCHAR			szTrNo[]	= "t8411";
	char			szNextKey[]	= "";

	//-----------------------------------------------------------
	// ������ ���
	CString str_shcode   ; GetDlgItemText( IDC_INBLOCK_SHCODE   , str_shcode    );		// �����ڵ� 
	CString str_ncnt     ; GetDlgItemText( IDC_INBLOCK_NCNT		, str_ncnt		);		// ����(nƽ)                     
	CString str_qrycnt   ; GetDlgItemText( IDC_INBLOCK_QRYCNT   , str_qrycnt    );		// ��û�Ǽ�(�ִ�-����:2000�����:500
	CString str_nday     ; GetDlgItemText( IDC_INBLOCK_NDAY		, str_nday		);		// ��ȸ�����ϼ�(0:�̻��1>=���)  ��   
	CString str_sdate    ; GetDlgItemText( IDC_INBLOCK_SDATE	, str_sdate		);		// ��������                       
	CString str_edate    ; GetDlgItemText( IDC_INBLOCK_EDATE	, str_edate		);		// �������� 
	CString str_cts_date ; GetDlgItemText( IDC_INBLOCK_CTS_DATE , str_cts_date	);		// �������� 
	CString str_cts_time ; GetDlgItemText( IDC_INBLOCK_CTS_TIME , str_cts_time	);		// ���ӽð�

	// ���࿩��(Y:����N:�����)       
	m_bCompress = GetCheckedRadioButton( IDC_RD_COMPRESS, IDC_RD_DECOMPRESS ) == IDC_RD_COMPRESS ? TRUE : FALSE;

	CString str_comp_yn; 
	str_comp_yn = ( m_bCompress == TRUE ? "Y" : "N" );


	// ���� ��ȸ�ϰ�쿡 ���� ��ȸ�� ����ϴ� Field�� �����͸� ������ �ȵȴ�.
	if( bNext == FALSE )
	{
		str_cts_date = "";
		str_cts_time = "";
	}
	
	//-----------------------------------------------------------
	// ������ �ʱ�ȭ
	FillMemory( &pckInBlock, sizeof( pckInBlock ), ' ' );
	
	//-----------------------------------------------------------
	// ������ �Է�
	SetPacketData( pckInBlock.shcode	, sizeof( pckInBlock.shcode		), str_shcode   , DATA_TYPE_STRING );	// �����ڵ�   
	SetPacketData( pckInBlock.ncnt		, sizeof( pckInBlock.ncnt		), str_ncnt		, DATA_TYPE_LONG );		// ����   
	SetPacketData( pckInBlock.qrycnt	, sizeof( pckInBlock.qrycnt		), str_qrycnt   , DATA_TYPE_LONG );		// ��û�Ǽ�   
	SetPacketData( pckInBlock.nday		, sizeof( pckInBlock.nday		), str_nday		, DATA_TYPE_STRING );	// ��ȸ�����ϼ�   
	SetPacketData( pckInBlock.sdate		, sizeof( pckInBlock.sdate		), str_sdate	, DATA_TYPE_STRING );	// ��������   
	SetPacketData( pckInBlock.edate		, sizeof( pckInBlock.edate		), str_edate	, DATA_TYPE_STRING );	// ��������   
	SetPacketData( pckInBlock.cts_date  , sizeof( pckInBlock.cts_date   ), str_cts_date , DATA_TYPE_STRING );	// ��������   
	SetPacketData( pckInBlock.cts_time  , sizeof( pckInBlock.cts_time	), str_cts_time , DATA_TYPE_STRING );	// ���ӽð�   
	SetPacketData( pckInBlock.comp_yn   , sizeof( pckInBlock.comp_yn    ), str_comp_yn  , DATA_TYPE_STRING );	// ���࿩��   

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
	
	if( bNext == FALSE )
	{
		m_ctrlOutBlock.DeleteAllItems();
		m_ctrlOutBlock1.DeleteAllItems();
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
LRESULT CDlg_t8411::OnXMReceiveData( WPARAM wParam, LPARAM lParam )
{
	//-------------------------------------------------------------------------------------
	// Data�� ����
	if( wParam == REQUEST_DATA )
	{
		LPRECV_PACKET pRpData = (LPRECV_PACKET)lParam;

		// Header�� A Type �� ��쿡�� Block ���� ���´�.
		if( strcmp( pRpData->szBlockName, NAME_t8411OutBlock ) == 0 )
		{
			LPt8411OutBlock pOutBlock = (LPt8411OutBlock)pRpData->lpData;
			m_ctrlOutBlock.InsertItem( 0, "" );
			m_ctrlOutBlock.SetItemText(  0, 0, GetDispData( pOutBlock->shcode ,		sizeof( pOutBlock->shcode		), DATA_TYPE_STRING ) );
			m_ctrlOutBlock.SetItemText(  0, 1, GetDispData( pOutBlock->jisiga ,		sizeof( pOutBlock->jisiga		), DATA_TYPE_LONG ) );
			m_ctrlOutBlock.SetItemText(  0, 2, GetDispData( pOutBlock->jihigh ,		sizeof( pOutBlock->jihigh		), DATA_TYPE_LONG ) );
			m_ctrlOutBlock.SetItemText(  0, 3, GetDispData( pOutBlock->jilow ,		sizeof( pOutBlock->jilow		), DATA_TYPE_LONG ) );
			m_ctrlOutBlock.SetItemText(  0, 4, GetDispData( pOutBlock->jiclose ,	sizeof( pOutBlock->jiclose      ), DATA_TYPE_LONG ) );
			m_ctrlOutBlock.SetItemText(  0, 5, GetDispData( pOutBlock->jivolume ,	sizeof( pOutBlock->jivolume     ), DATA_TYPE_LONG ) );
			m_ctrlOutBlock.SetItemText(  0, 6, GetDispData( pOutBlock->disiga ,		sizeof( pOutBlock->disiga		), DATA_TYPE_LONG ) );
			m_ctrlOutBlock.SetItemText(  0, 7, GetDispData( pOutBlock->dihigh ,		sizeof( pOutBlock->dihigh		), DATA_TYPE_LONG ) );
			m_ctrlOutBlock.SetItemText(  0, 8, GetDispData( pOutBlock->dilow ,		sizeof( pOutBlock->dilow		), DATA_TYPE_LONG ) );
			m_ctrlOutBlock.SetItemText(  0, 9, GetDispData( pOutBlock->diclose ,	sizeof( pOutBlock->diclose      ), DATA_TYPE_LONG ) );
			m_ctrlOutBlock.SetItemText(  0, 10, GetDispData( pOutBlock->highend ,	sizeof( pOutBlock->highend      ), DATA_TYPE_LONG ) );
			m_ctrlOutBlock.SetItemText(  0, 11, GetDispData( pOutBlock->lowend ,	sizeof( pOutBlock->lowend		), DATA_TYPE_LONG ) );
			m_ctrlOutBlock.SetItemText(  0, 12, GetDispData( pOutBlock->cts_date ,	sizeof( pOutBlock->cts_date     ), DATA_TYPE_STRING ) );
			m_ctrlOutBlock.SetItemText(  0, 13, GetDispData( pOutBlock->cts_time ,	sizeof( pOutBlock->cts_time     ), DATA_TYPE_STRING ) );
			m_ctrlOutBlock.SetItemText(  0, 14, GetDispData( pOutBlock->s_time ,	sizeof( pOutBlock->s_time		), DATA_TYPE_STRING ) );
			m_ctrlOutBlock.SetItemText(  0, 15, GetDispData( pOutBlock->e_time ,	sizeof( pOutBlock->e_time		), DATA_TYPE_STRING ) );
			m_ctrlOutBlock.SetItemText(  0, 16, GetDispData( pOutBlock->dshmin ,	sizeof( pOutBlock->dshmin		), DATA_TYPE_STRING ) );
			m_ctrlOutBlock.SetItemText(  0, 17, GetDispData( pOutBlock->rec_count , sizeof( pOutBlock->rec_count    ), DATA_TYPE_LONG ) );
		}
		else if( strcmp( pRpData->szBlockName, NAME_t8411OutBlock1 ) == 0 )
		{
			LPt8411OutBlock1 pOutBlock1 = (LPt8411OutBlock1)pRpData->lpData;

			int nDataLength = pRpData->nDataLength;
			int nCount = 0;

			t8411OutBlock1 szOutBlock1[2000];

			if( m_bCompress == TRUE)
			{
				nDataLength = g_iXingAPI.Decompress( (char *)pOutBlock1, (char *)&szOutBlock1[0], nDataLength );
				if (nDataLength  > 0)
				{
					nCount = nDataLength / sizeof( t8411OutBlock1 );
					pOutBlock1 = &szOutBlock1[0];
				}
			}
			else
			{
					nCount = nDataLength / sizeof( t8411OutBlock1 );
			}

			// Occurs �� ���
			// Header�� 'A' �̸� ��ü���̿��� OutBlock�� ���̸� ������ ������ ���Ѵ�.
			for( int i=0; i< nCount ; i++ )
			{
				m_ctrlOutBlock1.InsertItem( i, "" );
				m_ctrlOutBlock1.SetItemText( i,  0, GetDispData( pOutBlock1[i].date		, sizeof( pOutBlock1[i].date       ), DATA_TYPE_STRING ) );		// ��¥               
				m_ctrlOutBlock1.SetItemText( i,  1, GetDispData( pOutBlock1[i].time		, sizeof( pOutBlock1[i].time       ), DATA_TYPE_STRING ) );		// �ð�               
				m_ctrlOutBlock1.SetItemText( i,  2, GetDispData( pOutBlock1[i].open		, sizeof( pOutBlock1[i].open       ), DATA_TYPE_LONG ) );		// �ð�               
				m_ctrlOutBlock1.SetItemText( i,  3, GetDispData( pOutBlock1[i].high		, sizeof( pOutBlock1[i].high       ), DATA_TYPE_LONG ) );		// ��               
				m_ctrlOutBlock1.SetItemText( i,  4, GetDispData( pOutBlock1[i].low		, sizeof( pOutBlock1[i].low			), DATA_TYPE_LONG ) );		// ����               
				m_ctrlOutBlock1.SetItemText( i,  5, GetDispData( pOutBlock1[i].close	, sizeof( pOutBlock1[i].close       ), DATA_TYPE_LONG ) );		// ����               
				m_ctrlOutBlock1.SetItemText( i,  6, GetDispData( pOutBlock1[i].jdiff_vol, sizeof( pOutBlock1[i].jdiff_vol   ), DATA_TYPE_LONG ) );		// �ŷ���             
				m_ctrlOutBlock1.SetItemText( i,  7, GetDispData( pOutBlock1[i].jongchk  , sizeof( pOutBlock1[i].jongchk     ), DATA_TYPE_LONG ) );		// ��������           
				m_ctrlOutBlock1.SetItemText( i,  8, GetDispData( pOutBlock1[i].rate		, sizeof( pOutBlock1[i].rate		), DATA_TYPE_FLOAT ) );		// ��������           
				m_ctrlOutBlock1.SetItemText( i,  9, GetDispData( pOutBlock1[i].pricechk , sizeof( pOutBlock1[i].pricechk    ), DATA_TYPE_LONG ) );		// �����ְ��ݿ��׸�   
			}
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
LRESULT CDlg_t8411::OnXMTimeoutData( WPARAM wParam, LPARAM lParam )
{
	g_iXingAPI.ReleaseRequestData( (int)lParam );

	return 0L;
}