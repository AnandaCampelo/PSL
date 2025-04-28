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
              | <conditional>
              | <loop>
              | <block>

<declaration> ::= "✋" <identifier>

<assignment> ::= "👉" <identifier> <expression>

<conditional> ::= "✊" <condition> <block>

<loop> ::= "🤌" <condition> <block>

<block> ::= "🖐️" { <statement> } "🖐️"

(* Condições *)
<condition> ::= <expression> <comparator> <expression>

<expression> ::= <term> { <add-operator> <term> }

<term> ::= <factor> { <mul-operator> <factor> }

<factor> ::= <identifier>
           | <number>
           | "(" <expression> ")"

<add-operator> ::= "👆" (* soma (+) *)
                 | "👇" (* subtração (-) *)

<mul-operator> ::= "👍" (* multiplicação (*) *)
                 | "👎" (* divisão (/) *)

<identifier> ::= <letter> { <letter> | <digit> }

<number> ::= "💅" <digit> { <digit> }

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
- Números são precedidos do ícone "💅".
- Operadores de comparação e operadores aritméticos são representados por emojis.
- Identificadores seguem a convenção de letras e dígitos, sem espaços.
- Expressões agora suportam operações aritméticas (soma, subtração, multiplicação, divisão) além das comparações.

---

## Exemplo de Programa em PSL

```text
✋ x
👉 x 💅5
✊ x 🤜 💅3
🖐️
    ✋ y
    👉 y 💅10
🖐️
🛑
```

**Explicação:**
- Declara a variável `x`
- Atribui o valor `5` para `x`
- Se `x > 3`, então:
  - Declara a variável `y`
  - Atribui o valor `10` para `y`
- Finaliza o programa

---

## Resumo

A PSL é uma linguagem simbólica que visa explorar uma representação visual e inclusiva para a programação básica, mantendo a estrutura tradicional de declarações, atribuições, condições e repetições de forma inovadora e acessível.
