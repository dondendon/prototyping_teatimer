# Tea Timer with Pressure Sensor, 4-Digit 7-Segment Display, and toggle switches

## Introduction
This is the project for the **Prototyping for Interaction Design** class, with the intend to integrate physical and digital prototyping. We will be creating a prototype for a proof of concept with Arduino.

## My Concept

I create design a timer for tea making, with a switch to set up the time, pressure sensor to trigger the timer, and a 4-digit LCD screen signifier to show the output.

![alt text](https://github.com/dondendon/prototyping_teatimer/blob/master/Untitled_Artwork-1%202.png)

## Why Tea Timer?

The time of tea bag in the hot water will affect the quality of tea. However, there's no convenience timer for the current tea making process. One has to use a phone or alarm to set up every time. And the Hourglass provides limited flexibility. Therefore, I designed this timer that seamlessly integrates into the tea making process. The user only needs to put the cup on the timer, and they'll be notified after the countdown. Moreover, the user doesn't have to set up the switch every time, the Arduino board will automatically read the current setting to start.

## What do you need?

1. ARDUINO UNO
2. 4-Digit 7-Segment Display
3. A Pressure Sensor
4. Jumper wires (generic)
5. Toggle Switches

## How does this work?

1. Trigger the timer by holding the pressure sensor, start the count down.
![alt text](https://github.com/dondendon/prototyping_teatimer/blob/master/ezgif.com-video-to-gif.gif)


2. Trigger the timer, and release before the countdown ends. It'll restart the timer.

3. Change the setting of the switch, the countdown timer change(from 16 to 19).

## The Board

This is how I connect the accessories with Arduino board.

![alt text](https://github.com/dondendon/prototyping_teatimer/blob/master/timer_bb.png
)

<img src="https://github.com/dondendon/prototyping_teatimer/blob/master/timer_bb.png" width="40" height="40" />


## The Code

The code consists of three parts, the main functions, the show digit functions, and the count down digit functions.
The show digit function contains the logic of LED in different numbers, it will read the input of numbers and output the numbers on the LED screen.
The count down digit functions will call the show digit function for numbers to show up, and handle different digits position showing logic in milliseconds.
The main functions will check the switch setting every 20 milliseconds.And if the pressure sensor is pressed, it'll trigger the count down digit functions and start the count down process. After countdown or the pressure is released, it will reset the Arduino board to restart the timer.

## The References
1. 4-Digit 7-Segment Display
https://create.arduino.cc/projecthub/SAnwandter1/programming-4-digit-7-segment-led-display-2d33f8
2. The countdown timer function
http://www.hobbytronics.co.uk/arduino-countdown-timer
