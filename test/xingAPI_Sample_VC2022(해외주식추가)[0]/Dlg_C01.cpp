// Dlg_C01.cpp : implementation file
//

#include "stdafx.h"
#include "xingapi_sample.h"
#include "Dlg_C01.h"

#include "./Packet/C01.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlg_C01 dialog

IMPLEMENT_DYNCREATE(CDlg_C01, CDialog)

CDlg_C01::CDlg_C01(CWnd* pParent /*=NULL*/)
	: CDialog(CDlg_C01::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlg_C01)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CDlg_C01::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlg_C01)
	DDX_Control(pDX, IDC_OUTBLOCK, m_ctrlOutBlock);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlg_C01, CDialog)
	//{{AFX_MSG_MAP(CDlg_C01)
	//}}AFX_MSG_MAP
	ON_WM_DESTROY()
	ON_MESSAGE	 ( WM_USER + XM_RECEIVE_REAL_DATA,	OnXMReceiveRealData	)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlg_C01 message handlers

BOOL CDlg_C01::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// �ֹ��� ���õ� �ǽð�TR�� �Է°��� �����Ƿ� ȭ���� ���µɶ� ����Ѵ�.
	AdviseData();

	InitCtrls();
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CDlg_C01::OnDestroy() 
{
	UnadviseData();

	CDialog::OnDestroy();
}

//--------------------------------------------------------------------------------------
// ��Ʈ�� �ʱ�ȭ
//--------------------------------------------------------------------------------------
void CDlg_C01::InitCtrls()
{
	//-------------------------------------------------------------------------
	// OutBlock
	m_ctrlOutBlock.InsertColumn( 0, "�ʵ�  ", LVCFMT_LEFT, 150 );
	m_ctrlOutBlock.InsertColumn( 1, "������", LVCFMT_LEFT, 200 );

	int nRow = 0;
	m_ctrlOutBlock.InsertItem( nRow++, "�����Ϸù�ȣ"		);
	m_ctrlOutBlock.InsertItem( nRow++, "���¹�ȣ"			);
	m_ctrlOutBlock.InsertItem( nRow++, "������ID"			);
	m_ctrlOutBlock.InsertItem( nRow++, "�Ϸù�ȣ"			);
	m_ctrlOutBlock.InsertItem( nRow++, "trcode"				);
	m_ctrlOutBlock.InsertItem( nRow++, "��Ī�׷��ȣ"		);
	m_ctrlOutBlock.InsertItem( nRow++, "����ID"				);
	m_ctrlOutBlock.InsertItem( nRow++, "ȸ����ȣ"			);
	m_ctrlOutBlock.InsertItem( nRow++, "������ȣ"			);
	m_ctrlOutBlock.InsertItem( nRow++, "�ֹ���ȣ"			);
	m_ctrlOutBlock.InsertItem( nRow++, "���ֹ���ȣ"			);
	m_ctrlOutBlock.InsertItem( nRow++, "�����ڵ�"			);
	m_ctrlOutBlock.InsertItem( nRow++, "������ȣ"			);
	m_ctrlOutBlock.InsertItem( nRow++, "ü�ᰡ��"			);
	m_ctrlOutBlock.InsertItem( nRow++, "ü�����"			);
	m_ctrlOutBlock.InsertItem( nRow++, "����ID"				);
	m_ctrlOutBlock.InsertItem( nRow++, "ü������"			);
	m_ctrlOutBlock.InsertItem( nRow++, "ü��ð�"			);
	m_ctrlOutBlock.InsertItem( nRow++, "�ֱٿ�ü�ᰡ��"		);
	m_ctrlOutBlock.InsertItem( nRow++, "���ٿ�ü�ᰡ��"		);
	m_ctrlOutBlock.InsertItem( nRow++, "�ŵ�������"			);
	m_ctrlOutBlock.InsertItem( nRow++, "���¹�ȣ1"			);
	m_ctrlOutBlock.InsertItem( nRow++, "��������ȣ������"	);
	m_ctrlOutBlock.InsertItem( nRow++, "��Ź���ȣ"			);
	m_ctrlOutBlock.InsertItem( nRow++, "����ֱǰ��¹�ȣ"	);
	m_ctrlOutBlock.InsertItem( nRow++, "mem_filler"			);
	m_ctrlOutBlock.InsertItem( nRow++, "mem_accno"			);
	m_ctrlOutBlock.InsertItem( nRow++, "mem_filler1"		);
}

