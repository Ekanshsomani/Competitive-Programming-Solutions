y = int(input())

months = (y-2017)*12
if (months - 4)%26 < 12:
    print("yes\n")
else:
    print("no\n")