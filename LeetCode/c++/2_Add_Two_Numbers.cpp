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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *result = new ListNode(0);
        ListNode *ptr = result;
        int carry = 0;

        while (l1 != NULL && l2 != NULL) {

            int sum = l1->val + l2->val + carry;
            carry = sum / 10;
            sum = sum % 10;

            ptr->next = new ListNode(sum);
            ptr = ptr->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1!= NULL){
            int sum = carry + l1->val;
            carry = sum / 10;
            sum = sum % 10;

            ptr->next = new ListNode(sum);
            ptr = ptr->next;
            l1 = l1->next;
        }
        while(l2!= NULL){
            int sum = carry + l2->val;
            carry = sum / 10;
            sum = sum % 10;

            ptr->next = new ListNode(sum);
            ptr = ptr->next;
            l2 = l2->next;
        }
        if(carry !=0){
            ptr->next = new ListNode(carry);
            ptr = ptr->next;
        }
        ptr = result->next;
        return ptr;
    }
};

ListNode *vector_to_list(vector<int> &nums) {
    if (nums.size() == 0) return NULL;

    ListNode *head = new ListNode(nums[0]);
    ListNode *ptr = head;

    for (int i = 1; i < nums.size(); i++) {
        ptr->next = new ListNode(nums[i]);
        ptr = ptr->next;
    }
    ptr = head;
    delete head;
    return ptr;
}

int main() {

    vector<int> nums1 = {9,1,6};
    vector<int> nums2 = {0};

    ListNode *l1 = vector_to_list(nums1);
    ListNode *l2 = vector_to_list(nums2);

    ListNode *answer = Solution().addTwoNumbers(l1, l2);

    return 0;

}
