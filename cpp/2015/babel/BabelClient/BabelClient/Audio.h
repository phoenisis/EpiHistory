#ifndef	_AUDIO_H_
#define	_AUDIO_H_

#include "portaudio.h"
#include <cstdlib>
#include <iostream>

// Sound values

#define	INPUT_CHAN	1
#define	OUTPUT_CHAN	1
#define	SAMPLE_RATE	16000

class	Audio	{
private:
	PaStream	*stream;
public:
	Audio();
	~Audio();
	void	playSound(void *, int);
	void	recordSound(void *, int);
};

#endif