// Dlg_CSPAQ03700.cpp : implementation file
//

#include "stdafx.h"
#include "xingapi_sample.h"
#include "Dlg_CSPAQ03700.h"

#include "./Packet/CSPAQ13700.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlg_CSPAQ03700 dialog


IMPLEMENT_DYNCREATE(CDlg_CSPAQ03700, CDialog)

CDlg_CSPAQ03700::CDlg_CSPAQ03700(CWnd* pParent /*=NULL*/)
	: CDialog(CDlg_CSPAQ03700::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlg_CSPAQ03700)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CDlg_CSPAQ03700::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlg_CSPAQ03700)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
	DDX_Control(pDX, IDC_OUTBLOCK1, m_ctrlOutBlock1);
	DDX_Control(pDX, IDC_OUTBLOCK2, m_ctrlOutBlock2);
	DDX_Control(pDX, IDC_OUTBLOCK3, m_ctrlOutBlock3);
}


BEGIN_MESSAGE_MAP(CDlg_CSPAQ03700, CDialog)
	//{{AFX_MSG_MAP(CDlg_CSPAQ03700)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
	ON_BN_CLICKED( IDC_BUTTON_REQUEST,		  OnButtonRequest	  )
	ON_BN_CLICKED( IDC_BUTTON_REQUEST_NEXT,	  OnButtonRequestNext )
	ON_MESSAGE	 ( WM_USER + XM_RECEIVE_DATA, OnXMReceiveData	  )
	ON_MESSAGE	 ( WM_USER + XM_TIMEOUT_DATA, OnXMTimeoutData	  )
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlg_CSPAQ03700 message handlers

BOOL CDlg_CSPAQ03700::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	InitCtrls();
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CDlg_CSPAQ03700::OnButtonRequest() 
{
	RequestData();
}

void CDlg_CSPAQ03700::OnButtonRequestNext() 
{
	RequestData( TRUE );
}

