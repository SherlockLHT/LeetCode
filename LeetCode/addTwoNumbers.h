#include <windows.h>
#include <iostream>

#include "LinkList.h"
using namespace std;

/*给定两个非空链表来表示两个非负整数。位数按照逆序方式存储，它们的每个节点只存储单个数字。将两数相加返回一个新的链表。
你可以假设除了数字 0 之外，这两个数字都不会以零开头。
示例：
输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 0 -> 8
原因：342 + 465 = 807*/
//Definition for singly - linked list.
//struct ListNode
//{
//	int val;
//	ListNode *next;
//	ListNode(int x) : val(x), next(NULL) {}
//	~ListNode(){ 
//		delete next; 
//	}
//};

ListNode* createListNode(int value)
{
	return new ListNode(value);
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
{
	ListNode* result = new ListNode(0);
	result->val = l1->val + l2->val;
	l1 = l1->next;
	l2 = l2->next;
	int add = result->val / 10;
	result->val = result->val % 10;
	while (l1 != NULL || l2 != NULL)
	{
		int sum = add;
		sum += (l1 == NULL) ? 0 : l1->val;
		sum += (l2 == NULL) ? 0 : l2->val;
		add = sum / 10;
		result = Append(result, sum % 10);
		l1 = (l1 == NULL) ? NULL : l1->next;
		l2 = (l2 == NULL) ? NULL : l2->next;
	}
	if (add != 0)
	{
		result = Append(result, 1);
	}

	return result;
}
void TestAddTwoNumbers()
{
	ListNode* l1 = new ListNode(5);
	//l1 = Append(l1, 9);
	//l1 = Append(l1, 8);
	DisplayLinkList(l1);

	ListNode* l2 = new ListNode(5);
	//l2 = Append(l2, 2);
	//l2 = Append(l2, 9);
	DisplayLinkList(l2);

	ListNode* result = addTwoNumbers(l1, l2);
	DisplayLinkList(result);

	ReleaseLinkList(l1);
	ReleaseLinkList(l2);
	ReleaseLinkList(result);
}