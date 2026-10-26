#include "grid.h"

#include <iostream>
#include <utility>
#include <algorithm>

#ifdef  enLOG
#define LOG(x) std::cout << x << std::endl;
#else
#define LOG(x)
#endif  //enLOG


Grid::Grid(size_t width, size_t height, EdgeMode mode) 
            : _width(width), 
              _height(height), 
              _edgeMode(EdgeMode::Dead), // Normal pour l'instant
              _currentBuffer(width * height, 0),
              _nextBuffer(width * height, 0)
              {}

size_t Grid::index(size_t x, size_t y) const {
    return y * _width + x;
}

bool Grid::inBounds(int x, int y) const {
    return x >=0 && y >=0
        && static_cast<size_t>(x) < _width
        && static_cast<size_t>(y) < _height;
}

void Grid::setCell(int x, int y, bool alive){
    if(!inBounds(x,y)){
        LOG("Grid::setCell error - (x, y) not in bounds");
        return;
    }
    if(alive)
        _currentBuffer[index(x,y)] = 1;
    else
        _currentBuffer[index(x,y)] = 0;
}


size_t Grid::countAlive() const {
    size_t cptAlive = 0;
    for(int i : _currentBuffer){
        if(i == 1){
            cptAlive++;
        }
    }
    return cptAlive;
}

bool Grid::isAlive(int x, int y) const {
    if(!inBounds(x,y)){
        return false;
    }
    return _currentBuffer[index(x,y)] == 1 ? true : false;
}


void Grid::invertStateCell(int x, int y){
    if(!inBounds(x,y)){
        LOG("Grid::invertStateCell error - (x, y) not in bounds");
        return;
    }
    _currentBuffer[index(x,y)] ^= 1; //xor
}

void Grid::clear() {
    std::fill(_currentBuffer.begin(), _currentBuffer.end(), 0);
    std::fill(_nextBuffer.begin(), _nextBuffer.end(), 0);
    _nGeneration = 0;
    LOG("Grid::clear - _currentBuffer & _nextBuffer cleared !");
}

// void Grid::randomize(double aliveProbability){

// }

void Grid::step(){
    for(size_t y = 0; y < _height; y++){
        for(size_t x = 0; x < _width; x++){
            int n = countAliveNeighbors(static_cast<int>(x), static_cast<int>(y));
            bool alive = isAlive(static_cast<int>(x), static_cast<int>(y));
            bool nextState = alive ? (n == 2 || n == 3) : (n == 3);
            _nextBuffer[index(x,y)] = nextState ? 1 : 0;
        }
    }
    std::swap(_currentBuffer, _nextBuffer);
    _nGeneration++;
}

int Grid::countAliveNeighbors(int x, int y) const {
    if(!inBounds(x,y)){
        LOG("Grid::countAliveNeighbors error - (x, y) not in bounds");
        return -1;
    }
    
    int count = 0;
    for (int dy = -1; dy <= 1; ++dy)
        for (int dx = -1; dx <= 1; ++dx)
            if ((dx != 0 || dy != 0) && isAlive(x + dx, y + dy))
                count++;
    return count;
}