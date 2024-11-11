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

// it will not give answer because our linked list is not merged/intersected
Node *getIntersectionNode(Node *headA, Node *headB)
{
    if (headA == nullptr || headB == nullptr)
        return nullptr;

    Node *a = headA;
    Node *b = headB;

    // If a and b have different lengths, we'll reset the pointer after the first iteration
    while (a != b)
    {
        // For the end of the first iteration, reset the pointer to the head of the other list
        a = (a == nullptr) ? headB : a->next;
        b = (b == nullptr) ? headA : b->next;
    }

    return a;
}

int main()
{

    vector<int> arr1 = {4, 1, 8, 4, 5};
    vector<int> arr2 = {5, 6, 1, 8, 4, 5};
    Node *head1 = convertArr2LL(arr1);
    Node *head2 = convertArr2LL(arr2);
    Node *intersection = getIntersectionNode(head1, head2);

    printLL(intersection);

    return 0;
}