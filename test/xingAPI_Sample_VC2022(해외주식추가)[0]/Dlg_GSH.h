#if !defined(AFX_DLG_GSH_H__11644FEF_9B35_4F5C_AFD8_21E8183FBBDA__INCLUDED_)
#define AFX_DLG_GSH_H__11644FEF_9B35_4F5C_AFD8_21E8183FBBDA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Dlg_GSH.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlg_GSH dialog

class CDlg_GSH : public CDialog
{
	DECLARE_DYNCREATE( CDlg_GSH )
		// Construction
public:
	CDlg_GSH(CWnd* pParent = NULL);   // standard constructor
	
	// Dialog Data
	//{{AFX_DATA(CDlg_GSH)
	enum { IDD = IDD_GSH };
	// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA
	
	
	// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlg_GSH)
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL
	
	// Implementation
protected:
	CString				m_strCode;
	CListCtrl			m_ctrlOutBlock;
	void				InitCtrls();
	void				AdviseData();
	void				UnadviseData();
	
	// Generated message map functions
	//{{AFX_MSG(CDlg_GSH)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	afx_msg void		OnDestroy();
	afx_msg void		OnButtonRequest		();
	afx_msg	LRESULT		OnXMReceiveRealData	( WPARAM wParam, LPARAM lParam );
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLG_GSH_H__11644FEF_9B35_4F5C_AFD8_21E8183FBBDA__INCLUDED_)
