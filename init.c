#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>

int main() {
    /* 输入的命令行 */
    char cmd[256];
    /* 命令行拆解成的各部分，以空指针结尾 */
    char *args[128];
    while (1) {
        /* 提示符 */
        printf("# ");
        fflush(stdin);
        fgets(cmd, 256, stdin);
        /* 清理结尾的换行符 */
        int i;
        for (i = 0; cmd[i] != '\n'; i++)
            ;
        cmd[i] = '\0';
        /* 拆解命令行 */
        
        for(args[0] = cmd; *args[0]==' '; args[0]++);

        for (i = 0; *args[i]; i++)
            for (args[i+1] = args[i] + 1; *args[i+1]; args[i+1]++)
                if (*args[i+1] == ' ') {
                    *args[i+1] = '\0';
                    args[i+1]++;
                    for(; *args[i+1] == ' '; args[i+1]++);
                    break;
                }
        args[i] = NULL;

        /* 没有输入命令 */
        if (!args[0])
            continue;


        /* 内建命令 */
        if (strcmp(args[0], "cd") == 0) {
            if (args[1])
                if (chdir(args[1])==-1)
                    printf("路径输入错误！请重新输入\n");
            continue;
        }
        if (strcmp(args[0], "pwd") == 0) {
            char wd[4096];
            puts(getcwd(wd, 4096));
            continue;
        }
        if (strcmp(args[0], "exit") == 0)
            return 0;

        if (strcmp(args[0], "export")==0){
            char *value=args[1];
            for (; *value!='=' && *value!='\0'; value++);
            if (*value == '='){
                *value == '\0';
                value++;
                if(setenv(args[1],value,1)==-1){
                    printf("args[0]=%s\n",args[0]);
                    printf("args[1]=%s\n",args[1]);
                    printf("args[2]=%s\n",args[2]);
                    printf("环境变量设置失败，请检查格式！\n");

                }
            }
            else
                printf("环境变量设置失败，请检查格式！\n");
            continue;

        }

        /* 外部命令 */
        pid_t pid = fork();
        if (pid == 0) {
            /* 子进程 */
            execvp(args[0], args);
            /* execvp失败 */
            return 255;
        }
        /* 父进程 */
        wait(NULL);
    }
}
