#include <iostream>

void check(int &x, int &y) {
    bool result = false;

    if (y - x == 1) result = true;
    else if (x > y && (x - (y - 1)) % 9 == 0) result = true;
    else result = false;
    std::cout << (result ? "YES" : "NO") << std::endl;
    return;
}

int main() {
    int testcase;
    int x, y;
    std::cin >> testcase;
    while (testcase--) {
        std::cin >> x >> y;
        check(x, y);
    }

    return 0;
}