// Dlg_g3202.cpp : implementation file
//

#include "stdafx.h"
#include "XingAPI_Sample.h"
#include "Dlg_g3202.h"

#include "./Packet/g3202.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlg_g3202 dialog

IMPLEMENT_DYNCREATE(CDlg_g3202, CDialog)

CDlg_g3202::CDlg_g3202(CWnd* pParent /*=NULL*/)
	: CDialog(CDlg_g3202::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlg_g3202)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CDlg_g3202::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlg_g3202)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
	DDX_Control(pDX, IDC_OUTBLOCK, m_ctrlOutBlock);
	DDX_Control(pDX, IDC_OUTBLOCK1, m_ctrlOutBlock1);
}


BEGIN_MESSAGE_MAP(CDlg_g3202, CDialog)
	//{{AFX_MSG_MAP(CDlg_g3202)
	//}}AFX_MSG_MAP
	ON_BN_CLICKED( IDC_BUTTON_REQUEST,		  OnButtonRequest	  )
	ON_BN_CLICKED( IDC_BUTTON_REQUEST_NEXT,	  OnButtonRequestNext )
	ON_MESSAGE	 ( WM_USER + XM_RECEIVE_DATA, OnXMReceiveData	  )
	ON_MESSAGE	 ( WM_USER + XM_TIMEOUT_DATA, OnXMTimeoutData	  )
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlg_g3202 message handlers

BOOL CDlg_g3202::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	m_bCompress = FALSE;
	
	InitCtrls();
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CDlg_g3202::OnButtonRequest() 
{
	RequestData( FALSE );
}

void CDlg_g3202::OnButtonRequestNext() 
{
	RequestData( TRUE );	
}

//--------------------------------------------------------------------------------------
// ��Ʈ�� �ʱ�ȭ
//--------------------------------------------------------------------------------------
void CDlg_g3202::InitCtrls()
{
	//-----------------------------------------------------------
	// OutBlock
	m_ctrlOutBlock.InsertColumn( 0, "��������",				LVCFMT_RIGHT, 60 );
	m_ctrlOutBlock.InsertColumn( 1, "KEY�����ڵ�",			LVCFMT_RIGHT, 80 );
	m_ctrlOutBlock.InsertColumn( 2, "�ŷ����ڵ�",			LVCFMT_RIGHT, 80 );
	m_ctrlOutBlock.InsertColumn( 3, "�����ڵ�",				LVCFMT_RIGHT, 80 );
	m_ctrlOutBlock.InsertColumn( 4, "���ӽ�����",			LVCFMT_RIGHT, 100);
	m_ctrlOutBlock.InsertColumn( 5, "���ڵ�ī��Ʈ",			LVCFMT_RIGHT, 60 );
	m_ctrlOutBlock.InsertColumn( 6, "���Ͻð�",				LVCFMT_RIGHT, 80 );
	m_ctrlOutBlock.InsertColumn( 7, "���ϰ�",				LVCFMT_RIGHT, 80 );
	m_ctrlOutBlock.InsertColumn( 8, "��������",				LVCFMT_RIGHT, 80 );
	m_ctrlOutBlock.InsertColumn( 9, "��������",				LVCFMT_RIGHT, 80 );
	m_ctrlOutBlock.InsertColumn( 10, "���ϰŷ���",			LVCFMT_RIGHT, 80 );
	m_ctrlOutBlock.InsertColumn( 11, "���Ͻð�",			LVCFMT_RIGHT, 80 );
	m_ctrlOutBlock.InsertColumn( 12, "���ϰ�",			LVCFMT_RIGHT, 80 );
	m_ctrlOutBlock.InsertColumn( 13, "��������",			LVCFMT_RIGHT, 80 );
	m_ctrlOutBlock.InsertColumn( 14, "��������",			LVCFMT_RIGHT, 80 );
	m_ctrlOutBlock.InsertColumn( 15, "����۽ð�(HHMMSS)",	LVCFMT_RIGHT, 60 );
	m_ctrlOutBlock.InsertColumn( 16, "������ð�(HHMMSS)",	LVCFMT_RIGHT, 60 );
	m_ctrlOutBlock.InsertColumn( 17, "������Tick�Ǽ�",		LVCFMT_RIGHT, 60 );
	m_ctrlOutBlock.InsertColumn( 18, "����",					LVCFMT_RIGHT, 40 );

	//-----------------------------------------------------------
	// OutBlock1
	m_ctrlOutBlock1.InsertColumn(  0, "��¥",								LVCFMT_LEFT  , 60 );
	m_ctrlOutBlock1.InsertColumn(  1, "�����ð�",							LVCFMT_RIGHT , 60 );
	m_ctrlOutBlock1.InsertColumn(  2, "�ð�",								LVCFMT_RIGHT , 80 );
	m_ctrlOutBlock1.InsertColumn(  3, "��",								LVCFMT_RIGHT , 80 );
	m_ctrlOutBlock1.InsertColumn(  4, "����",								LVCFMT_RIGHT , 80 );
	m_ctrlOutBlock1.InsertColumn(  5, "����",								LVCFMT_RIGHT , 80 );
	m_ctrlOutBlock1.InsertColumn(  6, "ü�ᷮ",							LVCFMT_RIGHT , 60 );
	m_ctrlOutBlock1.InsertColumn(  7, "��������",							LVCFMT_RIGHT , 60 );
	m_ctrlOutBlock1.InsertColumn(  8, "��������",							LVCFMT_RIGHT , 60 );
	m_ctrlOutBlock1.InsertColumn(  9, "�����ְ��ݿ��׸�",						LVCFMT_RIGHT , 60 );
	m_ctrlOutBlock1.InsertColumn(  10, "�����������(1:����2:���3:����",		LVCFMT_LEFT  , 60 );
}

