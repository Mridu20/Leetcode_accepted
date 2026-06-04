class Solution {
public:
    int rob(vector<int>& a) {
        int n = a.size();
        vector<int> mxl(n);

        if(n==1)return a[0];

        int tot = 0;
        mxl[0] = a[0];
        mxl[1] = max(a[0], a[1]);
        for(int i=2; i<n; i++){
            int d1 = mxl[i-1];
            int d2 = mxl[i-2] + a[i];

            mxl[i] = max(d1, d2);
        }

        return mxl[n-1];
    }
};