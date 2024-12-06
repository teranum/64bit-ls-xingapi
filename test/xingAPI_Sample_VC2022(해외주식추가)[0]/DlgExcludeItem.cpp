// DlgExcludeItem.cpp : implementation file
//

#include "stdafx.h"
#include "xingapi_sample.h"
#include "DlgExcludeItem.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgExcludeItem dialog


CDlgExcludeItem::CDlgExcludeItem(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgExcludeItem::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgExcludeItem)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CDlgExcludeItem::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgExcludeItem)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgExcludeItem, CDialog)
	//{{AFX_MSG_MAP(CDlgExcludeItem)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgExcludeItem message handlers

BOOL CDlgExcludeItem::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
		 if( m_nData & 0x00000080 ) CheckDlgButton( IDC_CHECK1, BST_CHECKED );		// ��������
	else if( m_nData & 0x00000100 ) CheckDlgButton( IDC_CHECK2, BST_CHECKED );		// ����溸  
	else if( m_nData & 0x00000200 ) CheckDlgButton( IDC_CHECK3, BST_CHECKED );		// �ŷ�����  
	else if( m_nData & 0x00004000 ) CheckDlgButton( IDC_CHECK4, BST_CHECKED );		// �켱��    
	else if( m_nData & 0x00200000 ) CheckDlgButton( IDC_CHECK5, BST_CHECKED );		// ���ű�50  
	else if( m_nData & 0x01000000 ) CheckDlgButton( IDC_CHECK6, BST_CHECKED );		// �����Ÿ�  
	else if( m_nData & 0x04000000 ) CheckDlgButton( IDC_CHECK7, BST_CHECKED );		// ��������  
	else if( m_nData & 0x80000000 ) CheckDlgButton( IDC_CHECK8, BST_CHECKED );		// �Ҽ��ǰ���
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CDlgExcludeItem::OnOK() 
{
	m_nData = 0;
		 if( IsDlgButtonChecked( IDC_CHECK1 ) ) m_nData |= 0x00000080;		// ��������
	else if( IsDlgButtonChecked( IDC_CHECK2 ) ) m_nData |= 0x00000100;		// ����溸  
	else if( IsDlgButtonChecked( IDC_CHECK3 ) ) m_nData |= 0x00000200;		// �ŷ�����  
	else if( IsDlgButtonChecked( IDC_CHECK4 ) ) m_nData |= 0x00004000;		// �켱��    
	else if( IsDlgButtonChecked( IDC_CHECK5 ) ) m_nData |= 0x00200000;		// ���ű�50  
	else if( IsDlgButtonChecked( IDC_CHECK6 ) ) m_nData |= 0x01000000;		// �����Ÿ�  
	else if( IsDlgButtonChecked( IDC_CHECK7 ) ) m_nData |= 0x04000000;		// ��������  
	else if( IsDlgButtonChecked( IDC_CHECK8 ) ) m_nData |= 0x80000000;		// �Ҽ��ǰ���
	
	CDialog::OnOK();
}
