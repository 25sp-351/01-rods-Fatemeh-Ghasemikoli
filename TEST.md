Case 1: ./main 65                       
20,20
10,20
10,10
5,10
Cut 6 pieces of length 10 for total value 120
Cut 1 pieces of length 5 for total value 10
Remainder: 0
Value: 130
***********************************************
Case 2: ./main 65
20,40
10,20 
10,10
5,10
Cut 3 pieces of length 20 for total value 120
Cut 1 pieces of length 5 for total value 10
Remainder: 0
Value: 130
***********************************************
Case 3: ./main 65
20,10
10,15
10,10
5,30
Cut 13 pieces of length 5 for total value 390
Remainder: 0
Value: 390
***********************************************
Case 4: ./main 65
20,10
10,15
10,10
Cut 6 pieces of length 10 for total value 90
Remainder: 5
Value: 90
***********************************************
Case 5: ./main 65
20,10
10,15
10,10
Cut 6 pieces of length 10 for total value 90
Remainder: 5
Value: 90
***********************************************
Case 6: ./main 1000
200,300
150,250
100,200
50,100
Cut 10 pieces of length 100 for total value 2000
Remainder: 0
Value: 2000
***********************************************
Case 7: ./main 5   
10,50
20,100
Remainder: 5
Value: 0
***********************************************
Case 8: ./main 50
10,20
10,30
Cut 5 pieces of length 10 for total value 150
Remainder: 0
Value: 150
***********************************************
Case 9: ./main 20
10,30
Cut 2 pieces of length 10 for total value 60
Remainder: 0
Value: 60
***********************************************
Case 10: ./main 0
Error: Rod length must be a positive integer.
***********************************************
Case 11: ./main -10
Error: Rod length must be a positive integer.
***********************************************
Case 12: ./main 10.5                     
Error: Rod length must be an integer.
***********************************************
Case 13: ./main abc
Error: Rod length must be an integer.
***********************************************
Case 14: ./main     
Usage: ./main <rod_length>
***********************************************
Case 15: ./main 50                       
10,10
-10,-20
Error: Length and value must be positive integers.
***********************************************
Case 16: ./main 50                       
10,10
5
Error: Input must be in the format <length,value>.
***********************************************
Case 17: ./main 50
10,10
10.5,20,5
Error: Input must be in the format <length,value>.
***********************************************
Case 18: ./main 50
aa,bb
Error: Input must be in the format <length,value>.
***********************************************
