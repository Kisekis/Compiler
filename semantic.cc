#include "semantic.hh"
#include "symbol.hh"
#include "my_hash_table.hh"
#include "node.hh"
my_hash_table table;
using std::make_shared;
using std::move;
bool debug = true;
struct Node *kth_next(struct Node *node, int k)
{
    struct Node *cur = node;
    for (int i = 0; i < k; i++)
    {
        if (cur == NULL)
            return NULL;
        cur = cur->m_next;
    }
    return cur;
}

int comp(struct Node *node)
{
    int i = 0;
    struct Node *cur = node;
    while (cur != NULL)
    {
        i = i * 10;
        i += cur->index;
        cur = cur->m_next;
    }
    return i;
}

void init()
{
    // table;
    table = std::make_unique<my_hash_table_>();
    unnamed = 0;

    Symbol read(make_shared<Symbol_>("read", FUNC));

    Type int_type(make_shared<Type_>(BASIC, INT));
    std::get<Func>(read->sign)->ret = int_type;
    std::get<Func>(read->sign)->param_num = 0;
    table->insert(read);

    Symbol write(make_shared<Symbol_>("write", FUNC));
    std::get<Func>(write->sign)->ret = int_type;
    std::get<Func>(write->sign)->param_num = 1;

    Param p(make_shared<Param_>());
    p->type = int_type;
    std::get<Func>(write->sign)->param = p;
    // // Param p(make_shared<Param_>(BASIC, INT));
    // // // Param p = (Param)malloc(sizeof(struct Param_));
    // // p->type = int_type;
    // write->u.func->param = p;
    table->insert(write);
}

// void check_all_func_defined()
// {
//     for (int i = 0; i < MAX; i++)
//     {
//         SymbolList func_list = table->Func->buckets[i].list;
//         if (func_list != NULL)
//         {
//             SymbolList cur = func_list;
//             while (cur != NULL)
//             {
//                 if (cur->symbol->u.func->is_dec && !cur->symbol->u.func->is_def)
//                 {
//                     ////fprintf(stderr, "ERROR type %d at Line %d: %s\n", 18, cur->symbol->u.func->line_num, "No definition");
//                 }
//                 cur = cur->next;
//             }
//         }
//     }
// }
// bool is_equal_func(Func a, Func b)
// {
//     if (!is_equal_type(a->ret, b->ret))
//     {
//         return false;
//     }
//     if (a->param_num != b->param_num)
//     {
//         return false;
//     }
//     if (!is_equal_args(a->param, b->param, b->param_num))
//     {
//         return false;
//     }
//     return true;
// }
// void print_type(Type a)
// {
//     if (a == NULL)
//     {
//         printf("this is a null type\n");
//         return;
//     }
//     switch (a->kind)
//     {
//     case BASIC:

//         switch (a->u.basic)
//         {
//         case FLOAT:
//             printf("this is a BASIC FLOAT type\n");
//             break;
//         case INT:
//             printf("this is a BASIC INT type\n");
//             break;
//         }
//         break;
//     case ARRAY:
//         printf("this is a ARRAY type\n");
//         break;
//     case STRUCTURE:
//     {
//         FieldList s = a->u.structure;
//         printf("this is a STRUCT type begin\n");
//         while (s != NULL)
//         {
//             printf(s->name);
//             print_type(s->type);
//             s = s->next;
//         }
//         printf("this is a STRUCT type end\n");
//         break;
//     }
//     }
// }

// void print_field_list(FieldList list)
// {
//     FieldList cur = list;
//     while (cur != NULL)
//     {
//         print_type(cur->type);
//         printf("%s\n", cur->name);
//         cur = cur->next;
//     }
// }
// bool is_equal_type(Type a, Type b)
// {
//     if (a == NULL || b == NULL)
//     {
//         return false;
//     }
//     if (a->kind != b->kind)
//     {
//         return false;
//     }
//     switch (a->kind)
//     {
//     case BASIC:
//     {
//         if (a->u.basic != b->u.basic)
//         {
//             return false;
//         }
//     }
//     break;
//     case ARRAY:
//     {
//         if (!is_equal_type(a->u.array.elem, b->u.array.elem))
//         {
//             return false;
//         }
//         if (a->u.array.size != b->u.array.size)
//         {
//             return false;
//         }
//     }
//     break;
//     case STRUCTURE:
//     {
//         FieldList fa = a->u.structure;
//         FieldList fb = b->u.structure;
//         while (fa != NULL && fb != NULL)
//         {
//             // 结构等价
//             //  if (strcmp(fa->name, fb->name) != 0)
//             //  {
//             //      return false;
//             //  }
//             if (!is_equal_type(fa->type, fb->type))
//             {
//                 return false;
//             }
//             fa = fa->next;
//             fb = fb->next;
//         }
//         if (fa != NULL || fb != NULL)
//         {
//             return false;
//         }
//     }
//     break;
//     }
//     return true;
// }

