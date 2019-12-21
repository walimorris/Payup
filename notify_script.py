#! /usr/bin/env python3

import notify2
import sys
import os

def main():
    # First we'll read bill information and store it
    with open("benjis.txt", "r") as bill:
        line = bill.readline()
        bill_info = []
        while line != '':
            line = line.rstrip('\n')
            bill_info.append(line)
            line = bill.readline()
        bill.close()
    # Second, we'll create a formatted piece of text for the notification
    heart = '\n\t\t\t\t\t' + chr(9829) + ' Made with Python & C\n'
    notification = ''
    for i in range(len(bill_info)):
        notification += bill_info[i] + '\n'
    #create image
    image = "file://" + os.path.abspath(os.path.curdir) + "/paid.png"
    #send notification
    notify2.init('PayUp')
    n = notify2.Notification(heart, notification, image)
    n.show()
    if not n.show():
        print("Falied to send notification")
        sys.exit(1)
    
if __name__ == '__main__': 
    main() 
    
