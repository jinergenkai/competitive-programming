#include <iostream>
#include <vector>
#include <algorithm>

void binarySearchLessThan(const std::vector<int>& sortedList, int value) {
    // Sử dụng lower_bound để tìm vị trí đầu tiên không nhỏ hơn value
    auto it = std::lower_bound(sortedList.begin(), sortedList.end(), value);
    
    // Nếu it không trỏ tới phần đầu danh sách, in ra các phần tử nhỏ hơn value
    if (it != sortedList.begin()) {
        std::cout << "Các giá trị nhỏ hơn " << value << " là:\n";
        for (auto i = sortedList.begin(); i < it; ++i) {
            std::cout << *i << " ";
        }
        std::cout << std::endl;
    } else {
        std::cout << "Không có giá trị nào nhỏ hơn " << value << std::endl;
    }

    // Nếu có giá trị >= value thì in ra giá trị đầu tiên
    if (it != sortedList.end()) {
        std::cout << "Giá trị đầu tiên >= " << value << " là: " << *it << std::endl;
    }
}

int main() {
    // Danh sách mẫu đã được sắp xếp
    std::vector<int> example = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    // Gọi hàm với giá trị tìm kiếm là 5
    binarySearchLessThan(example, 5);

    return 0;
}
