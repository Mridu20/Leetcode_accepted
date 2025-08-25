class Solution {
public:
    string defangIPaddr(string a) {
        string s;
        for(int i=0; i<a.size(); i++){
            if(a[i] == '.'){
                s += "[.]";
            }
            else s += a[i];
        }
        return s;
    }
};