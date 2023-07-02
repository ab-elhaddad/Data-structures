#include <map>
#include <string>
using namespace std;

// Define a struct for a Trie node
struct node
{
    char val;                 // Value of the node
    bool isEnd;               // Flag indicating if it's the end of a word
    map<char, node *> childs; // Map to store child nodes

    // Constructor for the node
    node(char v)
    {
        val = v;
        isEnd = false;
    }
};

// Define a Trie class
class Trie
{
private:
    node *head; // Pointer to the head node of the Trie

public:
    // Constructor for the Trie class
    Trie()
    {
        head = new node('*'); // Create the head node with value '*' (just a dummy value)
    }

    // Function to insert a word into the Trie
    void insert(string word)
    {
        node *curr = head; // Start from the head node
        for (char c : word)
        {
            if (curr->childs.count(c) == 0)
                curr->childs[c] = new node(c); // Create a new node if the character is not present in the child nodes

            curr = curr->childs[c]; // Move to the next node
        }
        curr->isEnd = true; // Mark the last node as the end of the word
    }

    // Function to search for a word in the Trie
    bool search(string word)
    {
        node *curr = head; // Start from the head node
        int n = word.length();
        int i = 0;
        while (i < n)
        {
            if (curr->childs.count(word[i]) == 0)
                return false; // Return false if the character is not present in the child nodes

            curr = curr->childs[word[i]]; // Move to the next node

            if (i == n - 1 && !(curr->isEnd))
                return false; // If it's the last character but not the end of a word, return false

            i++;
        }
        return true; // Return true if the word is found in the Trie
    }

    // Function to check if a prefix exists in the Trie
    bool startsWith(string prefix)
    {
        node *curr = head; // Start from the head node
        for (char c : prefix)
        {
            if (curr->childs.count(c) == 0)
                return false; // Return false if the character is not present in the child nodes

            curr = curr->childs[c]; // Move to the next node
        }
        return true; // Return true if the prefix exists in the Trie
    }
};
