#ifndef _STATE_H
#define _STATE_H

#include "main.h"

typedef enum
{
	GENERATOR_STANDARD = 0,
	GENERATOR_PHASE_SHIFT = 1,
} generator_e;

typedef struct
{
	uint8_t is_on;
	uint32_t frequency; // 1 MHz
} standard_frequency_generator_s;

typedef struct
{
	uint8_t is_on;
	uint32_t frequency; // 4 MHz
} phase_shift_generator_s;

typedef struct
{
	generator_e generator_type;
	int32_t correction;

	standard_frequency_generator_s standard_frequency_generator;
	standard_frequency_generator_s standard_frequency_generator_2;
	standard_frequency_generator_s standard_frequency_generator_3;
	phase_shift_generator_s phase_shift_generator;
} state_s;

void state_init(state_s *state);

#endif