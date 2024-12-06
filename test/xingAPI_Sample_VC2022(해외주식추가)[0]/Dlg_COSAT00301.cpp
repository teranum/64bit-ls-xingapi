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
// ��Ʈ�� �ʱ�ȭ
//--------------------------------------------------------------------------------------
void CDlg_COSAT00301::InitCtrls()
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
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "���ڵ尹��         ",	FALSE,	10	);
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "�ֹ������ڵ�       ",	TRUE ,	12	);
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "���ֹ���ȣ         ",	FALSE,	10	);
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "���¹�ȣ           ",	TRUE ,  8	);
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "�Էº�й�ȣ       ",	TRUE ,  12	);
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "�ֹ������ڵ�       ",	TRUE ,  12	);
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "�����ȣ           ",	TRUE ,  8	);
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "�ֹ�����           ",	TRUE ,	8	);
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "�ؿ��ֹ���         ",	FALSE,	16	);
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "ȣ�������ڵ�       ",	TRUE ,  8	);
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "�����Ÿ�ü�ڵ�    ",	TRUE ,	8	);
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "�߰��α����ڵ�      ",	TRUE ,	8	);

	//-------------------------------------------------------------------------
	// OutBlock2
	nCol = 0;
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "���ڵ尹��      ",	FALSE,	10	);
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "�ֹ���ȣ        ",	FALSE,	8	);
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "���¸�         ",	TRUE ,	8	);
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "�����         ",	TRUE ,	20	);
}

