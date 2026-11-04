# Company Management System

A Windows console application written in C++ that demonstrates object-oriented programming through a small, role-based company management workflow. Administrators manage employee records and tasks; employees can view and update their own information and see tasks assigned to them.

## Features

### Administrator

After signing in, an administrator can:

- List employees and review their salary information.
- Search for an employee by ID.
- Add, update, or delete employee records.
- Apply a bonus or deduction to an employee's salary.
- Assign a task to an employee, including a topic, description, and deadline.

### Employee

An employee can:

- View their employee details.
- Update their own information.
- View tasks assigned to their employee ID.

### Project highlights

- Separates people, employee records, tasks, screens, and menu flows into C++ classes.
- Uses role-specific console menus to expose different actions to administrators and employees.
- Includes input helpers and formatted console screens for common interactions.
- Persists employee and task records in local text files, without requiring a database service.

## Requirements

- Windows
- Visual Studio 2022 with the **Desktop development with C++** workload
- The Visual Studio C++ v143 toolset and Windows 10 SDK (as configured by the project)

## Build and run

1. Clone or download this repository on Windows.
2. Open [`Company System.sln`](Company%20System.sln) in Visual Studio.
3. Select a configuration such as **Debug** and platform **x64**.
4. Build the solution, then run the **Company System** project (for example, with **Ctrl+F5**).

The application is a console program and uses Windows console commands for clearing the screen and pausing between menus.

## Sign-in and local data

The administrator credentials currently defined in the source are:

- **ID:** `admin`
- **Password:** `ADMIN1234`

Employee accounts are read from `EmployeesFile.txt`. The application writes employee records to that file and assigned tasks to `TasksFile.txt` in its current working directory. These files are created as the application uses those features; no sample employee or task data is included in the repository. Keep the working directory consistent between runs so the program can find its data files.

> **Security note:** This is a learning/demo project, not a production HR system. The administrator credentials are hard-coded, and employee passwords and other personal information are stored in plain text. Do not use real employee data or deploy this application in a production environment.

## Project layout

- `Company System.sln` — Visual Studio solution.
- `Company System/Company System.vcxproj` — C++ application project and build settings.
- `Company System/Company System.cpp` — application entry point.
- `Company System/clsEmployee.h` and `clsEmployee.cpp` — employee model and employee operations.
- `Company System/clsTasks.h` — task assignment and display.
- `Company System/cls*Menue*.h` and `Company System/clsLogInScreen.h` — console menus and sign-in flow.
- `Company System/ProjectDescription.txt` — project class and menu notes.

## Scope

This project is a compact console-based demonstration. It does not provide a graphical interface, database-backed storage, or production-grade authentication and data protection.
