#ifndef SWAP_NODES_IN_PAIRS_H
#define SWAP_NODES_IN_PAIRS_H

#include "LinkList.h"

/*
Given a linked list, swap every two adjacent nodes and return its head.

Example:
Given 1->2->3->4, you should return the list as 2->1->4->3.
Note:

Your algorithm should use only constant extra space.
You may not modify the values in the list's nodes, only nodes itself may be changed.

*/

ListNode* swapPairs(ListNode* head) {
	if (head == NULL || head->next == NULL)
	{
		return head;
	}
	ListNode* p = head;
	head = p->next;
	ListNode* preview= NULL;
	while (p != NULL &&p->next != NULL)
	{
		ListNode* temp = p->next;
		p->next = temp->next;
		temp->next = p;
		if (preview != NULL){
			preview->next = temp;
		}
		preview = p;
		p = p->next;
	}
	return head;
}

void TestSwapPairs()
{
	ListNode* link_list = new ListNode(1);


	DisplayLinkList(link_list);

	ListNode* new_list = swapPairs(link_list);

	DisplayLinkList(new_list);

	ReleaseLinkList(link_list);
}


#endif // !SWAP_NODES_IN_PAIRS_H




