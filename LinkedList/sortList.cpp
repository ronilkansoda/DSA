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
    Node *temp = head;
    while (temp != nullptr)
    {
        // Print the data of the current node
        cout << temp->data << " ";
        // Move to the next node
        temp = temp->next;
    }
    cout << endl;
}

// Function to find the middle of a linked list
Node *findMiddle(Node *head)
{
    // If the list is empty or has only one node
    // the middle is the head itself
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }

    // Initializing slow and fast pointers
    Node *slow = head;
    Node *fast = head->next;

    // Move the fast pointer twice as fast as the slow pointer
    // When the fast pointer reaches the end, the slow pointer
    // will be at the middle
    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

// Function to merge two sorted linked lists
Node *mergeTwoSortedLinkedLists(Node *list1, Node *list2)
{
    // Create a dummy node to serve
    // as the head of the merged list
    Node *dummyNode = new Node(-1);
    Node *temp = dummyNode;

    // Traverse both lists simultaneously
    while (list1 != nullptr && list2 != nullptr)
    {
        // Compare elements of both lists and
        // link the smaller node to the merged list
        if (list1->data <= list2->data)
        {
            temp->next = list1;
            list1 = list1->next;
        }
        else
        {
            temp->next = list2;
            list2 = list2->next;
        }
        // Move the temporary pointer
        // to the next node
        temp = temp->next;
    }

    // If any list still has remaining
    // elements, append them to the merged list
    if (list1 != nullptr)
    {
        temp->next = list1;
    }
    else
    {
        temp->next = list2;
    }
    // Return the merged list starting
    // from the next of the dummy node
    return dummyNode->next;
}

Node *sortList(Node *head)
{
    // Base case: if the list is empty or has only one node
    // it is already sorted, so return the head
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }

    // Find the middle of the list using the findMiddle function
    Node *middle = findMiddle(head);

    // Divide the list into two halves
    Node *right = middle->next;
    middle->next = nullptr;
    Node *left = head;

    // Recursively sort the left and right halves
    left = sortList(left);
    right = sortList(right);

    // Merge the sorted halves using the mergeTwoSortedLinkedLists function
    return mergeTwoSortedLinkedLists(left, right);
}

int main()
{

    vector<int> arr = {4, 2, 1, 3};
    Node *head = convertArr2LL(arr);
    head = sortList(head);

    printLL(head);

    return 0;
}