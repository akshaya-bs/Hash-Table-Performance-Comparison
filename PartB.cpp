#include "PartB.h"
#include <cstdlib>
#include <iostream>

// Constructor
HashTable2D::HashTable2D() {
    // Initialize all slots as unoccupied
    for (int i = 0; i < TABLE_ROWS; ++i) {
        for (int j = 0; j < SLOTS_PER_ROW; ++j) {
            occupied[i][j] = false;
            table[i][j] = 0;
        }
    }
}

// Destructor
HashTable2D::~HashTable2D() {
    // Clear the table and occupied arrays
    for (int i = 0; i < TABLE_ROWS; ++i) {
        for (int j = 0; j < SLOTS_PER_ROW; ++j) {
            occupied[i][j] = false;
            table[i][j] = 0;
        }
    }
}

// Hash function
int HashTable2D::hash(int key) const {
    return std::abs(key) % TABLE_ROWS;
}

// Insert method
int HashTable2D::Insert(int value) {
    int row = hash(value);
    int slots_checked = 0;

    // Check each slot in the row
    for (int col = 0; col < SLOTS_PER_ROW; ++col) {
        slots_checked++;

        if (!occupied[row][col]) {
            // Found an empty slot
            table[row][col] = value;
            occupied[row][col] = true;

            if (slots_checked == 1) {
                std::cout << "The value " << value << " was inserted." << std::endl;
            }
            return slots_checked;
        }
    }

    // Row is full
    std::cout << "The value " << value << " cannot be inserted." << std::endl;
    return slots_checked;
}

// Search method
int HashTable2D::Search(int value) const {
    int row = hash(value);
    int slots_checked = 0;

    // Check each slot in the row
    for (int col = 0; col < SLOTS_PER_ROW; ++col) {
        slots_checked++;

        if (occupied[row][col] && table[row][col] == value) {
            std::cout << "The value " << value << " can be found." << std::endl;
            return slots_checked;
        }
    }

    std::cout << "The value " << value << " cannot be found." << std::endl;
    return slots_checked;
}

// Remove method
int HashTable2D::Remove(int value) {
    int row = hash(value);
    int slots_checked = 0;

    // Check each slot in the row
    for (int col = 0; col < SLOTS_PER_ROW; ++col) {
        slots_checked++;

        if (occupied[row][col] && table[row][col] == value) {
            // Mark slot as unoccupied
            occupied[row][col] = false;

            // Shift remaining elements in the row
            for (int j = col; j < SLOTS_PER_ROW - 1; ++j) {
                table[row][j] = table[row][j + 1];
                occupied[row][j] = occupied[row][j + 1];
            }

            // Clear the last slot
            table[row][SLOTS_PER_ROW - 1] = 0;
            occupied[row][SLOTS_PER_ROW - 1] = false;

            std::cout << "The value " << value << " was removed." << std::endl;
            return slots_checked;
        }
    }

    std::cout << "The value " << value << " cannot be removed." << std::endl;
    return slots_checked;
}

// Print method
void HashTable2D::Print() const {
    std::cout << "Hash Table Contents:" << std::endl;
    for (int row = 0; row < TABLE_ROWS; ++row) {
        bool row_has_items = false;
        std::cout << "Row " << row << ": ";

        for (int col = 0; col < SLOTS_PER_ROW; ++col) {
            if (occupied[row][col]) {
                std::cout << table[row][col] << " ";
                row_has_items = true;
            }
        }

        if (!row_has_items) {
            std::cout << "[Empty]";
        }
        std::cout << std::endl;
    }
}