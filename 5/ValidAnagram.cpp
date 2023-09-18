#include <set>
#include <map>
#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    map<char, int> chars;
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
        for (int i = 0; i < s.length(); i++)
        {
            chars.insert({s[i], count(s[i])});
        }
        for (int i = 0; i < t.length(); i++)
        {
            if (!chars.count(t[i]))
            {
                return false;
            }
            else if (chars.count(t[i]))
            {
                chars[t[i]]--;
            }
        }
        for (auto x:chars)
        {
            if (x.second != 0)
            {
                return false;
            }
        }        
        return true;
    }
};

int main()
{
    string s = "a";
    string t = "a";
    Solution ret;
    cout<<ret.isAnagram(s,t);

}