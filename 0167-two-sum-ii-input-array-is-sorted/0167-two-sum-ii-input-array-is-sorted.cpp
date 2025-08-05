class Solution {
public:
    vector<int> twoSum(vector<int>& s, int t) {
        int i=0, j=s.size()-1;
        vector<int> v(2);

        while(i<j){
            if(s[i]+s[j] == t){
                v[0] = i+1;
                v[1] = j+1;
                return v;
            }
            else if(s[i]+s[j] > t){
                j--;
            }
            else{
                i++;
            }
        }
        return{};
    }
};