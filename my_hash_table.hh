#ifndef HASH_TABLE_HH
#define HASH_TABLE_HH
#include "symbol.hh"
#include <unordered_map>
#include <vector>
#include <memory>
typedef std::unordered_map<std::string, std::vector<Symbol>> Umap;
struct my_hash_table_;
typedef std::unique_ptr<my_hash_table_> my_hash_table;
struct my_hash_table_
{
    Umap map;
    bool is_contain(const std::string &name, SymbolKind kind);
    Symbol get_symbol(const std::string &name, SymbolKind kind);
    void insert(Symbol symbol);
};

#endif