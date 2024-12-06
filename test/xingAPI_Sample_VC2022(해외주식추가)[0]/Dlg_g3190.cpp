// Dlg_g3190.cpp : implementation file
//

#include "stdafx.h"
#include "xingapi_sample.h"
#include "Dlg_g3190.h"

#include "./Packet/g3190.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlg_g3190 dialog


IMPLEMENT_DYNCREATE(CDlg_g3190, CDialog)

CDlg_g3190::CDlg_g3190(CWnd* pParent /*=NULL*/)
	: CDialog(CDlg_g3190::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlg_g3190)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CDlg_g3190::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlg_g3190)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlg_g3190, CDialog)
	//{{AFX_MSG_MAP(CDlg_g3190)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
	ON_BN_CLICKED( IDC_BUTTON_REQUEST,		  OnButtonRequest	  )
	ON_BN_CLICKED( IDC_BUTTON_REQUEST_NEXT,	  OnButtonRequestNext )
	ON_MESSAGE	 ( WM_USER + XM_RECEIVE_DATA, OnXMReceiveData	  )
	ON_MESSAGE	 ( WM_USER + XM_TIMEOUT_DATA, OnXMTimeoutData	  )
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlg_g3190 message handlers

BOOL CDlg_g3190::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	InitCtrls();
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CDlg_g3190::OnButtonRequest() 
{
	RequestData();
}

void CDlg_g3190::OnButtonRequestNext() 
{
	RequestData( TRUE );
}

