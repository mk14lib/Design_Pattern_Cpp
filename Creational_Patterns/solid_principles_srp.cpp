#include <iostream>
#include <fstream>

using namespace std;

// Single Responsibility Principle (SRP)
class Report {
private:
    ofstream report;
    
public:
    Report() {
        report.open("reportfile.txt", ios::out | ios::app);
    }
    void generateReport() {
        cout << "Generating Reporting" << endl;
        report << "Mahesh generated this report for fun" << endl;
        report << "He felt like it be would be better to add one more line and check for more fun" << endl;
    }
    
    ~Report()
    {
        if (report.is_open())
            report.close();
    }
};

class ReportPrinter {
public:
    void printReport() {
        ifstream report;
        report.open("reportfile.txt");
        
        if (!report.is_open())
        {
            cout << "Failed to open the file" << endl;
            return;
        }
            
        string line;
        while(getline(report, line))
            cout << line << endl;
        
        report.close();
    }
};


int main()
{
    Report genReport;
    genReport.generateReport();
    
    ReportPrinter printRprt;
    printRprt.printReport();
}