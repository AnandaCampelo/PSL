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
                 CODIGO_BLOCO | IMAGEM | LINK | CITAÇÃO |
                 CHECKBOXES | TABELA | DIVISOR | NOTA ;

COMANDO_PROG   = IF | LOOP ;

TITULO         = "titulo", NOVA_LINHA, INDENT, TEXTO ;
SUBTITULO      = "subtitulo", NOVA_LINHA, INDENT, TEXTO ;
PARAGRAFO      = "paragrafo", NOVA_LINHA, { INDENT, TEXTO, NOVA_LINHA } ;

LISTA          = "lista", NOVA_LINHA, { INDENT, TEXTO, NOVA_LINHA } ;
ENUMERAR       = "enumerar", NOVA_LINHA, { INDENT, TEXTO, NOVA_LINHA } ;

CHECKBOXES     = "tarefas", NOVA_LINHA, { INDENT, STATUS, TEXTO, NOVA_LINHA } ;
STATUS         = "s" | "n" | "sim" | "não" ;

CODIGO_BLOCO   = "codigo", [LINGUAGEM], NOVA_LINHA,
                 { INDENT, LINHA_CODIGO }, SEPARADOR ;

IMAGEM         = "imagem", NOVA_LINHA,
                 INDENT, "alt", TEXTO, NOVA_LINHA,
                 INDENT, "src", TEXTO ;

LINK           = "link", NOVA_LINHA,
                 INDENT, "texto", TEXTO, NOVA_LINHA,
                 INDENT, "url", TEXTO ;

CITAÇÃO        = "citacao", NOVA_LINHA, INDENT, TEXTO ;
NOTA           = "nota", NOVA_LINHA, INDENT, TEXTO ;
DIVISOR        = "divisor" ;

TABELA         = "tabela", NOVA_LINHA,
                 INDENT, "cabecalho", CABECALHO, NOVA_LINHA,
                 { INDENT, LINHA_TABELA } ;

CABECALHO      = TEXTO , { "," , TEXTO } ;
LINHA_TABELA   = TEXTO , { "," , TEXTO } ;

IF             = "se", IDENT, OP_REL, TEXTO, NOVA_LINHA,
                 INDENT, "entao", NOVA_LINHA,
                 { INDENT2, BLOCO },
                 [ INDENT, "senao", NOVA_LINHA,
                   { INDENT2, BLOCO } ] ;

LOOP           = "repetir", NUMERO, "vezes", NOVA_LINHA,
                 { INDENT, BLOCO } ;

OP_REL         = "igual" | "diferente" | "maior" | "menor" | "maior_igual" | "menor_igual" ;

LINGUAGEM      = IDENT ;
LINHA_CODIGO   = TEXTO ;

TEXTO          = { CHAR } ;
CHAR           = ? qualquer caractere visível (exceto \n) ? ;
IDENT          = letra , { letra | digito } ;
NUMERO         = digito , { digito } ;

INDENT         = ? um nível de indentação ? ;
INDENT2        = ? dois níveis de indentação ? ;
NOVA_LINHA     = "\n" ;
SEPARADOR      = (palavra-chave não indentada, ou EOF) ;
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

lista
    Introdução
    Metodologia
    Conclusão

enumerar
    Passo 1: Coletar dados
    Passo 2: Analisar resultados
    Passo 3: Gerar gráficos

tarefas
    s Corrigir erros
    n Adicionar conclusão
    sim Revisar gráficos
    não Validar tabela

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

se nome igual Ana
    entao
        paragrafo
            Bem-vinda, Ana!
    senao
        paragrafo
            Usuário desconhecido.

repetir 2 vezes
    enumerar
        Execução de teste
        Validação dos dados
```

---