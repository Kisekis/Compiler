#include <iostream>
#include "driver.hh"
extern Node *root;
extern void print_tree(struct Node *root);
extern void delete_tree(struct Node *root);
int main(int argc, char *argv[])
{
    int res = 0;
    driver drv;
    for (int i = 1; i < argc; ++i)
        if (argv[i] == std::string("-p"))
            drv.trace_parsing = true;
        else if (argv[i] == std::string("-s"))
            drv.trace_scanning = true;
        else if (!drv.parse(argv[i]))
        {
            std::cout << drv.result << '\n';
            print_tree(root);
        }   
        else res = 1;
    return res;
}