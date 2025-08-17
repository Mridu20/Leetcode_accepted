class Solution {
public:
    int differenceOfSums(int n, int m) {
        int k = n/m;
        int l = 2*k*m + k*(k-1)*m;
        int j = (n*(n+1))/2;

        return j-l;
    }
};