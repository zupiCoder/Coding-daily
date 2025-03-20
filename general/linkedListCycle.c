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

bool hasCycleFastest(struct ListNode *head) {
    struct ListNode* slow = head;
    struct ListNode* fast = head;

    while(fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;

        if(slow == fast) return true;
    }
    return false;
}

bool hasCycleRecursive(struct ListNode *head) {
    struct ListNode* temp = head;

    if(temp == NULL) return false;
    if(temp->next == NULL) return false;

    temp->val = INT_MIN;
    if(temp->next->val == INT_MIN) return true; 

    return hasCycleRecursive(temp->next);
}