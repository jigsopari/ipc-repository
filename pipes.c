#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
void main()
{
pid_t pid;
int mypipefd[2];
int ret;
char buf[30];
ret=pipe(mypipefd);
if(ret==-1)
{
perror("pipe failed");
exit(1);
}
pid=fork();
if(pid==0)
{
printf("child process\n");
close(mypipefd[0]);
write(mypipefd[1],"hello there all is fun",22);
}
else
{
printf("parent process\n");

close(mypipefd[1]);

read(mypipefd[0],buf,25);
printf("data:%s\n",buf);
}
}

