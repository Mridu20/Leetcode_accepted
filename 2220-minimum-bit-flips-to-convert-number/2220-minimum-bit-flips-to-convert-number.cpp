class Solution {
public:
    int minBitFlips(int a, int b) {
        return __builtin_popcount(a^b);
    }
};