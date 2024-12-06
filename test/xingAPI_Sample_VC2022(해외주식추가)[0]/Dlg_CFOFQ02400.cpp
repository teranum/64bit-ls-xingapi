// Dlg_CFOFQ02400.cpp : implementation file
//

#include "stdafx.h"
#include "xingapi_sample.h"
#include "Dlg_CFOFQ02400.h"

#include "./Packet/CFOFQ02400.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlg_CFOFQ02400 dialog


IMPLEMENT_DYNCREATE(CDlg_CFOFQ02400, CDialog)

CDlg_CFOFQ02400::CDlg_CFOFQ02400(CWnd* pParent /*=NULL*/)
	: CDialog(CDlg_CFOFQ02400::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlg_CFOFQ02400)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CDlg_CFOFQ02400::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlg_CFOFQ02400)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
	DDX_Control(pDX, IDC_OUTBLOCK1, m_ctrlOutBlock1);
	DDX_Control(pDX, IDC_OUTBLOCK2, m_ctrlOutBlock2);
	DDX_Control(pDX, IDC_OUTBLOCK3, m_ctrlOutBlock3);
	DDX_Control(pDX, IDC_OUTBLOCK4, m_ctrlOutBlock4);
}


BEGIN_MESSAGE_MAP(CDlg_CFOFQ02400, CDialog)
	//{{AFX_MSG_MAP(CDlg_CFOFQ02400)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
	ON_BN_CLICKED( IDC_BUTTON_REQUEST,		  OnButtonRequest	  )
	ON_BN_CLICKED( IDC_BUTTON_REQUEST_NEXT,	  OnButtonRequestNext )
	ON_MESSAGE	 ( WM_USER + XM_RECEIVE_DATA, OnXMReceiveData	  )
	ON_MESSAGE	 ( WM_USER + XM_TIMEOUT_DATA, OnXMTimeoutData	  )
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlg_CFOFQ02400 message handlers

BOOL CDlg_CFOFQ02400::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	InitCtrls();
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CDlg_CFOFQ02400::OnButtonRequest() 
{
	RequestData();
}

void CDlg_CFOFQ02400::OnButtonRequestNext() 
{
	RequestData( TRUE );
}

