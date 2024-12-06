// Dlg_CSPBQ00200.cpp : implementation file
//

#include "stdafx.h"
#include "xingapi_sample.h"
#include "Dlg_CSPBQ00200.h"

#include "./Packet/CSPBQ00200.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlg_CSPBQ00200 dialog


IMPLEMENT_DYNCREATE(CDlg_CSPBQ00200, CDialog)

CDlg_CSPBQ00200::CDlg_CSPBQ00200(CWnd* pParent /*=NULL*/)
	: CDialog(CDlg_CSPBQ00200::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlg_CSPBQ00200)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CDlg_CSPBQ00200::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlg_CSPBQ00200)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
	DDX_Control(pDX, IDC_OUTBLOCK1, m_ctrlOutBlock1);
	DDX_Control(pDX, IDC_OUTBLOCK2, m_ctrlOutBlock2);
}


BEGIN_MESSAGE_MAP(CDlg_CSPBQ00200, CDialog)
	//{{AFX_MSG_MAP(CDlg_CSPBQ00200)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
	ON_BN_CLICKED( IDC_BUTTON_REQUEST,		  OnButtonRequest	  )
	ON_MESSAGE	 ( WM_USER + XM_RECEIVE_DATA, OnXMReceiveData	  )
	ON_MESSAGE	 ( WM_USER + XM_TIMEOUT_DATA, OnXMTimeoutData	  )
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlg_CSPBQ00200 message handlers

BOOL CDlg_CSPBQ00200::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	InitCtrls();
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CDlg_CSPBQ00200::OnButtonRequest() 
{
	RequestData();
}


