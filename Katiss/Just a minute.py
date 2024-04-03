totalMinute = 0
totalSecond = 0
for i in range(int(input())):
    minutes, seconds = map(float, input().split())
    totalMinute += minutes
    totalSecond += seconds

minuteLength = totalSecond/(totalMinute * 60.0)
if minuteLength <= 1:
    print("measurement error\n")
else:
    print(minuteLength)