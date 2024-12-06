// Dlg_t1602.cpp : implementation file
//

#include "stdafx.h"
#include "xingapi_sample.h"
#include "Dlg_t1602.h"

#include "./Packet/t1602.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlg_t1602 dialog


IMPLEMENT_DYNCREATE(CDlg_t1602, CDialog)

CDlg_t1602::CDlg_t1602(CWnd* pParent /*=NULL*/)
	: CDialog(CDlg_t1602::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlg_t1602)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CDlg_t1602::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlg_t1602)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
	DDX_Control( pDX, IDC_OUTBLOCK,  m_ctrlOutBlock  );
	DDX_Control( pDX, IDC_OUTBLOCK1, m_ctrlOutBlock1 );
}


BEGIN_MESSAGE_MAP(CDlg_t1602, CDialog)
	//{{AFX_MSG_MAP(CDlg_t1602)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
	ON_BN_CLICKED( IDC_BUTTON_REQUEST,		  OnButtonRequest	  )
	ON_BN_CLICKED( IDC_BUTTON_REQUEST_NEXT,	  OnButtonRequestNext )
	ON_MESSAGE	 ( WM_USER + XM_RECEIVE_DATA, OnXMReceiveData	  )
	ON_MESSAGE	 ( WM_USER + XM_TIMEOUT_DATA, OnXMTimeoutData	  )
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlg_t1602 message handlers

BOOL CDlg_t1602::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	InitCtrls();
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CDlg_t1602::OnButtonRequest() 
{
	RequestData( FALSE );
}

void CDlg_t1602::OnButtonRequestNext() 
{
	RequestData( TRUE );
}

//--------------------------------------------------------------------------------------
// ��Ʈ�� �ʱ�ȭ
//--------------------------------------------------------------------------------------
void CDlg_t1602::InitCtrls()
{
	int nCol;

	//-------------------------------------------------------------------------
	// InBlock : �⺻�� ����

	//-------------------------------------------------------------------------
	// OutBlock1
	nCol = 0;
	InsertColumn4List( this, IDC_OUTBLOCK, nCol++, "        ", TRUE ,   10 );    //         
	InsertColumn4List( this, IDC_OUTBLOCK, nCol++, "����    ", FALSE,   12 );    // ����    
	InsertColumn4List( this, IDC_OUTBLOCK, nCol++, "�ܱ���  ", FALSE,   12 );    // �ܱ���  
	InsertColumn4List( this, IDC_OUTBLOCK, nCol++, "�����  ", FALSE,   12 );    // �����  
	InsertColumn4List( this, IDC_OUTBLOCK, nCol++, "����    ", FALSE,   12 );    // ����    
	InsertColumn4List( this, IDC_OUTBLOCK, nCol++, "����    ", FALSE,   12 );    // ����    
	InsertColumn4List( this, IDC_OUTBLOCK, nCol++, "����    ", FALSE,   12 );    // ����    
	InsertColumn4List( this, IDC_OUTBLOCK, nCol++, "����    ", FALSE,   12 );    // ����    
	InsertColumn4List( this, IDC_OUTBLOCK, nCol++, "����    ", FALSE,   12 );    // ����    
	InsertColumn4List( this, IDC_OUTBLOCK, nCol++, "���    ", FALSE,   12 );    // ���    
	InsertColumn4List( this, IDC_OUTBLOCK, nCol++, "��Ÿ    ", FALSE,   12 );    // ��Ÿ    
	InsertColumn4List( this, IDC_OUTBLOCK, nCol++, "����    ", FALSE,   12 );    // ����    
	InsertColumn4List( this, IDC_OUTBLOCK, nCol++, "����ݵ�", FALSE,   12 );    // ����ݵ�

	//-------------------------------------------------------------------------
	// OutBlock2
	nCol = 0;
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "�ð�          ", TRUE ,    8 );    // [string,    8] �ð�                  
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "���μ��ż�    ", FALSE,   12 );    // [long  ,   12] ���μ��ż�            
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "�ܱ��μ��ż�  ", FALSE,   12 );    // [long  ,   12] �ܱ��μ��ż�          
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "�������ż�  ", FALSE,   12 );    // [long  ,   12] �������ż�          
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "���Ǽ��ż�    ", FALSE,   12 );    // [long  ,   12] ���Ǽ��ż�            
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "���ż��ż�    ", FALSE,   12 );    // [long  ,   12] ���ż��ż�            
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "������ż�    ", FALSE,   12 );    // [long  ,   12] ������ż�            
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "������ż�    ", FALSE,   12 );    // [long  ,   12] ������ż�            
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "���ݼ��ż�    ", FALSE,   12 );    // [long  ,   12] ���ݼ��ż�            
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "��ݼ��ż�    ", FALSE,   12 );    // [long  ,   12] ��ݼ��ż�            
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "��Ÿ���ż�    ", FALSE,   12 );    // [long  ,   12] ��Ÿ���ż�            
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "�������ż�    ", FALSE,   12 );    // [long  ,   12] �������ż�            
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "����ݵ���ż�", FALSE,   12 );    // [long  ,   12] ����ݵ���ż�        
}

