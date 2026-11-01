# Conway's Game of Life

A simple C++ implementation of Conway's Game of Life.

## What is the Game of Life?

The Game of Life is a cellular automaton created by the mathematician John Conway in 1970. It is a zero-player game: you set the starting state, then the game runs by itself.

The world is a grid of cells. Each cell is either alive or dead. Each cell has 8 neighbors (the cells around it). At every step, all cells change at the same time following these rules:

1. A live cell with fewer than 2 live neighbors dies (underpopulation).
2. A live cell with 2 or 3 live neighbors stays alive.
3. A live cell with more than 3 live neighbors dies (overpopulation).
4. A dead cell with exactly 3 live neighbors becomes alive (reproduction).

From these simple rules, complex patterns can appear. Some patterns stay still, some repeat in cycles, and some move across the grid.

## Build and Run

### Quick way

Two scripts are provided in the project:

- `setup.sh` installs all the dependencies.
- `run.sh` compiles the project and starts the game.

```bash
./setup.sh
./run.sh
```

If the scripts are not executable, run this first:

```bash
chmod +x setup.sh run.sh
```

### Manual way

Create a `build` folder, go inside it, then run CMake and make:

```bash
mkdir build
cd build
cmake ../
make
```

Then start the executable:

```bash
./conways_game_life_v0
```