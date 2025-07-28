class Solution {
public:
    vector<string> summaryRanges(vector<int>& n) {
        vector<string> t;
        int i=0;
        while(i<n.size()){
            string s;
            int a = n[i];
                int b = i;
            s += to_string(a);
            while((i<n.size()-1) && n[i]+1 == n[i+1]){
                i++;
            }

            if(i != b){
                s += "->";
                s += to_string(n[i]);
            }
            i++;
            t.push_back(s);
        }

        return t ;
    }
};