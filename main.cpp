#include "grid.h"

#include <iostream>

void printGrid(const Grid& grid) {
    std::cout << "Generation " << grid.getGeneration()
              << " - cellules vivantes : " << grid.countAlive() << "\n";
    for (size_t y = 0; y < grid.getHeight(); ++y) {
        for (size_t x = 0; x < grid.getWidth(); ++x) {
            std::cout << (grid.isAlive(static_cast<int>(x), static_cast<int>(y)) ? '#' : '.');
        }
        std::cout << "\n";
    }
    std::cout << std::endl;
}

void run(Grid& grid, int nSteps) {
    printGrid(grid);
    for (int i = 0; i < nSteps; ++i) {
        grid.step();
        printGrid(grid);
    }
}

void testBlock() {
    std::cout << "===== BLOC (doit rester stable) =====\n";
    Grid grid(10, 10);
    grid.setCell(4, 4, true);
    grid.setCell(5, 4, true);
    grid.setCell(4, 5, true);
    grid.setCell(5, 5, true);
    run(grid, 2);
}

void testBlinker() {
    std::cout << "===== CLIGNOTANT (période 2) =====\n";
    Grid grid(10, 10);
    grid.setCell(4, 5, true);
    grid.setCell(5, 5, true);
    grid.setCell(6, 5, true);
    run(grid, 3);
}

void testGlider() {
    std::cout << "===== PLANEUR (décalage en diagonale après 4 générations) =====\n";
    Grid grid(10, 10);
    grid.setCell(1, 0, true);
    grid.setCell(2, 1, true);
    grid.setCell(0, 2, true);
    grid.setCell(1, 2, true);
    grid.setCell(2, 2, true);
    run(grid, 8);
}

int main() {
    testBlock();
    testBlinker();
    testGlider();
    return 0;
}