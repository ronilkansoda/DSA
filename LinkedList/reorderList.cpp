#include <iostream>
#include <vector>
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

void reorderList(Node *head)
{
    Node *slow = head;
    Node *fast = head->next;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    Node *second = slow->next;
    Node *prev = NULL;
    slow->next = NULL;
    Node *temp;
    while (second != NULL)
    {
        temp = second->next;
        second->next = prev;
        prev = second;
        second = temp;
    }

    Node *first = head;
    second = prev;
    Node *temp1;
    Node *temp2;
    while (second != NULL)
    {
        temp1 = first->next;
        temp2 = second->next;

        first->next = second;
        second->next = temp1;

        first = temp1;
        second = temp2;
    }
}

int main()
{

    vector<int> arr = {1, 2, 3, 4,5};
    Node *head = convertArr2LL(arr);
    reorderList(head);

    printLL(head);

    return 0;
}