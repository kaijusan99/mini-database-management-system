#include <string>
#include <vector>

using namespace std;

bool isInt(const string& s);
bool isInRange(int value, int lower, int upper);

void printCell(string value, int width);

struct Column {
    string name;
    string type;
};

bool validateInsert(string value, Column& column);

struct Table {
    string name;
    vector<Column> columns;
    vector<vector<string>> rows;

    void init(string tableName);
    int getColumnWidth(int column);
    void addColumn(string name, string type);
    
    void insert(vector<string>& values);
    void print();
    void deleteByNumber(int number);
    void findByField(string field, string value);
    void sortByField(string field, bool reversed = false);
    void saveToFile(string filename);
    void loadFromFile(string filename);
};


