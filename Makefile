all:
	gcc src/main.c -ISDL/include -LSDL/lib -lmingw32 -lSDL3 -o main.exe
