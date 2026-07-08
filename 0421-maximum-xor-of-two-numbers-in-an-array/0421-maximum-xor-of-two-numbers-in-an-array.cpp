struct node{
    node* links[2];

    bool containskey(int bit){
        return (links[bit] != NULL);
    }
    node* get(int bit){
        return links[bit];
    }
    void put(int bit, node* temp){
        links[bit] = temp;
    }
};

class trie{
    node* root;
public:
    trie(){
        root = new node();
    }

    void insert(int num){
        node* temp = root;

        for(int i=31; i>=0; i--){
            int bit = (num >> i) & 1;

            if(!temp->containskey(bit)){
                temp->put(bit, new node());
            }
            temp = temp->get(bit);
        }
    }

    int getmax(int num){
        node* temp = root;
        int mx=0;
        for(int i=31; i>=0; i--){
            int bit = (num >> i) & 1;
            if(temp->containskey(1 - bit)){
                mx = mx | (1<<i);
                temp = temp->get(1-bit);
            }
            else{
                temp = temp->get(bit);
            }
        }

        return mx;
    }
    
};

class Solution {
public:
    int findMaximumXOR(vector<int>& a) {
        trie tr;
        for(auto it: a) tr.insert(it);

        int ans = 0;
        for(auto it: a){
            int b = tr.getmax(it);
            ans = max(ans, b);
        }

        return ans;
    }
};