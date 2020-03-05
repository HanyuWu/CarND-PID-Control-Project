#include "PID.h"

/**
 * TODO: Complete the PID class. You may add any additional desired functions.
 */

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp_, double Ki_, double Kd_) {
  /**
   * TODO: Initialize PID coefficients (and errors, if needed)
   */
  this->Kd = Kd_;
  this->Ki = Ki_;
  this->Kp = Kp_;
  this->i_error = 0;
  this->pre_cte = 0;
}

void PID::UpdateError(double cte) {
  /**
   * TODO: Update PID errors based on cte.
   */
  this->p_error = cte;
  this->d_error = (cte - pre_cte);
  this->i_error += cte;
  this->pre_cte = cte;
}

double PID::TotalError() {
  return -Kp * p_error - Kd * d_error -
         Ki * i_error; // TODO: Add your total error calc here!
}