#include<iostream>
#include <windows.h>

typedef int (*SingleNumberFunc)(const int*, int);

int main() {
    // Path to your DLL. Adjust if needed.
    HMODULE hLib = LoadLibraryA("../lib/single_number/single_number.dll");
    if (!hLib) {
        std::cerr << "Failed to load DLL" << std::endl;
        return 1;
    }

    // Get the function address
    auto func = (SingleNumberFunc)GetProcAddress(hLib, "singleNumber");
    if (!func) {
        std::cerr << "Failed to get function" << std::endl;
        FreeLibrary(hLib);
        return 1;
    }

    // Test data
    int arr[] = {4, 1, 2, 1, 2};
    int result = func(arr, 5);

    std::cout << "Single number: " << result << std::endl; // Output: 4

    FreeLibrary(hLib);
    return 0;
}