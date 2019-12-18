# FS is the Field Separator
# OFS is the Output Field Separator

echo $* |
awk ' BEGIN{ FS="-" ; OFS="/"}
{
mm=$1
dd=$2
yy=$3

if(mm<1 || mm>12)
{ flag=1 }
else if(dd<1 || dd>31)
{ flag=1 }
else if(yy<1 || yy>99)
{ flag=1 }

if(flag==1)
{ print "INVALID DATE" ; exit }

print dd,mm,yy

}'

# this can also be used to format the output
#printf("%s-%s-%s\n",dd,mm,yy)
