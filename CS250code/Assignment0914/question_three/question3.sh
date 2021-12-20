#!/bin/bash

# to print the names of all files that are duplicates 
# within that directory.
# Jingbo Wang

# test directory  
if [[ $# -eq 0 ]]
then
  directory='.'
elif [[ $# -ne 1 ]] || [[ ! -d "$1" ]]
then
  echo "$1 is a invalid directory!"
  exit 1
else
  directory="$1"
fi

echo "The duplicate files: "

#find first file in the directory
for file1 in $(ls $directory) 
do
  if [[ -f "$directory/$file1" ]]
  then
	md5file1=$(md5sum "$directory/$file1" |  cut -d " " -f1)
	file1Size=$(ls -l "$directory/$file1" |  cut -d " " -f5)
    boolFlag="0"
    if [[ $boolFlag = "0" ]]
    then
	  #find second file in the directory
	  for file2 in $(ls $directory)
	  do
	    if [[ (-f "$directory/$file2") ]]
	    then
	      file2Size=$(ls -l "$directory/$file2" |  cut -d " " -f5)
	      if [[ "$file2Size" = "$file2Size" ]]
	      then
			md5file2=$(md5sum "$directory/$file2" | cut -d " " -f1)
	  	    if [[ ("$file1" != "$file2") 
	  	         && ("$md5file1" = "$md5file2") ]]
	  	    then
				echo "$file1 --- $file2" 
      		    boolFlag="1"
			fi
		  fi	
	    fi 
      done
    fi
  fi   
done
exit 0 
