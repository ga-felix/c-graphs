# Implementações de Grafos em C
## Visão Geral
Grafos são estruturas de dados úteis para diversos fins: pesquisa de comunidades, otimização de caminhos, representação de relacionamentos. Nesse repositório, implementei dois tipos de grafo: direcionado e não direcionado, por matriz de adjacência e lista ligada.
## Utilização
É necessário que você tenha instalado o `gcc` para compilar o código e criar o executável. Os comandos necessários estão descritos em arquivos txt, para cada implementação.
## Estrutura de pastas

- directional: implementação de grafo direcional.
    - list: implementação por lista ligada.
    - matrix: implementação por matriz de adjacência.
- undirectional: implementação de grafo não direcional.
    - list: implementação por lista ligada.
    - matrix: implementação por matriz de adjacência.

## Performance
A matriz de adjacência é melhor para grafos densos, ou seja, com muitas arestas e poucos vértices. A lista ligada é mais performática quando há muitos vértices e poucas arestas. Isso acontece pois a matriz de adjacência possuí índices que permitem, por exemplo, comparar rapidamente se dois vértices tem uma aresta comum. Já a lista ligada, conhecer todos os vizinhos de um vértice é muito rápido, pois basta capturar o nó cabeça da respectiva lista.
## Sobre o autor
Meu nome é Gabriel e estou disponível para contato no meu e-mail gafelix@alumni.usp.br

***

# Implementations of Graphs in C
## Overview
Graphs are data structures that are useful for various purposes: community research, path optimization, relationship representation. In this repository, I implemented two types of graphs: directed and undirected, by adjacency matrix and linked list.
## Usage
It is necessary that you have installed `gcc` to compile the code and create the executable. The necessary commands are described in txt files, for each implementation.
## Folder structure
- directional: directional graph implementation.
    - list: linked list implementation.
    - matrix: adjacency matrix implementation.
- undirectional: undirectional graph implementation.
    - list: linked list implementation.
    - matrix: adjacency matrix implementation.

## Performance
The adjacency matrix is better for dense graphs, that is, with many edges and few vertices. The linked list is more performative when there are many vertices and few edges. This happens because the adjacency matrix has indices that allow, for example, to quickly compare whether two vertices have a common edge. On the other hand, knowing all the neighbors of a vertex in a linked list is very fast, as it is enough to capture the head node of the respective list.

## About the author
My name is Gabriel and I am available for contact at my email gafelix@alumni.usp.br