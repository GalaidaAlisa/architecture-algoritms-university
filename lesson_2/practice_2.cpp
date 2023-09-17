#include <iostream>

using namespace std;

struct Person {       // створюємо структуру
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

struct tnode {
    Person* info;
    tnode* next;
};

typedef tnode* pnode;

const char* position_number_to_char(Person::Position position) { // визначаємо позицію гравця
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

void output(Person* person) { // функція виведення інформації про гравця
    cout << endl;
    cout << "Player`s ID: " << person->id << endl;
    cout << "Player`s lastname: " << person->lastname << endl;
    cout << "Player`s position: " << position_number_to_char(person->position) << endl;
    cout << "Player`s age: " << person->age << endl;
    cout << "Number of played games: " << person->number_of_games << endl;
    cout << "Number of scored goals: " << person->number_of_goals << endl;
}

void players_to_console(pnode head) {
    pnode cur = head;
    while (cur) {
        if (cur->info == nullptr) {
            cur = cur->next;
        } else {
            output(cur->info); // виведення одного гравця
            cur = cur->next;
        }
    }
}

Person* input(int id) { // функція введення інформації про гравця
    Person* new_person = new Person; 
    new_person->id = id;
    cout << endl;
    cout << "Enter player`s last name: ";
    char* lastname = new char[50];
    cin >> lastname;
    new_person->lastname = lastname;
    cout << "Enter player`s position (0 - Goalkeeper, 1 - Defender, 2 - Midfielder, 3 - Forward): ";
    int position;
    cin >> position;
    if (position == 0) {
        new_person->position = Person::Position::Goalkeeper;
    } else if (position == 1) {
        new_person->position = Person::Position::Defender;
    } else if (position == 2) {
        new_person->position = Person::Position::Midfielder;
    } else if (position == 3) {
        new_person->position = Person::Position::Forward;
    }
    cout << "Enter player`s age: ";
    int age;
    cin >> age;
    new_person->age = age;
    cout << "Enter number of player`s games: ";
    int number_of_games;
    cin >> number_of_games;
    new_person->number_of_games = number_of_games;
    cout << "Enter number of player`s goals: ";
    int number_of_goals;
    cin >> number_of_goals;
    new_person->number_of_goals = number_of_goals;
    return new_person;
}

void add_person(pnode head, int& id) { // функція додавання гравця 
    pnode cur = head;
    while (cur->next) {
        cur = cur->next;
    }
    pnode new_player = new tnode;
    Person* new_person = input(id); // нова людина
    id++; // змінили айді глобально
    new_player->info = new_person;
    cur->next = new_player;
    new_player->next = nullptr;
}

void delete_person(pnode head, int id) { // функція видалення гравця
    pnode cur = head->next;
    pnode prev = head;
    while (cur) {
        if (cur->info->id == id) {
            prev->next = cur->next;
            delete cur->info;
            delete cur;
            return;
        }
        prev = cur;
        cur = cur->next;
    }
    cout << "There are no players with such id." << endl;
}

void games_less_5(pnode head) {
    pnode cur = head->next;
    while (cur) {
        if (cur->info->number_of_games < 5) {
            output(cur->info);
        }
        cur = cur->next;
    }
}

void the_best_forward(pnode head) {
    int n_of_goals = 0;
    Person* best_forward = nullptr;
    pnode cur = head->next;
    while (cur) {
        if (cur->info->position == 3) {
            if (cur->info->number_of_goals > n_of_goals) {
                best_forward = cur->info;
                n_of_goals = best_forward->number_of_goals;
            }
        }
        cur = cur->next;
    }
    if (best_forward) {
        output(best_forward);
    } else {
        cout << "There no best forward.";
    }
}

int main() {
    int id = 1;
    pnode head = new tnode;
    head->info = nullptr;
    head->next = nullptr;
    
    cout << "How many people you want to add?" << endl;
    int amount;
    cin >> amount;
    for (int i = 0; i < amount; i++) {
        add_person(head, id);
    }

    players_to_console(head);
    cout << "Players id to delete: ";
    int id_to_delete;
    cin >> id_to_delete;
    delete_person(head, id_to_delete);

    players_to_console(head);
    
    cout << endl << endl;
    cout << "Players with less than 5 games:";
    games_less_5(head);

    cout << endl << "The best forward:";
    the_best_forward(head);

    while (head) {
        pnode temp = head;
        head = head->next;
        delete temp;
    }
    
    return 0;
}