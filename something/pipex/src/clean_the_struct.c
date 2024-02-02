#include "../pipex.h"

int clean_the_struct(t_pipex *structure) {
    int iter;

    iter = 0;
    while ((structure->cmd_paths)[iter]) {
        printf("freeing memory in (cdm_paths *): %p\n", (structure->cmd_paths)[iter]);
        free((structure->cmd_paths)[iter]);
        iter++;
    }
    printf("freeing memory in (cmd_paths **): %p\n", (structure->cmd_paths));
    free(structure->cmd_paths);
    iter = 0;
    while ((structure->command_args)[iter]) {
        int j = 0;
        while ((structure->command_args)[iter][j]) {
            printf("freeing memory in (command_args *): %p\n", (structure->command_args)[iter][j]);
            free((structure->command_args)[iter][j]);
            j++;
        }
        printf("freeing memory in (command args **): %p\n", (structure->command_args)[iter]);
        free((structure->command_args)[iter]);
        iter++;
    }
    printf("freeing memory in (command args ***): %p\n", (structure->command_args));
    free(structure->command_args);
    printf("freeing structure (t_pipex *): %p\n", structure);
    free(structure);
    return (0);
}
