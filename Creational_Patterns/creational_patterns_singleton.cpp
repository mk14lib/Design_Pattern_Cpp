#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Logger {
    private:
    static Logger* instance;
    ofstream logfile;
    
    Logger() {
        cout << "Logger Initialized!" << endl;
        logfile.open("logfile.txt", ios::out | ios::app);
    }
    
    Logger(const Logger&) = delete;
    Logger operator=(const Logger&) = delete;
    
    public:
    static Logger& getInstance()
    {
        if (instance == nullptr)
            instance = new Logger();
        return *instance;
    }
    
    void log(const string& message)
    {
        logfile << message << endl;
    }
    
    ~Logger()
    {
        if (logfile.is_open())
            logfile.close();
    }
};

Logger* Logger::instance = nullptr;

int main()
{
    Logger& debugL = Logger::getInstance();
    debugL.log("[DEBUG] Application Started");
    debugL.log("[DEBUG] Application Processing");
    debugL.log("[DEBUG] Application Ended");
    
    Logger& customL = Logger::getInstance();
    customL.log("[Custom] Application Started");
    customL.log("[Custom] Application Processing");
    customL.log("[Custom] Application Ended");
    
    (&debugL == &customL) ? \
    cout << "Both are same instances of the class" << endl : \
    cout << "Both are different instances of the class" << endl;
    

    return 0;
}