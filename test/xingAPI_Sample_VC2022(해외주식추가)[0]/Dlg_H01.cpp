// Dlg_H01.cpp : implementation file
//

#include "stdafx.h"
#include "xingapi_sample.h"
#include "Dlg_H01.h"

#include "./Packet/H01.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlg_H01 dialog

IMPLEMENT_DYNCREATE(CDlg_H01, CDialog)

CDlg_H01::CDlg_H01(CWnd* pParent /*=NULL*/)
	: CDialog(CDlg_H01::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlg_H01)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CDlg_H01::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlg_H01)
	DDX_Control(pDX, IDC_OUTBLOCK, m_ctrlOutBlock);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlg_H01, CDialog)
	//{{AFX_MSG_MAP(CDlg_H01)
	//}}AFX_MSG_MAP
	ON_WM_DESTROY()
	ON_MESSAGE	 ( WM_USER + XM_RECEIVE_REAL_DATA,	OnXMReceiveRealData	)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlg_H01 message handlers

BOOL CDlg_H01::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// �ֹ��� ���õ� �ǽð�TR�� �Է°��� �����Ƿ� ȭ���� ���µɶ� ����Ѵ�.
	AdviseData();

	InitCtrls();
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CDlg_H01::OnDestroy() 
{
	UnadviseData();

	CDialog::OnDestroy();
}

//--------------------------------------------------------------------------------------
// ��Ʈ�� �ʱ�ȭ
//--------------------------------------------------------------------------------------
void CDlg_H01::InitCtrls()
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
	m_ctrlOutBlock.InsertItem( nRow++, "�ŵ�������"			);
	m_ctrlOutBlock.InsertItem( nRow++, "������ұ���"		);
	m_ctrlOutBlock.InsertItem( nRow++, "���¹�ȣ1"			);
	m_ctrlOutBlock.InsertItem( nRow++, "ȣ������"			);
	m_ctrlOutBlock.InsertItem( nRow++, "ȣ������"			);
	m_ctrlOutBlock.InsertItem( nRow++, "�ֹ�����"			);
	m_ctrlOutBlock.InsertItem( nRow++, "ȣ������"			);
	m_ctrlOutBlock.InsertItem( nRow++, "��������ȣ������"	);
	m_ctrlOutBlock.InsertItem( nRow++, "�ڻ��ֽŰ�ID"		);
	m_ctrlOutBlock.InsertItem( nRow++, "�ڻ��ָŸŹ��"		);
	m_ctrlOutBlock.InsertItem( nRow++, "�ŵ������ڵ�"		);
	m_ctrlOutBlock.InsertItem( nRow++, "�ſ뱸���ڵ�"		);
	m_ctrlOutBlock.InsertItem( nRow++, "��Ź�ڱⱸ��"		);
	m_ctrlOutBlock.InsertItem( nRow++, "��Ź���ȣ"			);
	m_ctrlOutBlock.InsertItem( nRow++, "���α׷�����"		);
	m_ctrlOutBlock.InsertItem( nRow++, "����ֱǰ��¹�ȣ"	);
	m_ctrlOutBlock.InsertItem( nRow++, "���±����ڵ�"		);
	m_ctrlOutBlock.InsertItem( nRow++, "�������ű��ڵ�"		);
	m_ctrlOutBlock.InsertItem( nRow++, "�����ڵ�"			);
	m_ctrlOutBlock.InsertItem( nRow++, "�����ڱ���"			);
	m_ctrlOutBlock.InsertItem( nRow++, "�ܱ����ڵ�"			);
	m_ctrlOutBlock.InsertItem( nRow++, "�ֹ���ü����"		);
	m_ctrlOutBlock.InsertItem( nRow++, "�ֹ��ĺ��ڹ�ȣ"		);
	m_ctrlOutBlock.InsertItem( nRow++, "MAC�ּ�"			);
	m_ctrlOutBlock.InsertItem( nRow++, "ȣ������"			);
	m_ctrlOutBlock.InsertItem( nRow++, "ȸ�����ֹ��ð�"		);
	m_ctrlOutBlock.InsertItem( nRow++, "mem_filler"			);
	m_ctrlOutBlock.InsertItem( nRow++, "mem_accno"			);
	m_ctrlOutBlock.InsertItem( nRow++, "mem_filler1"		);
	m_ctrlOutBlock.InsertItem( nRow++, "��Ī�����ð�"		);
	m_ctrlOutBlock.InsertItem( nRow++, "��������Ҽ���"		);
	m_ctrlOutBlock.InsertItem( nRow++, "�ڵ���ұ���"		);
	m_ctrlOutBlock.InsertItem( nRow++, "�źλ���"			);
	m_ctrlOutBlock.InsertItem( nRow++, "���α׷�ȣ���Ű�"	);
}

