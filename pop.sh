#!/bin/bash

# Currently PayUp supports UBUNTU 18.04 and Python3. There will be updates periodically. Also, at some point 
# this script will be executed through crontab for better automation. This script takes care of setting up 
# program dependencies for the first time and is meant to be run directly. Currently, this script should be
# run from the command line everytime this program should be carried out. Please see the README docs for  
# more information on setting up.
# Email: walimmorris@gmail.com
# Initial Setup: Dec 21, 2019 

w="60m"   #1 hour 
x="120m"  #2 hours
y="180m"  #3 hours 
z="240m"  #4 hours 
	
setup () { 
    echo setting up dependencies...
    sudo apt-get install libncurses5-dev libncursesw5-dev
    sudo apt-get install notify-osd
    sudo apt install python3-notify2
    gcc Payup.c -o Payup -lncurses
    chmod +x notify_script.py
    echo dependencies installed..
}
notify () {
    nohup python3 notify_script.py
}
rest () {
    while true; do
    notify
    sleep $1
done
}
echo First time running PayUp on this machine [Y/N]?
read startup
while [ $startup != 'Y' ] && [ $startup != 'N' ]; do
    echo First time running PayUp on this machine [Y/N]?
    read startup
done
if [ $startup == 'Y' ]; then 
    setup
fi
echo BEWARE: Notifications will run until system shutdown!
hour=5
while [ $hour -lt 0 ] || [ $hour -gt 4 ]; do
    echo In hours[1 thru 4]: How often should you be notified? [ex:2]
    read hour	    
done
./PayUp
if [ $hour == 1 ]; then
    rest $w 
elif [ $hour == 2 ]; then
    rest $x
elif [ $hour == 3 ]; then 
    rest $y
else
    rest $z
fi 