//--------------------------------------------------------------------------------------
// ������ ��ȸ
//--------------------------------------------------------------------------------------
void CDlg_COSAT00301::RequestData( BOOL bNext )
{
	//-----------------------------------------------------------
// ���������ֹ�(COSAT00301) ( base21=SONAT000,headtype=B )
	COSAT00301InBlock1	pckInBlock;

	TCHAR			szTrNo[]		= "COSAT00301";
	char			szNextKey[]		= "";

	//-----------------------------------------------------------
	// ������ ���
    CString strOrdPtnCode   ;		GetDlgItemText( IDC_INBLOCK_ORDPTNCODE   , strOrdPtnCode    );		// �ֹ������ڵ�                   
	CString strOrgOrdNo     ;		GetDlgItemText( IDC_INBLOCK_ORGORDNO     , strOrgOrdNo      );		// ���ֹ���ȣ
    CString strAcntNo       ;		GetDlgItemText( IDC_INBLOCK_ACNTNO       , strAcntNo        );		// ���¹�ȣ                     
    CString strInptPwd      ;		GetDlgItemText( IDC_INBLOCK_PWD          , strInptPwd       );		// �Էº�й�ȣ                   
	CString strOrdMktCode   ;		GetDlgItemText( IDC_INBLOCK_ORDMKTCODE   , strOrdMktCode    );		// �ֹ������ڵ�
    CString strIsuNo        ;		GetDlgItemText( IDC_INBLOCK_ISUNO        , strIsuNo         );		// �����ȣ                   
    CString strOrdQty       ;		GetDlgItemText( IDC_INBLOCK_ORDQTY       , strOrdQty        );		// �ֹ�����                       
    CString strOrdPrc       ;		GetDlgItemText( IDC_INBLOCK_ORDPRC       , strOrdPrc        );		// �ؿ��ֹ���                      
    CString strOrdprcPtnCode;		GetDlgItemText( IDC_INBLOCK_ORDPRCPTNCODE, strOrdprcPtnCode );		// ȣ�������ڵ�                 
	CString strBrkTpCode	;		GetDlgItemText( IDC_INBLOCK_BRKTPCODE	 , strBrkTpCode		 );		// �߰��α����ڵ�   

	//-----------------------------------------------------------
	// ������ �ʱ�ȭ
	FillMemory( &pckInBlock, sizeof( pckInBlock ), ' ' );

	//-----------------------------------------------------------
	// ������ �Է�
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
LRESULT CDlg_COSAT00301::OnXMReceiveData( WPARAM wParam, LPARAM lParam )
{
	//-------------------------------------------------------------------------------------
	// Data�� ����
	if( wParam == REQUEST_DATA )
	{
		LPRECV_PACKET pRpData = (LPRECV_PACKET)lParam;

		typedef struct
		{
			COSAT00301OutBlock1	outBlock1;
			COSAT00301OutBlock2	outBlock2;
		} COSAT00301AllOutBlock, *LPCOSAT00301AllOutBlock;

		LPCOSAT00301AllOutBlock pAllOutBlock = (LPCOSAT00301AllOutBlock)pRpData->lpData;

		// ���� ������ ũ�Ⱑ Block ũ�⺸�� �۴ٸ� ó������ �ʴ´�.
		if( pRpData->nDataLength >= sizeof( COSAT00301OutBlock1 ) )
		{
			int nCol = 0;
			m_ctrlOutBlock1.InsertItem( 0, "" );
			m_ctrlOutBlock1.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock1.RecCnt            , sizeof( pAllOutBlock->outBlock1.RecCnt             ), DATA_TYPE_LONG   ) );    // ���ڵ尹��          
			m_ctrlOutBlock1.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock1.OrdPtnCode        , sizeof( pAllOutBlock->outBlock1.OrdPtnCode         ), DATA_TYPE_STRING ) );    // �ֹ������ڵ�            
			m_ctrlOutBlock1.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock1.OrgOrdNo          , sizeof( pAllOutBlock->outBlock1.OrgOrdNo           ), DATA_TYPE_LONG   ) );    // ���ֹ���ȣ        
			m_ctrlOutBlock1.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock1.AcntNo            , sizeof( pAllOutBlock->outBlock1.AcntNo             ), DATA_TYPE_STRING ) );    // ���¹�ȣ            
			m_ctrlOutBlock1.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock1.InptPwd           , sizeof( pAllOutBlock->outBlock1.InptPwd            ), DATA_TYPE_STRING ) );    // �Էº�й�ȣ            
			m_ctrlOutBlock1.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock1.OrdMktCode        , sizeof( pAllOutBlock->outBlock1.OrdMktCode         ), DATA_TYPE_STRING ) );    // �ֹ������ڵ�         
			m_ctrlOutBlock1.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock1.IsuNo             , sizeof( pAllOutBlock->outBlock1.IsuNo              ), DATA_TYPE_STRING ) );    // �����ȣ            
			m_ctrlOutBlock1.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock1.OrdQty            , sizeof( pAllOutBlock->outBlock1.OrdQty             ), DATA_TYPE_LONG   ) );    // �ֹ�����        
			m_ctrlOutBlock1.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock1.OvrsOrdPrc        , sizeof( pAllOutBlock->outBlock1.OvrsOrdPrc         ), DATA_TYPE_DOT, 7 ) );    // �ؿ��ֹ���
			m_ctrlOutBlock1.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock1.OrdprcPtnCode     , sizeof( pAllOutBlock->outBlock1.OrdprcPtnCode      ), DATA_TYPE_STRING ) );    // ȣ�������ڵ�      
			m_ctrlOutBlock1.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock1.RegCommdaCode     , sizeof( pAllOutBlock->outBlock1.RegCommdaCode      ), DATA_TYPE_STRING ) );    // �����Ÿ�ü�ڵ�      
			m_ctrlOutBlock1.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock1.BrkTpCode         , sizeof( pAllOutBlock->outBlock1.BrkTpCode          ), DATA_TYPE_STRING ) );    // �߰��α����ڵ�           
			
		}

		if( pRpData->nDataLength >= sizeof( COSAT00301OutBlock1 ) + sizeof( COSAT00301OutBlock2 ) )
		{
			int nCol = 0;
			m_ctrlOutBlock2.InsertItem( 0, "" );
			m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock2.RecCnt     , sizeof( pAllOutBlock->outBlock2.RecCnt      ), DATA_TYPE_LONG   ) );    // ���ڵ尹��       
			m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock2.OrdNo      , sizeof( pAllOutBlock->outBlock2.OrdNo       ), DATA_TYPE_LONG   ) );    // �ֹ���ȣ         
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
LRESULT CDlg_COSAT00301::OnXMTimeoutData( WPARAM wParam, LPARAM lParam )
{
	g_iXingAPI.ReleaseRequestData( (int)lParam );
	GetParent()->SendMessage( WMU_SET_MESSAGE, (WPARAM)"", (LPARAM)"Timeout" );		

	return 0L;
}
