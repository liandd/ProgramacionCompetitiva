#include<bits/stdc++.h>
int main() {
    int n;
    while (std::cin >> n) {
        std::vector<std::tuple<std::string, std::string, int>> students;
        for (int i = 0; i < n; ++i) {
            std::string name, region;
            int distance;
            std::cin >> name >> region >> distance;
            students.emplace_back(name, region, distance);
        }
        std::sort(students.begin(), students.end(), [](auto const& a, auto const& b) {
            return std::tie(std::get<2>(a), std::get<1>(a), std::get<0>(a)) <
                   std::tie(std::get<2>(b), std::get<1>(b), std::get<0>(b));
        });
        for (auto const& student : students) {
            std::cout << std::get<0>(student) << "\n";
        }
    }
    return 0;
}
