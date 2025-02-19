# FIRST PROJECT - NATALIA

## Demo Worlds

* [Simple World](#Simple-World)
* [ICC Kyoto World](#ICC-Kyoto-World)

---
### ICC Kyoto World

HACER UNA INTRODUCCIÓN

![](../media/hotel_world.png)


#### Primeros pasos

 Para lanzar el docker debemos lanzar el siguiente comando:

```bash
cd /home/usuario/Documentos/GitHub/IR2134/TASK3y4_NAT/

rocker --nvidia --x11 \
  -e ROS_AUTOMATIC_DISCOVERY_RANGE=LOCALHOST \
  --network host --user \
  --volume `pwd`/rmf_ws:/home/usuario/rmf_ws --  \
  ghcr.io/open-rmf/rmf/rmf_demos:latest 	\
    bash
```
Una vez en el docker, lo que debemos hacer es ubicarnos en rmf_ws y hacer el colcon

```bash
source /opt/ros/jazzy/setup.bash
sudo cp -R /root/.gazebo .	
cd rmf_ws/

rm -rf build/ install/ log/
colcon build
source install/setup.bash
```

To launch the world and the schedule visualizer,

```bash
source ~/rmf_ws/install/setup.bash
ros2 launch rmf_demos_gz roomB.launch.xml \
  server_uri:="ws://localhost:8000/_internal"
```
Con esto, se nos abrirá

![image](https://github.com/user-attachments/assets/81998668-d22f-4e06-9f86-d7117670e507)

#### Terminal 2 : API Server

```bash
docker run --network host -it \
  -e ROS_AUTOMATIC_DISCOVERY_RANGE=LOCALHOST \
  -e RMW_IMPLEMENTATION=rmw_cyclonedds_cpp \
	ghcr.io/open-rmf/rmf-web/api-server:latest
```
#### Terminal 3 : Dashboard

```bash
docker run --network host -it \
  -e RMF_SERVER_URL=http://localhost:8000 \
  -e TRAJECTORY_SERVER_URL=ws://localhost:8006 \
	ghcr.io/open-rmf/rmf-web/dashboard:latest
```
WEB : http://localhost:3000

![image](https://github.com/user-attachments/assets/28841615-f6fd-49d5-80e9-28dd8b063533)

Ahora dentro de la dashboard lanzaremos algunas tasks:

La primera : 

- "partA_1" -> "ascensor" -> "partC_2"

https://github.com/user-attachments/assets/b92cb0b7-21b6-4ceb-aba6-9aba42f086c4


---



