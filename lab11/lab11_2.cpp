#include <iostream>
#include <queue>
#include <windows.h>

using namespace std;

void CP() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
}

// Структура узла бинарного дерева
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Функция для создания бинарного дерева (ввод в ширину)
TreeNode* buildTree() {
    int val;
    cout << "Введите корень дерева (или -1 для завершения): ";
    cin >> val;
    if (val == -1) return nullptr;

    TreeNode* root = new TreeNode(val);
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* current = q.front();
        q.pop();

        cout << "Введите левого потомка для " << current->val << " (или -1 для пропуска): ";
        cin >> val;
        if (val != -1) {
            current->left = new TreeNode(val);
            q.push(current->left);
        }

        cout << "Введите правого потомка для " << current->val << " (или -1 для пропуска): ";
        cin >> val;
        if (val != -1) {
            current->right = new TreeNode(val);
            q.push(current->right);
        }
    }

    return root;
}

// Функция для печати дерева (обход в ширину)
void printTree(TreeNode* root) {
    if (!root) {
        cout << "Дерево пусто!" << endl;
        return;
    }

    queue<TreeNode*> q;
    q.push(root);

    cout << "Бинарное дерево (в ширину): ";
    while (!q.empty()) {
        TreeNode* current = q.front();
        q.pop();
        cout << current->val << " ";

        if (current->left) q.push(current->left);
        if (current->right) q.push(current->right);
    }
    cout << endl;
}

// Функция для нахождения суммы и количества листьев (рекурсивно)
void findLeafStats(TreeNode* root, int& sum, int& count) {
    if (!root) return;

    if (!root->left && !root->right) { // Если узел - лист
        sum += root->val;
        count++;
    }

    findLeafStats(root->left, sum, count);
    findLeafStats(root->right, sum, count);
}

// Функция для вычисления среднего арифметического листьев
double calculateAverageOfLeaves(TreeNode* root) {
    int sum = 0, count = 0;
    findLeafStats(root, sum, count);

    if (count == 0) return 0.0; // Если нет листьев
    return static_cast<double>(sum) / count;
}

int main() {
    CP();
    cout << "Лабораторная работа №11" << endl;
    cout << "Часть №2" << endl;
    
    // Создание дерева
    TreeNode* root = buildTree();

    // Вывод исходного дерева
    printTree(root);

    // Вычисление среднего арифметического листьев
    double avg = calculateAverageOfLeaves(root);
    cout << "Среднее арифметическое листьев: " << avg << endl;

    return 0;
}