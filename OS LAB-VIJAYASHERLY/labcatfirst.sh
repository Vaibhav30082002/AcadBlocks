#Vaibhav Shah
#20BBS0162

echo "Enter the Number of times you want to repeat : "
read t
for((j<0; j<t; j++))
do
    echo "Enter the Number of terms :"
    read n
    a=0
    echo ""
    echo "The Terms are : "
    for((i=1;i<=n;i++))
    do
        b=$((3**i))
        echo -n "$((b-1))"
        echo -n " "
    done
    echo " "
done 
