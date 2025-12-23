class Solution {
public:
    int countConsistentStrings(string a, vector<string>& w) {
        int aa = strmsk(a);
        int cnt=0;
        for(string s: w){
            int o = strmsk(s);

            if((o & aa) == o) cnt++;
        }

        return cnt;
    }

    int strmsk(string s){
        int msk=0;
        for(char c: s){
            msk |= (1<<(c-'a'));
        }

        return msk;
    }
};