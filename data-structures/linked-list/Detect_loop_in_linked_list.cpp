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
void loopHere(Node *head, Node *tail, int position)
{
    if (position == 0)
        return;
    Node *walk = head;
    for (int i = 1; i < position; i++)
        walk = walk->next;
    tail->next = walk;
}
bool detectLoop(Node *head)
{
    // your code here
    struct Node *slow = head, *fast = head;
    if (head == 0)
        return false;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {

            return true;
        }
    }
    return false;
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

    if (detectLoop(head))
        cout << "True";
    else
        cout << "False";

    return 0;
}
