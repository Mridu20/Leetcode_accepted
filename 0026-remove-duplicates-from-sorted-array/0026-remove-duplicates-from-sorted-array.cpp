class Solution {
public:
    int removeDuplicates(vector<int>& s) {
        vector<int> v;
        for(int i=0; i<s.size()-1; i++){
            if(s[i] != s[i+1]){
                v.push_back(s[i]);
            }
        }
        v.push_back(s[s.size()-1]);
        for(int i=0; i<s.size(); i++){
            s[i]=0;
            if(i<v.size()){
                s[i] = v[i];
            }
        }

        return v.size();
    }
};