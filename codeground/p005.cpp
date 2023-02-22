#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
    const int PRIME = 1000000007, MAX = 1000000, LENGTH = 2 * MAX + 3;
    int Answer, T, test_case, N, M;
    int *fac = new int[LENGTH], *inv = new int[LENGTH];
    long long *fac_inv = new long long[LENGTH], i;
    fac[1] = inv[1] = fac_inv[1] = 1;
	for(i = 2; i < LENGTH; ++i)
    {
        fac[i] = fac[i - 1] * i % PRIME;
        inv[i] = (-PRIME / i * inv[PRIME % i] % PRIME + PRIME) % PRIME;
        fac_inv[i] = fac_inv[i - 1] * inv[i] % PRIME;
	}
    cin >> T;
    for(test_case = 0; test_case < T; test_case++)
    {
        cin >> N >> M;
        Answer = fac[N + M + 2] * fac_inv[N + 1] % PRIME * fac_inv[M + 1] % PRIME - 1;
        cout << "Case #" << test_case + 1 << endl;
        cout << Answer << endl;
    }
    delete(fac);
    delete(inv);
    delete(fac_inv);
    return 0;
}