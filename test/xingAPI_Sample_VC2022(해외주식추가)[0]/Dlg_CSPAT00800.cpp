// Dlg_CSPAT00800.cpp : implementation file
//

#include "stdafx.h"
#include "xingapi_sample.h"
#include "Dlg_CSPAT00800.h"

#include "./Packet/CSPAT00800.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlg_CSPAT00800 dialog


IMPLEMENT_DYNCREATE(CDlg_CSPAT00800, CDialog)

CDlg_CSPAT00800::CDlg_CSPAT00800(CWnd* pParent /*=NULL*/)
	: CDialog(CDlg_CSPAT00800::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlg_CSPAT00800)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CDlg_CSPAT00800::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlg_CSPAT00800)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
	DDX_Control(pDX, IDC_OUTBLOCK1, m_ctrlOutBlock1);
	DDX_Control(pDX, IDC_OUTBLOCK2, m_ctrlOutBlock2);
}


BEGIN_MESSAGE_MAP(CDlg_CSPAT00800, CDialog)
	//{{AFX_MSG_MAP(CDlg_CSPAT00800)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
	ON_BN_CLICKED( IDC_BUTTON_REQUEST,		  OnButtonRequest	  )
	ON_MESSAGE	 ( WM_USER + XM_RECEIVE_DATA, OnXMReceiveData	  )
	ON_MESSAGE	 ( WM_USER + XM_TIMEOUT_DATA, OnXMTimeoutData	  )
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlg_CSPAT00800 message handlers

BOOL CDlg_CSPAT00800::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	InitCtrls();
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CDlg_CSPAT00800::OnButtonRequest() 
{
	RequestData();
}


//--------------------------------------------------------------------------------------
// ��Ʈ�� �ʱ�ȭ
//--------------------------------------------------------------------------------------
void CDlg_CSPAT00800::InitCtrls()
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

	//-------------------------------------------------------------------------
	// OutBlock1
	nCol = 0;
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "���ڵ尹��    ", FALSE,    5 );
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "���ֹ���ȣ    ", FALSE,   10 );
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "���¹�ȣ      ", TRUE ,   20 );
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "�Էº�й�ȣ  ", TRUE ,    8 );
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "�����ȣ      ", TRUE ,   12 );
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "�ֹ�����      ", FALSE,   16 );
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "��Ÿ�ü�ڵ�  ", TRUE ,    2 );
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "�׷�ID        ", TRUE ,   20 );
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "�����ڵ�      ", TRUE ,    6 );
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "�ֹ�ȸ��      ", FALSE,   10 );
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "��Ʈ��������ȣ", FALSE,   10 );
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "�ٽ��Ϲ�ȣ    ", FALSE,   10 );
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "�����۹�ȣ    ", FALSE,   10 );
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "Ʈ��ġ��ȣ    ", FALSE,   10 );

	//-------------------------------------------------------------------------
	// OutBlock2
	nCol = 0;
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "���ڵ尹��          ", FALSE,    5 );
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "�ֹ���ȣ            ", FALSE,   10 );
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "���ֹ���ȣ          ", FALSE,   10 );
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "�ֹ��ð�            ", TRUE ,    9 );
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "�ֹ������ڵ�        ", TRUE ,    2 );
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "�ֹ������ڵ�        ", TRUE ,    2 );
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "���������ȣ        ", TRUE ,    9 );
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "���α׷�ȣ�������ڵ�", TRUE ,    2 );
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "���ŵ�ȣ������      ", TRUE ,    1 );
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "���ŵ����ɿ���      ", TRUE ,    1 );
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "�ſ�ŷ��ڵ�        ", TRUE ,    3 );
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "������              ", TRUE ,    8 );
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "�ݴ�Ÿ��ֹ�����    ", TRUE ,    1 );
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "�����������ڿ���    ", TRUE ,    1 );
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "���������ȣ        ", TRUE ,    9 );
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "�Ÿű���            ", TRUE ,    1 );
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "�����ֹ���ȣ        ", FALSE,   10 );
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "�ݴ�Ÿ��Ϸù�ȣ    ", FALSE,   10 );
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "�����ֹ���ȣ        ", FALSE,   10 );
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "���¸�              ", TRUE ,   40 );
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "�����              ", TRUE ,   40 );
}

