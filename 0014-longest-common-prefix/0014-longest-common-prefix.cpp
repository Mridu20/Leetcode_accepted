class Solution {
public:
    string longestCommonPrefix(vector<string>& s) {
        string cp;
        cp = s[0];
        for(int i=0; i<s.size(); i++){
            string m = s[i];
            if(cp.size()>m.size()){
                cp[m.size()]='.';
            }
            for(int j=0; j<m.size() && j<cp.size(); j++){
                if(cp[j] != m[j]){
                    cp[j] = '.';
                    break;
                }
            }
            continue;
        }

        string k;
        int i =0;
        while(cp[i] != '.' && i<cp.size()){
            k.push_back(cp[i]);
            i++;
        }

        return k;
    }
};