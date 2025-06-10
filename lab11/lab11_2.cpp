#include <iostream>
#include <queue>
#include <windows.h>

using namespace std;

void CP() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
}

// ��������� ���� ��������� ������
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// ������� ��� �������� ��������� ������ (���� � ������)
TreeNode* buildTree() {
    int val;
    cout << "������� ������ ������ (��� -1 ��� ����������): ";
    cin >> val;
    if (val == -1) return nullptr;

    TreeNode* root = new TreeNode(val);
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* current = q.front();
        q.pop();

        cout << "������� ������ ������� ��� " << current->val << " (��� -1 ��� ��������): ";
        cin >> val;
        if (val != -1) {
            current->left = new TreeNode(val);
            q.push(current->left);
        }

        cout << "������� ������� ������� ��� " << current->val << " (��� -1 ��� ��������): ";
        cin >> val;
        if (val != -1) {
            current->right = new TreeNode(val);
            q.push(current->right);
        }
    }

    return root;
}

// ������� ��� ������ ������ (����� � ������)
void printTree(TreeNode* root) {
    if (!root) {
        cout << "������ �����!" << endl;
        return;
    }

    queue<TreeNode*> q;
    q.push(root);

    cout << "�������� ������ (� ������): ";
    while (!q.empty()) {
        TreeNode* current = q.front();
        q.pop();
        cout << current->val << " ";

        if (current->left) q.push(current->left);
        if (current->right) q.push(current->right);
    }
    cout << endl;
}

// ������� ��� ���������� ����� � ���������� ������� (����������)
void findLeafStats(TreeNode* root, int& sum, int& count) {
    if (!root) return;

    if (!root->left && !root->right) { // ���� ���� - ����
        sum += root->val;
        count++;
    }

    findLeafStats(root->left, sum, count);
    findLeafStats(root->right, sum, count);
}

// ������� ��� ���������� �������� ��������������� �������
double calculateAverageOfLeaves(TreeNode* root) {
    int sum = 0, count = 0;
    findLeafStats(root, sum, count);

    if (count == 0) return 0.0; // ���� ��� �������
    return static_cast<double>(sum) / count;
}

int main() {
    CP();
    cout << "������������ ������ �11" << endl;
    cout << "����� �2" << endl;
    
    // �������� ������
    TreeNode* root = buildTree();

    // ����� ��������� ������
    printTree(root);

    // ���������� �������� ��������������� �������
    double avg = calculateAverageOfLeaves(root);
    cout << "������� �������������� �������: " << avg << endl;

    return 0;
}