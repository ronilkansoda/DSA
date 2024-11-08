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
Node *oddEvenList(Node *head)
{
    Node *odd = head;
    Node *even = head->next;
    Node *evenHead = even;

    if (head == NULL || head->next == NULL)
        return head;

    while (even != NULL && even->next != NULL)
    {
        odd->next = odd->next->next;
        odd = odd->next;

        even->next = even->next->next;
        even = even->next;
    }

    odd->next = evenHead;

    return head;
}

int main()
{

    vector<int> arr = {1, 2, 3, 4, 5};
    Node *head = convertArr2LL(arr);
    head = oddEvenList(head);

    printLL(head);

    return 0;
}