import sys

def AtoR(A):
    m = {1000: 'M', 900: 'CM', 500: 'D', 400: 'CD', 100: 'C', 90: 'XC',\
         50: 'L', 40: 'XL', 10: 'X', 9: 'IX', 5: 'V', 4: 'IV', 1: 'I'}
    A = int(A)
    for value, roman in m.items():
        while A >= value:
            print(roman, end='')
            A -= value
    print()

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

dic = {}
def arabicEncoding(idx=0, s=""):
    l = len(s)
    if(idx==l):
        i = 0
        while s[i]!='+':
            i += 1
        num2Start = i+1

        num1 = 0        
        i-=1
        deg  = 0
        while i>-1:
            num1 += dic[s[i]]*(10**deg)
            i-=1
            deg+=1

        num2End = num2Start
        while s[num2End]!='=':
            num2End += 1
        num3Start = num2End+1

        num2 = 0
        num2End -= 1
        deg = 0
        while num2End>=num2Start:
            num2 += dic[s[num2End]]*(10**deg)
            deg+=1
            num2End-=1
        
        num3 = 0
        num3End = l-1
        deg = 0
        while num3End>=num3Start:
            num3 += dic[s[num3End]]*(10**deg)
            num3End -= 1
            deg += 1

        if num1+num2==num3:
            return 2
        else:
            return 0

    if s[idx]=='+' or s[idx]=='=' or (s[idx] in dic):
        return arabicEncoding(idx+1, s)
    
    

def main():
    for s in sys.stdin:
        s = s.strip()
        i = 0
        while s[i]!='+':
            i += 1
        roman1 = s[0: i]
        i += 1
        j = i
        while s[j]!='=':
            j += 1
        roman2 = s[i:j]
        roman3 = s[j+1:]

        accept1 = False
        num1 = RtoA(roman1)
        num2 = RtoA(roman2)
        num3 = RtoA(roman3)
        if (num1 + num2) == num3:
            accept1 = True

        accept2 = 0


main()