# Digital Timer
 
Include your responses to the bold questions below. Include snippets of code that explain what you did. Deliverables are due next Tuesday. Post your lab reports as README.md pages on your GitHub, and post a link to that on your main class hub page.

## Pre Lab:
1. 
2.
3.
4.
5.
6.
7.
8.
9.
10.


## Part A. Solder your LCD panel

**Take a picture of your soldered panel and add it here!**
[Image](https://github.com/rec285/IDD-Fa19-Lab2/blob/master/1NqPrA8NRB%2BUAeNj0cX6mg.jpg)

## Part B. Writing to the LCD
 
**a. What voltage level do you need to power your display?**
To see the text, the potentiometer needs to be all the way to one end, which would send 5V to the display.

**b. What voltage level do you need to power the display backlight?**
The backlight was powered at all points on the potentiometer and uses the 3.3V.
   
**c. What was one mistake you made when wiring up the display? How did you fix it?**
I didn't have the 3.3V connected and was missing some ground connections. I used the circuit diagram to compare every connection on the display and arduino to my board.

**d. What line of code do you need to change to make it flash your name instead of "Hello World"?**
line 54: lcd.print("hello, world!"); -> line 54: lcd.print("Ryan");
 
**e. Include a copy of your Lowly Multimeter code in your lab write-up.**
[Link to code](https://github.com/rec285/IDD-Fa19-Lab2/blob/master/RyanLowlyMultimeter.ino)

## Part C. Using a time-based digital sensor

**Upload a video of your working rotary encoder here.**
[Link to video](https://youtu.be/L5fGZjaKass)

## Part D. Make your Arduino sing!

**a. How would you change the code to make the song play twice as fast?**
 Divide all of the note durations in half.
 
**b. What song is playing?**
The star wars theme song

## Part E. Make your own timer

**a. Make a short video showing how your timer works, and what happens when time is up!**
The timer is set using the rotary encoder and then starts the countdown by pressing the button. When the time is up, the speaker beeps.

[Link to Video](https://youtu.be/oX18yvg6WoE)
[Link to Code](https://github.com/rec285/IDD-Fa19-Lab2/blob/master/sketch_sep14a.ino)

**b. Post a link to the completed lab report your class hub GitHub repo.**
