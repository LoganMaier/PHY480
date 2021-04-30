# set the terminal type to be the screen (which is x11 here)
#set terminal png

# record the time and date the graph was generated

# titles and labels
set title 'ground state vs dimension; fixed b'
set xlabel 'dimension; log10'
set ylabel 'rel err of lowest energy; log10'

# move the legend to a free space
set key right
set grid

set logscale
# set the x and y axis scales (already logs)
#set xrange [-10:-1]
#set yrange [-12:0]

f(x) = a*x**b
fit [12:40] f(x) "groundstate.dat" using ($1):($2) via a,b
fit_label = sprintf("%.5e*x^{%-+4.1f}",a,b)

# plot the data as well as the fit, with appropriate titles 
plot "groundstate.dat" using ($1):($2) title 'low. energy vs dim', \
[12:40] a*x**b title fit_label

# output the plot to the file derivative_test_plt.ps   
set out "groundstate.ps"
set term postscript color enhanced
replot
