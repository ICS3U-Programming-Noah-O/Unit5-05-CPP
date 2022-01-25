// Copyright (c) 2022 Noah Ouellette All rights reserved.
//
// Created by: Noah Ouellette
// Created on: Jan. 25, 2022
// This program accepts an address from a
// user and then formats it nicely

#include <string.h>
#include <iostream>
#include <iomanip>

std::string FormatAddress(std::string name, std::string streetNum,
                          std::string street, std::string city,
                          std::string province, std::string postal,
                          std::string apartmentNum = "") {
    // This function organizes the address
    std::string address = name;

    // If the user inputted the apartment number print a different outcome
    if (apartmentNum != "") {
        address = address + " \n" + apartmentNum + "-" + streetNum +
                 " " + street +
                 " \n" + city + " " + province + " " + postal;
    } else {
        address = address + " \n" + streetNum + " " +
                  street + " \n" + city + " " + province + " " + postal;
    }
    // Return the final address to the main function
    return address;
}


int main() {
    // this gets the user input and then calls the function
    std::string apartmentNumber;
    std::string userName;
    std::string userAnswer;
    std::string streetAddress;
    std::string streetName;
    std::string cityName;
    std::string provinceName;
    std::string postalCode;
    std::string finalAddress;

    apartmentNumber = "";
    std::cout << "This program can format your address nicely.\n";
    std::cout << " \n";
    std::cout << " \n";

    // Get the various user inputs and ask the user if they're in an apartment
    std::cout << "Please enter your full name: ";
    getline(std::cin, userName);
    std::cout << "Do you live in an apartment? y/n: ";
    getline(std::cin, userAnswer);
    if (userAnswer == "Y" || userAnswer == "y" || userAnswer == "yes" ||
        userAnswer == "YES") {
        std::cout << "Enter your apartment number: ";
        getline(std::cin, apartmentNumber);
    }
    std::cout << " \n";
    std::cout << "Enter your street address number: ";
    getline(std::cin, streetAddress);
    std::cout << " \n";
    std::cout << "Enter the name of your street and";
    std::cout << " the type of your street (ex. Ave.): ";
    getline(std::cin, streetName);
    std::cout << " \n";
    std::cout << "Enter the name of your city: ";
    getline(std::cin, cityName);
    std::cout << " \n";
    std::cout << "Enter the name of your province ";
    std::cout << "(as an abbreviation): ";
    getline(std::cin, provinceName);
    std::cout << " \n";
    std::cout << "Enter your postal code: ";
    getline(std::cin, postalCode);
    std::cout << " \n";

    // Detect if the user lives in an apartment
    // Call the function based on whether or not the user lives in an apartment
    if (apartmentNumber != "") {
        finalAddress = FormatAddress(userName, streetAddress,
                                     streetName, cityName, provinceName,
                                     postalCode, apartmentNumber);
    } else {
        finalAddress = FormatAddress(userName, streetAddress,
                                     streetName, cityName, provinceName,
                                     postalCode);
    }

    // Print the final organized address
    std::cout << finalAddress;
}

