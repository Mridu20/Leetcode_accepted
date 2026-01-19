class Solution {
public:
    vector<vector<int>> generate(int a) {
        vector<vector<int>> ans;

        vector<int> n;
        for(int i = 0; i<a; i++){
            vector<int> m(i+1);
            for(int j=0; j<=i; j++){
                if(j==0 || j==i)m[j]=1;
                else{
                    m[j] = n[j]+n[j-1];
                }
            }

            ans.push_back(m);
            n = m;
        }

        return ans;
    }
};