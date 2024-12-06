// Dlg_CEXAT11100.cpp : implementation file
//

#include "stdafx.h"
#include "xingapi_sample.h"
#include "Dlg_CEXAT11100.h"

#include "./Packet/CEXAT11100.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlg_CEXAT11100 dialog


IMPLEMENT_DYNCREATE(CDlg_CEXAT11100, CDialog)

CDlg_CEXAT11100::CDlg_CEXAT11100(CWnd* pParent /*=NULL*/)
	: CDialog(CDlg_CEXAT11100::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlg_CEXAT11100)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CDlg_CEXAT11100::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlg_CEXAT11100)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
	DDX_Control(pDX, IDC_OUTBLOCK1, m_ctrlOutBlock1);
	DDX_Control(pDX, IDC_OUTBLOCK2, m_ctrlOutBlock2);
}


BEGIN_MESSAGE_MAP(CDlg_CEXAT11100, CDialog)
	//{{AFX_MSG_MAP(CDlg_CEXAT11100)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
	ON_BN_CLICKED( IDC_BUTTON_REQUEST,		  OnButtonRequest	  )
	ON_MESSAGE	 ( WM_USER + XM_RECEIVE_DATA, OnXMReceiveData	  )
	ON_MESSAGE	 ( WM_USER + XM_TIMEOUT_DATA, OnXMTimeoutData	  )
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlg_CEXAT11100 message handlers

BOOL CDlg_CEXAT11100::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	InitCtrls();
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CDlg_CEXAT11100::OnButtonRequest() 
{
	RequestData();
}

//--------------------------------------------------------------------------------------
// ��Ʈ�� �ʱ�ȭ
//--------------------------------------------------------------------------------------
void CDlg_CEXAT11100::InitCtrls()
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
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "���ڵ尹��            ", FALSE,    5 );    // [long  ,    5] ���ڵ尹��            
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "���¹�ȣ              ", TRUE ,   20 );    // [string,   20] ���¹�ȣ              
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "��й�ȣ              ", TRUE ,    8 );    // [string,    8] ��й�ȣ              
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "�����ɼ������ȣ      ", TRUE ,   12 );    // [string,   12] �����ɼ������ȣ      
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "�Ÿű���              ", TRUE ,    1 );    // [string,    1] �Ÿű���              
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "�������������Ǳ����ڵ�", TRUE ,    1 );    // [string,    1] �������������Ǳ����ڵ�
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "�ֹ�����              ", FALSE, 15.2 );    // [double, 15.2] �ֹ�����              
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "�ֹ�����              ", FALSE,   16 );    // [long  ,   16] �ֹ�����              
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "�ֹ����ǰ���          ", FALSE, 25.8 );    // [double, 25.8] �ֹ����ǰ���          
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "��Ÿ�ü�ڵ�          ", TRUE ,    2 );    // [string,    2] ��Ÿ�ü�ڵ�          

	//-------------------------------------------------------------------------
	// OutBlock2
	nCol = 0;
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "���ڵ尹��      ", FALSE,    5 );    // [long  ,    5] ���ڵ尹��             
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "�ֹ���ȣ        ", FALSE,   10 );    // [long  ,   10] �ֹ���ȣ               
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "������          ", TRUE ,   40 );    // [string,   40] ������                 
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "���¸�          ", TRUE ,   40 );    // [string,   40] ���¸�                 
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "�����          ", TRUE ,   50 );    // [string,   50] �����                 
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "�ֹ����ɱݾ�    ", FALSE,   16 );    // [long  ,   16] �ֹ����ɱݾ�           
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "�����ֹ����ɱݾ�", FALSE,   16 );    // [long  ,   16] �����ֹ����ɱݾ�       
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "�ֹ����ű�      ", FALSE,   16 );    // [long  ,   16] �ֹ����ű�             
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "�����ֹ����ű�  ", FALSE,   16 );    // [long  ,   16] �����ֹ����ű�         
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "�ֹ����ɼ���    ", FALSE,   16 );    // [long  ,   16] �ֹ����ɼ���           
}

