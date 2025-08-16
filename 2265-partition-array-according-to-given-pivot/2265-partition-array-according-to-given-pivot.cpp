class Solution {
public:
    vector<int> pivotArray(vector<int>& a, int p) {

        vector<int> ans;
        for(int i=0; i<a.size(); i++){
            if(a[i]<p)ans.push_back(a[i]);
        }
        for(int i=0; i<a.size(); i++){
           if(a[i]==p)ans.push_back(a[i]);
        }
        for(int i=0; i<a.size(); i++){
            if(a[i]>p) ans.push_back(a[i]);
        }

        return ans;
    }
};