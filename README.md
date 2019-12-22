# Payup: A small desktop notification program  
By: Wali Morris 

NOTE: This is my first, small, C programming project after a few weeks of self study.
I wanted to put the things I've learned to the test. I'm still getting the hang of C,
although I do enjoy using it as a programming lanaguage. It can be really tricky at times. 

ADDITIONS: This project is not completed. This is my first upload and as additions are completed 
this list will be updated along with dependencies (there will be a small few). 
* Complete loop structures and error handling
* A small script to automate running the program when PC is on
* The ability to process multiple bill procedures and notifications
* Creative art on the startup window using ncurses

"They" say, in the beginning, to make things that you can use daily. So, here it is, a 
program that'll perform daily bill notification pop ups directly on  my personal PC. 
I ran into the ncurses library and figured I'd give it a shot. One of my goals is to 
become very comfortable in a Linux environment, so some of my first programs have 
utilized command line protocols and libraries, like ncurses and TCP utilities, and notify2.

This program is mainly the setup for the pop-up notification, where I'll then use the notify-send 
command in a small script to automate the daily notifications. Notify send is a cool Linux command
I ran into after researching more online about C. This features allows you to communicate with your 
Linux system to send sweet pop-up notifications. This should already be installed on your Linux system. 
If not, you can use: 

* UBUNTU: sudo apt-get install notify-osd
* DEBIAN: apt-get install libnotify-bin
* NOTICE: I ran the second command on my machine running UBUNTU 18.04 and everything is still in tact. 

* On the command line: notify-send "Hello, World!"
* In a c-program, you'll need to use the \" escape character followed by \ escape and two double quotes
to close the command before sending it off to your system to send that sweet pop-up notification. 
* You can view an example found in the desktop_popup.c file.

You'll need to link ncurses when you compile or else gcc will throw a laundry list of errors. 
To compile a C program with ncurses, it should look like this (PayUp.c as example): 
* gcc PayUp.c -o PayUp -lncurses

To run: 
* ./PayUp

![PAYUP!](Notify.png)

 
 PayUp Notifications
 ![PayUP!](notification2.png)
 
Notify2 is a tool brought to the community by the developers of the Galago framework. The lead developer 
is Christain Hammond, but this team has brought a really cool framework to the community. Galago, and notify2, 
is described as a desktop presence framework, designed to transmit presence information between programs. 
Saying that, this is exactly what I've done building the information processing with C and ncurses then using a 
small Python3 script to use notify2 for the desktop notifications. There are many features to use with notify2
and I've barely touched the service with PayUp. So Thank you to Christain and their team! 

Installing notify2 from the command line and viewing examples: 
* Sudo apt install python3-notify 2
* Once installed you can view examples here: /usr/share/doc/python3-notify2/examples/

![PayUP!](notification1.png)


