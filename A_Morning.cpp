#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        string str;
        cin >> str;
        int s = str[0] - '0';

        if (s == 0) {
            s = 10;
        }

        for (int i = 1; i < str.size(); i++) {
            if (str[i] == '0') {
                s += abs((str[i - 1] - '0') - 10) + 1;
               // cout<<s<<" ";
                continue;
            }

            s += abs((str[i - 1] - '0') - (str[i] - '0')) + 1;
        }

        cout << s << endl;
    }

    return 0;
}
