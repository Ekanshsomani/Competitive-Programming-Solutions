from datetime import datetime

s = input()
a, b, c = map(int, s.split('/'))

minDate = datetime(2999, 12, 31)
invalids = 0

try:
    date = datetime((a if a>99 else a+2000), b, c)
    minDate = min(minDate, date)
except ValueError:
    invalids += 1

try:
    date = datetime((b if b> 99 else b+2000), a, c)
    minDate = min(minDate, date)
except ValueError:
    invalids += 1


try:
    date = datetime((b if b> 99 else b+2000), c, a)
    minDate = min(minDate, date)
except ValueError:
    invalids += 1


try:
    date = datetime((a if a>99 else a+2000), c, b)
    minDate = min(minDate, date)
except ValueError:
    invalids += 1


try:
    date = datetime((c if c>99 else c+2000), a, b)
    minDate = min(minDate, date)
except ValueError:
    invalids += 1

try:
    date = datetime((c if c>99 else c+2000), b, a)
    minDate = min(minDate, date)
except ValueError:
    invalids += 1

if invalids==6:
    print(f"{s} is illegal")
else:
    print(minDate.strftime("%Y-%m-%d"))