#include <iostream>
#include <fstream>
#include <string>

int writeFile() {
  int numEmployees;
  cout << "Enter the number of employees: ";
  cin >> numEmployees;

  ofstream outFile("employee.txt");
  if (!outFile) {
    cerr << "Error: Unable to open file for writing." << endl;
    return 0;
  }

  outFile << numEmployees << endl;

  for (int i = 0; i < numEmployees; i++) {
    int employeeID;
    string employeeName, departmentName;
    double salary;

    cout << "Enter details of employee " << i + 1 << endl;
    cout << "Employee ID: ";
    cin >> employeeID;
    cout << "Employee Name: ";
    cin >> employeeName;
    cout << "Department Name: ";
    cin >> departmentName;
    cout << "Salary: ";
    cin >> salary;

    outFile << eployeeID << " " << eployeeName << " " << departmentName << " " << salary << endl;
  }

  outFile.close();

  return numEmployees;
}

int readFile() {
  ifstream inFile("employee.txt");
  if (!inFile) {
    cerr << "Error: Unable to open file for reading." << endl;
    return 0;
  }

  int numEmployees;
  cout << "ID \t\t Name \t Salary" << endl;

  double totalSalary = 0;
  for(int i = 0; i < numEmployees; i++) {
    int employeeID;
    string employeeName, departmentName;
    double salary;

    inFile >> employeeID >> employeeName >> departmentName >> salary;
    cout << employeeID << " \t " << employeeName << " \t " << departmentName << " 
      t " << salary << endl;
    totalSalary += salary;
  }

  double averageSalary = totalSalary / numEmployees;
  cout << "Total: " << totalSalary << " Average: " << averageSalary << endl;
  inFile.close();
  return numEmployees;
}
}
