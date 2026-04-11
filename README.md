# ☕ Coffee Menu CLI (C Project)

## 📌 Description

This is a terminal-based coffee ordering application written in C.

The program allows users to:

* View a coffee menu
* Select multiple items
* Calculate the total bill

This project focuses on building a strong foundation in C programming, including memory management, input validation, and structured design.

---

## 🧠 What I Learned

* Using `struct` to model real-world data
* Safe user input handling with `fgets` and `strtol`
* Dynamic memory allocation using `malloc` and `free`
* Splitting logic into reusable functions
* Working with arrays and pointers

---

## ⚙️ Features

* Clean and readable menu display
* Input validation (prevents invalid entries)
* Multiple item selection
* Price formatting (e.g., $5.50)
* Total bill calculation

---

## ▶️ How to Run

Compile:

```bash
gcc src/main.c -o coffee      # This command is for compiling single file in C
gcc src/* -Iinclude -o coffee # This command is for compiling multiple file in C (.c & .h)
```

Run:

```bash
./coffee
```

---

## 🚀 Future Improvements

* Split code into multiple files (`.c` + `.h`)
* Add file-based menu loading
* Improve memory flexibility (dynamic strings)
* Add order history feature
* Support multiple currencies

---

## 🎯 Purpose

This project is part of my journey to:

* Learn low-level programming (C)
* Understand memory and system behavior
* Build a strong foundation for cybersecurity and systems development

---

## 👤 Author

Daniel Kazemian
