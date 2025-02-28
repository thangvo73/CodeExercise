#include <iostream>

void swap_value(int &x, int &y) {
    int tmp;
    tmp = x;
    x = y;
    y = tmp;
}

void solve(int &a, int &b, int &c) {
    int nums = 7;
    if (a > b) swap_value(a, b);
    if (a > c) swap_value(a, c);
    if (b > c) swap_value(b, c);

    if (a < 3) {
        nums = nums - (4 - a);
        if (b < 2) {
            nums =  nums - (2 - b);
            if (c == 0) nums = nums - 1;
        }
    }
    else if (a == 3) nums = 6;

    std::cout << nums << std::endl;
}

int main() {
    int testcase;
    std::cin >> testcase;
    while (testcase--) {
        int a,b,c;
        std::cin >> a >> b >> c;

        solve(a,b,c);
    }

    return 0;
}