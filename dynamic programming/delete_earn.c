int maxEarnings(int* nums, int* memo, int i, int numsSize);
#define MAX 10000

int deleteAndEarn(int* nums, int numsSize) {
    int earn[MAX] = {0};
    int* memo = malloc(MAX * sizeof(int));
    for (int i = 0; i < MAX; i++) memo[i] = -1;

    for(int i = 0; i < numsSize; i++) earn[nums[i]] += nums[i];

    return maxEarnings(earn, memo, MAX - 1, numsSize);
}

int maxEarnings(int* nums, int* memo, int i, int numsSize) {
    if(i < 0) return 0;
    
    if(memo[i] != -1) return memo[i];

    int take = nums[i] + maxEarnings(nums, memo, i - 2, numsSize);
    int skip = maxEarnings(nums, memo, i - 1, numsSize);

    memo[i] = (take > skip) ? take : skip;

    return memo[i];       
}      