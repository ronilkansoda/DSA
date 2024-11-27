#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class SortedStack {
public:
    stack<int> s;

    void sort();
private:
    void insertInSortedOrder(int element);
};


void SortedStack::insertInSortedOrder(int element) {
    // Base case: If the stack is empty or the top is smaller than the element
    if (s.empty() || s.top() <= element) {
        s.push(element);
        return;
    }

    // Otherwise, pop the top element, recurse, and then push it back
    int temp = s.top();
    s.pop();
    insertInSortedOrder(element);
    s.push(temp);
}

// Recursive sort function
void SortedStack::sort() {
    // Base case: If the stack is empty, return
    if (s.empty()) {
        return;
    }

    // Pop the top element
    int topElement = s.top();
    s.pop();

    // Recursively sort the remaining stack
    sort();

    // Insert the popped element back in sorted order
    insertInSortedOrder(topElement);
}

// Helper function to insert elements into the stack
void insertElements(SortedStack& sortedStack) {
    vector<int> elements = {7, 3, 6, 22, 5, 77};
    for (int element : elements) {
        sortedStack.s.push(element);
    }
}

int main() {
    SortedStack ss;

    // Insert elements into the stack
    insertElements(ss);

    // Display stack before sorting
    cout << "Stack before sorting: ";
    stack<int> temp = ss.s; // Copy the stack for printing
    while (!temp.empty()) {
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << endl;

    // Sort the stack
    ss.sort();

    // Display stack after sorting
    cout << "Stack after sorting: ";
    while (!ss.s.empty()) {
        cout << ss.s.top() << " ";
        ss.s.pop();
    }
    cout << endl;

    return 0;
}
