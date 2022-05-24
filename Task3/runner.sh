#!/bin/bash
VER=$1
echo "Run version: $VER"
echo 1
for i in `seq 1 3`
do
        RES=`mpirun -n 1 ./main_ver$VER`
        echo $RES
done

for i in `seq 2 2 8`
do
	echo $i
	for j in `seq 1 3`
	do
		RES=`mpirun -n $i ./main_ver$VER`
		echo $RES
	done
done 

echo 16
for i in `seq 1 3`
do 
	RES=`mpirun -n 16 ./main_ver$VER`
	echo $RES
done
