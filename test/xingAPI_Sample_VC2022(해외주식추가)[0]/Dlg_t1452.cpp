// Dlg_t1452.cpp : implementation file
//

#include "stdafx.h"
#include "xingapi_sample.h"
#include "Dlg_t1452.h"

#include "./Packet/t1452.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlg_t1452 dialog

IMPLEMENT_DYNCREATE(CDlg_t1452, CDialog)

CDlg_t1452::CDlg_t1452(CWnd* pParent /*=NULL*/)
	: CDialog(CDlg_t1452::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlg_t1452)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CDlg_t1452::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlg_t1452)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlg_t1452, CDialog)
	//{{AFX_MSG_MAP(CDlg_t1452)
	ON_BN_CLICKED(IDC_BUTTON_EXCLUDE_ITEM, OnButtonExcludeItem)
	//}}AFX_MSG_MAP
	ON_BN_CLICKED( IDC_BUTTON_REQUEST,		  OnButtonRequest	  )
	ON_BN_CLICKED( IDC_BUTTON_REQUEST_NEXT,	  OnButtonRequestNext )
	ON_MESSAGE	 ( WM_USER + XM_RECEIVE_DATA, OnXMReceiveData	  )
	ON_MESSAGE	 ( WM_USER + XM_TIMEOUT_DATA, OnXMTimeoutData	  )
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlg_t1452 message handlers

BOOL CDlg_t1452::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	InitCtrls();
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CDlg_t1452::OnButtonRequest() 
{
	RequestData();
}

void CDlg_t1452::OnButtonRequestNext() 
{
	RequestData( TRUE );
}

//--------------------------------------------------------------------------------------
// ��Ʈ�� �ʱ�ȭ
//--------------------------------------------------------------------------------------
void CDlg_t1452::InitCtrls()
{
	//-----------------------------------------------------------
	// OutBlock
	InsertColumn4List( this, IDC_OUTBLOCK ,  0, "IDX           ", FALSE,  4 );    // [long  ,    4] CNT   
	
	//-----------------------------------------------------------
	// OutBlock1
	InsertColumn4List( this, IDC_OUTBLOCK1,  0, "�����      ", TRUE , 20 );    // [string,   20] �����      
	InsertColumn4List( this, IDC_OUTBLOCK1,  1, "���簡      ", FALSE,  8 );    // [long  ,    8] ���簡      
	InsertColumn4List( this, IDC_OUTBLOCK1,  2, "���ϴ�񱸺�", FALSE,  1 );    // [string,    1] ���ϴ�񱸺�
	InsertColumn4List( this, IDC_OUTBLOCK1,  3, "���ϴ��    ", FALSE,  8 );    // [long  ,    8] ���ϴ��    
	InsertColumn4List( this, IDC_OUTBLOCK1,  4, "�����      ", FALSE,  6 );    // [float ,  6.2] �����      
	InsertColumn4List( this, IDC_OUTBLOCK1,  5, "�����ŷ���  ", TRUE , 12 );    // [long  ,   12] �����ŷ���  
	InsertColumn4List( this, IDC_OUTBLOCK1,  6, "ȸ����      ", FALSE,  6 );    // [float ,  6.2] ȸ����      
	InsertColumn4List( this, IDC_OUTBLOCK1,  7, "���ϰŷ���  ", FALSE, 12 );    // [long  ,   12] ���ϰŷ���  
	InsertColumn4List( this, IDC_OUTBLOCK1,  8, "���Ϻ�      ", FALSE, 10 );    // [float , 10.2] ���Ϻ�      
	InsertColumn4List( this, IDC_OUTBLOCK1,  9, "�����ڵ�    ", FALSE,  6 );    // [string,    6] �����ڵ�    
}

