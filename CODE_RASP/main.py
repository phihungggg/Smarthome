"""


"""
from gpiozero import LED
import serial
import cv2
import time
import os
import hand as htm 
from time import sleep


cap=cv2.VideoCapture(0)
flag = LED(18)
a = LED(23)
b = LED(24)
flag.off()
a.off()
b.off()


pTime=0

detector =htm.handDetector(detectionCon=1)

fingerid= [4,8,12,16,20]
while True:
    fps_limit=60
    current_time = time.time()
    if(current_time-pTime)>=1/fps_limit:
        pTime = current_time
        ret, frame = cap.read()
        
        
    frame = detector.findHands(frame)
    lmList = detector.findPosition(frame, draw=False) # phát hiện vị trí
    if len(lmList) !=0:
        fingers= []
       
        if lmList[fingerid[0]][1] < lmList[fingerid[0] - 1][1]:
            fingers.append(1)
            
        else:
            fingers.append(0)
       
        for id in range(1,5):
            if lmList[fingerid[id]][2] < lmList[fingerid[id]-2][2]:
                fingers.append(1)
                
            else:
                fingers.append(0)


        
        songontay=fingers.count(1)
        print(songontay)
        flag.on()
        if(songontay==0):
            print("Tat Het")
            a.off()
            b.off()
        elif(songontay==1):
            print("Mo Den")
            a.on()
        elif(songontay==2):
            print("Tat Den")
            a.off()
        elif(songontay==3):
            print("Mo Quat")
            b.on()
        elif(songontay==4):
            print("Tat Quat")
            b.off()
        else:
            print("Mo Ca 2")
            a.on()
            b.on()
    else:
        flag.off()
    

    cv2.imshow("Hand Tracking",frame)
    if cv2.waitKey(1)== ord("q"): # độ trễ 1/1000s , nếu bấm q sẽ thoát
        break
cap.release() # giải phóng camera
cv2.destroyAllWindows() # thoát tất cả các cửa sổ