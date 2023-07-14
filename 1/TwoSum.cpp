#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        vector <int> sol;
        set <int> a; 
        for(int i = 0; i< nums.size(); i++)
        {
            for(int j = 0; j< nums.size() && j != i; j++ )
            {
                if(nums[i] + nums[j] == target)
                {
                    cout << nums[i] << " + " <<nums[j] <<" = target"<<endl;
                    a.insert(i);
                    a.insert(j);
                }
            }
        }

        cout << "Size cua set a la: "<<a.size()<<endl;
        for (auto& x:a)
        {
            sol.push_back(x);
        }

        for (int i = 0; i < sol.size(); i++)
        {
            cout << sol[i] <<endl;
        }


        return sol;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {2,4,3};
    int target = 6;
    s.twoSum(nums,target);
}