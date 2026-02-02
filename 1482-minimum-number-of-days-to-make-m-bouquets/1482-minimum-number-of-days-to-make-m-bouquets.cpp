class Solution {
public:
    int minDays(vector<int>& a, int m, int k) {
        int right = *max_element(a.begin(), a.end());
        int left = 1;

        int d = -1;
        while(left <= right){
            int mid = left + (right-left)/2;

            int ans=0;
            int cnt=0;

            for(int i=0; i<a.size(); i++){
                if(a[i] <= mid)cnt++;
                else{
                    ans += cnt/k;
                    cnt = 0;
                }
            }

            ans += cnt / k;

            if(m <= ans){
                d = mid;
                right = mid-1;
            }
            else left=mid+1;
        }

        return d;
    }
};