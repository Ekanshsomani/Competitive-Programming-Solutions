from datetime import datetime, time, timedelta

hour, minute, second = map(int, input().split(':'))
currentTime = time(hour, minute, second)
hour, minute, second = map(int, input().split(':'))
explosionTime = time(hour, minute,  second)


if explosionTime<=currentTime:
    explosion = datetime.combine(datetime.today(), explosionTime) + timedelta(hours=24)
else:
    explosion = datetime.combine(datetime.today(), explosionTime)

current = datetime.combine(datetime.today(), currentTime)

timer  = (explosion - current).seconds

hour = timer//3600
minute = (timer//60)%60
second = timer%60

if timer!=0:
    print(f"{hour:02d}:{minute:02d}:{second:02d}")
else:
    print("24:00:00")