// bool is_equal_args(Param a, Param b, int b_num)
// {
//     Param pa = a;
//     Param pb = b;
//     int count = 0;
//     while (pa != NULL && pb != NULL)
//     {
//         if (!is_equal_type(pa->type, pb->type))
//         {
//             return false;
//         }
//         pa = pa->next;
//         pb = pb->next;
//         count++;
//     }
//     if (pa != NULL)
//         return false;
//     if (count != b_num)
//     {
//         return false;
//     }
//     return true;
// }
void semantic(struct Node *node)
{
    init();
    check_Program(node);
}


// bool is_FLOAT(Type type)
// {
//     if (type == NULL)
//         return false;
//     if (type->kind != BASIC || type->u.basic != FLOAT)
//     {
//         return false;
//     }
//     return true;
// }
// FieldList get_fields(SymbolList list)
// {

//     SymbolList cur = list;
//     FieldList dummy = (FieldList)malloc(sizeof(struct FieldList_));
//     FieldList f_list = dummy;
//     while (cur != NULL && cur->symbol != NULL)
//     {
//         FieldList new_field = (FieldList)malloc(sizeof(struct FieldList_));
//         new_field->name = cur->symbol->name;
//         new_field->type = cur->symbol->u.type;
//         f_list->next = new_field;
//         f_list = f_list->next;
//         cur = cur->next;
//     }
//     return dummy->next;
// }

void check_Program(struct Node *node)
{
    if (node == NULL)
    {
        return;
    }
    if (debug)
        printf("%s is checked, line num is %d\n", node->m_name.c_str(), node->m_line_num);

    switch (node->production_id)
    {
    case 1:
        check_ExtDefList(node->m_first_child);
        break;
    case 0:
        break;
    }
}
void check_ExtDefList(struct Node *node)
{
    if (node == NULL)
    {
        return;
    }
    if (debug)
        printf("%s is checked, line num is %d\n", node->m_name.c_str(), node->m_line_num);

    switch (node->production_id)
    {
    case 1:
        check_ExtDef(node->m_first_child);
        check_ExtDefList(kth_next(node->m_first_child, 1));
        break;
    case 0:
        break;
    }
}
void check_ExtDef(struct Node *node)
{
    if (node == NULL)
    {
        return;
    }
    if (debug)
        printf("%s is checked, line num is %d\n", node->m_name.c_str(), node->m_line_num);

    switch (node->production_id)
    {
    case 1:
    {
        Type type = check_Specifier(node->m_first_child);
        check_ExtDecList(kth_next(node->m_first_child, 1), move(type));
        break;
    }

    case 2:
    {
        check_Specifier(node->m_first_child);
        break;
    }
    case 3:
    {
        Type type = check_Specifier(node->m_first_child);
        Type new_type(make_shared<Type_>(type->kind));
        new_type->kind = type->kind;
        new_type->is_lvalue = false;
        switch (new_type->kind)
        {
        case BASIC:
            new_type->content.emplace<BasicType>(std::get<BasicType>(type->content));
            break;
        case ARRAY:
            new_type->content.emplace<ArrayType>(std::get<ArrayType>(type->content));
            break;
        case STRUCTURE:
            new_type->content.emplace<FieldType>(std::get<FieldType>(type->content));
            break;
        }
        Symbol fun_dec = check_FunDec(kth_next(node->m_first_child, 1), move(new_type), false);
        check_CompSt(kth_next(node->m_first_child, 2), fun_dec);
        break;
    }
    case 4:
    {
        Type type = check_Specifier(node->m_first_child);
        Type new_type(make_shared<Type_>(type->kind));
        new_type->is_lvalue = false;
        switch (new_type->kind)
        {
        case BASIC:
            new_type->content.emplace<BasicType>(std::get<BasicType>(type->content));
            break;
        case ARRAY:
            new_type->content.emplace<ArrayType>(std::get<ArrayType>(type->content));
            break;
        case STRUCTURE:
            new_type->content.emplace<FieldType>(std::get<FieldType>(type->content));
            break;
        }
        Symbol fun_dec = check_FunDec(kth_next(node->m_first_child, 1), move(new_type), true);
        break;
    }
    case 0:
        break;
    }
}
void check_ExtDecList(struct Node *node, Type type)
{
    if (node == NULL)
        return;
    if (debug)
        printf("%s is checked, line num is %d\n", node->m_name.c_str(), node->m_line_num);

    switch (node->production_id)
    {
    case 1:
        check_VarDec(node->m_first_child, VAR, move(type));
        break;
    case 2:

        check_VarDec(node->m_first_child, VAR, move(type));
        check_ExtDecList(kth_next(node->m_first_child, 2), move(type));
        break;
    case 0:
        break;
    }
}
Type check_Specifier(struct Node *node)
{
    if (node == NULL)
        return NULL;
    if (debug)
        printf("%s is checked, line num is %d\n", node->m_name.c_str(), node->m_line_num);
    switch (node->production_id)
    {
    case 1:
        return check_TYPE(node->m_first_child);
        break;
    case 2:
        // check_StructSpecifier(node->m_first_child);
        break;
    case 0:
        break;
    }
}
Type check_TYPE(struct Node *node)
{
    if (node == NULL)
    {
        return NULL;
    }
    if (std::get<std::string>(node->m_value) == "int")
    {
        Type int_type(make_shared<Type_>(BASIC, INT));
        return int_type;
    }
    else if (std::get<std::string>(node->m_value) == "float")
    {
        Type int_type(make_shared<Type_>(BASIC, FLOAT));
        return int_type;
    }
    else
    {
        return NULL;
    }
}
// Type check_StructSpecifier(struct Node *node)
// {
//     if (node == NULL)
//         return NULL;
//     if (debug)
//         printf("%s is checked, line num is %d\n", node->m_name.c_str(), node->m_line_num);

