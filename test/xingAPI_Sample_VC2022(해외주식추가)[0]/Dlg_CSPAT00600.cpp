// Dlg_CSPAT00600.cpp : implementation file
//

#include "stdafx.h"
#include "xingapi_sample.h"
#include "Dlg_CSPAT00600.h"

#include "./Packet/CSPAT00600.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlg_CSPAT00600 dialog


IMPLEMENT_DYNCREATE(CDlg_CSPAT00600, CDialog)

CDlg_CSPAT00600::CDlg_CSPAT00600(CWnd* pParent /*=NULL*/)
	: CDialog(CDlg_CSPAT00600::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlg_CSPAT00600)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CDlg_CSPAT00600::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlg_CSPAT00600)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
	DDX_Control(pDX, IDC_OUTBLOCK1, m_ctrlOutBlock1);
	DDX_Control(pDX, IDC_OUTBLOCK2, m_ctrlOutBlock2);
}


BEGIN_MESSAGE_MAP(CDlg_CSPAT00600, CDialog)
	//{{AFX_MSG_MAP(CDlg_CSPAT00600)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
	ON_BN_CLICKED( IDC_BUTTON_REQUEST,		  OnButtonRequest	  )
	ON_MESSAGE	 ( WM_USER + XM_RECEIVE_DATA, OnXMReceiveData	  )
	ON_MESSAGE	 ( WM_USER + XM_TIMEOUT_DATA, OnXMTimeoutData	  )
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlg_CSPAT00600 message handlers

BOOL CDlg_CSPAT00600::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	InitCtrls();
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CDlg_CSPAT00600::OnButtonRequest() 
{
	RequestData();
}


//--------------------------------------------------------------------------------------
// ��Ʈ�� �ʱ�ȭ
//--------------------------------------------------------------------------------------
void CDlg_CSPAT00600::InitCtrls()
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

	((CComboBox*)GetDlgItem( IDC_INBLOCK_ACNTNO        ))->SetCurSel( 0 );	// ���¹�ȣ
	((CComboBox*)GetDlgItem( IDC_INBLOCK_BNSTPCODE     ))->SetCurSel( 0 );	// �Ÿű���             
	((CComboBox*)GetDlgItem( IDC_INBLOCK_ORDPRCPTNCODE ))->SetCurSel( 0 );	// ȣ�������ڵ�         
	((CComboBox*)GetDlgItem( IDC_INBLOCK_MGNTRNCODE	   ))->SetCurSel( 0 );	// �ſ�ŷ��ڵ�         
	((CComboBox*)GetDlgItem( IDC_INBLOCK_ORDCNDITPCODE ))->SetCurSel( 0 );	// �ֹ����Ǳ���         

	//-------------------------------------------------------------------------
	// OutBlock1
	nCol = 0;
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "���ڵ尹��          ", FALSE,    5 );
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "���¹�ȣ            ", TRUE ,   20 );
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "�Էº�й�ȣ        ", TRUE ,    8 );
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "�����ȣ            ", TRUE ,   12 );
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "�ֹ�����            ", FALSE,   16 );
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "�ֹ���              ", FALSE, 13.2 );
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "�Ÿű���            ", TRUE ,    1 );
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "ȣ�������ڵ�        ", TRUE ,    2 );
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "���α׷�ȣ�������ڵ�", TRUE ,    2 );
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "���ŵ����ɿ���      ", TRUE ,    1 );
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "���ŵ�ȣ������      ", TRUE ,    1 );
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "��Ÿ�ü�ڵ�        ", TRUE ,    2 );
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "�ſ�ŷ��ڵ�        ", TRUE ,    3 );
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "������              ", TRUE ,    8 );
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "ȸ����ȣ            ", TRUE ,    3 );
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "�ֹ����Ǳ���        ", TRUE ,    1 );
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "�����ڵ�            ", TRUE ,    6 );
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "�׷�ID              ", TRUE ,   20 );
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "�ֹ�ȸ��            ", FALSE,   10 );
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "��Ʈ��������ȣ      ", FALSE,   10 );
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "�ٽ��Ϲ�ȣ          ", FALSE,   10 );
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "Ʈ��ġ��ȣ          ", FALSE,   10 );
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "�����۹�ȣ          ", FALSE,   10 );
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "������ù�ȣ        ", TRUE ,   12 );
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "�����������ڿ���    ", TRUE ,    1 );
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "�ݴ�Ÿű���        ", TRUE ,    1 );

	//-------------------------------------------------------------------------
	// OutBlock2
	nCol = 0;
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "���ڵ尹��      ", FALSE,    5 );
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "�ֹ���ȣ        ", FALSE,   10 );
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "�ֹ��ð�        ", TRUE ,    9 );
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "�ֹ������ڵ�    ", TRUE ,    2 );
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "�ֹ������ڵ�    ", TRUE ,    2 );
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "���������ȣ    ", TRUE ,    9 );
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "���������ȣ    ", TRUE ,    9 );
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "�ֹ��ݾ�        ", FALSE,   16 );
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "�����ֹ���ȣ    ", FALSE,   10 );
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "�ݴ�Ÿ��Ϸù�ȣ", FALSE,   10 );
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "�����ֹ���ȣ    ", FALSE,   10 );
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "�ǹ��ֹ�����    ", FALSE,   16 );
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "�����ֹ�����  ", FALSE,   16 );
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "�����ֹ��ݾ�    ", FALSE,   16 );
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "����ֹ��ݾ�    ", FALSE,   16 );
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "�����ֹ��ݾ�  ", FALSE,   16 );
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "���¸�          ", TRUE ,   40 );
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "�����          ", TRUE ,   40 );
}

