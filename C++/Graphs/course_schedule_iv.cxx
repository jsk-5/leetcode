//Implementation of the Floyd Warshall Algorithm
//Slightly tweaked to just display whether there is a path between nodes rather than
//distance
//https://leetcode.com/problems/course-schedule-iv/
class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<bool>> connected(numCourses, vector<bool>(numCourses,false));
        vector<bool> ans;

        for(auto&& pre : prerequisites){
            connected[pre[0]][pre[1]] = true;
        }
        for(int i = 0; i<numCourses; i++){
            for(int j = 0; j<numCourses; j++){
                for(int k = 0; k<numCourses; k++){
                    connected[j][k] = connected[j][k] || (connected[j][i] && connected[i][k]);
                }   
            }    
        }

        for(auto&& q : queries){
            ans.push_back(connected[q[0]][q[1]]);
        }

        return ans;
    }
};