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
  
![image](https://github.com/user-attachments/assets/8402c0b5-8320-48c8-85b1-e24dea0a116b)

![image](https://github.com/user-attachments/assets/daed2806-1efe-47ab-8848-f88e0553963e)

![image](https://github.com/user-attachments/assets/f5bb7b80-2684-45a4-b332-b35c158b5bc9)

https://github.com/user-attachments/assets/b92cb0b7-21b6-4ceb-aba6-9aba42f086c4

- "partA_2" -> "L1_waiting_room" -> "partB_1"

![image](https://github.com/user-attachments/assets/d1b205ae-faf6-49f2-bc43-65a8f1b49c21)


https://github.com/user-attachments/assets/3e957169-5d83-4446-856f-074ecc612ca0


### Test1 World

HACER UNA INTRODUCCIÓN

![image](https://github.com/user-attachments/assets/3306d853-fe15-4aa9-808f-8a46f112bcea)



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
ros2 launch rmf_demos_gz test1.launch.xml \
  server_uri:="ws://localhost:8000/_internal"
```
Con esto, se nos abrirá

![image](https://github.com/user-attachments/assets/7e64ec3e-0b4a-4eb7-b21b-0a8a9c5340cd)


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



Ahora dentro de la dashboard lanzaremos algunas tasks:

La primera : 

- "esquina_sup" -> "park"
  
![image](https://github.com/user-attachments/assets/f00b6ba1-a0a0-47ff-a8d1-69910c8fa32b)


- "partA_2" -> "L1_waiting_room" -> "partB_1"





---



