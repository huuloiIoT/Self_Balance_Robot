#include "OPERATION_Layer/OP_Header_Main.h"

void PID_Init(PID *pid, float Kp, float Ki, float Kd, float setpoint) {
    pid->Kp = Kp;
    pid->Ki = Ki;
    pid->Kd = Kd;
    pid->setpoint = setpoint;
    pid->integral = 0.0f;
    pid->previous_error = 0.0f;
}

float PID_Update(PID *pid, float measured_value, float dt) {
    float error = pid->setpoint - measured_value;
    pid->integral += error * dt;
    float derivative = (error - pid->previous_error) / dt;

    float output = (pid->Kp * error) +
                   (pid->Ki * pid->integral) +
                   (pid->Kd * derivative);

    pid->previous_error = error;
    return output;
}
