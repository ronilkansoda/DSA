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

Node *findNthNode(Node *temp, int k)
{
    int cnt = 1;
    while (temp != NULL)
    {
        if (cnt == k)
            return temp;
        cnt++;
        temp = temp->next;
    }
    return temp;
}

Node *rotateRight(Node *head, int k)
{
    if (head == NULL && k == 0)
        return head;

    int len = 1;
    Node *tail = head;
    while (tail->next != NULL)
    {
        tail = tail->next;
        len++;
    }
    if (k % len == 0)
        return head;

    k = k % len;

    tail->next = head;
    Node *newLastNode = findNthNode(head, len - k);

    head = newLastNode->next;
    newLastNode->next = NULL;

    return head;
}

int main()
{

    vector<int> arr = {1, 2, 3, 4, 5};
    Node *head = convertArr2LL(arr);
    head = rotateRight(head, 2);

    printLL(head);

    return 0;
}