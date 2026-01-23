class Solution {
public:
    vector<int> searchRange(vector<int>& n, int t) {
        int left = 0;
        int right = n.size()-1;

        int lb = -1, ub = -1;
        while(left<= right){
            int mid = left + (right-left)/2;

            if(n[mid] <= t){
                ub = mid;
                left = mid+1;
            }
            else right = mid-1;
        }

        left=0;
        right=n.size()-1;

        while(left<= right){
            int mid = left + (right-left)/2;

            if(n[mid] >= t){
                lb = mid;
                right = mid-1;
            }
            else left = mid+1;
        }

        if (lb == -1 || ub == -1 || lb > ub || n[lb] != t || n[ub] != t)
            return {-1, -1};

        return {lb, ub};

    }
};