//--------------------------------------------------------------------------------------
// ������ Advise
//--------------------------------------------------------------------------------------
void CDlg_H01::AdviseData()
{
	TCHAR	szTrCode[]		= "H01";

	//-----------------------------------------------------------
	// ������ ����
	BOOL bSuccess = g_iXingAPI.AdviseRealData( 
		GetSafeHwnd(),				// �����͸� ���� ������, XM_RECEIVE_REAL_DATA ���� �´�.
		szTrCode,					// TR ��ȣ
		"",							// H01�� �� �����͸� �Ѱܾ� �Ѵ�.
		0							// H01�� ������ ���̴� 0�̴�.
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
void CDlg_H01::UnadviseData()
{
	TCHAR	szTrCode[]		= "H01";
	
	//-----------------------------------------------------------
	// ������ ����
	BOOL bSuccess = g_iXingAPI.UnadviseRealData( 
		GetSafeHwnd(),				// �����͸� ���� ������, XM_RECEIVE_REAL_DATA ���� �´�.
		szTrCode,					// TR ��ȣ
		"",							// H01�� �� �����͸� �Ѱܾ� �Ѵ�.
		0							// H01�� ������ ���̴� 0�̴�.
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
LRESULT CDlg_H01::OnXMReceiveRealData( WPARAM wParam, LPARAM lParam )
{
	LPRECV_REAL_PACKET pRealPacket = (LPRECV_REAL_PACKET)lParam;

	if( strcmp( pRealPacket->szTrCode, "H01" ) == 0 )
	{
		LPH01_OutBlock pOutBlock = (LPH01_OutBlock)pRealPacket->pszData;
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
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->dosugb      , sizeof( pOutBlock->dosugb              ), DATA_TYPE_STRING      ) );    // �ŵ�������
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->mocagb      , sizeof( pOutBlock->mocagb              ), DATA_TYPE_STRING      ) );    // ������ұ���
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->accno1      , sizeof( pOutBlock->accno1              ), DATA_TYPE_STRING      ) );    // ���¹�ȣ1
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->qty2        , sizeof( pOutBlock->qty2				 ), DATA_TYPE_LONG        ) );    // ȣ������
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->price       , sizeof( pOutBlock->price				 ), DATA_TYPE_FLOAT       ) );    // ȣ������
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->ordgb       , sizeof( pOutBlock->ordgb               ), DATA_TYPE_STRING      ) );    // �ֹ�����
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->hogagb      , sizeof( pOutBlock->hogagb              ), DATA_TYPE_STRING      ) );    // ȣ������
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sihogagb    , sizeof( pOutBlock->sihogagb            ), DATA_TYPE_STRING      ) );    // ��������ȣ������
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->tradid      , sizeof( pOutBlock->tradid              ), DATA_TYPE_STRING      ) );    // �ڻ��ֽŰ�ID
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->treacode    , sizeof( pOutBlock->treacode            ), DATA_TYPE_STRING      ) );    // �ڻ��ָŸŹ��
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->askcode     , sizeof( pOutBlock->askcode             ), DATA_TYPE_STRING      ) );    // �ŵ������ڵ�
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->creditcode  , sizeof( pOutBlock->creditcode          ), DATA_TYPE_STRING      ) );    // �ſ뱸���ڵ�
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->jakigb      , sizeof( pOutBlock->jakigb              ), DATA_TYPE_STRING      ) );    // ��Ź�ڱⱸ��
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->trustnum    , sizeof( pOutBlock->trustnum            ), DATA_TYPE_STRING      ) );    // ��Ź���ȣ
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->ptgb        , sizeof( pOutBlock->ptgb				 ), DATA_TYPE_STRING      ) );    // ���α׷�����
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->substonum   , sizeof( pOutBlock->substonum           ), DATA_TYPE_STRING      ) );    // ����ֱǰ��¹�ȣ
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->accgb       , sizeof( pOutBlock->accgb				 ), DATA_TYPE_STRING      ) );    // ���±����ڵ�
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->accmarggb   , sizeof( pOutBlock->accmarggb           ), DATA_TYPE_STRING      ) );    // �������ű��ڵ�
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->nationcode  , sizeof( pOutBlock->nationcode          ), DATA_TYPE_STRING      ) );    // �����ڵ�
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->investgb    , sizeof( pOutBlock->investgb            ), DATA_TYPE_STRING      ) );    // �����ڱ���
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->forecode    , sizeof( pOutBlock->forecode            ), DATA_TYPE_STRING      ) );    // �ܱ����ڵ�
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->medcode     , sizeof( pOutBlock->medcode             ), DATA_TYPE_STRING      ) );    // �ֹ���ü����
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->ordid       , sizeof( pOutBlock->ordid				 ), DATA_TYPE_STRING      ) );    // �ֹ��ĺ��ڹ�ȣ
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->macid       , sizeof( pOutBlock->macid				 ), DATA_TYPE_STRING      ) );    // MAC�ּ�
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->orddate     , sizeof( pOutBlock->orddate             ), DATA_TYPE_STRING      ) );    // ȣ������
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->rcvtime     , sizeof( pOutBlock->rcvtime             ), DATA_TYPE_STRING      ) );    // ȸ�����ֹ��ð�
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->mem_filler  , sizeof( pOutBlock->mem_filler          ), DATA_TYPE_STRING      ) );    // mem_filler
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->mem_accno   , sizeof( pOutBlock->mem_accno           ), DATA_TYPE_STRING      ) );    // mem_accno
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->mem_filler1 , sizeof( pOutBlock->mem_filler1         ), DATA_TYPE_STRING      ) );    // mem_filler1
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->ordacpttm   , sizeof( pOutBlock->ordacpttm			 ), DATA_TYPE_STRING      ) );    // ��Ī�����ð�
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->qty         , sizeof( pOutBlock->qty				 ), DATA_TYPE_LONG	      ) );    // ��������Ҽ���
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->autogb      , sizeof( pOutBlock->autogb				 ), DATA_TYPE_STRING      ) );    // �ڵ���ұ���
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->rejcode     , sizeof( pOutBlock->rejcode			 ), DATA_TYPE_STRING      ) );    // �źλ���
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->prgordde   , sizeof( pOutBlock->prgordde			 ), DATA_TYPE_STRING      ) );    // ���α׷�ȣ���Ű�
	}

   	return 0L;
}
