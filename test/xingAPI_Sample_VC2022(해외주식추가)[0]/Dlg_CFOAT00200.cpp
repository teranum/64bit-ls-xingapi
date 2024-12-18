// Dlg_CFOAT00200.cpp : implementation file
//

#include "stdafx.h"
#include "xingapi_sample.h"
#include "Dlg_CFOAT00200.h"

#include "./Packet/CFOAT00200.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlg_CFOAT00200 dialog


IMPLEMENT_DYNCREATE(CDlg_CFOAT00200, CDialog)

CDlg_CFOAT00200::CDlg_CFOAT00200(CWnd* pParent /*=NULL*/)
	: CDialog(CDlg_CFOAT00200::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlg_CFOAT00200)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CDlg_CFOAT00200::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlg_CFOAT00200)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
	DDX_Control(pDX, IDC_OUTBLOCK1, m_ctrlOutBlock1);
	DDX_Control(pDX, IDC_OUTBLOCK2, m_ctrlOutBlock2);
}


BEGIN_MESSAGE_MAP(CDlg_CFOAT00200, CDialog)
	//{{AFX_MSG_MAP(CDlg_CFOAT00200)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
	ON_BN_CLICKED( IDC_BUTTON_REQUEST,		  OnButtonRequest	  )
	ON_MESSAGE	 ( WM_USER + XM_RECEIVE_DATA, OnXMReceiveData	  )
	ON_MESSAGE	 ( WM_USER + XM_TIMEOUT_DATA, OnXMTimeoutData	  )
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlg_CFOAT00200 message handlers

BOOL CDlg_CFOAT00200::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	InitCtrls();
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CDlg_CFOAT00200::OnButtonRequest() 
{
	RequestData();
}

//--------------------------------------------------------------------------------------
// 컨트롤 초기화
//--------------------------------------------------------------------------------------
void CDlg_CFOAT00200::InitCtrls()
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

	//-------------------------------------------------------------------------
	// OutBlock1
	nCol = 0;
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "레코드갯수          ", FALSE,    5 );    // [long  ,    5] 레코드갯수          
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "주문시장코드        ", TRUE ,    2 );    // [string,    2] 주문시장코드        
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "계좌번호            ", TRUE ,   20 );    // [string,   20] 계좌번호            
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "비밀번호            ", TRUE ,    8 );    // [string,    8] 비밀번호            
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "선물옵션종목번호    ", TRUE ,   12 );    // [string,   12] 선물옵션종목번호    
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "선물옵션주문유형코드", TRUE ,    2 );    // [string,    2] 선물옵션주문유형코드
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "원주문번호          ", FALSE,   10 );    // [long  ,   10] 원주문번호
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "선물옵션호가유형코드", TRUE ,    2 );    // [string,    2] 선물옵션호가유형코드
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "선물옵션주문가격    ", FALSE, 27.8 );    // [double, 27.8] 주문가격            
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "정정수량            ", FALSE,   16 );    // [long  ,   16] 정정수량            
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "통신매체코드        ", TRUE ,    2 );    // [string,    2] 통신매체코드        
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "협의매매완료시각    ", TRUE ,    9 );    // [string,    9] 협의매매완료시각    
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "그룹ID              ", TRUE ,   20 );    // [string,   20] 그룹ID              
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "주문일련번호        ", FALSE,   10 );    // [long  ,   10] 주문일련번호        
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "포트폴리오번호      ", FALSE,   10 );    // [long  ,   10] 포트폴리오번호      
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "바스켓번호          ", FALSE,   10 );    // [long  ,   10] 바스켓번호          
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "트렌치번호          ", FALSE,   10 );    // [long  ,   10] 트렌치번호          
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "아이템번호          ", FALSE,   16 );    // [long  ,   10] 아이템번호            
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "관리사원번호        ", TRUE ,    9 );    // [string,    9] 관리사원번호        
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "펀드ID              ", TRUE ,   12 );    // [string,   12] 펀드ID              
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "펀드원주문번호      ", FALSE,   10 );    // [long  ,   10] 펀드원주문번호        
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "펀드주문번호        ", FALSE,   10 );    // [long  ,   10] 펀드주문번호        

	//-------------------------------------------------------------------------
	// OutBlock2
	nCol = 0;
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "레코드갯수      ", FALSE,    5 );    // [long  ,    5] 레코드갯수      
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "주문번호        ", FALSE,   10 );    // [long  ,   10] 주문번호        
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "지점명          ", TRUE ,   40 );    // [string,   40] 지점명          
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "계좌명          ", TRUE ,   40 );    // [string,   40] 계좌명          
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "종목명          ", TRUE ,   50 );    // [string,   50] 종목명          
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "주문가능금액    ", FALSE,   16 );    // [long  ,   16] 주문가능금액    
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "현금주문가능금액", FALSE,   16 );    // [long  ,   16] 현금주문가능금액
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "주문증거금      ", FALSE,   16 );    // [long  ,   16] 주문증거금      
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "현금주문증거금  ", FALSE,   16 );    // [long  ,   16] 현금주문증거금  
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "주문가능수량    ", FALSE,   16 );    // [long  ,   16] 주문가능수량    
}

