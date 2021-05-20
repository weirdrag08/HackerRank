#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
#include <stack>
#include <queue>
#include <climits>
#include <string>
#include <algorithm>
#include <utility>
using namespace std;

#define mp make_pair
#define INFI 10e8
#define INF 10e7

typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef long long ll;
typedef vector<vector<int>> vvi;
typedef vector<vector<bool>> vvb;

int dfs(int r, int c, int i, int j, vvi &matrix, vvb &visited)
{
    if (i >= r || i < 0 || j >= c || j < 0 || visited[i][j] == true || matrix[i][j] == 0)
    {
        return 0;
    }
    visited[i][j] = true;
    return 1 + dfs(r, c, i - 1, j, matrix, visited) + dfs(r, c, i - 1, j + 1, matrix, visited) + dfs(r, c, i, j + 1, matrix, visited) + dfs(r, c, i + 1, j + 1, matrix, visited) + dfs(r, c, i + 1, j, matrix, visited) + dfs(r, c, i + 1, j - 1, matrix, visited) + dfs(r, c, i, j - 1, matrix, visited) + dfs(r, c, i - 1, j - 1, matrix, visited);
}


int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int r, c;
    cin >> r >> c;
    vvi matrix(r, vi(c));
    vvb visited(r, vb(c, 0));

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> matrix[i][j];
        }
    }

    int max_size = 0;

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (matrix[i][j] == 1 && !visited[i][j])
            {
                max_size = max(max_size, dfs(r, c, i, j, matrix, visited));
            }
        }
    }
    cout << max_size << '\n';
}
