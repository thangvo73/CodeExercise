#include <iostream>
#include <unordered_map>
#include <vector>

void solve(std::vector<int> &lan_vec, std::vector<int> &audio_vec, std::vector<int> &sub_vec) {
    int mov_index = 0;
    int max_freq = 0;
    int max_freq1 = 0;
    std::unordered_map<int, int> freq;
    for (int num : lan_vec) {
        freq[num]++;
    }

    std::unordered_map<int, int> map_index;
    for (int i = 0; i < audio_vec.size(); i++) {
        map_index[audio_vec[i]] = i;
    }
    for (auto& pair : freq) {
        auto tmp = map_index.find(pair.first);
        if (tmp != map_index.end()) {
            if (pair.second > max_freq) {
                max_freq = pair.second;
                mov_index = tmp->second;
            }
            else if (pair.second == max_freq) {
                auto tmp1 = freq.find(sub_vec[tmp->second]);
                if (tmp1 != freq.end()) {
                    if (tmp1->second > max_freq1) {
                        max_freq1 = tmp1->second;
                        mov_index = tmp->second;
                    }
                }
            }
        }
    }
    std::cout << mov_index + 1 << std::endl;
}

int main() {
    int sci_nums, mov_nums;
    std::cin >> sci_nums;
    std::vector<int> lan_vec(sci_nums);
    for (int i=0; i<sci_nums; i++) {
        std::cin >> lan_vec[i];
    }

    std::cin >> mov_nums;
    std::vector<int> audio_vec(mov_nums);
    std::vector<int> sub_vec(mov_nums);
    for (int i=0; i<mov_nums; i++) {
        std::cin >> audio_vec[i];
    }
    for (int i=0; i<mov_nums; i++) {
        std::cin >> sub_vec[i];
    }

    solve(lan_vec, audio_vec, sub_vec);
    return 0;
}