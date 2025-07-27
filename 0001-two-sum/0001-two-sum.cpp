class Solution {
public:
    vector<int> twoSum(vector<int>& n, int target) {
        vector<int> sol;

        for(int i=0; i<n.size(); i++){
            for(int j=i+1;j<n.size(); j++){
                if(n[i]+n[j] == target){
                    sol.push_back(i);
                    sol.push_back(j);
                    return sol;
                }
            }
        }

        return sol;
    }
};