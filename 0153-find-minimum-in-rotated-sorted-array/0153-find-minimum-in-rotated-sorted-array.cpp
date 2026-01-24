class Solution {
public:
    int findMin(vector<int>& a) {
        int left = 0;
        int right = a.size() - 1;

        while (left < right){
            int mid = left + (right - left) / 2;

            if (a[mid] > a[right]) left = mid + 1;
            else right = mid;
        }

        return a[left];
    }
};
