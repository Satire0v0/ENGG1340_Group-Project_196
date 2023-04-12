## Problem Collection for Final Assessment

1. Real time reading of user keyboard input (solved) (Hanson-666)

When working on local computer, I can realize this function by simply using getch() function in the header file called <conio.h>. However, this library is not installed on HKU server. 

After consulting with other friends, there is an alternative method, that is getch() introduced in <ncurses.h>. Luckily this header file is installed on server. Whereas, I realized that I needed to adhere to its specific initialization and output formats. It requires me to spend some time studying this library.

Finally, I unintentionally found that the library <termio.h> could also work well.


2. Dynamic memory management of two-dimensional array named map (unsolved) (Hanson-666)