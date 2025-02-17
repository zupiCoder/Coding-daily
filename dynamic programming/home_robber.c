#include<stdio.h>
#include<stdlib.h>

int robHelper(int* nums, int i, int numsSize);
int memo[101];

int rob(int* nums, int numsSize) {
    for(int i = 0; i < numsSize; i++) memo[i] = -1;

    int max0 = robHelper(nums, 0, numsSize);
    int max1 = robHelper(nums, 1, numsSize);
    
    return max0 > max1 ? max0 : max1;
}   

int robHelper(int* nums, int i, int numsSize) {
    
    if(i == numsSize -1) return nums[i];
    if(i >= numsSize) return 0;

    if(memo[i] != -1) return memo[i];

    int temp = 0; int max = 0;
    for(int x = i + 2; x < numsSize; x++) {
        temp = robHelper(nums, x,  numsSize);
        if(temp > max) max = temp;
    }
    memo[i] = nums[i] + max;

    return memo[i];
}

int main() {
    int nums[] = {2, 7, 9, 3, 1};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int result = rob(nums, numsSize);
    printf("Maximum amount that can be robbed: %d\n", result);
    return 0;
}