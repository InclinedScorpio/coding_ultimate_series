//https : //practice.geeksforgeeks.org/problems/sort-a-linked-list/1
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
//idea - keep splitting the list into two parts by using FindMiddle function and
//then merge the two parts by seeing which data is smaller

void FindMiddle(Node *cur, Node **first, Node **second)
{
    Node *fast;
    Node *slow;
    slow = cur;
    fast = cur->next;
    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            slow = slow->next;
            fast = fast->next;
        }
    }
    *first = cur;
    *second = slow->next;
    slow->next = NULL;
}

Node *MergeBoth(Node *first, Node *second)
{
    Node *answer = NULL;
    if (!first)
        return second;
    else if (!second)
        return first;
    if (first->data <= second->data)
    {
        answer = first;
        answer->next = MergeBoth(first->next, second);
    }
    else
    {
        answer = second;
        answer->next = MergeBoth(first, second->next);
    }
    return answer;
}
void MergeSorting(Node **head)
{
    Node *cur = *head;
    Node *first;
    Node *second;
    if (!cur or !cur->next)
        return;

    FindMiddle(cur, &first, &second);

    MergeSorting(&first);
    MergeSorting(&second);
    *head = MergeBoth(first, second);
}
//Function to sort the given linked list using Merge Sort.
Node *mergeSort(Node *head)
{
    // your code here
    MergeSorting(&head);
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
    Node *res = NULL;
    res = mergeSort(head);
    while (res != NULL)
    {
        cout << res->data << " ";
        res = res->next;
    }
    return 0;
}