#include <stack>
#include <set>
#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    set <char> open = {'{','[','('};
    set <char> close = {'}',']',')'};
    stack <char> check;
    bool isValid(string s)
    {
        if (s.length() != 1)
        {
            bool isClosed;
            for (int i = 0; i < s.length(); i++)
            {
                if (open.find(s[i]) != open.end())
                {
                    isClosed = 0;
                    check.push(s[i]);
                    continue;
                }
                else if (check.empty())
                {
                    return false;
                }
                
                else if (close.find(s[i]) != close.end() && !check.empty())
                {
                    isClosed = 1;
                    if (s[i] == '}' && check.top() != '{')
                    {
                        // cout << "Chuoi nay co dong la } nhung mo ko phai { \n";
                        return false;
                    }
                    else if (s[i] == ')' && check.top() != '(')
                    {
                        // cout << "Chuoi nay co dong la ) nhung mo ko phai ( \n";
                        return false;
                    }
                    else if (s[i] == ']' && check.top() != '[')
                    {
                        // cout << "Chuoi nay co dong la ] nhung mo ko phai [ \n";
                        return false;
                    }
                    else
                    {
                        // cout << "chuoi dang co dong la "<<s[i]<<" mo la "<<check.top() <<endl;
                        check.pop();
                        continue;
                    }
                }
            }
            if (isClosed == 1 && check.empty())
            {
                return true;
            }
            
        }
        return false;
    }
};


int main()
{
    Solution sol;
    string s;
    getline(cin,s);
    if (sol.isValid(s))
    {
        cout <<"\nTRUE";
    }
    else
    cout <<"\nFALSE";
    
}