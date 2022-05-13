
void thrust_vector(double *thrust, double *pitch, double *yaw)
{
    double sin_pitch = sin(*pitch);
    double cos_pitch = cos(*pitch);
    double sin_yaw = sin(*yaw);
    double cos_yaw = cos(*yaw);

    thrust[0] = cos_pitch * cos_yaw;
    thrust[1] = cos_pitch * sin_yaw;
    thrust[2] = sin_pitch;
}
