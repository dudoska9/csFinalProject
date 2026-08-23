# csFinalProject
IMPORTANT: need to have graphics.h library installed first
I implemented this project by using C++ and the graphics.h library. I created a straightforward ticket
booking system in C++. In this system, I wanted to design an engaging and interactive program where
users can click to book any seat of a cinema and mark it as booked.
First, I added all of the libraries I would need, such as graphics.h to do the graphics and iostream to do
standard input/output. I then initialized the graphics window with initwindow, specifying a good size like
800x600 so everything would be proportionate to fit onto the screen.
Then I created a 2D array to hold the representation of the seats. I set every value to be a 0 by default,
so it wasn't booked yet. I then used a for loop to plot out what the seating arrangement looked like on
screen, effectively drawing rectangles in grid form. I included numbers as labels to identify every seat so
that the user would know what number corresponds to what.
Now, onto the good stuff – click detection. I employed a loop that waits for a mouse click, and when you
click anywhere on screen, I analyze the coordinates. I then calculate where you clicked relative to the
size of the seat and its position. If you clicked above an unbooked seat (i.e., there's still 0 where you
clicked), I book it by changing it to 1 and making that rectangle green instead of white.
If the seat was booked already (i.e., its value was 1), I simply disregarded it and didn’t modify anything.
This ensures that users can’t double book a seat. And lastly, I allowed the program to continue running
so that users can reserve any number of seats. I included an exit condition as well so that it will close
when you click anywhere outside of the seating area.
