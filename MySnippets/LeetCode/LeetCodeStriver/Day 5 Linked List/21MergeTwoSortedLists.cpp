#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
		ListNode* temp = NULL;
		ListNode * head = NULL;
		while (list1 != NULL && list2 != NULL) {
			if (list1->val <= list2->val) {
				if (head == NULL) {
					head = list1;
					temp = head;
				} else {
					head->next = list1;
					head = head->next;
				}
				list1 = list1->next;
			} else {
				if (head == NULL) {
					head = list2;
					temp = head;
				} else {
					head->next = list2;
					head = head->next;
				}
				list2 = list2->next;
			}
		}
		while (list1 != NULL ) {
			if (head == NULL) {
				head = list1;
				temp = head;
			} else {
				head->next = list1;
				head = head->next;
			}
			list1 = list1->next;
		}
		while (list2 != NULL ) {
			if (head == NULL) {
				head = list2;
				temp = head;
			} else {
				head->next = list2;
				head = head->next;
			}
			list2 = list2->next;
		}
		return temp;
	}
};

int main() {

}