//--------------------------------------------------------------------------------------
// ������ ��ȸ
//--------------------------------------------------------------------------------------
void CDlg_g3202::RequestData( BOOL bNext )
{
	//-----------------------------------------------------------
	// �ֽ����簡ȣ����ȸ(g3202) ( attr,block,headtype=A )
	g3202InBlock	pckInBlock;

	TCHAR			szTrNo[]	= "g3202";
	char			szNextKey[]	= "";

	//-----------------------------------------------------------
	// ������ ���
	CString str_delaygb   ; GetDlgItemText( IDC_INBLOCK_DELAYGB      , str_delaygb      );		// ��������
	CString str_keysymbol ; GetDlgItemText( IDC_INBLOCK_KEYSYMBOL    , str_keysymbol	);		// KEY�����ڵ�
	CString str_exchcd    ; GetDlgItemText( IDC_INBLOCK_EXCHCD       , str_exchcd       );		// �ŷ����ڵ�
	CString str_symbol    ; GetDlgItemText( IDC_INBLOCK_SYMBOL		 , str_symbol		);		// �����ڵ�
	CString str_ncnt      ; GetDlgItemText( IDC_INBLOCK_NCNT	     , str_ncnt		    );		// ����(Nƽ)
	CString str_qrycnt    ; GetDlgItemText( IDC_INBLOCK_QRYCNT	     , str_qrycnt		);		// ��û�Ǽ�
	CString str_sdate     ; GetDlgItemText( IDC_INBLOCK_SDATE	     , str_sdate		);		// ��������
	CString str_edate     ; GetDlgItemText( IDC_INBLOCK_EDATE	     , str_edate		);		// ��������
	CString str_cts_seq    ; GetDlgItemText( IDC_INBLOCK_CTS_SEQ	 , str_cts_seq		);		// ���ӽ�����
	// ���࿩��(Y:����N:�����)       
	m_bCompress = GetCheckedRadioButton( IDC_RD_COMPRESS, IDC_RD_DECOMPRESS ) == IDC_RD_COMPRESS ? TRUE : FALSE;

	CString str_comp_yn; 
	str_comp_yn = ( m_bCompress == TRUE ? "Y" : "N" );


	// ���� ��ȸ�ϰ�쿡 ���� ��ȸ�� ����ϴ� Field�� �����͸� ������ �ȵȴ�.
	if( bNext == FALSE )
	{
		str_cts_seq = "";
	}
	
	//-----------------------------------------------------------
	// ������ �ʱ�ȭ
	FillMemory( &pckInBlock, sizeof( pckInBlock ), ' ' );
	
	//-----------------------------------------------------------
	// ������ �Է�
	SetPacketData( pckInBlock.delaygb	, sizeof( pckInBlock.delaygb	), str_delaygb   , DATA_TYPE_STRING );	// ��������
	SetPacketData( pckInBlock.keysymbol	, sizeof( pckInBlock.keysymbol	), str_keysymbol , DATA_TYPE_STRING );	// KEY�����ڵ�
	SetPacketData( pckInBlock.exchcd	, sizeof( pckInBlock.exchcd		), str_exchcd    , DATA_TYPE_STRING );	// �ŷ����ڵ�
	SetPacketData( pckInBlock.symbol	, sizeof( pckInBlock.symbol		), str_symbol	 , DATA_TYPE_STRING );	// �����ڵ�
	SetPacketData( pckInBlock.ncnt		, sizeof( pckInBlock.ncnt		), str_ncnt		 , DATA_TYPE_LONG );	// ����(Nƽ)
	SetPacketData( pckInBlock.qrycnt	, sizeof( pckInBlock.qrycnt		), str_qrycnt	 , DATA_TYPE_LONG );	// ��û�Ǽ�
	SetPacketData( pckInBlock.sdate		, sizeof( pckInBlock.sdate      ), str_sdate	 , DATA_TYPE_STRING );	// ���࿩��(Y:����N:�����)
	SetPacketData( pckInBlock.edate		, sizeof( pckInBlock.edate	    ), str_edate	 , DATA_TYPE_STRING );	// ��������
	SetPacketData( pckInBlock.cts_seq   , sizeof( pckInBlock.cts_seq    ), str_cts_seq   , DATA_TYPE_LONG );	// ��������
	SetPacketData( pckInBlock.comp_yn   , sizeof( pckInBlock.comp_yn    ), str_comp_yn   , DATA_TYPE_STRING );	// ���ӽ�����

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
LRESULT CDlg_g3202::OnXMReceiveData( WPARAM wParam, LPARAM lParam )
{
	//-------------------------------------------------------------------------------------
	// Data�� ����
	if( wParam == REQUEST_DATA )
	{
		LPRECV_PACKET pRpData = (LPRECV_PACKET)lParam;

		// Header�� A Type �� ��쿡�� Block ���� ���´�.
		if( strcmp( pRpData->szBlockName, NAME_g3202OutBlock ) == 0 )
		{
			LPg3202OutBlock pOutBlock = (LPg3202OutBlock)pRpData->lpData;
			m_ctrlOutBlock.InsertItem( 0, "" );
			m_ctrlOutBlock.SetItemText(  0, 0, GetDispData( pOutBlock->delaygb ,	sizeof( pOutBlock->delaygb		), DATA_TYPE_STRING ) );
			m_ctrlOutBlock.SetItemText(  0, 1, GetDispData( pOutBlock->keysymbol ,	sizeof( pOutBlock->keysymbol	), DATA_TYPE_STRING ) );
			m_ctrlOutBlock.SetItemText(  0, 2, GetDispData( pOutBlock->exchcd ,		sizeof( pOutBlock->exchcd		), DATA_TYPE_STRING ) );
			m_ctrlOutBlock.SetItemText(  0, 3, GetDispData( pOutBlock->symbol ,		sizeof( pOutBlock->symbol		), DATA_TYPE_STRING ) );
			m_ctrlOutBlock.SetItemText(  0, 4, GetDispData( pOutBlock->cts_seq ,	sizeof( pOutBlock->cts_seq      ), DATA_TYPE_LONG ) );
			m_ctrlOutBlock.SetItemText(  0, 5, GetDispData( pOutBlock->rec_count ,	sizeof( pOutBlock->rec_count    ), DATA_TYPE_LONG ) );
			m_ctrlOutBlock.SetItemText(  0, 6, GetDispData( pOutBlock->preopen ,	sizeof( pOutBlock->preopen		), DATA_TYPE_DOT, 8 ) );
			m_ctrlOutBlock.SetItemText(  0, 7, GetDispData( pOutBlock->prehigh ,	sizeof( pOutBlock->prehigh		), DATA_TYPE_DOT, 8 ) );
			m_ctrlOutBlock.SetItemText(  0, 8, GetDispData( pOutBlock->prelow ,		sizeof( pOutBlock->prelow		), DATA_TYPE_DOT, 8 ) );
			m_ctrlOutBlock.SetItemText(  0, 9, GetDispData( pOutBlock->preclose ,	sizeof( pOutBlock->preclose     ), DATA_TYPE_DOT, 8 ) );
			m_ctrlOutBlock.SetItemText(  0, 10, GetDispData( pOutBlock->prevolume ,	sizeof( pOutBlock->prevolume    ), DATA_TYPE_LONG ) );
			m_ctrlOutBlock.SetItemText(  0, 11, GetDispData( pOutBlock->open ,		sizeof( pOutBlock->open		    ), DATA_TYPE_DOT, 8 ) );
			m_ctrlOutBlock.SetItemText(  0, 12, GetDispData( pOutBlock->high ,		sizeof( pOutBlock->high         ), DATA_TYPE_DOT, 8 ) );
			m_ctrlOutBlock.SetItemText(  0, 13, GetDispData( pOutBlock->low ,		sizeof( pOutBlock->low          ), DATA_TYPE_DOT, 8 ) );
			m_ctrlOutBlock.SetItemText(  0, 14, GetDispData( pOutBlock->close ,		sizeof( pOutBlock->close		), DATA_TYPE_DOT, 8 ) );
			m_ctrlOutBlock.SetItemText(  0, 15, GetDispData( pOutBlock->s_time ,	sizeof( pOutBlock->s_time		), DATA_TYPE_STRING ) );
			m_ctrlOutBlock.SetItemText(  0, 16, GetDispData( pOutBlock->e_time ,	sizeof( pOutBlock->e_time		), DATA_TYPE_STRING ) );
			m_ctrlOutBlock.SetItemText(  0, 17, GetDispData( pOutBlock->last_count ,sizeof( pOutBlock->last_count   ), DATA_TYPE_STRING ) );
			m_ctrlOutBlock.SetItemText(  0, 18, GetDispData( pOutBlock->timediff ,  sizeof( pOutBlock->timediff     ), DATA_TYPE_STRING ) );
		}
		else if( strcmp( pRpData->szBlockName, NAME_g3202OutBlock1 ) == 0 )
		{
			LPg3202OutBlock1 pOutBlock1 = (LPg3202OutBlock1)pRpData->lpData;

			int nDataLength = pRpData->nDataLength;
			int nCount = 0;

			g3202OutBlock1 szOutBlock1[2000];

			if( m_bCompress == TRUE)
			{
				nDataLength = g_iXingAPI.Decompress( (char *)pOutBlock1, (char *)&szOutBlock1[0], nDataLength );
				if (nDataLength  > 0)
				{
					nCount = nDataLength / sizeof( g3202OutBlock1 );
					pOutBlock1 = &szOutBlock1[0];
				}
			}
			else
			{
					nCount = nDataLength / sizeof( g3202OutBlock1 );
			}

			// Occurs �� ���
			// Header�� 'A' �̸� ��ü���̿��� OutBlock�� ���̸� ������ ������ ���Ѵ�.
			for( int i=0; i< nCount ; i++ )
			{
				m_ctrlOutBlock1.InsertItem( i, "" );
				m_ctrlOutBlock1.SetItemText( i,  0, GetDispData( pOutBlock1[i].date		, sizeof( pOutBlock1[i].date       ), DATA_TYPE_STRING ) );		// ��¥               
				m_ctrlOutBlock1.SetItemText( i,  1, GetDispData( pOutBlock1[i].loctime	, sizeof( pOutBlock1[i].loctime    ), DATA_TYPE_STRING ) );		// �ð�               
				m_ctrlOutBlock1.SetItemText( i,  2, GetDispData( pOutBlock1[i].open		, sizeof( pOutBlock1[i].open       ), DATA_TYPE_DOT, 8 ) );		// �ð�               
				m_ctrlOutBlock1.SetItemText( i,  3, GetDispData( pOutBlock1[i].high		, sizeof( pOutBlock1[i].high       ), DATA_TYPE_DOT, 8 ) );		// ��               
				m_ctrlOutBlock1.SetItemText( i,  4, GetDispData( pOutBlock1[i].low		, sizeof( pOutBlock1[i].low		   ), DATA_TYPE_DOT, 8 ) );		// ����               
				m_ctrlOutBlock1.SetItemText( i,  5, GetDispData( pOutBlock1[i].close	, sizeof( pOutBlock1[i].close      ), DATA_TYPE_DOT, 8 ) );		// ����               
				m_ctrlOutBlock1.SetItemText( i,  6, GetDispData( pOutBlock1[i].exevol   , sizeof( pOutBlock1[i].exevol     ), DATA_TYPE_LONG ) );		// �ŷ���             
				m_ctrlOutBlock1.SetItemText( i,  7, GetDispData( pOutBlock1[i].jongchk  , sizeof( pOutBlock1[i].jongchk    ), DATA_TYPE_LONG ) );		// ��������           
				m_ctrlOutBlock1.SetItemText( i,  8, GetDispData( pOutBlock1[i].prtt_rate, sizeof( pOutBlock1[i].prtt_rate  ), DATA_TYPE_DOT, 2 ) );		// ��������           
				m_ctrlOutBlock1.SetItemText( i,  9, GetDispData( pOutBlock1[i].pricechk , sizeof( pOutBlock1[i].pricechk   ), DATA_TYPE_LONG ) );		// �����ְ��ݿ��׸�   
				m_ctrlOutBlock1.SetItemText( i,  10, GetDispData( pOutBlock1[i].sign    , sizeof( pOutBlock1[i].sign       ), DATA_TYPE_STRING ) );		// �����ְ��ݿ��׸�   
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
LRESULT CDlg_g3202::OnXMTimeoutData( WPARAM wParam, LPARAM lParam )
{
	g_iXingAPI.ReleaseRequestData( (int)lParam );

	return 0L;
}