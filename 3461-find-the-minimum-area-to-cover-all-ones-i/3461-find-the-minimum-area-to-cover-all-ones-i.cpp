class Solution {
public:
    int minimumArea(vector<vector<int>>& a) {
        int mni = a[0].size(), mxi = 0; 
        int mnj = a.size(), mxj = 0;

        for(int i=0; i<a.size(); i++){
            for(int j=0; j<a[0].size(); j++){
                if(a[i][j] == 1){
                    mni = min(mni, i);
                    mxi = max(mxi, i);
                    mnj = min(mnj, j);
                    mxj = max(mxj, j);
                }
            }
        }

        int ar = (mxj - mnj+1)*(mxi - mni+1);
        return ar;
    }
};