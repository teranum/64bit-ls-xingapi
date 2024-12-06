// Dlg_CSPAQ02300.cpp : implementation file
//

#include "stdafx.h"
#include "xingapi_sample.h"
#include "Dlg_CSPAQ02300.h"

#include "./Packet/CSPAQ12300.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlg_CSPAQ02300 dialog


IMPLEMENT_DYNCREATE(CDlg_CSPAQ02300, CDialog)

CDlg_CSPAQ02300::CDlg_CSPAQ02300(CWnd* pParent /*=NULL*/)
	: CDialog(CDlg_CSPAQ02300::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlg_CSPAQ02300)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CDlg_CSPAQ02300::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlg_CSPAQ02300)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
	DDX_Control(pDX, IDC_OUTBLOCK1, m_ctrlOutBlock1);
	DDX_Control(pDX, IDC_OUTBLOCK2, m_ctrlOutBlock2);
	DDX_Control(pDX, IDC_OUTBLOCK3, m_ctrlOutBlock3);
}


BEGIN_MESSAGE_MAP(CDlg_CSPAQ02300, CDialog)
	//{{AFX_MSG_MAP(CDlg_CSPAQ02300)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
	ON_BN_CLICKED( IDC_BUTTON_REQUEST,		  OnButtonRequest	  )
	ON_BN_CLICKED( IDC_BUTTON_REQUEST_NEXT,	  OnButtonRequestNext )
	ON_MESSAGE	 ( WM_USER + XM_RECEIVE_DATA, OnXMReceiveData	  )
	ON_MESSAGE	 ( WM_USER + XM_TIMEOUT_DATA, OnXMTimeoutData	  )
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlg_CSPAQ02300 message handlers

BOOL CDlg_CSPAQ02300::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	InitCtrls();
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CDlg_CSPAQ02300::OnButtonRequest() 
{
	RequestData();
}

void CDlg_CSPAQ02300::OnButtonRequestNext() 
{
	RequestData( TRUE );
}

