// https://leetcode.com/problems/time-based-key-value-store/

class TimeMap {
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        timemap[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        // Do not perfrom a vector assignment here because that is O(n)
        int high = timemap[key].size() - 1;
        int low = 0;
        int backup = 0;
        if(timemap.find(key) == timemap.end()) return "";

        while(low<=high){
            int mid = high - low / 2.0 + low;
            // cout << "L: " << low << " M: " << mid << " H: " << high << endl;
            if(timemap[key][mid].first == timestamp){
                return timemap[key][mid].second;
            } else if (timemap[key][mid].first < timestamp){
                //go right
                low = mid + 1;
            } else if(timemap[key][mid].first > timestamp){
                // go left
                high = mid - 1;
            }
        }
        if (high >= 0) {
            return timemap[key][high].second;
        }

        return "";

    }

private:
    unordered_map<string, vector<pair<int, string>>> timemap;
    
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */