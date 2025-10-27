# Data Structures & Algorithms - Google Interview Solutions

A comprehensive collection of coding interview solutions focusing on Google-style problems. This repository contains well-documented, tested implementations of various algorithms and data structures commonly asked in technical interviews.

## 🚀 Repository Overview

This repository contains **10 complete coding solutions** with over **760 lines** of well-documented C++ code, each solving a different algorithmic challenge that demonstrates various problem-solving techniques and data structure applications.

## 📁 Solutions Included

### 1. **Logger Rate Limiter** 📝
- **Problem**: Implement a rate limiter for logging messages
- **Technique**: Hash map with timestamp tracking
- **Time Complexity**: O(1) per message
- **Key Learning**: Efficient rate limiting algorithms

### 2. **My Calendar** 📅
- **Problem**: Design a calendar system with conflict detection
- **Technique**: Interval tree / Binary search
- **Time Complexity**: O(log n) per booking
- **Key Learning**: Interval scheduling and conflict resolution

### 3. **Race Car** 🏎️
- **Problem**: Find minimum steps for a race car to reach target
- **Technique**: Dynamic Programming + BFS
- **Time Complexity**: O(target * log(target))
- **Key Learning**: State space exploration with DP

### 4. **Shortest Path Grid** 🗺️
- **Problem**: Find shortest path in a grid with obstacles
- **Technique**: Breadth-First Search (BFS)
- **Time Complexity**: O(m * n)
- **Key Learning**: Grid traversal and pathfinding

### 5. **Step by Step Directions** 🧭
- **Problem**: Generate directions between nodes in binary tree
- **Technique**: Tree traversal (DFS) + LCA
- **Time Complexity**: O(n)
- **Key Learning**: Tree algorithms and path reconstruction

### 6. **Two Sum** ➕
- **Problem**: Find two numbers that add up to target
- **Technique**: Hash map
- **Time Complexity**: O(n)
- **Key Learning**: Classic hash map optimization

### 7. **Stock Price Fluctuation** 📈
- **Problem**: Track stock prices with real-time updates
- **Technique**: Heap (Priority Queue) + Hash map
- **Time Complexity**: O(log n) per update
- **Key Learning**: Heap operations and data structure design

### 8. **Find Leaves of Binary Tree** 🍃
- **Problem**: Collect tree leaves level by level
- **Technique**: Depth-First Search (DFS) with height calculation
- **Time Complexity**: O(n)
- **Key Learning**: Tree traversal and height-based grouping

### 9. **Roman to Integer** 🔢
- **Problem**: Convert Roman numerals to integers
- **Technique**: String parsing with subtraction rules
- **Time Complexity**: O(n)
- **Key Learning**: String manipulation and parsing

### 10. **Longest String Chain** 🔗
- **Problem**: Find longest word chain where each word differs by one character
- **Technique**: Dynamic Programming + Sorting
- **Time Complexity**: O(n * m²) where m is average word length
- **Key Learning**: DP with string manipulation

## 🛠️ How to Use

### Prerequisites
- C++ compiler (g++ recommended)
- Git

### Running the Solutions

Each solution is self-contained with its own folder:

```bash
# Clone the repository
git clone https://github.com/sa1136/Data-Structures.git
cd Data-Structures

# Navigate to any solution folder
cd "LOGGER RATE LIMITER"

# Compile and run
g++ -o logger Logger_rate_limiter.cpp
./logger
```

### Example: Running Stock Price Fluctuation
```bash
cd "STOCK PRICE FLUCTUATION"
g++ -o stock_price Stock_price_fluctuation.cpp
./stock_price
```

## 📊 Algorithm Categories

| Category | Problems | Techniques Used |
|----------|----------|-----------------|
| **Data Structures** | Stock Price Fluctuation, Logger Rate Limiter | Heap, Hash Map |
| **Tree Algorithms** | Find Leaves, Step by Step Directions | DFS, Tree Traversal |
| **Dynamic Programming** | Race Car, Longest String Chain | DP, Memoization |
| **Graph Algorithms** | Shortest Path Grid | BFS, Grid Traversal |
| **String Manipulation** | Roman to Integer, Longest String Chain | String Parsing, DP |
| **Scheduling** | My Calendar | Interval Trees, Binary Search |

## 🎯 Interview Preparation

This repository is perfect for:
- **Google-style interview preparation**
- **Algorithm and data structure practice**
- **Understanding complex problem-solving patterns**
- **Learning efficient implementation techniques**

## 📈 Complexity Analysis

Each solution includes:
- ✅ **Time Complexity** analysis
- ✅ **Space Complexity** analysis  
- ✅ **Multiple test cases**
- ✅ **Edge case handling**
- ✅ **Clear explanations**

## 🔧 Code Quality

- **Well-documented** with clear comments
- **Tested** with comprehensive test cases
- **Optimized** for time and space efficiency
- **Production-ready** implementations
- **Follows** C++ best practices

## 📝 Contributing

Feel free to:
- Add more test cases
- Suggest optimizations
- Report bugs
- Contribute new solutions

## 📚 Learning Resources

For deeper understanding of these algorithms:
- [LeetCode](https://leetcode.com/) - Practice platform
- [GeeksforGeeks](https://www.geeksforgeeks.org/) - Algorithm explanations
- [Cracking the Coding Interview](https://www.crackingthecodinginterview.com/) - Interview prep

## 🏆 Author

**sa1136** - Software Engineer passionate about algorithms and data structures

---

⭐ **Star this repository** if you found it helpful for your interview preparation!

## 📄 License

This project is open source and available under the [MIT License](LICENSE).