#include <iostream>
#include <vector>
#include <unistd.h>

const int WIDTH = 60;
const int HEIGHT = 20;

void printGrid(const std::vector<std::vector<bool> >& grid, int iteration) {
    std::cout << "Iteration: " << iteration << "\n";
    std::cout << '+';
    for (int x = 0; x < WIDTH; ++x) {
        std::cout << '-';
    }
    std::cout << "+\n";

    for (int y = 0; y < HEIGHT; ++y) {
        std::cout << '|';
        for (int x = 0; x < WIDTH; ++x) {
            std::cout << (grid[y][x] ? 'O' : ' ');
        }
        std::cout << "|\n";
    }

    std::cout << '+';
    for (int x = 0; x < WIDTH; ++x) {
        std::cout << '-';
    }
    std::cout << "+\n";
}

int countNeighbors(const std::vector<std::vector<bool> >& grid, int x, int y) {
    int count = 0;
    for (int i = -1; i <= 1; ++i) {
        for (int j = -1; j <= 1; ++j) {
            if (i == 0 && j == 0) continue;
            int nx = x + i;
            int ny = y + j;
            if (nx >= 0 && nx < WIDTH && ny >= 0 && ny < HEIGHT) {
                count += grid[ny][nx];
            }
        }
    }
    return count;
}

void updateGrid(std::vector<std::vector<bool> >& grid, bool& updated) {
    std::vector<std::vector<bool> > newGrid = grid;
    updated = false;
    for (int y = 0; y < HEIGHT; ++y) {
        for (int x = 0; x < WIDTH; ++x) {
            int neighbors = countNeighbors(grid, x, y);
            if (grid[y][x]) {
                newGrid[y][x] = (neighbors == 2 || neighbors == 3);
            } else {
                newGrid[y][x] = (neighbors == 3);
            }
            if (newGrid[y][x] != grid[y][x]) {
                updated = true;
            }
        }
    }
    grid = newGrid;
}

int main() {
    std::vector<std::vector<bool> > grid(HEIGHT, std::vector<bool>(WIDTH, false));
    int iterations;
    int config;

    std::cout << "Set the number of iterations: ";
    std::cin >> iterations;
    std::cout << "Set grid configuration: ";
    std::cin >> config;
    
    if(config == 0){
        grid[1][2] = true;
        grid[2][3] = true;
        grid[3][1] = true;
        grid[3][2] = true;
        grid[3][3] = true;
    } else if (config == 1) {
        grid[1][1] = true;
        grid[1][2] = true;
        grid[1][3] = true;
    } else {
        grid[1][1] = true;
        grid[1][2] = true;
        grid[1][3] = true;
        grid[2][1] = true;
        grid[2][2] = true;
        grid[2][3] = true;
        grid[3][1] = true;
        grid[3][2] = true;
        grid[3][3] = true;
    }

    int currentIteration = 0;
    int stagnantIterations = 0;
    bool updated = true;

    while (iterations >= 0) {
        std::cout << "\033[H\033[J";
        printGrid(grid, currentIteration);
        updateGrid(grid, updated);
        usleep(50000);
        --iterations;
        ++currentIteration;
        if (!updated) {
            ++stagnantIterations;
            if (stagnantIterations >= 5) {
                std::cout << "Stagnant configuration detected. Exiting...\n";
                break;
            }
        } else {
            stagnantIterations = 0;
        }
    }
    return 0;
}
