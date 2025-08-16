class Solution {
public:
    vector<int> minOperations(string s) {
        vector<int> a;
        for(int i=0; i<s.size(); i++){
            if(s[i] == '1')a.push_back(i);
        }

        vector<int> ans;

        for(int i=0; i<s.size(); i++){
            int sum=0;
            for(int j=0; j<a.size(); j++){
                sum += abs(i-a[j]);
            }

            ans.push_back(sum);
        }

        return ans;
    }
};