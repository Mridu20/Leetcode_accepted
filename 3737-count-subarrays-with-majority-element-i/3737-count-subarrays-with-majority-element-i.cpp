class Solution {
public:
    int countMajoritySubarrays(vector<int>& a, int t) {
        int n = a.size();
        vector<int> mcnt(n);
        int cnt = 0;

        for(int i=0; i<n; i++){
            if(a[i] == t)cnt++;

            mcnt[i] = cnt;
        }

        int ans=0;
        for(int i=0; i<n; i++){
            if(mcnt[i] > (i+1)/2)ans++;
            for(int j=0 ;j<i; j++){
                int d = mcnt[i] - mcnt[j];
                if(d > (i-j)/2)ans++;
            }
        }

        return ans;
    }
};