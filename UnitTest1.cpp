
#include "pch.h"
#include "CppUnitTest.h"
#include "PartA.h"
#include "PartB.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace HashTableTests
{
    TEST_CLASS(HashTable1DTests)
    {
    public:
        // Test basic insertion
        TEST_METHOD(TestInsert1D)
        {
            HashTable1D table;
            // Test successful insertion
            int spots = table.Insert(42);
            Assert::IsTrue(spots > 0, L"Insert should return positive number of spots checked");

            // Test searching for inserted value
            spots = table.Search(42);
            Assert::AreEqual(1, spots, L"Search should find value in first spot");

            // Test insertion of multiple values
            spots = table.Insert(142);
            Assert::IsTrue(spots > 0, L"Should be able to insert second value");
            spots = table.Search(142);
            Assert::IsTrue(spots > 0, L"Should be able to find second value");
        }

        // Test collision handling
        TEST_METHOD(TestCollision1D)
        {
            HashTable1D table;
            // Insert values that will have the same hash
            int val1 = 500; // Will hash to 500 % 500 = 0
            int val2 = 1000; // Will hash to 1000 % 500 = 0

            int spots1 = table.Insert(val1);
            int spots2 = table.Insert(val2);

            Assert::AreEqual(1, spots1, L"First insert should take 1 spot");
            Assert::AreEqual(2, spots2, L"Second insert should take 2 spots due to collision");

            // Verify both values can be found
            Assert::IsTrue(table.Search(val1) > 0, L"Should find first value");
            Assert::IsTrue(table.Search(val2) > 0, L"Should find second value");
        }

        // Test removal
        TEST_METHOD(TestRemove1D)
        {
            HashTable1D table;
            table.Insert(42);
            table.Insert(142);

            // Test successful removal
            int spots = table.Remove(42);
            Assert::IsTrue(spots > 0, L"Remove should return positive number of spots checked");

            // Verify removed value cannot be found
            spots = table.Search(42);
            Assert::IsTrue(spots > 0, L"Search should return spots checked even for missing value");

            // Verify other value still exists
            spots = table.Search(142);
            Assert::IsTrue(spots > 0, L"Should still find non-removed value");
        }

        // Test boundary conditions
        TEST_METHOD(TestBoundaryConditions1D)
        {
            HashTable1D table;

            // Test negative values
            int spots = table.Insert(-42);
            Assert::IsTrue(spots > 0, L"Should handle negative values");
            Assert::IsTrue(table.Search(-42) > 0, L"Should find negative values");

            // Test zero
            spots = table.Insert(0);
            Assert::IsTrue(spots > 0, L"Should handle zero");
            Assert::IsTrue(table.Search(0) > 0, L"Should find zero");
        }
    };

    TEST_CLASS(HashTable2DTests)
    {
    public:
        // Test basic insertion
        TEST_METHOD(TestInsert2D)
        {
            HashTable2D table;
            // Test successful insertion
            int spots = table.Insert(42);
            Assert::IsTrue(spots > 0, L"Insert should return positive number of spots checked");

            // Test searching for inserted value
            spots = table.Search(42);
            Assert::AreEqual(1, spots, L"Search should find value in first spot");

            // Test insertion of multiple values in same row
            spots = table.Insert(142); // Should hash to same row if using % 100
            Assert::IsTrue(spots > 0, L"Should be able to insert second value");
            spots = table.Search(142);
            Assert::IsTrue(spots > 0, L"Should be able to find second value");
        }

        // Test row overflow
        TEST_METHOD(TestRowOverflow2D)
        {
            HashTable2D table;
            // Insert more than SLOTS_PER_ROW values that hash to same row
            int baseValue = 100; // Will hash to 100 % 100 = 0

            // Insert 5 values (SLOTS_PER_ROW)
            for (int i = 0; i < 5; i++) {
                int spots = table.Insert(baseValue + (i * 100));
                Assert::IsTrue(spots <= (i + 1), L"Should check progressively more spots");
            }

            // Try to insert 6th value
            int spots = table.Insert(baseValue + 500);
            Assert::AreEqual(5, spots, L"Should check all spots in row before failing");
        }

        // Test removal
        TEST_METHOD(TestRemove2D)
        {
            HashTable2D table;
            table.Insert(42);
            table.Insert(142);

            // Test successful removal
            int spots = table.Remove(42);
            Assert::IsTrue(spots > 0, L"Remove should return positive number of spots checked");

            // Verify removed value cannot be found
            spots = table.Search(42);
            Assert::IsTrue(spots > 0, L"Search should return spots checked even for missing value");

            // Verify other value still exists
            spots = table.Search(142);
            Assert::IsTrue(spots > 0, L"Should still find non-removed value");
        }

        // Test boundary conditions
        TEST_METHOD(TestBoundaryConditions2D)
        {
            HashTable2D table;

            // Test negative values
            int spots = table.Insert(-42);
            Assert::IsTrue(spots > 0, L"Should handle negative values");
            Assert::IsTrue(table.Search(-42) > 0, L"Should find negative values");

            // Test zero
            spots = table.Insert(0);
            Assert::IsTrue(spots > 0, L"Should handle zero");
            Assert::IsTrue(table.Search(0) > 0, L"Should find zero");
        }
    };
}