//--------------------------------------------------------------------------------------
// ��Ʈ�� �ʱ�ȭ
//--------------------------------------------------------------------------------------
void CDlg_CFOFQ02400::InitCtrls()
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
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "���ڵ尹��      ", FALSE,    5 );    // [long  ,    5] ���ڵ尹��      
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "���¸�          ", TRUE ,   40 );    // [string,   40] ���¸�          
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "������������    ", FALSE,   16 );    // [long  ,   16] ������������    
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "�ɼǾ�������    ", FALSE,   16 );    // [long  ,   16] �ɼǾ�������    
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "��������        ", FALSE,   16 );    // [long  ,   16] ��������        
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "���������ݾ�    ", FALSE,   16 );    // [long  ,   16] ���������ݾ�    
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "�����ż������ݾ�", FALSE,   16 );    // [long  ,   16] �����ż������ݾ�
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "�����ŵ������ݾ�", FALSE,   16 );    // [long  ,   16] �����ŵ������ݾ�
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "�ݿɼǾ����ݾ�  ", FALSE,   16 );    // [long  ,   16] �ݿɼǾ����ݾ�  
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "�ݸż��ݾ�      ", FALSE,   16 );    // [long  ,   16] �ݸż��ݾ�      
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "�ݸŵ��ݾ�      ", FALSE,   16 );    // [long  ,   16] �ݸŵ��ݾ�      
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "ǲ�ɼǾ����ݾ�  ", FALSE,   16 );    // [long  ,   16] ǲ�ɼǾ����ݾ�  
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "ǲ�ż��ݾ�      ", FALSE,   16 );    // [long  ,   16] ǲ�ż��ݾ�      
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "ǲ�ŵ��ݾ�      ", FALSE,   16 );    // [long  ,   16] ǲ�ŵ��ݾ�      
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "��ü�����ݾ�    ", FALSE,   16 );    // [long  ,   16] ��ü�����ݾ�    
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "�ż���������ݾ�", FALSE,   16 );    // [long  ,   16] �ż���������ݾ�
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "�ŵ���������ݾ�", FALSE,   16 );    // [long  ,   16] �ŵ���������ݾ�
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "���������հ�    ", FALSE,   16 );    // [long  ,   16] ���������հ�    
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "�ɼǼ����հ�    ", FALSE,   16 );    // [long  ,   16] �ɼǼ����հ�    
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "��ü�����հ�    ", FALSE,   16 );    // [long  ,   16] ��ü�����հ�    
	
	//-------------------------------------------------------------------------
	// OutBlock2
	nCol = 0;
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "���ڵ尹��      ", FALSE,    5 );    // [long  ,    5] ���ڵ尹��      
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "���¸�          ", TRUE ,   40 );    // [string,   40] ���¸�          
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "������������    ", FALSE,   16 );    // [long  ,   16] ������������    
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "�ɼǾ�������    ", FALSE,   16 );    // [long  ,   16] �ɼǾ�������    
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "��������        ", FALSE,   16 );    // [long  ,   16] ��������        
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "���������ݾ�    ", FALSE,   16 );    // [long  ,   16] ���������ݾ�    
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "�����ż������ݾ�", FALSE,   16 );    // [long  ,   16] �����ż������ݾ�
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "�����ŵ������ݾ�", FALSE,   16 );    // [long  ,   16] �����ŵ������ݾ�
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "�ݿɼǾ����ݾ�  ", FALSE,   16 );    // [long  ,   16] �ݿɼǾ����ݾ�  
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "�ݸż��ݾ�      ", FALSE,   16 );    // [long  ,   16] �ݸż��ݾ�      
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "�ݸŵ��ݾ�      ", FALSE,   16 );    // [long  ,   16] �ݸŵ��ݾ�      
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "ǲ�ɼǾ����ݾ�  ", FALSE,   16 );    // [long  ,   16] ǲ�ɼǾ����ݾ�  
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "ǲ�ż��ݾ�      ", FALSE,   16 );    // [long  ,   16] ǲ�ż��ݾ�      
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "ǲ�ŵ��ݾ�      ", FALSE,   16 );    // [long  ,   16] ǲ�ŵ��ݾ�      
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "��ü�����ݾ�    ", FALSE,   16 );    // [long  ,   16] ��ü�����ݾ�    
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "�ż���������ݾ�", FALSE,   16 );    // [long  ,   16] �ż���������ݾ�
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "�ŵ���������ݾ�", FALSE,   16 );    // [long  ,   16] �ŵ���������ݾ�
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "���������հ�    ", FALSE,   16 );    // [long  ,   16] ���������հ�    
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "�ɼǼ����հ�    ", FALSE,   16 );    // [long  ,   16] �ɼǼ����հ�    
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "��ü�����հ�    ", FALSE,   16 );    // [long  ,   16] ��ü�����հ�    
	
	//-------------------------------------------------------------------------
	// OutBlock3
	nCol = 0;
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "�����ɼ�ǰ�񱸺�", TRUE ,    1 );    // [string,    1] �����ɼ�ǰ�񱸺�
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "�����ŵ�����    ", FALSE,   16 );    // [long  ,   16] �����ŵ�����    
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "�����ŵ�����    ", FALSE,   16 );    // [long  ,   16] �����ŵ�����    
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "�����ż�����    ", FALSE,   16 );    // [long  ,   16] �����ż�����    
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "�����ż�����    ", FALSE,   16 );    // [long  ,   16] �����ż�����    
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "�ݸŵ�����      ", FALSE,   16 );    // [long  ,   16] �ݸŵ�����      
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "�ݸŵ�����      ", FALSE,   16 );    // [long  ,   16] �ݸŵ�����      
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "�ݸż�����      ", FALSE,   16 );    // [long  ,   16] �ݸż�����      
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "�ݸż�����      ", FALSE,   16 );    // [long  ,   16] �ݸż�����      
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "ǲ�ŵ�����      ", FALSE,   16 );    // [long  ,   16] ǲ�ŵ�����      
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "ǲ�ŵ�����      ", FALSE,   16 );    // [long  ,   16] ǲ�ŵ�����      
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "ǲ�ż�����      ", FALSE,   16 );    // [long  ,   16] ǲ�ż�����      
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "ǲ�ż�����      ", FALSE,   16 );    // [long  ,   16] ǲ�ż�����      
	
	//-------------------------------------------------------------------------
	// OutBlock4
	nCol = 0;
	InsertColumn4List( this, IDC_OUTBLOCK4, nCol++, "�����ȣ    ", TRUE ,   12 );    // [string,   12] �����ȣ    
	InsertColumn4List( this, IDC_OUTBLOCK4, nCol++, "�����      ", TRUE ,   40 );    // [string,   40] �����      
	InsertColumn4List( this, IDC_OUTBLOCK4, nCol++, "�Ÿű���    ", TRUE ,    1 );    // [string,    1] �Ÿű���    
	InsertColumn4List( this, IDC_OUTBLOCK4, nCol++, "�Ÿű���    ", TRUE ,   10 );    // [string,   10] �Ÿű���    
	InsertColumn4List( this, IDC_OUTBLOCK4, nCol++, "�ܰ����    ", FALSE,   16 );    // [long  ,   16] �ܰ����    
	InsertColumn4List( this, IDC_OUTBLOCK4, nCol++, "��հ�      ", FALSE, 19.8 );    // [double, 19.8] ��հ�      
	InsertColumn4List( this, IDC_OUTBLOCK4, nCol++, "���ʱݾ�    ", FALSE,   16 );    // [long  ,   16] ���ʱݾ�    
	InsertColumn4List( this, IDC_OUTBLOCK4, nCol++, "����û�����", FALSE,   16 );    // [long  ,   16] ����û�����
	InsertColumn4List( this, IDC_OUTBLOCK4, nCol++, "���簡      ", FALSE, 13.2 );    // [double, 13.2] ���簡      
	InsertColumn4List( this, IDC_OUTBLOCK4, nCol++, "�򰡱ݾ�    ", FALSE,   16 );    // [long  ,   16] �򰡱ݾ�    
	InsertColumn4List( this, IDC_OUTBLOCK4, nCol++, "�򰡼��ͱݾ�", FALSE,   16 );    // [long  ,   16] �򰡼��ͱݾ�
	InsertColumn4List( this, IDC_OUTBLOCK4, nCol++, "�򰡼��ͷ�  ", FALSE, 12.6 );    // [double, 12.6] �򰡼��ͷ�  

	ZeroMemory( m_szContKey, sizeof( m_szContKey ) );
	GetDlgItem( IDC_BUTTON_REQUEST_NEXT )->EnableWindow( FALSE );
}

