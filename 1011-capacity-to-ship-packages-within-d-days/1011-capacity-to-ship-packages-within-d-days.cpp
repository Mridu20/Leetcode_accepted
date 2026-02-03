class Solution {
public:
    int shipWithinDays(vector<int>& w, int d) {
        int mx = 0;
        for(int i=0; i<w.size(); i++){
            mx += w[i];
        }

        int left = *max_element(w.begin(), w.end());
        int right = mx;
        int ans = mx;

        while(left <= right){
            int mid = left + (right- left)/2;

            int num=0;
            int m=0;
            for(int i=0; i<w.size(); i++){
                if(m + w[i] <= mid)m+=w[i];
                else {
                    num++;
                   m=w[i];
                }
            }

            if(m>0)num++;

            if(num <= d){
                ans = mid;
                right = mid-1;
            }
            else left = mid+1;
        }

        return ans;
    }
};