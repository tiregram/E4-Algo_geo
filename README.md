# ALGO GEO

![alt tag](https://raw.githubusercontent.com/tiregram/E4-Algo_geo/master/img/i0.png)
![alt tag](https://raw.githubusercontent.com/tiregram/E4-Algo_geo/master/img/i2.png)
![alt tag](https://raw.githubusercontent.com/tiregram/E4-Algo_geo/master/img/i3.png)
![alt tag](https://raw.githubusercontent.com/tiregram/E4-Algo_geo/master/img/i4.png)




### Cours
- [X] read File
- [x] normal
- [x] distance point   to  point
- [x] distance line    to  point
- [x] distance segment to  segment 
- [x] distance point   to  segment 
- [ ] distance line    to  face

## TP

### Extra
- [X] Cmake file
- [X] Git project
- [X] Linux port

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

### TD

### site

site du profeseur
---------------------

https://perso.esiee.fr/~mustafan/

site pour IN4I12
---------------------

https://perso.esiee.fr/~mustafan/Teaching/ESIEE/IN4I12-16/

if the website is delete you can consult it in the directory
sujet/perso.esiee.fr

## Code

Install the package need by the project

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

