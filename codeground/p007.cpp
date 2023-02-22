#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
    const int MAX_VALUE_COUNT = 5000, MAX_VALUE = 100000, SUM_COUNT = 3;
    int Answer, T, test_case, N, values[MAX_VALUE_COUNT], i, j;
    bool *dp;
    cin >> T;
    for(test_case = 0; test_case < T; test_case++)
    {
        Answer = 0;
        cin >> N;
        dp = new bool[4 * MAX_VALUE + 1]();
        for(i = 0; i < N; ++i)
        {
            cin >> values[i];
            for(j = 0; j < i; ++j)
            {
                if(dp[values[i] - values[j] + 2 * MAX_VALUE])
                {
                    ++Answer;
                    break;
                }
            }
            for(j = 0; j <= i; ++j)
            {
                dp[values[i] + values[j] + 2 * MAX_VALUE] = true;
            }
        }
        delete(dp);
        cout << "Case #" << test_case + 1 << endl;
        cout << Answer << endl;
    }
    return 0;
}