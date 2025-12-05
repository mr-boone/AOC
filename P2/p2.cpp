#include <iostream>
#include <vector>

int main() {
    std::vector<int> nums;
    int lowerBound;
    int upperBound; 
    char dummy; 

    // Read integers from stdin until EOF
    while (std::cin >> lowerBound) {
        std::cin >> dummy;
        std::cin >> upperBound; 
        std::cout << lowerBound << "-" << upperBound << std::endl; 
    }

   
}
