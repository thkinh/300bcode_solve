#include <set>
#include <map>
#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    map<char, int> chars;
    map<char, int> chart;
    int count(char c)
    {
        if (chars.find(c) != chars.end())
        {
            return chars[c]++;
        }
        else
        {
            return 1;
        }
    }
    bool isAnagram(string s, string t)
    {
        
    }
};

int main()
{
    string s = "a";
    string t = "ab";
    Solution ret;
    cout<<ret.isAnagram(s,t);

}