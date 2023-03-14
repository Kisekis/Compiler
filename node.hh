#ifndef NODE_HH
#define NODE_HH
#include <string>
#include <variant>
class Node
{
public:
    enum node_type
    {
        non_end,
        end,
        int_node,
        string_node,
        float_node
    };
    Node(int line_num, const std::string &name, node_type type) : m_line_num(line_num),
                                                                  m_name(name), m_type(type) {}
    Node(int line_num, const std::string &name, node_type type, int proid) : m_line_num(line_num),
                                                                             m_name(name), m_type(type), production_id(proid) {}
    // union
    // {
    //     int type_int;
    //     float type_float;
    //     std::string type_string;
    // };
    std::variant<int, float, std::string> m_value;
    node_type m_type;
    int m_line_num;
    std::string m_name;
    Node *m_next{nullptr};
    Node *m_first_child{nullptr};
    Node *m_last_child{nullptr};
    Node *m_parent{nullptr};
    int m_children_num{0};
    int m_layer{0};
    int production_id{0};
    int index{0};
    ~Node()
    {
    }
};
extern void add_child(struct Node *parent, struct Node *child, int index);
#endif