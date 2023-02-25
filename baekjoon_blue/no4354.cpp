#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
	while (true) {
		string input;
		getline(cin, input);

		int length = input.length();
		int count = 1;

		if (input.compare(".") == 0)
			break;
		else {
			for (int i = 1; i < length; i++) {

				if (length % i)
					continue;

				string a = input.substr(0, i);
				string b = input.substr(length - i, i);

				if (a == b) {
					int j = 1;
					for (j = 1; j < length / i; j++) {
						if (a == input.substr(i * j, i))
							count++;
						else
						{
							count = 1;
							break;
						}

					}
					if (j == length / i)
						break;
				}
			}
			cout << count << endl;
		}
	}

}