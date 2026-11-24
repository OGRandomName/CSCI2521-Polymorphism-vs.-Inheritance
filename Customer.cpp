/**
 * @file Customer.cpp
 * @author Kenneth Cherry
 * @date 2026-11-23
 * @brief Implements the Customer class.
 */

#include "Customer.h"

#include <iostream>

/**
 * @brief Constructs a Customer with default information.
 * @return A default Customer object.
 */
Customer::Customer()
    : customerID("Unknown"),
      email("none@example.com")
{
}

/**
 * @brief Constructs a Customer with an ID and email address.
 * @param id The unique identifier assigned to the customer.
 * @param emailAddress The customer's email address.
 * @return A Customer object containing the supplied information.
 */
Customer::Customer(
    const std::string& id,
    const std::string& emailAddress
)
    : customerID(id),
      email(emailAddress)
{
}

/**
 * @brief Gets the customer's unique identifier.
 * @return The customer's ID as a string.
 */
std::string Customer::getCustomerID() const
{
    return customerID;
}

/**
 * @brief Gets the customer's email address.
 * @return The customer's email address as a string.
 */
std::string Customer::getEmail() const
{
    return email;
}

/**
 * @brief Displays the customer's information.
 * @return Nothing.
 */
void Customer::printCustomerInfo() const
{
    std::cout << "Customer ID: " << customerID << '\n';
    std::cout << "Email: " << email << '\n';
}