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
// my approch TC = O(n) and SC = O(1)
Node *deleteMiddle(Node *head)
{
    Node *slow = head;
    Node *fast = head;
    Node *temp = head;

    if (head == NULL || head->next == NULL)
        return NULL;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    while (temp->next != slow)
    {
        temp = temp->next;
    }
    Node *delNode = temp->next;
    temp->next = temp->next->next;
    delete (delNode);

    return head;
}

// More optimize approch TC = O(n) and SC = O(1)
Node *deleteMiddle(Node *head)
{
    ListNode *slow = head;
    ListNode *fast = head;
    ListNode *prev = nullptr;

    if (head == NULL || head->next == NULL)
        return NULL;

    while (fast != NULL && fast->next != NULL)
    {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    prev->next = slow->next;
    delete slow;

    return head;
}

// Optimize approch TC = O(n) and SC = O(1)
Node *deleteMiddle(Node *head)
{
    Node *curr = new Node(0);
    curr->next = head;
    Node *fast = head;
    Node *slow = curr;
    while (fast != nullptr && fast->next != nullptr)
    {
        fast = fast->next->next;

        slow = slow->next;
    }
    slow->next = slow->next->next;
    return curr->next;
}
int main()
{

    vector<int> arr = {1, 2, 3, 4};
    Node *head = convertArr2LL(arr);
    head = deleteMiddle(head);

    printLL(head);

    return 0;
}