#include <fcntl.h>
#include <ndbm.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

int main(void)
{
    DBM        *db;
    datum       key;
    datum       data;
    datum       fetch_data;
    const char *db_file = "exampledb";

    // Open the database
    db = dbm_open(strdup(db_file), O_RDWR | O_CREAT, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);
    if(db == NULL)
    {
        fprintf(stderr, "Failed to open database.\n");
        exit(EXIT_FAILURE);
    }

    // Prepare key and data
    key.dptr = strdup("testkey");

#if defined(__linux__) || defined(__FreeBSD__)
    key.dsize = (int)strlen(key.dptr) + 1;
#else
    key.dsize = strlen(key.dptr) + 1;
#endif

    data.dptr = strdup("testvalue");

#if defined(__linux__) || defined(__FreeBSD__)
    data.dsize = (int)strlen(data.dptr) + 1;
#else
    data.dsize = strlen(data.dptr) + 1;
#endif

    // Store key-value pair
    if(dbm_store(db, key, data, DBM_REPLACE) != 0)
    {
        fprintf(stderr, "Failed to store key-value pair.\n");
        dbm_close(db);
        exit(EXIT_FAILURE);
    }

    // Fetch the stored value
    fetch_data = dbm_fetch(db, key);
    if(fetch_data.dptr)
    {
        printf("Fetched value: %s\n", (char *)fetch_data.dptr);
    }
    else
    {
        fprintf(stderr, "Failed to fetch value.\n");
        dbm_close(db);
        exit(EXIT_FAILURE);
    }

    // Close the database
    dbm_close(db);

    return EXIT_SUCCESS;
}
