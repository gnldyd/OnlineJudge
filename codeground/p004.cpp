#include <iostream>
#include <cmath>

using namespace std;

int getScore(int x, int y, int A, int B, int C, int D, int E)
{
    const int SCORES_COUNT = 20;
    const int SCORES[SCORES_COUNT] = {6, 13, 4, 18, 1, 20, 5, 12, 9, 14, 11, 8, 16, 7, 19, 3, 17, 2, 15, 10};
    double angle = atan2(y, x) * (180 / M_PI) + (360 / SCORES_COUNT / 2);
    int index = (int)((angle < 0 ? angle + 360 : angle) / (360 / SCORES_COUNT));
    double distance = sqrt(x * x + y * y);
    int score = 0;
    if(distance <= A)
    {
        score = 50;
    }
    else if(distance >= B && distance <= C)
    {
        score = 3 * SCORES[index];
    }
    else if(distance >= D && distance <= E)
    {
        score = 2 * SCORES[index];
    }
    else if(distance > E)
    {
        score = 0;
    }
    else
    {
        score = SCORES[index];
    }
    return score;
}

int main(int argc, char** argv)
{
    int Answer, T, test_case, N, A, B, C, D, E, x, y;
    cin >> T;
    for(test_case = 0; test_case < T; test_case++)
    {
        Answer = 0;
        cin >> A >> B >> C >> D >> E >> N;
        for(int i = 0; i < N; ++i)
        {
            cin >> x >> y;
            Answer += getScore(x, y, A, B, C, D, E);
        }
        cout << "Case #" << test_case + 1 << endl;
        cout << Answer << endl;
    }
    return 0;
}
