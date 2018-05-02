/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x),next(NULL){}
};
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode *newhead=new ListNode(0);
        newhead->next=head;
        ListNode *pre=newhead,*first;
        while(pre){
            if(!pre->next || !pre->next->next)
                break;
            first=pre->next;
            pre->next=first->next;
            first->next=pre->next->next;
            pre->next->next=first;
            pre=first;
        }
        return newhead->next;
    }
};

//大神代码
/*
 * class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode **pp = &head, *a, *b;

        while ((a = *pp) && (b = a->next)) {
            a->next = b->next;
            b->next = a;
            *pp = b;
            pp = &(a->next);
        }

        return head;
    }
};
 */