//--------------------------------------------------------------------------------------
// ������ ��ȸ
//--------------------------------------------------------------------------------------
void CDlg_CFOFQ02400::RequestData( BOOL bNext )
{
	//-----------------------------------------------------------
	CFOFQ02400InBlock1	pckInBlock;

	TCHAR			szTrNo[]		= "CFOFQ02400";
	char			szNextKey[]		= "";

	//-----------------------------------------------------------
	// ������ ���
    CString strAcntNo    ;		GetDlgItemText( IDC_INBLOCK_ACNTNO    , strAcntNo     );    // ���¹�ȣ       
    CString strPwd       ;		GetDlgItemText( IDC_INBLOCK_PWD       , strPwd        );    // ��й�ȣ       
    CString strRegMktCode;		GetDlgItemText( IDC_INBLOCK_REGMKTCODE, strRegMktCode );    // ��Ͻ����ڵ�   
    CString strBuyDt     ;		GetDlgItemText( IDC_INBLOCK_BUYDT     , strBuyDt      );    // �ż�����       

	//-----------------------------------------------------------
	// ������ �ʱ�ȭ
	FillMemory( &pckInBlock, sizeof( pckInBlock ), ' ' );

	//-----------------------------------------------------------
	// ������ �Է�
	SetPacketData( pckInBlock.RecCnt    , sizeof( pckInBlock.RecCnt     ), "1"          , DATA_TYPE_LONG   );    // [long  ,    5] ���ڵ尹��  
	SetPacketData( pckInBlock.AcntNo    , sizeof( pckInBlock.AcntNo     ), strAcntNo    , DATA_TYPE_STRING );    // [string,   20] ���¹�ȣ    
	SetPacketData( pckInBlock.Pwd       , sizeof( pckInBlock.Pwd        ), strPwd       , DATA_TYPE_STRING );    // [string,    8] ��й�ȣ    
	SetPacketData( pckInBlock.RegMktCode, sizeof( pckInBlock.RegMktCode ), strRegMktCode, DATA_TYPE_STRING );    // [string,    2] ��Ͻ����ڵ�
	SetPacketData( pckInBlock.BuyDt     , sizeof( pckInBlock.BuyDt      ), strBuyDt     , DATA_TYPE_STRING );    // [string,    8] �ż�����    

	//-----------------------------------------------------------
	// ������ ����
	int nRqID = g_iXingAPI.Request( 
		GetSafeHwnd(),				// �����͸� ���� ������, XM_RECEIVE_DATA ���� �´�.
		szTrNo,						// TR ��ȣ
		&pckInBlock,				// InBlock ������
		sizeof( pckInBlock ),		// InBlock ������ ũ��
		bNext,						// ������ȸ ���� : ������ȸ�� ��쿡 �����Ѵ�.
		bNext ? m_szContKey : "",	// ������ȸ Key : Header Type�� B �� ��쿣 ���� ��ȸ�� ���� Next Key�� �־��ش�.
		30							// Timeout(��) : �ش� �ð�(��)���� �����Ͱ� ���� ������ Timeout�� �߻��Ѵ�. XM_TIMEOUT_DATA �޽����� �߻��Ѵ�.
	);

	m_ctrlOutBlock1.DeleteAllItems();
	m_ctrlOutBlock2.DeleteAllItems();
	if( bNext == FALSE )
	{
		m_ctrlOutBlock3.DeleteAllItems();
		m_ctrlOutBlock4.DeleteAllItems();
	}

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
LRESULT CDlg_CFOFQ02400::OnXMReceiveData( WPARAM wParam, LPARAM lParam )
{
	//-------------------------------------------------------------------------------------
	// Data�� ����
	if( wParam == REQUEST_DATA )
	{
		LPRECV_PACKET	pRpData		= (LPRECV_PACKET)lParam;
		LPBYTE			lpData		= pRpData->lpData;
		int				nDataLength = pRpData->nDataLength;
		int				nOffset		= 0;
		int				nBlockSize	= 0;
		int				nCol;
		int				nRow;
		int				nCount;
		char			szCount[6] = { 0 };

		// ����Ű�� �����Ѵ�.
		strcpy_s( m_szContKey, pRpData->szContKey );
		GetDlgItem( IDC_BUTTON_REQUEST_NEXT )->EnableWindow( pRpData->cCont[0] == 'Y' );
		
		//------------------------------------------------
		// OutBlock1
		
		// ���� ������ ũ�Ⱑ Block ũ�⺸�� �۴ٸ� ó������ �ʴ´�.
		nBlockSize   = sizeof( CFOFQ02400OutBlock1 );
		nDataLength -= nBlockSize;
		if( nDataLength < 0 )
		{
			return 0L;
		}
		
		LPCFOFQ02400OutBlock1 pOutBlock1 = (LPCFOFQ02400OutBlock1)( lpData + nOffset );
		nOffset += nBlockSize;

		nCol = 0;
		m_ctrlOutBlock1.InsertItem( 0, "" );
		m_ctrlOutBlock1.SetItemText(  0, nCol++, GetDispData( pOutBlock1->RecCnt    , sizeof( pOutBlock1->RecCnt     ), DATA_TYPE_LONG   ) );    // [long  ,    5] ���ڵ尹��  
		m_ctrlOutBlock1.SetItemText(  0, nCol++, GetDispData( pOutBlock1->AcntNo    , sizeof( pOutBlock1->AcntNo     ), DATA_TYPE_STRING ) );    // [string,   20] ���¹�ȣ    
		m_ctrlOutBlock1.SetItemText(  0, nCol++, GetDispData( pOutBlock1->Pwd       , sizeof( pOutBlock1->Pwd        ), DATA_TYPE_STRING ) );    // [string,    8] ��й�ȣ    
		m_ctrlOutBlock1.SetItemText(  0, nCol++, GetDispData( pOutBlock1->RegMktCode, sizeof( pOutBlock1->RegMktCode ), DATA_TYPE_STRING ) );    // [string,    2] ��Ͻ����ڵ�
		m_ctrlOutBlock1.SetItemText(  0, nCol++, GetDispData( pOutBlock1->BuyDt     , sizeof( pOutBlock1->BuyDt      ), DATA_TYPE_STRING ) );    // [string,    8] �ż�����    
		
		//------------------------------------------------
		// OutBlock2
		
		// ���� ������ ũ�Ⱑ Block ũ�⺸�� �۴ٸ� ó������ �ʴ´�.
		nBlockSize   = sizeof( CFOFQ02400OutBlock2 );
		nDataLength -= nBlockSize;
		if( nDataLength < 0 )
		{
			return 0L;
		}
		
		LPCFOFQ02400OutBlock2 pOutBlock2 = (LPCFOFQ02400OutBlock2)( lpData + nOffset );
		nOffset += nBlockSize;

		nCol = 0;
		m_ctrlOutBlock2.InsertItem( 0, "" );
		m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pOutBlock2->RecCnt         , sizeof( pOutBlock2->RecCnt          ), DATA_TYPE_LONG   ) );    // [long  ,    5] ���ڵ尹��      
		m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pOutBlock2->AcntNm         , sizeof( pOutBlock2->AcntNm          ), DATA_TYPE_STRING ) );    // [string,   40] ���¸�          
		m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pOutBlock2->FutsCtrctQty   , sizeof( pOutBlock2->FutsCtrctQty    ), DATA_TYPE_LONG   ) );    // [long  ,   16] ������������    
		m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pOutBlock2->OptCtrctQty    , sizeof( pOutBlock2->OptCtrctQty     ), DATA_TYPE_LONG   ) );    // [long  ,   16] �ɼǾ�������    
		m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pOutBlock2->CtrctQty       , sizeof( pOutBlock2->CtrctQty        ), DATA_TYPE_LONG   ) );    // [long  ,   16] ��������        
		m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pOutBlock2->FutsCtrctAmt   , sizeof( pOutBlock2->FutsCtrctAmt    ), DATA_TYPE_LONG   ) );    // [long  ,   16] ���������ݾ�    
		m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pOutBlock2->FutsBuyctrAmt  , sizeof( pOutBlock2->FutsBuyctrAmt   ), DATA_TYPE_LONG   ) );    // [long  ,   16] �����ż������ݾ�
		m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pOutBlock2->FutsSlctrAmt   , sizeof( pOutBlock2->FutsSlctrAmt    ), DATA_TYPE_LONG   ) );    // [long  ,   16] �����ŵ������ݾ�
		m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pOutBlock2->CalloptCtrctAmt, sizeof( pOutBlock2->CalloptCtrctAmt ), DATA_TYPE_LONG   ) );    // [long  ,   16] �ݿɼǾ����ݾ�  
		m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pOutBlock2->CallBuyAmt     , sizeof( pOutBlock2->CallBuyAmt      ), DATA_TYPE_LONG   ) );    // [long  ,   16] �ݸż��ݾ�      
		m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pOutBlock2->CallSellAmt    , sizeof( pOutBlock2->CallSellAmt     ), DATA_TYPE_LONG   ) );    // [long  ,   16] �ݸŵ��ݾ�      
		m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pOutBlock2->PutoptCtrctAmt , sizeof( pOutBlock2->PutoptCtrctAmt  ), DATA_TYPE_LONG   ) );    // [long  ,   16] ǲ�ɼǾ����ݾ�  
		m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pOutBlock2->PutBuyAmt      , sizeof( pOutBlock2->PutBuyAmt       ), DATA_TYPE_LONG   ) );    // [long  ,   16] ǲ�ż��ݾ�      
		m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pOutBlock2->PutSellAmt     , sizeof( pOutBlock2->PutSellAmt      ), DATA_TYPE_LONG   ) );    // [long  ,   16] ǲ�ŵ��ݾ�      
		m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pOutBlock2->AllCtrctAmt    , sizeof( pOutBlock2->AllCtrctAmt     ), DATA_TYPE_LONG   ) );    // [long  ,   16] ��ü�����ݾ�    
		m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pOutBlock2->BuyctrAsmAmt   , sizeof( pOutBlock2->BuyctrAsmAmt    ), DATA_TYPE_LONG   ) );    // [long  ,   16] �ż���������ݾ�
		m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pOutBlock2->SlctrAsmAmt    , sizeof( pOutBlock2->SlctrAsmAmt     ), DATA_TYPE_LONG   ) );    // [long  ,   16] �ŵ���������ݾ�
		m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pOutBlock2->FutsPnlSum     , sizeof( pOutBlock2->FutsPnlSum      ), DATA_TYPE_LONG   ) );    // [long  ,   16] ���������հ�    
		m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pOutBlock2->OptPnlSum      , sizeof( pOutBlock2->OptPnlSum       ), DATA_TYPE_LONG   ) );    // [long  ,   16] �ɼǼ����հ�    
		m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pOutBlock2->AllPnlSum      , sizeof( pOutBlock2->AllPnlSum       ), DATA_TYPE_LONG   ) );    // [long  ,   16] ��ü�����հ�    
		
		//------------------------------------------------
		// OutBlock3

		// Count ���
		nBlockSize   = 5;
		nDataLength -= nBlockSize;
		if( nDataLength < 0 )
		{
			return 0L;
		}

		CopyMemory( szCount, lpData + nOffset, 5 );
		nCount = atoi( szCount );
		nOffset += nBlockSize;

		// Data
		nBlockSize   = sizeof( CFOFQ02400OutBlock3 ) * nCount;
		nDataLength -= nBlockSize;
		if( nDataLength < 0 )
		{
			return 0L;
		}
		
		LPCFOFQ02400OutBlock3 pOutBlock3 = (LPCFOFQ02400OutBlock3)( lpData + nOffset );
		nOffset += nBlockSize;

		for( int i=0; i<nCount; i++ )
		{
			nCol = 0;
			nRow = m_ctrlOutBlock3.InsertItem( m_ctrlOutBlock3.GetItemCount(), "" );
			m_ctrlOutBlock3.SetItemText( nRow, nCol++, GetDispData( pOutBlock3[i].FnoClssCode, sizeof( pOutBlock3[i].FnoClssCode ), DATA_TYPE_STRING ) );    // [string,    1] �����ɼ�ǰ�񱸺�
			m_ctrlOutBlock3.SetItemText( nRow, nCol++, GetDispData( pOutBlock3[i].FutsSellQty, sizeof( pOutBlock3[i].FutsSellQty ), DATA_TYPE_LONG   ) );    // [long  ,   16] �����ŵ�����    
			m_ctrlOutBlock3.SetItemText( nRow, nCol++, GetDispData( pOutBlock3[i].FutsSellPnl, sizeof( pOutBlock3[i].FutsSellPnl ), DATA_TYPE_LONG   ) );    // [long  ,   16] �����ŵ�����    
			m_ctrlOutBlock3.SetItemText( nRow, nCol++, GetDispData( pOutBlock3[i].FutsBuyQty , sizeof( pOutBlock3[i].FutsBuyQty  ), DATA_TYPE_LONG   ) );    // [long  ,   16] �����ż�����    
			m_ctrlOutBlock3.SetItemText( nRow, nCol++, GetDispData( pOutBlock3[i].FutsBuyPnl , sizeof( pOutBlock3[i].FutsBuyPnl  ), DATA_TYPE_LONG   ) );    // [long  ,   16] �����ż�����    
			m_ctrlOutBlock3.SetItemText( nRow, nCol++, GetDispData( pOutBlock3[i].CallSellQty, sizeof( pOutBlock3[i].CallSellQty ), DATA_TYPE_LONG   ) );    // [long  ,   16] �ݸŵ�����      
			m_ctrlOutBlock3.SetItemText( nRow, nCol++, GetDispData( pOutBlock3[i].CallSellPnl, sizeof( pOutBlock3[i].CallSellPnl ), DATA_TYPE_LONG   ) );    // [long  ,   16] �ݸŵ�����      
			m_ctrlOutBlock3.SetItemText( nRow, nCol++, GetDispData( pOutBlock3[i].CallBuyQty , sizeof( pOutBlock3[i].CallBuyQty  ), DATA_TYPE_LONG   ) );    // [long  ,   16] �ݸż�����      
			m_ctrlOutBlock3.SetItemText( nRow, nCol++, GetDispData( pOutBlock3[i].CallBuyPnl , sizeof( pOutBlock3[i].CallBuyPnl  ), DATA_TYPE_LONG   ) );    // [long  ,   16] �ݸż�����      
			m_ctrlOutBlock3.SetItemText( nRow, nCol++, GetDispData( pOutBlock3[i].PutSellQty , sizeof( pOutBlock3[i].PutSellQty  ), DATA_TYPE_LONG   ) );    // [long  ,   16] ǲ�ŵ�����      
			m_ctrlOutBlock3.SetItemText( nRow, nCol++, GetDispData( pOutBlock3[i].PutSellPnl , sizeof( pOutBlock3[i].PutSellPnl  ), DATA_TYPE_LONG   ) );    // [long  ,   16] ǲ�ŵ�����      
			m_ctrlOutBlock3.SetItemText( nRow, nCol++, GetDispData( pOutBlock3[i].PutBuyQty  , sizeof( pOutBlock3[i].PutBuyQty   ), DATA_TYPE_LONG   ) );    // [long  ,   16] ǲ�ż�����      
			m_ctrlOutBlock3.SetItemText( nRow, nCol++, GetDispData( pOutBlock3[i].PutBuyPnl  , sizeof( pOutBlock3[i].PutBuyPnl   ), DATA_TYPE_LONG   ) );    // [long  ,   16] ǲ�ż�����      
		}
		
		//------------------------------------------------
		// OutBlock4
		
		// Count ���
		nBlockSize   = 5;
		nDataLength -= nBlockSize;
		if( nDataLength < 0 )
		{
			return 0L;
		}
		
		CopyMemory( szCount, lpData + nOffset, 5 );
		nCount = atoi( szCount );
		nOffset += nBlockSize;
		
		// Data
		nBlockSize   = sizeof( CFOFQ02400OutBlock4 ) * nCount;
		nDataLength -= nBlockSize;
		if( nDataLength < 0 )
		{
			return 0L;
		}
		
		LPCFOFQ02400OutBlock4 pOutBlock4 = (LPCFOFQ02400OutBlock4)( lpData + nOffset );
		nOffset += nBlockSize;
		int i = 0;
		for( i=0; i<nCount; i++ )
		{
			nCol = 0;
			nRow = m_ctrlOutBlock4.InsertItem( m_ctrlOutBlock4.GetItemCount(), "" );
			m_ctrlOutBlock4.SetItemText( nRow, nCol++, GetDispData( pOutBlock4[i].IsuNo       , sizeof( pOutBlock4[i].IsuNo        ), DATA_TYPE_STRING ) );    // [string,   12] �����ȣ    
			m_ctrlOutBlock4.SetItemText( nRow, nCol++, GetDispData( pOutBlock4[i].IsuNm       , sizeof( pOutBlock4[i].IsuNm        ), DATA_TYPE_STRING ) );    // [string,   40] �����      
			m_ctrlOutBlock4.SetItemText( nRow, nCol++, GetDispData( pOutBlock4[i].BnsTpCode   , sizeof( pOutBlock4[i].BnsTpCode    ), DATA_TYPE_STRING ) );    // [string,    1] �Ÿű���    
			m_ctrlOutBlock4.SetItemText( nRow, nCol++, GetDispData( pOutBlock4[i].BnsTpNm     , sizeof( pOutBlock4[i].BnsTpNm      ), DATA_TYPE_STRING ) );    // [string,   10] �Ÿű���    
			m_ctrlOutBlock4.SetItemText( nRow, nCol++, GetDispData( pOutBlock4[i].BalQty      , sizeof( pOutBlock4[i].BalQty       ), DATA_TYPE_LONG   ) );    // [long  ,   16] �ܰ����    
			m_ctrlOutBlock4.SetItemText( nRow, nCol++, GetDispData( pOutBlock4[i].FnoAvrPrc   , sizeof( pOutBlock4[i].FnoAvrPrc    ), DATA_TYPE_DOT, 8 ) );    // [double, 19.8] ��հ�      
			m_ctrlOutBlock4.SetItemText( nRow, nCol++, GetDispData( pOutBlock4[i].BgnAmt      , sizeof( pOutBlock4[i].BgnAmt       ), DATA_TYPE_LONG   ) );    // [long  ,   16] ���ʱݾ�    
			m_ctrlOutBlock4.SetItemText( nRow, nCol++, GetDispData( pOutBlock4[i].ThdayLqdtQty, sizeof( pOutBlock4[i].ThdayLqdtQty ), DATA_TYPE_LONG   ) );    // [long  ,   16] ����û�����
			m_ctrlOutBlock4.SetItemText( nRow, nCol++, GetDispData( pOutBlock4[i].Curprc      , sizeof( pOutBlock4[i].Curprc       ), DATA_TYPE_DOT, 2 ) );    // [double, 13.2] ���簡      
			m_ctrlOutBlock4.SetItemText( nRow, nCol++, GetDispData( pOutBlock4[i].EvalAmt     , sizeof( pOutBlock4[i].EvalAmt      ), DATA_TYPE_LONG   ) );    // [long  ,   16] �򰡱ݾ�    
			m_ctrlOutBlock4.SetItemText( nRow, nCol++, GetDispData( pOutBlock4[i].EvalPnlAmt  , sizeof( pOutBlock4[i].EvalPnlAmt   ), DATA_TYPE_LONG   ) );    // [long  ,   16] �򰡼��ͱݾ�
			m_ctrlOutBlock4.SetItemText( nRow, nCol++, GetDispData( pOutBlock4[i].EvalErnrat  , sizeof( pOutBlock4[i].EvalErnrat   ), DATA_TYPE_DOT, 6 ) );    // [double, 12.6] �򰡼��ͷ�  
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
LRESULT CDlg_CFOFQ02400::OnXMTimeoutData( WPARAM wParam, LPARAM lParam )
{
	g_iXingAPI.ReleaseRequestData( (int)lParam );
	GetParent()->SendMessage( WMU_SET_MESSAGE, (WPARAM)"", (LPARAM)"Timeout" );		
	
	return 0L;
}
