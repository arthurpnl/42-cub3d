*This project has been created as part of the 42 curriculum by arpenel, skoudad.*

# cub3D

## Description

cub3D is a 42 graphics project: a small raycasting engine inspired by
Wolfenstein 3D. The program reads a `.cub` scene file and renders a textured
3D view of a maze that you can walk around in, using miniLibX.

## Features

- Parses a `.cub` file: 4 wall textures, floor color, ceiling color, map.
- Map validation with flood-fill (the map has to be closed by walls).
- Raycasting renderer (DDA), one texture per wall side (N/S/E/W).
- Movement with `W` `A` `S` `D`, camera rotation with `←` `→`.
- `ESC` and the window cross both close the program cleanly.
- On any error: prints `Error\n` + a message, frees everything, exits.

## Instructions

Linux only (the miniLibX shipped with the project is the X11 one).
You'll need `gcc`, `make`, and the X11 dev headers
(`libx11-dev`, `libxext-dev`, `zlib1g-dev` on Debian/Ubuntu).

```sh
make
./cub3D maps/map.cub
```

Other rules: `clean`, `fclean`, `re`.

## Map format

```
NO ./textures/north.xpm
SO ./textures/south.xpm
WE ./textures/west.xpm
EA ./textures/east.xpm

F 0,255,204
C 255,32,0

1111111111
1000000001
10N0000001
1000000001
1111111111
```

- `1` wall, `0` empty, `N`/`S`/`E`/`W` player spawn + facing.
- Identifiers can be in any order, the map must come last.
- Spaces are valid inside the map; the map just has to be closed.

## Project layout

```
sources/
  main.c, utils.c, ft_math.c
  parsing/    -> .cub parser + map validation (flood-fill)
  rendering/  -> raycasting, textures, hooks, movement
includes/cub3d.h
libft/, gnl/, minilibx-linux-master/
textures/, maps/
```

## Resources

- Lode's raycasting tutorial — https://lodev.org/cgtutor/raycasting.html
  (this is basically *the* reference for grid raycasting, DDA, fisheye fix,
  textured walls).
- 42docs MLX reference — https://harm-smits.github.io/42docs/libs/minilibx
- Fabien Sanglard's Wolf3D black book for historical context.
- `man` pages for `open`, `read`, `malloc`, `printf`, `gettimeofday`.

### About AI

We used ChatGPT / Claude as a tutor, not as a code generator: to get the
raycasting math explained differently when the tutorial wasn't clicking
(camera plane, perpWallDist, fisheye correction), and to bounce ideas around
for the parser (mainly the flood-fill to check that the map is closed).
The code was written and debugged by us — if it's in the repo, we can
explain it.
