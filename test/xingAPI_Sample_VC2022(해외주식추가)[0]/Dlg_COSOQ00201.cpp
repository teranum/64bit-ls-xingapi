// Dlg_COSOQ00201.cpp : implementation file
//

#include "stdafx.h"
#include "xingapi_sample.h"
#include "Dlg_COSOQ00201.h"

#include "./Packet/COSOQ00201.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlg_COSOQ00201 dialog


IMPLEMENT_DYNCREATE(CDlg_COSOQ00201, CDialog)

	CDlg_COSOQ00201::CDlg_COSOQ00201(CWnd* pParent /*=NULL*/)
	: CDialog(CDlg_COSOQ00201::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlg_COSOQ00201)
	// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CDlg_COSOQ00201::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlg_COSOQ00201)
	// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
	DDX_Control(pDX, IDC_OUTBLOCK1, m_ctrlOutBlock1);
	DDX_Control(pDX, IDC_OUTBLOCK2, m_ctrlOutBlock2);
	DDX_Control(pDX, IDC_OUTBLOCK3, m_ctrlOutBlock3);
	DDX_Control(pDX, IDC_OUTBLOCK4, m_ctrlOutBlock4);
}


BEGIN_MESSAGE_MAP(CDlg_COSOQ00201, CDialog)
	//{{AFX_MSG_MAP(CDlg_COSOQ00201)
	// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
	ON_BN_CLICKED( IDC_BUTTON_REQUEST,		  OnButtonRequest	  )
	ON_BN_CLICKED( IDC_BUTTON_REQUEST_NEXT,	  OnButtonRequestNext )
	ON_MESSAGE	 ( WM_USER + XM_RECEIVE_DATA, OnXMReceiveData	  )
	ON_MESSAGE	 ( WM_USER + XM_TIMEOUT_DATA, OnXMTimeoutData	  )
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlg_COSOQ00201 message handlers

BOOL CDlg_COSOQ00201::OnInitDialog() 
{
	CDialog::OnInitDialog();

	InitCtrls();

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}

void CDlg_COSOQ00201::OnButtonRequest() 
{
	RequestData();
}

void CDlg_COSOQ00201::OnButtonRequestNext() 
{
	RequestData( TRUE );
}

