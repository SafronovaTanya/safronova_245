# HW 1.

## 1) Convert decimal numbers to 6-bit binary

### Unsigned
- 0  → 000000
- 13 → 001101
- 24 → 011000
- 63 → 111111

(simple sum of "2"s in power i)

### Signed
- 16  → 010000
- -2  → 111110
- 31  → 011111
- -32 → 100000

(changing all bits value to opposite and at the end add 1)

---

## 2) Convert 6-bit values to decimal in both formats.

Values: 000101, 101011, 111111, 100000

> if "provide the formula" means explain how we convert to decimal numbers I explained it in previous task

| Binary   | Signed (2’s comp) | Unsigned |
|---------|--------------------:|---------:|
| 000101 | 5   | 5  |
| 101011 | -21 | 43 |
| 111111 | -1  | 63 |
| 100000 | -32 | 32 |

---

## 3) Convert decimal values to 8-bit hexadecimal

- 7   → 0x07
- 240 → 0xF0
- 171 → 0xAB
- 126 → 0x7E

---

## 4) Convert hexadecimal to 8-bit binary

- 0x3C → 60 → 00111100
- 0x7E → 126 → 01111110
- 0xFF → 255 → 11111111
- 0xA5 → 165 → 10100101

---

## 5) Negate the binary values (two’s complement)

- 00111100 → 11000100
- 01111110 → 10000010
- 11111111 → 00000001
- 10100101 → 01011011

---

## 6) Memory layout of 0xDEADBEEF

### Big-endian
DE AD BE EF

### Little-endian
EF BE AD DE

---

## 7) Convert decimal to 5-bit binary, then extend to 8 bits

| Decimal | 5-bit  | Zero-extend to 8-bit | Sign-extend to 8-bit |
|--------:|:------:|:---------------------:|:---------------------:|
| 7   | 00111 | 00000111 | 00000111 |
| 15  | 01111 | 00001111 | 00001111 |
| -16 | 10000 | 00010000 | 11110000 |
| -5  | 11011 | 00011011 | 11111011 |

---

## 8) Add 4-bit binaries

### Unsigned: (7, 9)
7 = 0111, 9 = 1001

0111 + 1001 = 1 0000 → 0000

### Signed: (4, -5)
4 = 0100, -5 = 1011

0100 + 1011 = 1111 → -1
