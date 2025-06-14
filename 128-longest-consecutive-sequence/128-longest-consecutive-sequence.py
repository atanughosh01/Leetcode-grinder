class Solution:

    def longestConsecutive_1(self, nums: List[int]) -> int:
        nums.sort()
        longest, cur_longest = 0, min(1, len(nums))
        for i in range(1, len(nums)):
            if nums[i] == nums[i - 1] : continue
            if nums[i] == nums[i - 1] + 1: cur_longest += 1
            else: longest, cur_longest = max(longest, cur_longest), 1
        return max(longest, cur_longest)


    def longestConsecutive_2(self, nums: List[int]) -> int:
        longest, s = 0, set(nums)
        for num in nums:
            cur_longest, j = 1, 1
            while num - j in s: 
                s.remove(num - j)
                cur_longest, j = cur_longest + 1, j + 1
            j = 1
            while num + j in s: 
                s.remove(num + j)
                cur_longest, j = cur_longest + 1, j + 1
            longest = max(longest, cur_longest)
        return longest


    def longestConsecutive(self, nums):
        s, longest = set(nums), 0
        for num in s:
            if num - 1 in s: continue
            j = 1
            while num + j in s: j += 1
            longest = max(longest, j)
        return longest
