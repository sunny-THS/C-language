#include <bits/stdc++.h>
#include <cmath>

using namespace std;

// Complete the powerSum function below.
int powerSum(int X, int N, int current = 1) {
    double p=pow(current, N);
    if( (int)p > X ) return 0;
    else if((int)p == X) return 1;
    return powerSum(X, N, current+1) + powerSum(X - (int)p, N, current+1);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int X;
    cin >> X;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int N;
    cin >> N;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int result = powerSum(X, N);

    cout << result << "\n";

    fout.close();

    return 0;
}
