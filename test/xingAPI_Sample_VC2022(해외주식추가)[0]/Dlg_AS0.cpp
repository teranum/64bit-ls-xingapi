// Dlg_AS0.cpp : implementation file
//

#include "stdafx.h"
#include "XingAPI_Sample.h"
#include "Dlg_AS0.h"

#include "./Packet/AS0.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlg_AS0 dialog

IMPLEMENT_DYNCREATE(CDlg_AS0, CDialog)

CDlg_AS0::CDlg_AS0(CWnd* pParent /*=NULL*/)
	: CDialog(CDlg_AS0::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlg_AS0)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CDlg_AS0::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlg_AS0)
	DDX_Control(pDX, IDC_OUTBLOCK, m_ctrlOutBlock);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlg_AS0, CDialog)
	//{{AFX_MSG_MAP(CDlg_AS0)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
	ON_WM_DESTROY()
	ON_MESSAGE	 ( WM_USER + XM_RECEIVE_REAL_DATA,	OnXMReceiveRealData	)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlg_AS0 message handlers

BOOL CDlg_AS0::OnInitDialog() 
{
	CDialog::OnInitDialog();

	// �ֹ��� ���õ� �ǽð�TR�� �Է°��� �����Ƿ� ȭ���� ���µɶ� ����Ѵ�.
	AdviseData();

	InitCtrls();
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CDlg_AS0::OnDestroy()
{
	UnadviseData();

	CDialog::OnDestroy();
}

//--------------------------------------------------------------------------------------
// ��Ʈ�� �ʱ�ȭ
//--------------------------------------------------------------------------------------
void CDlg_AS0::InitCtrls()
{
	//-------------------------------------------------------------------------
	// OutBlock
	m_ctrlOutBlock.InsertColumn( 0, "�ʵ�  ", LVCFMT_LEFT, 150 );
	m_ctrlOutBlock.InsertColumn( 1, "������", LVCFMT_LEFT, 200 );

	int nRow = 0;
	m_ctrlOutBlock.InsertItem( nRow++, "�����Ϸù�ȣ        " );
	m_ctrlOutBlock.InsertItem( nRow++, "���¹�ȣ          " );
	m_ctrlOutBlock.InsertItem( nRow++, "������ID           " );
	m_ctrlOutBlock.InsertItem( nRow++, "�������          " );
	m_ctrlOutBlock.InsertItem( nRow++, "�������          " );
	m_ctrlOutBlock.InsertItem( nRow++, "���౸��          " );
	m_ctrlOutBlock.InsertItem( nRow++, "��ȣ����          " );
	m_ctrlOutBlock.InsertItem( nRow++, "�����������        " );
	m_ctrlOutBlock.InsertItem( nRow++, "TRCODE          " );
	m_ctrlOutBlock.InsertItem( nRow++, "�̿���ȣ         " );
	m_ctrlOutBlock.InsertItem( nRow++, "�����ID           " );
	m_ctrlOutBlock.InsertItem( nRow++, "���Ӹ�ü          " );
	m_ctrlOutBlock.InsertItem( nRow++, "I/F�Ϸù�ȣ       " );
	m_ctrlOutBlock.InsertItem( nRow++, "�����Ϸù�ȣ        " );
	m_ctrlOutBlock.InsertItem( nRow++, "TR����ID          " );
	m_ctrlOutBlock.InsertItem( nRow++, "����IP            " );
	m_ctrlOutBlock.InsertItem( nRow++, "�缳IP            " );
	m_ctrlOutBlock.InsertItem( nRow++, "ó��������ȣ        " );
	m_ctrlOutBlock.InsertItem( nRow++, "������ȣ          " );
	m_ctrlOutBlock.InsertItem( nRow++, "�ܸ���ȣ          " );
	m_ctrlOutBlock.InsertItem( nRow++, "����          " );
	m_ctrlOutBlock.InsertItem( nRow++, "APó���ð�        " );
	m_ctrlOutBlock.InsertItem( nRow++, "�޼����ڵ�         " );
	m_ctrlOutBlock.InsertItem( nRow++, "�޼�����±���       " );
	m_ctrlOutBlock.InsertItem( nRow++, "�����û����        " );
	m_ctrlOutBlock.InsertItem( nRow++, "���Ű             " );
	m_ctrlOutBlock.InsertItem( nRow++, "��û���ڵ尳��       " );
	m_ctrlOutBlock.InsertItem( nRow++, "���񿵿�          " );
	m_ctrlOutBlock.InsertItem( nRow++, "���ӱ���          " );
	m_ctrlOutBlock.InsertItem( nRow++, "����Ű��          " );
	m_ctrlOutBlock.InsertItem( nRow++, "�����ý��۱���       " );
	m_ctrlOutBlock.InsertItem( nRow++, "�����ش�����        " );
	m_ctrlOutBlock.InsertItem( nRow++, "�����޽�������       " );
	m_ctrlOutBlock.InsertItem( nRow++, "��ȸ�߿���         " );
	m_ctrlOutBlock.InsertItem( nRow++, "I/F�̺�ƮID        " );
	m_ctrlOutBlock.InsertItem( nRow++, "I/F����           " );
	m_ctrlOutBlock.InsertItem( nRow++, "���񿵿�          " );
	m_ctrlOutBlock.InsertItem( nRow++, "�ֹ�ü�������ڵ�      " );
	m_ctrlOutBlock.InsertItem( nRow++, "�ֹ������ڵ�        " );
	m_ctrlOutBlock.InsertItem( nRow++, "�ֹ������ڵ�        " );
	m_ctrlOutBlock.InsertItem( nRow++, "���ֹ���ȣ         " );
	m_ctrlOutBlock.InsertItem( nRow++, "���¹�ȣ          " );
	m_ctrlOutBlock.InsertItem( nRow++, "��й�ȣ          " );
	m_ctrlOutBlock.InsertItem( nRow++, "�����ȣ          " );
	m_ctrlOutBlock.InsertItem( nRow++, "���������ȣ        " );
	m_ctrlOutBlock.InsertItem( nRow++, "�����            " );
	m_ctrlOutBlock.InsertItem( nRow++, "�ֹ�����           " );
	m_ctrlOutBlock.InsertItem( nRow++, "�ֹ���            " );
	m_ctrlOutBlock.InsertItem( nRow++, "�ֹ�����          " );
	m_ctrlOutBlock.InsertItem( nRow++, "ȣ�������ڵ�        " );
	m_ctrlOutBlock.InsertItem( nRow++, "�����ڵ�          " );
	m_ctrlOutBlock.InsertItem( nRow++, "�׷�ID           " );
	m_ctrlOutBlock.InsertItem( nRow++, "�ֹ�ȸ��          " );
	m_ctrlOutBlock.InsertItem( nRow++, "��Ÿ�ü�ڵ�        " );
	m_ctrlOutBlock.InsertItem( nRow++, "�ֹ���ȣ          " );
	m_ctrlOutBlock.InsertItem( nRow++, "�ֹ��ð�           " );
	m_ctrlOutBlock.InsertItem( nRow++, "���ֹ���ȣ         " );
	m_ctrlOutBlock.InsertItem( nRow++, "���ֹ���ü�����      " );
	m_ctrlOutBlock.InsertItem( nRow++, "���ֹ���������        " );
	m_ctrlOutBlock.InsertItem( nRow++, "���ֹ���Ҽ���       " );
	m_ctrlOutBlock.InsertItem( nRow++, "��ȸ����۽Ź�ȣ      " );
	m_ctrlOutBlock.InsertItem( nRow++, "�ֹ��ݾ�          " );
	m_ctrlOutBlock.InsertItem( nRow++, "�Ÿű���          " );
	m_ctrlOutBlock.InsertItem( nRow++, "�����ֹ��Ϸù�ȣ      " );
	m_ctrlOutBlock.InsertItem( nRow++, "�ֹ������ȣ        " );
	m_ctrlOutBlock.InsertItem( nRow++, "�ǹ��ֹ�����        " );
	m_ctrlOutBlock.InsertItem( nRow++, "�����ֹ�����       " );
	m_ctrlOutBlock.InsertItem( nRow++, "�ֹ�����          " );
	m_ctrlOutBlock.InsertItem( nRow++, "�ֹ����ݾ�        " );
	m_ctrlOutBlock.InsertItem( nRow++, "�ֹ�����ݾ�       " );
	m_ctrlOutBlock.InsertItem( nRow++, "��������         " );
	m_ctrlOutBlock.InsertItem( nRow++, "�ܰ����          " );
	m_ctrlOutBlock.InsertItem( nRow++, "�ǹ��ֹ����ɼ���       " );
	m_ctrlOutBlock.InsertItem( nRow++, "�ֹ������������    " );
	m_ctrlOutBlock.InsertItem( nRow++, "��������          " );
	m_ctrlOutBlock.InsertItem( nRow++, "�ܰ����(D2)      " );
	m_ctrlOutBlock.InsertItem( nRow++, "�ŵ��ֹ����ɼ���      " );
	m_ctrlOutBlock.InsertItem( nRow++, "��ü��ŵ��ֹ�����    " );
	m_ctrlOutBlock.InsertItem( nRow++, "��ո��԰�         " );
	m_ctrlOutBlock.InsertItem( nRow++, "���Աݾ�          " );
	m_ctrlOutBlock.InsertItem( nRow++, "������            " );
	m_ctrlOutBlock.InsertItem( nRow++, "����            " );
	m_ctrlOutBlock.InsertItem( nRow++, "��Ź�������űݾ�      " );
	m_ctrlOutBlock.InsertItem( nRow++, "��Ź������űݾ�      " );
	m_ctrlOutBlock.InsertItem( nRow++, "�ֹ���������        " );
	m_ctrlOutBlock.InsertItem( nRow++, "�ֹ����ɴ��ݾ�      " );
	m_ctrlOutBlock.InsertItem( nRow++, "���밡�ɱݾ�       " );
	m_ctrlOutBlock.InsertItem( nRow++, "�ſ�ŷ��ڵ�        " );
}

//--------------------------------------------------------------------------------------
// ������ Advise
//--------------------------------------------------------------------------------------
void CDlg_AS0::AdviseData()
{
	TCHAR	szTrCode[]		= "AS0";

	//-----------------------------------------------------------
	// ������ ����
	BOOL bSuccess = g_iXingAPI.AdviseRealData( 
		GetSafeHwnd(),				// �����͸� ���� ������, XM_RECEIVE_REAL_DATA ���� �´�.
		szTrCode,					// TR ��ȣ
		"",							// AS0�� �� �����͸� �Ѱܾ� �Ѵ�.
		0							// AS0�� ������ ���̴� 0�̴�.
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
void CDlg_AS0::UnadviseData()
{
	TCHAR	szTrCode[]		= "AS0";
	
	//-----------------------------------------------------------
	// ������ ����
	BOOL bSuccess = g_iXingAPI.UnadviseRealData( 
		GetSafeHwnd(),				// �����͸� ���� ������, XM_RECEIVE_REAL_DATA ���� �´�.
		szTrCode,					// TR ��ȣ
		"",							// AS0�� �� �����͸� �Ѱܾ� �Ѵ�.
		0							// AS0�� ������ ���̴� 0�̴�.
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
LRESULT CDlg_AS0::OnXMReceiveRealData( WPARAM wParam, LPARAM lParam )
{
	LPRECV_REAL_PACKET pRealPacket = (LPRECV_REAL_PACKET)lParam;

	if( strcmp( pRealPacket->szTrCode, "AS0" ) == 0 )
	{
		LPAS0_OutBlock pOutBlock = (LPAS0_OutBlock)pRealPacket->pszData;
		int nRow = 0;
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->lineseq          , sizeof( pOutBlock->lineseq         ), DATA_TYPE_LONG      ) );    // �����Ϸù�ȣ       
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->accno            , sizeof( pOutBlock->accno           ), DATA_TYPE_STRING    ) );    // ���¹�ȣ         
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->user             , sizeof( pOutBlock->user            ), DATA_TYPE_STRING    ) );    // ������ID         
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->len              , sizeof( pOutBlock->len             ), DATA_TYPE_LONG      ) );    // �������         
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->gubun            , sizeof( pOutBlock->gubun           ), DATA_TYPE_STRING    ) );    // �������          
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->compress         , sizeof( pOutBlock->compress        ), DATA_TYPE_STRING    ) );    // ���౸��         
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->encrypt          , sizeof( pOutBlock->encrypt         ), DATA_TYPE_STRING    ) );    // ��ȣ����         
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->offset           , sizeof( pOutBlock->offset          ), DATA_TYPE_LONG      ) );    // �����������       
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->trcode           , sizeof( pOutBlock->trcode          ), DATA_TYPE_STRING    ) );    // TRCODE        
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->comid            , sizeof( pOutBlock->comid           ), DATA_TYPE_STRING    ) );    // �̿���ȣ        
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->userid           , sizeof( pOutBlock->userid          ), DATA_TYPE_STRING    ) );    // �����ID         
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->media            , sizeof( pOutBlock->media           ), DATA_TYPE_STRING    ) );    // ���Ӹ�ü         
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->ifid             , sizeof( pOutBlock->ifid            ), DATA_TYPE_STRING    ) );    // I/F�Ϸù�ȣ      
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->seq              , sizeof( pOutBlock->seq             ), DATA_TYPE_STRING    ) );    // �����Ϸù�ȣ       
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->trid             , sizeof( pOutBlock->trid            ), DATA_TYPE_STRING    ) );    // TR����ID        
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->pubip            , sizeof( pOutBlock->pubip           ), DATA_TYPE_STRING    ) );    // ����IP          
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->prvip            , sizeof( pOutBlock->prvip           ), DATA_TYPE_STRING    ) );    // �缳IP          
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->pcbpno           , sizeof( pOutBlock->pcbpno          ), DATA_TYPE_STRING    ) );    // ó��������ȣ       
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->bpno             , sizeof( pOutBlock->bpno            ), DATA_TYPE_STRING    ) );    // ������ȣ         
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->termno           , sizeof( pOutBlock->termno          ), DATA_TYPE_STRING    ) );    // �ܸ���ȣ         
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->lang             , sizeof( pOutBlock->lang            ), DATA_TYPE_STRING    ) );    // ����         
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->proctm           , sizeof( pOutBlock->proctm          ), DATA_TYPE_LONG      ) );    // APó���ð�       
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->msgcode          , sizeof( pOutBlock->msgcode         ), DATA_TYPE_STRING    ) );    // �޼����ڵ�        
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->outgu            , sizeof( pOutBlock->outgu           ), DATA_TYPE_STRING    ) );    // �޼�����±���      
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->compreq          , sizeof( pOutBlock->compreq         ), DATA_TYPE_STRING    ) );    // �����û����        
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->funckey          , sizeof( pOutBlock->funckey         ), DATA_TYPE_STRING    ) );    // ���Ű           
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->reqcnt           , sizeof( pOutBlock->reqcnt          ), DATA_TYPE_LONG      ) );    // ��û���ڵ尳��      
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->filler           , sizeof( pOutBlock->filler          ), DATA_TYPE_STRING    ) );    // ���񿵿�          
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->cont             , sizeof( pOutBlock->cont            ), DATA_TYPE_STRING    ) );    // ���ӱ���         
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->contkey          , sizeof( pOutBlock->contkey         ), DATA_TYPE_STRING    ) );    // ����Ű��         
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->varlen           , sizeof( pOutBlock->varlen          ), DATA_TYPE_LONG      ) );    // �����ý��۱���       
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->varhdlen         , sizeof( pOutBlock->varhdlen        ), DATA_TYPE_LONG      ) );    // �����ش�����       
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->varmsglen        , sizeof( pOutBlock->varmsglen       ), DATA_TYPE_LONG      ) );    // �����޽�������      
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->trsrc            , sizeof( pOutBlock->trsrc           ), DATA_TYPE_STRING    ) );    // ��ȸ�߿���        
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->eventid          , sizeof( pOutBlock->eventid         ), DATA_TYPE_STRING    ) );    // I/F�̺�ƮID      
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->ifinfo           , sizeof( pOutBlock->ifinfo          ), DATA_TYPE_STRING    ) );    // I/F����         
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->filler1          , sizeof( pOutBlock->filler1         ), DATA_TYPE_STRING    ) );    // ���񿵿�         
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sOrdxctPtnCode   , sizeof( pOutBlock->sOrdxctPtnCode  ), DATA_TYPE_STRING    ) );    // �ֹ�ü�������ڵ�     
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sOrdMktCode      , sizeof( pOutBlock->sOrdMktCode     ), DATA_TYPE_STRING    ) );    // �ֹ������ڵ�       
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sOrdPtnCode      , sizeof( pOutBlock->sOrdPtnCode     ), DATA_TYPE_STRING    ) );    // �ֹ������ڵ�        
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sOrgOrdNo        , sizeof( pOutBlock->sOrgOrdNo       ), DATA_TYPE_LONG      ) );    // ���ֹ���ȣ         
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sAcntNo          , sizeof( pOutBlock->sAcntNo         ), DATA_TYPE_STRING    ) );    // ���¹�ȣ         
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sPwd             , sizeof( pOutBlock->sPwd            ), DATA_TYPE_STRING    ) );    // ��й�ȣ         
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sIsuNo           , sizeof( pOutBlock->sIsuNo          ), DATA_TYPE_STRING    ) );    // �����ȣ          
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sShtnIsuNo       , sizeof( pOutBlock->sShtnIsuNo      ), DATA_TYPE_STRING    ) );    // ���������ȣ        
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sIsuNm           , sizeof( pOutBlock->sIsuNm          ), DATA_TYPE_STRING    ) );    // �����           
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sOrdQty          , sizeof( pOutBlock->sOrdQty         ), DATA_TYPE_DOUBLE    ) );    // �ֹ�����         
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sOrdPrc          , sizeof( pOutBlock->sOrdPrc         ), DATA_TYPE_DOUBLE    ) );    // �ֹ���           
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sOrdCndi         , sizeof( pOutBlock->sOrdCndi        ), DATA_TYPE_STRING    ) );    // �ֹ�����         
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sOrdprcPtnCode   , sizeof( pOutBlock->sOrdprcPtnCode  ), DATA_TYPE_STRING    ) );    // ȣ�������ڵ�        
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sStrtgCode       , sizeof( pOutBlock->sStrtgCode      ), DATA_TYPE_LONG      ) );    // �����ڵ�          
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sGrpId           , sizeof( pOutBlock->sGrpId          ), DATA_TYPE_STRING    ) );    // �׷�ID          
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sOrdSeqno        , sizeof( pOutBlock->sOrdSeqno       ), DATA_TYPE_STRING    ) );    // �ֹ�ȸ��          
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sCommdaCode      , sizeof( pOutBlock->sCommdaCode     ), DATA_TYPE_STRING    ) );    // ��Ÿ�ü�ڵ�       
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sOrdNo           , sizeof( pOutBlock->sOrdNo          ), DATA_TYPE_STRING    ) );    // �ֹ���ȣ         
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sOrdTime         , sizeof( pOutBlock->sOrdTime        ), DATA_TYPE_STRING    ) );    // �ֹ��ð�         
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sPrntOrdNo       , sizeof( pOutBlock->sPrntOrdNo      ), DATA_TYPE_STRING    ) );    // ���ֹ���ȣ        
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sOrgOrdUnercQty  , sizeof( pOutBlock->sOrgOrdUnercQty ), DATA_TYPE_STRING    ) );    // ���ֹ���ü�����     
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sOrgOrdMdfyQty   , sizeof( pOutBlock->sOrgOrdMdfyQty  ), DATA_TYPE_DOUBLE    ) );    // ���ֹ���������      
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sOrgOrdCancQty   , sizeof( pOutBlock->sOrgOrdCancQty  ), DATA_TYPE_DOUBLE    ) );    // ���ֹ���Ҽ���      
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sNmcpySndNo      , sizeof( pOutBlock->sNmcpySndNo     ), DATA_TYPE_DOUBLE    ) );    // ��ȸ����۽Ź�ȣ     
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sOrdAmt          , sizeof( pOutBlock->sOrdAmt         ), DATA_TYPE_DOUBLE    ) );    // �ֹ��ݾ�         
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sBnsTp           , sizeof( pOutBlock->sBnsTp          ), DATA_TYPE_LONG      ) );    // �Ÿű���         
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sMtiordSeqno     , sizeof( pOutBlock->sMtiordSeqno    ), DATA_TYPE_LONG      ) );    // �����ֹ��Ϸù�ȣ     
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sOrdUserId       , sizeof( pOutBlock->sOrdUserId      ), DATA_TYPE_DOUBLE    ) );    // �ֹ������ȣ       
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sSpotOrdQty      , sizeof( pOutBlock->sSpotOrdQty     ), DATA_TYPE_DOUBLE    ) );    // �ǹ��ֹ�����       
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sRuseOrdQty      , sizeof( pOutBlock->sRuseOrdQty     ), DATA_TYPE_DOUBLE    ) );    // �����ֹ�����      
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sOrdMny          , sizeof( pOutBlock->sOrdMny         ), DATA_TYPE_DOUBLE    ) );    // �ֹ�����         
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sOrdSubstAmt     , sizeof( pOutBlock->sOrdSubstAmt    ), DATA_TYPE_DOUBLE    ) );    // �ֹ����ݾ�       
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sOrdRuseAmt      , sizeof( pOutBlock->sOrdRuseAmt     ), DATA_TYPE_DOUBLE    ) );    // �ֹ�����ݾ�      
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sUseCmsnAmt      , sizeof( pOutBlock->sUseCmsnAmt     ), DATA_TYPE_DOUBLE    ) );    // ��������        
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sSecBalQty       , sizeof( pOutBlock->sSecBalQty      ), DATA_TYPE_DOUBLE    ) );    // �ܰ����         
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sSpotOrdAbleQty  , sizeof( pOutBlock->sSpotOrdAbleQty ), DATA_TYPE_DOUBLE    ) );    // �ǹ��ֹ����ɼ���     
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sOrdAbleRuseQty  , sizeof( pOutBlock->sOrdAbleRuseQty ), DATA_TYPE_DOUBLE    ) );    // �ֹ������������   
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sFlctQty         , sizeof( pOutBlock->sFlctQty        ), DATA_TYPE_DOUBLE    ) );    // ��������         
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sSecBalQtyD2     , sizeof( pOutBlock->sSecBalQtyD2    ), DATA_TYPE_DOUBLE    ) );    // �ܰ����(D2)     
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sSellAbleQty     , sizeof( pOutBlock->sSellAbleQty    ), DATA_TYPE_DOUBLE    ) );    // �ŵ��ֹ����ɼ���     
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sUnercSellOrdQty , sizeof( pOutBlock->sUnercSellOrdQty), DATA_TYPE_DOUBLE    ) );    // ��ü��ŵ��ֹ�����   
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sAvrPchsPrc      , sizeof( pOutBlock->sAvrPchsPrc     ), DATA_TYPE_DOUBLE    ) );    // ��ո��԰�        
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sPchsAmt         , sizeof( pOutBlock->sPchsAmt        ), DATA_TYPE_DOUBLE    ) );    // ���Աݾ�         
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sDeposit         , sizeof( pOutBlock->sDeposit        ), DATA_TYPE_DOUBLE    ) );    // ������           
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sSubstAmt        , sizeof( pOutBlock->sSubstAmt       ), DATA_TYPE_DOUBLE    ) );    // ����           
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sCsgnMnyMgn      , sizeof( pOutBlock->sCsgnMnyMgn     ), DATA_TYPE_DOUBLE    ) );    // ��Ź�������űݾ�     
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sCsgnSubstMgn    , sizeof( pOutBlock->sCsgnSubstMgn   ), DATA_TYPE_DOUBLE    ) );    // ��Ź������űݾ�     
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sOrdAbleMny      , sizeof( pOutBlock->sOrdAbleMny     ), DATA_TYPE_DOUBLE    ) );    // �ֹ���������       
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sOrdAbleSubstAmt , sizeof( pOutBlock->sOrdAbleSubstAmt), DATA_TYPE_DOUBLE    ) );    // �ֹ����ɴ��ݾ�     
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sRuseAbleAmt     , sizeof( pOutBlock->sRuseAbleAmt    ), DATA_TYPE_DOUBLE    ) );    // ���밡�ɱݾ�      
		m_ctrlOutBlock.SetItemText(  nRow++, 1, GetDispData( pOutBlock->sMgntrnCode      , sizeof( pOutBlock->sMgntrnCode     ), DATA_TYPE_STRING    ) );    // �ſ�ŷ��ڵ�       
	} 
     
	return 0L;
}
