
if [[ $# -eq 0 ]]
then
  directory='.'
elif [[ $# -ne 1 ]] || [[ ! -d "$1" ]]
then
  echo "$1 is a invalid directory!"
  exit 1
else
  
  directory="$1"
  echo "$directory"
fi
