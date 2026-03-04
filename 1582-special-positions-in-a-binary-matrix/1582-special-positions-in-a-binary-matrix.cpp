class Solution {
public:
    int numSpecial(vector<vector<int>>& a) {
        int m = a.size();
        int n = a[0].size();
        int cnt=0;

        for(int i=0; i<m; i++){
            for(int j=0; j<n;j++){
                if(a[i][j]==1){
                    bool h = true;
                    for(int k=0; k<m && h; k++)if(a[k][j]==1 && k != i)h=false;
                    for(int k=0;k<n &&h; k++)if(a[i][k] == 1 && j!=k)h=false;

                    if(h)cnt++;
                }
            }
        }

        return cnt;
    }
};