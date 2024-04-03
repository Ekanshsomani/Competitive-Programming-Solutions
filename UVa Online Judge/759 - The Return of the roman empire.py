import sys

def AtoR(A):
    m = {1000: 'M', 900: 'CM', 500: 'D', 400: 'CD', 100: 'C', 90: 'XC',\
         50: 'L', 40: 'XL', 10: 'X', 9: 'IX', 5: 'V', 4: 'IV', 1: 'I'}
    A = int(A)
    rString = ""
    for value, roman in m.items():
        while A >= value:
            rString += roman
            A -= value
    return rString

def RtoA(R):
    m = {'I': 1, 'V': 5, 'X': 10, 'L': 50, 'C': 100, 'D': 500, 'M': 1000}
    value = 0
    for i in range(len(R)):
        if i+1 < len(R) and m[R[i]] < m[R[i+1]]:
            value += m[R[i+1]] - m[R[i]]
        elif i-1 >= 0 and m[R[i-1]] < m[R[i]]:
            continue
        else:
            value += m[R[i]]
    return value

def main():
    validRoman = []

    for i in range(1, 4000):
        validRoman.append(AtoR(i))
    
    for s in sys.stdin:
        s = s.strip()
        val = RtoA(s)
        if val>=4000 or s!=validRoman[val-1]:
            print("This is not a valid number")
        else:
            print(val)

main()