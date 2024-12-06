// Dlg_g3190.cpp : implementation file
//

#include "stdafx.h"
#include "xingapi_sample.h"
#include "Dlg_g3190.h"

#include "./Packet/g3190.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlg_g3190 dialog


IMPLEMENT_DYNCREATE(CDlg_g3190, CDialog)

CDlg_g3190::CDlg_g3190(CWnd* pParent /*=NULL*/)
	: CDialog(CDlg_g3190::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlg_g3190)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CDlg_g3190::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlg_g3190)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlg_g3190, CDialog)
	//{{AFX_MSG_MAP(CDlg_g3190)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
	ON_BN_CLICKED( IDC_BUTTON_REQUEST,		  OnButtonRequest	  )
	ON_BN_CLICKED( IDC_BUTTON_REQUEST_NEXT,	  OnButtonRequestNext )
	ON_MESSAGE	 ( WM_USER + XM_RECEIVE_DATA, OnXMReceiveData	  )
	ON_MESSAGE	 ( WM_USER + XM_TIMEOUT_DATA, OnXMTimeoutData	  )
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlg_g3190 message handlers

BOOL CDlg_g3190::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	InitCtrls();
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CDlg_g3190::OnButtonRequest() 
{
	RequestData();
}

void CDlg_g3190::OnButtonRequestNext() 
{
	RequestData( TRUE );
}

//--------------------------------------------------------------------------------------
// ��Ʈ�� �ʱ�ȭ
//--------------------------------------------------------------------------------------
void CDlg_g3190::InitCtrls()
{
	//-----------------------------------------------------------
	// OutBlock
	InsertColumn4List( this, IDC_OUTBLOCK ,  0, "��������      ", FALSE,  8  );   // [string,    1] ��������   
	InsertColumn4List( this, IDC_OUTBLOCK ,  1, "��������      ", TRUE ,  8  );   // [string,    2] ��������   
	InsertColumn4List( this, IDC_OUTBLOCK ,  2, "�ŷ��ұ���    ", FALSE,  10 );  // [string,    1] �ŷ��ұ���  
	InsertColumn4List( this, IDC_OUTBLOCK ,  3, "���ӱ���      ", TRUE ,  16 );  // [string,   16] ���ӱ���   
	InsertColumn4List( this, IDC_OUTBLOCK ,  4, "���ڵ�ī��Ʈ  ", FALSE,  8  );	// [long  ,    7] ���ڵ�ī��Ʈ 
	
	//-----------------------------------------------------------
	// OutBlock1
	InsertColumn4List( this, IDC_OUTBLOCK1,  0, "KEY�����ڵ�     ",		TRUE ,	18	);		// [string,   18] KEY�����ڵ�   
	InsertColumn4List( this, IDC_OUTBLOCK1,  1, "�����ڵ�        ",		TRUE ,  2	);		// [string,    2] �����ڵ�      
	InsertColumn4List( this, IDC_OUTBLOCK1,  2, "�ŷ����ڵ�      ",		TRUE ,  2	);		// [string,    2] �ŷ����ڵ�     
	InsertColumn4List( this, IDC_OUTBLOCK1,  3, "�����ڵ�        ",		TRUE ,  16	);		// [string,   16] �����ڵ�      
	InsertColumn4List( this, IDC_OUTBLOCK1,  4, "�ŷ��������ڵ�  ",		TRUE ,  18	);		// [string,   18] �ŷ��������ڵ�  
	InsertColumn4List( this, IDC_OUTBLOCK1,  5, "�ѱ������      ",		TRUE ,  64	);		// [string,   64] �ѱ������     
	InsertColumn4List( this, IDC_OUTBLOCK1,  6, "���������      ",		TRUE ,  64	);		// [string,   64] ���������     
	InsertColumn4List( this, IDC_OUTBLOCK1,  7, "��ȯ�ڵ�        ",		TRUE ,  4	);		// [string,    4] ��ȯ�ڵ�      
	InsertColumn4List( this, IDC_OUTBLOCK1,  8, "ISIN           ",		TRUE ,	12	);		// [string,   12] ISIN       
	InsertColumn4List( this, IDC_OUTBLOCK1,  9, "FLOATPOINT     ",		TRUE ,	1	);		// [string,    1] FLOATPOINT 
	InsertColumn4List( this, IDC_OUTBLOCK1, 10, "�����ڵ�        ",		TRUE ,  4	);		// [string,    4] �����ڵ�      
	InsertColumn4List( this, IDC_OUTBLOCK1, 11, "�����ֽļ�      ",		FALSE,  16	);		// [long  ,   16] �����ֽļ�     
	InsertColumn4List( this, IDC_OUTBLOCK1, 12, "�ں���          ",		FALSE,  16	);		// [long  ,   16] �ں���       
	InsertColumn4List( this, IDC_OUTBLOCK1, 13, "�׸鰡          ",		FALSE,	15.6 );		// [double, 15.6] �׸鰡       
	InsertColumn4List( this, IDC_OUTBLOCK1, 14, "�׸鰡��ȯ�ڵ�   ",		TRUE ,	4	);		// [string,    4] �׸鰡��ȯ�ڵ�  
	InsertColumn4List( this, IDC_OUTBLOCK1, 15, "�ż��ֹ�����2    ",		TRUE ,  8	);		// [string,    8] �ż��ֹ�����2   
	InsertColumn4List( this, IDC_OUTBLOCK1, 16, "�ŵ��ֹ�����2    ",		TRUE ,	8	);		// [string,    8] �ŵ��ֹ�����2   
	InsertColumn4List( this, IDC_OUTBLOCK1, 17, "���ذ�           ",		FALSE,	15.6 );		// [double, 15.6] ���ذ�       
	InsertColumn4List( this, IDC_OUTBLOCK1, 18, "��������         ",		TRUE ,  8	);		// [string,    8] ��������      
	InsertColumn4List( this, IDC_OUTBLOCK1, 19, "��������          ",	TRUE ,  8	);		// [string,    8] ��������      
	InsertColumn4List( this, IDC_OUTBLOCK1, 20, "�ŷ���������      ",	TRUE ,  1	);		// [string,    1] �ŷ���������    
	InsertColumn4List( this, IDC_OUTBLOCK1, 21, "��������          ",	TRUE ,  8	);		// [string,    8] ��������      
	InsertColumn4List( this, IDC_OUTBLOCK1, 22, "SELLONLY����      ",	TRUE ,  8	);		// [string,    8] SELLONLY����
	InsertColumn4List( this, IDC_OUTBLOCK1, 23, "����������        ",	TRUE ,  1	);		// [string,    1] ����������     
	InsertColumn4List( this, IDC_OUTBLOCK1, 24, "TICKSIZETYPE     ",	TRUE ,  8	);		// [string,    8] TICKSIZETYP
	InsertColumn4List( this, IDC_OUTBLOCK1, 25, "��������          ",	FALSE,  15.6 );		// [double, 15.6] ��������      
	InsertColumn4List( this, IDC_OUTBLOCK1, 26, "VCM�������       ",	TRUE ,  1	);		// [string,    1] VCM�������   
	InsertColumn4List( this, IDC_OUTBLOCK1, 27, "CAS�������       ",	TRUE ,  1	);		// [string,    1] CAS�������   
	InsertColumn4List( this, IDC_OUTBLOCK1, 28, "POS�������       ",	TRUE ,  1	);		// [string,    1] POS�������   
	InsertColumn4List( this, IDC_OUTBLOCK1, 29, "�Ҽ����ŸŰ������� ",	TRUE ,  1	);		// [string,    1] �Ҽ����ŸŰ�������
}

