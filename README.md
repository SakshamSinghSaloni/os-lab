# Operating Systems Lab

Implementations of Operating Systems algorithms and concepts in C.

This repository contains implementations developed as part of my B.Tech. CSE Operating Systems coursework and for practicing practical C programming.

## Topics

### CPU Scheduling

Implementations of CPU scheduling algorithms.

Currently implemented:

- FCFS (First Come, First Served)

More scheduling algorithms will be added as I implement them.

### Other Operating Systems Concepts

Implementations related to other Operating Systems topics will be added to this repository over time.

## Project Structure

```text
os-lab/
│
├── README.md
│
└── scheduling/
    ├── include/
    │   ├── process.h
    │   └── scheduler_utilities.h
    │
    ├── schedulers/
    │   └── FCFS.c
    │
    └── source/
        └── scheduler_utilities.c