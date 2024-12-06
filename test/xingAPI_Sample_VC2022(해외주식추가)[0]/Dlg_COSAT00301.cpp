// Dlg_COSAT00301.cpp : implementation file
//

#include "stdafx.h"
#include "xingapi_sample.h"
#include "Dlg_COSAT00301.h"

#include "./Packet/COSAT00301.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlg_COSAT00301 dialog


IMPLEMENT_DYNCREATE(CDlg_COSAT00301, CDialog)

CDlg_COSAT00301::CDlg_COSAT00301(CWnd* pParent /*=NULL*/)
	: CDialog(CDlg_COSAT00301::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlg_COSAT00301)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CDlg_COSAT00301::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlg_COSAT00301)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
	DDX_Control(pDX, IDC_OUTBLOCK1, m_ctrlOutBlock1);
	DDX_Control(pDX, IDC_OUTBLOCK2, m_ctrlOutBlock2);
}


BEGIN_MESSAGE_MAP(CDlg_COSAT00301, CDialog)
	//{{AFX_MSG_MAP(CDlg_COSAT00301)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
	ON_BN_CLICKED( IDC_BUTTON_REQUEST,		  OnButtonRequest	  )
	ON_MESSAGE	 ( WM_USER + XM_RECEIVE_DATA, OnXMReceiveData	  )
	ON_MESSAGE	 ( WM_USER + XM_TIMEOUT_DATA, OnXMTimeoutData	  )
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlg_COSAT00301 message handlers

BOOL CDlg_COSAT00301::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	InitCtrls();
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CDlg_COSAT00301::OnButtonRequest() 
{
	RequestData();
}


//--------------------------------------------------------------------------------------
// 컨트롤 초기화
//--------------------------------------------------------------------------------------
void CDlg_COSAT00301::InitCtrls()
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

	((CComboBox*)GetDlgItem( IDC_INBLOCK_ACNTNO        ))->SetCurSel( 0 );	// 계좌번호                  

	//-------------------------------------------------------------------------
	// OutBlock1
	nCol = 0;
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "레코드갯수         ",	FALSE,	10	);
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "주문유형코드       ",	TRUE ,	12	);
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "원주문번호         ",	FALSE,	10	);
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "계좌번호           ",	TRUE ,  8	);
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "입력비밀번호       ",	TRUE ,  12	);
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "주문시장코드       ",	TRUE ,  12	);
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "종목번호           ",	TRUE ,  8	);
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "주문수량           ",	TRUE ,	8	);
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "해외주문가         ",	FALSE,	16	);
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "호가유형코드       ",	TRUE ,  8	);
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "등록통신매체코드    ",	TRUE ,	8	);
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "중개인구분코드      ",	TRUE ,	8	);

	//-------------------------------------------------------------------------
	// OutBlock2
	nCol = 0;
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "레코드갯수      ",	FALSE,	10	);
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "주문번호        ",	FALSE,	8	);
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "계좌명         ",	TRUE ,	8	);
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "종목명         ",	TRUE ,	20	);
}

