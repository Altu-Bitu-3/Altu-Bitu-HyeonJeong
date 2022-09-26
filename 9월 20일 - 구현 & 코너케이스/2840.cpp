#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, k;
    int idx = 0;
    cin >> n >> k;
    vector<char> wheel(n);

    for (int i = 0; i < n; i++) {
        wheel[i] = '?';
    }

    for (int i = 0; i < k; i++) {
        int cnt;
        char ch;
        cin >> cnt >> ch;
        if (i == 0) {
            wheel[0] = ch;
            idx = 0;
            continue;
        }
        idx = (cnt + idx) % n;

        if (wheel[idx] != '?' && wheel[idx] != ch) {
            cout << "!";
            return 0;
        } else {
            wheel[idx] = ch;
        }
    }

    for (int i = 0; i < n - 1; i++) { // 중복체크해주기
        for (int j = i + 1; j < n; j++) {
            if (wheel[i] != '?' && wheel[i] == wheel[j]) {
                cout << "!";
                return 0;
            }
        }
    }

    //출력
    for (int i = 0; i < n; i++) {
        cout << wheel[idx];
        idx--;
        if (idx == -1)
            idx = n - 1;
    }
    cout << '\n';

    return 0;
}
