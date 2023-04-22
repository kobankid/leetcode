class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        ascii_dict: list[int] = [-1] * 256
        start = -1
        max_val = 0
        str_len = len(s)
        for i in range(str_len):
            if (ascii_dict[ord(s[i])] > start):
                start = ascii_dict[ord(s[i])]
            ascii_dict[ord(s[i])] = i
            max_val = max(i - start, max_val)
        return max_val

if __name__ == '__main__':
    sol = Solution()
    print(sol.lengthOfLongestSubstring('abcdeffeeeabcdefghi'))
    