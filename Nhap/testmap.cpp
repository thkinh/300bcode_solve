#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;

int Count(char target, string ch)
{
    int count = 0;
    for (int i = 0; i < ch.size(); i++)
    {
        if (ch[i] == target)
        {
            count ++;
        }
    }
    
    return count;
}

class Solution{
public:

    map<char, int> CountChar(string c)
    {      
        map <char , int> m;     
        for (int i = 0; i < c.size(); i++)
        {
            if (m.find(c[i]) == m.end())
            {
                m.insert({c[i], Count(c[i], c)});
            }
            
        }
        

        return m;

    }
};


int main()
{
    string name ;
    getline(cin,name);
    map <char,int> mp;
    Solution solv;
    mp = solv.CountChar(name);


    cout <<"Key\tCount\n";
    for(auto x:mp)
    {
        cout << x.first << "\t" << x.second <<endl;
    }

    return 0;
}