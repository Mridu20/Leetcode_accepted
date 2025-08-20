class Solution {
public:
    int minMovesToSeat(vector<int>& s, vector<int>& t) {
        sort(s.begin() ,s.end());
        sort(t.begin() ,t.end());
        int sum =0;

        for(int i=0; i<s.size(); i++){
            sum += abs(s[i]-t[i]);
        }

        return sum;
    }
};