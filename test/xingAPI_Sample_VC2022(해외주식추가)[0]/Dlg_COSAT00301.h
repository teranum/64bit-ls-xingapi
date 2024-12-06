#if !defined(AFX_DLG_COSAT00301_H__320B01BC_6300_4A45_85AE_83D9FF2AFDCF__INCLUDED_)
#define AFX_DLG_COSAT00301_H__320B01BC_6300_4A45_85AE_83D9FF2AFDCF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Dlg_COSAT00301.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlg_COSAT00301 dialog

class CDlg_COSAT00301 : public CDialog
{
	DECLARE_DYNCREATE( CDlg_COSAT00301 )
		
// Construction
public:
	CDlg_COSAT00301(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlg_COSAT00301)
	enum { IDD = IDD_CFOAT00100 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlg_CFOAT00100)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	CListCtrl			m_ctrlOutBlock1;
	CListCtrl			m_ctrlOutBlock2;
	void				InitCtrls();
	void				RequestData( BOOL bNext=FALSE );

	// Generated message map functions
	//{{AFX_MSG(CDlg_CFOAT00100)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	afx_msg void		OnButtonRequest		();
	afx_msg	LRESULT		OnXMReceiveData		( WPARAM wParam, LPARAM lParam );
	afx_msg	LRESULT		OnXMTimeoutData		( WPARAM wParam, LPARAM lParam );
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLG_COSAT00301_H__320B01BC_6300_4A45_85AE_83D9FF2AFDCF__INCLUDED_)
