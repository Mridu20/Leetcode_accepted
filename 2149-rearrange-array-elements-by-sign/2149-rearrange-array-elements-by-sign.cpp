class Solution {
public:
    vector<int> rearrangeArray(vector<int>& n) {
        vector<int> ans(n);
        int pos=0;
        int neg = 1;

        for(int i=0; i<n.size(); i++){
            if(n[i]<0){
                ans[neg] = n[i];
                neg += 2;
            }
            else{
                ans[pos]=n[i];
                pos += 2;
            }
        }

        return ans;
    }
};