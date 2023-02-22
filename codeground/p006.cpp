#include <iostream>

using namespace std;

long long get_number(int N, int down, int right)
{
    long long number, diagonal = down + right;
    bool reverse = diagonal >= N || (diagonal == (N - 1) && (N % 2 == 0 ? down > right : down < right));
    if(reverse)
    {
        down = (N - 1) - down;
        right = (N - 1) - right;
        diagonal = down + right;
    }   
    number = (diagonal + 1) * diagonal / 2;
    number = diagonal % 2 == 0 ? number + (right + 1) : number + (down + 1);
    if(reverse)
    {
        number = N * N + 1 - number;
    }
    return number;
}

int main(int argc, char** argv)
{
    const string IDENTIFIER = "UDLR";
    const int D_DIRECTION[4] = {-1, 1, 0, 0}, R_DIRECTION[4] = {0, 0, -1, 1};
    int T, test_case, N, K, down, right, i, di;
    long long Answer;
    string moving;
    cin >> T;
    for(test_case = 0; test_case < T; test_case++)
    {
        Answer = 1;
        down = right = 0;
        cin >> N >> K >> moving;
        for(i = 0; i < K; ++i)
        {
            di = IDENTIFIER.find(moving.at(i));
            down += D_DIRECTION[di];
            right += R_DIRECTION[di];
            Answer += get_number(N, down, right);
        }
        cout << "Case #" << test_case + 1 << endl;
        cout << Answer << endl;
    }
    return 0;
}