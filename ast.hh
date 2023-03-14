#ifndef AST_HH
#define AST_HH
#include "node.hh"
class AST
{
public:
    AST() {}
    AST(Node *root) : root(root) {}
    Node *root{nullptr};

    void print_tree(Node *node);
    ~AST() { delete_node(root); }

private:
    void delete_node(Node *root);
};
#endif