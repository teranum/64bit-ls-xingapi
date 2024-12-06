// Dlg_t1305.cpp : implementation file
//

#include "stdafx.h"
#include "xingapi_sample.h"
#include "Dlg_t1305.h"

#include "./Packet/t1305.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlg_t1305 dialog


IMPLEMENT_DYNCREATE(CDlg_t1305, CDialog)

CDlg_t1305::CDlg_t1305(CWnd* pParent /*=NULL*/)
	: CDialog(CDlg_t1305::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlg_t1305)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CDlg_t1305::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlg_t1305)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlg_t1305, CDialog)
	//{{AFX_MSG_MAP(CDlg_t1305)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
	ON_BN_CLICKED( IDC_BUTTON_REQUEST,		  OnButtonRequest	  )
	ON_BN_CLICKED( IDC_BUTTON_REQUEST_NEXT,	  OnButtonRequestNext )
	ON_MESSAGE	 ( WM_USER + XM_RECEIVE_DATA, OnXMReceiveData	  )
	ON_MESSAGE	 ( WM_USER + XM_TIMEOUT_DATA, OnXMTimeoutData	  )
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlg_t1305 message handlers

BOOL CDlg_t1305::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	InitCtrls();
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CDlg_t1305::OnButtonRequest() 
{
	RequestData();
}

void CDlg_t1305::OnButtonRequestNext() 
{
	RequestData( TRUE );
}

//--------------------------------------------------------------------------------------
// ��Ʈ�� �ʱ�ȭ
//--------------------------------------------------------------------------------------
void CDlg_t1305::InitCtrls()
{
	//-----------------------------------------------------------
	// OutBlock
	InsertColumn4List( this, IDC_OUTBLOCK ,  0, "CNT           ", FALSE,  4 );    // [long  ,    4] CNT   
	InsertColumn4List( this, IDC_OUTBLOCK ,  1, "��¥          ", TRUE ,  8 );    // [string,    8] ��¥  
	InsertColumn4List( this, IDC_OUTBLOCK ,  2, "IDX           ", FALSE,  4 );    // [long  ,    4] IDX   
	
	//-----------------------------------------------------------
	// OutBlock1
	InsertColumn4List( this, IDC_OUTBLOCK1,  0, "��¥          ", TRUE ,  8 );    // [string,    8] ��¥          
	InsertColumn4List( this, IDC_OUTBLOCK1,  1, "�ð�          ", FALSE,  8 );    // [long  ,    8] �ð�          
	InsertColumn4List( this, IDC_OUTBLOCK1,  2, "��          ", FALSE,  8 );    // [long  ,    8] ��          
	InsertColumn4List( this, IDC_OUTBLOCK1,  3, "����          ", FALSE,  8 );    // [long  ,    8] ����          
	InsertColumn4List( this, IDC_OUTBLOCK1,  4, "����          ", FALSE,  8 );    // [long  ,    8] ����          
	InsertColumn4List( this, IDC_OUTBLOCK1,  5, "���ϴ�񱸺�  ", TRUE ,  1 );    // [string,    1] ���ϴ�񱸺�  
	InsertColumn4List( this, IDC_OUTBLOCK1,  6, "���ϴ��      ", FALSE,  8 );    // [long  ,    8] ���ϴ��      
	InsertColumn4List( this, IDC_OUTBLOCK1,  7, "�����        ", FALSE,  6 );    // [float ,  6.2] �����        
	InsertColumn4List( this, IDC_OUTBLOCK1,  8, "�����ŷ���    ", FALSE, 12 );    // [long  ,   12] �����ŷ���    
	InsertColumn4List( this, IDC_OUTBLOCK1,  9, "�ŷ�������    ", FALSE, 10 );    // [float , 10.2] �ŷ�������    
	InsertColumn4List( this, IDC_OUTBLOCK1, 10, "ü�ᰭ��      ", FALSE,  6 );    // [float ,  6.2] ü�ᰭ��      
	InsertColumn4List( this, IDC_OUTBLOCK1, 11, "������        ", FALSE,  6 );    // [float ,  6.2] ������        
	InsertColumn4List( this, IDC_OUTBLOCK1, 12, "ȸ����        ", FALSE,  6 );    // [float ,  6.2] ȸ����        
	InsertColumn4List( this, IDC_OUTBLOCK1, 13, "���μ��ż�    ", FALSE, 12 );    // [long  ,   12] ���μ��ż�    
	InsertColumn4List( this, IDC_OUTBLOCK1, 14, "������ż�    ", FALSE, 12 );    // [long  ,   12] ������ż�    
	InsertColumn4List( this, IDC_OUTBLOCK1, 15, "�����ڵ�      ", TRUE ,  6 );    // [string,    6] �����ڵ�      
	InsertColumn4List( this, IDC_OUTBLOCK1, 16, "�����ŷ����  ", FALSE, 12 );    // [long  ,   12] �����ŷ����  
	InsertColumn4List( this, IDC_OUTBLOCK1, 17, "���μ��ż�    ", FALSE, 12 );    // [long  ,   12] ���μ��ż�    
	InsertColumn4List( this, IDC_OUTBLOCK1, 18, "�ð���񱸺�  ", TRUE ,  1 );    // [string,    1] �ð���񱸺�  
	InsertColumn4List( this, IDC_OUTBLOCK1, 19, "�ð����      ", FALSE,  8 );    // [long  ,    8] �ð����      
	InsertColumn4List( this, IDC_OUTBLOCK1, 20, "�ð����ص����", FALSE,  6 );    // [float ,  6.2] �ð����ص����
	InsertColumn4List( this, IDC_OUTBLOCK1, 21, "����񱸺�  ", TRUE ,  1 );    // [string,    1] ����񱸺�  
	InsertColumn4List( this, IDC_OUTBLOCK1, 22, "�����      ", FALSE,  8 );    // [long  ,    8] �����      
	InsertColumn4List( this, IDC_OUTBLOCK1, 23, "�����ص����", FALSE,  6 );    // [float ,  6.2] �����ص����
	InsertColumn4List( this, IDC_OUTBLOCK1, 24, "������񱸺�  ", TRUE ,  1 );    // [string,    1] ������񱸺�  
	InsertColumn4List( this, IDC_OUTBLOCK1, 25, "�������      ", FALSE,  8 );    // [long  ,    8] �������      
	InsertColumn4List( this, IDC_OUTBLOCK1, 26, "�������ص����", FALSE,  6 );    // [float ,  6.2] �������ص����
}

