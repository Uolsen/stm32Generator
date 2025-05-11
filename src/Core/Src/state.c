#include "state.h"

void state_init(state_s *state)
{
	state->generator_type = GENERATOR_STANDARD;
	state->correction = 978;

	state->standard_frequency_generator.is_on = 1;
	state->standard_frequency_generator.frequency = 1000000; // 1 MHz

	state->standard_frequency_generator_2.is_on = 0;
	state->standard_frequency_generator_2.frequency = 0;

	state->standard_frequency_generator_3.is_on = 0;
	state->standard_frequency_generator_3.frequency = 0;

	state->phase_shift_generator.is_on = state->generator_type == GENERATOR_PHASE_SHIFT ? 1 : 0; // 1 if phase shift generator is used 0 if standard frequency generator is used
	state->phase_shift_generator.frequency = 4000000; // 4 MHz
}