//--------------------------------------------------------------------------------------
// 데이터 조회
//--------------------------------------------------------------------------------------
void CDlg_CFOAT00200::RequestData( BOOL bNext )
{
	//-----------------------------------------------------------
// 현물정상주문(CFOAT00200) ( base21=SONAT000,headtype=B )
	CFOAT00200InBlock1	pckInBlock;

	TCHAR			szTrNo[]		= "CFOAT00200";
	char			szNextKey[]		= "";

	//-----------------------------------------------------------
	// 데이터 취득
    CString strAcntNo          ;	GetDlgItemText( IDC_INBLOCK_ACNTNO          , strAcntNo           );    
    CString strPwd             ;	GetDlgItemText( IDC_INBLOCK_PWD             , strPwd              );    
    CString strFnoIsuNo        ;	GetDlgItemText( IDC_INBLOCK_FNOISUNO        , strFnoIsuNo         );    
    CString strOrgOrdNo        ;	GetDlgItemText( IDC_INBLOCK_ORGORDNO        , strOrgOrdNo         );    
	CString strFnoOrdprcPtnCode;	GetDlgItemText( IDC_INBLOCK_FNOORDPRCPTNCODE, strFnoOrdprcPtnCode );    
    CString strOrdPrc          ;	GetDlgItemText( IDC_INBLOCK_ORDPRC          , strOrdPrc           );    
    CString strMdfyQty         ;	GetDlgItemText( IDC_INBLOCK_MDFYQTY         , strMdfyQty          );    

	//-----------------------------------------------------------
	// 데이터 초기화
	FillMemory( &pckInBlock, sizeof( pckInBlock ), ' ' );

	//-----------------------------------------------------------
	// 데이터 입력
	SetPacketData( pckInBlock.AcntNo          , sizeof( pckInBlock.AcntNo           ), strAcntNo          , DATA_TYPE_STRING );    // [string,   20] 계좌번호            
	SetPacketData( pckInBlock.Pwd             , sizeof( pckInBlock.Pwd              ), strPwd             , DATA_TYPE_STRING );    // [string,    8] 비밀번호            
	SetPacketData( pckInBlock.FnoIsuNo        , sizeof( pckInBlock.FnoIsuNo         ), strFnoIsuNo        , DATA_TYPE_STRING );    // [string,   12] 선물옵션종목번호    
	SetPacketData( pckInBlock.OrgOrdNo        , sizeof( pckInBlock.OrgOrdNo         ), strOrgOrdNo        , DATA_TYPE_LONG   );    // [long  ,   10] 원주문번호          
	SetPacketData( pckInBlock.FnoOrdprcPtnCode, sizeof( pckInBlock.FnoOrdprcPtnCode ), strFnoOrdprcPtnCode, DATA_TYPE_STRING );    // [string,    2] 선물옵션호가유형코드
	SetPacketData( pckInBlock.FnoOrdPrc       , sizeof( pckInBlock.FnoOrdPrc        ), strOrdPrc          , DATA_TYPE_DOT, 8 );    // [double, 27.8] 선물옵션주문가격            
	SetPacketData( pckInBlock.MdfyQty         , sizeof( pckInBlock.MdfyQty          ), strMdfyQty         , DATA_TYPE_LONG   );    // [long  ,   16] 정정수량            

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
		CString strMsg;
		strMsg.Format( "[%d] %s", nRqID, g_iXingAPI.GetErrorMessage( nRqID ) );
		MessageBox( strMsg, "조회실패", MB_ICONSTOP );
	}
}

