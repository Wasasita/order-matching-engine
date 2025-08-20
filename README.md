# High-Performance Order Matching Engine (C++)

## Overview
This project implements a simplified **Order Matching Engine** in **C++**, simulating the core behavior of an exchange system. It supports **price-time priority**, **partial fills**, and real-time order matching.  
The project demonstrates **systems programming principles**, **thread safety**, and **performance-focused data structures**—essential for building high-frequency trading systems.

---

## Features
- **Interactive Order Entry**  
  - Enter BUY/SELL orders via terminal in real time.
- **Order Book with Price-Time Priority**  
  - Highest bid and lowest ask matched first; ties resolved by timestamp.
- **Partial Fill Handling**  
  - Splits large orders across multiple matches.
- **Thread-Safe Design**  
  - Uses `std::mutex` for safe concurrent updates (future multithreading ready).
- **Extensible**  
  - Can be enhanced for **multithreading**, **network sockets**, and **latency benchmarking**.

---

## Project Structure
order-matching-engine/
├── src/
│ ├── main.cpp # Interactive order entry & program entry point
│ ├── Order.h # Order struct definition
│ ├── OrderBook.h # OrderBook class header
│ ├── OrderBook.cpp # OrderBook implementation (matching logic)
├── tests/
│ ├── test_case1.cpp # Basic match test
│ ├── test_case2.cpp # No match scenario
│ ├── test_case3.cpp # Partial fill scenario
│ ├── run_all_tests.sh # Script to build & run all tests
└── README.md

## Build
```bash
g++ -std=c++17 src/main.cpp src/OrderBook.cpp -o engine
./engine
```
## How To Use
When you run the engine, you’ll see:
```
Order Matching Engine Started
Enter orders in format: BUY/SELL price quantity (or type EXIT to quit)
```
example input:
```bash
BUY 101.5 10
SELL 100.5 5
SELL 101.0 5
EXIT
```
example output:
```
Trade executed: 5 @ 100.5
Trade executed: 5 @ 101
```
>


## Run Tests
```bash
cd tests
./run_all_tests.sh
```

## Example Output
```
Running all test cases...
Trade executed: 5 @ 100.5
[TEST 1 PASSED] Simple Buy/Sell match
[TEST 2 PASSED] No match when prices don't cross
Trade executed: 10 @ 100
[TEST 3 PASSED] Partial fill handled
Trade executed: 5 @ 100.5
Trade executed: 5 @ 101
[TEST 4 PASSED] Example input scenario
All tests completed.
```
