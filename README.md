# PSL - Procedural Structure Language

**PSL** é uma linguagem de marcação estruturada com elementos de programação, projetada para gerar documentos `.md` (Markdown) a partir de um arquivo `.psl`. Ela combina blocos declarativos como títulos, listas, imagens e código com estruturas lógicas como variáveis, condicionais e repetições.

---

## Objetivo

Permitir a criação de documentos Markdown dinâmicos, organizados por blocos indentados, com controle condicional e repetitivo do conteúdo, utilizando uma sintaxe simples e expressiva.

---

## Características

* Estrutura baseada em **indentacão**
* Suporte a **listas**, **parágrafos**, **código**, **imagens**, **links**, **tabelas**, etc.
* Suporte a **condicionais** e **loops**
* Geração de arquivos `.md` automática e estruturada

---

## EBNF da linguagem PSL

```ebnf
PROGRAMA       = { BLOCO } ;

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