#include "screen.h"
#include <stdio.h>

uint8_t screen_page;


void screen_init()
{
	ssd1306_Init();
	ssd1306_Fill(Black);
	ssd1306_UpdateScreen();
	ssd1306_SetCursor(0, 0);
	ssd1306_UpdateScreen();

	screen_page = SCREEN_GENERATOR_TYPE;
}

void screen_update(state_s *state)
{
	switch (screen_page)
	{
	case SCREEN_GENERATOR_TYPE:
		ssd1306_Fill(Black);
		ssd1306_SetCursor(0, 0);
		ssd1306_WriteString("GENERATOR TYPE", Font_7x10, White);
		ssd1306_SetCursor(4, 32);
		if (state->generator_type == GENERATOR_STANDARD)
		{
			ssd1306_WriteString(" STANDARD  ", Font_11x18, Black);
		}
		else
		{
			ssd1306_WriteString("PHASE SHIFT", Font_11x18, Black);
		}
		
		ssd1306_UpdateScreen();
		break;
	case SCREEN_GENERATOR_1:
		gen_screen(1, &state->standard_frequency_generator);
		break;
	
	default:
		break;
	}
}

void gen_screen(uint8_t generator_number, standard_frequency_generator_s *generator)
{
	char buf[32];
	ssd1306_Fill(Black);
	ssd1306_SetCursor(0, 0);
	snprintf(buf, sizeof(buf), "GENERATOR %d", generator_number);
	ssd1306_WriteString(buf, Font_7x10, White);


	ssd1306_UpdateScreen();
}

