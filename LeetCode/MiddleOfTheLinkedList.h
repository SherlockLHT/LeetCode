#ifndef MIDDLE_OF_THE_LINKED_LIST_H
#define MIDDLE_OF_THE_LINKED_LIST_H

#include "LinkList.h"

/*
����һ������ͷ��� head �ķǿյ���������������м��㡣
����������м��㣬�򷵻صڶ����м��㡣

ʾ�� 1��
���룺[1,2,3,4,5]
��������б��еĽ�� 3 (���л���ʽ��[3,4,5])
���صĽ��ֵΪ 3 �� (����ϵͳ�Ըý�����л������� [3,4,5])��
ע�⣬���Ƿ�����һ�� ListNode ���͵Ķ��� ans��������
ans.val = 3, ans.next.val = 4, ans.next.next.val = 5, �Լ� ans.next.next.next = NULL.
ʾ�� 2��

���룺[1,2,3,4,5,6]
��������б��еĽ�� 4 (���л���ʽ��[4,5,6])
���ڸ��б��������м��㣬ֵ�ֱ�Ϊ 3 �� 4�����Ƿ��صڶ�����㡣

��ʾ��

��������Ľ�������� 1 �� 100 ֮�䡣
*/

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
ListNode* middleNode(ListNode* head) {
	ListNode* new_link_list = head;
	ListNode* temp = head;

	char flag = 0;
	while (temp != NULL)
	{
		if (flag == 1)
		{
			new_link_list = new_link_list->next;
		}
		flag = !flag;
		temp = temp->next;
	}

	return new_link_list;
}

void TestMiddleNode()
{
	ListNode* link_list = new ListNode(1);
	Append(link_list, 2);
	Append(link_list, 3);
	Append(link_list, 4);
	Append(link_list, 5);
	//Append(link_list, 6);

	DisplayLinkList(link_list);

	ListNode* new_link_list = middleNode(link_list);
	DisplayLinkList(new_link_list);

	ReleaseLinkList(link_list);
}


#endif //MIDDLE_OF_THE_LINKED_LIST_H
