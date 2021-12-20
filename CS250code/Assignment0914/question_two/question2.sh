#!/bin/bash

# calculate the sum of the integer values 
# Jingbo Wang

# Check the input file is a regular file
if [[ ! -f $1 ]]
then
  echo "$1 not found!"
  exit 1
fi 

# store the chosed column from test csv file  into a template csv file
cut -f$(($2+1)) $1 > testTemp.csv

# assume the total of newline counts from template csv file
total_lines=$(wc -l testTemp.csv | cut -d " " -f1)

# assume total of word counts from template csv file
total_words=$(wc -w testTemp.csv | cut -d " " -f1)

#  bool all lines of this column have empty string or not
if [[ ($total_words -lt $total_lines) && ($total_words -gt 0 ) ]]
then
  echo "There are some lines of column #$2 do not contain a value!"
  
# bool this column exist or not
elif [[ $total_words -eq 0 ]]
then
   echo "Column #$2 does not have any value!"
   exit 2
   
# calculate the sum of column when it exists 
# and does not have empty srtring
elif [[ $total_lines -eq $total_words ]]
then
  sum=0
  for num in $(cut -c 1 testTemp.csv)
  do
    let sum=$sum+$num 
  done
  echo "The sum of column #$2 is" $sum
fi

#remove the template csv file
rm testTemp.csv
exit 0
