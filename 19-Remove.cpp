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
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *fp=head;//第一个指针；
        ListNode *sp=head;//第二个指针
        for(int i=0;i<n;i++)
            fp=fp->next;
        if(fp==nullptr)
        {
            head=head->next;
            return head;
        }
        while(fp->next){
            sp=sp->next;
            fp=fp->next;
        }
        ListNode *temp;
        temp=sp->next;
        sp->next=temp->next;
        delete temp;
        return head;
    }
};
/*
 * class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *pFirst = head;
        ListNode *pSecond = head;
        ListNode *temp = nullptr;//空指针常量

        for(int i = 0; i < n; i++) {
            pFirst = pFirst->next;

            if (pFirst == nullptr) {
                temp = head;
                head = head->next;
                delete temp;

                return head;
            }
        }

        while (pFirst->next) {
            pFirst = pFirst->next;
            pSecond = pSecond->next;
        }

        temp = pSecond->next;
        pSecond->next = temp->next;
        delete temp;

        return head;
    }
};
 */