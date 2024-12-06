// Dlg_AS4.cpp : implementation file
//

#include "stdafx.h"
#include "XingAPI_Sample.h"
#include "Dlg_AS4.h"

#include "./Packet/AS4.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlg_AS4 dialog

IMPLEMENT_DYNCREATE(CDlg_AS4, CDialog)

CDlg_AS4::CDlg_AS4(CWnd* pParent /*=NULL*/)
	: CDialog(CDlg_AS4::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlg_AS4)
	//}}AFX_DATA_INIT
}


void CDlg_AS4::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlg_AS4)
	DDX_Control(pDX, IDC_OUTBLOCK, m_ctrlOutBlock);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlg_AS4, CDialog)
	//{{AFX_MSG_MAP(CDlg_AS4)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
	ON_WM_DESTROY()
	ON_MESSAGE	 ( WM_USER + XM_RECEIVE_REAL_DATA,	OnXMReceiveRealData	)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlg_AS4 message handlers

BOOL CDlg_AS4::OnInitDialog() 
{
	CDialog::OnInitDialog();

	// 주문에 관련된 실시간TR은 입력값이 없으므로 화면이 오픈될때 등록한다.
	AdviseData();

	InitCtrls();
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CDlg_AS4::OnDestroy()
{
	UnadviseData();

	CDialog::OnDestroy();
}

//--------------------------------------------------------------------------------------
// 컨트롤 초기화
//--------------------------------------------------------------------------------------
void CDlg_AS4::InitCtrls()
{
	//-------------------------------------------------------------------------
	// OutBlock
	m_ctrlOutBlock.InsertColumn( 0, "필드  ", LVCFMT_LEFT, 150 );
	m_ctrlOutBlock.InsertColumn( 1, "데이터", LVCFMT_LEFT, 200 );

	int nRow = 0;
	m_ctrlOutBlock.InsertItem( nRow++, "라인일련번호              " );
	m_ctrlOutBlock.InsertItem( nRow++, "계좌번호                 " );
	m_ctrlOutBlock.InsertItem( nRow++, "조작자ID                 " );
	m_ctrlOutBlock.InsertItem( nRow++, "헤더길이                 " );
	m_ctrlOutBlock.InsertItem( nRow++, "헤더구분                 " );
	m_ctrlOutBlock.InsertItem( nRow++, "압축구분                 " );
	m_ctrlOutBlock.InsertItem( nRow++, "암호구분                 " );
	m_ctrlOutBlock.InsertItem( nRow++, "공통시작지점              " );
	m_ctrlOutBlock.InsertItem( nRow++, "TRCODE                 " );
	m_ctrlOutBlock.InsertItem( nRow++, "이용사번호               " );
	m_ctrlOutBlock.InsertItem( nRow++, "사용자ID                 " );
	m_ctrlOutBlock.InsertItem( nRow++, "접속매체                 " );
	m_ctrlOutBlock.InsertItem( nRow++, "I/F일련번호              " );
	m_ctrlOutBlock.InsertItem( nRow++, "전문일련번호              " );
	m_ctrlOutBlock.InsertItem( nRow++, "TR추적ID                 " );
	m_ctrlOutBlock.InsertItem( nRow++, "공인IP                   " );
	m_ctrlOutBlock.InsertItem( nRow++, "사설IP                   " );
	m_ctrlOutBlock.InsertItem( nRow++, "처리지점번호              " );
	m_ctrlOutBlock.InsertItem( nRow++, "지점번호                 " );
	m_ctrlOutBlock.InsertItem( nRow++, "단말번호                 " );
	m_ctrlOutBlock.InsertItem( nRow++, "언어구분                 " );
	m_ctrlOutBlock.InsertItem( nRow++, "AP처리시간               " );
	m_ctrlOutBlock.InsertItem( nRow++, "메세지코드               " );
	m_ctrlOutBlock.InsertItem( nRow++, "메세지출력구분             " );
	m_ctrlOutBlock.InsertItem( nRow++, "압축요청구분              " );
	m_ctrlOutBlock.InsertItem( nRow++, "기능키                   " );
	m_ctrlOutBlock.InsertItem( nRow++, "요청레코드개수             " );
	m_ctrlOutBlock.InsertItem( nRow++, "예비영역                 " );
	m_ctrlOutBlock.InsertItem( nRow++, "연속구분                 " );
	m_ctrlOutBlock.InsertItem( nRow++, "연속키값                 " );
	m_ctrlOutBlock.InsertItem( nRow++, "가변시스템길이             " );
	m_ctrlOutBlock.InsertItem( nRow++, "가변해더길이              " );
	m_ctrlOutBlock.InsertItem( nRow++, "가변메시지길이             " );
	m_ctrlOutBlock.InsertItem( nRow++, "조회발원지               " );
	m_ctrlOutBlock.InsertItem( nRow++, "I/F이벤트ID              " );
	m_ctrlOutBlock.InsertItem( nRow++, "I/F정보                  " );
	m_ctrlOutBlock.InsertItem( nRow++, "예비영역                 " );
	m_ctrlOutBlock.InsertItem( nRow++, "주문체결유형코드           " );
	m_ctrlOutBlock.InsertItem( nRow++, "주문시장코드              " );
	m_ctrlOutBlock.InsertItem( nRow++, "주문유형코드              " );
	m_ctrlOutBlock.InsertItem( nRow++, "관리지점번호              " );
	m_ctrlOutBlock.InsertItem( nRow++, "계좌번호                 " );
	m_ctrlOutBlock.InsertItem( nRow++, "계좌명                  " );
	m_ctrlOutBlock.InsertItem( nRow++, "종목번호                  " );
	m_ctrlOutBlock.InsertItem( nRow++, "종목명                  " );
	m_ctrlOutBlock.InsertItem( nRow++, "주문번호                  " );
	m_ctrlOutBlock.InsertItem( nRow++, "원주문번호               " );
	m_ctrlOutBlock.InsertItem( nRow++, "체결번호                 " );
	m_ctrlOutBlock.InsertItem( nRow++, "해외체결ID               " );
	m_ctrlOutBlock.InsertItem( nRow++, "주문수량                 " );
	m_ctrlOutBlock.InsertItem( nRow++, "주문가                  " );
	m_ctrlOutBlock.InsertItem( nRow++, "체결수량                 " );
	m_ctrlOutBlock.InsertItem( nRow++, "체결가                  " );
	m_ctrlOutBlock.InsertItem( nRow++, "정정확인수량              " );
	m_ctrlOutBlock.InsertItem( nRow++, "정정확인가               " );
	m_ctrlOutBlock.InsertItem( nRow++, "취소확인수량              " );
	m_ctrlOutBlock.InsertItem( nRow++, "거부수량                 " );
	m_ctrlOutBlock.InsertItem( nRow++, "주문처리유형코드           " );
	m_ctrlOutBlock.InsertItem( nRow++, "복수주문일련번호           " );
	m_ctrlOutBlock.InsertItem( nRow++, "주문조건                 " );
	m_ctrlOutBlock.InsertItem( nRow++, "호가유형코드              " );
	m_ctrlOutBlock.InsertItem( nRow++, "단축종목번호              " );
	m_ctrlOutBlock.InsertItem( nRow++, "운용지시번호              " );
	m_ctrlOutBlock.InsertItem( nRow++, "미체결수량(주문)           " );
	m_ctrlOutBlock.InsertItem( nRow++, "원주문미체결수량           " );
	m_ctrlOutBlock.InsertItem( nRow++, "원주문정정수량             " );
	m_ctrlOutBlock.InsertItem( nRow++, "원주문취소수량             " );
	m_ctrlOutBlock.InsertItem( nRow++, "주문평균체결가             " );
	m_ctrlOutBlock.InsertItem( nRow++, "주문금액                 " );
	m_ctrlOutBlock.InsertItem( nRow++, "표준종목번호              " );
	m_ctrlOutBlock.InsertItem( nRow++, "매매구분                 " );
	m_ctrlOutBlock.InsertItem( nRow++, "통신매체코드              " );
	m_ctrlOutBlock.InsertItem( nRow++, "주문계좌번호              " );
	m_ctrlOutBlock.InsertItem( nRow++, "집계지점번호              " );
	m_ctrlOutBlock.InsertItem( nRow++, "등록시장코드              " );
	m_ctrlOutBlock.InsertItem( nRow++, "현금증거금률              " );
	m_ctrlOutBlock.InsertItem( nRow++, "대용증거금률              " );
	m_ctrlOutBlock.InsertItem( nRow++, "현금체결금액              " );
	m_ctrlOutBlock.InsertItem( nRow++, "대용체결금액              " );
	m_ctrlOutBlock.InsertItem( nRow++, "수수료체결금액             " );
	m_ctrlOutBlock.InsertItem( nRow++, "전일재사용체결금액           " );
	m_ctrlOutBlock.InsertItem( nRow++, "금일재사용체결금액          " );
	m_ctrlOutBlock.InsertItem( nRow++, "실물체결수량              " );
	m_ctrlOutBlock.InsertItem( nRow++, "공매도체결수량             " );
	m_ctrlOutBlock.InsertItem( nRow++, "전략코드                 " );
	m_ctrlOutBlock.InsertItem( nRow++, "그룹ID                  " );
	m_ctrlOutBlock.InsertItem( nRow++, "주문회차                 " );
	m_ctrlOutBlock.InsertItem( nRow++, "주문자ID                " );
	m_ctrlOutBlock.InsertItem( nRow++, "체결시각                 " );
	m_ctrlOutBlock.InsertItem( nRow++, "거래소수신체결시각          " );
	m_ctrlOutBlock.InsertItem( nRow++, "거부사유                 " );
	m_ctrlOutBlock.InsertItem( nRow++, "잔고수량                 " );
	m_ctrlOutBlock.InsertItem( nRow++, "실물주문가능수량           " );
	m_ctrlOutBlock.InsertItem( nRow++, "주문가능재사용수량          " );
	m_ctrlOutBlock.InsertItem( nRow++, "변동수량                 " );
	m_ctrlOutBlock.InsertItem( nRow++, "잔고수량(D2)             " );
	m_ctrlOutBlock.InsertItem( nRow++, "매도주문가능수량           " );
	m_ctrlOutBlock.InsertItem( nRow++, "미체결매도주문수량          " );
	m_ctrlOutBlock.InsertItem( nRow++, "평균매입가               " );
	m_ctrlOutBlock.InsertItem( nRow++, "매입금액                 " );
	m_ctrlOutBlock.InsertItem( nRow++, "예수금                  " );
	m_ctrlOutBlock.InsertItem( nRow++, "대용금                   " );
	m_ctrlOutBlock.InsertItem( nRow++, "위탁현금증거금액           " );
	m_ctrlOutBlock.InsertItem( nRow++, "위탁대용증거금액           " );
	m_ctrlOutBlock.InsertItem( nRow++, "주문가능현금              " );
	m_ctrlOutBlock.InsertItem( nRow++, "주문가능대용금액           " );
	m_ctrlOutBlock.InsertItem( nRow++, "재사용가능금액             " );
	m_ctrlOutBlock.InsertItem( nRow++, "신용거래코드               " );
}

//--------------------------------------------------------------------------------------
// 데이터 Advise
//--------------------------------------------------------------------------------------
void CDlg_AS4::AdviseData()
{
	TCHAR	szTrCode[]		= "AS4";

	//-----------------------------------------------------------
	// 데이터 전송
	BOOL bSuccess = g_iXingAPI.AdviseRealData( 
		GetSafeHwnd(),				// 데이터를 받을 윈도우, XM_RECEIVE_REAL_DATA 으로 온다.
		szTrCode,					// TR 번호
		"",							// AS4는 빈 데이터를 넘겨야 한다.
		0							// AS4의 데이터 길이는 0이다.
		);

	//-----------------------------------------------------------
	// 에러체크
	if( bSuccess == FALSE )
	{
		MessageBox( "조회실패", "에러", MB_ICONSTOP );
	}
}

//--------------------------------------------------------------------------------------
// 데이터 Unadvise
//--------------------------------------------------------------------------------------
void CDlg_AS4::UnadviseData()
{
	TCHAR	szTrCode[]		= "AS4";
	
	//-----------------------------------------------------------
	// 데이터 전송
	BOOL bSuccess = g_iXingAPI.UnadviseRealData( 
		GetSafeHwnd(),				// 데이터를 받을 윈도우, XM_RECEIVE_REAL_DATA 으로 온다.
		szTrCode,					// TR 번호
		"",							// AS4는 빈 데이터를 넘겨야 한다.
		0							// AS4의 데이터 길이는 0이다.
		);
	
	//-----------------------------------------------------------
	// 에러체크
	if( bSuccess == FALSE )
	{
		MessageBox( "조회실패", "에러", MB_ICONSTOP );
	}
}

//--------------------------------------------------------------------------------------
// 데이터를 받음
//--------------------------------------------------------------------------------------
LRESULT CDlg_AS4::OnXMReceiveRealData( WPARAM wParam, LPARAM lParam )
{
	LPRECV_REAL_PACKET pRealPacket = (LPRECV_REAL_PACKET)lParam;

	if( strcmp( pRealPacket->szTrCode, "AS4" ) == 0 )
	{
		LPAS4_OutBlock pOutBlock = (LPAS4_OutBlock)pRealPacket->pszData;
		int nRow = 0;
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->lineseq              , sizeof( pOutBlock->lineseq              ), DATA_TYPE_LONG     ) );    // [long  ,   10] 라인일련번호       
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->accno                , sizeof( pOutBlock->accno                ), DATA_TYPE_STRING   ) );    // [string,   11] 계좌번호          
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->user                 , sizeof( pOutBlock->user                 ), DATA_TYPE_STRING   ) );    // [string,    8] 조작자ID         
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->len                  , sizeof( pOutBlock->len                  ), DATA_TYPE_LONG     ) );    // [long  ,    6] 헤더길이          
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->gubun                , sizeof( pOutBlock->gubun                ), DATA_TYPE_STRING   ) );    // [string,    1] 헤더구분          
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->compress             , sizeof( pOutBlock->compress             ), DATA_TYPE_STRING   ) );    // [string,    1] 압축구분          
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->encrypt              , sizeof( pOutBlock->encrypt              ), DATA_TYPE_STRING   ) );    // [string,    1] 암호구분          
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->offset               , sizeof( pOutBlock->offset               ), DATA_TYPE_LONG     ) );    // [long  ,    3] 공통시작지점       
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->trcode               , sizeof( pOutBlock->trcode               ), DATA_TYPE_STRING   ) );    // [string,    8] TRCODE         
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->comid                , sizeof( pOutBlock->comid                ), DATA_TYPE_STRING   ) );    // [string,    3] 이용사번호        
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->userid               , sizeof( pOutBlock->userid               ), DATA_TYPE_STRING   ) );    // [string,   16] 사용자ID         
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->media                , sizeof( pOutBlock->media                ), DATA_TYPE_STRING   ) );    // [string,    2] 접속매체          
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->ifid                 , sizeof( pOutBlock->ifid                 ), DATA_TYPE_STRING   ) );    // [string,    3] I/F일련번호       
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->seq                  , sizeof( pOutBlock->seq                  ), DATA_TYPE_STRING   ) );    // [string,    9] 전문일련번호       
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->trid                 , sizeof( pOutBlock->trid                 ), DATA_TYPE_STRING   ) );    // [string,   16] TR추적ID         
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->pubip                , sizeof( pOutBlock->pubip                ), DATA_TYPE_STRING   ) );    // [string,   12] 공인IP           
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->prvip                , sizeof( pOutBlock->prvip                ), DATA_TYPE_STRING   ) );    // [string,   12] 사설IP           
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->pcbpno               , sizeof( pOutBlock->pcbpno               ), DATA_TYPE_STRING   ) );    // [string,    3] 처리지점번호       
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->bpno                 , sizeof( pOutBlock->bpno                 ), DATA_TYPE_STRING   ) );    // [string,    3] 지점번호          
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->termno               , sizeof( pOutBlock->termno               ), DATA_TYPE_STRING   ) );    // [string,    8] 단말번호          
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->lang                 , sizeof( pOutBlock->lang                 ), DATA_TYPE_STRING   ) );    // [string,    1] 언어구분          
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->proctm               , sizeof( pOutBlock->proctm               ), DATA_TYPE_LONG     ) );    // [long  ,    9] AP처리시간        
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->msgcode              , sizeof( pOutBlock->msgcode              ), DATA_TYPE_STRING   ) );    // [string,    4] 메세지코드        
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->outgu                , sizeof( pOutBlock->outgu                ), DATA_TYPE_STRING   ) );    // [string,    1] 메세지출력구분      
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->compreq              , sizeof( pOutBlock->compreq              ), DATA_TYPE_STRING   ) );    // [string,    1] 압축요청구분       
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->funckey              , sizeof( pOutBlock->funckey              ), DATA_TYPE_STRING   ) );    // [string,    4] 기능키           
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->reqcnt               , sizeof( pOutBlock->reqcnt               ), DATA_TYPE_LONG     ) );    // [long  ,    4] 요청레코드개수      
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->filler               , sizeof( pOutBlock->filler               ), DATA_TYPE_STRING   ) );    // [string,    6] 예비영역          
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->cont                 , sizeof( pOutBlock->cont                 ), DATA_TYPE_STRING   ) );    // [string,    1] 연속구분          
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->contkey              , sizeof( pOutBlock->contkey              ), DATA_TYPE_STRING   ) );    // [string,   18] 연속키값          
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->varlen               , sizeof( pOutBlock->varlen               ), DATA_TYPE_LONG     ) );    // [long  ,    2] 가변시스템길이      
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->varhdlen             , sizeof( pOutBlock->varhdlen             ), DATA_TYPE_LONG     ) );    // [long  ,    2] 가변해더길이       
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->varmsglen            , sizeof( pOutBlock->varmsglen            ), DATA_TYPE_LONG     ) );    // [long  ,    2] 가변메시지길이      
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->trsrc                , sizeof( pOutBlock->trsrc                ), DATA_TYPE_STRING   ) );    // [string,    1] 조회발원지        
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->eventid              , sizeof( pOutBlock->eventid              ), DATA_TYPE_STRING   ) );    // [string,    4] I/F이벤트ID      
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->ifinfo               , sizeof( pOutBlock->ifinfo               ), DATA_TYPE_STRING   ) );    // [string,    4] I/F정보          
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->filler1              , sizeof( pOutBlock->filler1              ), DATA_TYPE_STRING   ) );    // [string,   41] 예비영역          
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sOrdxctPtnCode       , sizeof( pOutBlock->sOrdxctPtnCode       ), DATA_TYPE_STRING   ) );    // [string,    2] 주문체결유형코드    
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sOrdMktCode          , sizeof( pOutBlock->sOrdMktCode          ), DATA_TYPE_STRING   ) );    // [string,    2] 주문시장코드       
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sOrdPtnCode          , sizeof( pOutBlock->sOrdPtnCode          ), DATA_TYPE_STRING   ) );    // [string,    2] 주문유형코드       
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sMgmtBrnNo           , sizeof( pOutBlock->sMgmtBrnNo           ), DATA_TYPE_STRING   ) );    // [string,    3] 관리지점번호       
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sAcntNo              , sizeof( pOutBlock->sAcntNo              ), DATA_TYPE_STRING   ) );    // [string,   20] 계좌번호          
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sAcntNm              , sizeof( pOutBlock->sAcntNm              ), DATA_TYPE_STRING   ) );    // [string,   40] 계좌명           
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sIsuNo               , sizeof( pOutBlock->sIsuNo               ), DATA_TYPE_STRING   ) );    // [string,   12] 종목번호          
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sIsuNm               , sizeof( pOutBlock->sIsuNm               ), DATA_TYPE_STRING   ) );    // [string,   40] 종목명           
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sOrdNo               , sizeof( pOutBlock->sOrdNo               ), DATA_TYPE_STRING   ) );    // [long  ,   10] 주문번호          
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sOrgOrdNo            , sizeof( pOutBlock->sOrgOrdNo            ), DATA_TYPE_LONG     ) );    // [long  ,   10] 원주문번호        
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sExecNO              , sizeof( pOutBlock->sExecNO              ), DATA_TYPE_LONG     ) );    // [long  ,   10] 체결번호          
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sAbrdExecId          , sizeof( pOutBlock->sAbrdExecId          ), DATA_TYPE_LONG     ) );    // [long  ,   18] 해외체결ID        
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sOrdQty              , sizeof( pOutBlock->sOrdQty              ), DATA_TYPE_LONG     ) );    // [long  ,   16] 주문수량          
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sOrdPrc              , sizeof( pOutBlock->sOrdPrc              ), DATA_TYPE_LONG     ) );    // [long  ,   13] 주문가           
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sExecQty             , sizeof( pOutBlock->sExecQty             ), DATA_TYPE_LONG     ) );    // [long  ,   16] 체결수량          
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sExecPrc             , sizeof( pOutBlock->sExecPrc             ), DATA_TYPE_LONG     ) );    // [long  ,   13] 체결가           
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sMdfyCnfQty          , sizeof( pOutBlock->sMdfyCnfQty          ), DATA_TYPE_LONG     ) );    // [long  ,   16] 정정확인수량       
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sMdfyCnfPrc          , sizeof( pOutBlock->sMdfyCnfPrc          ), DATA_TYPE_LONG     ) );    // [long  ,   16] 정정확인가        
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sCancCnfQty          , sizeof( pOutBlock->sCancCnfQty          ), DATA_TYPE_LONG     ) );    // [long  ,   16] 취소확인수량       
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sRjtQty              , sizeof( pOutBlock->sRjtQty              ), DATA_TYPE_LONG     ) );    // [long  ,   16] 거부수량          
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sOrdTrxPtnCode       , sizeof( pOutBlock->sOrdTrxPtnCode       ), DATA_TYPE_LONG     ) );    // [long  ,    4] 주문처리유형코드    
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sMtiordSeqno         , sizeof( pOutBlock->sMtiordSeqno         ), DATA_TYPE_LONG     ) );    // [long  ,   10] 복수주문일련번호    
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sOrdCndi             , sizeof( pOutBlock->sOrdCndi             ), DATA_TYPE_LONG     ) );    // [string,    1] 주문조건          
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sOrdprcPtnCode       , sizeof( pOutBlock->sOrdprcPtnCode       ), DATA_TYPE_LONG     ) );    // [string,    2] 호가유형코드       
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sShtnIsuNo           , sizeof( pOutBlock->sShtnIsuNo           ), DATA_TYPE_STRING   ) );    // [long  ,    9] 단축종목번호       
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sOpDrtnNo            , sizeof( pOutBlock->sOpDrtnNo            ), DATA_TYPE_STRING   ) );    // [string,   12] 운용지시번호       
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sUnercQty            , sizeof( pOutBlock->sUnercQty            ), DATA_TYPE_LONG     ) );    // [string,   16] 미체결수량(주문)    
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sOrgOrdUnercQty      , sizeof( pOutBlock->sOrgOrdUnercQty      ), DATA_TYPE_STRING   ) );    // [string,   16] 원주문미체결수량    
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sOrgOrdMdfyQty       , sizeof( pOutBlock->sOrgOrdMdfyQty       ), DATA_TYPE_STRING   ) );    // [long  ,   16] 원주문정정수량      
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sOrgOrdCancQty       , sizeof( pOutBlock->sOrgOrdCancQty       ), DATA_TYPE_STRING   ) );    // [long  ,   16] 원주문취소수량      
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sOrdAvrExecPrc       , sizeof( pOutBlock->sOrdAvrExecPrc       ), DATA_TYPE_LONG     ) );    // [long  ,   13] 주문평균체결가      
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sOrdAmt              , sizeof( pOutBlock->sOrdAmt              ), DATA_TYPE_LONG     ) );    // [long  ,   16] 주문금액          
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sStdIsuNo            , sizeof( pOutBlock->sStdIsuNo            ), DATA_TYPE_LONG     ) );    // [long  ,   12] 표준종목번호       
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sBnsTp               , sizeof( pOutBlock->sBnsTp               ), DATA_TYPE_LONG     ) );    // [long  ,    1] 매매구분          
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sCommdaCode          , sizeof( pOutBlock->sCommdaCode          ), DATA_TYPE_LONG     ) );    // [string,    2] 통신매체코드       
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sOrdAcntNo           , sizeof( pOutBlock->sOrdAcntNo           ), DATA_TYPE_LONG     ) );    // [string,   20] 주문계좌번호       
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sAgrgtBrnNo          , sizeof( pOutBlock->sAgrgtBrnNo          ), DATA_TYPE_STRING   ) );    // [string,    3] 집계지점번호       
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sRegMktCode          , sizeof( pOutBlock->sRegMktCode          ), DATA_TYPE_STRING   ) );    // [string,    2] 등록시장코드       
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sMnyMgnRat           , sizeof( pOutBlock->sMnyMgnRat           ), DATA_TYPE_STRING   ) );    // [string,    7] 현금증거금률       
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sSubstMgnRat         , sizeof( pOutBlock->sSubstMgnRat         ), DATA_TYPE_STRING   ) );    // [string,    9] 대용증거금률       
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sMnyExecAmt          , sizeof( pOutBlock->sMnyExecAmt          ), DATA_TYPE_STRING   ) );    // [string,   16] 현금체결금액       
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sSubstExecAmt        , sizeof( pOutBlock->sSubstExecAmt        ), DATA_TYPE_STRING   ) );    // [string,   16] 대용체결금액       
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sCmsnAmtExecAmt      , sizeof( pOutBlock->sCmsnAmtExecAmt      ), DATA_TYPE_STRING   ) );    // [long  ,   16] 수수료체결금액      
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sPrdayRuseExecVal    , sizeof( pOutBlock->sPrdayRuseExecVal    ), DATA_TYPE_STRING   ) );    // [string,   16] 전일재사용체결금액   
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sCrdayRuseExecVal    , sizeof( pOutBlock->sCrdayRuseExecVal    ), DATA_TYPE_LONG     ) );    // [string,   16] 금일재사용체결금액   
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sSpotExecQty         , sizeof( pOutBlock->sSpotExecQty         ), DATA_TYPE_STRING   ) );    // [string,   16] 실물체결수량       
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sStslExecQty         , sizeof( pOutBlock->sStslExecQty         ), DATA_TYPE_STRING   ) );    // [string,   16] 공매도체결수량      
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sStrtgCode           , sizeof( pOutBlock->sStrtgCode           ), DATA_TYPE_STRING   ) );    // [string,    6] 전략코드          
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sGrpId               , sizeof( pOutBlock->sGrpId               ), DATA_TYPE_STRING   ) );    // [string,   20] 그룹ID           
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sOrdSeqno            , sizeof( pOutBlock->sOrdSeqno            ), DATA_TYPE_STRING   ) );    // [string,   10] 주문회차          
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sOrdUserId           , sizeof( pOutBlock->sOrdUserId           ), DATA_TYPE_STRING   ) );    // [long  ,   16] 주문자ID         
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sExecTime            , sizeof( pOutBlock->sExecTime            ), DATA_TYPE_STRING   ) );    // [long  ,    9] 체결시각          
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sRcptExecTime        , sizeof( pOutBlock->sRcptExecTime        ), DATA_TYPE_LONG     ) );    // [long  ,    9] 거래소수신체결시각   
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sRjtRsn              , sizeof( pOutBlock->sRjtRsn              ), DATA_TYPE_LONG     ) );    // [long  ,    8] 거부사유          
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sSecBalQty           , sizeof( pOutBlock->sSecBalQty           ), DATA_TYPE_LONG     ) );    // [long  ,   16] 잔고수량          
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sSpotOrdAbleQty      , sizeof( pOutBlock->sSpotOrdAbleQty      ), DATA_TYPE_LONG     ) );    // [long  ,   16] 실물주문가능수량    
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sOrdAbleRuseQty      , sizeof( pOutBlock->sOrdAbleRuseQty      ), DATA_TYPE_LONG     ) );    // [long  ,   16] 주문가능재사용수량   
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sFlctQty             , sizeof( pOutBlock->sFlctQty             ), DATA_TYPE_LONG     ) );    // [long  ,   16] 변동수량          
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sSecBalQtyD2         , sizeof( pOutBlock->sSecBalQtyD2         ), DATA_TYPE_LONG     ) );    // [long  ,   16] 잔고수량(D2)      
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sSellAbleQty         , sizeof( pOutBlock->sSellAbleQty         ), DATA_TYPE_LONG     ) );    // [long  ,   16] 매도주문가능수량    
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sUnercSellOrdQty     , sizeof( pOutBlock->sUnercSellOrdQty     ), DATA_TYPE_LONG     ) );    // [long  ,   16] 미체결매도주문수량   
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sAvrPchsPrc          , sizeof( pOutBlock->sAvrPchsPrc          ), DATA_TYPE_LONG     ) );    // [long  ,   13] 평균매입가        
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sPchsAmt             , sizeof( pOutBlock->sPchsAmt             ), DATA_TYPE_LONG     ) );    // [string,   16] 매입금액          
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sDeposit             , sizeof( pOutBlock->sDeposit             ), DATA_TYPE_STRING   ) );    // [string,   16] 예수금           
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sSubstAmt            , sizeof( pOutBlock->sSubstAmt            ), DATA_TYPE_STRING   ) );    // [long  ,   16] 대용금           
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sCsgnMnyMgn          , sizeof( pOutBlock->sCsgnMnyMgn          ), DATA_TYPE_LONG     ) );    // [long  ,   16] 위탁현금증거금액    
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sCsgnSubstMgn        , sizeof( pOutBlock->sCsgnSubstMgn        ), DATA_TYPE_LONG     ) );    // [long  ,   16] 위탁대용증거금액    
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sOrdAbleMny          , sizeof( pOutBlock->sOrdAbleMny          ), DATA_TYPE_LONG     ) );    // [long  ,   16] 주문가능현금       
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sOrdAbleSubstAmt     , sizeof( pOutBlock->sOrdAbleSubstAmt     ), DATA_TYPE_LONG     ) );    // [long  ,   16] 주문가능대용금액    
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sRuseAbleAmt         , sizeof( pOutBlock->sRuseAbleAmt         ), DATA_TYPE_LONG     ) );    // [string,   16] 재사용가능금액      
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sMgntrnCode          , sizeof( pOutBlock->sMgntrnCode          ), DATA_TYPE_STRING   ) );    // [string,    3] 신용거래코드       
	} 
     
	return 0L;
}
