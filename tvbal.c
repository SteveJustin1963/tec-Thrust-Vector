void ballistic(double *position, double *velocity, double *acceleration, double *thrust, double *mass, double *drag)
{
    double F_drag[3];
    double F_thrust[3];

    // Calculate drag force
    F_drag[0] = -0.5 * (*drag) * (*velocity) * (*velocity);
    F_drag[1] = -0.5 * (*drag) * (*velocity) * (*velocity);
    F_drag[2] = -0.5 * (*drag) * (*velocity) * (*velocity);

    // Calculate thrust force
    F_thrust[0] = *thrust * (*mass);
    F_thrust[1] = *thrust * (*mass);
    F_thrust[2] = *thrust * (*mass);

    // Calculate net force
    acceleration[0] = (F_thrust[0] + F_drag[0]) / (*mass);
    acceleration[1] = (F_thrust[1] + F_drag[1]) / (*mass);
    acceleration[2] = (F_thrust[2] + F_drag[2]) / (*mass);

    // Update velocity
    velocity[0] += acceleration[0] * dt;
    velocity[1] += acceleration[1] * dt;
    velocity[2] += acceleration[2] * dt;

    // Update position
    position[0] += velocity[0] * dt;
    position[1] += velocity[1] * dt;
    position[2] += velocity[2] * dt;
}
