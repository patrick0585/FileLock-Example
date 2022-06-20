# FileLock-Example
A simple FileLock Example written in C++

The credit is read from the balance.dat, increased and written back again

## balance.dat
```
../FileLock-Example % cat balance.dat 
100
```

## Compile
```
g++ main.cpp -o FileLockExample (without filelocking)
g++ main.cpp -DLOCK=1 -o FileLockExample (with filelocking)
```

## Usage
### 1 process (without filelocking)
```
../FileLock-Example % ./FileLockExample 
The current balance is 100$
The balance was increased to 120$
The current balance is 120$
The balance was increased to 140$
The current balance is 140$
The balance was increased to 160$
The current balance is 160$
The balance was increased to 180$
```

### 2 processes (without filelocking)
| Process 1 | Process 2  |
| ------ | --------- |
|../FileLock-Example % ./FileLockExample <br> The current balance is 100$ <br> The balance was increased to 120$ <br> The current balance is 140$ <br> The balance was increased to 160$ <br> The current balance is 180$ <br> The balance was increased to 200$ <br> The current balance is 220$ <br> The balance was increased to 240$ | ../FileLock-Example % ./FileLockExample <br> The current balance is 120$ <br> The balance was increased to 140$ <br> The current balance is 160$ <br> The balance was increased to 180$ <br> The current balance is 200$ <br> The balance was increased to 220$ <br> The current balance is 240$ <br> The balance was increased to 260$ |

## Clang-Format
Create clang-format file
```
clang-format -style=google -dump-config > .clang-format
```

Format C++ File with clang-format
```
clang-format -style=file -i main.cpp
```