//--------------------------------------------------------------------------------------
// ��Ʈ�� �ʱ�ȭ
//--------------------------------------------------------------------------------------
void CDlg_CSPAQ02300::InitCtrls()
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

	((CComboBox*)GetDlgItem( IDC_INBLOCK_ACNTNO         ))->SetCurSel( 0 );	// ���¹�ȣ
	((CComboBox*)GetDlgItem( IDC_INBLOCK_BALCRETP       ))->SetCurSel( 0 );	// �ܰ��������             
	((CComboBox*)GetDlgItem( IDC_INBLOCK_CMSNAPPTPCODE  ))->SetCurSel( 0 );	// ���������뱸��         
	((CComboBox*)GetDlgItem( IDC_INBLOCK_D2BALBASEQRYTP ))->SetCurSel( 0 );	// D2�ܰ������ȸ����         
	((CComboBox*)GetDlgItem( IDC_INBLOCK_UPRCTPCODE     ))->SetCurSel( 0 );	// �ܰ�����         

	//-------------------------------------------------------------------------
	// OutBlock1
	nCol = 0;
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "���ڵ尹��        ", FALSE,    5 );    // [long  ,    5] ���ڵ尹��        
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "���¹�ȣ          ", TRUE ,   20 );    // [string,   20] ���¹�ȣ          
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "��й�ȣ          ", TRUE ,    8 );    // [string,    8] ��й�ȣ          
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "�ܰ��������      ", TRUE ,    1 );    // [string,    1] �ܰ��������      
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "���������뱸��    ", TRUE ,    1 );    // [string,    1] ���������뱸��    
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "D2�ܰ������ȸ����", TRUE ,    1 );    // [string,    1] D2�ܰ������ȸ����
	InsertColumn4List( this, IDC_OUTBLOCK1, nCol++, "�ܰ�����          ", TRUE ,    1 );    // [string,    1] �ܰ�����          
	
	//-------------------------------------------------------------------------
	// OutBlock2
	nCol = 0;
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "���ڵ尹��                   ", FALSE,    5 );    // [long  ,    5] ���ڵ尹��                   
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "������                       ", TRUE ,   40 );    // [string,   40] ������                       
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "���¸�                       ", TRUE ,   40 );    // [string,   40] ���¸�                       
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "�����ֹ����ɱݾ�             ", FALSE,   16 );    // [long  ,   16] �����ֹ����ɱݾ�             
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "��ݰ��ɱݾ�                 ", FALSE,   16 );    // [long  ,   16] ��ݰ��ɱݾ�                 
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "�ŷ��ұݾ�                   ", FALSE,   16 );    // [long  ,   16] �ŷ��ұݾ�                   
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "�ڽ��ڱݾ�                   ", FALSE,   16 );    // [long  ,   16] �ڽ��ڱݾ�                   
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "HTS�ֹ����ɱݾ�              ", FALSE,   16 );    // [long  ,   16] HTS�ֹ����ɱݾ�              
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "���űݷ�100�ۼ�Ʈ�ֹ����ɱݾ�", FALSE,   16 );    // [long  ,   16] ���űݷ�100�ۼ�Ʈ�ֹ����ɱݾ�
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "�ܰ��򰡱ݾ�                 ", FALSE,   16 );    // [long  ,   16] �ܰ��򰡱ݾ�                 
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "���Աݾ�                     ", FALSE,   16 );    // [long  ,   16] ���Աݾ�                     
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "�̼��ݾ�                     ", FALSE,   16 );    // [long  ,   16] �̼��ݾ�                     
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "������                       ", FALSE, 18.6 );    // [double, 18.6] ������                       
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "���ڿ���                     ", FALSE,   20 );    // [long  ,   20] ���ڿ���                     
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "���ڼ��ͱݾ�                 ", FALSE,   16 );    // [long  ,   16] ���ڼ��ͱݾ�                 
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "�ſ�㺸�ֹ��ݾ�             ", FALSE,   16 );    // [long  ,   16] �ſ�㺸�ֹ��ݾ�             
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "������                       ", FALSE,   16 );    // [long  ,   16] ������                       
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "D1������                     ", FALSE,   16 );    // [long  ,   16] D1������                     
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "D2������                     ", FALSE,   16 );    // [long  ,   16] D2������                     
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "�ֹ���                       ", TRUE ,    8 );    // [string,    8] �ֹ���                       
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "�������űݾ�                 ", FALSE,   16 );    // [long  ,   16] �������űݾ�                 
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "������űݾ�                 ", FALSE,   16 );    // [long  ,   16] ������űݾ�                 
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "���ݾ�                     ", FALSE,   16 );    // [long  ,   16] ���ݾ�                     
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "���ϸż�ü��ݾ�             ", FALSE,   16 );    // [long  ,   16] ���ϸż�ü��ݾ�             
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "���ϸŵ�ü��ݾ�             ", FALSE,   16 );    // [long  ,   16] ���ϸŵ�ü��ݾ�             
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "���ϸż�ü��ݾ�             ", FALSE,   16 );    // [long  ,   16] ���ϸż�ü��ݾ�             
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "���ϸŵ�ü��ݾ�             ", FALSE,   16 );    // [long  ,   16] ���ϸŵ�ü��ݾ�             
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "�򰡼����հ�                 ", FALSE,   15 );    // [long  ,   15] �򰡼����հ�                 
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "��Ź�ڻ��Ѿ�                 ", FALSE,   16 );    // [long  ,   16] ��Ź�ڻ��Ѿ�                 
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "�����                       ", FALSE,   19 );    // [long  ,   19] �����                       
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "����ݾ�                   ", FALSE,   16 );    // [long  ,   16] ����ݾ�                   
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "��Ÿ�뿩�ݾ�                 ", FALSE,   16 );    // [long  ,   16] ��Ÿ�뿩�ݾ�                 
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "������ݾ�                   ", FALSE,   16 );    // [long  ,   16] ������ݾ�                   
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "D1������                     ", FALSE,   16 );    // [long  ,   16] D1������                     
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "D2������                     ", FALSE,   16 );    // [long  ,   16] D2������                     
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "D1������                     ", FALSE,   16 );    // [long  ,   16] D1������                     
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "D2������                     ", FALSE,   16 );    // [long  ,   16] D2������                     
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "D1���������ݾ�               ", FALSE,   16 );    // [long  ,   16] D1���������ݾ�               
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "D2���������ݾ�               ", FALSE,   16 );    // [long  ,   16] D2���������ݾ�               
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "����KSE�������ű�            ", FALSE,   16 );    // [long  ,   16] ����KSE�������ű�            
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "����KSE������ű�            ", FALSE,   16 );    // [long  ,   16] ����KSE������ű�            
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "����KSE�ſ��������ű�        ", FALSE,   16 );    // [long  ,   16] ����KSE�ſ��������ű�        
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "����KSE�ſ������ű�        ", FALSE,   16 );    // [long  ,   16] ����KSE�ſ������ű�        
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "����KSE�������ű�            ", FALSE,   16 );    // [long  ,   16] ����KSE�������ű�            
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "����KSE������ű�            ", FALSE,   16 );    // [long  ,   16] ����KSE������ű�            
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "����KSE�ſ��������ű�        ", FALSE,   16 );    // [long  ,   16] ����KSE�ſ��������ű�        
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "����KSE�ſ������ű�        ", FALSE,   16 );    // [long  ,   16] ����KSE�ſ������ű�        
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "�����ڽ����������ű�         ", FALSE,   16 );    // [long  ,   16] �����ڽ����������ű�         
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "�����ڽ��ڴ�����ű�         ", FALSE,   16 );    // [long  ,   16] �����ڽ��ڴ�����ű�         
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "�����ڽ��ڽſ��������ű�     ", FALSE,   16 );    // [long  ,   16] �����ڽ��ڽſ��������ű�     
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "�����ڽ��ڽſ������ű�     ", FALSE,   16 );    // [long  ,   16] �����ڽ��ڽſ������ű�     
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "�����ڽ����������ű�         ", FALSE,   16 );    // [long  ,   16] �����ڽ����������ű�         
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "�����ڽ��ڴ�����ű�         ", FALSE,   16 );    // [long  ,   16] �����ڽ��ڴ�����ű�         
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "�����ڽ��ڽſ��������ű�     ", FALSE,   16 );    // [long  ,   16] �����ڽ��ڽſ��������ű�     
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "�����ڽ��ڽſ������ű�     ", FALSE,   16 );    // [long  ,   16] �����ڽ��ڽſ������ű�     
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "�������������������ű�       ", FALSE,   16 );    // [long  ,   16] �������������������ű�       
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "�����������������ű�       ", FALSE,   16 );    // [long  ,   16] �����������������ű�       
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "�������������������ű�       ", FALSE,   16 );    // [long  ,   16] �������������������ű�       
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "�����������������ű�       ", FALSE,   16 );    // [long  ,   16] �����������������ű�       
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "��������������ű�           ", FALSE,   16 );    // [long  ,   16] ��������������ű�           
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "������ܴ�����ű�           ", FALSE,   16 );    // [long  ,   16] ������ܴ�����ű�           
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "��������������ű�           ", FALSE,   16 );    // [long  ,   16] ��������������ű�           
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "������ܴ�����ű�           ", FALSE,   16 );    // [long  ,   16] ������ܴ�����ű�           
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "��Ź�㺸����                 ", FALSE,   16 );    // [long  ,   16] ��Ź�㺸����                 
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "�ż������(D+2)              ", FALSE,   16 );    // [long  ,   16] �ż������(D+2)              
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "�ŵ������(D+2)              ", FALSE,   16 );    // [long  ,   16] �ŵ������(D+2)              
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "�����ҿ��(D+1)              ", FALSE,   16 );    // [long  ,   16] �����ҿ��(D+1)              
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "�����ҿ��(D+2)              ", FALSE,   16 );    // [long  ,   16] �����ҿ��(D+2)              
	InsertColumn4List( this, IDC_OUTBLOCK2, nCol++, "����ݾ�                     ", FALSE,   16 );    // [long  ,   16] ����ݾ�                     
	
	//-------------------------------------------------------------------------
	// OutBlock3
	nCol = 0;
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "�����ȣ            ", TRUE ,   12 );    // [string,   12] �����ȣ            
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "�����              ", TRUE ,   40 );    // [string,   40] �����              
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "���������ܰ������ڵ�", TRUE ,    2 );    // [string,    2] ���������ܰ������ڵ�
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "���������ܰ�������  ", TRUE ,   40 );    // [string,   40] ���������ܰ�������  
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "�ܰ����            ", FALSE,   16 );    // [long  ,   16] �ܰ����            
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "�Ÿű����ܰ����    ", FALSE,   16 );    // [long  ,   16] �Ÿű����ܰ����    
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "���ϸż�ü�����    ", FALSE,   16 );    // [long  ,   16] ���ϸż�ü�����    
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "���ϸŵ�ü�����    ", FALSE,   16 );    // [long  ,   16] ���ϸŵ�ü�����    
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "�ŵ���              ", FALSE, 21.4 );    // [double, 21.4] �ŵ���              
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "�ż���              ", FALSE, 21.4 );    // [double, 21.4] �ż���              
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "�ŵ����ͱݾ�        ", FALSE,   16 );    // [long  ,   16] �ŵ����ͱݾ�        
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "������              ", FALSE, 18.6 );    // [double, 18.6] ������              
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "���簡              ", FALSE, 15.2 );    // [double, 15.2] ���簡              
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "�ſ�ݾ�            ", FALSE,   16 );    // [long  ,   16] �ſ�ݾ�            
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "������              ", TRUE ,    8 );    // [string,    8] ������              
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "���ϸŵ�ü�ᰡ      ", FALSE, 13.2 );    // [double, 13.2] ���ϸŵ�ü�ᰡ      
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "���ϸŵ�����        ", FALSE,   16 );    // [long  ,   16] ���ϸŵ�����        
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "���ϸż�ü�ᰡ      ", FALSE, 13.2 );    // [double, 13.2] ���ϸż�ü�ᰡ      
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "���ϸż�����        ", FALSE,   16 );    // [long  ,   16] ���ϸż�����        
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "������              ", TRUE ,    8 );    // [string,    8] ������              
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "��մܰ�            ", FALSE, 13.2 );    // [double, 13.2] ��մܰ�            
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "�ŵ����ɼ���        ", FALSE,   16 );    // [long  ,   16] �ŵ����ɼ���        
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "�ŵ��ֹ�����        ", FALSE,   16 );    // [long  ,   16] �ŵ��ֹ�����        
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "���ϸż�ü��ݾ�    ", FALSE,   16 );    // [long  ,   16] ���ϸż�ü��ݾ�    
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "���ϸŵ�ü��ݾ�    ", FALSE,   16 );    // [long  ,   16] ���ϸŵ�ü��ݾ�    
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "���ϸż�ü��ݾ�    ", FALSE,   16 );    // [long  ,   16] ���ϸż�ü��ݾ�    
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "���ϸŵ�ü��ݾ�    ", FALSE,   16 );    // [long  ,   16] ���ϸŵ�ü��ݾ�    
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "�ܰ��򰡱ݾ�        ", FALSE,   16 );    // [long  ,   16] �ܰ��򰡱ݾ�        
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "�򰡼���            ", FALSE,   16 );    // [long  ,   16] �򰡼���            
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "�����ֹ����ɱݾ�    ", FALSE,   16 );    // [long  ,   16] �����ֹ����ɱݾ�    
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "�ֹ����ɱݾ�        ", FALSE,   16 );    // [long  ,   16] �ֹ����ɱݾ�        
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "�ŵ���ü�����      ", FALSE,   16 );    // [long  ,   16] �ŵ���ü�����      
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "�ŵ��̰�������      ", FALSE,   16 );    // [long  ,   16] �ŵ��̰�������      
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "�ż���ü�����      ", FALSE,   16 );    // [long  ,   16] �ż���ü�����      
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "�ż��̰�������      ", FALSE,   16 );    // [long  ,   16] �ż��̰�������      
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "�̰�������          ", FALSE,   16 );    // [long  ,   16] �̰�������          
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "��ü�����          ", FALSE,   16 );    // [long  ,   16] ��ü�����          
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "��������            ", FALSE, 15.2 );    // [double, 15.2] ��������            
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "���Աݾ�            ", FALSE,   16 );    // [long  ,   16] ���Աݾ�            
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "��Ͻ����ڵ�        ", TRUE ,    2 );    // [string,    2] ��Ͻ����ڵ�        
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "����󼼺з��ڵ�    ", TRUE ,    2 );    // [string,    2] ����󼼺з��ڵ�    
	InsertColumn4List( this, IDC_OUTBLOCK3, nCol++, "��Ź�㺸�������    ", FALSE,   16 );    // [long  ,   16] ��Ź�㺸�������    

	ZeroMemory( m_szContKey, sizeof( m_szContKey ) );
}

