# ALGO GEO
soft for the visualisation and edition to mesh.

![alt tag](https://raw.githubusercontent.com/tiregram/E4-Algo_geo/master/img/i0.png)
![alt tag](https://raw.githubusercontent.com/tiregram/E4-Algo_geo/master/img/i1.png)
![alt tag](https://raw.githubusercontent.com/tiregram/E4-Algo_geo/master/img/i2.png)
![alt tag](https://raw.githubusercontent.com/tiregram/E4-Algo_geo/master/img/i3.png)

## Cours

## TP

### Extra
- [X] Cmake file
- [X] Git project
- [X] Linux port
- [X] separation of helperfunction.h in  helperfunction.hpp and helperfunction.cpp
- [X] Bind key
- [X] shared_ptr on point and normal
- [ ] shared_ptr on the struct

### TP1
- [X] read File
- [x] normal
- [x] distance point   to  point
- [x] distance line    to  point
- [x] distance segment to  segment 
- [x] distance point   to  segment 
- [ ] distance line    to  face

### TP2
- [x] inflate
- [x] smooth
- [x] split face 3
- [x] split face 4
- [x] Catmull-Clark

### TP3
- [ ] Contract
- [ ] Simplified

## Bind Key

| key       | enum CALL           |
| ------    | : -------------:    |
| `n`       | MENU_DRAWNORMALS    |
| `v` & `w` | MENU_DRAWWIREFRAME  |
| `c`       | MENU_CHECK          |
| `C`       | MENU_CATMULLCLARK   |
| `t`       | MENU_TRIANGULATE    |
| `s`       | MENU_DRAWSILHOUETTE |
| `m`       | MENU_DRAWMESH       |
| `i`       | MENU_INFLATE        |
| `F`       | MENU_SPLITFACE      |
| `R`       | MENU_SPLITFACE4     |
| `E`       | MENU_SPLITEDGE      |
| `S`       | MENU_SMOOTHEN       |


## site

site du profeseur
---------------------

https://perso.esiee.fr/~mustafan/

site pour IN4I12
---------------------

https://perso.esiee.fr/~mustafan/Teaching/ESIEE/IN4I12-16/

if the website is delete you can consult it in the directory
sujet/perso.esiee.fr

## Code

Install the package need for the project

```bash
# for arch
pacman -S glew freeglut glm glfw
# add the other distrib ...

```

To run the demo program run this.

```bash
git clone http://github.com/tiregram/E4-Algo_geo
cd E4-Algo_geo

# generate make file
cmake .

# build
make

# run
./Mesh.bin
```
if you have some problem let me a message at ruhtra.mar@gmail.com