//     switch (node->production_id)
//     {
//     case 1:
//         switch (comp(node->m_first_child))
//         {
//         case 1345: // STRUCT LC DefList RC
//         {
//             unnamed++;
//             char name[32];
//             sprintf(name, "%d_unnamed", unnamed);
//             char *struct_name = (char *)malloc(32 * sizeof(char));
//             strcpy(struct_name, name);
//             bool is_insert = false;
//             Type type = (Type)malloc(sizeof(struct Type_));
//             type->kind = STRUCTURE;
//             type->u.structure = check_DefList(kth_next(node->m_first_child, 2), FIELD);
//             type->is_lvalue = false;
//             // type->u.structure->name = id;
//             Symbol symbol = create_symbol(struct_name, STRUCT);
//             symbol->u.type = type;
//             insert(table, symbol);
//             return type;
//             break;
//         }

//         case 12345: // STRUCT OptTag LC DefList RC
//         {
//             char *id = kth_next(node->m_first_child, 1)->m_first_child->m_value.type_string;
//             bool is_insert = false;
//             if (is_contain(table, id, STRUCT) || is_contain(table, id, VAR))
//             {
//                 // fprintf(stderr, "ERROR type %d at Line %d: %s\n", 16, kth_next(node->m_first_child, 1)->m_line_num, "Duplicated Struct Definition");
//                 is_insert = true;
//             }
//             Type type = (Type)malloc(sizeof(struct Type_));
//             type->kind = STRUCTURE;
//             type->u.structure = check_DefList(kth_next(node->m_first_child, 3), FIELD);
//             type->is_lvalue = false;
//             if (!is_insert)
//             {
//                 Symbol symbol = create_symbol(id, STRUCT);
//                 symbol->u.type = type;
//                 insert(table, symbol);
//             }
//             return type;
//             break;
//         }

//         case 135: // STRUCT LC RC
//         {
//             unnamed++;
//             char name[32];
//             sprintf(name, "%d_unnamed", unnamed);
//             char *struct_name = (char *)malloc(32 * sizeof(char));
//             strcpy(struct_name, name);
//             Type type = (Type)malloc(sizeof(struct Type_));
//             type->kind = STRUCTURE;
//             type->u.structure = NULL;
//             type->is_lvalue = false;
//             Symbol symbol = create_symbol(struct_name, STRUCT);
//             symbol->u.type = type;
//             insert(table, symbol);
//             return type;
//             break;
//         }

//         case 1235: // STRUCT OptTag LC RC
//         {
//             char *id = kth_next(node->m_first_child, 1)->m_first_child->m_value.type_string;
//             bool is_insert = false;
//             if (is_contain(table, id, STRUCT) || is_contain(table, id, VAR))
//             {
//                 // fprintf(stderr, "ERROR type %d at Line %d: %s\n", 16, node->m_first_child->m_line_num, "Duplicated Struct Definition");
//                 is_insert = true;
//             }
//             Type type = (Type)malloc(sizeof(struct Type_));
//             type->kind = STRUCTURE;
//             type->u.structure = NULL;
//             type->is_lvalue = false;
//             // type->u.structure->name = id;
//             if (!is_insert)
//             {
//                 Symbol symbol = create_symbol(id, STRUCT);
//                 symbol->u.type = type;
//                 insert(table, symbol);
//             }
//             return type;
//         }
//         }
//         break;
//     case 2: // STRUCT Tag
//     {
//         char *id = kth_next(node->m_first_child, 1)->m_first_child->m_value.type_string;
//         if (is_contain(table, id, STRUCT) || is_contain(table, id, VAR))
//         {
//             Symbol st = get_symbol(table, id, STRUCT);
//             if (st == NULL)
//             {
//                 // fprintf(stderr, "ERROR type %d at Line %d: %s\n", 17, node->m_first_child->m_line_num, "Struct not defined");
//             }
//             else
//             {
//                 return st->u.type;
//             }
//         }
//         else
//         {
//             // fprintf(stderr, "ERROR type %d at Line %d: %s\n", 17, node->m_first_child->m_line_num, "Struct not defined");
//             return NULL;
//         }
//     }
//         // check_Tag(kth_next(node->m_first_child, 1));
//     case 0:
//         break;
//     }
// }
void check_OptTag(struct Node *node)
{
    if (node == NULL)
        return;
    if (debug)
        printf("%s is checked, line num is %d\n", node->m_name.c_str(), node->m_line_num);

    switch (node->production_id)
    {
    case 1:
        break;
    case 0:
        break;
    }
}

