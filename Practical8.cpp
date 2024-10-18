#include <iostream>
#include <string>

struct Member {
    std::string prn;
    std::string name;
    Member* next;

    Member(const std::string& prn, const std::string& name) 
        : prn(prn), name(name), next(NULL) {} // Use NULL instead of nullptr
};

class PinnacleClub {
private:
    Member* head; // For division A
    Member* tail; // For division B

public:
    PinnacleClub() : head(NULL), tail(NULL) {} // Use NULL instead of nullptr

    // Add member to the club
    void addMember(const std::string& prn, const std::string& name) {
        if (head == NULL) {
            head = new Member(prn, name);
            tail = head;
        } else {
            tail->next = new Member(prn, name);
            tail = tail->next;
        }
    }

    // Delete member by PRN
    void deleteMember(const std::string& prn) {
        Member* current = head;
        Member* previous = NULL;

        while (current != NULL) {
            if (current->prn == prn) {
                if (previous == NULL) {
                    head = current->next; // Deleting the head
                } else {
                    previous->next = current->next;
                }
                delete current;
                return;
            }
            previous = current;
            current = current->next;
        }
        std::cout << "Member with PRN " << prn << " not found." << std::endl;
    }

    // Count total members
    int countMembers() {
        int count = 0;
        Member* current = head;
        while (current != NULL) {
            count++;
            current = current->next;
        }
        return count;
    }

    // Display members
    void displayMembers() {
        Member* current = head;
        if (current == NULL) {
            std::cout << "No members in this division." << std::endl;
            return;
        }
        while (current != NULL) {
            std::cout << "PRN: " << current->prn << ", Name: " << current->name << std::endl;
            current = current->next;
        }
    }

    // Concatenate two lists
    void concatenate(PinnacleClub& other) {
        if (head == NULL) {
            head = other.head;
            tail = other.tail;
        } else if (other.head != NULL) {
            tail->next = other.head;
            tail = other.tail;
        }
    }

    // Destructor to free memory
    ~PinnacleClub() {
        Member* current = head;
        while (current != NULL) {
            Member* next = current->next;
            delete current;
            current = next;
        }
    }
};

int main() {
    PinnacleClub divisionA;
    PinnacleClub divisionB;
    int choice, divisionChoice;
    std::string prn, name;

    while (true) {
        std::cout << "\nMenu:\n";
        std::cout << "1. Add member to a division\n";
        std::cout << "2. Display members of a division\n";
        std::cout << "3. Delete member by PRN\n";
        std::cout << "4. Concatenate Division B into Division A\n";
        std::cout << "5. Count total members in Division A\n";
        std::cout << "6. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter division (1 for A, 2 for B): ";
                std::cin >> divisionChoice;
                std::cout << "Enter PRN: ";
                std::cin >> prn;
                std::cout << "Enter Name: ";
                std::cin >> name;
                if (divisionChoice == 1) {
                    divisionA.addMember(prn, name);
                } else if (divisionChoice == 2) {
                    divisionB.addMember(prn, name);
                } else {
                    std::cout << "Invalid division!" << std::endl;
                }
                break;

            case 2:
                std::cout << "Enter division to display (1 for A, 2 for B): ";
                std::cin >> divisionChoice;
                if (divisionChoice == 1) {
                    std::cout << "Division A Members:\n";
                    divisionA.displayMembers();
                } else if (divisionChoice == 2) {
                    std::cout << "Division B Members:\n";
                    divisionB.displayMembers();
                } else {
                    std::cout << "Invalid division!" << std::endl;
                }
                break;

            case 3:
                std::cout << "Enter PRN of member to delete: ";
                std::cin >> prn;
                divisionA.deleteMember(prn);  // Assuming deleting from division A
                break;

            case 4:
                std::cout << "Concatenating Division B into Division A...\n";
                divisionA.concatenate(divisionB);
                break;

            case 5:
                std::cout << "Total members in Division A: " << divisionA.countMembers() << std::endl;
                break;

            case 6:
                std::cout << "Exiting program...\n";
                return 0;

            default:
                std::cout << "Invalid choice! Please try again.\n";
        }
    }

    return 0;
}


