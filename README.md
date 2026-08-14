# eStone

A Tic Tac Toe game written in C with an SDL3 GUI, a text-mode fallback, and a minimax-based bot opponent.

## Layout

```
headers/    Public headers (type.h, game.h, util.h, window.h)
src/        Implementation files (main.c, game.c, util.c, bot.c, window.c)
CMakeLists.txt
```

- `type.h` — shared types (`gameState`) and board size config.
- `game.c` / `game.h` — main game loop and orchestration.
- `util.c` / `util.h` — board rules: win/draw detection, turn handling, text-mode I/O, end screen.
- `window.c` / `window.h` — SDL3 window creation, rendering, and GUI input handling.
- `bot.c` — minimax opponent.

## Building

Requires CMake 3.20+, a C17 compiler, and SDL3 (via `find_package(SDL3 CONFIG REQUIRED)`).

```bash
cmake -B build
cmake --build build
```

The executable is built as `eStone` (or `eStone.exe` on Windows) inside `build/`.

## Running

```bash
./eStone            # GUI bot plays as Player 2
./eStone -b1         # GUI, bot plays as Player 1
./eStone -b2         # GUI, bot plays as Player 2
./eStone -t          # Terminal Mode
./eStone -2p         # For Two Players
```

## Controls (GUI)

Click a cell to place your mark. After the match ends, click anywhere (or close the window) to exit.
