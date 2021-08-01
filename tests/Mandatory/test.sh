array=(
	"cat wc"
	"cat 'wc -l'"
	"cat ./tester"
	"cat ./no_perm_read"

	"cat ./no_exist"
	"cat ./no_perm_ex"
	"cat 'wc -a'"
)

cp ./tester ./no_perm_ex
chmod -x ./no_perm_ex
cp ./tester ./no_perm_read
chmod -r ./no_perm_read

for i in ${!array[@]};
do
	for file in $(find "./tests/infile" -type f);
	do
		printf "=> \e[1m %s \e[m\n" "./pipex $file ${array[$i]} out"

		echo "./pipex $file ${array[$i]} out" | bash
		# STATUS=$?
		CMDS=$(echo ${array[$i]} | sed "s/ / | /" | tr -d \'\")
		echo "< $file $CMDS > expect" | bash
		# EX_STATUS=$?

		# echo "status code => out: $STATUS / expect: $EX_STATUS" > /dev/stderr
		diff out expect
		# if [ $? -eq 0 ] && [ $STATUS -eq $EX_STATUS ]; then
		if [ $? -eq 0 ]; then
			printf "\e[32m%s\n\e[m" ">> OK!"
		else
			printf "\e[31m%s\n\e[m" ">> KO!"
			diff -y out expect
			FLG=1
		fi
		rm -f out expect
	done
done
rm -f leaksout

exit $FLG