//--------------------------------------------------------------------------------------
// ������ ��ȸ
//--------------------------------------------------------------------------------------
void CDlg_CEXAT11100::RequestData( BOOL bNext )
{
	CEXAT11100InBlock1	pckInBlock;

	TCHAR			szTrNo[]		= "CEXAT11100";
	char			szNextKey[]		= "";

	//-----------------------------------------------------------
	// ������ ���
    CString strAcntNo          ;	GetDlgItemText( IDC_INBLOCK_ACNTNO          , strAcntNo           );    // [string,   20] ���¹�ȣ                  
    CString strPwd             ;	GetDlgItemText( IDC_INBLOCK_PWD             , strPwd              );    // [string,    8] ��й�ȣ                  
    CString strFnoIsuNo        ;	GetDlgItemText( IDC_INBLOCK_FNOISUNO        , strFnoIsuNo         );    // [string,   12] �����ɼ������ȣ          
    CString strBnsTpCode       ;	GetDlgItemText( IDC_INBLOCK_BNSTPCODE       , strBnsTpCode        );    // [string,    1] �Ÿű���                  
    CString strErxPrcCndiTpCode;	GetDlgItemText( IDC_INBLOCK_ERXPRCCNDITPCODE, strErxPrcCndiTpCode );    // [string,    1] �������������Ǳ����ڵ�    
    CString strOrdPrc          ;	GetDlgItemText( IDC_INBLOCK_ORDPRC          , strOrdPrc           );    // [double, 15.2] �ֹ�����                  
    CString strOrdQty          ;	GetDlgItemText( IDC_INBLOCK_ORDQTY          , strOrdQty           );    // [long  ,   16] �ֹ�����                  

	//-----------------------------------------------------------
	// ������ �ʱ�ȭ
	FillMemory( &pckInBlock, sizeof( pckInBlock ), ' ' );

	//-----------------------------------------------------------
	// ������ �Է�
	SetPacketData( pckInBlock.AcntNo          , sizeof( pckInBlock.AcntNo           ), strAcntNo          , DATA_TYPE_STRING );    // [string,   20] ���¹�ȣ                   
	SetPacketData( pckInBlock.Pwd             , sizeof( pckInBlock.Pwd              ), strPwd             , DATA_TYPE_STRING );    // [string,    8] ��й�ȣ                   
	SetPacketData( pckInBlock.FnoIsuNo        , sizeof( pckInBlock.FnoIsuNo         ), strFnoIsuNo        , DATA_TYPE_STRING );    // [string,   12] �����ɼ������ȣ           
	SetPacketData( pckInBlock.BnsTpCode       , sizeof( pckInBlock.BnsTpCode        ), strBnsTpCode       , DATA_TYPE_STRING );    // [string,    1] �Ÿű���                   
	SetPacketData( pckInBlock.ErxPrcCndiTpCode, sizeof( pckInBlock.ErxPrcCndiTpCode ), strErxPrcCndiTpCode, DATA_TYPE_STRING );    // [string,    1] �������������Ǳ����ڵ�
	SetPacketData( pckInBlock.OrdPrc          , sizeof( pckInBlock.OrdPrc           ), strOrdPrc          , DATA_TYPE_DOT, 2 );    // [double, 15.2] �ֹ�����                   
	SetPacketData( pckInBlock.OrdQty          , sizeof( pckInBlock.OrdQty           ), strOrdQty          , DATA_TYPE_LONG   );    // [long  ,   16] �ֹ�����                   

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
		CString strMsg;
		strMsg.Format( "[%d] %s", nRqID, g_iXingAPI.GetErrorMessage( nRqID ) );
		MessageBox( strMsg, "��ȸ����", MB_ICONSTOP );
	}
}

