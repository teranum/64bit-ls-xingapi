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
// 컨트롤 초기화
//--------------------------------------------------------------------------------------
void CDlg_COSAQ00102::InitCtrls()
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
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "레코드갯수         ",	FALSE,   8 );   
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "조회구분코드       ",	TRUE ,   8 );    
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "역순구분코드       ",	TRUE ,   8 );   
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "주문시장코드       ",	TRUE ,   8 );   
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "계좌번호           ",	TRUE ,   12 );    
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "비밀번호           ",	TRUE ,   8 );    
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "매매구분코드       ",	TRUE ,   8 );    
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "종목번호           ",	TRUE ,   12 );     
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "시작주문번호       ",	FALSE,   8 );   
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "주문일자           ",	TRUE ,   8 );    
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "체결여부           ",	TRUE ,   6 );  
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "통화코드           ",	TRUE ,   6 );  
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "당일매매적용여부    ",	TRUE ,   8 );  
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "대출잔고보유여부    ",	TRUE ,   8 );    

	//-------------------------------------------------------------------------
	// OutBlock2
	nCol = 0;
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "레코드갯수           ",		FALSE ,	 8 );   
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "계좌명               ",		TRUE  , 20 );    
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "일본시장한글종목명    ",		TRUE  , 50 );   
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "관리지점명            ",	TRUE  , 20 );   
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "매도체결외화금액      ",		FALSE , 15 );    
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "매도체결수량          ",	FALSE , 12 );    
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "매수체결외화금액      ",		FALSE , 15 );    
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "매수체결수량         ",		FALSE ,	12 );   

	//-------------------------------------------------------------------------
	// OutBlock3
	nCol = 0;
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "관리지점번호         ",	TRUE ,	12	);
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "계좌번호             ",	TRUE ,	12	);
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "계좌명               ",	TRUE ,	20	);
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "체결시각             ",	TRUE ,	8	);
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "주문시각             ",	TRUE ,	8	);
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "주문번호             ",	FALSE,	12	);
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "원주문번호           ",	FALSE,	12	);
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "단축종목번호         ", TRUE ,	12	);
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "주문처리유형명       ", TRUE ,	25	);
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "주문처리유형코드     ", TRUE ,	12	);
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "정정취소가능수량     ",	FALSE,	12	);
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "주문수량             ",	FALSE,  12	);
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "체결수량             ",	FALSE,  15	);
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "해외체결가           ",	FALSE,  12	);
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "해외주문가           ",	FALSE,	18	);
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "호가유형코드         ",	TRUE ,	8	);
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "호가유형명           ",	TRUE ,  20	);
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "주문유형명           ",	TRUE ,  20	);
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "주문유형코드         ",	TRUE ,  8	);
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "정정취소구분코드     ",	TRUE ,  8	);
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "정정취소구분명       ",	TRUE ,  10	);
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "전체체결수량         ",	FALSE,  12	);
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "통신매체코드         ",	FALSE,  8	);
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "주문시장코드         ",	TRUE ,  8	);
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "시장명               ",	TRUE ,  40	);
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "통신매체명           ",	TRUE ,  40	);
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "일본시장한글종목명    ",	TRUE ,  40	);
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "미체결수량           ",	TRUE ,  12	);
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "확인수량             ",	TRUE ,  12	);
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "통화코드             ",	TRUE ,  8	);
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "등록시장코드         ",	TRUE ,  8	);
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "종목번호             ",	TRUE ,  8	);
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "중개인구분코드       ",	TRUE ,  8	);
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "상대중개인명         ",	TRUE ,  20	);
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "매매구분코드         ",	TRUE ,  8	);
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "대출일자             ",	TRUE ,  8	);
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "대출금액             ",	FALSE , 12	); 

	ZeroMemory( m_szContKey, sizeof( m_szContKey ) );
	GetDlgItem( IDC_BUTTON_REQUEST_NEXT )->EnableWindow( FALSE );
}

