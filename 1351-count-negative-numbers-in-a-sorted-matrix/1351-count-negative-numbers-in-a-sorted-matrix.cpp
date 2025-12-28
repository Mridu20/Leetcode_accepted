class Solution {
public:
    int countNegatives(vector<vector<int>>& g) {
        int cnt =0;
        for(int i=0; i<g.size(); i++){
            int n = g[i].size();
            if(g[i][n-1] < 0){
                int left = 0;
                int right = n-1;
                int j= n;
                while(left <= right){
                    int mid = (left+right)/2;
                    if(g[i][mid] < 0){
                        right = mid-1;
                        j = mid;
                    }
                    else{
                        left = mid+1;
                    }
                }
                cnt += n-j; 
            }
        }
        return cnt;
    }
};