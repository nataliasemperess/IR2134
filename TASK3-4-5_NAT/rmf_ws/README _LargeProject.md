# LARGE PROJECT - NATALIA

En primer lugar, deberemos crear el mapa a través del Traffic-Editor : 

1) Descargamos los mapas, y los convertimos a png :

```bash
cd /home/usuario/Documentos/GitHub/IR2134/TASK3-4-5_NAT/large_project
pdftoppm TD_n0.pdf TD_n0 -png -singlefile
pdftoppm TD_n1.pdf TD_n1 -png -singlefile
```
2) Luego creamos buildings, y pasamos ahí los png
3) Nos metemos al Docker:
   
```bash
cd ~/Documentos/GitHub/IR2134/TASK3-4-5_NAT/large_project

rocker --nvidia --x11 --name traffic-editor --user   --volume `pwd`/buildings:/rmf_demos_ws/buildings --   ghcr.io/open-rmf/rmf/rmf_demos:latest   bash
```

Ahí nos tendremos que meter a la carpeta de buildings




---



