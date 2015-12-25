echo "Working on ls test"
./ft_ls testls > ftls.out 2> ftls.err
ls -1 testls > ls.out 2> ls.err
diff ftls.out ls.out > ls.out.diff
diff ftls.err ls.err > ls.err.diff
echo "Job done for ls test, see ls.out.diff and ls.err.dif orr ftls.[out, err] and ls.[out, err] for more detail"

echo "Working on ls -r test"
./ft_ls -r testls > ftlsr.out 2> ftlsr.err
ls -r1 testls > lsr.out 2> lsr.err
diff ftlsr.out lsr.out > lsr.out.diff
diff ftlsr.err lsr.err > lsr.err.diff
echo "Job done for ls -r test, see lsr.out.diff and lsr.err.dif orr ftlsr.[out, err] and lsr.[out, err] for more detail"

echo "Working on ls -a -r test"
./ft_ls -a -r testls > ftlsar.out 2> ftlsar.err
ls -1 -a -r testls > lsar.out 2> lsar.err
diff ftlsar.out lsar.out > lsar.out.diff
diff ftlsar.err lsar.err > lsar.err.diff
echo "Job done for ls -a -r test, see lsar.out.diff and lsar.err.dif orr ftlsar.[out, err] and lsar.[out, err] for more detail"

echo "Working on ls -Ra test"
./ft_ls -Ra testls > ftlsra.out 2> ftlsra.err
ls -1 -Ra testls > lsra.out 2> lsra.err
diff ftlsra.out lsra.out > lsra.out.diff
diff ftlsra.err lsra.err > lsra.err.diff
echo "Job done for ls -Ra test, see lsra.out.diff and lsra.err.dif orr ftlsra.[out, err] and lsra.[out, err] for more detail"

echo "Working on ls -Ra test"
./ft_ls -Rat testls > ftlsrat.out 2> ftlsrat.err
ls -1 -Rat testls > lsrat.out 2> lsrat.err
diff ftlsrat.out lsrat.out > lsrat.out.diff
diff ftlsrat.err lsrat.err > lsrat.err.diff
echo "Job done for ls -Rat test, see lsrat.out.diff and lsrat.err.dif orr ftlsrat.[out, err] and lsra.t[out, err] for more detail"
