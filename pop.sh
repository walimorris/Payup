#!/bin/bash

# Currently PayUp supports UBUNTU 18.04 and Python3. There will be updates periodically. Also, at some point 
# this script will be executed through crontab for better automation. This script takes care of setting up 
# program dependencies for the first time and is meant to be run directly. Currently, this script should be
# run from the command line everytime this program should be carried out. Please see the README docs for  
# more information on setting up.
# Email: walimmorris@gmail.com
# Initial Setup: Dec 21, 2019 

W="60m"   #1 hour 
X="120m"  #2 hours
Y="180m"  #3 hours 
Z="240m"  #4 hours 
	
setup () { 
    printf "setting up dependencies..."
    sudo apt-get install libncurses5-dev libncursesw5-dev
    sudo apt-get install notify-osd
    sudo apt install python3-notify2
    gcc Payup.c -o Payup -lncurses
    chmod +x notify_script.py
    printf "dependencies installed..."
}
notify () { nohup python3 notify_script.py; }
rest () {
    while true; do
    notify
    sleep $1
done
}
printf "First time running PayUp on this machine [Y/N]"
read -r startup
while [ $startup != 'Y' ] && [ $startup != 'N' ]; do
    printf "First time running PayUp on this machine [Y/N]"
    read -r startup
done
if [ $startup == 'Y' ]; then 
    setup
fi
hour=5
while [ $hour -lt 0 ] || [ $hour -gt 4 ]; do
    printf "In hours(1-4): How often should you be notified?"
    read -r hour	    
done
./Payup
if [ $hour == 1 ]; then
    rest $w 
elif [ $hour == 2 ]; then
    rest $x
elif [ $hour == 3 ]; then 
    rest $y
else
    rest $z
fi 
