#include <iostream>
#include <vector>
#include <map>
#include <stack>
using namespace std;

struct Node
{
public:
    int data;
    Node *next;

    Node(int data1, Node *next1)
    {
        data = data1;
        next = next1;
    }

    Node(int data1)
    {
        data = data1;
        next = nullptr;
    }
};

Node *convertArr2LL(vector<int> &arr)
{
    Node *head = new Node(arr[0]);
    Node *mover = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }

    return head;
}

void printLL(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Optimize approch TC = O(n) and SC = O(1)
Node *removeNthFromEnd(Node *head, int n)
{
    Node *fast = head;
    Node *slow = head;

    for (int i = 0; i < n; i++)
    {
        fast = fast->next;
    }
    if (fast == NULL)
        return head->next;

    while (fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next;
    }
    Node *delNode = slow->next;
    slow->next = slow->next->next;
    delete (delNode);

    return head;
}

int main()
{

    vector<int> arr = {1, 2};
    int n = 2;
    Node *head = convertArr2LL(arr);
    head = removeNthFromEnd(head, n);

    printLL(head);

    return 0;
}