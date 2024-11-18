# So_long

`so_long` es un juego en 2D creado con C y la biblioteca MiniLibX. Consiste en mover al jugador por el mapa recogiendo los objetos y saliendo en el menor número de movimientos posible.   

![gif_solong](https://github.com/user-attachments/assets/f8902a9d-42b6-4538-9435-ca57d5523136)


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
que se ve así:

![image](https://github.com/user-attachments/assets/3f4f7e86-ec49-4fa8-8c0a-70a57f735409)


Si quieres un reto superior, ejecuta el programa con el segundo mapa, que es más enrevesado:
```bash
./so_long map2.ber
```
Este laberinto ha sido creado por [@Aloik1](https://github.com/Aloik1).

### Leyenda

El mapa se compone por varios elementos:   
- `1`: paredes que no se pueden atravesar   
- `P`: el jugador   
- `0`: el suelo   
- `C`: los objetos coleccionables    
- `E`: la salida    

### Reglas para el mapa

Un mapa válido necesita cumplir con las siguientes consideraciones:   

- Tiene que estar rodeado por paredes
- Tiene que haber un solo jugador
- Tiene que tener una sola salida
- Tiene que haber, al menos, un coleccionable
- El resto del mapa puede alternar entre suelo y paredes, pero tiene que existir un camino válido, esto es, que todos los objetos coleccionables puedan ser recogidos y que sea posible salir.   

### Controles

Las teclas utilizadas en el proyecto para mover al personaje son tanto WASD como las flechas direccionales.   
Pulsar la tecla ESC o darle a la X, cierra la ventana. 

## Agradecimientos

Los sprites de este juego han sido obtenidos de [The Spriter's Resource](https://www.spriters-resource.com), concretamente de los creadores Hoeloe, FrenchOrange y redblueyellow. 
