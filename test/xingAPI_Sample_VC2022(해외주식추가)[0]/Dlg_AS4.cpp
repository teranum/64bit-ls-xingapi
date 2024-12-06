// Dlg_AS4.cpp : implementation file
//

#include "stdafx.h"
#include "XingAPI_Sample.h"
#include "Dlg_AS4.h"

#include "./Packet/AS4.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlg_AS4 dialog

IMPLEMENT_DYNCREATE(CDlg_AS4, CDialog)

CDlg_AS4::CDlg_AS4(CWnd* pParent /*=NULL*/)
	: CDialog(CDlg_AS4::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlg_AS4)
	//}}AFX_DATA_INIT
}


void CDlg_AS4::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlg_AS4)
	DDX_Control(pDX, IDC_OUTBLOCK, m_ctrlOutBlock);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlg_AS4, CDialog)
	//{{AFX_MSG_MAP(CDlg_AS4)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
	ON_WM_DESTROY()
	ON_MESSAGE	 ( WM_USER + XM_RECEIVE_REAL_DATA,	OnXMReceiveRealData	)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlg_AS4 message handlers

BOOL CDlg_AS4::OnInitDialog() 
{
	CDialog::OnInitDialog();

	// �ֹ��� ���õ� �ǽð�TR�� �Է°��� �����Ƿ� ȭ���� ���µɶ� ����Ѵ�.
	AdviseData();

	InitCtrls();
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CDlg_AS4::OnDestroy()
{
	UnadviseData();

	CDialog::OnDestroy();
}

//--------------------------------------------------------------------------------------
// ��Ʈ�� �ʱ�ȭ
//--------------------------------------------------------------------------------------
void CDlg_AS4::InitCtrls()
{
	//-------------------------------------------------------------------------
	// OutBlock
	m_ctrlOutBlock.InsertColumn( 0, "�ʵ�  ", LVCFMT_LEFT, 150 );
	m_ctrlOutBlock.InsertColumn( 1, "������", LVCFMT_LEFT, 200 );

	int nRow = 0;
	m_ctrlOutBlock.InsertItem( nRow++, "�����Ϸù�ȣ              " );
	m_ctrlOutBlock.InsertItem( nRow++, "���¹�ȣ                 " );
	m_ctrlOutBlock.InsertItem( nRow++, "������ID                 " );
	m_ctrlOutBlock.InsertItem( nRow++, "�������                 " );
	m_ctrlOutBlock.InsertItem( nRow++, "�������                 " );
	m_ctrlOutBlock.InsertItem( nRow++, "���౸��                 " );
	m_ctrlOutBlock.InsertItem( nRow++, "��ȣ����                 " );
	m_ctrlOutBlock.InsertItem( nRow++, "�����������              " );
	m_ctrlOutBlock.InsertItem( nRow++, "TRCODE                 " );
	m_ctrlOutBlock.InsertItem( nRow++, "�̿���ȣ               " );
	m_ctrlOutBlock.InsertItem( nRow++, "�����ID                 " );
	m_ctrlOutBlock.InsertItem( nRow++, "���Ӹ�ü                 " );
	m_ctrlOutBlock.InsertItem( nRow++, "I/F�Ϸù�ȣ              " );
	m_ctrlOutBlock.InsertItem( nRow++, "�����Ϸù�ȣ              " );
	m_ctrlOutBlock.InsertItem( nRow++, "TR����ID                 " );
	m_ctrlOutBlock.InsertItem( nRow++, "����IP                   " );
	m_ctrlOutBlock.InsertItem( nRow++, "�缳IP                   " );
	m_ctrlOutBlock.InsertItem( nRow++, "ó��������ȣ              " );
	m_ctrlOutBlock.InsertItem( nRow++, "������ȣ                 " );
	m_ctrlOutBlock.InsertItem( nRow++, "�ܸ���ȣ                 " );
	m_ctrlOutBlock.InsertItem( nRow++, "����                 " );
	m_ctrlOutBlock.InsertItem( nRow++, "APó���ð�               " );
	m_ctrlOutBlock.InsertItem( nRow++, "�޼����ڵ�               " );
	m_ctrlOutBlock.InsertItem( nRow++, "�޼�����±���             " );
	m_ctrlOutBlock.InsertItem( nRow++, "�����û����              " );
	m_ctrlOutBlock.InsertItem( nRow++, "���Ű                   " );
	m_ctrlOutBlock.InsertItem( nRow++, "��û���ڵ尳��             " );
	m_ctrlOutBlock.InsertItem( nRow++, "���񿵿�                 " );
	m_ctrlOutBlock.InsertItem( nRow++, "���ӱ���                 " );
	m_ctrlOutBlock.InsertItem( nRow++, "����Ű��                 " );
	m_ctrlOutBlock.InsertItem( nRow++, "�����ý��۱���             " );
	m_ctrlOutBlock.InsertItem( nRow++, "�����ش�����              " );
	m_ctrlOutBlock.InsertItem( nRow++, "�����޽�������             " );
	m_ctrlOutBlock.InsertItem( nRow++, "��ȸ�߿���               " );
	m_ctrlOutBlock.InsertItem( nRow++, "I/F�̺�ƮID              " );
	m_ctrlOutBlock.InsertItem( nRow++, "I/F����                  " );
	m_ctrlOutBlock.InsertItem( nRow++, "���񿵿�                 " );
	m_ctrlOutBlock.InsertItem( nRow++, "�ֹ�ü�������ڵ�           " );
	m_ctrlOutBlock.InsertItem( nRow++, "�ֹ������ڵ�              " );
	m_ctrlOutBlock.InsertItem( nRow++, "�ֹ������ڵ�              " );
	m_ctrlOutBlock.InsertItem( nRow++, "����������ȣ              " );
	m_ctrlOutBlock.InsertItem( nRow++, "���¹�ȣ                 " );
	m_ctrlOutBlock.InsertItem( nRow++, "���¸�                  " );
	m_ctrlOutBlock.InsertItem( nRow++, "�����ȣ                  " );
	m_ctrlOutBlock.InsertItem( nRow++, "�����                  " );
	m_ctrlOutBlock.InsertItem( nRow++, "�ֹ���ȣ                  " );
	m_ctrlOutBlock.InsertItem( nRow++, "���ֹ���ȣ               " );
	m_ctrlOutBlock.InsertItem( nRow++, "ü���ȣ                 " );
	m_ctrlOutBlock.InsertItem( nRow++, "�ؿ�ü��ID               " );
	m_ctrlOutBlock.InsertItem( nRow++, "�ֹ�����                 " );
	m_ctrlOutBlock.InsertItem( nRow++, "�ֹ���                  " );
	m_ctrlOutBlock.InsertItem( nRow++, "ü�����                 " );
	m_ctrlOutBlock.InsertItem( nRow++, "ü�ᰡ                  " );
	m_ctrlOutBlock.InsertItem( nRow++, "����Ȯ�μ���              " );
	m_ctrlOutBlock.InsertItem( nRow++, "����Ȯ�ΰ�               " );
	m_ctrlOutBlock.InsertItem( nRow++, "���Ȯ�μ���              " );
	m_ctrlOutBlock.InsertItem( nRow++, "�źμ���                 " );
	m_ctrlOutBlock.InsertItem( nRow++, "�ֹ�ó�������ڵ�           " );
	m_ctrlOutBlock.InsertItem( nRow++, "�����ֹ��Ϸù�ȣ           " );
	m_ctrlOutBlock.InsertItem( nRow++, "�ֹ�����                 " );
	m_ctrlOutBlock.InsertItem( nRow++, "ȣ�������ڵ�              " );
	m_ctrlOutBlock.InsertItem( nRow++, "���������ȣ              " );
	m_ctrlOutBlock.InsertItem( nRow++, "������ù�ȣ              " );
	m_ctrlOutBlock.InsertItem( nRow++, "��ü�����(�ֹ�)           " );
	m_ctrlOutBlock.InsertItem( nRow++, "���ֹ���ü�����           " );
	m_ctrlOutBlock.InsertItem( nRow++, "���ֹ���������             " );
	m_ctrlOutBlock.InsertItem( nRow++, "���ֹ���Ҽ���             " );
	m_ctrlOutBlock.InsertItem( nRow++, "�ֹ����ü�ᰡ             " );
	m_ctrlOutBlock.InsertItem( nRow++, "�ֹ��ݾ�                 " );
	m_ctrlOutBlock.InsertItem( nRow++, "ǥ�������ȣ              " );
	m_ctrlOutBlock.InsertItem( nRow++, "�Ÿű���                 " );
	m_ctrlOutBlock.InsertItem( nRow++, "��Ÿ�ü�ڵ�              " );
	m_ctrlOutBlock.InsertItem( nRow++, "�ֹ����¹�ȣ              " );
	m_ctrlOutBlock.InsertItem( nRow++, "����������ȣ              " );
	m_ctrlOutBlock.InsertItem( nRow++, "��Ͻ����ڵ�              " );
	m_ctrlOutBlock.InsertItem( nRow++, "�������űݷ�              " );
	m_ctrlOutBlock.InsertItem( nRow++, "������űݷ�              " );
	m_ctrlOutBlock.InsertItem( nRow++, "����ü��ݾ�              " );
	m_ctrlOutBlock.InsertItem( nRow++, "���ü��ݾ�              " );
	m_ctrlOutBlock.InsertItem( nRow++, "������ü��ݾ�             " );
	m_ctrlOutBlock.InsertItem( nRow++, "��������ü��ݾ�           " );
	m_ctrlOutBlock.InsertItem( nRow++, "��������ü��ݾ�          " );
	m_ctrlOutBlock.InsertItem( nRow++, "�ǹ�ü�����              " );
	m_ctrlOutBlock.InsertItem( nRow++, "���ŵ�ü�����             " );
	m_ctrlOutBlock.InsertItem( nRow++, "�����ڵ�                 " );
	m_ctrlOutBlock.InsertItem( nRow++, "�׷�ID                  " );
	m_ctrlOutBlock.InsertItem( nRow++, "�ֹ�ȸ��                 " );
	m_ctrlOutBlock.InsertItem( nRow++, "�ֹ���ID                " );
	m_ctrlOutBlock.InsertItem( nRow++, "ü��ð�                 " );
	m_ctrlOutBlock.InsertItem( nRow++, "�ŷ��Ҽ���ü��ð�          " );
	m_ctrlOutBlock.InsertItem( nRow++, "�źλ���                 " );
	m_ctrlOutBlock.InsertItem( nRow++, "�ܰ����                 " );
	m_ctrlOutBlock.InsertItem( nRow++, "�ǹ��ֹ����ɼ���           " );
	m_ctrlOutBlock.InsertItem( nRow++, "�ֹ������������          " );
	m_ctrlOutBlock.InsertItem( nRow++, "��������                 " );
	m_ctrlOutBlock.InsertItem( nRow++, "�ܰ����(D2)             " );
	m_ctrlOutBlock.InsertItem( nRow++, "�ŵ��ֹ����ɼ���           " );
	m_ctrlOutBlock.InsertItem( nRow++, "��ü��ŵ��ֹ�����          " );
	m_ctrlOutBlock.InsertItem( nRow++, "��ո��԰�               " );
	m_ctrlOutBlock.InsertItem( nRow++, "���Աݾ�                 " );
	m_ctrlOutBlock.InsertItem( nRow++, "������                  " );
	m_ctrlOutBlock.InsertItem( nRow++, "����                   " );
	m_ctrlOutBlock.InsertItem( nRow++, "��Ź�������űݾ�           " );
	m_ctrlOutBlock.InsertItem( nRow++, "��Ź������űݾ�           " );
	m_ctrlOutBlock.InsertItem( nRow++, "�ֹ���������              " );
	m_ctrlOutBlock.InsertItem( nRow++, "�ֹ����ɴ��ݾ�           " );
	m_ctrlOutBlock.InsertItem( nRow++, "���밡�ɱݾ�             " );
	m_ctrlOutBlock.InsertItem( nRow++, "�ſ�ŷ��ڵ�               " );
}

//--------------------------------------------------------------------------------------
// ������ Advise
//--------------------------------------------------------------------------------------
void CDlg_AS4::AdviseData()
{
	TCHAR	szTrCode[]		= "AS4";

	//-----------------------------------------------------------
	// ������ ����
	BOOL bSuccess = g_iXingAPI.AdviseRealData( 
		GetSafeHwnd(),				// �����͸� ���� ������, XM_RECEIVE_REAL_DATA ���� �´�.
		szTrCode,					// TR ��ȣ
		"",							// AS4�� �� �����͸� �Ѱܾ� �Ѵ�.
		0							// AS4�� ������ ���̴� 0�̴�.
		);

	//-----------------------------------------------------------
	// ����üũ
	if( bSuccess == FALSE )
	{
		MessageBox( "��ȸ����", "����", MB_ICONSTOP );
	}
}

//--------------------------------------------------------------------------------------
// ������ Unadvise
//--------------------------------------------------------------------------------------
void CDlg_AS4::UnadviseData()
{
	TCHAR	szTrCode[]		= "AS4";
	
	//-----------------------------------------------------------
	// ������ ����
	BOOL bSuccess = g_iXingAPI.UnadviseRealData( 
		GetSafeHwnd(),				// �����͸� ���� ������, XM_RECEIVE_REAL_DATA ���� �´�.
		szTrCode,					// TR ��ȣ
		"",							// AS4�� �� �����͸� �Ѱܾ� �Ѵ�.
		0							// AS4�� ������ ���̴� 0�̴�.
		);
	
	//-----------------------------------------------------------
	// ����üũ
	if( bSuccess == FALSE )
	{
		MessageBox( "��ȸ����", "����", MB_ICONSTOP );
	}
}

//--------------------------------------------------------------------------------------
// �����͸� ����
//--------------------------------------------------------------------------------------
LRESULT CDlg_AS4::OnXMReceiveRealData( WPARAM wParam, LPARAM lParam )
{
	LPRECV_REAL_PACKET pRealPacket = (LPRECV_REAL_PACKET)lParam;

	if( strcmp( pRealPacket->szTrCode, "AS4" ) == 0 )
	{
		LPAS4_OutBlock pOutBlock = (LPAS4_OutBlock)pRealPacket->pszData;
		int nRow = 0;
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->lineseq              , sizeof( pOutBlock->lineseq              ), DATA_TYPE_LONG     ) );    // [long  ,   10] �����Ϸù�ȣ       
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->accno                , sizeof( pOutBlock->accno                ), DATA_TYPE_STRING   ) );    // [string,   11] ���¹�ȣ          
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->user                 , sizeof( pOutBlock->user                 ), DATA_TYPE_STRING   ) );    // [string,    8] ������ID         
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->len                  , sizeof( pOutBlock->len                  ), DATA_TYPE_LONG     ) );    // [long  ,    6] �������          
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->gubun                , sizeof( pOutBlock->gubun                ), DATA_TYPE_STRING   ) );    // [string,    1] �������          
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->compress             , sizeof( pOutBlock->compress             ), DATA_TYPE_STRING   ) );    // [string,    1] ���౸��          
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->encrypt              , sizeof( pOutBlock->encrypt              ), DATA_TYPE_STRING   ) );    // [string,    1] ��ȣ����          
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->offset               , sizeof( pOutBlock->offset               ), DATA_TYPE_LONG     ) );    // [long  ,    3] �����������       
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->trcode               , sizeof( pOutBlock->trcode               ), DATA_TYPE_STRING   ) );    // [string,    8] TRCODE         
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->comid                , sizeof( pOutBlock->comid                ), DATA_TYPE_STRING   ) );    // [string,    3] �̿���ȣ        
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->userid               , sizeof( pOutBlock->userid               ), DATA_TYPE_STRING   ) );    // [string,   16] �����ID         
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->media                , sizeof( pOutBlock->media                ), DATA_TYPE_STRING   ) );    // [string,    2] ���Ӹ�ü          
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->ifid                 , sizeof( pOutBlock->ifid                 ), DATA_TYPE_STRING   ) );    // [string,    3] I/F�Ϸù�ȣ       
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->seq                  , sizeof( pOutBlock->seq                  ), DATA_TYPE_STRING   ) );    // [string,    9] �����Ϸù�ȣ       
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->trid                 , sizeof( pOutBlock->trid                 ), DATA_TYPE_STRING   ) );    // [string,   16] TR����ID         
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->pubip                , sizeof( pOutBlock->pubip                ), DATA_TYPE_STRING   ) );    // [string,   12] ����IP           
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->prvip                , sizeof( pOutBlock->prvip                ), DATA_TYPE_STRING   ) );    // [string,   12] �缳IP           
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->pcbpno               , sizeof( pOutBlock->pcbpno               ), DATA_TYPE_STRING   ) );    // [string,    3] ó��������ȣ       
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->bpno                 , sizeof( pOutBlock->bpno                 ), DATA_TYPE_STRING   ) );    // [string,    3] ������ȣ          
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->termno               , sizeof( pOutBlock->termno               ), DATA_TYPE_STRING   ) );    // [string,    8] �ܸ���ȣ          
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->lang                 , sizeof( pOutBlock->lang                 ), DATA_TYPE_STRING   ) );    // [string,    1] ����          
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->proctm               , sizeof( pOutBlock->proctm               ), DATA_TYPE_LONG     ) );    // [long  ,    9] APó���ð�        
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->msgcode              , sizeof( pOutBlock->msgcode              ), DATA_TYPE_STRING   ) );    // [string,    4] �޼����ڵ�        
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->outgu                , sizeof( pOutBlock->outgu                ), DATA_TYPE_STRING   ) );    // [string,    1] �޼�����±���      
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->compreq              , sizeof( pOutBlock->compreq              ), DATA_TYPE_STRING   ) );    // [string,    1] �����û����       
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->funckey              , sizeof( pOutBlock->funckey              ), DATA_TYPE_STRING   ) );    // [string,    4] ���Ű           
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->reqcnt               , sizeof( pOutBlock->reqcnt               ), DATA_TYPE_LONG     ) );    // [long  ,    4] ��û���ڵ尳��      
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->filler               , sizeof( pOutBlock->filler               ), DATA_TYPE_STRING   ) );    // [string,    6] ���񿵿�          
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->cont                 , sizeof( pOutBlock->cont                 ), DATA_TYPE_STRING   ) );    // [string,    1] ���ӱ���          
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->contkey              , sizeof( pOutBlock->contkey              ), DATA_TYPE_STRING   ) );    // [string,   18] ����Ű��          
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->varlen               , sizeof( pOutBlock->varlen               ), DATA_TYPE_LONG     ) );    // [long  ,    2] �����ý��۱���      
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->varhdlen             , sizeof( pOutBlock->varhdlen             ), DATA_TYPE_LONG     ) );    // [long  ,    2] �����ش�����       
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->varmsglen            , sizeof( pOutBlock->varmsglen            ), DATA_TYPE_LONG     ) );    // [long  ,    2] �����޽�������      
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->trsrc                , sizeof( pOutBlock->trsrc                ), DATA_TYPE_STRING   ) );    // [string,    1] ��ȸ�߿���        
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->eventid              , sizeof( pOutBlock->eventid              ), DATA_TYPE_STRING   ) );    // [string,    4] I/F�̺�ƮID      
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->ifinfo               , sizeof( pOutBlock->ifinfo               ), DATA_TYPE_STRING   ) );    // [string,    4] I/F����          
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->filler1              , sizeof( pOutBlock->filler1              ), DATA_TYPE_STRING   ) );    // [string,   41] ���񿵿�          
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sOrdxctPtnCode       , sizeof( pOutBlock->sOrdxctPtnCode       ), DATA_TYPE_STRING   ) );    // [string,    2] �ֹ�ü�������ڵ�    
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sOrdMktCode          , sizeof( pOutBlock->sOrdMktCode          ), DATA_TYPE_STRING   ) );    // [string,    2] �ֹ������ڵ�       
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sOrdPtnCode          , sizeof( pOutBlock->sOrdPtnCode          ), DATA_TYPE_STRING   ) );    // [string,    2] �ֹ������ڵ�       
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sMgmtBrnNo           , sizeof( pOutBlock->sMgmtBrnNo           ), DATA_TYPE_STRING   ) );    // [string,    3] ����������ȣ       
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sAcntNo              , sizeof( pOutBlock->sAcntNo              ), DATA_TYPE_STRING   ) );    // [string,   20] ���¹�ȣ          
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sAcntNm              , sizeof( pOutBlock->sAcntNm              ), DATA_TYPE_STRING   ) );    // [string,   40] ���¸�           
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sIsuNo               , sizeof( pOutBlock->sIsuNo               ), DATA_TYPE_STRING   ) );    // [string,   12] �����ȣ          
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sIsuNm               , sizeof( pOutBlock->sIsuNm               ), DATA_TYPE_STRING   ) );    // [string,   40] �����           
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sOrdNo               , sizeof( pOutBlock->sOrdNo               ), DATA_TYPE_STRING   ) );    // [long  ,   10] �ֹ���ȣ          
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sOrgOrdNo            , sizeof( pOutBlock->sOrgOrdNo            ), DATA_TYPE_LONG     ) );    // [long  ,   10] ���ֹ���ȣ        
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sExecNO              , sizeof( pOutBlock->sExecNO              ), DATA_TYPE_LONG     ) );    // [long  ,   10] ü���ȣ          
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sAbrdExecId          , sizeof( pOutBlock->sAbrdExecId          ), DATA_TYPE_LONG     ) );    // [long  ,   18] �ؿ�ü��ID        
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sOrdQty              , sizeof( pOutBlock->sOrdQty              ), DATA_TYPE_LONG     ) );    // [long  ,   16] �ֹ�����          
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sOrdPrc              , sizeof( pOutBlock->sOrdPrc              ), DATA_TYPE_LONG     ) );    // [long  ,   13] �ֹ���           
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sExecQty             , sizeof( pOutBlock->sExecQty             ), DATA_TYPE_LONG     ) );    // [long  ,   16] ü�����          
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sExecPrc             , sizeof( pOutBlock->sExecPrc             ), DATA_TYPE_LONG     ) );    // [long  ,   13] ü�ᰡ           
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sMdfyCnfQty          , sizeof( pOutBlock->sMdfyCnfQty          ), DATA_TYPE_LONG     ) );    // [long  ,   16] ����Ȯ�μ���       
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sMdfyCnfPrc          , sizeof( pOutBlock->sMdfyCnfPrc          ), DATA_TYPE_LONG     ) );    // [long  ,   16] ����Ȯ�ΰ�        
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sCancCnfQty          , sizeof( pOutBlock->sCancCnfQty          ), DATA_TYPE_LONG     ) );    // [long  ,   16] ���Ȯ�μ���       
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sRjtQty              , sizeof( pOutBlock->sRjtQty              ), DATA_TYPE_LONG     ) );    // [long  ,   16] �źμ���          
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sOrdTrxPtnCode       , sizeof( pOutBlock->sOrdTrxPtnCode       ), DATA_TYPE_LONG     ) );    // [long  ,    4] �ֹ�ó�������ڵ�    
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sMtiordSeqno         , sizeof( pOutBlock->sMtiordSeqno         ), DATA_TYPE_LONG     ) );    // [long  ,   10] �����ֹ��Ϸù�ȣ    
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sOrdCndi             , sizeof( pOutBlock->sOrdCndi             ), DATA_TYPE_LONG     ) );    // [string,    1] �ֹ�����          
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sOrdprcPtnCode       , sizeof( pOutBlock->sOrdprcPtnCode       ), DATA_TYPE_LONG     ) );    // [string,    2] ȣ�������ڵ�       
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sShtnIsuNo           , sizeof( pOutBlock->sShtnIsuNo           ), DATA_TYPE_STRING   ) );    // [long  ,    9] ���������ȣ       
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sOpDrtnNo            , sizeof( pOutBlock->sOpDrtnNo            ), DATA_TYPE_STRING   ) );    // [string,   12] ������ù�ȣ       
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sUnercQty            , sizeof( pOutBlock->sUnercQty            ), DATA_TYPE_LONG     ) );    // [string,   16] ��ü�����(�ֹ�)    
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sOrgOrdUnercQty      , sizeof( pOutBlock->sOrgOrdUnercQty      ), DATA_TYPE_STRING   ) );    // [string,   16] ���ֹ���ü�����    
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sOrgOrdMdfyQty       , sizeof( pOutBlock->sOrgOrdMdfyQty       ), DATA_TYPE_STRING   ) );    // [long  ,   16] ���ֹ���������      
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sOrgOrdCancQty       , sizeof( pOutBlock->sOrgOrdCancQty       ), DATA_TYPE_STRING   ) );    // [long  ,   16] ���ֹ���Ҽ���      
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sOrdAvrExecPrc       , sizeof( pOutBlock->sOrdAvrExecPrc       ), DATA_TYPE_LONG     ) );    // [long  ,   13] �ֹ����ü�ᰡ      
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sOrdAmt              , sizeof( pOutBlock->sOrdAmt              ), DATA_TYPE_LONG     ) );    // [long  ,   16] �ֹ��ݾ�          
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sStdIsuNo            , sizeof( pOutBlock->sStdIsuNo            ), DATA_TYPE_LONG     ) );    // [long  ,   12] ǥ�������ȣ       
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sBnsTp               , sizeof( pOutBlock->sBnsTp               ), DATA_TYPE_LONG     ) );    // [long  ,    1] �Ÿű���          
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sCommdaCode          , sizeof( pOutBlock->sCommdaCode          ), DATA_TYPE_LONG     ) );    // [string,    2] ��Ÿ�ü�ڵ�       
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sOrdAcntNo           , sizeof( pOutBlock->sOrdAcntNo           ), DATA_TYPE_LONG     ) );    // [string,   20] �ֹ����¹�ȣ       
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sAgrgtBrnNo          , sizeof( pOutBlock->sAgrgtBrnNo          ), DATA_TYPE_STRING   ) );    // [string,    3] ����������ȣ       
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sRegMktCode          , sizeof( pOutBlock->sRegMktCode          ), DATA_TYPE_STRING   ) );    // [string,    2] ��Ͻ����ڵ�       
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sMnyMgnRat           , sizeof( pOutBlock->sMnyMgnRat           ), DATA_TYPE_STRING   ) );    // [string,    7] �������űݷ�       
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sSubstMgnRat         , sizeof( pOutBlock->sSubstMgnRat         ), DATA_TYPE_STRING   ) );    // [string,    9] ������űݷ�       
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sMnyExecAmt          , sizeof( pOutBlock->sMnyExecAmt          ), DATA_TYPE_STRING   ) );    // [string,   16] ����ü��ݾ�       
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sSubstExecAmt        , sizeof( pOutBlock->sSubstExecAmt        ), DATA_TYPE_STRING   ) );    // [string,   16] ���ü��ݾ�       
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sCmsnAmtExecAmt      , sizeof( pOutBlock->sCmsnAmtExecAmt      ), DATA_TYPE_STRING   ) );    // [long  ,   16] ������ü��ݾ�      
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sPrdayRuseExecVal    , sizeof( pOutBlock->sPrdayRuseExecVal    ), DATA_TYPE_STRING   ) );    // [string,   16] ��������ü��ݾ�   
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sCrdayRuseExecVal    , sizeof( pOutBlock->sCrdayRuseExecVal    ), DATA_TYPE_LONG     ) );    // [string,   16] ��������ü��ݾ�   
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sSpotExecQty         , sizeof( pOutBlock->sSpotExecQty         ), DATA_TYPE_STRING   ) );    // [string,   16] �ǹ�ü�����       
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sStslExecQty         , sizeof( pOutBlock->sStslExecQty         ), DATA_TYPE_STRING   ) );    // [string,   16] ���ŵ�ü�����      
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sStrtgCode           , sizeof( pOutBlock->sStrtgCode           ), DATA_TYPE_STRING   ) );    // [string,    6] �����ڵ�          
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sGrpId               , sizeof( pOutBlock->sGrpId               ), DATA_TYPE_STRING   ) );    // [string,   20] �׷�ID           
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sOrdSeqno            , sizeof( pOutBlock->sOrdSeqno            ), DATA_TYPE_STRING   ) );    // [string,   10] �ֹ�ȸ��          
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sOrdUserId           , sizeof( pOutBlock->sOrdUserId           ), DATA_TYPE_STRING   ) );    // [long  ,   16] �ֹ���ID         
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sExecTime            , sizeof( pOutBlock->sExecTime            ), DATA_TYPE_STRING   ) );    // [long  ,    9] ü��ð�          
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sRcptExecTime        , sizeof( pOutBlock->sRcptExecTime        ), DATA_TYPE_LONG     ) );    // [long  ,    9] �ŷ��Ҽ���ü��ð�   
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sRjtRsn              , sizeof( pOutBlock->sRjtRsn              ), DATA_TYPE_LONG     ) );    // [long  ,    8] �źλ���          
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sSecBalQty           , sizeof( pOutBlock->sSecBalQty           ), DATA_TYPE_LONG     ) );    // [long  ,   16] �ܰ����          
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sSpotOrdAbleQty      , sizeof( pOutBlock->sSpotOrdAbleQty      ), DATA_TYPE_LONG     ) );    // [long  ,   16] �ǹ��ֹ����ɼ���    
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sOrdAbleRuseQty      , sizeof( pOutBlock->sOrdAbleRuseQty      ), DATA_TYPE_LONG     ) );    // [long  ,   16] �ֹ������������   
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sFlctQty             , sizeof( pOutBlock->sFlctQty             ), DATA_TYPE_LONG     ) );    // [long  ,   16] ��������          
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sSecBalQtyD2         , sizeof( pOutBlock->sSecBalQtyD2         ), DATA_TYPE_LONG     ) );    // [long  ,   16] �ܰ����(D2)      
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sSellAbleQty         , sizeof( pOutBlock->sSellAbleQty         ), DATA_TYPE_LONG     ) );    // [long  ,   16] �ŵ��ֹ����ɼ���    
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sUnercSellOrdQty     , sizeof( pOutBlock->sUnercSellOrdQty     ), DATA_TYPE_LONG     ) );    // [long  ,   16] ��ü��ŵ��ֹ�����   
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sAvrPchsPrc          , sizeof( pOutBlock->sAvrPchsPrc          ), DATA_TYPE_LONG     ) );    // [long  ,   13] ��ո��԰�        
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sPchsAmt             , sizeof( pOutBlock->sPchsAmt             ), DATA_TYPE_LONG     ) );    // [string,   16] ���Աݾ�          
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sDeposit             , sizeof( pOutBlock->sDeposit             ), DATA_TYPE_STRING   ) );    // [string,   16] ������           
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sSubstAmt            , sizeof( pOutBlock->sSubstAmt            ), DATA_TYPE_STRING   ) );    // [long  ,   16] ����           
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sCsgnMnyMgn          , sizeof( pOutBlock->sCsgnMnyMgn          ), DATA_TYPE_LONG     ) );    // [long  ,   16] ��Ź�������űݾ�    
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sCsgnSubstMgn        , sizeof( pOutBlock->sCsgnSubstMgn        ), DATA_TYPE_LONG     ) );    // [long  ,   16] ��Ź������űݾ�    
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sOrdAbleMny          , sizeof( pOutBlock->sOrdAbleMny          ), DATA_TYPE_LONG     ) );    // [long  ,   16] �ֹ���������       
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sOrdAbleSubstAmt     , sizeof( pOutBlock->sOrdAbleSubstAmt     ), DATA_TYPE_LONG     ) );    // [long  ,   16] �ֹ����ɴ��ݾ�    
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sRuseAbleAmt         , sizeof( pOutBlock->sRuseAbleAmt         ), DATA_TYPE_LONG     ) );    // [string,   16] ���밡�ɱݾ�      
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sMgntrnCode          , sizeof( pOutBlock->sMgntrnCode          ), DATA_TYPE_STRING   ) );    // [string,    3] �ſ�ŷ��ڵ�       
	} 
     
	return 0L;
}
