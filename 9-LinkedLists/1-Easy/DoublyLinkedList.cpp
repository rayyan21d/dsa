#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int data, Node *next = nullptr, Node *prev = nullptr)
    {
        this->data = data;
        this->next = next;
        this->prev = prev;
    }
};

Node *CreateDoubleLinkedList(vector<int> &arr)
{
    // Creating a Doubly linked list
    // Time complexity: O(n)
    Node *head = new Node(arr[0]);
    Node *tmp = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node *newNode = new Node(arr[i]);
        tmp->next = newNode;
        newNode->prev = tmp;
        tmp = newNode;
    }

    return head;
}

int main()
{
}