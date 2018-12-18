#ifndef MERGE_TWO_SORTED_LISTS_H
#define MERGE_TWO_SORTED_LISTS_H

#include "LinkList.h"

/*
Merge two sorted linked lists and return it as a new list.
The new list should be made by splicing together the nodes of the first two lists.

Example:

Input: 1->2->4, 1->3->4
Output: 1->1->2->3->4->4
*/

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
ListNode* mergeTwoList(ListNode* l1, ListNode* l2) {
	if (l1 == NULL)
	{
		return l2;
	}
	if (l2 == NULL)
	{
		return l1;
	}

	ListNode* temp1 = l1;
	ListNode* temp2 = l2;

	ListNode* new_link_list = NULL;

	while (temp1 != NULL && temp2 != NULL)
	{
		int min_value = 0;
		if (temp1->val < temp2->val)
		{
			min_value = temp1->val;
			temp1 = temp1->next;
		}
		else
		{
			min_value = temp2->val;
			temp2 = temp2->next;
		}

		if (NULL == new_link_list)
		{
			new_link_list = new ListNode(min_value);
		}
		else
		{
			new_link_list = Append(new_link_list, min_value);
		}
	}
	ListNode* last_node = (temp1 == NULL) ? temp2 : temp1;
	if (last_node != NULL)
	{
		while (last_node != NULL)
		{
			new_link_list = Append(new_link_list, last_node->val);
			last_node = last_node->next;
		}
	}

	return new_link_list;
}

void TestMergeTwoList()
{
	ListNode* link_list = new ListNode(1);
	link_list = Append(link_list, 2);
	link_list = Append(link_list, 4);
	link_list = Append(link_list, 14);

	ListNode* link_list2 = new ListNode(1);
	link_list2 = Append(link_list2, 3);
	link_list2 = Append(link_list2, 4);

	DisplayLinkList(link_list);
	DisplayLinkList(link_list2);

	ListNode* new_link_list = mergeTwoList(link_list, link_list2);
	DisplayLinkList(new_link_list);

	ReleaseLinkList(link_list);
	ReleaseLinkList(link_list2);
	ReleaseLinkList(new_link_list);
}

#endif	//MERGE_TWO_SORTED_LISTS_H
