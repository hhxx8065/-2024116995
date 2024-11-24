//
// 2025 Helios CV enter examination
//
/*
 * ██   ██ ███████ ██      ██  ██████  ███████
 * ██   ██ ██      ██      ██ ██    ██ ██
 * ███████ █████   ██      ██ ██    ██ ███████
 * ██   ██ ██      ██      ██ ██    ██      ██
 * ██   ██ ███████ ███████ ██  ██████  ███████
 */

#include <iostream>
#include <chrono>
#include <cmath>
#include "./chassis.h"

#include "kalman/kalman.h"
#include "kalman/AdaptiveEKF.h"

int main()
{
    const int mode = 2;
    SET_MODE(mode);
    ENABLE_LOG(true);

    while (true)
    {
        float sensor_data;
        float filtered_data;
        float current_position;

        // receive sensor data -> how far to the target (10ms delay)
        GET_SENSOR_DISTANCE(sensor_data);

        // receive current position (current_position + sensor_data ~= target position)
        GET_CURRENT_POSITION(current_position);

        // =============================================
        // TODO: your code here
        // you should try to follow the target position

        switch (mode)
        {
        case 0:
        case 1:
        case 2:
            {
                // you should replace the following line
                filtered_data = sensor_data;    // set filtered data as raw sensor data (without filter)
                                                // this may cause problem
            }
            break;
        };

        // =============================================
        SET_TARGET_POSITION(current_position + filtered_data);      // go to the position which you consider as the target position
        SHOW_DEBUG_IMAGE();         // show image debug info
    }

    return 0;
}
