# Personal Kanban Board (KanMingBan)

## Introduction

KanMingBan is a CLI-based Personal Kanban Board written in pure C. It aims to provide a simple and lightweight solution for managing tasks without relying on heavy dependencies or external services. The name "KanMingBan" is derived from "看命板" which translates to "Life Lookup board" in Chinese.

## Motivation

The motivation behind KanMingBan was the lack of lightweight CLI-based Kanban board solutions. Existing alternatives either had limited features, heavy dependencies (they tend to be toy projects), or were tightly integrated with other tools like text editors or cloud services (enterprise level)

Existing webbased tools also do not embody actual KanBan. Throughput, cycle time, Lead time and work in progress should be measured. Instead these tools focus on collaboration (with a subscription)

currently it is written in C so that future extentions do not get bogged down by the language choice. There is also no reason for just-in-time compilation for CRUD logic.

Not written in Rust because there should be no need for strict memory safety. essentially there is one data structure and one user

Not written in C++/Java because there is no need for their abstract data types, there is only one data structure

Not in Golang because of performance, there is no need for bounds checking and garbage collection for a simple application

## Philosophy

KanMingBan is designed to replace traditional sticky note Kanban boards. It focuses on offline usability and speed, aiming to provide a fast and efficient way to manage tasks without the need for cloud integration, advanced features, or heavy dependencies. The philosophy is to keep it simple and lightweight, resembling the traditional Kanban board experience. A CRUD app should not take more a tenth of a second to load/interface with.

Following Kanban philosophy lead time, cycle time, work-in-progress, and throughput should also be measured eventually

## RoadMap MVP:
- ~Draw table~
- ~Read Datafile~
- ~Store Datafile on heap~ (Decided to parse from JSON, Cross-compatibiliity, faster to parse)
- ~Parse Datafile (single call, fread to buffer, reduce syscalls if line by line)~
- ~Display data file properly~
- Argument handler class
- Add tasks
- Remove tasksh
- Promote task
- Regress task
- Swap task position on board
- Limit on column
  
## RoadMap iteration2:
- Edit task names
- Task drilldown
- Task lifecycle management
- Task throughput analysis

## RoadMap iteration3:
- Tagging
- Filtering
  
## RoadMap iteration4:
- Basic GUI support
  - Windows
  - macOS
  - Linux/GNU


## License

KanMingBan is copylefted software, released under the [GPL-3.0 license](https://www.gnu.org/licenses/gpl-3.0.en.html).
