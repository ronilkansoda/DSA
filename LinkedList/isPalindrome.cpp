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
Node *reverseLL(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    Node *newHead = reverseLL(head->next);
    Node *front = head->next;
    front->next = head;
    head->next = NULL;
    return newHead;
}

bool isPalindrome(Node *head)
{
    // stack<int> st;
    // Node *temp = head;

    // while (temp != NULL)
    // {
    //     st.push(temp->data); // space complexity O(n)
    //     temp = temp->next;
    // }
    // temp = head;
    // while (temp != NULL)
    // {
    //     if (temp->data != st.top())
    //     {
    //         return false;
    //     }
    //     st.pop();
    //     temp = temp->next;
    // }
    // return true;

    if (head == NULL || head->next == NULL)
        return true;

    Node *slow = head;
    Node *fast = head;

    while (fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    Node *newNode = reverseLL(slow->next);

    Node *first = head;
    Node *second = newNode;

    while (second != NULL)
    {
        if (first->data != second->data)
        {
            reverseLL(newNode);
            return false;
        }
        first = first->next;
        second = second->next;
    }

    reverseLL(newNode);
    return true;
}

int main()
{

    vector<int> arr = {1, 3, 2, 1};
    Node *head = convertArr2LL(arr);

    cout << isPalindrome(head) << endl;

    return 0;
}