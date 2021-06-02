// Copyright (c) 2021 Luke Beausoleil All rights reserved
//
// Created by: Luke Beausoleil
// Created on: June 2021
// This program finds the average of ten random numbers

#include <iostream>
#include <random>
#include <array>

template<size_t N>
int MaxOfNumbers(std::array<int, N> numbers) {
    // this function finds the greatest number among the list
    int tempMax = numbers[0];

    for (int loopCounter = 1; loopCounter < numbers.size(); loopCounter++) {
        if (numbers[loopCounter] >= tempMax) {
            tempMax = numbers[loopCounter];
        }
    }

    return tempMax;
}

int main() {
    // this function generates random numbers and calls another function

    // declaration
    std::array<int, 10> numbers;  // array
    int singleNumber;  // variable

    // process -- generate random numbers
    std::cout << "The numbers are [ ";  // output
    for (int loopCounter = 0; loopCounter < 10; loopCounter++) {
        std::random_device rseed;
        std::mt19937 rgen(rseed());  // mersenne_twister
        std::uniform_int_distribution<int> idist(1, 100);  // [1,100]
        singleNumber = idist(rgen);
        numbers[loopCounter] = singleNumber;
        std::cout << singleNumber << " ";  // output
    }
    std::cout << "]" << std::endl;  // output

    // output
    int max = MaxOfNumbers(numbers);
    std::cout << "The greatest number is " << max << "\nDone." << std::endl;
}
