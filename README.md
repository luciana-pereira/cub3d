# cub3d 👾​

Este projeto consiste em um gráfico 3D “realista” que contem a representação do interior de um labirinto a partir de um perspectiva em primeira pessoa. Ele foi criado usando os princípios de Ray-Casting.

A _**técnica de Ray-Casting**_, simula a visão de uma câmera 3D em uma projeção 2D, envolve cálculos trigonométricos e vetoriais, sera bom se tiver uma boa base de matemática e álgebra linear.

## Etapas do desenvolvimento:
Além de aplicar as __boas práticas de programação em C__, como __gerenciamento adequado de memória__, __modularização do código em funções__ e __documentação__ adequada, foi necessario aprender sobre __otimização de desempenho__ para garantir que o jogo seja executado suavemente.

A parte _**mandatoria**_, compoem:

- #### Configuração da janela e buffer de imagem:
- [ ] Inicialize a janela MinilibX.
- [ ] Criar um buffer de imagem para desenhar o labirinto.

- #### Carregamento do labirinto:
- [ ] Carregue o modelo 3D do labirinto.
- [ ] Converta o modelo 3D em um formato adequado para renderização (por exemplo, um mapa de texturas).

- #### Implementação do Ray-Casting:
- [ ] Lançar raios a partir da posição da câmera em diferentes ângulos para determinar o que é visível.
- [ ] Para cada raio lançado, determine onde ele atinge o labirinto (interseção).
- [ ] Calcular a distância da câmera até o ponto de interseção.
- [ ] Use a distância para determinar a altura da parede a ser desenhada na tela.
- [ ] Renderizar as colunas verticais das paredes de acordo com as alturas calculadas.

- #### Movimentação e interação:
- [ ] Implemente os controles de movimentação (avançar, retroceder, girar).
- [ ] Implemente detecção de colisões para evitar que o jogador atravesse as paredes.

- #### Iluminação e sombreamento (opcional):
- [ ] Adicionar efeitos de iluminação e sombreamento para tornar o ambiente mais realista.

- #### Gerenciamento de eventos:
- [ ] Capturar eventos de teclado para controlar a movimentação do jogador e sair do jogo.

- #### Loop de renderização:
- [ ] Implementar um loop que atualiza continuamente o buffer de imagem e exibir na janela.


## Estrutura do Projeto
```
cub3d/
│
├── src/             # Código-fonte do jogo
│   ├── main.c       # Arquivo principal
│   ├── game/        # Código do jogo em si
│   ├── graphics/    # Código para renderização gráfica
│   ├── input/       # Código de entrada (controles do jogador)
│   ├── assets/      # Recursos do jogo (texturas, modelos, etc.)
│
├── include/         # Arquivos de cabeçalho (.h)
│   ├── game.h
│   ├── graphics.h
│   ├── input.h
│   ├── ...
│
├── lib/             # Bibliotecas e dependências do projeto
│   ├── libft/    # Biblioteca Libft (ou outra biblioteca gráfica)
│   ├── ...
│
├── data/            # Dados do jogo (mapas, configurações)
│
├── bin/             # Executável compilado
│
├── Makefile         # Arquivo de compilação
│
├── README.md        # Documentação do projeto
│
└── ...
```