//--------------------------------------------------------------------------------------
// ������ ��ȸ
//--------------------------------------------------------------------------------------
void CDlg_t1452::RequestData( BOOL bNext )
{
	//-----------------------------------------------------------
	// �Ⱓ���ְ�(t1452) ( attr,block,headtype=A )
	t1452InBlock	pckInBlock;

	TCHAR			szTrNo[]	= "t1452";

	//-----------------------------------------------------------
	// ������ �ʱ�ȭ
	FillMemory( &pckInBlock, sizeof( pckInBlock ), ' ' );
	
	//-----------------------------------------------------------
	// ������ �Է�
	SetPacketData( pckInBlock.gubun    , sizeof( pckInBlock.gubun     ), this, IDC_INBLOCK_GUBUN    , DATA_TYPE_STRING );	// [string,    1] ����      
	SetPacketData( pckInBlock.jnilgubun, sizeof( pckInBlock.jnilgubun ), this, IDC_INBLOCK_JNILGUBUN, DATA_TYPE_STRING );	// [string,    1] ���ϱ���  
	SetPacketData( pckInBlock.sdiff    , sizeof( pckInBlock.sdiff     ), this, IDC_INBLOCK_SDIFF    , DATA_TYPE_LONG   );	// [long  ,    3] ���۵����
	SetPacketData( pckInBlock.ediff    , sizeof( pckInBlock.ediff     ), this, IDC_INBLOCK_EDIFF    , DATA_TYPE_LONG   );	// [long  ,    3] ��������
	SetPacketData( pckInBlock.jc_num   , sizeof( pckInBlock.jc_num    ), this, IDC_INBLOCK_JC_NUM   , DATA_TYPE_LONG   );	// [long  ,   12] �������  
	SetPacketData( pckInBlock.sprice   , sizeof( pckInBlock.sprice    ), this, IDC_INBLOCK_SPRICE   , DATA_TYPE_LONG   );	// [long  ,    8] ���۰���  
	SetPacketData( pckInBlock.eprice   , sizeof( pckInBlock.eprice    ), this, IDC_INBLOCK_EPRICE   , DATA_TYPE_LONG   );	// [long  ,    8] ���ᰡ��  
	SetPacketData( pckInBlock.volume   , sizeof( pckInBlock.volume    ), this, IDC_INBLOCK_VOLUME   , DATA_TYPE_LONG   );	// [long  ,   12] �ŷ���    
	SetPacketData( pckInBlock.idx      , sizeof( pckInBlock.idx       ), this, IDC_INBLOCK_IDX      , DATA_TYPE_LONG   );	// [long  ,    4] IDX       

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
LRESULT CDlg_t1452::OnXMReceiveData( WPARAM wParam, LPARAM lParam )
{
	//-------------------------------------------------------------------------------------
	// Data�� ����
	if( wParam == REQUEST_DATA )
	{
		LPRECV_PACKET pRpData = (LPRECV_PACKET)lParam;

		// Block Mode �̴�.
		if( strcmp( pRpData->szBlockName, NAME_t1452OutBlock ) == 0 )
		{
			CListCtrl*		pList	  = (CListCtrl*)GetDlgItem( IDC_OUTBLOCK );
			LPt1452OutBlock pOutBlock = (LPt1452OutBlock)pRpData->lpData;

			int nItem = pList->InsertItem( pList->GetItemCount(), "" );
			pList->SetItemText( nItem,  0, GetDispData( pOutBlock->idx , sizeof( pOutBlock->idx  ), DATA_TYPE_STRING ) );		// [long  ,    4] IDX   
		}
		else if( strcmp( pRpData->szBlockName, NAME_t1452OutBlock1 ) == 0 )
		{
			CListCtrl*		 pList	   = (CListCtrl*)GetDlgItem( IDC_OUTBLOCK1 );
			LPt1452OutBlock1 pOutBlock = (LPt1452OutBlock1)pRpData->lpData;
			int				 nCount	   = pRpData->nDataLength / sizeof( t1452OutBlock1 );		// Block Mode �ÿ� ��üũ�� / �ϳ��� Record ũ�� �� ������ ���Ѵ�.
			for( int i=0; i<nCount; i++ )
			{
				int nItem = pList->InsertItem( pList->GetItemCount(), "" );
				pList->SetItemText( nItem,  0, GetDispData( pOutBlock[i].hname     , sizeof( pOutBlock[i].hname      ), DATA_TYPE_STRING    ) );		// [string,   20] �����      
				pList->SetItemText( nItem,  1, GetDispData( pOutBlock[i].price     , sizeof( pOutBlock[i].price      ), DATA_TYPE_LONG      ) );		// [long  ,    8] ���簡      
				pList->SetItemText( nItem,  2, GetDispData( pOutBlock[i].sign      , sizeof( pOutBlock[i].sign       ), DATA_TYPE_STRING    ) );		// [string,    1] ���ϴ�񱸺�
				pList->SetItemText( nItem,  3, GetDispData( pOutBlock[i].change    , sizeof( pOutBlock[i].change     ), DATA_TYPE_LONG      ) );		// [long  ,    8] ���ϴ��    
				pList->SetItemText( nItem,  4, GetDispData( pOutBlock[i].diff      , sizeof( pOutBlock[i].diff       ), DATA_TYPE_DOUBLE, 2 ) );		// [float ,  6.2] �����      
				pList->SetItemText( nItem,  5, GetDispData( pOutBlock[i].volume    , sizeof( pOutBlock[i].volume     ), DATA_TYPE_LONG      ) );		// [long  ,   12] �����ŷ���  
				pList->SetItemText( nItem,  6, GetDispData( pOutBlock[i].vol       , sizeof( pOutBlock[i].vol        ), DATA_TYPE_DOUBLE, 2 ) );		// [float ,  6.2] ȸ����      
				pList->SetItemText( nItem,  7, GetDispData( pOutBlock[i].jnilvolume, sizeof( pOutBlock[i].jnilvolume ), DATA_TYPE_LONG      ) );		// [long  ,   12] ���ϰŷ���  
				pList->SetItemText( nItem,  8, GetDispData( pOutBlock[i].bef_diff  , sizeof( pOutBlock[i].bef_diff   ), DATA_TYPE_DOUBLE, 2 ) );		// [float , 10.2] ���Ϻ�      
				pList->SetItemText( nItem,  9, GetDispData( pOutBlock[i].shcode    , sizeof( pOutBlock[i].shcode     ), DATA_TYPE_STRING    ) );		// [string,    6] �����ڵ�    
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
LRESULT CDlg_t1452::OnXMTimeoutData( WPARAM wParam, LPARAM lParam )
{
	g_iXingAPI.ReleaseRequestData( (int)lParam );

	return 0L;
}

#include "DlgExcludeItem.h"
void CDlg_t1452::OnButtonExcludeItem() 
{
	CDlgExcludeItem dlg;
	dlg.SetData( GetDlgItemInt( IDC_INBLOCK_JC_NUM ) );
	if( dlg.DoModal() == IDOK )
	{
		SetDlgItemInt( IDC_INBLOCK_JC_NUM, dlg.GetData() );
	}	
}
