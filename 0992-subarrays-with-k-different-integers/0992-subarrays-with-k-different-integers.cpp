class Solution {
public:
    int atMostK(vector<int>& a, int K) {
        unordered_map<int, int> freq;
        int left = 0, count = 0;

        for (int right = 0; right < a.size(); right++) {
            if (freq[a[right]] == 0) {
                K--;
            }

            freq[a[right]]++;
            while (K < 0) {
                freq[a[left]]--;
                if (freq[a[left]] == 0) {
                    K++;
                }
                left++;
            }

            count += (right - left + 1);
        }

        return count;
    }
    
    int subarraysWithKDistinct(vector<int>& a, int k) {  
        int ans = atMostK(a, k) - atMostK(a, k-1);
        return ans;        
    }

};