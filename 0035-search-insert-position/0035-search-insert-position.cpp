class Solution {
public:
    int searchInsert(vector<int>& m, int t) {
        int left = 0, right = m.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (m[mid] == t) {
            return mid;
        } else if (m[mid] < t) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return left;
    }
};