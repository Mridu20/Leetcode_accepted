class Solution {
public:
    int minimumBoxes(vector<int>& a, vector<int>& c) {
        int sum=0;
        for(int i=0; i<a.size(); i++){
            sum += a[i];
        }

        sort(c.begin(), c.end());
        int cnt = 0;

        for(int i=c.size()-1; i>=0 && sum>0; i--){
            sum -= c[i];
            cnt++;
        }

        return cnt;
    }
};