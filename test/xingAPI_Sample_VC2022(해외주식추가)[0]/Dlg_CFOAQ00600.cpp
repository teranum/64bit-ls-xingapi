// Dlg_CFOAQ00600.cpp : implementation file
//

#include "stdafx.h"
#include "xingapi_sample.h"
#include "Dlg_CFOAQ00600.h"

#include "./Packet/CFOAQ00600.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlg_CFOAQ00600 dialog


IMPLEMENT_DYNCREATE(CDlg_CFOAQ00600, CDialog)

CDlg_CFOAQ00600::CDlg_CFOAQ00600(CWnd* pParent /*=NULL*/)
	: CDialog(CDlg_CFOAQ00600::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlg_CFOAQ00600)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CDlg_CFOAQ00600::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlg_CFOAQ00600)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
	DDX_Control(pDX, IDC_OUTBLOCK1, m_ctrlOutBlock1);
	DDX_Control(pDX, IDC_OUTBLOCK2, m_ctrlOutBlock2);
	DDX_Control(pDX, IDC_OUTBLOCK3, m_ctrlOutBlock3);
}


BEGIN_MESSAGE_MAP(CDlg_CFOAQ00600, CDialog)
	//{{AFX_MSG_MAP(CDlg_CFOAQ00600)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
	ON_BN_CLICKED( IDC_BUTTON_REQUEST,		  OnButtonRequest	  )
	ON_BN_CLICKED( IDC_BUTTON_REQUEST_NEXT,	  OnButtonRequestNext )
	ON_MESSAGE	 ( WM_USER + XM_RECEIVE_DATA, OnXMReceiveData	  )
	ON_MESSAGE	 ( WM_USER + XM_TIMEOUT_DATA, OnXMTimeoutData	  )
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlg_CFOAQ00600 message handlers

BOOL CDlg_CFOAQ00600::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	InitCtrls();
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CDlg_CFOAQ00600::OnButtonRequest() 
{
	RequestData();
}

void CDlg_CFOAQ00600::OnButtonRequestNext() 
{
	RequestData( TRUE );
}

