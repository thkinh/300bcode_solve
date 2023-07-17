#include <set>
#include <map>
#include <stack>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution{
public:
    map <char,char> pa = {{'[',']'}, {'(',')'}, {'{','}'}};
    bool isValid(string s)
    {
        int count = s.length();
        bool isClosed = 0;
        stack <char> check;
        if (count == 1)
        {
            cout << "\nChuoi chi co 1 ki tu\n";
            return false;
        }
        for (int i = 0; i < count; i++)
        {
            if (pa.find(s[i]) != pa.end())
            {
                check.push(s[i]);
                continue;
            }
            else if (check.empty())
            {
                return false;
            }
            else if (pa[check.top()] == s[i] && !check.empty())
            {
                isClosed = 1;
                check.pop();
                continue;
            }
            cout <<endl << pa[check.top()] <<" khac "<<s[i]<<endl;
            return false;
        }
        if (check.empty() && isClosed == 1)
        {
            return true;
        }
        return false;
    }
};

int main()
{
    Solution sol;
    string s;
    getline(cin,s);
    cout <<"\n"<<sol.isValid(s);

    return 0;
}