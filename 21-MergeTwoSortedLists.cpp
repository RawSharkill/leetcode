//
// Created by yutianpig on 18-4-2.
//
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
struct ListNode {
         int val;
         ListNode *next;
         ListNode(int x) : val(x), next(NULL) {}
     };
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1==NULL)return l2;
        if(l2==NULL)return l1;

        if(l1->val>l2->val){//递归思想
            ListNode *temp;
            temp=l2;
            temp->next=mergeTwoLists(l1,l2->next);
            return temp;
        } else{
            ListNode *temp;
            temp=l1;
            temp->next=mergeTwoLists(l1->next,l2);
            return temp;
        }
    }
};
