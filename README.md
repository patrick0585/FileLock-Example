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
``
