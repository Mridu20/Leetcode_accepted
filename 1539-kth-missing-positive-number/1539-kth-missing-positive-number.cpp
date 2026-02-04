class Solution {
public:
    int findKthPositive(vector<int>& a, int k) {
        int left = 0;
        int right = a.size()-1;
        int indx = right+1;
        while(left <= right){
            int mid = left + (right-left)/2;

            if(a[mid]-mid-1 >= k){
                right = mid-1;
                indx = mid;
            }
            else left = mid+1;
        }

        return indx+k ;
    }
};