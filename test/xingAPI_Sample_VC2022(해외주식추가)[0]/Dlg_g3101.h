#if !defined(AFX_DLG_G3101_H__011EDD60_0251_451C_ACE5_FE21B12283B7__INCLUDED_)
#define AFX_DLG_G3101_H__011EDD60_0251_451C_ACE5_FE21B12283B7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Dlg_g3101.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlg_g3101 dialog

class CDlg_g3101 : public CDialog
{
	DECLARE_DYNCREATE( CDlg_g3101 )
// Construction
public:
	CDlg_g3101();   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlg_g3101)
	enum { IDD = IDD_g3101 };
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlg_g3101)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	CListCtrl			m_ctrlOutBlock;
	void				InitCtrls();
	void				RequestData( BOOL bNext=FALSE );

	// Generated message map functions
	//{{AFX_MSG(CDlg_g3101)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	afx_msg void		OnButtonRequest		();
	afx_msg	LRESULT		OnXMReceiveData		( WPARAM wParam, LPARAM lParam );
	afx_msg	LRESULT		OnXMTimeoutData		( WPARAM wParam, LPARAM lParam );
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLG_G3101_H__011EDD60_0251_451C_ACE5_FE21B12283B7__INCLUDED_)
