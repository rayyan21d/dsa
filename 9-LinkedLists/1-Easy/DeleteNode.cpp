/*

237. Delete Node in a Linked List
Medium
Link: https://leetcode.com/problems/delete-node-in-a-linked-list/description/


There is a singly-linked list head and we want to delete a node node in it.
You are given the node to be deleted node.
You will not be given access to the first node of head.
All the values of the linked list are unique,
and it is guaranteed that the given node node is not the last node in the linked list.

Delete the given node.
Note that by deleting the node, we do not mean removing it from memory.

We mean:
The value of the given node should not exist in the linked list.
The number of nodes in the linked list should decrease by one.
All the values before node should be in the same order.
All the values after node should be in the same order.


Custom testing:

For the input, you should provide the entire linked list head and the node to be given node. node should not be the last node of the list and should be an actual node in the list.
We will build the linked list and pass the node to your function.
The output will be the entire list after calling your function.


Example 1:

Input: head = [4,5,1,9], node = 5
Output: [4,1,9]
Explanation: You are given the second node with value 5, the linked list should become 4 -> 1 -> 9 after calling your function.

Example 2:

Input: head = [4,5,1,9], node = 1
Output: [4,5,9]
Explanation: You are given the third node with value 1, the linked list should become 4 -> 5 -> 9 after calling your function.

*/
#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
};

ListNode *CreateLinkedList(vector<int> &arr)
{
    // Creating a singly linked list
    // Time complexity: O(n)
    ListNode *head = new ListNode();
    ListNode *tmp = head;
    for (int i = 0; i < arr.size(); i++)
    {
        ListNode *newNode = new ListNode();
        newNode->val = arr[i];
        tmp->next = newNode;
        tmp = newNode;
    }

    return head;
}

int removeNode(ListNode *node)
{

    ListNode *nextNode = node->next;
    node->val = nextNode->val;
    node->next = node->next->next;
    delete nextNode;

    return;
}

void printList(ListNode *head)
{
    ListNode *tmp = head->next;
    while (tmp != nullptr)
    {
        cout << tmp->val << " ";
        tmp = tmp->next;
    }
    cout << endl;
}

int main()
{
    vector<int> arr = {4, 5, 1, 9};
    ListNode *head = CreateLinkedList(arr);

    printList(head);

    ListNode *del = head->next->next;
    removeNode(del);

    printList(head);
}