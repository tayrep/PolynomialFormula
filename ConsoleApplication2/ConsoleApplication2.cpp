#include <iostream>
#include <vector>

using namespace std;

vector<int> exps;

long long factorial(int n) {
    long long res = 1;
    for (int i = 2; i <= n; i++) {
        res *= i;
    }
    return res;
}

long long calcCoeff(const vector<int>& exps_, int m) {
    long long temp = 1;
    for (auto i : exps_)
        temp *= factorial(i);
    return factorial(m) / temp;
}

void alg(int pos, int rem, int k, int m) {
    if (pos != k - 1) {
        for (int i = 0; i <= rem; i++) {
            exps[pos] = i;
            alg(pos + 1, rem - i, k, m);
        }
    }
    else {
        exps[pos] = rem;
        long long coeff = calcCoeff(exps, m);
        for (int i = 0; i < k; i++) {
            if (i == k - 1) 
                cout << "x" << i + 1 << "^" << exps[i];      
            else
                cout << "x" << i + 1 << "^" << exps[i] << ", ";
        }
        cout << ": " << coeff << "\n";
    }
}

int main()
{
    int k = 3;
    int m = 5;

    exps.resize(k);
    alg(0, m, k, m);

    return 0;
}