
// MFCApplication7Dlg.h: 头文件
//

#pragma once

class CMFCApplication7DlgAutoProxy;


// CMFCApplication7Dlg 对话框
class CMFCApplication7Dlg : public CDialogEx
{
	DECLARE_DYNAMIC(CMFCApplication7Dlg);
	friend class CMFCApplication7DlgAutoProxy;

// 构造
public:
	CMFCApplication7Dlg(CWnd* pParent = nullptr);	// 标准构造函数
	virtual ~CMFCApplication7Dlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCAPPLICATION7_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	CMFCApplication7DlgAutoProxy* m_pAutoProxy;
	HICON m_hIcon;

	BOOL CanExit();

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnClose();
	virtual void OnOK();
	virtual void OnCancel();
	DECLARE_MESSAGE_MAP()
};
