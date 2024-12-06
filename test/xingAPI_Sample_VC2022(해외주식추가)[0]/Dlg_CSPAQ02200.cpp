// Dlg_CSPAQ02200.cpp : implementation file
//

#include "stdafx.h"
#include "xingapi_sample.h"
#include "Dlg_CSPAQ02200.h"

#include "./Packet/CSPAQ12200.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlg_CSPAQ02200 dialog


IMPLEMENT_DYNCREATE(CDlg_CSPAQ02200, CDialog)

CDlg_CSPAQ02200::CDlg_CSPAQ02200(CWnd* pParent /*=NULL*/)
	: CDialog(CDlg_CSPAQ02200::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlg_CSPAQ02200)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CDlg_CSPAQ02200::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlg_CSPAQ02200)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
	DDX_Control(pDX, IDC_OUTBLOCK1, m_ctrlOutBlock1);
	DDX_Control(pDX, IDC_OUTBLOCK2, m_ctrlOutBlock2);
}


BEGIN_MESSAGE_MAP(CDlg_CSPAQ02200, CDialog)
	//{{AFX_MSG_MAP(CDlg_CSPAQ02200)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
	ON_BN_CLICKED( IDC_BUTTON_REQUEST,		  OnButtonRequest	  )
	ON_MESSAGE	 ( WM_USER + XM_RECEIVE_DATA, OnXMReceiveData	  )
	ON_MESSAGE	 ( WM_USER + XM_TIMEOUT_DATA, OnXMTimeoutData	  )
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlg_CSPAQ02200 message handlers

BOOL CDlg_CSPAQ02200::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	InitCtrls();
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CDlg_CSPAQ02200::OnButtonRequest() 
{
	RequestData();
}


//--------------------------------------------------------------------------------------
// ��Ʈ�� �ʱ�ȭ
//--------------------------------------------------------------------------------------
void CDlg_CSPAQ02200::InitCtrls()
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

	//-------------------------------------------------------------------------
	// OutBlock1
	nCol = 0;
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "���ڵ尹��  ", FALSE,    5 );
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "����������ȣ", TRUE ,    3 );
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "���¹�ȣ    ", TRUE ,   20 );
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "��й�ȣ    ", TRUE ,    8 );
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "�ܰ��������", TRUE ,    1 );

	//-------------------------------------------------------------------------
	// OutBlock2
	nCol = 0;
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "���ڵ尹��                   ", FALSE,    5 );
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "������                       ", TRUE ,   40 );
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "���¸�                       ", TRUE ,   40 );
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "�����ֹ����ɱݾ�             ", FALSE,   16 );
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "��ݰ��ɱݾ�                 ", FALSE,   16 );
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "�ŷ��ұݾ�                   ", FALSE,   16 );
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "�ڽ��ڱݾ�                   ", FALSE,   16 );
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "�ܰ��򰡱ݾ�                 ", FALSE,   16 );
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "�̼��ݾ�                     ", FALSE,   16 );
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "��Ź�ڻ��Ѿ�                 ", FALSE,   16 );
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "������                       ", FALSE, 18.6 );
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "���ڿ���                     ", FALSE,   20 );
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "���ڼ��ͱݾ�                 ", FALSE,   16 );
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "�ſ�㺸�ֹ��ݾ�             ", FALSE,   16 );
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "������                       ", FALSE,   16 );
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "���ݾ�                     ", FALSE,   16 );
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "D1������                     ", FALSE,   16 );
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "D2������                     ", FALSE,   16 );
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "���ݹ̼��ݾ�                 ", FALSE,   16 );
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "���ű�����                   ", FALSE,   16 );
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "���űݴ��                   ", FALSE,   16 );
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "��ǥ�ݾ�                     ", FALSE,   16 );
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "����ֹ����ɱݾ�             ", FALSE,   16 );
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "���űݷ�100�ۼ�Ʈ�ֹ����ɱݾ�", FALSE,   16 );
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "���űݷ�35%�ֹ����ɱݾ�      ", FALSE,   16 );
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "���űݷ�50%�ֹ����ɱݾ�      ", FALSE,   16 );
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "���ϸŵ�����ݾ�             ", FALSE,   16 );
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "���ϸż�����ݾ�             ", FALSE,   16 );
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "���ϸŵ�����ݾ�             ", FALSE,   16 );
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "���ϸż�����ݾ�             ", FALSE,   16 );
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "D1��ü�����ҿ�ݾ�           ", FALSE,   16 );
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "D2��ü�����ҿ�ݾ�           ", FALSE,   16 );
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "D1�������Ⱑ�ɱݾ�           ", FALSE,   16 );
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "D2�������Ⱑ�ɱݾ�           ", FALSE,   16 );
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "��Ź�㺸����ݾ�             ", FALSE,   16 );
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "�ſ뼳��������               ", FALSE,   16 );
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "���ڱݾ�                     ", FALSE,   16 );
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "�����Ĵ㺸����               ", FALSE,  9.3 );
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "���㺸�ݾ�                   ", FALSE,   16 );
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "�δ㺸�ݾ�                   ", FALSE,   16 );
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "�ҿ�㺸�ݾ�                 ", FALSE,   16 );
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "���㺸�����ݾ�               ", FALSE,   16 );
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "�㺸�����ݾ�                 ", FALSE,   16 );
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "�߰��㺸����                 ", FALSE,   16 );
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "D1�ֹ����ɱݾ�               ", FALSE,   16 );
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "�ſ����ڹ̳��ݾ�             ", FALSE,   16 );
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "��Ÿ�뿩�ݾ�                 ", FALSE,   16 );
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "���������ݴ�Ÿűݾ�         ", FALSE,   16 );
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "���㺸�հ�ݾ�               ", FALSE,   16 );
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "�ſ��ֹ����ɱݾ�             ", FALSE,   16 );
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "�δ㺸�հ�ݾ�               ", FALSE,   16 );
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "�ſ�㺸������               ", FALSE,   16 );
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "�ſ�㺸���ݾ�             ", FALSE,   16 );
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "�߰��ſ�㺸����             ", FALSE,   16 );
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "�ſ�㺸����ݾ�           ", FALSE,   16 );
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "�߰��ſ�㺸���             ", FALSE,   16 );
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "�ŵ���ݴ㺸����ݾ�         ", FALSE,   16 );
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "ó�����ѱݾ�                 ", FALSE,   16 );
}

