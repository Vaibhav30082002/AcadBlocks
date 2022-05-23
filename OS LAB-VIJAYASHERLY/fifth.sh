echo "NUMBER OF TIMES YOU WANT TO REPEAT(n): "
read n
for(( i=1; i<=n; i++))
do
    value=2000
    echo "ENTER THE NUMBER OF TERMS YOU WANT TO PRINT(N): "
    read Number
    echo -n $value
    echo -n " "
    for((j=1;j<Number;j++))
    do
        value=$(( value/j ))
        echo -n $value
        echo -n " "
    done
    echo
done

