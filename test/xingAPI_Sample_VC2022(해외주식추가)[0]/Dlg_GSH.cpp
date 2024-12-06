// Dlg_GSH.cpp : implementation file
//

#include "stdafx.h"
#include "XingAPI_Sample.h"
#include "Dlg_GSH.h"

#include "./Packet/GSH.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlg_GSH dialog

IMPLEMENT_DYNCREATE(CDlg_GSH, CDialog)

CDlg_GSH::CDlg_GSH(CWnd* pParent /*=NULL*/)
	: CDialog(CDlg_GSH::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlg_GSH)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CDlg_GSH::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlg_GSH)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
	DDX_Control(pDX, IDC_OUTBLOCK, m_ctrlOutBlock);
}


BEGIN_MESSAGE_MAP(CDlg_GSH, CDialog)
	//{{AFX_MSG_MAP(CDlg_GSH)
	//}}AFX_MSG_MAP
	ON_WM_DESTROY  ()
	ON_BN_CLICKED( IDC_BUTTON_REQUEST,				OnButtonRequest	    )
	ON_MESSAGE	 ( WM_USER + XM_RECEIVE_REAL_DATA,	OnXMReceiveRealData	)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlg_GSH message handlers

BOOL CDlg_GSH::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	InitCtrls();
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CDlg_GSH::OnDestroy()
{
	UnadviseData();

	CDialog::OnDestroy();
}

void CDlg_GSH::OnButtonRequest() 
{
	UnadviseData();
	AdviseData();
}


