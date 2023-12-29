/*
    Given the head of a singly linked list, group all the nodes with odd indices together followed by the nodes with even indices, and return the reordered list.
    The first node is considered odd, and the second node is even, and so on.
    Note that the relative order inside both the even and odd groups should remain as it was in the input.
    You must solve the problem in O(1) extra space complexity and O(n) time complexity.

    Example 1:
    Input: head = [1,2,3,4,5]
    Output: [1,3,5,2,4]
*/

#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next) 
            return head;
        
        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* evenHead = even; 

        while (even != nullptr && even->next != nullptr) {
            odd->next = even->next; 
            odd = odd->next;

            even->next = odd->next; 
            even = even->next;
        }

        odd->next = evenHead; 

        return head;
    }
};