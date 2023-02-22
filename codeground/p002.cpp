#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, char** argv)
{
    const int MAX_COUNT = 300000;
    int Answer, T, test_case, N, scores[MAX_COUNT], max_score, win_min_score = 0;
    cin >> T;
    for(test_case = 0; test_case < T; test_case++)
    {
        Answer = 0;
        cin >> N;
        for(int i = 0; i < N; ++i)
        {
            cin >> scores[i];
        }
        sort(scores, scores + N, greater<int>());
        for(int i = 0; i < N; ++i)
        {
            max_score = scores[i] + (i + 1);
            if(win_min_score < max_score)
            {
                win_min_score = max_score;
            }
        }
        for(int i = 0; i < N; ++i)
        {
            if(scores[i] + N >= win_min_score)
            {
                ++Answer;
            }
        }
        cout << "Case #" << test_case + 1 << endl;
        cout << Answer << endl;
    }
    return 0;
}