//--------------------------------------------------------------------------------------
// ��Ʈ�� �ʱ�ȭ
//--------------------------------------------------------------------------------------
void CDlg_CSPAQ03700::InitCtrls()
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

	//-------------------------------------------------------------------------
	// OutBlock1
	nCol = 0;
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "���ڵ尹��   ", FALSE,    5 );    // [long  ,    5] ���ڵ尹��   
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "���¹�ȣ     ", TRUE ,   20 );    // [string,   20] ���¹�ȣ     
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "�Էº�й�ȣ ", TRUE ,    8 );    // [string,    8] �Էº�й�ȣ 
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "�ֹ������ڵ� ", TRUE ,    2 );    // [string,    2] �ֹ������ڵ� 
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "�Ÿű���     ", TRUE ,    1 );    // [string,    1] �Ÿű���     
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "�����ȣ     ", TRUE ,   12 );    // [string,   12] �����ȣ     
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "ü�Ῡ��     ", TRUE ,    1 );    // [string,    1] ü�Ῡ��     
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "�ֹ���       ", TRUE ,    8 );    // [string,    8] �ֹ���       
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "�����ֹ���ȣ2", FALSE,   10 );    // [long  ,   10] �����ֹ���ȣ2
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "��������     ", TRUE ,    1 );    // [string,    1] ��������     
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "�ֹ������ڵ� ", TRUE ,    2 );    // [string,    2] �ֹ������ڵ� 
	
	//-------------------------------------------------------------------------
	// OutBlock2
	nCol = 0;
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "���ڵ尹��  ", FALSE,    5 );    // [long  ,    5] ���ڵ尹��  
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "�ŵ�ü��ݾ�", FALSE,   16 );    // [long  ,   16] �ŵ�ü��ݾ�
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "�ż�ü��ݾ�", FALSE,   16 );    // [long  ,   16] �ż�ü��ݾ�
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "�ŵ�ü�����", FALSE,   16 );    // [long  ,   16] �ŵ�ü�����
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "�ż�ü�����", FALSE,   16 );    // [long  ,   16] �ż�ü�����
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "�ŵ��ֹ�����", FALSE,   16 );    // [long  ,   16] �ŵ��ֹ�����
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "�ż��ֹ�����", FALSE,   16 );    // [long  ,   16] �ż��ֹ�����
	
	//-------------------------------------------------------------------------
	// OutBlock3
	nCol = 0;
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "�ֹ���          ", TRUE ,    8 );    // [string,    8] �ֹ���          
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "����������ȣ    ", TRUE ,    3 );    // [string,    3] ����������ȣ    
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "�ֹ������ڵ�    ", TRUE ,    2 );    // [string,    2] �ֹ������ڵ�    
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "�ֹ���ȣ        ", FALSE,   10 );    // [long  ,   10] �ֹ���ȣ        
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "���ֹ���ȣ      ", FALSE,   10 );    // [long  ,   10] ���ֹ���ȣ      
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "�����ȣ        ", TRUE ,   12 );    // [string,   12] �����ȣ        
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "�����          ", TRUE ,   40 );    // [string,   40] �����          
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "�Ÿű���        ", TRUE ,    1 );    // [string,    1] �Ÿű���        
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "�Ÿű���        ", TRUE ,   10 );    // [string,   10] �Ÿű���        
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "�ֹ������ڵ�    ", TRUE ,    2 );    // [string,    2] �ֹ������ڵ�    
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "�ֹ�������      ", TRUE ,   40 );    // [string,   40] �ֹ�������      
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "�ֹ�ó�������ڵ�", FALSE,    9 );    // [long  ,    9] �ֹ�ó�������ڵ�
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "�ֹ�ó��������  ", TRUE ,   50 );    // [string,   50] �ֹ�ó��������  
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "������ұ���    ", TRUE ,    1 );    // [string,    1] ������ұ���    
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "������ұ��и�  ", TRUE ,   10 );    // [string,   10] ������ұ��и�  
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "������Ҽ���    ", FALSE,   16 );    // [long  ,   16] ������Ҽ���    
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "������Ұ��ɼ���", FALSE,   16 );    // [long  ,   16] ������Ұ��ɼ���
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "�ֹ�����        ", FALSE,   16 );    // [long  ,   16] �ֹ�����        
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "�ֹ�����        ", FALSE, 15.2 );    // [double, 15.2] �ֹ�����        
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "ü�����        ", FALSE,   16 );    // [long  ,   16] ü�����        
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "ü�ᰡ          ", FALSE, 15.2 );    // [double, 15.2] ü�ᰡ          
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "ü��ó���ð�    ", TRUE ,    9 );    // [string,    9] ü��ó���ð�    
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "����ü��ð�    ", TRUE ,    9 );    // [string,    9] ����ü��ð�    
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "ȣ�������ڵ�    ", TRUE ,    2 );    // [string,    2] ȣ�������ڵ�    
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "ȣ��������      ", TRUE ,   40 );    // [string,   40] ȣ��������      
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "�ֹ����Ǳ���    ", TRUE ,    1 );    // [string,    1] �ֹ����Ǳ���    
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "��üü�����    ", FALSE,   16 );    // [long  ,   16] ��üü�����    
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "��Ÿ�ü�ڵ�    ", TRUE ,    2 );    // [string,    2] ��Ÿ�ü�ڵ�    
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "��Ÿ�ü��      ", TRUE ,   40 );    // [string,   40] ��Ÿ�ü��      
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "ȸ����ȣ        ", TRUE ,    3 );    // [string,    3] ȸ����ȣ        
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "�����ֹ�����    ", TRUE ,    1 );    // [string,    1] �����ֹ�����    
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "������          ", TRUE ,    8 );    // [string,    8] ������          
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "�ֹ��ð�        ", TRUE ,    9 );    // [string,    9] �ֹ��ð�        
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "������ù�ȣ    ", TRUE ,   12 );    // [string,   12] ������ù�ȣ    
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "�ֹ���ID        ", TRUE ,   16 );    // [string,   16] �ֹ���ID        
	
	ZeroMemory( m_szContKey, sizeof( m_szContKey ) );
	GetDlgItem( IDC_BUTTON_REQUEST_NEXT )->EnableWindow( FALSE );
}

