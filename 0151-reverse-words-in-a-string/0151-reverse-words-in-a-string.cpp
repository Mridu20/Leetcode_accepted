class Solution {
public:
    string reverseWords(string s){
        stack <string> p;

        string a;
        for(int i=0; i<s.size(); i++){
            if(s[i] != ' '){
                a.push_back(s[i]);
            }
            else{
                if(a.size()>0){
                    p.push(a);
                }
                a.clear();
            }
        }

        if(s[s.size()-1] != ' '){
            p.push(a);
        }

        string o;

        while (!p.empty()){
            o += p.top();
            p.pop();
            o += ' ';
        }

        o.erase(o.begin() + (o.size()-1));
        return o;
    }
};