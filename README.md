# Rule 30 Cellular Automaton

This project implements the Rule 30 elementary cellular automaton in C++. It simulates the evolution of a one-dimensional array of cells, each of which can be either alive or dead, over a specified number of rounds. The program provides a menu-driven interface allowing users to configure the automaton, initialize the cells, and observe their evolution.

---

## Demo Screenshots

![Initial state with random initialization](./screenshots/initial_state.png)  
*Initial random configuration of cells*

![Evolution after several rounds](./screenshots/evolution_rounds.png)  
*Automaton evolution after multiple rounds*

![Manual initialization screen](./screenshots/manual_init.png)  
*Manual setup of initial cell states*

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
