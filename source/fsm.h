 /**
 *@file
 *@brief Finite state machine that controls the elevator
 */
#pragma once

#include <stdio.h>
#include <time.h>
#include "io.h"
#include "channels.h"
#include "elev.h"


typedef enum states{
  IDLE,
  MOVING,
  DOOR_OPEN
} state;

typedef struct fsm_data{
  state active_state;
  int curr_dir;
  int prev_floor;
  int orders[N_FLOORS][N_BUTTONS];
} fsm_data;


/**
 * Initialize the state machine to a defined state
 */
fsm_data fsm_init();

/**
 * Event
 * Begin to complete any potential orders
 */
void fsm_evt_order(int floor, elev_button_type_t dir, fsm_data * data);

/**
 * Event
 * Reached a floor
 */
void fsm_evt_floor_sensor(int floor, fsm_data * data);

/**
 * Event
 * Stop button is pressed
 */
void fsm_evt_stop_button_pressed(fsm_data * data);


void door_timer(fsm_data * data);
