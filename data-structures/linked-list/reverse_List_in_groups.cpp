//https://practice.geeksforgeeks.org/problems/reverse-a-linked-list-in-groups-of-given-size/1
#include <iostream>
using namespace std;
//idea - reverse the sublist of size. k
//Keep two pointers, pointer to the next node be next and pointer to the previous node be prev.
//Recursively call for rest of the list and link the two sub-lists. /* (head->next=reverse(next, k)) */
//prev becomes the new head of the list.

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
Node *reverse(struct Node *head, int k)
{
    Node *prevptr = NULL;
    Node *currptr = head;
    Node *nextptr;
    int i = 0;
    while (currptr != NULL && i < k)
    {
        nextptr = currptr->next;
        currptr->next = prevptr;
        prevptr = currptr;
        currptr = nextptr;
        i++;
    }
    if (currptr != NULL)
        head->next = reverse(currptr, k);
    return prevptr;
}
int main()
{
    struct Node *head = NULL;
    struct Node *temp = NULL;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        if (i == 0)
        {
            head = new Node(val);
            temp = head;
        }
        else
        {
            temp->next = new Node(val);
            temp = temp->next;
        }
    }
    int k;
    cin >> k;
    head = reverse(head, k);
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }

    return 0;
}