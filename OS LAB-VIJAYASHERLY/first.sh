echo "Number of Products to be entered: "
read N
for(( i=0; i<N; i++ ))
do
    echo "Number of reviews for product $(( i+1 )): "
    read n
    sum=0
    avg=0
    for(( j=0; j<n; j++ ))
    do
        echo "Enter The rating: "
        read rating
        if [ $rating -lt 0 ]
        then
            continue
        fi
        sum=$(( sum+rating ))
        done
    avg=$(( sum/n ))
    echo
    if [ $avg -ge 90 ]
    then
        echo "Excellent"
        echo
        elif [ $avg -ge 80 -a $avg -lt 90 ]
        then
                echo "Very Good"
                echo
        elif [ $avg -ge 70 -a $avg -lt 80 ]
        then
                echo "Good"
                echo
        elif [ $avg -ge 60 -a $avg -lt 70 ]
        then
                echo "Fair"
                echo
        elif [ $avg -ge 55 -a $avg -lt 60 ]
        then
                echo "Bad"
                echo
        else
                echo "Poor"
                echo
        fi
done
