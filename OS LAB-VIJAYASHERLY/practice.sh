#         1
#       2 2 2
#     3 3 3 3 3
#   4 4 4 4 4 4 4
# 5 5 5 5 5 5 5 5 5

echo "Input the number: "
read number;
for((m=1; m<=number; m++))
do
for((a=1; a<=2*number-2*m; a++))
do
echo -n " ";
done
for((n=1; n<=$(( 2*m-1)); n=n+1))
do
echo -n "$((m)) "
done
echo;
done

#              2
#            4 4 4
#          6 6 6 6 6
#        8 8 8 8 8 8 8
#  10 10 10 10 10 10 10 10 10

echo "Input the number: "
read number;
for((m=1; m<=number; m++))
do
for((a=1; a<= number-m; a++))
do
echo -n "  ";
done
for((n=2; n<=$(( 2*m)); n=n+1))
do
echo -n "$((2*m)) "
done
echo;
done

#           1
#         3 3 3
#       5 5 5 5 5
#     7 7 7 7 7 7 7
#   9 9 9 9 9 9 9 9 9

echo "Input the number: "
read number;
for((m=1; m<=number; m++))
do
for((a=1; a<= number-m; a++))
do
echo -n "  ";
done
for((n=1; n<=$(( 2*m-1)); n=n+1))
do
echo -n "$((2*m -1)) "
done
echo;
done



#           1 1
#         3 3 3 3
#       5 5 5 5 5 5
#     7 7 7 7 7 7 7 7
#   9 9 9 9 9 9 9 9 9 9

echo "Input the number: "
read number;
for((m=1; m<=number; m++))
do
for((a=1; a<= number-m; a++))
do
echo -n "  ";
done
for((n=1; n<=$(( 2*m)); n=n+1))
do
echo -n "$((2*m-1)) "
done
echo;
done

#           1 1
#         2 2 2 2
#       3 3 3 3 3 3
#     4 4 4 4 4 4 4 4
#   5 5 5 5 5 5 5 5 5 5

echo "Input the number: "
read number;
for((m=1; m<=number; m++))
do
for((a=1; a<= number-m; a++))
do
echo -n "  ";
done
for((n=1; n<=$(( 2*m)); n=n+1))
do
echo -n "$((m)) "
done
echo;
done

