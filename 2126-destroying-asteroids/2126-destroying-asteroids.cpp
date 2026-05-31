class Solution {
public:
    bool asteroidsDestroyed(int m, vector<int>& a) {
        sort(a.begin(), a.end());
        int n = a.size();
        long long sum = m;
        for(int i=0; i<n; i++){
            if(sum >= a[i]) sum+=a[i];
            else return false;
        }

        return true;
    }
};