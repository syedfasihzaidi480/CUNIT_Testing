#include "20F-1133_21F-9053_File_Set3_Function_1.h"
#include <stdlib.h>
#include <string.h>

struct cli_def *cli_init() {
    struct cli_def *cli;
    struct cli_command *c;

    if (!(cli = calloc(1, sizeof(struct cli_def)))) return NULL;

    cli->buf_size = 1024;
    if (!(cli->buffer = calloc(cli->buf_size, 1))) {
        cli_done(cli);
        return NULL;
    }
    cli->telnet_protocol = 1;

    // Registering built-in commands
    cli_register_command(cli, NULL, "help", NULL, PRIVILEGE_UNPRIVILEGED, MODE_ANY, "Show available commands");
    cli_register_command(cli, NULL, "quit", NULL, PRIVILEGE_UNPRIVILEGED, MODE_ANY, "Disconnect");
    cli_register_command(cli, NULL, "logout", NULL, PRIVILEGE_UNPRIVILEGED, MODE_ANY, "Disconnect");
    cli_register_command(cli, NULL, "exit", NULL, PRIVILEGE_UNPRIVILEGED, MODE_ANY, "Exit from current mode");
    cli_register_command(cli, NULL, "history", NULL, PRIVILEGE_UNPRIVILEGED, MODE_ANY, "Show command history");
    cli_register_command(cli, NULL, "enable", NULL, PRIVILEGE_UNPRIVILEGED, MODE_EXEC, "Enable privileged mode");
    cli_register_command(cli, NULL, "disable", NULL, PRIVILEGE_PRIVILEGED, MODE_EXEC, "Disable privileged mode");

    c = cli_register_command(cli, NULL, "configure", NULL, PRIVILEGE_PRIVILEGED, MODE_EXEC, "Enter configuration mode");
    if (!c) {
        cli_done(cli);
        return NULL;
    }
    cli_register_command(cli, c, "terminal", NULL, PRIVILEGE_PRIVILEGED, MODE_EXEC, "Configure from terminal");

    // Registering built-in filters
    cli_register_filter(cli, "begin", NULL, NULL, PRIVILEGE_UNPRIVILEGED, MODE_ANY, "Start with matching lines");
    cli_register_filter(cli, "between", NULL, NULL, PRIVILEGE_UNPRIVILEGED, MODE_ANY, "Match lines between patterns");
    cli_register_filter(cli, "count", NULL, NULL, PRIVILEGE_UNPRIVILEGED, MODE_ANY, "Count lines");
    cli_register_filter(cli, "exclude", NULL, NULL, PRIVILEGE_UNPRIVILEGED, MODE_ANY, "Exclude lines");
    cli_register_filter(cli, "include", NULL, NULL, PRIVILEGE_UNPRIVILEGED, MODE_ANY, "Include lines");
    cli_register_filter(cli, "grep", NULL, NULL, PRIVILEGE_UNPRIVILEGED, MODE_ANY, "Regex filtering");
    cli_register_filter(cli, "egrep", NULL, NULL, PRIVILEGE_UNPRIVILEGED, MODE_ANY, "Extended regex filtering");

    // Setting default privileges and modes
    cli->privilege = cli->mode = -1;
    cli_set_privilege(cli, PRIVILEGE_UNPRIVILEGED);
    cli_set_configmode(cli, MODE_EXEC, NULL);

    // Setting idle timeout
    cli->timeout_tm.tv_sec = 1;
    cli->timeout_tm.tv_usec = 0;
    cli_set_idle_timeout_callback(cli, 0, NULL);

    return cli;
}
