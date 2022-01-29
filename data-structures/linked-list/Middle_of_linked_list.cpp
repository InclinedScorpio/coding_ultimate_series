//https://leetcode.com/problems/middle-of-the-linked-list/
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
int findLength(Node *head)
{
    Node *temp1 = head;
    int len = 0;
    while (temp1 != NULL)
    {
        len++;
        temp1 = temp1->next;
    }
    return len;
}

Node *middleNode(Node *head)
{
    Node *fast = head->next;
    Node *slow = head;
    int len = findLength(head);
    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            slow = slow->next;
            fast = fast->next;
        }
    }
    Node *res = NULL;

    if ((len % 2) == 0)
    {

        slow = slow->next;
        while (slow != NULL)
        {
            if (res == NULL)
            {
                Node *tmp = new Node(slow->data);
                res = tmp;
                head = res;
            }
            else
            {
                Node *tmp = new Node(slow->data);
                res->next = tmp;
                res = tmp;
            }
            slow = slow->next;
        }
    }
    else
    {
        while (slow != NULL)
        {
            if (res == NULL)
            {
                int x = slow->data;

                Node *tmp = new Node(x);
                res = tmp;
                head = res;
            }
            else
            {

                Node *tmp = new Node(slow->data);
                res->next = tmp;
                res = tmp;
            }
            slow = slow->next;
        }
    }
    return head;
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
    Node *res = NULL;
    res = middleNode(head);
    while (res != NULL)
    {
        cout << res->data << " ";
        res = res->next;
    }
    return 0;
}