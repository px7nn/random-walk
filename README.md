# 🎨 SDL3 Random Walk Lines
A simple generative art experiment built with **SDL3** in C.  
Multiple colored lines start from the center of the screen and perform a bounded random walk, creating evolving abstract patterns.

## 📸 Preview
* 4 independent lines
* Random colors
* Bounded movement (no going outside window)
* Persistent drawing using a texture as canvas

### Screenshots
<img width="717" height="741" alt="image" src="https://github.com/user-attachments/assets/output1" />
<img width="717" height="738" alt="image" src="https://github.com/user-attachments/assets/output2" />



## 🧠 How It Works

Each frame:
1. A random direction is chosen (X or Y axis)
2. The line moves either positive or negative
3. Boundary checks prevent leaving the screen
4. A line is drawn from old position to new position
5. Drawing accumulates over time on a texture

This creates a **generative art random-walk effect**.

## 📁 Project Structure
```
random-walk/
│
├── SDL/          # SDL3 headers and library files
├── src/          # Your C source files (main.c)
├── .gitignore
├── Makefile      # Build configuration (MinGW)
└── SDL3.dll      # Required runtime DLL
```

## 🛠 Requirements

* **MinGW (GCC)** – for compiling the project
* **SDL3 development library** – included inside this repository (SDL/ folder)

## 🔨 Build

From project root:
```
mingw32-make
```
Or manually:
```
gcc src/main.c -ISDL/include -LSDL/lib -lmingw32 -lSDL3 -o main.exe
```

## ▶ Run
Make sure `SDL3.dll` is in the same directory as `main.exe`, then:
```
./main.exe
```

## 💡 Author
Built as part of learning **SDL3 graphics programming in C**.
