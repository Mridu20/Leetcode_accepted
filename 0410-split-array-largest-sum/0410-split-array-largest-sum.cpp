class Solution {
public:
    int splitArray(vector<int>& a, int k) {
        int left = *max_element(a.begin(), a.end());

        int sum = 0;
        for(int i=0 ;i<a.size(); i++)sum += a[i];

        int right = sum;
        int ans = left;
        while(left <= right){
            int mid = left + (right- left)/2;

            int cnt=0;
            int sm = 0;
            for(int i=0; i<a.size(); i++){
                if(sm + a[i] <= mid)sm+=a[i];
                else{
                    cnt++;
                    sm=a[i];
                }
            }

            if(sm>0)cnt++;

            if(cnt > k)left = mid+1;
            else{
                ans = mid;
                right = mid-1;
            }
        }

        return ans;
    }
};