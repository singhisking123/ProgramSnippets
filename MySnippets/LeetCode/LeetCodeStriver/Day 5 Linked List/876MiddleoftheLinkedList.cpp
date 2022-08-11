#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Make fast pointer and slow pointer ....
    // fast point will reach null or the next of fast pointer will reach null
    // 1->2->3->4->5 in this case fast_ptr->next will reach null
    // 1->2->3->4 in this case fast_ptr will itself reach null
    ListNode* middleNode(ListNode* head) {
        ListNode* fast_ptr = head, *slow_ptr = head;
        while (fast_ptr != NULL && fast_ptr->next != NULL)
        {
            slow_ptr = slow_ptr->next;
            fast_ptr = fast_ptr->next->next;
        }
        return slow_ptr;
    }
};

int main() {

}