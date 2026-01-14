class Solution {
public:
    void nextPermutation(vector<int>& n) {
        for(int i=n.size()-1; i>=1; i--){
            if(n[i]>n[i-1]){
                sort(n.begin()+i, n.end());
                for(int j=i; j<n.size(); j++){
                    if(n[j]>n[i-1]){
                        swap(n[j], n[i-1]);
                        j = n.size() + 1;
                    }
                }
                return ;
            }
        }

        sort(n.begin(), n.end());
    }
};