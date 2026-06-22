class Solution {
public:
    int maxNumberOfBalloons(string s) {
        unordered_map<char, int> cnt;
        for(char c: s){
            if( c == 'b')cnt['b']++;
            else if(c == 'l')cnt['l']++;
            else if(c == 'o')cnt['o']++;
            else if(c == 'a')cnt['a']++;
            else if(c == 'n')cnt['n']++;
        }

        int ans = cnt['b'];
        ans= min(ans, cnt['o']/2);
        ans= min(ans, cnt['l']/2);
        ans= min(ans, cnt['n']);
        ans= min(ans, cnt['a']);

        return ans;
    }
};