//--------------------------------------------------------------------------------------
// ������ ��ȸ
//--------------------------------------------------------------------------------------
void CDlg_CSPAQ02200::RequestData( BOOL bNext )
{
	//-----------------------------------------------------------
	CSPAQ12200InBlock1	pckInBlock;

	TCHAR			szTrNo[]		= "CSPAQ12200";
	char			szNextKey[]		= "";

	//-----------------------------------------------------------
	// ������ ���
    CString strAcntNo ;	GetDlgItemText( IDC_INBLOCK_ACNTNO, strAcntNo );		// ���¹�ȣ                       StartPos 5, Length 20
    CString strPwd;		GetDlgItemText( IDC_INBLOCK_PWD   , strPwd    );		// �Էº�й�ȣ                   StartPos 25, Length 8

	//-----------------------------------------------------------
	// ������ �ʱ�ȭ
	FillMemory( &pckInBlock, sizeof( pckInBlock ), ' ' );

	//-----------------------------------------------------------
	// ������ �Է�
	SetPacketData( pckInBlock.RecCnt   , sizeof( pckInBlock.RecCnt    ), "1"      , DATA_TYPE_LONG   );		// [long  ,    5] ���ڵ尹��                      StartPos 0, Length 5         
	SetPacketData( pckInBlock.MgmtBrnNo, sizeof( pckInBlock.MgmtBrnNo ), "0"      , DATA_TYPE_STRING );		// [string,    3] ����������ȣ                    StartPos 5, Length 3         
	SetPacketData( pckInBlock.AcntNo   , sizeof( pckInBlock.AcntNo    ), strAcntNo, DATA_TYPE_STRING );		// [string,   20] ���¹�ȣ                        StartPos 8, Length 20         
	SetPacketData( pckInBlock.Pwd      , sizeof( pckInBlock.Pwd       ), strPwd   , DATA_TYPE_STRING );		// [string,    8] ��й�ȣ                        StartPos 28, Length 8         
	SetPacketData( pckInBlock.BalCreTp , sizeof( pckInBlock.BalCreTp  ), "0"      , DATA_TYPE_STRING );		// [string,    1] �ܰ��������                    StartPos 36, Length 1         

	//-----------------------------------------------------------
	// ������ ����
	int nRqID = g_iXingAPI.Request( 
		GetSafeHwnd(),				// �����͸� ���� ������, XM_RECEIVE_DATA ���� �´�.
		szTrNo,						// TR ��ȣ
		&pckInBlock,				// InBlock ������
		sizeof( pckInBlock ),		// InBlock ������ ũ��
		bNext,						// ������ȸ ���� : ������ȸ�� ��쿡 �����Ѵ�.
		szNextKey,					// ������ȸ Key : Header Type�� B �� ��쿣 ���� ��ȸ�� ���� Next Key�� �־��ش�.
		30							// Timeout(��) : �ش� �ð�(��)���� �����Ͱ� ���� ������ Timeout�� �߻��Ѵ�. XM_TIMEOUT_DATA �޽����� �߻��Ѵ�.
	);

	m_ctrlOutBlock1.DeleteAllItems();
	m_ctrlOutBlock2.DeleteAllItems();

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
LRESULT CDlg_CSPAQ02200::OnXMReceiveData( WPARAM wParam, LPARAM lParam )
{
	//-------------------------------------------------------------------------------------
	// Data�� ����
	if( wParam == REQUEST_DATA )
	{
		LPRECV_PACKET pRpData = (LPRECV_PACKET)lParam;

		typedef struct
		{
			CSPAQ12200OutBlock1	outBlock1;
			CSPAQ12200OutBlock2	outBlock2;
		} CSPAQ12200AllOutBlock, *LPCSPAQ12200AllOutBlock;

		LPCSPAQ12200AllOutBlock pAllOutBlock = (LPCSPAQ12200AllOutBlock)pRpData->lpData;

		// ���� ������ ũ�Ⱑ Block ũ�⺸�� �۴ٸ� ó������ �ʴ´�.
		if( pRpData->nDataLength >= sizeof( CSPAQ12200OutBlock1 ) )
		{
			int nCol = 0;
			m_ctrlOutBlock1.InsertItem( 0, "" );
			m_ctrlOutBlock1.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock1.RecCnt   , sizeof( pAllOutBlock->outBlock1.RecCnt    ), DATA_TYPE_LONG   ) );    // [long  ,    5] ���ڵ尹��          
			m_ctrlOutBlock1.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock1.MgmtBrnNo, sizeof( pAllOutBlock->outBlock1.MgmtBrnNo ), DATA_TYPE_STRING ) );    // [string,    3] ����������ȣ        
			m_ctrlOutBlock1.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock1.AcntNo   , sizeof( pAllOutBlock->outBlock1.AcntNo    ), DATA_TYPE_STRING ) );    // [string,   20] ���¹�ȣ            
			m_ctrlOutBlock1.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock1.Pwd      , sizeof( pAllOutBlock->outBlock1.Pwd       ), DATA_TYPE_STRING ) );    // [string,    8] ��й�ȣ            
			m_ctrlOutBlock1.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock1.BalCreTp , sizeof( pAllOutBlock->outBlock1.BalCreTp  ), DATA_TYPE_STRING ) );    // [string,    1] �ܰ��������        
		}

		if( pRpData->nDataLength >= sizeof( CSPAQ12200OutBlock1 ) + sizeof( CSPAQ12200OutBlock2 ) )
		{
			int nCol = 0;
			m_ctrlOutBlock2.InsertItem( 0, "" );
			m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock2.RecCnt                , sizeof( pAllOutBlock->outBlock2.RecCnt                 ), DATA_TYPE_LONG      ) );    // [long  ,    5] ���ڵ尹��                   
			m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock2.BrnNm                 , sizeof( pAllOutBlock->outBlock2.BrnNm                  ), DATA_TYPE_STRING    ) );    // [string,   40] ������                       
			m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock2.AcntNm                , sizeof( pAllOutBlock->outBlock2.AcntNm                 ), DATA_TYPE_STRING    ) );    // [string,   40] ���¸�                       
			m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock2.MnyOrdAbleAmt         , sizeof( pAllOutBlock->outBlock2.MnyOrdAbleAmt          ), DATA_TYPE_LONG      ) );    // [long  ,   16] �����ֹ����ɱݾ�             
			m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock2.MnyoutAbleAmt         , sizeof( pAllOutBlock->outBlock2.MnyoutAbleAmt          ), DATA_TYPE_LONG      ) );    // [long  ,   16] ��ݰ��ɱݾ�                 
			m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock2.SeOrdAbleAmt          , sizeof( pAllOutBlock->outBlock2.SeOrdAbleAmt           ), DATA_TYPE_LONG      ) );    // [long  ,   16] �ŷ��ұݾ�                   
			m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock2.KdqOrdAbleAmt         , sizeof( pAllOutBlock->outBlock2.KdqOrdAbleAmt          ), DATA_TYPE_LONG      ) );    // [long  ,   16] �ڽ��ڱݾ�                   
			m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock2.BalEvalAmt            , sizeof( pAllOutBlock->outBlock2.BalEvalAmt             ), DATA_TYPE_LONG      ) );    // [long  ,   16] �ܰ��򰡱ݾ�                 
			m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock2.RcvblAmt              , sizeof( pAllOutBlock->outBlock2.RcvblAmt               ), DATA_TYPE_LONG      ) );    // [long  ,   16] �̼��ݾ�                     
			m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock2.DpsastTotamt          , sizeof( pAllOutBlock->outBlock2.DpsastTotamt           ), DATA_TYPE_LONG      ) );    // [long  ,   16] ��Ź�ڻ��Ѿ�                 
			m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock2.PnlRat                , sizeof( pAllOutBlock->outBlock2.PnlRat                 ), DATA_TYPE_DOUBLE, 6 ) );    // [double, 18.6] ������                       
			m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock2.InvstOrgAmt           , sizeof( pAllOutBlock->outBlock2.InvstOrgAmt            ), DATA_TYPE_LONG      ) );    // [long  ,   20] ���ڿ���                     
			m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock2.InvstPlAmt            , sizeof( pAllOutBlock->outBlock2.InvstPlAmt             ), DATA_TYPE_LONG      ) );    // [long  ,   16] ���ڼ��ͱݾ�                 
			m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock2.CrdtPldgOrdAmt        , sizeof( pAllOutBlock->outBlock2.CrdtPldgOrdAmt         ), DATA_TYPE_LONG      ) );    // [long  ,   16] �ſ�㺸�ֹ��ݾ�             
			m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock2.Dps                   , sizeof( pAllOutBlock->outBlock2.Dps                    ), DATA_TYPE_LONG      ) );    // [long  ,   16] ������                       
			m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock2.SubstAmt              , sizeof( pAllOutBlock->outBlock2.SubstAmt               ), DATA_TYPE_LONG      ) );    // [long  ,   16] ���ݾ�                     
			m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock2.D1Dps                 , sizeof( pAllOutBlock->outBlock2.D1Dps                  ), DATA_TYPE_LONG      ) );    // [long  ,   16] D1������                     
			m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock2.D2Dps                 , sizeof( pAllOutBlock->outBlock2.D2Dps                  ), DATA_TYPE_LONG      ) );    // [long  ,   16] D2������                     
			m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock2.MnyrclAmt             , sizeof( pAllOutBlock->outBlock2.MnyrclAmt              ), DATA_TYPE_LONG      ) );    // [long  ,   16] ���ݹ̼��ݾ�                 
			m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock2.MgnMny                , sizeof( pAllOutBlock->outBlock2.MgnMny                 ), DATA_TYPE_LONG      ) );    // [long  ,   16] ���ű�����                   
			m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock2.MgnSubst              , sizeof( pAllOutBlock->outBlock2.MgnSubst               ), DATA_TYPE_LONG      ) );    // [long  ,   16] ���űݴ��                   
			m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock2.ChckAmt               , sizeof( pAllOutBlock->outBlock2.ChckAmt                ), DATA_TYPE_LONG      ) );    // [long  ,   16] ��ǥ�ݾ�                     
			m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock2.SubstOrdAbleAmt       , sizeof( pAllOutBlock->outBlock2.SubstOrdAbleAmt        ), DATA_TYPE_LONG      ) );    // [long  ,   16] ����ֹ����ɱݾ�             
			m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock2.MgnRat100pctOrdAbleAmt, sizeof( pAllOutBlock->outBlock2.MgnRat100pctOrdAbleAmt ), DATA_TYPE_LONG      ) );    // [long  ,   16] ���űݷ�100�ۼ�Ʈ�ֹ����ɱݾ�
			m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock2.MgnRat35ordAbleAmt    , sizeof( pAllOutBlock->outBlock2.MgnRat35ordAbleAmt     ), DATA_TYPE_LONG      ) );    // [long  ,   16] ���űݷ�35%�ֹ����ɱݾ�      
			m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock2.MgnRat50ordAbleAmt    , sizeof( pAllOutBlock->outBlock2.MgnRat50ordAbleAmt     ), DATA_TYPE_LONG      ) );    // [long  ,   16] ���űݷ�50%�ֹ����ɱݾ�      
			m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock2.PrdaySellAdjstAmt     , sizeof( pAllOutBlock->outBlock2.PrdaySellAdjstAmt      ), DATA_TYPE_LONG      ) );    // [long  ,   16] ���ϸŵ�����ݾ�             
			m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock2.PrdayBuyAdjstAmt      , sizeof( pAllOutBlock->outBlock2.PrdayBuyAdjstAmt       ), DATA_TYPE_LONG      ) );    // [long  ,   16] ���ϸż�����ݾ�             
			m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock2.CrdaySellAdjstAmt     , sizeof( pAllOutBlock->outBlock2.CrdaySellAdjstAmt      ), DATA_TYPE_LONG      ) );    // [long  ,   16] ���ϸŵ�����ݾ�             
			m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock2.CrdayBuyAdjstAmt      , sizeof( pAllOutBlock->outBlock2.CrdayBuyAdjstAmt       ), DATA_TYPE_LONG      ) );    // [long  ,   16] ���ϸż�����ݾ�             
			m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock2.D1ovdRepayRqrdAmt     , sizeof( pAllOutBlock->outBlock2.D1ovdRepayRqrdAmt      ), DATA_TYPE_LONG      ) );    // [long  ,   16] D1��ü�����ҿ�ݾ�           
			m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock2.D2ovdRepayRqrdAmt     , sizeof( pAllOutBlock->outBlock2.D2ovdRepayRqrdAmt      ), DATA_TYPE_LONG      ) );    // [long  ,   16] D2��ü�����ҿ�ݾ�           
			m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock2.D1PrsmptWthdwAbleAmt  , sizeof( pAllOutBlock->outBlock2.D1PrsmptWthdwAbleAmt   ), DATA_TYPE_LONG      ) );    // [long  ,   16] D1�������Ⱑ�ɱݾ�           
			m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock2.D2PrsmptWthdwAbleAmt  , sizeof( pAllOutBlock->outBlock2.D2PrsmptWthdwAbleAmt   ), DATA_TYPE_LONG      ) );    // [long  ,   16] D2�������Ⱑ�ɱݾ�           
			m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock2.DpspdgLoanAmt         , sizeof( pAllOutBlock->outBlock2.DpspdgLoanAmt          ), DATA_TYPE_LONG      ) );    // [long  ,   16] ��Ź�㺸����ݾ�             
			m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock2.Imreq                 , sizeof( pAllOutBlock->outBlock2.Imreq                  ), DATA_TYPE_LONG      ) );    // [long  ,   16] �ſ뼳��������               
			m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock2.MloanAmt              , sizeof( pAllOutBlock->outBlock2.MloanAmt               ), DATA_TYPE_LONG      ) );    // [long  ,   16] ���ڱݾ�                     
			m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock2.ChgAfPldgRat          , sizeof( pAllOutBlock->outBlock2.ChgAfPldgRat           ), DATA_TYPE_DOUBLE, 3 ) );    // [double,  9.3] �����Ĵ㺸����               
			m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock2.OrgPldgAmt            , sizeof( pAllOutBlock->outBlock2.OrgPldgAmt             ), DATA_TYPE_LONG      ) );    // [long  ,   16] ���㺸�ݾ�                   
			m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock2.SubPldgAmt            , sizeof( pAllOutBlock->outBlock2.SubPldgAmt             ), DATA_TYPE_LONG      ) );    // [long  ,   16] �δ㺸�ݾ�                   
			m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock2.RqrdPldgAmt           , sizeof( pAllOutBlock->outBlock2.RqrdPldgAmt            ), DATA_TYPE_LONG      ) );    // [long  ,   16] �ҿ�㺸�ݾ�                 
			m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock2.OrgPdlckAmt           , sizeof( pAllOutBlock->outBlock2.OrgPdlckAmt            ), DATA_TYPE_LONG      ) );    // [long  ,   16] ���㺸�����ݾ�               
			m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock2.PdlckAmt              , sizeof( pAllOutBlock->outBlock2.PdlckAmt               ), DATA_TYPE_LONG      ) );    // [long  ,   16] �㺸�����ݾ�                 
			m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock2.AddPldgMny            , sizeof( pAllOutBlock->outBlock2.AddPldgMny             ), DATA_TYPE_LONG      ) );    // [long  ,   16] �߰��㺸����                 
			m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock2.D1OrdAbleAmt          , sizeof( pAllOutBlock->outBlock2.D1OrdAbleAmt           ), DATA_TYPE_LONG      ) );    // [long  ,   16] D1�ֹ����ɱݾ�               
			m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock2.CrdtIntdltAmt         , sizeof( pAllOutBlock->outBlock2.CrdtIntdltAmt          ), DATA_TYPE_LONG      ) );    // [long  ,   16] �ſ����ڹ̳��ݾ�             
			m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock2.EtclndAmt             , sizeof( pAllOutBlock->outBlock2.EtclndAmt              ), DATA_TYPE_LONG      ) );    // [long  ,   16] ��Ÿ�뿩�ݾ�                 
			m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock2.NtdayPrsmptCvrgAmt    , sizeof( pAllOutBlock->outBlock2.NtdayPrsmptCvrgAmt     ), DATA_TYPE_LONG      ) );    // [long  ,   16] ���������ݴ�Ÿűݾ�         
			m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock2.OrgPldgSumAmt         , sizeof( pAllOutBlock->outBlock2.OrgPldgSumAmt          ), DATA_TYPE_LONG      ) );    // [long  ,   16] ���㺸�հ�ݾ�               
			m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock2.CrdtOrdAbleAmt        , sizeof( pAllOutBlock->outBlock2.CrdtOrdAbleAmt         ), DATA_TYPE_LONG      ) );    // [long  ,   16] �ſ��ֹ����ɱݾ�             
			m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock2.SubPldgSumAmt         , sizeof( pAllOutBlock->outBlock2.SubPldgSumAmt          ), DATA_TYPE_LONG      ) );    // [long  ,   16] �δ㺸�հ�ݾ�               
			m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock2.CrdtPldgAmtMny        , sizeof( pAllOutBlock->outBlock2.CrdtPldgAmtMny         ), DATA_TYPE_LONG      ) );    // [long  ,   16] �ſ�㺸������               
			m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock2.CrdtPldgSubstAmt      , sizeof( pAllOutBlock->outBlock2.CrdtPldgSubstAmt       ), DATA_TYPE_LONG      ) );    // [long  ,   16] �ſ�㺸���ݾ�             
			m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock2.AddCrdtPldgMny        , sizeof( pAllOutBlock->outBlock2.AddCrdtPldgMny         ), DATA_TYPE_LONG      ) );    // [long  ,   16] �߰��ſ�㺸����             
			m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock2.CrdtPldgRuseAmt       , sizeof( pAllOutBlock->outBlock2.CrdtPldgRuseAmt        ), DATA_TYPE_LONG      ) );    // [long  ,   16] �ſ�㺸����ݾ�           
			m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock2.AddCrdtPldgSubst      , sizeof( pAllOutBlock->outBlock2.AddCrdtPldgSubst       ), DATA_TYPE_LONG      ) );    // [long  ,   16] �߰��ſ�㺸���             
			m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock2.CslLoanAmtdt1         , sizeof( pAllOutBlock->outBlock2.CslLoanAmtdt1          ), DATA_TYPE_LONG      ) );    // [long  ,   16] �ŵ���ݴ㺸����ݾ�         
			m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock2.DpslRestrcAmt         , sizeof( pAllOutBlock->outBlock2.DpslRestrcAmt          ), DATA_TYPE_LONG      ) );    // [long  ,   16] ó�����ѱݾ�                 
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
LRESULT CDlg_CSPAQ02200::OnXMTimeoutData( WPARAM wParam, LPARAM lParam )
{
	g_iXingAPI.ReleaseRequestData( (int)lParam );
	GetParent()->SendMessage( WMU_SET_MESSAGE, (WPARAM)"", (LPARAM)"Timeout" );		

	return 0L;
}
