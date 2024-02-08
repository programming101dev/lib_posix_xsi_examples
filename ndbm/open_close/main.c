#include <fcntl.h>
#include <ndbm.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

int main(void)
{
    char *db_file;
    DBM  *db;
    int   exit_code;

    db_file = strdup("exampledb");
    db      = dbm_open(db_file, O_RDWR | O_CREAT, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);

    if(db == NULL)
    {
        fprintf(stderr, "Failed to open database.\n");
        exit_code = EXIT_FAILURE;
        goto cleanup;
    }

    dbm_close(db);
    exit_code = EXIT_SUCCESS;

cleanup:
    free(db_file);

    return exit_code;
}