//--------------------------------------------------------------------------------------
// 데이터 조회
//--------------------------------------------------------------------------------------
void CDlg_COSAQ00102::RequestData( BOOL bNext )
{
	//-----------------------------------------------------------
	COSAQ00102InBlock1	pckInBlock;

	TCHAR			szTrNo[]		= "COSAQ00102";
	char			szNextKey[]		= "";

	//-----------------------------------------------------------
	// 데이터 취득

	CString strQryTpCode ;		GetDlgItemText( IDC_INBLOCK_QRYTPCODE     , strQryTpCode     );    // [string,    1] 조회구분코드 
	CString strBkseqTpCode;		GetDlgItemText( IDC_INBLOCK_BKSEQTPCODE   , strBkseqTpCode   );    // [string,    1] 역순구분코드  
	CString strOrdMktCode ;		GetDlgItemText( IDC_INBLOCK_ORDMKTCODE    , strOrdMktCode    );    // [string,    2] 주문시장코드 
	CString strAcntNo     ;		GetDlgItemText( IDC_INBLOCK_ACNTNO        , strAcntNo        );    // [string,   20] 계좌번호
	CString strInptPwd    ;		GetDlgItemText( IDC_INBLOCK_INPTPWD       , strInptPwd       );    // [string,    8] 입력비밀번호 
	CString strBnsTpCode  ;		GetDlgItemText( IDC_INBLOCK_BNSTPCODE     , strBnsTpCode     );    // [string,    1] 매매구분     
	CString strIsuNo      ;		GetDlgItemText( IDC_INBLOCK_ISUNO         , strIsuNo         );    // [string,   12] 종목번호     
	CString strSrtOrdNo  ;		GetDlgItemText( IDC_INBLOCK_SRTORDNO2     , strSrtOrdNo      );    // [long  ,   10] 시작주문번호
	CString strOrdDt      ;		GetDlgItemText( IDC_INBLOCK_ORDDT         , strOrdDt         );    // [string,    8] 주문일자      
	CString strExecYn     ;		GetDlgItemText( IDC_INBLOCK_EXECYN        , strExecYn        );    // [string,    1] 체결여부 
	CString strCrcyCode;		GetDlgItemText( IDC_INBLOCK_CRCYCODE      , strCrcyCode      );    // [string,    3] 통화코드     
	CString strThdayBnsAppYn ;	GetDlgItemText( IDC_INBLOCK_THDAYBNSAPPYN , strThdayBnsAppYn );    // [string,    1] 당일매매적용여부 
	CString strLoanBalHldYn ;	GetDlgItemText( IDC_INBLOCK_LOANBALHLDYN  , strLoanBalHldYn  );    // [string,    1] 대출잔고보유여부 
	//-----------------------------------------------------------
	// 데이터 초기화
	FillMemory( &pckInBlock, sizeof( pckInBlock ), ' ' );

	//-----------------------------------------------------------
	// 데이터 입력
	SetPacketData( pckInBlock.RecCnt        , sizeof( pckInBlock.RecCnt        ), "1"           , DATA_TYPE_LONG   );    // [long  ,    5] 레코드갯수
	SetPacketData( pckInBlock.QryTpCode     , sizeof( pckInBlock.QryTpCode     ) , strQryTpCode , DATA_TYPE_STRING );    // [string,    1] 조회구분코드
	SetPacketData( pckInBlock.BkseqTpCode   , sizeof( pckInBlock.BkseqTpCode   ), strBkseqTpCode, DATA_TYPE_STRING );    // [string,    1] 역순구분코드
	SetPacketData( pckInBlock.OrdMktCode    , sizeof( pckInBlock.OrdMktCode    ), strOrdMktCode , DATA_TYPE_STRING );    // [string,    2] 주문시장코드 
	SetPacketData( pckInBlock.AcntNo        , sizeof( pckInBlock.AcntNo        ), strAcntNo     , DATA_TYPE_STRING );    // [string,   20] 계좌번호    
	SetPacketData( pckInBlock.Pwd           , sizeof( pckInBlock.Pwd           ), strInptPwd    , DATA_TYPE_STRING );    // [string,    8] 비밀번호 
	SetPacketData( pckInBlock.BnsTpCode     , sizeof( pckInBlock.BnsTpCode     ), strBnsTpCode  , DATA_TYPE_STRING );    // [string,    1] 매매구분     
	SetPacketData( pckInBlock.IsuNo         , sizeof( pckInBlock.IsuNo         ), strIsuNo      , DATA_TYPE_STRING );    // [string,   12] 종목번호   
	SetPacketData( pckInBlock.SrtOrdNo      , sizeof( pckInBlock.SrtOrdNo      ), strSrtOrdNo   , DATA_TYPE_LONG   );    // [long  ,   10] 시작주문번호
	SetPacketData( pckInBlock.OrdDt         , sizeof( pckInBlock.OrdDt         ), strOrdDt      , DATA_TYPE_STRING );    // [string,    8] 주문일자       
	SetPacketData( pckInBlock.ExecYn        , sizeof( pckInBlock.ExecYn        ), strExecYn     , DATA_TYPE_STRING );    // [string,    1] 체결여부     
	SetPacketData( pckInBlock.CrcyCode      , sizeof( pckInBlock.CrcyCode      ), strCrcyCode   , DATA_TYPE_STRING );    // [string,    3] 통화코드
	SetPacketData( pckInBlock.ThdayBnsAppYn , sizeof( pckInBlock.ThdayBnsAppYn ), strThdayBnsAppYn , DATA_TYPE_STRING );    // [string,    1] 당일매매적용여부 
	SetPacketData( pckInBlock.LoanBalHldYn  , sizeof( pckInBlock.LoanBalHldYn  ), strLoanBalHldYn , DATA_TYPE_STRING );    // [string,    1] 대출잔고보유여부 
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
LRESULT CDlg_COSAQ00102::OnXMReceiveData( WPARAM wParam, LPARAM lParam )
{
	//-------------------------------------------------------------------------------------
	// Data를 받음
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

		// 연속키를 저장한다.
		strcpy_s( m_szContKey, pRpData->szContKey );
		GetDlgItem( IDC_BUTTON_REQUEST_NEXT )->EnableWindow( pRpData->cCont[0] == 'Y' );

		//------------------------------------------------
		// OutBlock1

		// 받은 데이터 크기가 Block 크기보다 작다면 처리하지 않는다.
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

		// Count 계산
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
LRESULT CDlg_COSAQ00102::OnXMTimeoutData( WPARAM wParam, LPARAM lParam )
{
	g_iXingAPI.ReleaseRequestData( (int)lParam );
	GetParent()->SendMessage( WMU_SET_MESSAGE, (WPARAM)"", (LPARAM)"Timeout" );		

	return 0L;
}
