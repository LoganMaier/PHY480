# plot file for int_test

set timestamp
set key top right

set xlabel 'i; log10'
set ylabel 'Relative error of integration approach; log10'
set title 'Comparing Integration Methods'

set xrange [0.5:4]
set yrange [-16:-4]
f1(x) = a1*x + b1
f2(x) = a2*x + b2
f3(x) = a3*x + b3

fit [0.5:3.3] f1(x)  "int.dat" using ($1):($2) via a1,b1 
fit [0.5:2.5] f2(x)  "int.dat" using ($1):($3) via a2,b2 
fit [0:4] f3(x)  "int.dat" using ($1):($4) via a3,b3 


fit_title1 = sprintf("%-+4.1f*x %-+4.1f",a1,b1)
fit_title2 = sprintf("%-+4.1f*x %-+4.1f",a2,b2)
fit_title3 = sprintf("%-+4.1f*x %-+4.1f",a3,b3)



plot "int.dat" using ($1):($2) title 'Simpsons', \
     a1*x + b1 title fit_title1, \
      "int.dat" using ($1):($3) title 'Milne', \
     a2*x + b2 title fit_title2, \
      "int.dat" using ($1):($4) title 'GSL', \
     a3*x + b3 title fit_title3

plot \
  "int.dat" using ($1):(log10($2) title 'Simpsons;', \
  "int.dat" using ($1):(log10($3) title 'Milne;', \
  "int.dat" using ($1):(log10($4) title 'GSL;'


set out "int.ps"
set term postscript color enhanced
replot