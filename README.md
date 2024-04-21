# Personal Kanban Board (KanMingBan)

## Introduction

KanMingBan is a CLI-based Personal Kanban Board written in pure C. It aims to provide a simple and lightweight solution for managing tasks without relying on heavy dependencies or external services. The name "KanMingBan" is derived from "看命板" which translates to "Life Lookup board" in Chinese.

## Motivation

The motivation behind KanMingBan was the lack of lightweight CLI-based Kanban board solutions. Existing alternatives either had limited features, heavy dependencies (they tend to be toy projects), or were tightly integrated with other tools like text editors or cloud services (enterprise level)

Existing webbased tools also do not embody actual KanBan. Throughput, cycle time, Lead time and work in progress should be measured, if they are measured they are usually for enterprise and not personal use.

currently it is written in C so that future extentions do not get bogged down by the language choice. There is also no reason for just-in-time compilation for CRUD logic.

Not written in Rust because there should be no need for strict memory safety. essentially there is one data structure and one user

Not written in C++/Java because there is no need for their abstract data types, there is only one data structure

Not in Golang because of performance, there is no need for bounds checking and garbage collection for a simple application

## Philosophy

KanMingBan should be a portable personal Kanban boards. Should be as quick and self-contained as a kanban board itself.

keep it simple and lightweight
make it fast
(A CRUD app should not take more a tenth of a second to load/interface with.)


## RoadMap MVP:
- ~Draw table~
- ~Read Datafile~
- ~Store Datafile on heap~ (Decided to parse from JSON, Cross-compatibiliity, faster to parse)
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
- ID cache
- Recieve from stdin
- add task by name
  
## RoadMap iteration2:
- add description to task
- Swap task position on board
- Task lifecycle management
- Task throughput analysis

## RoadMap iteration3:
- Edit task names
- Task drilldown
- Tagging
- Filtering


## License

KanMingBan is copylefted software, released under the [GPL-3.0 license](https://www.gnu.org/licenses/gpl-3.0.en.html).
