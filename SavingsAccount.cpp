/**
 * @file SavingsAccount.cpp
 * @author Kenneth Cherry
 * @date 2026-11-23
 * @brief Implements the SavingsAccount class and file output.
 */

#include "SavingsAccount.h"

#include <fstream>
#include <iomanip>
#include <iostream>
#include <numeric>

/**
 * @brief Constructs a SavingsAccount with default information.
 * @return A default SavingsAccount object.
 */
SavingsAccount::SavingsAccount()
    : Account(),
      interest(0.01F)
{
}

/**
 * @brief Constructs a SavingsAccount with supplied information.
 * @param accNum The account number.
 * @param initialBalance The account's starting balance.
 * @param interestRate The decimal interest rate applied to the balance.
 * @param customer The Customer who owns the account.
 * @return A SavingsAccount containing the supplied information.
 */
SavingsAccount::SavingsAccount(
    const std::string& accNum,
    double initialBalance,
    float interestRate,
    const Customer& customer
)
    : Account(accNum, initialBalance, customer),
      interest(interestRate)
{
}

/**
 * @brief Processes transactions and applies interest.
 * @return Nothing.
 */
void SavingsAccount::closeOfBusiness()
{
    const double totalDeposits =
        std::accumulate(deposits.begin(), deposits.end(), 0.0);

    const double totalWithdrawals =
        std::accumulate(withdrawals.begin(), withdrawals.end(), 0.0);

    const double previousBalance = balance;

    const double interestToApply =
        previousBalance <= 0.0 ? 0.0 : static_cast<double>(interest);

    const double balanceAfterTransactions =
        previousBalance + totalDeposits - totalWithdrawals;

    const double newBalance =
        balanceAfterTransactions * (1.0 + interestToApply);

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
 * @brief Displays information about the savings account.
 * @return Nothing.
 */
void SavingsAccount::printAccountInfo() const
{
    std::cout << "Account Number: " << accountNumber << '\n';
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Current Balance: $" << balance << '\n';
    std::cout << "Interest Rate: " << interest * 100.0F << "%\n";

    owner.printCustomerInfo();
}

/**
 * @brief Saves the savings account details to a text file.
 * @return Nothing.
 */
void SavingsAccount::Save() const
{
    std::ofstream outputFile("account_summary.txt");

    outputFile << "Account Number: " << accountNumber << '\n';

    outputFile << std::fixed << std::setprecision(2);
    outputFile << "Current Balance: $" << balance << '\n';

    outputFile << std::defaultfloat;
    outputFile << "Daily Interest Rate: " << interest << '\n';

    outputFile.close();

    std::cout << "\nAccount information saved to account_summary.txt.\n";
}