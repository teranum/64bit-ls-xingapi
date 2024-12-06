// Dlg_COSAQ00102.cpp : implementation file
//

#include "stdafx.h"
#include "xingapi_sample.h"
#include "Dlg_COSAQ00102.h"

#include "./Packet/COSAQ00102.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlg_COSAQ00102 dialog


IMPLEMENT_DYNCREATE(CDlg_COSAQ00102, CDialog)

	CDlg_COSAQ00102::CDlg_COSAQ00102(CWnd* pParent /*=NULL*/)
	: CDialog(CDlg_COSAQ00102::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlg_COSAQ00102)
	// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CDlg_COSAQ00102::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlg_COSAQ00102)
	// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
	DDX_Control(pDX, IDC_OUTBLOCK1, m_ctrlOutBlock1);
	DDX_Control(pDX, IDC_OUTBLOCK2, m_ctrlOutBlock2);
	DDX_Control(pDX, IDC_OUTBLOCK3, m_ctrlOutBlock3);
}


BEGIN_MESSAGE_MAP(CDlg_COSAQ00102, CDialog)
	//{{AFX_MSG_MAP(CDlg_COSAQ00102)
	// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
	ON_BN_CLICKED( IDC_BUTTON_REQUEST,		  OnButtonRequest	  )
	ON_BN_CLICKED( IDC_BUTTON_REQUEST_NEXT,	  OnButtonRequestNext )
	ON_MESSAGE	 ( WM_USER + XM_RECEIVE_DATA, OnXMReceiveData	  )
	ON_MESSAGE	 ( WM_USER + XM_TIMEOUT_DATA, OnXMTimeoutData	  )
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlg_COSAQ00102 message handlers

BOOL CDlg_COSAQ00102::OnInitDialog() 
{
	CDialog::OnInitDialog();

	InitCtrls();

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}

void CDlg_COSAQ00102::OnButtonRequest() 
{
	RequestData();
}

void CDlg_COSAQ00102::OnButtonRequestNext() 
{
	RequestData( TRUE );
}

