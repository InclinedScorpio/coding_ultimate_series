//https://practice.geeksforgeeks.org/problems/add-1-to-a-number-represented-as-linked-list/1#
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
Node *reverse(Node *head)
{
    Node *prev = NULL;
    Node *current = head;
    Node *next;

    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    return prev;
}

Node *addOne(Node *head)
{

    head = reverse(head); // reversing list to make addition easy

    Node *current = head;
    int carry = 1;

    while (carry)
    {
        current->data += 1; // adding one to current node

        if (current->data < 10)
            return reverse(head);
        // if no carry we can reverse back list and return it
        else
            current->data = 0;
        // else we continue with taking carry forward

        if (current->next == NULL)
            break;
        // if, end of list, we break from loop
        else
            current = current->next;
        // else we move to next node
    }

    current->next = new Node(1); // adding new node for the carried 1
    return reverse(head);
}
int main()
{
    struct Node *head, *tail;

    int n;
    cin >> n;
    int num;
    cin >> num;
    head = tail = new Node(num);
    for (int i = 0; i < n - 1; i++)
    {
        cin >> num;
        tail->next = new Node(num);
        tail = tail->next;
    }
    Node *temp3 = NULL;
    temp3 = addOne(head);
    while (temp3 != NULL)
    {
        cout << temp3->data << " ";
        temp3 = temp3->next;
    }

    return 0;
}
