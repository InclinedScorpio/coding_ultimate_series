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
void print(Node *root)
{
    Node *temp = root;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
Node *removeDuplicates(Node *head)
{
    if (head == NULL)
        return head;
    Node *ptr = head;
    while (ptr->next != NULL)
    {
        if (ptr->data == ptr->next->data)
        {
            ptr->next = ptr->next->next;
        }
        else
            ptr = ptr->next;
    }
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
    Node *result = removeDuplicates(head);
    print(result);
    cout << endl;

    return 0;
}
