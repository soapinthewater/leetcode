/*
 * @lc app=leetcode.cn id=80 lang=c
 *
 * [80] 删除排序数组中的重复项 II
 */

// @lc code=start


int removeDuplicates(int* nums, int numsSize){
    int *head, *tail, *p;
    int result = 0, count = 0;
    head = nums;
    count ++;
    while(count < numsSize)
    {
        if(head == nums){
            tail = head + 1;
            printf("head :%d tail :%d ",*head, *tail);
            count ++;
        }
        else{
            head = tail;
            printf("head :%d tail:%d ",*head, *tail);
            tail = head + 1;
            count ++;
        }
        while(*head == *tail) {
            tail ++;
            count ++;
        }
        printf("%d", count);
        if(tail-head > 2){
            int step = tail - head - 2;
            result += step;
            for(p=tail; p < nums + numsSize; p++){
                *(p-step) = *p;
                printf("%d", *p);
            }
            tail = tail - step;
            printf("\n");
        }
    }
    result = numsSize - result;
    return result;
}


// @lc code=end

