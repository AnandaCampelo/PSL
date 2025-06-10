# Demonstração da Linguagem PSL

## Uma linguagem para geração de documentos Markdown

Este documento demonstra todas as funcionalidades da linguagem PSL (Presentation Script Language). PSL é uma linguagem de marcação simples que compila para Markdown usando LLVM como infraestrutura.

---

## 1. Elementos Básicos de Texto

A PSL suporta diferentes níveis de títulos e parágrafos de texto. O texto pode ser formatado em múltiplas linhas e será renderizado como um parágrafo contínuo no Markdown.

## 2. Listas

PSL suporta listas não ordenadas:

- Maçãs
- Bananas
- Laranjas
- Uvas

E também listas ordenadas (enumeradas):

1. Primeiro passo: planejamento
2. Segundo passo: desenvolvimento
3. Terceiro passo: testes
4. Quarto passo: implantação

---

## 3. Listas de Tarefas

Você pode criar listas de tarefas com status:

- [x] Tarefa já concluída
- [ ] Tarefa pendente
- [x] Esta também está concluída
- [ ] o Esta ainda precisa ser feita

---

## 4. Blocos de Código

PSL permite incluir blocos de código com syntax highlighting:

```python
# Exemplo de código Python
def hello_world():
    print("Hello, PSL!")
for i in range(3):
    print(f"Contagem: {i}")
```

```javascript
// Exemplo de código JavaScript
function calculateSum(a, b) {
    return a + b;
}
console.log("A soma é:", calculateSum(5, 7));
```

---

## 5. Imagens e Links

PSL facilita a inclusão de imagens:

![Uma imagem, wow!](image.png)

E links para recursos externos:

[GitHub da PSL!](https://github.com/AnandaCampelo/PSL)

---

## 6. Notas e Comentários

Você pode adicionar notas de destaque:

> *Note:* Esta é uma nota importante sobre a linguagem PSL. Ela será formatada como um bloco de destaque no Markdown.

A PSL também suporta comentários no código fonte que não aparecem na saída Markdown final.

---

## Conclusão

A PSL é uma linguagem simples mas poderosa para criar documentos Markdown estruturados. Seu compilador baseado em LLVM traduz a sintaxe PSL para Markdown de forma eficiente.

Este documento de teste demonstra todas as funcionalidades principais da linguagem.

---

> *Note:* Desenvolvido como projeto para a matéria de Lógica da Computação. Junho de 2025.

