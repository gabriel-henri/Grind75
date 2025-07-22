/*
You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.
*/


 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };


class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* merged = nullptr;

        ListNode* point1 = list1;
        ListNode* point2 = list2;
        ListNode* pointmerg = merged;

        while(point1 != nullptr && point2 != nullptr){
            if(merged == nullptr){
                if(point1->val > point2->val){
                    merged= new ListNode(point2->val);
                    point2 = point2->next;
                }else{
                    merged = new ListNode(point1->val);
                    point1 = point1->next;
                }
                pointmerg = merged;
            }else{
                if(point1->val > point2->val){
                    pointmerg->next = new ListNode(point2->val);
                    pointmerg = pointmerg->next;
                    point2 = point2->next;
                }else{
                    pointmerg->next = new ListNode(point1->val);
                    pointmerg = pointmerg->next;
                    point1 = point1->next;
                }
            }
        }

        while(point1 != nullptr){
            if(merged == nullptr){
                merged = new ListNode(point1->val);
                pointmerg = merged;
                point1 = point1->next;
            }else{
                pointmerg->next = new ListNode(point1->val);
                pointmerg = pointmerg->next;
                point1 = point1->next;
            }
        }

        while(point2 != nullptr){
            if(merged == nullptr){
                merged = new ListNode(point2->val);
                pointmerg = merged;
                point2 = point2->next;
            }else{
                pointmerg->next = new ListNode(point2->val);
                pointmerg = pointmerg->next;
                point2 = point2->next;
            }
        }

        return merged;
    }
};