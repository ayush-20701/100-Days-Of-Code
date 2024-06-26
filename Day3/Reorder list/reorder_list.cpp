//Leetcode 143

//(Tortoise and Hare algorithm)
#include <bits/stdc++.h>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    void reorderList(ListNode* head) {
        // base case: linked list is empty
        if (!head) return;

        // finding the middle with the help of two pointer approach
        ListNode *tmp = head, *half = head, *prev = nullptr;
        while (tmp->next && tmp->next->next) {
            tmp = tmp->next->next;
            half = half->next;
        }

        // adding one bit in case of lists with even length
        if (tmp->next) half = half->next;

        // Now reverse the second half
        while (half) {
            tmp = half->next;
            half->next = prev;
            prev = half;
            half = tmp;
        }
        half = prev;

        // After reversing the second half, let's merge both the halves
        while (head && half) {
            tmp = head->next;
            prev = half->next;
            head->next = half;
            half->next = tmp;
            head = tmp;
            half = prev;
        }

        // Base case: closing when we had even length arrays
        if (head && head->next) head->next->next = nullptr;
    }
};

// Utility function to print the linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "nullptr" << endl;
}

int main() {
    // Create a linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    Solution solution;
    cout << "Original List: ";
    printList(head);

    // Reorder the list
    solution.reorderList(head);
    cout << "Reordered List: ";
    printList(head);

    // Free memory
    while (head) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