//--------------------------------------------------------------------------------------
// ��Ʈ�� �ʱ�ȭ
//--------------------------------------------------------------------------------------
void CDlg_COSAQ00102::InitCtrls()
{
	int nCol;

	//-------------------------------------------------------------------------
	// InBlock : �⺻�� ����

	// ���¹�ȣ ����
	char szAccount[20];
	int nCount = g_iXingAPI.GetAccountListCount();
	for( int i=0; i<nCount; i++ )
	{
		if( g_iXingAPI.GetAccountList( i, szAccount, sizeof( szAccount ) ) )
		{
			((CComboBox*)GetDlgItem( IDC_INBLOCK_ACNTNO ))->AddString( szAccount );
		}	
	}
	((CComboBox*)GetDlgItem( IDC_INBLOCK_ACNTNO         ))->SetCurSel( 0 );	// ���¹�ȣ 

	//-------------------------------------------------------------------------
	// OutBlock1
	nCol = 0;
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "���ڵ尹��         ",	FALSE,   8 );   
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "��ȸ�����ڵ�       ",	TRUE ,   8 );    
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "���������ڵ�       ",	TRUE ,   8 );   
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "�ֹ������ڵ�       ",	TRUE ,   8 );   
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "���¹�ȣ           ",	TRUE ,   12 );    
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "��й�ȣ           ",	TRUE ,   8 );    
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "�Ÿű����ڵ�       ",	TRUE ,   8 );    
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "�����ȣ           ",	TRUE ,   12 );     
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "�����ֹ���ȣ       ",	FALSE,   8 );   
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "�ֹ�����           ",	TRUE ,   8 );    
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "ü�Ῡ��           ",	TRUE ,   6 );  
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "��ȭ�ڵ�           ",	TRUE ,   6 );  
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "���ϸŸ����뿩��    ",	TRUE ,   8 );  
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "�����ܰ�������    ",	TRUE ,   8 );    

	//-------------------------------------------------------------------------
	// OutBlock2
	nCol = 0;
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "���ڵ尹��           ",		FALSE ,	 8 );   
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "���¸�               ",		TRUE  , 20 );    
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "�Ϻ������ѱ������    ",		TRUE  , 50 );   
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "����������            ",	TRUE  , 20 );   
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "�ŵ�ü���ȭ�ݾ�      ",		FALSE , 15 );    
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "�ŵ�ü�����          ",	FALSE , 12 );    
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "�ż�ü���ȭ�ݾ�      ",		FALSE , 15 );    
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "�ż�ü�����         ",		FALSE ,	12 );   

	//-------------------------------------------------------------------------
	// OutBlock3
	nCol = 0;
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "����������ȣ         ",	TRUE ,	12	);
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "���¹�ȣ             ",	TRUE ,	12	);
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "���¸�               ",	TRUE ,	20	);
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "ü��ð�             ",	TRUE ,	8	);
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "�ֹ��ð�             ",	TRUE ,	8	);
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "�ֹ���ȣ             ",	FALSE,	12	);
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "���ֹ���ȣ           ",	FALSE,	12	);
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "���������ȣ         ", TRUE ,	12	);
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "�ֹ�ó��������       ", TRUE ,	25	);
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "�ֹ�ó�������ڵ�     ", TRUE ,	12	);
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "������Ұ��ɼ���     ",	FALSE,	12	);
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "�ֹ�����             ",	FALSE,  12	);
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "ü�����             ",	FALSE,  15	);
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "�ؿ�ü�ᰡ           ",	FALSE,  12	);
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "�ؿ��ֹ���           ",	FALSE,	18	);
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "ȣ�������ڵ�         ",	TRUE ,	8	);
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "ȣ��������           ",	TRUE ,  20	);
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "�ֹ�������           ",	TRUE ,  20	);
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "�ֹ������ڵ�         ",	TRUE ,  8	);
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "������ұ����ڵ�     ",	TRUE ,  8	);
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "������ұ��и�       ",	TRUE ,  10	);
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "��üü�����         ",	FALSE,  12	);
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "��Ÿ�ü�ڵ�         ",	FALSE,  8	);
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "�ֹ������ڵ�         ",	TRUE ,  8	);
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "�����               ",	TRUE ,  40	);
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "��Ÿ�ü��           ",	TRUE ,  40	);
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "�Ϻ������ѱ������    ",	TRUE ,  40	);
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "��ü�����           ",	TRUE ,  12	);
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "Ȯ�μ���             ",	TRUE ,  12	);
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "��ȭ�ڵ�             ",	TRUE ,  8	);
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "��Ͻ����ڵ�         ",	TRUE ,  8	);
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "�����ȣ             ",	TRUE ,  8	);
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "�߰��α����ڵ�       ",	TRUE ,  8	);
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "����߰��θ�         ",	TRUE ,  20	);
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "�Ÿű����ڵ�         ",	TRUE ,  8	);
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "��������             ",	TRUE ,  8	);
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "����ݾ�             ",	FALSE , 12	); 

	ZeroMemory( m_szContKey, sizeof( m_szContKey ) );
	GetDlgItem( IDC_BUTTON_REQUEST_NEXT )->EnableWindow( FALSE );
}

