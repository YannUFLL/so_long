# So Long

## Overview
"So Long" is a 2D maze game developed in C, using the MiniLibX graphics library. The goal is to collect all items and find the exit as quickly as possible.

## Requirements
- C Compiler (gcc recommended)
- MiniLibX Library
- Math Library (option `-lm` when compiling)

## Features
- Movement with W, A, S, D keys
- Count of moves displayed in shell
- Valid map parsing
- Memory leak-free

## Build and Run
```
$ make all
$ ./so_long [map.ber]
```

## Map Format
- 0: Empty space
- 1: Wall
- C: Collectible
- E: Exit
- P: Player's start position

## Contributions
Pull requests are welcome. For major changes, please open an issue first.

## License
MIT
```

Replace the placeholder text as appropriate for your project.
