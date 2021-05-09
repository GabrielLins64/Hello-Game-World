## Hello Game World

Learning SDL 2 (and more from C++) by building a game. The development of this game is lead by a tutorial book [[1]](#references) referenced in this doc.

<hr>

#### Index

- [Requirements](#requirements)
- [Building](#building)
  - [In VS Code](#method-1)
  - [With shell script](#method-2)
  - [By command line](#method-3)
  - [With CMake](#method-4)
- [Content](#content)
  - [SDL 2](#sdl-2)
  - [C++](#c++)
- [References](#references)

<hr>

### Requirements

- **Linux (for now)**
- **C++17**
- **GNU C++ Compiler ( g++ )**
- **Simple DirectMedia Layer 2.0 (SDL2)**

### Building

##### Method 1 (VS Code)

Use the files at `.vscode` dir to build the project and run.

Shortcuts for using the files:
> **Build:** ctrl + shift + B
> 
> **Run:** ctrl + F5

##### Method 2 (Shell script)

Give execution permission and run the *shell script*:

> $ chmod +x run<span/>.sh
> 
> $ ./run.sh

##### Method 3 (Command line)

Compile and run by command line:

> g++ -std=c++17 -Iinclude -o bin/main src/*.cpp \`sdl2-config --cflags --libs\`

##### Method 4 (CMake)

Use cmake:

`UNDER CONSTRUCTION`

### Tips

Useful concepts learned in the development of this game.

##### SDL 2

`UNDER CONSTRUCTION`

##### C++

`UNDER CONSTRUCTION`

### References

[1] **Mitchell, Shaun.** [SDL Game Development](https://github.com/kirbyboy/SDL-game-development-source-code): *Discover how to leverage the power of SDL 2.0 to create awesome games in C++*. Packt Publishing, 2013.

[2] [Google](https://www.google.com.br)

[3] [Stack Overflow](https://stackoverflow.com/)
