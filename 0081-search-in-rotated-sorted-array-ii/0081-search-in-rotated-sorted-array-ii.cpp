class Solution {
public:
    bool search(vector<int>& a, int t) {
        int left = 0, right = a.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (a[mid] == t) return true;

            if (a[left] == a[mid] && a[mid] == a[right]) {
                left++;
                right--;
            }
            else if (a[left] <= a[mid]) {
                if (a[left] <= t && t < a[mid])
                    right = mid - 1;
                else
                    left = mid + 1;
            }
            else {
                if (a[mid] < t && t <= a[right])
                    left = mid + 1;
                else
                    right = mid - 1;
            }
        }

        return false;
    }
};
