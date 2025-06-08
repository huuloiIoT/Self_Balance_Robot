#ifndef __OP_HEADER_DEFINE__
#define __OP_HEADER_DEFINE__

typedef struct {
    float Kp;
    float Ki;
    float Kd;

    float setpoint;
    float integral;
    float previous_error;
} PID;

#endif
