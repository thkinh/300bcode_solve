#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxSubArray(vector <int> nums)
    {
        int len = nums.size();
        int current_sum = 0;
        int max_sum = nums[0] ;
        for (int i = 0; i < len ; i++)
        {
            if (current_sum + nums[i] < 0)
            {
                if (nums[i] > max_sum)
                {
                    max_sum = nums[i];
                }
                current_sum = 0;
                continue;
            }
            else if (current_sum + nums[i] >= 0)
            {
                current_sum += nums[i];
                if (current_sum > max_sum)
                {
                    max_sum = current_sum;
                }
            }
            
        }
        
        
        return max_sum;
    }
};

int main()
{
    vector <int> nums = {17,-38,30,22,19,-100,-11,30,11,129};
    Solution sol;
    int sum = sol.maxSubArray(nums);
    cout << sum;
    return 0;
}