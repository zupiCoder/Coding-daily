#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>
#include <limits.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

bool hasCycle(struct ListNode *head) {
    struct ListNode *temp = head;

    while(temp && temp->next) {
        temp->val = INT_MIN;

        if(temp->next->val == INT_MIN) return true; 
        temp = temp->next;
    }
    return false;
}

bool hasCycleFaster(struct ListNode *head) {
    struct ListNode* slow = head;
    struct ListNode* fast = head;

    while(fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;

        if(slow == fast) return true;
    }
    return false;
}