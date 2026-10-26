#ifndef __GRID__H__
#define __GRID__H__

#include <cstddef>
#include <cstdint>
#include <vector>

enum class EdgeMode{
    Dead, // Every out cell is dead
    Torus // The edges connect (modulo)
};

class Grid{
    private: 
        size_t _width, _height, _nGeneration = 0;
        EdgeMode _edgeMode;

        // Two buffers are allocated. We read the currentBuffer and we write in the nextBuffer
        std::vector<std::uint8_t> _currentBuffer;
        std::vector<std::uint8_t> _nextBuffer;

        size_t index(size_t x, size_t y) const; //Convert (x, y) in an index inside the 1D vector

        bool inBounds(int x, int y) const; // Check if (x, y) is inside the grid

    public:
        Grid(size_t width, size_t height, EdgeMode mode = EdgeMode::Dead); // Default constructor, EdgeMode = dead by default

        size_t getWidth() const; 
        size_t getHeight() const;
        size_t countAlive() const;
        size_t getGeneration() const;
        EdgeMode getEdgeMode() const;

        bool isAlive(int x, int y) const; // Check if a cell is alive or no.
        void setCell(int x, int y, bool alive); // Set a cell alive or dead
        void invertStateCell(int x, int y);

        void clear();
        //void randomize(double aliveProbability = 0.25);

        void step(); // Process the next generation (double buffer + swap)

        int countAliveNeighbors(int x, int y) const; // Count the 8 living neighbors, taking into account the EdgeMode
};

inline size_t Grid::getWidth() const {
    return _width;
}

inline size_t Grid::getHeight() const {
    return _height;
}

inline size_t Grid::getGeneration() const {
    return _nGeneration;
}

inline EdgeMode Grid::getEdgeMode() const {
    return _edgeMode;
}

#endif  //!__GRID__H__