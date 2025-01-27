# Test Cases for 01-rods.c

This file contains documented test cases for the `01-rods.c` program. Each test case includes the command to run the program, the input data, and the expected output. It also includes edge cases to ensure the robustness of the program.

---

## **Test Case 1**
**Command**:
```bash
./main 65
```

**Input**:
```
20,20
10,20
10,10
5,10
```

**Expected Output**:
```
Cut 6 pieces of length 10 for total value 120
Cut 1 pieces of length 5 for total value 10
Remainder: 0
Value: 130
```

---

## **Test Case 2**
**Command**:
```bash
./main 65
```

**Input**:
```
20,40
10,20
10,10
5,10
```

**Expected Output**:
```
Cut 3 pieces of length 20 for total value 120
Cut 1 pieces of length 5 for total value 10
Remainder: 0
Value: 130
```

---

## **Test Case 3**
**Command**:
```bash
./main 65
```

**Input**:
```
20,10
10,15
10,10
5,30
```

**Expected Output**:
```
Cut 13 pieces of length 5 for total value 390
Remainder: 0
Value: 390
```

---

## **Test Case 4**
**Command**:
```bash
./main 65
```

**Input**:
```
20,10
10,15
10,10
```

**Expected Output**:
```
Cut 6 pieces of length 10 for total value 90
Remainder: 5
Value: 90
```

---

## **Test Case 5**
**Command**:
```bash
./main 65
```

**Input**:
```
20,10
10,15
10,10
```

**Expected Output**:
```
Cut 6 pieces of length 10 for total value 90
Remainder: 5
Value: 90
```

---

## **Test Case 6**
**Command**:
```bash
./main 1000
```

**Input**:
```
200,300
150,250
100,200
50,100
```

**Expected Output**:
```
Cut 10 pieces of length 100 for total value 2000
Remainder: 0
Value: 2000
```

---

## **Test Case 7**
**Command**:
```bash
./main 5
```

**Input**:
```
10,50
20,100
```

**Expected Output**:
```
Remainder: 5
Value: 0
```

---

## **Test Case 8**
**Command**:
```bash
./main 50
```

**Input**:
```
10,20
10,30
```

**Expected Output**:
```
Cut 5 pieces of length 10 for total value 150
Remainder: 0
Value: 150
```

---

## **Edge Cases**

### **Test Case 9: Minimum Rod Length**
**Command**:
```bash
./main 0
```

**Expected Output**:
```
Error: Rod length must be a positive integer.
```

---

### **Test Case 10: Negative Rod Length**
**Command**:
```bash
./main -10
```

**Expected Output**:
```
Error: Rod length must be a positive integer.
```

---

### **Test Case 11: Non-Integer Rod Length**
**Command**:
```bash
./main 10.5
```

**Expected Output**:
```
Error: Rod length must be an integer.
```

---

### **Test Case 12: Alphabetic Input for Rod Length**
**Command**:
```bash
./main abc
```

**Expected Output**:
```
Error: Rod length must be an integer.
```

---

### **Test Case 13: Missing Rod Length Argument**
**Command**:
```bash
./main
```

**Expected Output**:
```
Usage: ./main <rod_length>
```

---

### **Test Case 14: Negative Piece Values**
**Command**:
```bash
./main 50
```

**Input**:
```
10,10
-10,-20
```

**Expected Output**:
```
Error: Length and value must be positive integers.
```

---

### **Test Case 15: Malformed Input**
**Command**:
```bash
./main 50
```

**Input**:
```
10,10
5
```

**Expected Output**:
```
Error: Input must be in the format <length,value>.
```

---

### **Test Case 16: Decimal Input in Pieces**
**Command**:
```bash
./main 50
```

**Input**:
```
10,10
10.5,20
```

**Expected Output**:
```
Error: Input must be in the format <length,value>.
```

---

### **Test Case 17: Alphabetic Input in Pieces**
**Command**:
```bash
./main 50
```

**Input**:
```
aa,bb
```

**Expected Output**:
```
Error: Input must be in the format <length,value>.
```

---

## **Instructions**

1. **How to Compile**:
   ```bash
   clang -o main -Wall -g 01-rods.c
   ```

2. **How to Run**:
   ```bash
   ./main <rod_length>
   ```


---

