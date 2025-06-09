CC = gcc
CFLAGS = -Wall -Wextra -g
LLVM_CFLAGS = $(CFLAGS) -I/usr/include/llvm-c
LDFLAGS = -lLLVM-12

# Diretórios
SRC_DIR = .
LLVM_SRC_DIR = PSL-Compiler/src

# Arquivos objeto
OBJS = parser.tab.o lex.yy.o common.o main.o
LLVM_OBJS = $(LLVM_SRC_DIR)/psl_llvm.o $(LLVM_SRC_DIR)/psl_main.o parser.tab.o lex.yy.o common.o
NO_LLVM_OBJS = parser_no_llvm.tab.o lex_no_llvm.yy.o common.o main_no_llvm.o

# Destinos fictícios
.PHONY: all clean llvm-dirs

# Alvo principal (ambos)
all: psl psl-llvm

# Compilador PSL original (sem LLVM)
psl: $(NO_LLVM_OBJS)
	$(CC) -o $@ $^ -lfl

# Versão com LLVM
psl-llvm: llvm-dirs $(LLVM_OBJS)
	$(CC) -o $@ $(LLVM_OBJS) -lfl $(LDFLAGS)

# Criar diretórios necessários
llvm-dirs:
	mkdir -p $(LLVM_SRC_DIR)

# Geração do arquivo parser sem LLVM
main_no_llvm.c: main.c
	@echo "Gerando versão sem LLVM de main.c..."
	@cp $< $@
	@sed -i 's/#include "PSL-Compiler\/src\/psl_llvm.h"/\/\/ LLVM removido/' $@

# Versão do parser sem LLVM - abordagem mais simples e robusta
parser_no_llvm.y: parser.y
	@echo "Gerando versão sem LLVM de parser.y..."
	@cp $< $@
	@sed -i 's/#include "PSL-Compiler\/src\/psl_llvm.h"/\/\/ LLVM removido/' $@
	@sed -i 's/PSLCompilerContext/int/' $@
	@sed -i 's/compiler_ctx = psl_compiler_init[^;]*;/compiler_ctx = 0;/' $@
	@sed -i 's/psl_run_module[^;]*;//' $@
	@sed -i 's/if (compiler_ctx) {/if (0) {/' $@
	@sed -i '/psl_gen_/d' $@
	@sed -i 's/parse_psl_file[^}]*}/parse_psl_file(const char* filename, void* ctx) {\n    FILE* file = fopen(filename, "r");\n    if (!file) {\n        fprintf(stderr, "Erro: Não foi possível abrir o arquivo %s\\n", filename);\n        return 1;\n    }\n    yyin = file;\n    int result = yyparse();\n    fclose(file);\n    return result;\n}/' $@

scanner_no_llvm.l: scanner.l
	@echo "Gerando versão sem LLVM de scanner.l..."
	@cp $< $@
	@sed -i 's/parser.tab.h/parser_no_llvm.tab.h/' $@

# Regras para compilação dos arquivos não-LLVM
parser_no_llvm.tab.c parser_no_llvm.tab.h: parser_no_llvm.y
	bison -d $<

lex_no_llvm.yy.c: scanner_no_llvm.l parser_no_llvm.tab.h
	flex -o $@ $<

main_no_llvm.o: main_no_llvm.c parser_no_llvm.tab.h common.h
	$(CC) $(CFLAGS) -c $< -o $@

parser_no_llvm.tab.o: parser_no_llvm.tab.c common.h
	$(CC) $(CFLAGS) -c $< -o $@

lex_no_llvm.yy.o: lex_no_llvm.yy.c
	$(CC) $(CFLAGS) -c $< -o $@

# Regras para compilação dos arquivos LLVM
parser.tab.c parser.tab.h: parser.y
	bison -d $<

lex.yy.c: scanner.l parser.tab.h
	flex $<

main.o: main.c parser.tab.h common.h
	$(CC) $(LLVM_CFLAGS) -c $< -o $@

parser.tab.o: parser.tab.c common.h
	$(CC) $(LLVM_CFLAGS) -c $< -o $@

lex.yy.o: lex.yy.c
	$(CC) $(LLVM_CFLAGS) -c $< -o $@

common.o: common.c common.h
	$(CC) $(CFLAGS) -c $< -o $@

# Compilação dos arquivos LLVM
$(LLVM_SRC_DIR)/psl_llvm.o: $(LLVM_SRC_DIR)/psl_llvm.c $(LLVM_SRC_DIR)/psl_llvm.h
	$(CC) $(LLVM_CFLAGS) -c $< -o $@

$(LLVM_SRC_DIR)/psl_main.o: $(LLVM_SRC_DIR)/psl_main.c $(LLVM_SRC_DIR)/psl_llvm.h
	$(CC) $(LLVM_CFLAGS) -c $< -o $@

# Limpeza
clean:
	rm -f psl psl-llvm *.o parser*.tab.c parser*.tab.h lex*.yy.c main_no_llvm.c parser_no_llvm.y scanner_no_llvm.l
	rm -f $(LLVM_SRC_DIR)/*.o