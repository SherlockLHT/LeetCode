#ifndef REMOVE_NTH_NODE_FROM_END_OF_LIST_H
#define REMOVE_NTH_NODE_FROM_END_OF_LIST_H
#include "LinkList.h"
/*
Given a linked list, remove the n-th node from the end of list and return its head.

Example:
Given linked list: 1->2->3->4->5, and n = 2.
After removing the second node from the end, the linked list becomes 1->2->3->5.

Note:
Given n will always be valid.

Follow up:
Could you do this in one pass?
*/

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
ListNode* removeNthFromEnd(ListNode* head, int n) {
	ListNode* node = head;
	ListNode* temp = head;
	int index = 0;

	while (temp != NULL)
	{
		if (index > n)
		{
			node = node->next;
		}
		index++;
		temp = temp->next;
	}
	//链表长度不足
	if (node == head && index <= n)
	{
		return head->next;
	}
	else
	{
		node->next = node->next->next;
	}
	
	return head;
}

void TestRemoveNthFromEnd()
{
	ListNode* link_list = new ListNode(1);
	Append(link_list, 2);
	Append(link_list, 3);
	Append(link_list, 4);
	Append(link_list, 5);

	DisplayLinkList(link_list);

	ListNode* new_link_list = removeNthFromEnd(link_list, 0);

	DisplayLinkList(new_link_list);

	ReleaseLinkList(link_list);
}

#endif // REMOVE_NTH_NODE_FROM_END_OF_LIST_H
