class Solution {
public:
    int findPeakElement(vector<int>& n) {
        int left = 0;
        int right=n.size()-1;
        // int ans;

        while(left < right){
            int mid = left + (right-left)/2;

            if(n[mid]>n[mid+1]){
                right = mid;
            }
            else left = mid+1;
        }

        return left;
    }
};