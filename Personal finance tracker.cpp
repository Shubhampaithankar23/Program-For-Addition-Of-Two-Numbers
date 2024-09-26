#include <iostream>
#include <vector>
#include <iomanip>

class Expense {
public:
    std::string name;
    double amount;

    Expense(const std::string &name, double amount) : name(name), amount(amount) {}
};

class PersonalFinanceManager {
private:
    double income;
    std::vector<Expense> expenses;

public:
    PersonalFinanceManager() : income(0.0) {}

    void setIncome(double incomeAmount) {
        income = incomeAmount;
    }

    void addExpense(const std::string &name, double amount) {
        expenses.push_back(Expense(name, amount));
    }

    double calculateTotalExpenses() {
        double total = 0.0;
        for (const auto &expense : expenses) {
            total += expense.amount;
        }
        return total;
    }

    double calculateSavings() {
        return income - calculateTotalExpenses();
    }

    void displayReport() {
        std::cout << "\n--- Personal Finance Report ---" << std::endl;
        std::cout << "Income: $" << std::fixed << std::setprecision(2) << income << std::endl;

        std::cout << "Expenses:" << std::endl;
        for (const auto &expense : expenses) {
            std::cout << "- " << expense.name << ": $" << expense.amount << std::endl;
        }

        double totalExpenses = calculateTotalExpenses();
        std::cout << "Total Expenses: $" << totalExpenses << std::endl;
        std::cout << "Savings: $" << calculateSavings() << std::endl;
        std::cout << "--------------------------------" << std::endl;
    }
};

int main() {
    PersonalFinanceManager pfm;

    double income;
    std::cout << "Enter your total income: $";
    std::cin >> income;
    pfm.setIncome(income);

    char choice;
    do {
        std::string expenseName;
        double expenseAmount;

        std::cout << "Enter an expense name: ";
        std::cin >> expenseName;
        std::cout << "Enter the expense amount: $";
        std::cin >> expenseAmount;

        pfm.addExpense(expenseName, expenseAmount);

        std::cout << "Do you want to add another expense? (y/n): ";
        std::cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    pfm.displayReport();

    return 0;
}
