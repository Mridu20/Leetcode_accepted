class Solution {
public:
    int minPartitions(string n) {
        int l= *max_element(n.begin(), n.end()); 
        return l- '0';
    }
};
