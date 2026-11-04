#ifndef ROBOT_H
#define ROBOT_H

int getRobotX(void);
int getRobotY(void);
int getRobotOrientation(void);

void updateRobot(void); // update the robot position and orientation based on the current maze configuration.

void forward(void); // move forward to the next square in the direction the robot is facing. If there is a maze wall in front of the robot it does not move.
void left(void); // turn the robot direction left (anti-clockwise) by 90 degrees, while remaining in the same position.
void right(void); // turn the robot direction right (clockwise) by 90 degrees, while remaining in the same position.
bool atMarker(void); // return true if the robot is on the exit marker, otherwise false.
bool canMoveForward(void); // return true if the robot can move forward as there is no maze wall in front of it. Return false otherwise.

#endif