//--------------------------------------------------------------------------------------
// ������ ��ȸ
//--------------------------------------------------------------------------------------
void CDlg_CSPAQ02300::RequestData( BOOL bNext )
{
	//-----------------------------------------------------------
// ���������ֹ�(CSPAQ02300) ( base21=SONAT000,headtype=B )
	CSPAQ12300InBlock1	pckInBlock;

	TCHAR			szTrNo[]		= "CSPAQ12300";

	//-----------------------------------------------------------
	// ������ ���
    CString strAcntNo        ;		GetDlgItemText( IDC_INBLOCK_ACNTNO        , strAcntNo         );    // [long  ,    5] ���ڵ尹��        
    CString strPwd           ;		GetDlgItemText( IDC_INBLOCK_PWD           , strPwd            );    // [string,   20] ���¹�ȣ          
    CString strBalCreTp      ;		GetDlgItemText( IDC_INBLOCK_BALCRETP      , strBalCreTp       );    // [string,    8] ��й�ȣ          
    CString strCmsnAppTpCode ;		GetDlgItemText( IDC_INBLOCK_CMSNAPPTPCODE , strCmsnAppTpCode  );    // [string,    1] �ܰ��������      
    CString strD2balBaseQryTp;		GetDlgItemText( IDC_INBLOCK_D2BALBASEQRYTP, strD2balBaseQryTp );    // [string,    1] ���������뱸��    
    CString strUprcTpCode    ;		GetDlgItemText( IDC_INBLOCK_UPRCTPCODE    , strUprcTpCode     );    // [string,    1] D2�ܰ������ȸ����

	//-----------------------------------------------------------
	// ������ �ʱ�ȭ
	FillMemory( &pckInBlock, sizeof( pckInBlock ), ' ' );

	//-----------------------------------------------------------
	// ������ �Է�
	SetPacketData( pckInBlock.RecCnt        , sizeof( pckInBlock.RecCnt         ), "1"              , DATA_TYPE_LONG         );    // [long  ,    5] ���ڵ尹��        
	SetPacketData( pckInBlock.AcntNo        , sizeof( pckInBlock.AcntNo         ), strAcntNo        , DATA_TYPE_STRING       );    // [string,   20] ���¹�ȣ          
	SetPacketData( pckInBlock.Pwd           , sizeof( pckInBlock.Pwd            ), strPwd           , DATA_TYPE_STRING       );    // [string,    8] ��й�ȣ          
	SetPacketData( pckInBlock.BalCreTp      , sizeof( pckInBlock.BalCreTp       ), strBalCreTp      , DATA_TYPE_STRING       );    // [string,    1] �ܰ��������      
	SetPacketData( pckInBlock.CmsnAppTpCode , sizeof( pckInBlock.CmsnAppTpCode  ), strCmsnAppTpCode , DATA_TYPE_STRING       );    // [string,    1] ���������뱸��    
	SetPacketData( pckInBlock.D2balBaseQryTp, sizeof( pckInBlock.D2balBaseQryTp ), strD2balBaseQryTp, DATA_TYPE_STRING       );    // [string,    1] D2�ܰ������ȸ����
	SetPacketData( pckInBlock.UprcTpCode    , sizeof( pckInBlock.UprcTpCode     ), strUprcTpCode    , DATA_TYPE_STRING       );    // [string,    1] �ܰ�����          

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
LRESULT CDlg_CSPAQ02300::OnXMReceiveData( WPARAM wParam, LPARAM lParam )
{
	//-------------------------------------------------------------------------------------
	// Data�� ����
	if( wParam == REQUEST_DATA )
	{
		typedef struct
		{
			CSPAQ12300OutBlock1	outBlock1;
			CSPAQ12300OutBlock2	outBlock2;
			char				sCountOutBlock3[5];
			CSPAQ12300OutBlock3	outBlock3[1];
		} CSPAQ12300AllOutBlock, *LPCSPAQ12300AllOutBlock;

		LPRECV_PACKET			pRpData		 = (LPRECV_PACKET)lParam;
		LPCSPAQ12300AllOutBlock pAllOutBlock = (LPCSPAQ12300AllOutBlock)pRpData->lpData;
		int						nDataLength  = pRpData->nDataLength;
		int						nCol;
		int						nRow;
		int						nCount;
		char					szCount[6] = { 0 };

		// ����Ű�� �����Ѵ�.
		strcpy_s( m_szContKey, pRpData->szContKey );

		//------------------------------------------------
		// OutBlock1

		// ���� ������ ũ�Ⱑ Block ũ�⺸�� �۴ٸ� ó������ �ʴ´�.
		nDataLength -= sizeof( CSPAQ12300OutBlock1 );
		if( nDataLength < 0 )
		{
			return 0L;
		}

		nCol = 0;
		m_ctrlOutBlock1.InsertItem( 0, "" );
		m_ctrlOutBlock1.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock1.RecCnt        , sizeof( pAllOutBlock->outBlock1.RecCnt         ), DATA_TYPE_LONG   ) );    // [long  ,    5] ���ڵ尹��        
		m_ctrlOutBlock1.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock1.AcntNo        , sizeof( pAllOutBlock->outBlock1.AcntNo         ), DATA_TYPE_STRING ) );    // [string,   20] ���¹�ȣ          
		m_ctrlOutBlock1.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock1.Pwd           , sizeof( pAllOutBlock->outBlock1.Pwd            ), DATA_TYPE_STRING ) );    // [string,    8] ��й�ȣ          
		m_ctrlOutBlock1.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock1.BalCreTp      , sizeof( pAllOutBlock->outBlock1.BalCreTp       ), DATA_TYPE_STRING ) );    // [string,    1] �ܰ��������      
		m_ctrlOutBlock1.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock1.CmsnAppTpCode , sizeof( pAllOutBlock->outBlock1.CmsnAppTpCode  ), DATA_TYPE_STRING ) );    // [string,    1] ���������뱸��    
		m_ctrlOutBlock1.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock1.D2balBaseQryTp, sizeof( pAllOutBlock->outBlock1.D2balBaseQryTp ), DATA_TYPE_STRING ) );    // [string,    1] D2�ܰ������ȸ����          
		m_ctrlOutBlock1.SetItemText(  0, nCol++, GetDispData( pAllOutBlock->outBlock1.UprcTpCode    , sizeof( pAllOutBlock->outBlock1.UprcTpCode     ), DATA_TYPE_STRING ) );    // [string,    1] �ܰ�����          

		//------------------------------------------------
		// OutBlock2
		nDataLength -= sizeof( CSPAQ12300OutBlock2 );
		if( nDataLength < 0 )
		{
			return 0L;
		}

		nCol = 0;
		m_ctrlOutBlock2.InsertItem( 0, "" );
		m_ctrlOutBlock2.SetItemText( 0, nCol++, GetDispData( pAllOutBlock->outBlock2.RecCnt                , sizeof( pAllOutBlock->outBlock2.RecCnt                 ), DATA_TYPE_LONG   ) );    // [long  ,    5] ���ڵ尹��                   
		m_ctrlOutBlock2.SetItemText( 0, nCol++, GetDispData( pAllOutBlock->outBlock2.BrnNm                 , sizeof( pAllOutBlock->outBlock2.BrnNm                  ), DATA_TYPE_STRING ) );    // [string,   40] ������                       
		m_ctrlOutBlock2.SetItemText( 0, nCol++, GetDispData( pAllOutBlock->outBlock2.AcntNm                , sizeof( pAllOutBlock->outBlock2.AcntNm                 ), DATA_TYPE_STRING ) );    // [string,   40] ���¸�                       
		m_ctrlOutBlock2.SetItemText( 0, nCol++, GetDispData( pAllOutBlock->outBlock2.MnyOrdAbleAmt         , sizeof( pAllOutBlock->outBlock2.MnyOrdAbleAmt          ), DATA_TYPE_LONG   ) );    // [long  ,   16] �����ֹ����ɱݾ�             
		m_ctrlOutBlock2.SetItemText( 0, nCol++, GetDispData( pAllOutBlock->outBlock2.MnyoutAbleAmt         , sizeof( pAllOutBlock->outBlock2.MnyoutAbleAmt          ), DATA_TYPE_LONG   ) );    // [long  ,   16] ��ݰ��ɱݾ�                 
		m_ctrlOutBlock2.SetItemText( 0, nCol++, GetDispData( pAllOutBlock->outBlock2.SeOrdAbleAmt          , sizeof( pAllOutBlock->outBlock2.SeOrdAbleAmt           ), DATA_TYPE_LONG   ) );    // [long  ,   16] �ŷ��ұݾ�                   
		m_ctrlOutBlock2.SetItemText( 0, nCol++, GetDispData( pAllOutBlock->outBlock2.KdqOrdAbleAmt         , sizeof( pAllOutBlock->outBlock2.KdqOrdAbleAmt          ), DATA_TYPE_LONG   ) );    // [long  ,   16] �ڽ��ڱݾ�                   
		m_ctrlOutBlock2.SetItemText( 0, nCol++, GetDispData( pAllOutBlock->outBlock2.HtsOrdAbleAmt         , sizeof( pAllOutBlock->outBlock2.HtsOrdAbleAmt          ), DATA_TYPE_LONG   ) );    // [long  ,   16] HTS�ֹ����ɱݾ�              
		m_ctrlOutBlock2.SetItemText( 0, nCol++, GetDispData( pAllOutBlock->outBlock2.MgnRat100pctOrdAbleAmt, sizeof( pAllOutBlock->outBlock2.MgnRat100pctOrdAbleAmt ), DATA_TYPE_LONG   ) );    // [long  ,   16] ���űݷ�100�ۼ�Ʈ�ֹ����ɱݾ�
		m_ctrlOutBlock2.SetItemText( 0, nCol++, GetDispData( pAllOutBlock->outBlock2.BalEvalAmt            , sizeof( pAllOutBlock->outBlock2.BalEvalAmt             ), DATA_TYPE_LONG   ) );    // [long  ,   16] �ܰ��򰡱ݾ�                 
		m_ctrlOutBlock2.SetItemText( 0, nCol++, GetDispData( pAllOutBlock->outBlock2.PchsAmt               , sizeof( pAllOutBlock->outBlock2.PchsAmt                ), DATA_TYPE_LONG   ) );    // [long  ,   16] ���Աݾ�                     
		m_ctrlOutBlock2.SetItemText( 0, nCol++, GetDispData( pAllOutBlock->outBlock2.RcvblAmt              , sizeof( pAllOutBlock->outBlock2.RcvblAmt               ), DATA_TYPE_LONG   ) );    // [long  ,   16] �̼��ݾ�                     
		m_ctrlOutBlock2.SetItemText( 0, nCol++, GetDispData( pAllOutBlock->outBlock2.PnlRat                , sizeof( pAllOutBlock->outBlock2.PnlRat                 ), DATA_TYPE_DOT, 6 ) );    // [double, 18.6] ������                       
		m_ctrlOutBlock2.SetItemText( 0, nCol++, GetDispData( pAllOutBlock->outBlock2.InvstOrgAmt           , sizeof( pAllOutBlock->outBlock2.InvstOrgAmt            ), DATA_TYPE_LONG   ) );    // [long  ,   20] ���ڿ���                     
		m_ctrlOutBlock2.SetItemText( 0, nCol++, GetDispData( pAllOutBlock->outBlock2.InvstPlAmt            , sizeof( pAllOutBlock->outBlock2.InvstPlAmt             ), DATA_TYPE_LONG   ) );    // [long  ,   16] ���ڼ��ͱݾ�                 
		m_ctrlOutBlock2.SetItemText( 0, nCol++, GetDispData( pAllOutBlock->outBlock2.CrdtPldgOrdAmt        , sizeof( pAllOutBlock->outBlock2.CrdtPldgOrdAmt         ), DATA_TYPE_LONG   ) );    // [long  ,   16] �ſ�㺸�ֹ��ݾ�             
		m_ctrlOutBlock2.SetItemText( 0, nCol++, GetDispData( pAllOutBlock->outBlock2.Dps                   , sizeof( pAllOutBlock->outBlock2.Dps                    ), DATA_TYPE_LONG   ) );    // [long  ,   16] ������                       
		m_ctrlOutBlock2.SetItemText( 0, nCol++, GetDispData( pAllOutBlock->outBlock2.D1Dps                 , sizeof( pAllOutBlock->outBlock2.D1Dps                  ), DATA_TYPE_LONG   ) );    // [long  ,   16] D1������                     
		m_ctrlOutBlock2.SetItemText( 0, nCol++, GetDispData( pAllOutBlock->outBlock2.D2Dps                 , sizeof( pAllOutBlock->outBlock2.D2Dps                  ), DATA_TYPE_LONG   ) );    // [long  ,   16] D2������                     
		m_ctrlOutBlock2.SetItemText( 0, nCol++, GetDispData( pAllOutBlock->outBlock2.OrdDt                 , sizeof( pAllOutBlock->outBlock2.OrdDt                  ), DATA_TYPE_STRING ) );    // [string,    8] �ֹ���                       
		m_ctrlOutBlock2.SetItemText( 0, nCol++, GetDispData( pAllOutBlock->outBlock2.MnyMgn                , sizeof( pAllOutBlock->outBlock2.MnyMgn                 ), DATA_TYPE_LONG   ) );    // [long  ,   16] �������űݾ�                 
		m_ctrlOutBlock2.SetItemText( 0, nCol++, GetDispData( pAllOutBlock->outBlock2.SubstMgn              , sizeof( pAllOutBlock->outBlock2.SubstMgn               ), DATA_TYPE_LONG   ) );    // [long  ,   16] ������űݾ�                 
		m_ctrlOutBlock2.SetItemText( 0, nCol++, GetDispData( pAllOutBlock->outBlock2.SubstAmt              , sizeof( pAllOutBlock->outBlock2.SubstAmt               ), DATA_TYPE_LONG   ) );    // [long  ,   16] ���ݾ�                     
		m_ctrlOutBlock2.SetItemText( 0, nCol++, GetDispData( pAllOutBlock->outBlock2.PrdayBuyExecAmt       , sizeof( pAllOutBlock->outBlock2.PrdayBuyExecAmt        ), DATA_TYPE_LONG   ) );    // [long  ,   16] ���ϸż�ü��ݾ�             
		m_ctrlOutBlock2.SetItemText( 0, nCol++, GetDispData( pAllOutBlock->outBlock2.PrdaySellExecAmt      , sizeof( pAllOutBlock->outBlock2.PrdaySellExecAmt       ), DATA_TYPE_LONG   ) );    // [long  ,   16] ���ϸŵ�ü��ݾ�             
		m_ctrlOutBlock2.SetItemText( 0, nCol++, GetDispData( pAllOutBlock->outBlock2.CrdayBuyExecAmt       , sizeof( pAllOutBlock->outBlock2.CrdayBuyExecAmt        ), DATA_TYPE_LONG   ) );    // [long  ,   16] ���ϸż�ü��ݾ�             
		m_ctrlOutBlock2.SetItemText( 0, nCol++, GetDispData( pAllOutBlock->outBlock2.CrdaySellExecAmt      , sizeof( pAllOutBlock->outBlock2.CrdaySellExecAmt       ), DATA_TYPE_LONG   ) );    // [long  ,   16] ���ϸŵ�ü��ݾ�             
		m_ctrlOutBlock2.SetItemText( 0, nCol++, GetDispData( pAllOutBlock->outBlock2.EvalPnlSum            , sizeof( pAllOutBlock->outBlock2.EvalPnlSum             ), DATA_TYPE_LONG   ) );    // [long  ,   15] �򰡼����հ�                 
		m_ctrlOutBlock2.SetItemText( 0, nCol++, GetDispData( pAllOutBlock->outBlock2.DpsastTotamt          , sizeof( pAllOutBlock->outBlock2.DpsastTotamt           ), DATA_TYPE_LONG   ) );    // [long  ,   16] ��Ź�ڻ��Ѿ�                 
		m_ctrlOutBlock2.SetItemText( 0, nCol++, GetDispData( pAllOutBlock->outBlock2.Evrprc                , sizeof( pAllOutBlock->outBlock2.Evrprc                 ), DATA_TYPE_LONG   ) );    // [long  ,   19] �����                       
		m_ctrlOutBlock2.SetItemText( 0, nCol++, GetDispData( pAllOutBlock->outBlock2.RuseAmt               , sizeof( pAllOutBlock->outBlock2.RuseAmt                ), DATA_TYPE_LONG   ) );    // [long  ,   16] ����ݾ�                   
		m_ctrlOutBlock2.SetItemText( 0, nCol++, GetDispData( pAllOutBlock->outBlock2.EtclndAmt             , sizeof( pAllOutBlock->outBlock2.EtclndAmt              ), DATA_TYPE_LONG   ) );    // [long  ,   16] ��Ÿ�뿩�ݾ�                 
		m_ctrlOutBlock2.SetItemText( 0, nCol++, GetDispData( pAllOutBlock->outBlock2.PrcAdjstAmt           , sizeof( pAllOutBlock->outBlock2.PrcAdjstAmt            ), DATA_TYPE_LONG   ) );    // [long  ,   16] ������ݾ�                   
		m_ctrlOutBlock2.SetItemText( 0, nCol++, GetDispData( pAllOutBlock->outBlock2.D1CmsnAmt             , sizeof( pAllOutBlock->outBlock2.D1CmsnAmt              ), DATA_TYPE_LONG   ) );    // [long  ,   16] D1������                     
		m_ctrlOutBlock2.SetItemText( 0, nCol++, GetDispData( pAllOutBlock->outBlock2.D2CmsnAmt             , sizeof( pAllOutBlock->outBlock2.D2CmsnAmt              ), DATA_TYPE_LONG   ) );    // [long  ,   16] D2������                     
		m_ctrlOutBlock2.SetItemText( 0, nCol++, GetDispData( pAllOutBlock->outBlock2.D1EvrTax              , sizeof( pAllOutBlock->outBlock2.D1EvrTax               ), DATA_TYPE_LONG   ) );    // [long  ,   16] D1������                     
		m_ctrlOutBlock2.SetItemText( 0, nCol++, GetDispData( pAllOutBlock->outBlock2.D2EvrTax              , sizeof( pAllOutBlock->outBlock2.D2EvrTax               ), DATA_TYPE_LONG   ) );    // [long  ,   16] D2������                     
		m_ctrlOutBlock2.SetItemText( 0, nCol++, GetDispData( pAllOutBlock->outBlock2.D1SettPrergAmt        , sizeof( pAllOutBlock->outBlock2.D1SettPrergAmt         ), DATA_TYPE_LONG   ) );    // [long  ,   16] D1���������ݾ�               
		m_ctrlOutBlock2.SetItemText( 0, nCol++, GetDispData( pAllOutBlock->outBlock2.D2SettPrergAmt        , sizeof( pAllOutBlock->outBlock2.D2SettPrergAmt         ), DATA_TYPE_LONG   ) );    // [long  ,   16] D2���������ݾ�               
		m_ctrlOutBlock2.SetItemText( 0, nCol++, GetDispData( pAllOutBlock->outBlock2.PrdayKseMnyMgn        , sizeof( pAllOutBlock->outBlock2.PrdayKseMnyMgn         ), DATA_TYPE_LONG   ) );    // [long  ,   16] ����KSE�������ű�            
		m_ctrlOutBlock2.SetItemText( 0, nCol++, GetDispData( pAllOutBlock->outBlock2.PrdayKseSubstMgn      , sizeof( pAllOutBlock->outBlock2.PrdayKseSubstMgn       ), DATA_TYPE_LONG   ) );    // [long  ,   16] ����KSE������ű�            
		m_ctrlOutBlock2.SetItemText( 0, nCol++, GetDispData( pAllOutBlock->outBlock2.PrdayKseCrdtMnyMgn    , sizeof( pAllOutBlock->outBlock2.PrdayKseCrdtMnyMgn     ), DATA_TYPE_LONG   ) );    // [long  ,   16] ����KSE�ſ��������ű�        
		m_ctrlOutBlock2.SetItemText( 0, nCol++, GetDispData( pAllOutBlock->outBlock2.PrdayKseCrdtSubstMgn  , sizeof( pAllOutBlock->outBlock2.PrdayKseCrdtSubstMgn   ), DATA_TYPE_LONG   ) );    // [long  ,   16] ����KSE�ſ������ű�        
		m_ctrlOutBlock2.SetItemText( 0, nCol++, GetDispData( pAllOutBlock->outBlock2.CrdayKseMnyMgn        , sizeof( pAllOutBlock->outBlock2.CrdayKseMnyMgn         ), DATA_TYPE_LONG   ) );    // [long  ,   16] ����KSE�������ű�            
		m_ctrlOutBlock2.SetItemText( 0, nCol++, GetDispData( pAllOutBlock->outBlock2.CrdayKseSubstMgn      , sizeof( pAllOutBlock->outBlock2.CrdayKseSubstMgn       ), DATA_TYPE_LONG   ) );    // [long  ,   16] ����KSE������ű�            
		m_ctrlOutBlock2.SetItemText( 0, nCol++, GetDispData( pAllOutBlock->outBlock2.CrdayKseCrdtMnyMgn    , sizeof( pAllOutBlock->outBlock2.CrdayKseCrdtMnyMgn     ), DATA_TYPE_LONG   ) );    // [long  ,   16] ����KSE�ſ��������ű�        
		m_ctrlOutBlock2.SetItemText( 0, nCol++, GetDispData( pAllOutBlock->outBlock2.CrdayKseCrdtSubstMgn  , sizeof( pAllOutBlock->outBlock2.CrdayKseCrdtSubstMgn   ), DATA_TYPE_LONG   ) );    // [long  ,   16] ����KSE�ſ������ű�        
		m_ctrlOutBlock2.SetItemText( 0, nCol++, GetDispData( pAllOutBlock->outBlock2.PrdayKdqMnyMgn        , sizeof( pAllOutBlock->outBlock2.PrdayKdqMnyMgn         ), DATA_TYPE_LONG   ) );    // [long  ,   16] �����ڽ����������ű�         
		m_ctrlOutBlock2.SetItemText( 0, nCol++, GetDispData( pAllOutBlock->outBlock2.PrdayKdqSubstMgn      , sizeof( pAllOutBlock->outBlock2.PrdayKdqSubstMgn       ), DATA_TYPE_LONG   ) );    // [long  ,   16] �����ڽ��ڴ�����ű�         
		m_ctrlOutBlock2.SetItemText( 0, nCol++, GetDispData( pAllOutBlock->outBlock2.PrdayKdqCrdtMnyMgn    , sizeof( pAllOutBlock->outBlock2.PrdayKdqCrdtMnyMgn     ), DATA_TYPE_LONG   ) );    // [long  ,   16] �����ڽ��ڽſ��������ű�     
		m_ctrlOutBlock2.SetItemText( 0, nCol++, GetDispData( pAllOutBlock->outBlock2.PrdayKdqCrdtSubstMgn  , sizeof( pAllOutBlock->outBlock2.PrdayKdqCrdtSubstMgn   ), DATA_TYPE_LONG   ) );    // [long  ,   16] �����ڽ��ڽſ������ű�     
		m_ctrlOutBlock2.SetItemText( 0, nCol++, GetDispData( pAllOutBlock->outBlock2.CrdayKdqMnyMgn        , sizeof( pAllOutBlock->outBlock2.CrdayKdqMnyMgn         ), DATA_TYPE_LONG   ) );    // [long  ,   16] �����ڽ����������ű�         
		m_ctrlOutBlock2.SetItemText( 0, nCol++, GetDispData( pAllOutBlock->outBlock2.CrdayKdqSubstMgn      , sizeof( pAllOutBlock->outBlock2.CrdayKdqSubstMgn       ), DATA_TYPE_LONG   ) );    // [long  ,   16] �����ڽ��ڴ�����ű�         
		m_ctrlOutBlock2.SetItemText( 0, nCol++, GetDispData( pAllOutBlock->outBlock2.CrdayKdqCrdtMnyMgn    , sizeof( pAllOutBlock->outBlock2.CrdayKdqCrdtMnyMgn     ), DATA_TYPE_LONG   ) );    // [long  ,   16] �����ڽ��ڽſ��������ű�     
		m_ctrlOutBlock2.SetItemText( 0, nCol++, GetDispData( pAllOutBlock->outBlock2.CrdayKdqCrdtSubstMgn  , sizeof( pAllOutBlock->outBlock2.CrdayKdqCrdtSubstMgn   ), DATA_TYPE_LONG   ) );    // [long  ,   16] �����ڽ��ڽſ������ű�     
		m_ctrlOutBlock2.SetItemText( 0, nCol++, GetDispData( pAllOutBlock->outBlock2.PrdayFrbrdMnyMgn      , sizeof( pAllOutBlock->outBlock2.PrdayFrbrdMnyMgn       ), DATA_TYPE_LONG   ) );    // [long  ,   16] �������������������ű�       
		m_ctrlOutBlock2.SetItemText( 0, nCol++, GetDispData( pAllOutBlock->outBlock2.PrdayFrbrdSubstMgn    , sizeof( pAllOutBlock->outBlock2.PrdayFrbrdSubstMgn     ), DATA_TYPE_LONG   ) );    // [long  ,   16] �����������������ű�       
		m_ctrlOutBlock2.SetItemText( 0, nCol++, GetDispData( pAllOutBlock->outBlock2.CrdayFrbrdMnyMgn      , sizeof( pAllOutBlock->outBlock2.CrdayFrbrdMnyMgn       ), DATA_TYPE_LONG   ) );    // [long  ,   16] �������������������ű�       
		m_ctrlOutBlock2.SetItemText( 0, nCol++, GetDispData( pAllOutBlock->outBlock2.CrdayFrbrdSubstMgn    , sizeof( pAllOutBlock->outBlock2.CrdayFrbrdSubstMgn     ), DATA_TYPE_LONG   ) );    // [long  ,   16] �����������������ű�       
		m_ctrlOutBlock2.SetItemText( 0, nCol++, GetDispData( pAllOutBlock->outBlock2.PrdayCrbmkMnyMgn      , sizeof( pAllOutBlock->outBlock2.PrdayCrbmkMnyMgn       ), DATA_TYPE_LONG   ) );    // [long  ,   16] ��������������ű�           
		m_ctrlOutBlock2.SetItemText( 0, nCol++, GetDispData( pAllOutBlock->outBlock2.PrdayCrbmkSubstMgn    , sizeof( pAllOutBlock->outBlock2.PrdayCrbmkSubstMgn     ), DATA_TYPE_LONG   ) );    // [long  ,   16] ������ܴ�����ű�           
		m_ctrlOutBlock2.SetItemText( 0, nCol++, GetDispData( pAllOutBlock->outBlock2.CrdayCrbmkMnyMgn      , sizeof( pAllOutBlock->outBlock2.CrdayCrbmkMnyMgn       ), DATA_TYPE_LONG   ) );    // [long  ,   16] ��������������ű�           
		m_ctrlOutBlock2.SetItemText( 0, nCol++, GetDispData( pAllOutBlock->outBlock2.CrdayCrbmkSubstMgn    , sizeof( pAllOutBlock->outBlock2.CrdayCrbmkSubstMgn     ), DATA_TYPE_LONG   ) );    // [long  ,   16] ������ܴ�����ű�           
		m_ctrlOutBlock2.SetItemText( 0, nCol++, GetDispData( pAllOutBlock->outBlock2.DpspdgQty             , sizeof( pAllOutBlock->outBlock2.DpspdgQty              ), DATA_TYPE_LONG   ) );    // [long  ,   16] ��Ź�㺸����                 
		m_ctrlOutBlock2.SetItemText( 0, nCol++, GetDispData( pAllOutBlock->outBlock2.BuyAdjstAmtD2         , sizeof( pAllOutBlock->outBlock2.BuyAdjstAmtD2          ), DATA_TYPE_LONG   ) );    // [long  ,   16] �ż������(D+2)              
		m_ctrlOutBlock2.SetItemText( 0, nCol++, GetDispData( pAllOutBlock->outBlock2.SellAdjstAmtD2        , sizeof( pAllOutBlock->outBlock2.SellAdjstAmtD2         ), DATA_TYPE_LONG   ) );    // [long  ,   16] �ŵ������(D+2)              
		m_ctrlOutBlock2.SetItemText( 0, nCol++, GetDispData( pAllOutBlock->outBlock2.RepayRqrdAmtD1        , sizeof( pAllOutBlock->outBlock2.RepayRqrdAmtD1         ), DATA_TYPE_LONG   ) );    // [long  ,   16] �����ҿ��(D+1)              
		m_ctrlOutBlock2.SetItemText( 0, nCol++, GetDispData( pAllOutBlock->outBlock2.RepayRqrdAmtD2        , sizeof( pAllOutBlock->outBlock2.RepayRqrdAmtD2         ), DATA_TYPE_LONG   ) );    // [long  ,   16] �����ҿ��(D+2)              
		m_ctrlOutBlock2.SetItemText( 0, nCol++, GetDispData( pAllOutBlock->outBlock2.LoanAmt               , sizeof( pAllOutBlock->outBlock2.LoanAmt                ), DATA_TYPE_LONG   ) );    // [long  ,   16] ����ݾ�                     
		
		
		//------------------------------------------------
		// OutBlock3
		
		// Count ���
		nDataLength -= 5;
		if( nDataLength < 0 )
		{
			return 0L;
		}

		CopyMemory( szCount, pAllOutBlock->sCountOutBlock3, 5 );
		nCount = atoi( szCount );

		// Data
		nDataLength -= sizeof( CSPAQ12300OutBlock3 ) * nCount;
		if( nDataLength < 0 )
		{
			return 0L;
		}

		for( int i=0; i<nCount; i++ )
		{
			nCol = 0;
			nRow = m_ctrlOutBlock3.InsertItem( m_ctrlOutBlock3.GetItemCount(), "" );
			m_ctrlOutBlock3.SetItemText( nRow, nCol++, GetDispData( pAllOutBlock->outBlock3[i].IsuNo           , sizeof( pAllOutBlock->outBlock3[i].IsuNo            ), DATA_TYPE_STRING ) );    // [string,   12] �����ȣ            
			m_ctrlOutBlock3.SetItemText( nRow, nCol++, GetDispData( pAllOutBlock->outBlock3[i].IsuNm           , sizeof( pAllOutBlock->outBlock3[i].IsuNm            ), DATA_TYPE_STRING ) );    // [string,   40] �����              
			m_ctrlOutBlock3.SetItemText( nRow, nCol++, GetDispData( pAllOutBlock->outBlock3[i].SecBalPtnCode   , sizeof( pAllOutBlock->outBlock3[i].SecBalPtnCode    ), DATA_TYPE_STRING ) );    // [string,    2] ���������ܰ������ڵ�
			m_ctrlOutBlock3.SetItemText( nRow, nCol++, GetDispData( pAllOutBlock->outBlock3[i].SecBalPtnNm     , sizeof( pAllOutBlock->outBlock3[i].SecBalPtnNm      ), DATA_TYPE_STRING ) );    // [string,   40] ���������ܰ�������  
			m_ctrlOutBlock3.SetItemText( nRow, nCol++, GetDispData( pAllOutBlock->outBlock3[i].BalQty          , sizeof( pAllOutBlock->outBlock3[i].BalQty           ), DATA_TYPE_LONG   ) );    // [long  ,   16] �ܰ����            
			m_ctrlOutBlock3.SetItemText( nRow, nCol++, GetDispData( pAllOutBlock->outBlock3[i].BnsBaseBalQty   , sizeof( pAllOutBlock->outBlock3[i].BnsBaseBalQty    ), DATA_TYPE_LONG   ) );    // [long  ,   16] �Ÿű����ܰ����    
			m_ctrlOutBlock3.SetItemText( nRow, nCol++, GetDispData( pAllOutBlock->outBlock3[i].CrdayBuyExecQty , sizeof( pAllOutBlock->outBlock3[i].CrdayBuyExecQty  ), DATA_TYPE_LONG   ) );    // [long  ,   16] ���ϸż�ü�����    
			m_ctrlOutBlock3.SetItemText( nRow, nCol++, GetDispData( pAllOutBlock->outBlock3[i].CrdaySellExecQty, sizeof( pAllOutBlock->outBlock3[i].CrdaySellExecQty ), DATA_TYPE_LONG   ) );    // [long  ,   16] ���ϸŵ�ü�����    
			m_ctrlOutBlock3.SetItemText( nRow, nCol++, GetDispData( pAllOutBlock->outBlock3[i].SellPrc         , sizeof( pAllOutBlock->outBlock3[i].SellPrc          ), DATA_TYPE_DOT, 4 ) );    // [double, 21.4] �ŵ���              
			m_ctrlOutBlock3.SetItemText( nRow, nCol++, GetDispData( pAllOutBlock->outBlock3[i].BuyPrc          , sizeof( pAllOutBlock->outBlock3[i].BuyPrc           ), DATA_TYPE_DOT, 4 ) );    // [double, 21.4] �ż���              
			m_ctrlOutBlock3.SetItemText( nRow, nCol++, GetDispData( pAllOutBlock->outBlock3[i].SellPnlAmt      , sizeof( pAllOutBlock->outBlock3[i].SellPnlAmt       ), DATA_TYPE_LONG   ) );    // [long  ,   16] �ŵ����ͱݾ�        
			m_ctrlOutBlock3.SetItemText( nRow, nCol++, GetDispData( pAllOutBlock->outBlock3[i].PnlRat          , sizeof( pAllOutBlock->outBlock3[i].PnlRat           ), DATA_TYPE_DOT, 6 ) );    // [double, 18.6] ������              
			m_ctrlOutBlock3.SetItemText( nRow, nCol++, GetDispData( pAllOutBlock->outBlock3[i].NowPrc          , sizeof( pAllOutBlock->outBlock3[i].NowPrc           ), DATA_TYPE_DOT, 2 ) );    // [double, 15.2] ���簡              
			m_ctrlOutBlock3.SetItemText( nRow, nCol++, GetDispData( pAllOutBlock->outBlock3[i].CrdtAmt         , sizeof( pAllOutBlock->outBlock3[i].CrdtAmt          ), DATA_TYPE_LONG   ) );    // [long  ,   16] �ſ�ݾ�            
			m_ctrlOutBlock3.SetItemText( nRow, nCol++, GetDispData( pAllOutBlock->outBlock3[i].DueDt           , sizeof( pAllOutBlock->outBlock3[i].DueDt            ), DATA_TYPE_STRING ) );    // [string,    8] ������              
			m_ctrlOutBlock3.SetItemText( nRow, nCol++, GetDispData( pAllOutBlock->outBlock3[i].PrdaySellExecPrc, sizeof( pAllOutBlock->outBlock3[i].PrdaySellExecPrc ), DATA_TYPE_DOT, 2 ) );    // [double, 13.2] ���ϸŵ�ü�ᰡ      
			m_ctrlOutBlock3.SetItemText( nRow, nCol++, GetDispData( pAllOutBlock->outBlock3[i].PrdaySellQty    , sizeof( pAllOutBlock->outBlock3[i].PrdaySellQty     ), DATA_TYPE_LONG   ) );    // [long  ,   16] ���ϸŵ�����        
			m_ctrlOutBlock3.SetItemText( nRow, nCol++, GetDispData( pAllOutBlock->outBlock3[i].PrdayBuyExecPrc , sizeof( pAllOutBlock->outBlock3[i].PrdayBuyExecPrc  ), DATA_TYPE_DOT, 2 ) );    // [double, 13.2] ���ϸż�ü�ᰡ      
			m_ctrlOutBlock3.SetItemText( nRow, nCol++, GetDispData( pAllOutBlock->outBlock3[i].PrdayBuyQty     , sizeof( pAllOutBlock->outBlock3[i].PrdayBuyQty      ), DATA_TYPE_LONG   ) );    // [long  ,   16] ���ϸż�����        
			m_ctrlOutBlock3.SetItemText( nRow, nCol++, GetDispData( pAllOutBlock->outBlock3[i].LoanDt          , sizeof( pAllOutBlock->outBlock3[i].LoanDt           ), DATA_TYPE_STRING ) );    // [string,    8] ������              
			m_ctrlOutBlock3.SetItemText( nRow, nCol++, GetDispData( pAllOutBlock->outBlock3[i].AvrUprc         , sizeof( pAllOutBlock->outBlock3[i].AvrUprc          ), DATA_TYPE_DOT, 2 ) );    // [double, 13.2] ��մܰ�            
			m_ctrlOutBlock3.SetItemText( nRow, nCol++, GetDispData( pAllOutBlock->outBlock3[i].SellAbleQty     , sizeof( pAllOutBlock->outBlock3[i].SellAbleQty      ), DATA_TYPE_LONG   ) );    // [long  ,   16] �ŵ����ɼ���        
			m_ctrlOutBlock3.SetItemText( nRow, nCol++, GetDispData( pAllOutBlock->outBlock3[i].SellOrdQty      , sizeof( pAllOutBlock->outBlock3[i].SellOrdQty       ), DATA_TYPE_LONG   ) );    // [long  ,   16] �ŵ��ֹ�����        
			m_ctrlOutBlock3.SetItemText( nRow, nCol++, GetDispData( pAllOutBlock->outBlock3[i].CrdayBuyExecAmt , sizeof( pAllOutBlock->outBlock3[i].CrdayBuyExecAmt  ), DATA_TYPE_LONG   ) );    // [long  ,   16] ���ϸż�ü��ݾ�    
			m_ctrlOutBlock3.SetItemText( nRow, nCol++, GetDispData( pAllOutBlock->outBlock3[i].CrdaySellExecAmt, sizeof( pAllOutBlock->outBlock3[i].CrdaySellExecAmt ), DATA_TYPE_LONG   ) );    // [long  ,   16] ���ϸŵ�ü��ݾ�    
			m_ctrlOutBlock3.SetItemText( nRow, nCol++, GetDispData( pAllOutBlock->outBlock3[i].PrdayBuyExecAmt , sizeof( pAllOutBlock->outBlock3[i].PrdayBuyExecAmt  ), DATA_TYPE_LONG   ) );    // [long  ,   16] ���ϸż�ü��ݾ�    
			m_ctrlOutBlock3.SetItemText( nRow, nCol++, GetDispData( pAllOutBlock->outBlock3[i].PrdaySellExecAmt, sizeof( pAllOutBlock->outBlock3[i].PrdaySellExecAmt ), DATA_TYPE_LONG   ) );    // [long  ,   16] ���ϸŵ�ü��ݾ�    
			m_ctrlOutBlock3.SetItemText( nRow, nCol++, GetDispData( pAllOutBlock->outBlock3[i].BalEvalAmt      , sizeof( pAllOutBlock->outBlock3[i].BalEvalAmt       ), DATA_TYPE_LONG   ) );    // [long  ,   16] �ܰ��򰡱ݾ�        
			m_ctrlOutBlock3.SetItemText( nRow, nCol++, GetDispData( pAllOutBlock->outBlock3[i].EvalPnl         , sizeof( pAllOutBlock->outBlock3[i].EvalPnl          ), DATA_TYPE_LONG   ) );    // [long  ,   16] �򰡼���            
			m_ctrlOutBlock3.SetItemText( nRow, nCol++, GetDispData( pAllOutBlock->outBlock3[i].MnyOrdAbleAmt   , sizeof( pAllOutBlock->outBlock3[i].MnyOrdAbleAmt    ), DATA_TYPE_LONG   ) );    // [long  ,   16] �����ֹ����ɱݾ�    
			m_ctrlOutBlock3.SetItemText( nRow, nCol++, GetDispData( pAllOutBlock->outBlock3[i].OrdAbleAmt      , sizeof( pAllOutBlock->outBlock3[i].OrdAbleAmt       ), DATA_TYPE_LONG   ) );    // [long  ,   16] �ֹ����ɱݾ�        
			m_ctrlOutBlock3.SetItemText( nRow, nCol++, GetDispData( pAllOutBlock->outBlock3[i].SellUnercQty    , sizeof( pAllOutBlock->outBlock3[i].SellUnercQty     ), DATA_TYPE_LONG   ) );    // [long  ,   16] �ŵ���ü�����      
			m_ctrlOutBlock3.SetItemText( nRow, nCol++, GetDispData( pAllOutBlock->outBlock3[i].SellUnsttQty    , sizeof( pAllOutBlock->outBlock3[i].SellUnsttQty     ), DATA_TYPE_LONG   ) );    // [long  ,   16] �ŵ��̰�������      
			m_ctrlOutBlock3.SetItemText( nRow, nCol++, GetDispData( pAllOutBlock->outBlock3[i].BuyUnercQty     , sizeof( pAllOutBlock->outBlock3[i].BuyUnercQty      ), DATA_TYPE_LONG   ) );    // [long  ,   16] �ż���ü�����      
			m_ctrlOutBlock3.SetItemText( nRow, nCol++, GetDispData( pAllOutBlock->outBlock3[i].BuyUnsttQty     , sizeof( pAllOutBlock->outBlock3[i].BuyUnsttQty      ), DATA_TYPE_LONG   ) );    // [long  ,   16] �ż��̰�������      
			m_ctrlOutBlock3.SetItemText( nRow, nCol++, GetDispData( pAllOutBlock->outBlock3[i].UnsttQty        , sizeof( pAllOutBlock->outBlock3[i].UnsttQty         ), DATA_TYPE_LONG   ) );    // [long  ,   16] �̰�������          
			m_ctrlOutBlock3.SetItemText( nRow, nCol++, GetDispData( pAllOutBlock->outBlock3[i].UnercQty        , sizeof( pAllOutBlock->outBlock3[i].UnercQty         ), DATA_TYPE_LONG   ) );    // [long  ,   16] ��ü�����          
			m_ctrlOutBlock3.SetItemText( nRow, nCol++, GetDispData( pAllOutBlock->outBlock3[i].PrdayCprc       , sizeof( pAllOutBlock->outBlock3[i].PrdayCprc        ), DATA_TYPE_DOT, 2 ) );    // [double, 15.2] ��������            
			m_ctrlOutBlock3.SetItemText( nRow, nCol++, GetDispData( pAllOutBlock->outBlock3[i].PchsAmt         , sizeof( pAllOutBlock->outBlock3[i].PchsAmt          ), DATA_TYPE_LONG   ) );    // [long  ,   16] ���Աݾ�            
			m_ctrlOutBlock3.SetItemText( nRow, nCol++, GetDispData( pAllOutBlock->outBlock3[i].RegMktCode      , sizeof( pAllOutBlock->outBlock3[i].RegMktCode       ), DATA_TYPE_STRING ) );    // [string,    2] ��Ͻ����ڵ�        
			m_ctrlOutBlock3.SetItemText( nRow, nCol++, GetDispData( pAllOutBlock->outBlock3[i].LoanDtlClssCode , sizeof( pAllOutBlock->outBlock3[i].LoanDtlClssCode  ), DATA_TYPE_STRING ) );    // [string,    2] ����󼼺з��ڵ�    
			m_ctrlOutBlock3.SetItemText( nRow, nCol++, GetDispData( pAllOutBlock->outBlock3[i].DpspdgLoanQty   , sizeof( pAllOutBlock->outBlock3[i].DpspdgLoanQty    ), DATA_TYPE_LONG   ) );    // [long  ,   16] ��Ź�㺸�������    
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
LRESULT CDlg_CSPAQ02300::OnXMTimeoutData( WPARAM wParam, LPARAM lParam )
{
	g_iXingAPI.ReleaseRequestData( (int)lParam );
	GetParent()->SendMessage( WMU_SET_MESSAGE, (WPARAM)"", (LPARAM)"Timeout" );		

	return 0L;
}
