class Solution {
public:
    int search(vector<int>& a, int t) {
        int left = 0;
        int right = a.size()-1;

        while(left <= right){
            int mid = left + (right-left)/2;
            if(a[mid] == t)return mid;
            else if(a[mid] > t){
                right = mid-1;
            }
            else left = mid+1;
        }

        return -1;
    }
};