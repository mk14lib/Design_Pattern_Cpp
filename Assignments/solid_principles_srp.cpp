#include <iostream>
#include <fstream>
using namespace std;

typedef enum {
    Jan = 31,
    Feb = 28,
    Mar = 31,
    Apr = 30,
    May = 31,
    Jun = 30,
    Jul = 31,
    Aug = 31,
    Sep = 30,
    Oct = 31,
    Nov = 30,
    Dec = 31,
} Month;

class Employee {
public:
    string name, id, department;
    int salary;
    
    Employee(const string& name, const string& id, const string& department, int salary) 
        : name(name), id(id), department(department), salary(salary) {}
};

class SalaryCalculator {
    Employee employee;
    
public:
    SalaryCalculator(const Employee& emp) : employee(emp) {}
        
    int calculateMonthlySalary(Month month)
    {
        return employee.salary * (month)/365;
    }
};

class ReportGenerator
{
    Employee employee;
    SalaryCalculator salary;
    
public:
    ReportGenerator(const Employee& emp, const SalaryCalculator& sal) : employee(emp), salary(sal) {}
    
    string generateReport()
    {
        string result = "Employee : " + employee.name + "\nID       : " + employee.id + "\n";
        result += "Monthly Wise Salary Report\n";
        result += "--------------------------\n";
        result += "   January   : " + to_string(salary.calculateMonthlySalary(Month::Jan)) + "\n";
        result += "   February  : " + to_string(salary.calculateMonthlySalary(Month::Feb)) + "\n";
        result += "   March     : " + to_string(salary.calculateMonthlySalary(Month::Mar)) + "\n";
        result += "   April     : " + to_string(salary.calculateMonthlySalary(Month::Apr)) + "\n";
        result += "   May       : " + to_string(salary.calculateMonthlySalary(Month::May)) + "\n";
        result += "   June      : " + to_string(salary.calculateMonthlySalary(Month::Jun)) + "\n";
        result += "   July      : " + to_string(salary.calculateMonthlySalary(Month::Jul)) + "\n";
        result += "   August    : " + to_string(salary.calculateMonthlySalary(Month::Aug)) + "\n";
        result += "   September : " + to_string(salary.calculateMonthlySalary(Month::Sep)) + "\n";
        result += "   October   : " + to_string(salary.calculateMonthlySalary(Month::Oct)) + "\n";
        result += "   November  : " + to_string(salary.calculateMonthlySalary(Month::Nov)) + "\n";
        result += "   December  : " + to_string(salary.calculateMonthlySalary(Month::Dec)) + "\n";
        result += "--------------------------\n";
        return result;
    }   
};

class FileStorage
{
    ReportGenerator report;
    
public:
    FileStorage(const ReportGenerator& repo) : report(repo) {}
    
    void save(string filename)
    {
        ofstream ofs(filename);
        ofs << report.generateReport() << endl;
        ofs.close();
    }
};

class EmailNotifier {
    Employee emp;
    
public:
    EmailNotifier(const Employee& employee) : emp(employee) {}
    
    void sendEmail()
    {
        cout << "Email sent to " << emp.name << "!" << endl;
    }
};

int main()
{
    Employee emp("Harsha", "ad0123", "home", 600000);
    SalaryCalculator salary(emp);
    ReportGenerator report(emp, salary);
    FileStorage fs(report);
    EmailNotifier mailer(emp);
    
    cout << "Current Month Salary : " << salary.calculateMonthlySalary(Month::Mar) << endl;
    fs.save("test.txt");
    mailer.sendEmail();
    
    return 0;
}