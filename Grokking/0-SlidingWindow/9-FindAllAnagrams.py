'''

Given two strings s and p, return an array of all 
the start indices of p's anagrams in s. 
You may return the answer in any order.

 

Example 1:

Input: s = "cbaebabacd", p = "abc"
Output: [0,6]
Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".
Example 2:

Input: s = "abab", p = "ab"
Output: [0,1,2]
Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".
 

Constraints:

1 <= s.length, p.length <= 3 * 104
s and p consist of lowercase English letters.

'''


class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:

        freq = {};
        for i in range(len(p)):
            freq[p[i]] = freq.get(p[i], 0) + 1;
        

        seen = {};
        left = 0;
        ans = [];
        maxWindow = len(p);

        for right in range(len(s)):

            # Expand window
            seen[s[right]] = seen.get(s[right], 0) + 1;

            # Shrink window
            while(right - left + 1 > maxWindow):
                leftChar = s[left];
                seen[leftChar] = seen.get(leftChar, 0) - 1;
                if(seen.get(leftChar) <= 0):
                    del seen[leftChar];
                
                left += 1;
                

            if(seen == freq):
                ans.append(left);

        return ans;




        











