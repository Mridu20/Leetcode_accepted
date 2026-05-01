class Solution {
public:
    typedef long long ll;
    int maxRotateFunction(vector<int>& nums) {
       int n = nums.size();
    ll total = 0, f = 0;
    
    for (int i = 0; i < n; i++) {
        total += nums[i];
        f += (ll)i * nums[i];
    }
    
    ll max_f = f;
    
    for (int k = 1; k < n; k++) {
        f = f + total - (ll)n * nums[n - k];
        max_f = max(max_f, f);
    }
    
    return (int)max_f; 
    }
};