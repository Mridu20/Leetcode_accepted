class Solution {
public:
    int maxFreqSum(string s) {
        map<char, int> freq;

        for(int i=0; i<s.size(); i++){
            freq[s[i]]++;
        } 

        int vow=0;
        int cont=0;
        vector<char> ch = {'a', 'e', 'i', 'o', 'u'};
        for(auto it: freq){
            if(find(ch.begin(), ch.end(), it.first) != ch.end()){
                vow = max(it.second, vow);
            }
            else{
                cont = max(cont, it.second);
            }
        }

        return vow+cont ;
    }
};