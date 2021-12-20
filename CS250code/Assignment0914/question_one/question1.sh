#!/bin/bash

# save the original content to a file, and the file should be replaceed
# with one that has all trailling spaces on each lineremoved.
# Jingbo Wang

# Check the input file is a regular file
if [[ ! -f $1 ]]
then
  echo $1 " not found!"
  exit 1
fi

# save the original content to a file with .orig
cp $1 $1.orig

# read $1.orig and trail spaces on each lineremoved 
# then re-store into $1.
IFS='' # change Bash's input field separator from whitespace to nothing
cat "$1" | while read line # read each line, preserving spaces
do 
  while echo "$line" | grep -q  " $" # loop if there is trailing space
  do
    line=${line%?} #remove trailing space
  done
    echo $line >> "$1.temp" 
done 

cat "$1.temp" > "$1"

rm "$1.temp"
exit 0
