import fileinput

for line in fileinput.input():
    day = line.strip().split()

    hours, minutes = map(int, day[3].split(':'))
    sunrise = 60*hours+minutes

    hours, minutes = map(int, day[4].split(':'))
    sunset = 60*hours + minutes

    duration = sunset - sunrise
    hours = duration//60
    minutes = duration%60

    print(f"{day[0]} {day[1]} {day[2]} {hours} hours {minutes} minutes")