#include "common.h"
#include <string.h>
#include <ctype.h>

// Helper function to trim whitespace
char* trim(char *str) {
    if (!str) return NULL;
    
    // Trim leading spaces
    char *start = str;
    while (*start && (*start == ' ' || *start == '\t')) start++;
    
    // If only spaces, return empty string
    if (!*start) return start;
    
    // Trim trailing spaces
    char *end = start + strlen(start) - 1;
    while (end > start && (*end == ' ' || *end == '\t')) end--;
    *(end + 1) = '\0';
    
    return start;
}