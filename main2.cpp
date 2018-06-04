#include <iostream>
#include <vector>

#define ll long long
using namespace std;

int N;
vector<vector<ll>> memo;

ll f(int n, int type) {
    if (n > N) {
        return 0;
    } else if (n == N) {
        return 1;
    }
    if (memo[n + 2][3] == 0) {
        memo[n + 2][3] = f(n + 2, 3) % 10007;
    }
    if (memo[n + 2][2] == 0) {
        memo[n + 2][2] = f(n + 2, 2) % 10007;
    }
    if (memo[n + 1][1] == 0) {
        memo[n + 1][1] = f(n + 1, 1) % 10007;
    }
    return (memo[n + 2][3] + memo[n + 2][2] + memo[n + 1][1]) % 10007;
}

int main() {
    cin >> N;
    memo.resize(N + 5, vector<ll>(N + 5, 0));
    cout << f(0, 0);
    return 0;
}