//
// Created by yutianpig on 18-4-7.
//

 // Definition for singly-linked list.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 struct ListNode {
      int val;
      ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};
class cmp {
public:
    bool operator()(ListNode* p1, ListNode* p2) const {
        return p1->val > p2->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<ListNode*>::iterator beg = lists.begin();//迭代器
        for( ; beg!=lists.end(); ) {                        // 先移除lists中的空链表
            if(*beg == NULL)
                beg = lists.erase(beg);
            else
                ++beg;
        }
        if(lists.empty())                                   // 如果lists为空
            return NULL;

        make_heap(lists.begin(), lists.end(), cmp());       // 建小根堆
        ListNode* head = new ListNode(0);//初始一个空节点做头结点
        ListNode* p = head;
        while(!lists.empty()) {
            p->next = lists.front();                        // 第一个结点就是堆的根节点
            p = p->next;
            pop_heap(lists.begin(),lists.end(), cmp());     // pop操作将堆的根节点放到容器尾部
            lists.pop_back();                               // 移除之
            if(p->next != NULL) {
                lists.push_back(p->next);                   // 先将新元素插入容器尾部
                push_heap(lists.begin(),lists.end(),cmp()); // push_heap操作进行调整
            }
        }
        return head->next;
    }
};