//--------------------------------------------------------------------------------------
// 컨트롤 초기화
//--------------------------------------------------------------------------------------
void CDlg_g3190::InitCtrls()
{
	//-----------------------------------------------------------
	// OutBlock
	InsertColumn4List( this, IDC_OUTBLOCK ,  0, "지연구분      ", FALSE,  8  );   // [string,    1] 지연구분   
	InsertColumn4List( this, IDC_OUTBLOCK ,  1, "국가구분      ", TRUE ,  8  );   // [string,    2] 국가구분   
	InsertColumn4List( this, IDC_OUTBLOCK ,  2, "거래소구분    ", FALSE,  10 );  // [string,    1] 거래소구분  
	InsertColumn4List( this, IDC_OUTBLOCK ,  3, "연속구분      ", TRUE ,  16 );  // [string,   16] 연속구분   
	InsertColumn4List( this, IDC_OUTBLOCK ,  4, "레코드카운트  ", FALSE,  8  );	// [long  ,    7] 레코드카운트 
	
	//-----------------------------------------------------------
	// OutBlock1
	InsertColumn4List( this, IDC_OUTBLOCK1,  0, "KEY종목코드     ",		TRUE ,	18	);		// [string,   18] KEY종목코드   
	InsertColumn4List( this, IDC_OUTBLOCK1,  1, "국가코드        ",		TRUE ,  2	);		// [string,    2] 국가코드      
	InsertColumn4List( this, IDC_OUTBLOCK1,  2, "거래소코드      ",		TRUE ,  2	);		// [string,    2] 거래소코드     
	InsertColumn4List( this, IDC_OUTBLOCK1,  3, "종목코드        ",		TRUE ,  16	);		// [string,   16] 종목코드      
	InsertColumn4List( this, IDC_OUTBLOCK1,  4, "거래소종목코드  ",		TRUE ,  18	);		// [string,   18] 거래소종목코드  
	InsertColumn4List( this, IDC_OUTBLOCK1,  5, "한글종목명      ",		TRUE ,  64	);		// [string,   64] 한글종목명     
	InsertColumn4List( this, IDC_OUTBLOCK1,  6, "영문종목명      ",		TRUE ,  64	);		// [string,   64] 영문종목명     
	InsertColumn4List( this, IDC_OUTBLOCK1,  7, "외환코드        ",		TRUE ,  4	);		// [string,    4] 외환코드      
	InsertColumn4List( this, IDC_OUTBLOCK1,  8, "ISIN           ",		TRUE ,	12	);		// [string,   12] ISIN       
	InsertColumn4List( this, IDC_OUTBLOCK1,  9, "FLOATPOINT     ",		TRUE ,	1	);		// [string,    1] FLOATPOINT 
	InsertColumn4List( this, IDC_OUTBLOCK1, 10, "업종코드        ",		TRUE ,  4	);		// [string,    4] 업종코드      
	InsertColumn4List( this, IDC_OUTBLOCK1, 11, "상장주식수      ",		FALSE,  16	);		// [long  ,   16] 상장주식수     
	InsertColumn4List( this, IDC_OUTBLOCK1, 12, "자본금          ",		FALSE,  16	);		// [long  ,   16] 자본금       
	InsertColumn4List( this, IDC_OUTBLOCK1, 13, "액면가          ",		FALSE,	15.6 );		// [double, 15.6] 액면가       
	InsertColumn4List( this, IDC_OUTBLOCK1, 14, "액면가외환코드   ",		TRUE ,	4	);		// [string,    4] 액면가외환코드  
	InsertColumn4List( this, IDC_OUTBLOCK1, 15, "매수주문단위2    ",		TRUE ,  8	);		// [string,    8] 매수주문단위2   
	InsertColumn4List( this, IDC_OUTBLOCK1, 16, "매도주문단위2    ",		TRUE ,	8	);		// [string,    8] 매도주문단위2   
	InsertColumn4List( this, IDC_OUTBLOCK1, 17, "기준가           ",		FALSE,	15.6 );		// [double, 15.6] 기준가       
	InsertColumn4List( this, IDC_OUTBLOCK1, 18, "상장일자         ",		TRUE ,  8	);		// [string,    8] 상장일자      
	InsertColumn4List( this, IDC_OUTBLOCK1, 19, "만기일자          ",	TRUE ,  8	);		// [string,    8] 만기일자      
	InsertColumn4List( this, IDC_OUTBLOCK1, 20, "거래정지여부      ",	TRUE ,  1	);		// [string,    1] 거래정지여부    
	InsertColumn4List( this, IDC_OUTBLOCK1, 21, "영업일자          ",	TRUE ,  8	);		// [string,    8] 영업일자      
	InsertColumn4List( this, IDC_OUTBLOCK1, 22, "SELLONLY구분      ",	TRUE ,  8	);		// [string,    8] SELLONLY구분
	InsertColumn4List( this, IDC_OUTBLOCK1, 23, "인지세여부        ",	TRUE ,  1	);		// [string,    1] 인지세여부     
	InsertColumn4List( this, IDC_OUTBLOCK1, 24, "TICKSIZETYPE     ",	TRUE ,  8	);		// [string,    8] TICKSIZETYP
	InsertColumn4List( this, IDC_OUTBLOCK1, 25, "전일종가          ",	FALSE,  15.6 );		// [double, 15.6] 전일종가      
	InsertColumn4List( this, IDC_OUTBLOCK1, 26, "VCM대상종목       ",	TRUE ,  1	);		// [string,    1] VCM대상종목   
	InsertColumn4List( this, IDC_OUTBLOCK1, 27, "CAS대상종목       ",	TRUE ,  1	);		// [string,    1] CAS대상종목   
	InsertColumn4List( this, IDC_OUTBLOCK1, 28, "POS대상종목       ",	TRUE ,  1	);		// [string,    1] POS대상종목   
	InsertColumn4List( this, IDC_OUTBLOCK1, 29, "소수점매매가능종목 ",	TRUE ,  1	);		// [string,    1] 소수점매매가능종목
}

