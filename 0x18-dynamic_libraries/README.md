<h1><b>0x18. C - Dynamic libraries</b></h1>

<h1><b>Resources</b></h1>

<h3><b>Read or watch:</b></h3>
<pre>
<a href="https://www.youtube.com/watch?v=eW5he5uFBNM">Static and Dynamic Libraries explained</a>
<a href="https://https://www.youtube.com/watch?v=pkMg_df8gHs&t=35s">Creating a Dynamic Library</a>
</pre>

<h1><b>General Objectives</b></h1>
<ul>
  <li>What is a dynamic library, how does it work, how to create one, and how to use it</li>
  <li>What is the environment variable <mark>$LD_LIBRARY_PATH</mark> and how to use it</li>
  <li>What are the differences between static and shared libraries</li>
  <li>Basic usage <mark>nm, ldd, ldconfig</mark></li>
</ul>

<h1><b>Tasks</b></h1>
<h2><b>0. A library is not a luxury but one of the necessities of life</b></h2>
<pre>
Create the dynamic library libdynamic.so containing all the functions listed below:
int _putchar(char c);
int _islower(int c);
int _isalpha(int c);
int _abs(int n);
int _isupper(int c);
int _isdigit(int c);
int _strlen(char *s);
void _puts(char *s);
char *_strcpy(char *dest, char *src);
int _atoi(char *s);
char *_strcat(char *dest, char *src);
char *_strncat(char *dest, char *src, int n);
char *_strncpy(char *dest, char *src, int n);
int _strcmp(char *s1, char *s2);
char *_memset(char *s, char b, unsigned int n);
char *_memcpy(char *dest, char *src, unsigned int n);
char *_strchr(char *s, char c);
unsigned int _strspn(char *s, char *accept);
char *_strpbrk(char *s, char *accept);
char *_strstr(char *haystack, char *needle);
</pre>
<h2><b>1. Without libraries what have we? We have no past and no future</b></h2>
<p>
  Create a script that creates a dynamic library called liball.so from all the .c files that are in the current directory.
</p>

<h2><b>2. Let's call C functions from Python</b></h2>
<pre>
know, you’re missing C when coding in Python. So let’s fix that!

Create a dynamic library that contains C functions that can be called from Python. See example for more detail
</pre>
<pre>
  julien@ubuntu:~/0x18$ cat 100-tests.py
import random
import ctypes

cops = ctypes.CDLL('./100-operations.so')
a = random.randint(-111, 111)
b = random.randint(-111, 111)
print("{} + {} = {}".format(a, b, cops.add(a, b)))
print("{} - {} = {}".format(a, b, cops.sub(a, b)))
print("{} x {} = {}".format(a, b, cops.mul(a, b)))
print("{} / {} = {}".format(a, b, cops.div(a, b)))
print("{} % {} = {}".format(a, b, cops.mod(a, b)))
julien@ubuntu:~/0x16. Doubly linked lists$ python3 100-tests.py 
66 + -76 = -10
66 - -76 = 142
66 x -76 = -5016
66 / -76 = 0
66 % -76 = 66
julien@ubuntu:~/0x18$ python3 100-tests.py 
-34 + -57 = -91
-34 - -57 = 23
-34 x -57 = 1938
-34 / -57 = 0
-34 % -57 = -34
julien@ubuntu:~/0x18$ python3 100-tests.py 
-5 + -72 = -77
-5 - -72 = 67
-5 x -72 = 360
-5 / -72 = 0
-5 % -72 = -5
julien@ubuntu:~/0x18$ python3 100-tests.py 
39 + -62 = -23
39 - -62 = 101
39 x -62 = -2418
39 / -62 = 0
39 % -62 = 39
julien@ubuntu:~/0x18$ 
</pre>

<h2><b>3. Code injection: Win the Giga Millions!</b></h2>
<pre>
bought a ticket for the Giga Millions and chose these numbers: 9, 8, 10, 24, 75 + 9. If you could run two commands on the same server where the Giga Millions program runs, could you make me win the Jackpot?

Our mole got us a copy of the program, you can download it here. Our mole also gave us a piece of documentation:
</pre>

<pre>
  /* Giga Millions program                                                                                    
  * Players may pick six numbers from two separate pools of numbers:                                                
  * - five different numbers from 1 to 75 and                                                                       
  * - one number from 1 to 15                                                                                       
  * You win the jackpot by matching all six winning numbers in a drawing.                                           
  * Your chances to win the jackpot is 1 in 258,890,850                                                             
  *                                                                                                                 
  * usage: ./gm n1 n2 n3 n4 n5 bonus
</pre>
<ul>
  <li>You can’t modify the program gm itself as Master Sysadmin Sylvain (MSS) always checks its MD5 before running it.</li>
  <li>The system is an Linux Ubuntu 16.04.</li>
  <li>The server has internet access.</li>
  <li>Our mole will be only able to run two commands from a shell script, without being detected by MSS.</li>
  <li>Your shell script should be maximum 3 lines long. You are not allowed to use ;, &&, ||, |, ` (it would be detected by MSS), and have a maximum of two commands.</li>
  <li>Our mole has only the authorization to upload one file on the server. It will be your shell script.</li>
  <li>Our mole will run your shell script this way: mss@gm_server$ . ./101-make_me_win.sh.</li>
  <li>Our mole will run your shell script from the same directory containing the program gm, exactly 98 seconds before MSS runs gm with my numbers: ./gm 9 8 10 24 75 9.</li>
  <li>MSS will use the same terminal and session than our mole.</li>
  <li>Before running the gm program, MSS always check the content of the directory.</li>
  <li>MSS always exit after running the program gm.</li>
</ul>
<ul>
  <li>mss@gm_server$ . ./101-make_me_win.sh</li>
  <li>mss@gm_server$ rm 101-make_me_win.sh</li>
  <li>mss@gm_server$ ls -la</li>
  <ul>
    <li>.</li>
    <li>..</li>
    <li>gm</li>
  </ul>
  <li>mss@gm_server$ history -c</li>
  <li>mss@gm_server$ clear</li>
  <li>mss@gm_server$ ls -la</li>
  <ul>
    <li>.</li>
    <li>..</li>
    <li>gm</li>
  </ul>
  <li>mss@gm_server$ md5sum gm</li>
  <li>d52e6c18e0723f5b025a75dea19ef365  gm</li>
  <li>mss@gm_server$ ./gm 9 8 10 24 75 9</li>
  <ul>
    <li>--&gt; Please make me win!</li>
  </ul>
  <li>mss@gm_server$ exit</li>
</ul>
