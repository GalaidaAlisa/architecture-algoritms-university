#include <iostream>

using namespace std;

struct Person {
    enum Position {
        Goalkeeper,
        Defender,
        Midfielder,
        Forward
    };

    int id;
    const char* lastname;
    Position position;
    int age;
    int number_of_games;
    int number_of_goals;
};

const char* position_number_to_char(Person::Position position) {
    if (position == Person::Position::Goalkeeper) {
        return "Goalkeeper";
    } else if (position == Person::Position::Defender) {
        return "Defender";
    } else if (position == Person::Position::Midfielder) {
        return "Midfielder";
    } else if (position == Person::Position::Forward) {
        return "Forward";
    } else {
        return "Unknown position.";
    }
}

void output(Person person) {
    cout << endl;
    cout << "Player`s ID: " << person.id << endl;
    cout << "Player`s lastname: " << person.lastname << endl;
    cout << "Player`s position: " << position_number_to_char(person.position) << endl;
    cout << "Player`s age: " << person.age << endl;
    cout << "Number of played games: " << person.number_of_games << endl;
    cout << "Number of scored goals: " << person.number_of_goals << endl;
}

Person input(int id) {
    Person new_person;
    new_person.id = id;
    cout << endl;
    cout << "Enter player`s last name: ";
    char* lastname = new char[50];
    cin >> lastname;
    new_person.lastname = lastname;
    cout << "Enter player`s position (0 - Goalkeeper, 1 - Defender, 2 - Midfielder, 3 - Forward): ";
    int position;
    cin >> position;
    if (position == 0) {
        new_person.position = Person::Position::Goalkeeper;
    } else if (position == 1) {
        new_person.position = Person::Position::Defender;
    } else if (position == 2) {
        new_person.position = Person::Position::Midfielder;
    } else if (position == 3) {
        new_person.position = Person::Position::Forward;
    }
    cout << "Enter player`s age: ";
    int age;
    cin >> age;
    new_person.age = age;
    cout << "Enter number of player`s games: ";
    int number_of_games;
    cin >> number_of_games;
    new_person.number_of_games = number_of_games;
    cout << "Enter number of player`s goals: ";
    int number_of_goals;
    cin >> number_of_goals;
    new_person.number_of_goals = number_of_goals;
    return new_person;
}

void add_person(Person* &people, int size, int id) {
    Person new_person = input(id); // нова людина
    Person* new_people = new Person[size + 1];
    for (int i = 0; i < size; i++) {
        new_people[i] = people[i];
    }
    new_people[size] = new_person;

    delete[] people;
    people = new_people;
}

int delete_person(Person* &people, int size, int id) {
    int index_of_person = -1;
    for (int i = 0; i < size; i++) {
        Person current_person = people[i];
        if (current_person.id == id) {
            index_of_person = i;
            break;
        }
    }
    if (index_of_person == -1) {
        cout << "Invalide ID.";
        return size;
    }
    Person* new_people = new Person[size - 1];
    for (int i = 0; i < index_of_person; i++) {
        Person cur_person = people[i];
        new_people[i] = cur_person;
    }
    for (int i = index_of_person + 1; i < size; i++) {
        Person cur_person = people[i];
        new_people[i - 1] = cur_person;
    }

    delete[] people;
    people = new_people;
    return size - 1;
}

void less_than_five(Person* people, int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (people[i].number_of_games < 5) {
            output(people[i]);
            count++;
        }
    }
    if (count == 0) {
        cout << "There are no people with less than 5 games." << endl;
    }
}

void the_best_forward(Person* people, int size) {
    int index = -1;
    int max_goals = -1;
    for (int i = 0; i < size; i++) {
        if (people[i].position == 3) {
            if (people[i].number_of_goals > max_goals) {
                max_goals = people[i].number_of_goals;
                index = i;
            }            
        }
    }
    if (index == -1) {
        cout << "There is no forwards.";
    } else {
        output(people[index]);
    }
}

int main() {
    int id = 1;

    cout << "Enter number of people, whose you want to input: ";
    int number_of_people;
    cin >> number_of_people;
    Person* people = new Person[number_of_people];

    for (int i = 0; i < number_of_people; i++) {
        Person new_person = input(id);
        id++;
        people[i] = new_person;
    }

    for (int i = 0; i < number_of_people; i++) {
        Person current_person = people[i];
        output(current_person);
    }
    cout << endl;

    number_of_people = delete_person(people, number_of_people, 1);
    cout << "Renewed list of players: ";
    for (int i = 0; i < number_of_people; i++) {
        Person current_person = people[i];
        output(current_person);
    }

    add_person(people, number_of_people, id);
    number_of_people++;
    id++;

    cout << "Renewed list of players: ";
    for (int i = 0; i < number_of_people; i++) {
        Person current_person = people[i];
        output(current_person);
    }

    cout << endl;
    cout << "Player with less than 5 games: ";
    less_than_five(people, number_of_people);

    cout << "The best forward: ";
    the_best_forward(people, number_of_people);
    return 0;
}