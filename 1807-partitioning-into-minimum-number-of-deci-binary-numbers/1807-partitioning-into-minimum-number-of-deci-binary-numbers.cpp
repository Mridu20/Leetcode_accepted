class Solution {
public:
    int minPartitions(string n) {
        vector<int> v;
        for (char c : n) {
            v.push_back(c - '0'); 
        }
        int l= *max_element(v.begin(), v.end()); 
        return l;
    }
};