//--------------------------------------------------------------------------------------
// ��Ʈ�� �ʱ�ȭ
//--------------------------------------------------------------------------------------
void CDlg_CSPBQ00200::InitCtrls()
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
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "���ڵ尹��  ", FALSE,    5 );    // [long  ,    5] ���ڵ尹��  
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "�Ÿű���    ", TRUE ,    1 );    // [string,    1] �Ÿű���    
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "���¹�ȣ    ", TRUE ,   20 );    // [string,   20] ���¹�ȣ    
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "�Էº�й�ȣ", TRUE ,    8 );    // [string,    8] �Էº�й�ȣ
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "�����ȣ    ", TRUE ,   12 );    // [string,   12] �����ȣ    
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "�ֹ�����    ", FALSE, 15.2 );    // [double, 15.2] �ֹ�����    
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "��Ÿ�ü�ڵ�", TRUE ,    2 );    // [string,    2] ��Ÿ�ü�ڵ�

	//-------------------------------------------------------------------------
	// OutBlock2
	nCol = 0;
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "���ڵ尹��                       ", FALSE,    5 );    // [long  ,    5] ���ڵ尹��                      
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "���¸�                           ", TRUE ,   40 );    // [string,   40] ���¸�                          
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "�����                           ", TRUE ,   40 );    // [string,   40] �����                          
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "������                           ", FALSE,   16 );    // [long  ,   16] ������                          
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "���ݾ�                         ", FALSE,   16 );    // [long  ,   16] ���ݾ�                        
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "�ſ�㺸����ݾ�               ", FALSE,   16 );    // [long  ,   16] �ſ�㺸����ݾ�              
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "�����ֹ����ɱݾ�                 ", FALSE,   16 );    // [long  ,   16] �����ֹ����ɱݾ�                
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "����ֹ����ɱݾ�                 ", FALSE,   16 );    // [long  ,   16] ����ֹ����ɱݾ�                
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "�������űݾ�                     ", FALSE,   16 );    // [long  ,   16] �������űݾ�                    
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "������űݾ�                     ", FALSE,   16 );    // [long  ,   16] ������űݾ�                    
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "�ŷ��ұݾ�                       ", FALSE,   16 );    // [long  ,   16] �ŷ��ұݾ�                      
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "�ڽ��ڱݾ�                       ", FALSE,   16 );    // [long  ,   16] �ڽ��ڱݾ�                      
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "����������(D+1)                  ", FALSE,   16 );    // [long  ,   16] ����������(D+1)                 
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "����������(D+2)                  ", FALSE,   16 );    // [long  ,   16] ����������(D+2)                 
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "��ݰ��ɱݾ�                     ", FALSE,   16 );    // [long  ,   16] ��ݰ��ɱݾ�                    
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "�̼��ݾ�                         ", FALSE,   16 );    // [long  ,   16] �̼��ݾ�                        
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "��������                         ", FALSE, 15.5 );    // [double, 15.5] ��������                        
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "�߰�¡���ݾ�                     ", FALSE,   16 );    // [long  ,   16] �߰�¡���ݾ�                    
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "������ݾ�                   ", FALSE,   16 );    // [long  ,   16] ������ݾ�                  
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "����������ݾ�               ", FALSE,   16 );    // [long  ,   16] ����������ݾ�              
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "�̿�����űݷ�                   ", FALSE,  7.4 );    // [double,  7.4] �̿�����űݷ�                  
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "���������ݾ�               ", FALSE,   16 );    // [long  ,   16] ���������ݾ�              
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "�������űݷ�                     ", FALSE,  7.4 );    // [double,  7.4] �������űݷ�                    
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "�������űݷ�                     ", FALSE,  7.4 );    // [double,  7.4] �������űݷ�                    
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "�ŷ����űݷ�                     ", FALSE,  7.4 );    // [double,  7.4] �ŷ����űݷ�                    
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "������                           ", FALSE,   16 );    // [long  ,   16] ������                          
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "���űݷ�20�ۼ�Ʈ�ֹ����ɱݾ�     ", FALSE,   16 );    // [long  ,   16] ���űݷ�20�ۼ�Ʈ�ֹ����ɱݾ�    
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "���űݷ�100�ۼ�Ʈ�����ֹ����ɼ���", FALSE,   16 );    // [long  ,   16] ���űݷ�100�ۼ�Ʈ�����ֹ����ɼ���
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "���űݷ�30�ۼ�Ʈ�ֹ����ɱݾ�     ", FALSE,   16 );    // [long  ,   16] ���űݷ�30�ۼ�Ʈ�ֹ����ɱݾ�    
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "���űݷ�30�ۼ�Ʈ�ֹ����ɼ���     ", FALSE,   16 );    // [long  ,   16] ���űݷ�30�ۼ�Ʈ�ֹ����ɼ���
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "���űݷ�40�ۼ�Ʈ�ֹ����ɱݾ�     ", FALSE,   16 );    // [long  ,   16] ���űݷ�40�ۼ�Ʈ�ֹ����ɱݾ�    
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "���űݷ�40�ۼ�Ʈ�ֹ����ɼ���     ", FALSE,   16 );    // [long  ,   16] ���űݷ�40�ۼ�Ʈ�ֹ����ɼ���
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "���űݷ�100�ۼ�Ʈ�ֹ����ɱݾ�    ", FALSE,   16 );    // [long  ,   16] ���űݷ�100�ۼ�Ʈ�ֹ����ɱݾ�   
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "���űݷ�100�ۼ�Ʈ�ֹ����ɼ���    ", FALSE,   16 );    // [long  ,   16] ���űݷ�100�ۼ�Ʈ�ֹ����ɼ���
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "���űݷ�100�ۼ�Ʈ�����ֹ����ɱݾ�", FALSE,   16 );    // [long  ,   16] ���űݷ�100�ۼ�Ʈ�����ֹ����ɱݾ�
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "���űݷ�100�ۼ�Ʈ�����ֹ����ɼ���", FALSE,   16 );    // [long  ,   16] ���űݷ�100�ۼ�Ʈ�����ֹ����ɼ���
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "���űݷ�20�ۼ�Ʈ���밡�ɱݾ�   ", FALSE,   16 );    // [long  ,   16] ���űݷ�20�ۼ�Ʈ���밡�ɱݾ�  
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "���űݷ�30�ۼ�Ʈ���밡�ɱݾ�   ", FALSE,   16 );    // [long  ,   16] ���űݷ�30�ۼ�Ʈ���밡�ɱݾ�  
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "���űݷ�40�ۼ�Ʈ���밡�ɱݾ�   ", FALSE,   16 );    // [long  ,   16] ���űݷ�40�ۼ�Ʈ���밡�ɱݾ�  
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "���űݷ�100�ۼ�Ʈ���밡�ɱݾ�  ", FALSE,   16 );    // [long  ,   16] ���űݷ�100�ۼ�Ʈ���밡�ɱݾ� 
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "�ֹ����ɼ���                     ", FALSE,   16 );    // [long  ,   16] �ֹ����ɼ���                    
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "�ֹ����ɱݾ�                     ", FALSE,   16 );    // [long  ,   16] �ֹ����ɱݾ�                    
}

