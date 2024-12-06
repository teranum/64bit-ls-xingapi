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
// 컨트롤 초기화
//--------------------------------------------------------------------------------------
void CDlg_COSOQ00201::InitCtrls()
{
	int nCol;

	//-------------------------------------------------------------------------
	// InBlock : 기본값 세팅

	// 계좌번호 세팅
	char szAccount[20];
	int nCount = g_iXingAPI.GetAccountListCount();
	for( int i=0; i<nCount; i++ )
	{
		if( g_iXingAPI.GetAccountList( i, szAccount, sizeof( szAccount ) ) )
		{
			((CComboBox*)GetDlgItem( IDC_INBLOCK_ACNTNO ))->AddString( szAccount );
		}	
	}

	((CComboBox*)GetDlgItem( IDC_INBLOCK_ACNTNO         ))->SetCurSel( 0 );	// 계좌번호 

	//-------------------------------------------------------------------------
	// OutBlock1
	nCol = 0;
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "레코드갯수         ", FALSE,    8	);         
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "계좌번호           ", TRUE ,    10	);        
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "비밀번호           ", TRUE ,    8	);      
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "기준일자           ", TRUE ,    8	);        
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "통화코드           ", TRUE ,    8	);   
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "해외증권잔고구분코드", TRUE ,    16 );    


	//-------------------------------------------------------------------------
	// OutBlock2
	nCol = 0;
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "레코드갯수                  ",	FALSE,	8	);                 
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "수익율                      ",	TRUE ,	12	);                    
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "예수금환상평가금액           ",	TRUE ,	15	);                        
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "주식환산평가금액             ",	FALSE,	12	);            
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "예탁자산환산평가금액         ",	FALSE,	15	);             
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "원화평가합계금액             ",	FALSE,	15	);                      
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "환산평가손익금액             ",	FALSE,	15	);                       
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "원화예수금잔고금액           ",	FALSE,	15	);    
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "D2추정예수금                ",	FALSE,	15	);    
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "대출금액                    ",	FALSE,	12	);                             

	//-------------------------------------------------------------------------
	// OutBlock3
	nCol = 0;
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "통화코드          ",	TRUE ,	8	);            
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "외화예수금        ",	TRUE ,	15	);                
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "외화평가금액      ",	TRUE ,	15	);   
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "외화평가손익금액   ",	TRUE,	15	);    
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "손익율            ",	FALSE,	12	);
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "기준환율          ",	FALSE,	12	);        
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "예수금환산평가금액 ",	FALSE,	15	);     
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "매입금액          ",	FALSE,	15	);      
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "주식환산평가금액   ",	FALSE,	15	);                 
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "환산평가손익금액   ",	FALSE,	15	);            
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "외화매수금액       ",	FALSE,	15	);            
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "외화주문가능금액   ",	FALSE,	15	);      
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "대출금액          ",	FALSE,	12	);                  

	//-------------------------------------------------------------------------
	// OutBlock4
	nCol = 0;
	InsertColumn4List( this, IDC_OUTBLOCK4, nCol++, "통화코드             ",	TRUE ,	8	);            
	InsertColumn4List( this, IDC_OUTBLOCK4, nCol++, "단축종목번호         ",	TRUE ,	10	);   
	InsertColumn4List( this, IDC_OUTBLOCK4, nCol++, "종목번호             ",	TRUE ,	12	);   
	InsertColumn4List( this, IDC_OUTBLOCK4, nCol++, "일본시장한글종목명    ",	TRUE ,	20	);   
	InsertColumn4List( this, IDC_OUTBLOCK4, nCol++, "해외증권잔고구분코드  ",	TRUE ,	12	);   
	InsertColumn4List( this, IDC_OUTBLOCK4, nCol++, "해외증권잔고구분코드명",	TRUE ,	20	);   
	InsertColumn4List( this, IDC_OUTBLOCK4, nCol++, "해외증권잔고수량      ",	TRUE ,	20	);   
	InsertColumn4List( this, IDC_OUTBLOCK4, nCol++, "해외증권매도가능수량  ",	TRUE ,	20	);   
	InsertColumn4List( this, IDC_OUTBLOCK4, nCol++, "외화증권단가         ",	TRUE ,	15	);   
	InsertColumn4List( this, IDC_OUTBLOCK4, nCol++, "외화매수금액         ",	TRUE ,	15	);   
	InsertColumn4List( this, IDC_OUTBLOCK4, nCol++, "외화증권시장종목코드  ",	TRUE ,	15	);   
	InsertColumn4List( this, IDC_OUTBLOCK4, nCol++, "해외증권시세         ",	TRUE ,	20	);   
	InsertColumn4List( this, IDC_OUTBLOCK4, nCol++, "외화평가금액         ",	TRUE ,	20	);   
	InsertColumn4List( this, IDC_OUTBLOCK4, nCol++, "외화평가손익금액     ",	TRUE ,	20	);   
	InsertColumn4List( this, IDC_OUTBLOCK4, nCol++, "손익율              ",	TRUE ,	12	);   
	InsertColumn4List( this, IDC_OUTBLOCK4, nCol++, "기준환율            ",	TRUE ,	12	);   
	InsertColumn4List( this, IDC_OUTBLOCK4, nCol++, "매입금액            ",	TRUE ,	12	);   
	InsertColumn4List( this, IDC_OUTBLOCK4, nCol++, "예수금환산평가금액   ",	TRUE ,	12	);   
	InsertColumn4List( this, IDC_OUTBLOCK4, nCol++, "주식환산평가금액     ",	TRUE ,	12	);   
	InsertColumn4List( this, IDC_OUTBLOCK4, nCol++, "환산평가손익금액     ",	TRUE ,	12	);   
	InsertColumn4List( this, IDC_OUTBLOCK4, nCol++, "해외증권결제수량     ",	TRUE ,	15	);   
	InsertColumn4List( this, IDC_OUTBLOCK4, nCol++, "시장구분명           ",	TRUE ,	12	);   
	InsertColumn4List( this, IDC_OUTBLOCK4, nCol++, "외화시장코드         ",	TRUE ,	12	);   
	InsertColumn4List( this, IDC_OUTBLOCK4, nCol++, "대출일자            ",	TRUE ,	12	);   
	InsertColumn4List( this, IDC_OUTBLOCK4, nCol++, "대출상세분류코드     ",	TRUE ,	12	);   
	InsertColumn4List( this, IDC_OUTBLOCK4, nCol++, "대출금액            ",	TRUE ,	12	);   
	InsertColumn4List( this, IDC_OUTBLOCK4, nCol++, "만기일자            ",	TRUE ,	12	);   
	InsertColumn4List( this, IDC_OUTBLOCK4, nCol++, "해외증권기준가격     ",	TRUE ,	15	);   

  

	ZeroMemory( m_szContKey, sizeof( m_szContKey ) );
}

