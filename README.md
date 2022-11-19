# CPP Setup

## Install Chocolatey
https://docs.chocolatey.org/en-us/choco/setup

Open new powershell.
- Confirm `choco` command works.

</br>

## Install CMake and Make using Chocolatey
https://community.chocolatey.org/packages/cmake
https://community.chocolatey.org/packages/make

Open powershell as administrator and run the following:

Install cmake and add to path:
```
choco install cmake --installargs 'ADD_CMAKE_TO_PATH=System'
choco install make
```

Close and reopen powershell.
- Confirm `cmake` command works.
- Confirm `make` command works.

</br>

## Install `vcpkg` for installing libraries (Recommended)
https://vcpkg.io/en/getting-started.html

`C:/cppdev` is our chosen install directory for vcpkg, create your own directory and update the below commands as necessary.

### Open powershell as administrator and run the following:

#### 1) Download vcpkg repository
```powershell
cd C:/cppdev/
git clone https://github.com/Microsoft/vcpkg.git
```
#### 2) Run vcpkg install scripts
```powershell
./vcpkg/bootstrap-vcpkg.bat
cd vcpkg
./vcpkg integrate install
```

Further Information:
https://vcpkg.readthedocs.io/en/latest/examples/installing-and-using-packages/

</br><hr></br>

# Installing Libraries

As an example for demonstration, we will be building a WebSocket client using ixwebsocket.

## Install ixwebsocket
```
cd C:/cppdev/vcpkg
./vcpkg install ixwebsocket:x64-windows
```

Make sure to use `<libname>:x64-windows` for libs to generate dlls

Outputs:
```CMake
# ixwebsocket provides CMake targets:
find_package(ixwebsocket CONFIG REQUIRED)
target_link_libraries(<executable_name> PRIVATE ixwebsocket::ixwebsocket)
```

Copy the above lines to `CMakeLists.txt` as required (`ixwebsocket` already present in the example `CMakeLists.txt`).


</br><hr></br>

# Build Project

## 1) Build

Set the toolchain path either (a) in `CMakeLists.txt` or (b) manually in the build command:

### (a) In `CMakeLists.txt`
```CMake
set(CMAKE_TOOLCHAIN_FILE "C:/cppdev/vcpkg/scripts/buildsystems/vcpkg.cmake" CACHE STRING "")
```

Run the build command:

```powershell
cmake -S . -B build
```

### (b) Manually in the build command

Run the build command:
```powershell
cmake -S . -B build -DCMAKE_TOOLCHAIN_FILE=C:\\cppdev\vcpkg\scripts\buildsystems\vcpkg.cmake
```

</br>

## 2) Compile and Run

PowerShell (use `;`),  CMD / Bash (use `&&`)
```powershell
cmake --build build ; ./build/Debug/<executable_name>
```

Run this every time you make a change to be recompile.

</br><hr></br>

### Example Server for Testing
```cmd
websocat wss://prod-pusher.backend-capital.com/app/app_key?protocol=7&client=js&version=4.2.2&flash=true
```

Paste the following in the running shell:
```json
{"event":"pusher:subscribe","data":{"channel":"27045129890124996"}}
```


