#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		ListNode *temp = head;
		int t = 0;
		while (temp != NULL) {
			t++;
			temp = temp->next;
		}
		if (t == 1) return NULL;
		if (t == 2) {
			if (n == 1) {
				head->next = NULL;
				return head;
			}
			if (n == 2) {
				return head->next;
			}
		}
		int x = t - n - 1;
		temp = head;
		while (x > 0) {
			temp = temp->next; x--;
		}
		if (x < 0)
			head = head->next;
		else
			temp->next = temp->next->next;
		return head;
	}
};
int main() {

}