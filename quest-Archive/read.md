# quest-Archive

## Overview
quest-Archive is a small C++ project that is being set up as a text-based adventure or quest-driven application. The repository currently contains the basic file structure for the project and is intended to grow into a playable console program.

## Project Properties
- Language: C++
- Type: Console application
- Style: Simple, file-based project structure
- Purpose: Manage an adventurer and quest-related content
- Current status: Early-stage scaffold with placeholder files

## Project Structure
- `main.cpp` — Program entry point and main flow
- `adventurer.h` — Declaration for the adventurer-related class/interface
- `adventurer.cpp` — Implementation file for adventurer logic
- `quests.txt` — External data file for quest content
- `read.md` — Project documentation

## Current Responsibilities
- `main.cpp` is expected to initialize the program and coordinate the main logic.
- `adventurer.h` and `adventurer.cpp` are intended to define the adventurer's behavior and state.
- `quests.txt` is meant to store quest data that the program can load or process.

## Build Instructions
```bash
g++ main.cpp adventurer.cpp -o quest-archive
./quest-archive
```

## Usage
Run the compiled program from the project folder.
- The current version is a starting template.
- Future versions may include interactive gameplay, quest selection, and adventurer progression.

## Data File Format
`quests.txt` is planned to hold quest-related information such as:
- Quest name
- Description
- Objectives
- Rewards or status

The exact format is still to be defined as the project evolves.

## Design Notes
- The project is organized around a simple modular structure.
- The adventurer logic is separated into header and implementation files for clarity.
- Quest data is intended to be stored externally instead of being hardcoded.

## TODO
- Implement the adventurer class
- Define quest data format in `quests.txt`
- Build the game loop in `main.cpp`
- Add input/output handling and gameplay logic

## Author
- Hamza
- 2026
