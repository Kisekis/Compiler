#include "symbol.hh"
#include <string>
#include <iostream>

int compute_type_size(const Type& t)
{
    switch (t->kind)
    {
    case BASIC:
        return 4;
    case ARRAY:
        return std::get<ArrayType>(t->content)->size[0] * compute_type_size(std::get<ArrayType>(t->content)->elem);
    case STRUCTURE:
    {
        int sz = 0;
        auto &list = std::get<FieldType>(t->content);
        for (auto it = list->begin(); it != list->end();it++) {
            sz += compute_type_size((*it)->type);
        }
        return sz;
    }
    }
}
int get_field_loc(const Type &structure, const std::string& name)
{
    if (structure->kind != STRUCTURE)
    {
        printf("Not a structure\n");
    }
    auto &list = std::get<FieldType>(structure->content);
    int loc = 0;
    for (auto it = list->begin(); it != list->end();it++) {
        if((*it)->name == name) {
            return loc; 
        }else {
            loc += compute_type_size((*it)->type);
        }
    }
    return loc;
}