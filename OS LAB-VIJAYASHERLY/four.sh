echo -n Input your number:
read n
echo Select: 1.Composite        2.Automorphic       3.Abundant
echo -n "Select your number type:"
read type
case $type in
1)
        flag=0
        number=$n
        for ((i=2;i<n;i++))
        do
            if [ $n -eq 2 ]
            then
                    break
            fi
            mod=$((n%i))
            if [ $mod -eq 0 ]
            then
                    ((flag=flag+1))
                    break
            fi
        done
        if [ $flag -eq 0 ]
        then
                echo $number is not Composite
        elif [ $flag -gt 0 ]
        then
                echo $number is Composite
        fi
;;
2)
        num_sq=$((n*n))
        number=$n
        flag=0
        while [ $n -gt 0 ]
        do
            a=$((n%10))
            b=$((num_sq%10))
            if [ $a -ne $b ]
            then
                    ((flag=flag+1))
                    echo $number is not an Automorphic number
                    break
            fi
        ((n=n/10))
        ((num_sq=num_sq/10))
    done
    if [ $flag -eq 0 ]
    then
        echo $number is an Automorphic number
    fi
;;
3)
        sum=0
        for ((i=1;i<n;i++))
        do
                c=$((n%i))
                if [ $c -eq 0 ]
                then
                        ((sum = sum+i))
                fi
        done
        if [ $sum -gt $n ]
        then
                echo $n is an Abundant number
        else
                echo $n is not an Abundant number
        fi
;;
*)
        echo Invalid type:$type
;;
esac
