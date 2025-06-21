# Rule 30 Cellular Automaton

This project implements the Rule 30 elementary cellular automaton in C++. It simulates the evolution of a one-dimensional array of cells, each of which can be either alive or dead, over a specified number of rounds. The program provides a menu-driven interface allowing users to configure the automaton, initialize the cells, and observe their evolution.

---
# Rule set
The following is a wikipedia explanation of the rule 30.
<img width="758" alt="Rule-set" src="https://github.com/user-attachments/assets/7c97edcf-d0ab-4c5c-990f-6907d7387b25" />

---

## Demo Screenshots

| Menu | Initial cells | random config |
|------------|------------------------|------------------------|
| <img width="523" alt="Menu system" src="https://github.com/user-attachments/assets/4a160c53-4ff6-44c6-8fb7-efe9f16009b8" /> | <img width="505" alt="Example1-Defualt" src="https://github.com/user-attachments/assets/8a2de9fd-669e-43c2-9cc0-5256a1399422" /> | <img width="554" alt="Example2-RandomSelection" src="https://github.com/user-attachments/assets/2fbfb0aa-e34c-4d05-ae84-d82798794ccc" /> |

---

## Features

- Dynamic array size specified via command-line argument.
- Menu system for easy interaction.
- Option to manually set initial cell states or randomize them.
- Specify the number of rounds to evolve the automaton.
- Clear, step-by-step display of automaton evolution.
- Option to quit at any time.

---

## How to Use

- Compile the program using a C++ compiler supporting C++11 or later.

- Run the program with the size of the cellular array as a command-line argument. For example:


- Use the on-screen menu to:

- Choose to initialize the array randomly or manually.
- Enter the number of evolution rounds.
- Start the cellular automaton simulation.
- Quit the program.

- The program displays each round of evolution, showing alive cells as `1` and dead cells as `0`.

---

## About Rule 30

Rule 30 is a well-known elementary cellular automaton introduced by Stephen Wolfram. It evolves a one-dimensional array of cells by applying a simple set of rules based on the state of each cell and its immediate neighbors.

For a detailed explanation, visit the [Rule 30 Wikipedia page](https://en.wikipedia.org/wiki/Rule_30).

---

## Project Structure

- `main.cpp`: Entry point; handles command-line arguments and menu.
- `CellularSpace.h` / `CellularSpace.cpp`: Contains the `CellularSpace` namespace with functions for initializing and evolving the cellular automaton.
- `screenshots/`: Folder containing demo screenshots for documentation.


Feel free to explore the code and experiment with different array sizes and initialization methods!
