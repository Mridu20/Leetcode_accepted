class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& a) {
        int cnt=0;
        int mx=0;

        for(int i=0; i<a.size(); i++){
            if(a[i] == 1)cnt++;
            else{
                mx = max(mx, cnt);
                cnt=0;
            }
        }

        mx = max(mx, cnt);

        return mx;
    }
};