//--------------------------------------------------------------------------------------
// ��Ʈ�� �ʱ�ȭ
//--------------------------------------------------------------------------------------
void CDlg_COSOQ00201::InitCtrls()
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
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "���ڵ尹��         ", FALSE,    8	);         
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "���¹�ȣ           ", TRUE ,    10	);        
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "��й�ȣ           ", TRUE ,    8	);      
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "��������           ", TRUE ,    8	);        
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "��ȭ�ڵ�           ", TRUE ,    8	);   
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "�ؿ������ܰ����ڵ�", TRUE ,    16 );    


	//-------------------------------------------------------------------------
	// OutBlock2
	nCol = 0;
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "���ڵ尹��                  ",	FALSE,	8	);                 
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "������                      ",	TRUE ,	12	);                    
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "������ȯ���򰡱ݾ�           ",	TRUE ,	15	);                        
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "�ֽ�ȯ���򰡱ݾ�             ",	FALSE,	12	);            
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "��Ź�ڻ�ȯ���򰡱ݾ�         ",	FALSE,	15	);             
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "��ȭ���հ�ݾ�             ",	FALSE,	15	);                      
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "ȯ���򰡼��ͱݾ�             ",	FALSE,	15	);                       
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "��ȭ�������ܰ�ݾ�           ",	FALSE,	15	);    
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "D2����������                ",	FALSE,	15	);    
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "����ݾ�                    ",	FALSE,	12	);                             

	//-------------------------------------------------------------------------
	// OutBlock3
	nCol = 0;
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "��ȭ�ڵ�          ",	TRUE ,	8	);            
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "��ȭ������        ",	TRUE ,	15	);                
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "��ȭ�򰡱ݾ�      ",	TRUE ,	15	);   
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "��ȭ�򰡼��ͱݾ�   ",	TRUE,	15	);    
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "������            ",	FALSE,	12	);
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "����ȯ��          ",	FALSE,	12	);        
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "������ȯ���򰡱ݾ� ",	FALSE,	15	);     
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "���Աݾ�          ",	FALSE,	15	);      
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "�ֽ�ȯ���򰡱ݾ�   ",	FALSE,	15	);                 
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "ȯ���򰡼��ͱݾ�   ",	FALSE,	15	);            
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "��ȭ�ż��ݾ�       ",	FALSE,	15	);            
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "��ȭ�ֹ����ɱݾ�   ",	FALSE,	15	);      
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "����ݾ�          ",	FALSE,	12	);                  

	//-------------------------------------------------------------------------
	// OutBlock4
	nCol = 0;
	InsertColumn4List( this, IDC_OUTBLOCK4, nCol++, "��ȭ�ڵ�             ",	TRUE ,	8	);            
	InsertColumn4List( this, IDC_OUTBLOCK4, nCol++, "���������ȣ         ",	TRUE ,	10	);   
	InsertColumn4List( this, IDC_OUTBLOCK4, nCol++, "�����ȣ             ",	TRUE ,	12	);   
	InsertColumn4List( this, IDC_OUTBLOCK4, nCol++, "�Ϻ������ѱ������    ",	TRUE ,	20	);   
	InsertColumn4List( this, IDC_OUTBLOCK4, nCol++, "�ؿ������ܰ����ڵ�  ",	TRUE ,	12	);   
	InsertColumn4List( this, IDC_OUTBLOCK4, nCol++, "�ؿ������ܰ����ڵ��",	TRUE ,	20	);   
	InsertColumn4List( this, IDC_OUTBLOCK4, nCol++, "�ؿ������ܰ����      ",	TRUE ,	20	);   
	InsertColumn4List( this, IDC_OUTBLOCK4, nCol++, "�ؿ����Ǹŵ����ɼ���  ",	TRUE ,	20	);   
	InsertColumn4List( this, IDC_OUTBLOCK4, nCol++, "��ȭ���Ǵܰ�         ",	TRUE ,	15	);   
	InsertColumn4List( this, IDC_OUTBLOCK4, nCol++, "��ȭ�ż��ݾ�         ",	TRUE ,	15	);   
	InsertColumn4List( this, IDC_OUTBLOCK4, nCol++, "��ȭ���ǽ��������ڵ�  ",	TRUE ,	15	);   
	InsertColumn4List( this, IDC_OUTBLOCK4, nCol++, "�ؿ����ǽü�         ",	TRUE ,	20	);   
	InsertColumn4List( this, IDC_OUTBLOCK4, nCol++, "��ȭ�򰡱ݾ�         ",	TRUE ,	20	);   
	InsertColumn4List( this, IDC_OUTBLOCK4, nCol++, "��ȭ�򰡼��ͱݾ�     ",	TRUE ,	20	);   
	InsertColumn4List( this, IDC_OUTBLOCK4, nCol++, "������              ",	TRUE ,	12	);   
	InsertColumn4List( this, IDC_OUTBLOCK4, nCol++, "����ȯ��            ",	TRUE ,	12	);   
	InsertColumn4List( this, IDC_OUTBLOCK4, nCol++, "���Աݾ�            ",	TRUE ,	12	);   
	InsertColumn4List( this, IDC_OUTBLOCK4, nCol++, "������ȯ���򰡱ݾ�   ",	TRUE ,	12	);   
	InsertColumn4List( this, IDC_OUTBLOCK4, nCol++, "�ֽ�ȯ���򰡱ݾ�     ",	TRUE ,	12	);   
	InsertColumn4List( this, IDC_OUTBLOCK4, nCol++, "ȯ���򰡼��ͱݾ�     ",	TRUE ,	12	);   
	InsertColumn4List( this, IDC_OUTBLOCK4, nCol++, "�ؿ����ǰ�������     ",	TRUE ,	15	);   
	InsertColumn4List( this, IDC_OUTBLOCK4, nCol++, "���屸�и�           ",	TRUE ,	12	);   
	InsertColumn4List( this, IDC_OUTBLOCK4, nCol++, "��ȭ�����ڵ�         ",	TRUE ,	12	);   
	InsertColumn4List( this, IDC_OUTBLOCK4, nCol++, "��������            ",	TRUE ,	12	);   
	InsertColumn4List( this, IDC_OUTBLOCK4, nCol++, "����󼼺з��ڵ�     ",	TRUE ,	12	);   
	InsertColumn4List( this, IDC_OUTBLOCK4, nCol++, "����ݾ�            ",	TRUE ,	12	);   
	InsertColumn4List( this, IDC_OUTBLOCK4, nCol++, "��������            ",	TRUE ,	12	);   
	InsertColumn4List( this, IDC_OUTBLOCK4, nCol++, "�ؿ����Ǳ��ذ���     ",	TRUE ,	15	);   

  

	ZeroMemory( m_szContKey, sizeof( m_szContKey ) );
}

