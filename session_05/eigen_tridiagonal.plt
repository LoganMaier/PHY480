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
set timestamp

# titles and labels
set title 'Relative Error for Lowest Eigenvalue vs N'
set xlabel 'log(N)'
set ylabel 'log(Rel err)'

# move the legend to a free space
set key right
set grid

# set the x and y axis scales (already logs)
#set xrange [-10:-1]
#set yrange [-12:0]

# fit the curve
f1(x) = a1*x + b1

fit [0:3] f1(x) "eigen_tridiagonal.dat" using ($1):($2) via a1,b1 


fit_title1 = sprintf("%-+4.1f*x %-+4.1f",a1,b1)


# plot the data as well as the fit, with appropriate titles 
plot "eigen_tridiagonal.dat" using ($1):($2) title 'Rel err vs N', \
     a1*x + b1 title fit_title1


# output the plot to the file derivative_test_plt.ps   
set out "eigen_tridiagonal.ps"
set term postscript color enhanced
replot
