/*
 * @lc app=leetcode.cn id=141 lang=c
 *
 * [141] 环形链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    struct ListNode *pointer_fast = head, *pointer_slow = head;
    int counter_fast = 0 , counter_slow = 0;
    if(head == NULL)
        return false;
    while(pointer_fast->next != NULL)
    {
        pointer_fast = pointer_fast->next;
        counter_fast ++;
        pointer_slow = head;
        counter_slow = 0;
        while(pointer_slow != pointer_fast){
            pointer_slow = pointer_slow->next;
            counter_slow ++;
        }
        printf("%d %d \n",counter_slow, counter_fast);
        if (counter_slow != counter_fast || pointer_slow == head)   
            return true;
    }
    return false;

}
// @lc code=end

