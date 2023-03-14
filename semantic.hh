#ifndef SEMANTIC_HH
#define SEMANTIC_HH
#include "symbol.hh"
static int unnamed = 0;

struct Node *kth_next(struct Node *node, int k);
void semantic(struct Node *node);

void check_Program(struct Node *node);
void check_ExtDefList(struct Node *node);
void check_ExtDef(struct Node *node);
void check_ExtDecList(struct Node *node, Type type);
Type check_Specifier(struct Node *node);
Type check_TYPE(struct Node *node);
Type check_StructSpecifier(struct Node *node);
void check_OptTag(struct Node *node);
void check_Tag(struct Node *node);
Symbol check_VarDec(struct Node *node, SymbolKind kind, Type type);
Symbol check_FunDec(struct Node *node, Type type, bool is_dec);
Param check_VarList(struct Node *node);
Param check_ParamDec(struct Node *node);
void check_CompSt(struct Node *node, Symbol symbol);
void check_StmtList(struct Node *node, Symbol symbol);
void check_Stmt(struct Node *node, Symbol symbol);
FieldType check_DefList(struct Node *node, SymbolKind kind);
FieldType check_Def(struct Node *node, SymbolKind kind);
SymbolList check_DecList(struct Node *node, SymbolKind kind, Type type);
Symbol check_Dec(struct Node *node, SymbolKind kind, Type type);
Type check_Exp(struct Node *node);
Param check_Args(struct Node *node);

#endif