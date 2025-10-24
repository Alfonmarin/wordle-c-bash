# 🟩 Wordle en C – Proyecto de Programación para Sistemas

## 🧩 Descripción general
Proyecto desarrollado en **C** dentro de la asignatura **Programación para Sistemas (ETSIINF-UPM)**.  
Consiste en una implementación completa del juego **Wordle**, ejecutable desde consola, que permite al usuario adivinar una palabra oculta en un número limitado de intentos.

El proyecto incluye un **script Bash** para compilar, ejecutar y gestionar el juego, automatizando el proceso de construcción mediante `gcc` y enlazando con la biblioteca auxiliar **libwordle** desarrollada durante el curso.

---

## 🎯 Objetivos principales
- Programar un **juego interactivo tipo Wordle** en lenguaje C.  
- Gestionar **entrada/salida, memoria dinámica y control de flujo** en consola.  
- Automatizar la **compilación y ejecución** mediante un script Bash.  
- Practicar el uso de **librerías externas, modularidad y Makefile manuales**.

---

## 🧱 Estructura del proyecto

| Ruta / Archivo | Descripción breve |
|---|---|
| **`.vscode/`** | Configuración de tareas/depuración para el editor. |
| **`data/`** | Diccionarios y datasets de prueba: `dicES5.dat`, `dicTest.dat`, `dicTest.txt`. |
| **`lib/include/libwordle.h`** | Cabecera pública de la librería Wordle. |
| **`lib/include/wordle_dicc.h`** | Interfaces de utilidades de diccionario. |
| **`lib/libwordle.so`** | Librería compartida precompilada usada por el juego (`-Llib -lwordle`). |
| **`src/wordle.c`** | **Main** y bucle del juego: lectura de intentos, feedback de colores, control de fin. |
| **`src/pps_iniciar.c` / `src/pps_iniciar.h`** | Inicialización de partida: carga de diccionario y selección de palabra. |
| **`src/pps_dicc.c`** | Funciones de diccionario: lectura `.dat`, validación/búsqueda de palabras. |
| **`src/test_dicc.c` / `src/test_dicc.h`** | Pruebas rápidas para las funciones del diccionario. |
| **`src/fich_log`** | Utilidad de logging (binario/auxiliar). |
| **`src/fich_log.txt`** | Ejemplo/salida de logs de ejecución. |
| **`wordle.sh`** | Script Bash con comandos `construir`, `jugar` y `limpiar` (compilación y ejecución). |


---

## ⚙️ Tecnologías utilizadas
- **Lenguaje:** C (ANSI C, compilado con `gcc -Wall -Wextra -Werror`)  
- **Shell scripting:** Bash  
- **Paradigma:** Programación modular  
- **Entorno:** Linux / Ubuntu (consola)  

---

## ▶️ Cómo ejecutar el proyecto
- 0. Asegúrate de tener permisos de ejecución sobre el script y tener gcc instalado.

- 1. Abre una terminal en el directorio del proyecto (src).

- 2. Compila el programa ejecutando: **bash wordle.sh construir**

- 3. Inicia el juego con: **bash wordle.sh construir**

- 4. (Opcional) Para limpiar los archivos objeto y el ejecutable: **bash wordle.sh limpiar**
   
---

## 🧮 Funcionamiento general

1. El programa selecciona aleatoriamente una palabra del diccionario.  
2. El jugador dispone de **6 intentos** para adivinarla (hasta agotar las filas).  
3. Tras cada intento, el sistema muestra:  
   - 🟩 **Verde** si la letra está en la posición correcta.  
   - 🟨 **Amarillo** si la letra está en la palabra pero en otra posición.  
   - ⬜ **Gris** si la letra no aparece.  
4. El juego termina al acertar la palabra.
