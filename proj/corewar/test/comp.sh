rm -f sb zaz
./sbasm test.s
mv test.cor sb
./zazasm test.s
mv test.cor zaz
diff sb zaz