//--------------------------------------------------------------------------------------
// ������ ��ȸ
//--------------------------------------------------------------------------------------
void CDlg_COSOQ00201::RequestData( BOOL bNext )
{
	//-----------------------------------------------------------
	// �ؿ��ֽ������ܰ���(COSOQ00201) ( base21=SONAT000,headtype=B )
	COSOQ00201InBlock1	pckInBlock;

	TCHAR			szTrNo[]		= "COSOQ00201";

	//-----------------------------------------------------------
	// ������ ���
	CString strAcntNo        ;		GetDlgItemText( IDC_INBLOCK_ACNTNO        , strAcntNo        );    // [long  ,    5] ���¹�ȣ        
	CString strPwd           ;		GetDlgItemText( IDC_INBLOCK_PWD           , strPwd           );    // [string,   20] ��й�ȣ          
	CString strBaseDt        ;		GetDlgItemText( IDC_INBLOCK_BASEDT        , strBaseDt        );    // [string,    8] ��������          
	CString strCrcyCode      ;		GetDlgItemText( IDC_INBLOCK_CRCYCODE      , strCrcyCode      );    // [string,    3] ��ȭ�ڵ�      
	CString strAstkBalTpCode ;		GetDlgItemText( IDC_INBLOCK_ASTKBALTPCODE , strAstkBalTpCode );    // [string,    2] �ؿ������ܰ����ڵ�


	//-----------------------------------------------------------
	// ������ �ʱ�ȭ
	FillMemory( &pckInBlock, sizeof( pckInBlock ), ' ' );

	//-----------------------------------------------------------
	// ������ �Է�
	SetPacketData( pckInBlock.RecCnt        , sizeof( pckInBlock.RecCnt        ), "1"              , DATA_TYPE_LONG         );    // [long  ,    5] ���ڵ尹��        
	SetPacketData( pckInBlock.AcntNo        , sizeof( pckInBlock.AcntNo        ), strAcntNo        , DATA_TYPE_STRING       );    // [string,   20] ���¹�ȣ          
	SetPacketData( pckInBlock.Pwd           , sizeof( pckInBlock.Pwd           ), strPwd           , DATA_TYPE_STRING       );    // [string,    8] ��й�ȣ          
	SetPacketData( pckInBlock.BaseDt        , sizeof( pckInBlock.BaseDt        ), strBaseDt        , DATA_TYPE_STRING       );    // [string,    8] ��������      
	SetPacketData( pckInBlock.CrcyCode      , sizeof( pckInBlock.CrcyCode      ), strCrcyCode      , DATA_TYPE_STRING       );    // [string,    3] ��ȭ�ڵ�    
	SetPacketData( pckInBlock.AstkBalTpCode , sizeof( pckInBlock.AstkBalTpCode ), strAstkBalTpCode , DATA_TYPE_STRING       );    // [string,    2] �ؿ������ܰ����ڵ�


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
	if( bNext == FALSE )
	{
		m_ctrlOutBlock4.DeleteAllItems();
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
LRESULT CDlg_COSOQ00201::OnXMReceiveData( WPARAM wParam, LPARAM lParam )
{
	//-------------------------------------------------------------------------------------
	// Data�� ����
	if( wParam == REQUEST_DATA )
	{
		typedef struct
		{
			COSOQ00201OutBlock1	outBlock1;
			COSOQ00201OutBlock2	outBlock2;
			char				sCountOutBlock3[5];
			COSOQ00201OutBlock3	outBlock3[1];
		} COSOQ00201AllOutBlock, *LPCOSOQ00201AllOutBlock;

		LPRECV_PACKET			pRpData		 = (LPRECV_PACKET)lParam;
		LPCOSOQ00201AllOutBlock pAllOutBlock = (LPCOSOQ00201AllOutBlock)pRpData->lpData;
		int						nDataLength  = pRpData->nDataLength;
		int						nCol;
		int						nRow;
		int						nCount;
		int						nOffset = 0;
		char					szCount[6] = { 0 };

		// ����Ű�� �����Ѵ�.
		strcpy_s( m_szContKey, pRpData->szContKey );

		//------------------------------------------------
		// OutBlock1

		// ���� ������ ũ�Ⱑ Block ũ�⺸�� �۴ٸ� ó������ �ʴ´�.
		nDataLength -= sizeof( COSOQ00201OutBlock1 );
		if( nDataLength < 0 )
		{
			return 0L;
		}
		nOffset += sizeof( COSOQ00201OutBlock1 );

		nCol = 0;
		m_ctrlOutBlock1.InsertItem( 0, "" );
		m_ctrlOutBlock1.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock1.RecCnt        , sizeof( pAllOutBlock->outBlock1.RecCnt        ), DATA_TYPE_LONG   ) );   
		m_ctrlOutBlock1.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock1.AcntNo        , sizeof( pAllOutBlock->outBlock1.AcntNo        ), DATA_TYPE_STRING ) );    
		m_ctrlOutBlock1.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock1.Pwd           , sizeof( pAllOutBlock->outBlock1.Pwd           ), DATA_TYPE_STRING ) );    
		m_ctrlOutBlock1.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock1.BaseDt        , sizeof( pAllOutBlock->outBlock1.BaseDt        ), DATA_TYPE_STRING ) );    
		m_ctrlOutBlock1.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock1.CrcyCode      , sizeof( pAllOutBlock->outBlock1.CrcyCode      ), DATA_TYPE_STRING ) );    
		m_ctrlOutBlock1.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock1.AstkBalTpCode , sizeof( pAllOutBlock->outBlock1.AstkBalTpCode ), DATA_TYPE_STRING ) );  

		//------------------------------------------------
		// OutBlock2
		nDataLength -= sizeof( COSOQ00201OutBlock2 );
		if( nDataLength < 0 )
		{
			return 0L;
		}
		nOffset += sizeof( COSOQ00201OutBlock2 );

		nCol = 0;
		m_ctrlOutBlock2.InsertItem( 0, "" );
		m_ctrlOutBlock2.SetItemText( 0, nCol++, GetDispData( pAllOutBlock->outBlock2.RecCnt              , sizeof( pAllOutBlock->outBlock2.RecCnt             ), DATA_TYPE_LONG   ) );   
		m_ctrlOutBlock2.SetItemText( 0, nCol++, GetDispData( pAllOutBlock->outBlock2.ErnRat              , sizeof( pAllOutBlock->outBlock2.ErnRat             ), DATA_TYPE_DOT, 6 ) );   
		m_ctrlOutBlock2.SetItemText( 0, nCol++, GetDispData( pAllOutBlock->outBlock2.DpsConvEvalAmt      , sizeof( pAllOutBlock->outBlock2.DpsConvEvalAmt     ), DATA_TYPE_LONG   ) );           
		m_ctrlOutBlock2.SetItemText( 0, nCol++, GetDispData( pAllOutBlock->outBlock2.StkConvEvalAmt      , sizeof( pAllOutBlock->outBlock2.StkConvEvalAmt     ), DATA_TYPE_LONG   ) );    
		m_ctrlOutBlock2.SetItemText( 0, nCol++, GetDispData( pAllOutBlock->outBlock2.DpsastConvEvalAmt   , sizeof( pAllOutBlock->outBlock2.DpsastConvEvalAmt  ), DATA_TYPE_LONG   ) );         
		m_ctrlOutBlock2.SetItemText( 0, nCol++, GetDispData( pAllOutBlock->outBlock2.WonEvalSumAmt      , sizeof( pAllOutBlock->outBlock2.WonEvalSumAmt       ), DATA_TYPE_LONG   ) );           
		m_ctrlOutBlock2.SetItemText( 0, nCol++, GetDispData( pAllOutBlock->outBlock2.ConvEvalPnlAmt     , sizeof( pAllOutBlock->outBlock2.ConvEvalPnlAmt      ), DATA_TYPE_LONG   ) );      
		m_ctrlOutBlock2.SetItemText( 0, nCol++, GetDispData( pAllOutBlock->outBlock2.WonDpsBalAmt       , sizeof( pAllOutBlock->outBlock2.WonDpsBalAmt        ), DATA_TYPE_LONG   ) );             
		m_ctrlOutBlock2.SetItemText( 0, nCol++, GetDispData( pAllOutBlock->outBlock2.D2EstiDps          , sizeof( pAllOutBlock->outBlock2.D2EstiDps           ), DATA_TYPE_LONG   ) );   
		m_ctrlOutBlock2.SetItemText( 0, nCol++, GetDispData( pAllOutBlock->outBlock2.LoanAmt            , sizeof( pAllOutBlock->outBlock2.LoanAmt             ), DATA_TYPE_LONG   ) );                       

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
		nOffset += 5;

		// Data
		nDataLength -= sizeof( COSOQ00201OutBlock3 ) * nCount;
		if( nDataLength < 0 )
		{
			return 0L;
		}
		nOffset += sizeof( COSOQ00201OutBlock3 ) * nCount;

		for( int i=0; i<nCount; i++ )
		{
			nCol = 0;
			nRow = m_ctrlOutBlock3.InsertItem( m_ctrlOutBlock3.GetItemCount(), "" );
			m_ctrlOutBlock3.SetItemText( nRow, nCol++, GetDispData( pAllOutBlock->outBlock3[i].CrcyCode         , sizeof( pAllOutBlock->outBlock3[i].CrcyCode            ), DATA_TYPE_STRING ) ); 
			m_ctrlOutBlock3.SetItemText( nRow, nCol++, GetDispData( pAllOutBlock->outBlock3[i].FcurrDps         , sizeof( pAllOutBlock->outBlock3[i].FcurrDps            ), DATA_TYPE_DOT, 4 ) );        
			m_ctrlOutBlock3.SetItemText( nRow, nCol++, GetDispData( pAllOutBlock->outBlock3[i].FcurrEvalAmt     , sizeof( pAllOutBlock->outBlock3[i].FcurrEvalAmt        ), DATA_TYPE_DOT, 4 ) );   
			m_ctrlOutBlock3.SetItemText( nRow, nCol++, GetDispData( pAllOutBlock->outBlock3[i].FcurrEvalPnlAmt  , sizeof( pAllOutBlock->outBlock3[i].FcurrEvalPnlAmt     ), DATA_TYPE_DOT, 4 ) );  
			m_ctrlOutBlock3.SetItemText( nRow, nCol++, GetDispData( pAllOutBlock->outBlock3[i].PnlRat           , sizeof( pAllOutBlock->outBlock3[i].PnlRat              ), DATA_TYPE_DOT, 6 ) );              
			m_ctrlOutBlock3.SetItemText( nRow, nCol++, GetDispData( pAllOutBlock->outBlock3[i].BaseXchrat       , sizeof( pAllOutBlock->outBlock3[i].BaseXchrat          ), DATA_TYPE_DOT, 4 ) );  
			m_ctrlOutBlock3.SetItemText( nRow, nCol++, GetDispData( pAllOutBlock->outBlock3[i].DpsConvEvalAmt   , sizeof( pAllOutBlock->outBlock3[i].DpsConvEvalAmt      ), DATA_TYPE_LONG   ) ); 
			m_ctrlOutBlock3.SetItemText( nRow, nCol++, GetDispData( pAllOutBlock->outBlock3[i].PchsAmt          , sizeof( pAllOutBlock->outBlock3[i].PchsAmt             ), DATA_TYPE_LONG   ) );  
			m_ctrlOutBlock3.SetItemText( nRow, nCol++, GetDispData( pAllOutBlock->outBlock3[i].StkConvEvalAmt   , sizeof( pAllOutBlock->outBlock3[i].StkConvEvalAmt      ), DATA_TYPE_LONG	 ) );                
			m_ctrlOutBlock3.SetItemText( nRow, nCol++, GetDispData( pAllOutBlock->outBlock3[i].ConvEvalPnlAmt   , sizeof( pAllOutBlock->outBlock3[i].ConvEvalPnlAmt      ), DATA_TYPE_LONG	 ) );               
			m_ctrlOutBlock3.SetItemText( nRow, nCol++, GetDispData( pAllOutBlock->outBlock3[i].FcurrBuyAmt      , sizeof( pAllOutBlock->outBlock3[i].FcurrBuyAmt         ), DATA_TYPE_DOT, 4 ) );    
			m_ctrlOutBlock3.SetItemText( nRow, nCol++, GetDispData( pAllOutBlock->outBlock3[i].FcurrOrdAbleAmt  , sizeof( pAllOutBlock->outBlock3[i].FcurrOrdAbleAmt     ), DATA_TYPE_DOT, 2 ) );       
			m_ctrlOutBlock3.SetItemText( nRow, nCol++, GetDispData( pAllOutBlock->outBlock3[i].LoanAmt          , sizeof( pAllOutBlock->outBlock3[i].LoanAmt             ), DATA_TYPE_LONG	 ) );   
		}

		//------------------------------------------------
		// OutBlock4
		LPBYTE				  lpData	 = pRpData->lpData;
		LPCOSOQ00201OutBlock4 pOutBlock4 = (LPCOSOQ00201OutBlock4)( lpData + nOffset );

		// Count ���
		nDataLength -= 5;
		if( nDataLength < 0 )
		{
			return 0L;
		}

		CopyMemory( szCount, pOutBlock4, 5 );
		nCount = atoi( szCount );
		nOffset += 5;

		// Data
		nDataLength -= sizeof( COSOQ00201OutBlock4 ) * nCount;
		if( nDataLength < 0 )
		{
			return 0L;
		}

		pOutBlock4 = (LPCOSOQ00201OutBlock4)( lpData + nOffset );
		for( int i=0; i<nCount; i++ )
		{
			nCol = 0;
			m_ctrlOutBlock4.InsertItem( i, "" );
			m_ctrlOutBlock4.SetItemText( i, nCol++, GetDispData( pOutBlock4[i].CrcyCode         , sizeof( pOutBlock4[i].CrcyCode            ), DATA_TYPE_STRING ) ); 
			m_ctrlOutBlock4.SetItemText( i, nCol++, GetDispData( pOutBlock4[i].ShtnIsuNo        , sizeof( pOutBlock4[i].ShtnIsuNo           ), DATA_TYPE_STRING ) ); 
			m_ctrlOutBlock4.SetItemText( i, nCol++, GetDispData( pOutBlock4[i].IsuNo            , sizeof( pOutBlock4[i].IsuNo               ), DATA_TYPE_STRING ) ); 
			m_ctrlOutBlock4.SetItemText( i, nCol++, GetDispData( pOutBlock4[i].JpnMktHanglIsuNm , sizeof( pOutBlock4[i].JpnMktHanglIsuNm    ), DATA_TYPE_STRING ) ); 
			m_ctrlOutBlock4.SetItemText( i, nCol++, GetDispData( pOutBlock4[i].AstkBalTpCode    , sizeof( pOutBlock4[i].AstkBalTpCode       ), DATA_TYPE_STRING ) ); 
			m_ctrlOutBlock4.SetItemText( i, nCol++, GetDispData( pOutBlock4[i].AstkBalTpCodeNm  , sizeof( pOutBlock4[i].AstkBalTpCodeNm     ), DATA_TYPE_STRING ) );  
			m_ctrlOutBlock4.SetItemText( i, nCol++, GetDispData( pOutBlock4[i].AstkBalQty       , sizeof( pOutBlock4[i].AstkBalQty          ), DATA_TYPE_DOT, 6 ) ); 
			m_ctrlOutBlock4.SetItemText( i, nCol++, GetDispData( pOutBlock4[i].AstkSellAbleQty  , sizeof( pOutBlock4[i].AstkSellAbleQty     ), DATA_TYPE_DOT, 6 ) );  
			m_ctrlOutBlock4.SetItemText( i, nCol++, GetDispData( pOutBlock4[i].FcstckUprc       , sizeof( pOutBlock4[i].FcstckUprc          ), DATA_TYPE_DOT, 4 ) ); 
			m_ctrlOutBlock4.SetItemText( i, nCol++, GetDispData( pOutBlock4[i].FcurrBuyAmt      , sizeof( pOutBlock4[i].FcurrBuyAmt         ), DATA_TYPE_DOT, 4 ) ); 
			m_ctrlOutBlock4.SetItemText( i, nCol++, GetDispData( pOutBlock4[i].FcstckMktIsuCode , sizeof( pOutBlock4[i].FcstckMktIsuCode    ), DATA_TYPE_STRING ) );    
			m_ctrlOutBlock4.SetItemText( i, nCol++, GetDispData( pOutBlock4[i].OvrsScrtsCurpri  , sizeof( pOutBlock4[i].OvrsScrtsCurpri     ), DATA_TYPE_DOT, 7 ) );       
			m_ctrlOutBlock4.SetItemText( i, nCol++, GetDispData( pOutBlock4[i].FcurrEvalAmt     , sizeof( pOutBlock4[i].FcurrEvalAmt        ), DATA_TYPE_DOT, 4 ) );   
			m_ctrlOutBlock4.SetItemText( i, nCol++, GetDispData( pOutBlock4[i].FcurrEvalPnlAmt  , sizeof( pOutBlock4[i].FcurrEvalPnlAmt     ), DATA_TYPE_DOT, 4 ) ); 
			m_ctrlOutBlock4.SetItemText( i, nCol++, GetDispData( pOutBlock4[i].PnlRat           , sizeof( pOutBlock4[i].PnlRat              ), DATA_TYPE_DOT, 6 ) );        
			m_ctrlOutBlock4.SetItemText( i, nCol++, GetDispData( pOutBlock4[i].BaseXchrat       , sizeof( pOutBlock4[i].BaseXchrat          ), DATA_TYPE_DOT, 4 ) );   
			m_ctrlOutBlock4.SetItemText( i, nCol++, GetDispData( pOutBlock4[i].PchsAmt          , sizeof( pOutBlock4[i].PchsAmt             ), DATA_TYPE_LONG	) );  
			m_ctrlOutBlock4.SetItemText( i, nCol++, GetDispData( pOutBlock4[i].DpsConvEvalAmt   , sizeof( pOutBlock4[i].DpsConvEvalAmt      ), DATA_TYPE_LONG	) ); 
			m_ctrlOutBlock4.SetItemText( i, nCol++, GetDispData( pOutBlock4[i].StkConvEvalAmt   , sizeof( pOutBlock4[i].StkConvEvalAmt      ), DATA_TYPE_LONG	) );  
			m_ctrlOutBlock4.SetItemText( i, nCol++, GetDispData( pOutBlock4[i].ConvEvalPnlAmt   , sizeof( pOutBlock4[i].ConvEvalPnlAmt      ), DATA_TYPE_LONG   ) ); 
			m_ctrlOutBlock4.SetItemText( i, nCol++, GetDispData( pOutBlock4[i].AstkSettQty      , sizeof( pOutBlock4[i].AstkSettQty         ), DATA_TYPE_DOT, 6 ) );  
			m_ctrlOutBlock4.SetItemText( i, nCol++, GetDispData( pOutBlock4[i].MktTpNm          , sizeof( pOutBlock4[i].MktTpNm             ), DATA_TYPE_STRING ) ); 
			m_ctrlOutBlock4.SetItemText( i, nCol++, GetDispData( pOutBlock4[i].FcurrMktCode     , sizeof( pOutBlock4[i].FcurrMktCode        ), DATA_TYPE_STRING ) ); 
			m_ctrlOutBlock4.SetItemText( i, nCol++, GetDispData( pOutBlock4[i].LoanDt           , sizeof( pOutBlock4[i].LoanDt              ), DATA_TYPE_STRING ) ); 
			m_ctrlOutBlock4.SetItemText( i, nCol++, GetDispData( pOutBlock4[i].LoanDtlClssCode  , sizeof( pOutBlock4[i].LoanDtlClssCode     ), DATA_TYPE_STRING ) ); 
			m_ctrlOutBlock4.SetItemText( i, nCol++, GetDispData( pOutBlock4[i].LoanAmt          , sizeof( pOutBlock4[i].LoanAmt             ), DATA_TYPE_LONG	) );   
			m_ctrlOutBlock4.SetItemText( i, nCol++, GetDispData( pOutBlock4[i].DueDt		    , sizeof( pOutBlock4[i].DueDt			    ), DATA_TYPE_STRING ) );  
			m_ctrlOutBlock4.SetItemText( i, nCol++, GetDispData( pOutBlock4[i].AstkBasePrc      , sizeof( pOutBlock4[i].AstkBasePrc         ), DATA_TYPE_DOT, 6 ) );  
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
LRESULT CDlg_COSOQ00201::OnXMTimeoutData( WPARAM wParam, LPARAM lParam )
{
	g_iXingAPI.ReleaseRequestData( (int)lParam );
	GetParent()->SendMessage( WMU_SET_MESSAGE, (WPARAM)"", (LPARAM)"Timeout" );		

	return 0L;
}
