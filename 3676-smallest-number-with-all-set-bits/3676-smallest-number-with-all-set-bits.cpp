class Solution {
public:
    int smallestNumber(int n) {
        int d = (int)log2(n);
        int ans = (pow(2, d+1)) -1;

        return ans;
    }
};