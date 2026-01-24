class Solution {
public:
    int singleNonDuplicate(vector<int>& a) {
        int left = 0;
        int right = a.size()-1;

        while(left <= right){
            int mid = left + (right-left)/2;

            if(mid > 0 && a[mid]==a[mid-1]){
                if(mid%2 == 1)left = mid+1;
                else right = mid-1;
            }
            else if(mid<a.size()-1 && a[mid]==a[mid+1]){
                if(mid%2 == 0)left = mid+1;
                else right = mid-1;
            }
            else return a[mid];
        }

        return -1;
    }
};