// #include <iostream>
// #include <vector>
// #include <cmath>

// // Define constants
// const double MAX_VELOCITY = 1.0; // Maximum velocity of the robot
// const double K_1 = 0.1; // Proportional gain
// const double K_2 = 0.5; // Steering gain
// const double L = 0.5; // Lookahead distance

// // Define a waypoint structure
// struct Waypoint {
//     double x;
//     double y;
// };

// // Function to calculate the distance between two points
// double distance(double x1, double y1, double x2, double y2) {
//     return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
// }

// // Function to calculate the angle between two points
// double angle(double x1, double y1, double x2, double y2) {
//     return atan2(y2 - y1, x2 - x1);
// }

// // Function to calculate the angle difference between two angles (-pi to pi)
// double angleDifference(double target, double current) {
//     double difference = target - current;
//     while (difference > M_PI) {
//         difference -= 2.0 * M_PI;
//     }
//     while (difference < -M_PI) {
//         difference += 2.0 * M_PI;
//     }
//     return difference;
// }

// // Stanley controller function
// double stanleyController(double targetHeading, double currentHeading, double crossTrackError) {
//     double deltaHeading = angleDifference(targetHeading, currentHeading);
//     double steerAngle = deltaHeading + atan2(K_2 * crossTrackError, MAX_VELOCITY);
//     return steerAngle;
// }

// // Simulated motor control function (replace with actual VEX Robotics motor control)
// void moveMotors(double leftVelocity, double rightVelocity) {
//     std::cout << "Left Motor Velocity: " << leftVelocity << ", Right Motor Velocity: " << rightVelocity << std::endl;
//     // Implement motor control here
// }

// int main() {
//     // Define the path (waypoints)
//     std::vector<Waypoint> path = {{0, 0}, {1, 1}, {2, 0}, {3, 1}, {4, 0}};

//     // Initial robot position and heading
//     double robotX = 0.0;
//     double robotY = 0.0;
//     double robotHeading = 0.0;

//     // Time step for simulation
//     double dt = 0.1;

//     // Loop through each waypoint
//     for (size_t i = 0; i < path.size() - 1; ++i) {
//         // Calculate the target heading and distance to the current waypoint
//         double targetHeading = angle(path[i].x, path[i].y, path[i + 1].x, path[i + 1].y);
//         double distanceToWaypoint = distance(robotX, robotY, path[i + 1].x, path[i + 1].y);

//         // Loop until the robot reaches the current waypoint
//         while (distanceToWaypoint > 0.1) { // Adjust threshold as needed
//             // Calculate cross track error (distance from the path)
//             double crossTrackError = distance(robotX, robotY, path[i].x, path[i].y) *
//                                      sin(angleDifference(targetHeading, robotHeading));

//             // Use Stanley controller to get steering angle
//             double steeringAngle = stanleyController(targetHeading, robotHeading, crossTrackError);

//             // Calculate motor velocities based on steering angle
//             double leftVelocity = MAX_VELOCITY * (1.0 - 0.5 * std::abs(steeringAngle));
//             double rightVelocity = MAX_VELOCITY * (1.0 + 0.5 * std::abs(steeringAngle));

//             // Update robot position and heading (simple forward kinematics)
//             robotX += leftVelocity * cos(robotHeading) * dt;
//             robotY += leftVelocity * sin(robotHeading) * dt;
//             robotHeading += (rightVelocity - leftVelocity) / L * dt;

//             // Update distance to waypoint
//             distanceToWaypoint = distance(robotX, robotY, path[i + 1].x, path[i + 1].y);

//             // Move motors (replace with actual VEX Robotics motor control)
//             moveMotors(leftVelocity, rightVelocity);

//             // Wait for a short time (simulate time step)
//             // wait(std::chrono::milliseconds(static_cast<int>(dt * 1000)));
//         }
//     }

//     return 0;
// }