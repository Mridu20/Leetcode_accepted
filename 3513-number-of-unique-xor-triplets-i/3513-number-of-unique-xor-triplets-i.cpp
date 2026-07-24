class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n=nums.size();
        if(n<=2){
            return n;
        }
        if((n&(n-1))==0){
            return n<<1;
        }
        else{
            while((n&(n-1))!=0){
                n++;
            }
        }
        return n;
    }
};