//--------------------------------------------------------------------------------------
// ������ Advise
//--------------------------------------------------------------------------------------
void CDlg_C01::AdviseData()
{
	TCHAR	szTrCode[]		= "C01";

	//-----------------------------------------------------------
	// ������ ����
	BOOL bSuccess = g_iXingAPI.AdviseRealData( 
		GetSafeHwnd(),				// �����͸� ���� ������, XM_RECEIVE_REAL_DATA ���� �´�.
		szTrCode,					// TR ��ȣ
		"",							// C01�� �� �����͸� �Ѱܾ� �Ѵ�.
		0							// C01�� ������ ���̴� 0�̴�.
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
void CDlg_C01::UnadviseData()
{
	TCHAR	szTrCode[]		= "C01";
	
	//-----------------------------------------------------------
	// ������ ����
	BOOL bSuccess = g_iXingAPI.UnadviseRealData( 
		GetSafeHwnd(),				// �����͸� ���� ������, XM_RECEIVE_REAL_DATA ���� �´�.
		szTrCode,					// TR ��ȣ
		"",							// C01�� �� �����͸� �Ѱܾ� �Ѵ�.
		0							// C01�� ������ ���̴� 0�̴�.
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
LRESULT CDlg_C01::OnXMReceiveRealData( WPARAM wParam, LPARAM lParam )
{
	LPRECV_REAL_PACKET pRealPacket = (LPRECV_REAL_PACKET)lParam;

	if( strcmp( pRealPacket->szTrCode, "C01" ) == 0 )
	{
		LPC01_OutBlock pOutBlock = (LPC01_OutBlock)pRealPacket->pszData;
		int nRow = 0;
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->lineseq		, sizeof( pOutBlock->lineseq             ), DATA_TYPE_LONG        ) );    // �����Ϸù�ȣ        
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->accno		, sizeof( pOutBlock->accno				 ), DATA_TYPE_STRING      ) );    // ���¹�ȣ        
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->user        , sizeof( pOutBlock->user				 ), DATA_TYPE_STRING      ) );    // ������ID        
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->seq         , sizeof( pOutBlock->seq				 ), DATA_TYPE_LONG        ) );    // �Ϸù�ȣ        
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->trcode      , sizeof( pOutBlock->trcode              ), DATA_TYPE_STRING      ) );    // trcode        
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->megrpno     , sizeof( pOutBlock->megrpno             ), DATA_TYPE_STRING      ) );    // ��Ī�׷��ȣ        
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->boardid     , sizeof( pOutBlock->boardid             ), DATA_TYPE_STRING      ) );    // ����ID        
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->memberno    , sizeof( pOutBlock->memberno            ), DATA_TYPE_STRING      ) );    // ȸ����ȣ        
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->bpno        , sizeof( pOutBlock->bpno				 ), DATA_TYPE_STRING      ) );    // ������ȣ        
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->ordno       , sizeof( pOutBlock->ordno               ), DATA_TYPE_STRING      ) );    // �ֹ���ȣ        
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->orgordno    , sizeof( pOutBlock->orgordno            ), DATA_TYPE_STRING      ) );    // ���ֹ���ȣ        
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->expcode     , sizeof( pOutBlock->expcode             ), DATA_TYPE_STRING      ) );    // �����ڵ�        
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->yakseq      , sizeof( pOutBlock->yakseq              ), DATA_TYPE_STRING      ) );    // ������ȣ        
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->cheprice    , sizeof( pOutBlock->cheprice            ), DATA_TYPE_FLOAT       ) );    // ü�ᰡ��        
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->chevol      , sizeof( pOutBlock->chevol              ), DATA_TYPE_LONG        ) );    // ü�����        
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sessionid   , sizeof( pOutBlock->sessionid           ), DATA_TYPE_STRING      ) );    // ����ID        
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->chedate     , sizeof( pOutBlock->chedate             ), DATA_TYPE_STRING      ) );    // ü������        
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->chetime     , sizeof( pOutBlock->chetime             ), DATA_TYPE_STRING      ) );    // ü��ð�        
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->spdprc1     , sizeof( pOutBlock->spdprc1             ), DATA_TYPE_FLOAT       ) );    // �ֱٿ�ü�ᰡ��
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->spdprc2     , sizeof( pOutBlock->spdprc2             ), DATA_TYPE_FLOAT       ) );    // ���ٿ�ü�ᰡ��
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->dosugb      , sizeof( pOutBlock->dosugb              ), DATA_TYPE_STRING      ) );    // �ŵ�������
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->accno1      , sizeof( pOutBlock->accno1              ), DATA_TYPE_STRING      ) );    // ���¹�ȣ1
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sihogagb    , sizeof( pOutBlock->sihogagb            ), DATA_TYPE_STRING      ) );    // ��������ȣ������
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->jakino      , sizeof( pOutBlock->jakino              ), DATA_TYPE_STRING      ) );    // ��Ź���ȣ
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->daeyong     , sizeof( pOutBlock->daeyong             ), DATA_TYPE_STRING      ) );    // ����ֱǰ��¹�ȣ
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->mem_filler  , sizeof( pOutBlock->mem_filler          ), DATA_TYPE_STRING      ) );    // mem_filler
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->mem_accno   , sizeof( pOutBlock->mem_accno           ), DATA_TYPE_STRING      ) );    // mem_accno
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->mem_filler1 , sizeof( pOutBlock->mem_filler1         ), DATA_TYPE_STRING      ) );    // mem_filler1
	}

   	return 0L;
}
