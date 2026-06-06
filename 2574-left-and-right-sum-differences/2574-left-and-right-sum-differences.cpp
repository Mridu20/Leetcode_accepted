class Solution {
public:
    vector<int> leftRightDifference(vector<int>& n) {
        vector<int> ans;
        int sum=0;
        for(int i=0; i<n.size(); i++){
            sum += n[i];
        }

        int lft=0, rgt=0;
        for(int i=0; i<n.size(); i++){
            lft += n[i];
            rgt = sum-lft+n[i];

            int d = abs(lft - rgt);
            ans.push_back(d);
        }

        return ans;
        
    }
};