class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& n, int k) {
        int mxd = 100000;
        bool h;
        set<int> a;
       for(int i=0; i<n.size(); i++){
        a.insert(n[i]);
       }

       if(a.size() == n.size()){
        return false;
       }
       else{
        for (int i = 0; i < n.size(); i++) {
            for (int j = i+1; j < (i+k+1) && j<n.size(); j++) {
                if(n[i] == n[j]){
                    mxd = min(mxd, abs(i - j));
                    if(mxd <= k)return true;
                }  
            }
        }

        if(mxd <= k) {h = true;}
        else{ h = false;}
       }

        return h;
    }
};