#https://leetcode.com/problems/maximum-number-of-coins-you-can-get/description/
class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int number_of_piles = piles.size() / 3;

        int res = 0;
        int element = piles.size() - 2;
        std::sort(piles.begin(),piles.end());
        for(int i = 0; i<number_of_piles; i++){
            res += piles[element];
            element -= 2;
        }
        return res;
    }
};