// Dlg_FC0.cpp : implementation file
//

#include "stdafx.h"
#include "XingAPI_Sample.h"
#include "Dlg_FC0.h"

#include "./Packet/FC0.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlg_FC0 dialog

IMPLEMENT_DYNCREATE(CDlg_FC0, CDialog)

CDlg_FC0::CDlg_FC0(CWnd* pParent /*=NULL*/)
	: CDialog(CDlg_FC0::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlg_FC0)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CDlg_FC0::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlg_FC0)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
	DDX_Control(pDX, IDC_OUTBLOCK, m_ctrlOutBlock);
}


BEGIN_MESSAGE_MAP(CDlg_FC0, CDialog)
	//{{AFX_MSG_MAP(CDlg_FC0)
	//}}AFX_MSG_MAP
	ON_WM_DESTROY  ()
	ON_BN_CLICKED( IDC_BUTTON_REQUEST,				OnButtonRequest	    )
	ON_MESSAGE	 ( WM_USER + XM_RECEIVE_REAL_DATA,	OnXMReceiveRealData	)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlg_FC0 message handlers

BOOL CDlg_FC0::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	InitCtrls();
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CDlg_FC0::OnDestroy()
{
	UnadviseData();

	CDialog::OnDestroy();
}

void CDlg_FC0::OnButtonRequest() 
{
	UnadviseData();
	AdviseData();
}


//--------------------------------------------------------------------------------------
// ��Ʈ�� �ʱ�ȭ
//--------------------------------------------------------------------------------------
void CDlg_FC0::InitCtrls()
{
	//-------------------------------------------------------------------------
	// OutBlock
	m_ctrlOutBlock.InsertColumn( 0, "�ʵ�  ", LVCFMT_LEFT, 150 );
	m_ctrlOutBlock.InsertColumn( 1, "������", LVCFMT_LEFT, 200 );

	int nRow = 0;
	m_ctrlOutBlock.InsertItem( nRow++, "ü��ð�          " );
	m_ctrlOutBlock.InsertItem( nRow++, "���ϴ�񱸺�      " );
	m_ctrlOutBlock.InsertItem( nRow++, "���ϴ��          " );
	m_ctrlOutBlock.InsertItem( nRow++, "�����            " );
	m_ctrlOutBlock.InsertItem( nRow++, "���簡            " );
	m_ctrlOutBlock.InsertItem( nRow++, "�ð�              " );
	m_ctrlOutBlock.InsertItem( nRow++, "��              " );
	m_ctrlOutBlock.InsertItem( nRow++, "����              " );
	m_ctrlOutBlock.InsertItem( nRow++, "ü�ᱸ��          " );
	m_ctrlOutBlock.InsertItem( nRow++, "ü�ᷮ            " );
	m_ctrlOutBlock.InsertItem( nRow++, "�����ŷ���        " );
	m_ctrlOutBlock.InsertItem( nRow++, "�����ŷ����      " );
	m_ctrlOutBlock.InsertItem( nRow++, "�ŵ�����ü�ᷮ    " );
	m_ctrlOutBlock.InsertItem( nRow++, "�ŵ�����ü��Ǽ�  " );
	m_ctrlOutBlock.InsertItem( nRow++, "�ż�����ü�ᷮ    " );
	m_ctrlOutBlock.InsertItem( nRow++, "�ż�����ü��Ǽ�  " );
	m_ctrlOutBlock.InsertItem( nRow++, "ü�ᰭ��          " );
	m_ctrlOutBlock.InsertItem( nRow++, "�ŵ�ȣ��1         " );
	m_ctrlOutBlock.InsertItem( nRow++, "�ż�ȣ��1         " );
	m_ctrlOutBlock.InsertItem( nRow++, "�̰�����������    " );
	m_ctrlOutBlock.InsertItem( nRow++, "KOSPI200����      " );
	m_ctrlOutBlock.InsertItem( nRow++, "�̷а�            " );
	m_ctrlOutBlock.InsertItem( nRow++, "������            " );
	m_ctrlOutBlock.InsertItem( nRow++, "����BASIS         " );
	m_ctrlOutBlock.InsertItem( nRow++, "�̷�BASIS         " );
	m_ctrlOutBlock.InsertItem( nRow++, "�̰�����������    " );
	m_ctrlOutBlock.InsertItem( nRow++, "������        " );
	m_ctrlOutBlock.InsertItem( nRow++, "���ϵ��ð���ŷ���" );
	m_ctrlOutBlock.InsertItem( nRow++, "�����ڵ�          " );
}

//--------------------------------------------------------------------------------------
// ������ Advise
//--------------------------------------------------------------------------------------
void CDlg_FC0::AdviseData()
{
	TCHAR	szTrCode[]		= "FC0";

	//-----------------------------------------------------------
	// ������ ���
    CString strCode; GetDlgItemText( IDC_EDIT_CODE, strCode );

	//-----------------------------------------------------------
	// ������ ����
	BOOL bSuccess = g_iXingAPI.AdviseRealData( 
		GetSafeHwnd(),				// �����͸� ���� ������, XM_RECEIVE_REAL_DATA ���� �´�.
		szTrCode,					// TR ��ȣ
		strCode,					// �����ڵ�
		sizeof( FC0_InBlock )		// �����ڵ� ����
		);

	//-----------------------------------------------------------
	// ����üũ
	if( bSuccess == FALSE )
	{
		MessageBox( "��ȸ����", "����", MB_ICONSTOP );
	}
	else
	{
		m_strCode = strCode;
	}
}

