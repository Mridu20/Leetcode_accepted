class Solution {
public:
    bool searchMatrix(vector<vector<int>>& a, int t) {
        int n=a.size(), m=a[0].size();
        int row=0, col=m-1;
        while(row<n && col>=0){
            if(a[row][col]==t) return true;
            else if(a[row][col]<t) row++;
            else{
                col--;
            } 
        }
        return false;
    }
};