Este plugin de Gazebo permite obetner datos de viento de una lista CSV con magnitud y dirección. El plugin lee esta lista y aplica una fuerza global 
al mundo de Gazebo durante un tiempo determinado (para cada par: magnitud-dirección). E

Este tutorial considera que se posee Gazebo Sim 8.9.0 (Harmonic) instalado desde: 
```
https://github.com/PX4/PX4-Autopilot.git
```
También se recomienda usar Ubuntu 22.04 LTS y tener QGroundControl.

==============================================================================================

Pasos a seguir para poder usar este plugin:

1) Generar un folder workspace de Gazebo. No importa la locación pero se reocmnieda en hacerlo en home.

2) Dentro de este nuevo folder se debe colocar la carpeta wind_tests. Toda carpeta de un plugin personalizado tiene la estructura:
```
/plugin
   |___CMakeLists.txt
   |___plugin.hh
   |___plugin.cc
```

3) En el workspace creado, generar una carpeta llamada "build". Cada plugin personalizado necesita de una carpeta build propia. 
4) Ingresar a la carpeta "build" y realizar:
```
  cmake ../src/my_gz_plugin
  make -j4
```

5) Si no existen errores el plugin ya ha sido compilado en el sistema y puede ser usado.
6) Descargar el SDF: test_world.sdf y agregarlo a la ruta:
   ```
   /home/<user>/PX4-Autopilot/Tools/simulation/gz/worlds
   ```
   
7) Descargar los archivos ejemplos CSV y en el SDF cambiar la línea del plugin que los usa, ingresar la ruta donde se los haya guardado para probarlos:

![image](https://github.com/user-attachments/assets/7e254e1b-d6bd-4759-b2dd-0488f266e50f)

El archivo viento1.csv contiene una lista que mantiene constante la dirección del viento pero varía la magnitud de 0m/s a 100m/s alternadamente. 
El archivo viento2.csv mantiene constante la magnitud pero varía la dieracción de 0° a 360°.

9)  Se activa QGroundControl para poder comandar al dron.
10) Para probar el plugin, se ingresa primero a PX4 para activar el entorno:
```
  cd PX4-Autpilot
```

11) Se debe exportar explícitamente la carpeta del build creada para que Gazebo reconozca el nuevo plugin:
```
export GZ_SIM_SYSTEM_PLUGIN_PATH=$GZ_SIM_SYSTEM_PLUGIN_PATH:~/gz_ws/wind_tests_build
```

12) Ya se puede probar el plugin con:
```
PX4_GZ_WORLD=test_world make px4_sitl gz_x500
```
