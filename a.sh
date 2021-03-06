date1=1
date2=""
month=1
year=2011
fulldate=""
fulldateString=""
random=0
remarks=""
result=""
generalCounter=0
luuid=""
failedRec=0

while [ $month -lt 13 ]
do
  random=$((RANDOM%30))

  while [ $date1 -lt 29 ]
  do
    if [ $month -eq 2 -a $date1 -gt 28 ]
    then
      continue;
    fi

    luuid=`exec uuidgen`

    failedRec=$(($random%5))

    remarks="NA"
    result="SUCCESS"

    if [ $failedRec -gt 0 ]
    then
      failResult="FAILURE"
      failRemarks="some error error code '$random'"
    fi

    fulldate=$(printf "%02d" $date1)"/"$(printf "%02d" $month)"/"$year
    fulldateString=$(printf "%02d" $date1)"_"$(printf "%02d" $month)"_"$year

    date1=`expr $date1 + 1`

    generalCounter=`expr $generalCounter + 1`
    echo '{"index":{"_id":"'"A"$generalCounter$fulldateString'"}}'
    if [ $failedRec -eq 1 ]
    then
      echo '{"date":"'${fulldate}'","uuid":"'${luuid}'","scenarioid":"ABC_'$date1'","srvname":"SRV_ABC_1","result":"'$failResult'","remarks":"'$failRemarks'"}'
      continue;
    else
      echo '{"date":"'${fulldate}'","uuid":"'${luuid}'","scenarioid":"ABC_'$date1'","srvname":"SRV_ABC_1","result":"'$result'","remarks":"'$remarks'"}'
    fi

    generalCounter=`expr $generalCounter + 1`
    echo '{"index":{"_id":"'"A"$generalCounter$fulldateString'"}}'
    if [ $failedRec -eq 2 ]
    then
      echo '{"date":"'${fulldate}'","uuid":"'${luuid}'","scenarioid":"ABC_'$date1'","srvname":"SRV_ABC_2","result":"'$failResult'","remarks":"'$failRemarks'"}'
      continue;
    else
      echo '{"date":"'${fulldate}'","uuid":"'${luuid}'","scenarioid":"ABC_'$date1'","srvname":"SRV_ABC_2","result":"'$result'","remarks":"'$remarks'"}'
    fi

    generalCounter=`expr $generalCounter + 1`
    echo '{"index":{"_id":"'"A"$generalCounter$fulldateString'"}}'
    if [ $failedRec -eq 3 ]
    then
      echo '{"date":"'${fulldate}'","uuid":"'${luuid}'","scenarioid":"ABC_'$date1'","srvname":"SRV_ABC_3","result":"'$failResult'","remarks":"'$failRemarks'"}'
      continue;
    else
      echo '{"date":"'${fulldate}'","uuid":"'${luuid}'","scenarioid":"ABC_'$date1'","srvname":"SRV_ABC_3","result":"'$result'","remarks":"'$remarks'"}'
    fi

    generalCounter=`expr $generalCounter + 1`
    echo '{"index":{"_id":"'"A"$generalCounter$fulldateString'"}}'
    if [ $failedRec -eq 4 ]
    then
      echo '{"date":"'${fulldate}'","uuid":"'${luuid}'","scenarioid":"ABC_'$date1'","srvname":"SRV_ABC_4","result":"'$failResult'","remarks":"'$failRemarks'"}'
      continue;
    else
      echo '{"date":"'${fulldate}'","uuid":"'${luuid}'","scenarioid":"ABC_'$date1'","srvname":"SRV_ABC_4","result":"'$result'","remarks":"'$remarks'"}'
    fi

  done

  date1=1;
  month=`expr $month + 1`
done
