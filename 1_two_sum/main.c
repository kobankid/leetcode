/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){

    int *result = calloc((*returnSize = 2), sizeof(int));

    for (int i = 0; i < numsSize; i++) {
        int diff = target - nums[i];
        for (int j = i+1; j < numsSize; j++) {
            if (diff == nums[j]) {
                result[0] = i;
                result[1] = j;
                return result;
            }
        }
    }

    return 0;
}

/*
57 / 57 test cases passed.
Status: Accepted
Runtime: 145 ms
Memory Usage: 6.6 MB
*/

