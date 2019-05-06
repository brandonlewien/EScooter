/*
 * accel.h
 *
 *  Created on: Oct 21, 2017
 *      Author: Brandon, Charles, Sam
 */
#include <stdint.h>

#ifndef ACCEL_H_
#define ACCEL_H_

/*
 * Function: accel_init
 * ----------------------------
 *   Initializes the accelerometer
 *
 *   xchan: ADC MCTL channel to map x value to
 *   ychan: ADC MCTL channel to map y value to
 *   zchan: ADC MCTL channel to map z value to
 *
 *   returns: void
 */
void accel_init(uint8_t xchan, uint8_t ychan, uint8_t zchan);

/*
 * Function: accel_x
 * ----------------------------
 *   Calculates the acceleration in the x direction
 *
 *   returns: x value (in m/s^2)
 */
double accel_x();

/*
 * Function: accel_y
 * ----------------------------
 *   Calculates the accleration in the y direction
 *
 *   returns: y value (in m/s^2)
 */
double accel_y();

/*
 * Function: accel_z
 * ----------------------------
 *   Calculates the acceleration in the z direction
 *
 *   returns: z value (in m/s^2)
 */
double accel_z();

double accel_velocity();


#endif /* ACCEL_H_ */
