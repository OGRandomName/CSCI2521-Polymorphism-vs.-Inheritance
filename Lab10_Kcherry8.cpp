/**
 * @file Lab10_Kcherry8.cpp
 * @author Kenneth Cherry
 * @date 2026-11-23
 * @brief Main program for Lab 10. Demonstrates Customer, Account,
 *        and SavingsAccount functionality, including deposits,
 *        withdrawals, close of business, and saving account
 *        information to a text file.
 */

#include "SavingsAccount.h"

#include <iostream>

// Menu options
const int DEPOSIT = 1;
const int WITHDRAWAL = 2;
const int CLOSE_OF_BUSINESS = 3;
const int SAVE_ACCOUNT = 4;
const int QUIT = 5;

/**
 * @brief Displays the available banking menu options.
 * @return Nothing.
 */
void printMenu();

/**
 * @brief Gets a valid menu selection from the user.
 * @return A valid menu choice.
 */
int getMenuOption();

/**
 * @brief Determines whether a transaction amount is valid.
 * @param amount The dollar amount to validate.
 * @return True if the amount is greater than zero; otherwise, false.
 */
bool isAmountValid(double amount);

/**
 * @brief Determines whether a menu choice is valid.
 * @param choice The menu selection to validate.
 * @return True if the choice is within the valid menu range.
 */
bool isMenuChoiceValid(int choice);

/**
 * @brief Displays an invalid menu selection message.
 * @return Nothing.
 */
void printInvalidMenuChoiceMessage();

/**
 * @brief Gets a valid deposit amount from the user.
 * @return A valid deposit amount greater than zero.
 */
double getDepositAmount();

/**
 * @brief Gets a valid withdrawal amount from the user.
 * @return A valid withdrawal amount greater than zero.
 */
double getWithdrawalAmount();

/**
 * @brief Displays an invalid transaction amount message.
 * @return Nothing.
 */
void printInvalidAmountMessage();

/**
 * @brief Main entry point for the Lab 10 banking program.
 *
 * Creates a dynamically allocated SavingsAccount and allows the
 * user to make deposits, withdrawals, process close of business,
 * and save account information to a text file.
 *
 * @return 0 to indicate successful program completion.
 */
int main()
{
    // Create the customer.
    Customer customer(
        "0123456789",
        "customer@cscc.edu"
    );

    // Dynamically create the savings account.
    SavingsAccount* account = new SavingsAccount(
        "5423678409",
        100.00,
        0.05F,
        customer
    );

    std::cout << "Initial Account Information\n";
    std::cout << "---------------------------\n";
    account->printAccountInfo();

    int menuChoice = getMenuOption();

    while (menuChoice != QUIT)
    {
        switch (menuChoice)
        {
        case DEPOSIT:
        {
            double depositAmount = getDepositAmount();

            account->deposit(depositAmount);

            std::cout << "Deposit added successfully.\n";
            break;
        }

        case WITHDRAWAL:
        {
            double withdrawalAmount = getWithdrawalAmount();

            account->withdraw(withdrawalAmount);

            std::cout << "Withdrawal added successfully.\n";
            break;
        }

        case CLOSE_OF_BUSINESS:
        {
            account->closeOfBusiness();

            // Lab 10 requirement:
            // Save the account after closeOfBusiness().
            account->Save();

            break;
        }

        case SAVE_ACCOUNT:
        {
            account->Save();
            break;
        }

        default:
            break;
        }

        menuChoice = getMenuOption();
    }

    // Release dynamically allocated memory.
    delete account;
    account = nullptr;

    return 0;
}

/**
 * @brief Displays the available banking menu options.
 * @return Nothing.
 */
void printMenu()
{
    std::cout << "\nCSCC Bank and Trust\n";
    std::cout << "-------------------\n";
    std::cout << DEPOSIT << ". Make a deposit\n";
    std::cout << WITHDRAWAL << ". Make a withdrawal\n";
    std::cout << CLOSE_OF_BUSINESS << ". Close of Business\n";
    std::cout << SAVE_ACCOUNT << ". Save Account Information\n";
    std::cout << QUIT << ". Quit\n";
}

/**
 * @brief Gets a valid menu selection from the user.
 * @return A valid menu choice.
 */
int getMenuOption()
{
    int choice = 0;

    do
    {
        printMenu();

        std::cout << "Enter your choice: ";
        std::cin >> choice;

        if (!isMenuChoiceValid(choice))
        {
            printInvalidMenuChoiceMessage();
        }

    } while (!isMenuChoiceValid(choice));

    return choice;
}

/**
 * @brief Determines whether a transaction amount is valid.
 * @param amount The dollar amount to validate.
 * @return True if the amount is greater than zero; otherwise, false.
 */
bool isAmountValid(double amount)
{
    return amount > 0.0;
}

/**
 * @brief Determines whether a menu choice is valid.
 * @param choice The menu selection to validate.
 * @return True if the choice is between DEPOSIT and QUIT.
 */
bool isMenuChoiceValid(int choice)
{
    return choice >= DEPOSIT && choice <= QUIT;
}

/**
 * @brief Displays an invalid menu selection message.
 * @return Nothing.
 */
void printInvalidMenuChoiceMessage()
{
    std::cout
        << "Invalid option selected. Please try again.\n";
}

/**
 * @brief Gets a valid deposit amount from the user.
 * @return A deposit amount greater than zero.
 */
double getDepositAmount()
{
    double depositAmount = 0.0;

    do
    {
        std::cout << "Please enter the deposit amount: $";
        std::cin >> depositAmount;

        if (!isAmountValid(depositAmount))
        {
            printInvalidAmountMessage();
        }

    } while (!isAmountValid(depositAmount));

    return depositAmount;
}

/**
 * @brief Gets a valid withdrawal amount from the user.
 * @return A withdrawal amount greater than zero.
 */
double getWithdrawalAmount()
{
    double withdrawalAmount = 0.0;

    do
    {
        std::cout << "Please enter the withdrawal amount: $";
        std::cin >> withdrawalAmount;

        if (!isAmountValid(withdrawalAmount))
        {
            printInvalidAmountMessage();
        }

    } while (!isAmountValid(withdrawalAmount));

    return withdrawalAmount;
}

/**
 * @brief Displays an invalid transaction amount message.
 * @return Nothing.
 */
void printInvalidAmountMessage()
{
    std::cout
        << "The dollar amount must be greater than $0.00. "
        << "Please try again.\n";
}