set xlabel 't'
set ylabel 'theta'

set xrange [0:100]
set yrange [-1:1]

set title 'theta vs. t'
set grid

plot 'diffeq_pendulum0.2.dat' using 1:2