void check_Tag(struct Node *node)
{
    if (node == NULL)
        return;
    if (debug)
        printf("%s is checked, line num is %d\n", node->m_name.c_str(), node->m_line_num);

    switch (node->production_id)
    {
    case 1:
        break;
    case 0:
        break;
    }
}
Symbol check_VarDec(struct Node *node, SymbolKind kind, Type type)
{
    if (node == NULL)
        return NULL;
    if (debug)
        printf("%s is checked, line num is %d\n", node->m_name.c_str(), node->m_line_num);
    switch (node->production_id)
    {
    case 1:
    {
        struct Node *id = node->m_first_child;
        Symbol new_symbol(make_shared<Symbol_>(std::get<std::string>(id->m_value), FUNC));
        new_symbol->sign.emplace<Type>(move(type));
        bool is_insert = false;
        switch (kind)
        {
        case VAR:
        {
            if (table->is_contain(std::get<std::string>(id->m_value), VAR) || table->is_contain(std::get<std::string>(id->m_value), FIELD) || table->is_contain(std::get<std::string>(id->m_value), STRUCT))
            {
                is_insert = true;
                // fprintf(stderr, "ERROR type %d at Line %d: %s\n", 3, node->m_first_child->m_line_num, "Varible already defined");
                break;
            }
        }
        break;
        case FIELD:
        {
            if (table->is_contain(std::get<std::string>(id->m_value), VAR) || table->is_contain(std::get<std::string>(id->m_value), FIELD))
            {
                is_insert = true;
                // fprintf(stderr, "ERROR type %d at Line %d: %s\n", 15, node->m_first_child->m_line_num, "Field already defined");
                break;
            }
        }
        break;
        }
        if (!is_insert)
        {
            table->insert(new_symbol);
        }
        return new_symbol;
        break;
    }
    case 2:
    {
        Symbol symbol = check_VarDec(node->m_first_child, kind, move(type));
        if (symbol != NULL)
        {
            if (node->m_first_child->production_id == 1)
            {
                Type array(make_shared<Type_>(ARRAY));
                std::get<ArrayType>(array->content)->elem = std::get<Type>(move(symbol->sign));
                std::get<ArrayType>(array->content)->size = (int *)malloc(16 * sizeof(int));
                std::get<ArrayType>(array->content)->pos = 0;
                array->is_lvalue = false;
                std::get<ArrayType>(array->content)->size[std::get<ArrayType>(array->content)->pos] = std::get<int>(kth_next(node->m_first_child, 2)->m_value);
                std::get<ArrayType>(array->content)->pos++;
                symbol->sign.emplace<Type>(move(array));
                // symbol->u.type = array;
            }
            else
            {
                std::get<ArrayType>(std::get<Type>(symbol->sign)->content)->size[std::get<ArrayType>(std::get<Type>(symbol->sign)->content)->pos] = std::get<int>(kth_next(node->m_first_child, 2)->m_value);
                std::get<ArrayType>(std::get<Type>(symbol->sign)->content)->pos++;
            }
        }
        return symbol;
        break;
    }
    case 0:
        break;
    }
    return NULL;
}
Symbol check_FunDec(struct Node *node, Type type, bool is_dec)
{
    if (node == NULL)
        return NULL;
    if (debug)
        printf("%s is checked, line num is %d\n", node->m_name.c_str(), node->m_line_num);

    switch (node->production_id)
    {
    case 1:
    {
        struct Node *id = node->m_first_child;
        if (true || !is_dec)
        {
            if (table->is_contain(std::get<std::string>(id->m_value), FUNC))
            {
                // if (get_symbol(table, id->m_value.type_string, FUNC)->u.func->is_def)
                // {
                //     // fprintf(stderr, "ERROR type %d at Line %d: %s\n", 4, node->m_first_child->m_line_num, "Function already defined");
                // }
                // else
                // {
                //     get_symbol(table, id->m_value.type_string, FUNC)->u.func->is_def = true;
                // }
                return table->get_symbol(std::get<std::string>(id->m_value), FUNC);
            }
            Symbol func(make_shared<Symbol_>(std::get<std::string>(id->m_value), FUNC));
            std::get<Func>(func->sign)->ret = type;
            std::get<Func>(func->sign)->param_num = 0;
            std::get<Func>(func->sign)->param = check_VarList(kth_next(node->m_first_child, 2));
            std::get<Func>(func->sign)->line_num = node->m_first_child->m_line_num;
            std::get<Func>(func->sign)->is_def = true;
            std::get<Func>(func->sign)->is_dec = false;
            Param p = std::get<Func>(func->sign)->param;
            while (p != NULL)
            {
                p = p->next;
                std::get<Func>(func->sign)->param_num++;
            }
            table->insert(func);
            return func;
        }
        // else
        // {
        //     Param p = check_VarList(kth_next(node->m_first_child, 2));
        //     if (table->is_contain(std::get<std::string>(id->m_value), FUNC))
        //     {
        //         // Symbol func_def = get_symbol(table, id->m_value.type_string, FUNC);
        //         // if (!(is_equal_type(type, func_def->u.func->ret) && is_equal_args(p, func_def->u.func->param, func_def->u.func->param_num)))
        //         // {
        //         //     // fprintf(stderr, "ERROR type %d at Line %d: %s\n", 19, node->m_first_child->m_line_num, "Wrong Func Dec");
        //         //     return NULL;
        //         // }
        //         // get_symbol(table, id->m_value.type_string, FUNC)->u.func->is_dec = true;
        //         return get_symbol(table, id->m_value.type_string, FUNC);
        //     }
        //     Symbol new_func = create_symbol(id->m_value.type_string, FUNC);
        //     new_func->u.func->ret = type;
        //     new_func->u.func->param_num = 0;
        //     new_func->u.func->param = p;
        //     new_func->u.func->line_num = node->m_first_child->m_line_num;
        //     new_func->u.func->is_dec = true;
        //     new_func->u.func->is_def = false;
        //     Param p0 = new_func->u.func->param;
        //     while (p0 != NULL)
        //     {
        //         p0 = p0->next;
        //         new_func->u.func->param_num++;
        //     }
        //     insert(table, new_func);
        //     return new_func;
        // }
    }
    case 2:
    {
        struct Node *id = node->m_first_child;
        if (true || !is_dec)
        {
            if (table->is_contain(std::get<std::string>(id->m_value), FUNC))
            {
                // if (get_symbol(table, id->m_value.type_string, FUNC)->u.func->is_def)
                // {
                //     // fprintf(stderr, "ERROR type %d at Line %d: %s\n", 4, node->m_first_child->m_line_num, "Function already defined");
                // }
                // else
                // {
                //     get_symbol(table, id->m_value.type_string, FUNC)->u.func->is_def = true;
                // }
                return table->get_symbol(std::get<std::string>(id->m_value), FUNC);
            }
            Symbol func(make_shared<Symbol_>(std::get<std::string>(id->m_value), FUNC));
            std::get<Func>(func->sign)->ret = type;
            std::get<Func>(func->sign)->param_num = 0;
            std::get<Func>(func->sign)->param = NULL;
            std::get<Func>(func->sign)->line_num = node->m_first_child->m_line_num;
            std::get<Func>(func->sign)->is_def = true;
            std::get<Func>(func->sign)->is_dec = false;
            table->insert(func);
            return func;
        }
        // else
        // {
        //     if (is_contain(table, id->m_value.type_string, FUNC))
        //     {
        //         Symbol func_def = get_symbol(table, id->m_value.type_string, FUNC);
        //         if (!(is_equal_type(type, func_def->u.func->ret) && func_def->u.func->param_num == 0))
        //         {
        //             // fprintf(stderr, "ERROR type %d at Line %d: %s\n", 19, node->m_first_child->m_line_num, "Wrong Func Dec");
        //             return NULL;
        //         }
        //         get_symbol(table, id->m_value.type_string, FUNC)->u.func->is_dec = true;
        //         return get_symbol(table, id->m_value.type_string, FUNC);
        //     }
        //     Symbol func = create_symbol(id->m_value.type_string, FUNC);
        //     func->u.func->ret = type;
        //     func->u.func->param_num = 0;
        //     func->u.func->param = NULL;
        //     func->u.func->line_num = node->m_first_child->m_line_num;
        //     func->u.func->is_dec = true;
        //     func->u.func->is_def = false;
        //     insert(table, func);
        //     return func;
        // }
    }
    case 0:
        break;
    }
}
Param check_VarList(struct Node *node)
{
    if (node == NULL)
        return NULL;
    if (debug)
        printf("%s is checked, line num is %d\n", node->m_name.c_str(), node->m_line_num);

    switch (node->production_id)
    {
    case 1:
    {
        Param param = check_ParamDec(node->m_first_child);
        param->next = check_VarList(kth_next(node->m_first_child, 2));
        return param;
        break;
    }
    case 2:
        return check_ParamDec(node->m_first_child);
        break;
    case 0:
        break;
    }
    return NULL;
}
Param check_ParamDec(struct Node *node)
{
    if (node == NULL)
        return NULL;
    if (debug)
        printf("%s is checked, line num is %d\n", node->m_name.c_str(), node->m_line_num);

    switch (node->production_id)
    {
    case 1:
    {
        Type type = check_Specifier(node->m_first_child);
        Symbol symbol = check_VarDec(kth_next(node->m_first_child, 1), VAR, type);
        symbol->is_param = true;
        Param param(make_shared<Param_>());
        param->type = std::get<Type>(symbol->sign);
        param->next = NULL;
        return param;
        break;
    }
    case 0:
        break;
    }
}
void check_CompSt(struct Node *node, Symbol symbol)
{
    if (node == NULL)
        return;
    if (debug)
        printf("%s is checked, line num is %d\n", node->m_name.c_str(), node->m_line_num);
    switch (node->production_id)
    {
    case 1:
        switch (comp(node->m_first_child))
        {
        case 1234:
            check_DefList(kth_next(node->m_first_child, 1), VAR);
            check_StmtList(kth_next(node->m_first_child, 2), symbol);
            break;
        case 124:
            check_DefList(kth_next(node->m_first_child, 1), VAR);
            break;
        case 134:
            check_StmtList(kth_next(node->m_first_child, 1), symbol);
            break;
        case 14:
            break;
        }
        break;
    case 0:
        break;
    }
}
void check_StmtList(struct Node *node, Symbol symbol)
{
    if (node == NULL)
        return;
    if (debug)
        printf("%s is checked, line num is %d\n", node->m_name.c_str(), node->m_line_num);

    switch (node->production_id)
    {
    case 1:
        switch (comp(node->m_first_child))
        {
        case 12:
            check_Stmt(node->m_first_child, symbol);
            check_StmtList(kth_next(node->m_first_child, 1), symbol);
            break;
        case 1:
            check_Stmt(node->m_first_child, symbol);
            break;
        }
        break;
    case 0:
        break;
    }
}
void check_Stmt(struct Node *node, Symbol symbol)
{
    if (node == NULL)
        return;
    if (debug)
        printf("%s is checked, line num is %d\n", node->m_name.c_str(), node->m_line_num);
    switch (node->production_id)
    {
    case 1:
        check_Exp(node->m_first_child);
        break;
    case 2:
        check_CompSt(node->m_first_child, symbol);
        break;
    case 3: // return
    {
        Type t = check_Exp(kth_next(node->m_first_child, 1));
        break;
    }
    case 4:
    {
        Type cond = check_Exp(kth_next(node->m_first_child, 2));
        check_Stmt(kth_next(node->m_first_child, 4), symbol);
        break;
    }
    case 5:
    {
        Type cond = check_Exp(kth_next(node->m_first_child, 2));
        check_Stmt(kth_next(node->m_first_child, 4), symbol);
        check_Stmt(kth_next(node->m_first_child, 6), symbol);
        break;
    }
    case 6:
    {
        Type cond = check_Exp(kth_next(node->m_first_child, 2));
        check_Stmt(kth_next(node->m_first_child, 4), symbol);
        break;
    }
    case 0:
        break;
    }
}
FieldType check_DefList(struct Node *node, SymbolKind kind)
{
    if (node == NULL)
        return NULL;
    if (debug)
        printf("%s is checked, line num is %d\n", node->m_name.c_str(), node->m_line_num);

    switch (node->production_id)
    {
    case 1:
        switch (comp(node->m_first_child))
        {
        case 12: // Def DefList
            switch (kind)
            {
            case VAR:
                check_Def(node->m_first_child, kind);
                check_DefList(kth_next(node->m_first_child, 1), kind);
                break;
            // case FIELD:
            // {
            //     FieldList field = check_Def(node->m_first_child, kind);
            //     if (field == NULL)
            //     {
            //         return check_DefList(kth_next(node->m_first_child, 1), kind);
            //     }
            //     else
            //     {
            //         FieldList end = field;
            //         while (end->next != NULL)
            //         {
            //             end = end->next;
            //         }
            //         end->next = check_DefList(kth_next(node->m_first_child, 1), kind);
            //         return field;
            //     }
            //     break;
            // }
            }
            break;
        case 1: // Def
            switch (kind)
            {
            case VAR:
                check_Def(node->m_first_child, kind);
                return NULL;
                break;
            case FIELD:
                // return check_Def(node->m_first_child, kind);
                break;
            }
            break;
        }
        break;
    case 0:
        break;
    }
    return NULL;
}
FieldType check_Def(struct Node *node, SymbolKind kind)
{
    if (node == NULL)
        return NULL;
    if (debug)
        printf("%s is checked, line num is %d\n", node->m_name.c_str(), node->m_line_num);

    switch (node->production_id)
    {
    case 1:
    {
        Type type = check_Specifier(node->m_first_child);
        SymbolList list = check_DecList(kth_next(node->m_first_child, 1), kind, type);
        switch (kind)
        {
        case VAR:
            return NULL;
            break;
        // case FIELD:
        //     return get_fields(list);
        //     break;
        }
        break;
    }
    case 0:
        break;
    }
    return NULL;
}
SymbolList check_DecList(struct Node *node, SymbolKind kind, Type type)
{
    if (node == NULL)
        return NULL;
    if (debug)
        printf("%s is checked, line num is %d\n", node->m_name.c_str(), node->m_line_num);

    switch (node->production_id)
    {
    case 1:
    {

        Symbol dec = check_Dec(node->m_first_child, kind, type);
        SymbolList dec_list(make_shared<SymbolList_>());
        dec_list->symbol = dec;
        dec_list->next = NULL;
        return dec_list;
        break;
    }

    case 2:
    {
        Symbol dec = check_Dec(node->m_first_child, kind, type);
        SymbolList dec_list(make_shared<SymbolList_>());
        dec_list->symbol = dec;
        dec_list->next = check_DecList(kth_next(node->m_first_child, 2), kind, type);
        return dec_list;
        break;
    }

    case 0:
        break;
    }
}
Symbol check_Dec(struct Node *node, SymbolKind kind, Type type)
{
    if (node == NULL)
        return NULL;
    if (debug)
        printf("%s is checked, line num is %d\n", node->m_name.c_str(), node->m_line_num);

    switch (node->production_id)
    {
    case 1:
        return check_VarDec(node->m_first_child, kind, type);
        break;
    case 2:
    {

        Symbol var_dec = check_VarDec(node->m_first_child, kind, type);
        switch (kind)
        {
        case VAR:
        {
            Type exp_type = check_Exp(kth_next(node->m_first_child, 2));
            // if (!is_equal_type(type, exp_type))
            // {
            //     // fprintf(stderr, "ERROR type %d at Line %d: %s\n", 5, kth_next(node->m_first_child, 2)->m_line_num, "Declaration type wrong");
            // }
            return var_dec;
            break;
        }
        case FIELD:
            // fprintf(stderr, "ERROR type %d at Line %d: %s\n", 15, kth_next(node->m_first_child, 2)->m_line_num, "Initialize field when definiton");
            return var_dec;
            break;
        }
        break;
    }
    case 0:
        break;
    }
    return NULL;
}
Type check_Exp(struct Node *node)
{
    if (node == NULL)
        return NULL;
    if (debug)
        printf("%s is checked, line num is %d\n", node->m_name.c_str(), node->m_line_num);

    switch (node->production_id)
    {
    case 1: // Assignop
    {
        Type left = check_Exp(node->m_first_child);
        Type right = check_Exp(kth_next(node->m_first_child, 2));
        return left == NULL ? move(right) : move(left);
        break;
    }

    case 2: // AND
    {
        Type left = check_Exp(node->m_first_child);
        Type right = check_Exp(kth_next(node->m_first_child, 2));
        Type new_type(make_shared<Type_>(BASIC,INT));
        return new_type;
        break;
    }

    case 3: // or
    {
        Type left = check_Exp(node->m_first_child);
        Type right = check_Exp(kth_next(node->m_first_child, 2));
        Type new_type(make_shared<Type_>(BASIC, INT));
        return new_type;
        break;
    }

    case 4: // relop
    {

        Type left = check_Exp(node->m_first_child);
        Type right = check_Exp(kth_next(node->m_first_child, 2));
        Type new_type(make_shared<Type_>(BASIC, INT));
        return new_type;
        break;
    }

    case 5: // PLUS
    {
        Type left = check_Exp(node->m_first_child);
        Type right = check_Exp(kth_next(node->m_first_child, 2));
        return left == NULL ? move(right) : move(left);
        break;
    }

    case 6: // MINUS
    {
        Type left = check_Exp(node->m_first_child);
        Type right = check_Exp(kth_next(node->m_first_child, 2));
        return left == NULL ? move(right) : move(left);
        break;
    }

    case 7: // STAR
    {
        Type left = check_Exp(node->m_first_child);
        Type right = check_Exp(kth_next(node->m_first_child, 2));
        return left == NULL ? move(right) : move(left);
        break;
    }

    case 8: // DIV
    {
        Type left = check_Exp(node->m_first_child);
        Type right = check_Exp(kth_next(node->m_first_child, 2));
        return left == NULL ? move(right) : move(left);
        break;
    }

    case 9: // LP Exp RP
        return check_Exp(kth_next(node->m_first_child, 1));
        break;
    case 10: // MINUS EXP
    {
        Type type = check_Exp(kth_next(node->m_first_child, 1));
        return type;
        break;
    }

    case 11: // NOT EXP
    {
        Type type = check_Exp(kth_next(node->m_first_child, 1));
        Type new_type(make_shared<Type_>(BASIC,INT));
        return new_type;
        break;
    }

    case 12: // ID LP Args RP
    {
        struct Node *id = node->m_first_child;
        if (table->is_contain(std::get<std::string>(id->m_value), FUNC))
        {
            Symbol func = table->get_symbol(std::get<std::string>(id->m_value), FUNC);
            Param param = check_Args(kth_next(node->m_first_child, 2));
            return move(std::get<Func>(func->sign)->ret);
        }
        return NULL;

        break;
    }

    case 13: // ID LP RP
    {
        struct Node *id = node->m_first_child;
        if (table->is_contain(std::get<std::string>(id->m_value), FUNC))
        {
            Symbol func = table->get_symbol(std::get<std::string>(id->m_value), FUNC);
            return move(std::get<Func>(func->sign)->ret);
        }
        return NULL;
        break;
    }

    case 14: // Exp LB Exp RB
    {
        Type var = check_Exp(node->m_first_child);
        Type index = check_Exp(kth_next(node->m_first_child, 2));
        if (var == NULL)
            return NULL;
        if (var->kind != ARRAY)
        {
            // fprintf(stderr, "ERROR type %d at Line %d: %s\n", 10, node->m_first_child->m_line_num, "Var is Not Array");
        }
        if (var->kind == ARRAY)
        {
            std::get<ArrayType>(var->content)->elem->is_lvalue = true;
            return std::move(std::get<ArrayType>(var->content)->elem);
        }
        else
        {
            return NULL;
        }
        break;
    }

    // case 15: // Exp DOT ID
    // {
    //     Type type = check_Exp(node->m_first_child);
    //     if (type == NULL)
    //         return NULL;
    //     if (type->kind != STRUCTURE)
    //     {
    //         // fprintf(stderr, "ERROR type %d at Line %d: %s\n", 13, node->m_first_child->m_line_num, "Not a Structure");
    //         return type;
    //     }
    //     Symbol st = get_symbol(table, type->u.structure->name, STRUCT);
    //     char *id = kth_next(node->m_first_child, 2)->m_value.type_string;
    //     FieldList field = type->u.structure;
    //     while (field != NULL)
    //     {
    //         if (strcmp(field->name, id) == 0)
    //         {
    //             field->type->is_lvalue = true;
    //             return field->type;
    //         }
    //         field = field->next;
    //     }
    //     // fprintf(stderr, "ERROR type %d at Line %d: %s\n", 14, node->m_first_child->m_line_num, "No such a field");
    //     return NULL;
    //     break;
    // }

    case 16: // ID
    {

        std::string id = std::get<std::string>(node->m_first_child->m_value);
        if (table->is_contain( id, VAR))
        {

            Symbol symbol = table->get_symbol(id, VAR);
            std::get<Type>(symbol->sign)->is_lvalue = true;
            return std::get<Type>(symbol->sign);
        }
        else
        {
            // fprintf(stderr, "ERROR type %d at Line %d: %s\n", 1, node->m_first_child->m_line_num, "Var not declared");
        }
        return NULL;
        break;
    }

    case 17: // INT
    {
        Type type(make_shared<Type_>(BASIC, INT));
        return type;
    }
    case 18: // FLOAT
    {
        Type type(make_shared<Type_>(BASIC, INT));
        return type;
    }
    case 0:
        break;
    }
    return NULL;
}
Param check_Args(struct Node *node)
{
    if (node == NULL)
        return NULL;
    if (debug)
        printf("%s is checked, line num is %d\n", node->m_name.c_str(), node->m_line_num);

    switch (node->production_id)
    {
    case 1:
    {
        Param arg(make_shared<Param_>());
        arg->next = check_Args(kth_next(node->m_first_child, 2));
        arg->type = check_Exp(node->m_first_child);
        return arg;
        break;
    }
    case 2:
    {
        Param arg(make_shared<Param_>());
        arg->next = NULL;
        arg->type = check_Exp(node->m_first_child);
        return arg;
    }
    case 0:
        break;
    }
    return NULL;
}