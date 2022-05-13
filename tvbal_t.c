


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

; \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

convert the above to fortran IV

subroutine trajectory_control(position, velocity, acceleration, thrust, mass, drag, desired_position, desired_velocity, desired_acceleration)
    double precision, dimension(3) :: position, velocity, acceleration, thrust, mass, drag, desired_position, desired_velocity, desired_acceleration
    double precision, dimension(3) :: F_drag, F_thrust, F_desired
 
    F_drag(1) = -0.5 * drag * velocity(1) * velocity(1)
    F_drag(2) = -0.5 * drag * velocity(2) * velocity(2)
    F_drag(3) = -0.5 * drag * velocity(3) * velocity(3)
 
    F_thrust(1) = thrust * mass
    F_thrust(2) = thrust * mass
    F_thrust(3) = thrust * mass
 
    F_desired(1) = (desired_position(1) - position(1)) * kp + (desired_velocity(1) - velocity(1)) * kv + (desired_acceleration(1) - acceleration(1)) * ka
    F_desired(2) = (desired_position(2) - position(2)) * kp + (desired_velocity(2) - velocity(2)) * kv + (desired_acceleration(2) - acceleration(2)) * ka
    F_desired(3) = (desired_position(3) - position(3)) * kp + (desired_velocity(3) - velocity(3)) * kv + (desired_acceleration(3) - acceleration(3)) * ka
 
    acceleration(1) = (F_thrust(1) + F_drag(1) + F_desired(1)) / mass
    acceleration(2) = (F_thrust(2) + F_drag(2) + F_desired(2)) / mass
    acceleration(3) = (F_thrust(3) + F_drag(3) + F_desired(3)) / mass
 
    velocity(1) = velocity(1) + acceleration(1) * dt
    velocity(2) = velocity(2) + acceleration(2) * dt
    velocity(3) = velocity(3) + acceleration(3) * dt
 
    position(1) = position(1) + velocity(1) * dt
    position(2) = position(2) + velocity(2) * dt
    position(3) = position(3) + velocity(3) * dt
 
end subroutine trajectory_control


; \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
convert the above to forth 83 code

: trajectory-control ( position velocity acceleration thrust mass drag desired-position desired-velocity desired-acceleration -- )
    
    F-drag 1 - 0.5 * drag * velocity * velocity d>r
    F-thrust 1 - thrust * mass d>r
    F-desired 1 - (desired-position - position) * kp + (desired-velocity - velocity) * kv + (desired-acceleration - acceleration) * ka d>r
    acceleration 1 - (F-thrust + F-drag + F-desired) / mass d>r
    velocity 1 - velocity + acceleration * dt d>r
    position 1 - position + velocity * dt d>r
    ;
    
; \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

