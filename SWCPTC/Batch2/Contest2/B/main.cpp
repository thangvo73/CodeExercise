#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

void solve(int &n, std::string &str) {
    std::vector<int> prefix(n), suffix(n);
    std::set<char> pre_set, suf_set;
    n = n - 1;
    
    prefix[0] = 0;
    suffix[n] = 0;

    for (int i=0; i<=n; i++) {
        pre_set.insert(str[i]);
        suf_set.insert(str[n-i]);

        prefix[i] = pre_set.size();
        suffix[n-i] = suf_set.size();
    }

    int maxVal = 0;
    for (int i=0; i<n; i++) {
        maxVal = std::max(maxVal, prefix[i] + suffix[i+1]);
    }

    std::cout << maxVal << std::endl;
}

int main() {
    int testcase = 0;
    std::cin >> testcase;

    while (testcase--) {
        int size = 0;
        std::cin >> size;
        std::string str;
        std::cin >> str;

        solve(size, str);
    }
    return 0;
}