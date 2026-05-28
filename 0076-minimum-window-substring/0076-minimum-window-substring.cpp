class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.length();
        int n = t.length();

        if (m < n) return "";

        unordered_map<char, int> need, freq;

        for (char c : t) need[c]++;

        int left = 0;
        int matched = 0;           
        int need_count = need.size();

        int minLen = INT_MAX;
        int minStart = 0;

        for (int right = 0; right < m; right++) {
            char c = s[right];

            if (need.count(c)) {   
                freq[c]++;
                if (freq[c] == need[c]) matched++;
            }

            while (matched == need_count) {
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    minStart = left;
                }

                char lc = s[left];
                left++;

                if (need.count(lc)) {
                    if (freq[lc] == need[lc]) matched--; 
                    freq[lc]--;
                }
            }
        }

        return minLen == INT_MAX ? "" : s.substr(minStart, minLen);
    }
};