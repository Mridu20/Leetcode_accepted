class Solution {
public:
    bool searchMatrix(vector<vector<int>>& a, int t) {
        int m = a.size();
        int n = a[0].size();
        bool h = false;
        for(int i=0; i<m && !h; i++){
            int left = 0;
            int right = n-1;

            while(left <= right){
                int mid = left +(right-left)/2;

                if(a[i][mid] == t)return true;
                else if(a[i][mid] > t)right = mid-1;
                else left = mid+1;
            }
        }

        return h;
    }
};