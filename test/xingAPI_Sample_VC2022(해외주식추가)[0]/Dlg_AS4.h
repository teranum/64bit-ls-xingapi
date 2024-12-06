#if !defined(AFX_DLG_AS4_H__710B3EC0_37CD_46A6_B0FC_4B721A0641E3__INCLUDED_)
#define AFX_DLG_AS4_H__710B3EC0_37CD_46A6_B0FC_4B721A0641E3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Dlg_AS4.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlg_AS4 dialog

class CDlg_AS4 : public CDialog
{
	DECLARE_DYNCREATE( CDlg_AS4 )
// Construction
public:
	CDlg_AS4(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlg_AS4)
	enum { IDD = IDD_AS4 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlg_AS4)
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
	//{{AFX_MSG(CDlg_AS4)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	afx_msg void		OnDestroy();
	afx_msg	LRESULT		OnXMReceiveRealData	( WPARAM wParam, LPARAM lParam );
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLG_AS4_H__710B3EC0_37CD_46A6_B0FC_4B721A0641E3__INCLUDED_)
