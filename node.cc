#include "node.hh"

void add_child(struct Node *parent, struct Node *child, int index)
{
    if (child == NULL)
        return;
    child->index = index;
    if (parent->m_first_child == NULL)
    {
        parent->m_first_child = child;
        parent->m_last_child = child;
    }
    else
    {
        parent->m_last_child->m_next = child;
        parent->m_last_child = child;
    }
    parent->m_children_num++;
    // parent->layer = child->layer+1;
    child->m_parent = parent;
}