//--------------------------------------------------------------------------------------
// ������ ��ȸ
//--------------------------------------------------------------------------------------
void CDlg_CSPAQ03700::RequestData( BOOL bNext )
{
	//-----------------------------------------------------------
	CSPAQ13700InBlock1	pckInBlock;

	TCHAR			szTrNo[]		= "CSPAQ13700";
	char			szNextKey[]		= "";

	//-----------------------------------------------------------
	// ������ ���
    CString strAcntNo     ;		GetDlgItemText( IDC_INBLOCK_ACNTNO     , strAcntNo      );    // [string,   20] ���¹�ȣ     
    CString strInptPwd    ;		GetDlgItemText( IDC_INBLOCK_INPTPWD    , strInptPwd     );    // [string,    8] �Էº�й�ȣ 
    CString strOrdMktCode ;		GetDlgItemText( IDC_INBLOCK_ORDMKTCODE , strOrdMktCode  );    // [string,    2] �ֹ������ڵ� 
    CString strBnsTpCode  ;		GetDlgItemText( IDC_INBLOCK_BNSTPCODE  , strBnsTpCode   );    // [string,    1] �Ÿű���     
    CString strIsuNo      ;		GetDlgItemText( IDC_INBLOCK_ISUNO      , strIsuNo       );    // [string,   12] �����ȣ     
    CString strExecYn     ;		GetDlgItemText( IDC_INBLOCK_EXECYN     , strExecYn      );    // [string,    1] ü�Ῡ��     
    CString strOrdDt      ;		GetDlgItemText( IDC_INBLOCK_ORDDT      , strOrdDt       );    // [string,    8] �ֹ���       
    CString strSrtOrdNo2  ;		GetDlgItemText( IDC_INBLOCK_SRTORDNO2  , strSrtOrdNo2   );    // [long  ,   10] �����ֹ���ȣ2
    CString strBkseqTpCode;		GetDlgItemText( IDC_INBLOCK_BKSEQTPCODE, strBkseqTpCode );    // [string,    1] ��������     
    CString strOrdPtnCode ;		GetDlgItemText( IDC_INBLOCK_ORDPTNCODE , strOrdPtnCode  );    // [string,    2] �ֹ������ڵ� 

	//-----------------------------------------------------------
	// ������ �ʱ�ȭ
	FillMemory( &pckInBlock, sizeof( pckInBlock ), ' ' );

	//-----------------------------------------------------------
	// ������ �Է�
	SetPacketData( pckInBlock.RecCnt     , sizeof( pckInBlock.RecCnt      ), "1"           , DATA_TYPE_LONG   );    // [long  ,    5] ���ڵ尹��   
	SetPacketData( pckInBlock.AcntNo     , sizeof( pckInBlock.AcntNo      ), strAcntNo     , DATA_TYPE_STRING );    // [string,   20] ���¹�ȣ     
	SetPacketData( pckInBlock.InptPwd    , sizeof( pckInBlock.InptPwd     ), strInptPwd    , DATA_TYPE_STRING );    // [string,    8] �Էº�й�ȣ 
	SetPacketData( pckInBlock.OrdMktCode , sizeof( pckInBlock.OrdMktCode  ), strOrdMktCode , DATA_TYPE_STRING );    // [string,    2] �ֹ������ڵ� 
	SetPacketData( pckInBlock.BnsTpCode  , sizeof( pckInBlock.BnsTpCode   ), strBnsTpCode  , DATA_TYPE_STRING );    // [string,    1] �Ÿű���     
	SetPacketData( pckInBlock.IsuNo      , sizeof( pckInBlock.IsuNo       ), strIsuNo      , DATA_TYPE_STRING );    // [string,   12] �����ȣ     
	SetPacketData( pckInBlock.ExecYn     , sizeof( pckInBlock.ExecYn      ), strExecYn     , DATA_TYPE_STRING );    // [string,    1] ü�Ῡ��     
	SetPacketData( pckInBlock.OrdDt      , sizeof( pckInBlock.OrdDt       ), strOrdDt      , DATA_TYPE_STRING );    // [string,    8] �ֹ���       
	SetPacketData( pckInBlock.SrtOrdNo2  , sizeof( pckInBlock.SrtOrdNo2   ), strSrtOrdNo2  , DATA_TYPE_LONG   );    // [long  ,   10] �����ֹ���ȣ2
	SetPacketData( pckInBlock.BkseqTpCode, sizeof( pckInBlock.BkseqTpCode ), strBkseqTpCode, DATA_TYPE_STRING );    // [string,    1] ��������     
	SetPacketData( pckInBlock.OrdPtnCode , sizeof( pckInBlock.OrdPtnCode  ), strOrdPtnCode , DATA_TYPE_STRING );    // [string,    2] �ֹ������ڵ� 

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
LRESULT CDlg_CSPAQ03700::OnXMReceiveData( WPARAM wParam, LPARAM lParam )
{
	//-------------------------------------------------------------------------------------
	// Data�� ����
	if( wParam == REQUEST_DATA )
	{
		typedef struct
		{
			CSPAQ13700OutBlock1	outBlock1;
			CSPAQ13700OutBlock2	outBlock2;
			char				sCountOutBlock3[5];
			CSPAQ13700OutBlock3	outBlock3[1];
		} CSPAQ13700AllOutBlock, *LPCSPAQ13700AllOutBlock;

		LPRECV_PACKET			pRpData		 = (LPRECV_PACKET)lParam;
		LPCSPAQ13700AllOutBlock pAllOutBlock = (LPCSPAQ13700AllOutBlock)pRpData->lpData;
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
		nDataLength -= sizeof( CSPAQ13700OutBlock1 );
		if( nDataLength < 0 )
		{
			return 0L;
		}

		nCol = 0;
		m_ctrlOutBlock1.InsertItem( 0, "" );
		m_ctrlOutBlock1.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock1.RecCnt     , sizeof( pAllOutBlock->outBlock1.RecCnt      ), DATA_TYPE_LONG   ) );    // [long  ,    5] ���ڵ尹��   
		m_ctrlOutBlock1.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock1.AcntNo     , sizeof( pAllOutBlock->outBlock1.AcntNo      ), DATA_TYPE_STRING ) );    // [string,   20] ���¹�ȣ     
		m_ctrlOutBlock1.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock1.InptPwd    , sizeof( pAllOutBlock->outBlock1.InptPwd     ), DATA_TYPE_STRING ) );    // [string,    8] �Էº�й�ȣ 
		m_ctrlOutBlock1.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock1.OrdMktCode , sizeof( pAllOutBlock->outBlock1.OrdMktCode  ), DATA_TYPE_STRING ) );    // [string,    2] �ֹ������ڵ� 
		m_ctrlOutBlock1.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock1.BnsTpCode  , sizeof( pAllOutBlock->outBlock1.BnsTpCode   ), DATA_TYPE_STRING ) );    // [string,    1] �Ÿű���     
		m_ctrlOutBlock1.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock1.IsuNo      , sizeof( pAllOutBlock->outBlock1.IsuNo       ), DATA_TYPE_STRING ) );    // [string,   12] �����ȣ     
		m_ctrlOutBlock1.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock1.ExecYn     , sizeof( pAllOutBlock->outBlock1.ExecYn      ), DATA_TYPE_STRING ) );    // [string,    1] ü�Ῡ��     
		m_ctrlOutBlock1.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock1.OrdDt      , sizeof( pAllOutBlock->outBlock1.OrdDt       ), DATA_TYPE_STRING ) );    // [string,    8] �ֹ���       
		m_ctrlOutBlock1.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock1.SrtOrdNo2  , sizeof( pAllOutBlock->outBlock1.SrtOrdNo2   ), DATA_TYPE_LONG   ) );    // [long  ,   10] �����ֹ���ȣ2
		m_ctrlOutBlock1.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock1.BkseqTpCode, sizeof( pAllOutBlock->outBlock1.BkseqTpCode ), DATA_TYPE_STRING ) );    // [string,    1] ��������     
		m_ctrlOutBlock1.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock1.OrdPtnCode , sizeof( pAllOutBlock->outBlock1.OrdPtnCode  ), DATA_TYPE_STRING ) );    // [string,    2] �ֹ������ڵ� 
		
		//------------------------------------------------
		// OutBlock2
		nDataLength -= sizeof( CSPAQ13700OutBlock2 );
		if( nDataLength < 0 )
		{
			return 0L;
		}
		
		nCol = 0;
		m_ctrlOutBlock2.InsertItem( 0, "" );
		m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock2.RecCnt     , sizeof( pAllOutBlock->outBlock2.RecCnt      ), DATA_TYPE_LONG   ) );    // [long  ,    5] ���ڵ尹��       
		m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock2.SellExecAmt, sizeof( pAllOutBlock->outBlock2.SellExecAmt ), DATA_TYPE_LONG   ) );    // [long  ,   16] �ŵ�ü��ݾ�     
		m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock2.BuyExecAmt , sizeof( pAllOutBlock->outBlock2.BuyExecAmt  ), DATA_TYPE_LONG   ) );    // [long  ,   16] �ż�ü��ݾ�     
		m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock2.SellExecQty, sizeof( pAllOutBlock->outBlock2.SellExecQty ), DATA_TYPE_LONG   ) );    // [long  ,   16] �ŵ�ü�����     
		m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock2.BuyExecQty , sizeof( pAllOutBlock->outBlock2.BuyExecQty  ), DATA_TYPE_LONG   ) );    // [long  ,   16] �ż�ü�����     
		m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock2.SellOrdQty , sizeof( pAllOutBlock->outBlock2.SellOrdQty  ), DATA_TYPE_LONG   ) );    // [long  ,   16] �ŵ��ֹ�����     
		m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock2.BuyOrdQty  , sizeof( pAllOutBlock->outBlock2.BuyOrdQty   ), DATA_TYPE_LONG   ) );    // [long  ,   16] �ż��ֹ�����     
		
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
		nDataLength -= sizeof( CSPAQ13700OutBlock3 ) * nCount;
		if( nDataLength < 0 )
		{
			return 0L;
		}
		
		for( int i=0; i<nCount; i++ )
		{
			nCol = 0;
			nRow = m_ctrlOutBlock3.InsertItem( m_ctrlOutBlock3.GetItemCount(), "" );
			m_ctrlOutBlock3.SetItemText(  nRow, nCol++, GetDispData( pAllOutBlock->outBlock3[i].OrdDt        , sizeof( pAllOutBlock->outBlock3[i].OrdDt         ), DATA_TYPE_STRING ) );    // [string,    8] �ֹ���              
			m_ctrlOutBlock3.SetItemText(  nRow, nCol++, GetDispData( pAllOutBlock->outBlock3[i].MgmtBrnNo    , sizeof( pAllOutBlock->outBlock3[i].MgmtBrnNo     ), DATA_TYPE_STRING ) );    // [string,    3] ����������ȣ        
			m_ctrlOutBlock3.SetItemText(  nRow, nCol++, GetDispData( pAllOutBlock->outBlock3[i].OrdMktCode   , sizeof( pAllOutBlock->outBlock3[i].OrdMktCode    ), DATA_TYPE_STRING ) );    // [string,    2] �ֹ������ڵ�        
			m_ctrlOutBlock3.SetItemText(  nRow, nCol++, GetDispData( pAllOutBlock->outBlock3[i].OrdNo        , sizeof( pAllOutBlock->outBlock3[i].OrdNo         ), DATA_TYPE_LONG   ) );    // [long  ,   10] �ֹ���ȣ            
			m_ctrlOutBlock3.SetItemText(  nRow, nCol++, GetDispData( pAllOutBlock->outBlock3[i].OrgOrdNo     , sizeof( pAllOutBlock->outBlock3[i].OrgOrdNo      ), DATA_TYPE_LONG   ) );    // [long  ,   10] ���ֹ���ȣ          
			m_ctrlOutBlock3.SetItemText(  nRow, nCol++, GetDispData( pAllOutBlock->outBlock3[i].IsuNo        , sizeof( pAllOutBlock->outBlock3[i].IsuNo         ), DATA_TYPE_STRING ) );    // [string,   12] �����ȣ            
			m_ctrlOutBlock3.SetItemText(  nRow, nCol++, GetDispData( pAllOutBlock->outBlock3[i].IsuNm        , sizeof( pAllOutBlock->outBlock3[i].IsuNm         ), DATA_TYPE_STRING ) );    // [string,   40] �����              
			m_ctrlOutBlock3.SetItemText(  nRow, nCol++, GetDispData( pAllOutBlock->outBlock3[i].BnsTpCode    , sizeof( pAllOutBlock->outBlock3[i].BnsTpCode     ), DATA_TYPE_STRING ) );    // [string,    1] �Ÿű���            
			m_ctrlOutBlock3.SetItemText(  nRow, nCol++, GetDispData( pAllOutBlock->outBlock3[i].BnsTpNm      , sizeof( pAllOutBlock->outBlock3[i].BnsTpNm       ), DATA_TYPE_STRING ) );    // [string,   10] �Ÿű���            
			m_ctrlOutBlock3.SetItemText(  nRow, nCol++, GetDispData( pAllOutBlock->outBlock3[i].OrdPtnCode   , sizeof( pAllOutBlock->outBlock3[i].OrdPtnCode    ), DATA_TYPE_STRING ) );    // [string,    2] �ֹ������ڵ�        
			m_ctrlOutBlock3.SetItemText(  nRow, nCol++, GetDispData( pAllOutBlock->outBlock3[i].OrdPtnNm     , sizeof( pAllOutBlock->outBlock3[i].OrdPtnNm      ), DATA_TYPE_STRING ) );    // [string,   40] �ֹ�������          
			m_ctrlOutBlock3.SetItemText(  nRow, nCol++, GetDispData( pAllOutBlock->outBlock3[i].OrdTrxPtnCode, sizeof( pAllOutBlock->outBlock3[i].OrdTrxPtnCode ), DATA_TYPE_LONG   ) );    // [long  ,    9] �ֹ�ó�������ڵ�    
			m_ctrlOutBlock3.SetItemText(  nRow, nCol++, GetDispData( pAllOutBlock->outBlock3[i].OrdTrxPtnNm  , sizeof( pAllOutBlock->outBlock3[i].OrdTrxPtnNm   ), DATA_TYPE_STRING ) );    // [string,   50] �ֹ�ó��������      
			m_ctrlOutBlock3.SetItemText(  nRow, nCol++, GetDispData( pAllOutBlock->outBlock3[i].MrcTpCode    , sizeof( pAllOutBlock->outBlock3[i].MrcTpCode     ), DATA_TYPE_STRING ) );    // [string,    1] ������ұ���        
			m_ctrlOutBlock3.SetItemText(  nRow, nCol++, GetDispData( pAllOutBlock->outBlock3[i].MrcTpNm      , sizeof( pAllOutBlock->outBlock3[i].MrcTpNm       ), DATA_TYPE_STRING ) );    // [string,   10] ������ұ��и�      
			m_ctrlOutBlock3.SetItemText(  nRow, nCol++, GetDispData( pAllOutBlock->outBlock3[i].MrcQty       , sizeof( pAllOutBlock->outBlock3[i].MrcQty        ), DATA_TYPE_LONG   ) );    // [long  ,   16] ������Ҽ���        
			m_ctrlOutBlock3.SetItemText(  nRow, nCol++, GetDispData( pAllOutBlock->outBlock3[i].MrcAbleQty   , sizeof( pAllOutBlock->outBlock3[i].MrcAbleQty    ), DATA_TYPE_LONG   ) );    // [long  ,   16] ������Ұ��ɼ���    
			m_ctrlOutBlock3.SetItemText(  nRow, nCol++, GetDispData( pAllOutBlock->outBlock3[i].OrdQty       , sizeof( pAllOutBlock->outBlock3[i].OrdQty        ), DATA_TYPE_LONG   ) );    // [long  ,   16] �ֹ�����            
			m_ctrlOutBlock3.SetItemText(  nRow, nCol++, GetDispData( pAllOutBlock->outBlock3[i].OrdPrc       , sizeof( pAllOutBlock->outBlock3[i].OrdPrc        ), DATA_TYPE_DOT, 2 ) );    // [double, 15.2] �ֹ�����            
			m_ctrlOutBlock3.SetItemText(  nRow, nCol++, GetDispData( pAllOutBlock->outBlock3[i].ExecQty      , sizeof( pAllOutBlock->outBlock3[i].ExecQty       ), DATA_TYPE_LONG   ) );    // [long  ,   16] ü�����            
			m_ctrlOutBlock3.SetItemText(  nRow, nCol++, GetDispData( pAllOutBlock->outBlock3[i].ExecPrc      , sizeof( pAllOutBlock->outBlock3[i].ExecPrc       ), DATA_TYPE_DOT, 2 ) );    // [double, 15.2] ü�ᰡ              
			m_ctrlOutBlock3.SetItemText(  nRow, nCol++, GetDispData( pAllOutBlock->outBlock3[i].ExecTrxTime  , sizeof( pAllOutBlock->outBlock3[i].ExecTrxTime   ), DATA_TYPE_STRING ) );    // [string,    9] ü��ó���ð�        
			m_ctrlOutBlock3.SetItemText(  nRow, nCol++, GetDispData( pAllOutBlock->outBlock3[i].LastExecTime , sizeof( pAllOutBlock->outBlock3[i].LastExecTime  ), DATA_TYPE_STRING ) );    // [string,    9] ����ü��ð�        
			m_ctrlOutBlock3.SetItemText(  nRow, nCol++, GetDispData( pAllOutBlock->outBlock3[i].OrdprcPtnCode, sizeof( pAllOutBlock->outBlock3[i].OrdprcPtnCode ), DATA_TYPE_STRING ) );    // [string,    2] ȣ�������ڵ�        
			m_ctrlOutBlock3.SetItemText(  nRow, nCol++, GetDispData( pAllOutBlock->outBlock3[i].OrdprcPtnNm  , sizeof( pAllOutBlock->outBlock3[i].OrdprcPtnNm   ), DATA_TYPE_STRING ) );    // [string,   40] ȣ��������          
			m_ctrlOutBlock3.SetItemText(  nRow, nCol++, GetDispData( pAllOutBlock->outBlock3[i].OrdCndiTpCode, sizeof( pAllOutBlock->outBlock3[i].OrdCndiTpCode ), DATA_TYPE_STRING ) );    // [string,    1] �ֹ����Ǳ���        
			m_ctrlOutBlock3.SetItemText(  nRow, nCol++, GetDispData( pAllOutBlock->outBlock3[i].AllExecQty   , sizeof( pAllOutBlock->outBlock3[i].AllExecQty    ), DATA_TYPE_LONG   ) );    // [long  ,   16] ��üü�����        
			m_ctrlOutBlock3.SetItemText(  nRow, nCol++, GetDispData( pAllOutBlock->outBlock3[i].RegCommdaCode, sizeof( pAllOutBlock->outBlock3[i].RegCommdaCode ), DATA_TYPE_STRING ) );    // [string,    2] ��Ÿ�ü�ڵ�        
			m_ctrlOutBlock3.SetItemText(  nRow, nCol++, GetDispData( pAllOutBlock->outBlock3[i].CommdaNm     , sizeof( pAllOutBlock->outBlock3[i].CommdaNm      ), DATA_TYPE_STRING ) );    // [string,   40] ��Ÿ�ü��          
			m_ctrlOutBlock3.SetItemText(  nRow, nCol++, GetDispData( pAllOutBlock->outBlock3[i].MbrNo        , sizeof( pAllOutBlock->outBlock3[i].MbrNo         ), DATA_TYPE_STRING ) );    // [string,    3] ȸ����ȣ            
			m_ctrlOutBlock3.SetItemText(  nRow, nCol++, GetDispData( pAllOutBlock->outBlock3[i].RsvOrdYn     , sizeof( pAllOutBlock->outBlock3[i].RsvOrdYn      ), DATA_TYPE_STRING ) );    // [string,    1] �����ֹ�����        
			m_ctrlOutBlock3.SetItemText(  nRow, nCol++, GetDispData( pAllOutBlock->outBlock3[i].LoanDt       , sizeof( pAllOutBlock->outBlock3[i].LoanDt        ), DATA_TYPE_STRING ) );    // [string,    8] ������              
			m_ctrlOutBlock3.SetItemText(  nRow, nCol++, GetDispData( pAllOutBlock->outBlock3[i].OrdTime      , sizeof( pAllOutBlock->outBlock3[i].OrdTime       ), DATA_TYPE_STRING ) );    // [string,    9] �ֹ��ð�            
			m_ctrlOutBlock3.SetItemText(  nRow, nCol++, GetDispData( pAllOutBlock->outBlock3[i].OpDrtnNo     , sizeof( pAllOutBlock->outBlock3[i].OpDrtnNo      ), DATA_TYPE_STRING ) );    // [string,   12] ������ù�ȣ        
			m_ctrlOutBlock3.SetItemText(  nRow, nCol++, GetDispData( pAllOutBlock->outBlock3[i].OdrrId       , sizeof( pAllOutBlock->outBlock3[i].OdrrId        ), DATA_TYPE_STRING ) );    // [string,   16] �ֹ���ID            
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
LRESULT CDlg_CSPAQ03700::OnXMTimeoutData( WPARAM wParam, LPARAM lParam )
{
	g_iXingAPI.ReleaseRequestData( (int)lParam );
	GetParent()->SendMessage( WMU_SET_MESSAGE, (WPARAM)"", (LPARAM)"Timeout" );		

	return 0L;
}
