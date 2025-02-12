# STUDENT DORM ADMINISTRATION SYSTEM

## Overview
This project is a **STUDENT DORM ADMINISTRATION SYSTEM**, developed using the **C programming language**. It helps manage different aspects of shared living, including **student information, room allocations, payments, and maintenance records**.

## Features
- **Student Management**: Add, update, delete, and view student details.
- **Room Management**: Assign, manage, and track room allocations.
- **Payment Management**: Handle payment records for shared expenses.
- **Maintenance Tracking**: Log and monitor maintenance requests.
- **File Handling**: Store data securely using `.dat` files.
- **Menu-Driven Interface**: Easy navigation through different sections.

## Project Structure
```
project/
├── vscode/                 # VS Code configuration files
├── src/                    # Source code files
│   ├── filehandler.c       # File handling functions
│   ├── library.c           # Utility functions
│   ├── main_menu.c         # Main menu logic
│   ├── main.c              # Program entry point
│   ├── maintenance.c       # Maintenance module
│   ├── payment.c           # Payment module
│   ├── room.c              # Room management module
│   ├── student.c           # Student management module
├── include/                # Header files
│   ├── filehandler.h       
│   ├── library.h           
│   ├── main_menu.h         
│   ├── maintenance.h       
│   ├── payment.h           
│   ├── room.h              
│   ├── student.h           
├── data/                   # Data storage files
│   ├── maintenance.dat     
│   ├── payment.dat         
│   ├── rooms.dat           
│   ├── student.dat         
│   ├── students.dat        
│   ├── user.dat            
├── .gitignore              # Git ignored files
└── README.md               # Project documentation
```

## Installation & Usage
### Prerequisites
- **GCC Compiler** (for compiling C programs)
- **VS Code or any C IDE** (for development)

### Compilation
1. Open a terminal in the project root directory.
2. Compile the source code using the following command:
   ```sh
   gcc main.c library.c main_menu.c -o main.exe -I../include
   ```
3. Run the executable:
   ```sh
   ./main.exe
   ```

## Contribution Guidelines
- Fork the repository.
- Create a new branch for your feature or bug fix.
- Commit meaningful changes with clear commit messages.
- Submit a pull request for review.

## License
This project is **open-source** under the **MIT License**.

## Authors
Developed by **Arafat and Team**.

---
### Note:
- Make sure data files exist before running the program.
- Future improvements can include **GUI integration, database storage, and multi-user access**.

Feel free to contribute and improve the system! 🚀

