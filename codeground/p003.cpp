#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, char** argv)
{
    const int MAX_COUNT = 200000;
    int Answer, T, test_case, N, K, scores[MAX_COUNT];
    cin >> T;
    for(test_case = 0; test_case < T; test_case++)
    {
        Answer = 0;
        cin >> N >> K;
        for(int i = 0; i < N; ++i)
        {
            cin >> scores[i];
        }
        sort(scores, scores + N, greater<int>());
        for(int i = 0; i < K; ++i)
        {
            Answer += scores[i];
        }
        cout << "Case #" << test_case + 1 << endl;
        cout << Answer << endl;
    }
    return 0;
}
