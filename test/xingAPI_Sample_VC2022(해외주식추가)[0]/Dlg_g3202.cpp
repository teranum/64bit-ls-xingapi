// Dlg_g3202.cpp : implementation file
//

#include "stdafx.h"
#include "XingAPI_Sample.h"
#include "Dlg_g3202.h"

#include "./Packet/g3202.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlg_g3202 dialog

IMPLEMENT_DYNCREATE(CDlg_g3202, CDialog)

CDlg_g3202::CDlg_g3202(CWnd* pParent /*=NULL*/)
	: CDialog(CDlg_g3202::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlg_g3202)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CDlg_g3202::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlg_g3202)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
	DDX_Control(pDX, IDC_OUTBLOCK, m_ctrlOutBlock);
	DDX_Control(pDX, IDC_OUTBLOCK1, m_ctrlOutBlock1);
}


BEGIN_MESSAGE_MAP(CDlg_g3202, CDialog)
	//{{AFX_MSG_MAP(CDlg_g3202)
	//}}AFX_MSG_MAP
	ON_BN_CLICKED( IDC_BUTTON_REQUEST,		  OnButtonRequest	  )
	ON_BN_CLICKED( IDC_BUTTON_REQUEST_NEXT,	  OnButtonRequestNext )
	ON_MESSAGE	 ( WM_USER + XM_RECEIVE_DATA, OnXMReceiveData	  )
	ON_MESSAGE	 ( WM_USER + XM_TIMEOUT_DATA, OnXMTimeoutData	  )
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlg_g3202 message handlers

BOOL CDlg_g3202::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	m_bCompress = FALSE;
	
	InitCtrls();
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CDlg_g3202::OnButtonRequest() 
{
	RequestData( FALSE );
}

void CDlg_g3202::OnButtonRequestNext() 
{
	RequestData( TRUE );	
}

//--------------------------------------------------------------------------------------
// 컨트롤 초기화
//--------------------------------------------------------------------------------------
void CDlg_g3202::InitCtrls()
{
	//-----------------------------------------------------------
	// OutBlock
	m_ctrlOutBlock.InsertColumn( 0, "지연구분",				LVCFMT_RIGHT, 60 );
	m_ctrlOutBlock.InsertColumn( 1, "KEY종목코드",			LVCFMT_RIGHT, 80 );
	m_ctrlOutBlock.InsertColumn( 2, "거래소코드",			LVCFMT_RIGHT, 80 );
	m_ctrlOutBlock.InsertColumn( 3, "종목코드",				LVCFMT_RIGHT, 80 );
	m_ctrlOutBlock.InsertColumn( 4, "연속시퀀스",			LVCFMT_RIGHT, 100);
	m_ctrlOutBlock.InsertColumn( 5, "레코드카운트",			LVCFMT_RIGHT, 60 );
	m_ctrlOutBlock.InsertColumn( 6, "전일시가",				LVCFMT_RIGHT, 80 );
	m_ctrlOutBlock.InsertColumn( 7, "전일고가",				LVCFMT_RIGHT, 80 );
	m_ctrlOutBlock.InsertColumn( 8, "전일저가",				LVCFMT_RIGHT, 80 );
	m_ctrlOutBlock.InsertColumn( 9, "전일종가",				LVCFMT_RIGHT, 80 );
	m_ctrlOutBlock.InsertColumn( 10, "전일거래량",			LVCFMT_RIGHT, 80 );
	m_ctrlOutBlock.InsertColumn( 11, "당일시가",			LVCFMT_RIGHT, 80 );
	m_ctrlOutBlock.InsertColumn( 12, "당일고가",			LVCFMT_RIGHT, 80 );
	m_ctrlOutBlock.InsertColumn( 13, "당일저가",			LVCFMT_RIGHT, 80 );
	m_ctrlOutBlock.InsertColumn( 14, "당일종가",			LVCFMT_RIGHT, 80 );
	m_ctrlOutBlock.InsertColumn( 15, "장시작시간(HHMMSS)",	LVCFMT_RIGHT, 60 );
	m_ctrlOutBlock.InsertColumn( 16, "장종료시간(HHMMSS)",	LVCFMT_RIGHT, 60 );
	m_ctrlOutBlock.InsertColumn( 17, "마지막Tick건수",		LVCFMT_RIGHT, 60 );
	m_ctrlOutBlock.InsertColumn( 18, "시차",					LVCFMT_RIGHT, 40 );

	//-----------------------------------------------------------
	// OutBlock1
	m_ctrlOutBlock1.InsertColumn(  0, "날짜",								LVCFMT_LEFT  , 60 );
	m_ctrlOutBlock1.InsertColumn(  1, "현지시간",							LVCFMT_RIGHT , 60 );
	m_ctrlOutBlock1.InsertColumn(  2, "시가",								LVCFMT_RIGHT , 80 );
	m_ctrlOutBlock1.InsertColumn(  3, "고가",								LVCFMT_RIGHT , 80 );
	m_ctrlOutBlock1.InsertColumn(  4, "저가",								LVCFMT_RIGHT , 80 );
	m_ctrlOutBlock1.InsertColumn(  5, "종가",								LVCFMT_RIGHT , 80 );
	m_ctrlOutBlock1.InsertColumn(  6, "체결량",							LVCFMT_RIGHT , 60 );
	m_ctrlOutBlock1.InsertColumn(  7, "수정구분",							LVCFMT_RIGHT , 60 );
	m_ctrlOutBlock1.InsertColumn(  8, "수정비율",							LVCFMT_RIGHT , 60 );
	m_ctrlOutBlock1.InsertColumn(  9, "수정주가반영항목",						LVCFMT_RIGHT , 60 );
	m_ctrlOutBlock1.InsertColumn(  10, "종가등락구분(1:상한2:상승3:보합",		LVCFMT_LEFT  , 60 );
}

