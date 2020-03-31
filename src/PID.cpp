#include "PID.h"


/**
 * TODO: Complete the PID class. You may add any additional desired functions.
 */

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp_, double Ki_, double Kd_) {
    /**
     * Initialize PID coefficients (and errors, if needed)
     */
    this->Kp = Kp_;
    this->Ki = Ki_;
    this->Kd = Kd_;
    p_error = 0.0;
    i_error = 0.0;
    d_error = 0.0;
    int_cte = 0.0;
    prev_cte = 1.0;
    diff_cte = 0.0;
}

double PID::UpdateError(double cte) {
    d_error = cte - p_error;
    p_error = cte;
    i_error += cte;
}

double PID::TotalError() {
    return -Kp * p_error - Kd * d_error - Ki * i_error;
}

double PID::Steer() {
}