#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
	int Answer, T, test_case, count, number;
	cin >> T;
	for(test_case = 0; test_case < T; test_case++)
	{
		Answer = 0;
		for(cin >> count; count > 0; --count)
		{
			cin >> number;
			Answer ^= number;
		}
		cout << "Case #" << test_case + 1 << endl;
		cout << Answer << endl;
	}
	return 0;
}
