# **Company Management System**

## **Description**
This is a C++ Object-Oriented Programming (OOP) project that simulates a simple company management system. The system consists of two main roles: **Administrator** and **Employee**, each having their respective menus and functionality. The system operates behind a login menu, where users are directed to their respective menus based on their credentials.

## **Features**

### **Login Menu**
The system starts with a login menu.
- **Administrator**: Enters their **ID** and **password** to access the Administrator menu.
- **Employee**: Enters their **ID** and **password** to access the Employee menu.

### **Administrator Menu**
The Administrator has the following responsibilities:
- **Add Employee**: Add new employees to the system.
- **Update Employee Info**: Modify the information of existing employees.
- **Delete Employee**: Remove an employee from the system.
- **Bonus/Deduction**: Apply bonuses or deductions to employees' salaries.
- **Assign Tasks**: Assign tasks to employees.
- **View Employee Information**: View details of all employees in the system.

### **Employee Menu**
The Employee has access to the following functionality:
- **Update Personal Info**: Update their own information (e.g., contact details, address).
- **View Assigned Tasks**: View the tasks assigned to them by the administrator.

## **Structure**
- **Login System**: Checks whether the user is an Administrator or an Employee and routes them to the correct menu.
- **Administrator Functions**: Handles all employee management tasks like adding, deleting, and updating employee records.
- **Employee Functions**: Enables employees to update their personal information and view tasks.
