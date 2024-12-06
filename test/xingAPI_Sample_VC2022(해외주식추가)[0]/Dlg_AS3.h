#if !defined(AFX_DLG_AS3_H__29445288_B93B_4972_A7B8_63F3272DF90C__INCLUDED_)
#define AFX_DLG_AS3_H__29445288_B93B_4972_A7B8_63F3272DF90C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Dlg_AS3.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlg_AS3 dialog

class CDlg_AS3 : public CDialog
{
	DECLARE_DYNCREATE( CDlg_AS3 )
// Construction
public:
	CDlg_AS3(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlg_AS3)
	enum { IDD = IDD_AS3 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlg_AS3)
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
	//{{AFX_MSG(CDlg_AS3)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	afx_msg void		OnDestroy();
	afx_msg	LRESULT		OnXMReceiveRealData	( WPARAM wParam, LPARAM lParam );
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLG_AS3_H__29445288_B93B_4972_A7B8_63F3272DF90C__INCLUDED_)
