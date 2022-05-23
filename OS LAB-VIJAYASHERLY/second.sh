d="-"
for m in `ls`
do
 if [[ `ls -l -d $m | awk '{print $1}'` =~ ^$d.* ]]
 then
 echo `file $m` " `ls -l -d $i | awk '{print $1}'`"
 chmod 666 $m
 else
 file $m
 fi
done






