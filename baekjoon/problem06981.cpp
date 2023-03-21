#include <iostream>
#define MAX_DIGIT 4
#define MAX_NUMBER 9999

using namespace std;

int main(int argc, char** argv)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, G, number, strike, ball, max_value, max_count;
    int bases[MAX_DIGIT] = {1000, 100, 10, 1}, number_digit[MAX_DIGIT];
    string score, Answer;
    cin >> N;
    while(N--)
    {
        cin >> G;
        int possible[MAX_NUMBER + 1] = {0, };
        for(int i = 0; i < G; ++i)
        {
            cin >> number >> score;
            for(int j = 0; j < MAX_DIGIT; ++j)
            {
                number_digit[j] = number / bases[j] % 10;
            }
            strike = score.at(0) - '0';
            ball = score.at(2) - '0';
            for(int j = 0; j <= MAX_NUMBER; ++j)
            {
                int temp_strike = 0, temp_ball = 0, j_digit[MAX_DIGIT];
                for(int k = 0; k < MAX_DIGIT; ++k)
                {
                    j_digit[k] = j / bases[k] % 10;
                }

                // check strike
                for(int k = 0; k < MAX_DIGIT; ++k)
                {
                    if(number_digit[k] == j_digit[k])
                    {
                        ++temp_strike;
                    }
                }

                // check_ball
                for(int k = 0; k < MAX_DIGIT; ++k)
                {
                    for(int l = 0; l < MAX_DIGIT; ++l)
                    {
                        if(k != l && number_digit[k] == j_digit[l] && number_digit[k] != j_digit[k] && number_digit[l] != j_digit[l])
                        {
                            ++temp_ball;
                            break;
                        }
                    }
                }
                
                if(strike == temp_strike && ball == temp_ball)
                {
                    ++possible[j];
                }
            }
        }

        // calculate
        max_value = max_count = 0;
        for(int i = 0; i <= MAX_NUMBER; ++i)
        {
            if(possible[i] > max_value)
            {
                max_value = possible[i];
                max_count = 1;
                Answer = to_string(i);
            }
            else if(possible[i] == max_value)
            {
                ++max_count;
            }
        }
        cout << (max_value < G ? "impossible" : max_count > 1 ? "indeterminate" : Answer) << endl;
    }
    return 0;
}