#ifndef DELETE_NODE_IN_A_LINKED_LIST_H
#define DELETE_NODE_IN_A_LINKED_LIST_H

#include "LinkList.h"

/*
���дһ��������ʹ�����ɾ��ĳ�������и����ģ���ĩβ���ڵ㣬�㽫ֻ������Ҫ��ɾ���Ľڵ㡣

����һ������ -- head = [4,5,1,9]�������Ա�ʾΪ:

4 -> 5 -> 1 -> 9
ʾ�� 1:

����: head = [4,5,1,9], node = 5
���: [4,1,9]
����: ������������ֵΪ 5 �ĵڶ����ڵ㣬��ô�ڵ�������ĺ���֮�󣬸�����Ӧ��Ϊ 4 -> 1 -> 9.
ʾ�� 2:

����: head = [4,5,1,9], node = 1
���: [4,5,9]
����: ������������ֵΪ 1 �ĵ������ڵ㣬��ô�ڵ�������ĺ���֮�󣬸�����Ӧ��Ϊ 4 -> 5 -> 9.
˵��:

�������ٰ��������ڵ㡣
���������нڵ��ֵ����Ψһ�ġ�
�����Ľڵ�Ϊ��ĩβ�ڵ㲢��һ���������е�һ����Ч�ڵ㡣
��Ҫ����ĺ����з����κν����
*/

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
void deleteNode(ListNode* node) {

}

void TestDeleteNode()
{
	ListNode* link_list = new ListNode(4);
	Append(link_list, 5);
	Append(link_list, 1);
	Append(link_list, 9);

	DisplayLinkList(link_list);
}

#endif	//DELETE_NODE_IN_A_LINKED_LIST_H
