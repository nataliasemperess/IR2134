# Natalia Sempere - exam_ws

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

pdftoppm CD-n0-1.pdf CD-n0-1 -png -singlefile
pdftoppm CD-n1-1.pdf CD-n1-1 -png -singlefile
pdftoppm CD-n2-1.pdf CD-n2-1 -png -singlefile
pdftoppm CD-n3-1.pdf CD-n3-1 -png -singlefile
pdftoppm CD-n4-1.pdf CD-n4-1 -png -singlefile
pdftoppm CD-n5-1.pdf CD-n5-1 -png -singlefile
```

#### 5) Create a building model named "library.building.yaml" in the "maps" folder with traffic-editor.

```bash
cd /home/usuario/Documentos/GitHub/IR2134/exam_ws/src/rmf_library/maps
```
Dentro del Docker, abrimos el traffic-editor y empezamos a construir el modelo.

#### 6) Generate the Gazebo world and navigation graphs.

```bash
source /opt/ros/jazzy/setup.bash
sudo cp -R /root/.gazebo .	
cd ../../exam_ws

rm -rf build/ install/ log/
colcon build
source install/setup.bash
```

#### 7) Create a launch file named "library.launch.xml" for running the simulation and visualization (you can create additional launch files if needed)

#### Terminal 1 : Lanzar Gazebo y RViz

```bash 
ros2 launch rmf_library library.launch.xml 
```
Una vez nos ubiquemos en el Gazebo y en el RViz, hay que tener en cuenta que el edificio lo he diseñado para que empiece por la planta "L2_entrada" (así lo deberás indicar en el RViz para poder visualizarla), el resto de plantas corresponden a los nombres : "L1", "L3", "L4", "L5" Y "L6".

#### Terminal 2 : API Server (Solo en el caso de lanzar las tasks por la Dashboard)

Abrimos un segundo terminal donde ejecutaremos el servidor API para la interacción con los servicios:

```bash
docker run --network host -it \
  -e ROS_AUTOMATIC_DISCOVERY_RANGE=LOCALHOST \
  -e RMW_IMPLEMENTATION=rmw_cyclonedds_cpp \
	ghcr.io/open-rmf/rmf-web/api-server:latest
```
#### Terminal 3 : Dashboard (Solo en el caso de lanzar las tasks por la Dashboard)

En otro terminal, ejecutamos el Dashboard para tener una visualización de las tareas y el estado de los robots:

```bash
docker run --network host -it \
  -e RMF_SERVER_URL=http://localhost:8000 \
  -e TRAJECTORY_SERVER_URL=ws://localhost:8006 \
	ghcr.io/open-rmf/rmf-web/dashboard:latest
```
URL del Dashboard : http://localhost:3000

#### 8) Add the instructions for running several patrol and clean tasks in the command line.

#### POR TERMINAL 

PATROL TASK 1 : 

```bash
 docker exec -it rmf_library bash
cd ../../exam_ws
source /opt/ros/jazzy/setup.bash
source install/setup.bash
ros2 run rmf_demos_tasks dispatch_patrol -p entrada_ascensor -n 1 --use_sim_time
```
![task1](https://github.com/user-attachments/assets/a41f0fa2-5ba7-4055-a647-92c02b6cea38)


PATROL TASK 2 : 

```bash
docker exec -it rmf_library bash
cd ../../exam_ws
source /opt/ros/jazzy/setup.bash
source install/setup.bash
ros2 run rmf_demos_tasks dispatch_patrol -p (PUNTO) -n 1 --use_sim_time
```

PATROL TASK 3 : 

```bash
docker exec -it rmf_library bash
cd ../../exam_ws
source /opt/ros/jazzy/setup.bash
source install/setup.bash
ros2 run rmf_demos_tasks dispatch_patrol -p (PUNTO)  -n 1 --use_sim_time
```

CLEAN TASK 1 : 

```bash
docker exec -it rmf_library bash
cd ../../exam_ws
source /opt/ros/jazzy/setup.bash
source install/setup.bash
ros2 run rmf_demos_tasks dispatch_clean -cs  clean_zona1 --use_sim_time
```

CLEAN TASK 2 : 

```bash
docker exec -it rmf_library bash
cd ../../exam_ws
source /opt/ros/jazzy/setup.bash
source install/setup.bash
ros2 run rmf_demos_tasks dispatch_clean -cs  clean_zona2 --use_sim_time
```

CLEAN TASK 3 : 

```bash
docker exec -it rmf_library bash
cd ../../exam_ws
source /opt/ros/jazzy/setup.bash
source install/setup.bash
ros2 run rmf_demos_tasks dispatch_clean -cs  clean_zona3  --use_sim_time
```

![imagen](https://github.com/user-attachments/assets/37744c75-f644-49ac-ba5b-ea15184a292b)


https://github.com/user-attachments/assets/f1903293-113d-4f70-8c6f-135488ea1be6


#### POR DASHBOARD (EXTRA)

PATROL TASK 1 : entrada_ascensores -> salon_L3

https://github.com/user-attachments/assets/49701f72-eb95-48b0-8db6-e80f5587ea66

CLEAN TASK 1 : clean_zona2

https://github.com/user-attachments/assets/960d060b-0275-464e-9a47-25a340e08052

----------------------------------------------------------------------------------
### EXTRAS (PARA IR PROBANDOLO YO AL PRINCIPIO) GAZEBO

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
----------------------------------------------------------------------------------
