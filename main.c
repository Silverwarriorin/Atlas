#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sqlite3.h>
#include <ncurses.h>

static inline int query(sqlite3 *DB, char *query, char *sqlerror);
static int callback(void *data, int argc, char **argv, char **azColName);

int main(int argc, char **argv) {
    static sqlite3 *DB;
    char *sqlerror;
    int exit = sqlite3_open("Atlas.db", &DB);

    if (exit) {
        fprintf(stderr, "Could not open database\n");
        return SQLITE_ERROR;
    } else
        fprintf(stdout, "Database opened successfully!\n");


    char *q = "INSERT INTO Atlas (playerName) VALUES('Zach');";

    exit = sqlite3_exec(DB, q, callback, 0, &sqlerror);

    if (exit != SQLITE_OK) {
        fprintf(stderr, "Could not q table\n");
        return SQLITE_CANTOPEN;
    } else
        fprintf(stdout, "Table queried successfully\n");

    q = "SELECT * FROM Atlas";

    exit = sqlite3_exec(DB, q, callback, 0, &sqlerror);

    if (exit != SQLITE_OK) {
        fprintf(stderr, "Could not q table\n");
        return SQLITE_CANTOPEN;
    } else
        fprintf(stdout, "Table queried successfully\n");

    q = "DELETE FROM Atlas WHERE playerName='Zach'";

    query(DB, q, sqlerror);

    sqlite3_close(DB);
}

static inline int query(sqlite3 *DB, char *query, char *sqlerror) {
    int exit = sqlite3_exec(DB, query, callback, 0, &sqlerror);

    if (exit != SQLITE_OK) {
        fprintf(stderr, "Could not query table\n");
        return SQLITE_CANTOPEN;
    } else
        fprintf(stdout, "Table queried successfully\n");

    return 0;
}

static int callback(void *data, int argc, char **argv, char **azColName)
{
    fprintf(stderr, "%s: ", (const char*)data);

    for (int i = 0; i < argc; i++) {
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }

    printf("\n");

    return 0;
}