//--------------------------------------------------------------------------------------
// �����͸� ����
//--------------------------------------------------------------------------------------
LRESULT CDlg_CEXAT11100::OnXMReceiveData( WPARAM wParam, LPARAM lParam )
{
	//-------------------------------------------------------------------------------------
	// Data�� ����
	if( wParam == REQUEST_DATA )
	{
		typedef struct
		{
			CEXAT11100OutBlock1	outBlock1;
			CEXAT11100OutBlock2	outBlock2;
		} CEXAT11100AllOutBlock, *LPCEXAT11100AllOutBlock;

		LPRECV_PACKET			pRpData		 = (LPRECV_PACKET)lParam;
		LPCEXAT11100AllOutBlock pAllOutBlock = (LPCEXAT11100AllOutBlock)pRpData->lpData;
		int						nDataLength  = pRpData->nDataLength;
		int						nCol;
		
		//------------------------------------------------
		// OutBlock1
		nDataLength -= sizeof( CEXAT11100OutBlock1 );
		if( nDataLength < 0 )
		{
			return 0L;
		}

		nCol = 0;
		m_ctrlOutBlock1.InsertItem( 0, "" );
		m_ctrlOutBlock1.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock1.RecCnt          , sizeof( pAllOutBlock->outBlock1.RecCnt            ), DATA_TYPE_LONG   ) );    // [long  ,    5] ���ڵ尹��            
		m_ctrlOutBlock1.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock1.AcntNo          , sizeof( pAllOutBlock->outBlock1.AcntNo            ), DATA_TYPE_STRING ) );    // [string,   20] ���¹�ȣ              
		m_ctrlOutBlock1.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock1.Pwd             , sizeof( pAllOutBlock->outBlock1.Pwd               ), DATA_TYPE_STRING ) );    // [string,    8] ��й�ȣ              
		m_ctrlOutBlock1.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock1.FnoIsuNo        , sizeof( pAllOutBlock->outBlock1.FnoIsuNo          ), DATA_TYPE_STRING ) );    // [string,   12] �����ɼ������ȣ      
		m_ctrlOutBlock1.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock1.BnsTpCode       , sizeof( pAllOutBlock->outBlock1.BnsTpCode         ), DATA_TYPE_STRING ) );    // [string,    1] �Ÿű���              
		m_ctrlOutBlock1.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock1.ErxPrcCndiTpCode, sizeof( pAllOutBlock->outBlock1.ErxPrcCndiTpCode  ), DATA_TYPE_STRING ) );    // [string,    1] �������������Ǳ����ڵ�  
		m_ctrlOutBlock1.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock1.OrdPrc          , sizeof( pAllOutBlock->outBlock1.OrdPrc            ), DATA_TYPE_DOT, 2 ) );    // [double, 15.2] �ֹ�����              
		m_ctrlOutBlock1.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock1.OrdQty          , sizeof( pAllOutBlock->outBlock1.OrdQty            ), DATA_TYPE_LONG   ) );    // [long  ,   16] �ֹ�����              
		m_ctrlOutBlock1.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock1.OrdCndiPrc      , sizeof( pAllOutBlock->outBlock1.OrdCndiPrc        ), DATA_TYPE_DOT, 8 ) );    // [double, 25.8] �ֹ����ǰ���          
		m_ctrlOutBlock1.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock1.CommdaCode      , sizeof( pAllOutBlock->outBlock1.CommdaCode        ), DATA_TYPE_STRING ) );    // [string,    2] ��Ÿ�ü�ڵ�          

		//------------------------------------------------
		// OutBlock1
		nDataLength -= sizeof( CEXAT11100OutBlock2 );
		if( nDataLength < 0 )
		{
			return 0L;
		}
		
		nCol = 0;
		m_ctrlOutBlock2.InsertItem( 0, "" );
		m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock2.RecCnt       , sizeof( pAllOutBlock->outBlock2.RecCnt        ), DATA_TYPE_LONG   ) );    // [long  ,    5] ���ڵ尹��      
		m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock2.OrdNo        , sizeof( pAllOutBlock->outBlock2.OrdNo         ), DATA_TYPE_LONG   ) );    // [long  ,   10] �ֹ���ȣ        
		m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock2.BrnNm        , sizeof( pAllOutBlock->outBlock2.BrnNm         ), DATA_TYPE_STRING ) );    // [string,   40] ������          
		m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock2.AcntNm       , sizeof( pAllOutBlock->outBlock2.AcntNm        ), DATA_TYPE_STRING ) );    // [string,   40] ���¸�          
		m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock2.IsuNm        , sizeof( pAllOutBlock->outBlock2.IsuNm         ), DATA_TYPE_STRING ) );    // [string,   50] �����          
		m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock2.OrdAbleAmt   , sizeof( pAllOutBlock->outBlock2.OrdAbleAmt    ), DATA_TYPE_LONG   ) );    // [long  ,   16] �ֹ����ɱݾ�    
		m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock2.MnyOrdAbleAmt, sizeof( pAllOutBlock->outBlock2.MnyOrdAbleAmt ), DATA_TYPE_LONG   ) );    // [long  ,   16] �����ֹ����ɱݾ�
		m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock2.OrdMgn       , sizeof( pAllOutBlock->outBlock2.OrdMgn        ), DATA_TYPE_LONG   ) );    // [long  ,   16] �ֹ����ű�      
		m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock2.MnyOrdMgn    , sizeof( pAllOutBlock->outBlock2.MnyOrdMgn     ), DATA_TYPE_LONG   ) );    // [long  ,   16] �����ֹ����ű�  
		m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock2.OrdAbleQty   , sizeof( pAllOutBlock->outBlock2.OrdAbleQty    ), DATA_TYPE_LONG   ) );    // [long  ,   16] �ֹ����ɼ���    
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
LRESULT CDlg_CEXAT11100::OnXMTimeoutData( WPARAM wParam, LPARAM lParam )
{
	g_iXingAPI.ReleaseRequestData( (int)lParam );
	GetParent()->SendMessage( WMU_SET_MESSAGE, (WPARAM)"", (LPARAM)"Timeout" );		

	return 0L;
}