//--------------------------------------------------------------------------------------
// 데이터를 받음
//--------------------------------------------------------------------------------------
LRESULT CDlg_CFOAT00200::OnXMReceiveData( WPARAM wParam, LPARAM lParam )
{
	//-------------------------------------------------------------------------------------
	// Data를 받음
	if( wParam == REQUEST_DATA )
	{
		typedef struct
		{
			CFOAT00200OutBlock1	outBlock1;
			CFOAT00200OutBlock2	outBlock2;
		} CFOAT00200AllOutBlock, *LPCFOAT00200AllOutBlock;
		
		LPRECV_PACKET			pRpData		 = (LPRECV_PACKET)lParam;
		LPCFOAT00200AllOutBlock pAllOutBlock = (LPCFOAT00200AllOutBlock)pRpData->lpData;
		int						nDataLength  = pRpData->nDataLength;
		int						nCol;
		
		//------------------------------------------------
		// OutBlock1
		nDataLength -= sizeof( CFOAT00200OutBlock1 );
		if( nDataLength < 0 )
		{
			return 0L;
		}
		
		nCol = 0;
		m_ctrlOutBlock1.InsertItem( 0, "" );
		m_ctrlOutBlock1.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock1.RecCnt           , sizeof( pAllOutBlock->outBlock1.RecCnt            ), DATA_TYPE_LONG   ) );    // [long  ,    5] 레코드갯수          
		m_ctrlOutBlock1.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock1.OrdMktCode       , sizeof( pAllOutBlock->outBlock1.OrdMktCode        ), DATA_TYPE_STRING ) );    // [string,    2] 주문시장코드        
		m_ctrlOutBlock1.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock1.AcntNo           , sizeof( pAllOutBlock->outBlock1.AcntNo            ), DATA_TYPE_STRING ) );    // [string,   20] 계좌번호            
		m_ctrlOutBlock1.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock1.Pwd              , sizeof( pAllOutBlock->outBlock1.Pwd               ), DATA_TYPE_STRING ) );    // [string,    8] 비밀번호            
		m_ctrlOutBlock1.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock1.FnoIsuNo         , sizeof( pAllOutBlock->outBlock1.FnoIsuNo          ), DATA_TYPE_STRING ) );    // [string,   12] 선물옵션종목번호    
		m_ctrlOutBlock1.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock1.FnoOrdPtnCode    , sizeof( pAllOutBlock->outBlock1.FnoOrdPtnCode     ), DATA_TYPE_STRING ) );    // [string,    2] 선물옵션주문유형코드  
		m_ctrlOutBlock1.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock1.OrgOrdNo         , sizeof( pAllOutBlock->outBlock1.OrgOrdNo          ), DATA_TYPE_LONG   ) );    // [long  ,   10] 원주문번호          
		m_ctrlOutBlock1.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock1.FnoOrdprcPtnCode , sizeof( pAllOutBlock->outBlock1.FnoOrdprcPtnCode  ), DATA_TYPE_STRING ) );    // [string,    2] 선물옵션호가유형코드
		m_ctrlOutBlock1.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock1.FnoOrdPrc        , sizeof( pAllOutBlock->outBlock1.FnoOrdPrc         ), DATA_TYPE_DOT, 8 ) );    // [double, 27.8] 선물옵션주문가격            
		m_ctrlOutBlock1.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock1.MdfyQty          , sizeof( pAllOutBlock->outBlock1.MdfyQty           ), DATA_TYPE_LONG   ) );    // [long  ,   16] 정정수량            
		m_ctrlOutBlock1.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock1.CommdaCode       , sizeof( pAllOutBlock->outBlock1.CommdaCode        ), DATA_TYPE_STRING ) );    // [string,    2] 통신매체코드        
		m_ctrlOutBlock1.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock1.DscusBnsCmpltTime, sizeof( pAllOutBlock->outBlock1.DscusBnsCmpltTime ), DATA_TYPE_STRING ) );    // [string,    9] 협의매매완료시각    
		m_ctrlOutBlock1.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock1.GrpId            , sizeof( pAllOutBlock->outBlock1.GrpId             ), DATA_TYPE_STRING ) );    // [string,   20] 그룹ID              
		m_ctrlOutBlock1.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock1.OrdSeqno         , sizeof( pAllOutBlock->outBlock1.OrdSeqno          ), DATA_TYPE_LONG   ) );    // [long  ,   10] 주문일련번호        
		m_ctrlOutBlock1.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock1.PtflNo           , sizeof( pAllOutBlock->outBlock1.PtflNo            ), DATA_TYPE_LONG   ) );    // [long  ,   10] 포트폴리오번호      
		m_ctrlOutBlock1.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock1.BskNo            , sizeof( pAllOutBlock->outBlock1.BskNo             ), DATA_TYPE_LONG   ) );    // [long  ,   10] 바스켓번호          
		m_ctrlOutBlock1.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock1.TrchNo           , sizeof( pAllOutBlock->outBlock1.TrchNo            ), DATA_TYPE_LONG   ) );    // [long  ,   10] 트렌치번호          
		m_ctrlOutBlock1.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock1.ItemNo           , sizeof( pAllOutBlock->outBlock1.ItemNo            ), DATA_TYPE_LONG   ) );    // [long  ,   10] 아이템번호          
		m_ctrlOutBlock1.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock1.MgempNo          , sizeof( pAllOutBlock->outBlock1.MgempNo           ), DATA_TYPE_STRING ) );    // [string,    9] 관리사원번호        
		m_ctrlOutBlock1.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock1.FundId           , sizeof( pAllOutBlock->outBlock1.FundId            ), DATA_TYPE_STRING ) );    // [string,   12] 펀드ID              
		m_ctrlOutBlock1.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock1.FundOrgOrdNo     , sizeof( pAllOutBlock->outBlock1.FundOrgOrdNo      ), DATA_TYPE_LONG   ) );    // [long  ,   10] 펀드원주문번호      
		m_ctrlOutBlock1.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock1.FundOrdNo        , sizeof( pAllOutBlock->outBlock1.FundOrdNo         ), DATA_TYPE_LONG   ) );    // [long  ,   10] 펀드주문번호        
		
		//------------------------------------------------
		// OutBlock1
		nDataLength -= sizeof( CFOAT00200OutBlock2 );
		if( nDataLength < 0 )
		{
			return 0L;
		}
		
		nCol = 0;
		m_ctrlOutBlock2.InsertItem( 0, "" );
		m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock2.RecCnt       , sizeof( pAllOutBlock->outBlock2.RecCnt        ), DATA_TYPE_LONG   ) );    // [long  ,    5] 레코드갯수      
		m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock2.OrdNo        , sizeof( pAllOutBlock->outBlock2.OrdNo         ), DATA_TYPE_LONG   ) );    // [long  ,   10] 주문번호        
		m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock2.BrnNm        , sizeof( pAllOutBlock->outBlock2.BrnNm         ), DATA_TYPE_STRING ) );    // [string,   40] 지점명          
		m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock2.AcntNm       , sizeof( pAllOutBlock->outBlock2.AcntNm        ), DATA_TYPE_STRING ) );    // [string,   40] 계좌명          
		m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock2.IsuNm        , sizeof( pAllOutBlock->outBlock2.IsuNm         ), DATA_TYPE_STRING ) );    // [string,   50] 종목명          
		m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock2.OrdAbleAmt   , sizeof( pAllOutBlock->outBlock2.OrdAbleAmt    ), DATA_TYPE_LONG   ) );    // [long  ,   16] 주문가능금액    
		m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock2.MnyOrdAbleAmt, sizeof( pAllOutBlock->outBlock2.MnyOrdAbleAmt ), DATA_TYPE_LONG   ) );    // [long  ,   16] 현금주문가능금액
		m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock2.OrdMgn       , sizeof( pAllOutBlock->outBlock2.OrdMgn        ), DATA_TYPE_LONG   ) );    // [long  ,   16] 주문증거금      
		m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock2.MnyOrdMgn    , sizeof( pAllOutBlock->outBlock2.MnyOrdMgn     ), DATA_TYPE_LONG   ) );    // [long  ,   16] 현금주문증거금  
		m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock2.OrdAbleQty   , sizeof( pAllOutBlock->outBlock2.OrdAbleQty    ), DATA_TYPE_LONG   ) );    // [long  ,   16] 주문가능수량    
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
LRESULT CDlg_CFOAT00200::OnXMTimeoutData( WPARAM wParam, LPARAM lParam )
{
	g_iXingAPI.ReleaseRequestData( (int)lParam );
	GetParent()->SendMessage( WMU_SET_MESSAGE, (WPARAM)"", (LPARAM)"Timeout" );		

	return 0L;
}
