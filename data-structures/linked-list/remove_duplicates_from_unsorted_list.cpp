//https://practice.geeksforgeeks.org/problems/remove-duplicates-from-an-unsorted-linked-list/1#
#include <iostream>
#include <unordered_map>
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
    //idea - save the frequency of the list elements using map
    //check the map for frequency and make the list
    unordered_map<int, int> mp;
    Node *temp = head, *prev = head;
    while (temp)
    {
        mp[temp->data]++;
        temp = temp->next;
    }
    temp = head;
    while (temp)
    {
        if (mp[temp->data] != 0)
        {
            mp[temp->data] = 0;
            prev = temp;
        }
        else
        {
            prev->next = temp->next;
        }
        temp = temp->next;
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
