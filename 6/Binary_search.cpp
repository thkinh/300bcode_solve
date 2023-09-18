#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    int search(vector<int>& nums, int target) {
        int right = nums.size();
        cout << right<<"\n";
        int pivot = right/2;
        int left = 0;
        int repeat = 0;
        do
        {
            if (nums[pivot] == target)
            {
                return pivot;
            }
            else if (target < nums[pivot])
            {
                cout <<target <<"<"<<nums[pivot]<<"\n";
                system("pause>nul");
                right = pivot;
                repeat = pivot;
                pivot = (right+left)/2;
            }
            else if (target > nums[pivot]) 
            {
                cout <<target <<">"<<nums[pivot]<<"\n";
                system("pause>nul");
                left = pivot;
                repeat = pivot;
                pivot = (right+left)/2;
            }
        } while (left < right && repeat!=pivot);
        
        return -1;
    }
};

int main()
{
    Solution ret;
    vector <int> numbers = {1,2,3,4,5,6,7,8,9};
    int target = 0;
    cin >> target;
    int sol = ret.search(numbers,target);
    cout<<sol;
}