class Solution {
public:
    int smallestDivisor(vector<int>& a, int t) {
        int left = 1;
        int right = *max_element(a.begin(), a.end());
        int ans = right;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            long long sum = 0;
            for (int i = 0; i < a.size(); i++) {
                sum += (a[i] + mid - 1) / mid;  
            }

            if (sum <= t) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return ans;
    }
};
