#include <iostream>
#include <queue>
#define DIRECTION_COUNT 4
#define MAX_N 20
#define BLANK 0
#define SHARK 9
#define BASE_SHARK_SIZE 2
#define FOOD_KIND 6

using namespace std;

int get_can_eat_count(int *shark_size, int *food_count)
{
    int can_eat_count = 0;
    for(int i = 1; i < *shark_size; ++i)
    {
        can_eat_count += food_count[i];
    }
    return can_eat_count;
}

bool can_move(int map[][MAX_N], int N, int *shark_size, int next_row, int next_column, bool visit[][MAX_N])
{
    return next_row >= 0 && next_row < N && next_column >= 0 && next_column < N && !visit[next_row][next_column] && *shark_size >= map[next_row][next_column];
}

int next_move(int map[][MAX_N], int N, int *shark_size, int *eat_count, int *food_count, int *row, int *column)
{
    int move_count = 0, temp_row, temp_column, queue_size, next_candidate[MAX_N * MAX_N][2], candidate_index = 0;
    const int direction[DIRECTION_COUNT][2] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
    bool visit[MAX_N][MAX_N] = {0, }; 
    queue<int> positions;
    positions.push(*row * MAX_N + *column);
    visit[*row][*column] = true;
    while(!positions.empty())
    {
        queue_size = positions.size();
        for(int i = 0; i < queue_size; ++i)
        {
            int potision = positions.front(), next_row, next_column;
            positions.pop();
            temp_row = potision / MAX_N, temp_column = potision % MAX_N;
            for(int j = 0; j < DIRECTION_COUNT; ++j)
            {
                next_row = temp_row + direction[j][0];
                next_column = temp_column + direction[j][1];
                if(can_move(map, N, shark_size, next_row, next_column, visit))
                {
                    if(map[next_row][next_column] != BLANK && map[next_row][next_column] < *shark_size)
                    {
                        next_candidate[candidate_index][0] = next_row;
                        next_candidate[candidate_index++][1] = next_column;
                    }
                    if(map[next_row][next_column] == BLANK || map[next_row][next_column] == *shark_size)
                    {
                        positions.push(next_row * MAX_N + next_column);
                        visit[next_row][next_column] = true;
                    }
                }
            }
        }
        ++move_count;
        if(candidate_index > 0)
        {
            temp_row = next_candidate[0][0];
            temp_column = next_candidate[0][1];
            for(int i = 1; i < candidate_index; ++i)
            {
                if(temp_row > next_candidate[i][0])
                {
                    temp_row = next_candidate[i][0];
                    temp_column = next_candidate[i][1];
                }
                else if(temp_row == next_candidate[i][0] && temp_column > next_candidate[i][1])
                {
                    temp_column = next_candidate[i][1];
                }
            }
            ++(*eat_count);
            if(*eat_count == *shark_size)
            {
                ++(*shark_size);
                *eat_count = 0;
            }
            *row = temp_row;
            *column = temp_column;
            --food_count[map[*row][*column]];
            map[*row][*column] = BLANK;
            return move_count;
        }
    }
    return 0;
}

int main(int argc, char** argv)
{
    int N, answer = 0, map[MAX_N][MAX_N], shark_size = BASE_SHARK_SIZE, eat_count = 0;
    int food_count[FOOD_KIND + 1] = {0, }, row = -1, column = -1, move;
    cin >> N;
    for(int i = 0; i < N; ++i)
    {
        for(int j = 0; j < N; ++j)
        {
            cin >> map[i][j];
            if(map[i][j] > BLANK && map[i][j] <= FOOD_KIND)
            {
                ++food_count[map[i][j]];
            }
            if(map[i][j] == SHARK)
            {
                map[i][j] = BLANK;
                row = i;
                column = j;
            }
        }
    }
    while(get_can_eat_count(&shark_size, food_count) > 0 && (move = next_move(map, N, &shark_size, &eat_count, food_count, &row, &column)) > 0)
    {
        answer += move;
    }
    cout << answer << endl;
}