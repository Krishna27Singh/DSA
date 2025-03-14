#include <iostream>
#include <vector>
#include <algorithm> // for std::find
using namespace std;

int main() {
    std::vector<int> vec;

    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);
    int value_to_find = 3;
    auto it = std::find(vec.begin(), vec.end(), value_to_find);

    if (it != vec.end()) {
        std::cout << "Value " << value_to_find << " found at index " 
                  << std::distance(vec.begin(), it) << std::endl;
    } else {
        std::cout << "Value " << value_to_find << " not found in the vector." << std::endl;
    }

    return 0;
}
