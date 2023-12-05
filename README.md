# Los Desafios de James

Trabajo Práctico Grupal de Algoritmos y Programación 2 2c2023.

### Integrantes del grupo NOMBRE_GRUPO:

1. Balella, Juan - 110271 - jbalella@fi.uba.ar
2. Malbran, Beltran - 110036 - bmalbran@fi.uba.ar
3. Lorenzo, Cabirta - Padron - Mail_FIUBA
4. Frattasi, Roman - 110229 - rfrattasi@fi.uba.ar

### Corrector asignado:

Andres Juarez

## Compilación:

El programa se puede compilar utilizando el **CMakeLists.txt** que está en el repositorio o bien ejecutando por consola:

> g++ -I include src/*.cpp main.cpp -o main -Wall -Werror -Wconversion

Al compilar con **CMake**, se deben agregar todos los archivos **.cpp** en la línea:

> add_executable(ayp2_plantilla_tp_grupal_2c2023 main.cpp //otros archivos .cpp//)

## Tests:

Para ejecutar los tests, basta con cargar el **CMakeLists.txt** que se encuentra dentro de la carpeta tests/.

## Organización de archivos:

En la carpeta src/ van a encontrar los archivos .cpp del proyecto.<br>
En la carpeta include/ van a encontrar los headers del proyecto.<br>