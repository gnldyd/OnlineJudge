#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_SIDE = 100000, MAX_BLOCK_COUNT = 2000, PRIME = 1000000007;
int fac[2 * MAX_SIDE + 1], inv[2 * MAX_SIDE + 1];
long long fac_inv[2 * MAX_SIDE + 1];

struct Point
{
    int row, column;
}points[MAX_BLOCK_COUNT + 1];

bool point_compare(const Point& p1, const Point& p2)
{
    return p1.row < p2.row || (p1.row == p2.row && p1.column < p2.column);
}

void preprocessing()
{
    long long i;
    fac[0] = inv[0] = fac_inv[0] = fac[1] = inv[1] = fac_inv[1] = 1; 
    for(i = 2; i < 2 * MAX_SIDE + 1; ++i)
    {
        fac[i] = fac[i - 1] * i % PRIME;
        inv[i] = (-PRIME / i * inv[PRIME % i] % PRIME + PRIME) % PRIME;
        fac_inv[i] = fac_inv[i - 1] * inv[i] % PRIME;
    }
}

int main(int argc, char** argv)
{
    int T, test_case, N, M, K, row, column, valid_K, path_counts[MAX_BLOCK_COUNT + 1], path_count;
    long long i, j;
    preprocessing();
    cin >> T;
    for(test_case = 0; test_case < T; test_case++)
    {
        cin >> N >> M >> K;
        valid_K = 0;
        for(i = 0; i < K; ++i)
        {
            cin >> row >> column;
            if(0 < row && row <= N && 0 < column && column <= M)
            {
                points[valid_K].row = row;
                points[valid_K++].column = column;
            }
        }
        points[valid_K].row = N;
        points[valid_K++].column = M;
        sort(points, points + valid_K, point_compare);
        for(i = 0; i < valid_K; ++i)
        {
            path_count = fac[(points[i].row - 1) + (points[i].column - 1)] * fac_inv[points[i].row - 1] % PRIME * fac_inv[points[i].column - 1] % PRIME;
            for(j = 0; j < i; ++j)
            {
                if(points[i].row - points[j].row >= 0 && points[i].column - points[j].column >= 0)
                {
                    path_count -= path_counts[j] * (fac[(points[i].row - points[j].row) + (points[i].column - points[j].column)] * fac_inv[points[i].row - points[j].row] % PRIME * fac_inv[points[i].column - points[j].column] % PRIME) % PRIME;
                    path_count = (path_count + PRIME) % PRIME;
                }
            }
            path_counts[i] = path_count;
        }
        cout << "Case #" << test_case + 1 << endl;
        cout << path_counts[valid_K - 1] << endl;
    }
    return 0;
}