# LARGE PROJECT - NATALIA

En primer lugar, deberemos crear el mapa a través del Traffic-Editor : 

1) Descargamos los mapas, y los convertimos a png :

```bash
cd /home/usuario/Documentos/GitHub/IR2134/TASK3-4-5_NAT/large_project
pdftoppm CD-n0-1.pdf CD-n0-1 -png -singlefile
pdftoppm CD-n1-1.pdf CD-n1-1 -png -singlefile
pdftoppm CD-n2-1.pdf CD-n2-1 -png -singlefile
pdftoppm CD-n3-1.pdf CD-n3-1 -png -singlefile
pdftoppm CD-n4-1.pdf CD-n4-1 -png -singlefile
pdftoppm CD-n5-1.pdf CD-n5-1 -png -singlefile
pdftoppm CD-ns-1.pdf CD-ns-1 -png -singlefile
```
2) Luego creamos buildings, y pasamos ahí los png
3) Nos metemos al Docker:
   
```bash
cd ~/Documentos/GitHub/IR2134/TASK3-4-5_NAT/examen

rocker --nvidia --x11 --name traffic-editor --user   --volume `pwd`/buildings:/rmf_demos_ws/buildings --   ghcr.io/open-rmf/rmf/rmf_demos:latest   bash
```
Una vez dentro, comenzamos a construir a través de traffic-editor, el edificio de la biblioteca, que estará guardado en la carpeta de buildings.

El mapa creado en traffic-editor se nos quedaría así:

PLANTA 2 - (ENTRADA)

![image](https://github.com/user-attachments/assets/082d3a88-deec-471a-8e85-7f6a7b7ea0b4)

Podemos ir probando que el gazebo funciona correctamente con los siguientes comandos : 

### ABRIR GAZEBO

```bash
# Se hace dentro del root
cd buildings/
ros2 run rmf_building_map_tools building_map_generator gazebo biblioteca.building.yaml biblioteca.world ./biblioteca_world

```

```bash
ros2 run rmf_building_map_tools building_map_model_downloader biblioteca.building.yaml -e ./models

export GZ_SIM_RESOURCE_PATH=`pwd`/biblioteca_world:`pwd`/models

// Usamos este export para cuando tengamos ya el robot, sino solo usamos el primer export
export GZ_SIM_RESOURCE_PATH=`pwd`/biblioteca_world:`pwd`/models:/rmf_demos_ws/install/rmf_demos_assets/share/rmf_demos_assets/models

gz sim -r -v 3 biblioteca.world
```


### PASAMOS EL PROYECTO AL RMF_wS (creando las carpetas necesarias)

Ahora deberemos seguir los siguientes pasos : 

#### Terminal 1 : Primeros pasos

Para comenzar, debes abrir un terminal y lanzar el siguiente comando para iniciar el contenedor de Docker con la configuración necesaria.

```bash
cd /home/usuario/Documentos/GitHub/IR2134/TASK3-4-5_NAT/

rocker --nvidia --x11 \
  -e ROS_AUTOMATIC_DISCOVERY_RANGE=LOCALHOST \
  --network host --user \
  --volume `pwd`/rmf_ws:/home/usuario/rmf_ws --  \
  ghcr.io/open-rmf/rmf/rmf_demos:latest 	\
    bash
```
Una vez dentro del contenedo Docker, lo que debemos hacer es ubicarnos en rmf_ws, y ejecutar los siguientes comandos para preparar el entorno de trabajo.

```bash
source /opt/ros/jazzy/setup.bash
sudo cp -R /root/.gazebo .	
cd rmf_ws/

rm -rf build/ install/ log/
colcon build
source install/setup.bash
```

Luego, para lanzar el Gazebo y RViz de "TD_definitivo" ejecutamos:

```bash
ros2 launch rmf_demos_gz biblioteca.launch.xml \
  server_uri:="ws://localhost:8000/_internal"
```
Con esto, se nos abrirá el Gazebo y el Rviz:


#### Terminal 2 : API Server

Abrimos un segundo terminal donde ejecutaremos el servidor API para la interacción con los servicios:

```bash
docker run --network host -it \
  -e ROS_AUTOMATIC_DISCOVERY_RANGE=LOCALHOST \
  -e RMW_IMPLEMENTATION=rmw_cyclonedds_cpp \
	ghcr.io/open-rmf/rmf-web/api-server:latest
```
#### Terminal 3 : Dashboard

En otro terminal, ejecutamos el Dashboard para tener una visualización de las tareas y el estado de los robots:

```bash
docker run --network host -it \
  -e RMF_SERVER_URL=http://localhost:8000 \
  -e TRAJECTORY_SERVER_URL=ws://localhost:8006 \
	ghcr.io/open-rmf/rmf-web/dashboard:latest
```
URL del Dashboard : http://localhost:3000




