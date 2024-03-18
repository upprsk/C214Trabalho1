---
lang: pt-BR
---

# Trabalho 1

Teste uma classe responsável por popular uma página WEB com informações
referentes ao horário de atendimento dos professores do Inatel. O horário de
atendimento é retornado por um servidor remoto em um JSON em formato String.
Não é necessário demonstrar o funcionamento da página WEB, somente o teste.

## Dependências

O projeto depende de um compilador `C++` (`g++` ou `clang++`) com suporte a
C++ 17 e `cmake`.

Para compilar só é necessário rodar o seguinte comando, este também irá baixar
todas as dependências durante a _build_.

```bash
cmake -S . -B build && cmake --build build
```

Para rodar os testes use:

```bash
./build/tests/testlib
```
