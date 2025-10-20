#include <iostream>
using namespace std;

struct Node
{
    int nilai;
    Node *left;
    Node *right;
    Node(int n) : nilai(n), left(nullptr), right(nullptr) {}
};

Node *insertNode(Node *root, int nilai)
{
    if (!root)
        return new Node(nilai);
    if (nilai < root->nilai)
        root->left = insertNode(root->left, nilai);
    else if (nilai > root->nilai)
        root->right = insertNode(root->right, nilai);
    return root;
}

bool searchNode(Node *root, int nilai)
{
    if (!root)
        return false;
    if (root->nilai == nilai)
        return true;
    if (nilai < root->nilai)
        return searchNode(root->left, nilai);
    return searchNode(root->right, nilai);
}

void inorder(Node *root)
{
    if (!root)
        return;
    inorder(root->left);
    cout << root->nilai << " ";
    inorder(root->right);
}

void preorder(Node *root)
{
    if (!root)
        return;
    cout << root->nilai << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node *root)
{
    if (!root)
        return;
    postorder(root->left);
    postorder(root->right);
    cout << root->nilai << " ";
}

int findMin(Node *root)
{
    if (!root)
        return -1;
    while (root->left)
        root = root->left;
    return root->nilai;
}

int findMax(Node *root)
{
    if (!root)
        return -1;
    while (root->right)
        root = root->right;
    return root->nilai;
}

int countNodes(Node *root)
{
    if (!root)
        return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

long long sumNodes(Node *root)
{
    if (!root)
        return 0;
    return root->nilai + sumNodes(root->left) + sumNodes(root->right);
}

int main()
{
    Node *root = nullptr;
    int nilai, cari;

    cout << "Masukkan 5 nilai mahasiswa: \n";
    for (int i = 0; i < 5; i++)
    {
        cout << "Nilai ke-" << i + 1 << ": ";
        cin >> nilai;
        root = insertNode(root, nilai);
    }

    cout << "\n=== HASIL TRAVERSAL BST ===\n";
    cout << "Inorder   : ";
    inorder(root);
    cout << "\nPreorder  : ";
    preorder(root);
    cout << "\nPostorder : ";
    postorder(root);
    cout << "\n\n";

    cout << "Nilai terkecil (Min): " << findMin(root) << endl;
    cout << "Nilai terbesar (Max): " << findMax(root) << endl;
    cout << "Jumlah node (Count) : " << countNodes(root) << endl;
    cout << "Total semua nilai   : " << sumNodes(root) << endl;

    cout << "\nMasukkan nilai yang ingin dicari: ";
    cin >> cari;
    if (searchNode(root, cari))
        cout << "Nilai " << cari << " ditemukan di BST.\n";
    else
        cout << "Nilai " << cari << " tidak ditemukan di BST.\n";

    return 0;
}
