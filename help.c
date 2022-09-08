#include <stdio.h>
#include <string.h>

void help(int cmd_argc, char *cmd_argv[])
{
    if (cmd_argc > 2)
    {
        printf("help command syntax error\n");
    }

    else if (cmd_argc == 1)
    {
        printf("For more information on a specific command, type \"help command-name\".\n\n");

        // ECHO
        printf("echo\t\t Display messages.\n");

        // EXIT
        printf("exit\t\t Quits the cli.exe program (commmand interpreter).\n");

        // FCMP
        printf("fcmp\t\t Compares two files and display the first line that differs.\n");

        // FINDS
        printf("finds\t\t Find pattern in a file then print it to the screen.\n");

        // GCOPY
        printf("gcopy\t\t Copy from source filename to destination filename.\n");

        // HELP
        printf("help\t\t Provides help information for cli command.\n");

        // PRINT
        printf("print\t\t Prints opened file to the screen.\n");

        printf("\nFor more information on tools see the command-line reference in the online help.\n\n");
    }

    // Detailed "echo" information.
    else if (strcmp(cmd_argv[1], "echo") == 0)
    {
        printf("Display messages.\n\n");
        printf("echo [message]\n\n");
    }

    // Detailed "exit" information.
    else if (strcmp(cmd_argv[1], "exit") == 0)
        printf("Quits the cli.exe program (command interpreter).\n\n");

    // Detailed "fcmp" information.
    else if (strcmp(cmd_argv[1], "fcmp") == 0)
    {
        printf("Compares two files then display the first line that differs.\n\n");
        printf("fcmp [drive:][path]filename1 [drive:][path]filename2\n\n");
        printf("\t[drive:][path]filenameNUM\n");
        printf("\t\tSpecifies drive, directory, and/or files to compare.\n\n");
    }

    // Detailed "gcopy" information.
    else if (strcmp(cmd_argv[1], "gcopy") == 0)
    {
        printf("Copy from filename1 to filename2.\nIf filename2 doesn't exist gcopy will create it otherwise gcopy will overwrite it.\n\n");
        printf("gcopy source destination\n\n");
        printf("source\n");
        printf("\t[drive:][path]sourceFileName\n");
        printf("\t\tSpecifies drive, directory, and or source file to copy.\n\n");
        printf("destination\n");
        printf("\t[drive:][path]destinationFileName\n");
        printf("\tSpecifies drive, directory, and or destination file to copy.\n\n");
    }


    // Detailed "finds" infomation.
    else if (strcmp(cmd_argv[1], "finds") == 0)
    {
        printf("Finds patterns in a file then print it to the screen.\n\n");
        printf("finds [-[n][x] [...]] [drive:][path]filename\n\n");
        printf("\t[drive:][path]filename\n");
        printf("\t\tSpecifies drive, directory, and/or file to find.\n\n");
        printf("\t-n Print line number.\n");
        printf("\t-x Print every line that didn't contain pattern.\n\n");
    }

    // Detailed "help" information.
    else if (strcmp(cmd_argv[1], "help") == 0)
    {
        printf("Provides help information for cli commands.\n\n");
        printf("help [command-name]\n\n");
        printf("\tcommand - displays help information on that command.\n\n");
    }

    // Detailed "print" information.
    else if (strcmp(cmd_argv[1], "print") == 0)
    {
        printf("Open stdin and print the content to stdout.\n\n");
        printf("print [drive:][path]filename\n\n");
        printf("\t[drive:][path]filename\n");
        printf("\t\tSpecifies drive, directory, and/or files to print.\n\n");
    }

    else
    {
        printf("help %s command does not exist.\n\n", cmd_argv[1]);
    }
}
