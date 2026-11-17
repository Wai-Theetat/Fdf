# FdF

A 3D wireframe renderer in C (42 curriculum). It reads a height map from a `.fdf` file and draws it as an isometric wireframe using the **MLX42** graphics library.

## Features
- Parses `.fdf` height maps (with optional hex colors) and validates the input
- Isometric projection with 3-axis rotation
- Auto-fits the map to the window on startup
- Color by height, with a toggle between color modes
- Keyboard controls for moving, rotating, and zooming

## Controls
| Key | Action |
|---|---|
| Arrow keys | Move the map |
| `W` `A` `S` `D` | Rotate on X / Y axis |
| `Q` `E` | Rotate on Z axis |
| `+` `-` | Zoom in / out |
| `Space` | Toggle color mode |

## Build & Run
Requires `cmake` and `glfw` for MLX42.

```bash
make
./fdf test_maps/42.fdf
```

> On NixOS/some Linux setups, you may need:
> `sed -i 's|/bin/bash|/usr/bin/env bash|' MLX42/tools/compile_shader.sh`

## Known issues / TODO
- Color gradient snaps between colors instead of blending smoothly