//--------------------------------------------------------------------------------------
// 컨트롤 초기화
//--------------------------------------------------------------------------------------
void CDlg_GSH::InitCtrls()
{
	//-------------------------------------------------------------------------
	// OutBlock
	m_ctrlOutBlock.InsertColumn( 0, "필드  ", LVCFMT_LEFT, 150 );
	m_ctrlOutBlock.InsertColumn( 1, "데이터", LVCFMT_LEFT, 200 );

	int nRow = 0;
	m_ctrlOutBlock.InsertItem( nRow++, "종목코드             " );
	m_ctrlOutBlock.InsertItem( nRow++, "현지호가시간         " );
	m_ctrlOutBlock.InsertItem( nRow++, "한국호가시간         " );
	m_ctrlOutBlock.InsertItem( nRow++, "매도호가 1           " );
	m_ctrlOutBlock.InsertItem( nRow++, "매수호가 1           " );
	m_ctrlOutBlock.InsertItem( nRow++, "매도호가 잔량 1      " );
	m_ctrlOutBlock.InsertItem( nRow++, "매수호가 잔량 1      " );
	m_ctrlOutBlock.InsertItem( nRow++, "매도호가 건수 1      " );
	m_ctrlOutBlock.InsertItem( nRow++, "매수호가 건수 1      " );
	m_ctrlOutBlock.InsertItem( nRow++, "매도호가 2           " );
	m_ctrlOutBlock.InsertItem( nRow++, "매수호가 2           " );
	m_ctrlOutBlock.InsertItem( nRow++, "매도호가 잔량 2      " );
	m_ctrlOutBlock.InsertItem( nRow++, "매수호가 잔량 2      " );
	m_ctrlOutBlock.InsertItem( nRow++, "매도호가 건수 2      " );
	m_ctrlOutBlock.InsertItem( nRow++, "매수호가 건수 2      " );
	m_ctrlOutBlock.InsertItem( nRow++, "매도호가 3           " );
	m_ctrlOutBlock.InsertItem( nRow++, "매수호가 3           " );
	m_ctrlOutBlock.InsertItem( nRow++, "매도호가 잔량 3      " );
	m_ctrlOutBlock.InsertItem( nRow++, "매수호가 잔량 3      " );
	m_ctrlOutBlock.InsertItem( nRow++, "매도호가 건수 3      " );
	m_ctrlOutBlock.InsertItem( nRow++, "매수호가 건수 3      " );
	m_ctrlOutBlock.InsertItem( nRow++, "매도호가 4           " );
	m_ctrlOutBlock.InsertItem( nRow++, "매수호가 4           " );
	m_ctrlOutBlock.InsertItem( nRow++, "매도호가 잔량 4      " );
	m_ctrlOutBlock.InsertItem( nRow++, "매수호가 잔량 4      " );
	m_ctrlOutBlock.InsertItem( nRow++, "매도호가 건수 4      " );
	m_ctrlOutBlock.InsertItem( nRow++, "매수호가 건수 4      " );
	m_ctrlOutBlock.InsertItem( nRow++, "매도호가 5           " );
	m_ctrlOutBlock.InsertItem( nRow++, "매수호가 5           " );
	m_ctrlOutBlock.InsertItem( nRow++, "매도호가 잔량 5      " );
	m_ctrlOutBlock.InsertItem( nRow++, "매수호가 잔량 5      " );
	m_ctrlOutBlock.InsertItem( nRow++, "매도호가 건수 5      " );
	m_ctrlOutBlock.InsertItem( nRow++, "매수호가 건수 5      " );
	m_ctrlOutBlock.InsertItem( nRow++, "매도호가 5           " );
	m_ctrlOutBlock.InsertItem( nRow++, "매수호가 6           " );
	m_ctrlOutBlock.InsertItem( nRow++, "매도호가 잔량 6      " );
	m_ctrlOutBlock.InsertItem( nRow++, "매수호가 잔량 6      " );
	m_ctrlOutBlock.InsertItem( nRow++, "매도호가 건수 6      " );
	m_ctrlOutBlock.InsertItem( nRow++, "매수호가 건수 6      " );
	m_ctrlOutBlock.InsertItem( nRow++, "매도호가 7           " );
	m_ctrlOutBlock.InsertItem( nRow++, "매수호가 7           " );
	m_ctrlOutBlock.InsertItem( nRow++, "매도호가 잔량 7      " );
	m_ctrlOutBlock.InsertItem( nRow++, "매수호가 잔량 7      " );
	m_ctrlOutBlock.InsertItem( nRow++, "매도호가 건수 7      " );
	m_ctrlOutBlock.InsertItem( nRow++, "매수호가 건수 7      " );
	m_ctrlOutBlock.InsertItem( nRow++, "매도호가 8           " );
	m_ctrlOutBlock.InsertItem( nRow++, "매수호가 8           " );
	m_ctrlOutBlock.InsertItem( nRow++, "매도호가 잔량 8      " );
	m_ctrlOutBlock.InsertItem( nRow++, "매수호가 잔량 8      " );
	m_ctrlOutBlock.InsertItem( nRow++, "매도호가 건수 8      " );
	m_ctrlOutBlock.InsertItem( nRow++, "매수호가 건수 8      " );
	m_ctrlOutBlock.InsertItem( nRow++, "매도호가 9           " );
	m_ctrlOutBlock.InsertItem( nRow++, "매수호가 9           " );
	m_ctrlOutBlock.InsertItem( nRow++, "매도호가 잔량 9      " );
	m_ctrlOutBlock.InsertItem( nRow++, "매수호가 잔량 9      " );
	m_ctrlOutBlock.InsertItem( nRow++, "매도호가 건수 9      " );
	m_ctrlOutBlock.InsertItem( nRow++, "매수호가 건수 9      " );
	m_ctrlOutBlock.InsertItem( nRow++, "매도호가 10          " );
	m_ctrlOutBlock.InsertItem( nRow++, "매수호가 10          " );
	m_ctrlOutBlock.InsertItem( nRow++, "매도호가 잔량 10     " );
	m_ctrlOutBlock.InsertItem( nRow++, "매수호가 잔량 10     " );
	m_ctrlOutBlock.InsertItem( nRow++, "매도호가 건수 10     " );
	m_ctrlOutBlock.InsertItem( nRow++, "매수호가 건수 10     " );
	m_ctrlOutBlock.InsertItem( nRow++, "매도호가총건수       " );
	m_ctrlOutBlock.InsertItem( nRow++, "매수호가총건수       " );
	m_ctrlOutBlock.InsertItem( nRow++, "매도호가총잔량       " );
	m_ctrlOutBlock.InsertItem( nRow++, "매수호가총잔량       " );
}

