class Solution {
public:
    vector<int> plusOne(vector<int>& d) {
        if (d[d.size() - 1] < 9) {
            d[d.size() - 1]++;

            return d;
        } else {
            long long i = d.size() - 1;
            while (i >= 0 && d[i] == 9) {
                d[i] = 0;
                i--;
            }

            if (i == -1) {
                d.insert(d.begin(), 1);
            } else {
                d[i]++;
            }

            return d;
        }
    }
};