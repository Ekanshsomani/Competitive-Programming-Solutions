addHour = {
    "UTC" : 0, "GMT" : 0, "BST" : 1, "IST" : 1, "WET" : 0, "WEST" : 1, "CET" : 1,
    "CEST" : 2, "EET" : 2, "EEST" : 3, "MSK" : 3, "MSD" : 4, "AST" : -4, "ADT" : -3,
    "NST" : -3, "NDT" : -2, "EST" : -5, "EDT" : -4, "CST" : -6, "CDT" : -5, "MST" : -7,
    "MDT" : -6, "PST" : -8, "PDT" : -7, "HST" : -10,  "AKST": -9, "AKDT": -8,
    "AEST": 10, "AEDT": 11,  "ACST": 9, "ACDT": 10, "AWST": 8
}
addMinute = {
    "NST" : -30,
    "NDT" : -30,
    "ACST": 30,
    "ACDT": 30
}

for i in range(int(input())):
    line = list(input().split())
    initTimeIdx = 1
    toTimeIdx = 2
    if line[0] == "noon":
        hour, minute = 12, 0
        
    elif line[0] == "midnight":
        hour, minute = 0, 0
    else:
        hour, minute = map(int, line[0].split(':'))
        if hour==12:
            hour -= 12
        if line[1]=="p.m.":
            hour += 12
        initTimeIdx = 2
        toTimeIdx = 3

    hour += addHour[line[toTimeIdx]] - addHour[line[initTimeIdx]]
    minute += addMinute.get(line[toTimeIdx], 0) - addMinute.get(line[initTimeIdx], 0)

    if minute < 0:
        hour -= 1
        minute += 60
    elif minute >= 60:
        hour += 1
        minute -= 60
    
    if hour < 0:
        hour += 24
    elif hour>=24:
        hour -= 24
    
    if hour==12 and minute==0:
        print("noon")
    elif hour==0 and minute==0:
        print("midnight")
    else:
        remHour = hour % 12
        if remHour == 0:
            remHour += 12
        print(f"{remHour:d}:{minute:02d} ", end='')
        if hour >= 12:
            print("p.m.")
        else:
            print("a.m.")