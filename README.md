# Cube3D
Summary:  This project is inspired by the world-famous Wolfenstein 3D game, which  
was the first FPS ever. It will enable you to explore ray-casting. Your goal will be to  
make a dynamic view inside a maze, in which you’ll have to find your way.

---

Run (compile on Linux only):
```
make
./cub3D <map.cub>
```
Screenshot: 
```
make
./cub3D <map.cub> --save
```
---
Control:
<kbd>W</kbd>, <kbd>A</kbd>, <kbd>S</kbd>, <kbd>D</kbd> - move
<kbd>LEFT</kbd><kbd>RIGHT</kbd> - rotate camera
<kbd>ESC</kbd> - exit

---
General settings (.cub file):

`R` - Resolution 
`S` - Sprite texture 
`C` - Sky color 
`F` - Floor color 
`NO` - North wall texture 
`SO` - South wall texture 
`WE` - West wall texture 
`EA` - East wall texture 

Map settings:

`0` - Empty space
`1` - Wall
`2` - Sprite
`N, S, W, E` - player start position and spawning orientation
