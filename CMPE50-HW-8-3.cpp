#include <iostream>
#include <string>

using namespace std;

class Pet {
public:
    Pet(const string& name, int age, const string* dates);
    virtual ~Pet(); // Virtual destructor
    const string& getName() const;
    int getAge() const;
    const string* getDatesOfVisits() const;
    virtual void print() const; // Virtual function
    Pet(const Pet& other); // Copy constructor
    Pet& operator=(const Pet& other); // Overloaded assignment operator

private:
    string name;
    int age;
    string* datesOfVisits;
};

Pet::Pet(const string& name, int age, const string* dates) : name(name), age(age) {
    // Assuming dates is an array of strings, copying them to dynamic array
    datesOfVisits = new string[age];
    for (int i = 0; i < age; ++i) {
        datesOfVisits[i] = dates[i];
    }
}

Pet::~Pet() {
    delete[] datesOfVisits;
}

const string& Pet::getName() const {
    return name;
}

int Pet::getAge() const {
    return age;
}

const string* Pet::getDatesOfVisits() const {
    return datesOfVisits;
}

void Pet::print() const {
    cout << "Name: " << name << ", Age: " << age << ", Dates of Visits: ";
    for (int i = 0; i < age; ++i) {
        cout << datesOfVisits[i] << " ";
    }
    cout << endl;
}

Pet::Pet(const Pet& other) : name(other.name), age(other.age) {
    datesOfVisits = new string[age];
    for (int i = 0; i < age; ++i) {
        datesOfVisits[i] = other.datesOfVisits[i];
    }
}

Pet& Pet::operator=(const Pet& other) {
    if (this != &other) {
        delete[] datesOfVisits;
        name = other.name;
        age = other.age;
        datesOfVisits = new string[age];
        for (int i = 0; i < age; ++i) {
            datesOfVisits[i] = other.datesOfVisits[i];
        }
    }
    return *this;
}

class Dog : public Pet {
public:
    Dog(const string& name, int age, const string* dates, const string& breed, const string* vaccinationShots);
    ~Dog(); // Virtual destructor
    const string& getBreed() const;
    const string* getDatesOfShots() const;
    void print() const override; // Override virtual function
    Dog(const Dog& other); // Copy constructor
    Dog& operator=(const Dog& other); // Overloaded assignment operator

private:
    string breed;
    string* datesOfShots;
};

Dog::Dog(const string& name, int age, const string* dates, const string& breed, const string* vaccinationShots)
    : Pet(name, age, dates), breed(breed) {
    datesOfShots = new string[age];
    for (int i = 0; i < age; ++i) {
        datesOfShots[i] = vaccinationShots[i];
    }
}

Dog::~Dog() {
    delete[] datesOfShots;
}

const string& Dog::getBreed() const {
    return breed;
}

const string* Dog::getDatesOfShots() const {
    return datesOfShots;
}

void Dog::print() const {
    Pet::print(); // Call base class print function
    cout << "Breed: " << breed << ", Dates of Vaccination Shots: ";
    for (int i = 0; i < getAge(); ++i) {
        cout << datesOfShots[i] << " ";
    }
    cout << endl;
}

Dog::Dog(const Dog& other) : Pet(other), breed(other.breed) {
    datesOfShots = new string[getAge()];
    for (int i = 0; i < getAge(); ++i) {
        datesOfShots[i] = other.datesOfShots[i];
    }
}

Dog& Dog::operator=(const Dog& other) {
    if (this != &other) {
        Pet::operator=(other);
        delete[] datesOfShots;
        breed = other.breed;
        datesOfShots = new string[getAge()];
        for (int i = 0; i < getAge(); ++i) {
            datesOfShots[i] = other.datesOfShots[i];
        }
    }
    return *this;
}

void PrintBill(const Pet& pet) {
    pet.print();
}

int main() {
    // Test the program
    string dates[] = { "01/01/2000", "02/01/200", "03/01/200" };
    string vaccinationShots[] = { "01/02/200", "02/02/200", "03/02/2000" };

    // Create a Dog object
    Dog myDog("Buddy", 4, dates, "Golden Retriever", vaccinationShots);

    // Call the PrintBill function
    PrintBill(myDog);

    return 0;
}
/*Name: Buddy, Age: 4, Dates of Visits: 01/01/2000 02/01/200 03/01/200  
Breed: Golden Retriever, Dates of Vaccination Shots: 01/02/200 02/02/200 03/02/2000 01/01/2000 
*/