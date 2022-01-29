//https://practice.geeksforgeeks.org/problems/remove-loop-in-linked-list/1
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
bool isLoop(Node *head)
{
    if (!head)
        return false;
    Node *fast = head->next;
    Node *slow = head;
    while (fast != slow)
    {
        if (!fast || fast->next)
            return false;
        fast = fast->next->next;
        slow = slow->next;
    }
    return true;
}
int length(Node *head)
{
    int ret = 0;
    while (head)
    {
        ret++;
        head = head->next;
    }
    return ret;
}

void loopHere(Node *head, Node *tail, int position)
{
    if (position == 0)
        return;
    Node *walk = head;
    for (int i = 1; i < position; i++)
        walk = walk->next;
    tail->next = walk;
}
void removeLoop(Node *head)
{
    //idea - First detect the loop using floyd cycle detection algo then move the fast or slow pointer to the head
    //and then loop the fast and slow pointer until they point to a same node. Then just make the next pointer null of fast/slow pointer

    Node *fast, *slow;
    fast = head;
    slow = head;
    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
        if (slow == fast)
        {
            break;
        }
    }
    if (slow == head)
    {
        while (fast->next != slow)
        {
            fast = fast->next;
        }
        fast->next = NULL;
    }
    else if (slow == fast)
    {
        slow = head;
        while (slow->next != fast->next)
        {
            slow = slow->next;
            fast = fast->next;
        }
        fast->next = NULL;
    }
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
    int pos;
    cin >> pos;
    loopHere(head, tail, pos);

    removeLoop(head);
    if (isLoop(head) || length(head) != n)
        cout << "0\n";
    else
        cout << "1\n";

    return 0;
}
