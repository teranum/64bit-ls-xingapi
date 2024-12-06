#if !defined(AFX_DLG_COSOQ00201_H__C9C65302_25A4_4C4E_AE5C_B24F97E21FEE__INCLUDED_)
#define AFX_DLG_COSOQ00201_H__C9C65302_25A4_4C4E_AE5C_B24F97E21FEE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Dlg_COSOQ00201.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlg_COSOQ00201 dialog

class CDlg_COSOQ00201 : public CDialog
{
	DECLARE_DYNCREATE( CDlg_COSOQ00201 )
// Construction
public:
	CDlg_COSOQ00201(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlg_COSOQ00201)
	enum { IDD = IDD_COSOQ00201 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlg_COSOQ00201)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	char				m_szContKey[30];

	CListCtrl			m_ctrlOutBlock1;
	CListCtrl			m_ctrlOutBlock2;
	CListCtrl			m_ctrlOutBlock3;
	CListCtrl			m_ctrlOutBlock4;
	void				InitCtrls();
	void				RequestData( BOOL bNext=FALSE );

	// Generated message map functions
	//{{AFX_MSG(CDlg_COSOQ00201)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	afx_msg void		OnButtonRequest		();
	afx_msg void		OnButtonRequestNext	();
	afx_msg	LRESULT		OnXMReceiveData		( WPARAM wParam, LPARAM lParam );
	afx_msg	LRESULT		OnXMTimeoutData		( WPARAM wParam, LPARAM lParam );
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLG_COSOQ00201_H__C9C65302_25A4_4C4E_AE5C_B24F97E21FEE__INCLUDED_)
