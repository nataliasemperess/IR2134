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


### ABRIR GAZEBO

```bash
# Se hace dentro del root
cd buildings/
ros2 run rmf_building_map_tools building_map_generator gazebo TD_def.building.yaml TD_def.world ./TD_def_world

```

```bash
ros2 run rmf_building_map_tools building_map_model_downloader TD_def.building.yaml -e ./models

export GZ_SIM_RESOURCE_PATH=`pwd`/TD_def_world:`pwd`/models

// Usamos este export para cuando tengamos ya el robot, sino solo usamos el primer export
export GZ_SIM_RESOURCE_PATH=`pwd`/TD_def_world:`pwd`/models:/rmf_demos_ws/install/rmf_demos_assets/share/rmf_demos_assets/models

gz sim -r -v 3 TD_def.world
```


