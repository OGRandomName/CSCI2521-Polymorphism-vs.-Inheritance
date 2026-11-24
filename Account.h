#ifndef ACCOUNT_H
#define ACCOUNT_H

#include "Customer.h"

#include <string>
#include <vector>

/**
 * @class Account
 * @brief Represents a basic bank account with deposits and withdrawals.
 */
class Account
{
protected:
    std::string accountNumber;
    double balance;
    Customer owner;
    std::vector<double> deposits;
    std::vector<double> withdrawals;

    /**
     * @brief Displays the close-of-business account summary.
     * @param previousBalance The balance before processing transactions.
     * @param totalDeposits The total amount deposited.
     * @param totalWithdrawals The total amount withdrawn.
     * @param newBalance The balance after processing transactions.
     * @return Nothing.
     */
    void printSummary(
        double previousBalance,
        double totalDeposits,
        double totalWithdrawals,
        double newBalance
    ) const;

public:
    /**
     * @brief Constructs an Account with default information.
     * @return A default Account object.
     */
    Account();

    /**
     * @brief Constructs an Account with supplied account information.
     * @param accNum The account number.
     * @param initialBalance The account's starting balance.
     * @param customer The Customer who owns the account.
     * @return An Account containing the supplied information.
     */
    Account(
        const std::string& accNum,
        double initialBalance,
        const Customer& customer
    );

    /**
     * @brief Adds a pending deposit to the account.
     * @param amount The amount to deposit.
     * @return True when the amount is positive; otherwise, false.
     */
    bool deposit(double amount);

    /**
     * @brief Adds a pending withdrawal to the account.
     * @param amount The amount to withdraw.
     * @return True when the amount is positive; otherwise, false.
     */
    bool withdraw(double amount);

    /**
     * @brief Processes pending transactions and updates the balance.
     * @return Nothing.
     */
    virtual void closeOfBusiness();

    /**
     * @brief Gets the account's current balance.
     * @return The current account balance.
     */
    double getBalance() const;

    /**
     * @brief Gets the account number.
     * @return The account number as a string.
     */
    std::string getAccountNumber() const;

    /**
     * @brief Gets the customer who owns the account.
     * @return A copy of the account's Customer object.
     */
    Customer getCustomer() const;

    /**
     * @brief Displays general information about the account.
     * @return Nothing.
     */
    virtual void printAccountInfo() const;

    /**
     * @brief Displays all pending deposits and withdrawals.
     * @return Nothing.
     */
    void printTransactions() const;
};

#endif