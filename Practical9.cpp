#include <iostream>
#include <string>

const int ROWS = 10; // Number of rows in the cinema
const int SEATS = 7; // Number of seats per row

struct Seat {
    int seatNumber;
    bool isBooked;
    Seat* next;
    Seat* prev;

    Seat(int number) : seatNumber(number), isBooked(false), next(NULL), prev(NULL) {}
};

class Row {
public:
    Seat* head;
    Seat* tail;

    Row() {
        head = NULL;
        tail = NULL;
        createSeats();
    }

    // Create seats for the row
    void createSeats() {
        for (int i = 1; i <= SEATS; ++i) {
            Seat* newSeat = new Seat(i);
            if (!head) {
                head = newSeat;
                tail = newSeat;
                head->next = head;
                head->prev = head;
            } else {
                tail->next = newSeat;
                newSeat->prev = tail;
                newSeat->next = head;
                head->prev = newSeat;
                tail = newSeat;
            }
        }
    }

    // Display available seats
    void displayAvailableSeats() {
        Seat* current = head;
        bool found = false;
        do {
            if (!current->isBooked) {
                std::cout << "Seat " << current->seatNumber << " is available." << std::endl;
                found = true;
            }
            current = current->next;
        } while (current != head);
        if (!found) {
            std::cout << "No available seats." << std::endl;
        }
    }

    // Book a seat
    bool bookSeat(int seatNumber) {
        Seat* current = head;
        do {
            if (current->seatNumber == seatNumber) {
                if (!current->isBooked) {
                    current->isBooked = true;
                    std::cout << "Seat " << seatNumber << " booked successfully." << std::endl;
                    return true;
                } else {
                    std::cout << "Seat " << seatNumber << " is already booked." << std::endl;
                    return false;
                }
            }
            current = current->next;
        } while (current != head);
        std::cout << "Seat " << seatNumber << " not found." << std::endl;
        return false;
    }

    // Cancel a booking
    bool cancelBooking(int seatNumber) {
        Seat* current = head;
        do {
            if (current->seatNumber == seatNumber) {
                if (current->isBooked) {
                    current->isBooked = false;
                    std::cout << "Booking for seat " << seatNumber << " cancelled successfully." << std::endl;
                    return true;
                } else {
                    std::cout << "Seat " << seatNumber << " was not booked." << std::endl;
                    return false;
                }
            }
            current = current->next;
        } while (current != head);
        std::cout << "Seat " << seatNumber << " not found." << std::endl;
        return false;
    }

    ~Row() {
        Seat* current = head;
        if (current) {
            do {
                Seat* next = current->next;
                delete current;
                current = next;
            } while (current != head);
        }
    }
};

class Cinema {
private:
    Row rows[ROWS];
public:
    // Display available seats in all rows
    void displayAllAvailableSeats() {
        for (int i = 0; i < ROWS; ++i) {
            std::cout << "Row " << (i + 1) << ":" << std::endl;
            rows[i].displayAvailableSeats();
        }
    }
    // Book a seat in a specific row
    void bookSeat(int rowNumber, int seatNumber) {
        if (rowNumber >= 1 && rowNumber <= ROWS) {
            rows[rowNumber - 1].bookSeat(seatNumber);
        } else {
            std::cout << "Invalid row number." << std::endl;
        }
    }
    // Cancel a booking in a specific row
    void cancelBooking(int rowNumber, int seatNumber) {
        if (rowNumber >= 1 && rowNumber <= ROWS) {
            rows[rowNumber - 1].cancelBooking(seatNumber);
        } else {
            std::cout << "Invalid row number." << std::endl;
        }
    }
};
int main() {
    Cinema cinema;
    int choice, rowNumber, seatNumber;
    while (true) {
        std::cout << "\nCinema Booking System\n";
        std::cout << "1. Display all available seats\n";
        std::cout << "2. Book a seat\n";
        std::cout << "3. Cancel a booking\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        switch (choice) {
            case 1:
                cinema.displayAllAvailableSeats();
                break;
            case 2:
                std::cout << "Enter row number (1-" << ROWS << "): ";
                std::cin >> rowNumber;
                std::cout << "Enter seat number (1-" << SEATS << "): ";
                std::cin >> seatNumber;
                cinema.bookSeat(rowNumber, seatNumber);
                break;
            case 3:
                std::cout << "Enter row number (1-" << ROWS << "): ";
                std::cin >> rowNumber;
                std::cout << "Enter seat number (1-" << SEATS << "): ";
                std::cin >> seatNumber;
                cinema.cancelBooking(rowNumber, seatNumber);
                break;
            case 4:
                std::cout << "Exiting program...\n";
                return 0;
            default:
                std::cout << "Invalid choice! Please try again.\n";
        }
    }
    return 0;
}

