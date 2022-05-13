


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
