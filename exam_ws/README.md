# Natalia Sempere - exam_ws

### ABRIR GAZEBO

```bash
# Se hace dentro del root
 cd /exam_ws/src/rmf_library/maps
ros2 run rmf_building_map_tools building_map_generator gazebo library.building.yaml library.world ./library_world

```
```bash
ros2 run rmf_building_map_tools building_map_model_downloader library.building.yaml -e ./models

export GZ_SIM_RESOURCE_PATH=`pwd`/library_world:`pwd`/models

// Usamos este export para cuando tengamos ya el robot, sino solo usamos el primer export
export GZ_SIM_RESOURCE_PATH=`pwd`/library_world:`pwd`/models:/rmf_demos_ws/install/rmf_demos_assets/share/rmf_demos_assets/models

gz sim -r -v 3 library.world
``

### PASOS EXAMEN

#### 1) Create a ROS workspace named "exam_ws" with a README.md file in it. 

```bash
mkdir -p /home/usuario/Documentos/GitHub/IR2134/exam_ws/src
cd /home/usuario/Documentos/GitHub/IR2134/exam_ws
touch README.md
```

#### 2) Run the Open-RMF Docker container with : 

```bash
cd /home/usuario/Documentos/GitHub/IR2134/

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

#### 4) Download the floor plans of the library and convert the PDFs to PNGs and store in "map" folder:

```bash

cd /home/usuario/Documentos/GitHub/IR2134/exam_ws/src/rmf_library/maps

pdftoppm CD-n1-1.pdf CD-n1-1 -png -singlefile
pdftoppm CD-n2-1.pdf CD-n2-1 -png -singlefile
pdftoppm CD-n3-1.pdf CD-n3-1 -png -singlefile
pdftoppm CD-n4-1.pdf CD-n4-1 -png -singlefile
```

#### 5) Create a building model named "library.building.yaml" in the "maps" folder with traffic-editor.

```bash
cd /home/usuario/Documentos/GitHub/IR2134/exam_ws/src/rmf_library/maps
```

#### 6) Generate the Gazebo world and navigation graphs.

(Se puede hacer manualmente con menos puntuación o con CMakeLists.txt file con mayor puntuación, en ambos casos debemos añadir las intrucciones utilizadas.)

```bash
source /opt/ros/jazzy/setup.bash
sudo cp -R /root/.gazebo .	
cd ../../exam_ws

rm -rf build/ install/ log/
colcon build
source install/setup.bash
```

#### 7) Create a launch file named "library.launch.xml" for running the simulation and visualization (you can create additional launch files if needed)

- Create the configuration files for RViz and RMF in the "config" folder.
- Add the appropiate instructions for launching the simulation to the documentation.
  
#### Terminal 1 : Lanzar Gazebo y RViz

```bash 
ros2 launch rmf_library library.launch.xml server_uri:="ws://localhost:8000/_internal"
```
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

Guardamos los cambios en Git

#### 8) Add the instructions for running several patrol and clean tasks in the command line.

PATROL TASK 2 : entrada_ascensores -> salon_L3

https://github.com/user-attachments/assets/49701f72-eb95-48b0-8db6-e80f5587ea66





#### 9) When finished, submit a ZIP archive of your package (not the workspace) to the task in Aula Virtual.

