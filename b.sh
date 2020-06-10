date1=1
month=1
year=$1
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

  while [ $date1 -lt 29 ]
  do
    if [ $month -eq 2 -a $date1 -gt 28 ]
    then
      continue;
    fi

    luuid=`exec uuidgen`

    fulldate=$(printf "%02d" $date1)"/"$(printf "%02d" $month)"/"$year
    fulldateString=$(printf "%02d" $date1)"_"$(printf "%02d" $month)"_"$year

    date1=`expr $date1 + 1`

      for str in "SRV1_" "SRV2_" "SRV3_" "SRV4_" "SRV5_"
      do
        random=$((RANDOM%30))

        failedRec=$(($random%5))

        remarks="NA"
        result="SUCCESS"

        if [ $failedRec -gt 0 ]
        then
          failResult="FAILURE"
          failRemarks="some error error code '$random'"
        fi

        generalCounter=`expr $generalCounter + 1`
        if [ $failedRec -eq 1 ]
        then
          echo ${fulldate}","${luuid}","$str$date1","SRV_$str","$failResult","$failRemarks
          continue;
        else
          echo ${fulldate}","${luuid}","$str$date1","SRV_$str","$result","$remarks
        fi

        generalCounter=`expr $generalCounter + 1`
        if [ $failedRec -eq 2 ]
        then
          echo ${fulldate}","${luuid}","$str$date1","SRV_$str","$failResult","$failRemarks
          continue;
        else
          echo ${fulldate}","${luuid}","$str$date1","SRV_$str","$result","$remarks
        fi

        generalCounter=`expr $generalCounter + 1`
        if [ $failedRec -eq 3 ]
        then
          echo ${fulldate}","${luuid}","$str$date1","SRV_$str","$failResult","$failRemarks
          continue;
        else
          echo ${fulldate}","${luuid}","$str$date1","SRV_$str","$result","$remarks
        fi

        generalCounter=`expr $generalCounter + 1`
        if [ $failedRec -eq 4 ]
        then
          echo ${fulldate}","${luuid}","$str$date1","SRV_$str","$failResult","$failRemarks
          continue;
        else
          echo ${fulldate}","${luuid}","$str$date1","SRV_$str","$result","$remarks
        fi

        done
    done

  date1=1;
  month=`expr $month + 1`
done
