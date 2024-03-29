#include <stdio.h>
#include <stdlib.h>

#include "string.h"
#include "list.h"
#include "lexer.h"

#define LOG(message) fputs((message), stderr)
#define LOGF(format, ...) fprintf(stderr, (format), __VA_ARGS__)

int main(int argc, char* argv[])
{
    if (argc < 2) {
        LOGF("Usage: %s [-v] -e 'expression'\n", argv[0]);
        exit(EXIT_SUCCESS);
    }

    String input = string_init(argv[1]);
    List tokens = lexical_scan(&input);

    for list_range(it, tokens) {
        Token* token = list_node_data(it, Token);
        string_print(&token->content);
        putchar('\n');
    }

    list_deinit(&tokens);
}
