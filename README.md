# ⚽ Egyptian League Management System (C++)
> **An Advanced Sports Management Application built with C++ using Dynamic Linked Lists and OOP Principles.**

<div align="center">

![C++](https://img.shields.io/badge/C++-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![Data Structures](https://img.shields.io/badge/Data_Structures-Linked_Lists-FFD700?style=for-the-badge)
![Logic](https://img.shields.io/badge/Logic-Algorithms-orange?style=for-the-badge)

</div>

---

### 🌟 Project Overview
This is a comprehensive **League Management System** developed in C++. Unlike basic applications, this system utilizes **Dynamic Memory Management** and **Linked Lists** to handle data for football teams and players. It is designed to demonstrate efficient data manipulation, searching, and sorting algorithms in a real-world scenario.

---

### 🚀 Key Technical Features
* 🔗 **Linked List Architecture:** Custom implementation of `TeamNode` and `PlayerNode` for dynamic data storage.
* 🛠️ **Full CRUD Operations:** Support for adding, searching, updating, and removing teams and players.
* 📈 **Advanced Sorting (Bonus):**
    * Sort players within a team by **Salary (Descending)**.
    * Sort teams based on the **Average Age** of their players.
* 🗑️ **Cascading Deletion:** Deleting a team automatically triggers a cleanup of all its associated players to maintain data integrity.
* 💻 **Interactive CLI:** A robust command-line interface with a user-friendly menu system.

---

### 🛠️ Programming Concepts Used
| Concept | Description |
| :--- | :--- |
| **OOP** | Encapsulating the league logic within the `LeagueSystem` class. |
| **Structs** | Defining complex data types for Nodes. |
| **Pointers** | Efficiently navigating through linked data structures. |
| **Bubble Sort** | Implemented for custom sorting of salaries and average ages. |
| **Memory Mgmt** | Proper use of `new` and `delete` to prevent memory leaks. |

---

### 📂 Logic Flow & Structure
```text
├── TeamNode (Struct)    # Contains: ID, Name, President, Next Pointer
├── PlayerNode (Struct)  # Contains: ID, Name, Team, Position, Age, Salary, Next Pointer
└── LeagueSystem (Class) # Core logic for managing the League
    ├── Team Logic       # Add, Display, Search, Remove
    ├── Player Logic     # Add, Display, Search, Update, Remove
    └── Bonus Analytics  # Salary Sorting, Avg Age Sorting
