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
    Person info;
    tnode* next;
};

typedef tnode* pnode;

const char* position_number_to_char(Person::Position position); // визначаємо позицію гравця
void output(Person person); // функція виведення інформації про гравця
void players_to_console(pnode head); // виведення одного гравця
Person input(int id); // функція введення інформації про гравця
void add_people(pnode head, int &id); // функція додавання гравців
void add_person_before(pnode head, int &id, int id_person); // функція додавання гравця перед обраним
void add_person_after(pnode head, int &id, int id_person); // функція додавання гравця після обраного
void delete_person(pnode head, int id); // функція видалення гравця за id
void the_best_forward(pnode head); // функція визначення найкращого форварда
void less_than_5_games(pnode head); // функція виведення гравців з менше ніж 5 ігор


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

void players_to_console(pnode head) {
    pnode cur = head->next;
    while (cur) {
        output(cur->info); 
        cur = cur->next;
    }
}

Person input(int id) {
    Person new_person;
    new_person.id = id;
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

void add_people(pnode head, int &id) {
    int choice;
    pnode cur = head;
    while(cur->next) {
        cur = cur->next;
    }
    Person new_person;
    while(true) {
        cout << endl << "Do you want to add new player? (1 - yes, 2 - no)" << endl;
        cin >> choice;
        pnode new_player = new tnode;
        switch(choice) {
            case 1:
                new_person = input(id);
                new_player = new tnode;
                new_player->info = new_person;
                new_player->next = nullptr;
                cur->next = new_player;
                cur = cur->next;
                id++;
                cout << endl << "Player successfully added." << endl;
                break;
            case 2:
                cout << endl << "All players added successfully." << endl;
                return;
            default:
                cout << endl << "Wrong choice." << endl;
                break;
        }
    }
}

void add_person_before(pnode head, int &id, int id_person) {
    pnode cur = head;
    while(cur->next) {
        if (cur->next->info.id == id_person) {
            Person new_person;
            new_person = input(id);
            id++;
            pnode new_player = new tnode;
            new_player->info = new_person;
            new_player->next = cur->next;
            cur->next = new_player;
            return;
        }
        cur = cur->next;
    } 
    cout << endl << "There is no player with such id." << endl;
}

void add_person_after(pnode head, int &id, int id_person) {
    pnode cur = head->next;
    while(cur) {
        if (cur->info.id == id_person) {
            Person new_person;
            new_person = input(id);
            id++;
            pnode new_player = new tnode;
            new_player->info = new_person;
            new_player->next = cur->next;
            cur->next = new_player;
            return;
        }
        cur = cur->next;
    } 
    cout << endl << "There is no player with such id." << endl;
}

void delete_person(pnode head, int id) {
    pnode cur = head;
    while(cur->next) {
        if (cur->next->info.id == id) {
            pnode temp = cur->next;
            cur->next = cur->next->next;
            delete temp;
            cout << endl << "Player successfully deleted." << endl;
            return;
        } 
        cur = cur->next;
    }
    cout << endl << "There is not such id." << endl;
}

void the_best_forward(pnode head) {
    cout << endl << "Information about best forward:\n";
    pnode cur = head->next;
    Person best_forward;
    best_forward.number_of_goals = 0;
    bool flag = false;
    while(cur) {
        if (cur->info.position == 3) {
            flag = true;
            if (cur->info.number_of_goals >= best_forward.number_of_goals) {
                best_forward = cur->info;
            }
        }
        cur = cur->next;
    }
    if (!flag) {
        cout << endl << "There is no forwards." << endl;
    } else {
        output(best_forward);
    }
}

void less_than_5_games(pnode head) {
    pnode cur = head->next;
    cout << endl << "Players with less than 5 games: " << endl;
    bool flag = false;
    while(cur) {
        if (cur->info.number_of_games < 5) {
            flag = true;
            output(cur->info);
        }
        cur = cur->next;
    }
    if (!flag) {
        cout << endl << "There is no players with less than 5 games." << endl;
    }
}


int main() {
    int id = 1;
    pnode head = new tnode;
    head->next = nullptr;
    bool flag = true;
    int person_id;

    int choice;
    while(flag) {
        cout << "Menu: " << endl;
        cout << "1. Add people" << endl;
        cout << "2. Add player before chosen one" << endl;
        cout << "3. Add player after chosen one" << endl;
        cout << "4. Output person" << endl;
        cout << "5. Delete person" << endl;
        cout << "6. The best forward" << endl;
        cout << "7. Players with less than 5 games" << endl;
        cout << "8. End the program" << endl;

        cin >> choice;
        switch(choice) {
            case 1:
                add_people(head, id);
                break;
            case 2:
                cout << endl << "Enter id of person before whom you want to add new player: " << endl;
                cin >> person_id;
                add_person_before(head, id, person_id);
                break;
            case 3:
                cout << endl << "Enter id of person after whom you want to add new player: " << endl;
                cin >> person_id;
                add_person_after(head, id, person_id);
                break;
            case 4:
                players_to_console(head);
                break;
            case 5:
                cout << "Enter person's id whom you want to delete: ";
                int id_del;
                cin >> id_del;
                delete_person(head, id_del);
                break;
            case 6:
                the_best_forward(head);
                break;
            case 7:
                less_than_5_games(head);
                break;
            case 8:
                cout << endl << "The program is finished." << endl;
                flag = false;
                break;
            default: 
                cout << endl << "Wrong choice." << endl;
        }        
    }
    
    while(head) {
        pnode temp = head;
        head = head->next;
        delete temp;
    }
    return 0;
}
