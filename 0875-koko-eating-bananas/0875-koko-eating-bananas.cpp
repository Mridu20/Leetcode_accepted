class Solution {
public:
    int minEatingSpeed(vector<int>& a, int h) {
        int right= *max_element(a.begin(), a.end());
        int left= 1;

        while(left<right){
            int mid = left+(right-left)/2;

            int hr=0;
            for(int x:a){
                if(x<=mid)hr+=1;
                else if(x%mid == 0)hr += x/mid;
                else hr +=( x/mid + 1);
            }

            if(hr <= h)right = mid;
            else left = mid+1;
        }

        return left;
    }
};