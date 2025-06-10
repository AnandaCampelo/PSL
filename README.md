# PSL - Procedural Structure Language

**PSL** é uma linguagem de marcação estruturada com elementos de programação, projetada para gerar documentos `.md` (Markdown) a partir de um arquivo `.psl`. Ela combina blocos declarativos como títulos, listas, imagens e código com estruturas lógicas como variáveis, condicionais e repetições.

---

## Objetivo

Permitir a criação de documentos Markdown dinâmicos, organizados por blocos indentados, com controle condicional e repetitivo do conteúdo, utilizando uma sintaxe simples e expressiva.

---

## Características

* Estrutura baseada em **indentacão**
* Suporte a **listas**, **parágrafos**, **código**, **imagens**, **links**, **tabelas**, etc.
* Geração de arquivos `.md` automática e estruturada

---

## Como executar o PSL

### Pré-requisitos

- GCC (GNU Compiler Collection)
- Flex (Fast Lexical Analyzer)
- Bison (Parser Generator)
- LLVM Development Libraries (versão 12 ou superior)

### Compilação

Para compilar o processador PSL, use os seguintes comandos:

```bash
# Limpar compilações anteriores
make clean

# Compilar a versão com suporte LLVM
make psl-llvm

# Ou compilar a versão básica sem LLVM
make psl

# Versão com LLVM
./psl-llvm seu_arquivo.psl

# Versão básica
./psl seu_arquivo.psl
```

---

## EBNF da linguagem PSL

```ebnf
PROGRAMA       = { BLOCO }, FIM_ARQUIVO ;

BLOCO          = COMANDO_MARCA | COMANDO_PROG ;

COMANDO_MARCA  = TITULO | SUBTITULO | PARAGRAFO | LISTA | ENUMERAR |
                 CODIGO_BLOCO | IMAGEM | LINK | CITACAO |
                 TAREFAS | TABELA | DIVISOR | NOTA ;

COMANDO_PROG   = IF | LOOP ;

TITULO         = "titulo", NOVA_LINHA, TEXTO_INDENTADO ;
SUBTITULO      = "subtitulo", NOVA_LINHA, TEXTO_INDENTADO ;
PARAGRAFO      = "paragrafo", NOVA_LINHA, { TEXTO_INDENTADO } ;

LISTA          = "lista", NOVA_LINHA, { TEXTO_INDENTADO } ;
ENUMERAR       = "enumerar", NOVA_LINHA, { TEXTO_INDENTADO } ;

TAREFAS        = "tarefas", NOVA_LINHA, { STATUS_ITEM } ;
STATUS_ITEM    = INDENT, ("s" | "n" | "sim" | "não"), ESPACO, TEXTO, NOVA_LINHA ;

CODIGO_BLOCO   = "codigo", ESPACO, LINGUAGEM, NOVA_LINHA,
                 { TEXTO_INDENTADO } ;

IMAGEM         = "imagem", NOVA_LINHA,
                 INDENT, "alt", ESPACO, TEXTO, NOVA_LINHA,
                 INDENT, "src", ESPACO, TEXTO, NOVA_LINHA ;

LINK           = "link", NOVA_LINHA,
                 INDENT, "texto", ESPACO, TEXTO, NOVA_LINHA,
                 INDENT, "url", ESPACO, TEXTO, NOVA_LINHA ;

CITACAO        = "citacao", NOVA_LINHA, TEXTO_INDENTADO ;
NOTA           = "nota", NOVA_LINHA, TEXTO_INDENTADO ;
DIVISOR        = "divisor", NOVA_LINHA ;

TABELA         = "tabela", NOVA_LINHA,
                 INDENT, "cabecalho", ESPACO, CABECALHO, NOVA_LINHA,
                 { TEXTO_INDENTADO } ;

CABECALHO      = TEXTO , { "," , TEXTO } ;
LINHA_TABELA   = TEXTO , { "," , TEXTO } ;

IF             = "se", ESPACO, VARIAVEL, ESPACO, OP_REL, ESPACO, VALOR, NOVA_LINHA,
                 INDENT, "entao", NOVA_LINHA,
                 BLOCO_INDENTADO,
                 [ INDENT, "senao", NOVA_LINHA,
                   BLOCO_INDENTADO ] ;

LOOP           = "repetir", ESPACO, NUMERO, ESPACO, "vezes", NOVA_LINHA,
                 BLOCO_INDENTADO ;

OP_REL         = "igual" | "diferente" | "maior" | "menor" | "maior_igual" | "menor_igual" ;

VARIAVEL       = IDENT ;
VALOR          = TEXTO ;
LINGUAGEM      = IDENT ;

TEXTO_INDENTADO = INDENT, TEXTO, NOVA_LINHA ;
BLOCO_INDENTADO = { INDENT, BLOCO } ;

TEXTO          = { CHAR } ;
CHAR           = ? qualquer caractere visível (exceto \n) ? ;
IDENT          = LETRA , { LETRA | DIGITO } ;
NUMERO         = DIGITO , { DIGITO } ;
LETRA          = "a" | "b" | ... | "z" | "A" | "B" | ... | "Z" ;
DIGITO         = "0" | "1" | ... | "9" ;

INDENT         = "    " ; /* 4 espaços */
ESPACO         = " ", { " " } ; /* Um ou mais espaços */
NOVA_LINHA     = "\n" ;

FIM_ARQUIVO    = NOVA_LINHA, NOVA_LINHA ;
```

---

## Exemplo de entrada `.psl`

```psl
titulo
    Relatório Final

subtitulo
    Visão Geral

paragrafo
    Este relatório descreve os resultados
    obtidos ao longo do experimento.

divisor

lista
    Introdução
    Metodologia
    Conclusão

divisor

enumerar
    Passo 1: Coletar dados
    Passo 2: Analisar resultados
    Passo 3: Gerar gráficos

divisor

tarefas
    s Corrigir erros
    n Adicionar conclusão
    sim Revisar gráficos
    não Validar tabela

divisor

codigo python
    for i in range(3):
        print(i)

imagem
    alt Logo do Projeto
    src imagens/logo.png

link
    texto Repositório do Projeto
    url https://github.com/exemplo

nota
    Este é um comentário importante.

divisor


```
---

## Exemplo de saída `.md`

```
# Relatório Final

## Visão Geral

Este relatório descreve os resultados obtidos ao longo do experimento.

---

- Introdução
- Metodologia
- Conclusão

---

1. Passo 1: Coletar dados
2. Passo 2: Analisar resultados
3. Passo 3: Gerar gráficos

---

- [x] Corrigir erros
- [ ] Adicionar conclusão
- [x] Revisar gráficos
- [ ] o Validar tabela

---

    ```python
for i in range(3):
    print(i)
    ```

---

![Logo do Projeto](imagens/logo.png)

[Repositório do Projeto](https://github.com/exemplo)

> *Note:* Este é um comentário importante.

---


```