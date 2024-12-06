// Dlg_CFOAT00300.cpp : implementation file
//

#include "stdafx.h"
#include "xingapi_sample.h"
#include "Dlg_CFOAT00300.h"

#include "./Packet/CFOAT00300.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlg_CFOAT00300 dialog


IMPLEMENT_DYNCREATE(CDlg_CFOAT00300, CDialog)

CDlg_CFOAT00300::CDlg_CFOAT00300(CWnd* pParent /*=NULL*/)
	: CDialog(CDlg_CFOAT00300::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlg_CFOAT00300)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CDlg_CFOAT00300::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlg_CFOAT00300)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
	DDX_Control(pDX, IDC_OUTBLOCK1, m_ctrlOutBlock1);
	DDX_Control(pDX, IDC_OUTBLOCK2, m_ctrlOutBlock2);
}


BEGIN_MESSAGE_MAP(CDlg_CFOAT00300, CDialog)
	//{{AFX_MSG_MAP(CDlg_CFOAT00300)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
	ON_BN_CLICKED( IDC_BUTTON_REQUEST,		  OnButtonRequest	  )
	ON_MESSAGE	 ( WM_USER + XM_RECEIVE_DATA, OnXMReceiveData	  )
	ON_MESSAGE	 ( WM_USER + XM_TIMEOUT_DATA, OnXMTimeoutData	  )
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlg_CFOAT00300 message handlers

BOOL CDlg_CFOAT00300::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	InitCtrls();
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CDlg_CFOAT00300::OnButtonRequest() 
{
	RequestData();
}

