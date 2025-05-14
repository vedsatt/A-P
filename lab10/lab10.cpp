#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <windows.h>

using namespace std;

void CP() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
}

struct Grades {
    int marks[4];
    double average;
};

struct FullName {
    string first;
    string last;
    string patronymic;
};

struct Student {
    int Group;
    Grades grades;
    FullName name;
};

struct Node {
    Student data;
    Node* prev;
    Node* next;
};

struct StackNode {
    Student data;
    StackNode* next;
    
    StackNode(const Student& student) : data(student), next(nullptr) {}
};

class List {
private:
    Node* head;
public:
    List() : head(nullptr) {}
    
    
    ~List() {
        if (!head) return;
        
        Node* current = head->next;
        while (current != head) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        delete head;
    }
    
    void addStudent(const Student& student) {
        Node* newNode = new Node{student, nullptr, nullptr};
        
        if (!head) {
            head = newNode;
            head->next = head;
            head->prev = head;
        } else {
            Node* tail = head->prev;
            tail->next = newNode;
            newNode->prev = tail;
            newNode->next = head;
            head->prev = newNode;
        }
    }
    
    void printAll() const {
        if (!head) {
            cout << "Список пуст" << endl;
            return;
        }
        
        Node* current = head;
        do {
            cout << "Студент: " << current->data.name.last << " " 
                 << current->data.name.first << " " 
                 << current->data.name.patronymic << endl;
            cout << "Група: " << current->data.Group << endl;
            cout << "Оценки: ";
            for (int mark : current->data.grades.marks) {
                cout << mark << " ";
            }
            cout << endl;
            cout << "Средний балл: " << current->data.grades.average << endl;
            cout << "---------------------" << endl;
            
            current = current->next;
        } while (current != head);
    }

    Node* getHead() const {
        return head;
    }
};

class Stack {
private:
    StackNode* top;

public:
    Stack() : top(nullptr) {}
    
    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }
    
    void push(const Student& student) {
        StackNode* newNode = new StackNode(student);
        newNode->next = top;
        top = newNode;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Стек пуст!" << endl;
            return;
        }
        
        StackNode* temp = top;
        top = top->next;
        delete temp;
    }

    Student& peek() const {
        if (isEmpty()) {
            throw runtime_error("Стек пуст!");
        }
        return top->data;
    }

    bool isEmpty() const {
        return top == nullptr;
    }

    StackNode* getTop() const {
        return top;
    }
};

List readData(const string filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        throw runtime_error("Ошибка открытия файла");
    }
    
    List studentList;
    string line;
    
    while (getline(file, line)) {
        if (line.empty()) continue;
        
        Student student;
        
        try {
            student.Group = stoi(line);
        } catch (...) {
            throw runtime_error("Ошибка чтения номера группы");
        }
        
        getline(file, line);
        istringstream marksStream(line);
        int sum = 0;
        bool marksValid = true;
        for (int i = 0; i < 4; ++i) {
            if (!(marksStream >> student.grades.marks[i])) {
                marksValid = false;
                break;
            }
            sum += student.grades.marks[i];
        }
        
        if (!marksValid) {
            throw runtime_error("Ошибка чтения оценок студента");
        }
        student.grades.average = static_cast<double>(sum) / 4;
        
        if (!getline(file, student.name.last) || 
            !getline(file, student.name.first) || 
            !getline(file, student.name.patronymic)) {
            throw runtime_error("Ошибка чтения ФИО студента");
        }
        
        studentList.addStudent(student);
    }
    
    file.close();
    return studentList;
}

Stack createWithoutDebts(const List& studentList) {
    Stack noDebtsStack;
    Node* head = studentList.getHead();
    
    if (!head) return noDebtsStack;
    
    Node* current = head;
    do {
        bool hasDebt = false;
        for (int mark : current->data.grades.marks) {
            if (mark < 4) {
                hasDebt = true;
                break;
            }
        }
        
        if (!hasDebt) {
            noDebtsStack.push(current->data);
        }
        
        current = current->next;
    } while (current != head);
    
    return noDebtsStack;
}

void printStackToFile(const Stack& stack, const string& filename) {
    ofstream outFile(filename);
    if (!outFile.is_open()) {
        throw runtime_error("Не удалось открыть файл для записи");
    }
    
    outFile << "Студенты без задолженностей (все оценки >= 4):\n";
    outFile << "=============================================\n\n";
    
    if (stack.isEmpty()) {
        outFile << "Нет студентов без задолженностей." << endl;
    } else {
        StackNode* current = stack.getTop();
        while (current != nullptr) {
            outFile << "Фамилия: " << current->data.name.last << endl;
            outFile << "Имя: " << current->data.name.first << endl;
            outFile << "Отчество: " << current->data.name.patronymic << endl;
            outFile << "Группа: " << current->data.Group << endl;
            outFile << "Оценки: ";
            for (int mark : current->data.grades.marks) {
                outFile << mark << " ";
            }
            outFile << endl;
            outFile << "Средний балл: " << current->data.grades.average << endl;
            outFile << "------------------------" << endl;
            
            current = current->next;
        }
    }
    
    outFile.close();    
    cout << "Данные успешно записаны в файл " << filename << endl;
}

int main() {
    CP();

    cout << "Лабораторная работа №10\n";
    string filename;
    cout << "Введите имя входного файла: ";
    cin >> filename;

    List studentList;
    try {
        studentList = readData(filename);
    } catch (const exception& err) {
        cout << err.what() << endl;
        return 1;
    }

    cout << "\nСписок студентов:" << endl;
    studentList.printAll();

    Stack noDebtsStack = createWithoutDebts(studentList);

    try {
        printStackToFile(noDebtsStack, "output.txt");
    } catch (const exception& err) {
        cout << err.what() << endl;
        return 1;
    }
    
    return 0;
}

