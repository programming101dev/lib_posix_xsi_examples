#include <p101_env/env.h>
#include <p101_error/error.h>
#include <p101_posix_xsi/p101_libgen.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    struct p101_error *error;
    struct p101_env   *env;
    char              *path;

    error = p101_error_create(false);
    env   = p101_env_create(error, NULL);
    path  = strdup("/usr/local/bin/example");

    if(path != NULL)
    {
        const char *const base = p101_basename(env, path);

        printf("p101_basename(\"/usr/local/bin/example\") = %s\n", base);
        free(path);
    }

    p101_env_destroy(env);
    p101_error_destroy(error);

    return EXIT_SUCCESS;
}
