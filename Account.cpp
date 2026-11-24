/**
 * @file Account.cpp
 * @author Kenneth Cherry
 * @date 2026-11-23
 * @brief Implements the Account class and its transaction processing.
 */

#include "Account.h"

#include <iostream>
#include <numeric>

/**
 * @brief Constructs an Account with default information.
 * @return A default Account object.
 */
Account::Account()
    : accountNumber("0000000000"),
      balance(0.0),
      owner()
{
}

/**
 * @brief Constructs an Account with supplied account information.
 * @param accNum The account number.
 * @param initialBalance The account's starting balance.
 * @param customer The Customer who owns the account.
 * @return An Account containing the supplied information.
 */
Account::Account(
    const std::string& accNum,
    double initialBalance,
    const Customer& customer
)
    : accountNumber(accNum),
      balance(initialBalance),
      owner(customer)
{
}

/**
 * @brief Adds a pending deposit to the account.
 * @param amount The amount to deposit.
 * @return True when the amount is positive; otherwise, false.
 */
bool Account::deposit(double amount)
{
    if (amount > 0.0)
    {
        deposits.push_back(amount);
        return true;
    }

    return false;
}

/**
 * @brief Adds a pending withdrawal to the account.
 * @param amount The amount to withdraw.
 * @return True when the amount is positive; otherwise, false.
 */
bool Account::withdraw(double amount)
{
    if (amount > 0.0)
    {
        withdrawals.push_back(amount);
        return true;
    }

    return false;
}

/**
 * @brief Processes pending transactions and updates the balance.
 * @return Nothing.
 */
void Account::closeOfBusiness()
{
    const double totalDeposits =
        std::accumulate(deposits.begin(), deposits.end(), 0.0);

    const double totalWithdrawals =
        std::accumulate(withdrawals.begin(), withdrawals.end(), 0.0);

    const double previousBalance = balance;

    const double newBalance =
        previousBalance + totalDeposits - totalWithdrawals;

    printSummary(
        previousBalance,
        totalDeposits,
        totalWithdrawals,
        newBalance
    );

    balance = newBalance;

    deposits.clear();
    withdrawals.clear();
}

/**
 * @brief Displays the close-of-business account summary.
 * @param previousBalance The balance before processing transactions.
 * @param totalDeposits The total amount deposited.
 * @param totalWithdrawals The total amount withdrawn.
 * @param newBalance The balance after processing transactions.
 * @return Nothing.
 */
void Account::printSummary(
    double previousBalance,
    double totalDeposits,
    double totalWithdrawals,
    double newBalance
) const
{
    std::cout << "Account Number: " << accountNumber << '\n';
    std::cout << "Previous Balance: $" << previousBalance << '\n';
    std::cout << "Total Deposits: $" << totalDeposits << '\n';
    std::cout << "Total Withdrawals: $" << totalWithdrawals << '\n';
    std::cout << "New Balance after COB: $" << newBalance << '\n';
}

/**
 * @brief Gets the account's current balance.
 * @return The current account balance.
 */
double Account::getBalance() const
{
    return balance;
}

/**
 * @brief Gets the account number.
 * @return The account number as a string.
 */
std::string Account::getAccountNumber() const
{
    return accountNumber;
}

/**
 * @brief Gets the customer who owns the account.
 * @return A copy of the account's Customer object.
 */
Customer Account::getCustomer() const
{
    return owner;
}

/**
 * @brief Displays general information about the account.
 * @return Nothing.
 */
void Account::printAccountInfo() const
{
    std::cout << "Account Number: " << accountNumber << '\n';
    std::cout << "Current Balance: $" << balance << '\n';

    owner.printCustomerInfo();
}

/**
 * @brief Displays all pending deposits and withdrawals.
 * @return Nothing.
 */
void Account::printTransactions() const
{
    std::cout << "Deposits: ";

    for (double depositAmount : deposits)
    {
        std::cout << "$" << depositAmount << ' ';
    }

    std::cout << '\n';
    std::cout << "Withdrawals: ";

    for (double withdrawalAmount : withdrawals)
    {
        std::cout << "$" << withdrawalAmount << ' ';
    }

    std::cout << '\n';
}