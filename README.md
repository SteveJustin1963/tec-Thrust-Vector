# tec-Thrust-Vector
tec-1 Thrust Vector Controlled Rocket

In rocketry and ballistic missiles, thrust vectoring is the primary means of attitude control. Exhaust vanes and gimbaled engines were used in the 1930s by Robert Goddard. Thrust vectoring is the ability to generate pitch and yaw moments by deflecting the main rocket thrust vector so that it does not pass through the vehicle's center of mass. Roll control usually requires the use of two or more separately hinged nozzles or a separate system altogether.

### Gimbaled thrust
Thrust vectoring for many liquid rockets is achieved by gimbaling the whole engine. This involves moving the entire combustion chamber and outer engine bell.   A later method developed for solid propellant ballistic missiles achieves thrust vectoring by deflecting only the nozzle.


![](https://github.com/SteveJustin1963/tec-Thrust-Vector/blob/main/pics/1.png)

### Propellant injection
It involves injecting fluid into the exhaust flow from injectors mounted around the aft end of the missile. If the liquid is injected on only one side of the missile, it modifies that side of the exhaust plume, resulting in different thrust on that side resulting in asymmetric net forces

### Vernier thrusters
are used when  a wide range of different thrust levels for attitude or velocity control. The name is derived from vernier calipers which have a primary scale for gross measurements, and a secondary scale for fine measurements.
  
### Jet vanes 
allow thrust to be deflected without moving any parts of the engine. They have the benefit of allowing roll control with only a single engine, which nozzle gimbaling does not. Jet vanes must be made of refractory material or actively cooled to prevent melting.  

### mechanical vanes
smaller atmospheric missiles dont use flight control surfaces and instead use mechanical vanes to deflect rocket motor exhaust. Thrust vectoring can reduce a missile's minimum range. 

### project

write c code to control Thrust vectoring algorithm using 2 axis gimbaling

https://github.com/SteveJustin1963/tec-Thrust-Vector/blob/main/tv1.c


combine this c code with ballistic algorithm



combine this c code with trajectory control




void trajectory_control(double *position, double *velocity, double *acceleration, double *thrust, double *mass, double *drag, double *desired_position, double *desired_velocity, double *desired_acceleration)
{
    double F_drag[3];
    double F_thrust[3];
    double F_desired[3];

    // Calculate drag force
    F_drag[0] = -0.5 * (*drag) * (*velocity) * (*velocity);
    F_drag[1] = -0.5 * (*drag) * (*velocity) * (*velocity);
    F_drag[2] = -0.5 * (*drag) * (*velocity) * (*velocity);

    // Calculate thrust force
    F_thrust[0] = *thrust * (*mass);
    F_thrust[1] = *thrust * (*mass);
    F_thrust[2] = *thrust * (*mass);

    // Calculate desired force
    F_desired[0] = (*desired_position - position[0]) * kp + (*desired_velocity - velocity[0]) * kv + (*desired_acceleration - acceleration[0]) * ka;
    F_desired[1] = (*desired_position - position[1]) * kp + (*desired_velocity - velocity[1]) * kv + (*desired_acceleration - acceleration[1]) * ka;
    F_desired[2] = (*desired_position - position[2]) * kp + (*desired_velocity - velocity[2]) * kv + (*desired_acceleration - acceleration[2]) * ka;

    // Calculate net force
    acceleration[0] = (F_thrust[0] + F_drag[0] + F_desired[0]) / (*mass);
    acceleration[1] = (F_thrust[1] + F_drag[1] + F_desired[1]) / (*mass);
    acceleration[2] = (F_thrust[2] + F_drag[2] + F_desired[2]) / (*mass);

    // Update velocity
    velocity[0] += acceleration[0] * dt;
    velocity[1] += acceleration[1] * dt;
    velocity[2] += acceleration[2] * dt;

    // Update position
    position[0] += velocity[0] * dt;
    position[1] += velocity[1] * dt;
    position[2] += velocity[2] * dt;
}


## Ref
- https://create.arduino.cc/projecthub/search?q=thrust+vector
- https://en.wikipedia.org/wiki/Thrust_vectoring
- https://bps.space/products/thrust-vector-control
- 

