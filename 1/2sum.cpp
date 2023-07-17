#include <vector>
#include <set>
#include <map>
#include <iostream>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        map <int, int> m;
        int n = nums.size();
        for(int i = 0; i < n; i++)
        {
            m.insert({nums[i],i});
        }
        for (int i = 0; i < n; i++) {
            int temp = target - nums[i];
            if (m.find(temp) != m.end() && m[temp] != i) {
                return {i, m[temp]};
            }
        }

        return {};
    }
};

int main()
{

}