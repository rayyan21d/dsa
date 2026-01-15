'''

3. Longest Substring Without Repeating Characters

 

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3. Note that "bca" and "cab" are also correct answers.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
 

Constraints:

0 <= s.length <= 5 * 104
s consists of English letters, digits, symbols and spaces.

'''


class Solution:
    
    
    def lengthOfLongestSubstring(self, s: str) -> int:

        freq = {};
        left = maxLen = 0;

        for right in range(len(s)):

            selected = s[right];
            freq[selected] = freq.get(selected, 0) + 1;

            while freq[selected] > 1:
                freq[s[left]] -=1;
                left += 1;

            currLen = right - left + 1;
            maxLen = max(maxLen, currLen);


        return maxLen;
    
    def lengthOfLongestSubstringDict(self, s: str) -> int:

        left = maxLen = 0;
        counter = defaultdict(int)

        for right in range(len(s)):

            selected = s[right];
            counter[selected] +=1;

            while counter[selected] > 1:
                freq[s[left]] -=1;
                left += 1;

            currLen = right - left + 1;
            maxLen = max(maxLen, currLen);


        return maxLen;


    def lengthOfLongestSubstringSet(self, s: str) -> int:

        
        left = maxLen = 0
        counter = set()

        for right in range(len(s)):

            ch = s[right];

            if ch in counter:
                # Already contains in the window
                while ch in counter:
                    counter.remove(s[left]);
                    left += 1;

        
            # Add to set and expand window
            counter.add(ch);
            maxLen = max(right-left +1, maxLen);

    

        return maxLen;
        








