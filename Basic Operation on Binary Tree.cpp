#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* leftChild;
    Node* rightChild;
    Node(int data)
    {
        this->data = data;
        leftChild = nullptr;
        rightChild = nullptr;
    }
};

class Tree{
    private:
    Node* root;
    public:
    Tree();
    ~Tree();
    void CreateTree();
    void Inorder()
    {
        Inorder(root);
    }
    void Inorder(Node* root);
    void Preorder()
    {
        Preorder(root);
    }
    void Preorder(Node* root);
    void Postorder()
    {
        Postorder(root);
    }
    void LevelOrder()
    {
        LevelOrder(root);
    }
    void LevelOrder(Node* root);
    void Postorder(Node* root);
    int Height()
    {
        return Height(root);
    }
    int Height(Node* root);
};

void Tree::LevelOrder(Node* root)
{
    queue<Node*>q;
    q.push(root);
    while (!q.empty())
    {
        Node* temp = q.front();
        cout << temp->data << " ";
        q.pop();
        if(temp->leftChild)
        {
            q.push(temp->leftChild);
        }
        if(temp->rightChild)
        {
            q.push(temp->rightChild);
        }
    }
}

void Tree::Inorder(Node* root)
{
    if(root == NULL)
    {
        return;
    }
    Inorder(root->leftChild);
    cout << root->data << " ";
    Inorder(root->rightChild);
}

int Tree :: Height(Node* root)
{
    if(root == NULL)
    {
        return 0;
    }
    int l = Height(root->leftChild);
    int r = Height(root->rightChild);
    return max(l,r)+1;
}

void Tree::Preorder(Node* root)
{
    if(root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    Preorder(root->leftChild);
    Preorder(root->rightChild);
}

void Tree::Postorder(Node* root)
{
    if(root == NULL)
    {
        return;
    }
    Postorder(root->leftChild);
    Postorder(root->rightChild);
    cout << root->data << " ";
}

Tree :: Tree()
{
    root = nullptr;
}

Tree :: ~Tree()
{

}

void Tree::CreateTree()
{
    int x;
    cout << "\n Enter root : ";
    cin >> x;
    root = new Node(x);
    queue<Node*>q;
    q.push(root);
    while(!q.empty())
    {
        Node* temp = q.front();
        q.pop();
        int l;
        cout << "\n Enter data for leftChild : ";
        cin >> l;
        if(l!= -1)
        {
            Node* newNode = new Node(l);
            temp->leftChild = newNode;
            q.push(newNode);
        }

        int r;
        cout << "\n Enter data for rightChild : ";
        cin >> r;
        if(r!= -1)
        {
            Node* newNode = new Node(r);
            temp->rightChild = newNode;
            q.push(newNode);
        }
    }
}

int main()
{
    Tree obj;
    obj.CreateTree();
    obj.Inorder();
    cout << endl;
    int x = obj.Height();
    cout << "Height : " << x << endl;
    cout << endl;
    obj.LevelOrder();
    return 0;
}
