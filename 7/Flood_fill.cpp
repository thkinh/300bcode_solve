#include <iostream>
#include <vector>

using namespace std;

void Print(vector<vector<int>> image)
{
    cout <<"====================\n";
    for (int i = 0; i < image.size(); i++)
    {
        for (int j = 0; j < image[i].size(); j++)
        {
            cout << image[i][j] <<" ";
        }
        cout << "\n";
    }
    cout <<"====================\n";
}

class Solution{
public:
    vector <vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color)
    {
        if (color == image[sr][sc])
        {
            return image;
        }
        
        int l = image.size();
        int h = image[0].size();
        int old_color = image[sr][sc];
        image[sr][sc] = color;
        // Print(image);
        // system("pause>nul");
        for (int i = sr - 1; i <= sr + 1; i++)
        {
            if (i < 0 || i > l-1)
            {
                continue;
            }
            if (image[i][sc] == old_color)
            {
                floodFill(image,i,sc,color);        
            }
            else
                continue;
        }
        for (int j = sc - 1; j <= sc + 1; j++)
        {
            if (j < 0 || j > h-1)
            {
                continue;
            }
            if (image[sr][j] == old_color)
            {
                floodFill(image,sr,j,color);     
            }
            else
                continue;
        }
        // cout << "done, removing from stack...\n";
        return image;
    }
};




int main()
{
    vector< vector<int>> image;
    vector< vector<int>> new_image;
    image = {{0,0,0},{0,0,0}};
    Print(image);
    
    Solution sol;
    new_image = sol.floodFill(image,0,0,0);
    cout << "\n\n image sau cung la\n";
    Print(new_image);
}