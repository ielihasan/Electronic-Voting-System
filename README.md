# Electronic Voting System

A console-based Electronic Voting System developed in C++ as a first-semester project. It handles login authentication, candidate registration, and voting functionality using text file storage.

## 📌 Features
- Admin and user login
- Role-based voting (President, Vice President, etc.)
- Vote validation (prevents multiple voting)
- File-based data storage on .txt file

## 🗂️ Project Structure
- `Source.cpp` – Main source code file
- `admin.txt` – Stores admin credentials
- `login.txt` – Stores voter credentials
- `President_input.txt`, etc. – Stores votes for respective roles

## 🛠️ How to Run
1. Open `Project52.sln` in Visual Studio.
2. Build and run the project (preferably in `x64` configuration).
3. Interact with the system through the console prompts.

## 🔒 Notes
- Make sure `.txt` files are in the correct working directory.
- Clear `Already_entered_login.txt` to reset voting state.

## 📄 License
[MIT License](LICENSE)
