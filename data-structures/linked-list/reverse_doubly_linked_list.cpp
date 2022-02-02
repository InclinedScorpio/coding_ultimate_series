//https://practice.geeksforgeeks.org/problems/reverse-a-doubly-linked-list/1
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    Node(int x)
    {
        data = x;
        next = NULL;
        prev = NULL;
    }
};

struct Node *reverse(struct Node *head)
{
    struct Node *ptr1 = head;
    struct Node *ptr2 = ptr1->next;
    ptr1->next = NULL;
    ptr1->prev = ptr2;
    while (ptr2 != NULL)
    {
        ptr2->prev = ptr2->next;
        ptr2->next = ptr1;
        ptr1 = ptr2;
        ptr2 = ptr2->prev;
    }
    head = ptr1;
    return head;
}

void printList(Node *node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
}

int main()
{

    int n;
    cin >> n;
    int k;
    cin >> k;
    Node *head = NULL, *tail = NULL;
    head = new Node(k);
    tail = head;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> k;
        Node *temp = new Node(k);
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }

    cout << "Original Linked list" << endl;
    printList(head);

    // Reverse doubly linked list
    head = reverse(head);

    cout << "Reversed Linked list" << endl;
    printList(head);

    return 0;
}
