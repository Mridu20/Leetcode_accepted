class Solution {
public:
    int minElement(vector<int>& a) {
        int n = a.size();
        int mn = INT_MAX;
        for(int i=0; i<n; i++){
            int b = a[i];
            int sum = 0;
            while(b>0){
                sum += b%10;
                b /= 10;
            }

            a[i] = sum;
            mn = min(mn, a[i]);
        }

        return mn;
    }
};