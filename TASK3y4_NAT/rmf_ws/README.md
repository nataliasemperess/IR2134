# RMF Demos

![](https://github.com/open-rmf/rmf_demos/workflows/build/badge.svg)
![](https://github.com/open-rmf/rmf_demos/workflows/style/badge.svg)

The Open Robotics Middleware Framework (Open-RMF) enables interoperability among heterogeneous robot fleets while managing robot traffic that share resources such as space, building infrastructure systems (lifts, doors, etc) and other automation systems within the same facility. Open-RMF also handles task allocation and conflict resolution  among its participants (de-conflicting traffic lanes and other resources). These capabilities are provided by various libraries in [Open-RMF](https://github.com/open-rmf/rmf).
For more details about Open RMF, refer to the comprehensive documentation provided [here](https://osrf.github.io/ros2multirobotbook/intro.html).

This repository contains demonstrations of the above mentioned capabilities of RMF. It serves as a starting point for working and integrating with Open-RMF.

You can also find a nice demonstration of Open-RMF using `Nav2` and `MoveIt!` built into the [Ionic Release Demo](https://github.com/gazebosim/ionic_demo).

[![Robotics Middleware Framework](../media/thumbnail.png?raw=true)](https://vimeo.com/405803151)

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

![image](https://github.com/user-attachments/assets/13c57bfb-6c41-4bf6-92c2-a18885314741)

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

---

