#include <bits/stdc++.h>
using namespace std;


class Solution {
private:
    vector<vector<int> > edges;
    vector<int> visited;
    vector<int> result;
    bool valid = true;
    
public:
    void dfs(int post){
        visited[post] = 1;
        for (int pre: edges[post]){
            if (visited[pre] == 0){
                dfs(pre);
                if (!valid){
                    return;
                }
            }
            else if (visited[pre] == 1){
                valid = false;
                return;
            }
        }
        visited[post] = 2;
        result.push_back(post);
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        edges.resize(numCourses);
        visited.resize(numCourses);
        for (const auto& info: prerequisites) {
            edges[info[1]].push_back(info[0]);
        }
        for (int i = 0; i < numCourses && valid; i++) {
            if (!visited[i]) {
                dfs(i);
            }
        }
        if (!valid){
            return {};
        }
        reverse(result.begin(), result.end());
        return result;
    }
};