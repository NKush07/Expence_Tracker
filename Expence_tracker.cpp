#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Expense {
    string category;
    double amount;
};

class ExpenseTracker {
private:
    vector<Expense> expenses;
    
public:
    void addExpense(string category, double amount) {
        Expense newExpense;
        newExpense.category = category;
        newExpense.amount = amount;
        expenses.push_back(newExpense);
        cout << "Expense added successfully!" << endl;
    }

    void viewExpenses() {
        if (expenses.empty()) {
            cout << "No expenses recorded yet." << endl;
            return;
        }

        cout << "\nList of Expenses:" << endl;
        for (const auto &expense : expenses) {
            cout << "Category: " << expense.category << ", Amount: " << expense.amount << endl;
        }
    }

    void calculateTotalExpense() {
        if (expenses.empty()) {
            cout << "No expenses recorded yet." << endl;
            return;
        }

        double total = 0;
        for (const auto &expense : expenses) {
            total += expense.amount;
        }
        cout << "Total Expenses: " << total << endl;
    }

    void calculateCategoryExpense(string category) {
        double total = 0;
        for (const auto &expense : expenses) {
            if (expense.category == category) {
                total += expense.amount;
            }
        }
        cout << "Total Expense for " << category << ": " << total << endl;
    }
};

int main() {
    ExpenseTracker tracker;
    int choice;
    string category;
    double amount;

    do {
        cout << "\nExpense Tracker Menu:" << endl;
        cout << "1. Add Expense" << endl;
        cout << "2. View Expenses" << endl;
        cout << "3. Calculate Total Expenses" << endl;
        cout << "4. Calculate Expense by Category" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter category: ";
                cin >> category;
                cout << "Enter amount: ";
                cin >> amount;
                tracker.addExpense(category, amount);
                break;
            case 2:
                tracker.viewExpenses();
                break;
            case 3:
                tracker.calculateTotalExpense();
                break;
            case 4:
                cout << "Enter category: ";
                cin >> category;
                tracker.calculateCategoryExpense(category);
                break;
            case 5:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}