#ifndef ROTATE_LIST_H
#define ROTATE_LIST_H

#include "LinkList.h"
//未完成
//移动链表
/*
Given a linked list, rotate the list to the right by k places, where k is non-negative.

Example 1:

Input: 1->2->3->4->5->NULL, k = 2
Output: 4->5->1->2->3->NULL
Explanation:
rotate 1 steps to the right: 5->1->2->3->4->NULL
rotate 2 steps to the right: 4->5->1->2->3->NULL
Example 2:

Input: 0->1->2->NULL, k = 4
Output: 2->0->1->NULL
Explanation:
rotate 1 steps to the right: 2->0->1->NULL
rotate 2 steps to the right: 1->2->0->NULL
rotate 3 steps to the right: 0->1->2->NULL
rotate 4 steps to the right: 2->0->1->NULL
*/

//左移
/*
ListNode* rotateRight(ListNode* head, int k) {
	if (0 == k || head == NULL)
	{
		return head;
	}

	ListNode* origin_head = head;
	ListNode* preview_node = NULL;
	ListNode* current_node = head;

	int index = 0;
	char ergodic_flag = 1, find_flag = 1;
	while (ergodic_flag || find_flag)
	{
		if (current_node->next == NULL)
		{
			current_node->next = origin_head;
			ergodic_flag = 0;
		}
		if (index < k)
		{
			preview_node = (preview_node == NULL) ? head : preview_node->next;
			head = head->next;
			index++;
		}
		else
		{
			find_flag = 0;
		}
		current_node = current_node->next;
	}

	preview_node->next = NULL;
	return head;
}*/

ListNode* rotateRight(ListNode* head, int k) {
	if (0 == k || head == NULL)
	{
		return head;
	}

	ListNode* origin_head = head;
	ListNode* preview_node = NULL;
	ListNode* current_node = head;

	int index = 0;
	char ergodic_flag = 1, find_flag = 1;
	while (ergodic_flag || find_flag)
	{
		if (current_node->next == NULL)
		{
			ergodic_flag = 0;
			current_node->next = origin_head;
		}
		if (index < k)
		{
			index++;
		}
		else
		{
			find_flag = 0;
			preview_node = (preview_node == NULL) ? head : preview_node->next;
			head = head->next;
		}
		current_node = current_node->next;
	}
	preview_node->next = NULL;
	
	return head;
}


void TestRotateRight()
{
	ListNode* link_list = new ListNode(0);
	Append(link_list, 1);
	Append(link_list, 2);


	DisplayLinkList(link_list);

	ListNode* new_list = rotateRight(link_list, 4);

	DisplayLinkList(new_list);

	ReleaseLinkList(link_list);
}

#endif	//ROTATE_LIST_H
