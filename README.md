# PSL (Programming Sign Language) - Definição EBNF

## Introdução

A PSL (**Programming Sign Language**) é uma linguagem de programação baseada em ícones de mãos e sinais visuais, inspirada na comunicação por linguagem de sinais. O objetivo é representar as estruturas fundamentais de programação de maneira simples, simbólica e acessível.

Cada execução da PSL é associada a um usuário identificado por nome, permitindo manter um histórico de operações exclusivo para cada um. Além disso, PSL permite ações externas como abrir páginas na web, e consultar o histórico de variáveis de qualquer usuário declarado.

A seguir está a estrutura formal da linguagem definida em **Extended Backus-Naur Form (EBNF)**.

---

## Definição EBNF da PSL

```ebnf
(* Unidade de Tradução: Programa completo *)
<translation-unit> ::= <user-declaration> { <external-declaration> } <end-program>

<user-declaration> ::= "✍️" <string>

<external-declaration> ::= <statement>

<end-program> ::= "🛑"

(* Declarações e Instruções *)
<statement> ::= <declaration>
              | <assignment>
              | <print>
              | <input>
              | <bind>
              | <conditional>
              | <loop>
              | <block>
              | <websearch>
              | <history-access>

<declaration> ::= "✋" (<number-type> | <string-type>) <identifier>

<number-type> ::= "💅"
<string-type> ::= "✍️"

<assignment> ::= "👉" (<input> | <operation> | <identifier>) <expression>

<operation> ::= ("👆" | "👇")

<print> ::= "☝️" <expression>
<input> ::= "🫵"
<bind> ::= "🤝" <identifier> <identifier>

<conditional> ::= "✊" <condition> <block>
<loop> ::= "🤌" <condition> <block>
<block> ::= "🖐️" { <statement> } "🖐️"

<websearch> ::= "🦾" <string>
<history-access> ::= "🪬" <string>

(* Expressões *)
<condition> ::= <expression> <comparator> <expression>
<expression> ::= <term> { <add-operator> <term> }
<term> ::= <factor> { <mul-operator> <factor> }
<factor> ::= <identifier>
           | <number>
           | <string>
           | "(" <expression> ")"

<add-operator> ::= "👆" (* soma (+) *)
                 | "👇" (* subtração (-) *)

<mul-operator> ::= "🫴" (* multiplicação (*) *)
                 | "🫳" (* divisão (/) *)

<identifier> ::= <letter> { <letter> | <digit> }
<number> ::= <digit> { <digit> }
<string> ::= "\"" { <letter> | <digit> | " " | "!" | "?" | "," | "." } "\""

(* Operadores de Comparação usando Emojis *)
<comparator> ::= "👋" (* diferente (!=) *)
               | "👏" (* igual (==) *)
               | "🤜" (* maior (>) *)
               | "🤛" (* menor (<) *)
               | "🤜🤏" (* maior ou igual (>=) *)
               | "🤛🤏" (* menor ou igual (<=) *)

(* Unidades Básicas *)
<letter> ::= "A" | "B" | "C" | ... | "Z"
           | "a" | "b" | "c" | ... | "z"

digit ::= "0" | "1" | "2" | "3" | "4" | "5" | "6" | "7" | "8" | "9"
```

---

## Observações

- O programa inicia com a declaração de usuário "✍️ \"nome\"", que vincula as ações a um histórico pessoal.
- O programa sempre deve terminar com o ícone "🛑".
- Blocos de código (em `if` e `while`) são delimitados pelo ícone de mão aberta "🖐️".
- Todas as variáveis são declaradas com "✋" seguidas de seu tipo ("💅" para números, "✍️" para strings).
- O tipo de valor é determinado na declaração.
- Atribuições podem envolver operações diretas.
- Operadores de comparação e operadores aritméticos são representados por emojis.
- PSL permite vinculação de variáveis, condições, entrada, impressão e comandos externos.
- Comando `🦾 "site"` abre o navegador com a URL correspondente a `www.<site>.com`.
- Comando `🪬 "nome"` acessa o histórico de variáveis daquele usuário, exibindo os nomes e valores atuais.

---

## Exemplo de Programa em PSL

```text
✍️ "Ananda"
✋💅 idade
✋✍️ nome
✋💅 x
✋💅 y
👉 idade 22
👉 nome "Ananda"
👉 x 10
👉 y 15
🤝 x y
👉 x 👆 5
☝️ y
👉 nome 🫵
☝️ nome
✊ idade 🤜 18
🖐️
    ☝️ "Maior de idade!"
    🦾 "google"
🖐️
🪬 "Ananda"
🛑
```

**Explicação:**
- Declara o nome do usuário com "✍️" para iniciar o escopo de execução.
- Executa operações associadas ao usuário "Ananda".
- Usa `🦾 "google"` para abrir o navegador em "www.google.com".
- Usa `🪬 "Ananda"` para acessar o histórico de variáveis declaradas por "Ananda".

---

## Resumo

A PSL é uma linguagem simbólica e visualmente acessível para programação com escopo individual por usuário. Suporta criação de variáveis, manipulação, condicionais, comandos externos, e agora também permite **consulta de histórico de execução** e **acesso a sites dinâmicos** com base em entrada textual do usuário.
