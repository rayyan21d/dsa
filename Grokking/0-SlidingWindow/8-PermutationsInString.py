'''

Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.

In other words, return true if one of s1's permutations is the substring of s2.

 

Example 1:

Input: s1 = "ab", s2 = "eidbaooo"
Output: true
Explanation: s2 contains one permutation of s1 ("ba").
Example 2:

Input: s1 = "ab", s2 = "eidboaoo"
Output: false
 

Constraints:

1 <= s1.length, s2.length <= 104
s1 and s2 consist of lowercase English letters.


'''


class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:

        freq = {};

        for i in range(len(s1)):
            freq[s1[i]] = freq.get(s1[i], 0 ) + 1;
        
        seen = {};

        left = 0;
        finalSize = len(s1);

        for right in range(len(s2)):
            
            # Expand Window
            char = s2[right];
            seen[char] = seen.get(char, 0) + 1;

            # Shrink while the length of window is greater
            while(right - left + 1 > finalSize):

                if(seen.get(s2[left]) - 1 == 0):
                    del seen[s2[left]];
                else:
                    seen[s2[left]] = seen.get(s2[left]) - 1;
                
                left += 1;

            if seen == freq:
                return True;
        
        return False;

        