//--------------------------------------------------------------------------------------
// ������ ��ȸ
//--------------------------------------------------------------------------------------
void CDlg_CSPAT00600::RequestData( BOOL bNext )
{
	//-----------------------------------------------------------
// ���������ֹ�(CSPAT00600) ( base21=SONAT000,headtype=B )
	CSPAT00600InBlock1	pckInBlock;

	TCHAR			szTrNo[]		= "CSPAT00600";
	char			szNextKey[]		= "";

	//-----------------------------------------------------------
	// ������ ���
    CString strAcntNo       ;		GetDlgItemText( IDC_INBLOCK_ACNTNO       , strAcntNo        );		// ���¹�ȣ                       StartPos 5, Length 20
    CString strInptPwd      ;		GetDlgItemText( IDC_INBLOCK_INPTPWD      , strInptPwd       );		// �Էº�й�ȣ                   StartPos 25, Length 8
    CString strIsuNo        ;		GetDlgItemText( IDC_INBLOCK_ISUNO        , strIsuNo         );		// �����ȣ                       StartPos 33, Length 12
    CString strOrdQty       ;		GetDlgItemText( IDC_INBLOCK_ORDQTY       , strOrdQty        );		// �ֹ�����                       StartPos 45, Length 16
    CString strOrdPrc       ;		GetDlgItemText( IDC_INBLOCK_ORDPRC       , strOrdPrc        );		// �ֹ���                         StartPos 61, Length 13
    CString strBnsTpCode    ;		GetDlgItemText( IDC_INBLOCK_BNSTPCODE    , strBnsTpCode     );		// �Ÿű���                       StartPos 74, Length 1
    CString strOrdprcPtnCode;		GetDlgItemText( IDC_INBLOCK_ORDPRCPTNCODE, strOrdprcPtnCode );		// ȣ�������ڵ�                   StartPos 75, Length 2
    CString strMgntrnCode   ;		GetDlgItemText( IDC_INBLOCK_MGNTRNCODE   , strMgntrnCode    );		// �ſ�ŷ��ڵ�                   StartPos 83, Length 3
    CString strLoanDt       ;		GetDlgItemText( IDC_INBLOCK_LOANDT       , strLoanDt        );		// ������                         StartPos 86, Length 8
    CString strOrdCndiTpCode;		GetDlgItemText( IDC_INBLOCK_ORDCNDITPCODE, strOrdCndiTpCode ); 		// �ֹ����Ǳ���                   StartPos 97, Length 1

	//-----------------------------------------------------------
	// ������ �ʱ�ȭ
	FillMemory( &pckInBlock, sizeof( pckInBlock ), ' ' );

	//-----------------------------------------------------------
	// ������ �Է�
	SetPacketData( pckInBlock.AcntNo       , sizeof( pckInBlock.AcntNo        ), strAcntNo       , DATA_TYPE_STRING );		// ���¹�ȣ                 
	SetPacketData( pckInBlock.InptPwd      , sizeof( pckInBlock.InptPwd       ), strInptPwd      , DATA_TYPE_STRING );		// �Էº�й�ȣ             
	SetPacketData( pckInBlock.IsuNo        , sizeof( pckInBlock.IsuNo         ), strIsuNo        , DATA_TYPE_STRING );		// �����ȣ                 
	SetPacketData( pckInBlock.OrdQty       , sizeof( pckInBlock.OrdQty        ), strOrdQty       , DATA_TYPE_LONG   );		// �ֹ�����                 
	SetPacketData( pckInBlock.OrdPrc       , sizeof( pckInBlock.OrdPrc        ), strOrdPrc       , DATA_TYPE_FLOAT_DOT, 2 );	// �ֹ���, Header Type�� B �� ��� Data Type�� �Ǽ��� �Ҽ����� �����ؾ� �Ѵ�.
	SetPacketData( pckInBlock.BnsTpCode    , sizeof( pckInBlock.BnsTpCode     ), strBnsTpCode    , DATA_TYPE_STRING );		// �Ÿű���                 
	SetPacketData( pckInBlock.OrdprcPtnCode, sizeof( pckInBlock.OrdprcPtnCode ), strOrdprcPtnCode, DATA_TYPE_STRING );		// ȣ�������ڵ�             
	SetPacketData( pckInBlock.MgntrnCode   , sizeof( pckInBlock.MgntrnCode    ), strMgntrnCode   , DATA_TYPE_STRING );		// �ſ�ŷ��ڵ�             
	SetPacketData( pckInBlock.LoanDt       , sizeof( pckInBlock.LoanDt        ), strLoanDt       , DATA_TYPE_STRING );		// ������                   
	SetPacketData( pckInBlock.OrdCndiTpCode, sizeof( pckInBlock.OrdCndiTpCode ), strOrdCndiTpCode, DATA_TYPE_STRING ); 		// �ֹ����Ǳ���             

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
LRESULT CDlg_CSPAT00600::OnXMReceiveData( WPARAM wParam, LPARAM lParam )
{
	//-------------------------------------------------------------------------------------
	// Data�� ����
	if( wParam == REQUEST_DATA )
	{
		LPRECV_PACKET pRpData = (LPRECV_PACKET)lParam;

		typedef struct
		{
			CSPAT00600OutBlock1	outBlock1;
			CSPAT00600OutBlock2	outBlock2;
		} CSPAT00600AllOutBlock, *LPCSPAT00600AllOutBlock;

		LPCSPAT00600AllOutBlock pAllOutBlock = (LPCSPAT00600AllOutBlock)pRpData->lpData;

		// ���� ������ ũ�Ⱑ Block ũ�⺸�� �۴ٸ� ó������ �ʴ´�.
		if( pRpData->nDataLength >= sizeof( CSPAT00600OutBlock1 ) )
		{
			int nCol = 0;
			m_ctrlOutBlock1.InsertItem( 0, "" );
			m_ctrlOutBlock1.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock1.RecCnt           , sizeof( pAllOutBlock->outBlock1.RecCnt            ), DATA_TYPE_LONG   ) );    // ���ڵ尹��          
			m_ctrlOutBlock1.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock1.AcntNo           , sizeof( pAllOutBlock->outBlock1.AcntNo            ), DATA_TYPE_STRING ) );    // ���¹�ȣ            
			m_ctrlOutBlock1.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock1.InptPwd          , sizeof( pAllOutBlock->outBlock1.InptPwd           ), DATA_TYPE_STRING ) );    // �Էº�й�ȣ        
			m_ctrlOutBlock1.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock1.IsuNo            , sizeof( pAllOutBlock->outBlock1.IsuNo             ), DATA_TYPE_STRING ) );    // �����ȣ            
			m_ctrlOutBlock1.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock1.OrdQty           , sizeof( pAllOutBlock->outBlock1.OrdQty            ), DATA_TYPE_LONG   ) );    // �ֹ�����            
			m_ctrlOutBlock1.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock1.OrdPrc           , sizeof( pAllOutBlock->outBlock1.OrdPrc            ), DATA_TYPE_FLOAT_DOT, 2 ) );  // �ֹ���, Header�� B Type �� ��� �Ǽ��� ������ �Ҽ����� �����Ѵ�.          
			m_ctrlOutBlock1.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock1.BnsTpCode        , sizeof( pAllOutBlock->outBlock1.BnsTpCode         ), DATA_TYPE_STRING ) );    // �Ÿű���            
			m_ctrlOutBlock1.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock1.OrdprcPtnCode    , sizeof( pAllOutBlock->outBlock1.OrdprcPtnCode     ), DATA_TYPE_STRING ) );    // ȣ�������ڵ�        
			m_ctrlOutBlock1.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock1.PrgmOrdprcPtnCode, sizeof( pAllOutBlock->outBlock1.PrgmOrdprcPtnCode ), DATA_TYPE_STRING ) );    // ���α׷�ȣ�������ڵ�
			m_ctrlOutBlock1.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock1.StslAbleYn       , sizeof( pAllOutBlock->outBlock1.StslAbleYn        ), DATA_TYPE_STRING ) );    // ���ŵ����ɿ���      
			m_ctrlOutBlock1.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock1.StslOrdprcTpCode , sizeof( pAllOutBlock->outBlock1.StslOrdprcTpCode  ), DATA_TYPE_STRING ) );    // ���ŵ�ȣ������      
			m_ctrlOutBlock1.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock1.CommdaCode       , sizeof( pAllOutBlock->outBlock1.CommdaCode        ), DATA_TYPE_STRING ) );    // ��Ÿ�ü�ڵ�        
			m_ctrlOutBlock1.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock1.MgntrnCode       , sizeof( pAllOutBlock->outBlock1.MgntrnCode        ), DATA_TYPE_STRING ) );    // �ſ�ŷ��ڵ�        
			m_ctrlOutBlock1.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock1.LoanDt           , sizeof( pAllOutBlock->outBlock1.LoanDt            ), DATA_TYPE_STRING ) );    // ������              
			m_ctrlOutBlock1.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock1.MbrNo            , sizeof( pAllOutBlock->outBlock1.MbrNo             ), DATA_TYPE_STRING ) );    // ȸ����ȣ            
			m_ctrlOutBlock1.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock1.OrdCndiTpCode    , sizeof( pAllOutBlock->outBlock1.OrdCndiTpCode     ), DATA_TYPE_STRING ) );    // �ֹ����Ǳ���        
			m_ctrlOutBlock1.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock1.StrtgCode        , sizeof( pAllOutBlock->outBlock1.StrtgCode         ), DATA_TYPE_STRING ) );    // �����ڵ�            
			m_ctrlOutBlock1.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock1.GrpId            , sizeof( pAllOutBlock->outBlock1.GrpId             ), DATA_TYPE_STRING ) );    // �׷�ID              
			m_ctrlOutBlock1.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock1.OrdSeqNo         , sizeof( pAllOutBlock->outBlock1.OrdSeqNo          ), DATA_TYPE_LONG   ) );    // �ֹ�ȸ��            
			m_ctrlOutBlock1.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock1.PtflNo           , sizeof( pAllOutBlock->outBlock1.PtflNo            ), DATA_TYPE_LONG   ) );    // ��Ʈ��������ȣ      
			m_ctrlOutBlock1.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock1.BskNo            , sizeof( pAllOutBlock->outBlock1.BskNo             ), DATA_TYPE_LONG   ) );    // �ٽ��Ϲ�ȣ          
			m_ctrlOutBlock1.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock1.TrchNo           , sizeof( pAllOutBlock->outBlock1.TrchNo            ), DATA_TYPE_LONG   ) );    // Ʈ��ġ��ȣ          
			m_ctrlOutBlock1.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock1.ItemNo           , sizeof( pAllOutBlock->outBlock1.ItemNo            ), DATA_TYPE_LONG   ) );    // �����۹�ȣ          
			m_ctrlOutBlock1.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock1.OpDrtnNo         , sizeof( pAllOutBlock->outBlock1.OpDrtnNo          ), DATA_TYPE_STRING ) );    // ������ù�ȣ        
			m_ctrlOutBlock1.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock1.LpYn             , sizeof( pAllOutBlock->outBlock1.LpYn              ), DATA_TYPE_STRING ) );    // �����������ڿ���    
			m_ctrlOutBlock1.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock1.CvrgTpCode       , sizeof( pAllOutBlock->outBlock1.CvrgTpCode        ), DATA_TYPE_STRING ) );    // �ݴ�Ÿű���        
		}

		if( pRpData->nDataLength >= sizeof( CSPAT00600OutBlock1 ) + sizeof( CSPAT00600OutBlock2 ) )
		{
			int nCol = 0;
			m_ctrlOutBlock2.InsertItem( 0, "" );
			m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock2.RecCnt     , sizeof( pAllOutBlock->outBlock2.RecCnt      ), DATA_TYPE_LONG   ) );    // ���ڵ尹��       
			m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock2.OrdNo      , sizeof( pAllOutBlock->outBlock2.OrdNo       ), DATA_TYPE_LONG   ) );    // �ֹ���ȣ         
			m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock2.OrdTime    , sizeof( pAllOutBlock->outBlock2.OrdTime     ), DATA_TYPE_STRING ) );    // �ֹ��ð�         
			m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock2.OrdMktCode , sizeof( pAllOutBlock->outBlock2.OrdMktCode  ), DATA_TYPE_STRING ) );    // �ֹ������ڵ�     
			m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock2.OrdPtnCode , sizeof( pAllOutBlock->outBlock2.OrdPtnCode  ), DATA_TYPE_STRING ) );    // �ֹ������ڵ�     
			m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock2.ShtnIsuNo  , sizeof( pAllOutBlock->outBlock2.ShtnIsuNo   ), DATA_TYPE_STRING ) );    // ���������ȣ     
			m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock2.MgempNo    , sizeof( pAllOutBlock->outBlock2.MgempNo     ), DATA_TYPE_STRING ) );    // ���������ȣ     
			m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock2.OrdAmt     , sizeof( pAllOutBlock->outBlock2.OrdAmt      ), DATA_TYPE_LONG   ) );    // �ֹ��ݾ�         
			m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock2.SpareOrdNo , sizeof( pAllOutBlock->outBlock2.SpareOrdNo  ), DATA_TYPE_LONG   ) );    // �����ֹ���ȣ     
			m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock2.CvrgSeqno  , sizeof( pAllOutBlock->outBlock2.CvrgSeqno   ), DATA_TYPE_LONG   ) );    // �ݴ�Ÿ��Ϸù�ȣ 
			m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock2.RsvOrdNo   , sizeof( pAllOutBlock->outBlock2.RsvOrdNo    ), DATA_TYPE_LONG   ) );    // �����ֹ���ȣ     
			m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock2.SpotOrdQty , sizeof( pAllOutBlock->outBlock2.SpotOrdQty  ), DATA_TYPE_LONG   ) );    // �ǹ��ֹ�����     
			m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock2.RuseOrdQty , sizeof( pAllOutBlock->outBlock2.RuseOrdQty  ), DATA_TYPE_LONG   ) );    // �����ֹ�����   
			m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock2.MnyOrdAmt  , sizeof( pAllOutBlock->outBlock2.MnyOrdAmt   ), DATA_TYPE_LONG   ) );    // �����ֹ��ݾ�     
			m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock2.SubstOrdAmt, sizeof( pAllOutBlock->outBlock2.SubstOrdAmt ), DATA_TYPE_LONG   ) );    // ����ֹ��ݾ�     
			m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock2.RuseOrdAmt , sizeof( pAllOutBlock->outBlock2.RuseOrdAmt  ), DATA_TYPE_LONG   ) );    // �����ֹ��ݾ�   
			m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock2.AcntNm     , sizeof( pAllOutBlock->outBlock2.AcntNm      ), DATA_TYPE_STRING ) );    // ���¸�           
			m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock2.IsuNm      , sizeof( pAllOutBlock->outBlock2.IsuNm       ), DATA_TYPE_STRING ) );    // �����           
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
LRESULT CDlg_CSPAT00600::OnXMTimeoutData( WPARAM wParam, LPARAM lParam )
{
	g_iXingAPI.ReleaseRequestData( (int)lParam );
	GetParent()->SendMessage( WMU_SET_MESSAGE, (WPARAM)"", (LPARAM)"Timeout" );		

	return 0L;
}