//--------------------------------------------------------------------------------------
// ������ ��ȸ
//--------------------------------------------------------------------------------------
void CDlg_COSAQ00102::RequestData( BOOL bNext )
{
	//-----------------------------------------------------------
	COSAQ00102InBlock1	pckInBlock;

	TCHAR			szTrNo[]		= "COSAQ00102";
	char			szNextKey[]		= "";

	//-----------------------------------------------------------
	// ������ ���

	CString strQryTpCode ;		GetDlgItemText( IDC_INBLOCK_QRYTPCODE     , strQryTpCode     );    // [string,    1] ��ȸ�����ڵ� 
	CString strBkseqTpCode;		GetDlgItemText( IDC_INBLOCK_BKSEQTPCODE   , strBkseqTpCode   );    // [string,    1] ���������ڵ�  
	CString strOrdMktCode ;		GetDlgItemText( IDC_INBLOCK_ORDMKTCODE    , strOrdMktCode    );    // [string,    2] �ֹ������ڵ� 
	CString strAcntNo     ;		GetDlgItemText( IDC_INBLOCK_ACNTNO        , strAcntNo        );    // [string,   20] ���¹�ȣ
	CString strInptPwd    ;		GetDlgItemText( IDC_INBLOCK_INPTPWD       , strInptPwd       );    // [string,    8] �Էº�й�ȣ 
	CString strBnsTpCode  ;		GetDlgItemText( IDC_INBLOCK_BNSTPCODE     , strBnsTpCode     );    // [string,    1] �Ÿű���     
	CString strIsuNo      ;		GetDlgItemText( IDC_INBLOCK_ISUNO         , strIsuNo         );    // [string,   12] �����ȣ     
	CString strSrtOrdNo  ;		GetDlgItemText( IDC_INBLOCK_SRTORDNO2     , strSrtOrdNo      );    // [long  ,   10] �����ֹ���ȣ
	CString strOrdDt      ;		GetDlgItemText( IDC_INBLOCK_ORDDT         , strOrdDt         );    // [string,    8] �ֹ�����      
	CString strExecYn     ;		GetDlgItemText( IDC_INBLOCK_EXECYN        , strExecYn        );    // [string,    1] ü�Ῡ�� 
	CString strCrcyCode;		GetDlgItemText( IDC_INBLOCK_CRCYCODE      , strCrcyCode      );    // [string,    3] ��ȭ�ڵ�     
	CString strThdayBnsAppYn ;	GetDlgItemText( IDC_INBLOCK_THDAYBNSAPPYN , strThdayBnsAppYn );    // [string,    1] ���ϸŸ����뿩�� 
	CString strLoanBalHldYn ;	GetDlgItemText( IDC_INBLOCK_LOANBALHLDYN  , strLoanBalHldYn  );    // [string,    1] �����ܰ������� 
	//-----------------------------------------------------------
	// ������ �ʱ�ȭ
	FillMemory( &pckInBlock, sizeof( pckInBlock ), ' ' );

	//-----------------------------------------------------------
	// ������ �Է�
	SetPacketData( pckInBlock.RecCnt        , sizeof( pckInBlock.RecCnt        ), "1"           , DATA_TYPE_LONG   );    // [long  ,    5] ���ڵ尹��
	SetPacketData( pckInBlock.QryTpCode     , sizeof( pckInBlock.QryTpCode     ) , strQryTpCode , DATA_TYPE_STRING );    // [string,    1] ��ȸ�����ڵ�
	SetPacketData( pckInBlock.BkseqTpCode   , sizeof( pckInBlock.BkseqTpCode   ), strBkseqTpCode, DATA_TYPE_STRING );    // [string,    1] ���������ڵ�
	SetPacketData( pckInBlock.OrdMktCode    , sizeof( pckInBlock.OrdMktCode    ), strOrdMktCode , DATA_TYPE_STRING );    // [string,    2] �ֹ������ڵ� 
	SetPacketData( pckInBlock.AcntNo        , sizeof( pckInBlock.AcntNo        ), strAcntNo     , DATA_TYPE_STRING );    // [string,   20] ���¹�ȣ    
	SetPacketData( pckInBlock.Pwd           , sizeof( pckInBlock.Pwd           ), strInptPwd    , DATA_TYPE_STRING );    // [string,    8] ��й�ȣ 
	SetPacketData( pckInBlock.BnsTpCode     , sizeof( pckInBlock.BnsTpCode     ), strBnsTpCode  , DATA_TYPE_STRING );    // [string,    1] �Ÿű���     
	SetPacketData( pckInBlock.IsuNo         , sizeof( pckInBlock.IsuNo         ), strIsuNo      , DATA_TYPE_STRING );    // [string,   12] �����ȣ   
	SetPacketData( pckInBlock.SrtOrdNo      , sizeof( pckInBlock.SrtOrdNo      ), strSrtOrdNo   , DATA_TYPE_LONG   );    // [long  ,   10] �����ֹ���ȣ
	SetPacketData( pckInBlock.OrdDt         , sizeof( pckInBlock.OrdDt         ), strOrdDt      , DATA_TYPE_STRING );    // [string,    8] �ֹ�����       
	SetPacketData( pckInBlock.ExecYn        , sizeof( pckInBlock.ExecYn        ), strExecYn     , DATA_TYPE_STRING );    // [string,    1] ü�Ῡ��     
	SetPacketData( pckInBlock.CrcyCode      , sizeof( pckInBlock.CrcyCode      ), strCrcyCode   , DATA_TYPE_STRING );    // [string,    3] ��ȭ�ڵ�
	SetPacketData( pckInBlock.ThdayBnsAppYn , sizeof( pckInBlock.ThdayBnsAppYn ), strThdayBnsAppYn , DATA_TYPE_STRING );    // [string,    1] ���ϸŸ����뿩�� 
	SetPacketData( pckInBlock.LoanBalHldYn  , sizeof( pckInBlock.LoanBalHldYn  ), strLoanBalHldYn , DATA_TYPE_STRING );    // [string,    1] �����ܰ������� 
	//-----------------------------------------------------------
	// ������ ����
	int nRqID = g_iXingAPI.Request( 
		GetSafeHwnd(),				// �����͸� ���� ������, XM_RECEIVE_DATA ���� �´�.
		szTrNo,						// TR ��ȣ
		&pckInBlock,				// InBlock ������
		sizeof( pckInBlock ),		// InBlock ������ ũ��
		bNext,						// ������ȸ ���� : ������ȸ�� ��쿡 �����Ѵ�.
		bNext ? m_szContKey : "",	// ������ȸ Key : Header Type�� B �� ��쿣 ���� ��ȸ�� ���� Next Key�� �־��ش�.
		30							// Timeout(��) : �ش� �ð�(��)���� �����Ͱ� ���� ������ Timeout�� �߻��Ѵ�. XM_TIMEOUT_DATA �޽����� �߻��Ѵ�.
		);

	m_ctrlOutBlock1.DeleteAllItems();
	m_ctrlOutBlock2.DeleteAllItems();
	if( bNext == FALSE )
	{
		m_ctrlOutBlock3.DeleteAllItems();
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
LRESULT CDlg_COSAQ00102::OnXMReceiveData( WPARAM wParam, LPARAM lParam )
{
	//-------------------------------------------------------------------------------------
	// Data�� ����
	if( wParam == REQUEST_DATA )
	{
		typedef struct
		{
			COSAQ00102OutBlock1	outBlock1;
			COSAQ00102OutBlock2	outBlock2;
			char				sCountOutBlock3[5];
			COSAQ00102OutBlock3	outBlock3[1];
		} COSAQ00102AllOutBlock, *LPCOSAQ00102AllOutBlock;

		LPRECV_PACKET			pRpData		 = (LPRECV_PACKET)lParam;
		LPCOSAQ00102AllOutBlock pAllOutBlock = (LPCOSAQ00102AllOutBlock)pRpData->lpData;
		int						nDataLength  = pRpData->nDataLength;
		int						nCol;
		int						nRow;
		int						nCount;
		char					szCount[6] = { 0 };

		// ����Ű�� �����Ѵ�.
		strcpy_s( m_szContKey, pRpData->szContKey );
		GetDlgItem( IDC_BUTTON_REQUEST_NEXT )->EnableWindow( pRpData->cCont[0] == 'Y' );

		//------------------------------------------------
		// OutBlock1

		// ���� ������ ũ�Ⱑ Block ũ�⺸�� �۴ٸ� ó������ �ʴ´�.
		nDataLength -= sizeof( COSAQ00102OutBlock1 );
		if( nDataLength < 0 )
		{
			return 0L;
		}

		nCol = 0;
		m_ctrlOutBlock1.InsertItem( 0, "" );

		m_ctrlOutBlock1.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock1.RecCnt       , sizeof( pAllOutBlock->outBlock1.RecCnt         ), DATA_TYPE_LONG   ) );   
		m_ctrlOutBlock1.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock1.QryTpCode    , sizeof( pAllOutBlock->outBlock1.QryTpCode      ), DATA_TYPE_STRING ) );  
		m_ctrlOutBlock1.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock1.BkseqTpCode  , sizeof( pAllOutBlock->outBlock1.BkseqTpCode    ), DATA_TYPE_STRING ) );  
		m_ctrlOutBlock1.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock1.OrdMktCode   , sizeof( pAllOutBlock->outBlock1.OrdMktCode     ), DATA_TYPE_STRING ) );   
		m_ctrlOutBlock1.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock1.AcntNo       , sizeof( pAllOutBlock->outBlock1.AcntNo         ), DATA_TYPE_STRING ) );    
		m_ctrlOutBlock1.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock1.Pwd          , sizeof( pAllOutBlock->outBlock1.Pwd            ), DATA_TYPE_STRING ) );   
		m_ctrlOutBlock1.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock1.BnsTpCode    , sizeof( pAllOutBlock->outBlock1.BnsTpCode      ), DATA_TYPE_STRING ) );  
		m_ctrlOutBlock1.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock1.IsuNo        , sizeof( pAllOutBlock->outBlock1.IsuNo          ), DATA_TYPE_STRING ) );         
		m_ctrlOutBlock1.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock1.SrtOrdNo     , sizeof( pAllOutBlock->outBlock1.SrtOrdNo       ), DATA_TYPE_LONG   ) );   
		m_ctrlOutBlock1.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock1.OrdDt        , sizeof( pAllOutBlock->outBlock1.OrdDt          ), DATA_TYPE_STRING ) );       
		m_ctrlOutBlock1.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock1.ExecYn       , sizeof( pAllOutBlock->outBlock1.ExecYn         ), DATA_TYPE_STRING ) );   
		m_ctrlOutBlock1.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock1.CrcyCode     , sizeof( pAllOutBlock->outBlock1.CrcyCode       ), DATA_TYPE_STRING ) ); 
		m_ctrlOutBlock1.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock1.ThdayBnsAppYn, sizeof( pAllOutBlock->outBlock1.ThdayBnsAppYn  ), DATA_TYPE_STRING ) ); 
		m_ctrlOutBlock1.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock1.LoanBalHldYn , sizeof( pAllOutBlock->outBlock1.LoanBalHldYn   ), DATA_TYPE_STRING ) ); 


		//------------------------------------------------
		// OutBlock2
		nDataLength -= sizeof( COSAQ00102OutBlock2 );
		if( nDataLength < 0 )
		{
			return 0L;
		}

		nCol = 0;
		m_ctrlOutBlock2.InsertItem( 0, "" );
		m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock2.RecCnt           , sizeof( pAllOutBlock->outBlock2.RecCnt            ), DATA_TYPE_LONG   ) );       
		m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock2.AcntNm           , sizeof( pAllOutBlock->outBlock2.AcntNm            ), DATA_TYPE_STRING ) );   
		m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock2.JpnMktHanglIsuNm , sizeof( pAllOutBlock->outBlock2.JpnMktHanglIsuNm  ), DATA_TYPE_STRING ) );        
		m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock2.MgmtBrnNm        , sizeof( pAllOutBlock->outBlock2.MgmtBrnNm         ), DATA_TYPE_STRING ) );     
		m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock2.SellExecFcurrAmt , sizeof( pAllOutBlock->outBlock2.SellExecFcurrAmt  ), DATA_TYPE_DOT, 4 ) );  
		m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock2.SellExecQty      , sizeof( pAllOutBlock->outBlock2.SellExecQty       ), DATA_TYPE_LONG   ) );     
		m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock2.BuyExecFcurrAmt  , sizeof( pAllOutBlock->outBlock2.BuyExecFcurrAmt   ), DATA_TYPE_DOT, 4 ) );        
		m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock2.BuyExecQty       , sizeof( pAllOutBlock->outBlock2.BuyExecQty        ), DATA_TYPE_LONG   ) );  

		//------------------------------------------------
		// OutBlock3

		// Count ���
		nDataLength -= 5;
		if( nDataLength < 0 )
		{
			return 0L;
		}

		CopyMemory( szCount, pAllOutBlock->sCountOutBlock3, 5 );
		nCount = atoi( szCount );

		// Data
		nDataLength -= sizeof( COSAQ00102OutBlock3 ) * nCount;
		if( nDataLength < 0 )
		{
			return 0L;
		}

		for( int i=0; i<nCount; i++ )
		{
			nCol = 0;
			nRow = m_ctrlOutBlock3.InsertItem( m_ctrlOutBlock3.GetItemCount(), "" );
			m_ctrlOutBlock3.SetItemText(  nRow, nCol++, GetDispData( pAllOutBlock->outBlock3[i].MgmtBrnNo                , sizeof( pAllOutBlock->outBlock3[i].MgmtBrnNo                ), DATA_TYPE_STRING ) );
			m_ctrlOutBlock3.SetItemText(  nRow, nCol++, GetDispData( pAllOutBlock->outBlock3[i].AcntNo                   , sizeof( pAllOutBlock->outBlock3[i].AcntNo                   ), DATA_TYPE_STRING ) );
			m_ctrlOutBlock3.SetItemText(  nRow, nCol++, GetDispData( pAllOutBlock->outBlock3[i].AcntNm                   , sizeof( pAllOutBlock->outBlock3[i].AcntNm                   ), DATA_TYPE_STRING ) );
			m_ctrlOutBlock3.SetItemText(  nRow, nCol++, GetDispData( pAllOutBlock->outBlock3[i].ExecTime                 , sizeof( pAllOutBlock->outBlock3[i].ExecTime                 ), DATA_TYPE_STRING ) );
			m_ctrlOutBlock3.SetItemText(  nRow, nCol++, GetDispData( pAllOutBlock->outBlock3[i].OrdTime                  , sizeof( pAllOutBlock->outBlock3[i].OrdTime                  ), DATA_TYPE_STRING ) );
			m_ctrlOutBlock3.SetItemText(  nRow, nCol++, GetDispData( pAllOutBlock->outBlock3[i].OrdNo                    , sizeof( pAllOutBlock->outBlock3[i].OrdNo                    ), DATA_TYPE_LONG ) );
			m_ctrlOutBlock3.SetItemText(  nRow, nCol++, GetDispData( pAllOutBlock->outBlock3[i].OrgOrdNo                 , sizeof( pAllOutBlock->outBlock3[i].OrgOrdNo                 ), DATA_TYPE_LONG ) );
			m_ctrlOutBlock3.SetItemText(  nRow, nCol++, GetDispData( pAllOutBlock->outBlock3[i].ShtnIsuNo                , sizeof( pAllOutBlock->outBlock3[i].ShtnIsuNo                ), DATA_TYPE_STRING ) );
			m_ctrlOutBlock3.SetItemText(  nRow, nCol++, GetDispData( pAllOutBlock->outBlock3[i].OrdTrxPtnNm              , sizeof( pAllOutBlock->outBlock3[i].OrdTrxPtnNm              ), DATA_TYPE_STRING ) );
			m_ctrlOutBlock3.SetItemText(  nRow, nCol++, GetDispData( pAllOutBlock->outBlock3[i].OrdTrxPtnCode            , sizeof( pAllOutBlock->outBlock3[i].OrdTrxPtnCode            ), DATA_TYPE_LONG ) );
			m_ctrlOutBlock3.SetItemText(  nRow, nCol++, GetDispData( pAllOutBlock->outBlock3[i].MrcAbleQty               , sizeof( pAllOutBlock->outBlock3[i].MrcAbleQty               ), DATA_TYPE_LONG ) );
			m_ctrlOutBlock3.SetItemText(  nRow, nCol++, GetDispData( pAllOutBlock->outBlock3[i].OrdQty                   , sizeof( pAllOutBlock->outBlock3[i].OrdQty                   ), DATA_TYPE_LONG ) );
			m_ctrlOutBlock3.SetItemText(  nRow, nCol++, GetDispData( pAllOutBlock->outBlock3[i].ExecQty                  , sizeof( pAllOutBlock->outBlock3[i].ExecQty                  ), DATA_TYPE_LONG ) );
			m_ctrlOutBlock3.SetItemText(  nRow, nCol++, GetDispData( pAllOutBlock->outBlock3[i].OvrsExecPrc              , sizeof( pAllOutBlock->outBlock3[i].OvrsExecPrc              ), DATA_TYPE_DOT, 7 ) );
			m_ctrlOutBlock3.SetItemText(  nRow, nCol++, GetDispData( pAllOutBlock->outBlock3[i].OvrsOrdPrc               , sizeof( pAllOutBlock->outBlock3[i].OvrsOrdPrc               ), DATA_TYPE_DOT, 7 ) );
			m_ctrlOutBlock3.SetItemText(  nRow, nCol++, GetDispData( pAllOutBlock->outBlock3[i].OrdprcPtnCode            , sizeof( pAllOutBlock->outBlock3[i].OrdprcPtnCode            ), DATA_TYPE_STRING ) );
			m_ctrlOutBlock3.SetItemText(  nRow, nCol++, GetDispData( pAllOutBlock->outBlock3[i].OrdprcPtnNm              , sizeof( pAllOutBlock->outBlock3[i].OrdprcPtnNm              ), DATA_TYPE_STRING ) );
			m_ctrlOutBlock3.SetItemText(  nRow, nCol++, GetDispData( pAllOutBlock->outBlock3[i].OrdPtnNm                 , sizeof( pAllOutBlock->outBlock3[i].OrdPtnNm                 ), DATA_TYPE_STRING ) );
			m_ctrlOutBlock3.SetItemText(  nRow, nCol++, GetDispData( pAllOutBlock->outBlock3[i].OrdPtnCode               , sizeof( pAllOutBlock->outBlock3[i].OrdPtnCode               ), DATA_TYPE_STRING ) );
			m_ctrlOutBlock3.SetItemText(  nRow, nCol++, GetDispData( pAllOutBlock->outBlock3[i].MrcTpCode                , sizeof( pAllOutBlock->outBlock3[i].MrcTpCode                ), DATA_TYPE_STRING ) );
			m_ctrlOutBlock3.SetItemText(  nRow, nCol++, GetDispData( pAllOutBlock->outBlock3[i].MrcTpNm                  , sizeof( pAllOutBlock->outBlock3[i].MrcTpNm                  ), DATA_TYPE_STRING ) );
			m_ctrlOutBlock3.SetItemText(  nRow, nCol++, GetDispData( pAllOutBlock->outBlock3[i].AllExecQty               , sizeof( pAllOutBlock->outBlock3[i].AllExecQty               ), DATA_TYPE_LONG ) );
			m_ctrlOutBlock3.SetItemText(  nRow, nCol++, GetDispData( pAllOutBlock->outBlock3[i].CommdaCode               , sizeof( pAllOutBlock->outBlock3[i].CommdaCode               ), DATA_TYPE_STRING ) );
			m_ctrlOutBlock3.SetItemText(  nRow, nCol++, GetDispData( pAllOutBlock->outBlock3[i].OrdMktCode               , sizeof( pAllOutBlock->outBlock3[i].OrdMktCode               ), DATA_TYPE_STRING ) );
			m_ctrlOutBlock3.SetItemText(  nRow, nCol++, GetDispData( pAllOutBlock->outBlock3[i].MktNm                    , sizeof( pAllOutBlock->outBlock3[i].MktNm                    ), DATA_TYPE_STRING ) );
			m_ctrlOutBlock3.SetItemText(  nRow, nCol++, GetDispData( pAllOutBlock->outBlock3[i].CommdaNm                 , sizeof( pAllOutBlock->outBlock3[i].CommdaNm                 ), DATA_TYPE_STRING ) );
			m_ctrlOutBlock3.SetItemText(  nRow, nCol++, GetDispData( pAllOutBlock->outBlock3[i].JpnMktHanglIsuNm         , sizeof( pAllOutBlock->outBlock3[i].JpnMktHanglIsuNm         ), DATA_TYPE_STRING ) );
			m_ctrlOutBlock3.SetItemText(  nRow, nCol++, GetDispData( pAllOutBlock->outBlock3[i].UnercQty                 , sizeof( pAllOutBlock->outBlock3[i].UnercQty                 ), DATA_TYPE_LONG ) );
			m_ctrlOutBlock3.SetItemText(  nRow, nCol++, GetDispData( pAllOutBlock->outBlock3[i].CnfQty                   , sizeof( pAllOutBlock->outBlock3[i].CnfQty                   ), DATA_TYPE_LONG ) );
			m_ctrlOutBlock3.SetItemText(  nRow, nCol++, GetDispData( pAllOutBlock->outBlock3[i].CrcyCode                 , sizeof( pAllOutBlock->outBlock3[i].CrcyCode                 ), DATA_TYPE_STRING ) );
			m_ctrlOutBlock3.SetItemText(  nRow, nCol++, GetDispData( pAllOutBlock->outBlock3[i].RegMktCode               , sizeof( pAllOutBlock->outBlock3[i].RegMktCode               ), DATA_TYPE_STRING ) );
			m_ctrlOutBlock3.SetItemText(  nRow, nCol++, GetDispData( pAllOutBlock->outBlock3[i].IsuNo                    , sizeof( pAllOutBlock->outBlock3[i].IsuNo                    ), DATA_TYPE_STRING ) );
			m_ctrlOutBlock3.SetItemText(  nRow, nCol++, GetDispData( pAllOutBlock->outBlock3[i].BrkTpCode                , sizeof( pAllOutBlock->outBlock3[i].BrkTpCode                ), DATA_TYPE_STRING ) );
			m_ctrlOutBlock3.SetItemText(  nRow, nCol++, GetDispData( pAllOutBlock->outBlock3[i].OppBrkNm                 , sizeof( pAllOutBlock->outBlock3[i].OppBrkNm                 ), DATA_TYPE_STRING ) );
			m_ctrlOutBlock3.SetItemText(  nRow, nCol++, GetDispData( pAllOutBlock->outBlock3[i].BnsTpCode                , sizeof( pAllOutBlock->outBlock3[i].BnsTpCode                ), DATA_TYPE_STRING ) );
			m_ctrlOutBlock3.SetItemText(  nRow, nCol++, GetDispData( pAllOutBlock->outBlock3[i].LoanDt                   , sizeof( pAllOutBlock->outBlock3[i].LoanDt                   ), DATA_TYPE_STRING ) );
			m_ctrlOutBlock3.SetItemText(  nRow, nCol++, GetDispData( pAllOutBlock->outBlock3[i].LoanAmt                  , sizeof( pAllOutBlock->outBlock3[i].LoanAmt                  ), DATA_TYPE_LONG ) );
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
LRESULT CDlg_COSAQ00102::OnXMTimeoutData( WPARAM wParam, LPARAM lParam )
{
	g_iXingAPI.ReleaseRequestData( (int)lParam );
	GetParent()->SendMessage( WMU_SET_MESSAGE, (WPARAM)"", (LPARAM)"Timeout" );		

	return 0L;
}
