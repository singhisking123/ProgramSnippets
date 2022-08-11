#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		ListNode *dummy = NULL;
		ListNode *nexti ;
		while (head != NULL) {
			nexti = head->next;
			head->next = dummy;
			dummy = head;
			head = nexti;
		}
		return dummy;
	}
};

int main() {

}