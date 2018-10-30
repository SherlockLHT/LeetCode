#include <windows.h>
#include <iostream>

#include "LinkList.h"
using namespace std;

/*���������ǿ���������ʾ�����Ǹ�������λ����������ʽ�洢�����ǵ�ÿ���ڵ�ֻ�洢�������֡���������ӷ���һ���µ�����
����Լ���������� 0 ֮�⣬���������ֶ��������㿪ͷ��
ʾ����
���룺(2 -> 4 -> 3) + (5 -> 6 -> 4)
�����7 -> 0 -> 8
ԭ��342 + 465 = 807*/
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
	result->value = l1->value + l2->value;
	l1 = l1->next;
	l2 = l2->next;
	int add = result->value / 10;
	result->value = result->value % 10;
	while (l1 != NULL || l2 != NULL)
	{
		int sum = add;
		sum += (l1 == NULL) ? 0 : l1->value;
		sum += (l2 == NULL) ? 0 : l2->value;
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