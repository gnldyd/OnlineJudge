#include <iostream>
#include <cstring>
#include <string>

using namespace std;

int main(int argc, char** argv)
{
    const int MAX_SEQUENCE_LENGTH = 50000;
    string PERIODIC_TABLE[] = {
        "H", "He", "Li", "Be", "B", "C", "N", "O", "F", "Ne", "Na", "Mg", "Al",
        "Si", "P", "S", "Cl", "Ar", "K", "Ca", "Sc", "Ti", "V", "Cr", "Mn", "Fe",
        "Co", "Ni", "Cu", "Zn", "Ga", "Ge", "As", "Se", "Br", "Kr", "Rb", "Sr",
        "Y","Zr", "Nb", "Mo", "Tc", "Ru", "Rh", "Pd", "Ag", "Cd", "In", "Sn", "Sb",
        "Te", "I", "Xe", "Cs", "Ba", "Hf", "Ta", "W", "Re", "Os", "Ir", "Pt", "Au",
        "Hg", "Tl", "Pb", "Bi", "Po", "At", "Rn", "Fr", "Ra", "Rf", "Db", "Sg",
        "Bh", "Hs", "Mt", "Ds", "Rg", "Cn", "Fl", "Lv", "La", "Ce", "Pr", "Nd",
        "Pm", "Sm", "Eu", "Gd", "Tb", "Dy", "Ho", "Er", "Tm", "Yb", "Lu", "Ac",
        "Th", "Pa", "U", "Np", "Pu", "Am", "Cm", "Bk", "Cf", "Es", "Fm", "Md",
        "No", "Lr"
    };
    int T, test_case, i, j;
    int count = sizeof(PERIODIC_TABLE) / sizeof(PERIODIC_TABLE[0]);
    int length[count];
    string Answer, sequence;
    for(i = 0; i < count; ++i)
    {
        for(char &c : PERIODIC_TABLE[i])
        {
            c = tolower(c);
        }
        length[i] = PERIODIC_TABLE[i].length();
    }
    cin >> T;
    for(test_case = 0; test_case < T; test_case++)
    {
        cin >> sequence;
        int legal[MAX_SEQUENCE_LENGTH + 1] = {1, };
        for(i = 0; i < sequence.length(); ++i)
        {
            for(int j = 0; j < count; ++j)
            {
                if(i >= length[j] - 1 && strcmp(sequence.substr(i - length[j] + 1, length[j]).c_str(), PERIODIC_TABLE[j].c_str()) == 0)
                {
                    legal[i + 1] |= legal[i - length[j] + 1];
                }
            }
        }
        Answer = legal[sequence.length()] ? "YES" : "NO";
        cout << "Case #" << test_case + 1 << endl << Answer << endl;
    }
    return 0;
}