#  file: eigen_tridiagonal.plt 
#
#  Gnuplot plot file for eigout_mod output
#  
#  Programmer:  Dick Furnstahl  furnstahl.1@osu.edu
# 
#  Revision history
#   2004-01-24  original version for 780.20 session 5
#   2004-01-16  added postscript enhanced and comments for session 4
#

# set the terminal type to be the screen (which is x11 here)
#set terminal png

# record the time and date the graph was generated
#set timestamp

# titles and labels
set title 'Wavefunction of Oscillator'
set xlabel 'r'
set ylabel 'u(r)'

# move the legend to a free space
set key right
set grid

# set the x and y axis scales (already logs)
#set xrange [-10:-1]
#set yrange [-12:0]

# plot the data as well as the fit, with appropriate titles 
plot "eigen_tridiagonal.dat" using ($1):($2) title 'u(r)', \

# output the plot to the file derivative_test_plt.ps   
set out "eigen_tridiagonal.ps"
set term postscript color enhanced
replot
