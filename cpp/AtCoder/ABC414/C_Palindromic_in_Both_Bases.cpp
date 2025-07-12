#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;

int main() {
    ll A, N;
    cin >> A >> N;
    string n_str = to_string(N);
    int len_max = n_str.size();

    ll sum = 0;
    for (int L = 1; L <= len_max; L++) {
        int half = (L + 1) / 2;
        ll start = 1;
        for (int i = 1; i < half; i++) {
            start *= 10;
        }
        ll end = start * 10 - 1;

        for (ll left = start; left <= end; left++) {
            string s = to_string(left);
            string rev;
            if (L % 2 == 0) {
                rev = s;
                reverse(rev.begin(), rev.end());
            } else {
                if (s.size() > 1) {
                    rev = s.substr(0, s.size() - 1);
                } else {
                    rev = "";
                }
                reverse(rev.begin(), rev.end());
            }
            string palindrome_str = s + rev;
            if (palindrome_str.size() != L) {
                continue;
            }

            ll x = stoll(palindrome_str);
            if (x > N) {
                break;
            }

            ll t = x;
            vector<ll> digits;
            while (t) {
                digits.push_back(t % A);
                t /= A;
            }
            bool is_palindrome = true;
            int num_digits = digits.size();
            for (int i = 0; i < num_digits / 2; i++) {
                if (digits[i] != digits[num_digits - 1 - i]) {
                    is_palindrome = false;
                    break;
                }
            }
            if (is_palindrome) {
                sum += x;
            }
        }
    }
    cout << sum << endl;
    return 0;
}