//--------------------------------------------------------------------------------------
// ������ ��ȸ
//--------------------------------------------------------------------------------------
void CDlg_t1305::RequestData( BOOL bNext )
{
	//-----------------------------------------------------------
	// �Ⱓ���ְ�(t1305) ( attr,block,headtype=A )
	t1305InBlock	pckInBlock;

	TCHAR			szTrNo[]	= "t1305";

	//-----------------------------------------------------------
	// ������ �ʱ�ȭ
	FillMemory( &pckInBlock, sizeof( pckInBlock ), ' ' );
	
	//-----------------------------------------------------------
	// ������ �Է�
	SetPacketData( pckInBlock.shcode , sizeof( pckInBlock.shcode  ), this, IDC_INBLOCK_SHCODE , DATA_TYPE_STRING );	// �����ڵ�  
	SetPacketData( pckInBlock.dwmcode, sizeof( pckInBlock.dwmcode ), this, IDC_INBLOCK_DWMCODE, DATA_TYPE_STRING );	// ���ֿ�����
	SetPacketData( pckInBlock.date   , sizeof( pckInBlock.date    ), this, IDC_INBLOCK_DATE   , DATA_TYPE_STRING );	// ��¥      
	SetPacketData( pckInBlock.idx    , sizeof( pckInBlock.idx     ), this, IDC_INBLOCK_IDX    , DATA_TYPE_STRING );	// IDX       
	SetPacketData( pckInBlock.cnt    , sizeof( pckInBlock.cnt     ), this, IDC_INBLOCK_CNT    , DATA_TYPE_STRING );	// �Ǽ�      

	//-----------------------------------------------------------
	// ������ ����
	int nRqID = g_iXingAPI.Request( 
		GetSafeHwnd(),				// �����͸� ���� ������, XM_RECEIVE_DATA ���� �´�.
		szTrNo,						// TR ��ȣ
		&pckInBlock,				// InBlock ������
		sizeof( pckInBlock ),		// InBlock ������ ũ��
		bNext,						// ������ȸ ����
		"",							// ������ȸ Key
		30							// Timeout(��) : �ش� �ð�(��)���� �����Ͱ� ���� ������ Timeout�� �߻��Ѵ�. XM_TIMEOUT_DATA �޽����� �߻��Ѵ�.
	);
	
	((CListCtrl*)GetDlgItem( IDC_OUTBLOCK  ))->DeleteAllItems();
	((CListCtrl*)GetDlgItem( IDC_OUTBLOCK1 ))->DeleteAllItems();

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
LRESULT CDlg_t1305::OnXMReceiveData( WPARAM wParam, LPARAM lParam )
{
	//-------------------------------------------------------------------------------------
	// Data�� ����
	if( wParam == REQUEST_DATA )
	{
		LPRECV_PACKET pRpData = (LPRECV_PACKET)lParam;

		// Block Mode �̴�.
		if( strcmp( pRpData->szBlockName, NAME_t1305OutBlock ) == 0 )
		{
			CListCtrl*		pList	  = (CListCtrl*)GetDlgItem( IDC_OUTBLOCK );
			LPt1305OutBlock pOutBlock = (LPt1305OutBlock)pRpData->lpData;

			int nItem = pList->InsertItem( pList->GetItemCount(), "" );
			pList->SetItemText( nItem,  0, GetDispData( pOutBlock->cnt , sizeof( pOutBlock->cnt  ), DATA_TYPE_STRING ) );		// [long  ,    4] CNT   
			pList->SetItemText( nItem,  1, GetDispData( pOutBlock->date, sizeof( pOutBlock->date ), DATA_TYPE_STRING ) );		// [string,    8] ��¥  
			pList->SetItemText( nItem,  2, GetDispData( pOutBlock->idx , sizeof( pOutBlock->idx  ), DATA_TYPE_STRING ) );		// [long  ,    4] IDX   
		}
		else if( strcmp( pRpData->szBlockName, NAME_t1305OutBlock1 ) == 0 )
		{
			CListCtrl*		 pList	   = (CListCtrl*)GetDlgItem( IDC_OUTBLOCK1 );
			LPt1305OutBlock1 pOutBlock = (LPt1305OutBlock1)pRpData->lpData;
			int				 nCount	   = pRpData->nDataLength / sizeof( t1305OutBlock1 );		// Block Mode �ÿ� ��üũ�� / �ϳ��� Record ũ�� �� ������ ���Ѵ�.
			for( int i=0; i<nCount; i++ )
			{
				int nItem = pList->InsertItem( pList->GetItemCount(), "" );
				pList->SetItemText( nItem,  0, GetDispData( pOutBlock[i].date      , sizeof( pOutBlock[i].date       ), DATA_TYPE_STRING ) );		// [string,    8] ��¥          
				pList->SetItemText( nItem,  1, GetDispData( pOutBlock[i].open      , sizeof( pOutBlock[i].open       ), DATA_TYPE_STRING ) );		// [long  ,    8] �ð�          
				pList->SetItemText( nItem,  2, GetDispData( pOutBlock[i].high      , sizeof( pOutBlock[i].high       ), DATA_TYPE_STRING ) );		// [long  ,    8] ��          
				pList->SetItemText( nItem,  3, GetDispData( pOutBlock[i].low       , sizeof( pOutBlock[i].low        ), DATA_TYPE_STRING ) );		// [long  ,    8] ����          
				pList->SetItemText( nItem,  4, GetDispData( pOutBlock[i].close     , sizeof( pOutBlock[i].close      ), DATA_TYPE_STRING ) );		// [long  ,    8] ����          
				pList->SetItemText( nItem,  5, GetDispData( pOutBlock[i].sign      , sizeof( pOutBlock[i].sign       ), DATA_TYPE_STRING ) );		// [string,    1] ���ϴ�񱸺�  
				pList->SetItemText( nItem,  6, GetDispData( pOutBlock[i].change    , sizeof( pOutBlock[i].change     ), DATA_TYPE_STRING ) );		// [long  ,    8] ���ϴ��      
				pList->SetItemText( nItem,  7, GetDispData( pOutBlock[i].diff      , sizeof( pOutBlock[i].diff       ), DATA_TYPE_STRING ) );		// [float ,  6.2] �����        
				pList->SetItemText( nItem,  8, GetDispData( pOutBlock[i].volume    , sizeof( pOutBlock[i].volume     ), DATA_TYPE_STRING ) );		// [long  ,   12] �����ŷ���    
				pList->SetItemText( nItem,  9, GetDispData( pOutBlock[i].diff_vol  , sizeof( pOutBlock[i].diff_vol   ), DATA_TYPE_STRING ) );		// [float , 10.2] �ŷ�������    
				pList->SetItemText( nItem, 10, GetDispData( pOutBlock[i].chdegree  , sizeof( pOutBlock[i].chdegree   ), DATA_TYPE_FLOAT  ) );		// [float ,  6.2] ü�ᰭ��      
				pList->SetItemText( nItem, 11, GetDispData( pOutBlock[i].sojinrate , sizeof( pOutBlock[i].sojinrate  ), DATA_TYPE_LONG   ) );		// [float ,  6.2] ������        
				pList->SetItemText( nItem, 12, GetDispData( pOutBlock[i].changerate, sizeof( pOutBlock[i].changerate ), DATA_TYPE_LONG   ) );		// [float ,  6.2] ȸ����        
				pList->SetItemText( nItem, 13, GetDispData( pOutBlock[i].fpvolume  , sizeof( pOutBlock[i].fpvolume   ), DATA_TYPE_LONG   ) );		// [long  ,   12] ���μ��ż�    
				pList->SetItemText( nItem, 14, GetDispData( pOutBlock[i].covolume  , sizeof( pOutBlock[i].covolume   ), DATA_TYPE_LONG   ) );		// [long  ,   12] ������ż�    
				pList->SetItemText( nItem, 15, GetDispData( pOutBlock[i].shcode    , sizeof( pOutBlock[i].shcode     ), DATA_TYPE_STRING ) );		// [string,    6] �����ڵ�      
				pList->SetItemText( nItem, 16, GetDispData( pOutBlock[i].value     , sizeof( pOutBlock[i].value      ), DATA_TYPE_STRING ) );		// [long  ,   12] �����ŷ����  
				pList->SetItemText( nItem, 17, GetDispData( pOutBlock[i].ppvolume  , sizeof( pOutBlock[i].ppvolume   ), DATA_TYPE_STRING ) );		// [long  ,   12] ���μ��ż�    
				pList->SetItemText( nItem, 18, GetDispData( pOutBlock[i].o_sign    , sizeof( pOutBlock[i].o_sign     ), DATA_TYPE_STRING ) );		// [string,    1] �ð���񱸺�  
				pList->SetItemText( nItem, 19, GetDispData( pOutBlock[i].o_change  , sizeof( pOutBlock[i].o_change   ), DATA_TYPE_STRING ) );		// [long  ,    8] �ð����      
				pList->SetItemText( nItem, 20, GetDispData( pOutBlock[i].o_diff    , sizeof( pOutBlock[i].o_diff     ), DATA_TYPE_LONG   ) );		// [float ,  6.2] �ð����ص����
				pList->SetItemText( nItem, 21, GetDispData( pOutBlock[i].h_sign    , sizeof( pOutBlock[i].h_sign     ), DATA_TYPE_STRING ) );		// [string,    1] ����񱸺�  
				pList->SetItemText( nItem, 22, GetDispData( pOutBlock[i].h_change  , sizeof( pOutBlock[i].h_change   ), DATA_TYPE_STRING ) );		// [long  ,    8] �����      
				pList->SetItemText( nItem, 23, GetDispData( pOutBlock[i].h_diff    , sizeof( pOutBlock[i].h_diff     ), DATA_TYPE_STRING ) );		// [float ,  6.2] �����ص����
				pList->SetItemText( nItem, 24, GetDispData( pOutBlock[i].l_sign    , sizeof( pOutBlock[i].l_sign     ), DATA_TYPE_STRING ) );		// [string,    1] ������񱸺�  
				pList->SetItemText( nItem, 25, GetDispData( pOutBlock[i].l_change  , sizeof( pOutBlock[i].l_change   ), DATA_TYPE_FLOAT  ) );		// [long  ,    8] �������      
				pList->SetItemText( nItem, 26, GetDispData( pOutBlock[i].l_diff    , sizeof( pOutBlock[i].l_diff     ), DATA_TYPE_STRING ) );		// [float ,  6.2] �������ص����
			}
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
LRESULT CDlg_t1305::OnXMTimeoutData( WPARAM wParam, LPARAM lParam )
{
	g_iXingAPI.ReleaseRequestData( (int)lParam );

	return 0L;
}
