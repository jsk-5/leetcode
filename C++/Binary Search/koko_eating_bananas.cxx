//https://leetcode.com/problems/koko-eating-bananas/
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int n = piles.size();
        int high = *max_element(piles.begin(), piles.end());
        int low = 1;
        int middle = 0;
        int result = high;
        while(low<=high){
            int middle = (high-low) / 2 + low;
            long int hours = 0;
            
            for(int i = 0; i<n; i++){
                // cout << " " << ceil((double) piles[i]/middle);
                hours += ceil((double) piles[i]/middle);
            }
            // cout << "k: " << middle;
            // cout << " hours:" << hours << endl;

            if(hours>h){
                low = middle + 1;

            } else if (hours<=h) {
                high = middle -1;
                // Have to include this in the top decrease branch
                // because the last value to hit this will be the minmum k value
                // eg if k can be 4 5 6 but k_opt = 4
                // k = 6, decrement pointer
                // k = 5, decrement pointer
                // k = 4 and we no longer update it.
                result = middle;
            }
        }
        return result;
    }
};