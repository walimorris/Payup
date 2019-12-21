#! /usr/bin/env python3

import notify2
import sys
import os
from apscheduler.schedulers.background import BackgroundScheduler
"""
First we'll read the bill information and store it. Second, we'll create a
formatted piece of text for the notification. We'll send the notification
to the desktop using notify2, and lastly automate sending notifications with
the apscheduler.
"""
def main():
    sched = BackgroundScheduler(daemon=True)
    sched.add_job(notify,'interval', seconds=5)
    sched.start()
    

def notify():
    with open('benjis.txt', 'r') as bill:
        line = bill.readline()
        bill_info = []        
        while line != '':
            line = line.rstrip('\n')
            bill_info.append(line)
            line = bill.readline()
        bill.close()
        notification = ''
        for i in range(len(bill_info)):
            notification += bill_info[i] + '\n'
        heart = '\n\t\t\t\t\t' + chr(9829) + ' Made with Python & C\n'
        image = "file://" + os.path.abspath(os.path.curdir) + "/paid.png"
        notify2.init('PayUp')
        n = notify2.Notification(heart, notification, image)
        n.show()
        if not n.show():
            print("Falied to send notification")
            sys.exit(1)

if __name__ == '__main__':
    main()
    
    
    
