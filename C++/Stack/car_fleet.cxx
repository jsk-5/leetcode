// https://leetcode.com/problems/car-fleet/
// MDS = NEXT GREATER ELEMENT 
// MIS = NEXT LESSER ELEMENT
// https://leetcode.com/discuss/study-guide/2347639/A-comprehensive-guide-and-template-for-monotonic-stack-based-problems
class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,double>> cars;

        for(int i = 0; i < position.size(); i++){
            double time = (target-position[i])/ (double) speed[i];
            
            cars.push_back({position[i], time});
        }

        sort(cars.begin(), cars.end(), std::less<>());
        
        stack<pair<int,double>> st;

        for(int i = 0; i < cars.size(); i++){
            while(!st.empty() && st.top().second <= cars[i].second){
                st.pop();
            }
            // cout << cars[i].first << " " << cars[i].second << endl;
            st.push(cars[i]);
        }

        return st.size();
        
    }
};