//--------------------------------------------------------------------------------------
// ��Ʈ�� �ʱ�ȭ
//--------------------------------------------------------------------------------------
void CDlg_CFOAQ00600::InitCtrls()
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
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "���ڵ尹��      ", FALSE,    5 );    // [long  ,    5] ���ڵ尹��      
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "���¹�ȣ        ", TRUE ,   20 );    // [string,   20] ���¹�ȣ        
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "�Էº�й�ȣ    ", TRUE ,    8 );    // [string,    8] �Էº�й�ȣ    
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "��ȸ������      ", TRUE ,    8 );    // [string,    8] ��ȸ������      
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "��ȸ������      ", TRUE ,    8 );    // [string,    8] ��ȸ������      
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "�����ɼǺз��ڵ�", TRUE ,    2 );    // [string,    2] �����ɼǺз��ڵ�
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "��ǰ���ڵ�      ", TRUE ,    2 );    // [string,    2] ��ǰ���ڵ�      
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "ü�ᱸ��        ", TRUE ,    1 );    // [string,    1] ü�ᱸ��        
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "���ļ�������    ", TRUE ,    1 );    // [string,    1] ���ļ�������    
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "��Ÿ�ü�ڵ�    ", TRUE ,    2 );    // [string,    2] ��Ÿ�ü�ڵ�    
	
	//-------------------------------------------------------------------------
	// OutBlock2
	nCol = 0;
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "���ڵ尹��  ", FALSE,    5 );    // [long  ,    5] ���ڵ尹��  
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "���¸�      ", TRUE ,   40 );    // [string,   40] ���¸�      
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "�����ֹ�����", FALSE,   16 );    // [long  ,   16] �����ֹ�����
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "����ü�����", FALSE,   16 );    // [long  ,   16] ����ü�����
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "�ɼ��ֹ�����", FALSE,   16 );    // [long  ,   16] �ɼ��ֹ�����
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "�ɼ�ü�����", FALSE,   16 );    // [long  ,   16] �ɼ�ü�����
	
	//-------------------------------------------------------------------------
	// OutBlock3
	nCol = 0;
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "�ֹ���              ", TRUE ,    8 );    // [string,    8] �ֹ���              
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "�ֹ���ȣ            ", FALSE,   10 );    // [long  ,   10] �ֹ���ȣ            
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "���ֹ���ȣ          ", FALSE,   10 );    // [long  ,   10] ���ֹ���ȣ          
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "�ֹ��ð�            ", TRUE ,    9 );    // [string,    9] �ֹ��ð�            
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "�����ɼ������ȣ    ", TRUE ,   12 );    // [string,   12] �����ɼ������ȣ    
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "�����              ", TRUE ,   40 );    // [string,   40] �����              
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "�Ÿű���            ", TRUE ,   10 );    // [string,   10] �Ÿű���            
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "������ұ��и�      ", TRUE ,   10 );    // [string,   10] ������ұ��и�      
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "�����ɼ�ȣ�������ڵ�", TRUE ,    2 );    // [string,    2] �����ɼ�ȣ�������ڵ�
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "�����ɼ�ȣ��������  ", TRUE ,   40 );    // [string,   40] �����ɼ�ȣ��������  
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "�ֹ���              ", FALSE, 13.2 );    // [double, 13.2] �ֹ���              
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "�ֹ�����            ", FALSE,   16 );    // [long  ,   16] �ֹ�����            
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "�ֹ����и�          ", TRUE ,   10 );    // [string,   10] �ֹ����и�          
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "ü�ᱸ�и�          ", TRUE ,   10 );    // [string,   10] ü�ᱸ�и�          
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "ü�ᰡ              ", FALSE, 13.2 );    // [double, 13.2] ü�ᰡ              
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "ü�����            ", FALSE,   16 );    // [long  ,   16] ü�����            
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "�����ð�            ", TRUE ,    9 );    // [string,    9] �����ð�            
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "������ȣ            ", FALSE,   10 );    // [long  ,   10] ������ȣ            
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "ü���ȣ            ", FALSE,   10 );    // [long  ,   10] ü���ȣ            
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "�Ÿż��ͱݾ�        ", FALSE,   16 );    // [long  ,   16] �Ÿż��ͱݾ�        
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "��ü�����          ", FALSE,   16 );    // [long  ,   16] ��ü�����          
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "�����ID            ", TRUE ,   16 );    // [string,   16] �����ID            
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "��Ÿ�ü�ڵ�        ", TRUE ,    2 );    // [string,    2] ��Ÿ�ü�ڵ�        
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "��Ÿ�ü�ڵ��      ", TRUE ,   40 );    // [string,   40] ��Ÿ�ü�ڵ��      
	
	ZeroMemory( m_szContKey, sizeof( m_szContKey ) );
	GetDlgItem( IDC_BUTTON_REQUEST_NEXT )->EnableWindow( FALSE );
}

