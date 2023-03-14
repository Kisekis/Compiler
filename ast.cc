#include "ast.hh"
#include <variant>
void AST::print_tree(Node *node)
{
    if (node == NULL)
    {
        return;
    }
    struct Node *cur = node;
    while (cur != NULL)
    {
        if (cur != this->root)
        {
            cur->m_layer = cur->m_parent->m_layer + 1;
            for (int i = 0; i < cur->m_layer; i++)
            {
                printf("  ");
            }
        }
        printf("%s", cur->m_name.c_str());
        printf(" %d", cur->production_id);
        switch (cur->m_type)
        {
        case Node::non_end:
            printf(" (%d)", cur->m_line_num);
            break;
        case Node::end:
            break;
        case Node::int_node:
            printf(": %d", std::get<int>(cur->m_value));
            break;
        case Node::float_node:
            printf(": %f", std::get<float>(cur->m_value));
            break;
        case Node::string_node:
            printf(": %s", std::get<std::string>(cur->m_value).c_str());
            break;
        }
        if (cur->m_name == "RELOP")
        {
            printf(" %s", std::get<std::string>(cur->m_value).c_str());
        }
        printf(" \n");
        print_tree(cur->m_first_child);
        cur = cur->m_next;
    }
}

void AST::delete_node(struct Node *root)
{
    if (root == NULL)
    {
        return;
    }
    struct Node *cur = root->m_first_child;
    while (cur != NULL)
    {
        delete_node(cur);
        cur = cur->m_next;
    }
    delete root;
}