//--------------------------------------------------------------------------------------
// ��Ʈ�� �ʱ�ȭ
//--------------------------------------------------------------------------------------
void CDlg_CFOAT00300::InitCtrls()
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
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "���ڵ尹��          ", FALSE,    5 );    // [long  ,    5] ���ڵ尹��          
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "�ֹ������ڵ�        ", TRUE ,    2 );    // [string,    2] �ֹ������ڵ�        
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "���¹�ȣ            ", TRUE ,   20 );    // [string,   20] ���¹�ȣ            
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "��й�ȣ            ", TRUE ,    8 );    // [string,    8] ��й�ȣ            
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "�����ɼ������ȣ    ", TRUE ,   12 );    // [string,   12] �����ɼ������ȣ    
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "�����ɼ��ֹ������ڵ�", TRUE ,    2 );    // [string,    2] �����ɼ��ֹ������ڵ�
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "���ֹ���ȣ          ", FALSE,   10 );    // [long  ,   10] ���ֹ���ȣ          
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "��Ҽ���            ", FALSE,   16 );    // [long  ,   16] ��Ҽ���            
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "��Ÿ�ü�ڵ�        ", TRUE ,    2 );    // [string,    2] ��Ÿ�ü�ڵ�        
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "���ǸŸſϷ�ð�    ", TRUE ,    9 );    // [string,    9] ���ǸŸſϷ�ð�    
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "�׷�ID              ", TRUE ,   20 );    // [string,   20] �׷�ID              
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "�ֹ��Ϸù�ȣ        ", FALSE,   10 );    // [long  ,   10] �ֹ��Ϸù�ȣ        
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "��Ʈ��������ȣ      ", FALSE,   10 );    // [long  ,   10] ��Ʈ��������ȣ      
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "�ٽ��Ϲ�ȣ          ", FALSE,   10 );    // [long  ,   10] �ٽ��Ϲ�ȣ          
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "Ʈ��ġ��ȣ          ", FALSE,   10 );    // [long  ,   10] Ʈ��ġ��ȣ          
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "�����۹�ȣ          ", FALSE,   10 );    // [long  ,   10] �����۹�ȣ          
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "���������ȣ        ", TRUE ,    9 );    // [string,    9] ���������ȣ        
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "�ݵ�ID              ", TRUE ,   12 );    // [string,   12] �ݵ�ID              
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "�ݵ���ֹ���ȣ      ", FALSE,   10 );    // [long  ,   10] �ݵ���ֹ���ȣ      
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "�ݵ��ֹ���ȣ        ", FALSE,   10 );    // [long  ,   10] �ݵ��ֹ���ȣ        

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
void CDlg_CFOAT00300::RequestData( BOOL bNext )
{
	//-----------------------------------------------------------
// ���������ֹ�(CFOAT00300) ( base21=SONAT000,headtype=B )
	CFOAT00300InBlock1	pckInBlock;

	TCHAR			szTrNo[]		= "CFOAT00300";
	char			szNextKey[]		= "";

	//-----------------------------------------------------------
	// ������ ���
    CString strAcntNo  ;	GetDlgItemText( IDC_INBLOCK_ACNTNO  , strAcntNo   );    
    CString strPwd     ;	GetDlgItemText( IDC_INBLOCK_PWD     , strPwd      );    
    CString strFnoIsuNo;	GetDlgItemText( IDC_INBLOCK_FNOISUNO, strFnoIsuNo );    
    CString strOrgOrdNo;	GetDlgItemText( IDC_INBLOCK_ORGORDNO, strOrgOrdNo );    
    CString strCancQty ;	GetDlgItemText( IDC_INBLOCK_CANCQTY , strCancQty  );    

	//-----------------------------------------------------------
	// ������ �ʱ�ȭ
	FillMemory( &pckInBlock, sizeof( pckInBlock ), ' ' );

	//-----------------------------------------------------------
	// ������ �Է�
	SetPacketData( pckInBlock.AcntNo          , sizeof( pckInBlock.AcntNo           ), strAcntNo          , DATA_TYPE_STRING );    // [string,   20] ���¹�ȣ            
	SetPacketData( pckInBlock.Pwd             , sizeof( pckInBlock.Pwd              ), strPwd             , DATA_TYPE_STRING );    // [string,    8] ��й�ȣ            
	SetPacketData( pckInBlock.FnoIsuNo        , sizeof( pckInBlock.FnoIsuNo         ), strFnoIsuNo        , DATA_TYPE_STRING );    // [string,   12] �����ɼ������ȣ    
	SetPacketData( pckInBlock.OrgOrdNo        , sizeof( pckInBlock.OrgOrdNo         ), strOrgOrdNo        , DATA_TYPE_LONG   );    // [long  ,   10] ���ֹ���ȣ          
	SetPacketData( pckInBlock.CancQty         , sizeof( pckInBlock.CancQty          ), strCancQty         , DATA_TYPE_LONG   );    // [long  ,   16] ��Ҽ���            

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
LRESULT CDlg_CFOAT00300::OnXMReceiveData( WPARAM wParam, LPARAM lParam )
{
	//-------------------------------------------------------------------------------------
	// Data�� ����
	if( wParam == REQUEST_DATA )
	{
		typedef struct
		{
			CFOAT00300OutBlock1	outBlock1;
			CFOAT00300OutBlock2	outBlock2;
		} CFOAT00300AllOutBlock, *LPCFOAT00300AllOutBlock;
		
		LPRECV_PACKET			pRpData		 = (LPRECV_PACKET)lParam;
		LPCFOAT00300AllOutBlock pAllOutBlock = (LPCFOAT00300AllOutBlock)pRpData->lpData;
		int						nDataLength  = pRpData->nDataLength;
		int						nCol;
		
		//------------------------------------------------
		// OutBlock1
		nDataLength -= sizeof( CFOAT00300OutBlock1 );
		if( nDataLength < 0 )
		{
			return 0L;
		}
		
		nCol = 0;
		m_ctrlOutBlock1.InsertItem( 0, "" );
		m_ctrlOutBlock1.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock1.RecCnt           , sizeof( pAllOutBlock->outBlock1.RecCnt            ), DATA_TYPE_LONG   ) );    // [long  ,    5] ���ڵ尹��          
		m_ctrlOutBlock1.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock1.OrdMktCode       , sizeof( pAllOutBlock->outBlock1.OrdMktCode        ), DATA_TYPE_STRING ) );    // [string,    2] �ֹ������ڵ�        
		m_ctrlOutBlock1.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock1.AcntNo           , sizeof( pAllOutBlock->outBlock1.AcntNo            ), DATA_TYPE_STRING ) );    // [string,   20] ���¹�ȣ            
		m_ctrlOutBlock1.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock1.Pwd              , sizeof( pAllOutBlock->outBlock1.Pwd               ), DATA_TYPE_STRING ) );    // [string,    8] ��й�ȣ            
		m_ctrlOutBlock1.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock1.FnoIsuNo         , sizeof( pAllOutBlock->outBlock1.FnoIsuNo          ), DATA_TYPE_STRING ) );    // [string,   12] �����ɼ������ȣ    
		m_ctrlOutBlock1.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock1.FnoOrdPtnCode    , sizeof( pAllOutBlock->outBlock1.FnoOrdPtnCode     ), DATA_TYPE_STRING ) );    // [string,    2] �����ɼ��ֹ������ڵ�  
		m_ctrlOutBlock1.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock1.OrgOrdNo         , sizeof( pAllOutBlock->outBlock1.OrgOrdNo          ), DATA_TYPE_LONG   ) );    // [long  ,   10] ���ֹ���ȣ          
		m_ctrlOutBlock1.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock1.CancQty          , sizeof( pAllOutBlock->outBlock1.CancQty           ), DATA_TYPE_LONG   ) );    // [long  ,   16] ��Ҽ���            
		m_ctrlOutBlock1.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock1.CommdaCode       , sizeof( pAllOutBlock->outBlock1.CommdaCode        ), DATA_TYPE_STRING ) );    // [string,    2] ��Ÿ�ü�ڵ�        
		m_ctrlOutBlock1.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock1.DscusBnsCmpltTime, sizeof( pAllOutBlock->outBlock1.DscusBnsCmpltTime ), DATA_TYPE_STRING ) );    // [string,    9] ���ǸŸſϷ�ð�    
		m_ctrlOutBlock1.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock1.GrpId            , sizeof( pAllOutBlock->outBlock1.GrpId             ), DATA_TYPE_STRING ) );    // [string,   20] �׷�ID              
		m_ctrlOutBlock1.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock1.OrdSeqno         , sizeof( pAllOutBlock->outBlock1.OrdSeqno          ), DATA_TYPE_LONG   ) );    // [long  ,   10] �ֹ��Ϸù�ȣ        
		m_ctrlOutBlock1.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock1.PtflNo           , sizeof( pAllOutBlock->outBlock1.PtflNo            ), DATA_TYPE_LONG   ) );    // [long  ,   10] ��Ʈ��������ȣ      
		m_ctrlOutBlock1.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock1.BskNo            , sizeof( pAllOutBlock->outBlock1.BskNo             ), DATA_TYPE_LONG   ) );    // [long  ,   10] �ٽ��Ϲ�ȣ          
		m_ctrlOutBlock1.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock1.TrchNo           , sizeof( pAllOutBlock->outBlock1.TrchNo            ), DATA_TYPE_LONG   ) );    // [long  ,   10] Ʈ��ġ��ȣ          
		m_ctrlOutBlock1.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock1.ItemNo           , sizeof( pAllOutBlock->outBlock1.ItemNo            ), DATA_TYPE_LONG   ) );    // [long  ,   10] �����۹�ȣ          
		m_ctrlOutBlock1.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock1.MgempNo          , sizeof( pAllOutBlock->outBlock1.MgempNo           ), DATA_TYPE_STRING ) );    // [string,    9] ���������ȣ        
		m_ctrlOutBlock1.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock1.FundId           , sizeof( pAllOutBlock->outBlock1.FundId            ), DATA_TYPE_STRING ) );    // [string,   12] �ݵ�ID              
		m_ctrlOutBlock1.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock1.FundOrgOrdNo     , sizeof( pAllOutBlock->outBlock1.FundOrgOrdNo      ), DATA_TYPE_LONG   ) );    // [long  ,   10] �ݵ���ֹ���ȣ      
		m_ctrlOutBlock1.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock1.FundOrdNo        , sizeof( pAllOutBlock->outBlock1.FundOrdNo         ), DATA_TYPE_LONG   ) );    // [long  ,   10] �ݵ��ֹ���ȣ        
		
		//------------------------------------------------
		// OutBlock1
		nDataLength -= sizeof( CFOAT00300OutBlock2 );
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
LRESULT CDlg_CFOAT00300::OnXMTimeoutData( WPARAM wParam, LPARAM lParam )
{
	g_iXingAPI.ReleaseRequestData( (int)lParam );
	GetParent()->SendMessage( WMU_SET_MESSAGE, (WPARAM)"", (LPARAM)"Timeout" );		

	return 0L;
}
