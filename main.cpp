#include <iostream>
#include <vector>
#include <string>

// Contact class
class Contact {
public:
    // Constructor
    Contact(std::string name, std::string phone_number) {
        this->name = name;
        this->phone_number = phone_number;
    }

    // Getter functions
    std::string getName() const {
        return name;
    }

    std::string getPhoneNumber() const {
        return phone_number;
    }

private:
    std::string name;
    std::string phone_number;
};

// ContactManager class
class ContactManager {
public:
    // Add a contact to the manager
    void addContact(Contact contact) {
        contacts.push_back(contact);
    }

    // Print all contacts in the manager
    void printContacts() const {
        std::cout << "Contacts:\n";
        for (const auto& contact : contacts) {
            std::cout << contact.getName() << " (" << contact.getPhoneNumber() << ")\n";
        }
    }

    // Search for a contact by name
    Contact* searchContactByName(const std::string& name) {
        for (auto& contact : contacts) {
            if (contact.getName() == name) {
                return &contact;
            }
        }
        return nullptr;
    }

private:
    std::vector<Contact> contacts;
};

int main() {
    // Create a ContactManager
    ContactManager contact_manager;

    // Add some contacts
    contact_manager.addContact(Contact("Alice", "555-1234"));
    contact_manager.addContact(Contact("Bob", "555-5678"));

    // Print all contacts
    contact_manager.printContacts();

    // Search for a contact by name
    std::string search_name = "Alice";
    Contact* contact = contact_manager.searchContactByName(search_name);
    if (contact != nullptr) {
        std::cout << "Found contact " << contact->getName() << " (" << contact->getPhoneNumber() << ")\n";
    } else {
        std::cout << "Contact " << search_name << " not found.\n";
    }

    return 0;
}
