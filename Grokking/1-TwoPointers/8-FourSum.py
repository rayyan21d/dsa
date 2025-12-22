'''
Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

0 <= a, b, c, d < n
a, b, c, and d are distinct.
nums[a] + nums[b] + nums[c] + nums[d] == target
You may return the answer in any order.

 

Example 1:

Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
Example 2:

Input: nums = [2,2,2,2,2], target = 8
Output: [[2,2,2,2]]
 
'''


class Solution(object):
    
    def fourSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        

class SumProblems():
    
    
    # Returns all the pairs of compliment and number!
    def TwoSumHashing(self, nums, target):
        
        
        n = len(nums);
        seen = set()
        result = []
        
        for x in nums:
            
            comp = target - x;
            if comp in seen:
                res.append([comp, x]);
            
            seen.add(x);
        
        return result;
                
        
        
        
        
    def TwoSumTwoPointers(self, nums, target):
        
        # We need to sort the array for this to work
        # Then we take advantage of high and low pointers
        
        n = len(nums);
        low = 0;
        high = n-1;
        result = []
        nums.sort();
        
        while low<high:
            
            s = nums[low] + nums[high];
            
            if s == target:
                result.append([nums[low], nums[high]]);
                low +=1
                high -=1;
                
                # Skip over the duplicates
                while low<high and nums[low] == nums[low-1]:
                    low +=1;
                
                while low < high and nums[high] == nums[high+1]:
                    high -=1;
                
            elif s<target:
                low +=1;
            else: 
                high -=1;
            
        
        return result;
        
        
        
        
        
        
        
    def ThreeSumHashing(self, nums, target):
        
        # Select one element and then hash the remaining part of array and treat it as 
    
        nums.sort();
        n = len(nums);
        result = [];
        
        for i in range(n):
            
            if i > 0 and nums[i] == nums[i-1]:
                continue;
            
            # Selected the i-th element
            seen = set();
            for j in range(i+1, n):
                comp = target - nums[i] - nums[j];
                
                if(comp in seen):
                    result.append([nums[i], comp, nums[j]]);
                
                seen.add(nums[j]);
            
        return result;
    
    

    
    def ThreeSumTwoPointers(self, nums, target):
        
        # The Golden solution for ThreeSum using no extra space!
        n = len(nums);
        result = [];
        
        nums.sort();
        
        for i in range(n):
            # We selected the i-th element
            if i > 0 and nums[i] == nums[i-1]:
                continue;

            left, right = i+1, n-1;
            while(left<right):
                
                s = nums[i] + nums[left] + nums[right];
                if s == target :
                    result.append([nums[i], nums[left], nums[right]]);
                elif s < target:
                    left+=1;
                else:
                    right -=1;
            
            return result;
        
        

        
    def FourSumTwoPointers(self, nums, target):
        
        # Fix two pointers and then apply the low, high logic 
        
        n = len(nums);
        nums.sort();
        result = [];
        
        for i in range(n):
            
            if i>0 and nums[i] == nums[i-1]:
                continue;
            
            for j in range(i+1, n):
                
                if j > i+1 and nums[j] == nums[j-1]:
                    continue;
                
                left, right = j+1, n-1;
                
                while left < right:
                    s = nums[i] + nums[j] + nums[left] + nums[right];
                    
                    if(s<target):
                        left +=1;
                    elif(s>target):
                        right -=1;
                    else:
                        result.append([nums[i], nums[j], nums[left], nums[right]]);
                        
                        left +=1;
                        right -=1;
                        
                        # Skip over duplicates
                        while left < right and nums[left] == nums[left -1]:
                            left +=1;
                        ehile left < right and nums[right] == nums[right+1]:
                            right -=1;
        
        
        return result;