//--------------------------------------------------------------------------------------
// ������ ��ȸ
//--------------------------------------------------------------------------------------
void CDlg_CSPAT00800::RequestData( BOOL bNext )
{
	//-----------------------------------------------------------
// ���������ֹ�(CSPAT00800) ( base21=SONAT000,headtype=B )
	CSPAT00800InBlock1	pckInBlock;

	TCHAR			szTrNo[]		= "CSPAT00800";
	char			szNextKey[]		= "";

	//-----------------------------------------------------------
	// ������ ���
    CString strOrgOrdNo     ;		GetDlgItemText( IDC_INBLOCK_ORGORDNO     , strOrgOrdNo      );		// [long  ,   10] ���ֹ���ȣ                      StartPos 5, Length 10
    CString strAcntNo       ;		GetDlgItemText( IDC_INBLOCK_ACNTNO       , strAcntNo        );		// [string,   20] ���¹�ȣ                        StartPos 15, Length 20
    CString strInptPwd      ;		GetDlgItemText( IDC_INBLOCK_INPTPWD      , strInptPwd       );		// [string,    8] �Էº�й�ȣ                    StartPos 35, Length 8
    CString strIsuNo        ;		GetDlgItemText( IDC_INBLOCK_ISUNO        , strIsuNo         );		// [string,   12] �����ȣ                        StartPos 43, Length 12
    CString strOrdQty       ;		GetDlgItemText( IDC_INBLOCK_ORDQTY       , strOrdQty        );		// [long  ,   16] �ֹ�����                        StartPos 55, Length 16

	//-----------------------------------------------------------
	// ������ �ʱ�ȭ
	FillMemory( &pckInBlock, sizeof( pckInBlock ), ' ' );

	//-----------------------------------------------------------
	// ������ �Է�
	SetPacketData( pckInBlock.OrgOrdNo     , sizeof( pckInBlock.OrgOrdNo      ), strOrgOrdNo     , DATA_TYPE_LONG	);		// ���¹�ȣ                 
	SetPacketData( pckInBlock.AcntNo       , sizeof( pckInBlock.AcntNo        ), strAcntNo       , DATA_TYPE_STRING );		// ���¹�ȣ                 
	SetPacketData( pckInBlock.InptPwd      , sizeof( pckInBlock.InptPwd       ), strInptPwd      , DATA_TYPE_STRING );		// �Էº�й�ȣ             
	SetPacketData( pckInBlock.IsuNo        , sizeof( pckInBlock.IsuNo         ), strIsuNo        , DATA_TYPE_STRING );		// �����ȣ                 
	SetPacketData( pckInBlock.OrdQty       , sizeof( pckInBlock.OrdQty        ), strOrdQty       , DATA_TYPE_LONG   );		// �ֹ�����                 

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
LRESULT CDlg_CSPAT00800::OnXMReceiveData( WPARAM wParam, LPARAM lParam )
{
	//-------------------------------------------------------------------------------------
	// Data�� ����
	if( wParam == REQUEST_DATA )
	{
		LPRECV_PACKET pRpData = (LPRECV_PACKET)lParam;

		typedef struct
		{
			CSPAT00800OutBlock1	outBlock1;
			CSPAT00800OutBlock2	outBlock2;
		} CSPAT00800AllOutBlock, *LPCSPAT00800AllOutBlock;

		LPCSPAT00800AllOutBlock pAllOutBlock = (LPCSPAT00800AllOutBlock)pRpData->lpData;

		// ���� ������ ũ�Ⱑ Block ũ�⺸�� �۴ٸ� ó������ �ʴ´�.
		if( pRpData->nDataLength >= sizeof( CSPAT00800OutBlock1 ) )
		{
			int nCol = 0;
			m_ctrlOutBlock1.InsertItem( 0, "" );
			m_ctrlOutBlock1.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock1.RecCnt    , sizeof( pAllOutBlock->outBlock1.RecCnt     ), DATA_TYPE_LONG         ) );   // [long  ,    5] ���ڵ尹��                      StartPos 0, Length 5
			m_ctrlOutBlock1.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock1.OrgOrdNo  , sizeof( pAllOutBlock->outBlock1.OrgOrdNo   ), DATA_TYPE_LONG         ) );   // [long  ,   10] ���ֹ���ȣ                      StartPos 5, Length 10
			m_ctrlOutBlock1.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock1.AcntNo    , sizeof( pAllOutBlock->outBlock1.AcntNo     ), DATA_TYPE_STRING       ) );   // [string,   20] ���¹�ȣ                        StartPos 15, Length 20
			m_ctrlOutBlock1.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock1.InptPwd   , sizeof( pAllOutBlock->outBlock1.InptPwd    ), DATA_TYPE_STRING       ) );   // [string,    8] �Էº�й�ȣ                    StartPos 35, Length 8
			m_ctrlOutBlock1.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock1.IsuNo     , sizeof( pAllOutBlock->outBlock1.IsuNo      ), DATA_TYPE_STRING       ) );   // [string,   12] �����ȣ                        StartPos 43, Length 12
			m_ctrlOutBlock1.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock1.OrdQty    , sizeof( pAllOutBlock->outBlock1.OrdQty     ), DATA_TYPE_LONG         ) );	  // [long  ,   16] �ֹ�����                        StartPos 55, Length 16   
			m_ctrlOutBlock1.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock1.CommdaCode, sizeof( pAllOutBlock->outBlock1.CommdaCode ), DATA_TYPE_STRING       ) );   // [string,    2] ��Ÿ�ü�ڵ�                    StartPos 71, Length 2
			m_ctrlOutBlock1.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock1.GrpId     , sizeof( pAllOutBlock->outBlock1.GrpId      ), DATA_TYPE_STRING       ) );   // [string,   20] �׷�ID                          StartPos 73, Length 20
			m_ctrlOutBlock1.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock1.StrtgCode , sizeof( pAllOutBlock->outBlock1.StrtgCode  ), DATA_TYPE_STRING       ) );   // [string,    6] �����ڵ�                        StartPos 93, Length 6
			m_ctrlOutBlock1.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock1.OrdSeqNo  , sizeof( pAllOutBlock->outBlock1.OrdSeqNo   ), DATA_TYPE_LONG         ) );   // [long  ,   10] �ֹ�ȸ��                        StartPos 99, Length 10
			m_ctrlOutBlock1.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock1.PtflNo    , sizeof( pAllOutBlock->outBlock1.PtflNo     ), DATA_TYPE_LONG         ) );   // [long  ,   10] ��Ʈ��������ȣ                  StartPos 109, Length 10
			m_ctrlOutBlock1.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock1.BskNo     , sizeof( pAllOutBlock->outBlock1.BskNo      ), DATA_TYPE_LONG         ) );   // [long  ,   10] �ٽ��Ϲ�ȣ                      StartPos 119, Length 10
			m_ctrlOutBlock1.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock1.TrchNo    , sizeof( pAllOutBlock->outBlock1.TrchNo     ), DATA_TYPE_LONG         ) );   // [long  ,   10] Ʈ��ġ��ȣ                      StartPos 129, Length 10
			m_ctrlOutBlock1.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock1.ItemNo    , sizeof( pAllOutBlock->outBlock1.ItemNo     ), DATA_TYPE_LONG         ) );   // [long  ,   10] �����۹�ȣ                      StartPos 139, Length 10
		}

		if( pRpData->nDataLength >= sizeof( CSPAT00800OutBlock1 ) + sizeof( CSPAT00800OutBlock2 ) )
		{
			int nCol = 0;
			m_ctrlOutBlock2.InsertItem( 0, "" );
			m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock2.RecCnt           , sizeof( pAllOutBlock->outBlock2.RecCnt            ), DATA_TYPE_LONG   ) );    // [long  ,    5] ���ڵ尹��                      StartPos 0, Length 5
			m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock2.OrdNo            , sizeof( pAllOutBlock->outBlock2.OrdNo             ), DATA_TYPE_LONG   ) );    // [long  ,   10] �ֹ���ȣ                        StartPos 5, Length 10
			m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock2.PrntOrdNo        , sizeof( pAllOutBlock->outBlock2.PrntOrdNo         ), DATA_TYPE_LONG   ) );    // [long  ,   10] ���ֹ���ȣ                      StartPos 15, Length 10
			m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock2.OrdTime          , sizeof( pAllOutBlock->outBlock2.OrdTime           ), DATA_TYPE_STRING ) );    // [string,    9] �ֹ��ð�                        StartPos 25, Length 9
			m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock2.OrdMktCode       , sizeof( pAllOutBlock->outBlock2.OrdMktCode        ), DATA_TYPE_STRING ) );    // [string,    2] �ֹ������ڵ�                    StartPos 34, Length 2
			m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock2.OrdPtnCode       , sizeof( pAllOutBlock->outBlock2.OrdPtnCode        ), DATA_TYPE_STRING ) );    // [string,    2] �ֹ������ڵ�                    StartPos 36, Length 2
			m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock2.ShtnIsuNo        , sizeof( pAllOutBlock->outBlock2.ShtnIsuNo         ), DATA_TYPE_STRING ) );    // [string,    9] ���������ȣ                    StartPos 38, Length 9
			m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock2.PrgmOrdprcPtnCode, sizeof( pAllOutBlock->outBlock2.PrgmOrdprcPtnCode ), DATA_TYPE_STRING ) );    // [string,    2] ���α׷�ȣ�������ڵ�            StartPos 47, Length 2
			m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock2.StslOrdprcTpCode , sizeof( pAllOutBlock->outBlock2.StslOrdprcTpCode  ), DATA_TYPE_STRING ) );    // [string,    1] ���ŵ�ȣ������                  StartPos 49, Length 1
			m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock2.StslAbleYn       , sizeof( pAllOutBlock->outBlock2.StslAbleYn        ), DATA_TYPE_STRING ) );    // [string,    1] ���ŵ����ɿ���                  StartPos 50, Length 1
			m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock2.MgntrnCode       , sizeof( pAllOutBlock->outBlock2.MgntrnCode        ), DATA_TYPE_STRING ) );    // [string,    3] �ſ�ŷ��ڵ�                    StartPos 51, Length 3
			m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock2.LoanDt           , sizeof( pAllOutBlock->outBlock2.LoanDt            ), DATA_TYPE_STRING ) );    // [string,    8] ������                          StartPos 54, Length 8
			m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock2.CvrgOrdTp        , sizeof( pAllOutBlock->outBlock2.CvrgOrdTp         ), DATA_TYPE_STRING ) );    // [string,    1] �ݴ�Ÿ��ֹ�����                StartPos 62, Length 1
			m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock2.LpYn             , sizeof( pAllOutBlock->outBlock2.LpYn              ), DATA_TYPE_STRING ) );    // [string,    1] �����������ڿ���                StartPos 63, Length 1
			m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock2.MgempNo          , sizeof( pAllOutBlock->outBlock2.MgempNo           ), DATA_TYPE_STRING ) );    // [string,    9] ���������ȣ                    StartPos 64, Length 9
			m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock2.BnsTpCode        , sizeof( pAllOutBlock->outBlock2.BnsTpCode         ), DATA_TYPE_STRING ) );    // [string,    1] �Ÿű���                        StartPos 73, Length 1
			m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock2.SpareOrdNo       , sizeof( pAllOutBlock->outBlock2.SpareOrdNo        ), DATA_TYPE_LONG   ) );    // [long  ,   10] �����ֹ���ȣ                    StartPos 74, Length 10
			m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock2.CvrgSeqno        , sizeof( pAllOutBlock->outBlock2.CvrgSeqno         ), DATA_TYPE_LONG   ) );    // [long  ,   10] �ݴ�Ÿ��Ϸù�ȣ                StartPos 84, Length 10
			m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock2.RsvOrdNo         , sizeof( pAllOutBlock->outBlock2.RsvOrdNo          ), DATA_TYPE_LONG   ) );    // [long  ,   10] �����ֹ���ȣ                    StartPos 94, Length 10
			m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock2.AcntNm           , sizeof( pAllOutBlock->outBlock2.AcntNm            ), DATA_TYPE_STRING ) );    // [string,   40] ���¸�                          StartPos 104, Length 40
			m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock2.IsuNm            , sizeof( pAllOutBlock->outBlock2.IsuNm             ), DATA_TYPE_STRING ) );    // [string,   40] �����                          StartPos 144, Length 40
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
LRESULT CDlg_CSPAT00800::OnXMTimeoutData( WPARAM wParam, LPARAM lParam )
{
	g_iXingAPI.ReleaseRequestData( (int)lParam );
	GetParent()->SendMessage( WMU_SET_MESSAGE, (WPARAM)"", (LPARAM)"Timeout" );		

	return 0L;
}
