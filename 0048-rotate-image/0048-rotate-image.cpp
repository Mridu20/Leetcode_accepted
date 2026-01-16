class Solution {
public:
    void rotate(vector<vector<int>>& a) {
        for(int i=0; i<a.size(); i++){
            for(int j=i; j<a[i].size(); j++){
                if(i != j)
                swap(a[i][j], a[j][i]);
            }
        }

        for(int i=0; i<a.size(); i++){
            for(int j=0; j<a[i].size()/2; j++){
                swap(a[i][j], a[i][a.size()-1-j]);
            }
        }
    }
};