#include <iostream>
#include <malloc.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *answer=new ListNode(0);
        ListNode *p=answer;
        int term=0;
        while(l1!=NULL && l2!=NULL){
            p->next=new ListNode((term+l1->val+l2->val)%10);
            term=(term+l1->val+l2->val)/10;
            l1=l1->next;
            l2=l2->next;
            p=p->next;
        }
        while(l1!=NULL){
            p->next=new ListNode((l1->val+term)%10);
            term=(l1->val+term)/10;
            l1=l1->next;
            p=p->next;
        }
        while(l2!=NULL){
            p->next=new ListNode((l2->val+term)%10);
            term=(l2->val+term)/10;
            l2=l2->next;
            p=p->next;
        }
        if(term){
            p->next=new ListNode(1);
        }
       return answer->next;
    }
};




