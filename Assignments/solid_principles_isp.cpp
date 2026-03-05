#include <iostream>
#include <exception>
using namespace std;

/**
 * PROBLEM: Interface Segregation Principle (ISP) Violation
 *
 * The SmartDevice interface is a "fat interface" that contains methods for
 * ALL types of smart devices (lights, thermostats, locks, cameras, etc.).
 * This violates ISP which states: "Clients should not be forced to depend on
 * interfaces they do not use."
 *
 * Consequences of this violation:
 * 1. CODE BLOAT: Implementing classes must provide empty implementations
 *    for methods they don't need (see SmartLight lines 40-48)
 * 2. MAINTENANCE BURDEN: Any change to the interface requires updates to
 *    ALL implementing classes, even those that don't use the changed methods
 * 3. CONFUSION: Users might call methods like lock() or startRecording()
 *    on a SmartLight, expecting them to work, but they do nothing
 * 4. BROKEN CONTRACT: Empty implementations violate the implied contract
 *    of the interface methods
 * 5. TESTING OVERHEAD: Must test methods that do nothing
 * 6. POOR DESIGN: Doesn't reflect real-world model - a light doesn't have
 *    locking or recording capabilities
 *
 * Solution: Split SmartDevice into smaller, focused interfaces:
 * - ILight (turnOn, turnOff, setDim, setColor)
 * - IThermostat (setTemperature, getTemperature)
 * - ILock (lock, unlock, isLocked)
 * - ICamera (startRecording, stopRecording, streamVideo, motionDetection)
 *
 * Then SmartLight would only implement ILight interface.
 *

class SmartDevice {
public:
    virtual void turnOn() = 0;
    virtual void turnOff() = 0;
    virtual void setDim(int percent) = 0;
    virtual void setColor(string color) = 0;
    virtual void setTemperature() = 0;
    virtual void getTempereature() = 0;
    virtual void lock() = 0;
    virtual void unlock() = 0;
    virtual void isLocked() = 0;
    virtual void startRecording() = 0;
    virtual void stopRecording() = 0;
    virtual void streamVideo() = 0;
    virtual void motionDetection(bool enable) = 0;
};

class SmartLight : public SmartDevice {
public: 
    void turnOn() override {
        cout << "Smart Light turned on." << endl;
    }  

    void turnOff() override {
        cout << "Smart Light turned off." << endl;
    }

    void setDim(int percent) override {
        cout << "Smart Light dimmed by " << percent << "%." << endl;
    }

    void setColor(string color) override {
        cout << "Smart Light color changed to " << color << "." << endl;
    }

    // violates ISP, as SmartLight does not need these functionalities
    void setTemperature() override {}
    void getTempereature() override {}
    void lock() override {}
    void unlock() override {}
    void isLocked() override {}
    void startRecording() override {}
    void stopRecording() override {}
    void streamVideo() override {}
    void motionDetection(bool enable) override {} 
};

*/

class ILight {
public:
	virtual void turnOn() = 0;
	virtual void turnOff() = 0;
	virtual void setDim(int percent) = 0;
	virtual void setColor(string color) = 0;
};

class IThermostat {
public:
	virtual void setTemperature(int) = 0;
	virtual void getTemperature() = 0;
};

class ILock {
public:
	virtual void lock() = 0;
	virtual void unlock() = 0;
	virtual bool isLocked() = 0;
};

class ICamera {
public:
	virtual void startRecording() = 0;
	virtual void stopRecording() = 0;
	virtual void streamVideo() = 0;
	virtual void motionDetection(bool enable) = 0;
};

class SmartLight : public ILight {
public:
	void turnOn() override {
		cout << "Turning on the light!\n";
	};

	void turnOff() override {
		cout << "Turning off the light\n";
	};

	void setDim(int percent) override {
		cout << "Dimming is set to " << percent << "%\n";
	};

	void setColor(string color) override {
		throw invalid_argument("Current Hardware does not support multicolors\n");
	}
};

class SmartHeater : public IThermostat {
	int heaterTemperature;
public:
	void setTemperature(int temperature) override {
		heaterTemperature = temperature;
		cout << "Temperature is set to " << heaterTemperature << endl;
	}

	void getTemperature() override {
		cout << "Current Temperature is " << heaterTemperature << endl;
	}
};

int main()
{
	SmartLight sl;

	sl.turnOn();
	sl.setDim(60);
	try {
		sl.setColor("Yellow");
	}
	catch (const exception& e)
	{
		cout << "[ERROR] " << e.what();
	}
	sl.turnOff();
	cout << endl;
	
	
	SmartHeater sh;
	sh.setTemperature(70);
	sh.getTemperature();
	return 0;
}