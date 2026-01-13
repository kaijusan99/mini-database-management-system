#include <string>
#include "table.h"

void getRandomValuesTable(Table& table) {

    vector<string> names = {
        "Adam", "Alex", "Alice", "Andrew", "Anna",
        "Arthur", "Ben", "Brian", "Carl", "Chris",
        "Daniel", "David", "Dennis", "Diana", "Edward",
        "Emily", "Eric", "Frank", "George", "Harry",
        "Helen", "Henry", "Ian", "Jack", "James",
        "Jane", "John", "Julia", "Kevin", "Laura",
        "Leo", "Linda", "Mark", "Mary", "Michael",
        "Nancy", "Oliver", "Oscar", "Paul", "Peter",
        "Quentin", "Rachel", "Robert", "Rose", "Samuel",
        "Sarah", "Scott", "Sophia", "Steven", "Thomas",
        "Tim", "Victor", "William", "Wendy", "Zack",
        "Aaron", "Bella", "Bruce", "Clara", "Colin",
        "Derek", "Ella", "Felix", "Fiona", "Gavin",
        "Grace", "Hugo", "Iris", "Jason", "Kelly",
        "Liam", "Megan", "Nathan", "Olivia", "Patrick",
        "Quinn", "Rebecca", "Simon", "Tina", "Ursula",
        "Vincent", "Violet", "Walter", "Xavier", "Yvonne",
        "Zoe", "Calvin", "Ethan", "Lucas", "Noah",
        "Owen", "Paula", "Ryan", "Stella", "Trevor",
        "Uma", "Victorine", "Wayne", "Yara", "Zane"
    };

    int rowsNumber = 20;

    for (int n = 0; n < rowsNumber; n++) {
        vector<string> randomPerson;
        for (int i = 0; i < table.columns.size(); i++) {
            if (table.columns[i].name == "name") {
                int randomNumber = 0 + rand() % (100 - 0 + 1);
                string randomName = names[randomNumber];
                randomPerson.push_back(randomName);
                continue;
            }
            int min = 1;
            int max = 100;
            int randomNumber = min + rand() % (max - min + 1);
            
            randomPerson.push_back(to_string(randomNumber));
        }
        table.insert(randomPerson);
    }
}