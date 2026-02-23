//
// Created by logued on 23/02/2026.
//
#pragma once
#include <vector>
#include <stdexcept>
#include <span>

struct RGB {
    unsigned char r, g, b;  // values 0-255 for each colour channel

    RGB() : r(0), g(0), b(0) {}   // no-argument constructor
    RGB(unsigned char r, unsigned char g, unsigned char b)
        : r(r), g(g), b(b) {}
};

class Image {
private:
    int width, height;      // width and height in pixels
    std::vector<RGB> data;

    void check_bounds(int x, int y) const {             // private member function
        if (x < 0 || x >= width || y < 0 || y >= height)
            throw std::out_of_range("Pixel coordinate out of bounds");
    }

public:
    Image(int width, int height)
        : width(width), height(height), data(width * height) {}

    // --- 1. Bounds-checked access ---  safe access
    RGB& at(int x, int y) {
        check_bounds(x, y);
        return data[y * width + x];
    }

    const RGB& at(int x, int y) const {
        check_bounds(x, y);
        return data[y * width + x];
    }

    // --- 2. Fast operator()(x, y) --- with NO bounds checking
    RGB& operator()(int x, int y) {
        return data[y * width + x];
    }

    const RGB& operator()(int x, int y) const {
        return data[y * width + x];
    }

    // --- 3. exposing Iterators for STL compatibility ---
    auto begin()       { return data.begin(); }
    auto end()         { return data.end(); }
    auto begin() const { return data.begin(); }
    auto end()   const { return data.end(); }

    // --- 4. Row access using std::span ---
    std::span<RGB> row(int y) {
        if (y < 0 || y >= height)
            throw std::out_of_range("Row index out of bounds");
        return std::span<RGB>(&data[y * width], width);
    }

    std::span<const RGB> row(int y) const {
        if (y < 0 || y >= height)
            throw std::out_of_range("Row index out of bounds");
        return std::span<const RGB>(&data[y * width], width);
    }

    // --- Getters ---
    int getWidth()  const { return width; }
    int getHeight() const { return height; }

};
