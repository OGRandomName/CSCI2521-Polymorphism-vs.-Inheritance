#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>

/**
 * @class Customer
 * @brief Stores identifying information for a bank customer.
 */
class Customer
{
private:
    std::string customerID;
    std::string email;

public:
    /**
     * @brief Constructs a Customer with default information.
     * @return A default Customer object.
     */
    Customer();

    /**
     * @brief Constructs a Customer with an ID and email address.
     * @param id The unique identifier assigned to the customer.
     * @param emailAddress The customer's email address.
     * @return A Customer object containing the supplied information.
     */
    Customer(
        const std::string& id,
        const std::string& emailAddress
    );

    /**
     * @brief Gets the customer's unique identifier.
     * @return The customer's ID as a string.
     */
    std::string getCustomerID() const;

    /**
     * @brief Gets the customer's email address.
     * @return The customer's email address as a string.
     */
    std::string getEmail() const;

    /**
     * @brief Displays the customer's information.
     * @return Nothing.
     */
    void printCustomerInfo() const;
};

#endif