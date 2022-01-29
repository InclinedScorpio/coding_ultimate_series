//https://practice.geeksforgeeks.org/problems/circular-linked-list/1
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};
void printList(Node *head)
{
    Node *temp = head;
    if (head != NULL)
    {

        if (head != NULL)
        {
            do
            {
                cout << temp->data << " ";
                temp = temp->next;
            } while (temp != head);
            cout << "\n";
        }
    }
}
void splitList(Node *head, Node **head1_ref, Node **head2_ref)
{
    // your code goes here
    Node *slow = head;
    Node *fast = head;
    while (fast->next != head)
    {
        fast = fast->next;
        if (fast->next != head)
        {
            slow = slow->next;
            fast = fast->next;
        }
    }
    Node *res = slow->next;

    *head1_ref = head;
    slow->next = head;
    *head2_ref = res;
    fast->next = *head2_ref;
}
int main()
{
    struct Node *head = NULL;
    struct Node *temp = NULL;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int data;
        cin >> data;
        if (i == 0)
        {
            head = new Node(data);
            temp = head;
        }
        else
        {
            temp->next = new Node(data);
            temp = temp->next;
        }
    }
    if (n >= 1)
        temp->next = head;
    Node *head1 = NULL;
    Node *head2 = NULL;
    splitList(head, &head1, &head2);

    printList(head1);
    printList(head2);
    return 0;
}