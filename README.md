# Electric Sounds
Electric Sounds is an audio/music visualizer that works in C++ using `openFrameworks`. A song is played from a `.wav` file then visual aspects change based on the intensity and spectrum of sound being played.
## Requirements
This project is a Visual Studio solution written with [Visual Studio 2015](https://www.visualstudio.com/vs/older-downloads/). It uses different openFrameworks libraries to create the GUI, process audio from a file, and generate graphics, so it is necessary to [download](http://openframeworks.cc/download/), then [setup](http://openframeworks.cc/setup/vs/) properly. Also, `ofSoundPlayer` requires files to be either `.wav` or `.mp3` type. I used [this](https://audio.online-convert.com/convert-to-wav) file converter to convert from `.m4a` to `.wav`.
## Implementation
Sound files are stored in and accessed with reference to `bin/data/`. Different songs or audio files can be loaded to the `ofSoundPlayer` object `mySound` with the following commands:
```c++
mySound.load("filename.wav");
mySound.setVolume(1.0);
mySound.play();
```
These commands can be found in `ofApp.cpp` in the function `setup()`. It is important to not that volume can be set to a float between 0.0 and 1.0 representing volume as a percentage.
## Functionality
The GUI is generated in `main.cpp` then in `ofApp.cpp` the function `setup()` is run once, and the functions `update(), draw()` are run every frame. Also used is [data smoothing](https://en.wikipedia.org/wiki/Smoothing) for volume and spectral intensity of the sound.