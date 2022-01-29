//https://practice.geeksforgeeks.org/problems/add-two-numbers-represented-by-linked-lists/1#
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
Node *buildList(int size)
{
    int val;
    cin >> val;
    Node *head = new Node(val);
    Node *tail = head;
    for (int i = 0; i < size - 1; i++)
    {
        cin >> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    return head;
}
void printList(Node *n)
{
    while (n)
    {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}
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

struct Node *addTwoLists(struct Node *first, struct Node *second)
{
    //idea - Reverse both lists and add nodes one by one and also keep track of carry.
    Node *t1 = reverse(first);
    Node *t2 = reverse(second);

    Node *temp1 = t1, *temp2 = t2;
    int carry = 0, sum = 0;
    Node *result = NULL, *head = NULL;
    while (temp1 && temp2)
    {
        if (temp1->data + temp2->data + carry > 9)
        {
            sum = (temp1->data + temp2->data + carry) % 10;
            carry = 1;
        }
        else
        {
            sum = temp1->data + temp2->data + carry;
            carry = 0;
        }

        if (!result)
        {
            Node *t = new Node(sum);
            result = t;
            head = result;
        }
        else
        {
            Node *t = new Node(sum);
            result->next = t;
            result = t;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    while (temp1)
    {

        if (temp1->data + carry > 9)
        {
            sum = (temp1->data + carry) % 10;
            carry = 1;
        }
        else
        {
            sum = temp1->data + carry;
            carry = 0;
        }
        if (!result)
        {
            Node *t = new Node(sum);
            result = t;
            head = result;
        }
        else
        {
            Node *t = new Node(sum);
            result->next = t;
            result = t;
        }
        temp1 = temp1->next;
    }

    while (temp2)
    {

        if (temp2->data + carry > 9)
        {
            sum = (temp2->data + carry) % 10;
            carry = 1;
        }
        else
        {
            sum = temp2->data + carry;
            carry = 0;
        }
        if (!result)
        {
            Node *t = new Node(sum);
            result = t;
            head = result;
        }
        else
        {
            Node *t = new Node(sum);
            result->next = t;
            result = t;
        }
        temp2 = temp2->next;
    }

    if (carry)
    {
        Node *t = new Node(1);
        result->next = t;
        result = t;
    }

    Node *res = reverse(head);
    return res;
}

int main()
{
    int n, m;
    cin >> n;
    Node *first = buildList(n);
    cin >> m;
    Node *second = buildList(m);
    Node *res = addTwoLists(first, second);
    printList(res);

    return 0;
}
