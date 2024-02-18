#https://leetcode.com/problems/k-closest-points-to-origin/
class Solution {
public:

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto customGreater = [](const vector<int> l, const vector<int> r) { return (pow(l[0],2) + pow(l[1],2)) < (pow(r[0],2) + pow(r[1],2)); };
        std::make_heap(points.begin(),points.end(), customGreater);

        while(points.size() > k){
            std::pop_heap(points.begin(),points.end(), customGreater);
            points.pop_back();
        }

        return points;
    }
};