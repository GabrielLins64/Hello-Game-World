## My docs


### Compiling and run

##### Method 1

Use the files at `.vscode` dir to build the project and run.

Shortcuts for using the files:
> **Build:** ctrl + shift + B
> **Run:** ctrl + F5

##### Method 2

Give execution permission and run the *shell script*:

> `$ chmod +x run.sh`
> `$ ./run.sh`

##### Method 3

Compile and run by command line interface:

> g++ -std=c++17 -Iinclude -o bin/main src/*.cpp \`sdl2-config --cflags --libs\`

##### Method 4

Use cmake:
