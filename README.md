# Implementações de Grafos em C
## Visão Geral
Grafos são estruturas de dados úteis para diversos fins: pesquisa de comunidades, otimização de caminhos, representação de relacionamentos. Nesse repositório, implementei dois tipos de grafo: direcionado e não direcionado, por matriz de adjacência e lista ligada.
## Utilização
É necessário que você tenha instalado o `gcc` para compilar o código e criar o executável. Os comandos necessários estão descritos em arquivos txt, para cada implementação.
## Estrutura de pastas

- directional: implementação de grafo direcional.
    - list: implementação por lista ligada.
    - matrix: implementação por matriz de adjacência.
- non-directional: implementação de grafo não direcional.
    - list: implementação por lista ligada.
    - matrix: implementação por matriz de adjacência.

## Performance
A matriz de adjacência é melhor para grafos densos, ou seja, com muitas arestas e poucos vértices. A lista ligada é mais performática quando há muitos vértices e poucas arestas. Isso acontece pois a matriz de adjacência possuí índices que permitem, por exemplo, comparar rapidamente se dois vértices tem uma aresta comum. Já a lista ligada, conhecer todos os vizinhos de um vértice é muito rápido, pois basta capturar o nó cabeça da respectiva lista.
## Sobre o autor
Meu nome é Gabriel e estou disponível para contato no meu e-mail gafelix@alumni.usp.br