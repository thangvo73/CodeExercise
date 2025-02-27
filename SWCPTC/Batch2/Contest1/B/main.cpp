#include <iostream>
#include <vector>
#include <algorithm>

void solve(int &n, std::vector<long long> &vec) {
    n = n -1;
    std::vector<long long> prefix(n+1), suffix(n+1);
    
    prefix[0] = 0;
    suffix[n] = 0;

    for (int i=1; i<=n; i++) {
        if (vec[i-1] > 0) prefix[i] = prefix[i-1] + vec[i-1];
        else prefix[i] = prefix[i-1];
        
        if (vec[n-i+1] < 0) suffix[n-i] = suffix[n-i+1] - vec[n-i+1];
        else suffix[n-i] = suffix[n-i+1];
    }

    long long maxVal = 0;
    for (int i=0; i<=n; i++) {
        maxVal = std::max(maxVal, prefix[i] + suffix[i] + std::abs(vec[i]));
    }

    std::cout << maxVal << std::endl;
}

int main() {
    int testcase = 0;
    std::cin >> testcase;

    while (testcase--) {
        int size = 0;
        std::cin >> size;
        std::vector<long long> vec(size);
        for (int i=0; i<size; i++) {
            std::cin >> vec[i];
        }

        solve(size, vec);
    }
    return 0;
}