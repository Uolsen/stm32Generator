#ifndef _SCREEN_H
#define _SCREEN_H

#include "main.h"
#include "state.h"

#include "screen.h"
#include "ssd1306_fonts.h"
#include "ssd1306.h"

typedef enum
{
	SCREEN_GENERATOR_TYPE = 0,
	SCREEN_GENERATOR_1 = 1,
	SCREEN_GENERATOR_2 = 2,
	SCREEN_GENERATOR_3 = 3,
	SCREEN_PHASE_SHIFT = 4,
} screen_pages_e;

uint8_t screen_page;

void screen_init();
void screen_update(state_s *state);

#endif