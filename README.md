# 🧱 so_long

A 42 school project: a simple 2D game developed using the MiniLibX graphics library.

## 📌 Project Overview

`so_long` is a basic 2D game where the player must collect all the collectibles on the map and reach the exit. The map is read from a `.ber` file and must pass a series of validations. Graphics rendering is handled using `minilibx-linux`.

## 🎮 Controls

| Key    | Action         |
|--------|----------------|
| `W`    | Move Up        |
| `A`    | Move Left      |
| `S`    | Move Down      |
| `D`    | Move Right     |
| `ESC`  | Exit Game      |

## 🗺️ Map Requirements

The map must follow these rules:

- Must be rectangular
- Surrounded by walls (`1`)
- Contains:
  - One player (`P`)
  - At least one exit (`E`)
  - At least one collectible (`C`)
- The file extension must be `.ber`

Example map:

111111
1P0C01
100001
1C0E01
111111

## 🛠️ Installation

To compile the game, first make sure you have the required libraries:

### 🧩 Dependencies (Linux)
- `gcc` (or another C compiler)
- `make`

You can install them on Ubuntu/Debian with:
```bash```
sudo apt-get update
sudo apt-get install gcc make libx11-dev libxext-dev
## Cloning the Project
git clone --recurse-submodules https://github.com/your-username/so_long.git
cd so_long
make
## Run the Game
./so_long maps/map1.ber



