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

Node *deleteDuplicates(Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    Node *prev = head;
    Node *temp = prev->next;
    while (temp != NULL)
    {
        if (temp->data == prev->data)
        {
            temp = temp->next;
        }
        else
        {
            prev->next = temp;
            prev = temp;
            temp = temp->next;
        }
    }
    prev->next = NULL;
    return head;
}
int main()
{

    vector<int> arr = {1, 1, 5};
    Node *head = convertArr2LL(arr);
    head = deleteDuplicates(head);

    printLL(head);

    return 0;
}