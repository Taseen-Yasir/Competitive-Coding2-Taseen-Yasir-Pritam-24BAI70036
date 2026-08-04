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

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<int> values;

    
        ListNode* curr = head;
        while (curr != nullptr) {
            values.push_back(curr->val);
            curr = curr->next;
        }

    
        int left = 0;
        int right = values.size() - 1;

        while (left < right) {
            if (values[left] != values[right])
                return false;

            left++;
            right--;
        }

        return true;
    }
};

ListNode* createList(vector<int> arr) {
    if (arr.empty()) return nullptr;

    ListNode* head = new ListNode(arr[0]);
    ListNode* temp = head;

    for (int i = 1; i < arr.size(); i++) {
        temp->next = new ListNode(arr[i]);
        temp = temp->next;
    }

    return head;
}

int main() {
    vector<int> arr = {1, 2, 2, 1};

    ListNode* head = createList(arr);

    Solution obj;

    if (obj.isPalindrome(head))
        cout << "True";
    else
        cout << "False";

    return 0;
}