//--------------------------------------------------------------------------------------
// ������ ��ȸ
//--------------------------------------------------------------------------------------
void CDlg_g3190::RequestData( BOOL bNext )
{
	//-----------------------------------------------------------
	// �Ⱓ���ְ�(g3190) ( attr,block,headtype=A )
	g3190InBlock	pckInBlock;

	TCHAR			szTrNo[]	= "g3190";

	//-----------------------------------------------------------
	// ������ �ʱ�ȭ
	FillMemory( &pckInBlock, sizeof( pckInBlock ), ' ' );
	
	//-----------------------------------------------------------
	// ������ �Է�
	SetPacketData( pckInBlock.delaygb      , sizeof( pckInBlock.delaygb       ), this, IDC_INBLOCK_DELAYGB    , DATA_TYPE_STRING );// [string,    1] ��������          
	SetPacketData( pckInBlock.natcode      , sizeof( pckInBlock.natcode       ), this, IDC_INBLOCK_NATCODE    , DATA_TYPE_STRING );	// [string,    2] ��������          
	SetPacketData( pckInBlock.exgubun      , sizeof( pckInBlock.exgubun       ), this, IDC_INBLOCK_EXCHCD     , DATA_TYPE_STRING );	// [string,    1] �ŷ��ұ���         
	SetPacketData( pckInBlock.readcnt      , sizeof( pckInBlock.readcnt       ), this, IDC_INBLOCK_CNT        , DATA_TYPE_LONG   );	// [long  ,    4] ��ȸ����          
	SetPacketData( pckInBlock.cts_value    , sizeof( pckInBlock.cts_value     ), this, IDC_INBLOCK_CTS_VALUE  , DATA_TYPE_STRING );	// [string,   16] ���ӱ���          

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
LRESULT CDlg_g3190::OnXMReceiveData( WPARAM wParam, LPARAM lParam )
{
	//-------------------------------------------------------------------------------------
	// Data�� ����
	if( wParam == REQUEST_DATA )
	{
		LPRECV_PACKET pRpData = (LPRECV_PACKET)lParam;

		// Block Mode �̴�.
		if( strcmp( pRpData->szBlockName, NAME_g3190OutBlock ) == 0 )
		{
			CListCtrl*		pList	  = (CListCtrl*)GetDlgItem( IDC_OUTBLOCK );
			LPg3190OutBlock pOutBlock = (LPg3190OutBlock)pRpData->lpData;

			int nItem = pList->InsertItem( pList->GetItemCount(), "" );
			pList->SetItemText( nItem,  0, GetDispData( pOutBlock->delaygb   , sizeof( pOutBlock->delaygb   ), DATA_TYPE_STRING ) );		// [string,    1] �������� 
			pList->SetItemText( nItem,  1, GetDispData( pOutBlock->natcode   , sizeof( pOutBlock->natcode   ), DATA_TYPE_STRING ) );		// [string,    2] �������� 
			pList->SetItemText( nItem,  2, GetDispData( pOutBlock->exgubun   , sizeof( pOutBlock->exgubun   ), DATA_TYPE_STRING ) );		// [string,    1] �ŷ��ұ��� 
			pList->SetItemText( nItem,  3, GetDispData( pOutBlock->cts_value , sizeof( pOutBlock->cts_value ), DATA_TYPE_STRING ) );		// [string,   16] ���ӱ��� 
			pList->SetItemText( nItem,  4, GetDispData( pOutBlock->rec_count , sizeof( pOutBlock->rec_count ), DATA_TYPE_LONG   ) );		// [long  ,    4] ��ȸ����
		}
		else if( strcmp( pRpData->szBlockName, NAME_g3190OutBlock1 ) == 0 )
		{
			CListCtrl*		 pList	   = (CListCtrl*)GetDlgItem( IDC_OUTBLOCK1 );
			LPg3190OutBlock1 pOutBlock = (LPg3190OutBlock1)pRpData->lpData;
			int				 nCount	   = pRpData->nDataLength / sizeof( g3190OutBlock1 );		// Block Mode �ÿ� ��üũ�� / �ϳ��� Record ũ�� �� ������ ���Ѵ�.
			for( int i=0; i<nCount; i++ )
			{
				int nItem = pList->InsertItem( pList->GetItemCount(), "" );
				pList->SetItemText( nItem,  0, GetDispData( pOutBlock[i].keysymbol   , sizeof( pOutBlock[i].keysymbol   ), DATA_TYPE_STRING ) );		    // [string,   18] KEY�����ڵ�    
				pList->SetItemText( nItem,  1, GetDispData( pOutBlock[i].natcode     , sizeof( pOutBlock[i].natcode     ), DATA_TYPE_STRING ) );		    // [string,    2] �����ڵ�       
				pList->SetItemText( nItem,  2, GetDispData( pOutBlock[i].exchcd      , sizeof( pOutBlock[i].exchcd      ), DATA_TYPE_STRING ) );		    // [string,    2] �ŷ����ڵ�      
				pList->SetItemText( nItem,  3, GetDispData( pOutBlock[i].symbol      , sizeof( pOutBlock[i].symbol      ), DATA_TYPE_STRING ) );		    // [string,   16] �����ڵ�       
				pList->SetItemText( nItem,  4, GetDispData( pOutBlock[i].seccode     , sizeof( pOutBlock[i].seccode     ), DATA_TYPE_STRING ) );		    // [string,   18] �ŷ��������ڵ�   
				pList->SetItemText( nItem,  5, GetDispData( pOutBlock[i].korname     , sizeof( pOutBlock[i].korname     ), DATA_TYPE_STRING ) );		    // [string,   64] �ѱ������      
				pList->SetItemText( nItem,  6, GetDispData( pOutBlock[i].engname     , sizeof( pOutBlock[i].engname     ), DATA_TYPE_STRING ) );		    // [string,   64] ���������      
				pList->SetItemText( nItem,  7, GetDispData( pOutBlock[i].currency    , sizeof( pOutBlock[i].currency    ), DATA_TYPE_STRING ) );		    // [string,    4] ��ȯ�ڵ�       
				pList->SetItemText( nItem,  8, GetDispData( pOutBlock[i].isin        , sizeof( pOutBlock[i].isin        ), DATA_TYPE_STRING ) );		    // [string,   12] ISIN        
				pList->SetItemText( nItem,  9, GetDispData( pOutBlock[i].floatpoint  , sizeof( pOutBlock[i].floatpoint  ), DATA_TYPE_STRING ) );		    // [string,    1] FLOATPOINT  
				pList->SetItemText( nItem, 10, GetDispData( pOutBlock[i].indusury    , sizeof( pOutBlock[i].indusury    ), DATA_TYPE_STRING ) );		    // [string,    4] �����ڵ�       
				pList->SetItemText( nItem, 11, GetDispData( pOutBlock[i].share       , sizeof( pOutBlock[i].share       ), DATA_TYPE_LONG   ) );		    // [long  ,   16] �����ֽļ�      
				pList->SetItemText( nItem, 12, GetDispData( pOutBlock[i].marketcap   , sizeof( pOutBlock[i].marketcap   ), DATA_TYPE_LONG   ) );		    // [long  ,   16] �ں���        
				pList->SetItemText( nItem, 13, GetDispData( pOutBlock[i].par         , sizeof( pOutBlock[i].par         ), DATA_TYPE_DOUBLE, 6 ) );		    // [double, 15.6] �׸鰡        
				pList->SetItemText( nItem, 14, GetDispData( pOutBlock[i].parcurr     , sizeof( pOutBlock[i].parcurr     ), DATA_TYPE_LONG   ) );		    // [string,    4] �׸鰡��ȯ�ڵ�   
				pList->SetItemText( nItem, 15, GetDispData( pOutBlock[i].bidlotsize2 , sizeof( pOutBlock[i].bidlotsize2 ), DATA_TYPE_STRING ) );		    // [string,    8] �ż��ֹ�����2    
				pList->SetItemText( nItem, 16, GetDispData( pOutBlock[i].asklotsize2 , sizeof( pOutBlock[i].asklotsize2 ), DATA_TYPE_STRING ) );		    // [string,    8] �ŵ��ֹ�����2    
				pList->SetItemText( nItem, 17, GetDispData( pOutBlock[i].clos        , sizeof( pOutBlock[i].clos        ), DATA_TYPE_DOUBLE, 6 ) );		    // [double, 15.6] ���ذ�        
				pList->SetItemText( nItem, 18, GetDispData( pOutBlock[i].listed_date , sizeof( pOutBlock[i].listed_date ), DATA_TYPE_STRING ) );		    // [string,    8] ��������       
				pList->SetItemText( nItem, 19, GetDispData( pOutBlock[i].expire_date , sizeof( pOutBlock[i].expire_date ), DATA_TYPE_STRING ) );		    // [string,    8] ��������       
				pList->SetItemText( nItem, 20, GetDispData( pOutBlock[i].suspend     , sizeof( pOutBlock[i].suspend     ), DATA_TYPE_LONG   ) );		    // [string,    1] �ŷ���������     
				pList->SetItemText( nItem, 21, GetDispData( pOutBlock[i].bymd        , sizeof( pOutBlock[i].bymd        ), DATA_TYPE_STRING ) );		    // [string,    8] ��������       
				pList->SetItemText( nItem, 22, GetDispData( pOutBlock[i].sellonly    , sizeof( pOutBlock[i].sellonly    ), DATA_TYPE_STRING ) );		    // [string,    8] SELLONLY���� 
				pList->SetItemText( nItem, 23, GetDispData( pOutBlock[i].stamp       , sizeof( pOutBlock[i].stamp       ), DATA_TYPE_STRING ) );		    // [string,    1] ����������      
				pList->SetItemText( nItem, 24, GetDispData( pOutBlock[i].ticktype    , sizeof( pOutBlock[i].ticktype    ), DATA_TYPE_STRING ) );		    // [string,    8] TICKSIZETYPE
				pList->SetItemText( nItem, 25, GetDispData( pOutBlock[i].pcls        , sizeof( pOutBlock[i].pcls        ), DATA_TYPE_DOUBLE, 6 ) );		    // [double, 15.6] ��������       
				pList->SetItemText( nItem, 26, GetDispData( pOutBlock[i].vcmf        , sizeof( pOutBlock[i].vcmf        ), DATA_TYPE_STRING ) );		    // [string,    1] VCM�������    
				pList->SetItemText( nItem, 27, GetDispData( pOutBlock[i].casf        , sizeof( pOutBlock[i].casf        ), DATA_TYPE_STRING ) );		    // [string,    1] CAS�������    
				pList->SetItemText( nItem, 28, GetDispData( pOutBlock[i].posf        , sizeof( pOutBlock[i].posf        ), DATA_TYPE_STRING ) );		    // [string,    1] POS�������    
				pList->SetItemText( nItem, 29, GetDispData( pOutBlock[i].point       , sizeof( pOutBlock[i].point       ), DATA_TYPE_STRING ) );		    // [string,    1] �Ҽ����ŸŰ������� 
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
LRESULT CDlg_g3190::OnXMTimeoutData( WPARAM wParam, LPARAM lParam )
{
	g_iXingAPI.ReleaseRequestData( (int)lParam );

	return 0L;
}
