#include "my_hash_table.hh"

bool my_hash_table_::is_contain(const std::string &name, SymbolKind kind)
{
    if(map.find(name) == map.end())
        return false;
    for(auto &x : map[name]) {
        if(x->kind == kind) {
            return true;
        }
    }
    return false;
}
Symbol my_hash_table_::get_symbol(const std::string &name, SymbolKind kind)
{
    for (auto &x : map[name])
    {
        if (x->kind == kind)
        {
            return x;
        }
    }
    return nullptr;
}

void my_hash_table_::insert(Symbol symbol)
{
    map[symbol->name].push_back(symbol);
}