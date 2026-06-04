class Solution {
public:
    int lengthOfLIS(vector<int>& a) {
        int n = a.size();
        vector<int> lis(n, 1);
        
        for(int i=1; i<n; i++){
            int j = 0;
            while(j<i){
                if(a[i]>a[j])lis[i] = max(lis[i], lis[j]+1);
                j++;
            }
        }

        int ans = *max_element(lis.begin(), lis.end());
        return ans;
    }
};