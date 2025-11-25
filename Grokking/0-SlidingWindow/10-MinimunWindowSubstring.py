'''

Given two strings s and t of lengths m and n respectively, 
return the minimum window substring of s such that 
every character in t (including duplicates) is included in the window. 
If there is no such substring, return the empty string "".

The testcases will be generated such that the answer is unique.

 

Example 1:

Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
Example 2:

Input: s = "a", t = "a"
Output: "a"
Explanation: The entire string s is the minimum window.
Example 3:

Input: s = "a", t = "aa"
Output: ""
Explanation: Both 'a's from t must be included in the window.
Since the largest window of s only has one 'a', return empty string.
 

Constraints:

m == s.length
n == t.length
1 <= m, n <= 105
s and t consist of uppercase and lowercase English letters.


'''


class Solution:
    def minWindow(self, s: str, t: str) -> str:

        if not s or not t:
            return ""

        m = len(s);
        n = len(t);


        # freq = Counter(t);
        freq = {};
        for char in t:
            freq[char] = freq.get(char, 0) + 1;
        

        seen = {};
        minLength= float('inf');
        need = len(freq);
        res, resLen = [-1, -1], float("inf");
        have = 0;
        left = 0;

        for right in range(m):

            # Expand window
            ch = s[right];
            seen[ch] = seen.get(ch, 0) +1;

            # Increments the have incase the added exists in the 
            if(ch in freq and seen[ch] == freq[ch]):
                have +=1;

            #Shrink
            while have == need:
                # Update result
                if (right - left + 1) < resLen:
                    res = [left, right]
                    resLen = right - left + 1

                # Pop from left
                seen[s[left]] -= 1
                if s[left] in freq and seen[s[left]] < freq[s[left]]:
                    have -= 1
                left += 1

        l, r = res
        return s[l:r+1] if resLen != float("inf") else ""

        