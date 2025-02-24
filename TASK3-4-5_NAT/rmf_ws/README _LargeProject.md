# LARGE PROJECT - NATALIA

En primer lugar, deberemos crear el mapa a través del Traffic-Editor : 







![image](https://github.com/user-attachments/assets/3306d853-fe15-4aa9-808f-8a46f112bcea)


#### Terminal 1 : Primeros pasos

Para comenzar, debes abrir un terminal y lanzar el siguiente comando para iniciar el contenedor de Docker con la configuración necesaria.

```bash
cd /home/usuario/Documentos/GitHub/IR2134/TASK3y4_NAT/

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

Luego, para lanzar el Gazebo y RViz de "test1" ejecutamos:

```bash
ros2 launch rmf_demos_gz test1.launch.xml \
  server_uri:="ws://localhost:8000/_internal"
```
Con esto, se nos abrirá

![image](https://github.com/user-attachments/assets/7e64ec3e-0b4a-4eb7-b21b-0a8a9c5340cd)


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

Ahora dentro de la dashboard lanzaremos algunas tareas:

- "esquina_sup" -> "park"
  
![image](https://github.com/user-attachments/assets/f00b6ba1-a0a0-47ff-a8d1-69910c8fa32b)

![image](https://github.com/user-attachments/assets/4aab1042-a13f-4a6a-be9f-f9d3b17512cf)

https://github.com/user-attachments/assets/c817da0b-4e1b-490f-8b92-325657d9f12d

Si lo hicieramos desde fuera del Dashboard, deberiamos poner lo siguiente:

```bash
docker exec -it fervent_ride bash //fervent_ride es el nombre de mi docker
source /opt/ros/jazzy/setup.bash
source install/setup.bash
ros2 run rmf_demos_tasks dispatch_patrol -p esquina_sup park -n 1 --use_sim_time

```
Nos mostrará por terminal:

```bash
[INFO] [1739993757.402720729] [task_requester]: Using Sim Time
[INFO] [1739993757.406213071] [task_requester]: Using 'dispatch_task_request'
Json msg payload: 
{
  "type": "dispatch_task_request",
  "request": {
    "unix_millis_request_time": 0,
    "unix_millis_earliest_start_time": 0,
    "requester": "rmf_demos_tasks",
    "category": "patrol",
    "description": {
      "places": [
        "esquina_sup",
        "park"
      ],
      "rounds": 1
    }
  }
}
Got response: 
{'state': {'booking': {'id': 'patrol.dispatch-028ad14662', 'requester': 'rmf_demos_tasks', 'unix_millis_earliest_start_time': 0, 'unix_millis_request_time': 0}, 'category': 'patrol', 'detail': {'places': ['esquina_sup', 'park'], 'rounds': 1}, 'dispatch': {'errors': [], 'status': 'queued'}, 'status': 'queued', 'unix_millis_start_time': 0}, 'success': True}

```

![image](https://github.com/user-attachments/assets/7ebc4769-87d7-4a89-bd56-501a1b379386)


- "entrada_ascensor" -> "puntoA" 

![image](https://github.com/user-attachments/assets/f28751c3-9087-4f70-b866-b4f5086cc180)

![Captura desde 2025-02-19 19-57-23](https://github.com/user-attachments/assets/6f81eefb-7db3-474f-b436-5d6175fe1b11)

https://github.com/user-attachments/assets/9e4eb11f-1248-41aa-b3ef-d3f8a2d71ec1

Si lo hicieramos desde fuera del Dashboard, deberiamos poner lo siguiente:

```bash
docker exec -it fervent_ride bash //fervent_ride es el nombre de mi docker
source /opt/ros/jazzy/setup.bash
source install/setup.bash
ros2 run rmf_demos_tasks dispatch_patrol -p entrada_ascensor puntoA -n 1 --use_sim_time
```
Nos mostrará por terminal:

```bash
[INFO] [1739994140.393732516] [task_requester]: Using Sim Time
[INFO] [1739994140.397495911] [task_requester]: Using 'dispatch_task_request'
Json msg payload: 
{
  "type": "dispatch_task_request",
  "request": {
    "unix_millis_request_time": 0,
    "unix_millis_earliest_start_time": 0,
    "requester": "rmf_demos_tasks",
    "category": "patrol",
    "description": {
      "places": [
        "entrada_ascensor",
        "puntoA"
      ],
      "rounds": 1
    }
  }
}
Got response: 
{'state': {'booking': {'id': 'patrol.dispatch-474ca589e8', 'requester': 'rmf_demos_tasks', 'unix_millis_earliest_start_time': 0, 'unix_millis_request_time': 0}, 'category': 'patrol', 'detail': {'places': ['entrada_ascensor', 'puntoA'], 'rounds': 1}, 'dispatch': {'errors': [], 'status': 'queued'}, 'status': 'queued', 'unix_millis_start_time': 0}, 'success': True}


```

![image](https://github.com/user-attachments/assets/a6514847-205e-48c8-8ba5-00e72ab39dcd)

### 2) ICC Kyoto World

Ahora trabajaremos con el mundo del hotel ICC Kyoto, el que trabajamos en la práctica anterior.


#### Terminal 1 : Primeros pasos

 Al igual que en el Test1, debes iniciar el Docker y ejecutar los mismos comandos para preparar el entorno.

```bash
cd /home/usuario/Documentos/GitHub/IR2134/TASK3y4_NAT/

rocker --nvidia --x11 \
  -e ROS_AUTOMATIC_DISCOVERY_RANGE=LOCALHOST \
  --network host --user \
  --volume `pwd`/rmf_ws:/home/usuario/rmf_ws --  \
  ghcr.io/open-rmf/rmf/rmf_demos:latest 	\
    bash
```
Luego, se ejecuta también los mismos comandos para compilar los archivos de la workspace.

```bash
source /opt/ros/jazzy/setup.bash
sudo cp -R /root/.gazebo .	
cd rmf_ws/

rm -rf build/ install/ log/
colcon build
source install/setup.bash
```

Para lanzar el mundo Kyoto (yo lo llamo como roomB)

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
URL del Dashboard : http://localhost:3000

![image](https://github.com/user-attachments/assets/28841615-f6fd-49d5-80e9-28dd8b063533)

Ahora dentro de la dashboard lanzaremos algunas tasks:

- "partA_1" -> "ascensor" -> "partC_2"
  
![image](https://github.com/user-attachments/assets/8402c0b5-8320-48c8-85b1-e24dea0a116b)

![image](https://github.com/user-attachments/assets/daed2806-1efe-47ab-8848-f88e0553963e)

![image](https://github.com/user-attachments/assets/f5bb7b80-2684-45a4-b332-b35c158b5bc9)

https://github.com/user-attachments/assets/b92cb0b7-21b6-4ceb-aba6-9aba42f086c4


- "partA_2" -> "L1_waiting_room" -> "partB_1"

![image](https://github.com/user-attachments/assets/d1b205ae-faf6-49f2-bc43-65a8f1b49c21)


https://github.com/user-attachments/assets/3e957169-5d83-4446-856f-074ecc612ca0




---



