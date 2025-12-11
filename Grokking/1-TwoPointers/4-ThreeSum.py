'''

3Sum

Given an integer array nums, 
return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.

 

Example 1:

Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Explanation: 
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].
Notice that the order of the output and the order of the triplets does not matter.
Example 2:

Input: nums = [0,1,1]
Output: []
Explanation: The only possible triplet does not sum up to 0.
Example 3:

Input: nums = [0,0,0]
Output: [[0,0,0]]
Explanation: The only possible triplet sums up to 0.
 

Constraints:

3 <= nums.length <= 3000
-105 <= nums[i] <= 105



'''


class Solution(object):
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        
        res = [];
        
        # Sort the array -> nlogn complexity added
        nums.sort();
        n = len(nums);

        # Pick up the first element of the triplet 
        # Overall complexity -> N^2 due to inner loop
        for i,a in enumerate(nums):
            
            # The first number of the triplet can't be positive
            # Because all others following are pos and sum can never be 0
            if a>0:
                break;

            # Check if the selected el has a duplicate
            # If yes we skip to the duplicate to consider it
            if a == nums[i+1]:
                continue;
            
            # The first element has been selected now the problem is a two pointer
            l, r = i+1, n-1;
            while(l<r):
                
                # Calculate sum
                sum = a + nums[l] + nums[r];
                
                # If too big, decrement
                if(sum > 0):
                    r -=1;
                
                elif(sum < 0):
                    l +=1;

                else:
                    res.append(a, nums[l], nums[r]);
                    l+=1;
                    r-=1;
                    
                    # Skip over all duplicates of left
                    while( nums[l] == nums[l-1] and l<r ):
                        l += 1;
                
        return res;
    
            




