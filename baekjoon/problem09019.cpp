#include <iostream>
#include <queue>
#define MAX_NUMBER 9999
#define MAX_OPTION 4
#define D(n) (n * 2 % (MAX_NUMBER + 1))
#define S(n) (n != 0 ? n - 1 : MAX_NUMBER)
#define L(n) (n * 10 % (MAX_NUMBER + 1) + n / 1000)
#define R(n) (n / 10 % 1000 + n % 10 * 1000)

using namespace std;

string bfs(int now_value, int goal_value)
{
    bool check[MAX_NUMBER + 1] = {false, };
    string record, options[MAX_OPTION] = {"D", "S", "L", "R"};
    queue<int> bfs_values;
    queue<string> bfs_records;
    bfs_values.push(now_value);
    bfs_records.push("");
    check[now_value] = true;
    while(!bfs_values.empty())
    {
        now_value = bfs_values.front();
        record = bfs_records.front();
        bfs_values.pop();
        bfs_records.pop();
        if(now_value == goal_value)
        {
            return record;
        }
        int next_values[MAX_OPTION] = {D(now_value), S(now_value), L(now_value), R(now_value)};
        for(int i = 0; i < MAX_OPTION; ++i)
        {
            if(!check[next_values[i]])
            {
                bfs_values.push(next_values[i]);
                bfs_records.push(record + options[i]);
                check[next_values[i]] = true;
            }
        }
    }
    return "";  // unreachable
}

int main(int argc, char** argv)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_count, A, B;
    cin >> test_count;
    while(test_count--)
    {   
        cin >> A >> B;
        cout << bfs(A, B) << endl;
    }
    return 0;
}