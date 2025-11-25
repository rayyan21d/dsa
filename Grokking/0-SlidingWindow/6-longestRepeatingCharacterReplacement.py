'''
424. Longest Repeating Character Replacement

You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.

Return the length of the longest substring containing the same letter you can get after performing the above operations.

 

Example 1:

Input: s = "ABAB", k = 2
Output: 4
Explanation: Replace the two 'A's with two 'B's or vice versa.
Example 2:

Input: s = "AABABBA", k = 1
Output: 4
Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".
The substring "BBBB" has the longest repeating letters, which is 4.
There may exists other ways to achieve this answer too.
 

Constraints:

1 <= s.length <= 105
s consists of only uppercase English letters.
0 <= k <= s.length


'''

class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        

        
        freq = {};
        left = maxCount = maxLen =0;


        for right in range(len(s)):
            
            char = s[right];
            freq[char] = freq.get(char, 0) + 1;


            # Did the current char become the current maximum in the considered window?
            maxCount = max(maxCount, freq[char]);

            
            length = right - left + 1;

            while( length - maxCount > k):
                freq[s[left]] -=1;
                left +=1;
                length = right - left+1;
            
            maxLen = max(maxLen, length);
        
        return maxLen;

