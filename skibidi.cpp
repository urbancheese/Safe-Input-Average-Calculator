#include <iostream>
#include <vector>
#include <numeric>  
#include <limits>  

// Function to calculate the average
double calculateAverage(const std::vector<double>& numbers) {
    if (numbers.empty()) {
        return 0.0;  // Return 0 if the list is empty
    }
    double sum = std::accumulate(numbers.begin(), numbers.end(), 0.0);
    return sum / numbers.size();
}

// Function to get the number of elements from the user
int getNumberOfElements() {
    int numOfElements;
    while (true) {
        std::cout << "Enter the number of elements: ";
        std::cin >> numOfElements;

        if (std::cin.fail() || numOfElements <= 0) {
            std::cin.clear(); // Clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
            std::cout << "Error: Please enter a valid positive integer.\n";
        }
        else {
            return numOfElements;
        }
    }
}

// Function to get the list of numbers from the user
std::vector<double> getNumbers(int numOfElements) {
    std::vector<double> numbers;
    double number;

    std::cout << "Enter " << numOfElements << " numbers:\n";

    for (int i = 0; i < numOfElements; ++i) {
        while (true) {
            std::cout << "Number " << (i + 1) << ": ";
            std::cin >> number;

            if (std::cin.fail()) {
                std::cin.clear(); // Clear the error flag
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
                std::cout << "Error: Please enter a valid number.\n";
            }
            else {
                numbers.push_back(number);
                break;
            }
        }
    }

    return numbers;
}

int main() {
    // Get the number of elements and the list of numbers from the user
    int numOfElements = getNumberOfElements();
    std::vector<double> numbers = getNumbers(numOfElements);

    // Calculate the average
    double average = calculateAverage(numbers);

    // Display the result
    std::cout << "\nThe average of the entered numbers is: " << average << std::endl;

    return 0;
}
