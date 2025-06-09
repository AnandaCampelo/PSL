#ifndef PSL_COMMON_H
#define PSL_COMMON_H

#include <string.h>
#include <ctype.h>

// Operator types for relations
typedef enum {
    OP_IGUAL = 1,       // Make sure these start at 1 to avoid conflicts
    OP_DIFERENTE,
    OP_MAIOR,
    OP_MENOR,
    OP_MAIOR_IGUAL,
    OP_MENOR_IGUAL
} op_type;

// Helper function to trim whitespace
char* trim(char *str);

#endif // PSL_COMMON_H