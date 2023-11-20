# Cub3D
*This project is inspired by the world-famous **Wolfenstein 3D** game.* <br>

## Raycasting vs Raytracing
Raycasting is a rendering technique to create a 3D perspective in a 2D map. Back when computers were slower it wasn't possible to run real 3D engines in realtime, and raycasting was the first solution. Raycasting can go very fast, because only a calculation has to be done for every vertical line of the screen. The most well known game that used this technique, is of course Wolfenstein 3D.


| ![image](https://github.com/hheghine/RayCaster-cub3D/assets/119530584/dcf5dbd9-6185-4470-a68f-ca85acc4f028)  | ![image](https://github.com/hheghine/RayCaster-cub3D/assets/119530584/b3840a9a-f0a5-4516-8eb7-ccf16018eb09)  |
|--------------------------------------------------------------------------------------------------------------|--------------------------------------------------------------------------------------------------------------|

> **Note:** Raycasting is not the same as raytracing! Raycasting is a fast semi-3D technique that works in realtime even on 4MHz graphical calculators, while raytracing is a realistic rendering technique that supports reflections and shadows in true 3D scenes, and only recently computers became fast enough to do it in realtime for reasonably high resolutions and complex scenes.

## Map
The ``cub3d`` executable receives as a single argument, the map file we read, which must be of ``.cub`` filetype.

The file must follow these rules:
- There must be header lines before the actual map containing the following:
    - At least a line containing ``NO``, ``SO``, ``EA`` and ``WE`` followed by a valid path to an xpm image
    - A line starting with ``F`` (**f**loor) or ``C`` (**c**eiling) followed by a color in RGB separated by commas
- Only `` `` *(empty)*, ``1`` *(wall)*, ``0`` *(floor)*, and either ``N``, ``S``, ``E`` or ``W`` *(Player starting position looking at **N**orth, **S**outh, **E**ast or **W**est)*, will be accepted characters in our map.
- The map may not be rectangular, but it must be surrounded by walls
- Spaces are allowed but the player cannot walk on them, thus every space must also be closed/surrounded by walls
- There must be a single player on the map

## Algorithm
To calculate the distance between the player and the nearest wall, we can use the following algorithm:
### 1. Attributes needed for the projection:
|                              Attribute                              |                              Description                              |                              Value                              |
|---------------------------------------------------------------------|-----------------------------------------------------------------------|-----------------------------------------------------------------|
| FOV                                                                 | The field of view of the player                                       | 60º                                                             |
| HFOV                                                                | Half of the player's FOV                                              | 30º                                                             |
| Player's position                                                   | Center of the square where the player is                              | (int)(player_x + 0.5), (int)(player_y + 0.5)                    |
| Ray angle                                                           | Angle of the player view's direction                                  | N (270º), S (90º), E (0º), W (180º)                             |
| Ray increment angle                                                 | Angle difference between one ray and the next one                     | 2 * HFOV / window_width                                         |
| Precision                                                           | Size of 'steps' taken every iteration                                 | 50                                                              |
| Limit                                                               | Limit of the distance the player can view                             | 11                                                              |

| ![image](https://github.com/hheghine/RayCaster-cub3D/assets/119530584/ad61a1df-ace9-4795-8582-bccce62598ba) | ![image](https://github.com/hheghine/RayCaster-cub3D/assets/119530584/a242f578-8909-410b-a1b8-8883b9b9e3b7) |
|-------------------------------------------------------------------------------------------------------------|-------------------------------------------------------------------------------------------------------------|

### 2. From the the player's position incrementing the x's and y's coordinates of the ray.
```
ray.x += ray_sin;
ray.y += ray_cos;
```
### 3. Repeat until we hit a wall.

### 4. Calculate the distance between the player's and the ray's position using the `euclidean distance`:
```
distance = sqrt(powf(x - pl.x - 0.5, 2.0) + powf(y - pl.y - 0.5, 2.0));
```
![image](https://github.com/hheghine/RayCaster-cub3D/assets/119530584/2af01239-dd3e-4723-91cc-c002af685e85)

This algorith is repeated `window_width` times.<br>
This distance is really helpful to calculate the height of the wall height:
```
wall_height = (window_height / (1.5 * distance));
```


