#include <iostream>
#include <cstdlib>
#include <ctime>
#include "PartA.h" // HashTable1D
#include "PartB.h" // HashTable2D

int main() {
    // Step 1: Generate 100 unique random integers between 1 and 1000
    int dataset[100];
    bool used[1001] = { false }; // Array to ensure unique values
    std::srand(static_cast<unsigned int>(std::time(nullptr))); // Seed for random number generation

    for (int i = 0; i < 100; ++i) {
        int value;
        do {
            value = std::rand() % 1000 + 1;
        } while (used[value]);
        used[value] = true;
        dataset[i] = value;
    }

    // Step 2: Create hash table instances
    HashTable1D hashTable1D;
    HashTable2D hashTable2D;

    // Step 3a: Initial Insertion
    int spotsChecked1D = 0, spotsChecked2D = 0;
    for (int i = 0; i < 50; ++i) {
        spotsChecked1D += hashTable1D.Insert(dataset[i]);
        spotsChecked2D += hashTable2D.Insert(dataset[i]);
    }
    std::cout << "Initial Insertion Results:" << std::endl;
    std::cout << "1D Hash Table: Total spots checked = " << spotsChecked1D << std::endl;
    std::cout << "2D Hash Table: Total spots checked = " << spotsChecked2D << std::endl;

    // Step 3b: Selective Removal (x % 7 == 0)
    int removalSpots1D = 0, removalSpots2D = 0;
    for (int i = 0; i < 50; ++i) {
        if (dataset[i] % 7 == 0) {
            removalSpots1D += hashTable1D.Remove(dataset[i]);
            removalSpots2D += hashTable2D.Remove(dataset[i]);
        }
    }
    std::cout << "Selective Removal Results:" << std::endl;
    std::cout << "1D Hash Table: Total spots checked = " << removalSpots1D << std::endl;
    std::cout << "2D Hash Table: Total spots checked = " << removalSpots2D << std::endl;

    // Step 3c: Second Insertion
    int secondSpots1D = 0, secondSpots2D = 0;
    for (int i = 50; i < 100; ++i) {
        secondSpots1D += hashTable1D.Insert(dataset[i]);
        secondSpots2D += hashTable2D.Insert(dataset[i]);
    }
    std::cout << "Second Insertion Results:" << std::endl;
    std::cout << "1D Hash Table: Total spots checked = " << secondSpots1D << std::endl;
    std::cout << "2D Hash Table: Total spots checked = " << secondSpots2D << std::endl;

    // Step 3d: Search Operation (x % 9 == 0)
    int searchSpots1D = 0, searchSpots2D = 0;
    for (int i = 0; i < 100; ++i) {
        if (dataset[i] % 9 == 0) {
            searchSpots1D += hashTable1D.Search(dataset[i]);
            searchSpots2D += hashTable2D.Search(dataset[i]);
        }
    }
    std::cout << "Search Operation Results:" << std::endl;
    std::cout << "1D Hash Table: Total spots checked = " << searchSpots1D << std::endl;
    std::cout << "2D Hash Table: Total spots checked = " << searchSpots2D << std::endl;

    return 0;
}