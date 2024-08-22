//https://leetcode.com/problems/container-with-most-water/submissions/
class Solution {
public:
    // Water stored = (pos(i) - pos(n)) * min(i,n)
    // Find the two largest numbers with maximum distance between them
    int maxArea(vector<int>& height) {
        vector<int>::iterator begin = height.begin();
        vector<int>::iterator end = height.end();
        end--;
        int maxWater = 0;

        while(distance(begin,end) > 0){
            int water = distance(begin,end) * min(*begin,*end);
            if(water > maxWater) maxWater = water;
            if(*begin < *end){
                begin++;
            } else if (*end < *begin){
                end--;
            } else {
                begin++;
            }
            
        }
        return maxWater;
        
    }
};