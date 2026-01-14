class Solution {
public:
    vector<int> rearrangeArray(vector<int>& n) {
        vector<int> neg, pos;

        for(int i=0; i<n.size(); i++){
            if(n[i] < 0)neg.push_back(n[i]);
            else pos.push_back(n[i]);
        }

        vector<int> ans;
        for(int i=0; i<n.size()/2; i++){
            ans.push_back(pos[i]);
            ans.push_back(neg[i]);
            
        }

        return ans;
    }
};