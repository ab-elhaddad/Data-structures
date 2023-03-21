#  Implementation:
```cpp
template <typename T> // Using Generic Template to store any comparable data type in the value variable
struct TreeNode       // This struct is gonna be used for the binary search tree nodes
{
    T value;         // To store the node's value
    TreeNode *right; // To store the right child node's refrence
    TreeNode *left;  // To store the left child node's refrence

    TreeNode()
    {
        value = "";
        right = nullptr; // Setting the right child node's refrence to NULL to know in the future there is no right child
        left = nullptr;  // Setting the left child node's refrence to NULL to know in the future there is no left child
    };

    TreeNode(T value)
    {
        this->value = value;
        right = nullptr;
        left = nullptr;
    }

    TreeNode(T value, TreeNode *right, TreeNode *left)
    {
        this->value = value;
        this->right = right;
        this->left = left;
    }
};

template <typename T> // Using Generic Template to use the tree with any comparable datatype
class Tree            // The class that contains all the interesting work :)
{
private:
    TreeNode<T> *head; // Declaring the head node

public:
    Tree()
    {
        head = nullptr; // If we initialize an object from the class without passing starting value we will set the head node to NULL
    }

    Tree(T &el)
    {
        head = new TreeNode(el); // If we initialize an object from the class passing starting value we will set the head node to a new node which its value is the passed value
    }

    void insert(T el)
    {
        if (!head)                   // Checking whether the head node exists or not
            head = new TreeNode(el); // If not (means that our tree is empty) then we will set the head node to a new node with the passed element
        else
            insertRec(el, head); // If the head node exists then we will have to traverse through the tree to find the right place for our passed element
    }

    void insertRec(T &el, TreeNode<T> *curr)
    {
        if (el > (curr->value)) // If the passed element is bigger than the current node's value, Then we will go to the right branch
        {
            if (!curr->right) // If the right child node is NULL that means it is the intended node to insert our element
                curr->right = new TreeNode(el);
            else // If the right child node not NULL then we will enter it to continue traversing
                insertRec(el, curr->right);
        }
        else // If the passed element is less than or equal to the current node's value, Then we will go to the left branch
        {
            if (!curr->left)
                curr->left = new TreeNode(el);
            else
                insertRec(el, curr->left);
        }
    }

    bool search(T el)
    {
        return searchRec(el, head); // Start to traverse through the tree to find the intended value
    }

    bool searchRec(T &el, TreeNode<T> *curr)
    {
        if (curr == nullptr) // If I reached a NULL node that means the intended value does not exist, Thus we will return false
            return false;
        if (el == curr->value) // If the current node's value equals the intended value we will stop traversing and return true
            return true;

        if (el > (curr->value)) // If the passed element is bigger than the current node's value, Then we will go to the right branch
            return searchRec(el, curr->right);

        else // If the passed element is less than or equal to the current node's value, Then we will go to the left branch
            return searchRec(el, curr->left);
    }
};
```
