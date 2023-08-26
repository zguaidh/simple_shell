<h1 align="center"> 
    0x16. C - Simple Shell 
</h1>

<h3 align="center"> 
    Authors
</h3>
<p align="center">
    <i> Mojalefa Kodisang & Habiba Zguaid </i>
</p>

<h2 align="center">
    Description 
</h2>

<p>
    <arial>
        The project was focused more on building a simple shell with similar capabilities as the <i>sh</i> builtin shell.
        <br>
            <br>
                Our should handle every case that are handle by <i>sh</i> as we are going to explain in detail in this document. Here are the concepts required to build the project:
                <li> Basics of C programming </li>
                <li> Basic shell / bash commands </li>
            </br>
        </br>
    </arial>
</p>

<h2 align="center"> How does our prompt work? </h2>

### Compilation
For compilation we used <i> gcc </i> compiler, which compiles all .c files and using the following flags as seen below :
``` 
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh 
```

### Execution
To run the program, you need to execute the program name ``` hsh ``` on to your bash prompt. Upon execution a prompt woulf appear, see example below:
```
julien@ubuntu:~/shell$ ./hsh
:)  
```
### Handles
Our prompt handles a limited cases. Here are some of the cases it handles:

1. UNIX command line interpretion
```
julien@ubuntu:~/shell$ ./hsh
:)
:) Ctrl+D
julien@ubuntu:~/shell$
```
2. Handle command lines with arguments
```
julien@ubuntu:~/shell$
:) /bin/ls -l /tmp 
total 20
-rw------- 1 julien julien    0 Dec  5 12:09 config-err-aAMZrR
drwx------ 3 root   root   4096 Dec  5 12:09 systemd-private-062a0eca7f2a44349733e78cb4abdff4-colord.service-V7DUzr
drwx------ 3 root   root   4096 Dec  5 12:09 systemd-private-062a0eca7f2a44349733e78cb4abdff4-rtkit-daemon.service-ANGvoV
drwx------ 3 root   root   4096 Dec  5 12:07 systemd-private-062a0eca7f2a44349733e78cb4abdff4-systemd-timesyncd.service-CdXUtH
-rw-rw-r-- 1 julien julien    0 Dec  5 12:09 unity_support_test.0
:) ^C
julien@ubuntu:~/shell$
```
3. Handle the ```PATH```
    * ```fork``` must not be called if the command doesn’t exist
    <p>
    <b><u> Warning: </u> </b>
    This case has a memory leakage problem of which we are going to fix soon
    </p>
```
julien@ubuntu:~/shell$ ./hsh
:) /bin/ls
barbie_j       env-main.c  exec.c  fork.c  pid.c  ppid.c    prompt   prompt.c  shell_0.3  stat    test_scripting.sh  wait.c
env-environ.c  exec    fork    mypid   ppid   printenv  promptc  shell     shell.c    stat.c  wait
:) ls
barbie_j       env-main.c  exec.c  fork.c  pid.c  ppid.c    prompt   prompt.c  shell_0.3  stat    test_scripting.sh  wait.c
env-environ.c  exec    fork    mypid   ppid   printenv  promptc  shell     shell.c    stat.c  wait
:) ls -l /tmp 
total 20
-rw------- 1 julien julien    0 Dec  5 12:09 config-err-aAMZrR
drwx------ 3 root   root   4096 Dec  5 12:09 systemd-private-062a0eca7f2a44349733e78cb4abdff4-colord.service-V7DUzr
drwx------ 3 root   root   4096 Dec  5 12:09 systemd-private-062a0eca7f2a44349733e78cb4abdff4-rtkit-daemon.service-ANGvoV
drwx------ 3 root   root   4096 Dec  5 12:07 systemd-private-062a0eca7f2a44349733e78cb4abdff4-systemd-timesyncd.service-CdXUtH
-rw-rw-r-- 1 julien julien    0 Dec  5 12:09 unity_support_test.0
:) ^C
julien@ubuntu:~/shell$
```
4. Implement the ```exit``` built-in, that exits the shell without arguments
```
julien@ubuntu:~/shell$ ./hsh
:) exit
julien@ubuntu:~/shell$
```
5. ```env``` built-in, that prints the current environment
```
julien@ubuntu:~/shell$ ./hsh
:) env
USER=julien
LANGUAGE=en_US
SESSION=ubuntu
COMPIZ_CONFIG_PROFILE=ubuntu
SHLVL=1
HOME=/home/julien
C_IS=Fun_:)
DESKTOP_SESSION=ubuntu
LOGNAME=julien
TERM=xterm-256color
PATH=/home/julien/bin:/home/julien/.local/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin
DISPLAY=:0
:) exit
julien@ubuntu:~/shell$
```
6. builtin command ```cd```
```
julien@ubuntu:~/shell$ ./hsh
:) cd [directory]
:)
:) exit
julien@ubuntu:~/shell$
```
### How to get this get this project?
```
$ git clone https://github.com/zguaidh/simple_shell
```
# 
<p align="right">
	<i>copyrights reserved</i>
	2023
	<br>
		<b>ALX</b>
		- African Leadership International
	</br>
	M. Kodisang and B. Zguaid
	</br>
</p>