//--------------------------------------------------------------------------------------
// ������ Unadvise
//--------------------------------------------------------------------------------------
void CDlg_FC0::UnadviseData()
{
	//-----------------------------------------------------------
	// ������ ����� ������ ���ٸ� Return�Ѵ�.
	if( m_strCode.IsEmpty() )
	{
		return;
	}

	TCHAR	szTrCode[]		= "FC0";
	
	//-----------------------------------------------------------
	// ������ ����
	BOOL bSuccess = g_iXingAPI.UnadviseRealData( 
		GetSafeHwnd(),				// �����͸� ���� ������, XM_RECEIVE_REAL_DATA ���� �´�.
		szTrCode,					// TR ��ȣ
		m_strCode,					// �����ڵ�
		sizeof( FC0_InBlock )		// �����ڵ� ����
		);
	
	//-----------------------------------------------------------
	// ����üũ
	if( bSuccess == FALSE )
	{
		MessageBox( "��ȸ����", "����", MB_ICONSTOP );
	}
	else
	{
		m_strCode.Empty();
	}
}

//--------------------------------------------------------------------------------------
// �����͸� ����
//--------------------------------------------------------------------------------------
LRESULT CDlg_FC0::OnXMReceiveRealData( WPARAM wParam, LPARAM lParam )
{
	LPRECV_REAL_PACKET pRealPacket = (LPRECV_REAL_PACKET)lParam;

	if( strcmp( pRealPacket->szTrCode, "FC0" ) == 0 )
	{
		LPFC0_OutBlock pOutBlock = (LPFC0_OutBlock)pRealPacket->pszData;
		int nRow = 0;
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->chetime    , sizeof( pOutBlock->chetime     ), DATA_TYPE_STRING    ) );    // ü��ð�          
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sign       , sizeof( pOutBlock->sign        ), DATA_TYPE_STRING    ) );    // ���ϴ�񱸺�      
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->change     , sizeof( pOutBlock->change      ), DATA_TYPE_FLOAT , 2 ) );    // ���ϴ��          
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->drate      , sizeof( pOutBlock->drate       ), DATA_TYPE_FLOAT , 2 ) );    // �����            
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->price      , sizeof( pOutBlock->price       ), DATA_TYPE_FLOAT , 2 ) );    // ���簡            
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->open       , sizeof( pOutBlock->open        ), DATA_TYPE_FLOAT , 2 ) );    // �ð�              
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->high       , sizeof( pOutBlock->high        ), DATA_TYPE_FLOAT , 2 ) );    // ��              
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->low        , sizeof( pOutBlock->low         ), DATA_TYPE_FLOAT , 2 ) );    // ����              
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->cgubun     , sizeof( pOutBlock->cgubun      ), DATA_TYPE_STRING    ) );    // ü�ᱸ��          
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->cvolume    , sizeof( pOutBlock->cvolume     ), DATA_TYPE_LONG      ) );    // ü�ᷮ            
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->volume     , sizeof( pOutBlock->volume      ), DATA_TYPE_LONG      ) );    // �����ŷ���        
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->value      , sizeof( pOutBlock->value       ), DATA_TYPE_LONG      ) );    // �����ŷ����      
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->mdvolume   , sizeof( pOutBlock->mdvolume    ), DATA_TYPE_LONG      ) );    // �ŵ�����ü�ᷮ    
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->mdchecnt   , sizeof( pOutBlock->mdchecnt    ), DATA_TYPE_LONG      ) );    // �ŵ�����ü��Ǽ�  
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->msvolume   , sizeof( pOutBlock->msvolume    ), DATA_TYPE_LONG      ) );    // �ż�����ü�ᷮ    
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->mschecnt   , sizeof( pOutBlock->mschecnt    ), DATA_TYPE_LONG      ) );    // �ż�����ü��Ǽ�  
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->cpower     , sizeof( pOutBlock->cpower      ), DATA_TYPE_FLOAT , 2 ) );    // ü�ᰭ��          
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->offerho1   , sizeof( pOutBlock->offerho1    ), DATA_TYPE_FLOAT , 2 ) );    // �ŵ�ȣ��1         
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->bidho1     , sizeof( pOutBlock->bidho1      ), DATA_TYPE_FLOAT , 2 ) );    // �ż�ȣ��1         
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->openyak    , sizeof( pOutBlock->openyak     ), DATA_TYPE_LONG      ) );    // �̰�����������    
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->k200jisu   , sizeof( pOutBlock->k200jisu    ), DATA_TYPE_FLOAT , 2 ) );    // KOSPI200����      
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->theoryprice, sizeof( pOutBlock->theoryprice ), DATA_TYPE_FLOAT , 2 ) );    // �̷а�            
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->kasis      , sizeof( pOutBlock->kasis       ), DATA_TYPE_FLOAT , 2 ) );    // ������            
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sbasis     , sizeof( pOutBlock->sbasis      ), DATA_TYPE_FLOAT , 2 ) );    // ����BASIS         
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->ibasis     , sizeof( pOutBlock->ibasis      ), DATA_TYPE_FLOAT , 2 ) );    // �̷�BASIS         
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->openyakcha , sizeof( pOutBlock->openyakcha  ), DATA_TYPE_LONG      ) );    // �̰�����������    
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->jgubun     , sizeof( pOutBlock->jgubun      ), DATA_TYPE_STRING    ) );    // ������        
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->jnilvolume , sizeof( pOutBlock->jnilvolume  ), DATA_TYPE_LONG      ) );    // ���ϵ��ð���ŷ���
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->futcode    , sizeof( pOutBlock->futcode     ), DATA_TYPE_STRING    ) );    // �����ڵ�          
	}

	return 0L;
}
