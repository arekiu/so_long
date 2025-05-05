# so_long

> A simple 2D game developed with the MiniLibX library as part of the 42 programming curriculum.

## 🕹️ About the Project

**so_long** is a small 2D graphical project where the player navigates a character through a maze-like map, collecting items and reaching the exit. The goal is to implement basic game logic, image rendering, and user interaction using a lightweight graphics library.

This project emphasizes:
- Map parsing and validation
- Real-time rendering with MiniLibX
- Event handling (keyboard input)
- Memory management

---

## 🗺️ Map Format

The game map is read from a `.ber` file and must:
- Be rectangular
- Be surrounded by walls (`1`)
- Contain exactly one player start (`P`), at least one exit (`E`), and one or more collectibles (`C`)
