# cub3d 👾​

`CURSO: Engenharia de Software | 42SP`

## :page_facing_up: Índice

* [1. Sobre](#1-sobre)
* [2. Planejamento Ágil](#2-planejamento-ágil)
* [3. Kanban](#3-kanban)
* [4. Etapas do desenvolvimento](#4-etapas-do-desenvolvimento)
* [5.Tecnologias e Ferramentas externas utilizadas](#5-tecnologias-e-ferramentas-externas-utilizadas)
* [6. Estrutura do Projeto](#6-estrutura-do-projeto)
* [7. Desenvolvedores](#6-Desenvolvedores)

## 1. Sobre
Este projeto consiste em um gráfico 3D “realista” que contem a representação do interior de um labirinto a partir de um perspectiva em primeira pessoa.
 
O game foi criado usando a _**técnica de Ray-Casting**_, que simula a visão de uma câmera 3D em uma projeção 2D, envolve cálculos trigonométricos e vetoriais. Além da _**técnica de Scanline**_ usada para renderizar polígonos em gráficos 2D. Ele percorre as linhas horizontais da tela e preenche os pixels entre as arestas do polígono, determinando quais pixels devem ser coloridos e a utilização do _**Algoritmo de Bresenham**_ para desenhar linhas em uma grade de pixels. 

<div align="center">
  <img src="./ezgif.com-speed.gif.png" alt="Game Cub3D"/>
</div>



## 2. Planejamento Ágil
Utilizou-se o kaban do GitHub na aba [Projects](https://github.com/users/luciana-pereira/projects/12) e o Discord para planejar as ideais, organizar as tarefas e facilitar a comunicação durante o desenvolvimento.

## 3. Kanban

![image](https://github.com/luciana-pereira/cub3d/assets/37550557/1e626031-55c2-4db9-b686-c143956ade7b)

## 4. Etapas do desenvolvimento
Além de aplicar as __boas práticas de programação em C__, como __gerenciamento adequado de memória__, __modularização do código em funções__ e __documentação__ adequada, foi necessario aprender sobre __otimização de desempenho__ para garantir que o jogo seja executado suavemente.

## 5. Tecnologias e Ferramentas externas utilizadas

#### Linguagem C 
O projeto é implementado principalmente em C, uma linguagem de programação de baixo nível, o que significa que os alunos precisam lidar diretamente com a manipulação de memória e outros aspectos de baixo nível da programação.

#### MinilibX
Utilizamos a [MinilibX](https://harm-smits.github.io/42docs/libs/minilibx) que é uma biblioteca gráfica simples, projetada especificamente para os projetos da 42. Ela oferece funcionalidades básicas para manipulação de janelas e renderização gráfica. É uma biblioteca que ajuda os Cadetes da 42 a a começarem a entender os princípios básicos de programação gráfica.

#### Raycasting
O projeto tambem envolve a implementação do algoritmo de raycasting, que é utilizado para renderizar gráficos 3D em tempo real. Este é um conceito fundamental para criar uma sensação de profundidade e perspectiva no jogo.


## 6. Estrutura do Projeto
```
cub3d/
│
|   ├── bonus/               # Código-fonte do jogo, parte bonus
|   |   ├── assets/          # Recursos do jogo (texturas e mapas)
|   |   ├── include/         # Arquivos de cabeçalho (.h)
|   |   │   ├── buttons_bonus.h
|   |   │   ├── colors_bonus.h
|   |   │   ├── constants_bonus.h
|   |   │   ├── cub3d_bonus.h
|   |   │   ├── errors_bonus.h
|   |   │   ├── functions_bonus.h
|   |   │   ├── structs_bonus.h
|   |   │   └── ...
|   |   ├── src/             # Código-fonte do jogo
|   |   │   ├── events/      # Contem código para manipulação de eventos de entrada do usuário
|   |   │   ├── graphics/    # Contem código para renderização gráfica
|   |   │   ├── init/        # Contem código de inicialização da janela do jogo, mlx entre outros.
|   |   │   ├── math/        # Contem código de operações para manipular vetores, realizar transformações e operações geométricas necessárias para renderização
|   |   │   ├── parse/       # Contem código responsável por analisar e processar os arquivos de configuração do jogo.
|   |   │   ├── rays/        # Contem código responsavel implementação do algoritmo de ray casting entre outros.
|   |   │   ├── utils/       # Contem código com funções auxiliares.
|   |   │   ├── main.c       # Arquivo principal
|   |   |   └──
|   |   └── ...
|   ├── lib/                 # Bibliotecas e dependências do projeto
|   |   ├── libft/           # Biblioteca personalizada
|   |   ├── minilibx-linux/  # Biblioteca gráfica
|   |   └── ...
|   ├── mandatory/           # Código-fonte do jogo, parte obrigatoria
|   |   ├── assets/          # Recursos do jogo (texturas e mapas)
|   |   ├── include/         # Arquivos de cabeçalho (.h)
|   |   │   ├── buttons.h
|   |   │   ├── colors.h
|   |   │   ├── constants.h
|   |   │   ├── cub3d.h
|   |   │   ├── errors.h
|   |   │   ├── functions.h
|   |   │   ├── structs.h
|   |   │   └── ...
|   |   ├── src/             # Código-fonte do jogo
|   |   │   ├── events/      # Contem código para manipulação de eventos de entrada do usuário
|   |   │   ├── graphics/    # Contem código para renderização gráfica
|   |   │   ├── init/        # Contem código de inicialização da janela do jogo, mlx entre outros.
|   |   │   ├── math/        # Contem código de operações para manipular vetores, realizar transformações e operações geométricas necessárias para renderização
|   |   │   ├── parse/       # Contem código responsável por analisar e processar os arquivos de configuração do jogo.
|   |   │   ├── rays/        # Contem código responsavel implementação do algoritmo de ray casting entre outros.
|   |   │   ├── utils/       # Contem código com funções auxiliares.
|   |   │   ├── main.c       # Arquivo principal
|   |   |   └── ...
|   |   └── 
├── Makefile                   # Arquivo de compilação
├── README.md                  # Documentação do projeto
│
└── 
```

## 7. Desenvolvedores :octocat:

<table align="center">
  <tr>
    <td align="center">
      <a href="https://github.com/luizedua42" target="_blank">
        <img src="https://avatars.githubusercontent.com/u/70030484?v=4" width="100px;" alt="Foto de Luiz Eduardo Adami no GitHub"/><br>
        <sub>
          <b>Luiz Eduardo</b>
        </sub>
      </a>
    </td>
     <td align="center">
      <a href="https://github.com/luciana-pereira" target="_blank">
        <img src="https://avatars.githubusercontent.com/u/37550557?v=4" width="100px;" alt="Foto de Luciana Pereira no GitHub"/><br>
        <sub>
          <b>Luciana Pereira</b>
        </sub>
      </a>
    </td>
  </tr>
</table>

