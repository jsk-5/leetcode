class Solution {
public:
    // The water stored at position i is given by: min(max height to left of i, max height to right of i) - height at i
    // First solution: o(n) time, o(n) memory
    // Calculate an array holding max height left, not including i!
    // Calculate an array holding max height right, not including i!
    // The first entry of either array is 0 because the elevation map is not bounded.
    // Make an array holding min(l,r)

    // Second solution: o(n) time, o(1) memory. Two pointers.

    // int trap(vector<int>& height) {
    //     vector<int> minH;
    //     vector<int>::iterator l = height.begin();
    //     int maxL = 0;
    //     while(l < height.end()){
    //         minH.push_back(maxL);
    //         if(*l > maxL){
    //             maxL = *l;
                
    //         }
            
    //         l++;
    //     }
    //     // for (auto& elem: minH) {
    //     //     cout << elem << " ";
    //     // }
    //     // cout << endl;
    //     vector<int>::iterator r = height.end();
    //     r--;
    //     int maxR = 0;
    //     int i = height.size()-1;
    //     while(r >= height.begin()){
    //         if(maxR < minH[i]) minH[i] = maxR;
    //         if(*r > maxR){
    //             maxR = *r; 
    //         }
    //         // cout << maxR << " ";
    //         r--;
    //         i--;
    //     }
    //     // cout << endl;
    //     int water = 0;
    //     vector<int>::iterator pos = height.begin();
    //     while(pos < height.end()){
    //         auto i = std::distance(height.begin(), pos); 
    //         if(minH[i] - *pos > 0){
    //             water += minH[i] - *pos;
    //         }
    //         pos++;
    //     }

    //     // for (auto& elem: minH) {
    //     //     // if the current index is needed:
    //     //     cout << elem << " ";

    //     //     // any code including continue, break, return
    //     // }
    //     return water;
    // }

    // water[i] = min(maxL, maxR) - height[i]
    // because we're incrementing the smallest max pointer we know its min(maxL,maxR)
    int trap(vector<int>& height) {
        vector<int>::iterator left = height.begin();
        vector<int>:: iterator right = height.end()-1;
        int maxL = *left;
        int maxR = *right;
        int water = 0;

        while(distance(left,right)>0){
            if(maxL < maxR){
                left++;
                if(maxL - *left > 0) water += maxL - *left;
                if(*left > maxL) maxL = *left;
            } else {
                right--;
                if(maxR - *right > 0) water += maxR - *right;
                if(*right > maxR) maxR = *right;
            }
        }

        return water;
    }
};