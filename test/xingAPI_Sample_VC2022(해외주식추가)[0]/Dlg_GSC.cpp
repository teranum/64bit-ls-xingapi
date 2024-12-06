// Dlg_GSC.cpp : implementation file
//

#include "stdafx.h"
#include "XingAPI_Sample.h"
#include "Dlg_GSC.h"

#include "./Packet/GSC.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlg_GSC dialog

IMPLEMENT_DYNCREATE(CDlg_GSC, CDialog)

CDlg_GSC::CDlg_GSC(CWnd* pParent /*=NULL*/)
	: CDialog(CDlg_GSC::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlg_GSC)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CDlg_GSC::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlg_GSC)
	DDX_Control(pDX, IDC_OUTBLOCK, m_ctrlOutBlock);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlg_GSC, CDialog)
	//{{AFX_MSG_MAP(CDlg_GSC)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
	ON_WM_DESTROY()
	ON_BN_CLICKED( IDC_BUTTON_REQUEST,				OnButtonRequest	    )
	ON_MESSAGE	 ( WM_USER + XM_RECEIVE_REAL_DATA,	OnXMReceiveRealData	)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlg_GSC message handlers

BOOL CDlg_GSC::OnInitDialog() 
{
	CDialog::OnInitDialog();

	InitCtrls();
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CDlg_GSC::OnDestroy()
{
	UnadviseData();

	CDialog::OnDestroy();
}

void CDlg_GSC::OnButtonRequest() 
{
	UnadviseData();
	AdviseData();
}

//--------------------------------------------------------------------------------------
// ��Ʈ�� �ʱ�ȭ
//--------------------------------------------------------------------------------------
void CDlg_GSC::InitCtrls()
{
	//-------------------------------------------------------------------------
	// OutBlock
	m_ctrlOutBlock.InsertColumn( 0, "�ʵ�  ", LVCFMT_LEFT, 150 );
	m_ctrlOutBlock.InsertColumn( 1, "������", LVCFMT_LEFT, 200 );

	int nRow = 0;
	m_ctrlOutBlock.InsertItem( nRow++, "�����ڵ�         " );
	m_ctrlOutBlock.InsertItem( nRow++, "ü������(����)   " );
	m_ctrlOutBlock.InsertItem( nRow++, "ü������(�ѱ�)   " );
	m_ctrlOutBlock.InsertItem( nRow++, "ü��ð�(����)   " );
	m_ctrlOutBlock.InsertItem( nRow++, "ü��ð�(�ѱ�)   " );
	m_ctrlOutBlock.InsertItem( nRow++, "���ϴ�񱸺�     " );
	m_ctrlOutBlock.InsertItem( nRow++, "ü�ᰡ��         " );
	m_ctrlOutBlock.InsertItem( nRow++, "���ϴ��         " );
	m_ctrlOutBlock.InsertItem( nRow++, "�����           " );
	m_ctrlOutBlock.InsertItem( nRow++, "�ð�             " );
	m_ctrlOutBlock.InsertItem( nRow++, "����             " );
	m_ctrlOutBlock.InsertItem( nRow++, "��             " );
	m_ctrlOutBlock.InsertItem( nRow++, "�Ǻ�ü�����      " );
	m_ctrlOutBlock.InsertItem( nRow++, "����ü�����      " );
	m_ctrlOutBlock.InsertItem( nRow++, "ü�ᱸ��          " );
	m_ctrlOutBlock.InsertItem( nRow++, "�ʴ������        " );
	m_ctrlOutBlock.InsertItem( nRow++, "�����ŷ����      " );
	m_ctrlOutBlock.InsertItem( nRow++, "52�ְ�         " );
	m_ctrlOutBlock.InsertItem( nRow++, "52������         " );
}

//--------------------------------------------------------------------------------------
// ������ Advise
//--------------------------------------------------------------------------------------
void CDlg_GSC::AdviseData()
{
	TCHAR	szTrCode[]		= "GSC";
	//-----------------------------------------------------------
	// ������ ���
    CString strCode; GetDlgItemText( IDC_EDIT_CODE, strCode );

	//-----------------------------------------------------------
	// ������ ����
	BOOL bSuccess = g_iXingAPI.AdviseRealData( 
		GetSafeHwnd(),				// �����͸� ���� ������, XM_RECEIVE_REAL_DATA ���� �´�.
		szTrCode,					// TR ��ȣ
		strCode,					// �����ڵ�
		sizeof( GSC_InBlock )		// �����ڵ� ����
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
void CDlg_GSC::UnadviseData()
{
	//-----------------------------------------------------------
	// ������ ����� ������ ���ٸ� Return�Ѵ�.
	if( m_strCode.IsEmpty() )
	{
		return;
	}

	TCHAR	szTrCode[]		= "GSC";
	
	//-----------------------------------------------------------
	// ������ ����
	BOOL bSuccess = g_iXingAPI.UnadviseRealData( 
		GetSafeHwnd(),				// �����͸� ���� ������, XM_RECEIVE_REAL_DATA ���� �´�.
		szTrCode,					// TR ��ȣ
		m_strCode,					// �����ڵ�
		sizeof( GSC_InBlock )		// �����ڵ� ����
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
LRESULT CDlg_GSC::OnXMReceiveRealData( WPARAM wParam, LPARAM lParam )
{
	LPRECV_REAL_PACKET pRealPacket = (LPRECV_REAL_PACKET)lParam;

	if( strcmp( pRealPacket->szTrCode, "GSC" ) == 0 )
	{
		LPGSC_OutBlock pOutBlock = (LPGSC_OutBlock)pRealPacket->pszData;
		int nRow = 0;
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->symbol  , sizeof( pOutBlock->symbol ), DATA_TYPE_STRING		) );    // �����ڵ�        
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->ovsdate , sizeof( pOutBlock->ovsdate), DATA_TYPE_STRING		) );    // ü������(����)            
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->kordate , sizeof( pOutBlock->kordate), DATA_TYPE_STRING		) );    // ü������(�ѱ�)            
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->trdtm   , sizeof( pOutBlock->trdtm  ), DATA_TYPE_STRING		) );    // ü��ð�(����)            
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->kortm   , sizeof( pOutBlock->kortm  ), DATA_TYPE_STRING		) );    // ü��ð�(�ѱ�)            
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sign    , sizeof( pOutBlock->sign   ), DATA_TYPE_STRING		) );    // ���ϴ�񱸺�        
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->price   , sizeof( pOutBlock->price  ), DATA_TYPE_DOT, 6		) );    // ü�ᰡ��            
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->diff    , sizeof( pOutBlock->diff   ), DATA_TYPE_DOT, 6		) );    // ���ϴ��            
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->rate    , sizeof( pOutBlock->rate   ), DATA_TYPE_FLOAT, 2	) );    // �����            
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->open    , sizeof( pOutBlock->open   ), DATA_TYPE_DOT, 6		) );    // �ð�            
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->high    , sizeof( pOutBlock->high   ), DATA_TYPE_DOT, 6		) );    // ��        
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->low     , sizeof( pOutBlock->low    ), DATA_TYPE_DOT, 6		) );    // ����            
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->trdq    , sizeof( pOutBlock->trdq   ), DATA_TYPE_LONG		) );    // �Ǻ�ü�����            
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->totq    , sizeof( pOutBlock->totq   ), DATA_TYPE_LONG		) );    // ����ü�����            
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->cgubun  , sizeof( pOutBlock->cgubun ), DATA_TYPE_STRING		) );    // ü�ᱸ��            
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->lSeq    , sizeof( pOutBlock->lSeq   ), DATA_TYPE_LONG		) );    // �ʴ������        
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->amount  , sizeof( pOutBlock->amount ), DATA_TYPE_LONG		) );    // �����ŷ����            
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->high52p , sizeof( pOutBlock->high52p), DATA_TYPE_DOT, 6		) );    // 52�ְ�            
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->low52p  , sizeof( pOutBlock->low52p ), DATA_TYPE_DOT, 6		) );    // 52������            
	} 
     
	return 0L;
}
