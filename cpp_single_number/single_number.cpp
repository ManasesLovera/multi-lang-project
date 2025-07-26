#include<iostream>

extern "C" 
#ifdef _WIN32
__declspec(dllexport)
#endif
int singleNumber(const int* nums, int size) {
    int result = 0;
    for (int i = 0; i < size; ++i) {
        result ^= nums[i];
    }
    return result;
}

// This main() will only matter when you compile as an executable
int main() {
    int nums[] = { 1, 7, 3, 6, 3, 6, 1 };
    int length = sizeof(nums) / sizeof(nums[0]);
    int single = singleNumber(nums, length);
    std::cout << "The single number is: " << single << std::endl;
}