class Solution {
public:
    int singleNumber(vector<int>& n) {
        map<int, int> mp;

        for(int i=0; i<n.size(); i++){
            mp[n[i]]++;
        }

        for(auto it:mp){
            if(it.second == 1){
                return it.first;
            }
        }

        return 0;
    }
};