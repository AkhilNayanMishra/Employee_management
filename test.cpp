#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <string>
#include <numeric>  // For std::accumulate

using namespace std;

struct Employee {
    int id;
    string name;
    double salary;
};

void displayEmployee(const Employee &emp) {
    cout << "ID: " << emp.id << ", Name: " << emp.name << ", Salary: " << emp.salary << endl;
}

int main() {
    vector<Employee> employees = {
        {101, "Akhil", 100000},
        {102, "Nayan", 700000},
        {103, "Mishra", 900000},
        {104, "Rimjhim", 800000},
        {105, "Rahul", 600000}
    };

    sort(employees.begin(), employees.end(), [](const Employee &e1, const Employee &e2) {
        return e1.salary < e2.salary;
    });
    cout << "Employees sorted by salary:\n";
    for_each(employees.begin(), employees.end(), displayEmployee);

    vector<Employee> highEarners;
    copy_if(
        employees.begin(),
        employees.end(),
        back_inserter(highEarners),
        [](const Employee& e) {
            return e.salary > 500000;
        }
    );
    cout << "\nEmployees who are high earners:\n";
    for_each(highEarners.begin(), highEarners.end(), displayEmployee);

    double totalSalary = accumulate(employees.begin(), employees.end(), 0.0, [](double sum, const Employee& e) {
        return sum + e.salary;
    });
    double avgSalary = totalSalary / employees.size();
    cout << "\nTotal Salary: " << totalSalary << ", Average Salary: " << avgSalary << endl;

    auto highestPaid = max_element(employees.begin(), employees.end(), [](const Employee& e1, const Employee& e2) {
        return e1.salary < e2.salary;
    });

    if (highestPaid != employees.end()) {
        cout << "\nHighest Paid Employee:\n";
        displayEmployee(*highestPaid);
    }

    return 0;
}