//--------------------------------------------------------------------------------------
// 데이터 조회
//--------------------------------------------------------------------------------------
void CDlg_g3190::RequestData( BOOL bNext )
{
	//-----------------------------------------------------------
	// 기간별주가(g3190) ( attr,block,headtype=A )
	g3190InBlock	pckInBlock;

	TCHAR			szTrNo[]	= "g3190";

	//-----------------------------------------------------------
	// 데이터 초기화
	FillMemory( &pckInBlock, sizeof( pckInBlock ), ' ' );
	
	//-----------------------------------------------------------
	// 데이터 입력
	SetPacketData( pckInBlock.delaygb      , sizeof( pckInBlock.delaygb       ), this, IDC_INBLOCK_DELAYGB    , DATA_TYPE_STRING );// [string,    1] 지연구분          
	SetPacketData( pckInBlock.natcode      , sizeof( pckInBlock.natcode       ), this, IDC_INBLOCK_NATCODE    , DATA_TYPE_STRING );	// [string,    2] 국가구분          
	SetPacketData( pckInBlock.exgubun      , sizeof( pckInBlock.exgubun       ), this, IDC_INBLOCK_EXCHCD     , DATA_TYPE_STRING );	// [string,    1] 거래소구분         
	SetPacketData( pckInBlock.readcnt      , sizeof( pckInBlock.readcnt       ), this, IDC_INBLOCK_CNT        , DATA_TYPE_LONG   );	// [long  ,    4] 조회갯수          
	SetPacketData( pckInBlock.cts_value    , sizeof( pckInBlock.cts_value     ), this, IDC_INBLOCK_CTS_VALUE  , DATA_TYPE_STRING );	// [string,   16] 연속구분          

	//-----------------------------------------------------------
	// 데이터 전송
	int nRqID = g_iXingAPI.Request( 
		GetSafeHwnd(),				// 데이터를 받을 윈도우, XM_RECEIVE_DATA 으로 온다.
		szTrNo,						// TR 번호
		&pckInBlock,				// InBlock 데이터
		sizeof( pckInBlock ),		// InBlock 데이터 크기
		bNext,						// 다음조회 여부
		"",							// 다음조회 Key
		30							// Timeout(초) : 해당 시간(초)동안 데이터가 오지 않으면 Timeout에 발생한다. XM_TIMEOUT_DATA 메시지가 발생한다.
	);
	
	((CListCtrl*)GetDlgItem( IDC_OUTBLOCK  ))->DeleteAllItems();
	((CListCtrl*)GetDlgItem( IDC_OUTBLOCK1 ))->DeleteAllItems();

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
LRESULT CDlg_g3190::OnXMReceiveData( WPARAM wParam, LPARAM lParam )
{
	//-------------------------------------------------------------------------------------
	// Data를 받음
	if( wParam == REQUEST_DATA )
	{
		LPRECV_PACKET pRpData = (LPRECV_PACKET)lParam;

		// Block Mode 이다.
		if( strcmp( pRpData->szBlockName, NAME_g3190OutBlock ) == 0 )
		{
			CListCtrl*		pList	  = (CListCtrl*)GetDlgItem( IDC_OUTBLOCK );
			LPg3190OutBlock pOutBlock = (LPg3190OutBlock)pRpData->lpData;

			int nItem = pList->InsertItem( pList->GetItemCount(), "" );
			pList->SetItemText( nItem,  0, GetDispData( pOutBlock->delaygb   , sizeof( pOutBlock->delaygb   ), DATA_TYPE_STRING ) );		// [string,    1] 지연구분 
			pList->SetItemText( nItem,  1, GetDispData( pOutBlock->natcode   , sizeof( pOutBlock->natcode   ), DATA_TYPE_STRING ) );		// [string,    2] 국가구분 
			pList->SetItemText( nItem,  2, GetDispData( pOutBlock->exgubun   , sizeof( pOutBlock->exgubun   ), DATA_TYPE_STRING ) );		// [string,    1] 거래소구분 
			pList->SetItemText( nItem,  3, GetDispData( pOutBlock->cts_value , sizeof( pOutBlock->cts_value ), DATA_TYPE_STRING ) );		// [string,   16] 연속구분 
			pList->SetItemText( nItem,  4, GetDispData( pOutBlock->rec_count , sizeof( pOutBlock->rec_count ), DATA_TYPE_LONG   ) );		// [long  ,    4] 조회갯수
		}
		else if( strcmp( pRpData->szBlockName, NAME_g3190OutBlock1 ) == 0 )
		{
			CListCtrl*		 pList	   = (CListCtrl*)GetDlgItem( IDC_OUTBLOCK1 );
			LPg3190OutBlock1 pOutBlock = (LPg3190OutBlock1)pRpData->lpData;
			int				 nCount	   = pRpData->nDataLength / sizeof( g3190OutBlock1 );		// Block Mode 시엔 전체크기 / 하나의 Record 크기 로 갯수를 구한다.
			for( int i=0; i<nCount; i++ )
			{
				int nItem = pList->InsertItem( pList->GetItemCount(), "" );
				pList->SetItemText( nItem,  0, GetDispData( pOutBlock[i].keysymbol   , sizeof( pOutBlock[i].keysymbol   ), DATA_TYPE_STRING ) );		    // [string,   18] KEY종목코드    
				pList->SetItemText( nItem,  1, GetDispData( pOutBlock[i].natcode     , sizeof( pOutBlock[i].natcode     ), DATA_TYPE_STRING ) );		    // [string,    2] 국가코드       
				pList->SetItemText( nItem,  2, GetDispData( pOutBlock[i].exchcd      , sizeof( pOutBlock[i].exchcd      ), DATA_TYPE_STRING ) );		    // [string,    2] 거래소코드      
				pList->SetItemText( nItem,  3, GetDispData( pOutBlock[i].symbol      , sizeof( pOutBlock[i].symbol      ), DATA_TYPE_STRING ) );		    // [string,   16] 종목코드       
				pList->SetItemText( nItem,  4, GetDispData( pOutBlock[i].seccode     , sizeof( pOutBlock[i].seccode     ), DATA_TYPE_STRING ) );		    // [string,   18] 거래소종목코드   
				pList->SetItemText( nItem,  5, GetDispData( pOutBlock[i].korname     , sizeof( pOutBlock[i].korname     ), DATA_TYPE_STRING ) );		    // [string,   64] 한글종목명      
				pList->SetItemText( nItem,  6, GetDispData( pOutBlock[i].engname     , sizeof( pOutBlock[i].engname     ), DATA_TYPE_STRING ) );		    // [string,   64] 영문종목명      
				pList->SetItemText( nItem,  7, GetDispData( pOutBlock[i].currency    , sizeof( pOutBlock[i].currency    ), DATA_TYPE_STRING ) );		    // [string,    4] 외환코드       
				pList->SetItemText( nItem,  8, GetDispData( pOutBlock[i].isin        , sizeof( pOutBlock[i].isin        ), DATA_TYPE_STRING ) );		    // [string,   12] ISIN        
				pList->SetItemText( nItem,  9, GetDispData( pOutBlock[i].floatpoint  , sizeof( pOutBlock[i].floatpoint  ), DATA_TYPE_STRING ) );		    // [string,    1] FLOATPOINT  
				pList->SetItemText( nItem, 10, GetDispData( pOutBlock[i].indusury    , sizeof( pOutBlock[i].indusury    ), DATA_TYPE_STRING ) );		    // [string,    4] 업종코드       
				pList->SetItemText( nItem, 11, GetDispData( pOutBlock[i].share       , sizeof( pOutBlock[i].share       ), DATA_TYPE_LONG   ) );		    // [long  ,   16] 상장주식수      
				pList->SetItemText( nItem, 12, GetDispData( pOutBlock[i].marketcap   , sizeof( pOutBlock[i].marketcap   ), DATA_TYPE_LONG   ) );		    // [long  ,   16] 자본금        
				pList->SetItemText( nItem, 13, GetDispData( pOutBlock[i].par         , sizeof( pOutBlock[i].par         ), DATA_TYPE_DOUBLE, 6 ) );		    // [double, 15.6] 액면가        
				pList->SetItemText( nItem, 14, GetDispData( pOutBlock[i].parcurr     , sizeof( pOutBlock[i].parcurr     ), DATA_TYPE_LONG   ) );		    // [string,    4] 액면가외환코드   
				pList->SetItemText( nItem, 15, GetDispData( pOutBlock[i].bidlotsize2 , sizeof( pOutBlock[i].bidlotsize2 ), DATA_TYPE_STRING ) );		    // [string,    8] 매수주문단위2    
				pList->SetItemText( nItem, 16, GetDispData( pOutBlock[i].asklotsize2 , sizeof( pOutBlock[i].asklotsize2 ), DATA_TYPE_STRING ) );		    // [string,    8] 매도주문단위2    
				pList->SetItemText( nItem, 17, GetDispData( pOutBlock[i].clos        , sizeof( pOutBlock[i].clos        ), DATA_TYPE_DOUBLE, 6 ) );		    // [double, 15.6] 기준가        
				pList->SetItemText( nItem, 18, GetDispData( pOutBlock[i].listed_date , sizeof( pOutBlock[i].listed_date ), DATA_TYPE_STRING ) );		    // [string,    8] 상장일자       
				pList->SetItemText( nItem, 19, GetDispData( pOutBlock[i].expire_date , sizeof( pOutBlock[i].expire_date ), DATA_TYPE_STRING ) );		    // [string,    8] 만기일자       
				pList->SetItemText( nItem, 20, GetDispData( pOutBlock[i].suspend     , sizeof( pOutBlock[i].suspend     ), DATA_TYPE_LONG   ) );		    // [string,    1] 거래정지여부     
				pList->SetItemText( nItem, 21, GetDispData( pOutBlock[i].bymd        , sizeof( pOutBlock[i].bymd        ), DATA_TYPE_STRING ) );		    // [string,    8] 영업일자       
				pList->SetItemText( nItem, 22, GetDispData( pOutBlock[i].sellonly    , sizeof( pOutBlock[i].sellonly    ), DATA_TYPE_STRING ) );		    // [string,    8] SELLONLY구분 
				pList->SetItemText( nItem, 23, GetDispData( pOutBlock[i].stamp       , sizeof( pOutBlock[i].stamp       ), DATA_TYPE_STRING ) );		    // [string,    1] 인지세여부      
				pList->SetItemText( nItem, 24, GetDispData( pOutBlock[i].ticktype    , sizeof( pOutBlock[i].ticktype    ), DATA_TYPE_STRING ) );		    // [string,    8] TICKSIZETYPE
				pList->SetItemText( nItem, 25, GetDispData( pOutBlock[i].pcls        , sizeof( pOutBlock[i].pcls        ), DATA_TYPE_DOUBLE, 6 ) );		    // [double, 15.6] 전일종가       
				pList->SetItemText( nItem, 26, GetDispData( pOutBlock[i].vcmf        , sizeof( pOutBlock[i].vcmf        ), DATA_TYPE_STRING ) );		    // [string,    1] VCM대상종목    
				pList->SetItemText( nItem, 27, GetDispData( pOutBlock[i].casf        , sizeof( pOutBlock[i].casf        ), DATA_TYPE_STRING ) );		    // [string,    1] CAS대상종목    
				pList->SetItemText( nItem, 28, GetDispData( pOutBlock[i].posf        , sizeof( pOutBlock[i].posf        ), DATA_TYPE_STRING ) );		    // [string,    1] POS대상종목    
				pList->SetItemText( nItem, 29, GetDispData( pOutBlock[i].point       , sizeof( pOutBlock[i].point       ), DATA_TYPE_STRING ) );		    // [string,    1] 소수점매매가능종목 
			}
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
LRESULT CDlg_g3190::OnXMTimeoutData( WPARAM wParam, LPARAM lParam )
{
	g_iXingAPI.ReleaseRequestData( (int)lParam );

	return 0L;
}
