#pragma once
#include "vex.h"

class Stanley
{
public:
  float error = 0;
  float lookahead = 0;
  float angle_turn_back_velo = 0;
  bool reversed = false;
  float settle_error = 0;
  float settle_time = 0;
  float timeout = 0;
  float accumulated_error = 0;
  float previous_error = 0;
  float output = 0;
  float time_spent_settled = 0;
  float time_spent_running = 0;

  Stanley(float error, float kp, float ki, float kd, float starti, float settle_error, float settle_time, float timeout);

  Stanley(float error, float kp, float ki, float kd, float starti);

  float compute(float error);

  bool is_settled();
};