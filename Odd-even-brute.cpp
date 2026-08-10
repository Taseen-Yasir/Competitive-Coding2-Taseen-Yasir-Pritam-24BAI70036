#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = nullptr;
    }
};

ListNode* oddEvenList(ListNode* head) {
    if (!head || !head->next)
        return head;

    vector<ListNode*> odd, even;

    ListNode* curr = head;
    int pos = 1;

    while (curr) {
        if (pos % 2 == 1)
            odd.push_back(curr);
        else
            even.push_back(curr);

        curr = curr->next;
        pos++;
    }

    ListNode* newHead = odd[0];
    ListNode* tail = newHead;

    for (int i = 1; i < odd.size(); i++) {
        tail->next = odd[i];
        tail = tail->next;
    }

    for (int i = 0; i < even.size(); i++) {
        tail->next = even[i];
        tail = tail->next;
    }

    tail->next = nullptr;

    return newHead;
}

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    head = oddEvenList(head);

    while (head) {
        cout << head->val << " ";
        head = head->next;
    }

    return 0;
}