rows=5
n=1
for((i=1; i<=rows; i++))
do
  for((j=1; j<=rows - i; j++))
  do
    echo -n "  "
  done
  n=$i
  k=1
  for((j=1; j<=2*i - 1; j++))
  do
    if [ $j -lt $i ];
    then
      echo -n "$n "
      n=$((n + 1))
    elif [ $j -eq $i ];
    then
      echo -n "$n "
      n=$((n - 1))
    else
      echo -n "$n "
      n=$((n - 1))
    fi
  done
  echo
done
