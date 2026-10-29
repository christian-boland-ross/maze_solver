# Plan
Course checklist:
- [ ] Display a maze
- [ ] Display a robot
- [ ] Implement a maze search algorithm
- [ ] Implement a maze generator algorithm
- [ ] Improve searcher algorithm to work with all possible mazes

Main parts:
- [ ] [2D maze](#2d-maze)
- [ ] [3D maze](#3d-maze)
- [ ] [Maze Searcher](#maze-searcher)
- [ ] [Maze Generator](#maze-generator)

## 2D maze
TO-DO:
- [ ] Grid
- [ ] Walls
- [ ] Robot

### Robot Interface
As according to the [CCoursework specification](CCoursework.pdf)

>The robot is simple and only these functions should be provided to control the robot:<br>
>• forward() – move forward to the next square in the direction the robot is facing. If there is a maze wall in front of the robot it does not move.<br>
>• left() – turn the robot direction left (anti-clockwise) by 90 degrees, while remaining in the same position.<br>
>• right() – turn the robot direction right (clockwise) by 90 degrees, while remaining in the same position.<br>
>• int atMarker() – return true if the robot is on the exit marker, otherwise false.<br>
>• int canMoveForward() – return true if the robot can move forward as there is no maze wall in front of it. Return false otherwise.<br>

## 3D maze
TO-DO:
- [ ] Draw floor and sky
- [ ] Determine visible walls
- [ ] Draw visible walls
- [ ] Lighting? <!-- Torch and simulate light falloff? or fog? multiple worlds? -->

## Maze Searcher
TO_DO:
- [ ] Choose Algorithm
- [ ] Implement connectivity using [Robot Interface](#robot-interface)


## Maze Generator
TO-DO:
- [ ] Choose algorithm
- [ ] Decide connectivity <!-- File? Array by argument? Other method? -->
