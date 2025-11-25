'''

Given a string s and an integer k, return the length of the longest substring that contains at most k distinct characters.

If k is 0 or the string is empty, return 0.

Example 1:
Input: s = "eceba", k = 2 → Output: 3
Explanation: The answer is "ece" with 2 distinct characters.

Example 2:
Input: s = "aa", k = 1 → Output: 2
Explanation: The entire string has only one distinct character.


'''


class SlidingWindowSolution:
    
    def LongestSubstringAtMostK(self, s:str, k:int) -> int:
        
        
        freq = {}
        left = maxLen = 0;
        
        for r in range(len(s)):
            freq[s[r]] = freq.get(s[end, 0] + 1);
            
            while len(freq) > k:
                freq[s[left]] -=1;
                if freq[s[left]] == 0:
                    del freq[s[left]];
                    
                left+=1;
            
            maxLen = max(maxLen, r - left +1);
            

        return maxLen;
                
            

