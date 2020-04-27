#include <stdio.h>
#include <iomanip>
#include <iostream>
#include <math.h>
#include <cstdlib>
#include <ctime>
#define E 2.71828

using namespace std;

double Factor(float n) {
    double res = 1;
    for (int i = 2; i <= n; i++) {
        res *= i;
    }
    return res;
}

double Poisson(double lambda, double t, double n) {
    return (pow(lambda, t) * pow(E, -lambda)) / Factor(n);
}

double ExpGen(double lambda) {
    return log((rand() - 1) / (lambda));
}

int main() {

    double lambda, n, t, res = 0, sum = 0;
    cout << "enter lambda: " << endl; cin >> lambda;
    cout << "enter n: " << endl; cin >> n;
    cout << "enter t: " << endl; cin >> t;
    for (int i = 0; i < n; i++)
    {
        sum = ExpGen(lambda);
        cout << setprecision(10) << sum << endl;
    }
    sum = 0;
    res = 0;
    cout << "--------------------------------------------" << endl;
    for(int i = 0; i < n; i++) {
        sum += Poisson(lambda, t, res);
        cout <<setprecision(10)<< sum << endl;
    } 
    return res - 1;
}