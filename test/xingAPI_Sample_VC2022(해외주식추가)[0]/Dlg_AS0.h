#if !defined(AFX_DLG_AS0_H__B04CF47B_7090_428F_A74A_3BDEF74BB5E8__INCLUDED_)
#define AFX_DLG_AS0_H__B04CF47B_7090_428F_A74A_3BDEF74BB5E8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Dlg_AS0.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlg_AS0 dialog

class CDlg_AS0 : public CDialog
{
	DECLARE_DYNCREATE( CDlg_AS0 )
// Construction
public:
	CDlg_AS0(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlg_AS0)
	enum { IDD = IDD_AS0 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlg_AS0)
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
	//{{AFX_MSG(CDlg_AS0)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	afx_msg void		OnDestroy();
	afx_msg	LRESULT		OnXMReceiveRealData	( WPARAM wParam, LPARAM lParam );
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLG_AS0_H__B04CF47B_7090_428F_A74A_3BDEF74BB5E8__INCLUDED_)
