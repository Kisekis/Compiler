#ifndef SYMBOL_HH
#define SYMBOL_HH
#include <variant>
#include <string>
#include <list>
#include <iostream>
#include <memory>
struct Field_;
struct Func_;
struct ArrayType_;
struct Type_;
struct Param_;
typedef std::shared_ptr<Field_> Field;
typedef std::list<Field> FieldType_;
typedef std::shared_ptr<ArrayType_> ArrayType;
typedef std::shared_ptr<FieldType_> FieldType;
typedef std::shared_ptr<Func_> Func;
typedef std::shared_ptr<Param_> Param;
typedef std::shared_ptr<Type_> Type;

enum TypeKind
{
    BASIC,
    ARRAY,
    STRUCTURE
};
enum BasicType
{
    FLOAT,
    INT
};
struct ArrayType_
{
    Type elem;
    int *size;
    int pos;
    ~ArrayType_(){
        delete[] size;
    }
};

struct Field_
{
    Type type;
    std::string name;
};



struct Type_
{
    TypeKind kind;
    std::variant<BasicType, ArrayType, FieldType> content;
    bool is_lvalue;
    Type_(TypeKind kind, BasicType btype, bool l = false): kind(kind), is_lvalue(l)
    {
        content.emplace<BasicType>(btype);
    }
    Type_(TypeKind kind) : kind(kind){
        if(kind == ARRAY) {
            content.emplace<ArrayType>(std::make_shared<ArrayType_>());
        }
        else if (kind == STRUCTURE) {
            content.emplace<FieldType>(std::make_shared<FieldType_>());
        }
    };
    Type_() {
        
    }
    // Type_(TypeKind kind, ArrayType atype): kind(kind)
    // {
    //     content = atype;
    // }
};



enum SymbolKind
{
    VAR,
    FIELD,
    STRUCT,
    FUNC
};


struct Param_
{
    Type type;
    Param next;
};
struct Func_
{
    Type ret;
    int param_num;
    Param param;
    int line_num;
    bool is_dec;
    bool is_def;
};

struct Symbol_
{
    std::string name;
    SymbolKind kind;
    std::variant<Type, Func> sign;
    bool is_param;
    Symbol_(const std::string &name, SymbolKind kind) :
                name(name), kind(kind) {
        if (kind == FUNC) {
            sign.emplace<Func>(std::make_shared<Func_>());
        }
        else
        {
            sign.emplace<Type>(std::make_shared<Type_>());
        }
        }
};
struct SymbolList_;
typedef std::shared_ptr<Symbol_> Symbol;
typedef std::shared_ptr<SymbolList_> SymbolList;
struct SymbolList_
{
    Symbol symbol;
    SymbolList next{nullptr};
    SymbolList layer_next{nullptr};
};


SymbolList create_symbol_list(const std::string &name, SymbolKind kind);
int compute_type_size(const Type &t);
int get_field_loc(const Type &structure, const std::string &name);

#endif