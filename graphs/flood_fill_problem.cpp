/*
Flood Fill Problem
N = No of rows
M = No of columns
Time complexity:O(N*M)
Space complexity:O(N*M)
 */
#include <bits/stdc++.h>
using namespace std;
void dfs(vector<vector<int>> &image, int i, int j, int newColor, int orgColor)
{
    if (i < 0 || j < 0 || i >= image.size() || j >= image[0].size() || image[i][j] == newColor || image[i][j] != orgColor)
    {
        return;
    }
    image[i][j] = newColor;
    dfs(image, i - 1, j, newColor, orgColor);
    dfs(image, i, j + 1, newColor, orgColor);
    dfs(image, i, j - 1, newColor, orgColor);
    dfs(image, i + 1, j, newColor, orgColor);
}
vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
{
    dfs(image, sr, sc, color, image[sr][sc]);
    return image;
}
int main()
{
    vector<vector<int>> image = 
    {
        {1, 1, 1},
        {1, 1, 0},
        {1, 0, 1}
    };
    int sr = 1, sc = 1, newColor = 2;
    cout << "Original Image:" << endl;
    for (const auto &row : image)
    {
        for (int pixel : row)
        {
            cout << pixel << " ";
        }
        cout << endl;
    }
    vector<vector<int>> result = floodFill(image, sr, sc, newColor);
    cout << "\nImage after Flood Fill:" << endl;
    for (const auto &row : result)
    {
        for (int pixel : row)
        {
            cout << pixel << " ";
        }
        cout << endl;
    }
    return 0;
}