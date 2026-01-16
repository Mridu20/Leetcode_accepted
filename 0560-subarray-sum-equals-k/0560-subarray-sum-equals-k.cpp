class Solution {
public:
    int subarraySum(vector<int>& a, int k) {
        int n = a.size();
        unordered_map<int, int> pfscnt;
        int pfs = 0;
        int cnt = 0;

        pfscnt[0] = 1; 

        for (int i = 0; i < n; i++) {
            pfs += a[i];
            int remove = pfs - k;

            if (pfscnt.find(remove) != pfscnt.end()) {
                cnt += pfscnt[remove];
            }
            pfscnt[pfs]++;
        }
        return cnt;
    }
};