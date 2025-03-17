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
cd /home/usuario/Documentos/GitHub/IR2134/exam_ws

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
...
```

#### 7) Create a launch file named "library.launch.xml" for running the simulation and visualization (you can create additional launch files if needed)

- Create the configuration files for RViz and RMF in the "config" folder.
- Add the appropiate instructions for launching the simulation to the documentation.

Guardamos los cambios en Git


#### 8) Add the instructions for running several patrol and clean tasks in the command line.

(Include some figures with snapshots of Gazebo and RViz for each task.


#### 9) When finished, submit a ZIP archive of your package (not the workspace) to the task in Aula Virtual.



