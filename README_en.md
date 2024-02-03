<a href="./README.md" target="_blank">Potuguês **🇧🇷**</a> | <a href="./README_en.md" target="_blank">English **🇺🇸**</a>

# cub3d 👾​

`CURSO: Engenharia de Software | 42SP`

## :page_facing_up: Índice

* [1. About](#1-about)
* [2. Agile Planning](#2-agile-planning)
* [3. Kanban](#3-kanban)
* [4. Development Stages](#4-development-stages)
* [5.Technologies and External Tools Used](#5-technologies-and-external-tools-used)
* [6. Project Structure](#6-project-structure)
* [7. Developers](#6-Developers)

## 1. About
This project consists of a “realistic” 3D graphic that contains the representation of the interior of a maze from a first-person perspective.
 
The game was created using the _**Ray-Casting technique**_, which simulates the view of a 3D camera in a 2D projection, involving trigonometric and vector calculations. In addition to the _**Scanline technique**_ used to render polygons in 2D graphics. It runs along the horizontal lines of the screen and fills the pixels between the edges of the polygon, determining which pixels should be colored and using the _**Bresenham Algorithm**_ to draw lines on a grid of pixels.

<div align="center">
   <img src="./ezgif.com-speed.gif" alt="Game Cub3D"/>
</div>

## 2. Agile Planning
We used the GitHub kaban in the [Projects](https://github.com/users/luciana-pereira/projects/12) and Discord to plan ideas, organize tasks and facilitate communication during development.

## 3. Kanban

![image](https://github.com/luciana-pereira/cub3d/assets/37550557/1e626031-55c2-4db9-b686-c143956ade7b)

## 4. Development stages
In addition to applying __good programming practices in C__, such as __proper memory management__, __modularization of code into functions__ and __proper documentation__, it was necessary to learn about __performance optimization__ to ensure that the game runs smoothly.

## 5. Technologies and external tools used

#### C language
The project is implemented primarily in C, a low-level programming language, which means that students have to directly deal with memory manipulation and other low-level aspects of programming.

#### MinilibX
We use [MinilibX](https://harm-smits.github.io/42docs/libs/minilibx) which is a simple graphics library designed specifically for 42 projects. It offers basic functionality for window manipulation and graphics rendering . It is a library that helps 42nd Cadets begin to understand the basic principles of graphical programming.

#### Raycasting
The project also involves the implementation of the raycasting algorithm, which is used to render 3D graphics in real time. This is a fundamental concept for creating a sense of depth and perspective in the game.


## 6. Project Structure
```
cub3d/
│
|   ├── bonus/           # Game source code, bonus part
|   |   ├── assets/      # Game resources (textures and maps)
|   |   ├── include/     # Header files (.h)
|   |   │   ├── buttons_bonus.h
|   |   │   ├── colors_bonus.h
|   |   │   ├── constants_bonus.h
|   |   │   ├── cub3d_bonus.h
|   |   │   ├── errors_bonus.h
|   |   │   ├── functions_bonus.h
|   |   │   ├── structs_bonus.h
|   |   │   └── ...
|   |   ├── src/          # Game source code
|   |   │   ├── events/   # Contains code for handling user input events
|   |   │   ├── graphics/ # Contains code for graphics rendering
|   |   │   ├── init/     # Contains initialization code for the game window, mlx, among others.
|   |   │   ├── math/     # Contains code of operations to manipulate vectors, perform transformations and geometric operations necessary for rendering
|   |   │   ├── parse/    # Contains code responsible for analyzing and processing the game's configuration files.
|   |   │   ├── rays/     # Contains code responsible for implementing the ray casting algorithm, among others.
|   |   │   ├── utils/    # Contains code with auxiliary functions.
|   |   │   ├── main.c    # Main file
|   |   |   └── ...
|   |   └──...
|   ├── lib/             # Libraries and project dependencies
|   |   ├── libft/       # Custom library
|   |   ├── minilibx-linux/ # Graphics library
|   |   └──...
|   ├── mandatory/      # Game source code, mandatory part
|   |   ├── assets/     # Game resources (textures and maps)
|   |   ├── include/    # Header files (.h)
|   |   │   ├── buttons.h
|   |   │   ├── colors.h
|   |   │   ├── constants.h
|   |   │   ├── cub3d.h
|   |   │   ├── errors.h
|   |   │   ├── functions.h
|   |   │   ├── structs.h
|   |   │   └── ...
|   |   ├── src/         # Game source code
|   |   │   ├──  events/ # Contains code for handling user input events
|   |   │   ├──  graphics/ # Contains code for graphics rendering
|   |   │   ├──  init/   # Contains initialization code for the game window, mlx, among others.
|   |   │   ├──   math/  # Contains code of operations to manipulate vectors, perform transformations and geometric operations necessary for rendering
|   |   │   ├──   parse/ # Contains code responsible for analyzing and processing the game's configuration files.
|   |   │   ├──  rays/   # Contains code responsible for implementing the ray casting algorithm, among others.
|   |   │   ├──  utils/  # Contains code with auxiliary functions.
|   |   │   ├──  main.c  # Main file
|   |   |   └──...
|   |   └── ...
|   └── ...
├── Makefile             # Build file
├── README.md            # Project documentation
└── ...
```

## 7. Developers :octocat:

<table align="center">
   <tr>
     <td align="center">
       <a href="https://github.com/luizedua42" target="_blank">
         <img src="https://avatars.githubusercontent.com/u/70030484?v=4" width="100px;" alt="Photo by Luiz Eduardo Adami on GitHub"/><br>
         <sub>
           <b>Luiz Eduardo</b>
         </sub>
       </a>
     </td>
      <td align="center">
       <a href="https://github.com/luciana-pereira" target="_blank">
         <img src="https://avatars.githubusercontent.com/u/37550557?v=4" width="100px;" alt="Photo by Luciana Pereira on GitHub"/><br>
         <sub>
           <b>Luciana Pereira</b>
         </sub>
       </a>
     </td>
   </tr>
</table>
