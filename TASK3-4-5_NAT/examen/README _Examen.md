# LARGE PROJECT - NATALIA

En primer lugar, deberemos crear el mapa a través del Traffic-Editor : 

1) Descargamos los mapas, y los convertimos a png :
2) Luego creamos buildings, y pasamos ahí los png
3) Nos metemos al Docker:
   
```bash
cd ~/Documentos/GitHub/IR2134/TASK3-4-5_NAT/examen

rocker --nvidia --x11 --name traffic-editor --user   --volume `pwd`/buildings:/rmf_demos_ws/buildings --    ghcr.io/open-rmf/rmf/rmf_demos:latest   bash
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

### PASOS EXAMEN

#### 1) Create a ROS workspace named "exam_ws" with a README.md file in it. 

```bash
mkdir -p /home/usuario/Documentos/GitHub/IR2134/exam_ws/src
cd /home/usuario/Documentos/GitHub/IR2134/exam_ws
touch README.md
echo "# exam_ws - ROS 2 Workspace" > README.md
```
Guardamos los cambios en Git

```bash
git init
git add README.md
git commit -m "Create workspace"
git push
```

#### 2) Run the Open-RMF Docker container with : 

```bash
rocker --nvidia --x11 --name rmf_library -e ROS_AUTOMATIC_DISCOVERY_RANGE=LOCALHOST --network host --user --volume `pwd`/exam_ws:/exam_ws -- ghcr.io/open-rmf/rmf/rmf_demos:latest bash

```
#### 3) Create a ROS package named "rmf_library" and the folders : "launch", "config" and "maps".

```bash

cd /home/usuario/Documentos/GitHub/IR2134/exam_ws/src
source /opt/ros/humble/setup.bash
ros2 pkg create rmf_library --build-type ament_cmake --license Apache-2.0
cd rmf_library
mkdir launch config maps
```
Guardamos los cambios en Git

```bash
git init
git add README.md
git commit -m "Create package"
git push
```

#### 4) Download the floor plans of the library and convert the PDFs to PNGs and store in "map" folder:

```bash

cd /home/usuario/Documentos/GitHub/IR2134/exam_ws/src/rmf_library/maps

pdftoppm CD-n1-1.pdf CD-n1-1 -png -singlefile
pdftoppm CD-n2-1.pdf CD-n2-1 -png -singlefile
pdftoppm CD-n3-1.pdf CD-n3-1 -png -singlefile
pdftoppm CD-n4-1.pdf CD-n4-1 -png -singlefile
```
Guardamos los cambios en Git

```bash
git init
git add maps
git commit -m "Create floorplans"
git push

```
#### 5) Create a building model named "library.building.yaml" in the "maps" folder with traffic-editor.

```bash
cd /home/usuario/Documentos/GitHub/IR2134/exam_ws/src/rmf_library/maps

```
Guardamos los cambios en Git

```bash
git init
git add maps
git commit -m "Create building model"
git push

```
Si vamos añadiendo cosas vamos comentandolo como walls, navigation graphs, etc.

#### 6) Generate the Gazebo world and navigation graphs.

(Se puede hacer manualmente con menos puntuación o con CMakeLists.txt file con mayor puntuación, en ambos casos debemos añadir las intrucciones utilizadas.)

```bash
...
```
Guardamos los cambios en Git

```bash
git init
git add "rellenar"
git commit -m "Create gazebo world"
git push

```
#### 7) Create a launch file named "library.launch.xml" for running the simulation and visualization (you can create additional launch files if needed)

- Create the configuration files for RViz and RMF in the "config" folder.
- Add the appropiate instructions for launching the simulation to the documentation.

Guardamos los cambios en Git

```bash
git init
git add "rellenar"
git commit -m "Create launch file"
git push

```

#### 8) Add the instructions for running several patrol and clean tasks in the command line.

(Include some figures with snapshots of Gazebo and RViz for each task.

Guardamos los cambios en Git

```bash
git init
git add "rellenar"
git commit -m "Instructions for running tasks."
git push

```

#### 9) When finished, submit a ZIP archive of your package (not the workspace) to the task in Aula Virtual.



### EXTRAS DE OTRAS PRÁCTICAS (BORRAR DESPUÉS)

Ahora deberemos seguir los siguientes pasos : 

#### Terminal 1 : 

Para comenzar, debes abrir un terminal y lanzar el siguiente comando para crear el workspace e iniciar el contenedor de Docker con la configuración necesaria.

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
```

Debemos crear las carpetas necesarias, y meter los archivos correspondientes en cada carpeta : 
![image](https://github.com/user-attachments/assets/8dd420bb-f5a4-4794-9318-152921941c7a)


```bash
rm -rf build/ install/ log/
colcon build
source install/setup.bash
```

Luego, para lanzar el Gazebo y RViz de "biblioteca" ejecutamos:

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




