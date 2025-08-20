#!/bin/bash
echo "Running all test cases..."
g++ -std=c++17 ../src/OrderBook.cpp test_case1.cpp -o test1 && ./test1
g++ -std=c++17 ../src/OrderBook.cpp test_case2.cpp -o test2 && ./test2
g++ -std=c++17 ../src/OrderBook.cpp test_case3.cpp -o test3 && ./test3
g++ -std=c++17 ../src/OrderBook.cpp test_case4.cpp -o test4 && ./test4
echo "All tests completed."
