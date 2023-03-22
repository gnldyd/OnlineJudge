#include <iostream>
#include <cmath>
#include <string>
#define MAX_DIGIT 4
#define MAX_NUMBER (int)(pow(10, MAX_DIGIT) - 1)

using namespace std;

void calculate_possible(int *possible, string number, int strike, int ball)
{
    for(int j = 0; j <= MAX_NUMBER; ++j)
    {
        int temp_strike = 0, temp_ball = 0;
        string temp_number = to_string(j);
        while(temp_number.length() < MAX_DIGIT)
        {
            temp_number = '0' + temp_number;
        }
        for(int k = 0; k < MAX_DIGIT; ++k)
        {
            if(number.at(k) == temp_number.at(k))
            {
                ++temp_strike;
            }
        }
        for(int k = 0; k < MAX_DIGIT; ++k)
        {
            for(int l = 0; l < MAX_DIGIT; ++l)
            {
                if(k != l && number.at(k) == temp_number.at(l) && number.at(k) != temp_number.at(k) && number.at(l) != temp_number.at(l))
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

string calculate_result(int *possible, int guess_count)
{
    string answer;
    int max_possible_value = 0, max_possible_value_duplicate_count = 0;
    for(int i = 0; i <= MAX_NUMBER; ++i)
    {
        if(possible[i] > max_possible_value)
        {
            max_possible_value = possible[i];
            max_possible_value_duplicate_count = 1;
            answer = to_string(i);
        }
        else if(possible[i] == max_possible_value)
        {
            ++max_possible_value_duplicate_count;
        }
    }
    return max_possible_value < guess_count ? "impossible" : max_possible_value_duplicate_count > 1 ? "indeterminate" : answer;
}

int main(int argc, char** argv)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, G;
    cin >> N;
    while(N--)
    {
        cin >> G;
        int possible[MAX_NUMBER + 1] = {0, };
        string number, score;
        for(int i = 0; i < G; ++i)
        {
            cin >> number >> score;
            calculate_possible(possible, number, stoi(score.substr(0, score.find('/'))), stoi(score.substr(score.find('/') + 1)));
        }
        cout << calculate_result(possible, G) << endl;
    }
    return 0;
}