#https://leetcode.com/problems/last-stone-weight/submissions/1178177540/
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        std::priority_queue stone_heap(stones.begin(), stones.end());
        while(stone_heap.size() > 1){
            int stone1 = stone_heap.top();
            stone_heap.pop();
            int stone2 = stone_heap.top();
            stone_heap.pop();
            if(stone1 > stone2){
                stone_heap.push(stone1 - stone2);
            }


        }
        if(stone_heap.size() == 0) return 0;
        return stone_heap.top();
    }
};