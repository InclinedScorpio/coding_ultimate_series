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
bool isCircular(Node *head)
{
    // Your code here
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->next == head)
            return 1;
        temp = temp->next;
    }
    return 0;
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
    bool res = isCircular(head);
    cout << res;
    return 0;
}