#IFS=''
TMPIP=$(cat $1)
echo "$TMPIP"
echo "----------------------------"
for x in $TMPIP
do
   echo [$x] 666
done
echo "----------------------------"
IFS=''
while read -r line
do 
	echo [$line]666 
done < "$1"
echo "----------------------------"
IFS=''
cat "$1" | while read line
do 
  while echo "$line" | grep -q  " $"
  do
	line=${line%*${line:(-1)}}
  done
  echo "$line" >> "$1.tem"
done 
