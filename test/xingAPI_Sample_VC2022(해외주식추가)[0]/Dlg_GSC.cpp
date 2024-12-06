// Dlg_GSC.cpp : implementation file
//

#include "stdafx.h"
#include "XingAPI_Sample.h"
#include "Dlg_GSC.h"

#include "./Packet/GSC.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlg_GSC dialog

IMPLEMENT_DYNCREATE(CDlg_GSC, CDialog)

CDlg_GSC::CDlg_GSC(CWnd* pParent /*=NULL*/)
	: CDialog(CDlg_GSC::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlg_GSC)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CDlg_GSC::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlg_GSC)
	DDX_Control(pDX, IDC_OUTBLOCK, m_ctrlOutBlock);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlg_GSC, CDialog)
	//{{AFX_MSG_MAP(CDlg_GSC)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
	ON_WM_DESTROY()
	ON_BN_CLICKED( IDC_BUTTON_REQUEST,				OnButtonRequest	    )
	ON_MESSAGE	 ( WM_USER + XM_RECEIVE_REAL_DATA,	OnXMReceiveRealData	)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlg_GSC message handlers

BOOL CDlg_GSC::OnInitDialog() 
{
	CDialog::OnInitDialog();

	InitCtrls();
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CDlg_GSC::OnDestroy()
{
	UnadviseData();

	CDialog::OnDestroy();
}

void CDlg_GSC::OnButtonRequest() 
{
	UnadviseData();
	AdviseData();
}

//--------------------------------------------------------------------------------------
// 컨트롤 초기화
//--------------------------------------------------------------------------------------
void CDlg_GSC::InitCtrls()
{
	//-------------------------------------------------------------------------
	// OutBlock
	m_ctrlOutBlock.InsertColumn( 0, "필드  ", LVCFMT_LEFT, 150 );
	m_ctrlOutBlock.InsertColumn( 1, "데이터", LVCFMT_LEFT, 200 );

	int nRow = 0;
	m_ctrlOutBlock.InsertItem( nRow++, "종목코드         " );
	m_ctrlOutBlock.InsertItem( nRow++, "체결일자(현지)   " );
	m_ctrlOutBlock.InsertItem( nRow++, "체결일자(한국)   " );
	m_ctrlOutBlock.InsertItem( nRow++, "체결시간(현지)   " );
	m_ctrlOutBlock.InsertItem( nRow++, "체결시간(한국)   " );
	m_ctrlOutBlock.InsertItem( nRow++, "전일대비구분     " );
	m_ctrlOutBlock.InsertItem( nRow++, "체결가격         " );
	m_ctrlOutBlock.InsertItem( nRow++, "전일대비         " );
	m_ctrlOutBlock.InsertItem( nRow++, "등락율           " );
	m_ctrlOutBlock.InsertItem( nRow++, "시가             " );
	m_ctrlOutBlock.InsertItem( nRow++, "저가             " );
	m_ctrlOutBlock.InsertItem( nRow++, "고가             " );
	m_ctrlOutBlock.InsertItem( nRow++, "건별체결수량      " );
	m_ctrlOutBlock.InsertItem( nRow++, "누적체결수량      " );
	m_ctrlOutBlock.InsertItem( nRow++, "체결구분          " );
	m_ctrlOutBlock.InsertItem( nRow++, "초당시퀀스        " );
	m_ctrlOutBlock.InsertItem( nRow++, "누적거래대금      " );
	m_ctrlOutBlock.InsertItem( nRow++, "52주고가         " );
	m_ctrlOutBlock.InsertItem( nRow++, "52주저가         " );
}

//--------------------------------------------------------------------------------------
// 데이터 Advise
//--------------------------------------------------------------------------------------
void CDlg_GSC::AdviseData()
{
	TCHAR	szTrCode[]		= "GSC";
	//-----------------------------------------------------------
	// 데이터 취득
    CString strCode; GetDlgItemText( IDC_EDIT_CODE, strCode );

	//-----------------------------------------------------------
	// 데이터 전송
	BOOL bSuccess = g_iXingAPI.AdviseRealData( 
		GetSafeHwnd(),				// 데이터를 받을 윈도우, XM_RECEIVE_REAL_DATA 으로 온다.
		szTrCode,					// TR 번호
		strCode,					// 종목코드
		sizeof( GSC_InBlock )		// 종목코드 길이
		);

	//-----------------------------------------------------------
	// 에러체크
	if( bSuccess == FALSE )
	{
		MessageBox( "조회실패", "에러", MB_ICONSTOP );
	}
	else
	{
		m_strCode = strCode;
	}
}

//--------------------------------------------------------------------------------------
// 데이터 Unadvise
//--------------------------------------------------------------------------------------
void CDlg_GSC::UnadviseData()
{
	//-----------------------------------------------------------
	// 이전에 등록한 종목이 없다면 Return한다.
	if( m_strCode.IsEmpty() )
	{
		return;
	}

	TCHAR	szTrCode[]		= "GSC";
	
	//-----------------------------------------------------------
	// 데이터 전송
	BOOL bSuccess = g_iXingAPI.UnadviseRealData( 
		GetSafeHwnd(),				// 데이터를 받을 윈도우, XM_RECEIVE_REAL_DATA 으로 온다.
		szTrCode,					// TR 번호
		m_strCode,					// 종목코드
		sizeof( GSC_InBlock )		// 종목코드 길이
		);
	
	//-----------------------------------------------------------
	// 에러체크
	if( bSuccess == FALSE )
	{
		MessageBox( "조회실패", "에러", MB_ICONSTOP );
	}
	else
	{
		m_strCode.Empty();
	}
}

//--------------------------------------------------------------------------------------
// 데이터를 받음
//--------------------------------------------------------------------------------------
LRESULT CDlg_GSC::OnXMReceiveRealData( WPARAM wParam, LPARAM lParam )
{
	LPRECV_REAL_PACKET pRealPacket = (LPRECV_REAL_PACKET)lParam;

	if( strcmp( pRealPacket->szTrCode, "GSC" ) == 0 )
	{
		LPGSC_OutBlock pOutBlock = (LPGSC_OutBlock)pRealPacket->pszData;
		int nRow = 0;
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->symbol  , sizeof( pOutBlock->symbol ), DATA_TYPE_STRING		) );    // 종목코드        
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->ovsdate , sizeof( pOutBlock->ovsdate), DATA_TYPE_STRING		) );    // 체결일자(현지)            
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->kordate , sizeof( pOutBlock->kordate), DATA_TYPE_STRING		) );    // 체결일자(한국)            
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->trdtm   , sizeof( pOutBlock->trdtm  ), DATA_TYPE_STRING		) );    // 체결시간(현지)            
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->kortm   , sizeof( pOutBlock->kortm  ), DATA_TYPE_STRING		) );    // 체결시간(한국)            
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sign    , sizeof( pOutBlock->sign   ), DATA_TYPE_STRING		) );    // 전일대비구분        
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->price   , sizeof( pOutBlock->price  ), DATA_TYPE_DOT, 6		) );    // 체결가격            
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->diff    , sizeof( pOutBlock->diff   ), DATA_TYPE_DOT, 6		) );    // 전일대비            
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->rate    , sizeof( pOutBlock->rate   ), DATA_TYPE_FLOAT, 2	) );    // 등락율            
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->open    , sizeof( pOutBlock->open   ), DATA_TYPE_DOT, 6		) );    // 시가            
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->high    , sizeof( pOutBlock->high   ), DATA_TYPE_DOT, 6		) );    // 고가        
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->low     , sizeof( pOutBlock->low    ), DATA_TYPE_DOT, 6		) );    // 저가            
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->trdq    , sizeof( pOutBlock->trdq   ), DATA_TYPE_LONG		) );    // 건별체결수량            
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->totq    , sizeof( pOutBlock->totq   ), DATA_TYPE_LONG		) );    // 누적체결수량            
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->cgubun  , sizeof( pOutBlock->cgubun ), DATA_TYPE_STRING		) );    // 체결구분            
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->lSeq    , sizeof( pOutBlock->lSeq   ), DATA_TYPE_LONG		) );    // 초당시퀀스        
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->amount  , sizeof( pOutBlock->amount ), DATA_TYPE_LONG		) );    // 누적거래대금            
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->high52p , sizeof( pOutBlock->high52p), DATA_TYPE_DOT, 6		) );    // 52주고가            
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->low52p  , sizeof( pOutBlock->low52p ), DATA_TYPE_DOT, 6		) );    // 52주저가            
	} 
     
	return 0L;
}
