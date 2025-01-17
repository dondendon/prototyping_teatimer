# Tea Timer with Pressure Sensor, 4-Digit 7-Segment Display, and toggle switches

## Introduction
This is the project for the **Prototyping for Interaction Design** class, with the intend to integrate physical and digital prototyping. We will be creating a prototype for a proof of concept with Arduino.

## My Concept

I create design a timer for tea making, with a switch to set up the time, pressure sensor to trigger the timer, and a 4-digit LCD screen signifier to show the output.

<img src="https://github.com/dondendon/prototyping_teatimer/blob/master/img/sketch.png" width="500" />

## Why Tea Timer?

The time of tea bag in the hot water will affect the quality of tea. However, there's no convenience timer for the current tea making process. One has to use a phone or alarm to set up every time. And the Hourglass provides limited flexibility. Therefore, I designed this timer that seamlessly integrates into the tea making process. The user only needs to put the cup on the timer, and they'll be notified after the countdown. Moreover, the user doesn't have to set up the switch every time, the Arduino board will automatically read the current setting to start.

## What do you need?

1. ARDUINO UNO
2. 4-Digit 7-Segment Display(Output)
3. A Pressure Sensor(Input)
4. LED light bulb (Output)
5. Jumper wires (generic)
6. Toggle Switches

## How does this work?

Once the pressure sensor is triggered, the LED light bulb lights up, and the Digital display starts to count down.<br>
The countdown will only continue when there's pressure(the cup is on the timer). <br>
If the pressure is released before the count down time reaches zero, the timer restarts, and the LED light and digital display turn off.<br>
Else if the count down reaches zero, the LED light and the digital display turn off.<br>

Here are some demo gif:
1. Trigger the timer by holding the pressure sensor, start the count down.
<img src="https://github.com/dondendon/prototyping_teatimer/blob/master/img/count_1.gif" width="500" />


2. Trigger the timer, and release before the countdown ends. It'll restart the timer.
<img src="https://github.com/dondendon/prototyping_teatimer/blob/master/img/count_2.gif" width="500" />

3. Change the setting of the switch, the countdown timer change(from 16 to 19).
<img src="https://github.com/dondendon/prototyping_teatimer/blob/master/img/count_3.gif" width="500" />


## The Board

This is how I connect the accessories with Arduino board.


<img src="https://github.com/dondendon/prototyping_teatimer/blob/master/img/arduino_board.png" width="500" />

And it looks like this:
<img src="https://github.com/dondendon/prototyping_teatimer/blob/master/img/board.jpg" width="500" />



## The Code

The code consists of three parts, the main functions, the show digit functions, and the count down digit functions.<br>
The show digit function contains the logic of LED in different numbers, it will read the input of numbers and output the numbers on the LED screen.<br>
The count down digit functions will call the show digit function for numbers to show up, and handle different digits position showing logic in milliseconds.<br>
The main functions will check the switch setting every 20 milliseconds.And if the pressure sensor is pressed, it'll trigger the count down digit functions and start the count down process. After countdown or the pressure is released, it will reset the Arduino board to restart the timer.<br>

## The References
1. 4-Digit 7-Segment Display
https://create.arduino.cc/projecthub/SAnwandter1/programming-4-digit-7-segment-led-display-2d33f8
2. The countdown timer function
http://www.hobbytronics.co.uk/arduino-countdown-timer
