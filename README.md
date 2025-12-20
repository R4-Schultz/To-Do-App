📝 C++ To-Do List (Console Application)

A simple command-line To-Do List application written in C++, built as a learning project to practice core C++ concepts such as file I/O, vectors, input handling, and program structure.

This project stores tasks in a .txt file so they persist between runs.

📌 Features

Load tasks from a text file
Display the current to-do list
Add new tasks
Remove tasks by index
Save tasks back to the file
Menu-driven console interface

🛠️ Technologies Used

C++ (Standard Library)
iostream
vector
string
fstream
No external libraries required.

📂 File Format

Tasks are stored one per line in a plain text file:

Buy groceries
Finish homework
Go to the gym

Empty or whitespace-only lines are ignored when loading.

▶️ How to Run
1. Compile
g++ main.cpp -o todo

2. Run
./todo

3. On Startup

You’ll be prompted to enter a filename (e.g. list.txt).
If the file exists → tasks are loaded
If the file does not exist → it is created

📋 Menu Options
(1) Print out current To-Do list
(2) Add a Task to the To-Do list
(3) Remove a Task from the To-Do list
(4) Save current To-Do list to a file
(5) Quit

🧠 Design Notes

Uses std::vector<std::string> to store tasks in memory
Uses std::getline everywhere to avoid input buffer issues
File I/O follows RAII principles (files open and close inside functions)
Tasks are saved explicitly (not auto-saved)

⚠️ Known Limitations

Minimal input validation (invalid menu input may cause crashes)
No confirmation before deleting tasks
No automatic saving on exit
Global variables used for simplicity
These are intentional tradeoffs for a learning-focused first project.

🚀 Possible Improvements

Add robust input validation
Auto-save on exit
Prevent duplicate tasks
Add task priorities or due dates
Refactor into classes (e.g., TodoList, FileManager)
Add unit tests

🎯 Learning Goals

This project was built to practice:
File parsing with std::ifstream
Writing files with std::ofstream
Vectors vs arrays
Program flow and menu loops
Debugging common C++ pitfalls
