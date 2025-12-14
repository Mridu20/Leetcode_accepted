class Solution {
public:
    int minOperations(vector<int>& n, int k) {
        int sum = 0;
        for(int a: n){
            sum += a;
        }

        return sum%k;
    }
};