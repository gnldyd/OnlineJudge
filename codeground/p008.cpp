#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
    const int MAX_COUNT = 100000;
    int Answer, T, test_case, N, blocks[MAX_COUNT + 2], i;
    cin >> T;
    for(test_case = 0; test_case < T; test_case++)
    {
        Answer = 0;
        cin >> N;
        for(i = 1; i <= N; ++i)
        {
            cin >> blocks[i];
        }
        blocks[0] = blocks[N + 1] = 0;
        for(i = 1; i <= N; ++i)
        {
            blocks[i] = min(blocks[i], blocks[i - 1] + 1);
        }
        for(i = N; i >= 1; --i)
        {
            blocks[i] = min(blocks[i], blocks[i + 1] + 1);
            if(Answer < blocks[i])
            {
                Answer = blocks[i];
            }
        }
        cout << "Case #" << test_case + 1 << endl;
        cout << Answer << endl;
    }
    return 0;
}