#if !defined(AFX_DLG_G3202_H__5DFC2B5D_CF0D_4E7C_9A9C_DAE55212E6A2__INCLUDED_)
#define AFX_DLG_G3202_H__5DFC2B5D_CF0D_4E7C_9A9C_DAE55212E6A2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Dlg_g3202.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlg_g3202 dialog

class CDlg_g3202 : public CDialog
{
	DECLARE_DYNCREATE( CDlg_g3202 )

// Construction
public:
	CDlg_g3202(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlg_g3202)
	enum { IDD = IDD_g3202 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlg_g3202)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	CListCtrl			m_ctrlOutBlock;
	CListCtrl			m_ctrlOutBlock1;
	void				InitCtrls();
	void				RequestData( BOOL bNext );

	BOOL				m_bCompress;

	// Generated message map functions
	//{{AFX_MSG(CDlg_t1301)
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

#endif // !defined(AFX_DLG_G3202_H__5DFC2B5D_CF0D_4E7C_9A9C_DAE55212E6A2__INCLUDED_)
