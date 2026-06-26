class BIT {
public:
    int n;
    vector<int> bit;

    BIT(int n) {
        this->n = n;
        bit.assign(n + 1, 0);
    }

    void update(int idx, int val) {
        while (idx <= n) {
            bit[idx] += val;
            idx += idx & -idx;
        }
    }

    int query(int idx) {
        int ans = 0;
        while (idx > 0) {
            ans += bit[idx];
            idx -= idx & -idx;
        }
        return ans;
    }
};

class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();

        BIT bit(2 * n + 1);

        int pref = n + 1;

        bit.update(pref, 1);

        long long ans = 0;

        for (int x : nums) {
            if (x == target)
                pref++;
            else
                pref--;

            ans += bit.query(pref - 1);

            bit.update(pref, 1);
        }

        return ans;
    }
};