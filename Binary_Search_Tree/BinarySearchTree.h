#include <iostream>
using namespace std;

template <class T>
class node
{
public:
    T value;
    node<T> *parrent;
    node<T> *left;
    node<T> *right;
};

template <class T>
class MyBST
{
private:
    node<T> *root;

public:
    MyBST()
    {
        root = nullptr;
    }
    void Insert(T element)
    {
        if (root == nullptr)
        {
            node<T> *newNode = new node<T>;
            newNode->value = element;
            newNode->left = nullptr;
            newNode->right = nullptr;
            newNode->parrent = nullptr;
            root = newNode;
            return;
        }
        else
        {
            node<T> *currentNode = root;
            while (1)
            {
                if (currentNode->value > element)
                {
                    if (currentNode->left != nullptr)
                        currentNode = currentNode->left;
                    else
                    {
                        node<T> *newNode = new node<T>;
                        newNode->left = nullptr;
                        newNode->right = nullptr;
                        newNode->parrent = currentNode;
                        newNode->value = element;
                        currentNode->left = newNode;
                        return;
                    }
                }
                else if (currentNode->value < element)
                {
                    if (currentNode->right != nullptr)
                        currentNode = currentNode->right;
                    else
                    {
                        node<T> *newNode = new node<T>;
                        newNode->left = nullptr;
                        newNode->right = nullptr;
                        newNode->parrent = currentNode;
                        newNode->value = element;
                        currentNode->right = newNode;
                        return;
                    }
                }
                else
                    return;
            }
        }
    }
    void Delete(T element)
    {
        if (!Find(element))
        {
            return;
        }
        if (root->value == element)
        {
            if (root->left == nullptr && root->right == nullptr)
            {
                delete root;
                root = nullptr;
            }
            else
                cout << "Invalid Operation" << endl;
            return;
        }
        else
        {
            node<T> *currentNode = root;
            while (1)
            {
                if (currentNode->value > element)
                {
                    if (currentNode->left != nullptr)
                        currentNode = currentNode->left;
                    else
                        return;
                }
                else if (currentNode->value < element)
                {
                    if (currentNode->right != nullptr)
                        currentNode = currentNode->right;
                    else
                        return;
                }
                else
                {
                    if (currentNode->left == nullptr && currentNode->right == nullptr)
                    {
                        node<T> *del = currentNode;
                        if (currentNode->parrent->left == currentNode)
                        {
                            currentNode->parrent->left = nullptr;
                            delete del;
                        }
                        else if (currentNode->parrent->right == currentNode)
                        {
                            currentNode->parrent->right = nullptr;
                            delete del;
                        }
                    }
                    else
                        cout << "Invalid Operation" << endl;
                    return;
                }
            }
        }
    }
    bool Find(T element)
    {
        node<T> *currentNode = root;
        while (1)
        {
            if (currentNode == nullptr)
                return false;
            else if (currentNode->value == element)
                return true;
            else if (currentNode->value > element)
                currentNode = currentNode->left;
            else if (currentNode->value < element)
                currentNode = currentNode->right;
        }
    }
    void InorderTraversal()
    {
        InorderTraversal(root);
    }
    void InorderTraversal(node<T> *p)
    {
        if (p == nullptr)
            return;
        InorderTraversal(p->left);
        cout << p->value << " ";
        InorderTraversal(p->right);
        if (p == root)
            cout << endl;
    }
    void PreorderTraversal()
    {
        PreorderTraversal(root);
    }
    void PreorderTraversal(node<T> *p)
    {
        if (p == nullptr)
            return;
        cout << p->value << " ";
        PreorderTraversal(p->left);
        PreorderTraversal(p->right);
        if (p == root)
            cout << endl;
    }
    void PostorderTraversal()
    {
        PostorderTraversal(root);
    }
    void PostorderTraversal(node<T> *p)
    {
        if (p == nullptr)
            return;
        PostorderTraversal(p->left);
        PostorderTraversal(p->right);
        cout << p->value << " ";
        if (p == root)
            cout << endl;
    }
    void display()
    {
        display(root);
    }
    void display(node<T> *p)
    {
        if (p == nullptr)
        {
            return;
        }
        cout << p->value;
        if (p->left != nullptr || p->right != nullptr)
        {
            cout << '(';
            display(p->left);
            cout << ')';
            cout << '(';
            display(p->right);
            cout << ')';
        }
        if (p == root)
            cout << endl;
    }
};
