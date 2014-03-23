#pragma once

// Since we are on a controller based game,
// inputs are simplified to click only
enum GUIEVENT {
	CLICK,
	PRESSED,
	RELEASED,
	DRAW,
	UPDATE
};