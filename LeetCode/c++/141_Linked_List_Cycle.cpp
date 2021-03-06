//
// Created by 박혜원 on 2020/05/11.
//

#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *fastPointer = head;
        ListNode *slowPointer = head;

        while (fastPointer != NULL && fastPointer->next != NULL) {
            fastPointer = fastPointer->next->next;
            slowPointer = slowPointer->next;

            if (slowPointer == fastPointer)
                return true;
        }
        return false;
    }
};

ListNode *make_list(vector<int> &nums, int k) {
    ListNode *myList = new ListNode(0);
    ListNode *ptr = myList;

    for (int i = 0; i < nums.size(); i++) {
        ptr->next = new ListNode(nums[i]);
        ptr = ptr->next;
    }
    ListNode *target = myList->next;

    if (k > 0) {
        for (int i = 0; i < k; i++) {
            target = target->next;
        }
        ptr->next = target;
        ptr = myList->next;
    }

    delete myList;
    return ptr;
}

int main() {

    vector<int> nums = {1};
    int k = -1;
    ListNode *head = make_list(nums, k);
    Solution().hasCycle(head) ? cout << "True" : cout << "False";
    return 0;
}