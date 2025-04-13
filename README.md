<img src="readme/cub3d.png" alt="cub3d" width="900"/>

# Cub3D
**The Cub3D project is a C-based implementation of a 3D rendering engine using raycasting, a technique similar to the one used in classic games like <ins>Wolfenstein 3D</ins>. The main goal is to create a three-dimensional maze from a 2D map, allowing the player to navigate an immersive environment with a first-person perspective.**<br>

[![Contributors][contributors-shield]][contributors-url]
[![Forks][forks-shield]][forks-url]
[![Stargazers][stars-shield]][stars-url]
[![Issues][issues-shield]][issues-url]
[![LinkedIn][linkedin-shield]][linkedin-url]

## 📒 Index

- [About](#about)
- [Approach](#approach)
- [Installation](#installation)
- [Development](#development)
  - [Pre-Requisites](#pre-requisites)
  - [File Structure](#file-structure)
 <!-- - [Diagram Architecture](#diagram-architecture)  -->
- [Notes](#notes)
- [Credits](#credits)

## About

The heart of the project lies in parsing a configuration file (*.cub*) that defines the map structure, wall textures, floor and ceiling colors, as well as the player's starting position. Once the map is validated, the program uses a raycasting algorithm to project walls in 3D on the screen, calculating distances and angles to simulate realistic perspective. The MiniLibX library (or an alternative depending on constraints) is used to display graphics and handle keyboard/mouse interactions.<br>

**<ins>The mandatory features include:</ins>**<br>
*• Wall collision*<br>
*• A minimap system*<br>
*• Doors that can be opened/closed*<br>
*• Animations (animated sprites)*<br>
*• Rotate the viewpoint with the mouse*<br>

Bonus features can be added to enhance the experience, like a 2D minimap, openable doors, animated sprites, or even light and shadow effects.<br>

## Approach

<ins>**Approach and Collaboration**</ins><br>
This project proved particularly challenging to manage as a team. As with <ins>**Minishell**</ins>, I got ahead of my teammate and began development alone. This dynamic slightly complicated task distribution, leading me to implement the majority of the project autonomously.<br>

<ins>**Parsing: The Technical Challenge**</ins><br>
**I structured the development around rigorous parsing, an essential prerequisite for establishing a robust test suite. The specific complexities included:**<br>

* *Handling adjacent maps within the same file*<br>

* *Supporting variable map sizes*<br>

* *Validating empty spaces (only permitted when surrounded by '1' walls)*<br>

<ins>**Development Pipeline**</ins><br>
**Once parsing was finalized:**<br>

* *Graphical Assets: I selected external resources which I modified in Photoshop to optimize visual rendering.*<br>

* *Raycasting Integration: My teammate (<ins>**tmoel1**</ins>) joined the project at this phase:*<br>

* *He took charge of finalizing the algorithm*<br>

* *Implemented directional movements (WASD) + collision*<br>

![game](readme/game.gif)

<ins>**Additional Features (BONUS):**</ins><br>

* *Added an interactive minimap*<br>

* *Integrated mouse control via a dedicated function*<br>

<ins>**Quality Validation**</ins><br>
**To ensure robustness, we:**<br>

* *Developed an exhaustive test suite with varied maps*<br>

* *Systematically verified edge cases in the parser*<br>

## Installation
```bash
# Clone this repository
$ git clone https://github.com/HaruSnak/Cub3D.git

# Go into the repository
$ cd Cub3D

# To compile the program
$ make

# To compile the program + bonus
$ make bonus

# Execution example
$ ./cub3D [MAP_NAME] (Ex: ./cub3D maps/map1.cub)

# Removes all generated files and the executable for a thorough cleanup.
$ make fclean

# Removes generated object files and the executable.
$ make clean
```

## Development
### Pre-Requisites
```
Requirements for Linux

X11 (Install: sudo apt-get install libx11-dev libxext-dev xorg-dev)
```

### File Structure

```
.
└── 📁Cub3D
    └── 📁assets
        └── 📁textures
            └── EA.PNG
            └── EA.xpm
            └── NO.PNG
            └── NO.xpm
            └── SO.png
            └── SO.xpm
            └── WE.PNG
            └── WE.xpm
        └── 📁ui
            └── main_menu.png
            └── main_menu.xpm
    └── 📁includes
        └── cub3d.h
        └── 📁libft
            └── 📁char
                └── ft_isalnum.c
                └── ft_isalpha.c
                └── ft_isascii.c
                └── ft_isdigit.c
                └── ft_isprint.c
                └── ft_tolower.c
                └── ft_toupper.c
            └── 📁conv
                └── ft_atoi.c
                └── ft_itoa.c
            └── 📁gnl
                └── get_next_line.c
            └── 📁includes
                └── libft.h
            └── 📁lst
                └── ft_lstadd_back_bonus.c
                └── ft_lstadd_front_bonus.c
                └── ft_lstclear_bonus.c
                └── ft_lstdelone_bonus.c
                └── ft_lstiter_bonus.c
                └── ft_lstlast_bonus.c
                └── ft_lstmap_bonus.c
                └── ft_lstnew_bonus.c
                └── ft_lstsize_bonus.c
            └── Makefile
            └── 📁mem
                └── ft_bzero.c
                └── ft_calloc.c
                └── ft_memchr.c
                └── ft_memcmp.c
                └── ft_memcpy.c
                └── ft_memmove.c
                └── ft_memset.c
            └── 📁put
                └── ft_putchar_fd.c
                └── ft_putendl_fd.c
                └── ft_putnbr_fd.c
                └── ft_putstr_fd.c
            └── 📁str
                └── ft_split.c
                └── ft_strchr.c
                └── ft_strcpy.c
                └── ft_strdup.c
                └── ft_striteri.c
                └── ft_strjoin.c
                └── ft_strlcat.c
                └── ft_strlcpy.c
                └── ft_strlen.c
                └── ft_strmapi.c
                └── ft_strncmp.c
                └── ft_strnstr.c
                └── ft_strrchr.c
                └── ft_strtrim.c
                └── ft_substr.c
    └── 📁maps
        └── error1.cub
        └── error10.cub
        └── error11.cub
        └── error12.cub
        └── error13.cub
        └── error14.cub
        └── error15.cub
        └── error16.cub.ber
        └── error17.cub
        └── error18.cub
        └── error19.cub
        └── error2.cub
        └── error20.cub
        └── error21.cub
        └── error22.cub
        └── error23.cub
        └── error24.cub
        └── error25.cub
        └── error26.cub
        └── error27.cub
        └── error28.cub
        └── error29.cub
        └── error3.cub
        └── error30.cub
        └── error31.cub
        └── error32.cub
        └── error33.cub
        └── error34.cub
        └── error35.cub
        └── error36.cub
        └── error37.cub
        └── error38.cub
        └── error39.cub
        └── error4.cub
        └── error40.cub
        └── error41.cub
        └── error42.cub
        └── error43.cub
        └── error44.cub
        └── error45.cub
        └── error46.cub
        └── error47.cub
        └── error48.cub
        └── error49.cub
        └── error5.cub
        └── error50.cub
        └── error51.cub
        └── error52.cub
        └── error53.cub
        └── error54.cub
        └── error55.cub
        └── error56.cub
        └── error57.cub
        └── error6.cub
        └── error7.cub
        └── error8.cub
        └── error9.cub
        └── map1.cub
        └── map2.cub
        └── map3.cub
        └── map4.cub
        └── map5.cub
    └── 📁minilibx-linux
        └── .gitignore
        └── configure
        └── libmlx_Linux.a
        └── libmlx.a
        └── LICENSE
        └── Makefile
        └── Makefile.gen
        └── Makefile.mk
        └── 📁man
            └── 📁man1
                └── mlx_loop.1
                └── mlx_new_image.1
                └── mlx_new_window.1
                └── mlx_pixel_put.1
                └── mlx.1
            └── 📁man3
                └── mlx_loop.3
                └── mlx_new_image.3
                └── mlx_new_window.3
                └── mlx_pixel_put.3
                └── mlx.3
        └── mlx_clear_window.c
        └── mlx_destroy_display.c
        └── mlx_destroy_image.c
        └── mlx_destroy_window.c
        └── mlx_expose_hook.c
        └── mlx_ext_randr.c
        └── mlx_flush_event.c
        └── mlx_get_color_value.c
        └── mlx_get_data_addr.c
        └── mlx_hook.c
        └── mlx_init.c
        └── mlx_int_anti_resize_win.c
        └── mlx_int_do_nothing.c
        └── mlx_int_get_visual.c
        └── mlx_int_param_event.c
        └── mlx_int_set_win_event_mask.c
        └── mlx_int_str_to_wordtab.c
        └── mlx_int_wait_first_expose.c
        └── mlx_int.h
        └── mlx_key_hook.c
        └── mlx_lib_xpm.c
        └── mlx_loop_hook.c
        └── mlx_loop.c
        └── mlx_mouse_hook.c
        └── mlx_mouse.c
        └── mlx_new_image.c
        └── mlx_new_window.c
        └── mlx_pixel_put.c
        └── mlx_put_image_to_window.c
        └── mlx_rgb.c
        └── mlx_screen_size.c
        └── mlx_set_font.c
        └── mlx_string_put.c
        └── mlx_xpm.c
        └── mlx_xpm.c.ok
        └── mlx.h
        └── 📁obj
            └── mlx_clear_window.o
            └── mlx_destroy_display.o
            └── mlx_destroy_image.o
            └── mlx_destroy_window.o
            └── mlx_expose_hook.o
            └── mlx_flush_event.o
            └── mlx_get_color_value.o
            └── mlx_get_data_addr.o
            └── mlx_hook.o
            └── mlx_init.o
            └── mlx_int_anti_resize_win.o
            └── mlx_int_do_nothing.o
            └── mlx_int_get_visual.o
            └── mlx_int_param_event.o
            └── mlx_int_set_win_event_mask.o
            └── mlx_int_str_to_wordtab.o
            └── mlx_int_wait_first_expose.o
            └── mlx_key_hook.o
            └── mlx_loop_hook.o
            └── mlx_loop.o
            └── mlx_mouse_hook.o
            └── mlx_mouse.o
            └── mlx_new_image.o
            └── mlx_new_window.o
            └── mlx_pixel_put.o
            └── mlx_put_image_to_window.o
            └── mlx_rgb.o
            └── mlx_screen_size.o
            └── mlx_set_font.o
            └── mlx_string_put.o
            └── mlx_xpm.o
        └── README.md
        └── rgb2c.pl
        └── 📁test
            └── main.c
            └── main.o
            └── Makefile.gen
            └── Makefile.mk
            └── mlx-test
            └── new_win.c
            └── open.xpm
            └── open24.xpm
            └── open30.xpm
            └── run_tests.sh
    └── 📁srcs
        └── 📁bonus
            └── minimap.c
            └── mouse_rotate.c
        └── cub3d.c
        └── 📁errors
            └── errors.c
        └── 📁game
            └── settings.c
        └── 📁parsing
            └── parsing_map.c
            └── parsing_rgb.c
            └── parsing.c
            └── verify_direction.c
            └── verify_map.c
        └── 📁player
            └── init_player_controls.c
            └── keys.c
            └── player_init_movement.c
            └── player_movement.c
            └── rotate.c
        └── 📁raycasting
            └── raycasting_calcul_bis.c
            └── raycasting_calcul.c
            └── raycasting_draw.c
            └── raycasting_init.c
        └── 📁texturing
            └── init_textures.c
        └── 📁ui
            └── main_menu.c
        └── 📁utils
        └── 📁utils-mlx
            └── function_mlx.c
            └── function_utils.c
            └── parsing_utils.c
    └── cub3d_tester.sh
    └── LICENSE
    └── Makefile
    └── README.md
    └── valgrind_output.txt
```

<!--### Diagram Architecture
Write the build Instruction here.-->

## Notes
<img src="readme/115.png" alt="Notes" width="200"/>

## Credits

Below you will find the links used for this project:

- [Norm 42](https://cdn.intra.42.fr/pdf/pdf/960/norme.en.pdf)
- [Raycasting - Lode Vandevenne](https://lodev.org/cgtutor/raycasting.html)

[contributors-shield]: https://img.shields.io/github/contributors/HaruSnak/Cub3D.svg?style=for-the-badge
[contributors-url]: https://github.com/HaruSnak/Cub3D/graphs/contributors
[forks-shield]: https://img.shields.io/github/forks/HaruSnak/Cub3D.svg?style=for-the-badge
[forks-url]: https://github.com/HaruSnak/Cub3D/network/members
[stars-shield]: https://img.shields.io/github/stars/HaruSnak/Cub3D.svg?style=for-the-badge
[stars-url]: https://github.com/HaruSnak/Cub3D/stargazers
[issues-shield]: https://img.shields.io/github/issues/HaruSnak/Cub3D.svg?style=for-the-badge
[issues-url]: https://github.com/HaruSnak/Cub3D/issues
[linkedin-shield]: https://img.shields.io/badge/-LinkedIn-black.svg?style=for-the-badge&logo=linkedin&colorB=555
[linkedin-url]: https://www.linkedin.com/in/shany-moreno-5a863b2aa

