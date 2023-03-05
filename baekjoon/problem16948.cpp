#include <iostream>
#include <queue>
#define MAX_N 200
#define NEXT_MOVES(r, c) {{r - 2, c - 1}, {r - 2, c + 1}, {r, c - 2}, {r, c + 2}, {r + 2, c - 1}, {r + 2, c + 1}}

using namespace std;

int bfs(int n, int now_r, int now_c, int goal_r, int goal_c)
{
    int result = 0, position, size;
    bool check[MAX_N][MAX_N] = {false, };
    queue<int> bfs_positions;
    bfs_positions.push(now_r * MAX_N + now_c);
    check[now_r][now_c] = true;
    while(!bfs_positions.empty())
    {
        size = bfs_positions.size();
        while(size--)
        {
            position = bfs_positions.front();
            bfs_positions.pop();
            now_r = position / 200;
            now_c = position % 200;
            if(now_r == goal_r && now_c == goal_c)
            {
                return result;
            }
            int next_moves[6][2] = NEXT_MOVES(now_r, now_c);
            for(int i = 0; i < 6; ++i)
            {
                if(next_moves[i][0] >= 0 && next_moves[i][0] < n && next_moves[i][1] >= 0 && next_moves[i][1] < n && !check[next_moves[i][0]][next_moves[i][1]])
                {
                    bfs_positions.push(next_moves[i][0] * MAX_N + next_moves[i][1]);
                    check[next_moves[i][0]][next_moves[i][1]] = true;
                }
            }
        }
        ++result;
    }
    return -1;
}

int main(int argc, char** argv)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, r1, c1, r2, c2;
    cin >> N >> r1 >> c1 >> r2 >> c2;
    cout << bfs(N, r1, c1, r2, c2) << endl;
    return 0;
}