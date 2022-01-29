//https://www.codingninjas.com/codestudio/problems/let-last-be-the-first_920455?leftPanelTab=0
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
Node *moveToFront(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    Node *secLast = head;
    Node *last = NULL;
    while (secLast->next->next != NULL)
    {
        secLast = secLast->next;
    }
    last = secLast->next;
    secLast->next = NULL;
    last->next = head;
    head = last;
    return head;
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
    temp3 = moveToFront(head);
    while (temp3 != NULL)
    {
        cout << temp3->data << " ";
        temp3 = temp3->next;
    }

    return 0;
}
