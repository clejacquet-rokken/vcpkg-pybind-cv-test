# To reproduce

**Environment**
- OS: Windows 11 Home
- Compiler: MSVC (Visual Studio Community 2022 17.5.1 - amd64)
- CMake version 3.25.1-msvc1
- Python 3.10.10
- Pybind11 2.9.1

The Python package `opencv-python-headless` has to be installed.

## Bash

Configure and install dependencies with VCPKG:
```bash
cmake -B build -S . -DCMAKE_TOOLCHAIN_FILE=[path-to-vcpkg]/scripts/buildsystems/vcpkg.cmake
```

If you use a virtualenv environment:
```bash
cmake -B build -S . -DCMAKE_TOOLCHAIN_FILE=[path-to-vcpkg]/scripts/buildsystems/vcpkg.cmake -DCUSTOM_SYS_PATH=[path-to-env]/Lib/site-packages -DPYTHON_EXECUTABLE:FILEPATH=[path-to-env]/Scripts/python.exe
```

Build:
```bash
cmake --build build --target PybindTest --config Release
```

Run:
```bash
./build/Release/PybindTest.exe
```

The following error message should appear:
```
ImportError: DLL load failed while importing cv2: The specified module could not be found.
```

## With VSCode:

The `.vscode/settings.json` file is provided, but you need to adapt the paths to your environment.

# Temporary solution:

It seems that setting the env var `PYTHONPATH` to the path of an external installation of OpenCV fixes this issue.

I tested with the pre-built version of OpenCV 4.6.0 that you can download here: https://docs.opencv.org/4.x/d3/d52/tutorial_windows_install.html

Then set the env var `PYTHONPATH` to `[path-to-external-opencv]/build/python` before running the program.

For VSCode users, the `.vscode/launch.json` file is provided with the env var commented out.