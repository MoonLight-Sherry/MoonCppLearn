#include <queue>
#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    int dir[5] = {-1, 0, 1, 0, -1};

    queue<pair<int, int>> rot(queue<pair<int, int>> &rottenB, int &fresh, vector<vector<int>> &grid)
    {
        queue<pair<int, int>> rottenA;
        while (!rottenB.empty())
        {
            pair<int, int> rot = rottenB.front();
            rottenB.pop();
            for (int i = 0; i < 4; ++i)
            {
                int m = rot.first + dir[i], n = rot.second + dir[i + 1];
                if (m >= 0 && m < grid.size() && n >= 0 && n < grid[0].size())
                {
                    if (grid[m][n] == 0 || grid[m][n] == -1 || grid[m][n] == 2)
                        continue;
                    else if (grid[m][n] == 1)
                    {
                        grid[m][n] = -1;
                        rottenA.push(make_pair(m, n));
                        --fresh;
                    }
                }
            }
        }
        return rottenA;
    }

    void ergodic(int &fresh, queue<pair<int, int>> &rotten, vector<vector<int>> &grid)
    {
        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid[i].size(); ++j)
            {
                if (grid[i][j] == 1)
                    ++fresh;
                else if (grid[i][j] == 2)
                {
                    rotten.push(make_pair(i, j));
                    grid[i][j] = -1;
                }
            }
        }
    }

    int orangesRotting(vector<vector<int>> &grid)
    {
        int fresh = 0;
        int cnt = 0;
        queue<pair<int, int>> rotten;
        ergodic(fresh, rotten, grid);
        if (!fresh) return 0;
        while (fresh)
        {
            int freshB = fresh;
            rotten = rot(rotten, freshB, grid);
            if (fresh == freshB) return -1;
            fresh = freshB;
            ++cnt;
        }
        return cnt;
    }

    int main()
    {
        vector<vector<int> > grid = {{2,1,1},{1,1,0},{0,1,1}};
        cout << orangesRotting(grid) << endl;
        return 0;
    }
};