# Multi-Language Functions: C++ + Go + C# + Python
This project demonstrates how to build and use shared libraries (DLL/.so) from different languages (C++ and Go) and consume them in C# and Python.

### Function 1 (C++): single_number

### Function 2 (Go): IsPalindrome

Project Structure
```bash
multi-lang-project/
├─ cpp_single_number/      # C++ source code
│   └─ single_number.cpp
├─ go_palindrome/          # Go source code
│   └─ palindrome.go
├─ libs/                   # Compiled shared libraries
├─ cs_app/                 # C# application
│   ├─ Program.cs
│   └─ cs_app.csproj
├─ python_app/             # Python script
│   └─ test_functions.py
└─ README.md
```

## Prerequisites
- g++ (MinGW on Windows or GCC/Clang on Linux/macOS)
- Go 1.20+
- .NET 8 SDK
- Python 3.10+ (using Conda for environment management)

### Set up Python environment from the project root:

```bash
conda create -n multi_lang_env python=3.10 -y
conda activate multi_lang_env
You can then run the Python script in step 5.
```

### Compile the C++ library navigate to the C++ source folder:

```bash
cd cpp_single_number
```
### Compile with g++:

Linux/macOS
```bash
g++ -shared -fPIC single_number.cpp -o ../libs/libsingle_number.so
```
Windows (MinGW)
```bash
g++ -shared -o ../libs/single_number.dll single_number.cpp
```
### Compile the Go library
Navigate to the Go source folder:

```bash
cd ../go_palindrome
```
**Compile with:**

Linux/macOS
```bash

go build -o ../libs/libpalindrome.so -buildmode=c-shared palindrome.go
```
Windows
```bash
go build -o ../libs/palindrome.dll -buildmode=c-shared palindrome.go
```
The compiled libraries will be saved in the `libs/` directory.

## Run the C# application
Navigate to the C# app folder:

```bash
cd ../cs_app
dotnet build
dotnet run
```
Expected output:

```
Single number: 7
'mom' is palindrome? true
'No' is palindrome? false
```
## Run the Python script
Make sure your Conda environment is activated:

```bash
conda activate multi_lang_env
cd ../python_app
python test_functions.py
```
Expected output:

```
Single number: 7
'mom' is palindrome? true
'No' is palindrome? false
```

Library file names
|OS	| C++ library |Go library |
| ------- | ------- | ------- |
|Windows	| libs/single_number.dll	| libs/palindrome.dll |
|Linux/macOS | libs/libsingle_number.so	| libs/libpalindrome.so |


Update the library paths in `Program.cs` and `test_functions.py` accordingly if running on Linux/macOS.

**Notes**  
Make sure all compiled libraries (.dll or .so) are in the `libs/` folder before running the C# or Python code.

Architecture (x64 vs x86) of all binaries and runtimes must match.

This setup uses manual compilation commands without build systems like CMake for simplicity.

**Educational goals**  
Export C-compatible functions from C++ and Go.

### Consume native libraries from:

- C# using DllImport (P/Invoke)
- Python using ctypes
