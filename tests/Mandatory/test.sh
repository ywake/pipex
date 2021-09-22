export PATH="$PATH:$PWD"

array=(
	"cat | wc"
	"cat | 'wc -l'"
	"'ls -l' | 'wc -l'"
	"cat | ./tester"
	"cat | ./no_perm_read"

	"cat | ./no_exist"
	"cat | no_exist"
	"cat | ./no_perm_ex"
	"cat | 'no_perm_ex arg1'"
	"cat | 'wc -wrong-option'"
	"'ls no_such_file' | 'ls no_such_file'"

	## ノンブロッキングのテスト
	"cat | ls"
)

cp ./tester ./no_perm_ex
chmod -x ./no_perm_ex
cp ./tester ./no_perm_read
chmod -r ./no_perm_read

infiles=(
	"tests/infile/normal"
	"tests/infile/no_exists"
	"tests/infile/no_perm"
)

make leak || exit 1

for infile in ${infiles[@]};
do
	printf "\e[1m--------- < $infile ---------\e[m\n"
	for i in ${!array[@]};
	do
		echo "< $infile `echo ${array[$i]} | sed "s/'//g"` > tests/expect" | zsh
		EX_STATUS=$?
		# echo "./tester $infile `echo ${array[$i]} | sed 's/ | / /g'` tests/out" | zsh
		echo "./pipex $infile `echo ${array[$i]} | sed 's/ | / /g'` tests/out" | zsh
		STATUS=$?

		diff tests/out tests/expect > /dev/null
		if [ $? -eq 0 ] && [ $STATUS -eq $EX_STATUS ]; then
			printf "\e[1m %s \e[32m %s \e[m\n\n" "${array[$i]}" "✓"
		else
			printf "\e[1m %s \e[31m %s \e[m\n" "${array[$i]}" "×"
			echo "status code => out: $STATUS / expect: $EX_STATUS"
			diff -y -W 80 ./tests/out ./tests/expect
			FLG=1
		fi
		rm -f tests/out tests/expect
	done
done
rm -f leaksout no_perm_ex no_perm_read

exit $FLG