//--------------------------------------------------------------------------------------
// 데이터 조회
//--------------------------------------------------------------------------------------
void CDlg_g3202::RequestData( BOOL bNext )
{
	//-----------------------------------------------------------
	// 주식현재가호가조회(g3202) ( attr,block,headtype=A )
	g3202InBlock	pckInBlock;

	TCHAR			szTrNo[]	= "g3202";
	char			szNextKey[]	= "";

	//-----------------------------------------------------------
	// 데이터 취득
	CString str_delaygb   ; GetDlgItemText( IDC_INBLOCK_DELAYGB      , str_delaygb      );		// 지연구분
	CString str_keysymbol ; GetDlgItemText( IDC_INBLOCK_KEYSYMBOL    , str_keysymbol	);		// KEY종목코드
	CString str_exchcd    ; GetDlgItemText( IDC_INBLOCK_EXCHCD       , str_exchcd       );		// 거래소코드
	CString str_symbol    ; GetDlgItemText( IDC_INBLOCK_SYMBOL		 , str_symbol		);		// 종목코드
	CString str_ncnt      ; GetDlgItemText( IDC_INBLOCK_NCNT	     , str_ncnt		    );		// 단위(N틱)
	CString str_qrycnt    ; GetDlgItemText( IDC_INBLOCK_QRYCNT	     , str_qrycnt		);		// 요청건수
	CString str_sdate     ; GetDlgItemText( IDC_INBLOCK_SDATE	     , str_sdate		);		// 시작일자
	CString str_edate     ; GetDlgItemText( IDC_INBLOCK_EDATE	     , str_edate		);		// 종료일자
	CString str_cts_seq    ; GetDlgItemText( IDC_INBLOCK_CTS_SEQ	 , str_cts_seq		);		// 연속시퀀스
	// 압축여부(Y:압축N:비압축)       
	m_bCompress = GetCheckedRadioButton( IDC_RD_COMPRESS, IDC_RD_DECOMPRESS ) == IDC_RD_COMPRESS ? TRUE : FALSE;

	CString str_comp_yn; 
	str_comp_yn = ( m_bCompress == TRUE ? "Y" : "N" );


	// 다음 조회일경우에 다음 조회시 사용하는 Field는 데이터를 넣으면 안된다.
	if( bNext == FALSE )
	{
		str_cts_seq = "";
	}
	
	//-----------------------------------------------------------
	// 데이터 초기화
	FillMemory( &pckInBlock, sizeof( pckInBlock ), ' ' );
	
	//-----------------------------------------------------------
	// 데이터 입력
	SetPacketData( pckInBlock.delaygb	, sizeof( pckInBlock.delaygb	), str_delaygb   , DATA_TYPE_STRING );	// 지연구분
	SetPacketData( pckInBlock.keysymbol	, sizeof( pckInBlock.keysymbol	), str_keysymbol , DATA_TYPE_STRING );	// KEY종목코드
	SetPacketData( pckInBlock.exchcd	, sizeof( pckInBlock.exchcd		), str_exchcd    , DATA_TYPE_STRING );	// 거래소코드
	SetPacketData( pckInBlock.symbol	, sizeof( pckInBlock.symbol		), str_symbol	 , DATA_TYPE_STRING );	// 종목코드
	SetPacketData( pckInBlock.ncnt		, sizeof( pckInBlock.ncnt		), str_ncnt		 , DATA_TYPE_LONG );	// 단위(N틱)
	SetPacketData( pckInBlock.qrycnt	, sizeof( pckInBlock.qrycnt		), str_qrycnt	 , DATA_TYPE_LONG );	// 요청건수
	SetPacketData( pckInBlock.sdate		, sizeof( pckInBlock.sdate      ), str_sdate	 , DATA_TYPE_STRING );	// 압축여부(Y:압축N:비압축)
	SetPacketData( pckInBlock.edate		, sizeof( pckInBlock.edate	    ), str_edate	 , DATA_TYPE_STRING );	// 시작일자
	SetPacketData( pckInBlock.cts_seq   , sizeof( pckInBlock.cts_seq    ), str_cts_seq   , DATA_TYPE_LONG );	// 종료일자
	SetPacketData( pckInBlock.comp_yn   , sizeof( pckInBlock.comp_yn    ), str_comp_yn   , DATA_TYPE_STRING );	// 연속시퀀스

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
	
	if( bNext == FALSE )
	{
		m_ctrlOutBlock.DeleteAllItems();
		m_ctrlOutBlock1.DeleteAllItems();
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
LRESULT CDlg_g3202::OnXMReceiveData( WPARAM wParam, LPARAM lParam )
{
	//-------------------------------------------------------------------------------------
	// Data를 받음
	if( wParam == REQUEST_DATA )
	{
		LPRECV_PACKET pRpData = (LPRECV_PACKET)lParam;

		// Header가 A Type 일 경우에는 Block 명이 들어온다.
		if( strcmp( pRpData->szBlockName, NAME_g3202OutBlock ) == 0 )
		{
			LPg3202OutBlock pOutBlock = (LPg3202OutBlock)pRpData->lpData;
			m_ctrlOutBlock.InsertItem( 0, "" );
			m_ctrlOutBlock.SetItemText(  0, 0, GetDispData( pOutBlock->delaygb ,	sizeof( pOutBlock->delaygb		), DATA_TYPE_STRING ) );
			m_ctrlOutBlock.SetItemText(  0, 1, GetDispData( pOutBlock->keysymbol ,	sizeof( pOutBlock->keysymbol	), DATA_TYPE_STRING ) );
			m_ctrlOutBlock.SetItemText(  0, 2, GetDispData( pOutBlock->exchcd ,		sizeof( pOutBlock->exchcd		), DATA_TYPE_STRING ) );
			m_ctrlOutBlock.SetItemText(  0, 3, GetDispData( pOutBlock->symbol ,		sizeof( pOutBlock->symbol		), DATA_TYPE_STRING ) );
			m_ctrlOutBlock.SetItemText(  0, 4, GetDispData( pOutBlock->cts_seq ,	sizeof( pOutBlock->cts_seq      ), DATA_TYPE_LONG ) );
			m_ctrlOutBlock.SetItemText(  0, 5, GetDispData( pOutBlock->rec_count ,	sizeof( pOutBlock->rec_count    ), DATA_TYPE_LONG ) );
			m_ctrlOutBlock.SetItemText(  0, 6, GetDispData( pOutBlock->preopen ,	sizeof( pOutBlock->preopen		), DATA_TYPE_DOT, 8 ) );
			m_ctrlOutBlock.SetItemText(  0, 7, GetDispData( pOutBlock->prehigh ,	sizeof( pOutBlock->prehigh		), DATA_TYPE_DOT, 8 ) );
			m_ctrlOutBlock.SetItemText(  0, 8, GetDispData( pOutBlock->prelow ,		sizeof( pOutBlock->prelow		), DATA_TYPE_DOT, 8 ) );
			m_ctrlOutBlock.SetItemText(  0, 9, GetDispData( pOutBlock->preclose ,	sizeof( pOutBlock->preclose     ), DATA_TYPE_DOT, 8 ) );
			m_ctrlOutBlock.SetItemText(  0, 10, GetDispData( pOutBlock->prevolume ,	sizeof( pOutBlock->prevolume    ), DATA_TYPE_LONG ) );
			m_ctrlOutBlock.SetItemText(  0, 11, GetDispData( pOutBlock->open ,		sizeof( pOutBlock->open		    ), DATA_TYPE_DOT, 8 ) );
			m_ctrlOutBlock.SetItemText(  0, 12, GetDispData( pOutBlock->high ,		sizeof( pOutBlock->high         ), DATA_TYPE_DOT, 8 ) );
			m_ctrlOutBlock.SetItemText(  0, 13, GetDispData( pOutBlock->low ,		sizeof( pOutBlock->low          ), DATA_TYPE_DOT, 8 ) );
			m_ctrlOutBlock.SetItemText(  0, 14, GetDispData( pOutBlock->close ,		sizeof( pOutBlock->close		), DATA_TYPE_DOT, 8 ) );
			m_ctrlOutBlock.SetItemText(  0, 15, GetDispData( pOutBlock->s_time ,	sizeof( pOutBlock->s_time		), DATA_TYPE_STRING ) );
			m_ctrlOutBlock.SetItemText(  0, 16, GetDispData( pOutBlock->e_time ,	sizeof( pOutBlock->e_time		), DATA_TYPE_STRING ) );
			m_ctrlOutBlock.SetItemText(  0, 17, GetDispData( pOutBlock->last_count ,sizeof( pOutBlock->last_count   ), DATA_TYPE_STRING ) );
			m_ctrlOutBlock.SetItemText(  0, 18, GetDispData( pOutBlock->timediff ,  sizeof( pOutBlock->timediff     ), DATA_TYPE_STRING ) );
		}
		else if( strcmp( pRpData->szBlockName, NAME_g3202OutBlock1 ) == 0 )
		{
			LPg3202OutBlock1 pOutBlock1 = (LPg3202OutBlock1)pRpData->lpData;

			int nDataLength = pRpData->nDataLength;
			int nCount = 0;

			g3202OutBlock1 szOutBlock1[2000];

			if( m_bCompress == TRUE)
			{
				nDataLength = g_iXingAPI.Decompress( (char *)pOutBlock1, (char *)&szOutBlock1[0], nDataLength );
				if (nDataLength  > 0)
				{
					nCount = nDataLength / sizeof( g3202OutBlock1 );
					pOutBlock1 = &szOutBlock1[0];
				}
			}
			else
			{
					nCount = nDataLength / sizeof( g3202OutBlock1 );
			}

			// Occurs 일 경우
			// Header가 'A' 이면 전체길이에서 OutBlock의 길이를 나눠서 갯수를 구한다.
			for( int i=0; i< nCount ; i++ )
			{
				m_ctrlOutBlock1.InsertItem( i, "" );
				m_ctrlOutBlock1.SetItemText( i,  0, GetDispData( pOutBlock1[i].date		, sizeof( pOutBlock1[i].date       ), DATA_TYPE_STRING ) );		// 날짜               
				m_ctrlOutBlock1.SetItemText( i,  1, GetDispData( pOutBlock1[i].loctime	, sizeof( pOutBlock1[i].loctime    ), DATA_TYPE_STRING ) );		// 시간               
				m_ctrlOutBlock1.SetItemText( i,  2, GetDispData( pOutBlock1[i].open		, sizeof( pOutBlock1[i].open       ), DATA_TYPE_DOT, 8 ) );		// 시가               
				m_ctrlOutBlock1.SetItemText( i,  3, GetDispData( pOutBlock1[i].high		, sizeof( pOutBlock1[i].high       ), DATA_TYPE_DOT, 8 ) );		// 고가               
				m_ctrlOutBlock1.SetItemText( i,  4, GetDispData( pOutBlock1[i].low		, sizeof( pOutBlock1[i].low		   ), DATA_TYPE_DOT, 8 ) );		// 저가               
				m_ctrlOutBlock1.SetItemText( i,  5, GetDispData( pOutBlock1[i].close	, sizeof( pOutBlock1[i].close      ), DATA_TYPE_DOT, 8 ) );		// 종가               
				m_ctrlOutBlock1.SetItemText( i,  6, GetDispData( pOutBlock1[i].exevol   , sizeof( pOutBlock1[i].exevol     ), DATA_TYPE_LONG ) );		// 거래량             
				m_ctrlOutBlock1.SetItemText( i,  7, GetDispData( pOutBlock1[i].jongchk  , sizeof( pOutBlock1[i].jongchk    ), DATA_TYPE_LONG ) );		// 수정구분           
				m_ctrlOutBlock1.SetItemText( i,  8, GetDispData( pOutBlock1[i].prtt_rate, sizeof( pOutBlock1[i].prtt_rate  ), DATA_TYPE_DOT, 2 ) );		// 수정비율           
				m_ctrlOutBlock1.SetItemText( i,  9, GetDispData( pOutBlock1[i].pricechk , sizeof( pOutBlock1[i].pricechk   ), DATA_TYPE_LONG ) );		// 수정주가반영항목   
				m_ctrlOutBlock1.SetItemText( i,  10, GetDispData( pOutBlock1[i].sign    , sizeof( pOutBlock1[i].sign       ), DATA_TYPE_STRING ) );		// 수정주가반영항목   
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
LRESULT CDlg_g3202::OnXMTimeoutData( WPARAM wParam, LPARAM lParam )
{
	g_iXingAPI.ReleaseRequestData( (int)lParam );

	return 0L;
}