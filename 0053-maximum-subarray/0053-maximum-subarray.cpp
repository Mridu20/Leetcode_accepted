class Solution {
public:
    int maxSubArray(vector<int>& n) {
        int sum = 0;
        int mxs = INT_MIN;

        for(int i=0; i<n.size(); i++){
            sum += n[i];
            mxs = max(sum, mxs);
            
            sum = max(0, sum);
        }

        return mxs;
    }
};