/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
 struct Compare{
    bool operator()(ListNode*a,ListNode*b){
        return a->val > b->val;
    }
 };

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,Compare>minHeap;
        for(ListNode*listHead:lists){
            if(listHead!=nullptr){
                minHeap.push(listHead);
            }
        }
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;
        while(!minHeap.empty()){
            ListNode*smallest = minHeap.top();
            minHeap.pop();
            tail->next = smallest;
            tail=tail->next;
            if(smallest->next!=nullptr){
                minHeap.push(smallest->next);
            }
        }
        ListNode*result = dummy->next;
        delete dummy;
        return result;
    }
};
