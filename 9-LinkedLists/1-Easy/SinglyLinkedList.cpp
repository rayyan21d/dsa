#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int value;
    Node *next;

    Node(int value, Node *next = nullptr)
    {
        this->value = value;
        this->next = next;
    }
};

Node *CreateLinkedList(vector<int> &arr)
{
    // Creating a linked list
    // Time complexity: O(n)
    Node *head = new Node(arr[0]);

    Node *tmp = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node *newNode = new Node(arr[i]);
        tmp->next = newNode;
        tmp = newNode;
    }

    return head;
}

void printLinkedList(Node *head)
{
    // Traversing the linked list
    // Time complexity: O(n)

    Node *ptr = head;
    while (ptr != NULL)
    {
        cout << "[" << ptr->value << "] -> ";
        ptr = ptr->next;
    }
    cout << "NULL" << endl;
}

Node *deleteHead(Node *head)
{
    if (head == NULL)
        return NULL;
    Node *tmp = head;
    head = head->next;
    free(tmp);

    return head;
}

Node *deleteTail(Node *head)
{
    if (head == NULL)
        return NULL; // Empty list
    if (head->next == NULL)
    { // Single node
        free(head);
        return NULL;
    }
    Node *ptr = head;
    while (ptr->next->next != NULL)
    {
        ptr = ptr->next;
    }

    free(ptr->next);
    ptr->next = NULL;

    return head;
}

Node *deleteKthNode(Node *head, int k)
{

    if (head == NULL)
        return NULL;
    if (k == 1)
    {
        Node *ptr = head;
        head = head->next;
        free(ptr);
        return head;
    }

    Node *ptr = head;
    Node *prev = NULL;
    int count = 0;
    while (ptr != NULL)
    {
        count++;
        if (count == k)
        {
            prev->next = ptr->next;
            free(ptr);
            return head;
        }

        prev = ptr;
        ptr = ptr->next;
    }

    return head;
}

Node *removeElement(Node *head, int element)
{

    if (head == NULL)
        return NULL;
    if (head->value == element)
    {
        Node *ptr = head;
        head = head->next;
        free(ptr);
        return head;
    }

    Node *ptr = head;
    Node *prev = NULL;

    while (ptr != NULL)
    {

        if (ptr->value == element)
        {
            prev->next = ptr->next;
            free(ptr);
            return head;
        }

        prev = ptr;
        ptr = ptr->next;
    }

    return head;
}

Node *insertHead(Node *head, int value)
{
    Node *newNode = new Node(value, head);
    return newNode;
}

Node *insertEnd(Node *head, int value)
{
    if (head == NULL)
    {
        return new Node(value);
    }

    Node *ptr = head;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }

    Node *newNode = new Node(value);
    ptr->next = newNode;
    return head;

    return head;
}

Node *insertKthNode(Node *head, int k, int value)
{
    if (head == NULL)
    {
        return NULL;
    }

    if (k == 1)
    {
        return new Node(value, head);
    }

    Node *ptr = head;
    int count = 0;

    while (ptr != NULL)
    {
        count++;
        if (count == k - 1)
        {
            Node *newNode = new Node(value, ptr->next);
            ptr->next = newNode;
            return head;
        }

        ptr = ptr->next;
    }

    return head;
}

Node *insertBeforeElement(Node *head, int value)
{
    if (head == NULL)
    {
        return NULL;
    }

    if (head->value == value)
    {
        return new Node(value, head);
    }

    Node *ptr = head;
    bool found = false;
    while (ptr->next != NULL)
    {
        if (ptr->next->value == value)
        {
            Node *newNode = new Node(value, ptr->next);
            ptr->next = newNode;
            found = true;
            return head;
        }
        ptr = ptr->next;
    }

    if (!found)
    {
        cout << "Element not found" << endl;
    }
    return head;
}

int main()
{

    vector<int> arr = {1, 2, 3, 4, 5};
    vector<int> arr2 = {1, 3, 5, 7, 9};
    vector<int> arr3 = {13, 17, 93, 45, 76};

    vector<Node *> heads;

    heads.push_back(CreateLinkedList(arr));
    heads.push_back(CreateLinkedList(arr2));
    heads.push_back(CreateLinkedList(arr3));

    for (int i = 0; i < 3; i++)
    {

        cout << "Linked list " << i + 1 << ":" << endl;
        printLinkedList(heads[i]);
    }

    cout << "Deleting 3rd element of arr3" << endl;
    heads[2] = deleteKthNode(heads[2], 3);
    printLinkedList(heads[2]);
}