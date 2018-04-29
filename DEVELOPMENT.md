## April 18-20
* Generated ElectricSounds openframeworks project in Visual Studio
* Takes volume input and writes current volume to the window
* Draws a rectangle with dynamic width based on current volume
* In a seperate application, I made a dynamic circle which changed radius using arrow keys
	* Will use this method to have radius be volume controlled
	* Volume needs to be smoothed first, as cur_vol_ changes too fast
* Unable to read pitch using Gist library so far
	* Will research different libraries, or implement [Yin method](http://audition.ens.fr/adc/pdf/2002_JASA_YIN.pdf) myself in a seperate class
## April 22
* Smoothed volume is calculated in audioIn
* Integrated moving circles to the project using a circle_shape struct
	* Has its own update and draw functions
	* Similar structures can be used for different shapes
* Added states RUNNING and PAUSED to the program
	* Press 'P' to Pause, 'U' to Unpause
* "new file: .vs/ElectricSounds/v14/.suo" accidental commit message
	* Getting the hang of committing through command line, though
## April 24
* Integrated moving and rotating polygons using polygon_shape struct
* Next steps include 
	* Adding vecotrs of these shapes for more functionality
	* Possibly adding more shapes or background graphics
	* Pitch implementation still not working correctly
## April 25
* Successfully uses vectors of circle_shape and polygon_shape structs to hold graphic objects
* 'P' now pauses and unpauses based on the current state
	* Before, it was possible to start(stop) an already started(stopped) soundstream
* Next steps include
	* Detecting pitch from audio input using some library
	* Making shapes move across the screen at a rate proportional to pitch
	* Adding user controlled features like number of circles
## April 28 
* There is a pitch detection method using ofSoundGetSpectrum() in ofSoundPlayer
* May need to change to model of the app to read audio from a file rather than live stream
* Able to play audio using ofSoundPlayer, but it does not show in audioOut(...) which causes some problems
	* Without being able to read in audioOut, I need to find a way to measure volume