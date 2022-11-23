class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        result = []
        for index_1, elem_1 in enumerate(nums):
            for index_2, elem_2 in enumerate(nums[(index_1+1):]):
                if (elem_1 + elem_2 == target):
                    result.append(index_1)
                    result.append(index_1 + index_2 + 1)
                    return result

"""
57 / 57 test cases passed.
Status: Accepted
Runtime: 8481 ms
Memory Usage: 15 MB
"""

