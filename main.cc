#include <iostream>
#include "driver.hh"
#include "ast.hh"
#include "semantic.hh"
#include <memory>
extern std::unique_ptr<AST> ast;
extern void semantic(struct Node *node);
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
            // std::cout << drv.result << '\n';
            ast->print_tree(ast->root);
            semantic(ast->root);
        }
        else res = 1;
    return res;
}