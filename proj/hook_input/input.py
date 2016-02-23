#! /usr/bin/python

max_size = 32000

digit0_z = ord('A')
digit1_z = ord('a')
digit2_z = ord('0')

digit0_m = ord('Z')
digit1_m = ord('z')
digit2_m = ord('9')

rst = "ls "

digit0 = digit0_z
while digit0 <= digit0_m :
    digit1 = digit1_z
    while digit1 <= digit1_m :
        digit2 = digit2_z
        while digit2 <= digit2_m :
            rst += chr(digit0)+chr(digit1)+chr(digit2)+" "
            if len(rst) > max_size :
                break
            digit2 += 1
        if len(rst) > max_size :
            break
        digit1 += 1
    if len(rst) > max_size :
        break
    digit0 += 1

print rst