//--------------------------------------------------------------------------------------
// 데이터 Advise
//--------------------------------------------------------------------------------------
void CDlg_GSH::AdviseData()
{
	TCHAR	szTrCode[]		= "GSH";

	//-----------------------------------------------------------
	// 데이터 취득
    CString strCode; GetDlgItemText( IDC_EDIT_CODE, strCode );

	//-----------------------------------------------------------
	// 데이터 전송
	BOOL bSuccess = g_iXingAPI.AdviseRealData( 
		GetSafeHwnd(),				// 데이터를 받을 윈도우, XM_RECEIVE_REAL_DATA 으로 온다.
		szTrCode,					// TR 번호
		strCode,					// 종목코드
		sizeof( GSH_InBlock )		// 종목코드 길이
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
void CDlg_GSH::UnadviseData()
{
	//-----------------------------------------------------------
	// 이전에 등록한 종목이 없다면 Return한다.
	if( m_strCode.IsEmpty() )
	{
		return;
	}

	TCHAR	szTrCode[]		= "GSH";
	
	//-----------------------------------------------------------
	// 데이터 전송
	BOOL bSuccess = g_iXingAPI.UnadviseRealData( 
		GetSafeHwnd(),				// 데이터를 받을 윈도우, XM_RECEIVE_REAL_DATA 으로 온다.
		szTrCode,					// TR 번호
		m_strCode,					// 종목코드
		sizeof( GSH_InBlock )		// 종목코드 길이
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
LRESULT CDlg_GSH::OnXMReceiveRealData( WPARAM wParam, LPARAM lParam )
{
	LPRECV_REAL_PACKET pRealPacket = (LPRECV_REAL_PACKET)lParam;

	if( strcmp( pRealPacket->szTrCode, "GSH" ) == 0 )
	{
		LPGSH_OutBlock pOutBlock = (LPGSH_OutBlock)pRealPacket->pszData;
		int nRow = 0;
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->symbol   , sizeof( pOutBlock->symbol         ), DATA_TYPE_STRING    ) );    // 종목코드        
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->loctime  , sizeof( pOutBlock->loctime        ), DATA_TYPE_STRING    ) );    // 체결일자(현지)            
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->kortime  , sizeof( pOutBlock->kortime        ), DATA_TYPE_STRING    ) );    // 체결일자(한국)            
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->offerho1 , sizeof( pOutBlock->offerho1       ), DATA_TYPE_DOT, 6	) );    // 매도호가 1            
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->bidho1   , sizeof( pOutBlock->bidho1         ), DATA_TYPE_DOT, 6	) );    // 매수호가 1            
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->offerrem1, sizeof( pOutBlock->offerrem1      ), DATA_TYPE_LONG      ) );    // 매도호가 잔량 1        
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->bidrem1  , sizeof( pOutBlock->bidrem1        ), DATA_TYPE_LONG		) );    // 매수호가 잔량 1            
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->offerno1 , sizeof( pOutBlock->offerno1       ), DATA_TYPE_LONG		) );    // 매수호가 건수 1            
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->bidno1   , sizeof( pOutBlock->bidno1         ), DATA_TYPE_LONG      ) );    // 매수호가 건수 1            
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->offerho2 , sizeof( pOutBlock->offerho2       ), DATA_TYPE_DOT, 6	) );    // 매도호가 2            
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->bidho2   , sizeof( pOutBlock->bidho2         ), DATA_TYPE_DOT, 6	) );    // 매수호가 2            
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->offerrem2, sizeof( pOutBlock->offerrem2      ), DATA_TYPE_LONG		) );    // 매도호가 잔량 2        
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->bidrem2  , sizeof( pOutBlock->bidrem2        ), DATA_TYPE_LONG		) );    // 매수호가 잔량 2            
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->offerno2 , sizeof( pOutBlock->offerno2       ), DATA_TYPE_LONG		) );    // 매수호가 건수 2            
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->bidno2   , sizeof( pOutBlock->bidno2         ), DATA_TYPE_LONG      ) );    // 매수호가 건수 2  
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->offerho3 , sizeof( pOutBlock->offerho3       ), DATA_TYPE_DOT, 6	) );    // 매도호가 3            
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->bidho3   , sizeof( pOutBlock->bidho3         ), DATA_TYPE_DOT, 6	) );    // 매수호가 3            
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->offerrem3, sizeof( pOutBlock->offerrem3      ), DATA_TYPE_LONG      ) );    // 매도호가 잔량 3        
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->bidrem3  , sizeof( pOutBlock->bidrem3        ), DATA_TYPE_LONG		) );    // 매수호가 잔량 3            
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->offerno3 , sizeof( pOutBlock->offerno3       ), DATA_TYPE_LONG		) );    // 매수호가 건수 3            
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->bidno3   , sizeof( pOutBlock->bidno3         ), DATA_TYPE_LONG      ) );    // 매수호가 건수 3  
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->offerho4 , sizeof( pOutBlock->offerho4       ), DATA_TYPE_DOT, 6	) );    // 매도호가 4            
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->bidho4   , sizeof( pOutBlock->bidho4         ), DATA_TYPE_DOT, 6	) );    // 매수호가 4            
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->offerrem4, sizeof( pOutBlock->offerrem4      ), DATA_TYPE_LONG      ) );    // 매도호가 잔량 4        
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->bidrem4  , sizeof( pOutBlock->bidrem4        ), DATA_TYPE_LONG		) );    // 매수호가 잔량 4            
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->offerno4 , sizeof( pOutBlock->offerno4       ), DATA_TYPE_LONG		) );    // 매수호가 건수 4            
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->bidno4   , sizeof( pOutBlock->bidno4         ), DATA_TYPE_LONG      ) );    // 매수호가 건수 4  
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->offerho5 , sizeof( pOutBlock->offerho5       ), DATA_TYPE_DOT, 6	) );    // 매도호가 5            
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->bidho5   , sizeof( pOutBlock->bidho5         ), DATA_TYPE_DOT, 6	) );    // 매수호가 5            
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->offerrem5, sizeof( pOutBlock->offerrem5      ), DATA_TYPE_LONG      ) );    // 매도호가 잔량 5        
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->bidrem5  , sizeof( pOutBlock->bidrem5        ), DATA_TYPE_LONG		) );    // 매수호가 잔량 5            
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->offerno5 , sizeof( pOutBlock->offerno5       ), DATA_TYPE_LONG		) );    // 매수호가 건수 5            
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->bidno5   , sizeof( pOutBlock->bidno5         ), DATA_TYPE_LONG      ) );    // 매수호가 건수 5  
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->offerho6 , sizeof( pOutBlock->offerho6       ), DATA_TYPE_DOT, 6	) );    // 매도호가 6            
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->bidho6   , sizeof( pOutBlock->bidho6         ), DATA_TYPE_DOT, 6	) );    // 매수호가 6            
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->offerrem6, sizeof( pOutBlock->offerrem6      ), DATA_TYPE_LONG      ) );    // 매도호가 잔량 6        
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->bidrem6  , sizeof( pOutBlock->bidrem6        ), DATA_TYPE_LONG		) );    // 매수호가 잔량 6            
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->offerno6 , sizeof( pOutBlock->offerno6       ), DATA_TYPE_LONG		) );    // 매수호가 건수 6            
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->bidno6   , sizeof( pOutBlock->bidno6         ), DATA_TYPE_LONG      ) );    // 매수호가 건수 6  
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->offerho7 , sizeof( pOutBlock->offerho7       ), DATA_TYPE_DOT, 6	) );    // 매도호가 7            
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->bidho7   , sizeof( pOutBlock->bidho7         ), DATA_TYPE_DOT, 6	) );    // 매수호가 7            
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->offerrem7, sizeof( pOutBlock->offerrem7      ), DATA_TYPE_LONG      ) );    // 매도호가 잔량 7        
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->bidrem7  , sizeof( pOutBlock->bidrem7        ), DATA_TYPE_LONG		) );    // 매수호가 잔량 7            
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->offerno7 , sizeof( pOutBlock->offerno7       ), DATA_TYPE_LONG		) );    // 매수호가 건수 7            
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->bidno7   , sizeof( pOutBlock->bidno7         ), DATA_TYPE_LONG      ) );    // 매수호가 건수 7  
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->offerho8 , sizeof( pOutBlock->offerho8       ), DATA_TYPE_DOT, 6	) );    // 매도호가 7            
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->bidho8   , sizeof( pOutBlock->bidho8         ), DATA_TYPE_DOT, 6	) );    // 매수호가 8            
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->offerrem8, sizeof( pOutBlock->offerrem8      ), DATA_TYPE_LONG		) );    // 매도호가 잔량 8        
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->bidrem8  , sizeof( pOutBlock->bidrem8        ), DATA_TYPE_LONG		) );    // 매수호가 잔량 8            
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->offerno8 , sizeof( pOutBlock->offerno8       ), DATA_TYPE_LONG		) );    // 매수호가 건수 8            
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->bidno8   , sizeof( pOutBlock->bidno8         ), DATA_TYPE_LONG		) );    // 매수호가 건수 8  
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->offerho9 , sizeof( pOutBlock->offerho9       ), DATA_TYPE_DOT, 6	) );    // 매도호가 9            
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->bidho9   , sizeof( pOutBlock->bidho9         ), DATA_TYPE_DOT, 6	) );    // 매수호가 9            
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->offerrem9, sizeof( pOutBlock->offerrem9      ), DATA_TYPE_LONG		) );    // 매도호가 잔량 9        
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->bidrem9  , sizeof( pOutBlock->bidrem9        ), DATA_TYPE_LONG		) );    // 매수호가 잔량 9            
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->offerno9 , sizeof( pOutBlock->offerno9       ), DATA_TYPE_LONG		) );    // 매수호가 건수 9            
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->bidno9   , sizeof( pOutBlock->bidno9         ), DATA_TYPE_LONG      ) );    // 매수호가 건수 9  
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->offerho10, sizeof( pOutBlock->offerho10      ), DATA_TYPE_DOT, 6	) );    // 매도호가 10            
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->bidho10  , sizeof( pOutBlock->bidho10        ), DATA_TYPE_DOT, 6	) );    // 매수호가 10            
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->offerrem10 , sizeof( pOutBlock->offerrem10   ), DATA_TYPE_LONG      ) );    // 매도호가 잔량 10        
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->bidrem10   , sizeof( pOutBlock->bidrem10     ), DATA_TYPE_LONG		) );    // 매수호가 잔량 10            
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->offerno10  , sizeof( pOutBlock->offerno10    ), DATA_TYPE_LONG		) );    // 매수호가 건수 10            
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->bidno10    , sizeof( pOutBlock->bidno10      ), DATA_TYPE_LONG      ) );    // 매수호가 건수 10  
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->totoffercnt , sizeof( pOutBlock->totoffercnt ), DATA_TYPE_LONG      ) );    // 매도호가총건수        
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->totbidcnt   , sizeof( pOutBlock->totbidcnt   ), DATA_TYPE_LONG		) );    // 매도호가총건수            
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->totofferrem , sizeof( pOutBlock->totofferrem ), DATA_TYPE_LONG		) );    // 매도호가총수량            
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->totbidrem   , sizeof( pOutBlock->totbidrem   ), DATA_TYPE_LONG      ) );    // 매도호가총수량         
	}

	return 0L;
}