//--------------------------------------------------------------------------------------
// ������ ��ȸ
//--------------------------------------------------------------------------------------
void CDlg_CSPBQ00200::RequestData( BOOL bNext )
{
	//-----------------------------------------------------------
// ���������ֹ�(CSPBQ00200) ( base21=SONAT000,headtype=B )
	CSPBQ00200InBlock1	pckInBlock;

	TCHAR			szTrNo[]		= "CSPBQ00200";
	char			szNextKey[]		= "";

	//-----------------------------------------------------------
	// ������ ���
    CString strBnsTpCode    ;		GetDlgItemText( IDC_INBLOCK_BNSTPCODE    , strBnsTpCode     );    // [string,    1] �Ÿű���    
    CString strAcntNo       ;		GetDlgItemText( IDC_INBLOCK_ACNTNO       , strAcntNo        );    // [string,   20] ���¹�ȣ    
    CString strInptPwd      ;		GetDlgItemText( IDC_INBLOCK_INPTPWD      , strInptPwd       );    // [string,    8] �Էº�й�ȣ
    CString strIsuNo        ;		GetDlgItemText( IDC_INBLOCK_ISUNO        , strIsuNo         );    // [string,   12] �����ȣ    
    CString strOrdPrc       ;		GetDlgItemText( IDC_INBLOCK_ORDPRC       , strOrdPrc        );    // [double, 15.2] �ֹ�����    

	//-----------------------------------------------------------
	// ������ �ʱ�ȭ
	FillMemory( &pckInBlock, sizeof( pckInBlock ), ' ' );

	//-----------------------------------------------------------
	// ������ �Է�
	SetPacketData( pckInBlock.RecCnt       , sizeof( pckInBlock.RecCnt        ), "1"                      , DATA_TYPE_LONG   );    // [long  ,    5] ���ڵ尹��  
	SetPacketData( pckInBlock.BnsTpCode    , sizeof( pckInBlock.BnsTpCode     ), strBnsTpCode             , DATA_TYPE_STRING );    // [string,    1] �Ÿű���    
	SetPacketData( pckInBlock.AcntNo       , sizeof( pckInBlock.AcntNo        ), strAcntNo                , DATA_TYPE_STRING );    // [string,   20] ���¹�ȣ    
	SetPacketData( pckInBlock.InptPwd      , sizeof( pckInBlock.InptPwd       ), strInptPwd               , DATA_TYPE_STRING );    // [string,    8] �Էº�й�ȣ
	SetPacketData( pckInBlock.IsuNo        , sizeof( pckInBlock.IsuNo         ), strIsuNo                 , DATA_TYPE_STRING );    // [string,   12] �����ȣ    
	SetPacketData( pckInBlock.OrdPrc       , sizeof( pckInBlock.OrdPrc        ), strOrdPrc                , DATA_TYPE_DOT, 2 );    // [double, 15.2] �ֹ�����    
	SetPacketData( pckInBlock.RegCommdaCode, sizeof( pckInBlock.RegCommdaCode ), g_iXingAPI.GetCommMedia(), DATA_TYPE_STRING );    // [string,    2] ��Ÿ�ü�ڵ�

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
LRESULT CDlg_CSPBQ00200::OnXMReceiveData( WPARAM wParam, LPARAM lParam )
{
	//-------------------------------------------------------------------------------------
	// Data�� ����
	if( wParam == REQUEST_DATA )
	{
		LPRECV_PACKET pRpData = (LPRECV_PACKET)lParam;

		typedef struct
		{
			CSPBQ00200OutBlock1	outBlock1;
			CSPBQ00200OutBlock2	outBlock2;
		} CSPBQ00200AllOutBlock, *LPCSPBQ00200AllOutBlock;

		LPCSPBQ00200AllOutBlock pAllOutBlock = (LPCSPBQ00200AllOutBlock)pRpData->lpData;

		// ���� ������ ũ�Ⱑ Block ũ�⺸�� �۴ٸ� ó������ �ʴ´�.
		if( pRpData->nDataLength >= sizeof( CSPBQ00200OutBlock1 ) )
		{
			int nCol = 0;
			m_ctrlOutBlock1.InsertItem( 0, "" );
			m_ctrlOutBlock1.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock1.RecCnt       , sizeof( pAllOutBlock->outBlock1.RecCnt        ), DATA_TYPE_LONG   ) );    // [long  ,    5] ���ڵ尹��  
			m_ctrlOutBlock1.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock1.BnsTpCode    , sizeof( pAllOutBlock->outBlock1.BnsTpCode     ), DATA_TYPE_STRING ) );    // [string,    1] �Ÿű���    
			m_ctrlOutBlock1.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock1.AcntNo       , sizeof( pAllOutBlock->outBlock1.AcntNo        ), DATA_TYPE_STRING ) );    // [string,   20] ���¹�ȣ    
			m_ctrlOutBlock1.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock1.InptPwd      , sizeof( pAllOutBlock->outBlock1.InptPwd       ), DATA_TYPE_STRING ) );    // [string,    8] �Էº�й�ȣ
			m_ctrlOutBlock1.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock1.IsuNo        , sizeof( pAllOutBlock->outBlock1.IsuNo         ), DATA_TYPE_LONG   ) );    // [string,   12] �����ȣ    
			m_ctrlOutBlock1.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock1.OrdPrc       , sizeof( pAllOutBlock->outBlock1.OrdPrc        ), DATA_TYPE_DOT, 2 ) );    // [double, 15.2] �ֹ�����            
			m_ctrlOutBlock1.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock1.RegCommdaCode, sizeof( pAllOutBlock->outBlock1.RegCommdaCode ), DATA_TYPE_STRING ) );    // [string,    2] ��Ÿ�ü�ڵ�
		}

		if( pRpData->nDataLength >= sizeof( CSPBQ00200OutBlock1 ) + sizeof( CSPBQ00200OutBlock2 ) )
		{
			int nCol = 0;
			m_ctrlOutBlock2.InsertItem( 0, "" );
			m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock2.RecCnt                 , sizeof( pAllOutBlock->outBlock2.RecCnt                  ), DATA_TYPE_LONG   ) );    // [long  ,    5] ���ڵ尹��                     
			m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock2.AcntNm                 , sizeof( pAllOutBlock->outBlock2.AcntNm                  ), DATA_TYPE_STRING ) );    // [string,   40] ���¸�                         
			m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock2.IsuNm                  , sizeof( pAllOutBlock->outBlock2.IsuNm                   ), DATA_TYPE_STRING ) );    // [string,   40] �����                         
			m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock2.Dps                    , sizeof( pAllOutBlock->outBlock2.Dps                     ), DATA_TYPE_LONG   ) );    // [long  ,   16] ������                         
			m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock2.SubstAmt               , sizeof( pAllOutBlock->outBlock2.SubstAmt                ), DATA_TYPE_LONG   ) );    // [long  ,   16] ���ݾ�                       
			m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock2.CrdtPldgRuseAmt        , sizeof( pAllOutBlock->outBlock2.CrdtPldgRuseAmt         ), DATA_TYPE_LONG   ) );    // [long  ,   16] �ſ�㺸����ݾ�             
			m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock2.MnyOrdAbleAmt          , sizeof( pAllOutBlock->outBlock2.MnyOrdAbleAmt           ), DATA_TYPE_LONG   ) );    // [long  ,   16] �����ֹ����ɱݾ�               
			m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock2.SubstOrdAbleAmt        , sizeof( pAllOutBlock->outBlock2.SubstOrdAbleAmt         ), DATA_TYPE_LONG   ) );    // [long  ,   16] ����ֹ����ɱݾ�               
			m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock2.MnyMgn                 , sizeof( pAllOutBlock->outBlock2.MnyMgn                  ), DATA_TYPE_LONG   ) );    // [long  ,   16] �������űݾ�                   
			m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock2.SubstMgn               , sizeof( pAllOutBlock->outBlock2.SubstMgn                ), DATA_TYPE_LONG   ) );    // [long  ,   16] ������űݾ�                   
			m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock2.SeOrdAbleAmt           , sizeof( pAllOutBlock->outBlock2.SeOrdAbleAmt            ), DATA_TYPE_LONG   ) );    // [long  ,   16] �ŷ��ұݾ�                     
			m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock2.KdqOrdAbleAmt          , sizeof( pAllOutBlock->outBlock2.KdqOrdAbleAmt           ), DATA_TYPE_LONG   ) );    // [long  ,   16] �ڽ��ڱݾ�                     
			m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock2.PrsmptDpsD1            , sizeof( pAllOutBlock->outBlock2.PrsmptDpsD1             ), DATA_TYPE_LONG   ) );    // [long  ,   16] ����������(D+1)                
			m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock2.PrsmptDpsD2            , sizeof( pAllOutBlock->outBlock2.PrsmptDpsD2             ), DATA_TYPE_LONG   ) );    // [long  ,   16] ����������(D+2)                
			m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock2.MnyoutAbleAmt          , sizeof( pAllOutBlock->outBlock2.MnyoutAbleAmt           ), DATA_TYPE_LONG   ) );    // [long  ,   16] ��ݰ��ɱݾ�                   
			m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock2.RcvblAmt               , sizeof( pAllOutBlock->outBlock2.RcvblAmt                ), DATA_TYPE_LONG   ) );    // [long  ,   16] �̼��ݾ�                       
			m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock2.CmsnRat                , sizeof( pAllOutBlock->outBlock2.CmsnRat                 ), DATA_TYPE_DOT, 5 ) );    // [double, 15.5] ��������                       
			m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock2.AddLevyAmt             , sizeof( pAllOutBlock->outBlock2.AddLevyAmt              ), DATA_TYPE_LONG   ) );    // [long  ,   16] �߰�¡���ݾ�                   
			m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock2.RuseObjAmt             , sizeof( pAllOutBlock->outBlock2.RuseObjAmt              ), DATA_TYPE_LONG   ) );    // [long  ,   16] ������ݾ�                 
			m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock2.MnyRuseObjAmt          , sizeof( pAllOutBlock->outBlock2.MnyRuseObjAmt           ), DATA_TYPE_LONG   ) );    // [long  ,   16] ����������ݾ�             
			m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock2.FirmMgnRat             , sizeof( pAllOutBlock->outBlock2.FirmMgnRat              ), DATA_TYPE_DOT, 4 ) );    // [double,  7.4] �̿�����űݷ�                 
			m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock2.SubstRuseObjAmt        , sizeof( pAllOutBlock->outBlock2.SubstRuseObjAmt         ), DATA_TYPE_LONG   ) );    // [long  ,   16] ���������ݾ�             
			m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock2.IsuMgnRat              , sizeof( pAllOutBlock->outBlock2.IsuMgnRat               ), DATA_TYPE_DOT, 4 ) );    // [double,  7.4] �������űݷ�                   
			m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock2.AcntMgnRat             , sizeof( pAllOutBlock->outBlock2.AcntMgnRat              ), DATA_TYPE_DOT, 4 ) );    // [double,  7.4] �������űݷ�                   
			m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock2.TrdMgnrt               , sizeof( pAllOutBlock->outBlock2.TrdMgnrt                ), DATA_TYPE_DOT, 4 ) );    // [double,  7.4] �ŷ����űݷ�                   
			m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock2.Cmsn                   , sizeof( pAllOutBlock->outBlock2.Cmsn                    ), DATA_TYPE_LONG   ) );    // [long  ,   16] ������                         
			m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock2.MgnRat20pctOrdAbleAmt  , sizeof( pAllOutBlock->outBlock2.MgnRat20pctOrdAbleAmt   ), DATA_TYPE_LONG   ) );    // [long  ,   16] ���űݷ�20�ۼ�Ʈ�ֹ����ɱݾ�   
			m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock2.MgnRat20OrdAbleQty     , sizeof( pAllOutBlock->outBlock2.MgnRat20OrdAbleQty      ), DATA_TYPE_LONG   ) );    // [long  ,   16] ���űݷ�100�ۼ�Ʈ�����ֹ����ɼ�
			m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock2.MgnRat30pctOrdAbleAmt  , sizeof( pAllOutBlock->outBlock2.MgnRat30pctOrdAbleAmt   ), DATA_TYPE_LONG   ) );    // [long  ,   16] ���űݷ�30�ۼ�Ʈ�ֹ����ɱݾ�   
			m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock2.MgnRat30OrdAbleQty     , sizeof( pAllOutBlock->outBlock2.MgnRat30OrdAbleQty      ), DATA_TYPE_LONG   ) );    // [long  ,   16] ���űݷ�30�ۼ�Ʈ�ֹ����ɼ���?? 
			m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock2.MgnRat40pctOrdAbleAmt  , sizeof( pAllOutBlock->outBlock2.MgnRat40pctOrdAbleAmt   ), DATA_TYPE_LONG   ) );    // [long  ,   16] ���űݷ�40�ۼ�Ʈ�ֹ����ɱݾ�   
			m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock2.MgnRat40OrdAbleQty     , sizeof( pAllOutBlock->outBlock2.MgnRat40OrdAbleQty      ), DATA_TYPE_LONG   ) );    // [long  ,   16] ���űݷ�40�ۼ�Ʈ�ֹ����ɼ���?? 
			m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock2.MgnRat100pctOrdAbleAmt , sizeof( pAllOutBlock->outBlock2.MgnRat100pctOrdAbleAmt  ), DATA_TYPE_LONG   ) );    // [long  ,   16] ���űݷ�100�ۼ�Ʈ�ֹ����ɱݾ�  
			m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock2.MgnRat100OrdAbleQty    , sizeof( pAllOutBlock->outBlock2.MgnRat100OrdAbleQty     ), DATA_TYPE_LONG   ) );    // [long  ,   16] ���űݷ�100�ۼ�Ʈ�ֹ����ɼ���??
			m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock2.MgnRat100MnyOrdAbleAmt , sizeof( pAllOutBlock->outBlock2.MgnRat100MnyOrdAbleAmt  ), DATA_TYPE_LONG   ) );    // [long  ,   16] ���űݷ�100�ۼ�Ʈ�����ֹ����ɱ�
			m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock2.MgnRat100MnyOrdAbleQty , sizeof( pAllOutBlock->outBlock2.MgnRat100MnyOrdAbleQty  ), DATA_TYPE_LONG   ) );    // [long  ,   16] ���űݷ�100�ۼ�Ʈ�����ֹ����ɼ�
			m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock2.MgnRat20pctRuseAbleAmt , sizeof( pAllOutBlock->outBlock2.MgnRat20pctRuseAbleAmt  ), DATA_TYPE_LONG   ) );    // [long  ,   16] ���űݷ�20�ۼ�Ʈ���밡�ɱݾ� 
			m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock2.MgnRat30pctRuseAbleAmt , sizeof( pAllOutBlock->outBlock2.MgnRat30pctRuseAbleAmt  ), DATA_TYPE_LONG   ) );    // [long  ,   16] ���űݷ�30�ۼ�Ʈ���밡�ɱݾ� 
			m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock2.MgnRat40pctRuseAbleAmt , sizeof( pAllOutBlock->outBlock2.MgnRat40pctRuseAbleAmt  ), DATA_TYPE_LONG   ) );    // [long  ,   16] ���űݷ�40�ۼ�Ʈ���밡�ɱݾ� 
			m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock2.MgnRat100pctRuseAbleAmt, sizeof( pAllOutBlock->outBlock2.MgnRat100pctRuseAbleAmt ), DATA_TYPE_LONG   ) );    // [long  ,   16] ���űݷ�100�ۼ�Ʈ���밡�ɱݾ�
			m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock2.OrdAbleQty             , sizeof( pAllOutBlock->outBlock2.OrdAbleQty              ), DATA_TYPE_LONG   ) );    // [long  ,   16] �ֹ����ɼ���                   
			m_ctrlOutBlock2.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock2.OrdAbleAmt             , sizeof( pAllOutBlock->outBlock2.OrdAbleAmt              ), DATA_TYPE_LONG   ) );    // [long  ,   16] �ֹ����ɱݾ�                   
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
LRESULT CDlg_CSPBQ00200::OnXMTimeoutData( WPARAM wParam, LPARAM lParam )
{
	g_iXingAPI.ReleaseRequestData( (int)lParam );
	GetParent()->SendMessage( WMU_SET_MESSAGE, (WPARAM)"", (LPARAM)"Timeout" );		

	return 0L;
}
