# PSL (Programming Sign Language) - Definição EBNF

## Introdução

A PSL (**Programming Sign Language**) é uma linguagem de programação baseada em ícones de mãos e sinais visuais, inspirada na comunicação por linguagem de sinais. O objetivo é representar as estruturas fundamentais de programação de maneira simples, simbólica e acessível.

A seguir está a estrutura formal da linguagem definida em **Extended Backus-Naur Form (EBNF)**.

---

## Definição EBNF da PSL

```ebnf
(* Unidade de Tradução: Programa completo *)
<translation-unit> ::= { <external-declaration> } <end-program>

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

- O programa sempre deve terminar com o ícone "🛑".
- Blocos de código (em `if` e `while`) são delimitados pelo ícone de mão aberta "🖐️".
- Todas as variáveis são declaradas com "✋" seguidas de seu tipo ("💅" para números, "✍️" para strings).
- O tipo de valor é determinado na declaração.
- Atribuições podem envolver operações diretas.
- Operadores de comparação e operadores aritméticos são representados por emojis.
- A linguagem suporta operações de soma, subtração, multiplicação, divisão, comparações, impressão, entrada e vínculo de variáveis.
- Identificadores seguem a convenção de letras e dígitos, sem espaços.

---

## Exemplo de Programa em PSL

```text
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
🖐️
🛑
```

**Explicação:**
- Declara variáveis de número e string usando "✋" seguidas de tipo.
- Atribui valores diretamente.
- Vínculo (`🤝`) entre `x` e `y`, operações simples feitas em `x` serão espelhadas em `y`.
  - Vínculo (`🤝`) só pode ser feito entre variáveis não nulas e de valor numérico.
- Operação de soma (`👆`) realizada sobre `x`.
- Entrada de valor do usuário (`🫵`) para `nome`.
- Impressão de valores.
- Verifica se `idade` é maior que 18 e imprime mensagem.
- Finaliza o programa.

---

## Resumo

A PSL é uma linguagem simbólica e visualmente inclusiva para programação básica. Agora suporta tipos numéricos e strings, impressão, entrada, comparações, operações matemáticas e vínculo dinâmico de variáveis, trazendo uma abordagem inovadora e original para o desenvolvimento de algoritmos.