//--------------------------------------------------------------------------------------
// 데이터 조회
//--------------------------------------------------------------------------------------
void CDlg_COSAT00301::RequestData( BOOL bNext )
{
	//-----------------------------------------------------------
// 현물정상주문(COSAT00301) ( base21=SONAT000,headtype=B )
	COSAT00301InBlock1	pckInBlock;

	TCHAR			szTrNo[]		= "COSAT00301";
	char			szNextKey[]		= "";

	//-----------------------------------------------------------
	// 데이터 취득
    CString strOrdPtnCode   ;		GetDlgItemText( IDC_INBLOCK_ORDPTNCODE   , strOrdPtnCode    );		// 주문유형코드                   
	CString strOrgOrdNo     ;		GetDlgItemText( IDC_INBLOCK_ORGORDNO     , strOrgOrdNo      );		// 원주문번호
    CString strAcntNo       ;		GetDlgItemText( IDC_INBLOCK_ACNTNO       , strAcntNo        );		// 계좌번호                     
    CString strInptPwd      ;		GetDlgItemText( IDC_INBLOCK_PWD          , strInptPwd       );		// 입력비밀번호                   
	CString strOrdMktCode   ;		GetDlgItemText( IDC_INBLOCK_ORDMKTCODE   , strOrdMktCode    );		// 주문시장코드
    CString strIsuNo        ;		GetDlgItemText( IDC_INBLOCK_ISUNO        , strIsuNo         );		// 종목번호                   
    CString strOrdQty       ;		GetDlgItemText( IDC_INBLOCK_ORDQTY       , strOrdQty        );		// 주문수량                       
    CString strOrdPrc       ;		GetDlgItemText( IDC_INBLOCK_ORDPRC       , strOrdPrc        );		// 해외주문가                      
    CString strOrdprcPtnCode;		GetDlgItemText( IDC_INBLOCK_ORDPRCPTNCODE, strOrdprcPtnCode );		// 호가유형코드                 
	CString strBrkTpCode	;		GetDlgItemText( IDC_INBLOCK_BRKTPCODE	 , strBrkTpCode		 );		// 중개인구분코드   

	//-----------------------------------------------------------
	// 데이터 초기화
	FillMemory( &pckInBlock, sizeof( pckInBlock ), ' ' );

	//-----------------------------------------------------------
	// 데이터 입력
	SetPacketData( pckInBlock.RecCnt        , sizeof( pckInBlock.RecCnt       ), "1"              , DATA_TYPE_LONG   );
	SetPacketData( pckInBlock.OrdPtnCode    , sizeof( pckInBlock.OrdPtnCode   ), strOrdPtnCode    , DATA_TYPE_STRING );		           
	SetPacketData( pckInBlock.OrgOrdNo      , sizeof( pckInBlock.OrgOrdNo     ), strOrgOrdNo      , DATA_TYPE_LONG   );		     
	SetPacketData( pckInBlock.AcntNo        , sizeof( pckInBlock.AcntNo       ), strAcntNo        , DATA_TYPE_STRING );		            
	SetPacketData( pckInBlock.InptPwd       , sizeof( pckInBlock.InptPwd      ), strInptPwd       , DATA_TYPE_STRING );		             
	SetPacketData( pckInBlock.OrdMktCode    , sizeof( pckInBlock.OrdMktCode   ), strOrdMktCode    , DATA_TYPE_STRING );	
	SetPacketData( pckInBlock.IsuNo         , sizeof( pckInBlock.IsuNo        ), strIsuNo         , DATA_TYPE_STRING );		  
	SetPacketData( pckInBlock.OrdQty        , sizeof( pckInBlock.OrdQty       ), strOrdQty        , DATA_TYPE_LONG   );	
	SetPacketData( pckInBlock.OvrsOrdPrc    , sizeof( pckInBlock.OvrsOrdPrc   ), strOrdPrc        , DATA_TYPE_DOT, 7 );		
	SetPacketData( pckInBlock.OrdprcPtnCode , sizeof( pckInBlock.OrdprcPtnCode), strOrdprcPtnCode , DATA_TYPE_STRING );	
	SetPacketData( pckInBlock.BrkTpCode		, sizeof( pckInBlock.BrkTpCode	  ), strBrkTpCode	  , DATA_TYPE_STRING );	

	//-----------------------------------------------------------
	// 데이터 전송
	int nRqID = g_iXingAPI.Request( 
		GetSafeHwnd(),				// 데이터를 받을 윈도우, XM_RECEIVE_DATA 으로 온다.
		szTrNo,						// TR 번호
		&pckInBlock,				// InBlock 데이터
		sizeof( pckInBlock ),		// InBlock 데이터 크기
		bNext,						// 다음조회 여부 : 다음조회일 경우에 세팅한다.
		szNextKey,					// 다음조회 Key : Header Type이 B 일 경우엔 이전 조회때 받은 Next Key를 넣어준다.
		30							// Timeout(초) : 해당 시간(초)동안 데이터가 오지 않으면 Timeout에 발생한다. XM_TIMEOUT_DATA 메시지가 발생한다.
	);

	m_ctrlOutBlock1.DeleteAllItems();
	m_ctrlOutBlock2.DeleteAllItems();

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
LRESULT CDlg_COSAT00301::OnXMReceiveData( WPARAM wParam, LPARAM lParam )
{
	//-------------------------------------------------------------------------------------
	// Data를 받음
	if( wParam == REQUEST_DATA )
	{
		LPRECV_PACKET pRpData = (LPRECV_PACKET)lParam;

		typedef struct
		{
			COSAT00301OutBlock1	outBlock1;
			COSAT00301OutBlock2	outBlock2;
		} COSAT00301AllOutBlock, *LPCOSAT00301AllOutBlock;

		LPCOSAT00301AllOutBlock pAllOutBlock = (LPCOSAT00301AllOutBlock)pRpData->lpData;

		// 받은 데이터 크기가 Block 크기보다 작다면 처리하지 않는다.
		if( pRpData->nDataLength >= sizeof( COSAT00301OutBlock1 ) )
		{
			int nCol = 0;
			m_ctrlOutBlock1.InsertItem( 0, "" );
			m_ctrlOutBlock1.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock1.RecCnt            , sizeof( pAllOutBlock->outBlock1.RecCnt             ), DATA_TYPE_LONG   ) );    // 레코드갯수          
			m_ctrlOutBlock1.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock1.OrdPtnCode        , sizeof( pAllOutBlock->outBlock1.OrdPtnCode         ), DATA_TYPE_STRING ) );    // 주문유형코드            
			m_ctrlOutBlock1.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock1.OrgOrdNo          , sizeof( pAllOutBlock->outBlock1.OrgOrdNo           ), DATA_TYPE_LONG   ) );    // 원주문번호        
			m_ctrlOutBlock1.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock1.AcntNo            , sizeof( pAllOutBlock->outBlock1.AcntNo             ), DATA_TYPE_STRING ) );    // 계좌번호            
			m_ctrlOutBlock1.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock1.InptPwd           , sizeof( pAllOutBlock->outBlock1.InptPwd            ), DATA_TYPE_STRING ) );    // 입력비밀번호            
			m_ctrlOutBlock1.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock1.OrdMktCode        , sizeof( pAllOutBlock->outBlock1.OrdMktCode         ), DATA_TYPE_STRING ) );    // 주문시장코드         
			m_ctrlOutBlock1.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock1.IsuNo             , sizeof( pAllOutBlock->outBlock1.IsuNo              ), DATA_TYPE_STRING ) );    // 종목번호            
			m_ctrlOutBlock1.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock1.OrdQty            , sizeof( pAllOutBlock->outBlock1.OrdQty             ), DATA_TYPE_LONG   ) );    // 주문수량        
			m_ctrlOutBlock1.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock1.OvrsOrdPrc        , sizeof( pAllOutBlock->outBlock1.OvrsOrdPrc         ), DATA_TYPE_DOT, 7 ) );    // 해외주문가
			m_ctrlOutBlock1.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock1.OrdprcPtnCode     , sizeof( pAllOutBlock->outBlock1.OrdprcPtnCode      ), DATA_TYPE_STRING ) );    // 호가유형코드      
			m_ctrlOutBlock1.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock1.RegCommdaCode     , sizeof( pAllOutBlock->outBlock1.RegCommdaCode      ), DATA_TYPE_STRING ) );    // 등록통신매체코드      
			m_ctrlOutBlock1.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock1.BrkTpCode         , sizeof( pAllOutBlock->outBlock1.BrkTpCode          ), DATA_TYPE_STRING ) );    // 중개인구분코드           
			
		}

		if( pRpData->nDataLength >= sizeof( COSAT00301OutBlock1 ) + sizeof( COSAT00301OutBlock2 ) )
		{
			int nCol = 0;
			m_ctrlOutBlock2.InsertItem( 0, "" );
			m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock2.RecCnt     , sizeof( pAllOutBlock->outBlock2.RecCnt      ), DATA_TYPE_LONG   ) );    // 레코드갯수       
			m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock2.OrdNo      , sizeof( pAllOutBlock->outBlock2.OrdNo       ), DATA_TYPE_LONG   ) );    // 주문번호         
			m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock2.AcntNm     , sizeof( pAllOutBlock->outBlock2.AcntNm      ), DATA_TYPE_STRING ) );    // 계좌명         
			m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock2.IsuNm      , sizeof( pAllOutBlock->outBlock2.IsuNm       ), DATA_TYPE_STRING ) );    // 종목명     
			
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
LRESULT CDlg_COSAT00301::OnXMTimeoutData( WPARAM wParam, LPARAM lParam )
{
	g_iXingAPI.ReleaseRequestData( (int)lParam );
	GetParent()->SendMessage( WMU_SET_MESSAGE, (WPARAM)"", (LPARAM)"Timeout" );		

	return 0L;
}
