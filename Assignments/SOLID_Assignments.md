# SOLID Principles Practice Assignments in C++

## 1. Single Responsibility Principle (SRP)

**Problem Statement: Employee Management System**

Create an employee management system that currently handles:
- Storing employee data (name, ID, salary, department)
- Calculating monthly salary
- Generating salary reports
- Saving employee data to a file
- Sending email notifications to employees

**Assignment:**
1. First, write a `Employee` class that does ALL of the above (violating SRP)
2. Then refactor it into separate classes, each with a single responsibility:
   - `Employee` - stores only employee data
   - `SalaryCalculator` - calculates salary
   - `ReportGenerator` - generates reports
   - `FileStorage` - handles file I/O
   - `EmailNotifier` - handles email sending

**Key Learning:** A class should have only one reason to change.

---

## 2. Open/Closed Principle (OCP)

**Problem Statement: Payment Processing System**

Create a payment processing system that supports multiple payment methods:
- Credit Card
- Debit Card
- PayPal
- Apple Pay (to be added later)

**Assignment:**
1. First, write a `PaymentProcessor` class with `if-else` or `switch` statements to handle different payment types (violating OCP)
2. Then refactor using:
   - An abstract `PaymentMethod` base class with a pure virtual `process()` method
   - Concrete classes: `CreditCardPayment`, `DebitCardPayment`, `PayPalPayment`
   - `PaymentProcessor` accepts any `PaymentMethod` without modification

**Key Learning:** Software entities should be open for extension but closed for modification.

---

## 3. Liskov Substitution Principle (LSP)

**Problem Statement: Shape Area Calculator**

Create a shape hierarchy with area calculation:
- Rectangle (width × height)
- Square (side × side)
- Circle (π × radius²)

**Assignment:**
1. First, make `Square` inherit from `Rectangle` and override `setWidth()` and `setHeight()` to maintain equal sides (violates LSP)
2. Demonstrate the problem: when a `Square` is used where a `Rectangle` is expected, behavior breaks
3. Refactor by creating a common `Shape` base class with `area()` method, and make both `Rectangle` and `Square` inherit from it independently

**Key Learning:** Subtypes must be substitutable for their base types without altering program correctness.

---

## 4. Interface Segregation Principle (ISP)

**Problem Statement: Smart Home Device System**

Create interfaces for smart home devices:
- Light (on/off, dim, change color)
- Thermostat (set temperature, get temperature)
- Door Lock (lock, unlock, check status)
- Camera (record, stream, motion detection)

**Assignment:**
1. First, create a single `SmartDevice` interface with ALL methods (violates ISP)
2. Show the problem: a simple light bulb must implement methods like `record()` and `setTemperature()`
3. Refactor into smaller, focused interfaces:
   - `Switchable` - on/off
   - `Dimmable` - brightness control
   - `Colorable` - color control
   - `TemperatureControl` - temperature methods
   - `Lockable` - lock/unlock
   - `Recordable` - recording/streaming

**Key Learning:** Clients should not depend on interfaces they don't use.

---

## 5. Dependency Inversion Principle (DIP)

**Problem Statement: Notification System**

Create a notification system that sends alerts through multiple channels:
- Email
- SMS
- Push Notification
- Slack

**Assignment:**
1. First, write a `NotificationService` class that directly creates and uses concrete notification classes (violating DIP)
2. Then refactor:
   - Create abstract `INotificationChannel` interface with `send()` method
   - Implement concrete classes: `EmailChannel`, `SMSChannel`, `PushChannel`
   - `NotificationService` depends on `INotificationChannel` (abstraction), not concrete classes
   - Use dependency injection (constructor or setter) to pass the channel

**Key Learning:** Depend on abstractions, not concretions.

## Implementation Tips

| Principle | Key C++ Feature | Common Pitfall |
|-----------|-----------------|----------------|
| SRP | Separate classes, composition | God classes doing too much |
| OCP | Abstract base classes, virtual functions | Modifying existing code for new features |
| LSP | Proper inheritance design | Breaking base class contracts |
| ISP | Multiple small interfaces | Fat interfaces with unused methods |
| DIP | Pure virtual classes, dependency injection | Direct instantiation of concrete classes |

Start with the "violating" version first to understand the problem, then refactor to apply the principle correctly. This approach helps you appreciate why each principle matters.