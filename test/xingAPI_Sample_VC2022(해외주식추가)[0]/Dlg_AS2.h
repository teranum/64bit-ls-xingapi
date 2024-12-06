#if !defined(AFX_DLG_AS2_H__E40D1E1A_8E09_43B2_9BC5_3ADDE849DA15__INCLUDED_)
#define AFX_DLG_AS2_H__E40D1E1A_8E09_43B2_9BC5_3ADDE849DA15__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Dlg_AS2.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlg_AS2 dialog

class CDlg_AS2 : public CDialog
{
	DECLARE_DYNCREATE( CDlg_AS2 )
// Construction
public:
	CDlg_AS2(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlg_AS2)
	enum { IDD = IDD_AS2 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlg_AS2)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	CListCtrl			m_ctrlOutBlock;
	void				InitCtrls();
	void				AdviseData();
	void				UnadviseData();
	
	// Generated message map functions
	//{{AFX_MSG(CDlg_AS2)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	afx_msg void		OnDestroy();
	afx_msg	LRESULT		OnXMReceiveRealData	( WPARAM wParam, LPARAM lParam );
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLG_AS2_H__E40D1E1A_8E09_43B2_9BC5_3ADDE849DA15__INCLUDED_)
