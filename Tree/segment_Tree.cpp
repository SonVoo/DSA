#include <iostream>
using namespace std;

int n, a[1000], t[1000 * 4];

void build(int v, int l, int r) {
    if (l == r) {
        t[v] = a[l];
    }
    else {
        int m = (l + r) / 2;
        build(2 * v, l, m);
        build(2 * v + 1, m + 1, r);
        t[v] = t[2 * v] + t[2 * v + 1];
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    build(1, 0, n - 1);
    for (int i = 1; i <= 15; i++) {
        cout << t[i] << " ";
    }
    cout << endl;

    return 0;
}