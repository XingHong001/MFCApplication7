
// DlgProxy.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "MFCApplication7.h"
#include "DlgProxy.h"
#include "MFCApplication7Dlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication7DlgAutoProxy

IMPLEMENT_DYNCREATE(CMFCApplication7DlgAutoProxy, CCmdTarget)

CMFCApplication7DlgAutoProxy::CMFCApplication7DlgAutoProxy()
{
	EnableAutomation();

	// 为使应用程序在自动化对象处于活动状态时一直保持
	//	运行，构造函数调用 AfxOleLockApp。
	AfxOleLockApp();

	// 通过应用程序的主窗口指针
	//  来访问对话框。  设置代理的内部指针
	//  指向对话框，并设置对话框的后向指针指向
	//  该代理。
	ASSERT_VALID(AfxGetApp()->m_pMainWnd);
	if (AfxGetApp()->m_pMainWnd)
	{
		ASSERT_KINDOF(CMFCApplication7Dlg, AfxGetApp()->m_pMainWnd);
		if (AfxGetApp()->m_pMainWnd->IsKindOf(RUNTIME_CLASS(CMFCApplication7Dlg)))
		{
			m_pDialog = reinterpret_cast<CMFCApplication7Dlg*>(AfxGetApp()->m_pMainWnd);
			m_pDialog->m_pAutoProxy = this;
		}
	}
}

CMFCApplication7DlgAutoProxy::~CMFCApplication7DlgAutoProxy()
{
	// 为了在用 OLE 自动化创建所有对象后终止应用程序，
	//	析构函数调用 AfxOleUnlockApp。
	//  除了做其他事情外，这还将销毁主对话框
	if (m_pDialog != nullptr)
		m_pDialog->m_pAutoProxy = nullptr;
	AfxOleUnlockApp();
}

void CMFCApplication7DlgAutoProxy::OnFinalRelease()
{
	// 释放了对自动化对象的最后一个引用后，将调用
	// OnFinalRelease。  基类将自动
	// 删除该对象。  在调用该基类之前，请添加您的
	// 对象所需的附加清理代码。

	CCmdTarget::OnFinalRelease();
}

BEGIN_MESSAGE_MAP(CMFCApplication7DlgAutoProxy, CCmdTarget)
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CMFCApplication7DlgAutoProxy, CCmdTarget)
END_DISPATCH_MAP()

// 注意: 我们添加了对 IID_IMFCApplication7 的支持来支持类型安全绑定
//  以支持来自 VBA 的类型安全绑定。  此 IID 必须同附加到 .IDL 文件中的
//  调度接口的 GUID 匹配。

// {f2e46328-3180-42a8-a877-ab0d39d2ecfb}
static const IID IID_IMFCApplication7 =
{0xf2e46328,0x3180,0x42a8,{0xa8,0x77,0xab,0x0d,0x39,0xd2,0xec,0xfb}};

BEGIN_INTERFACE_MAP(CMFCApplication7DlgAutoProxy, CCmdTarget)
	INTERFACE_PART(CMFCApplication7DlgAutoProxy, IID_IMFCApplication7, Dispatch)
END_INTERFACE_MAP()

// IMPLEMENT_OLECREATE2 宏是在此项目的 pch.h 中定义的
// {0c314edc-78a9-4369-8b85-39b7606cb63c}
IMPLEMENT_OLECREATE2(CMFCApplication7DlgAutoProxy, "MFCApplication7.Application", 0x0c314edc,0x78a9,0x4369,0x8b,0x85,0x39,0xb7,0x60,0x6c,0xb6,0x3c)


// CMFCApplication7DlgAutoProxy 消息处理程序
