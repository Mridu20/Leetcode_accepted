class Solution {
public:
    vector<string> readBinaryWatch(int t) {
        vector<string> ans;
        
        for(int i = 0; i < 12; i++) {
            for(int j = 0; j < 60; j++) {
                
                int c = __builtin_popcount(i) + __builtin_popcount(j);
                
                if(c == t) {
                    string s = "";
                    
                    s += to_string(i);
                    s += ":";
                    
                    if(j < 10)
                        s += "0";
                    
                    s += to_string(j);
                    
                    ans.push_back(s);
                }
            }
        }
        
        return ans;
    }
};