//--------------------------------------------------------------------------------------
// ������ ��ȸ
//--------------------------------------------------------------------------------------
void CDlg_CFOAQ00600::RequestData( BOOL bNext )
{
	//-----------------------------------------------------------
	CFOAQ00600InBlock1	pckInBlock;

	TCHAR			szTrNo[]		= "CFOAQ00600";
	char			szNextKey[]		= "";

	//-----------------------------------------------------------
	// ������ ���
    CString strAcntNo        ;		GetDlgItemText( IDC_INBLOCK_ACNTNO        , strAcntNo         );    // ���¹�ȣ        
    CString strInptPwd       ;		GetDlgItemText( IDC_INBLOCK_INPTPWD       , strInptPwd        );    // �Էº�й�ȣ    
    CString strQrySrtDt      ;		GetDlgItemText( IDC_INBLOCK_QRYSRTDT      , strQrySrtDt       );    // ��ȸ������      
    CString strQryEndDt      ;		GetDlgItemText( IDC_INBLOCK_QRYENDDT      , strQryEndDt       );    // ��ȸ������      
    CString strPrdgrpCode    ;		GetDlgItemText( IDC_INBLOCK_PRDGRPCODE    , strPrdgrpCode     );    // ��ǰ���ڵ�      
    CString strPrdtExecTpCode;		GetDlgItemText( IDC_INBLOCK_PRDTEXECTPCODE, strPrdtExecTpCode );    // ü�ᱸ��        
    CString strStnlnSeqTp    ;		GetDlgItemText( IDC_INBLOCK_STNLNSEQTP    , strStnlnSeqTp     );    // ���ļ�������    

	//-----------------------------------------------------------
	// ������ �ʱ�ȭ
	FillMemory( &pckInBlock, sizeof( pckInBlock ), ' ' );

	//-----------------------------------------------------------
	// ������ �Է�
	SetPacketData( pckInBlock.RecCnt        , sizeof( pckInBlock.RecCnt         ), "1"              , DATA_TYPE_LONG   );    // [long  ,    5] ���ڵ尹��      
	SetPacketData( pckInBlock.AcntNo        , sizeof( pckInBlock.AcntNo         ), strAcntNo        , DATA_TYPE_STRING );    // [string,   20] ���¹�ȣ        
	SetPacketData( pckInBlock.InptPwd       , sizeof( pckInBlock.InptPwd        ), strInptPwd       , DATA_TYPE_STRING );    // [string,    8] �Էº�й�ȣ    
	SetPacketData( pckInBlock.QrySrtDt      , sizeof( pckInBlock.QrySrtDt       ), strQrySrtDt      , DATA_TYPE_STRING );    // [string,    8] ��ȸ������      
	SetPacketData( pckInBlock.QryEndDt      , sizeof( pckInBlock.QryEndDt       ), strQryEndDt      , DATA_TYPE_STRING );    // [string,    8] ��ȸ������      
	SetPacketData( pckInBlock.FnoClssCode   , sizeof( pckInBlock.FnoClssCode    ), "00"             , DATA_TYPE_STRING );    // [string,    2] �����ɼǺз��ڵ�
	SetPacketData( pckInBlock.PrdgrpCode    , sizeof( pckInBlock.PrdgrpCode     ), strPrdgrpCode    , DATA_TYPE_STRING );    // [string,    2] ��ǰ���ڵ�      
	SetPacketData( pckInBlock.PrdtExecTpCode, sizeof( pckInBlock.PrdtExecTpCode ), strPrdtExecTpCode, DATA_TYPE_STRING );    // [string,    1] ü�ᱸ��        
	SetPacketData( pckInBlock.StnlnSeqTp    , sizeof( pckInBlock.StnlnSeqTp     ), strStnlnSeqTp    , DATA_TYPE_STRING );    // [string,    1] ���ļ�������    
	SetPacketData( pckInBlock.CommdaCode    , sizeof( pckInBlock.CommdaCode     ), "99"             , DATA_TYPE_STRING );    // [string,    2] ��Ÿ�ü�ڵ�    

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
		CString strMsg;
		strMsg.Format( "[%d] %s", nRqID, g_iXingAPI.GetErrorMessage( nRqID ) );
		MessageBox( strMsg, "��ȸ����", MB_ICONSTOP );
	}
}

