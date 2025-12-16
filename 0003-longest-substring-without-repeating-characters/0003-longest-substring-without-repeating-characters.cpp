class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        string ans;
        int l = 0;
        int st = 0;

        for(int i=0; i<s.size(); i++){
            if(ans.size() == 0){
                ans += s[i];
                l++;
                st = i;
            } 
            else{
                int pos = ans.find(s[i]);
                if(pos != string::npos){
                    l = max(l, (int)ans.size());
                    ans.erase(0, pos-st+1);
                    ans += s[i];
                }
                else{
                    ans += s[i];
                } 
            }
        }

        l = max(l, (int)ans.size());

        return l;
    }
};