class Solution {
public:
    int numberOfSubarrays(vector<int>& a, int k) {
        int ans =0;
        vector<int> o;
        o.push_back(-1);
        for(int i=0; i<a.size(); i++){
            if(a[i]%2 == 1)o.push_back(i);
        }
        o.push_back(a.size());

        if(o.size()-2 < k)return 0;

        for(int i=1; i+k<o.size(); i++){
            int l = o[i] -o[i-1];
            int r = o[i+k]-o[i+k-1];

            ans += l*r;
        }

        return ans;

    }
};