#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
#include "clsEmployee.h"
#include "utilLibrary.h"

using namespace std;

class clsTask : public clsEmployee {

private:
    string _ID;
    string _Topic;
    string _Body;
    string _DeadLine;

    // Convert line from file to clsTask object
    static clsTask _ConvertLinetoTasks(string Line, string Seperator = "#//#") {

        vector<string> vTaskData = utilLibrary::Split(Line, Seperator);

        if (vTaskData.size() < 4) {  // Adjusted size to match the number of fields for clsTask
            throw std::length_error("Insufficient data in line, unable to create clsTask object.");
        }

        return clsTask(
            vTaskData[0],  // Id 
            vTaskData[1],  // Topic
            vTaskData[2],  // Body
            vTaskData[3]   // Deadline
        );
    }

    // Convert clsTask object to line for saving to file
    static string _ConvertObjectToLine(const clsTask& Task, string Seperator = "#//#") {

        string stTaskRecord = "";
        stTaskRecord += Task._ID + Seperator;
        stTaskRecord += Task._Topic + Seperator;
        stTaskRecord += Task._Body + Seperator;
        stTaskRecord += Task._DeadLine;

        return stTaskRecord;
    }

    // Load all tasks from the file into a vector
    static vector<clsTask> _LoadDataFromFile() {

        vector<clsTask> vTasks;
        fstream MyFile;
        MyFile.open("TasksFile.txt", ios::in); // Read mode

        if (MyFile.is_open()) {
            string Line;
            while (getline(MyFile, Line)) {
                clsTask Task = _ConvertLinetoTasks(Line);
                vTasks.push_back(Task);
            }
            MyFile.close();
        }
        return vTasks;
    }

    // Add a task line to the file
    static void _AddDataLineToTasks(const string& stDataLine) {

        fstream MyFile;
        MyFile.open("TasksFile.txt", ios::out | ios::app);  // Append mode

        if (MyFile.is_open()) {
            MyFile << stDataLine << endl;
            MyFile.close();
        }
    }

    // Read task data from the user
    static void ReadTaskData(clsTask& Task) {

        cout << "\nEnter The Topic of the Task: ";
        Task._Topic = utilLibrary::ReadString();

        cout << "\nEnter The Body of the Task: ";
        Task._Body = utilLibrary::ReadString();

        cout << "\nEnter The Deadline of the Task: ";
        Task._DeadLine = utilLibrary::ReadString();
    }

public:
    // Constructors
    clsTask() = default;

    clsTask(string ID, string Topic, string Body, string DeadLine) {

        _ID = ID;
        _Topic = Topic;
        _Body = Body;
        _DeadLine = DeadLine;
    }

    // ID Getter
    string GetID() {
        return _ID;
    }
    __declspec(property(get = GetID)) string ID;


    // Topic getter and setter
    void SetTopic(string Topic) {
        _Topic = Topic;
    }
    string GetTopic() const {
        return _Topic;
    }
    __declspec(property(get = GetTopic, put = SetTopic)) string Topic;


    // Body getter and setter
    void SetBody(string Body) {
        _Body = Body;
    }
    string GetBody() const {
        return _Body;
    }
    __declspec(property(get = GetBody, put = SetBody)) string Body;


    // DeadLine getter and setter
    void SetDeadLine(string DeadLine) {
        _DeadLine = DeadLine;
    }
    string GetDeadLine() const {
        return _DeadLine;
    }
    __declspec(property(get = GetDeadLine, put = SetDeadLine)) string DeadLine;


    // Print task in a formatted way
    void PrintTaskFormat() const {
        cout << "Dear Employee: " << _ID << endl;
        cout << "                              " << _Topic << endl;
        cout << _Body << endl;
        cout << "                                            Deadline: " << _DeadLine << endl;
        cout << "================================================================================\n";
    }

    // Send a task to an employee
    void SendTask() {
        string Id;
        cout << "\nPlease Enter Employee's ID: ";
        Id = utilLibrary::ReadString();

        while (!clsEmployee::IsIdExist(Id, "EmployeesFile.txt")) {
            cout << "\nEmployee ID doesn't exist, please choose another one: ";
            Id = utilLibrary::ReadString();
        }

        clsTask NewTask(Id, "", "", "");

        ReadTaskData(NewTask);

        _AddDataLineToTasks(_ConvertObjectToLine(NewTask));

        NewTask.PrintTaskFormat();
    }

    //Get Empty Task object
    static clsTask _GetEmptyTask()
    {
        return clsTask("", "", "","");
    }

    //Find Emplyee
    static clsTask FindTask(string Id, string File)
    {

        fstream TasksFile;
        TasksFile.open(File, ios::in); //read Mode

        if (TasksFile.is_open())
        {
            string Line;
            while (getline(TasksFile, Line))
            {
                clsTask Task = _ConvertLinetoTasks(Line);
                if (Task.ID == Id)
                {
                    Task.PrintTaskFormat();
                }

            }

            TasksFile.close();

        }

        return _GetEmptyTask();
    }

    void SeeTask() {

        string Id;
        cout << "\nPlease Enter Employee's ID: ";
        Id = utilLibrary::ReadString();

        while (!clsEmployee::IsIdExist(Id, "EmployeesFile.txt")) {
            cout << "\nEmployee ID doesn't exist, please choose another one: ";
            Id = utilLibrary::ReadString();
        }

        clsTask Task = FindTask(Id,"TasksFile.txt");

    }


};
