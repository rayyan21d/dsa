'''

Given an array nums with n objects colored red, white, or blue, 
sort them in-place so that objects of the same color are adjacent, 
with the colors in the order red, white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

You must solve this problem without using the library's sort function.

 
Example 1:

Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
Example 2:

Input: nums = [2,0,1]
Output: [0,1,2]

'''

class Solution(object):
    
    def sortColorsHashMap(self, nums):
        """
        :type nums: List[int]
        :rtype: None Do not return anything, modify nums in-place instead.
        """
        
        count = {0: 0, 1: 0, 2: 0};
        for num in nums: 
            count[num] += 1

        i = 0;
        for color in [0, 1, 2]: 
            for _ in range(count[color]): 
                nums[i] = color 
                i += 1
                
                


    def sortColorsThreePointers(self, nums):
        """
        :type nums: List[int]
        :rtype: None Do not return anything, modify nums in-place instead.
        """
        
        n = len(nums);
        i = 0;
        left = 0;
        right = n -1;
        
        while(i<=right):
            
            # If we encounter a 0
            # We swap the i and the left and increment them
            if(nums[i] == 0):
                nums[i], nums[left] = nums[left], nums[i];
                left +=1;
                i+=1;
            elif(nums[i] == 1):
                i+=1;
            else:
                nums[i], nums[right] = nums[right], nums[i];
                right -=1;
                
        
        return;
    
       