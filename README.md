# Conway's Game of Life CLI

This project is a simple implementation of Conway's Game of Life in C++ that runs in the command line interface (CLI). When I initially looked into this project I figured it would be more challenging to code, but in reality it took me a grand total of 30 minutes after I read the rules of the game.

## How to Build

To build the project, you need a C++ compiler. You can use `g++` if you are on a Unix-like system.

```sh
g++ -o game_of_life src/main.cpp
```

## How to Run

After building the project, you can run the executable. The program will prompt you to set the number of iterations and the initial grid configuration.

```sh
./game_of_life
```

## Grid Configurations

When prompted to set the grid configuration, you can choose from the following options:

- `0`: A small glider pattern
- `1`: A horizontal line of three cells
- `2`: A larger block of cells

## Example

```sh
Set the number of iterations: 100
Set grid configuration: 0
```

This will run the Game of Life for 100 iterations starting with a glider pattern.

## Features

- Customizable number of iterations
- Multiple initial grid configurations
- Detects stagnant configurations and exits early

## License

This project is licensed under the MIT License.