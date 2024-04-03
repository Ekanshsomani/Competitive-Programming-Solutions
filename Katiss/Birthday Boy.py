from datetime import datetime, timedelta


daysList = []
firstDate = datetime(2023, 1, 1)
n = int(input())

for i in range(n):
    month, day = map(int, input().split()[1].split('-'))
    newDate = datetime(2023, month, day)
    daysList.append((newDate - firstDate).days)
daysList.sort()

nearDate = datetime(2022, 10, 28)

maxDiff = 0
birthDate = datetime(2022, 10, 28)
closeness = (birthDate-nearDate).days%365


for i in range(n-1):
    if (daysList[i+1]-daysList[i])>maxDiff:
        maxDiff = daysList[i+1]-daysList[i]
        birthDate = firstDate + timedelta(days=daysList[i+1]-1)
        closeness = (birthDate-nearDate).days%365
    elif (daysList[i+1]-daysList[i]) == maxDiff and (((firstDate + timedelta(days=daysList[i+1]-1)) - nearDate).days%365) < closeness:
        birthDate = firstDate + timedelta(days=daysList[i+1]-1)
        closeness = (birthDate-nearDate).days%365

if (daysList[0]+365-daysList[n-1])>maxDiff:
    birthDate = firstDate + timedelta(days=daysList[0]-1)
elif (daysList[0]+365-daysList[n-1])==maxDiff and (((firstDate + timedelta(days=daysList[0]-1)) - nearDate).days) < closeness:
    birthDate = firstDate + timedelta(days=daysList[0]-1)

print(birthDate.strftime("%m-%d"))