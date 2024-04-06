#pragma once
#include "vex.h"

double LKp;
double LKi;
double LKd;
double AKp;
double AKi;
double AKd;
int osc_count;
bool oscval;
double linaddval;
double angaddval;
double Terr;

void conditions();
int recursion(int x,double start, double end);
void osc(int tar, int PD);
void osc_finder_lin(int PID);
void osc_finder_ang(int PID);
void tunelinear(int PID);
void tuneangular(int PID);