//--------------------------------------------------------------------------------------
// ������ ��ȸ
//--------------------------------------------------------------------------------------
void CDlg_t1602::RequestData( BOOL bNext )
{
	//-----------------------------------------------------------
	t1602InBlock	pckInBlock;

	TCHAR			szTrNo[]		= "t1602";
	char			szNextKey[]		= "";

	//-----------------------------------------------------------
	// ������ ���
    CString str_market  ;		GetDlgItemText( IDC_INBLOCK_MARKET  , str_market   );    // [string,    1] ���屸��  
    CString str_upcode  ;		GetDlgItemText( IDC_INBLOCK_UPCODE  , str_upcode   );    // [string,    3] �����ڵ�  
    CString str_gubun1  ;		GetDlgItemText( IDC_INBLOCK_GUBUN1  , str_gubun1   );    // [string,    1] ��������  
    CString str_gubun2  ;		GetDlgItemText( IDC_INBLOCK_GUBUN2  , str_gubun2   );    // [string,    1] ���Ϻб���
    CString str_cts_time;		GetDlgItemText( IDC_INBLOCK_CTS_TIME, str_cts_time );    // [string,    8] CTSTIME   
    CString str_cts_idx ;		GetDlgItemText( IDC_INBLOCK_CTS_IDX , str_cts_idx  );    // [long  ,    4] CTSIDX    
    CString str_cnt     ;		GetDlgItemText( IDC_INBLOCK_CNT     , str_cnt      );    // [string,    4] ��ȸ�Ǽ�  
    CString str_gubun3  ;		GetDlgItemText( IDC_INBLOCK_GUBUN3  , str_gubun3   );    // [string,    1] ������񱸺�(C:�������)  

	//-----------------------------------------------------------
	// ������ �ʱ�ȭ
	FillMemory( &pckInBlock, sizeof( pckInBlock ), ' ' );

	//-----------------------------------------------------------
	// ������ �Է�
	SetPacketData( pckInBlock.market  , sizeof( pckInBlock.market   ), str_market  , DATA_TYPE_STRING );    // [string,    1] ���屸��  
	SetPacketData( pckInBlock.upcode  , sizeof( pckInBlock.upcode   ), str_upcode  , DATA_TYPE_STRING );    // [string,    3] �����ڵ�  
	SetPacketData( pckInBlock.gubun1  , sizeof( pckInBlock.gubun1   ), str_gubun1  , DATA_TYPE_STRING );    // [string,    1] ��������  
	SetPacketData( pckInBlock.gubun2  , sizeof( pckInBlock.gubun2   ), str_gubun2  , DATA_TYPE_STRING );    // [string,    1] ���Ϻб���
	SetPacketData( pckInBlock.cts_time, sizeof( pckInBlock.cts_time ), str_cts_time, DATA_TYPE_STRING );    // [string,    8] CTSTIME   
	SetPacketData( pckInBlock.cts_idx , sizeof( pckInBlock.cts_idx  ), str_cts_idx , DATA_TYPE_LONG   );    // [long  ,    4] CTSIDX    
	SetPacketData( pckInBlock.gubun3  , sizeof( pckInBlock.gubun3   ), str_gubun3  , DATA_TYPE_STRING );    // [string,    1] ������񱸺�(C:�������)  

	//-----------------------------------------------------------
	// ������ ����
	int nRqID = g_iXingAPI.Request( 
		GetSafeHwnd(),				// �����͸� ���� ������, XM_RECEIVE_DATA ���� �´�.
		szTrNo,						// TR ��ȣ
		&pckInBlock,				// InBlock ������
		sizeof( pckInBlock ),		// InBlock ������ ũ��
		bNext,						// ������ȸ ���� : ������ȸ�� ��쿡 �����Ѵ�.
		"",							// ������ȸ Key : Header Type�� B �� ��쿣 ���� ��ȸ�� ���� Next Key�� �־��ش�.
		30							// Timeout(��) : �ش� �ð�(��)���� �����Ͱ� ���� ������ Timeout�� �߻��Ѵ�. XM_TIMEOUT_DATA �޽����� �߻��Ѵ�.
	);

	m_ctrlOutBlock .DeleteAllItems();
	if( bNext == FALSE )
	{
		m_ctrlOutBlock1.DeleteAllItems();
	}

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
LRESULT CDlg_t1602::OnXMReceiveData( WPARAM wParam, LPARAM lParam )
{
	//-------------------------------------------------------------------------------------
	// Data�� ����
	if( wParam == REQUEST_DATA )
	{
		LPRECV_PACKET pRecvPacket = (LPRECV_PACKET)lParam;

		if( strcmp( pRecvPacket->szBlockName, "t1602OutBlock" ) == 0 )
		{
			LPt1602OutBlock pOutBlock = (LPt1602OutBlock)pRecvPacket->lpData;

			char szTemp[100] = { 0 };
			CopyMemory( szTemp, pOutBlock->cts_time, sizeof( pOutBlock->cts_time ) );
			SetDlgItemText( IDC_INBLOCK_CTS_TIME, szTemp );

			m_ctrlOutBlock.InsertItem( 0, "�������ڵ�" );
			m_ctrlOutBlock.InsertItem( 1, "�ż�" );
			m_ctrlOutBlock.InsertItem( 2, "�ŵ�" );
			m_ctrlOutBlock.InsertItem( 3, "����" );
			m_ctrlOutBlock.InsertItem( 4, "���ż�" );
			m_ctrlOutBlock.SetItemText(  0,  1, GetDispData( pOutBlock->tjjcode_08, sizeof( pOutBlock->tjjcode_08 ), DATA_TYPE_STRING ) );    // [string,    4] �����������ڵ�   
			m_ctrlOutBlock.SetItemText(  1,  1, GetDispData( pOutBlock->ms_08     , sizeof( pOutBlock->ms_08      ), DATA_TYPE_LONG   ) );    // [long  ,   12] ���θż�         
			m_ctrlOutBlock.SetItemText(  2,  1, GetDispData( pOutBlock->md_08     , sizeof( pOutBlock->md_08      ), DATA_TYPE_LONG   ) );    // [long  ,   12] ���θŵ�         
			m_ctrlOutBlock.SetItemText(  3,  1, GetDispData( pOutBlock->rate_08   , sizeof( pOutBlock->rate_08    ), DATA_TYPE_LONG   ) );    // [long  ,   12] ��������         
			m_ctrlOutBlock.SetItemText(  4,  1, GetDispData( pOutBlock->svolume_08, sizeof( pOutBlock->svolume_08 ), DATA_TYPE_LONG   ) );    // [long  ,   12] ���μ��ż�       
			m_ctrlOutBlock.SetItemText(  0,  2, GetDispData( pOutBlock->tjjcode_17, sizeof( pOutBlock->tjjcode_17 ), DATA_TYPE_STRING ) );    // [string,    4] �ܱ����������ڵ� 
			m_ctrlOutBlock.SetItemText(  1,  2, GetDispData( pOutBlock->ms_17     , sizeof( pOutBlock->ms_17      ), DATA_TYPE_LONG   ) );    // [long  ,   12] �ܱ��θż�       
			m_ctrlOutBlock.SetItemText(  2,  2, GetDispData( pOutBlock->md_17     , sizeof( pOutBlock->md_17      ), DATA_TYPE_LONG   ) );    // [long  ,   12] �ܱ��θŵ�       
			m_ctrlOutBlock.SetItemText(  3,  2, GetDispData( pOutBlock->rate_17   , sizeof( pOutBlock->rate_17    ), DATA_TYPE_LONG   ) );    // [long  ,   12] �ܱ�������       
			m_ctrlOutBlock.SetItemText(  4,  2, GetDispData( pOutBlock->svolume_17, sizeof( pOutBlock->svolume_17 ), DATA_TYPE_LONG   ) );    // [long  ,   12] �ܱ��μ��ż�     
			m_ctrlOutBlock.SetItemText(  0,  3, GetDispData( pOutBlock->tjjcode_18, sizeof( pOutBlock->tjjcode_18 ), DATA_TYPE_STRING ) );    // [string,    4] ������������ڵ� 
			m_ctrlOutBlock.SetItemText(  1,  3, GetDispData( pOutBlock->ms_18     , sizeof( pOutBlock->ms_18      ), DATA_TYPE_LONG   ) );    // [long  ,   12] �����ż�       
			m_ctrlOutBlock.SetItemText(  2,  3, GetDispData( pOutBlock->md_18     , sizeof( pOutBlock->md_18      ), DATA_TYPE_LONG   ) );    // [long  ,   12] �����ŵ�       
			m_ctrlOutBlock.SetItemText(  3,  3, GetDispData( pOutBlock->rate_18   , sizeof( pOutBlock->rate_18    ), DATA_TYPE_LONG   ) );    // [long  ,   12] ���������       
			m_ctrlOutBlock.SetItemText(  4,  3, GetDispData( pOutBlock->svolume_18, sizeof( pOutBlock->svolume_18 ), DATA_TYPE_LONG   ) );    // [long  ,   12] �������ż�     
			m_ctrlOutBlock.SetItemText(  0,  4, GetDispData( pOutBlock->tjjcode_01, sizeof( pOutBlock->tjjcode_01 ), DATA_TYPE_STRING ) );    // [string,    4] �����������ڵ�   
			m_ctrlOutBlock.SetItemText(  1,  4, GetDispData( pOutBlock->ms_01     , sizeof( pOutBlock->ms_01      ), DATA_TYPE_LONG   ) );    // [long  ,   12] ���Ǹż�         
			m_ctrlOutBlock.SetItemText(  2,  4, GetDispData( pOutBlock->md_01     , sizeof( pOutBlock->md_01      ), DATA_TYPE_LONG   ) );    // [long  ,   12] ���Ǹŵ�         
			m_ctrlOutBlock.SetItemText(  3,  4, GetDispData( pOutBlock->rate_01   , sizeof( pOutBlock->rate_01    ), DATA_TYPE_LONG   ) );    // [long  ,   12] ��������         
			m_ctrlOutBlock.SetItemText(  4,  4, GetDispData( pOutBlock->svolume_01, sizeof( pOutBlock->svolume_01 ), DATA_TYPE_LONG   ) );    // [long  ,   12] ���Ǽ��ż�       
			m_ctrlOutBlock.SetItemText(  0,  5, GetDispData( pOutBlock->tjjcode_03, sizeof( pOutBlock->tjjcode_03 ), DATA_TYPE_STRING ) );    // [string,    4] �����������ڵ�   
			m_ctrlOutBlock.SetItemText(  1,  5, GetDispData( pOutBlock->ms_03     , sizeof( pOutBlock->ms_03      ), DATA_TYPE_LONG   ) );    // [long  ,   12] ���Ÿż�         
			m_ctrlOutBlock.SetItemText(  2,  5, GetDispData( pOutBlock->md_03     , sizeof( pOutBlock->md_03      ), DATA_TYPE_LONG   ) );    // [long  ,   12] ���Ÿŵ�         
			m_ctrlOutBlock.SetItemText(  3,  5, GetDispData( pOutBlock->rate_03   , sizeof( pOutBlock->rate_03    ), DATA_TYPE_LONG   ) );    // [long  ,   12] ��������         
			m_ctrlOutBlock.SetItemText(  4,  5, GetDispData( pOutBlock->svolume_03, sizeof( pOutBlock->svolume_03 ), DATA_TYPE_LONG   ) );    // [long  ,   12] ���ż��ż�       
			m_ctrlOutBlock.SetItemText(  0,  6, GetDispData( pOutBlock->tjjcode_04, sizeof( pOutBlock->tjjcode_04 ), DATA_TYPE_STRING ) );    // [string,    4] �����������ڵ�   
			m_ctrlOutBlock.SetItemText(  1,  6, GetDispData( pOutBlock->ms_04     , sizeof( pOutBlock->ms_04      ), DATA_TYPE_LONG   ) );    // [long  ,   12] ����ż�         
			m_ctrlOutBlock.SetItemText(  2,  6, GetDispData( pOutBlock->md_04     , sizeof( pOutBlock->md_04      ), DATA_TYPE_LONG   ) );    // [long  ,   12] ����ŵ�         
			m_ctrlOutBlock.SetItemText(  3,  6, GetDispData( pOutBlock->rate_04   , sizeof( pOutBlock->rate_04    ), DATA_TYPE_LONG   ) );    // [long  ,   12] ��������         
			m_ctrlOutBlock.SetItemText(  4,  6, GetDispData( pOutBlock->svolume_04, sizeof( pOutBlock->svolume_04 ), DATA_TYPE_LONG   ) );    // [long  ,   12] ������ż�       
			m_ctrlOutBlock.SetItemText(  0,  7, GetDispData( pOutBlock->tjjcode_02, sizeof( pOutBlock->tjjcode_02 ), DATA_TYPE_STRING ) );    // [string,    4] �����������ڵ�   
			m_ctrlOutBlock.SetItemText(  1,  7, GetDispData( pOutBlock->ms_02     , sizeof( pOutBlock->ms_02      ), DATA_TYPE_LONG   ) );    // [long  ,   12] ����ż�         
			m_ctrlOutBlock.SetItemText(  2,  7, GetDispData( pOutBlock->md_02     , sizeof( pOutBlock->md_02      ), DATA_TYPE_LONG   ) );    // [long  ,   12] ����ŵ�         
			m_ctrlOutBlock.SetItemText(  3,  7, GetDispData( pOutBlock->rate_02   , sizeof( pOutBlock->rate_02    ), DATA_TYPE_LONG   ) );    // [long  ,   12] ��������         
			m_ctrlOutBlock.SetItemText(  4,  7, GetDispData( pOutBlock->svolume_02, sizeof( pOutBlock->svolume_02 ), DATA_TYPE_LONG   ) );    // [long  ,   12] ������ż�       
			m_ctrlOutBlock.SetItemText(  0,  8, GetDispData( pOutBlock->tjjcode_05, sizeof( pOutBlock->tjjcode_05 ), DATA_TYPE_STRING ) );    // [string,    4] �����������ڵ�   
			m_ctrlOutBlock.SetItemText(  1,  8, GetDispData( pOutBlock->ms_05     , sizeof( pOutBlock->ms_05      ), DATA_TYPE_LONG   ) );    // [long  ,   12] ���ݸż�         
			m_ctrlOutBlock.SetItemText(  2,  8, GetDispData( pOutBlock->md_05     , sizeof( pOutBlock->md_05      ), DATA_TYPE_LONG   ) );    // [long  ,   12] ���ݸŵ�         
			m_ctrlOutBlock.SetItemText(  3,  8, GetDispData( pOutBlock->rate_05   , sizeof( pOutBlock->rate_05    ), DATA_TYPE_LONG   ) );    // [long  ,   12] ��������         
			m_ctrlOutBlock.SetItemText(  4,  8, GetDispData( pOutBlock->svolume_05, sizeof( pOutBlock->svolume_05 ), DATA_TYPE_LONG   ) );    // [long  ,   12] ���ݼ��ż�       
			m_ctrlOutBlock.SetItemText(  0,  9, GetDispData( pOutBlock->tjjcode_06, sizeof( pOutBlock->tjjcode_06 ), DATA_TYPE_STRING ) );    // [string,    4] ����������ڵ�   
			m_ctrlOutBlock.SetItemText(  1,  9, GetDispData( pOutBlock->ms_06     , sizeof( pOutBlock->ms_06      ), DATA_TYPE_LONG   ) );    // [long  ,   12] ��ݸż�         
			m_ctrlOutBlock.SetItemText(  2,  9, GetDispData( pOutBlock->md_06     , sizeof( pOutBlock->md_06      ), DATA_TYPE_LONG   ) );    // [long  ,   12] ��ݸŵ�         
			m_ctrlOutBlock.SetItemText(  3,  9, GetDispData( pOutBlock->rate_06   , sizeof( pOutBlock->rate_06    ), DATA_TYPE_LONG   ) );    // [long  ,   12] �������         
			m_ctrlOutBlock.SetItemText(  4,  9, GetDispData( pOutBlock->svolume_06, sizeof( pOutBlock->svolume_06 ), DATA_TYPE_LONG   ) );    // [long  ,   12] ��ݼ��ż�       
			m_ctrlOutBlock.SetItemText(  0, 10, GetDispData( pOutBlock->tjjcode_07, sizeof( pOutBlock->tjjcode_07 ), DATA_TYPE_STRING ) );    // [string,    4] ��Ÿ�������ڵ�   
			m_ctrlOutBlock.SetItemText(  1, 10, GetDispData( pOutBlock->ms_07     , sizeof( pOutBlock->ms_07      ), DATA_TYPE_LONG   ) );    // [long  ,   12] ��Ÿ�ż�         
			m_ctrlOutBlock.SetItemText(  2, 10, GetDispData( pOutBlock->md_07     , sizeof( pOutBlock->md_07      ), DATA_TYPE_LONG   ) );    // [long  ,   12] ��Ÿ�ŵ�         
			m_ctrlOutBlock.SetItemText(  3, 10, GetDispData( pOutBlock->rate_07   , sizeof( pOutBlock->rate_07    ), DATA_TYPE_LONG   ) );    // [long  ,   12] ��Ÿ����         
			m_ctrlOutBlock.SetItemText(  4, 10, GetDispData( pOutBlock->svolume_07, sizeof( pOutBlock->svolume_07 ), DATA_TYPE_LONG   ) );    // [long  ,   12] ��Ÿ���ż�       
			m_ctrlOutBlock.SetItemText(  0, 11, GetDispData( pOutBlock->tjjcode_11, sizeof( pOutBlock->tjjcode_11 ), DATA_TYPE_STRING ) );    // [string,    4] �����������ڵ�   
			m_ctrlOutBlock.SetItemText(  1, 11, GetDispData( pOutBlock->ms_11     , sizeof( pOutBlock->ms_11      ), DATA_TYPE_LONG   ) );    // [long  ,   12] �����ż�         
			m_ctrlOutBlock.SetItemText(  2, 11, GetDispData( pOutBlock->md_11     , sizeof( pOutBlock->md_11      ), DATA_TYPE_LONG   ) );    // [long  ,   12] �����ŵ�         
			m_ctrlOutBlock.SetItemText(  3, 11, GetDispData( pOutBlock->rate_11   , sizeof( pOutBlock->rate_11    ), DATA_TYPE_LONG   ) );    // [long  ,   12] ��������         
			m_ctrlOutBlock.SetItemText(  4, 11, GetDispData( pOutBlock->svolume_11, sizeof( pOutBlock->svolume_11 ), DATA_TYPE_LONG   ) );    // [long  ,   12] �������ż�       
			m_ctrlOutBlock.SetItemText(  0, 12, GetDispData( pOutBlock->tjjcode_00, sizeof( pOutBlock->tjjcode_00 ), DATA_TYPE_STRING ) );    // [string,    4] ����ݵ��ڵ�     
			m_ctrlOutBlock.SetItemText(  1, 12, GetDispData( pOutBlock->ms_00     , sizeof( pOutBlock->ms_00      ), DATA_TYPE_LONG   ) );    // [long  ,   12] ����ݵ�ż�     
			m_ctrlOutBlock.SetItemText(  2, 12, GetDispData( pOutBlock->md_00     , sizeof( pOutBlock->md_00      ), DATA_TYPE_LONG   ) );    // [long  ,   12] ����ݵ�ŵ�     
			m_ctrlOutBlock.SetItemText(  3, 12, GetDispData( pOutBlock->rate_00   , sizeof( pOutBlock->rate_00    ), DATA_TYPE_LONG   ) );    // [long  ,   12] ����ݵ�����     
			m_ctrlOutBlock.SetItemText(  4, 12, GetDispData( pOutBlock->svolume_00, sizeof( pOutBlock->svolume_00 ), DATA_TYPE_LONG   ) );    // [long  ,   12] ����ݵ���ż�   
		}
		else if( strcmp( pRecvPacket->szBlockName, "t1602OutBlock1" ) == 0 )
		{
			LPt1602OutBlock1 pOutBlock = (LPt1602OutBlock1)pRecvPacket->lpData;
			int nCount = pRecvPacket->nDataLength / sizeof( t1602OutBlock1 );

			int nCol, nRow;
			for( int i=0; i<nCount; i++ )
			{
				nCol = 0;
				nRow = m_ctrlOutBlock1.InsertItem( m_ctrlOutBlock1.GetItemCount(), "" );
				m_ctrlOutBlock1.SetItemText( nRow, nCol++, GetDispData( pOutBlock[i].time , sizeof( pOutBlock[i].time  ), DATA_TYPE_STRING ) );    // [string,    8] �ð�          
				m_ctrlOutBlock1.SetItemText( nRow, nCol++, GetDispData( pOutBlock[i].sv_08, sizeof( pOutBlock[i].sv_08 ), DATA_TYPE_LONG   ) );    // [long  ,   12] ���μ��ż�    
				m_ctrlOutBlock1.SetItemText( nRow, nCol++, GetDispData( pOutBlock[i].sv_17, sizeof( pOutBlock[i].sv_17 ), DATA_TYPE_LONG   ) );    // [long  ,   12] �ܱ��μ��ż�  
				m_ctrlOutBlock1.SetItemText( nRow, nCol++, GetDispData( pOutBlock[i].sv_18, sizeof( pOutBlock[i].sv_18 ), DATA_TYPE_LONG   ) );    // [long  ,   12] �������ż�  
				m_ctrlOutBlock1.SetItemText( nRow, nCol++, GetDispData( pOutBlock[i].sv_01, sizeof( pOutBlock[i].sv_01 ), DATA_TYPE_LONG   ) );    // [long  ,   12] ���Ǽ��ż�    
				m_ctrlOutBlock1.SetItemText( nRow, nCol++, GetDispData( pOutBlock[i].sv_03, sizeof( pOutBlock[i].sv_03 ), DATA_TYPE_LONG   ) );    // [long  ,   12] ���ż��ż�    
				m_ctrlOutBlock1.SetItemText( nRow, nCol++, GetDispData( pOutBlock[i].sv_04, sizeof( pOutBlock[i].sv_04 ), DATA_TYPE_LONG   ) );    // [long  ,   12] ������ż�    
				m_ctrlOutBlock1.SetItemText( nRow, nCol++, GetDispData( pOutBlock[i].sv_02, sizeof( pOutBlock[i].sv_02 ), DATA_TYPE_LONG   ) );    // [long  ,   12] ������ż�    
				m_ctrlOutBlock1.SetItemText( nRow, nCol++, GetDispData( pOutBlock[i].sv_05, sizeof( pOutBlock[i].sv_05 ), DATA_TYPE_LONG   ) );    // [long  ,   12] ���ݼ��ż�    
				m_ctrlOutBlock1.SetItemText( nRow, nCol++, GetDispData( pOutBlock[i].sv_06, sizeof( pOutBlock[i].sv_06 ), DATA_TYPE_LONG   ) );    // [long  ,   12] ��ݼ��ż�    
				m_ctrlOutBlock1.SetItemText( nRow, nCol++, GetDispData( pOutBlock[i].sv_07, sizeof( pOutBlock[i].sv_07 ), DATA_TYPE_LONG   ) );    // [long  ,   12] ��Ÿ���ż�    
				m_ctrlOutBlock1.SetItemText( nRow, nCol++, GetDispData( pOutBlock[i].sv_11, sizeof( pOutBlock[i].sv_11 ), DATA_TYPE_LONG   ) );    // [long  ,   12] �������ż�    
				m_ctrlOutBlock1.SetItemText( nRow, nCol++, GetDispData( pOutBlock[i].sv_00, sizeof( pOutBlock[i].sv_00 ), DATA_TYPE_LONG   ) );    // [long  ,   12] ����ݵ���ż�
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
LRESULT CDlg_t1602::OnXMTimeoutData( WPARAM wParam, LPARAM lParam )
{
	g_iXingAPI.ReleaseRequestData( (int)lParam );
	GetParent()->SendMessage( WMU_SET_MESSAGE, (WPARAM)"", (LPARAM)"Timeout" );		

	return 0L;
}
