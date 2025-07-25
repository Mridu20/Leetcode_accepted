class Solution {
public:
    int strStr(string h, string n) {
        int hs = h.size(), ns = n.size();

        for (int i = 0; i <= hs - ns; i++) {
            int j = 0;
            while (j < ns && h[i + j] == n[j]) {
                j++;
            }
            if (j == ns) return i;
        }
        return -1;
    }
};