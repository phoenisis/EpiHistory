#include "Audio.h"

Audio::Audio() {
//	Pa_Initialize();
//	Pa_OpenDefaultStream(&stream, INPUT_CHAN, OUTPUT_CHAN, paFloat32, SAMPLE_RATE, NULL, NULL, NULL);
//	Pa_StartStream(stream);
}

Audio::~Audio() {
//	Pa_StopStream(stream);
//	Pa_Terminate();
}

void	Audio::playSound(void *sound, int size) {
//	Pa_WriteStream(stream, sound, size);
}

void	Audio::recordSound(void *sound, int size) {
//	Pa_ReadStream(stream, sound, size);
}
