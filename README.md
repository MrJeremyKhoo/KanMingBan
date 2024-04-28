# Personal CLI KanBan
## Introduction

KanMingBan is a CLI-based Personal Kanban Board written in pure C. It aims to provide a simple and lightweight solution for managing tasks without relying on heavy dependencies or external services. The name "KanMingBan" is derived from "看命板" which translates to "Life Lookup board" in Chinese.

## Motivation

Currently it is written in C only using gcc libraries (binary is only 80kilo bytes)

Not written in Rust because there should be no need for strict memory safety. essentially there is one data structure and one user

Not written in C++/Java because there is no need for their abstract data types, there is essentially only one data structure

Not in Golang because of performance, there is no need for bounds checking and garbage collection for a simple application

## Install
## Installing a Tarball (.tar.gz) on Linux

1. **Download the Tarball**: Download the `tar.gz` file from release


2. **Extract the Tarball**:
   - Use `tar` to extract the contents of the tarball. For example:
     ```bash
     tar -xzvf <kmb-verx.x>.tar.gz
     ```
   - This command will extract the contents of the tarball into a directory.

3. **Navigate to the Extracted Directory**:
   - Use `cd` to navigate into the directory where the contents were extracted. For example:
     ```bash
     cd <dir>
     ```
4. **Install the Software**:
   - Use `make install` to install the compiled software. This step usually requires superuser privileges (root). For example:

     ```bash
     ./configure; sudo make install
5. **Uninstall the Software**:
   - Use `make uninstall` to uninstall the compiled software. This step usually requires superuser privileges (root). For example:

     ```bash
     ./configure; sudo make uninstall
     
## How to use
add task:
```
<executable> a "task1" 
```
delete:
```
<executable> d [task ID]
```
forward task to next column
```
<executable> f [task ID]
```
regress task to prev column
```
<executable> r [task ID]
```
### Tips:
you can add the following to bashrc so that the board opens every time you spawn a window
```
kmb
```
you can use grep, awk, less and other GNU utils to manipulate the output

## RoadMap MVP:
- ~Draw table~
- ~Read Datafile~
- ~Store Datafile on heap~ (Decided to parse from JSON-esq, Cross-compatibiliity)
- ~Parse Datafile (single call, fread to buffer, reduce syscalls if line by line)~
- ~Display data file properly~
- ~Argument handler~
- ~Add tasks~
- ~tasks have ID and description~
- ~Remove tasks~
- ~Promote task~
- ~Regress task~
- ~Delete by ID~
- ~Promote by ID~
- ~Regress by ID~
- ~Add by task name~
- ~Remove from available ID~
- ~Add availiable ID (for deletion)~
- ~add task by name~
- ~Recieve from stdin~
## RoadMap iteration2:
- code quality refactor
- code performance refactor
- Memory leakfix
- drilldown description to task
- Add task in proper order
- Task lifecycle management
- Task throughput analysis
- Add more multiple columns

## RoadMap iteration3:
- Add multiple boards
- Edit task names
- edit description



## License

KanMingBan is copylefted software, released under the [GPL-3.0 license](https://www.gnu.org/licenses/gpl-3.0.en.html).
