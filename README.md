# So_long

`so_long` es un juego en 2D creado con C. Consiste en mover al jugador por el mapa recogiendo los objetos y saliendo en el menor número de movimientos posible.   

## Instalación

Para jugar a `so_long` es necesario tener `make` y `gcc` instalado.   

Para instalar el juego, escribiremos el siguiente comando en la terminal: 
```bash
git clone https://github.com/jcherrerosl/so_long.git
cd so_long
make
```
Esto creará un archivo ejecutable `so_long`.    

## Jugar 

Para jugarlo hay que cargar un mapa con extensión `.ber`. Algunos mapas están ya incluidos en el repositorio.   
Ejecutamos el programa con un mapa como argumento, de la siguiente manera:   
```bash
./so_long map1.ber
```
En este caso, nuestro mapa es el siguiente:  
```
11111111111
1P0C0C0E001
11101110111
1C0C0C0C001
11111111111
```
### Leyenda

El mapa se compone por varios elementos:   
- `1`: paredes que no se pueden atravesar
- `P`: el jugador
- `0`: el suelo
- `C`: los objetos coleccionables
- `E`: la salida

### Controles

Las teclas utilizadas en el proyecto para mover al personaje son tanto WASD como las flechas direccionales.   
Pulsar la tecla ESC o darle a la X, cierra la ventana. 