//--------------------------------------------------------------------------------------
// �����͸� ����
//--------------------------------------------------------------------------------------
LRESULT CDlg_CFOAQ00600::OnXMReceiveData( WPARAM wParam, LPARAM lParam )
{
	//-------------------------------------------------------------------------------------
	// Data�� ����
	if( wParam == REQUEST_DATA )
	{
		typedef struct
		{
			CFOAQ00600OutBlock1	outBlock1;
			CFOAQ00600OutBlock2	outBlock2;
			char				sCountOutBlock3[5];
			CFOAQ00600OutBlock3	outBlock3[1];
		} CFOAQ00600AllOutBlock, *LPCFOAQ00600AllOutBlock;

		LPRECV_PACKET			pRpData		 = (LPRECV_PACKET)lParam;
		LPCFOAQ00600AllOutBlock pAllOutBlock = (LPCFOAQ00600AllOutBlock)pRpData->lpData;
		int						nDataLength  = pRpData->nDataLength;
		int						nCol;
		int						nRow;
		int						nCount;
		char					szCount[6] = { 0 };

		// ����Ű�� �����Ѵ�.
		strcpy_s( m_szContKey, sizeof(pRpData->szContKey), pRpData->szContKey );
		GetDlgItem( IDC_BUTTON_REQUEST_NEXT )->EnableWindow( pRpData->cCont[0] == 'Y' );

		//------------------------------------------------
		// OutBlock1
		
		// ���� ������ ũ�Ⱑ Block ũ�⺸�� �۴ٸ� ó������ �ʴ´�.
		nDataLength -= sizeof( CFOAQ00600OutBlock1 );
		if( nDataLength < 0 )
		{
			return 0L;
		}

		nCol = 0;
		m_ctrlOutBlock1.InsertItem( 0, "" );
		m_ctrlOutBlock1.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock1.RecCnt        , sizeof( pAllOutBlock->outBlock1.RecCnt         ), DATA_TYPE_LONG   ) );    // [long  ,    5] ���ڵ尹��      
		m_ctrlOutBlock1.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock1.AcntNo        , sizeof( pAllOutBlock->outBlock1.AcntNo         ), DATA_TYPE_STRING ) );    // [string,   20] ���¹�ȣ        
		m_ctrlOutBlock1.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock1.InptPwd       , sizeof( pAllOutBlock->outBlock1.InptPwd        ), DATA_TYPE_STRING ) );    // [string,    8] �Էº�й�ȣ    
		m_ctrlOutBlock1.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock1.QrySrtDt      , sizeof( pAllOutBlock->outBlock1.QrySrtDt       ), DATA_TYPE_STRING ) );    // [string,    8] ��ȸ������      
		m_ctrlOutBlock1.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock1.QryEndDt      , sizeof( pAllOutBlock->outBlock1.QryEndDt       ), DATA_TYPE_STRING ) );    // [string,    8] ��ȸ������      
		m_ctrlOutBlock1.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock1.FnoClssCode   , sizeof( pAllOutBlock->outBlock1.FnoClssCode    ), DATA_TYPE_STRING ) );    // [string,    2] �����ɼǺз��ڵ�
		m_ctrlOutBlock1.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock1.PrdgrpCode    , sizeof( pAllOutBlock->outBlock1.PrdgrpCode     ), DATA_TYPE_STRING ) );    // [string,    2] ��ǰ���ڵ�      
		m_ctrlOutBlock1.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock1.PrdtExecTpCode, sizeof( pAllOutBlock->outBlock1.PrdtExecTpCode ), DATA_TYPE_STRING ) );    // [string,    1] ü�ᱸ��        
		m_ctrlOutBlock1.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock1.StnlnSeqTp    , sizeof( pAllOutBlock->outBlock1.StnlnSeqTp     ), DATA_TYPE_STRING ) );    // [string,    1] ���ļ�������    
		m_ctrlOutBlock1.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock1.CommdaCode    , sizeof( pAllOutBlock->outBlock1.CommdaCode     ), DATA_TYPE_STRING ) );    // [string,    2] ��Ÿ�ü�ڵ�    
		
		//------------------------------------------------
		// OutBlock2
		nDataLength -= sizeof( CFOAQ00600OutBlock2 );
		if( nDataLength < 0 )
		{
			return 0L;
		}
		
		nCol = 0;
		m_ctrlOutBlock2.InsertItem( 0, "" );
		m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock2.RecCnt     , sizeof( pAllOutBlock->outBlock2.RecCnt      ), DATA_TYPE_LONG   ) );    // [long  ,    5] ���ڵ尹��       
		m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock2.AcntNm     , sizeof( pAllOutBlock->outBlock2.AcntNm      ), DATA_TYPE_STRING ) );    // [string,   40] ���¸�           
		m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock2.FutsOrdQty , sizeof( pAllOutBlock->outBlock2.FutsOrdQty  ), DATA_TYPE_LONG   ) );    // [long  ,   16] �����ֹ�����     
		m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock2.FutsExecQty, sizeof( pAllOutBlock->outBlock2.FutsExecQty ), DATA_TYPE_LONG   ) );    // [long  ,   16] ����ü�����     
		m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock2.OptOrdQty  , sizeof( pAllOutBlock->outBlock2.OptOrdQty   ), DATA_TYPE_LONG   ) );    // [long  ,   16] �ɼ��ֹ�����     
		m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock2.OptExecQty , sizeof( pAllOutBlock->outBlock2.OptExecQty  ), DATA_TYPE_LONG   ) );    // [long  ,   16] �ɼ�ü�����     
		
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
		nDataLength -= sizeof( CFOAQ00600OutBlock3 ) * nCount;
		if( nDataLength < 0 )
		{
			return 0L;
		}
		
		for( int i=0; i<nCount; i++ )
		{
			nCol = 0;
			nRow = m_ctrlOutBlock3.InsertItem( m_ctrlOutBlock3.GetItemCount(), "" );
			m_ctrlOutBlock3.SetItemText(  nRow, nCol++, GetDispData( pAllOutBlock->outBlock3[i].OrdDt           , sizeof( pAllOutBlock->outBlock3[i].OrdDt            ), DATA_TYPE_STRING ) );    // [string,    8] �ֹ���                  
			m_ctrlOutBlock3.SetItemText(  nRow, nCol++, GetDispData( pAllOutBlock->outBlock3[i].OrdNo           , sizeof( pAllOutBlock->outBlock3[i].OrdNo            ), DATA_TYPE_LONG   ) );    // [long  ,   10] �ֹ���ȣ                
			m_ctrlOutBlock3.SetItemText(  nRow, nCol++, GetDispData( pAllOutBlock->outBlock3[i].OrgOrdNo        , sizeof( pAllOutBlock->outBlock3[i].OrgOrdNo         ), DATA_TYPE_LONG   ) );    // [long  ,   10] ���ֹ���ȣ              
			m_ctrlOutBlock3.SetItemText(  nRow, nCol++, GetDispData( pAllOutBlock->outBlock3[i].OrdTime         , sizeof( pAllOutBlock->outBlock3[i].OrdTime          ), DATA_TYPE_STRING ) );    // [string,    9] �ֹ��ð�                
			m_ctrlOutBlock3.SetItemText(  nRow, nCol++, GetDispData( pAllOutBlock->outBlock3[i].FnoIsuNo        , sizeof( pAllOutBlock->outBlock3[i].FnoIsuNo         ), DATA_TYPE_STRING ) );    // [string,   12] �����ɼ������ȣ        
			m_ctrlOutBlock3.SetItemText(  nRow, nCol++, GetDispData( pAllOutBlock->outBlock3[i].IsuNm           , sizeof( pAllOutBlock->outBlock3[i].IsuNm            ), DATA_TYPE_STRING ) );    // [string,   40] �����                  
			m_ctrlOutBlock3.SetItemText(  nRow, nCol++, GetDispData( pAllOutBlock->outBlock3[i].BnsTpNm         , sizeof( pAllOutBlock->outBlock3[i].BnsTpNm          ), DATA_TYPE_STRING ) );    // [string,   10] �Ÿű���                
			m_ctrlOutBlock3.SetItemText(  nRow, nCol++, GetDispData( pAllOutBlock->outBlock3[i].MrcTpNm         , sizeof( pAllOutBlock->outBlock3[i].MrcTpNm          ), DATA_TYPE_STRING ) );    // [string,   10] ������ұ��и�          
			m_ctrlOutBlock3.SetItemText(  nRow, nCol++, GetDispData( pAllOutBlock->outBlock3[i].FnoOrdprcPtnCode, sizeof( pAllOutBlock->outBlock3[i].FnoOrdprcPtnCode ), DATA_TYPE_STRING ) );    // [string,    2] �����ɼ�ȣ�������ڵ�    
			m_ctrlOutBlock3.SetItemText(  nRow, nCol++, GetDispData( pAllOutBlock->outBlock3[i].FnoOrdprcPtnNm  , sizeof( pAllOutBlock->outBlock3[i].FnoOrdprcPtnNm   ), DATA_TYPE_STRING ) );    // [string,   40] �����ɼ�ȣ��������      
			m_ctrlOutBlock3.SetItemText(  nRow, nCol++, GetDispData( pAllOutBlock->outBlock3[i].OrdPrc          , sizeof( pAllOutBlock->outBlock3[i].OrdPrc           ), DATA_TYPE_DOT, 2 ) );    // [double, 13.2] �ֹ���                  
			m_ctrlOutBlock3.SetItemText(  nRow, nCol++, GetDispData( pAllOutBlock->outBlock3[i].OrdQty          , sizeof( pAllOutBlock->outBlock3[i].OrdQty           ), DATA_TYPE_LONG   ) );    // [long  ,   16] �ֹ�����                
			m_ctrlOutBlock3.SetItemText(  nRow, nCol++, GetDispData( pAllOutBlock->outBlock3[i].OrdTpNm         , sizeof( pAllOutBlock->outBlock3[i].OrdTpNm          ), DATA_TYPE_STRING ) );    // [string,   10] �ֹ����и�              
			m_ctrlOutBlock3.SetItemText(  nRow, nCol++, GetDispData( pAllOutBlock->outBlock3[i].ExecTpNm        , sizeof( pAllOutBlock->outBlock3[i].ExecTpNm         ), DATA_TYPE_STRING ) );    // [string,   10] ü�ᱸ�и�              
			m_ctrlOutBlock3.SetItemText(  nRow, nCol++, GetDispData( pAllOutBlock->outBlock3[i].ExecPrc         , sizeof( pAllOutBlock->outBlock3[i].ExecPrc          ), DATA_TYPE_DOT, 2 ) );    // [double, 13.2] ü�ᰡ                  
			m_ctrlOutBlock3.SetItemText(  nRow, nCol++, GetDispData( pAllOutBlock->outBlock3[i].ExecQty         , sizeof( pAllOutBlock->outBlock3[i].ExecQty          ), DATA_TYPE_LONG   ) );    // [long  ,   16] ü�����                
			m_ctrlOutBlock3.SetItemText(  nRow, nCol++, GetDispData( pAllOutBlock->outBlock3[i].CtrctTime       , sizeof( pAllOutBlock->outBlock3[i].CtrctTime        ), DATA_TYPE_STRING ) );    // [string,    9] �����ð�                
			m_ctrlOutBlock3.SetItemText(  nRow, nCol++, GetDispData( pAllOutBlock->outBlock3[i].CtrctNo         , sizeof( pAllOutBlock->outBlock3[i].CtrctNo          ), DATA_TYPE_LONG   ) );    // [long  ,   10] ������ȣ                
			m_ctrlOutBlock3.SetItemText(  nRow, nCol++, GetDispData( pAllOutBlock->outBlock3[i].ExecNo          , sizeof( pAllOutBlock->outBlock3[i].ExecNo           ), DATA_TYPE_LONG   ) );    // [long  ,   10] ü���ȣ                
			m_ctrlOutBlock3.SetItemText(  nRow, nCol++, GetDispData( pAllOutBlock->outBlock3[i].BnsplAmt        , sizeof( pAllOutBlock->outBlock3[i].BnsplAmt         ), DATA_TYPE_LONG   ) );    // [long  ,   16] �Ÿż��ͱݾ�            
			m_ctrlOutBlock3.SetItemText(  nRow, nCol++, GetDispData( pAllOutBlock->outBlock3[i].UnercQty        , sizeof( pAllOutBlock->outBlock3[i].UnercQty         ), DATA_TYPE_LONG   ) );    // [long  ,   16] ��ü�����              
			m_ctrlOutBlock3.SetItemText(  nRow, nCol++, GetDispData( pAllOutBlock->outBlock3[i].UserId          , sizeof( pAllOutBlock->outBlock3[i].UserId           ), DATA_TYPE_STRING ) );    // [string,   16] �����ID                
			m_ctrlOutBlock3.SetItemText(  nRow, nCol++, GetDispData( pAllOutBlock->outBlock3[i].CommdaCode      , sizeof( pAllOutBlock->outBlock3[i].CommdaCode       ), DATA_TYPE_STRING ) );    // [string,    2] ��Ÿ�ü�ڵ�            
			m_ctrlOutBlock3.SetItemText(  nRow, nCol++, GetDispData( pAllOutBlock->outBlock3[i].CommdaCodeNm    , sizeof( pAllOutBlock->outBlock3[i].CommdaCodeNm     ), DATA_TYPE_STRING ) );    // [string,   40] ��Ÿ�ü�ڵ��          
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
LRESULT CDlg_CFOAQ00600::OnXMTimeoutData( WPARAM wParam, LPARAM lParam )
{
	g_iXingAPI.ReleaseRequestData( (int)lParam );
	GetParent()->SendMessage( WMU_SET_MESSAGE, (WPARAM)"", (LPARAM)"Timeout" );		

	return 0L;
}
