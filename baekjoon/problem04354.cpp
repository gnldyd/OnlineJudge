#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
    int Answer, alength, slength, quotient;
    string s, a, comp;
    cin >> s;
    while(s.compare("."))
    {
        Answer = alength = 1;
        slength = s.length();
        while(alength <= slength / 2)
        {
            if(slength % alength == 0)
            {
                a = s.substr(0, alength);
                comp = "";
                quotient = slength / alength;
                while(quotient > 0)
                {
                    comp += a;
                    --quotient;
                }
                if(comp.compare(s) == 0)
                {
                    Answer = slength / alength;
                    break;
                }
            }
            ++alength;
        }
        cout << Answer << endl;
        cin >> s;
    }
<<<<<<< HEAD
    return 0;
}
=======
	return 0;
}
>>>>>>> 84b0fc30351e13a6ac461bd0e508053b3c6f7247
