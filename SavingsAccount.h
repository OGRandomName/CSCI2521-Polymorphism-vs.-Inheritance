#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H

#include "Account.h"

/**
 * @class SavingsAccount
 * @brief Represents an account that applies interest at close of business.
 */
class SavingsAccount : public Account
{
protected:
    float interest;

public:
    /**
     * @brief Constructs a SavingsAccount with default information.
     * @return A default SavingsAccount object.
     */
    SavingsAccount();

    /**
     * @brief Constructs a SavingsAccount with supplied information.
     * @param accNum The account number.
     * @param initialBalance The account's starting balance.
     * @param interestRate The decimal interest rate applied to the balance.
     * @param customer The Customer who owns the account.
     * @return A SavingsAccount containing the supplied information.
     */
    SavingsAccount(
        const std::string& accNum,
        double initialBalance,
        float interestRate,
        const Customer& customer
    );

    /**
     * @brief Processes transactions and applies interest.
     * @return Nothing.
     */
    void closeOfBusiness() override;

    /**
     * @brief Displays information about the savings account.
     * @return Nothing.
     */
    void printAccountInfo() const override;

    /**
     * @brief Saves the savings account details to a text file.
     * @return Nothing.
     */
    void Save() const;
};

#endif