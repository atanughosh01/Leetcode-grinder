class Solution:
    def numIdenticalPairs(self, nums: List[int]) -> int:
        mp = defaultdict(int)
        count = 0
        for num in nums:
            count += mp[num]
            mp[num] += 1
        return count
