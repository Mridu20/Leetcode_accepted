class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& a, vector<int>& b) {
        vector<int> c;
        map<int, int> ab;

        for(int i=0; i<a.size(); i++){
            ab[a[i]]++;
            ab[b[i]]++;
            int cnt =0;

            for(auto k: ab){
                if(k.second == 2)cnt++;
            }

            c.push_back(cnt);
        }

        return c;
    }
};