#include <iostream>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    unordered_map<int, vector<int>> graph;
    vector<int> visited;
    bool f = true;

    bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
        visited = vector(numCourses, 0);
        for (auto &prerequisite: prerequisites) {
            int u = prerequisite[0], v = prerequisite[1];
            graph[u].push_back(v);
        }
        for (int u = 0; u < numCourses; ++u) {
            if (visited[u] != 1) {
                dfs(u);
            }
        }
        return f;
    }

    void dfs(int u) {
        if (visited[u] == 1) return;
        visited[u] = 2;
        for (auto &v: graph[u]) {
            if (visited[v] == 2) {
                f = false;
                return;
            }
            dfs(v);
        }
        visited[u] = 1;
    }
};

class Solution2 {
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
        vector inDegrees(numCourses, 0);
        vector<vector<int>> graph(numCourses);
        for (auto &uv: prerequisites) {
            inDegrees[uv[0]]++;
            graph[uv[1]].push_back(uv[0]);
        }

        queue<int> q;
        int count = 0;
        for (int i = 0; i < numCourses; ++i) {
            if (inDegrees[i] == 0) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            count++;
            int u = q.front();
            q.pop();
            for (auto &v: graph[u]) {
                inDegrees[v]--;
                if (inDegrees[v] == 0) {
                    q.push(v);
                }
            }
        }
        return count == numCourses;
    }
};

int main() {
    return 0;
}
