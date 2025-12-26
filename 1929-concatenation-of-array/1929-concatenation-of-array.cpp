class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int>n(2*nums.size());
        for(int i=0; i<nums.size(); i++){
            n[i]=nums[i];
            n[i+nums.size()]=nums[i];
        }

        return n;
    }
};