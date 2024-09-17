// https://leetcode.com/problems/daily-temperatures/
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        //temp , index
        stack<pair<int,int>> mds;
        

        vector<int> results(temperatures.size());
        for(int i = 0; i<temperatures.size(); i++){
            
            while(!mds.empty() && mds.top().first < temperatures[i]){  
                int prevDay = mds.top().second;
                int prevTemp = mds.top().first;
                results[prevDay] = i - prevDay; 
                mds.pop();
            }
            pair nextElem(temperatures[i], i);
            mds.push(nextElem);
        }

        return results;
    }
};