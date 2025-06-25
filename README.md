# ESP32 with a LAN8720 or JL1101
Connect a LAN8720 ethernet board to a ESP32

I’ve been trying to connect a LAN8720 ethernet board on a ESP32 Dev module and everywhere I look, I just can’t seem to get all the info to get it to work first shot!

There’s the physical plugging of them together, using the onboard 50 MHz oscilator or using the ESP32 to generate the 50 MHz clock, using the GPIO 0 or another, and I’ve tried almost all of them including using a transistor to isolate the clock out of the LAN8720 board connecting to GPIO0 of the ESP32 and using another GPIO with a delay to activate the transistor so that the ESP32 will boot up normally at every boot or reboot.

Here’s what I found to be the simplest solution that I managed to make work and it works every time I boot or reboot the ESP32.

Take a look at the PDF file for more info.
I also have the info for the settings to also make the JL1101 ethernet that's on the DTWONDER boards work.
I hope this will help someone else!
