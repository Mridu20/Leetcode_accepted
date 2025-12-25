class Solution {
public:
    long long maximumHappinessSum(vector<int>& h, int k) {
        sort(h.begin(), h.end(), greater<int>());
        long long sum = 0;
        int cnt=0;
        for(int i=0; i<k; i++){
            if(h[i]-cnt >= 0){
                sum += (h[i]-cnt);
            }

            cnt++;
        }

        return sum;
    }
};