#!/bin/bash  
  
# file='read_file.txt'  
  
# i=1  
# while read line; do  
  
#Reading each line  
# echo "Line No..........."  
# i=$((i+1))
# done < $file  

while read "./read_file.txt"; do 
   array=( $line )
   echo "${array[0]}"
   echo "${array[2]}"
done