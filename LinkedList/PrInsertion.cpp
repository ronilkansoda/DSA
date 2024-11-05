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

Node *insertAtFirst(Node *head, int val)
{
    Node *temp = new Node(val, head);
    return temp;
}
Node *insertAtLast(Node *head, int val)
{
    if (head == NULL)
    {
        return new Node(val);
    }
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    Node *newNode = new Node(val);
    temp->next = newNode;

    return head;
}
Node *insertAtKth(Node *head, int val, int k)
{
    if (head == NULL)
    {
        if (k == 1)
        {
            return new Node(val);
        }
        else
        {
            return head;
        }
    }

    if (k == 1)
    {
        return new Node(val, head);
    }

    int cnt = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        cnt++;
        if (cnt == (k - 1))
        {
            Node *newNode = new Node(val, temp->next);
            temp->next = newNode;
            break;
        }

        temp = temp->next;
    }

    return head;
}
Node *insertBeforevalue(Node *head, int el, int val)
{
    if (head == NULL)
    {
        return NULL;
    }

    if (head->data == val)
    {
        return new Node(el, head);
    }

    Node *temp = head;
    while (temp->next != NULL)
    {
        if (temp->next->data == val)
        {
            Node *newNode = new Node(el, temp->next);
            temp->next = newNode;
            break;
        }

        temp = temp->next;
    }

    return head;
}

int main()
{

    vector<int> arr = {1, 4, 7, 11, 15};
    Node *head = convertArr2LL(arr);
    head = insertBeforevalue(head, 41, 15);

    printLL(head);

    return 0;
}