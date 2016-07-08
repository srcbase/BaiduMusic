#ifndef UI_LIST_DEFINE_BASE_H 
#define UI_LIST_DEFINE_BASE_H 
#pragma once
#include<vector>
#include <set>
#include "Control/UIList.h"
namespace DuiLib
{
//struct ListItemInfo
//{
//	bool folder;
//	bool empty;
//	CStdString id;
//	CStdString logo;
//	CStdString name;
//};

// ��ԭ��CUIListDefineBase�е���ҵ���޹صĶ�ѡ������������γ�CMultiSelListUI,
// ����Ҫ��ѡ��ʱ��ֻ��Ҫ����ΪCMultiSelListUI���� modify:zuo.JY
class UILIB_API CMultiSelListUI : public CListUI
{
public:
	CMultiSelListUI();
	virtual ~CMultiSelListUI();

	LPCTSTR GetClass() const;
	LPVOID GetInterface( LPCTSTR pstrName );

	virtual bool SelectItem( int iIndex, bool bTakeFocus = false );
	virtual void SetMultiSelectItem( bool bMultiSel = true );
	virtual bool IsMultiSelectItem()const;
	virtual void SetBeginSelectItem( bool bBeginSel = true );
	virtual bool IsBeginSelectItem();
	virtual std::set<int> GetSelectItems();
	virtual int GetCurSel();
	void CMultiSelListUI::SetAttribute( LPCTSTR pstrName, LPCTSTR pstrValue );
	void UnSelectAll();
	void SelectAll();
	int GetCurItem(POINT pt );
	bool MouseSelect(int iIndex);
	bool SetSelect(int iIndex,bool bSelect);
protected:
	std::set<int> m_setSelectItems;
	bool m_bMultiSelect;
	bool m_bBeginSelect;
	bool m_bMouseSelect;
	int m_itemStart;
	int m_itemEnd;
};

class UILIB_API CUIListDefineBase : public CMultiSelListUI
{
public:
	CUIListDefineBase();
	~CUIListDefineBase();
	enum { SCROLL_TIMERID = 10 };

	// �Լ������ض����ʵ��������������ܾ������б����������б���
	// ListItemInfo���Ի����Լ�����Ľṹ��
	//virtual Node* AddNode( const ListItemInfo& info, Node* pParent = NULL ){ return NULL; }

	virtual void DoEvent( TEventUI& event );
	//virtual void SetChildVisible( Node* node, bool visible );
	//virtual bool CanExpand( Node* node ) const;

public:
	bool Add( CControlUI* pControl );
	bool AddAt( CControlUI* pControl, int iIndex );
	bool Remove( CControlUI* pControl );
	bool RemoveAt( int iIndex );
	void RemoveAll();
	//bool RemoveNode( Node* node );
	//Node *GetRootNode(){return root_node_;}
	

protected:
	
	LONG delay_deltaY_;
	DWORD delay_number_;
	DWORD delay_left_;
	CDuiRect text_padding_;
	int level_text_start_pos_;
	//CPaintManagerUI& paint_manager_;
    CDialogBuilder m_dlgBuilder;
};

} // DirectUICore

#endif // UI_LIST_DEFINE_BASE_H