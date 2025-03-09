#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {};
    ListNode(int x) : val(x), next(nullptr) {};
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *createList(vector<int> arr)
{
    ListNode *head = new ListNode(arr[0]);
    ListNode *ptr = head;
    for (int i = 1; i < arr.size(); i++)
    {
        ptr->next = new ListNode(arr[i]);
        ptr = ptr->next;
    }
    return head;
}

// Approach: Brute Force
// Time Complexity: O(n)
// Space Complexity: O(1)
ListNode *middleNode_brute_force(ListNode *head)
{

    int n = 1;
    ListNode *ptr = head;
    while (ptr->next != NULL)
    {
        n++;
        ptr = ptr->next;
    }

    n = n / 2 + 1;

    ptr = head;
    for (int i = 1; i < n; i++)
    {
        ptr = ptr->next;
    }

    return ptr;
}

// Approach: Fast and Slow Pointers
// Time Complexity: O(2*n)
// Space Complexity: O(1)
ListNode *middleNode_optimal(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head;

    while (fast != NULL & fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

void printList(ListNode *head)
{
    ListNode *ptr = head;
    while (ptr != NULL)
    {
        cout << ptr->val << " ";
        ptr = ptr->next;
    }
    cout << endl;
    return;
}

int main()
{

    vector<int> arr = {1, 2, 3, 4, 5};
    ListNode *head = createList(arr);

    ListNode *middle = middleNode_optimal(head);
    printList(middle);

    return 0;
}