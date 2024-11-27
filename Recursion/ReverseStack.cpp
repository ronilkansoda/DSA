#include <iostream>
#include <stack>
#include <vector>
using namespace std;

void insertInOrder(int element, stack<int> &s)
{
    if (s.empty())
    {
        s.push(element);
        return;
    }

    int temp = s.top();
    s.pop();
    insertInOrder(element, s);
    s.push(temp);
}

void Reverse(stack<int> &s)
{
    if (s.empty())
    {
        return;
    }

    // Pop the top element
    int topElement = s.top();
    s.pop();

    // Recursively sort the remaining stack
    Reverse(s);

    // Insert the popped element back in sorted order
    insertInOrder(topElement, s);
}

// Helper function to insert elements into the stack
void insertElements(stack<int> &s)
{
    vector<int> elements = {7, 3, 6, 22, 5, 77};
    for (int element : elements)
    {
        s.push(element);
    }
}

int main()
{
    stack<int> s;

    insertElements(s);

    // Display stack before reversing
    cout << "Stack before reversing: ";
    stack<int> temp = s; // Copy the stack for printing
    while (!temp.empty())
    {
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << endl;

    Reverse(s);

    cout << "Stack after reversing: ";
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;

    return 0;
}
