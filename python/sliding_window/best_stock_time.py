#https://leetcode.com/problems/best-time-to-buy-and-sell-stock/submissions/
#two pointer approach

class Solution:
    @staticmethod
    def maxProfit(prices: list[int]) -> int:
        
        left_ptr = 0
        right_ptr = -1
        result = 0
        for i in range(len(prices)):
            right_ptr += 1
            if(prices[right_ptr] < prices[left_ptr] ):
                left_ptr = right_ptr
            if(prices[right_ptr] - prices[left_ptr] > result):
                result = prices[right_ptr] - prices[left_ptr]
                    
        return result


print(Solution.maxProfit(prices=[7,1,5,3,6,4]))