//--------------------------------------------------------------------------------------
// 데이터 조회
//--------------------------------------------------------------------------------------
void CDlg_COSOQ00201::RequestData( BOOL bNext )
{
	//-----------------------------------------------------------
	// 해외주식종합잔고평가(COSOQ00201) ( base21=SONAT000,headtype=B )
	COSOQ00201InBlock1	pckInBlock;

	TCHAR			szTrNo[]		= "COSOQ00201";

	//-----------------------------------------------------------
	// 데이터 취득
	CString strAcntNo        ;		GetDlgItemText( IDC_INBLOCK_ACNTNO        , strAcntNo        );    // [long  ,    5] 계좌번호        
	CString strPwd           ;		GetDlgItemText( IDC_INBLOCK_PWD           , strPwd           );    // [string,   20] 비밀번호          
	CString strBaseDt        ;		GetDlgItemText( IDC_INBLOCK_BASEDT        , strBaseDt        );    // [string,    8] 기준일자          
	CString strCrcyCode      ;		GetDlgItemText( IDC_INBLOCK_CRCYCODE      , strCrcyCode      );    // [string,    3] 통화코드      
	CString strAstkBalTpCode ;		GetDlgItemText( IDC_INBLOCK_ASTKBALTPCODE , strAstkBalTpCode );    // [string,    2] 해외증권잔고구분코드


	//-----------------------------------------------------------
	// 데이터 초기화
	FillMemory( &pckInBlock, sizeof( pckInBlock ), ' ' );

	//-----------------------------------------------------------
	// 데이터 입력
	SetPacketData( pckInBlock.RecCnt        , sizeof( pckInBlock.RecCnt        ), "1"              , DATA_TYPE_LONG         );    // [long  ,    5] 레코드갯수        
	SetPacketData( pckInBlock.AcntNo        , sizeof( pckInBlock.AcntNo        ), strAcntNo        , DATA_TYPE_STRING       );    // [string,   20] 계좌번호          
	SetPacketData( pckInBlock.Pwd           , sizeof( pckInBlock.Pwd           ), strPwd           , DATA_TYPE_STRING       );    // [string,    8] 비밀번호          
	SetPacketData( pckInBlock.BaseDt        , sizeof( pckInBlock.BaseDt        ), strBaseDt        , DATA_TYPE_STRING       );    // [string,    8] 기준일자      
	SetPacketData( pckInBlock.CrcyCode      , sizeof( pckInBlock.CrcyCode      ), strCrcyCode      , DATA_TYPE_STRING       );    // [string,    3] 통화코드    
	SetPacketData( pckInBlock.AstkBalTpCode , sizeof( pckInBlock.AstkBalTpCode ), strAstkBalTpCode , DATA_TYPE_STRING       );    // [string,    2] 해외증권잔고구분코드


	//-----------------------------------------------------------
	// 데이터 전송
	int nRqID = g_iXingAPI.Request( 
		GetSafeHwnd(),				// 데이터를 받을 윈도우, XM_RECEIVE_DATA 으로 온다.
		szTrNo,						// TR 번호
		&pckInBlock,				// InBlock 데이터
		sizeof( pckInBlock ),		// InBlock 데이터 크기
		bNext,						// 다음조회 여부 : 다음조회일 경우에 세팅한다.
		bNext ? m_szContKey : "",	// 다음조회 Key : Header Type이 B 일 경우엔 이전 조회때 받은 Next Key를 넣어준다.
		30							// Timeout(초) : 해당 시간(초)동안 데이터가 오지 않으면 Timeout에 발생한다. XM_TIMEOUT_DATA 메시지가 발생한다.
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
	// Request ID가 0보다 작을 경우에는 에러이다.
	if( nRqID < 0 )
	{
		MessageBox( "조회실패", "에러", MB_ICONSTOP );
	}
}

//--------------------------------------------------------------------------------------
// 데이터를 받음
//--------------------------------------------------------------------------------------
LRESULT CDlg_COSOQ00201::OnXMReceiveData( WPARAM wParam, LPARAM lParam )
{
	//-------------------------------------------------------------------------------------
	// Data를 받음
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

		// 연속키를 저장한다.
		strcpy_s( m_szContKey, pRpData->szContKey );

		//------------------------------------------------
		// OutBlock1

		// 받은 데이터 크기가 Block 크기보다 작다면 처리하지 않는다.
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

		// Count 계산
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

		// Count 계산
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
	// 메시지를 받음
	else if( wParam == MESSAGE_DATA )
	{
		LPMSG_PACKET pMsg = (LPMSG_PACKET)lParam;

		CString strMsg( (char*)pMsg->lpszMessageData, pMsg->nMsgLength );
		GetParent()->SendMessage( WMU_SET_MESSAGE, (WPARAM)pMsg->szMsgCode, (LPARAM)(LPCTSTR)strMsg );		

		g_iXingAPI.ReleaseMessageData( lParam );
	}

	//-------------------------------------------------------------------------------------
	// System Error를 받음
	else if( wParam == SYSTEM_ERROR_DATA )
	{
		LPMSG_PACKET pMsg = (LPMSG_PACKET)lParam;

		CString strMsg( (char*)pMsg->lpszMessageData, pMsg->nMsgLength );
		GetParent()->SendMessage( WMU_SET_MESSAGE, (WPARAM)pMsg->szMsgCode, (LPARAM)(LPCTSTR)strMsg );		

		g_iXingAPI.ReleaseMessageData( lParam );
	}

	//-------------------------------------------------------------------------------------
	// Release Data를 받음
	else if( wParam == RELEASE_DATA )
	{
		g_iXingAPI.ReleaseRequestData( (int)lParam );
	}

	return 0L;
}

//--------------------------------------------------------------------------------------
// Timeout 발생
//--------------------------------------------------------------------------------------
LRESULT CDlg_COSOQ00201::OnXMTimeoutData( WPARAM wParam, LPARAM lParam )
{
	g_iXingAPI.ReleaseRequestData( (int)lParam );
	GetParent()->SendMessage( WMU_SET_MESSAGE, (WPARAM)"", (LPARAM)"Timeout" );		

	return 0L;
}
