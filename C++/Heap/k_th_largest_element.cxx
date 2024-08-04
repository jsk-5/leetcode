#https://leetcode.com/problems/kth-largest-element-in-a-stream/
class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;

        for(int n : nums){
            minHeap.push(n);
        }
        while(minHeap.size()>k){
            minHeap.pop();
        }
    }
    
    int add(int val) {
        minHeap.push(val);
        while(minHeap.size()>k){
            minHeap.pop();
        }
        return minHeap.top();
    }

private:
    int k;
    priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */