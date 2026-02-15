# SDL3 – Basic Setup Directory
A minimal **SDL3 setup template** for C using **MinGW (GCC)** on Windows.  
This repository provides a clean starting structure for building SDL3 projects.

## 📁 Project Structure

```
SDL3-Basic-Setup/
│
├── SDL/           # SDL3 headers and library files
├── src/           # Your C source files (main.c, etc.)
├── .gitignore
├── Makefile       # Build configuration using MinGW
├── SDL3.dll       # Required runtime DLL
```
---

## ⚙️ Requirements

* Windows OS
* MinGW (GCC)
* SDL3 Development Library

  
Make sure `gcc` is available in your system PATH:
```
gcc --version
```

## 🛠️ Build Instructions
From the project root directory:
```
mingw32-make
```
This will generate:
```
main.exe
```
## ▶️ Run the Program
After building:
```
.\main.exe
```

> ⚠️ **Important:**
> `SDL3.dll` must be in the **same directory** as `main.exe`, or Windows will fail to launch the program.


## 🔧 Manual Compile Command (Without Makefile)

If you prefer compiling manually:

```bash
gcc src/main.c -ISDL/include -LSDL/lib -lmingw32 -lSDL3 -o main.exe
```

### Explanation of Flags

* `-ISDL/include` → Include SDL header files
* `-LSDL/lib` → Link SDL library directory
* `-lmingw32` → Required MinGW system library
* `-lSDL3` → Link against SDL3

---

## 🚀 Purpose
This repository serves as:
* A clean SDL3 starter template
* A reference for correct folder structure
* A minimal working setup for learning SDL3
