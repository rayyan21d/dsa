'''
Given an integer array nums of length n and an integer target, find three integers in nums such that the sum is closest to target.

Return the sum of the three integers.

You may assume that each input would have exactly one solution.

 

Example 1:

Input: nums = [-1,2,1,-4], target = 1
Output: 2
Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
Example 2:

Input: nums = [0,0,0], target = 1
Output: 0
Explanation: The sum that is closest to the target is 0. (0 + 0 + 0 = 0).
 

Constraints:

3 <= nums.length <= 500
-1000 <= nums[i] <= 1000
-104 <= target <= 104

'''

class Solution(object):
    def threeSumClosest(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        
        '''
        Brute force would be n^3 bc we will check every possible triplet.

        From prev problem, we can bring it down to n^2 by sorting and 2pointers.


        '''

        # Sort first
        nums.sort();
        n = len(nums);

        # Intialize with first three nums
        res = nums[0] + nums[1] + nums[2] 

        # Pick an element
        for i,a in enumerate(nums):

            l, r = i+1, n-1;
            while(l<r):

                summ = a + nums[l] + nums[r];
                if abs(summ - target) < abs(res - target):
                    res = summ

                if(summ > target):
                    r -=1;
                elif( summ < target):
                    l +=1;
                else:
                    return target;

        return res;
            
